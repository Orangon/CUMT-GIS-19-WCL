#pragma once

#ifndef head_01_h
#define head_01_h
#include<stdio.h>
#include <iostream>
using namespace std;
template<class t>
struct link_node
{
	t data;//��ֵ��
	link_node<t>* link;//ָ����
	link_node(link_node<t>* ptr = NULL) { link = ptr; }//ֻ��ʼ��ָ���Ա�Ĺ��캯��
	link_node(const t& item, link_node<t>* ptr = NULL) { data = item; link = ptr; }//��ʼ�����ݺ�ָ���Ա�Ĺ��캯��
};

template<class t>
class list
{
public:
	list() { first = new link_node<t>; cout << "�����ɹ���\n"; }//û�д��ݲ���ʱ��ͷָ�������ڴ棬����ͷָ��ָ��һ���µĽ�㡣���ù��캯��1
	list(const t& x) { first = new link_node<t>(x); cout << "�����ɹ���\n"; }//����һ�������������ڴ棬���ù��캯��2
	~list() {make_empty();}
	void make_empty();//ɾ��
	int length()const;//���س���
	link_node<t>* search(t x);//������������x�Ľ�㣬����Ԫ�صĵ�ַ
	link_node<t>* locate(int i);//��λ�����ص�i��Ԫ�صĵ�ַ
	bool get_data(int i, t& x);//�ȶ�λ����ȡ����i��Ԫ��ֵ
	void set_data(int i, t& x);//��x�޸ĵ�i��Ԫ��ֵ
	bool insert(int i, t& x);//�ڵ�i��Ԫ�غ����
	bool remove(int i, t& x);//ɾ����i��Ԫ�أ�x���ظ�Ԫ�ص�ֵ
	bool is_empty()const { return first->link == NULL; }//first->link==null?true:false
	void input_f(t end);//ǰ�巨
	void input_r(t end);//ǰ�巨
	void output();//���
protected:
	link_node<t>* first;//ͷָ��
};

template<class t>
void list<t>::make_empty() {
	link_node<t>* q;
	while (first->link != NULL)
	{
		q = first->link;
		first->link = q->link;
		delete q;
	}
}
template<class t>
int list<t>::length()const {
	int length = 0;
	link_node<t>* p = first;
	while (p->link != NULL) {
		++length;
		p = p->link;
	}
	/*�α�д��
	 link_node<t>* p = first->link;
	while (p!= NULL) {
		p = p->link;
		length++;
	}
	*/
	return length;
}
template<class t>
link_node<t>* list<t>::search(t x) {
	link_node<t>* current = first->link;
	while (current!=NULL)
	{
		if (current->data == x) break;
		else
			current = current->link;
	}
	return current;
}
template<class t>
link_node<t>* list<t>::locate(int i) {
	if (i < 0)return NULL;//i̫С
	link_node<t>* current = first;
	int k = 0;
	while (current!= NULL && k < i) {
		current = current->link;
		k++;
	}
	return current;//�����ؼ٣�i̫��
}
template<class t>
bool list<t>::get_data(int i, t& x){
	if (i <= 0)return false;//i̫С
	link_node<t>* current = locate(i);
	if (current == NULL)return false;//i̫��
	else{
		x = current->data;
		return true;
	}
}
template<class t>
void list<t>::set_data(int i, t& x){
	if (i <= 0)return;//i̫С
	link_node<t>* current = locate(i);
	if (current == NULL)return;//i̫��
	else {
		current->data = x;
		cout << "�޸ĳɹ���" << endl;
	}
}
template<class t>
bool list<t>::insert(int i, t& x){

	link_node<t>* current = locate(i);
	if (current == NULL) return false;
	link_node<t>* new_node = new link_node<t>(x);
	if (new_node == NULL) {
		cout << "����ʧ�ܣ�" << endl;
	}
	new_node->link = current->link;
	current->link = new_node;
	cout << "����ɹ���" << endl;
	return true;
}
template<class t>
bool list<t>::remove(int i, t& x) {
	link_node<t>* current = locate(i-1);
	if (current == NULL||current->link==NULL) return false;
	link_node<t>* del = current->link;
	x = del->data;
	current->link = del->link;
	delete del;
	return true;
}

template<class t>
void list<t>::input_f(t end) {
	link_node<t>* new_node=NULL;
	t val;
	make_empty();
	cout << "���������ݣ�����-1������" << endl;
	cin >> val;
	while(val != end){
		new_node = new link_node<t>(val);
		if (new_node == NULL)
		{
			cout << "�ڴ�������" << endl;
			exit(1);
		}
		new_node->link = first->link;
		first->link = new_node;
		cout << "���������ݣ�����-1������" << endl;
		cin >> val;
	}
}
template<class t>
void list<t>::input_r(t end) {
	link_node<t>* new_node = NULL, * last;
	t val;
	make_empty();
	cout << "���������ݣ�����-1������" << endl;
	cin >> val;
	last = first;
	while(val != end){
		new_node = new link_node<t>(val);
		if (new_node == NULL)
		{
			cout << "�ڴ�������" << endl;
			exit(1);
			last->link = new_node;
			last = new_node;
			cout << "���������ݣ�����-1������" << endl;
			cin >> val;
		}
		last->link = NULL;
	}
}
template<class t>
void list<t>::output() {
	link_node<t>* current = first->link;
	while (current!=NULL)//�����current=first��Ȼ��������current->link�أ�
	{
		cout << current->data << "  ";
		current = current->link;
	}
}
#endif head_01_h