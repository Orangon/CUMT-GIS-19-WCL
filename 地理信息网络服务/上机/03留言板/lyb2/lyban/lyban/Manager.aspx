<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Manager.aspx.cs" Inherits="lyban.Manager" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <link href="css/lyan.css" rel="stylesheet" />
    <script src="js/jquery.js"></script>
    <script src="js/manager.js"></script>
    <title>留言管理界面</title>
</head>
<body>
     <header class="header jz">
        <h1>麻 雀 虽 小 留 言 板</h1>
        <div class="login jz"><%=(string)Session["username"] %></div>
    </header>
    <div class="container">
        <div class="contents">
            <article class="comments">
                <%--<div id="delly" class="del"><img src="pic/del.png" style="width:20px;height:20px;opacity:0.2;" /></div>--%>
                <div class="left">
                    <div class="hpic jz">
                        <img src="pic/bilibili.png" style="height: 100px; width: 100px; border-radius: 50%;" />
                    </div>
                    <div class="uname jz" style="color: #1f99c2; margin-top: 10px;">
                        <label style="width: 100px;"></label>
                    </div>
                </div>
                <div class="right">
                    <div class="ucontents">                                              
                    </div>                    
                </div>
                <div class="reply">
                    <div style="margin-right: 15px; font-size: 12px;">
                        <label class="rp" onclick="replyHandle()">回复留言</label>
                        <label class="rp" onclick="delReplyHandle(this)">删除回复</label>
                        <label class="rp" onclick="delLyHandle(this)">删除留言</label>
                        <label id="lytime"></label>
                    </div>
                </div>
                <div class="clear"></div>
            </article>
            <article class="ly" id="message">
                <div style="margin: 15px 20px 15px 15px;">
                    <div style="margin-bottom: 10px;float: left;">发表留言：</div>
                    <div style="margin-right: 10px;float: left;">
                        <textarea id="ucontents2" style="width: 450px; height: 50px; font-size: 14px;"></textarea>
                    </div>
                    <div style="margin-bottom: 5px;float: left;">用户名：</div>
                    <div style="margin-bottom: 10px;">
                        <input id="uname2" type="text">
                        （必填）
                    </div>
                    <div>
                        <input id="btnMsg" type="button" style="width: 100px; height: 26px;" value="发表">
                    </div>
                </div>
            </article>
            <article id="hf" class="ly">
                <div style="margin: 15px 20px 15px 15px;">
                    <div style="margin-bottom: 10px;">回复留言：</div>
                    <div style="margin-bottom: 10px;">
                        <textarea id="hfContents" style="width: 100%; height: 150px; font-size: 14px;"></textarea>
                    </div>
                    <div style="margin-bottom: 5px;">用户名：</div>
                    <div style="margin-bottom: 10px;">
                        <input id="Text1" type="text" value="admin" />
                        （必填）
                    </div>
                    <div>
                        <input id="hfBtn" type="button" style="width: 100px; height: 26px;" value="回复" />
                    </div>
                </div>
            </article>
        </div>
    </div>

    <footer class="footer jz">
        copyright@武成龙
    </footer>
    <%--<form id="form1" runat="server">
    <div>
    这是管理员页面<asp:Button ID="Button1" runat="server" Text="Button" />
    </div>
    </form>--%>
</body>
</html>
