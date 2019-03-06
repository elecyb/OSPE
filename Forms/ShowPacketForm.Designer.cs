namespace OSPE
{
    partial class ShowPacketForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ShowPacketForm));
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.panelHeader = new System.Windows.Forms.Panel();
            this.btnGenerateFilter = new System.Windows.Forms.Button();
            this.lblFunc = new System.Windows.Forms.Label();
            this.picDirection = new System.Windows.Forms.PictureBox();
            this.txtSize = new System.Windows.Forms.TextBox();
            this.lblSize = new System.Windows.Forms.Label();
            this.txtRemote = new System.Windows.Forms.TextBox();
            this.lblRemote = new System.Windows.Forms.Label();
            this.txtLocal = new System.Windows.Forms.TextBox();
            this.lblLocal = new System.Windows.Forms.Label();
            this.txtPacket = new System.Windows.Forms.TextBox();
            this.lblPacket = new System.Windows.Forms.Label();
            this.txtData = new System.Windows.Forms.TextBox();
            this.hexBox1 = new Be.Windows.Forms.HexBox();
            this.panelAceptCancel = new System.Windows.Forms.Panel();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnAccept = new System.Windows.Forms.Button();
            this.tableLayoutPanel1.SuspendLayout();
            this.panelHeader.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picDirection)).BeginInit();
            this.panelAceptCancel.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Controls.Add(this.panelHeader, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.txtData, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.hexBox1, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.panelAceptCancel, 0, 3);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 52F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 56.13577F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 43.86423F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 0F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(652, 467);
            this.tableLayoutPanel1.TabIndex = 1;
            // 
            // panelHeader
            // 
            this.panelHeader.Controls.Add(this.btnGenerateFilter);
            this.panelHeader.Controls.Add(this.lblFunc);
            this.panelHeader.Controls.Add(this.picDirection);
            this.panelHeader.Controls.Add(this.txtSize);
            this.panelHeader.Controls.Add(this.lblSize);
            this.panelHeader.Controls.Add(this.txtRemote);
            this.panelHeader.Controls.Add(this.lblRemote);
            this.panelHeader.Controls.Add(this.txtLocal);
            this.panelHeader.Controls.Add(this.lblLocal);
            this.panelHeader.Controls.Add(this.txtPacket);
            this.panelHeader.Controls.Add(this.lblPacket);
            this.panelHeader.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelHeader.Location = new System.Drawing.Point(3, 3);
            this.panelHeader.Name = "panelHeader";
            this.panelHeader.Size = new System.Drawing.Size(646, 46);
            this.panelHeader.TabIndex = 1;
            // 
            // btnGenerateFilter
            // 
            this.btnGenerateFilter.Location = new System.Drawing.Point(412, 21);
            this.btnGenerateFilter.Name = "btnGenerateFilter";
            this.btnGenerateFilter.Size = new System.Drawing.Size(108, 23);
            this.btnGenerateFilter.TabIndex = 5;
            this.btnGenerateFilter.Text = "Generate Filter";
            this.btnGenerateFilter.UseVisualStyleBackColor = true;
            this.btnGenerateFilter.Click += new System.EventHandler(this.btnGenerateFilter_Click);
            // 
            // lblFunc
            // 
            this.lblFunc.AutoSize = true;
            this.lblFunc.Location = new System.Drawing.Point(154, 7);
            this.lblFunc.Name = "lblFunc";
            this.lblFunc.Size = new System.Drawing.Size(65, 13);
            this.lblFunc.TabIndex = 4;
            this.lblFunc.Text = "Func_Name";
            // 
            // picDirection
            // 
            this.picDirection.Location = new System.Drawing.Point(175, 24);
            this.picDirection.Name = "picDirection";
            this.picDirection.Size = new System.Drawing.Size(28, 18);
            this.picDirection.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.picDirection.TabIndex = 2;
            this.picDirection.TabStop = false;
            // 
            // txtSize
            // 
            this.txtSize.Location = new System.Drawing.Point(326, 23);
            this.txtSize.Name = "txtSize";
            this.txtSize.ReadOnly = true;
            this.txtSize.Size = new System.Drawing.Size(50, 20);
            this.txtSize.TabIndex = 1;
            this.txtSize.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblSize
            // 
            this.lblSize.AutoSize = true;
            this.lblSize.Location = new System.Drawing.Point(339, 6);
            this.lblSize.Name = "lblSize";
            this.lblSize.Size = new System.Drawing.Size(27, 13);
            this.lblSize.TabIndex = 0;
            this.lblSize.Text = "Size";
            // 
            // txtRemote
            // 
            this.txtRemote.Location = new System.Drawing.Point(204, 23);
            this.txtRemote.Name = "txtRemote";
            this.txtRemote.ReadOnly = true;
            this.txtRemote.Size = new System.Drawing.Size(118, 20);
            this.txtRemote.TabIndex = 1;
            this.txtRemote.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblRemote
            // 
            this.lblRemote.AutoSize = true;
            this.lblRemote.Location = new System.Drawing.Point(239, 7);
            this.lblRemote.Name = "lblRemote";
            this.lblRemote.Size = new System.Drawing.Size(44, 13);
            this.lblRemote.TabIndex = 0;
            this.lblRemote.Text = "Remote";
            // 
            // txtLocal
            // 
            this.txtLocal.Location = new System.Drawing.Point(52, 23);
            this.txtLocal.Name = "txtLocal";
            this.txtLocal.ReadOnly = true;
            this.txtLocal.Size = new System.Drawing.Size(123, 20);
            this.txtLocal.TabIndex = 1;
            this.txtLocal.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblLocal
            // 
            this.lblLocal.AutoSize = true;
            this.lblLocal.Location = new System.Drawing.Point(97, 6);
            this.lblLocal.Name = "lblLocal";
            this.lblLocal.Size = new System.Drawing.Size(33, 13);
            this.lblLocal.TabIndex = 0;
            this.lblLocal.Text = "Local";
            // 
            // txtPacket
            // 
            this.txtPacket.Location = new System.Drawing.Point(3, 23);
            this.txtPacket.Name = "txtPacket";
            this.txtPacket.ReadOnly = true;
            this.txtPacket.Size = new System.Drawing.Size(45, 20);
            this.txtPacket.TabIndex = 1;
            this.txtPacket.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // lblPacket
            // 
            this.lblPacket.AutoSize = true;
            this.lblPacket.Location = new System.Drawing.Point(7, 6);
            this.lblPacket.Name = "lblPacket";
            this.lblPacket.Size = new System.Drawing.Size(41, 13);
            this.lblPacket.TabIndex = 0;
            this.lblPacket.Text = "Packet";
            // 
            // txtData
            // 
            this.txtData.Dock = System.Windows.Forms.DockStyle.Fill;
            this.txtData.Location = new System.Drawing.Point(3, 55);
            this.txtData.Multiline = true;
            this.txtData.Name = "txtData";
            this.txtData.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtData.Size = new System.Drawing.Size(646, 226);
            this.txtData.TabIndex = 2;
            this.txtData.TextChanged += new System.EventHandler(this.txtData_TextChanged);
            // 
            // hexBox1
            // 
            this.hexBox1.ColumnInfoVisible = true;
            this.hexBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.hexBox1.Font = new System.Drawing.Font("Courier New", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.hexBox1.InfoForeColor = System.Drawing.SystemColors.GrayText;
            this.hexBox1.LineInfoVisible = true;
            this.hexBox1.Location = new System.Drawing.Point(3, 287);
            this.hexBox1.Name = "hexBox1";
            this.hexBox1.ShadowSelectionColor = System.Drawing.Color.FromArgb(((int)(((byte)(100)))), ((int)(((byte)(60)))), ((int)(((byte)(188)))), ((int)(((byte)(255)))));
            this.hexBox1.Size = new System.Drawing.Size(646, 176);
            this.hexBox1.StringViewVisible = true;
            this.hexBox1.TabIndex = 3;
            this.hexBox1.UseFixedBytesPerLine = true;
            this.hexBox1.VScrollBarVisible = true;
            this.hexBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.hexBox1_Paint);
            // 
            // panelAceptCancel
            // 
            this.panelAceptCancel.Controls.Add(this.btnCancel);
            this.panelAceptCancel.Controls.Add(this.btnAccept);
            this.panelAceptCancel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelAceptCancel.Location = new System.Drawing.Point(3, 469);
            this.panelAceptCancel.Name = "panelAceptCancel";
            this.panelAceptCancel.Size = new System.Drawing.Size(646, 1);
            this.panelAceptCancel.TabIndex = 4;
            this.panelAceptCancel.Visible = false;
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(352, 0);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(106, 29);
            this.btnCancel.TabIndex = 1;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnAccept
            // 
            this.btnAccept.Location = new System.Drawing.Point(157, 0);
            this.btnAccept.Name = "btnAccept";
            this.btnAccept.Size = new System.Drawing.Size(106, 29);
            this.btnAccept.TabIndex = 0;
            this.btnAccept.Text = "Accept";
            this.btnAccept.UseVisualStyleBackColor = true;
            this.btnAccept.Click += new System.EventHandler(this.btnAccept_Click);
            // 
            // ShowPacketForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(652, 467);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "ShowPacketForm";
            this.Text = "Packet";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.panelHeader.ResumeLayout(false);
            this.panelHeader.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.picDirection)).EndInit();
            this.panelAceptCancel.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Panel panelHeader;
        private System.Windows.Forms.TextBox txtSize;
        private System.Windows.Forms.Label lblSize;
        private System.Windows.Forms.TextBox txtRemote;
        private System.Windows.Forms.Label lblRemote;
        private System.Windows.Forms.TextBox txtLocal;
        private System.Windows.Forms.Label lblLocal;
        private System.Windows.Forms.TextBox txtPacket;
        private System.Windows.Forms.Label lblPacket;
        private System.Windows.Forms.PictureBox picDirection;
        private System.Windows.Forms.TextBox txtData;
        private System.Windows.Forms.Label lblFunc;
        private Be.Windows.Forms.HexBox hexBox1;
        private System.Windows.Forms.Panel panelAceptCancel;
        private System.Windows.Forms.Button btnAccept;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnGenerateFilter;
    }
}