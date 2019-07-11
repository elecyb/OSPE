namespace OSPE
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.menuStripMain = new System.Windows.Forms.MenuStrip();
            this.programToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiMenuSelectProcess = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiMenuInjectLast = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmiMenuExit = new System.Windows.Forms.ToolStripMenuItem();
            this.captureToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiMenuStartCapture = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiMenuStopCapture = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiClearList = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmiViewAsHex = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiAutoScroll = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator7 = new System.Windows.Forms.ToolStripSeparator();
            this.listToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItemCapture = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItemCapture = new System.Windows.Forms.ToolStripMenuItem();
            this.clearToolStripMenuItem2Capture = new System.Windows.Forms.ToolStripMenuItem();
            this.filtersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiActiveFilters = new System.Windows.Forms.ToolStripMenuItem();
            this.addNewFilterToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator9 = new System.Windows.Forms.ToolStripSeparator();
            this.listToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.clearToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.scriptsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiPacketInjector = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiScriptEditor = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator12 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmiActiveCustomFilters = new System.Windows.Forms.ToolStripMenuItem();
            this.settingsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.displayQuickBarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewLogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator11 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmiMenuConfigure = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.statusStripMain = new System.Windows.Forms.StatusStrip();
            this.tslNumPacketsLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslNumPackets = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslTotalReceivedLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslTotalReceived = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslTotalReceivedUnit = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslTotalSentLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslTotalSent = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslTotalSentUnit = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslTesting = new System.Windows.Forms.ToolStripStatusLabel();
            this.tslTesting2 = new System.Windows.Forms.ToolStripStatusLabel();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.notifyIcon = new System.Windows.Forms.NotifyIcon(this.components);
            this.trayMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.trayTsmiOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.trayTsmiStartCapture = new System.Windows.Forms.ToolStripMenuItem();
            this.trayTsmiStopCapture = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.trayTsmiSelectProcess = new System.Windows.Forms.ToolStripMenuItem();
            this.trayTsmiInjectLastProc = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.trayTsmiActiveFilters = new System.Windows.Forms.ToolStripMenuItem();
            this.trayTsmiActiveCustomFilter = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.trayTsmiExit = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnSearch = new System.Windows.Forms.Button();
            this.radioSearchHex = new System.Windows.Forms.RadioButton();
            this.radioSearchString = new System.Windows.Forms.RadioButton();
            this.btnStopCapture = new System.Windows.Forms.Button();
            this.txtSearch = new System.Windows.Forms.TextBox();
            this.checkBoxViewAsHex = new System.Windows.Forms.CheckBox();
            this.btnClearPacketList = new System.Windows.Forms.Button();
            this.chkActiveCustomScript = new System.Windows.Forms.CheckBox();
            this.chkActiveFilters = new System.Windows.Forms.CheckBox();
            this.chkAutoScroll = new System.Windows.Forms.CheckBox();
            this.btnStartPauseCapture = new System.Windows.Forms.Button();
            this.splitContainerFiltersAndBody = new System.Windows.Forms.SplitContainer();
            this.splitFilterAndConversions = new System.Windows.Forms.SplitContainer();
            this.tabControlCapturesAndFilters = new System.Windows.Forms.TabControl();
            this.tabCaptures = new System.Windows.Forms.TabPage();
            this.lvCaptures = new System.Windows.Forms.ListView();
            this.colCaptureName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.cmsCaptures = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tsmiCaptureOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiCaptureDelete = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator13 = new System.Windows.Forms.ToolStripSeparator();
            this.listToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiCaptureListSave = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiCaptureListLoad = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiCaptureListClear = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiCaptureListExportHTMLascii = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiCaptureListExportHTMLhex = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiCaptureListExportTXTascii = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiCaptureListExportTXThex = new System.Windows.Forms.ToolStripMenuItem();
            this.tabFilters = new System.Windows.Forms.TabPage();
            this.lvFilters = new System.Windows.Forms.ListView();
            this.colName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.cmsFilters = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tsmiFilterListAddNew = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiFilterListEdit = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiFilterListDelete = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator10 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmiFilterListList = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiFilterListListOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiFilterListListSave = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiFilterListListSaveAs = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiFilterListListClear = new System.Windows.Forms.ToolStripMenuItem();
            this.tabSendList = new System.Windows.Forms.TabPage();
            this.lvSendList = new System.Windows.Forms.ListView();
            this.colSendList = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.cmsSendList = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tsmiSendListIEdit = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiSendListDelete = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiSendListSelection = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
            this.tsmiSendListListOptions = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiSendListListLoad = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiSendListListSave = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiSendListListClear = new System.Windows.Forms.ToolStripMenuItem();
            this.groupConversions = new System.Windows.Forms.GroupBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.txtConverDouble = new System.Windows.Forms.TextBox();
            this.txtConverFloat = new System.Windows.Forms.TextBox();
            this.txtConverUInt64 = new System.Windows.Forms.TextBox();
            this.txtConverInt64 = new System.Windows.Forms.TextBox();
            this.txtConverUInt32 = new System.Windows.Forms.TextBox();
            this.txtConverInt32 = new System.Windows.Forms.TextBox();
            this.txtConverUShort = new System.Windows.Forms.TextBox();
            this.txtConverShort = new System.Windows.Forms.TextBox();
            this.txtConverByte = new System.Windows.Forms.TextBox();
            this.txtConverChar = new System.Windows.Forms.TextBox();
            this.txtConverPos = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.lblConverDouble = new System.Windows.Forms.Label();
            this.lblConverFloat = new System.Windows.Forms.Label();
            this.lblConverUInt64 = new System.Windows.Forms.Label();
            this.lblConverInt64 = new System.Windows.Forms.Label();
            this.lblConverULong = new System.Windows.Forms.Label();
            this.lblConverLong = new System.Windows.Forms.Label();
            this.lblConverUShort = new System.Windows.Forms.Label();
            this.lblConverShort = new System.Windows.Forms.Label();
            this.lblConverByte = new System.Windows.Forms.Label();
            this.lblConverChar = new System.Windows.Forms.Label();
            this.lblConverPos = new System.Windows.Forms.Label();
            this.splitContainerTabsAndHex = new System.Windows.Forms.SplitContainer();
            this.tabControlMain = new System.Windows.Forms.TabControl();
            this.tabBoth = new System.Windows.Forms.TabPage();
            this.lvwBoth = new System.Windows.Forms.ListView();
            this.colBothPacket = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colBothSource = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colBothDestination = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colBothFunction = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colBothSize = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colBothData = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.tabReceived = new System.Windows.Forms.TabPage();
            this.lvwReceived = new System.Windows.Forms.ListView();
            this.colReceivedPacket = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colReceivedSource = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colReceivedDestination = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colRecivedFunction = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colReceivedSize = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colReceivedData = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.tabSent = new System.Windows.Forms.TabPage();
            this.lvwSent = new System.Windows.Forms.ListView();
            this.colSentPacket = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colSentSource = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colSentDestination = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colSentFunction = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colSentSize = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colSentData = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.tabWatch = new System.Windows.Forms.TabPage();
            this.lvwWatch = new System.Windows.Forms.ListView();
            this.colWatchPacket = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colWatchSource = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colWatchDestination = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colWatchFunction = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colWatchSize = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colWatchData = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.hexBox = new Be.Windows.Forms.HexBox();
            this.cmsPacketOptions = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tsmiOpenPacket = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiSendPacket = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiAddToSendList = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmiGenerateFilter = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStripMain.SuspendLayout();
            this.statusStripMain.SuspendLayout();
            this.trayMenuStrip.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerFiltersAndBody)).BeginInit();
            this.splitContainerFiltersAndBody.Panel1.SuspendLayout();
            this.splitContainerFiltersAndBody.Panel2.SuspendLayout();
            this.splitContainerFiltersAndBody.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitFilterAndConversions)).BeginInit();
            this.splitFilterAndConversions.Panel1.SuspendLayout();
            this.splitFilterAndConversions.Panel2.SuspendLayout();
            this.splitFilterAndConversions.SuspendLayout();
            this.tabControlCapturesAndFilters.SuspendLayout();
            this.tabCaptures.SuspendLayout();
            this.cmsCaptures.SuspendLayout();
            this.tabFilters.SuspendLayout();
            this.cmsFilters.SuspendLayout();
            this.tabSendList.SuspendLayout();
            this.cmsSendList.SuspendLayout();
            this.groupConversions.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerTabsAndHex)).BeginInit();
            this.splitContainerTabsAndHex.Panel1.SuspendLayout();
            this.splitContainerTabsAndHex.Panel2.SuspendLayout();
            this.splitContainerTabsAndHex.SuspendLayout();
            this.tabControlMain.SuspendLayout();
            this.tabBoth.SuspendLayout();
            this.tabReceived.SuspendLayout();
            this.tabSent.SuspendLayout();
            this.tabWatch.SuspendLayout();
            this.cmsPacketOptions.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStripMain
            // 
            this.menuStripMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.programToolStripMenuItem,
            this.captureToolStripMenuItem,
            this.filtersToolStripMenuItem,
            this.scriptsToolStripMenuItem,
            this.settingsToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStripMain.Location = new System.Drawing.Point(0, 0);
            this.menuStripMain.Name = "menuStripMain";
            this.menuStripMain.Padding = new System.Windows.Forms.Padding(6, 2, 0, 0);
            this.menuStripMain.Size = new System.Drawing.Size(799, 24);
            this.menuStripMain.TabIndex = 0;
            this.menuStripMain.Text = "menuStrip1";
            // 
            // programToolStripMenuItem
            // 
            this.programToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiMenuSelectProcess,
            this.tsmiMenuInjectLast,
            this.toolStripSeparator2,
            this.tsmiMenuExit});
            this.programToolStripMenuItem.ForeColor = System.Drawing.Color.Black;
            this.programToolStripMenuItem.Name = "programToolStripMenuItem";
            this.programToolStripMenuItem.Size = new System.Drawing.Size(65, 22);
            this.programToolStripMenuItem.Text = "Program";
            this.programToolStripMenuItem.Click += new System.EventHandler(this.tsmiProgram_Click);
            // 
            // tsmiMenuSelectProcess
            // 
            this.tsmiMenuSelectProcess.Image = global::OSPE.Properties.Resources.Magnifying_glass16;
            this.tsmiMenuSelectProcess.Name = "tsmiMenuSelectProcess";
            this.tsmiMenuSelectProcess.Size = new System.Drawing.Size(170, 22);
            this.tsmiMenuSelectProcess.Text = "Select Process";
            this.tsmiMenuSelectProcess.Click += new System.EventHandler(this.tsmiSelectProcess_Click);
            // 
            // tsmiMenuInjectLast
            // 
            this.tsmiMenuInjectLast.Image = global::OSPE.Properties.Resources.Counterclockwise_arrow16;
            this.tsmiMenuInjectLast.Name = "tsmiMenuInjectLast";
            this.tsmiMenuInjectLast.Size = new System.Drawing.Size(170, 22);
            this.tsmiMenuInjectLast.Text = "Inject Last Process";
            this.tsmiMenuInjectLast.Click += new System.EventHandler(this.tsmiInjectLast_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(167, 6);
            // 
            // tsmiMenuExit
            // 
            this.tsmiMenuExit.Image = global::OSPE.Properties.Resources.logout24;
            this.tsmiMenuExit.Name = "tsmiMenuExit";
            this.tsmiMenuExit.Size = new System.Drawing.Size(170, 22);
            this.tsmiMenuExit.Text = "Exit";
            this.tsmiMenuExit.Click += new System.EventHandler(this.tsmiExit_Click);
            // 
            // captureToolStripMenuItem
            // 
            this.captureToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiMenuStartCapture,
            this.tsmiMenuStopCapture,
            this.tsmiClearList,
            this.toolStripSeparator1,
            this.tsmiViewAsHex,
            this.tsmiAutoScroll,
            this.toolStripSeparator7,
            this.listToolStripMenuItem2});
            this.captureToolStripMenuItem.Name = "captureToolStripMenuItem";
            this.captureToolStripMenuItem.Size = new System.Drawing.Size(61, 22);
            this.captureToolStripMenuItem.Text = "Capture";
            // 
            // tsmiMenuStartCapture
            // 
            this.tsmiMenuStartCapture.Image = global::OSPE.Properties.Resources.Play16;
            this.tsmiMenuStartCapture.Name = "tsmiMenuStartCapture";
            this.tsmiMenuStartCapture.Size = new System.Drawing.Size(143, 22);
            this.tsmiMenuStartCapture.Text = "Start Capture";
            // 
            // tsmiMenuStopCapture
            // 
            this.tsmiMenuStopCapture.Image = global::OSPE.Properties.Resources.Stop16;
            this.tsmiMenuStopCapture.Name = "tsmiMenuStopCapture";
            this.tsmiMenuStopCapture.Size = new System.Drawing.Size(143, 22);
            this.tsmiMenuStopCapture.Text = "Stop Capture";
            // 
            // tsmiClearList
            // 
            this.tsmiClearList.Image = global::OSPE.Properties.Resources.Delete216;
            this.tsmiClearList.Name = "tsmiClearList";
            this.tsmiClearList.Size = new System.Drawing.Size(143, 22);
            this.tsmiClearList.Text = "Clear";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(140, 6);
            // 
            // tsmiViewAsHex
            // 
            this.tsmiViewAsHex.CheckOnClick = true;
            this.tsmiViewAsHex.Name = "tsmiViewAsHex";
            this.tsmiViewAsHex.Size = new System.Drawing.Size(143, 22);
            this.tsmiViewAsHex.Text = "View as Hex";
            this.tsmiViewAsHex.Click += new System.EventHandler(this.tsmiViewAsHex_Click);
            // 
            // tsmiAutoScroll
            // 
            this.tsmiAutoScroll.CheckOnClick = true;
            this.tsmiAutoScroll.Name = "tsmiAutoScroll";
            this.tsmiAutoScroll.Size = new System.Drawing.Size(143, 22);
            this.tsmiAutoScroll.Text = "Auto Scroll";
            this.tsmiAutoScroll.Click += new System.EventHandler(this.tsmiAutoScroll_Click);
            // 
            // toolStripSeparator7
            // 
            this.toolStripSeparator7.Name = "toolStripSeparator7";
            this.toolStripSeparator7.Size = new System.Drawing.Size(140, 6);
            // 
            // listToolStripMenuItem2
            // 
            this.listToolStripMenuItem2.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveToolStripMenuItemCapture,
            this.loadToolStripMenuItemCapture,
            this.clearToolStripMenuItem2Capture});
            this.listToolStripMenuItem2.Name = "listToolStripMenuItem2";
            this.listToolStripMenuItem2.Size = new System.Drawing.Size(143, 22);
            this.listToolStripMenuItem2.Text = "List";
            // 
            // saveToolStripMenuItemCapture
            // 
            this.saveToolStripMenuItemCapture.Name = "saveToolStripMenuItemCapture";
            this.saveToolStripMenuItemCapture.Size = new System.Drawing.Size(101, 22);
            this.saveToolStripMenuItemCapture.Text = "Save";
            this.saveToolStripMenuItemCapture.Click += new System.EventHandler(this.tsmiCaptureListSave_Click);
            // 
            // loadToolStripMenuItemCapture
            // 
            this.loadToolStripMenuItemCapture.Name = "loadToolStripMenuItemCapture";
            this.loadToolStripMenuItemCapture.Size = new System.Drawing.Size(101, 22);
            this.loadToolStripMenuItemCapture.Text = "Load";
            this.loadToolStripMenuItemCapture.Click += new System.EventHandler(this.tsmiCaptureListLoad_Click);
            // 
            // clearToolStripMenuItem2Capture
            // 
            this.clearToolStripMenuItem2Capture.Name = "clearToolStripMenuItem2Capture";
            this.clearToolStripMenuItem2Capture.Size = new System.Drawing.Size(101, 22);
            this.clearToolStripMenuItem2Capture.Text = "Clear";
            this.clearToolStripMenuItem2Capture.Click += new System.EventHandler(this.tsmiCaptureListClear_Click);
            // 
            // filtersToolStripMenuItem
            // 
            this.filtersToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiActiveFilters,
            this.addNewFilterToolStripMenuItem,
            this.toolStripSeparator9,
            this.listToolStripMenuItem1});
            this.filtersToolStripMenuItem.ForeColor = System.Drawing.Color.Black;
            this.filtersToolStripMenuItem.Name = "filtersToolStripMenuItem";
            this.filtersToolStripMenuItem.Size = new System.Drawing.Size(50, 22);
            this.filtersToolStripMenuItem.Text = "Filters";
            // 
            // tsmiActiveFilters
            // 
            this.tsmiActiveFilters.CheckOnClick = true;
            this.tsmiActiveFilters.Name = "tsmiActiveFilters";
            this.tsmiActiveFilters.Size = new System.Drawing.Size(152, 22);
            this.tsmiActiveFilters.Text = "Active Filters";
            this.tsmiActiveFilters.Click += new System.EventHandler(this.tsmiActiveFilters_CheckedChanged);
            // 
            // addNewFilterToolStripMenuItem
            // 
            this.addNewFilterToolStripMenuItem.Name = "addNewFilterToolStripMenuItem";
            this.addNewFilterToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.addNewFilterToolStripMenuItem.Text = "Add New Filter";
            this.addNewFilterToolStripMenuItem.Click += new System.EventHandler(this.tsmiFilterListAddNew_Click);
            // 
            // toolStripSeparator9
            // 
            this.toolStripSeparator9.Name = "toolStripSeparator9";
            this.toolStripSeparator9.Size = new System.Drawing.Size(149, 6);
            // 
            // listToolStripMenuItem1
            // 
            this.listToolStripMenuItem1.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem1,
            this.saveToolStripMenuItem1,
            this.saveAsToolStripMenuItem2,
            this.clearToolStripMenuItem1});
            this.listToolStripMenuItem1.Name = "listToolStripMenuItem1";
            this.listToolStripMenuItem1.Size = new System.Drawing.Size(152, 22);
            this.listToolStripMenuItem1.Text = "List";
            // 
            // openToolStripMenuItem1
            // 
            this.openToolStripMenuItem1.Name = "openToolStripMenuItem1";
            this.openToolStripMenuItem1.Size = new System.Drawing.Size(111, 22);
            this.openToolStripMenuItem1.Text = "Open";
            this.openToolStripMenuItem1.Click += new System.EventHandler(this.tsmiFilterListLoad_Click);
            // 
            // saveToolStripMenuItem1
            // 
            this.saveToolStripMenuItem1.Name = "saveToolStripMenuItem1";
            this.saveToolStripMenuItem1.Size = new System.Drawing.Size(111, 22);
            this.saveToolStripMenuItem1.Text = "Save";
            this.saveToolStripMenuItem1.Click += new System.EventHandler(this.tsmiFilterListSave_Click);
            // 
            // saveAsToolStripMenuItem2
            // 
            this.saveAsToolStripMenuItem2.Name = "saveAsToolStripMenuItem2";
            this.saveAsToolStripMenuItem2.Size = new System.Drawing.Size(111, 22);
            this.saveAsToolStripMenuItem2.Text = "SaveAs";
            this.saveAsToolStripMenuItem2.Click += new System.EventHandler(this.tsmiFilterListSave_Click);
            // 
            // clearToolStripMenuItem1
            // 
            this.clearToolStripMenuItem1.Name = "clearToolStripMenuItem1";
            this.clearToolStripMenuItem1.Size = new System.Drawing.Size(111, 22);
            this.clearToolStripMenuItem1.Text = "Clear";
            this.clearToolStripMenuItem1.Click += new System.EventHandler(this.tsmiFilterListClear_Click);
            // 
            // scriptsToolStripMenuItem
            // 
            this.scriptsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiPacketInjector,
            this.tsmiScriptEditor,
            this.toolStripSeparator12,
            this.tsmiActiveCustomFilters});
            this.scriptsToolStripMenuItem.ForeColor = System.Drawing.Color.Black;
            this.scriptsToolStripMenuItem.Name = "scriptsToolStripMenuItem";
            this.scriptsToolStripMenuItem.Size = new System.Drawing.Size(72, 22);
            this.scriptsToolStripMenuItem.Text = "Advanced";
            // 
            // tsmiPacketInjector
            // 
            this.tsmiPacketInjector.Name = "tsmiPacketInjector";
            this.tsmiPacketInjector.Size = new System.Drawing.Size(185, 22);
            this.tsmiPacketInjector.Text = "Packet Injector";
            this.tsmiPacketInjector.Click += new System.EventHandler(this.tsmiPacketInjector_Click);
            // 
            // tsmiScriptEditor
            // 
            this.tsmiScriptEditor.Name = "tsmiScriptEditor";
            this.tsmiScriptEditor.Size = new System.Drawing.Size(185, 22);
            this.tsmiScriptEditor.Text = "Script Editor";
            this.tsmiScriptEditor.Click += new System.EventHandler(this.tsmiScriptEditor_Click);
            // 
            // toolStripSeparator12
            // 
            this.toolStripSeparator12.Name = "toolStripSeparator12";
            this.toolStripSeparator12.Size = new System.Drawing.Size(182, 6);
            // 
            // tsmiActiveCustomFilters
            // 
            this.tsmiActiveCustomFilters.CheckOnClick = true;
            this.tsmiActiveCustomFilters.Name = "tsmiActiveCustomFilters";
            this.tsmiActiveCustomFilters.Size = new System.Drawing.Size(185, 22);
            this.tsmiActiveCustomFilters.Text = "Active Custom Script";
            this.tsmiActiveCustomFilters.Click += new System.EventHandler(this.tsmiActiveCustomFilters_CheckStateChanged);
            // 
            // settingsToolStripMenuItem
            // 
            this.settingsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.displayQuickBarToolStripMenuItem,
            this.viewLogToolStripMenuItem,
            this.toolStripSeparator11,
            this.tsmiMenuConfigure});
            this.settingsToolStripMenuItem.ForeColor = System.Drawing.Color.Black;
            this.settingsToolStripMenuItem.Name = "settingsToolStripMenuItem";
            this.settingsToolStripMenuItem.Size = new System.Drawing.Size(61, 22);
            this.settingsToolStripMenuItem.Text = "Options";
            // 
            // displayQuickBarToolStripMenuItem
            // 
            this.displayQuickBarToolStripMenuItem.CheckOnClick = true;
            this.displayQuickBarToolStripMenuItem.Name = "displayQuickBarToolStripMenuItem";
            this.displayQuickBarToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.displayQuickBarToolStripMenuItem.Text = "Hide Quick Bar";
            this.displayQuickBarToolStripMenuItem.Click += new System.EventHandler(this.tsmiDisplayQuickBar_Click);
            // 
            // viewLogToolStripMenuItem
            // 
            this.viewLogToolStripMenuItem.Image = global::OSPE.Properties.Resources.File_info16;
            this.viewLogToolStripMenuItem.Name = "viewLogToolStripMenuItem";
            this.viewLogToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.viewLogToolStripMenuItem.Text = "Open Log";
            this.viewLogToolStripMenuItem.Click += new System.EventHandler(this.tsmiViewLog_Click);
            // 
            // toolStripSeparator11
            // 
            this.toolStripSeparator11.Name = "toolStripSeparator11";
            this.toolStripSeparator11.Size = new System.Drawing.Size(177, 6);
            // 
            // tsmiMenuConfigure
            // 
            this.tsmiMenuConfigure.Image = global::OSPE.Properties.Resources.Maintenance16;
            this.tsmiMenuConfigure.Name = "tsmiMenuConfigure";
            this.tsmiMenuConfigure.Size = new System.Drawing.Size(180, 22);
            this.tsmiMenuConfigure.Text = "Configure";
            this.tsmiMenuConfigure.Click += new System.EventHandler(this.tsmiConfigure_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.ForeColor = System.Drawing.Color.Black;
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 22);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Image = global::OSPE.Properties.Resources.Info16;
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // statusStripMain
            // 
            this.statusStripMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tslNumPacketsLabel,
            this.tslNumPackets,
            this.tslTotalReceivedLabel,
            this.tslTotalReceived,
            this.tslTotalReceivedUnit,
            this.tslTotalSentLabel,
            this.tslTotalSent,
            this.tslTotalSentUnit,
            this.tslTesting,
            this.tslTesting2});
            this.statusStripMain.Location = new System.Drawing.Point(0, 607);
            this.statusStripMain.Name = "statusStripMain";
            this.statusStripMain.Size = new System.Drawing.Size(799, 22);
            this.statusStripMain.TabIndex = 7;
            this.statusStripMain.Text = "statusStrip";
            // 
            // tslNumPacketsLabel
            // 
            this.tslNumPacketsLabel.Name = "tslNumPacketsLabel";
            this.tslNumPacketsLabel.Size = new System.Drawing.Size(50, 17);
            this.tslNumPacketsLabel.Text = "Packets:";
            // 
            // tslNumPackets
            // 
            this.tslNumPackets.BackColor = System.Drawing.Color.Transparent;
            this.tslNumPackets.ForeColor = System.Drawing.Color.Black;
            this.tslNumPackets.Name = "tslNumPackets";
            this.tslNumPackets.Size = new System.Drawing.Size(13, 17);
            this.tslNumPackets.Text = "0";
            // 
            // tslTotalReceivedLabel
            // 
            this.tslTotalReceivedLabel.Name = "tslTotalReceivedLabel";
            this.tslTotalReceivedLabel.Size = new System.Drawing.Size(57, 17);
            this.tslTotalReceivedLabel.Text = "Received:";
            // 
            // tslTotalReceived
            // 
            this.tslTotalReceived.Name = "tslTotalReceived";
            this.tslTotalReceived.Size = new System.Drawing.Size(13, 17);
            this.tslTotalReceived.Text = "0";
            // 
            // tslTotalReceivedUnit
            // 
            this.tslTotalReceivedUnit.Name = "tslTotalReceivedUnit";
            this.tslTotalReceivedUnit.Size = new System.Drawing.Size(14, 17);
            this.tslTotalReceivedUnit.Text = "B";
            // 
            // tslTotalSentLabel
            // 
            this.tslTotalSentLabel.Name = "tslTotalSentLabel";
            this.tslTotalSentLabel.Size = new System.Drawing.Size(33, 17);
            this.tslTotalSentLabel.Text = "Sent:";
            // 
            // tslTotalSent
            // 
            this.tslTotalSent.Name = "tslTotalSent";
            this.tslTotalSent.Size = new System.Drawing.Size(13, 17);
            this.tslTotalSent.Text = "0";
            // 
            // tslTotalSentUnit
            // 
            this.tslTotalSentUnit.Name = "tslTotalSentUnit";
            this.tslTotalSentUnit.Size = new System.Drawing.Size(14, 17);
            this.tslTotalSentUnit.Text = "B";
            // 
            // tslTesting
            // 
            this.tslTesting.Name = "tslTesting";
            this.tslTesting.Size = new System.Drawing.Size(0, 17);
            // 
            // tslTesting2
            // 
            this.tslTesting2.Name = "tslTesting2";
            this.tslTesting2.Size = new System.Drawing.Size(0, 17);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "openFileDialog1";
            // 
            // notifyIcon
            // 
            this.notifyIcon.Icon = ((System.Drawing.Icon)(resources.GetObject("notifyIcon.Icon")));
            this.notifyIcon.Text = "notifyIcon1";
            this.notifyIcon.Visible = true;
            this.notifyIcon.Click += new System.EventHandler(this.trayIcon_Click);
            // 
            // trayMenuStrip
            // 
            this.trayMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.trayTsmiOpen,
            this.toolStripSeparator3,
            this.trayTsmiStartCapture,
            this.trayTsmiStopCapture,
            this.toolStripSeparator4,
            this.trayTsmiSelectProcess,
            this.trayTsmiInjectLastProc,
            this.toolStripSeparator5,
            this.trayTsmiActiveFilters,
            this.trayTsmiActiveCustomFilter,
            this.toolStripSeparator6,
            this.trayTsmiExit});
            this.trayMenuStrip.Name = "contextMenuStrip1";
            this.trayMenuStrip.Size = new System.Drawing.Size(182, 204);
            // 
            // trayTsmiOpen
            // 
            this.trayTsmiOpen.Name = "trayTsmiOpen";
            this.trayTsmiOpen.Size = new System.Drawing.Size(181, 22);
            this.trayTsmiOpen.Text = "Open";
            this.trayTsmiOpen.Click += new System.EventHandler(this.trayMenuOpen_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(178, 6);
            // 
            // trayTsmiStartCapture
            // 
            this.trayTsmiStartCapture.Name = "trayTsmiStartCapture";
            this.trayTsmiStartCapture.Size = new System.Drawing.Size(181, 22);
            this.trayTsmiStartCapture.Text = "Start Capture";
            this.trayTsmiStartCapture.Click += new System.EventHandler(this.tsmiStartCapture_Click);
            // 
            // trayTsmiStopCapture
            // 
            this.trayTsmiStopCapture.Enabled = false;
            this.trayTsmiStopCapture.Name = "trayTsmiStopCapture";
            this.trayTsmiStopCapture.Size = new System.Drawing.Size(181, 22);
            this.trayTsmiStopCapture.Text = "Stop Capture";
            this.trayTsmiStopCapture.Click += new System.EventHandler(this.tsmiStopCapture_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(178, 6);
            // 
            // trayTsmiSelectProcess
            // 
            this.trayTsmiSelectProcess.Name = "trayTsmiSelectProcess";
            this.trayTsmiSelectProcess.Size = new System.Drawing.Size(181, 22);
            this.trayTsmiSelectProcess.Text = "Select Process";
            this.trayTsmiSelectProcess.Click += new System.EventHandler(this.tsmiSelectProcess_Click);
            // 
            // trayTsmiInjectLastProc
            // 
            this.trayTsmiInjectLastProc.Name = "trayTsmiInjectLastProc";
            this.trayTsmiInjectLastProc.Size = new System.Drawing.Size(181, 22);
            this.trayTsmiInjectLastProc.Text = "Inject .....";
            this.trayTsmiInjectLastProc.Click += new System.EventHandler(this.tsmiInjectLast_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(178, 6);
            // 
            // trayTsmiActiveFilters
            // 
            this.trayTsmiActiveFilters.CheckOnClick = true;
            this.trayTsmiActiveFilters.Name = "trayTsmiActiveFilters";
            this.trayTsmiActiveFilters.Size = new System.Drawing.Size(181, 22);
            this.trayTsmiActiveFilters.Text = "Active Filters";
            this.trayTsmiActiveFilters.Click += new System.EventHandler(this.tsmiActiveFilters_CheckedChanged);
            // 
            // trayTsmiActiveCustomFilter
            // 
            this.trayTsmiActiveCustomFilter.CheckOnClick = true;
            this.trayTsmiActiveCustomFilter.Name = "trayTsmiActiveCustomFilter";
            this.trayTsmiActiveCustomFilter.Size = new System.Drawing.Size(181, 22);
            this.trayTsmiActiveCustomFilter.Text = "Active Custom Filter";
            this.trayTsmiActiveCustomFilter.Click += new System.EventHandler(this.tsmiActiveCustomFilters_CheckStateChanged);
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(178, 6);
            // 
            // trayTsmiExit
            // 
            this.trayTsmiExit.Name = "trayTsmiExit";
            this.trayTsmiExit.Size = new System.Drawing.Size(181, 22);
            this.trayTsmiExit.Text = "Exit";
            this.trayTsmiExit.Click += new System.EventHandler(this.trayMenuExit_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.groupBox1.Controls.Add(this.btnSearch);
            this.groupBox1.Controls.Add(this.radioSearchHex);
            this.groupBox1.Controls.Add(this.radioSearchString);
            this.groupBox1.Controls.Add(this.btnStopCapture);
            this.groupBox1.Controls.Add(this.txtSearch);
            this.groupBox1.Controls.Add(this.checkBoxViewAsHex);
            this.groupBox1.Controls.Add(this.btnClearPacketList);
            this.groupBox1.Controls.Add(this.chkActiveCustomScript);
            this.groupBox1.Controls.Add(this.chkActiveFilters);
            this.groupBox1.Controls.Add(this.chkAutoScroll);
            this.groupBox1.Controls.Add(this.btnStartPauseCapture);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.groupBox1.Location = new System.Drawing.Point(0, 24);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(3, 0, 3, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(799, 51);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            // 
            // btnSearch
            // 
            this.btnSearch.Image = global::OSPE.Properties.Resources.Search16;
            this.btnSearch.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnSearch.Location = new System.Drawing.Point(563, 12);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(82, 32);
            this.btnSearch.TabIndex = 10;
            this.btnSearch.Text = "Search (F3)";
            this.btnSearch.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.btnSearch_Click);
            // 
            // radioSearchHex
            // 
            this.radioSearchHex.AutoSize = true;
            this.radioSearchHex.Location = new System.Drawing.Point(513, 33);
            this.radioSearchHex.Name = "radioSearchHex";
            this.radioSearchHex.Size = new System.Drawing.Size(44, 17);
            this.radioSearchHex.TabIndex = 9;
            this.radioSearchHex.Text = "Hex";
            this.radioSearchHex.UseVisualStyleBackColor = true;
            this.radioSearchHex.CheckedChanged += new System.EventHandler(this.radioSearchHex_CheckedChanged);
            // 
            // radioSearchString
            // 
            this.radioSearchString.AutoSize = true;
            this.radioSearchString.Checked = true;
            this.radioSearchString.Location = new System.Drawing.Point(455, 33);
            this.radioSearchString.Name = "radioSearchString";
            this.radioSearchString.Size = new System.Drawing.Size(52, 17);
            this.radioSearchString.TabIndex = 8;
            this.radioSearchString.TabStop = true;
            this.radioSearchString.Text = "String";
            this.radioSearchString.UseVisualStyleBackColor = true;
            this.radioSearchString.CheckedChanged += new System.EventHandler(this.radioSearchString_CheckedChanged);
            // 
            // btnStopCapture
            // 
            this.btnStopCapture.Enabled = false;
            this.btnStopCapture.Image = global::OSPE.Properties.Resources.Stop16;
            this.btnStopCapture.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnStopCapture.Location = new System.Drawing.Point(209, 12);
            this.btnStopCapture.Name = "btnStopCapture";
            this.btnStopCapture.Size = new System.Drawing.Size(92, 32);
            this.btnStopCapture.TabIndex = 7;
            this.btnStopCapture.Text = "Stop Capture";
            this.btnStopCapture.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnStopCapture.UseVisualStyleBackColor = true;
            this.btnStopCapture.Click += new System.EventHandler(this.btnStopCapture_Click);
            // 
            // txtSearch
            // 
            this.txtSearch.Location = new System.Drawing.Point(455, 12);
            this.txtSearch.Name = "txtSearch";
            this.txtSearch.Size = new System.Drawing.Size(102, 20);
            this.txtSearch.TabIndex = 6;
            this.txtSearch.Text = "Search...";
            this.txtSearch.Enter += new System.EventHandler(this.txtSearch_Enter);
            // 
            // checkBoxViewAsHex
            // 
            this.checkBoxViewAsHex.AutoSize = true;
            this.checkBoxViewAsHex.Location = new System.Drawing.Point(372, 12);
            this.checkBoxViewAsHex.Name = "checkBoxViewAsHex";
            this.checkBoxViewAsHex.Size = new System.Drawing.Size(80, 17);
            this.checkBoxViewAsHex.TabIndex = 5;
            this.checkBoxViewAsHex.Text = "ViewAsHex";
            this.checkBoxViewAsHex.UseVisualStyleBackColor = true;
            this.checkBoxViewAsHex.CheckedChanged += new System.EventHandler(this.checkBoxViewAsHex_CheckedChanged);
            // 
            // btnClearPacketList
            // 
            this.btnClearPacketList.Enabled = false;
            this.btnClearPacketList.Image = global::OSPE.Properties.Resources.Delete216;
            this.btnClearPacketList.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnClearPacketList.Location = new System.Drawing.Point(307, 12);
            this.btnClearPacketList.Name = "btnClearPacketList";
            this.btnClearPacketList.Size = new System.Drawing.Size(57, 32);
            this.btnClearPacketList.TabIndex = 4;
            this.btnClearPacketList.Text = "Clear";
            this.btnClearPacketList.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnClearPacketList.UseVisualStyleBackColor = true;
            this.btnClearPacketList.Click += new System.EventHandler(this.buttonClearList_Click);
            // 
            // chkActiveCustomScript
            // 
            this.chkActiveCustomScript.AutoSize = true;
            this.chkActiveCustomScript.Location = new System.Drawing.Point(5, 28);
            this.chkActiveCustomScript.Name = "chkActiveCustomScript";
            this.chkActiveCustomScript.Size = new System.Drawing.Size(86, 17);
            this.chkActiveCustomScript.TabIndex = 3;
            this.chkActiveCustomScript.Text = "Active Script";
            this.chkActiveCustomScript.UseVisualStyleBackColor = true;
            this.chkActiveCustomScript.CheckedChanged += new System.EventHandler(this.chkActiveCustomScript_CheckedChanged);
            // 
            // chkActiveFilters
            // 
            this.chkActiveFilters.AutoSize = true;
            this.chkActiveFilters.Location = new System.Drawing.Point(5, 12);
            this.chkActiveFilters.Name = "chkActiveFilters";
            this.chkActiveFilters.Size = new System.Drawing.Size(86, 17);
            this.chkActiveFilters.TabIndex = 2;
            this.chkActiveFilters.Text = "Active Filters";
            this.chkActiveFilters.UseVisualStyleBackColor = true;
            this.chkActiveFilters.CheckedChanged += new System.EventHandler(this.chkActiveFilters_CheckedChanged);
            // 
            // chkAutoScroll
            // 
            this.chkAutoScroll.AutoSize = true;
            this.chkAutoScroll.Location = new System.Drawing.Point(372, 30);
            this.chkAutoScroll.Name = "chkAutoScroll";
            this.chkAutoScroll.Size = new System.Drawing.Size(77, 17);
            this.chkAutoScroll.TabIndex = 1;
            this.chkAutoScroll.Text = "Auto Scroll";
            this.chkAutoScroll.UseVisualStyleBackColor = true;
            this.chkAutoScroll.CheckedChanged += new System.EventHandler(this.checkAutoScroll_CheckedChanged);
            // 
            // btnStartPauseCapture
            // 
            this.btnStartPauseCapture.Image = global::OSPE.Properties.Resources.Play16;
            this.btnStartPauseCapture.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnStartPauseCapture.Location = new System.Drawing.Point(103, 12);
            this.btnStartPauseCapture.Name = "btnStartPauseCapture";
            this.btnStartPauseCapture.Size = new System.Drawing.Size(100, 32);
            this.btnStartPauseCapture.TabIndex = 0;
            this.btnStartPauseCapture.Text = "Start Capture";
            this.btnStartPauseCapture.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnStartPauseCapture.UseVisualStyleBackColor = true;
            this.btnStartPauseCapture.Click += new System.EventHandler(this.btnStartPauseCapture_Click);
            // 
            // splitContainerFiltersAndBody
            // 
            this.splitContainerFiltersAndBody.BackColor = System.Drawing.SystemColors.Control;
            this.splitContainerFiltersAndBody.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainerFiltersAndBody.Location = new System.Drawing.Point(0, 75);
            this.splitContainerFiltersAndBody.Name = "splitContainerFiltersAndBody";
            // 
            // splitContainerFiltersAndBody.Panel1
            // 
            this.splitContainerFiltersAndBody.Panel1.BackColor = System.Drawing.SystemColors.Control;
            this.splitContainerFiltersAndBody.Panel1.Controls.Add(this.splitFilterAndConversions);
            this.splitContainerFiltersAndBody.Panel1MinSize = 120;
            // 
            // splitContainerFiltersAndBody.Panel2
            // 
            this.splitContainerFiltersAndBody.Panel2.Controls.Add(this.splitContainerTabsAndHex);
            this.splitContainerFiltersAndBody.Size = new System.Drawing.Size(799, 532);
            this.splitContainerFiltersAndBody.SplitterDistance = 150;
            this.splitContainerFiltersAndBody.SplitterWidth = 6;
            this.splitContainerFiltersAndBody.TabIndex = 8;
            // 
            // splitFilterAndConversions
            // 
            this.splitFilterAndConversions.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitFilterAndConversions.Location = new System.Drawing.Point(0, 0);
            this.splitFilterAndConversions.Name = "splitFilterAndConversions";
            this.splitFilterAndConversions.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitFilterAndConversions.Panel1
            // 
            this.splitFilterAndConversions.Panel1.Controls.Add(this.tabControlCapturesAndFilters);
            // 
            // splitFilterAndConversions.Panel2
            // 
            this.splitFilterAndConversions.Panel2.Controls.Add(this.groupConversions);
            this.splitFilterAndConversions.Size = new System.Drawing.Size(150, 532);
            this.splitFilterAndConversions.SplitterDistance = 360;
            this.splitFilterAndConversions.SplitterWidth = 6;
            this.splitFilterAndConversions.TabIndex = 28;
            // 
            // tabControlCapturesAndFilters
            // 
            this.tabControlCapturesAndFilters.Controls.Add(this.tabCaptures);
            this.tabControlCapturesAndFilters.Controls.Add(this.tabFilters);
            this.tabControlCapturesAndFilters.Controls.Add(this.tabSendList);
            this.tabControlCapturesAndFilters.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControlCapturesAndFilters.Location = new System.Drawing.Point(0, 0);
            this.tabControlCapturesAndFilters.Name = "tabControlCapturesAndFilters";
            this.tabControlCapturesAndFilters.SelectedIndex = 0;
            this.tabControlCapturesAndFilters.Size = new System.Drawing.Size(150, 360);
            this.tabControlCapturesAndFilters.TabIndex = 0;
            // 
            // tabCaptures
            // 
            this.tabCaptures.Controls.Add(this.lvCaptures);
            this.tabCaptures.Location = new System.Drawing.Point(4, 22);
            this.tabCaptures.Name = "tabCaptures";
            this.tabCaptures.Padding = new System.Windows.Forms.Padding(3);
            this.tabCaptures.Size = new System.Drawing.Size(142, 334);
            this.tabCaptures.TabIndex = 0;
            this.tabCaptures.Text = "Captures";
            this.tabCaptures.UseVisualStyleBackColor = true;
            // 
            // lvCaptures
            // 
            this.lvCaptures.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colCaptureName});
            this.lvCaptures.ContextMenuStrip = this.cmsCaptures;
            this.lvCaptures.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lvCaptures.GridLines = true;
            this.lvCaptures.Location = new System.Drawing.Point(3, 3);
            this.lvCaptures.MultiSelect = false;
            this.lvCaptures.Name = "lvCaptures";
            this.lvCaptures.Scrollable = false;
            this.lvCaptures.ShowItemToolTips = true;
            this.lvCaptures.Size = new System.Drawing.Size(136, 328);
            this.lvCaptures.TabIndex = 0;
            this.lvCaptures.UseCompatibleStateImageBehavior = false;
            this.lvCaptures.View = System.Windows.Forms.View.Details;
            this.lvCaptures.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.lvCaptures_MouseDoubleClick);
            // 
            // colCaptureName
            // 
            this.colCaptureName.Text = "Name";
            this.colCaptureName.Width = 150;
            // 
            // cmsCaptures
            // 
            this.cmsCaptures.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiCaptureOpen,
            this.tsmiCaptureDelete,
            this.toolStripSeparator13,
            this.listToolStripMenuItem});
            this.cmsCaptures.Name = "cmsCaptures";
            this.cmsCaptures.Size = new System.Drawing.Size(108, 76);
            this.cmsCaptures.Opening += new System.ComponentModel.CancelEventHandler(this.cmsCaptureList_Opening);
            // 
            // tsmiCaptureOpen
            // 
            this.tsmiCaptureOpen.Name = "tsmiCaptureOpen";
            this.tsmiCaptureOpen.Size = new System.Drawing.Size(107, 22);
            this.tsmiCaptureOpen.Text = "Open";
            this.tsmiCaptureOpen.Click += new System.EventHandler(this.tsmiCaptureListOpen_Click);
            // 
            // tsmiCaptureDelete
            // 
            this.tsmiCaptureDelete.Name = "tsmiCaptureDelete";
            this.tsmiCaptureDelete.Size = new System.Drawing.Size(107, 22);
            this.tsmiCaptureDelete.Text = "Delete";
            this.tsmiCaptureDelete.Click += new System.EventHandler(this.tsmiCaptureListDelete_Click);
            // 
            // toolStripSeparator13
            // 
            this.toolStripSeparator13.Name = "toolStripSeparator13";
            this.toolStripSeparator13.Size = new System.Drawing.Size(104, 6);
            // 
            // listToolStripMenuItem
            // 
            this.listToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiCaptureListSave,
            this.tsmiCaptureListLoad,
            this.tsmiCaptureListClear,
            this.exportToolStripMenuItem});
            this.listToolStripMenuItem.Name = "listToolStripMenuItem";
            this.listToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
            this.listToolStripMenuItem.Text = "List";
            // 
            // tsmiCaptureListSave
            // 
            this.tsmiCaptureListSave.Name = "tsmiCaptureListSave";
            this.tsmiCaptureListSave.Size = new System.Drawing.Size(107, 22);
            this.tsmiCaptureListSave.Text = "Save";
            this.tsmiCaptureListSave.Click += new System.EventHandler(this.tsmiCaptureListSave_Click);
            // 
            // tsmiCaptureListLoad
            // 
            this.tsmiCaptureListLoad.Name = "tsmiCaptureListLoad";
            this.tsmiCaptureListLoad.Size = new System.Drawing.Size(107, 22);
            this.tsmiCaptureListLoad.Text = "Load";
            this.tsmiCaptureListLoad.Click += new System.EventHandler(this.tsmiCaptureListLoad_Click);
            // 
            // tsmiCaptureListClear
            // 
            this.tsmiCaptureListClear.Name = "tsmiCaptureListClear";
            this.tsmiCaptureListClear.Size = new System.Drawing.Size(107, 22);
            this.tsmiCaptureListClear.Text = "Clear";
            this.tsmiCaptureListClear.Click += new System.EventHandler(this.tsmiCaptureListClear_Click);
            // 
            // exportToolStripMenuItem
            // 
            this.exportToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiCaptureListExportHTMLascii,
            this.tsmiCaptureListExportHTMLhex,
            this.tsmiCaptureListExportTXTascii,
            this.tsmiCaptureListExportTXThex});
            this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
            this.exportToolStripMenuItem.Size = new System.Drawing.Size(107, 22);
            this.exportToolStripMenuItem.Text = "Export";
            // 
            // tsmiCaptureListExportHTMLascii
            // 
            this.tsmiCaptureListExportHTMLascii.Name = "tsmiCaptureListExportHTMLascii";
            this.tsmiCaptureListExportHTMLascii.Size = new System.Drawing.Size(141, 22);
            this.tsmiCaptureListExportHTMLascii.Text = "HTML (ascii)";
            // 
            // tsmiCaptureListExportHTMLhex
            // 
            this.tsmiCaptureListExportHTMLhex.Name = "tsmiCaptureListExportHTMLhex";
            this.tsmiCaptureListExportHTMLhex.Size = new System.Drawing.Size(141, 22);
            this.tsmiCaptureListExportHTMLhex.Text = "HTML (hex)";
            // 
            // tsmiCaptureListExportTXTascii
            // 
            this.tsmiCaptureListExportTXTascii.Name = "tsmiCaptureListExportTXTascii";
            this.tsmiCaptureListExportTXTascii.Size = new System.Drawing.Size(141, 22);
            this.tsmiCaptureListExportTXTascii.Text = "TXT (ascii)";
            // 
            // tsmiCaptureListExportTXThex
            // 
            this.tsmiCaptureListExportTXThex.Name = "tsmiCaptureListExportTXThex";
            this.tsmiCaptureListExportTXThex.Size = new System.Drawing.Size(141, 22);
            this.tsmiCaptureListExportTXThex.Text = "TXT (hex)";
            // 
            // tabFilters
            // 
            this.tabFilters.Controls.Add(this.lvFilters);
            this.tabFilters.Location = new System.Drawing.Point(4, 22);
            this.tabFilters.Name = "tabFilters";
            this.tabFilters.Padding = new System.Windows.Forms.Padding(3);
            this.tabFilters.Size = new System.Drawing.Size(142, 334);
            this.tabFilters.TabIndex = 1;
            this.tabFilters.Text = "Filters";
            this.tabFilters.UseVisualStyleBackColor = true;
            // 
            // lvFilters
            // 
            this.lvFilters.CheckBoxes = true;
            this.lvFilters.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colName});
            this.lvFilters.ContextMenuStrip = this.cmsFilters;
            this.lvFilters.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lvFilters.FullRowSelect = true;
            this.lvFilters.GridLines = true;
            this.lvFilters.Location = new System.Drawing.Point(3, 3);
            this.lvFilters.MinimumSize = new System.Drawing.Size(116, 4);
            this.lvFilters.Name = "lvFilters";
            this.lvFilters.ShowItemToolTips = true;
            this.lvFilters.Size = new System.Drawing.Size(136, 328);
            this.lvFilters.TabIndex = 30;
            this.lvFilters.UseCompatibleStateImageBehavior = false;
            this.lvFilters.View = System.Windows.Forms.View.Details;
            // 
            // colName
            // 
            this.colName.Tag = "";
            this.colName.Text = "Filters  (Inactive)";
            this.colName.Width = 150;
            // 
            // cmsFilters
            // 
            this.cmsFilters.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiFilterListAddNew,
            this.tsmiFilterListEdit,
            this.tsmiFilterListDelete,
            this.toolStripSeparator10,
            this.tsmiFilterListList});
            this.cmsFilters.Name = "cmsListOnlyOptions";
            this.cmsFilters.Size = new System.Drawing.Size(153, 98);
            this.cmsFilters.Opening += new System.ComponentModel.CancelEventHandler(this.cmsFilterList_Opening);
            // 
            // tsmiFilterListAddNew
            // 
            this.tsmiFilterListAddNew.Name = "tsmiFilterListAddNew";
            this.tsmiFilterListAddNew.Size = new System.Drawing.Size(152, 22);
            this.tsmiFilterListAddNew.Text = "Add New Filter";
            this.tsmiFilterListAddNew.Click += new System.EventHandler(this.tsmiFilterListAddNew_Click);
            // 
            // tsmiFilterListEdit
            // 
            this.tsmiFilterListEdit.Name = "tsmiFilterListEdit";
            this.tsmiFilterListEdit.Size = new System.Drawing.Size(152, 22);
            this.tsmiFilterListEdit.Text = "Edit Filter";
            this.tsmiFilterListEdit.Click += new System.EventHandler(this.tsmiFilterListEdit_Click);
            // 
            // tsmiFilterListDelete
            // 
            this.tsmiFilterListDelete.Name = "tsmiFilterListDelete";
            this.tsmiFilterListDelete.Size = new System.Drawing.Size(152, 22);
            this.tsmiFilterListDelete.Text = "Delete Filter";
            this.tsmiFilterListDelete.Click += new System.EventHandler(this.tsmiFilterListDelete_Click);
            // 
            // toolStripSeparator10
            // 
            this.toolStripSeparator10.Name = "toolStripSeparator10";
            this.toolStripSeparator10.Size = new System.Drawing.Size(149, 6);
            // 
            // tsmiFilterListList
            // 
            this.tsmiFilterListList.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiFilterListListOpen,
            this.tsmiFilterListListSave,
            this.tsmiFilterListListSaveAs,
            this.tsmiFilterListListClear});
            this.tsmiFilterListList.Name = "tsmiFilterListList";
            this.tsmiFilterListList.Size = new System.Drawing.Size(152, 22);
            this.tsmiFilterListList.Text = "List";
            // 
            // tsmiFilterListListOpen
            // 
            this.tsmiFilterListListOpen.Name = "tsmiFilterListListOpen";
            this.tsmiFilterListListOpen.Size = new System.Drawing.Size(111, 22);
            this.tsmiFilterListListOpen.Text = "Open";
            this.tsmiFilterListListOpen.Click += new System.EventHandler(this.tsmiFilterListLoad_Click);
            // 
            // tsmiFilterListListSave
            // 
            this.tsmiFilterListListSave.Name = "tsmiFilterListListSave";
            this.tsmiFilterListListSave.Size = new System.Drawing.Size(111, 22);
            this.tsmiFilterListListSave.Text = "Save";
            this.tsmiFilterListListSave.Click += new System.EventHandler(this.tsmiFilterListSave_Click);
            // 
            // tsmiFilterListListSaveAs
            // 
            this.tsmiFilterListListSaveAs.Name = "tsmiFilterListListSaveAs";
            this.tsmiFilterListListSaveAs.Size = new System.Drawing.Size(111, 22);
            this.tsmiFilterListListSaveAs.Text = "SaveAs";
            this.tsmiFilterListListSaveAs.Click += new System.EventHandler(this.tsmiFilterListSaveAs_Click);
            // 
            // tsmiFilterListListClear
            // 
            this.tsmiFilterListListClear.Name = "tsmiFilterListListClear";
            this.tsmiFilterListListClear.Size = new System.Drawing.Size(111, 22);
            this.tsmiFilterListListClear.Text = "Clear";
            this.tsmiFilterListListClear.Click += new System.EventHandler(this.tsmiFilterListClear_Click);
            // 
            // tabSendList
            // 
            this.tabSendList.Controls.Add(this.lvSendList);
            this.tabSendList.Location = new System.Drawing.Point(4, 22);
            this.tabSendList.Name = "tabSendList";
            this.tabSendList.Padding = new System.Windows.Forms.Padding(3);
            this.tabSendList.Size = new System.Drawing.Size(142, 334);
            this.tabSendList.TabIndex = 2;
            this.tabSendList.Text = "Send";
            this.tabSendList.UseVisualStyleBackColor = true;
            // 
            // lvSendList
            // 
            this.lvSendList.CheckBoxes = true;
            this.lvSendList.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colSendList});
            this.lvSendList.ContextMenuStrip = this.cmsSendList;
            this.lvSendList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lvSendList.GridLines = true;
            this.lvSendList.Location = new System.Drawing.Point(3, 3);
            this.lvSendList.MultiSelect = false;
            this.lvSendList.Name = "lvSendList";
            this.lvSendList.Scrollable = false;
            this.lvSendList.ShowItemToolTips = true;
            this.lvSendList.Size = new System.Drawing.Size(136, 328);
            this.lvSendList.TabIndex = 1;
            this.lvSendList.UseCompatibleStateImageBehavior = false;
            this.lvSendList.View = System.Windows.Forms.View.Details;
            // 
            // colSendList
            // 
            this.colSendList.Text = "Send List";
            this.colSendList.Width = 150;
            // 
            // cmsSendList
            // 
            this.cmsSendList.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiSendListIEdit,
            this.tsmiSendListDelete,
            this.tsmiSendListSelection,
            this.toolStripSeparator8,
            this.tsmiSendListListOptions});
            this.cmsSendList.Name = "cmsSendList";
            this.cmsSendList.Size = new System.Drawing.Size(152, 98);
            this.cmsSendList.Opening += new System.ComponentModel.CancelEventHandler(this.cmsSendList_Opening);
            // 
            // tsmiSendListIEdit
            // 
            this.tsmiSendListIEdit.Name = "tsmiSendListIEdit";
            this.tsmiSendListIEdit.Size = new System.Drawing.Size(151, 22);
            this.tsmiSendListIEdit.Text = "Edit";
            this.tsmiSendListIEdit.Click += new System.EventHandler(this.tsmiSendListEdit_Click);
            // 
            // tsmiSendListDelete
            // 
            this.tsmiSendListDelete.Name = "tsmiSendListDelete";
            this.tsmiSendListDelete.Size = new System.Drawing.Size(151, 22);
            this.tsmiSendListDelete.Text = "Delete";
            this.tsmiSendListDelete.Click += new System.EventHandler(this.tsmiSendListDelete_Click);
            // 
            // tsmiSendListSelection
            // 
            this.tsmiSendListSelection.Name = "tsmiSendListSelection";
            this.tsmiSendListSelection.Size = new System.Drawing.Size(151, 22);
            this.tsmiSendListSelection.Text = "Send Selection";
            // 
            // toolStripSeparator8
            // 
            this.toolStripSeparator8.Name = "toolStripSeparator8";
            this.toolStripSeparator8.Size = new System.Drawing.Size(148, 6);
            // 
            // tsmiSendListListOptions
            // 
            this.tsmiSendListListOptions.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiSendListListLoad,
            this.tsmiSendListListSave,
            this.tsmiSendListListClear});
            this.tsmiSendListListOptions.Name = "tsmiSendListListOptions";
            this.tsmiSendListListOptions.Size = new System.Drawing.Size(151, 22);
            this.tsmiSendListListOptions.Text = "List";
            // 
            // tsmiSendListListLoad
            // 
            this.tsmiSendListListLoad.Name = "tsmiSendListListLoad";
            this.tsmiSendListListLoad.Size = new System.Drawing.Size(101, 22);
            this.tsmiSendListListLoad.Text = "Load";
            this.tsmiSendListListLoad.Click += new System.EventHandler(this.tsmiSendListLoad_Click);
            // 
            // tsmiSendListListSave
            // 
            this.tsmiSendListListSave.Name = "tsmiSendListListSave";
            this.tsmiSendListListSave.Size = new System.Drawing.Size(101, 22);
            this.tsmiSendListListSave.Text = "Save";
            this.tsmiSendListListSave.Click += new System.EventHandler(this.tsmiSendListSave_Click);
            // 
            // tsmiSendListListClear
            // 
            this.tsmiSendListListClear.Name = "tsmiSendListListClear";
            this.tsmiSendListListClear.Size = new System.Drawing.Size(101, 22);
            this.tsmiSendListListClear.Text = "Clear";
            this.tsmiSendListListClear.Click += new System.EventHandler(this.tsmiSendListClear_Click);
            // 
            // groupConversions
            // 
            this.groupConversions.Controls.Add(this.panel2);
            this.groupConversions.Controls.Add(this.panel1);
            this.groupConversions.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupConversions.Location = new System.Drawing.Point(0, 0);
            this.groupConversions.Margin = new System.Windows.Forms.Padding(3, 19, 3, 3);
            this.groupConversions.Name = "groupConversions";
            this.groupConversions.Size = new System.Drawing.Size(150, 166);
            this.groupConversions.TabIndex = 30;
            this.groupConversions.TabStop = false;
            this.groupConversions.Text = "Conversions:";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.txtConverDouble);
            this.panel2.Controls.Add(this.txtConverFloat);
            this.panel2.Controls.Add(this.txtConverUInt64);
            this.panel2.Controls.Add(this.txtConverInt64);
            this.panel2.Controls.Add(this.txtConverUInt32);
            this.panel2.Controls.Add(this.txtConverInt32);
            this.panel2.Controls.Add(this.txtConverUShort);
            this.panel2.Controls.Add(this.txtConverShort);
            this.panel2.Controls.Add(this.txtConverByte);
            this.panel2.Controls.Add(this.txtConverChar);
            this.panel2.Controls.Add(this.txtConverPos);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel2.Location = new System.Drawing.Point(51, 16);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(96, 147);
            this.panel2.TabIndex = 21;
            // 
            // txtConverDouble
            // 
            this.txtConverDouble.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverDouble.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverDouble.Location = new System.Drawing.Point(0, 130);
            this.txtConverDouble.Name = "txtConverDouble";
            this.txtConverDouble.ReadOnly = true;
            this.txtConverDouble.Size = new System.Drawing.Size(96, 13);
            this.txtConverDouble.TabIndex = 29;
            this.txtConverDouble.TabStop = false;
            // 
            // txtConverFloat
            // 
            this.txtConverFloat.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverFloat.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverFloat.Location = new System.Drawing.Point(0, 117);
            this.txtConverFloat.Name = "txtConverFloat";
            this.txtConverFloat.ReadOnly = true;
            this.txtConverFloat.Size = new System.Drawing.Size(96, 13);
            this.txtConverFloat.TabIndex = 28;
            this.txtConverFloat.TabStop = false;
            // 
            // txtConverUInt64
            // 
            this.txtConverUInt64.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverUInt64.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverUInt64.Location = new System.Drawing.Point(0, 104);
            this.txtConverUInt64.Name = "txtConverUInt64";
            this.txtConverUInt64.ReadOnly = true;
            this.txtConverUInt64.Size = new System.Drawing.Size(96, 13);
            this.txtConverUInt64.TabIndex = 27;
            this.txtConverUInt64.TabStop = false;
            // 
            // txtConverInt64
            // 
            this.txtConverInt64.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverInt64.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverInt64.Location = new System.Drawing.Point(0, 91);
            this.txtConverInt64.Name = "txtConverInt64";
            this.txtConverInt64.ReadOnly = true;
            this.txtConverInt64.Size = new System.Drawing.Size(96, 13);
            this.txtConverInt64.TabIndex = 26;
            this.txtConverInt64.TabStop = false;
            // 
            // txtConverUInt32
            // 
            this.txtConverUInt32.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverUInt32.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverUInt32.Location = new System.Drawing.Point(0, 78);
            this.txtConverUInt32.Name = "txtConverUInt32";
            this.txtConverUInt32.ReadOnly = true;
            this.txtConverUInt32.Size = new System.Drawing.Size(96, 13);
            this.txtConverUInt32.TabIndex = 25;
            this.txtConverUInt32.TabStop = false;
            // 
            // txtConverInt32
            // 
            this.txtConverInt32.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverInt32.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverInt32.Location = new System.Drawing.Point(0, 65);
            this.txtConverInt32.Name = "txtConverInt32";
            this.txtConverInt32.ReadOnly = true;
            this.txtConverInt32.Size = new System.Drawing.Size(96, 13);
            this.txtConverInt32.TabIndex = 24;
            this.txtConverInt32.TabStop = false;
            // 
            // txtConverUShort
            // 
            this.txtConverUShort.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverUShort.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverUShort.Location = new System.Drawing.Point(0, 52);
            this.txtConverUShort.Name = "txtConverUShort";
            this.txtConverUShort.ReadOnly = true;
            this.txtConverUShort.Size = new System.Drawing.Size(96, 13);
            this.txtConverUShort.TabIndex = 23;
            this.txtConverUShort.TabStop = false;
            // 
            // txtConverShort
            // 
            this.txtConverShort.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverShort.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverShort.Location = new System.Drawing.Point(0, 39);
            this.txtConverShort.Name = "txtConverShort";
            this.txtConverShort.ReadOnly = true;
            this.txtConverShort.Size = new System.Drawing.Size(96, 13);
            this.txtConverShort.TabIndex = 22;
            this.txtConverShort.TabStop = false;
            // 
            // txtConverByte
            // 
            this.txtConverByte.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverByte.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverByte.Location = new System.Drawing.Point(0, 26);
            this.txtConverByte.Name = "txtConverByte";
            this.txtConverByte.ReadOnly = true;
            this.txtConverByte.Size = new System.Drawing.Size(96, 13);
            this.txtConverByte.TabIndex = 21;
            this.txtConverByte.TabStop = false;
            // 
            // txtConverChar
            // 
            this.txtConverChar.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverChar.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverChar.Location = new System.Drawing.Point(0, 13);
            this.txtConverChar.Name = "txtConverChar";
            this.txtConverChar.ReadOnly = true;
            this.txtConverChar.Size = new System.Drawing.Size(96, 13);
            this.txtConverChar.TabIndex = 20;
            this.txtConverChar.TabStop = false;
            // 
            // txtConverPos
            // 
            this.txtConverPos.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtConverPos.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtConverPos.Location = new System.Drawing.Point(0, 0);
            this.txtConverPos.Name = "txtConverPos";
            this.txtConverPos.ReadOnly = true;
            this.txtConverPos.Size = new System.Drawing.Size(96, 13);
            this.txtConverPos.TabIndex = 30;
            this.txtConverPos.TabStop = false;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.lblConverDouble);
            this.panel1.Controls.Add(this.lblConverFloat);
            this.panel1.Controls.Add(this.lblConverUInt64);
            this.panel1.Controls.Add(this.lblConverInt64);
            this.panel1.Controls.Add(this.lblConverULong);
            this.panel1.Controls.Add(this.lblConverLong);
            this.panel1.Controls.Add(this.lblConverUShort);
            this.panel1.Controls.Add(this.lblConverShort);
            this.panel1.Controls.Add(this.lblConverByte);
            this.panel1.Controls.Add(this.lblConverChar);
            this.panel1.Controls.Add(this.lblConverPos);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(3, 16);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(48, 147);
            this.panel1.TabIndex = 20;
            // 
            // lblConverDouble
            // 
            this.lblConverDouble.AutoSize = true;
            this.lblConverDouble.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverDouble.Location = new System.Drawing.Point(0, 130);
            this.lblConverDouble.Name = "lblConverDouble";
            this.lblConverDouble.Size = new System.Drawing.Size(44, 13);
            this.lblConverDouble.TabIndex = 19;
            this.lblConverDouble.Text = "Double:";
            // 
            // lblConverFloat
            // 
            this.lblConverFloat.AutoSize = true;
            this.lblConverFloat.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverFloat.Location = new System.Drawing.Point(0, 117);
            this.lblConverFloat.Name = "lblConverFloat";
            this.lblConverFloat.Size = new System.Drawing.Size(33, 13);
            this.lblConverFloat.TabIndex = 18;
            this.lblConverFloat.Text = "Float:";
            // 
            // lblConverUInt64
            // 
            this.lblConverUInt64.AutoSize = true;
            this.lblConverUInt64.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverUInt64.Location = new System.Drawing.Point(0, 104);
            this.lblConverUInt64.Name = "lblConverUInt64";
            this.lblConverUInt64.Size = new System.Drawing.Size(42, 13);
            this.lblConverUInt64.TabIndex = 17;
            this.lblConverUInt64.Text = "UInt64:";
            // 
            // lblConverInt64
            // 
            this.lblConverInt64.AutoSize = true;
            this.lblConverInt64.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverInt64.Location = new System.Drawing.Point(0, 91);
            this.lblConverInt64.Name = "lblConverInt64";
            this.lblConverInt64.Size = new System.Drawing.Size(34, 13);
            this.lblConverInt64.TabIndex = 16;
            this.lblConverInt64.Text = "Int64:";
            // 
            // lblConverULong
            // 
            this.lblConverULong.AutoSize = true;
            this.lblConverULong.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverULong.Location = new System.Drawing.Point(0, 78);
            this.lblConverULong.Name = "lblConverULong";
            this.lblConverULong.Size = new System.Drawing.Size(42, 13);
            this.lblConverULong.TabIndex = 15;
            this.lblConverULong.Text = "UInt32:";
            // 
            // lblConverLong
            // 
            this.lblConverLong.AutoSize = true;
            this.lblConverLong.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverLong.Location = new System.Drawing.Point(0, 65);
            this.lblConverLong.Name = "lblConverLong";
            this.lblConverLong.Size = new System.Drawing.Size(34, 13);
            this.lblConverLong.TabIndex = 14;
            this.lblConverLong.Text = "Int32:";
            // 
            // lblConverUShort
            // 
            this.lblConverUShort.AutoSize = true;
            this.lblConverUShort.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverUShort.Location = new System.Drawing.Point(0, 52);
            this.lblConverUShort.Name = "lblConverUShort";
            this.lblConverUShort.Size = new System.Drawing.Size(43, 13);
            this.lblConverUShort.TabIndex = 13;
            this.lblConverUShort.Text = "UShort:";
            // 
            // lblConverShort
            // 
            this.lblConverShort.AutoSize = true;
            this.lblConverShort.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverShort.Location = new System.Drawing.Point(0, 39);
            this.lblConverShort.Name = "lblConverShort";
            this.lblConverShort.Size = new System.Drawing.Size(35, 13);
            this.lblConverShort.TabIndex = 12;
            this.lblConverShort.Text = "Short:";
            // 
            // lblConverByte
            // 
            this.lblConverByte.AutoSize = true;
            this.lblConverByte.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverByte.Location = new System.Drawing.Point(0, 26);
            this.lblConverByte.Name = "lblConverByte";
            this.lblConverByte.Size = new System.Drawing.Size(31, 13);
            this.lblConverByte.TabIndex = 11;
            this.lblConverByte.Text = "Byte:";
            // 
            // lblConverChar
            // 
            this.lblConverChar.AutoSize = true;
            this.lblConverChar.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverChar.Location = new System.Drawing.Point(0, 13);
            this.lblConverChar.Name = "lblConverChar";
            this.lblConverChar.Size = new System.Drawing.Size(32, 13);
            this.lblConverChar.TabIndex = 10;
            this.lblConverChar.Text = "Char:";
            // 
            // lblConverPos
            // 
            this.lblConverPos.AutoSize = true;
            this.lblConverPos.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblConverPos.Location = new System.Drawing.Point(0, 0);
            this.lblConverPos.Name = "lblConverPos";
            this.lblConverPos.Size = new System.Drawing.Size(47, 13);
            this.lblConverPos.TabIndex = 20;
            this.lblConverPos.Text = "Position:";
            // 
            // splitContainerTabsAndHex
            // 
            this.splitContainerTabsAndHex.BackColor = System.Drawing.SystemColors.Control;
            this.splitContainerTabsAndHex.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainerTabsAndHex.Location = new System.Drawing.Point(0, 0);
            this.splitContainerTabsAndHex.Name = "splitContainerTabsAndHex";
            this.splitContainerTabsAndHex.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainerTabsAndHex.Panel1
            // 
            this.splitContainerTabsAndHex.Panel1.Controls.Add(this.tabControlMain);
            this.splitContainerTabsAndHex.Panel1MinSize = 0;
            // 
            // splitContainerTabsAndHex.Panel2
            // 
            this.splitContainerTabsAndHex.Panel2.Controls.Add(this.hexBox);
            this.splitContainerTabsAndHex.Panel2MinSize = 0;
            this.splitContainerTabsAndHex.Size = new System.Drawing.Size(643, 532);
            this.splitContainerTabsAndHex.SplitterDistance = 360;
            this.splitContainerTabsAndHex.SplitterWidth = 6;
            this.splitContainerTabsAndHex.TabIndex = 9;
            // 
            // tabControlMain
            // 
            this.tabControlMain.Controls.Add(this.tabBoth);
            this.tabControlMain.Controls.Add(this.tabReceived);
            this.tabControlMain.Controls.Add(this.tabSent);
            this.tabControlMain.Controls.Add(this.tabWatch);
            this.tabControlMain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControlMain.Location = new System.Drawing.Point(0, 0);
            this.tabControlMain.Margin = new System.Windows.Forms.Padding(0);
            this.tabControlMain.Name = "tabControlMain";
            this.tabControlMain.SelectedIndex = 0;
            this.tabControlMain.Size = new System.Drawing.Size(643, 360);
            this.tabControlMain.TabIndex = 0;
            // 
            // tabBoth
            // 
            this.tabBoth.Controls.Add(this.lvwBoth);
            this.tabBoth.Location = new System.Drawing.Point(4, 22);
            this.tabBoth.Margin = new System.Windows.Forms.Padding(0);
            this.tabBoth.Name = "tabBoth";
            this.tabBoth.Size = new System.Drawing.Size(635, 334);
            this.tabBoth.TabIndex = 2;
            this.tabBoth.Text = "Both";
            this.tabBoth.UseVisualStyleBackColor = true;
            // 
            // lvwBoth
            // 
            this.lvwBoth.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colBothPacket,
            this.colBothSource,
            this.colBothDestination,
            this.colBothFunction,
            this.colBothSize,
            this.colBothData});
            this.lvwBoth.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lvwBoth.FullRowSelect = true;
            this.lvwBoth.Location = new System.Drawing.Point(0, 0);
            this.lvwBoth.MultiSelect = false;
            this.lvwBoth.Name = "lvwBoth";
            this.lvwBoth.ShowItemToolTips = true;
            this.lvwBoth.Size = new System.Drawing.Size(635, 334);
            this.lvwBoth.TabIndex = 1;
            this.lvwBoth.UseCompatibleStateImageBehavior = false;
            this.lvwBoth.View = System.Windows.Forms.View.Details;
            this.lvwBoth.SelectedIndexChanged += new System.EventHandler(this.OnSelectedIndexChanged);
            // 
            // colBothPacket
            // 
            this.colBothPacket.Text = "Packet";
            // 
            // colBothSource
            // 
            this.colBothSource.Text = "Source";
            // 
            // colBothDestination
            // 
            this.colBothDestination.Text = "Destination";
            this.colBothDestination.Width = 65;
            // 
            // colBothFunction
            // 
            this.colBothFunction.Text = "Function";
            // 
            // colBothSize
            // 
            this.colBothSize.Text = "Size";
            // 
            // colBothData
            // 
            this.colBothData.Text = "Data";
            this.colBothData.Width = 224;
            // 
            // tabReceived
            // 
            this.tabReceived.Controls.Add(this.lvwReceived);
            this.tabReceived.Location = new System.Drawing.Point(4, 22);
            this.tabReceived.Name = "tabReceived";
            this.tabReceived.Size = new System.Drawing.Size(635, 334);
            this.tabReceived.TabIndex = 0;
            this.tabReceived.Text = "Received";
            this.tabReceived.UseVisualStyleBackColor = true;
            // 
            // lvwReceived
            // 
            this.lvwReceived.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colReceivedPacket,
            this.colReceivedSource,
            this.colReceivedDestination,
            this.colRecivedFunction,
            this.colReceivedSize,
            this.colReceivedData});
            this.lvwReceived.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lvwReceived.FullRowSelect = true;
            this.lvwReceived.Location = new System.Drawing.Point(0, 0);
            this.lvwReceived.MultiSelect = false;
            this.lvwReceived.Name = "lvwReceived";
            this.lvwReceived.ShowItemToolTips = true;
            this.lvwReceived.Size = new System.Drawing.Size(635, 334);
            this.lvwReceived.TabIndex = 0;
            this.lvwReceived.UseCompatibleStateImageBehavior = false;
            this.lvwReceived.View = System.Windows.Forms.View.Details;
            this.lvwReceived.SelectedIndexChanged += new System.EventHandler(this.OnSelectedIndexChanged);
            // 
            // colReceivedPacket
            // 
            this.colReceivedPacket.Text = "Packet";
            // 
            // colReceivedSource
            // 
            this.colReceivedSource.Text = "Source";
            // 
            // colReceivedDestination
            // 
            this.colReceivedDestination.Text = "Destination";
            this.colReceivedDestination.Width = 65;
            // 
            // colRecivedFunction
            // 
            this.colRecivedFunction.Text = "Function";
            // 
            // colReceivedSize
            // 
            this.colReceivedSize.Text = "Size";
            // 
            // colReceivedData
            // 
            this.colReceivedData.Text = "Data";
            this.colReceivedData.Width = 224;
            // 
            // tabSent
            // 
            this.tabSent.Controls.Add(this.lvwSent);
            this.tabSent.Location = new System.Drawing.Point(4, 22);
            this.tabSent.Margin = new System.Windows.Forms.Padding(0);
            this.tabSent.Name = "tabSent";
            this.tabSent.Size = new System.Drawing.Size(635, 334);
            this.tabSent.TabIndex = 1;
            this.tabSent.Text = "Sent";
            this.tabSent.UseVisualStyleBackColor = true;
            // 
            // lvwSent
            // 
            this.lvwSent.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colSentPacket,
            this.colSentSource,
            this.colSentDestination,
            this.colSentFunction,
            this.colSentSize,
            this.colSentData});
            this.lvwSent.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lvwSent.FullRowSelect = true;
            this.lvwSent.Location = new System.Drawing.Point(0, 0);
            this.lvwSent.MultiSelect = false;
            this.lvwSent.Name = "lvwSent";
            this.lvwSent.ShowItemToolTips = true;
            this.lvwSent.Size = new System.Drawing.Size(635, 334);
            this.lvwSent.TabIndex = 1;
            this.lvwSent.UseCompatibleStateImageBehavior = false;
            this.lvwSent.View = System.Windows.Forms.View.Details;
            this.lvwSent.SelectedIndexChanged += new System.EventHandler(this.OnSelectedIndexChanged);
            // 
            // colSentPacket
            // 
            this.colSentPacket.Text = "Packet";
            // 
            // colSentSource
            // 
            this.colSentSource.Text = "Source";
            // 
            // colSentDestination
            // 
            this.colSentDestination.Text = "Destination";
            this.colSentDestination.Width = 65;
            // 
            // colSentFunction
            // 
            this.colSentFunction.Text = "Function";
            // 
            // colSentSize
            // 
            this.colSentSize.Text = "Size";
            // 
            // colSentData
            // 
            this.colSentData.Text = "Data";
            this.colSentData.Width = 224;
            // 
            // tabWatch
            // 
            this.tabWatch.Controls.Add(this.lvwWatch);
            this.tabWatch.Location = new System.Drawing.Point(4, 22);
            this.tabWatch.Margin = new System.Windows.Forms.Padding(0);
            this.tabWatch.Name = "tabWatch";
            this.tabWatch.Size = new System.Drawing.Size(635, 334);
            this.tabWatch.TabIndex = 5;
            this.tabWatch.Text = "Watch";
            this.tabWatch.UseVisualStyleBackColor = true;
            // 
            // lvwWatch
            // 
            this.lvwWatch.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colWatchPacket,
            this.colWatchSource,
            this.colWatchDestination,
            this.colWatchFunction,
            this.colWatchSize,
            this.colWatchData});
            this.lvwWatch.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lvwWatch.FullRowSelect = true;
            this.lvwWatch.Location = new System.Drawing.Point(0, 0);
            this.lvwWatch.Margin = new System.Windows.Forms.Padding(0);
            this.lvwWatch.MultiSelect = false;
            this.lvwWatch.Name = "lvwWatch";
            this.lvwWatch.ShowItemToolTips = true;
            this.lvwWatch.Size = new System.Drawing.Size(635, 334);
            this.lvwWatch.TabIndex = 3;
            this.lvwWatch.UseCompatibleStateImageBehavior = false;
            this.lvwWatch.View = System.Windows.Forms.View.Details;
            this.lvwWatch.SelectedIndexChanged += new System.EventHandler(this.OnSelectedIndexChanged);
            // 
            // colWatchPacket
            // 
            this.colWatchPacket.Text = "Packet";
            // 
            // colWatchSource
            // 
            this.colWatchSource.Text = "Source";
            // 
            // colWatchDestination
            // 
            this.colWatchDestination.Text = "Destination";
            this.colWatchDestination.Width = 65;
            // 
            // colWatchFunction
            // 
            this.colWatchFunction.Text = "Function";
            // 
            // colWatchSize
            // 
            this.colWatchSize.Text = "Size";
            // 
            // colWatchData
            // 
            this.colWatchData.Text = "Data";
            this.colWatchData.Width = 224;
            // 
            // hexBox
            // 
            this.hexBox.ColumnInfoVisible = true;
            this.hexBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.hexBox.Font = new System.Drawing.Font("Courier New", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.hexBox.InfoForeColor = System.Drawing.SystemColors.GrayText;
            this.hexBox.LineInfoVisible = true;
            this.hexBox.Location = new System.Drawing.Point(0, 0);
            this.hexBox.Name = "hexBox";
            this.hexBox.ShadowSelectionColor = System.Drawing.Color.FromArgb(((int)(((byte)(100)))), ((int)(((byte)(60)))), ((int)(((byte)(188)))), ((int)(((byte)(255)))));
            this.hexBox.Size = new System.Drawing.Size(643, 166);
            this.hexBox.StringViewVisible = true;
            this.hexBox.TabIndex = 0;
            this.hexBox.UseFixedBytesPerLine = true;
            this.hexBox.VScrollBarVisible = true;
            this.hexBox.SelectionStartChanged += new System.EventHandler(this.hexBox_SelectionStartChanged);
            this.hexBox.SelectionLengthChanged += new System.EventHandler(this.hexBox_SelectionLengthChanged);
            // 
            // cmsPacketOptions
            // 
            this.cmsPacketOptions.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmiOpenPacket,
            this.tsmiSendPacket,
            this.tsmiAddToSendList,
            this.tsmiGenerateFilter});
            this.cmsPacketOptions.Name = "cmsPacketOptions";
            this.cmsPacketOptions.Size = new System.Drawing.Size(157, 92);
            // 
            // tsmiOpenPacket
            // 
            this.tsmiOpenPacket.Name = "tsmiOpenPacket";
            this.tsmiOpenPacket.Size = new System.Drawing.Size(156, 22);
            this.tsmiOpenPacket.Text = "Open";
            this.tsmiOpenPacket.Click += new System.EventHandler(this.tsmiOpenPacket_Click);
            // 
            // tsmiSendPacket
            // 
            this.tsmiSendPacket.Name = "tsmiSendPacket";
            this.tsmiSendPacket.Size = new System.Drawing.Size(156, 22);
            this.tsmiSendPacket.Text = "Send";
            this.tsmiSendPacket.Click += new System.EventHandler(this.tsmiSendPacket_Click);
            // 
            // tsmiAddToSendList
            // 
            this.tsmiAddToSendList.Name = "tsmiAddToSendList";
            this.tsmiAddToSendList.Size = new System.Drawing.Size(156, 22);
            this.tsmiAddToSendList.Text = "Add to send list";
            this.tsmiAddToSendList.Click += new System.EventHandler(this.tsmiAddToSendList_Click);
            // 
            // tsmiGenerateFilter
            // 
            this.tsmiGenerateFilter.Name = "tsmiGenerateFilter";
            this.tsmiGenerateFilter.Size = new System.Drawing.Size(156, 22);
            this.tsmiGenerateFilter.Text = "Generate filter";
            this.tsmiGenerateFilter.Click += new System.EventHandler(this.tsmiGenerateFilter_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(799, 629);
            this.Controls.Add(this.splitContainerFiltersAndBody);
            this.Controls.Add(this.statusStripMain);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.menuStripMain);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStripMain;
            this.MinimumSize = new System.Drawing.Size(495, 500);
            this.Name = "MainForm";
            this.Text = "OSPE - Open Source Packet Editor";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.Resize += new System.EventHandler(this.frmMain_Resize);
            this.menuStripMain.ResumeLayout(false);
            this.menuStripMain.PerformLayout();
            this.statusStripMain.ResumeLayout(false);
            this.statusStripMain.PerformLayout();
            this.trayMenuStrip.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.splitContainerFiltersAndBody.Panel1.ResumeLayout(false);
            this.splitContainerFiltersAndBody.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerFiltersAndBody)).EndInit();
            this.splitContainerFiltersAndBody.ResumeLayout(false);
            this.splitFilterAndConversions.Panel1.ResumeLayout(false);
            this.splitFilterAndConversions.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitFilterAndConversions)).EndInit();
            this.splitFilterAndConversions.ResumeLayout(false);
            this.tabControlCapturesAndFilters.ResumeLayout(false);
            this.tabCaptures.ResumeLayout(false);
            this.cmsCaptures.ResumeLayout(false);
            this.tabFilters.ResumeLayout(false);
            this.cmsFilters.ResumeLayout(false);
            this.tabSendList.ResumeLayout(false);
            this.cmsSendList.ResumeLayout(false);
            this.groupConversions.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.splitContainerTabsAndHex.Panel1.ResumeLayout(false);
            this.splitContainerTabsAndHex.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainerTabsAndHex)).EndInit();
            this.splitContainerTabsAndHex.ResumeLayout(false);
            this.tabControlMain.ResumeLayout(false);
            this.tabBoth.ResumeLayout(false);
            this.tabReceived.ResumeLayout(false);
            this.tabSent.ResumeLayout(false);
            this.tabWatch.ResumeLayout(false);
            this.cmsPacketOptions.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStripMain;
        private System.Windows.Forms.ToolStripMenuItem programToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tsmiMenuSelectProcess;
        private System.Windows.Forms.ToolStripMenuItem filtersToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem scriptsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem settingsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem tsmiMenuExit;
        private System.Windows.Forms.StatusStrip statusStripMain;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.ToolStripStatusLabel tslNumPackets;
        private System.Windows.Forms.ToolStripMenuItem tsmiMenuConfigure;
        private System.Windows.Forms.ToolStripStatusLabel tslNumPacketsLabel;
        private System.Windows.Forms.ToolStripStatusLabel tslTotalReceivedLabel;
        private System.Windows.Forms.ToolStripStatusLabel tslTotalReceived;
        private System.Windows.Forms.ToolStripMenuItem tsmiMenuInjectLast;
        private System.Windows.Forms.ToolStripStatusLabel tslTotalReceivedUnit;
        private System.Windows.Forms.ToolStripStatusLabel tslTotalSentLabel;
        private System.Windows.Forms.ToolStripStatusLabel tslTotalSent;
        private System.Windows.Forms.ToolStripStatusLabel tslTotalSentUnit;
        private System.Windows.Forms.NotifyIcon notifyIcon;
        private System.Windows.Forms.ContextMenuStrip trayMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem trayTsmiOpen;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem trayTsmiStartCapture;
        private System.Windows.Forms.ToolStripMenuItem trayTsmiStopCapture;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripMenuItem trayTsmiSelectProcess;
        private System.Windows.Forms.ToolStripMenuItem trayTsmiInjectLastProc;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripMenuItem trayTsmiActiveFilters;
        private System.Windows.Forms.ToolStripMenuItem trayTsmiActiveCustomFilter;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator6;
        private System.Windows.Forms.ToolStripMenuItem trayTsmiExit;
        private System.Windows.Forms.ToolStripStatusLabel tslTesting;
        private System.Windows.Forms.ToolStripStatusLabel tslTesting2;
        private System.Windows.Forms.ToolStripMenuItem tsmiScriptEditor;
        private System.Windows.Forms.ToolStripMenuItem tsmiActiveFilters;
        private System.Windows.Forms.ToolStripMenuItem tsmiActiveCustomFilters;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.SplitContainer splitContainerFiltersAndBody;
        private System.Windows.Forms.SplitContainer splitContainerTabsAndHex;
        private System.Windows.Forms.TabControl tabControlMain;
        private System.Windows.Forms.TabPage tabReceived;
        private System.Windows.Forms.ListView lvwReceived;
        private System.Windows.Forms.ColumnHeader colReceivedPacket;
        private System.Windows.Forms.ColumnHeader colReceivedSource;
        private System.Windows.Forms.ColumnHeader colReceivedDestination;
        private System.Windows.Forms.ColumnHeader colReceivedSize;
        private System.Windows.Forms.ColumnHeader colReceivedData;
        private System.Windows.Forms.TabPage tabSent;
        private System.Windows.Forms.ListView lvwSent;
        private System.Windows.Forms.ColumnHeader colSentPacket;
        private System.Windows.Forms.ColumnHeader colSentSource;
        private System.Windows.Forms.ColumnHeader colSentDestination;
        private System.Windows.Forms.ColumnHeader colSentSize;
        private System.Windows.Forms.ColumnHeader colSentData;
        private System.Windows.Forms.TabPage tabBoth;
        private System.Windows.Forms.ListView lvwBoth;
        private System.Windows.Forms.ColumnHeader colBothPacket;
        private System.Windows.Forms.ColumnHeader colBothSource;
        private System.Windows.Forms.ColumnHeader colBothDestination;
        private System.Windows.Forms.ColumnHeader colBothSize;
        private System.Windows.Forms.ColumnHeader colBothData;
        private System.Windows.Forms.TabPage tabWatch;
        private System.Windows.Forms.ListView lvwWatch;
        private System.Windows.Forms.ColumnHeader colWatchPacket;
        private System.Windows.Forms.ColumnHeader colWatchSource;
        private System.Windows.Forms.ColumnHeader colWatchDestination;
        private System.Windows.Forms.ColumnHeader colWatchSize;
        private System.Windows.Forms.ColumnHeader colWatchData;
        private Be.Windows.Forms.HexBox hexBox;
        private System.Windows.Forms.ToolStripMenuItem viewLogToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem displayQuickBarToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip cmsFilters;
        private System.Windows.Forms.ToolStripMenuItem tsmiFilterListAddNew;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator10;
        private System.Windows.Forms.ToolStripMenuItem tsmiFilterListDelete;
        private System.Windows.Forms.ToolStripMenuItem tsmiFilterListList;
        private System.Windows.Forms.ToolStripMenuItem tsmiFilterListListOpen;
        private System.Windows.Forms.ToolStripMenuItem tsmiFilterListListSave;
        private System.Windows.Forms.ToolStripMenuItem tsmiFilterListListSaveAs;
        private System.Windows.Forms.ToolStripMenuItem tsmiFilterListListClear;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator9;
        private System.Windows.Forms.ToolStripMenuItem addNewFilterToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tsmiFilterListEdit;
        private System.Windows.Forms.CheckBox chkActiveCustomScript;
        private System.Windows.Forms.CheckBox chkActiveFilters;
        private System.Windows.Forms.CheckBox chkAutoScroll;
        private System.Windows.Forms.Button btnStartPauseCapture;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator11;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator12;
        private System.Windows.Forms.CheckBox checkBoxViewAsHex;
        private System.Windows.Forms.Button btnClearPacketList;
        private System.Windows.Forms.ColumnHeader colRecivedFunction;
        private System.Windows.Forms.ColumnHeader colBothFunction;
        private System.Windows.Forms.ColumnHeader colSentFunction;
        private System.Windows.Forms.ColumnHeader colWatchFunction;
        private System.Windows.Forms.SplitContainer splitFilterAndConversions;
        private System.Windows.Forms.GroupBox groupConversions;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.TextBox txtConverDouble;
        private System.Windows.Forms.TextBox txtConverFloat;
        private System.Windows.Forms.TextBox txtConverUInt64;
        private System.Windows.Forms.TextBox txtConverInt64;
        private System.Windows.Forms.TextBox txtConverUInt32;
        private System.Windows.Forms.TextBox txtConverInt32;
        private System.Windows.Forms.TextBox txtConverUShort;
        private System.Windows.Forms.TextBox txtConverShort;
        private System.Windows.Forms.TextBox txtConverByte;
        private System.Windows.Forms.TextBox txtConverChar;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label lblConverDouble;
        private System.Windows.Forms.Label lblConverFloat;
        private System.Windows.Forms.Label lblConverUInt64;
        private System.Windows.Forms.Label lblConverInt64;
        private System.Windows.Forms.Label lblConverULong;
        private System.Windows.Forms.Label lblConverLong;
        private System.Windows.Forms.Label lblConverUShort;
        private System.Windows.Forms.Label lblConverShort;
        private System.Windows.Forms.Label lblConverByte;
        private System.Windows.Forms.Label lblConverChar;
        private System.Windows.Forms.TextBox txtSearch;
        private System.Windows.Forms.TabControl tabControlCapturesAndFilters;
        private System.Windows.Forms.TabPage tabCaptures;
        private System.Windows.Forms.TabPage tabFilters;
        private System.Windows.Forms.ListView lvFilters;
        private System.Windows.Forms.ColumnHeader colName;
        private System.Windows.Forms.ListView lvCaptures;
        private System.Windows.Forms.ColumnHeader colCaptureName;
        private System.Windows.Forms.ContextMenuStrip cmsCaptures;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureOpen;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureDelete;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator13;
        private System.Windows.Forms.Button btnStopCapture;
        private System.Windows.Forms.RadioButton radioSearchHex;
        private System.Windows.Forms.RadioButton radioSearchString;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.TextBox txtConverPos;
        private System.Windows.Forms.Label lblConverPos;
        private System.Windows.Forms.ToolStripMenuItem captureToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tsmiMenuStartCapture;
        private System.Windows.Forms.ToolStripMenuItem tsmiMenuStopCapture;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem tsmiViewAsHex;
        private System.Windows.Forms.ToolStripMenuItem tsmiAutoScroll;
        private System.Windows.Forms.ToolStripMenuItem tsmiClearList;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem listToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureListSave;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureListLoad;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureListClear;
        private System.Windows.Forms.ToolStripMenuItem exportToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureListExportHTMLascii;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureListExportHTMLhex;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureListExportTXTascii;
        private System.Windows.Forms.ToolStripMenuItem tsmiCaptureListExportTXThex;
        private System.Windows.Forms.ToolStripMenuItem listToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem clearToolStripMenuItem1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator7;
        private System.Windows.Forms.ToolStripMenuItem listToolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItemCapture;
        private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItemCapture;
        private System.Windows.Forms.ToolStripMenuItem clearToolStripMenuItem2Capture;
        private System.Windows.Forms.ToolStripMenuItem tsmiPacketInjector;
        private System.Windows.Forms.TabPage tabSendList;
        private System.Windows.Forms.ListView lvSendList;
        private System.Windows.Forms.ColumnHeader colSendList;
        private System.Windows.Forms.ContextMenuStrip cmsPacketOptions;
        private System.Windows.Forms.ToolStripMenuItem tsmiOpenPacket;
        private System.Windows.Forms.ToolStripMenuItem tsmiSendPacket;
        private System.Windows.Forms.ToolStripMenuItem tsmiAddToSendList;
        private System.Windows.Forms.ToolStripMenuItem tsmiGenerateFilter;
        private System.Windows.Forms.ContextMenuStrip cmsSendList;
        private System.Windows.Forms.ToolStripMenuItem tsmiSendListIEdit;
        private System.Windows.Forms.ToolStripMenuItem tsmiSendListDelete;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator8;
        private System.Windows.Forms.ToolStripMenuItem tsmiSendListListOptions;
        private System.Windows.Forms.ToolStripMenuItem tsmiSendListListLoad;
        private System.Windows.Forms.ToolStripMenuItem tsmiSendListListSave;
        private System.Windows.Forms.ToolStripMenuItem tsmiSendListListClear;
        private System.Windows.Forms.ToolStripMenuItem tsmiSendListSelection;
    }
}

