namespace CSharpWindowsFormsApp1
{
    partial class Form
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
            this.Label_for_Text = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Label_for_Text
            // 
            this.Label_for_Text.Location = new System.Drawing.Point(345, 215);
            this.Label_for_Text.Name = "Label_for_Text";
            this.Label_for_Text.Size = new System.Drawing.Size(86, 23);
            this.Label_for_Text.TabIndex = 0;
            this.Label_for_Text.Text = "Click Here";
            this.Label_for_Text.UseVisualStyleBackColor = true;
            this.Label_for_Text.Click += new System.EventHandler(this.Label_for_Text_Click);
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Label_for_Text);
            this.Name = "Form";
            this.Text = "MyApp";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Label_for_Text;
    }
}

