namespace OSPE.Forms
{
    partial class PacketInjectorForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PacketInjectorForm));
            this.hexBox1 = new Be.Windows.Forms.HexBox();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.txtData = new System.Windows.Forms.TextBox();
            this.panelAceptCancel = new System.Windows.Forms.Panel();
            this.btnSave = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.chkEnabled = new System.Windows.Forms.CheckBox();
            this.label6 = new System.Windows.Forms.Label();
            this.txtItemName = new System.Windows.Forms.TextBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.numPacketSize = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.numSendTimes = new System.Windows.Forms.NumericUpDown();
            this.numDelay = new System.Windows.Forms.NumericUpDown();
            this.radSendTimes = new System.Windows.Forms.RadioButton();
            this.radContinously = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.numNewSocketPort = new System.Windows.Forms.NumericUpDown();
            this.txtNewSocketIp = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.radOpenedSocketId = new System.Windows.Forms.RadioButton();
            this.radNewSocket = new System.Windows.Forms.RadioButton();
            this.numOpenedSocketId = new System.Windows.Forms.NumericUpDown();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.timerSender = new System.Windows.Forms.Timer(this.components);
            this.tableLayoutPanel1.SuspendLayout();
            this.panelAceptCancel.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numPacketSize)).BeginInit();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numSendTimes)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numDelay)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numNewSocketPort)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numOpenedSocketId)).BeginInit();
            this.SuspendLayout();
            // 
            // hexBox1
            // 
            this.hexBox1.ColumnInfoVisible = true;
            this.hexBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.hexBox1.Font = new System.Drawing.Font("Courier New", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.hexBox1.InfoForeColor = System.Drawing.SystemColors.GrayText;
            this.hexBox1.LineInfoVisible = true;
            this.hexBox1.Location = new System.Drawing.Point(3, 190);
            this.hexBox1.Name = "hexBox1";
            this.hexBox1.ShadowSelectionColor = System.Drawing.Color.FromArgb(((int)(((byte)(100)))), ((int)(((byte)(60)))), ((int)(((byte)(188)))), ((int)(((byte)(255)))));
            this.hexBox1.Size = new System.Drawing.Size(642, 140);
            this.hexBox1.StringViewVisible = true;
            this.hexBox1.TabIndex = 3;
            this.hexBox1.UseFixedBytesPerLine = true;
            this.hexBox1.VScrollBarVisible = true;
            this.hexBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.hexBox1_Paint);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Controls.Add(this.txtData, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.hexBox1, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.panelAceptCancel, 0, 2);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 3;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 56.13577F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 43.86423F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 168F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(648, 502);
            this.tableLayoutPanel1.TabIndex = 2;
            // 
            // txtData
            // 
            this.txtData.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtData.Location = new System.Drawing.Point(3, 3);
            this.txtData.Multiline = true;
            this.txtData.Name = "txtData";
            this.txtData.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtData.Size = new System.Drawing.Size(642, 181);
            this.txtData.TabIndex = 2;
            this.txtData.TextChanged += new System.EventHandler(this.txtData_TextChanged);
            // 
            // panelAceptCancel
            // 
            this.panelAceptCancel.Controls.Add(this.btnSave);
            this.panelAceptCancel.Controls.Add(this.groupBox4);
            this.panelAceptCancel.Controls.Add(this.statusStrip1);
            this.panelAceptCancel.Controls.Add(this.groupBox2);
            this.panelAceptCancel.Controls.Add(this.groupBox3);
            this.panelAceptCancel.Controls.Add(this.groupBox1);
            this.panelAceptCancel.Controls.Add(this.btnStop);
            this.panelAceptCancel.Controls.Add(this.btnClose);
            this.panelAceptCancel.Controls.Add(this.btnStart);
            this.panelAceptCancel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelAceptCancel.Location = new System.Drawing.Point(3, 336);
            this.panelAceptCancel.Name = "panelAceptCancel";
            this.panelAceptCancel.Size = new System.Drawing.Size(642, 163);
            this.panelAceptCancel.TabIndex = 4;
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(311, 109);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(106, 29);
            this.btnSave.TabIndex = 7;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.chkEnabled);
            this.groupBox4.Controls.Add(this.label6);
            this.groupBox4.Controls.Add(this.txtItemName);
            this.groupBox4.Location = new System.Drawing.Point(536, 3);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(100, 100);
            this.groupBox4.TabIndex = 6;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "List item";
            // 
            // chkEnabled
            // 
            this.chkEnabled.AutoSize = true;
            this.chkEnabled.Location = new System.Drawing.Point(6, 70);
            this.chkEnabled.Name = "chkEnabled";
            this.chkEnabled.Size = new System.Drawing.Size(65, 17);
            this.chkEnabled.TabIndex = 2;
            this.chkEnabled.Text = "Enabled";
            this.chkEnabled.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 21);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(38, 13);
            this.label6.TabIndex = 1;
            this.label6.Text = "Name:";
            // 
            // txtItemName
            // 
            this.txtItemName.Location = new System.Drawing.Point(6, 42);
            this.txtItemName.Name = "txtItemName";
            this.txtItemName.Size = new System.Drawing.Size(88, 20);
            this.txtItemName.TabIndex = 0;
            // 
            // statusStrip1
            // 
            this.statusStrip1.Location = new System.Drawing.Point(0, 141);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(642, 22);
            this.statusStrip1.TabIndex = 5;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.numPacketSize);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Location = new System.Drawing.Point(183, 3);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.groupBox2.Size = new System.Drawing.Size(85, 100);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Size";
            // 
            // numPacketSize
            // 
            this.numPacketSize.Location = new System.Drawing.Point(5, 42);
            this.numPacketSize.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.numPacketSize.Name = "numPacketSize";
            this.numPacketSize.Size = new System.Drawing.Size(64, 20);
            this.numPacketSize.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(2, 23);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 13);
            this.label3.TabIndex = 0;
            this.label3.Text = "Packet Size:";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.numSendTimes);
            this.groupBox3.Controls.Add(this.numDelay);
            this.groupBox3.Controls.Add(this.radSendTimes);
            this.groupBox3.Controls.Add(this.radContinously);
            this.groupBox3.Location = new System.Drawing.Point(9, 3);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(170, 100);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Send";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(91, 42);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Times";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(91, 67);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(56, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Delay (ms)";
            // 
            // numSendTimes
            // 
            this.numSendTimes.Location = new System.Drawing.Point(26, 39);
            this.numSendTimes.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numSendTimes.Name = "numSendTimes";
            this.numSendTimes.Size = new System.Drawing.Size(59, 20);
            this.numSendTimes.TabIndex = 3;
            this.numSendTimes.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // numDelay
            // 
            this.numDelay.Increment = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.numDelay.Location = new System.Drawing.Point(26, 65);
            this.numDelay.Maximum = new decimal(new int[] {
            99999,
            0,
            0,
            0});
            this.numDelay.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numDelay.Name = "numDelay";
            this.numDelay.Size = new System.Drawing.Size(59, 20);
            this.numDelay.TabIndex = 2;
            this.numDelay.Value = new decimal(new int[] {
            1000,
            0,
            0,
            0});
            // 
            // radSendTimes
            // 
            this.radSendTimes.AutoSize = true;
            this.radSendTimes.Checked = true;
            this.radSendTimes.Location = new System.Drawing.Point(6, 42);
            this.radSendTimes.Name = "radSendTimes";
            this.radSendTimes.Size = new System.Drawing.Size(14, 13);
            this.radSendTimes.TabIndex = 1;
            this.radSendTimes.TabStop = true;
            this.radSendTimes.UseVisualStyleBackColor = true;
            // 
            // radContinously
            // 
            this.radContinously.AutoSize = true;
            this.radContinously.Location = new System.Drawing.Point(6, 19);
            this.radContinously.Name = "radContinously";
            this.radContinously.Size = new System.Drawing.Size(79, 17);
            this.radContinously.TabIndex = 0;
            this.radContinously.Text = "Continously";
            this.radContinously.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.numNewSocketPort);
            this.groupBox1.Controls.Add(this.txtNewSocketIp);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.radOpenedSocketId);
            this.groupBox1.Controls.Add(this.radNewSocket);
            this.groupBox1.Controls.Add(this.numOpenedSocketId);
            this.groupBox1.Location = new System.Drawing.Point(274, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(255, 100);
            this.groupBox1.TabIndex = 4;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Socket";
            // 
            // numNewSocketPort
            // 
            this.numNewSocketPort.Enabled = false;
            this.numNewSocketPort.Location = new System.Drawing.Point(138, 39);
            this.numNewSocketPort.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.numNewSocketPort.Name = "numNewSocketPort";
            this.numNewSocketPort.Size = new System.Drawing.Size(60, 20);
            this.numNewSocketPort.TabIndex = 8;
            // 
            // txtNewSocketIp
            // 
            this.txtNewSocketIp.Enabled = false;
            this.txtNewSocketIp.Location = new System.Drawing.Point(138, 17);
            this.txtNewSocketIp.Name = "txtNewSocketIp";
            this.txtNewSocketIp.Size = new System.Drawing.Size(103, 20);
            this.txtNewSocketIp.TabIndex = 4;
            this.txtNewSocketIp.Text = "0.0.0.0";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(103, 39);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(29, 13);
            this.label5.TabIndex = 3;
            this.label5.Text = "Port:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(110, 21);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(20, 13);
            this.label4.TabIndex = 2;
            this.label4.Text = "IP:";
            // 
            // radOpenedSocketId
            // 
            this.radOpenedSocketId.AutoSize = true;
            this.radOpenedSocketId.Checked = true;
            this.radOpenedSocketId.Location = new System.Drawing.Point(13, 68);
            this.radOpenedSocketId.Name = "radOpenedSocketId";
            this.radOpenedSocketId.Size = new System.Drawing.Size(117, 17);
            this.radOpenedSocketId.TabIndex = 1;
            this.radOpenedSocketId.TabStop = true;
            this.radOpenedSocketId.Text = "Opened Socket ID:";
            this.radOpenedSocketId.UseVisualStyleBackColor = true;
            this.radOpenedSocketId.CheckedChanged += new System.EventHandler(this.rad_CheckedChanged);
            // 
            // radNewSocket
            // 
            this.radNewSocket.AutoSize = true;
            this.radNewSocket.Location = new System.Drawing.Point(13, 19);
            this.radNewSocket.Name = "radNewSocket";
            this.radNewSocket.Size = new System.Drawing.Size(84, 17);
            this.radNewSocket.TabIndex = 0;
            this.radNewSocket.Text = "New Socket";
            this.radNewSocket.UseVisualStyleBackColor = true;
            this.radNewSocket.CheckedChanged += new System.EventHandler(this.rad_CheckedChanged);
            // 
            // numOpenedSocketId
            // 
            this.numOpenedSocketId.Location = new System.Drawing.Point(138, 67);
            this.numOpenedSocketId.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.numOpenedSocketId.Name = "numOpenedSocketId";
            this.numOpenedSocketId.Size = new System.Drawing.Size(60, 20);
            this.numOpenedSocketId.TabIndex = 7;
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(162, 109);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(106, 29);
            this.btnStop.TabIndex = 2;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(423, 109);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(106, 29);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(50, 109);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(106, 29);
            this.btnStart.TabIndex = 0;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // timerSender
            // 
            this.timerSender.Tick += new System.EventHandler(this.timerSender_Tick);
            // 
            // PacketInjectorForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(648, 502);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "PacketInjectorForm";
            this.Text = "InjectForm";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.panelAceptCancel.ResumeLayout(false);
            this.panelAceptCancel.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numPacketSize)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numSendTimes)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numDelay)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numNewSocketPort)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numOpenedSocketId)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private Be.Windows.Forms.HexBox hexBox1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TextBox txtData;
        private System.Windows.Forms.Panel panelAceptCancel;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown numPacketSize;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown numSendTimes;
        private System.Windows.Forms.NumericUpDown numDelay;
        private System.Windows.Forms.RadioButton radSendTimes;
        private System.Windows.Forms.RadioButton radContinously;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtNewSocketIp;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.RadioButton radOpenedSocketId;
        private System.Windows.Forms.RadioButton radNewSocket;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.CheckBox chkEnabled;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtItemName;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Timer timerSender;
        private System.Windows.Forms.NumericUpDown numOpenedSocketId;
        private System.Windows.Forms.NumericUpDown numNewSocketPort;
    }
}