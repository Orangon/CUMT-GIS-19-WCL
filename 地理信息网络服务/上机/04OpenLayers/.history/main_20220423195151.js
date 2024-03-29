<script>
var vector = new ol.layer.Vector({
    source: new ol.source.Vector({
        format: new ol.format.GeoJSON(),
        url: 'http://localhost:9080/geoserver/wfs?service=wfs&version=1.1.0&request=GetFeature&typeNames=gslearning:water&outputFormat=application/json&srsname=EPSG:3857'
    }),
    style: function (feature, resolution) {
        return new ol.style.Style({
            stroke: new ol.style.Stroke({
                color: 'blue',
                width: 1
            })
        });
    }
});

var map = new ol.Map({
    layers: [new ol.layer.Tile({
        source: new ol.source.OSM()
    }), vector],
    target: 'map',
    view: new ol.View({
        center: ol.proj.fromLonLat([117.140, 34.215]),
        maxZoom: 19,
        zoom: 16,
        projection: 'EPSG:3857'
    })
});
</script>
