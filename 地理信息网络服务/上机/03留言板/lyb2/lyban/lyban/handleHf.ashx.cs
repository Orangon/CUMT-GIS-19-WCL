using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using lyban.App_Code;

namespace lyban
{
    /// <summary>
    /// handleHf 的摘要说明
    /// </summary>
    public class handleHf : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            if (context.Request["lyid"] != null && context.Request["hfContents"] != null) {
                reply hf = new reply();
                hf.username = "admin";
                hf.contents = context.Request["hfContents"];
                hf.hftime = DateTime.Now;
                hf.lyid = Convert.ToInt32(context.Request["lyid"]);

                DBHelper dh = new DBHelper();
                string sql = "insert into hf (username,hftime,contents,lyid) values ('"+ 
                    hf.username + "','" + hf.hftime.ToString() + "','" + hf.contents + "','" + hf.lyid + "' )";
                int res = dh.ExeCurd(sql);
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