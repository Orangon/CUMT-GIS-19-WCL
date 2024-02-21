using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using lyban.App_Code;

namespace lyban
{
    /// <summary>
    /// handleMsg 的摘要说明
    /// </summary>
    public class handleMsg : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            if (context.Request["username"] != null && context.Request["comments"] != null)
            {
                // 假如用户名和留言不为空，就创建一个 message 对象。
                message ly = new message();
                ly.username = context.Request["username"];
                ly.comments = context.Request["comments"];
                ly.ipaddr = context.Request.UserHostAddress=="::1"?"127.0.0.1":context.Request.UserHostAddress;
                ly.lytime = DateTime.Now; 
                DBHelper dh = new DBHelper();
                // 定义SQL语句
                string sql = "insert into ly (username,ipaddr,comments,lytime) values ( '" +
                    ly.username + "','" + ly.ipaddr + "','" + ly.comments + "','" + ly.lytime.ToString() + " ')";
                // 执行SQL语句
                int res =dh.ExeCurd(sql);
                if (res > 0)
                {
                    context.Response.Write("success");
                }
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