## 上机1

# bootstrap

## 头部

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <title>Bootstrap 5 实例</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
  </head>
</html>
```



## 容器

```html
.container 类提供了响应式的固定宽度容器
.container-fluid 类提供了全宽容器，跨越视口的整个宽度
```



## 字体

Bootstrap 5 把 HTML 标题（<h1> 到 <h6>）的样式设置为有更粗的 font-weight 以及响应式的 font-size。

display 标题用于比普通标题更突出（更大的 font-size 和更细的 font-weight），有六个类可供选择：.display-1 到 .display-6：

在 Bootstrap 5 中，HTML <small> 元素（和 .small 类）用于在任何标题中创建较小的辅助文本：

## 可切换的导航

```html
<div class="container mt-3">
  <h2>可切换的 / 动态胶囊导航</h2>
  <br>
  <!-- Nav pills -->
  <ul class="nav nav-pills" role="tablist">
    <li class="nav-item">
      <a class="nav-link active" data-bs-toggle="pill" href="#home">春日</a>
    </li>
    <li class="nav-item">
      <a class="nav-link" data-bs-toggle="pill" href="#menu1">初夏</a>
    </li>
    <li class="nav-item">
      <a class="nav-link" data-bs-toggle="pill" href="#menu2">山行</a>
    </li>
  </ul>

  <!-- Tab panes -->
  <div class="tab-content">
    <div id="home" class="container tab-pane active"><br>
      <h3>春日</h3>
      <p>胜日寻芳泗水滨，无边光景一时新。</p>
      <p>等闲识得东风面，万紫千红总是春。</p>
    </div>
    <div id="menu1" class="container tab-pane fade"><br>
      <h3>初夏绝句</h3>
      <p>纷纷红紫已成尘，布谷声中夏令新。</p>
      <p>夹路桑麻行不尽，始知身是太平人。</p>
    </div>
    <div id="menu2" class="container tab-pane fade"><br>
      <h3>山行</h3>
      <p>远上寒山石径斜，白云生处有人家。</p>
      <p>停车坐爱枫林晚，霜叶红于二月花。</p>
    </div>
  </div>
</div>
```
