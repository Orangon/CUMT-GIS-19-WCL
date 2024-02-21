$(document).ready(function () {
    init();

    $("#btnMsg").click(function () {       
        if ($("#ucontents2").val() == "" || $("#uname2").val() == "")
        {
            //若内容为空，则提醒
            alert("请填入内容！");
            return;
        }
        var t = new Date();
        sendMsg({
            username: $("#uname2").val(),
            comments: $("#ucontents2").val(),
            lytime: t.toLocaleDateString() + " " + t.toTimeString().split(" ")[0]
        });
    })
})

function sendMsg(msg) {
    $.ajax({
        type:"POST",
        url: "handleMsg.ashx",
        data: msg,
        success: function (res,status,xhr) {
            if (res = "success") {
                alert("留言成功！");
                //添加留言
                var comments = $(".comments").eq(0).clone();
                comments.find(".uname").find("label").text($("#uname2").val());
                comments.find(".ucontents").html($("#ucontents2").val());
                comments.find("#lytime").text(msg.lytime);
                $(".contents").prepend(comments);
                //清空留言窗口内容
                $("#message").find("#ucontents2").val("");
                $("#message").find("#uname2").val("");
            }           
        }
    })
}

function init() {
    $.ajax({
        type: "GET",
        url: "init.ashx",
        data:"",
        success: function (res, status, xhr) {
            if (res != "error") {
                var lyList = eval("(" + res + ")");
                
                for (var i = 0; i < lyList.length; i++) {
                    var comments;
                    if (i == 0) {
                        comments = $(".comments").eq(0);
                    } else {
                        comments = $(".comments").eq(0).clone();
                    }                    
                    comments.find(".uname").find("label").text(lyList[i].username);
                    comments.find(".ucontents").html(lyList[i].comments);
                    comments.find("#lytime").text(lyList[i].lytime.replace("T"," "));
                    $(".contents").prepend(comments);
                }
            }
        }
    })
}