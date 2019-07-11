/*
* OSPE - Open Source Packet Editor
* Copyright(C) 2018-2019 Javier Pereda <https://github.com/elecyb>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using Be.Windows.Forms;
using OSPE.Forms;
using OSPE.Properties;
using Table = OSPE.MainForm.Tab;

namespace OSPE
{

    public static class ListViewHelper
    {
        public static void SetDoubleBuffered(Control c)
        {
            if (System.Windows.Forms.SystemInformation.TerminalServerSession)
                return;

            var aProp = typeof(Control).GetProperty(
                        "DoubleBuffered",
                        System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance
                        );

            aProp.SetValue(c, true, null);
        }
    }

    /// <summary>
    /// Subclase de ListViewItem que contiene un parametro de solo lectura con el tiempo en que fue instanciado el objeto.
    /// </summary>
    public class WeListViewItem : ListViewItem
    {
        public int Time { get; private set; }
        public WeListViewItem(string[] strings) : base(strings)
        {
            Time = Environment.TickCount;
        }
    }


    public partial class MainForm
    {
        public readonly List<WeListViewItem> ListItems = new List<WeListViewItem>();
        private int LastUIChange; // Tiempo del último cambio que se realizó en la interface y que afecta a la información mostrada en las tablas.
        private int ColDataTextLength; // Cantidad de caracteres que se deben mostrar en la columna Data.
        private bool _changingColumnWidth; // Booleano para usar en la función OnColumnWidthChanged.
        private ImageList _tableIcons;

        public enum Tab
        {
            Both, Received, Sent, Watch
        }

        /// <summary>
        /// Crea un item de tabla y se almacena en una lista de items.
        /// El item está preparado para ser entregado a la tabla cuando ésta lo requiera.
        /// </summary>
        /// <param name="packet"></param>
        public void AddPacket(Packet packet)
        {
            var data = Settings.ViewAsHex ? packet.GetBufferAsHex() : packet.GetBufferAsText();
            if (data.Length > ColDataTextLength)
                data = data.Substring(0, ColDataTextLength);

            string[] strings = { " " + ListItems.Count, packet.LocalIp + " : " + packet.LocalPort, packet.RemoteIp + " : " + packet.RemotePort, Program.FunctionNameToString(packet.FunctionID), packet.Size.ToString(), data };
            ListItems.Add(new WeListViewItem(strings) {ImageIndex = (int) packet.Direction});
        }

        /// <summary>
        /// Vuelve a crear el item.
        /// Esta función se utiliza cuando el item queda desactualizado, por ejemplo, al cambiar el ancho de la columna "Data" o al cambiar la visualización en hexadecimal o string.
        /// </summary>
        /// <param name="id"></param>
        public void ReloadItem(int id)
        {
            var packet = PacketManager.PacketList[id];

            var data = Settings.ViewAsHex ? packet.GetBufferAsHex() : packet.GetBufferAsText();
            if(data.Length > ColDataTextLength)
                data = data.Substring(0, ColDataTextLength);

            string[] strings = { " " + id, packet.LocalIp + " : " + packet.LocalPort, packet.RemoteIp + " : " + packet.RemotePort, Program.FunctionNameToString(packet.FunctionID), packet.Size.ToString(), data };
            ListItems[id] = new WeListViewItem(strings) { ImageIndex = (int)packet.Direction };
        }

        private static int GetPacketIdFromTableItemIndex(object sender, int index)
        {
            int id;
            switch ((Table)((ListView)sender).Tag)
            {
                case Table.Both:
                    id = PacketManager.Both[index];
                    break;
                case Table.Received:
                    id = PacketManager.Received[index];
                    break;
                case Table.Sent:
                    id = PacketManager.Sent[index];
                    break;
                case Table.Watch:
                    id = PacketManager.Watch[index];
                    break;
                default:
                    throw new ArgumentOutOfRangeException();
            }
            return id;
        }

        /// <summary>
        /// Obtiene el item correspondiente a un índice de fila dado para una tabla determinada.
        /// Esta función se ejecuta cada vez que una tabla necesita mostrar un item en la pantalla.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="eventArgs"></param>
        private void OnRetrieveVirtualItem(object sender, RetrieveVirtualItemEventArgs e)
        {
            var id = GetPacketIdFromTableItemIndex(sender, e.ItemIndex);
            var item = ListItems[id];

            // Si el item está desactualizado lo vuelve a crear
            if (LastUIChange > item.Time)
                ReloadItem(id);

            e.Item = item;

        }

        private List<int> Refreshes = new List<int>();
        private int lastRefresh ;

        /// <summary>
        /// Actualiza la cantidad de filas de la tabla correspondiente a la tab seleccionada.
        /// </summary>
        public void RefreshTables()
        {
            if (InvokeRequired)
            {
                try
                {
                    Invoke(new VoidDelegate(RefreshTables));
                }
                catch{}
                return;
            }

            if (lastRefresh > 0)
            {
                if (Refreshes.Count >= 5)
                    Refreshes.RemoveAt(0);
                Refreshes.Add(Environment.TickCount - lastRefresh);
                tslTesting.Text = Refreshes.Average().ToString("N");
                tslTesting2.Text = (Environment.TickCount - lastRefresh).ToString();
            }
            lastRefresh = Environment.TickCount;

            switch ((Tab)tabControlMain.SelectedIndex)
            {
                case Tab.Both:
                    lvwBoth.VirtualListSize = PacketManager.Both.Count;
                    break;
                case Tab.Received:
                    lvwReceived.VirtualListSize = PacketManager.Received.Count;
                    break;
                case Tab.Sent:
                    lvwSent.VirtualListSize = PacketManager.Sent.Count;
                    break;
                case Tab.Watch:
                    lvwWatch.VirtualListSize = PacketManager.Watch.Count;
                    break;

            }

            if(tsmiAutoScroll.Checked)
                ScrollToBottom();

        }

        /// <summary>
        /// Calcula la cantidad de caracteres que se deben poner en la columna Data.
        /// </summary>
        public void SetColDataTextLength()
        {
            var prev = ColDataTextLength;
            switch ((Tab)tabControlMain.SelectedIndex)
            {
                case Tab.Both:
                    ColDataTextLength = colBothData.Width;
                    break;
                case Tab.Received:
                    ColDataTextLength = colReceivedData.Width;
                    break;
                case Tab.Sent:
                    ColDataTextLength = colSentData.Width;
                    break;
                case Tab.Watch:
                    ColDataTextLength = colWatchData.Width;
                    break;
            }

            ColDataTextLength /= (tabControlMain.TabCount - 1);

            // Si la cantidad de caracteres cambia entonces se considera que hubo un cambio en la interface que afecta a los items.
            // Se guarda el tiempo en el que se produjo el cambio para que los items que están desactualizados se actualizen.
            if (ColDataTextLength != prev)
                LastUIChange = Environment.TickCount;
        }

        /// <summary>
        /// Se llama al cambiar de tab
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void OnTabChange(object sender, EventArgs e)
        {
            RefreshTables();
        }

        /// <summary>
        /// Al hacer click sobre una fila de la tabla, se abre el detalle del packet
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void OnMouseDoubleClick(object sender, MouseEventArgs e)
        {
            var list = (ListView) sender;
            if (list.SelectedIndices.Count <= 0)
                return;

            var index = list.SelectedIndices[0];
            var id = GetPacketIdFromTableItemIndex(sender, index);
            var packet = PacketManager.PacketList[id];
            Form showPacketForm = new ShowPacketForm(id, packet);
            showPacketForm.Show();
        }

        private void OnMouseClick(object sender, MouseEventArgs e)
        {
            var list = (ListView)sender;
            if (e.Button == MouseButtons.Right)
            {
                if (list.FocusedItem.Bounds.Contains(e.Location) == true)
                {
                    cmsPacketOptions.Show(Cursor.Position);
                }
            }
        }

        private void OnResize(object sender, EventArgs e)
        {
            colBothData.Width = -2;
            colReceivedData.Width = -2;
            colSentData.Width = -2;
            colWatchData.Width = -2;

            SetColDataTextLength();
        }

        /// <summary>
        /// Cuando se cambia el ancho de una columna se propaga el cambio en las demas tablas y se ajusta el ancho de la columna Data.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void OnColumnWidthChanged(object sender, ColumnWidthChangedEventArgs e)
        {
            // Para evitar recursión se verifica el booleano
            if (_changingColumnWidth)
                return;
            _changingColumnWidth = true;

            // El nuevo ancho se obtiene de la columna dada por ColumnIndex en la tabla "sender".
            var width = ((ListView)sender).Columns[e.ColumnIndex].Width;

            switch (e.ColumnIndex)
            {
                case 0: // Column Packet
                    colReceivedPacket.Width = width;
                    colSentPacket.Width = width;
                    colBothPacket.Width = width;
                    colWatchPacket.Width = width;
                    break;
                case 1: // Column Source
                    colReceivedSource.Width = width;
                    colSentSource.Width = width;
                    colBothSource.Width = width;
                    colWatchSource.Width = width;
                    break;
                case 2: // Column Destination
                    colReceivedDestination.Width = width;
                    colSentDestination.Width = width;
                    colBothDestination.Width = width;
                    colWatchDestination.Width = width;
                    break;
                case 3: // Column Function
                    colBothFunction.Width = width;
                    colSentFunction.Width = width;
                    colRecivedFunction.Width = width;
                    colWatchFunction.Width = width;
                    break;
                case 4: // Column Size
                    colReceivedSize.Width = width;
                    colSentSize.Width = width;
                    colBothSize.Width = width;
                    colWatchSize.Width = width;
                    break;
            }
            // Column Data
            colReceivedData.Width = -2;
            colSentData.Width = -2;
            colBothData.Width = -2;
            colWatchData.Width = -2;

            SetColDataTextLength();

            _changingColumnWidth = false;
        }

        /// <summary>
        /// Actualiza el contenido del hexbox cuando se selecciona un packet
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void OnSelectedIndexChanged(object sender, EventArgs e)
        {
            var list = (ListView) sender;
            if(list.SelectedIndices.Count <= 0)
                return;
            var index = list.SelectedIndices[0];
            var id = GetPacketIdFromTableItemIndex(sender, index);
            var packet = PacketManager.PacketList[id];
            hexBox.ByteProvider = new DynamicByteProvider(packet.Data);

            tsmiAutoScroll.Checked = false;
        }

        /// <summary>
        /// Scroll to bottom of selected table.
        /// </summary>
        private void ScrollToBottom()
        {
            switch ((Table)tabControlMain.SelectedIndex)
            {
                case Table.Received:
                    if(lvwReceived.VirtualListSize > 0)
                       lvwReceived.EnsureVisible(lvwReceived.VirtualListSize - 1);
                    break;
                case Table.Sent:
                    if (lvwSent.VirtualListSize > 0)
                        lvwSent.EnsureVisible(lvwSent.VirtualListSize - 1);
                    break;
                case Table.Both:
                    if (lvwBoth.VirtualListSize > 0)
                        lvwBoth.EnsureVisible(lvwBoth.VirtualListSize - 1);
                    break;
                case Table.Watch:
                    if (lvwWatch.VirtualListSize > 0)
                        lvwWatch.EnsureVisible(lvwWatch.VirtualListSize - 1);
                    break;
            }
        }

        /// <summary>
        /// Inicializa las listas.
        /// </summary>
        private void InitListViews()
        {
            //tabControlMain.SelectedIndex = Settings.CurrentTab;
            tabControlCapturesAndFilters.SelectedIndex = Settings.CurrentCaptureFilterTab;
            tabControlMain.SelectedIndexChanged += OnTabChange;

            lvwBoth.Tag = Tab.Both;
            lvwReceived.Tag = Tab.Received;
            lvwSent.Tag = Tab.Sent;
            lvwWatch.Tag = Tab.Watch;

            ListViewHelper.SetDoubleBuffered(lvwBoth);
            ListViewHelper.SetDoubleBuffered(lvwReceived);
            ListViewHelper.SetDoubleBuffered(lvwSent);
            ListViewHelper.SetDoubleBuffered(lvwWatch);

            colBothPacket.Width = Settings.colPacket;
            colBothSource.Width = Settings.colSource;
            colBothDestination.Width = Settings.colDestination;
            colBothSize.Width = Settings.colSize;
            colReceivedPacket.Width = Settings.colPacket;
            colReceivedSource.Width = Settings.colSource;
            colReceivedDestination.Width = Settings.colDestination;
            colReceivedSize.Width = Settings.colSize;
            colSentPacket.Width = Settings.colPacket;
            colSentSource.Width = Settings.colSource;
            colSentDestination.Width = Settings.colDestination;
            colSentSize.Width = Settings.colSize;
            colWatchPacket.Width = Settings.colPacket;
            colWatchSource.Width = Settings.colSource;
            colWatchDestination.Width = Settings.colDestination;
            colWatchSize.Width = Settings.colSize;

            colReceivedData.Width = -2;
            colSentData.Width = -2;
            colBothData.Width = -2;
            colWatchData.Width = 2;

            lvwReceived.GridLines = true;
            lvwSent.GridLines = true;
            lvwBoth.GridLines = true;
            lvwWatch.GridLines = true;

            lvwReceived.VirtualMode = true;
            lvwSent.VirtualMode = true;
            lvwBoth.VirtualMode = true;
            lvwWatch.VirtualMode = true;

            lvwReceived.ForeColor = Color.Black;
            lvwSent.ForeColor = Color.Black;
            lvwBoth.ForeColor = Color.Black;
            lvwWatch.ForeColor = Color.Black;

            lvwReceived.RetrieveVirtualItem += OnRetrieveVirtualItem;
            lvwSent.RetrieveVirtualItem += OnRetrieveVirtualItem;
            lvwBoth.RetrieveVirtualItem += OnRetrieveVirtualItem;
            lvwWatch.RetrieveVirtualItem += OnRetrieveVirtualItem;

            lvwReceived.ColumnWidthChanged += OnColumnWidthChanged;
            lvwSent.ColumnWidthChanged += OnColumnWidthChanged;
            lvwBoth.ColumnWidthChanged += OnColumnWidthChanged;
            lvwWatch.ColumnWidthChanged += OnColumnWidthChanged;

            lvwReceived.MouseDoubleClick += OnMouseDoubleClick;
            lvwReceived.MouseClick += OnMouseClick;
            lvwSent.MouseDoubleClick += OnMouseDoubleClick;
            lvwSent.MouseClick += OnMouseClick;
            lvwBoth.MouseDoubleClick += OnMouseDoubleClick;
            lvwBoth.MouseClick += OnMouseClick;
            lvwWatch.MouseDoubleClick += OnMouseDoubleClick;
            lvwWatch.MouseClick += OnMouseClick;

            _tableIcons = new ImageList {ColorDepth = ColorDepth.Depth32Bit};
            _tableIcons.Images.Add(Resources.Faq24);
            _tableIcons.Images.Add(Resources.received);
            _tableIcons.Images.Add(Resources.sent);


            lvwReceived.SmallImageList = _tableIcons;
            lvwSent.SmallImageList = _tableIcons;
            lvwBoth.SmallImageList = _tableIcons;
            lvwWatch.SmallImageList = _tableIcons;
        }


        private void tsmiOpenPacket_Click(object sender, EventArgs e)
        {
            ListView list = (ListView) tabControlMain.TabPages[tabControlMain.SelectedIndex].Controls[0];
            var index = list.SelectedIndices[0];
            var id = GetPacketIdFromTableItemIndex(list, index);
            var packet = PacketManager.PacketList[id];
            Form showPacketForm = new ShowPacketForm(id, packet);
            showPacketForm.Show();
        }

        private void tsmiSendPacket_Click(object sender, EventArgs e)
        {
            ListView list = (ListView)tabControlMain.TabPages[tabControlMain.SelectedIndex].Controls[0];
            var index = list.SelectedIndices[0];
            var id = GetPacketIdFromTableItemIndex(list, index);
            var packet = PacketManager.PacketList[id];
            Form injectForm = new PacketInjectorForm("Send " + id, true, packet);
            injectForm.Show();

        }

        private void tsmiAddToSendList_Click(object sender, EventArgs e)
        {
            ListView list = (ListView)tabControlMain.TabPages[tabControlMain.SelectedIndex].Controls[0];
            var index = list.SelectedIndices[0];
            var id = GetPacketIdFromTableItemIndex(list, index);
            var packet = PacketManager.PacketList[id];
            SendManager.AddToList("Send " + id, false, packet);
            tabControlCapturesAndFilters.SelectTab("tabSendList");
        }

        private void tsmiGenerateFilter_Click(object sender, EventArgs e)
        {
            ListView list = (ListView)tabControlMain.TabPages[tabControlMain.SelectedIndex].Controls[0];
            var index = list.SelectedIndices[0];
            var id = GetPacketIdFromTableItemIndex(list, index);
            var packet = PacketManager.PacketList[id];
            var filterForm = new FilterEditorForm();
            filterForm.LoadSearchData(packet.Data);
        }
    }
}
