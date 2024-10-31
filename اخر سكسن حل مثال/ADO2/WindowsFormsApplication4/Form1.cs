using System;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
using System.Data;

namespace WindowsFormsApplication4
{
    public partial class Form1 : Form
    {
        MySqlConnection conn;
        MySqlCommand cmd;
        MySqlDataReader dr;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                conn = new MySqlConnection();
                conn.ConnectionString = "server=localhost;uid=root;pwd=rootroot";
                conn.Open();
                MessageBox.Show("SUCCESS");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);

            }
            finally { conn.Close(); }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
                cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "show databases;";
                dr = cmd.ExecuteReader();
                listBox1.Items.Clear();
                while (dr.Read())
                    listBox1.Items.Add(dr.GetString(0));

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);

            }
            finally { conn.Close(); }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
                cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "use "+listBox1.Text;
                cmd.ExecuteNonQuery();
                MessageBox.Show(listBox1.Text+ " selected ");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);

            }
            finally { conn.Close(); }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
                cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "show tables;";
                dr = cmd.ExecuteReader();
                listBox2.Items.Clear();
                while (dr.Read())
                    listBox2.Items.Add(dr.GetString(0));

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);

            }
            finally { conn.Close(); }
        }

        private void listBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                conn.Open();
                cmd = new MySqlCommand();
                cmd.Connection = conn;
                cmd.CommandText = "select * from " + listBox2.Text;
                dr = cmd.ExecuteReader();
                DataTable dt = new DataTable();
                dt.Load(dr);
                dataGridView1.DataSource = dt;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);

            }
            finally { conn.Close(); }
        }
    }
}
