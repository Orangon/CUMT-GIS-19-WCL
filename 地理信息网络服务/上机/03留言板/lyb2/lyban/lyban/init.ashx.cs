using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using lyban.App_Code;
using System.Data;
//using System.Data.OleDb;
using System.Data.SqlClient;//SQL server数据提供程序
using Newtonsoft.Json;

namespace lyban
{
    /// <summary>
    /// init 的摘要说明
    /// </summary>
    public class init : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            DBHelper dh = new DBHelper();
            // 选择留言表的所有数据
            string sql = "select * from ly";
            SqlDataReader reader = dh.queryDb(sql);
            List<message> lylist = new List<message>();
            // 判断表是否为空
            if (reader.HasRows)
            {
                while (reader.Read())
                {
                    message tmp = new message();
                    tmp.id = (int)reader[0];
                    tmp.username = (string)reader[1];
                    tmp.ipaddr = (string)reader[2];
                    tmp.comments = (string)reader[3];
                    tmp.lytime = Convert.ToDateTime(reader[4]);
                    lylist.Add(tmp);
                }
                // 关闭数据库连接，释放资源
                dh.closeDb();
                // 把留言转换成JSON格式
                string res = JsonConvert.SerializeObject(lylist);
                context.Response.Write(res);
            }
            else 
            {
                context.Response.Write("error");
            }
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}