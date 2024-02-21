#pragma once
#ifndef head_H
#define head_H
#define default_size 128
#include <iostream>
#include <string>
using namespace std;

class Astring 
{//�ַ��ඨ��
private:
	char* ch;//����ַ���������
	int length;//ʵ�ʳ���
	int max_size;//��󳤶�
public:
	Astring(int sz = default_size);//ʹ��Ĭ�ϲ����Ĺ��캯��
	Astring(const char* init);//���캯��
	~Astring() { delete[]ch; }//��������

	int get_length()const { return length; };//����ʵ�ʳ���
	void operator()(Astring& temp,int pos, int len);//���Ӵ�
	bool operator==(Astring& ob)const { return strcmp(ch, ob.ch) == 0; }//�ж��ַ����Ƿ���ȣ���ȷ���1�����ȷ���0
	friend bool operator!=(Astring& ob1, Astring& ob2) { return strcmp(ob1.ch, ob2.ch) != 0; }//�ж��ַ����Ƿ񲻵ȣ���ȷ���0�����ȷ���1
	bool operator!()const { return length == 0; }//�ж��Ƿ�Ϊ�գ���Ϊ1���ǿ�Ϊ0
	Astring& operator=(Astring& ob);//�ַ�����ֵ���أ�������&�������thisָ���޷��Ƚ�
	Astring& operator+=(const Astring& ob);//�ַ�����������
	int find(Astring& pat)const;//ģʽƥ��,���ص�һ��ƥ�䵽���±�
	friend ostream& operator <<(ostream& os, Astring& temp);//<<���أ�ʹ֮������ʾAstring���������
	int count(char a);//ͳ�Ƴ��ִ���
	void num();//ͳ��Сд��ĸ����д��ĸ���ո���ִ���
};

Astring::Astring(int sz) {
	max_size = sz;
	ch = new char[max_size + 1];
	if (ch == NULL) {
		cout << "�洢�������";
	}
	length = 0;
	ch[0] = '\0';//��ʼ��
	cout << "�����ɹ���" << endl;
}
Astring::Astring(const char* init) {
	int len = strlen(init);
	max_size = (len > default_size) ? len : default_size;
	ch = new char[max_size + 1];
	if (ch == NULL) {
		cout << "�洢�������";
	}
	length = len;
	strcpy_s(ch, len + 1, init);//����
	cout << "�����ɹ���" << endl;
}
void Astring::operator()(Astring& temp, int pos, int len)
{//���Ӵ���pos�ǿ�ʼȡֵ���±꣬len���Ӵ�����
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
			cout << "�ڴ�������" << endl;
		length = ob.length;
		strcpy_s(ch, length + 1, ob.ch);//����
	}
	else
		cout << "�ַ�������ֵ����" << endl;
	return *this;
}
Astring& Astring::operator+=(const Astring& ob)
{
	char* temp = ch;
	int n = length + ob.length;
	int m = (max_size > n) ? max_size : n;
	ch = new char[m + 1];
	if (ch == NULL)
		cout << "�洢�����!";
	max_size = m; length = n;
	strcpy_s(ch, max_size + 1, temp);//����
	strcat_s(ch, max_size + 1, ob.ch);//����
	delete[]temp;
	return *this;
}
int Astring::find(Astring& pat)const {//��ͨ��ģʽƥ��
	int i, j;
	if (length < pat.length) {
		cout << "\n���ȳ��ޣ�ƥ��ʧ�ܣ�";
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
{//����<<��ʹ֮������ʾAstring���������
	os << temp.ch << endl;
	os << "��ǰ�ַ����������Ϊ��" << temp.max_size << endl;
	os << "�����ַ� " << temp.length << " ��" << endl;
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
	int c = 0;//ÿ���ַ����ִ���
	int num = 0;
	cout << "����" << length << "���ַ�" << endl;
	for (char a = 'a'; a <= 'z'; a++)
	{//ͳ��Сд��ĸ
		c = count(a);
		num += c;
		if (c != 0)
		{
			cout << "������ĸ " << a << "�� " << c << " ��" << endl;
		}
	}
	for (char a = 'A'; a <= 'Z'; a++)
	{//ͳ�ƴ�д��ĸ
		c = count(a);
		num += c;
		if (c != 0)
		{
			cout << "������ĸ " << a << "�� " << c << " ��" << endl;
		}
	}
	//ͳ�ƿո�
	c = count(' ');
	num += c;
	cout << "���ֿո� " << c << "��" << endl;
	//ͳ�������ַ�
	cout << "���������ַ��� " << length - num << "��" << endl;
}
#endif head_H

