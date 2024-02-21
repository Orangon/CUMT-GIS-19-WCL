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
	//������ά����
	double x;
	double y;
	double z;
public:
	TPoint() { x = 0; y = 0; z = 0; }//ȱʡ�����Ĺ��캯��
	TPoint(double px, double py, double pz) { x = px; y = py; z = pz; }//��Ĭ�ϲ����Ĺ��캯��
	void move(double px, double py, double pz) { x = px; y = py; z = pz; }//�޸�����
	void show() { cout << "���X���꣺" << x << "\t" << "Y���꣺" << y << "\t" << "Z���꣺" << z << "\n"; }//��ʾ����
	void get_p(double &px, double &py, double &pz) { px = x; py = y; pz = z; }
 };
class TBall:public TPoint
{
private:
	double radius;
public:
	TBall() { radius = 0; x = 0; y = 0; }//ȱʡ���캯��
	TBall(double px, double py, double pz,double r) {x = px;y = py; z = pz;radius = r;}//�������Ĺ��캯��
	void show();//������ģ��뾶,����������
	void move(double px, double py, double pz) { x = px; y = py; z = pz; }//�޸���������
	void set_r(double nr) { radius = nr; }//�޸İ뾶
	friend void p_b(TPoint p, TBall b);//�жϵ�����Ĺ�ϵ�������ڣ��������ϣ������⣩
};
void TBall::show() 
{
	cout << "���ĵ�X���꣺" << x << "\t" << "Y���꣺" << y << "\t" << "Z���꣺" << z << "\t" << "�뾶��" << radius << "\t"; 
	cout << "������Ϊ��" << 4 * pi * pow(radius, 2) << "\t" << "�����Ϊ��" << 4 * pi * pow(radius, 3) / 3 << "\n";
}
//��Ԫ����
void p_b(TPoint p, TBall b)
{
	double px = 0, py = 0, pz = 0;
	p.get_p(px, py, pz);//��õ�����
	double flag = 0;
	flag = sqrt(pow(b.x-px,2)+ pow(b.y - py, 2)+ pow(b.z - pz, 2)) - b.radius;
	if (flag > 0)
	{
		cout << "��������";
	}
	else  if(flag == 0)
	{
		cout << "����������";
	}
	else if (flag < 0)
	{
		cout << "��������";
	}
}
#endif point_h

