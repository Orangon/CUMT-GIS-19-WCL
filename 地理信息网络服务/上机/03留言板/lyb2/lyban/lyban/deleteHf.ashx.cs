using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using lyban.App_Code;

namespace lyban
{
    /// <summary>
    /// deleteHf 的摘要说明
    /// </summary>
    public class deleteHf : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            if (context.Request["lyid"] != null)
            {
                // 假如ID不为空
                string delID = context.Request["lyid"];
                DBHelper dh = new DBHelper();
                // 定义SQL语句
                string sql = "DELETE FROM hf WHERE lyid = " + delID;
                // 执行SQL语句
                int res = dh.ExeCurd(sql);
                if (res > 0)
                {
                    context.Response.Write("success");
                }
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