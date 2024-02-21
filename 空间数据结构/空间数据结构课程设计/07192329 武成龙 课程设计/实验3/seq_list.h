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
	t* data;//�������
	int max_size;//������������
	int last;//��ǰ�������λ�ã���ʵ���������-1
	void resize(int new_size);//�ı�����ռ��С
public:
	void RESIZE(int n) { resize(n); }//���øı�����ռ��С˽�к���
	seq_list(int sz = default_size);//���캯��
	seq_list(seq_list<t>& ls);//���ƹ��캯��
	~seq_list() { delete[]data; }//��������
	int size()const { return max_size; };//�������Ԫ�ظ���
	int length()const { return last+1; };//���ر�ʵ�ʳ���
	int search(t& x)const;//��������x�ڱ��е�λ�ã������±�
	int locate(int i)const;//��λ��i���������±�
	void input();//����
	void output();//���
	bool get_data(int i, t& x)const;//ȡ��i�������ֵ�����ı�ԭֵ
	void set_data(int i, t& x);//��x�޸ĵ�i�������ֵ�����û��const
	bool insert(int i, t& x);//����x���ڵ�i�������
	bool remove(int i, t& x);//ɾ����i��������ر����ֵ
	bool is_empty() { return(last == -1) ? true: false;}//�жϱ��
	bool is_full() { return(last == max_size - 1) ? true : false; }//�жϱ���
	seq_list<t>operator=(seq_list<t>& l);
	//�����������ʵ�����帳ֵ���͸��ƹ��캯��������ͬ������������
};
//����˳���
template<class t>
void seq_list<t>::resize(int new_size) 
{
	if (new_size <= 0)
	{
		cout << "��С������";
		return;
	}
	if (new_size != max_size)
	{
		t* newarray = new t[new_size];
		if (newarray == NULL)
		{
			cout << "�ڴ�������";
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
//���캯������
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
				cout<< "�洢�������" << endl; exit(1);
			}
			cout << "�����ɹ���" << endl;
	}
}
//���ƹ��캯������
template<class t>
seq_list<t>::seq_list(seq_list<t>& ls) 
{
	max_size = ls.size();
	last = ls.length()-1;
	t value;//���ԭ�����Ԫ��
	data = new t[max_size];
	if (data == NULL)
	{
		cout << "�洢�������" << endl;
	}
	for (int i = 1; i <= last + 1; i++) 
	{
		ls.get_data(i, value);//���
		data[i - 1] = value;//ת��
	}
	cout << "�����ɹ���" << endl;
}
//����
template<class t>
int seq_list<t>::search(t& x)const 
{
	for (int i = 0; i <= last; i++)
	{
		if (data[i] == x)
		{
			cout << "�����ɹ���" ;
			return i + 1;
		}
	}
	cout << "����ʧ�ܣ�" ;
	return 0;
}
//��λ
template<class t>
int seq_list<t>::locate(int i)const {
	if (i >= 1 && i <= last + 1)
	{
		cout << "��λ�ɹ���" ;
		return i;
	}
	else
	{
		cout << "��λʧ�ܣ�" ;
		return 0;
	}
}
//��������
template<class t>
void seq_list<t>::input() 
{
	cout << "���������һ��Ԫ�ص��±꣺";
	while (true)
	{
		cin >> last;
		if (last <= max_size - 1)
			break;
		cout << "�������󣡷�Χ���ܳ���" << max_size-1;
	}
	for (int i = 0; i <=last; i++)
	{
		cout << "��" << i + 1 << "��Ԫ��Ϊ��";
		cin >> data[i];
	}
	cout << "����ɹ���" << endl;
}
//�������
template<class t>
void seq_list<t>::output() 
{
	cout << "��������������" << max_size << endl;
	for (int i = 0; i <= last; i++)
	{
		cout << "��" << i + 1<<"��Ԫ��Ϊ��"<< data[i]<<endl;
	}
	cout << "����ɹ���" << endl;
}
//ȡֵ
template<class t>
bool seq_list<t>::get_data(int i, t& x) const
{
	if (i >= 1 && i <= last + 1)//����1˵�����ڣ�С��last+1˵���ڷ�Χ��
	{
		x = data[i - 1];
		return true;
	}
	else
		return false;
}
//�޸�
template<class t>
void seq_list<t>::set_data(int i, t& x)
{
	if (i >= 1 && i <= last + 1)
		data[i - 1] = x;
	cout << "�޸ĳɹ���" << endl;
}
//����
template<class t>
bool seq_list<t>::insert(int i, t& x)
{//i=0ʱ���뵽��һ��Ԫ��λ�á�i=last+1ʱ���뵽���һ��Ԫ��λ�á�
	if (last == max_size - 1)
		return false;
	if (i<0 || i>last + 1)
		return false;
	for (int j = last; j >= i; j--)//�����һ����ʼ����������λ
		data[j + 1] = data[j];
	data[i] = x;
	last++;
	cout << "����ɹ���" << endl;
	return true;
}
//ɾ��
template<class t>
bool seq_list<t>::remove(int i, t& x) {
	if (last == -1)
		return false;
	if (i<1 || i>last+1)
		return false;
	x = data[i - 1];
	for (int j = i; j <= last; j++)//�ӵ�i����ʼ������ǰ��λ
		data[j - 1] = data[j];
	last--;
	cout << "ɾ���ɹ���" << endl;
	return true;
}
//���帳ֵ
template<class t>
seq_list<t> seq_list<t>::operator=(seq_list<t>& nwl)
{
	max_size = nwl.size();
	last = nwl.length() - 1;
	t* new_array = new t[max_size];//����������
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