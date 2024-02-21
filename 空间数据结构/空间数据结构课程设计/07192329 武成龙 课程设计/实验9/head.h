#pragma once
#ifndef head_H
#define head_H
#define default_size 128
#include <iostream>
#include <string>
using namespace std;

class Astring 
{//字符类定义
private:
	char* ch;//存放字符串的数组
	int length;//实际长度
	int max_size;//最大长度
public:
	Astring(int sz = default_size);//使用默认参数的构造函数
	Astring(const char* init);//构造函数
	~Astring() { delete[]ch; }//析构函数

	int get_length()const { return length; };//返回实际长度
	void operator()(Astring& temp,int pos, int len);//求子串
	bool operator==(Astring& ob)const { return strcmp(ch, ob.ch) == 0; }//判断字符串是否相等，相等返回1，不等返回0
	friend bool operator!=(Astring& ob1, Astring& ob2) { return strcmp(ob1.ch, ob2.ch) != 0; }//判断字符串是否不等，相等返回0，不等返回1
	bool operator!()const { return length == 0; }//判断是否为空，空为1，非空为0
	Astring& operator=(Astring& ob);//字符串赋值重载，必须有&，否则和this指针无法比较
	Astring& operator+=(const Astring& ob);//字符串连接重载
	int find(Astring& pat)const;//模式匹配,返回第一个匹配到的下标
	friend ostream& operator <<(ostream& os, Astring& temp);//<<重载，使之可以显示Astring对象的属性
	int count(char a);//统计出现次数
	void num();//统计小写字母，大写字母，空格出现次数
};

Astring::Astring(int sz) {
	max_size = sz;
	ch = new char[max_size + 1];
	if (ch == NULL) {
		cout << "存储分配错误！";
	}
	length = 0;
	ch[0] = '\0';//初始化
	cout << "创建成功！" << endl;
}
Astring::Astring(const char* init) {
	int len = strlen(init);
	max_size = (len > default_size) ? len : default_size;
	ch = new char[max_size + 1];
	if (ch == NULL) {
		cout << "存储分配错误！";
	}
	length = len;
	strcpy_s(ch, len + 1, init);//拷贝
	cout << "创建成功！" << endl;
}
void Astring::operator()(Astring& temp, int pos, int len)
{//求子串，pos是开始取值的下标，len是子串长度
	if (len < 0 || pos < 0 || len + pos - 1 > max_size)
	{
		temp.length = 0;
		temp.ch[0] = '\0';
	}
	else
	{
		if (len + pos - 1 >= length)
		{
			len = length - pos;
		}
		temp.length = len;
		for (int i = 0, j = pos; i < len; i++, j++)
		{
			temp.ch[i] = ch[j];
		}
		temp.ch[len] = '\0';
	}
}
Astring& Astring::operator=(/*const */Astring& ob) {
	if (&ob != this) {
		delete[]ch;
		ch = new char[ob.max_size + 1];
		if (ch == NULL)
			cout << "内存分配错误！" << endl;
		length = ob.length;
		strcpy_s(ch, length + 1, ob.ch);//拷贝
	}
	else
		cout << "字符串自身赋值出错！" << endl;
	return *this;
}
Astring& Astring::operator+=(const Astring& ob)
{
	char* temp = ch;
	int n = length + ob.length;
	int m = (max_size > n) ? max_size : n;
	ch = new char[m + 1];
	if (ch == NULL)
		cout << "存储分配错!";
	max_size = m; length = n;
	strcpy_s(ch, max_size + 1, temp);//拷贝
	strcat_s(ch, max_size + 1, ob.ch);//连接
	delete[]temp;
	return *this;
}
int Astring::find(Astring& pat)const {//普通的模式匹配
	int i, j;
	if (length < pat.length) {
		cout << "\n长度超限，匹配失败！";
		return -1;
	}
	for (i = 0; i < length - pat.length; i++) {
		for (j = 0; j < pat.length; j++) {
			if (ch[i + j] != pat.ch[j])//+j
				break;
		}
		if (j == pat.length)
			return i;
	}
	return -1;
}
ostream& operator <<(ostream& os, Astring& temp)
{//重载<<，使之可以显示Astring对象的属性
	os << temp.ch << endl;
	os << "当前字符串最大容量为：" << temp.max_size << endl;
	os << "已有字符 " << temp.length << " 个" << endl;
	return  os;
}
int Astring::count(char a) {
	int num=0;
	for (int i = 0; i < length; i++)
	{
		if (ch[i] == a)
			num++;
	}
	return num;
	
}
void Astring::num()
{
	int c = 0;//每个字符出现次数
	int num = 0;
	cout << "共有" << length << "个字符" << endl;
	for (char a = 'a'; a <= 'z'; a++)
	{//统计小写字母
		c = count(a);
		num += c;
		if (c != 0)
		{
			cout << "出现字母 " << a << "共 " << c << " 次" << endl;
		}
	}
	for (char a = 'A'; a <= 'Z'; a++)
	{//统计大写字母
		c = count(a);
		num += c;
		if (c != 0)
		{
			cout << "出现字母 " << a << "共 " << c << " 次" << endl;
		}
	}
	//统计空格
	c = count(' ');
	num += c;
	cout << "出现空格共 " << c << "次" << endl;
	//统计其他字符
	cout << "出现其他字符共 " << length - num << "次" << endl;
}
#endif head_H

