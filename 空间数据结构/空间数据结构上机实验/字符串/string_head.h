#pragma once
#include <string> 
#include <iostream>
using namespace std;
#ifndef string_head_H
#define a_string_head_H
#define default_size 128

class a_string {
private:
	char* ch;//����ַ���������
	int length;//ʵ�ʳ���
	int max_size;//��󳤶�
public:
	a_string(int sz = default_size);//ʹ��Ĭ�ϲ����Ĺ��캯��
	a_string(const char* init);//���캯��
	a_string(const a_string& ob);//���ƹ��캯��
	~a_string() { delete[]ch; }//��������
	int get_length()const { return length; };//����ʵ�ʳ���
	bool operator==(a_string& ob)const { return strcmp(ch, ob.ch) == 0; }//&��const������ʡ�ԣ�����������Ԫ����
	friend bool operator!=(a_string& ob1,a_string& ob2) { return strcmp(ob1.ch, ob2.ch) != 0; }//����Ԫд
	bool operator!()const { return length == 0; }//�ж��Ƿ�Ϊ�գ���Ϊ1���ǿ�Ϊ0
	a_string& operator=(a_string& ob);//����ֵ��������&�������thisָ���޷��Ƚ�
	a_string& operator+=(const a_string& ob);//������
	char& operator[](int i);//ȡ�±�Ϊi���ַ�
	int find(a_string& pat)const;//ƥ��,���ص�һ��ƥ�䵽���±�
	void output() { cout << ch; }
};
#endif string_head_H


