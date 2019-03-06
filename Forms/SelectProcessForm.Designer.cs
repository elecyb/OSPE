namespace OSPE
{
    partial class SelectProcessForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param Name="disposing">true if managed resources should be disposed; otherwise, false.</param>
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SelectProcessForm));
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.lvwProcesses = new System.Windows.Forms.ListView();
            this.colName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colPid = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.colPath = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btnBringToFront = new System.Windows.Forms.Button();
            this.rdo32Icons = new System.Windows.Forms.RadioButton();
            this.rdo24Icons = new System.Windows.Forms.RadioButton();
            this.rdo16Icons = new System.Windows.Forms.RadioButton();
            this.txtSearch = new System.Windows.Forms.TextBox();
            this.btnInject = new System.Windows.Forms.Button();
            this.btnRefresh = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.lvwProcesses);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.btnBringToFront);
            this.splitContainer1.Panel2.Controls.Add(this.rdo32Icons);
            this.splitContainer1.Panel2.Controls.Add(this.rdo24Icons);
            this.splitContainer1.Panel2.Controls.Add(this.rdo16Icons);
            this.splitContainer1.Panel2.Controls.Add(this.txtSearch);
            this.splitContainer1.Panel2.Controls.Add(this.btnInject);
            this.splitContainer1.Panel2.Controls.Add(this.btnRefresh);
            this.splitContainer1.Size = new System.Drawing.Size(600, 482);
            this.splitContainer1.SplitterDistance = 442;
            this.splitContainer1.TabIndex = 0;
            // 
            // lvwProcesses
            // 
            this.lvwProcesses.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.colName,
            this.colPid,
            this.colPath});
            this.lvwProcesses.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lvwProcesses.FullRowSelect = true;
            this.lvwProcesses.Location = new System.Drawing.Point(0, 0);
            this.lvwProcesses.MultiSelect = false;
            this.lvwProcesses.Name = "lvwProcesses";
            this.lvwProcesses.Size = new System.Drawing.Size(600, 442);
            this.lvwProcesses.TabIndex = 0;
            this.lvwProcesses.UseCompatibleStateImageBehavior = false;
            this.lvwProcesses.View = System.Windows.Forms.View.Details;
            this.lvwProcesses.DoubleClick += new System.EventHandler(this.lvwProcesses_MouseDoubleClick);
            this.lvwProcesses.Resize += new System.EventHandler(this.lvwProcesses_Resize);
            // 
            // colName
            // 
            this.colName.Text = "Process Name";
            this.colName.Width = 100;
            // 
            // colPid
            // 
            this.colPid.Text = "PID";
            // 
            // colPath
            // 
            this.colPath.Text = "Path";
            this.colPath.Width = 436;
            // 
            // btnBringToFront
            // 
            this.btnBringToFront.Location = new System.Drawing.Point(514, 6);
            this.btnBringToFront.Name = "btnBringToFront";
            this.btnBringToFront.Size = new System.Drawing.Size(74, 23);
            this.btnBringToFront.TabIndex = 14;
            this.btnBringToFront.Text = "Focus Proc";
            this.btnBringToFront.UseVisualStyleBackColor = true;
            this.btnBringToFront.Click += new System.EventHandler(this.btnBringToFront_Click);
            // 
            // rdo32Icons
            // 
            this.rdo32Icons.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdo32Icons.AutoSize = true;
            this.rdo32Icons.Location = new System.Drawing.Point(460, 6);
            this.rdo32Icons.Name = "rdo32Icons";
            this.rdo32Icons.Size = new System.Drawing.Size(38, 23);
            this.rdo32Icons.TabIndex = 13;
            this.rdo32Icons.TabStop = true;
            this.rdo32Icons.Text = "       ";
            this.rdo32Icons.UseVisualStyleBackColor = true;
            this.rdo32Icons.CheckedChanged += new System.EventHandler(this.rdo32Icons_CheckedChanged);
            // 
            // rdo24Icons
            // 
            this.rdo24Icons.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdo24Icons.AutoSize = true;
            this.rdo24Icons.Location = new System.Drawing.Point(416, 6);
            this.rdo24Icons.Name = "rdo24Icons";
            this.rdo24Icons.Size = new System.Drawing.Size(38, 23);
            this.rdo24Icons.TabIndex = 12;
            this.rdo24Icons.TabStop = true;
            this.rdo24Icons.Text = "       ";
            this.rdo24Icons.UseVisualStyleBackColor = true;
            this.rdo24Icons.CheckedChanged += new System.EventHandler(this.rdo24Icons_CheckedChanged);
            // 
            // rdo16Icons
            // 
            this.rdo16Icons.Appearance = System.Windows.Forms.Appearance.Button;
            this.rdo16Icons.AutoSize = true;
            this.rdo16Icons.Location = new System.Drawing.Point(372, 6);
            this.rdo16Icons.Name = "rdo16Icons";
            this.rdo16Icons.Size = new System.Drawing.Size(38, 23);
            this.rdo16Icons.TabIndex = 11;
            this.rdo16Icons.TabStop = true;
            this.rdo16Icons.Text = "       ";
            this.rdo16Icons.UseVisualStyleBackColor = true;
            this.rdo16Icons.CheckedChanged += new System.EventHandler(this.rdo16Icons_CheckedChanged);
            // 
            // txtSearch
            // 
            this.txtSearch.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtSearch.Location = new System.Drawing.Point(240, 8);
            this.txtSearch.Name = "txtSearch";
            this.txtSearch.Size = new System.Drawing.Size(114, 20);
            this.txtSearch.TabIndex = 3;
            this.txtSearch.Text = "Search Process...";
            this.txtSearch.Click += new System.EventHandler(this.txtSearch_Click);
            this.txtSearch.TextChanged += new System.EventHandler(this.txtSearch_TextChanged);
            // 
            // btnInject
            // 
            this.btnInject.Location = new System.Drawing.Point(115, 5);
            this.btnInject.Name = "btnInject";
            this.btnInject.Size = new System.Drawing.Size(97, 24);
            this.btnInject.TabIndex = 1;
            this.btnInject.Text = "Inject";
            this.btnInject.UseVisualStyleBackColor = true;
            this.btnInject.Click += new System.EventHandler(this.btnInject_Click);
            // 
            // btnRefresh
            // 
            this.btnRefresh.Location = new System.Drawing.Point(12, 5);
            this.btnRefresh.Name = "btnRefresh";
            this.btnRefresh.Size = new System.Drawing.Size(97, 24);
            this.btnRefresh.TabIndex = 0;
            this.btnRefresh.Text = "Refresh";
            this.btnRefresh.UseVisualStyleBackColor = true;
            this.btnRefresh.Click += new System.EventHandler(this.btnRefresh_Click);
            // 
            // SelectProcessForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(600, 482);
            this.Controls.Add(this.splitContainer1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(300, 300);
            this.Name = "SelectProcessForm";
            this.Text = "SelectProcessForm";
            this.Load += new System.EventHandler(this.frmSelectProcess_Load);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Button btnInject;
        private System.Windows.Forms.Button btnRefresh;
        private System.Windows.Forms.ListView lvwProcesses;
        private System.Windows.Forms.ColumnHeader colName;
        private System.Windows.Forms.ColumnHeader colPid;
        private System.Windows.Forms.ColumnHeader colPath;
        private System.Windows.Forms.TextBox txtSearch;
        private System.Windows.Forms.RadioButton rdo16Icons;
        private System.Windows.Forms.RadioButton rdo32Icons;
        private System.Windows.Forms.RadioButton rdo24Icons;
        private System.Windows.Forms.Button btnBringToFront;
    }
}