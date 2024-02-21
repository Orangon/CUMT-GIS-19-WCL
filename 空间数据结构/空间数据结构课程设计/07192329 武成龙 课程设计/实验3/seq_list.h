#pragma once
#ifndef seq_list_h
#define seq_list_h
#include<iostream>
#include<stdlib.h>
using namespace std;
const int default_size = 100;

template<class t>
class seq_list {
protected:
	t* data;//存放数组
	int max_size;//最大可容纳项数
	int last;//当前数组最后位置，即实际最大项数-1
	void resize(int new_size);//改变数组空间大小
public:
	void RESIZE(int n) { resize(n); }//调用改变数组空间大小私有函数
	seq_list(int sz = default_size);//构造函数
	seq_list(seq_list<t>& ls);//复制构造函数
	~seq_list() { delete[]data; }//析构函数
	int size()const { return max_size; };//返回最大元素个数
	int length()const { return last+1; };//返回表实际长度
	int search(t& x)const;//搜索变量x在表中的位置，返回下标
	int locate(int i)const;//定位第i个，返回下标
	void input();//输入
	void output();//输出
	bool get_data(int i, t& x)const;//取第i个表项的值，不改变原值
	void set_data(int i, t& x);//用x修改第i个表项的值，因此没有const
	bool insert(int i, t& x);//插入x，在第i个表项后
	bool remove(int i, t& x);//删除第i个表项，返回表项的值
	bool is_empty() { return(last == -1) ? true: false;}//判断表空
	bool is_full() { return(last == max_size - 1) ? true : false; }//判断表满
	seq_list<t>operator=(seq_list<t>& l);
	//用运算符重载实现整体赋值，和复制构造函数作用相同，不过更方便
};
//扩充顺序表
template<class t>
void seq_list<t>::resize(int new_size) 
{
	if (new_size <= 0)
	{
		cout << "大小不合理！";
		return;
	}
	if (new_size != max_size)
	{
		t* newarray = new t[new_size];
		if (newarray == NULL)
		{
			cout << "内存分配错误！";
			return;
		}
		int n = last + 1;
		t* srcarray = data;
		t* destarray = newarray;
		while (n--) *destarray++ = *srcarray++;
		delete[]data;
		data = newarray;
		max_size = new_size;
	}
}
//构造函数定义
template<class t>
seq_list<t>::seq_list(int sz) 
{
	if (sz > 0) 
	{
		max_size = sz;
		last = -1;
		data = new t[max_size];
			if(data==NULL)
			{
				cout<< "存储分配错误！" << endl; exit(1);
			}
			cout << "创建成功！" << endl;
	}
}
//复制构造函数定义
template<class t>
seq_list<t>::seq_list(seq_list<t>& ls) 
{
	max_size = ls.size();
	last = ls.length()-1;
	t value;//存放原数组的元素
	data = new t[max_size];
	if (data == NULL)
	{
		cout << "存储分配错误！" << endl;
	}
	for (int i = 1; i <= last + 1; i++) 
	{
		ls.get_data(i, value);//获得
		data[i - 1] = value;//转移
	}
	cout << "创建成功！" << endl;
}
//搜索
template<class t>
int seq_list<t>::search(t& x)const 
{
	for (int i = 0; i <= last; i++)
	{
		if (data[i] == x)
		{
			cout << "搜索成功！" ;
			return i + 1;
		}
	}
	cout << "搜索失败！" ;
	return 0;
}
//定位
template<class t>
int seq_list<t>::locate(int i)const {
	if (i >= 1 && i <= last + 1)
	{
		cout << "定位成功！" ;
		return i;
	}
	else
	{
		cout << "定位失败！" ;
		return 0;
	}
}
//依次输入
template<class t>
void seq_list<t>::input() 
{
	cout << "请输入最后一个元素的下标：";
	while (true)
	{
		cin >> last;
		if (last <= max_size - 1)
			break;
		cout << "输入有误！范围不能超过" << max_size-1;
	}
	for (int i = 0; i <=last; i++)
	{
		cout << "第" << i + 1 << "个元素为：";
		cin >> data[i];
	}
	cout << "输入成功！" << endl;
}
//依次输出
template<class t>
void seq_list<t>::output() 
{
	cout << "最大可容纳项数：" << max_size << endl;
	for (int i = 0; i <= last; i++)
	{
		cout << "第" << i + 1<<"个元素为："<< data[i]<<endl;
	}
	cout << "输出成功！" << endl;
}
//取值
template<class t>
bool seq_list<t>::get_data(int i, t& x) const
{
	if (i >= 1 && i <= last + 1)//大于1说明存在，小于last+1说明在范围内
	{
		x = data[i - 1];
		return true;
	}
	else
		return false;
}
//修改
template<class t>
void seq_list<t>::set_data(int i, t& x)
{
	if (i >= 1 && i <= last + 1)
		data[i - 1] = x;
	cout << "修改成功！" << endl;
}
//插入
template<class t>
bool seq_list<t>::insert(int i, t& x)
{//i=0时插入到第一个元素位置。i=last+1时插入到最后一个元素位置。
	if (last == max_size - 1)
		return false;
	if (i<0 || i>last + 1)
		return false;
	for (int j = last; j >= i; j--)//从最后一个开始依次往后移位
		data[j + 1] = data[j];
	data[i] = x;
	last++;
	cout << "插入成功！" << endl;
	return true;
}
//删除
template<class t>
bool seq_list<t>::remove(int i, t& x) {
	if (last == -1)
		return false;
	if (i<1 || i>last+1)
		return false;
	x = data[i - 1];
	for (int j = i; j <= last; j++)//从第i个开始依次往前移位
		data[j - 1] = data[j];
	last--;
	cout << "删除成功！" << endl;
	return true;
}
//整体赋值
template<class t>
seq_list<t> seq_list<t>::operator=(seq_list<t>& nwl)
{
	max_size = nwl.size();
	last = nwl.length() - 1;
	t* new_array = new t[max_size];//分配新数组
	t* src = new_array;
	for (int i = 0; i < last + 1; i++)
	{
		nwl.get_data(i + 1, src[i]);
	}
	delete[] data;
	data = src;
	return *this;
}
#endif seq_list_h