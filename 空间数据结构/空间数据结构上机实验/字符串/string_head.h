#pragma once
#include <string> 
#include <iostream>
using namespace std;
#ifndef string_head_H
#define a_string_head_H
#define default_size 128

class a_string {
private:
	char* ch;//存放字符串的数组
	int length;//实际长度
	int max_size;//最大长度
public:
	a_string(int sz = default_size);//使用默认参数的构造函数
	a_string(const char* init);//构造函数
	a_string(const a_string& ob);//复制构造函数
	~a_string() { delete[]ch; }//析构函数
	int get_length()const { return length; };//返回实际长度
	bool operator==(a_string& ob)const { return strcmp(ch, ob.ch) == 0; }//&和const都可以省略，还可以用友元重载
	friend bool operator!=(a_string& ob1,a_string& ob2) { return strcmp(ob1.ch, ob2.ch) != 0; }//用友元写
	bool operator!()const { return length == 0; }//判断是否为空，空为1，非空为0
	a_string& operator=(a_string& ob);//串赋值，必须有&，否则和this指针无法比较
	a_string& operator+=(const a_string& ob);//串连接
	char& operator[](int i);//取下标为i的字符
	int find(a_string& pat)const;//匹配,返回第一个匹配到的下标
	void output() { cout << ch; }
};
#endif string_head_H


