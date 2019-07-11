namespace OSPE
{
    partial class SettingsForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SettingsForm));
            this.btnOk = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.tabControlSettings = new System.Windows.Forms.TabControl();
            this.tabGeneral = new System.Windows.Forms.TabPage();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.txtRemoteIp = new System.Windows.Forms.TextBox();
            this.txtLocalIp = new System.Windows.Forms.TextBox();
            this.numRemotePort = new System.Windows.Forms.NumericUpDown();
            this.numLocalPort = new System.Windows.Forms.NumericUpDown();
            this.chkLocalIp = new System.Windows.Forms.CheckBox();
            this.chkRemotePort = new System.Windows.Forms.CheckBox();
            this.chkLocalPort = new System.Windows.Forms.CheckBox();
            this.chkRemoteIp = new System.Windows.Forms.CheckBox();
            this.btnSelectScript = new System.Windows.Forms.Button();
            this.label10 = new System.Windows.Forms.Label();
            this.txtScript = new System.Windows.Forms.TextBox();
            this.chkLogEnabled = new System.Windows.Forms.CheckBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.chkSSLWrite = new System.Windows.Forms.CheckBox();
            this.chkSSLRead = new System.Windows.Forms.CheckBox();
            this.label12 = new System.Windows.Forms.Label();
            this.chkDecryptMessage = new System.Windows.Forms.CheckBox();
            this.chkEncryptMessage = new System.Windows.Forms.CheckBox();
            this.chkSSLDecryptPacket = new System.Windows.Forms.CheckBox();
            this.chkSSLEncryptPacket = new System.Windows.Forms.CheckBox();
            this.label11 = new System.Windows.Forms.Label();
            this.chkPRWrite = new System.Windows.Forms.CheckBox();
            this.chkPRRead = new System.Windows.Forms.CheckBox();
            this.chkPRRecv = new System.Windows.Forms.CheckBox();
            this.chkPRSend = new System.Windows.Forms.CheckBox();
            this.label9 = new System.Windows.Forms.Label();
            this.chkWSARecvFrom = new System.Windows.Forms.CheckBox();
            this.chkWSARecv = new System.Windows.Forms.CheckBox();
            this.chkWSASendTo = new System.Windows.Forms.CheckBox();
            this.chkWSASend = new System.Windows.Forms.CheckBox();
            this.label8 = new System.Windows.Forms.Label();
            this.chkWS2RecvFrom = new System.Windows.Forms.CheckBox();
            this.chkWS2Recv = new System.Windows.Forms.CheckBox();
            this.chkWS2SendTo = new System.Windows.Forms.CheckBox();
            this.chkWS2Send = new System.Windows.Forms.CheckBox();
            this.label7 = new System.Windows.Forms.Label();
            this.chkWSRecvFrom = new System.Windows.Forms.CheckBox();
            this.chkWSRecv = new System.Windows.Forms.CheckBox();
            this.chkWSSendTo = new System.Windows.Forms.CheckBox();
            this.chkWSSend = new System.Windows.Forms.CheckBox();
            this.chkMinimizeToSystemTray = new System.Windows.Forms.CheckBox();
            this.btnSelectDLL = new System.Windows.Forms.Button();
            this.lblDLL = new System.Windows.Forms.Label();
            this.txtDLL = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.tabHotkeys = new System.Windows.Forms.TabPage();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.txtSelectProcessHotKey = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtInjectLastHotKey = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtCustomFilterHotKey = new System.Windows.Forms.TextBox();
            this.txtNormalFilterHotKey = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.txtStopCaptureHotKey = new System.Windows.Forms.TextBox();
            this.txtStartCaptureHotKey = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tableLayoutPanel1.SuspendLayout();
            this.tabControlSettings.SuspendLayout();
            this.tabGeneral.SuspendLayout();
            this.groupBox5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numRemotePort)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numLocalPort)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.tabHotkeys.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnOk
            // 
            this.btnOk.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnOk.Location = new System.Drawing.Point(3, 447);
            this.btnOk.Name = "btnOk";
            this.btnOk.Size = new System.Drawing.Size(491, 23);
            this.btnOk.TabIndex = 3;
            this.btnOk.Text = "OK";
            this.btnOk.UseVisualStyleBackColor = true;
            this.btnOk.Click += new System.EventHandler(this.btnOk_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.btnOk, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.tabControlSettings, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(10, 10);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 92.52577F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 7.474227F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(497, 473);
            this.tableLayoutPanel1.TabIndex = 4;
            // 
            // tabControlSettings
            // 
            this.tabControlSettings.Controls.Add(this.tabGeneral);
            this.tabControlSettings.Controls.Add(this.tabHotkeys);
            this.tabControlSettings.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControlSettings.Location = new System.Drawing.Point(3, 3);
            this.tabControlSettings.Name = "tabControlSettings";
            this.tabControlSettings.SelectedIndex = 0;
            this.tabControlSettings.Size = new System.Drawing.Size(491, 431);
            this.tabControlSettings.TabIndex = 0;
            // 
            // tabGeneral
            // 
            this.tabGeneral.Controls.Add(this.groupBox5);
            this.tabGeneral.Controls.Add(this.btnSelectScript);
            this.tabGeneral.Controls.Add(this.label10);
            this.tabGeneral.Controls.Add(this.txtScript);
            this.tabGeneral.Controls.Add(this.chkLogEnabled);
            this.tabGeneral.Controls.Add(this.groupBox4);
            this.tabGeneral.Controls.Add(this.chkMinimizeToSystemTray);
            this.tabGeneral.Controls.Add(this.btnSelectDLL);
            this.tabGeneral.Controls.Add(this.lblDLL);
            this.tabGeneral.Controls.Add(this.txtDLL);
            this.tabGeneral.Controls.Add(this.button3);
            this.tabGeneral.Location = new System.Drawing.Point(4, 22);
            this.tabGeneral.Name = "tabGeneral";
            this.tabGeneral.Padding = new System.Windows.Forms.Padding(3);
            this.tabGeneral.Size = new System.Drawing.Size(483, 405);
            this.tabGeneral.TabIndex = 1;
            this.tabGeneral.Text = "General";
            this.tabGeneral.UseVisualStyleBackColor = true;
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.txtRemoteIp);
            this.groupBox5.Controls.Add(this.txtLocalIp);
            this.groupBox5.Controls.Add(this.numRemotePort);
            this.groupBox5.Controls.Add(this.numLocalPort);
            this.groupBox5.Controls.Add(this.chkLocalIp);
            this.groupBox5.Controls.Add(this.chkRemotePort);
            this.groupBox5.Controls.Add(this.chkLocalPort);
            this.groupBox5.Controls.Add(this.chkRemoteIp);
            this.groupBox5.Location = new System.Drawing.Point(23, 172);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(438, 71);
            this.groupBox5.TabIndex = 16;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "IP/Port Conditions (capture only)";
            // 
            // txtRemoteIp
            // 
            this.txtRemoteIp.Location = new System.Drawing.Point(316, 16);
            this.txtRemoteIp.Name = "txtRemoteIp";
            this.txtRemoteIp.Size = new System.Drawing.Size(96, 20);
            this.txtRemoteIp.TabIndex = 19;
            // 
            // txtLocalIp
            // 
            this.txtLocalIp.Location = new System.Drawing.Point(105, 17);
            this.txtLocalIp.Name = "txtLocalIp";
            this.txtLocalIp.Size = new System.Drawing.Size(96, 20);
            this.txtLocalIp.TabIndex = 18;
            // 
            // numRemotePort
            // 
            this.numRemotePort.Location = new System.Drawing.Point(316, 39);
            this.numRemotePort.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.numRemotePort.Name = "numRemotePort";
            this.numRemotePort.Size = new System.Drawing.Size(96, 20);
            this.numRemotePort.TabIndex = 17;
            // 
            // numLocalPort
            // 
            this.numLocalPort.Location = new System.Drawing.Point(105, 39);
            this.numLocalPort.Maximum = new decimal(new int[] {
            65535,
            0,
            0,
            0});
            this.numLocalPort.Name = "numLocalPort";
            this.numLocalPort.Size = new System.Drawing.Size(96, 20);
            this.numLocalPort.TabIndex = 16;
            // 
            // chkLocalIp
            // 
            this.chkLocalIp.AutoSize = true;
            this.chkLocalIp.Location = new System.Drawing.Point(17, 19);
            this.chkLocalIp.Name = "chkLocalIp";
            this.chkLocalIp.Size = new System.Drawing.Size(68, 17);
            this.chkLocalIp.TabIndex = 12;
            this.chkLocalIp.Text = "Local IP:";
            this.chkLocalIp.UseVisualStyleBackColor = true;
            // 
            // chkRemotePort
            // 
            this.chkRemotePort.AutoSize = true;
            this.chkRemotePort.Location = new System.Drawing.Point(223, 42);
            this.chkRemotePort.Name = "chkRemotePort";
            this.chkRemotePort.Size = new System.Drawing.Size(88, 17);
            this.chkRemotePort.TabIndex = 15;
            this.chkRemotePort.Text = "Remote Port:";
            this.chkRemotePort.UseVisualStyleBackColor = true;
            // 
            // chkLocalPort
            // 
            this.chkLocalPort.AutoSize = true;
            this.chkLocalPort.Location = new System.Drawing.Point(17, 42);
            this.chkLocalPort.Name = "chkLocalPort";
            this.chkLocalPort.Size = new System.Drawing.Size(77, 17);
            this.chkLocalPort.TabIndex = 13;
            this.chkLocalPort.Text = "Local Port:";
            this.chkLocalPort.UseVisualStyleBackColor = true;
            // 
            // chkRemoteIp
            // 
            this.chkRemoteIp.AutoSize = true;
            this.chkRemoteIp.Location = new System.Drawing.Point(223, 20);
            this.chkRemoteIp.Name = "chkRemoteIp";
            this.chkRemoteIp.Size = new System.Drawing.Size(79, 17);
            this.chkRemoteIp.TabIndex = 14;
            this.chkRemoteIp.Text = "Remote IP:";
            this.chkRemoteIp.UseVisualStyleBackColor = true;
            // 
            // btnSelectScript
            // 
            this.btnSelectScript.Location = new System.Drawing.Point(376, 136);
            this.btnSelectScript.Name = "btnSelectScript";
            this.btnSelectScript.Size = new System.Drawing.Size(73, 23);
            this.btnSelectScript.TabIndex = 11;
            this.btnSelectScript.Text = "Select DLL";
            this.btnSelectScript.UseVisualStyleBackColor = true;
            this.btnSelectScript.Click += new System.EventHandler(this.btnSelectScript_Click);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(28, 96);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(62, 13);
            this.label10.TabIndex = 10;
            this.label10.Text = "SCRIPT file";
            // 
            // txtScript
            // 
            this.txtScript.Location = new System.Drawing.Point(31, 112);
            this.txtScript.Name = "txtScript";
            this.txtScript.Size = new System.Drawing.Size(418, 20);
            this.txtScript.TabIndex = 9;
            // 
            // chkLogEnabled
            // 
            this.chkLogEnabled.AutoSize = true;
            this.chkLogEnabled.Location = new System.Drawing.Point(192, 10);
            this.chkLogEnabled.Name = "chkLogEnabled";
            this.chkLogEnabled.Size = new System.Drawing.Size(80, 17);
            this.chkLogEnabled.TabIndex = 8;
            this.chkLogEnabled.Text = "Enable Log";
            this.chkLogEnabled.UseVisualStyleBackColor = true;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.chkSSLWrite);
            this.groupBox4.Controls.Add(this.chkSSLRead);
            this.groupBox4.Controls.Add(this.label12);
            this.groupBox4.Controls.Add(this.chkDecryptMessage);
            this.groupBox4.Controls.Add(this.chkEncryptMessage);
            this.groupBox4.Controls.Add(this.chkSSLDecryptPacket);
            this.groupBox4.Controls.Add(this.chkSSLEncryptPacket);
            this.groupBox4.Controls.Add(this.label11);
            this.groupBox4.Controls.Add(this.chkPRWrite);
            this.groupBox4.Controls.Add(this.chkPRRead);
            this.groupBox4.Controls.Add(this.chkPRRecv);
            this.groupBox4.Controls.Add(this.chkPRSend);
            this.groupBox4.Controls.Add(this.label9);
            this.groupBox4.Controls.Add(this.chkWSARecvFrom);
            this.groupBox4.Controls.Add(this.chkWSARecv);
            this.groupBox4.Controls.Add(this.chkWSASendTo);
            this.groupBox4.Controls.Add(this.chkWSASend);
            this.groupBox4.Controls.Add(this.label8);
            this.groupBox4.Controls.Add(this.chkWS2RecvFrom);
            this.groupBox4.Controls.Add(this.chkWS2Recv);
            this.groupBox4.Controls.Add(this.chkWS2SendTo);
            this.groupBox4.Controls.Add(this.chkWS2Send);
            this.groupBox4.Controls.Add(this.label7);
            this.groupBox4.Controls.Add(this.chkWSRecvFrom);
            this.groupBox4.Controls.Add(this.chkWSRecv);
            this.groupBox4.Controls.Add(this.chkWSSendTo);
            this.groupBox4.Controls.Add(this.chkWSSend);
            this.groupBox4.Location = new System.Drawing.Point(23, 249);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(438, 148);
            this.groupBox4.TabIndex = 7;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Winsock Functions (capture only)";
            // 
            // chkSSLWrite
            // 
            this.chkSSLWrite.AutoSize = true;
            this.chkSSLWrite.Location = new System.Drawing.Point(323, 124);
            this.chkSSLWrite.Name = "chkSSLWrite";
            this.chkSSLWrite.Size = new System.Drawing.Size(71, 17);
            this.chkSSLWrite.TabIndex = 26;
            this.chkSSLWrite.Text = "SSLWrite";
            this.chkSSLWrite.UseVisualStyleBackColor = true;
            // 
            // chkSSLRead
            // 
            this.chkSSLRead.AutoSize = true;
            this.chkSSLRead.Location = new System.Drawing.Point(323, 108);
            this.chkSSLRead.Name = "chkSSLRead";
            this.chkSSLRead.Size = new System.Drawing.Size(72, 17);
            this.chkSSLRead.TabIndex = 25;
            this.chkSSLRead.Text = "SSLRead";
            this.chkSSLRead.UseVisualStyleBackColor = true;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(320, 25);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(62, 13);
            this.label12.TabIndex = 24;
            this.label12.Text = "SSL Funcs:";
            // 
            // chkDecryptMessage
            // 
            this.chkDecryptMessage.AutoSize = true;
            this.chkDecryptMessage.Location = new System.Drawing.Point(323, 92);
            this.chkDecryptMessage.Name = "chkDecryptMessage";
            this.chkDecryptMessage.Size = new System.Drawing.Size(106, 17);
            this.chkDecryptMessage.TabIndex = 23;
            this.chkDecryptMessage.Text = "DecryptMessage";
            this.chkDecryptMessage.UseVisualStyleBackColor = true;
            // 
            // chkEncryptMessage
            // 
            this.chkEncryptMessage.AutoSize = true;
            this.chkEncryptMessage.Location = new System.Drawing.Point(323, 76);
            this.chkEncryptMessage.Name = "chkEncryptMessage";
            this.chkEncryptMessage.Size = new System.Drawing.Size(105, 17);
            this.chkEncryptMessage.TabIndex = 22;
            this.chkEncryptMessage.Text = "EncryptMessage";
            this.chkEncryptMessage.UseVisualStyleBackColor = true;
            // 
            // chkSSLDecryptPacket
            // 
            this.chkSSLDecryptPacket.AutoSize = true;
            this.chkSSLDecryptPacket.Location = new System.Drawing.Point(323, 60);
            this.chkSSLDecryptPacket.Name = "chkSSLDecryptPacket";
            this.chkSSLDecryptPacket.Size = new System.Drawing.Size(117, 17);
            this.chkSSLDecryptPacket.TabIndex = 21;
            this.chkSSLDecryptPacket.Text = "SSLDecryptPacket";
            this.chkSSLDecryptPacket.UseVisualStyleBackColor = true;
            // 
            // chkSSLEncryptPacket
            // 
            this.chkSSLEncryptPacket.AutoSize = true;
            this.chkSSLEncryptPacket.Location = new System.Drawing.Point(323, 44);
            this.chkSSLEncryptPacket.Name = "chkSSLEncryptPacket";
            this.chkSSLEncryptPacket.Size = new System.Drawing.Size(116, 17);
            this.chkSSLEncryptPacket.TabIndex = 20;
            this.chkSSLEncryptPacket.Text = "SSLEncryptPacket";
            this.chkSSLEncryptPacket.UseVisualStyleBackColor = true;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(248, 31);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(40, 13);
            this.label11.TabIndex = 19;
            this.label11.Text = "NSPR:";
            // 
            // chkPRWrite
            // 
            this.chkPRWrite.AutoSize = true;
            this.chkPRWrite.Location = new System.Drawing.Point(248, 119);
            this.chkPRWrite.Name = "chkPRWrite";
            this.chkPRWrite.Size = new System.Drawing.Size(69, 17);
            this.chkPRWrite.TabIndex = 18;
            this.chkPRWrite.Text = "PR Write";
            this.chkPRWrite.UseVisualStyleBackColor = true;
            // 
            // chkPRRead
            // 
            this.chkPRRead.AutoSize = true;
            this.chkPRRead.Location = new System.Drawing.Point(248, 96);
            this.chkPRRead.Name = "chkPRRead";
            this.chkPRRead.Size = new System.Drawing.Size(70, 17);
            this.chkPRRead.TabIndex = 17;
            this.chkPRRead.Text = "PR Read";
            this.chkPRRead.UseVisualStyleBackColor = true;
            // 
            // chkPRRecv
            // 
            this.chkPRRecv.AutoSize = true;
            this.chkPRRecv.Location = new System.Drawing.Point(248, 73);
            this.chkPRRecv.Name = "chkPRRecv";
            this.chkPRRecv.Size = new System.Drawing.Size(70, 17);
            this.chkPRRecv.TabIndex = 16;
            this.chkPRRecv.Text = "PR Recv";
            this.chkPRRecv.UseVisualStyleBackColor = true;
            // 
            // chkPRSend
            // 
            this.chkPRSend.AutoSize = true;
            this.chkPRSend.Location = new System.Drawing.Point(248, 50);
            this.chkPRSend.Name = "chkPRSend";
            this.chkPRSend.Size = new System.Drawing.Size(69, 17);
            this.chkPRSend.TabIndex = 15;
            this.chkPRSend.Text = "PR Send";
            this.chkPRSend.UseVisualStyleBackColor = true;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(145, 31);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(104, 13);
            this.label9.TabIndex = 14;
            this.label9.Text = "Winsock 2.0 (WSA):";
            // 
            // chkWSARecvFrom
            // 
            this.chkWSARecvFrom.AutoSize = true;
            this.chkWSARecvFrom.Location = new System.Drawing.Point(148, 119);
            this.chkWSARecvFrom.Name = "chkWSARecvFrom";
            this.chkWSARecvFrom.Size = new System.Drawing.Size(100, 17);
            this.chkWSARecvFrom.TabIndex = 13;
            this.chkWSARecvFrom.Text = "WSARecvFrom";
            this.chkWSARecvFrom.UseVisualStyleBackColor = true;
            // 
            // chkWSARecv
            // 
            this.chkWSARecv.AutoSize = true;
            this.chkWSARecv.Location = new System.Drawing.Point(148, 96);
            this.chkWSARecv.Name = "chkWSARecv";
            this.chkWSARecv.Size = new System.Drawing.Size(77, 17);
            this.chkWSARecv.TabIndex = 12;
            this.chkWSARecv.Text = "WSARecv";
            this.chkWSARecv.UseVisualStyleBackColor = true;
            // 
            // chkWSASendTo
            // 
            this.chkWSASendTo.AutoSize = true;
            this.chkWSASendTo.Location = new System.Drawing.Point(148, 73);
            this.chkWSASendTo.Name = "chkWSASendTo";
            this.chkWSASendTo.Size = new System.Drawing.Size(89, 17);
            this.chkWSASendTo.TabIndex = 11;
            this.chkWSASendTo.Text = "WSASendTo";
            this.chkWSASendTo.UseVisualStyleBackColor = true;
            // 
            // chkWSASend
            // 
            this.chkWSASend.AutoSize = true;
            this.chkWSASend.Location = new System.Drawing.Point(148, 50);
            this.chkWSASend.Name = "chkWSASend";
            this.chkWSASend.Size = new System.Drawing.Size(76, 17);
            this.chkWSASend.TabIndex = 10;
            this.chkWSASend.Text = "WSASend";
            this.chkWSASend.UseVisualStyleBackColor = true;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(74, 31);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(70, 13);
            this.label8.TabIndex = 9;
            this.label8.Text = "Winsock 2.0:";
            // 
            // chkWS2RecvFrom
            // 
            this.chkWS2RecvFrom.AutoSize = true;
            this.chkWS2RecvFrom.Location = new System.Drawing.Point(77, 119);
            this.chkWS2RecvFrom.Name = "chkWS2RecvFrom";
            this.chkWS2RecvFrom.Size = new System.Drawing.Size(75, 17);
            this.chkWS2RecvFrom.TabIndex = 8;
            this.chkWS2RecvFrom.Text = "RecvFrom";
            this.chkWS2RecvFrom.UseVisualStyleBackColor = true;
            // 
            // chkWS2Recv
            // 
            this.chkWS2Recv.AutoSize = true;
            this.chkWS2Recv.Location = new System.Drawing.Point(77, 96);
            this.chkWS2Recv.Name = "chkWS2Recv";
            this.chkWS2Recv.Size = new System.Drawing.Size(52, 17);
            this.chkWS2Recv.TabIndex = 7;
            this.chkWS2Recv.Text = "Recv";
            this.chkWS2Recv.UseVisualStyleBackColor = true;
            // 
            // chkWS2SendTo
            // 
            this.chkWS2SendTo.AutoSize = true;
            this.chkWS2SendTo.Location = new System.Drawing.Point(77, 73);
            this.chkWS2SendTo.Name = "chkWS2SendTo";
            this.chkWS2SendTo.Size = new System.Drawing.Size(64, 17);
            this.chkWS2SendTo.TabIndex = 6;
            this.chkWS2SendTo.Text = "SendTo";
            this.chkWS2SendTo.UseVisualStyleBackColor = true;
            // 
            // chkWS2Send
            // 
            this.chkWS2Send.AutoSize = true;
            this.chkWS2Send.Location = new System.Drawing.Point(77, 50);
            this.chkWS2Send.Name = "chkWS2Send";
            this.chkWS2Send.Size = new System.Drawing.Size(51, 17);
            this.chkWS2Send.TabIndex = 5;
            this.chkWS2Send.Text = "Send";
            this.chkWS2Send.UseVisualStyleBackColor = true;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(3, 31);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(70, 13);
            this.label7.TabIndex = 4;
            this.label7.Text = "Winsock 1.1:";
            // 
            // chkWSRecvFrom
            // 
            this.chkWSRecvFrom.AutoSize = true;
            this.chkWSRecvFrom.Location = new System.Drawing.Point(6, 119);
            this.chkWSRecvFrom.Name = "chkWSRecvFrom";
            this.chkWSRecvFrom.Size = new System.Drawing.Size(75, 17);
            this.chkWSRecvFrom.TabIndex = 3;
            this.chkWSRecvFrom.Text = "RecvFrom";
            this.chkWSRecvFrom.UseVisualStyleBackColor = true;
            // 
            // chkWSRecv
            // 
            this.chkWSRecv.AutoSize = true;
            this.chkWSRecv.Location = new System.Drawing.Point(6, 96);
            this.chkWSRecv.Name = "chkWSRecv";
            this.chkWSRecv.Size = new System.Drawing.Size(52, 17);
            this.chkWSRecv.TabIndex = 2;
            this.chkWSRecv.Text = "Recv";
            this.chkWSRecv.UseVisualStyleBackColor = true;
            // 
            // chkWSSendTo
            // 
            this.chkWSSendTo.AutoSize = true;
            this.chkWSSendTo.Location = new System.Drawing.Point(6, 73);
            this.chkWSSendTo.Name = "chkWSSendTo";
            this.chkWSSendTo.Size = new System.Drawing.Size(64, 17);
            this.chkWSSendTo.TabIndex = 1;
            this.chkWSSendTo.Text = "SendTo";
            this.chkWSSendTo.UseVisualStyleBackColor = true;
            // 
            // chkWSSend
            // 
            this.chkWSSend.AutoSize = true;
            this.chkWSSend.Location = new System.Drawing.Point(6, 50);
            this.chkWSSend.Name = "chkWSSend";
            this.chkWSSend.Size = new System.Drawing.Size(51, 17);
            this.chkWSSend.TabIndex = 0;
            this.chkWSSend.Text = "Send";
            this.chkWSSend.UseVisualStyleBackColor = true;
            // 
            // chkMinimizeToSystemTray
            // 
            this.chkMinimizeToSystemTray.AutoSize = true;
            this.chkMinimizeToSystemTray.Location = new System.Drawing.Point(31, 10);
            this.chkMinimizeToSystemTray.Name = "chkMinimizeToSystemTray";
            this.chkMinimizeToSystemTray.Size = new System.Drawing.Size(133, 17);
            this.chkMinimizeToSystemTray.TabIndex = 6;
            this.chkMinimizeToSystemTray.Text = "Minimize to system tray";
            this.chkMinimizeToSystemTray.UseVisualStyleBackColor = true;
            this.chkMinimizeToSystemTray.CheckedChanged += new System.EventHandler(this.chkMinimizeToSystemTray_CheckedChanged);
            // 
            // btnSelectDLL
            // 
            this.btnSelectDLL.Location = new System.Drawing.Point(374, 80);
            this.btnSelectDLL.Name = "btnSelectDLL";
            this.btnSelectDLL.Size = new System.Drawing.Size(75, 23);
            this.btnSelectDLL.TabIndex = 5;
            this.btnSelectDLL.Text = "Select DLL";
            this.btnSelectDLL.UseVisualStyleBackColor = true;
            this.btnSelectDLL.Click += new System.EventHandler(this.btnSelectDLL_Click);
            // 
            // lblDLL
            // 
            this.lblDLL.AutoSize = true;
            this.lblDLL.Location = new System.Drawing.Point(26, 40);
            this.lblDLL.Name = "lblDLL";
            this.lblDLL.Size = new System.Drawing.Size(43, 13);
            this.lblDLL.TabIndex = 4;
            this.lblDLL.Text = "DLL file";
            // 
            // txtDLL
            // 
            this.txtDLL.Location = new System.Drawing.Point(29, 56);
            this.txtDLL.Name = "txtDLL";
            this.txtDLL.Size = new System.Drawing.Size(420, 20);
            this.txtDLL.TabIndex = 3;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(353, 6);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(108, 23);
            this.button3.TabIndex = 2;
            this.button3.Text = "Reset all settings";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.btnResetAllSettings_Click);
            // 
            // tabHotkeys
            // 
            this.tabHotkeys.Controls.Add(this.groupBox3);
            this.tabHotkeys.Controls.Add(this.groupBox2);
            this.tabHotkeys.Controls.Add(this.groupBox1);
            this.tabHotkeys.Location = new System.Drawing.Point(4, 22);
            this.tabHotkeys.Name = "tabHotkeys";
            this.tabHotkeys.Padding = new System.Windows.Forms.Padding(3);
            this.tabHotkeys.Size = new System.Drawing.Size(467, 405);
            this.tabHotkeys.TabIndex = 2;
            this.tabHotkeys.Text = "HotKeys";
            this.tabHotkeys.UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txtSelectProcessHotKey);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.txtInjectLastHotKey);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Location = new System.Drawing.Point(40, 207);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(264, 87);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Injection";
            // 
            // txtSelectProcessHotKey
            // 
            this.txtSelectProcessHotKey.Location = new System.Drawing.Point(110, 19);
            this.txtSelectProcessHotKey.Name = "txtSelectProcessHotKey";
            this.txtSelectProcessHotKey.ReadOnly = true;
            this.txtSelectProcessHotKey.Size = new System.Drawing.Size(123, 20);
            this.txtSelectProcessHotKey.TabIndex = 4;
            this.txtSelectProcessHotKey.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtSelectProcess_KeyDown);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(27, 22);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(81, 13);
            this.label5.TabIndex = 3;
            this.label5.Text = "Select Process:";
            // 
            // txtInjectLastHotKey
            // 
            this.txtInjectLastHotKey.Location = new System.Drawing.Point(110, 45);
            this.txtInjectLastHotKey.Name = "txtInjectLastHotKey";
            this.txtInjectLastHotKey.ReadOnly = true;
            this.txtInjectLastHotKey.Size = new System.Drawing.Size(123, 20);
            this.txtInjectLastHotKey.TabIndex = 2;
            this.txtInjectLastHotKey.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtInjectLast_KeyDown);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(27, 48);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(59, 13);
            this.label6.TabIndex = 0;
            this.label6.Text = "Inject Last:";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtCustomFilterHotKey);
            this.groupBox2.Controls.Add(this.txtNormalFilterHotKey);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Location = new System.Drawing.Point(40, 114);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(264, 87);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Filters";
            // 
            // txtCustomFilterHotKey
            // 
            this.txtCustomFilterHotKey.Location = new System.Drawing.Point(110, 48);
            this.txtCustomFilterHotKey.Name = "txtCustomFilterHotKey";
            this.txtCustomFilterHotKey.ReadOnly = true;
            this.txtCustomFilterHotKey.Size = new System.Drawing.Size(123, 20);
            this.txtCustomFilterHotKey.TabIndex = 3;
            this.txtCustomFilterHotKey.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtCustomFilterKey_KeyDown);
            // 
            // txtNormalFilterHotKey
            // 
            this.txtNormalFilterHotKey.Location = new System.Drawing.Point(110, 19);
            this.txtNormalFilterHotKey.Name = "txtNormalFilterHotKey";
            this.txtNormalFilterHotKey.ReadOnly = true;
            this.txtNormalFilterHotKey.Size = new System.Drawing.Size(123, 20);
            this.txtNormalFilterHotKey.TabIndex = 2;
            this.txtNormalFilterHotKey.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtNormalFilterKey_KeyDown);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(28, 51);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(70, 13);
            this.label3.TabIndex = 1;
            this.label3.Text = "Custom Filter:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(28, 22);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(68, 13);
            this.label4.TabIndex = 0;
            this.label4.Text = "Normal Filter:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txtStopCaptureHotKey);
            this.groupBox1.Controls.Add(this.txtStartCaptureHotKey);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(40, 21);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(264, 87);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Capture";
            // 
            // txtStopCaptureHotKey
            // 
            this.txtStopCaptureHotKey.Location = new System.Drawing.Point(110, 48);
            this.txtStopCaptureHotKey.Name = "txtStopCaptureHotKey";
            this.txtStopCaptureHotKey.ReadOnly = true;
            this.txtStopCaptureHotKey.Size = new System.Drawing.Size(123, 20);
            this.txtStopCaptureHotKey.TabIndex = 3;
            this.txtStopCaptureHotKey.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtStopCaptureKey_KeyDown);
            // 
            // txtStartCaptureHotKey
            // 
            this.txtStartCaptureHotKey.Location = new System.Drawing.Point(110, 19);
            this.txtStartCaptureHotKey.Name = "txtStartCaptureHotKey";
            this.txtStartCaptureHotKey.ReadOnly = true;
            this.txtStartCaptureHotKey.Size = new System.Drawing.Size(123, 20);
            this.txtStartCaptureHotKey.TabIndex = 2;
            this.txtStartCaptureHotKey.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtStartCaptureKey_KeyDown);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(27, 51);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(32, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Stop:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(32, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Start:";
            // 
            // SettingsForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(517, 493);
            this.Controls.Add(this.tableLayoutPanel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(517, 458);
            this.Name = "SettingsForm";
            this.Padding = new System.Windows.Forms.Padding(10);
            this.Text = "Settings";
            this.Load += new System.EventHandler(this.frmSettings_Load);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tabControlSettings.ResumeLayout(false);
            this.tabGeneral.ResumeLayout(false);
            this.tabGeneral.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numRemotePort)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numLocalPort)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.tabHotkeys.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnOk;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TabControl tabControlSettings;
        private System.Windows.Forms.TabPage tabGeneral;
        private System.Windows.Forms.CheckBox chkLogEnabled;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.CheckBox chkWSARecvFrom;
        private System.Windows.Forms.CheckBox chkWSARecv;
        private System.Windows.Forms.CheckBox chkWSASendTo;
        private System.Windows.Forms.CheckBox chkWSASend;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.CheckBox chkWS2RecvFrom;
        private System.Windows.Forms.CheckBox chkWS2Recv;
        private System.Windows.Forms.CheckBox chkWS2SendTo;
        private System.Windows.Forms.CheckBox chkWS2Send;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.CheckBox chkWSRecvFrom;
        private System.Windows.Forms.CheckBox chkWSRecv;
        private System.Windows.Forms.CheckBox chkWSSendTo;
        private System.Windows.Forms.CheckBox chkWSSend;
        private System.Windows.Forms.CheckBox chkMinimizeToSystemTray;
        private System.Windows.Forms.Button btnSelectDLL;
        private System.Windows.Forms.Label lblDLL;
        private System.Windows.Forms.TextBox txtDLL;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.TabPage tabHotkeys;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox txtSelectProcessHotKey;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtInjectLastHotKey;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox txtCustomFilterHotKey;
        private System.Windows.Forms.TextBox txtNormalFilterHotKey;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtStopCaptureHotKey;
        private System.Windows.Forms.TextBox txtStartCaptureHotKey;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnSelectScript;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox txtScript;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.TextBox txtRemoteIp;
        private System.Windows.Forms.TextBox txtLocalIp;
        private System.Windows.Forms.NumericUpDown numRemotePort;
        private System.Windows.Forms.NumericUpDown numLocalPort;
        private System.Windows.Forms.CheckBox chkLocalIp;
        private System.Windows.Forms.CheckBox chkRemotePort;
        private System.Windows.Forms.CheckBox chkLocalPort;
        private System.Windows.Forms.CheckBox chkRemoteIp;
        private System.Windows.Forms.CheckBox chkSSLWrite;
        private System.Windows.Forms.CheckBox chkSSLRead;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.CheckBox chkDecryptMessage;
        private System.Windows.Forms.CheckBox chkEncryptMessage;
        private System.Windows.Forms.CheckBox chkSSLDecryptPacket;
        private System.Windows.Forms.CheckBox chkSSLEncryptPacket;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.CheckBox chkPRWrite;
        private System.Windows.Forms.CheckBox chkPRRead;
        private System.Windows.Forms.CheckBox chkPRRecv;
        private System.Windows.Forms.CheckBox chkPRSend;
    }
}