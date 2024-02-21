using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace lyban.App_Code
{
    public class message
    {
        public int id { get; set; }
        public string username { get; set; }
        public string ipaddr { get; set; }
        public string comments { get; set; }
        public DateTime lytime { get; set; }
    }
}