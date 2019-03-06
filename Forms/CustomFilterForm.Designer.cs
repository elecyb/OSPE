namespace OSPE
{
    partial class CustomFilterForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CustomFilterForm));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.compilerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.buildToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showLogToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ospeFunctionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.winshockToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.wsock32RecvToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.wsock32SendToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.wS2RecvToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.wS232SendToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.wS232WSARecvToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.wS232WSASendToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.getBufferAsHexToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.getBufferAsTextToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.messageBoxToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.changeIfMatchToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.fctb = new FastColoredTextBoxNS.FastColoredTextBox();
            this.txtCompilerOutput = new System.Windows.Forms.TextBox();
            this.sfd = new System.Windows.Forms.SaveFileDialog();
            this.ofd = new System.Windows.Forms.OpenFileDialog();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.compilerToolStripMenuItem,
            this.ospeFunctionsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(650, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.openToolStripMenuItem,
            this.toolStripSeparator1,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newToolStripMenuItem
            // 
            this.newToolStripMenuItem.Name = "newToolStripMenuItem";
            this.newToolStripMenuItem.Size = new System.Drawing.Size(114, 22);
            this.newToolStripMenuItem.Text = "New";
            this.newToolStripMenuItem.Click += new System.EventHandler(this.newToolStripMenuItem_Click);
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(114, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(114, 22);
            this.saveAsToolStripMenuItem.Text = "Save As";
            this.saveAsToolStripMenuItem.Click += new System.EventHandler(this.saveAsToolStripMenuItem_Click);
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(114, 22);
            this.openToolStripMenuItem.Text = "Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(111, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(114, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // compilerToolStripMenuItem
            // 
            this.compilerToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.buildToolStripMenuItem,
            this.showLogToolStripMenuItem,
            this.optionsToolStripMenuItem});
            this.compilerToolStripMenuItem.Name = "compilerToolStripMenuItem";
            this.compilerToolStripMenuItem.Size = new System.Drawing.Size(68, 20);
            this.compilerToolStripMenuItem.Text = "Compiler";
            // 
            // buildToolStripMenuItem
            // 
            this.buildToolStripMenuItem.Name = "buildToolStripMenuItem";
            this.buildToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.buildToolStripMenuItem.Text = "Build";
            this.buildToolStripMenuItem.Click += new System.EventHandler(this.buildToolStripMenuItem_Click);
            // 
            // showLogToolStripMenuItem
            // 
            this.showLogToolStripMenuItem.Name = "showLogToolStripMenuItem";
            this.showLogToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.showLogToolStripMenuItem.Text = "Show Log";
            this.showLogToolStripMenuItem.Click += new System.EventHandler(this.showLogToolStripMenuItem_Click);
            // 
            // optionsToolStripMenuItem
            // 
            this.optionsToolStripMenuItem.Name = "optionsToolStripMenuItem";
            this.optionsToolStripMenuItem.Size = new System.Drawing.Size(126, 22);
            this.optionsToolStripMenuItem.Text = "Options";
            this.optionsToolStripMenuItem.Click += new System.EventHandler(this.optionsToolStripMenuItem_Click);
            // 
            // ospeFunctionsToolStripMenuItem
            // 
            this.ospeFunctionsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.winshockToolStripMenuItem,
            this.getBufferAsHexToolStripMenuItem,
            this.getBufferAsTextToolStripMenuItem,
            this.messageBoxToolStripMenuItem,
            this.changeIfMatchToolStripMenuItem});
            this.ospeFunctionsToolStripMenuItem.Name = "ospeFunctionsToolStripMenuItem";
            this.ospeFunctionsToolStripMenuItem.Size = new System.Drawing.Size(101, 20);
            this.ospeFunctionsToolStripMenuItem.Text = "Ospe Functions";
            // 
            // winshockToolStripMenuItem
            // 
            this.winshockToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.wsock32RecvToolStripMenuItem,
            this.wsock32SendToolStripMenuItem,
            this.wS2RecvToolStripMenuItem,
            this.wS232SendToolStripMenuItem,
            this.wS232WSARecvToolStripMenuItem,
            this.wS232WSASendToolStripMenuItem});
            this.winshockToolStripMenuItem.Name = "winshockToolStripMenuItem";
            this.winshockToolStripMenuItem.Size = new System.Drawing.Size(158, 22);
            this.winshockToolStripMenuItem.Text = "Winshock";
            // 
            // wsock32RecvToolStripMenuItem
            // 
            this.wsock32RecvToolStripMenuItem.Name = "wsock32RecvToolStripMenuItem";
            this.wsock32RecvToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.wsock32RecvToolStripMenuItem.Text = "wsock32 - Recv";
            this.wsock32RecvToolStripMenuItem.Click += new System.EventHandler(this.wsock32RecvToolStripMenuItem_Click);
            // 
            // wsock32SendToolStripMenuItem
            // 
            this.wsock32SendToolStripMenuItem.Name = "wsock32SendToolStripMenuItem";
            this.wsock32SendToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.wsock32SendToolStripMenuItem.Text = "wsock32 - Send";
            this.wsock32SendToolStripMenuItem.Click += new System.EventHandler(this.wsock32SendToolStripMenuItem_Click);
            // 
            // wS2RecvToolStripMenuItem
            // 
            this.wS2RecvToolStripMenuItem.Name = "wS2RecvToolStripMenuItem";
            this.wS2RecvToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.wS2RecvToolStripMenuItem.Text = "WS2_32 - Recv";
            this.wS2RecvToolStripMenuItem.Click += new System.EventHandler(this.wS2RecvToolStripMenuItem_Click);
            // 
            // wS232SendToolStripMenuItem
            // 
            this.wS232SendToolStripMenuItem.Name = "wS232SendToolStripMenuItem";
            this.wS232SendToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.wS232SendToolStripMenuItem.Text = "WS2_32 - Send";
            this.wS232SendToolStripMenuItem.Click += new System.EventHandler(this.wS232SendToolStripMenuItem_Click);
            // 
            // wS232WSARecvToolStripMenuItem
            // 
            this.wS232WSARecvToolStripMenuItem.Name = "wS232WSARecvToolStripMenuItem";
            this.wS232WSARecvToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.wS232WSARecvToolStripMenuItem.Text = "WS2_32(WSA) - Recv";
            this.wS232WSARecvToolStripMenuItem.Click += new System.EventHandler(this.wS232WSARecvToolStripMenuItem_Click);
            // 
            // wS232WSASendToolStripMenuItem
            // 
            this.wS232WSASendToolStripMenuItem.Name = "wS232WSASendToolStripMenuItem";
            this.wS232WSASendToolStripMenuItem.Size = new System.Drawing.Size(184, 22);
            this.wS232WSASendToolStripMenuItem.Text = "WS2_32(WSA) - Send";
            this.wS232WSASendToolStripMenuItem.Click += new System.EventHandler(this.wS232WSASendToolStripMenuItem_Click);
            // 
            // getBufferAsHexToolStripMenuItem
            // 
            this.getBufferAsHexToolStripMenuItem.Name = "getBufferAsHexToolStripMenuItem";
            this.getBufferAsHexToolStripMenuItem.Size = new System.Drawing.Size(158, 22);
            this.getBufferAsHexToolStripMenuItem.Text = "GetBufferAsHex";
            this.getBufferAsHexToolStripMenuItem.Click += new System.EventHandler(this.getBufferAsHexToolStripMenuItem_Click);
            // 
            // getBufferAsTextToolStripMenuItem
            // 
            this.getBufferAsTextToolStripMenuItem.Name = "getBufferAsTextToolStripMenuItem";
            this.getBufferAsTextToolStripMenuItem.Size = new System.Drawing.Size(158, 22);
            this.getBufferAsTextToolStripMenuItem.Text = "GetBufferAsText";
            this.getBufferAsTextToolStripMenuItem.Click += new System.EventHandler(this.getBufferAsTextToolStripMenuItem_Click);
            // 
            // messageBoxToolStripMenuItem
            // 
            this.messageBoxToolStripMenuItem.Name = "messageBoxToolStripMenuItem";
            this.messageBoxToolStripMenuItem.Size = new System.Drawing.Size(158, 22);
            this.messageBoxToolStripMenuItem.Text = "MessageBox";
            this.messageBoxToolStripMenuItem.Click += new System.EventHandler(this.messageBoxToolStripMenuItem_Click);
            // 
            // changeIfMatchToolStripMenuItem
            // 
            this.changeIfMatchToolStripMenuItem.Name = "changeIfMatchToolStripMenuItem";
            this.changeIfMatchToolStripMenuItem.Size = new System.Drawing.Size(158, 22);
            this.changeIfMatchToolStripMenuItem.Text = "ChangeIfMatch";
            this.changeIfMatchToolStripMenuItem.Click += new System.EventHandler(this.changeIfMatchToolStripMenuItem_Click);
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 24);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.fctb);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.txtCompilerOutput);
            this.splitContainer1.Size = new System.Drawing.Size(650, 483);
            this.splitContainer1.SplitterDistance = 407;
            this.splitContainer1.SplitterWidth = 5;
            this.splitContainer1.TabIndex = 1;
            // 
            // fctb
            // 
            this.fctb.AllowDrop = true;
            this.fctb.AutoScrollMinSize = new System.Drawing.Size(0, 285);
            this.fctb.BackBrush = null;
            this.fctb.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.fctb.DisabledColor = System.Drawing.Color.FromArgb(((int)(((byte)(100)))), ((int)(((byte)(180)))), ((int)(((byte)(180)))), ((int)(((byte)(180)))));
            this.fctb.Dock = System.Windows.Forms.DockStyle.Fill;
            this.fctb.Font = new System.Drawing.Font("Consolas", 9.75F);
            this.fctb.IsReplaceMode = false;
            this.fctb.Language = FastColoredTextBoxNS.Language.CSharp;
            this.fctb.LeftBracket = '(';
            this.fctb.Location = new System.Drawing.Point(0, 0);
            this.fctb.Name = "fctb";
            this.fctb.Paddings = new System.Windows.Forms.Padding(0);
            this.fctb.RightBracket = ')';
            this.fctb.SelectionColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
            this.fctb.Size = new System.Drawing.Size(650, 407);
            this.fctb.TabIndex = 8;
            this.fctb.Text = resources.GetString("fctb.Text");
            this.fctb.WordWrap = true;
            this.fctb.SelectionChangedDelayed += new System.EventHandler(this.fctb_SelectionChangedDelayed);
            this.fctb.KeyPressing += new System.Windows.Forms.KeyPressEventHandler(this.fctb_KeyPressing);
            // 
            // txtCompilerOutput
            // 
            this.txtCompilerOutput.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtCompilerOutput.Location = new System.Drawing.Point(0, 0);
            this.txtCompilerOutput.Multiline = true;
            this.txtCompilerOutput.Name = "txtCompilerOutput";
            this.txtCompilerOutput.Size = new System.Drawing.Size(650, 71);
            this.txtCompilerOutput.TabIndex = 0;
            // 
            // sfd
            // 
            this.sfd.DefaultExt = "ospe";
            this.sfd.Filter = "All Files (*.*)|*.*";
            this.sfd.Title = "Save File As";
            // 
            // ofd
            // 
            this.ofd.Filter = "Ospe Filter Custom files (*.ospe)|*.ospe|All files (*.*)|*.*";
            this.ofd.Title = "Open Custom Filter";
            // 
            // CustomFilterForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(650, 507);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.menuStrip1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "CustomFilterForm";
            this.Text = "Custom Filter";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem compilerToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem buildToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem showLogToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem optionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ospeFunctionsToolStripMenuItem;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private FastColoredTextBoxNS.FastColoredTextBox fctb;
        private System.Windows.Forms.TextBox txtCompilerOutput;
        private System.Windows.Forms.ToolStripMenuItem winshockToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem wsock32RecvToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem wsock32SendToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem wS2RecvToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem wS232SendToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem wS232WSARecvToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem wS232WSASendToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem getBufferAsHexToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem getBufferAsTextToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem messageBoxToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem changeIfMatchToolStripMenuItem;
        private System.Windows.Forms.SaveFileDialog sfd;
        private System.Windows.Forms.OpenFileDialog ofd;
    }
}