using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
//using System.Data.OleDb;
using System.Configuration;
using System.Data.SqlClient;//SQL server数据提供程序

namespace lyban.App_Code
{
    public class DBHelper
    {
        private static readonly string connStr = ConfigurationManager.ConnectionStrings["sqlConnect"].ConnectionString;
        private SqlConnection conn;//负责打开或连接数据库文件
        private SqlCommand cmd;//对数据库下达行动查询指令，以及执行SQL Server的存储过程
        // 构造函数
        public DBHelper() { }

        public SqlConnection getConn()
        {
            conn = new SqlConnection(connStr);
            return conn;
        }

        // 把留言存放到数据库中，删除留言或回复
        public int ExeCurd(string sql)
        {
            try
            {
                SqlConnection oleConn =getConn();
                cmd = new SqlCommand();
                cmd.Connection = oleConn;
                cmd.CommandText = sql;
                cmd.Connection.Open();

                int res = cmd.ExecuteNonQuery();
                return res;
            }
            catch (Exception e)
            {
                return 0;
            }
            finally {
                cmd.Connection.Close();
                cmd.Dispose();
            }
        }
        // 读取数据表
        public SqlDataReader queryDb(string sql)
        {
            //OleDbCommand cmd = null;
            try
            {
                // 创建连接对象
                SqlConnection oleConn = getConn();
                // 创建执行对象
                cmd = new SqlCommand();
                cmd.Connection = oleConn;
                cmd.CommandText = sql;
                cmd.Connection.Open();
                if (conn.State == ConnectionState.Open)
                {
                    //如果数据库连接打开则为真
                    Boolean state = true;
                }
                return cmd.ExecuteReader();
            }
            catch (Exception e)
            {
                return null;
            }
            finally
            {
                //cmd.Connection.Close();
                //cmd.Dispose();
            }
        }

        public DataTable queyDb(string sql)
        {
            //OleDbCommand cmd = null;
            try
            {
                SqlConnection oleConn = getConn();
                cmd = new SqlCommand();
                cmd.Connection = oleConn;
                cmd.CommandText = sql;
                cmd.Connection.Open();
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                DataTable dt=new DataTable();
                adapter.Fill(dt);
                return dt;
            }
            catch (Exception e)
            {
                return null;
            }
            finally
            {
                //cmd.Connection.Close();
                //cmd.Dispose();
            }
        }

        public void closeDb() {
            cmd.Connection.Close();
            cmd.Dispose();
        }
    }
}