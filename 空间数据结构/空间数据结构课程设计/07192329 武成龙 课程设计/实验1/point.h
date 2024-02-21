#pragma once
#ifndef point_h
#define point_h
#include <iostream>
#include <math.h>
using namespace std;
const double pi = 3.1415926;
class TPoint
{
protected:
	//定义三维坐标
	double x;
	double y;
	double z;
public:
	TPoint() { x = 0; y = 0; z = 0; }//缺省参数的构造函数
	TPoint(double px, double py, double pz) { x = px; y = py; z = pz; }//有默认参数的构造函数
	void move(double px, double py, double pz) { x = px; y = py; z = pz; }//修改坐标
	void show() { cout << "点的X坐标：" << x << "\t" << "Y坐标：" << y << "\t" << "Z坐标：" << z << "\n"; }//显示坐标
	void get_p(double &px, double &py, double &pz) { px = x; py = y; pz = z; }
 };
class TBall:public TPoint
{
private:
	double radius;
public:
	TBall() { radius = 0; x = 0; y = 0; }//缺省构造函数
	TBall(double px, double py, double pz,double r) {x = px;y = py; z = pz;radius = r;}//带参数的构造函数
	void show();//输出球心，半径,表面积，体积
	void move(double px, double py, double pz) { x = px; y = py; z = pz; }//修改球心坐标
	void set_r(double nr) { radius = nr; }//修改半径
	friend void p_b(TPoint p, TBall b);//判断点与球的关系（在球内，在球面上，在球外）
};
void TBall::show() 
{
	cout << "球心的X坐标：" << x << "\t" << "Y坐标：" << y << "\t" << "Z坐标：" << z << "\t" << "半径：" << radius << "\t"; 
	cout << "球表面积为：" << 4 * pi * pow(radius, 2) << "\t" << "球体积为：" << 4 * pi * pow(radius, 3) / 3 << "\n";
}
//友元函数
void p_b(TPoint p, TBall b)
{
	double px = 0, py = 0, pz = 0;
	p.get_p(px, py, pz);//获得点坐标
	double flag = 0;
	flag = sqrt(pow(b.x-px,2)+ pow(b.y - py, 2)+ pow(b.z - pz, 2)) - b.radius;
	if (flag > 0)
	{
		cout << "点在球外";
	}
	else  if(flag == 0)
	{
		cout << "点在球面上";
	}
	else if (flag < 0)
	{
		cout << "点在球内";
	}
}
#endif point_h

