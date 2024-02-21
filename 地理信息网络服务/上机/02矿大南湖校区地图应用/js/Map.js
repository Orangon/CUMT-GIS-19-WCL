var map;//声明为全局变量
var center;
//创建地图
function initMap() {
    //定位在矿大南湖校区
    center = new TMap.LatLng(34.215,117.145);
    //初始化地图
    map = new TMap.Map("container", {
        rotation: 0,//设置地图旋转角度
        //pitch:30, //设置俯仰角度（0~45）
        zoom:15.5,//设置地图缩放级别
        center: center//设置地图中心点坐标
    });
    // 显示搜索区域
    // var circle = new TMap.MultiCircle({
    //     map,
    //     styles: { // 设置圆形样式
    //         'circle': new TMap.CircleStyle({
    //             'color': 'rgba(41,91,255,0.16)',
    //             'showBorder': true,
    //             'borderColor': 'rgba(41,91,255,1)',
    //             'borderWidth': 2,
    //         }),
    //     },
    //     geometries: [{
    //         styleId: 'circle',
    //         center: center,
    //         radius: 700,
    //     }],
    // });

}
//关键词搜索
var search = new TMap.service.Search({ pageSize: 10 }); // 新建一个地点搜索类
var markers = new TMap.MultiMarker({
    map: map,
    geometries: [],
});
var infoWindowList = Array(10);
function searchByKeyword() {
    // 新建一个地点搜索类

    infoWindowList.forEach((infoWindow) => {
        infoWindow.close();
    });
    infoWindowList.length = 0;
    // 清除已有结果
    markers.setGeometries([]);
    // 在地图显示范围内以给定的关键字搜索地点
    search
        .searchNearby(
            {
                keyword:document.getElementById('keyword').value,
                center:center,
                radius:700,
                autoExtend:false,
            }
        )
        // .searchRectangle({
        //     keyword: document.getElementById('keyword').value,
        //     bounds: map.getBounds(),
        // })
        .then((result) => {
            result.data.forEach((item, index) => {
                var geometries = markers.getGeometries();
                // 新增信息窗体显示地标的名称与地址、电话等信息
                var infoWindow = new TMap.InfoWindow({
                    map: map,
                    position: item.location,
                    content: `<h3>${item.title}</h3><p>地址：${item.address}</p><p>电话：${item.tel}</p>`,
                    offset: { x: 0, y: -50 },
                });
                infoWindow.close();
                infoWindowList[index] = infoWindow;
                geometries.push({
                    id: String(index), // 点标注数据数组
                    position: item.location,
                });
                markers.updateGeometries(geometries); // 绘制地点标注
                markers.on('click', (e) => {
                    infoWindowList[Number(e.geometry.id)].open();
                }); // 点击标注显示信息窗体
            });
        });
}

