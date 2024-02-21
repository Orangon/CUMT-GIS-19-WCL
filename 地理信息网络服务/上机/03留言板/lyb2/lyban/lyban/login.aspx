<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="login.aspx.cs" Inherits="lyban.lyan" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <link href="css/lyan.css" rel="stylesheet" />
    <script src="js/jquery.js"></script>
    <script src="js/index.js"></script>
    <title>登陆</title>
</head>
<body>
    <header class="header jz">
        <h1>麻 雀 虽 小 留 言 板</h1>
        <div class="login jz"><a href="index.html">返回主页</a></div>
    </header>
    <div class="container">
        <div class="contents">
            <div style="width: 100%; height: 480px; margin: 0px auto; padding-top: 100px;" class="jz">
                <div style="width: 360px; height: 280px; border: 1px solid #1f99c2; margin: 0px auto;" class="jz">
                    <form id="form1" runat="server">
                        <div style="width: 100%; height: 50px; background-color: #ffa500; color: #fff; font-size: 18px; line-height: 50px;" class="jz">登 陆</div>
                        <div style="width: 100%; height: 50px; font-size: 18px; line-height: 50px; margin-top: 20px;" class="jz">
                            用户名：<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                        </div>
                        <div style="width: 100%; height: 50px; font-size: 18px; line-height: 50px;" class="jz">
                            密&nbsp;&nbsp;&nbsp;码：<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                        </div>
                        <div style="width: 100%; height: 50px; font-size: 18px; line-height: 50px;" class="jz">
                            <asp:Button ID="Button1" runat="server" Text="登陆" Font-Names="微软雅黑" Height="25px" OnClick="loadButton" Width="78px" />&nbsp;&nbsp;&nbsp;
                            <asp:Button ID="Button2" runat="server" Text="取消" Font-Names="微软雅黑" Height="25px" OnClick="clearText" Width="78px" />
                        </div>
                        <div style="width: 100%; height: 50px; font-size: 18px; line-height: 50px;" class="jz">
                            <asp:Label ID="Label1" runat="server" ForeColor="Red"></asp:Label>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
    <%--<form id="form1" runat="server">
    </form>--%>
    <footer class="footer jz">
        copyright@留言板
    </footer>
</body>
</html>
