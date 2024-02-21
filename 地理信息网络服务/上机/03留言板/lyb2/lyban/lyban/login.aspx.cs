using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using lyban.App_Code;
using System.Data;
//using System.Data.OleDb;
using System.Data.SqlClient;//SQL server数据提供程序

namespace lyban
{
    public partial class lyan : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void loadButton(object sender, EventArgs e)
        {
            if (TextBox1.Text == "" || TextBox2.Text == "")
            {
                Label1.Text = "*请输入用户名或密码！";
                //Response.Redirect("login.aspx");
            }
            else {
                DBHelper dh = new DBHelper();
                string username = TextBox1.Text.Trim();
                string password = TextBox2.Text.Trim();
                string sql = "select password from gly where username='" + username + "';";
                SqlDataReader reader = dh.queryDb(sql);
                if (reader.HasRows)
                {
                    reader.Read();
                    string readPassword = reader[0].ToString().Trim();
                    if (readPassword == password)
                    {
                        //登录成功就存放用户名并且重定向到Manager.aspx文件
                        Session["username"] = username;                        
                        Response.Redirect("Manager.aspx");
                    }
                    else
                    {
                        Label1.Text = "*用户名或密码错误！";
                    }
                }
                else {
                    Label1.Text = "*用户名或密码错误！";
                }
                
            }

        }

        protected void clearText(object sender, EventArgs e)
        {
            TextBox1.Text = "";
            TextBox2.Text = "";
        }
    }
}