$(document).ready(function () {
    init();

    $("#btnMsg").click(function () {
        if ($("#ucontents2").val() == "" || $("#uname2").val() == "") {
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
    });

    //$("#delreply").click(function () {
    //    alert("hello");
    //    var hfDialog = $("#lhf");
    //    hfDialog.css("display", "block");
    //    $(this).parent().parent().parent().insertAfter(hfDialog);
    //});

    $("#hfBtn").click(function () {
        if ($("#hfContents").val() == "") {
            //若内容为空，则提醒
            alert("请填入内容！");
            return;
        }
        var lyid = $("#hf").parent().find(".left").find(".h").html();
        var t = new Date();
        sendHf({
            lyid: lyid,
            hfContents: $("#hfContents").val(),
            hftime: t.toLocaleDateString() + " " + t.toTimeString().split(" ")[0]
        });
    });
})

function sendMsg(msg) {
    $.ajax({
        type:"POST",
        url: "handleMsg.ashx",
        data: msg,
        success: function (res,status,xhr) {
            if (res = "success") {
                alert("留言成功！");
                //显示留言
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

function sendHf(msg) {
    $.ajax({
        type: "POST",
        url: "handleHf.ashx",
        data: msg, 
        success: function (res, status, xhr) {
            if (res = "success") {
                alert("回复成功！");
                //显示回复
                $("#hf").parent().find(".ucontents").append("<div class='reply-container'><p style='font-size:12px;opacity:0.8;'>"
                    + msg.hfContents + "</p>" + "<label style='font-size:12px;opacity:0.5;'>" + msg.hftime + "</label></div>");
                //回复存值
                $("#hf").parent().find(".reply-container").data("lyid", msg.lyid);
                //清空回复
                $("#hf").find("#hfContents").val("");
                //隐藏回复区
                $("#hf").css("display", "none");
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
            //判断返回的状态信息
            if (res != "error") {
                var lyList = eval("(" + res + ")");
                
                for (var i = 0; i < lyList.length; i++) {
                    var comments;
                    if (i == 0) {
                        comments = $(".comments").eq(0);
                    } else {
                        comments = $(".comments").eq(0).clone();
                    }
                    comments.find(".uname").find("label").html(lyList[i].username+"<p class=\"h\" hidden>"+lyList[i].id+"</p>");
                    comments.find(".ucontents").html(lyList[i].comments);
                    comments.find("#lytime").text(lyList[i].lytime.replace("T"," "));
                    $(".contents").prepend(comments);
                }
            }
        }
    })
}

//显示回复窗口
function replyHandle() {
    var hfDialog = $("#hf");
    hfDialog.css("display", "block");
    //添加回复
    $(event.srcElement).parent().parent().parent().append($("#hf"));
}
//删除回复
function delReplyHandle(e) {
    if (confirm("确定要删除所有回复吗? ") == true) {
        //找到对应的元素
        var lyid = $(e).parent().parent().parent().find(".reply-container").data("lyid");
        deleteHf({ lyid }, e);
    }
}
//删除回复
function deleteHf(lyid, e) {
    $.ajax({
        type: "POST",
        url: "deleteHf.ashx",
        data: lyid,
        success: function (res, status, xhr) {
            if (res = "success") {
                $(e).parent().parent().parent().find(".reply-container").text("");
                alert("删除成功! ");
            }
        }
    })
}

//删除留言
function delLyHandle(e) {
    if (confirm("确定要删除留言吗?") == true) {
        //找到对应的元素
        const id = $(e).parent().parent().parent().find(".left").find(".h").html();
        deleteMsg({ ID:id }, e)
    }
}
//删除留言
function deleteMsg(msgId, e) {
    $.ajax({
        type: "POST",
        url: "deleteMsg.ashx",
        data: msgId,
        success: function (res, status, xhr) {
            if (res = "success") {
                $(e).parent().parent().parent().remove();
                alert("删除成功! ");
            }
        }
    })
}