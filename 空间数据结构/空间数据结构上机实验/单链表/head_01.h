#pragma once

#ifndef head_01_h
#define head_01_h
#include<stdio.h>
#include <iostream>
using namespace std;
template<class t>
struct link_node
{
	t data;//数值域
	link_node<t>* link;//指针域
	link_node(link_node<t>* ptr = NULL) { link = ptr; }//只初始化指针成员的构造函数
	link_node(const t& item, link_node<t>* ptr = NULL) { data = item; link = ptr; }//初始化数据和指针成员的构造函数
};

template<class t>
class list
{
public:
	list() { first = new link_node<t>; cout << "创建成功！\n"; }//没有传递参数时给头指针请求内存，即让头指针指向一个新的结点。调用构造函数1
	list(const t& x) { first = new link_node<t>(x); cout << "创建成功！\n"; }//传递一个变量，请求内存，调用构造函数2
	~list() {make_empty();}
	void make_empty();//删除
	int length()const;//返回长度
	link_node<t>* search(t x);//搜索含有数据x的结点，返回元素的地址
	link_node<t>* locate(int i);//定位，返回第i个元素的地址
	bool get_data(int i, t& x);//先定位，再取出第i个元素值
	void set_data(int i, t& x);//用x修改第i个元素值
	bool insert(int i, t& x);//在第i个元素后插入
	bool remove(int i, t& x);//删除第i个元素，x返回该元素的值
	bool is_empty()const { return first->link == NULL; }//first->link==null?true:false
	void input_f(t end);//前插法
	void input_r(t end);//前插法
	void output();//输出
protected:
	link_node<t>* first;//头指针
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
	/*课本写法
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
	if (i < 0)return NULL;//i太小
	link_node<t>* current = first;
	int k = 0;
	while (current!= NULL && k < i) {
		current = current->link;
		k++;
	}
	return current;//若返回假，i太大
}
template<class t>
bool list<t>::get_data(int i, t& x){
	if (i <= 0)return false;//i太小
	link_node<t>* current = locate(i);
	if (current == NULL)return false;//i太大
	else{
		x = current->data;
		return true;
	}
}
template<class t>
void list<t>::set_data(int i, t& x){
	if (i <= 0)return;//i太小
	link_node<t>* current = locate(i);
	if (current == NULL)return;//i太大
	else {
		current->data = x;
		cout << "修改成功！" << endl;
	}
}
template<class t>
bool list<t>::insert(int i, t& x){

	link_node<t>* current = locate(i);
	if (current == NULL) return false;
	link_node<t>* new_node = new link_node<t>(x);
	if (new_node == NULL) {
		cout << "插入失败！" << endl;
	}
	new_node->link = current->link;
	current->link = new_node;
	cout << "插入成功！" << endl;
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
	cout << "请输入数据（输入-1结束）" << endl;
	cin >> val;
	while(val != end){
		new_node = new link_node<t>(val);
		if (new_node == NULL)
		{
			cout << "内存分配错误！" << endl;
			exit(1);
		}
		new_node->link = first->link;
		first->link = new_node;
		cout << "请输入数据（输入-1结束）" << endl;
		cin >> val;
	}
}
template<class t>
void list<t>::input_r(t end) {
	link_node<t>* new_node = NULL, * last;
	t val;
	make_empty();
	cout << "请输入数据（输入-1结束）" << endl;
	cin >> val;
	last = first;
	while(val != end){
		new_node = new link_node<t>(val);
		if (new_node == NULL)
		{
			cout << "内存分配错误！" << endl;
			exit(1);
			last->link = new_node;
			last = new_node;
			cout << "请输入数据（输入-1结束）" << endl;
			cin >> val;
		}
		last->link = NULL;
	}
}
template<class t>
void list<t>::output() {
	link_node<t>* current = first->link;
	while (current!=NULL)//如果是current=first，然后条件是current->link呢？
	{
		cout << current->data << "  ";
		current = current->link;
	}
}
#endif head_01_h