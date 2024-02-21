using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace lyban.App_Code
{
    public class reply
    {
        public int id { get; set; }
        public int lyid { get; set; }
        public string username { get; set; }
        public DateTime hftime { get; set; }
        public string contents { get; set; }
    }
}