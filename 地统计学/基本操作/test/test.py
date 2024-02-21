from osgeo import gdal
from osgeo import ogr, osr
import shapefile
import pyproj
import pysal
import geopandas
import pointpats

def readShapefile(sf):
    # file_path：文件路径
    # file_name：文件名
    file_path = 'E:\\学习资料\\大三下\\地统计学\\南海诸岛\\'
    file_name = 'nanhaizhudao.shp'
    sf = shapefile.Reader(str(file_path) + str(file_name))
    fields = sf.fields
    numR = sf.numRecords
    numS = sf.numShapes


def getRef(file_name):
    # 获取已有矢量数据的空间坐标参考
    driver = ogr.GetDriverByName('ESRI Shapefile')
    dataset = driver.Open(file_name)
    # 获取元素个数
    layer = dataset.GetLayer()
    numLen = len(layer)
    # 获取文件的空间坐标参考
    spatialRef = layer.GetSpatialRef()
    # print(spatialRef)
    wkt = spatialRef.ExportToWkt()
    return wkt


def saveRef():
    # 设置路径
    data_path = 'E:\学习资料\大三下\地统计学\基本操作\\'
    data_name = 'GCS_WGS_1984.shp'
    # 创建新坐标系，转换为 Wkt 格式
    proj = osr.SpatialReference()
    proj.ImportFromEPSG(4326)  # 4326-GCS_WGS_1984; 4490- GCS_China_Geodetic_Coordinate_System_2000
    wkt = proj.ExportToWkt()
    # 写入 prj 文件
    data_location = str(data_path) + str(data_name)
    new_sf = open(str(data_location).replace(".shp", ".prj"), 'w')
    new_sf.write(wkt)
    new_sf.close()

def newShapefile():
    file = shapefile.Writer('E:\学习资料\大三下\地统计学\基本操作\\test.shp')
    file.autoBalance = 1
    # 创建两种属性
    file.field('FIRST_FLD', 'C', '40')
    file.field('SECOND_FLD', 'C', '40')
    # 创建四个点
    file.point(1, 5)
    file.record('First', 'Point')

    file.point(5, 5)
    file.record('Second', 'Point')

    file.point(5, 1)
    file.record('Third', 'Point')

    file.point(1, 1)
    file.record('Fourth', 'Point')

    file.point(3, 3)
    file.record('Fifth', 'Point')

    file.close()


def defineProj(src_name,tgt_path,tgt_name):
    # src_name：源矢量文件名
    # tgt_path：目标矢量文件路径
    # tgt_name：目标矢量文件名

    # 返回源文件投影，转换为 Wkt 格式
    driver = ogr.GetDriverByName('ESRI Shapefile')
    dataset = driver.Open(src_name)
    layer = dataset.GetLayer()
    # numLen = len(layer)
    spatialRef = layer.GetSpatialRef()
    # print(spatialRef)
    wkt = spatialRef.ExportToWkt()

    # 新建一个文件，写入 Wkt ，保存
    data_location = str(tgt_path) + str(tgt_name)
    new_sf = open(str(data_location).replace(".shp",".prj"), 'w')
    new_sf.write(wkt)
    new_sf.close()

    # 查看相应的 shapefile 文件
    # driver = ogr.GetDriverByName('ESRI Shapefile')
    # dataset = driver.Open(str(data_location).replace(".prj",".shp"))
    # # 获取元素个数
    # layer = dataset.GetLayer()
    # print("元素数量为：",len(layer))
    # # 获取文件的空间坐标参考
    # spatialRef = layer.GetSpatialRef()
    # print("新的空间坐标参考为：\n",spatialRef)


if __name__ == '__main__':

    # 南海诸岛 Shapefile 文件操作
    # readShapefile(sf)

    # 读取 shapefile 文件的坐标信息，即投影信息
    # getRef('E:\学习资料\大三下\地统计学\南海诸岛\\nanhaizhudao.shp')

    # 保存shapefile文件的坐标
    # saveRef()


    # 创建新的shapefile文件
    newShapefile()

    # 把一个现有的shapefile文件的坐标系写入到这个新创建shapefile文件中
    # src_name = 'E:\\学习资料\\大三下\\地统计学\\中国行政区划图\\China.shp'
    # tgt_path = 'E:\\学习资料\\大三下\\地统计学\\基本操作\\'
    # tgt_name = 'test.shp'
    # defineProj(src_name,tgt_path,tgt_name)
    pass