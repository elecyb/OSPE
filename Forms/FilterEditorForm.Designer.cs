namespace OSPE
{
    partial class FilterEditorForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FilterEditorForm));
            this.dataGridViewSearch = new System.Windows.Forms.DataGridView();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.nudNumTimesApply = new System.Windows.Forms.NumericUpDown();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.nudPacketLengthMin = new System.Windows.Forms.NumericUpDown();
            this.nudPacketLengthMax = new System.Windows.Forms.NumericUpDown();
            this.chkPackeLength = new System.Windows.Forms.CheckBox();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.chkBreak = new System.Windows.Forms.CheckBox();
            this.chkWatch = new System.Windows.Forms.CheckBox();
            this.chkIgnore = new System.Windows.Forms.CheckBox();
            this.chkBlock = new System.Windows.Forms.CheckBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.txtFilterName = new System.Windows.Forms.TextBox();
            this.printDialog1 = new System.Windows.Forms.PrintDialog();
            this.chkActive = new System.Windows.Forms.CheckBox();
            this.btnApply = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.chkWSRecvFrom = new System.Windows.Forms.CheckBox();
            this.chkWSRecv = new System.Windows.Forms.CheckBox();
            this.chkWSSendTo = new System.Windows.Forms.CheckBox();
            this.chkWSSend = new System.Windows.Forms.CheckBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.chkWS2RecvFrom = new System.Windows.Forms.CheckBox();
            this.chkWS2Recv = new System.Windows.Forms.CheckBox();
            this.chkWS2SendTo = new System.Windows.Forms.CheckBox();
            this.chkWS2Send = new System.Windows.Forms.CheckBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.chkWSARecvFrom = new System.Windows.Forms.CheckBox();
            this.chkWSARecv = new System.Windows.Forms.CheckBox();
            this.chkWSASendTo = new System.Windows.Forms.CheckBox();
            this.chkWSASend = new System.Windows.Forms.CheckBox();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.chkPRSend = new System.Windows.Forms.CheckBox();
            this.chkPRRecv = new System.Windows.Forms.CheckBox();
            this.chkPRWrite = new System.Windows.Forms.CheckBox();
            this.chkPRRead = new System.Windows.Forms.CheckBox();
            this.tabPage5 = new System.Windows.Forms.TabPage();
            this.chkSSLRead = new System.Windows.Forms.CheckBox();
            this.chkSSLWrite = new System.Windows.Forms.CheckBox();
            this.chkDecryptMessage = new System.Windows.Forms.CheckBox();
            this.chkEncryptMessage = new System.Windows.Forms.CheckBox();
            this.chkSSLDecryptPacket = new System.Windows.Forms.CheckBox();
            this.chkSSLEncryptPacket = new System.Windows.Forms.CheckBox();
            this.dataGridViewReplace = new System.Windows.Forms.DataGridView();
            this.dataGridViewReplace2 = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSearch)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudNumTimesApply)).BeginInit();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPacketLengthMin)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPacketLengthMax)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.tabPage5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewReplace)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewReplace2)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewSearch
            // 
            this.dataGridViewSearch.AllowUserToAddRows = false;
            this.dataGridViewSearch.AllowUserToDeleteRows = false;
            this.dataGridViewSearch.AllowUserToResizeColumns = false;
            this.dataGridViewSearch.AllowUserToResizeRows = false;
            this.dataGridViewSearch.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridViewSearch.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewSearch.Location = new System.Drawing.Point(12, 11);
            this.dataGridViewSearch.Name = "dataGridViewSearch";
            this.dataGridViewSearch.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            this.dataGridViewSearch.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.dataGridViewSearch.Size = new System.Drawing.Size(632, 85);
            this.dataGridViewSearch.TabIndex = 0;
            this.dataGridViewSearch.CellPainting += new System.Windows.Forms.DataGridViewCellPaintingEventHandler(this.dataGridView_CellPainting);
            this.dataGridViewSearch.EditingControlShowing += new System.Windows.Forms.DataGridViewEditingControlShowingEventHandler(this.dataGridView_EditingControlShowing);
            this.dataGridViewSearch.KeyDown += new System.Windows.Forms.KeyEventHandler(this.dataGridView_KeyDown);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.groupBox5);
            this.groupBox1.Controls.Add(this.groupBox3);
            this.groupBox1.Controls.Add(this.radioButton3);
            this.groupBox1.Controls.Add(this.radioButton2);
            this.groupBox1.Controls.Add(this.radioButton1);
            this.groupBox1.Location = new System.Drawing.Point(12, 199);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(328, 141);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Search-modify method";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.nudNumTimesApply);
            this.groupBox5.Location = new System.Drawing.Point(219, 91);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(101, 43);
            this.groupBox5.TabIndex = 6;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Nbr times apply";
            // 
            // nudNumTimesApply
            // 
            this.nudNumTimesApply.Enabled = false;
            this.nudNumTimesApply.Location = new System.Drawing.Point(6, 17);
            this.nudNumTimesApply.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudNumTimesApply.Name = "nudNumTimesApply";
            this.nudNumTimesApply.Size = new System.Drawing.Size(87, 20);
            this.nudNumTimesApply.TabIndex = 4;
            this.nudNumTimesApply.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.nudPacketLengthMin);
            this.groupBox3.Controls.Add(this.nudPacketLengthMax);
            this.groupBox3.Controls.Add(this.chkPackeLength);
            this.groupBox3.Location = new System.Drawing.Point(7, 91);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(206, 43);
            this.groupBox3.TabIndex = 5;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Packet Length";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(113, 19);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(26, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "max";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(28, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(23, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "min";
            // 
            // nudPacketLengthMin
            // 
            this.nudPacketLengthMin.Enabled = false;
            this.nudPacketLengthMin.Location = new System.Drawing.Point(52, 17);
            this.nudPacketLengthMin.Maximum = new decimal(new int[] {
            9999,
            0,
            0,
            0});
            this.nudPacketLengthMin.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudPacketLengthMin.Name = "nudPacketLengthMin";
            this.nudPacketLengthMin.Size = new System.Drawing.Size(57, 20);
            this.nudPacketLengthMin.TabIndex = 5;
            this.nudPacketLengthMin.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudPacketLengthMin.ValueChanged += new System.EventHandler(this.nudPacketLengthMin_ValueChanged);
            // 
            // nudPacketLengthMax
            // 
            this.nudPacketLengthMax.Enabled = false;
            this.nudPacketLengthMax.Location = new System.Drawing.Point(142, 17);
            this.nudPacketLengthMax.Maximum = new decimal(new int[] {
            9999,
            0,
            0,
            0});
            this.nudPacketLengthMax.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudPacketLengthMax.Name = "nudPacketLengthMax";
            this.nudPacketLengthMax.Size = new System.Drawing.Size(57, 20);
            this.nudPacketLengthMax.TabIndex = 4;
            this.nudPacketLengthMax.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudPacketLengthMax.ValueChanged += new System.EventHandler(this.nudPacketLengthMax_ValueChanged);
            // 
            // chkPackeLength
            // 
            this.chkPackeLength.AutoSize = true;
            this.chkPackeLength.Location = new System.Drawing.Point(6, 19);
            this.chkPackeLength.Name = "chkPackeLength";
            this.chkPackeLength.Size = new System.Drawing.Size(15, 14);
            this.chkPackeLength.TabIndex = 3;
            this.chkPackeLength.UseVisualStyleBackColor = true;
            this.chkPackeLength.CheckedChanged += new System.EventHandler(this.chkPackeLength_CheckedChanged);
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(6, 65);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(321, 17);
            this.radioButton3.TabIndex = 2;
            this.radioButton3.Text = "Search occurrence, modify from the position of the chain found";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(6, 42);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(308, 17);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.Text = "Search occurrence, modify from the beginning of the packet";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(6, 19);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(269, 17);
            this.radioButton1.TabIndex = 0;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Search and modify from the beginning of the packet";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.chkBreak);
            this.groupBox2.Controls.Add(this.chkWatch);
            this.groupBox2.Controls.Add(this.chkIgnore);
            this.groupBox2.Controls.Add(this.chkBlock);
            this.groupBox2.Location = new System.Drawing.Point(361, 187);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(90, 113);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Action";
            // 
            // chkBreak
            // 
            this.chkBreak.AutoSize = true;
            this.chkBreak.Location = new System.Drawing.Point(20, 88);
            this.chkBreak.Name = "chkBreak";
            this.chkBreak.Size = new System.Drawing.Size(54, 17);
            this.chkBreak.TabIndex = 3;
            this.chkBreak.Text = "Break";
            this.chkBreak.UseVisualStyleBackColor = true;
            // 
            // chkWatch
            // 
            this.chkWatch.AutoSize = true;
            this.chkWatch.Location = new System.Drawing.Point(20, 68);
            this.chkWatch.Name = "chkWatch";
            this.chkWatch.Size = new System.Drawing.Size(58, 17);
            this.chkWatch.TabIndex = 2;
            this.chkWatch.Text = "Watch";
            this.chkWatch.UseVisualStyleBackColor = true;
            this.chkWatch.CheckedChanged += new System.EventHandler(this.chkWatch_CheckedChanged);
            // 
            // chkIgnore
            // 
            this.chkIgnore.AutoSize = true;
            this.chkIgnore.Location = new System.Drawing.Point(20, 45);
            this.chkIgnore.Name = "chkIgnore";
            this.chkIgnore.Size = new System.Drawing.Size(56, 17);
            this.chkIgnore.TabIndex = 1;
            this.chkIgnore.Text = "Ignore";
            this.chkIgnore.UseVisualStyleBackColor = true;
            this.chkIgnore.CheckedChanged += new System.EventHandler(this.chkIgnore_CheckedChanged);
            // 
            // chkBlock
            // 
            this.chkBlock.AutoSize = true;
            this.chkBlock.Location = new System.Drawing.Point(20, 22);
            this.chkBlock.Name = "chkBlock";
            this.chkBlock.Size = new System.Drawing.Size(53, 17);
            this.chkBlock.TabIndex = 0;
            this.chkBlock.Text = "Block";
            this.chkBlock.UseVisualStyleBackColor = true;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.txtFilterName);
            this.groupBox4.Location = new System.Drawing.Point(15, 153);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(322, 40);
            this.groupBox4.TabIndex = 4;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Filter Name";
            // 
            // txtFilterName
            // 
            this.txtFilterName.Location = new System.Drawing.Point(6, 14);
            this.txtFilterName.MaxLength = 80;
            this.txtFilterName.Name = "txtFilterName";
            this.txtFilterName.Size = new System.Drawing.Size(307, 20);
            this.txtFilterName.TabIndex = 0;
            // 
            // printDialog1
            // 
            this.printDialog1.UseEXDialog = true;
            // 
            // chkActive
            // 
            this.chkActive.AutoSize = true;
            this.chkActive.Location = new System.Drawing.Point(361, 164);
            this.chkActive.Name = "chkActive";
            this.chkActive.Size = new System.Drawing.Size(56, 17);
            this.chkActive.TabIndex = 5;
            this.chkActive.Text = "Active";
            this.chkActive.UseVisualStyleBackColor = true;
            // 
            // btnApply
            // 
            this.btnApply.Location = new System.Drawing.Point(398, 313);
            this.btnApply.Name = "btnApply";
            this.btnApply.Size = new System.Drawing.Size(90, 27);
            this.btnApply.TabIndex = 6;
            this.btnApply.Text = "Apply";
            this.btnApply.UseVisualStyleBackColor = true;
            this.btnApply.Click += new System.EventHandler(this.btnApply_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(512, 313);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(90, 27);
            this.btnCancel.TabIndex = 7;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Controls.Add(this.tabPage4);
            this.tabControl1.Controls.Add(this.tabPage5);
            this.tabControl1.Font = new System.Drawing.Font("Microsoft Sans Serif", 6.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tabControl1.Location = new System.Drawing.Point(457, 167);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(192, 133);
            this.tabControl1.TabIndex = 8;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.Transparent;
            this.tabPage1.Controls.Add(this.chkWSRecvFrom);
            this.tabPage1.Controls.Add(this.chkWSRecv);
            this.tabPage1.Controls.Add(this.chkWSSendTo);
            this.tabPage1.Controls.Add(this.chkWSSend);
            this.tabPage1.Location = new System.Drawing.Point(4, 18);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(184, 111);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "WS 1.1";
            // 
            // chkWSRecvFrom
            // 
            this.chkWSRecvFrom.AutoSize = true;
            this.chkWSRecvFrom.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWSRecvFrom.Location = new System.Drawing.Point(14, 83);
            this.chkWSRecvFrom.Name = "chkWSRecvFrom";
            this.chkWSRecvFrom.Size = new System.Drawing.Size(75, 17);
            this.chkWSRecvFrom.TabIndex = 3;
            this.chkWSRecvFrom.Text = "RecvFrom";
            this.chkWSRecvFrom.UseVisualStyleBackColor = true;
            // 
            // chkWSRecv
            // 
            this.chkWSRecv.AutoSize = true;
            this.chkWSRecv.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWSRecv.Location = new System.Drawing.Point(14, 60);
            this.chkWSRecv.Name = "chkWSRecv";
            this.chkWSRecv.Size = new System.Drawing.Size(52, 17);
            this.chkWSRecv.TabIndex = 2;
            this.chkWSRecv.Text = "Recv";
            this.chkWSRecv.UseVisualStyleBackColor = true;
            // 
            // chkWSSendTo
            // 
            this.chkWSSendTo.AutoSize = true;
            this.chkWSSendTo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWSSendTo.Location = new System.Drawing.Point(14, 37);
            this.chkWSSendTo.Name = "chkWSSendTo";
            this.chkWSSendTo.Size = new System.Drawing.Size(64, 17);
            this.chkWSSendTo.TabIndex = 1;
            this.chkWSSendTo.Text = "SendTo";
            this.chkWSSendTo.UseVisualStyleBackColor = true;
            // 
            // chkWSSend
            // 
            this.chkWSSend.AutoSize = true;
            this.chkWSSend.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWSSend.Location = new System.Drawing.Point(14, 14);
            this.chkWSSend.Name = "chkWSSend";
            this.chkWSSend.Size = new System.Drawing.Size(51, 17);
            this.chkWSSend.TabIndex = 0;
            this.chkWSSend.Text = "Send";
            this.chkWSSend.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.Transparent;
            this.tabPage2.Controls.Add(this.chkWS2RecvFrom);
            this.tabPage2.Controls.Add(this.chkWS2Recv);
            this.tabPage2.Controls.Add(this.chkWS2SendTo);
            this.tabPage2.Controls.Add(this.chkWS2Send);
            this.tabPage2.Location = new System.Drawing.Point(4, 18);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(184, 111);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "WS 2.0";
            // 
            // chkWS2RecvFrom
            // 
            this.chkWS2RecvFrom.AutoSize = true;
            this.chkWS2RecvFrom.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWS2RecvFrom.Location = new System.Drawing.Point(14, 83);
            this.chkWS2RecvFrom.Name = "chkWS2RecvFrom";
            this.chkWS2RecvFrom.Size = new System.Drawing.Size(75, 17);
            this.chkWS2RecvFrom.TabIndex = 7;
            this.chkWS2RecvFrom.Text = "RecvFrom";
            this.chkWS2RecvFrom.UseVisualStyleBackColor = true;
            // 
            // chkWS2Recv
            // 
            this.chkWS2Recv.AutoSize = true;
            this.chkWS2Recv.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWS2Recv.Location = new System.Drawing.Point(14, 60);
            this.chkWS2Recv.Name = "chkWS2Recv";
            this.chkWS2Recv.Size = new System.Drawing.Size(52, 17);
            this.chkWS2Recv.TabIndex = 6;
            this.chkWS2Recv.Text = "Recv";
            this.chkWS2Recv.UseVisualStyleBackColor = true;
            // 
            // chkWS2SendTo
            // 
            this.chkWS2SendTo.AutoSize = true;
            this.chkWS2SendTo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWS2SendTo.Location = new System.Drawing.Point(14, 37);
            this.chkWS2SendTo.Name = "chkWS2SendTo";
            this.chkWS2SendTo.Size = new System.Drawing.Size(64, 17);
            this.chkWS2SendTo.TabIndex = 5;
            this.chkWS2SendTo.Text = "SendTo";
            this.chkWS2SendTo.UseVisualStyleBackColor = true;
            // 
            // chkWS2Send
            // 
            this.chkWS2Send.AutoSize = true;
            this.chkWS2Send.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWS2Send.Location = new System.Drawing.Point(14, 14);
            this.chkWS2Send.Name = "chkWS2Send";
            this.chkWS2Send.Size = new System.Drawing.Size(51, 17);
            this.chkWS2Send.TabIndex = 4;
            this.chkWS2Send.Text = "Send";
            this.chkWS2Send.UseVisualStyleBackColor = true;
            // 
            // tabPage3
            // 
            this.tabPage3.BackColor = System.Drawing.Color.Transparent;
            this.tabPage3.Controls.Add(this.chkWSARecvFrom);
            this.tabPage3.Controls.Add(this.chkWSARecv);
            this.tabPage3.Controls.Add(this.chkWSASendTo);
            this.tabPage3.Controls.Add(this.chkWSASend);
            this.tabPage3.Location = new System.Drawing.Point(4, 18);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Size = new System.Drawing.Size(184, 111);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "WSA";
            // 
            // chkWSARecvFrom
            // 
            this.chkWSARecvFrom.AutoSize = true;
            this.chkWSARecvFrom.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWSARecvFrom.Location = new System.Drawing.Point(14, 83);
            this.chkWSARecvFrom.Name = "chkWSARecvFrom";
            this.chkWSARecvFrom.Size = new System.Drawing.Size(100, 17);
            this.chkWSARecvFrom.TabIndex = 7;
            this.chkWSARecvFrom.Text = "WSARecvFrom";
            this.chkWSARecvFrom.UseVisualStyleBackColor = true;
            // 
            // chkWSARecv
            // 
            this.chkWSARecv.AutoSize = true;
            this.chkWSARecv.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWSARecv.Location = new System.Drawing.Point(14, 60);
            this.chkWSARecv.Name = "chkWSARecv";
            this.chkWSARecv.Size = new System.Drawing.Size(77, 17);
            this.chkWSARecv.TabIndex = 6;
            this.chkWSARecv.Text = "WSARecv";
            this.chkWSARecv.UseVisualStyleBackColor = true;
            // 
            // chkWSASendTo
            // 
            this.chkWSASendTo.AutoSize = true;
            this.chkWSASendTo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWSASendTo.Location = new System.Drawing.Point(14, 37);
            this.chkWSASendTo.Name = "chkWSASendTo";
            this.chkWSASendTo.Size = new System.Drawing.Size(89, 17);
            this.chkWSASendTo.TabIndex = 5;
            this.chkWSASendTo.Text = "WSASendTo";
            this.chkWSASendTo.UseVisualStyleBackColor = true;
            // 
            // chkWSASend
            // 
            this.chkWSASend.AutoSize = true;
            this.chkWSASend.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkWSASend.Location = new System.Drawing.Point(14, 14);
            this.chkWSASend.Name = "chkWSASend";
            this.chkWSASend.Size = new System.Drawing.Size(76, 17);
            this.chkWSASend.TabIndex = 4;
            this.chkWSASend.Text = "WSASend";
            this.chkWSASend.UseVisualStyleBackColor = true;
            // 
            // tabPage4
            // 
            this.tabPage4.BackColor = System.Drawing.Color.Transparent;
            this.tabPage4.Controls.Add(this.chkPRSend);
            this.tabPage4.Controls.Add(this.chkPRRecv);
            this.tabPage4.Controls.Add(this.chkPRWrite);
            this.tabPage4.Controls.Add(this.chkPRRead);
            this.tabPage4.Location = new System.Drawing.Point(4, 18);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Size = new System.Drawing.Size(184, 111);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "NSPR";
            // 
            // chkPRSend
            // 
            this.chkPRSend.AutoSize = true;
            this.chkPRSend.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkPRSend.Location = new System.Drawing.Point(14, 83);
            this.chkPRSend.Name = "chkPRSend";
            this.chkPRSend.Size = new System.Drawing.Size(69, 17);
            this.chkPRSend.TabIndex = 11;
            this.chkPRSend.Text = "PR Send";
            this.chkPRSend.UseVisualStyleBackColor = true;
            // 
            // chkPRRecv
            // 
            this.chkPRRecv.AutoSize = true;
            this.chkPRRecv.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkPRRecv.Location = new System.Drawing.Point(14, 60);
            this.chkPRRecv.Name = "chkPRRecv";
            this.chkPRRecv.Size = new System.Drawing.Size(70, 17);
            this.chkPRRecv.TabIndex = 10;
            this.chkPRRecv.Text = "PR Recv";
            this.chkPRRecv.UseVisualStyleBackColor = true;
            // 
            // chkPRWrite
            // 
            this.chkPRWrite.AutoSize = true;
            this.chkPRWrite.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkPRWrite.Location = new System.Drawing.Point(14, 37);
            this.chkPRWrite.Name = "chkPRWrite";
            this.chkPRWrite.Size = new System.Drawing.Size(69, 17);
            this.chkPRWrite.TabIndex = 9;
            this.chkPRWrite.Text = "PR Write";
            this.chkPRWrite.UseVisualStyleBackColor = true;
            // 
            // chkPRRead
            // 
            this.chkPRRead.AutoSize = true;
            this.chkPRRead.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkPRRead.Location = new System.Drawing.Point(14, 14);
            this.chkPRRead.Name = "chkPRRead";
            this.chkPRRead.Size = new System.Drawing.Size(70, 17);
            this.chkPRRead.TabIndex = 8;
            this.chkPRRead.Text = "PR Read";
            this.chkPRRead.UseVisualStyleBackColor = true;
            // 
            // tabPage5
            // 
            this.tabPage5.BackColor = System.Drawing.Color.Transparent;
            this.tabPage5.Controls.Add(this.chkSSLRead);
            this.tabPage5.Controls.Add(this.chkSSLWrite);
            this.tabPage5.Controls.Add(this.chkDecryptMessage);
            this.tabPage5.Controls.Add(this.chkEncryptMessage);
            this.tabPage5.Controls.Add(this.chkSSLDecryptPacket);
            this.tabPage5.Controls.Add(this.chkSSLEncryptPacket);
            this.tabPage5.Location = new System.Drawing.Point(4, 18);
            this.tabPage5.Name = "tabPage5";
            this.tabPage5.Size = new System.Drawing.Size(184, 111);
            this.tabPage5.TabIndex = 4;
            this.tabPage5.Text = "SSL";
            // 
            // chkSSLRead
            // 
            this.chkSSLRead.AutoSize = true;
            this.chkSSLRead.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkSSLRead.Location = new System.Drawing.Point(118, 37);
            this.chkSSLRead.Name = "chkSSLRead";
            this.chkSSLRead.Size = new System.Drawing.Size(71, 17);
            this.chkSSLRead.TabIndex = 13;
            this.chkSSLRead.Text = "SSLWrite";
            this.chkSSLRead.UseVisualStyleBackColor = true;
            // 
            // chkSSLWrite
            // 
            this.chkSSLWrite.AutoSize = true;
            this.chkSSLWrite.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkSSLWrite.Location = new System.Drawing.Point(118, 14);
            this.chkSSLWrite.Name = "chkSSLWrite";
            this.chkSSLWrite.Size = new System.Drawing.Size(72, 17);
            this.chkSSLWrite.TabIndex = 12;
            this.chkSSLWrite.Text = "SSLRead";
            this.chkSSLWrite.UseVisualStyleBackColor = true;
            // 
            // chkDecryptMessage
            // 
            this.chkDecryptMessage.AutoSize = true;
            this.chkDecryptMessage.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkDecryptMessage.Location = new System.Drawing.Point(7, 83);
            this.chkDecryptMessage.Name = "chkDecryptMessage";
            this.chkDecryptMessage.Size = new System.Drawing.Size(106, 17);
            this.chkDecryptMessage.TabIndex = 11;
            this.chkDecryptMessage.Text = "DecryptMessage";
            this.chkDecryptMessage.UseVisualStyleBackColor = true;
            // 
            // chkEncryptMessage
            // 
            this.chkEncryptMessage.AutoSize = true;
            this.chkEncryptMessage.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkEncryptMessage.Location = new System.Drawing.Point(7, 60);
            this.chkEncryptMessage.Name = "chkEncryptMessage";
            this.chkEncryptMessage.Size = new System.Drawing.Size(105, 17);
            this.chkEncryptMessage.TabIndex = 10;
            this.chkEncryptMessage.Text = "EncryptMessage";
            this.chkEncryptMessage.UseVisualStyleBackColor = true;
            // 
            // chkSSLDecryptPacket
            // 
            this.chkSSLDecryptPacket.AutoSize = true;
            this.chkSSLDecryptPacket.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkSSLDecryptPacket.Location = new System.Drawing.Point(7, 37);
            this.chkSSLDecryptPacket.Name = "chkSSLDecryptPacket";
            this.chkSSLDecryptPacket.Size = new System.Drawing.Size(117, 17);
            this.chkSSLDecryptPacket.TabIndex = 9;
            this.chkSSLDecryptPacket.Text = "SSLDecryptPacket";
            this.chkSSLDecryptPacket.UseVisualStyleBackColor = true;
            // 
            // chkSSLEncryptPacket
            // 
            this.chkSSLEncryptPacket.AutoSize = true;
            this.chkSSLEncryptPacket.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chkSSLEncryptPacket.Location = new System.Drawing.Point(7, 14);
            this.chkSSLEncryptPacket.Name = "chkSSLEncryptPacket";
            this.chkSSLEncryptPacket.Size = new System.Drawing.Size(116, 17);
            this.chkSSLEncryptPacket.TabIndex = 8;
            this.chkSSLEncryptPacket.Text = "SSLEncryptPacket";
            this.chkSSLEncryptPacket.UseVisualStyleBackColor = true;
            // 
            // dataGridViewReplace
            // 
            this.dataGridViewReplace.AllowUserToAddRows = false;
            this.dataGridViewReplace.AllowUserToDeleteRows = false;
            this.dataGridViewReplace.AllowUserToResizeColumns = false;
            this.dataGridViewReplace.AllowUserToResizeRows = false;
            this.dataGridViewReplace.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridViewReplace.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewReplace.Location = new System.Drawing.Point(12, 74);
            this.dataGridViewReplace.Name = "dataGridViewReplace";
            this.dataGridViewReplace.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            this.dataGridViewReplace.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.dataGridViewReplace.Size = new System.Drawing.Size(632, 63);
            this.dataGridViewReplace.TabIndex = 9;
            this.dataGridViewReplace.Visible = false;
            this.dataGridViewReplace.CellPainting += new System.Windows.Forms.DataGridViewCellPaintingEventHandler(this.dataGridView_CellPainting);
            this.dataGridViewReplace.EditingControlShowing += new System.Windows.Forms.DataGridViewEditingControlShowingEventHandler(this.dataGridView_EditingControlShowing);
            this.dataGridViewReplace.KeyDown += new System.Windows.Forms.KeyEventHandler(this.dataGridView_KeyDown);
            // 
            // dataGridViewReplace2
            // 
            this.dataGridViewReplace2.AllowUserToAddRows = false;
            this.dataGridViewReplace2.AllowUserToDeleteRows = false;
            this.dataGridViewReplace2.AllowUserToResizeColumns = false;
            this.dataGridViewReplace2.AllowUserToResizeRows = false;
            this.dataGridViewReplace2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridViewReplace2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewReplace2.Location = new System.Drawing.Point(12, 74);
            this.dataGridViewReplace2.Name = "dataGridViewReplace2";
            this.dataGridViewReplace2.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing;
            this.dataGridViewReplace2.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.dataGridViewReplace2.Size = new System.Drawing.Size(632, 63);
            this.dataGridViewReplace2.TabIndex = 10;
            this.dataGridViewReplace2.Visible = false;
            this.dataGridViewReplace2.CellPainting += new System.Windows.Forms.DataGridViewCellPaintingEventHandler(this.dataGridView_CellPainting);
            this.dataGridViewReplace2.EditingControlShowing += new System.Windows.Forms.DataGridViewEditingControlShowingEventHandler(this.dataGridView_EditingControlShowing);
            this.dataGridViewReplace2.KeyDown += new System.Windows.Forms.KeyEventHandler(this.dataGridView_KeyDown);
            // 
            // FilterEditorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(656, 352);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnApply);
            this.Controls.Add(this.chkActive);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.dataGridViewSearch);
            this.Controls.Add(this.dataGridViewReplace2);
            this.Controls.Add(this.dataGridViewReplace);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(636, 385);
            this.Name = "FilterEditorForm";
            this.Text = "Filter Editor";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSearch)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.nudNumTimesApply)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPacketLengthMin)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPacketLengthMax)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            this.tabPage5.ResumeLayout(false);
            this.tabPage5.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewReplace)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewReplace2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewSearch;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.NumericUpDown nudNumTimesApply;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.NumericUpDown nudPacketLengthMax;
        private System.Windows.Forms.CheckBox chkPackeLength;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.CheckBox chkWatch;
        private System.Windows.Forms.CheckBox chkIgnore;
        private System.Windows.Forms.CheckBox chkBlock;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.TextBox txtFilterName;
        private System.Windows.Forms.PrintDialog printDialog1;
        private System.Windows.Forms.CheckBox chkActive;
        private System.Windows.Forms.Button btnApply;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.CheckBox chkWSRecvFrom;
        private System.Windows.Forms.CheckBox chkWSRecv;
        private System.Windows.Forms.CheckBox chkWSSendTo;
        private System.Windows.Forms.CheckBox chkWSSend;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.CheckBox chkWS2RecvFrom;
        private System.Windows.Forms.CheckBox chkWS2Recv;
        private System.Windows.Forms.CheckBox chkWS2SendTo;
        private System.Windows.Forms.CheckBox chkWS2Send;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.CheckBox chkWSARecvFrom;
        private System.Windows.Forms.CheckBox chkWSARecv;
        private System.Windows.Forms.CheckBox chkWSASendTo;
        private System.Windows.Forms.CheckBox chkWSASend;
        private System.Windows.Forms.DataGridView dataGridViewReplace;
        private System.Windows.Forms.DataGridView dataGridViewReplace2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown nudPacketLengthMin;
        private System.Windows.Forms.CheckBox chkBreak;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.CheckBox chkPRSend;
        private System.Windows.Forms.CheckBox chkPRRecv;
        private System.Windows.Forms.CheckBox chkPRWrite;
        private System.Windows.Forms.CheckBox chkPRRead;
        private System.Windows.Forms.TabPage tabPage5;
        private System.Windows.Forms.CheckBox chkSSLRead;
        private System.Windows.Forms.CheckBox chkSSLWrite;
        private System.Windows.Forms.CheckBox chkDecryptMessage;
        private System.Windows.Forms.CheckBox chkEncryptMessage;
        private System.Windows.Forms.CheckBox chkSSLDecryptPacket;
        private System.Windows.Forms.CheckBox chkSSLEncryptPacket;
    }
}