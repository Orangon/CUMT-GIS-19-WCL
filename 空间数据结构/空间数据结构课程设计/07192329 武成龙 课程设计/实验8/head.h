#pragma once
#ifndef head_h
#define head_h
#include<iostream>
#include <fstream> 
using namespace std;
template <class t>
struct bintree_node
{
	t data;//��ֵ��
	bintree_node<t>* left_child, * right_child;//����
	bintree_node()  //����Ĭ�ϲ����Ĺ��캯��
	{
		left_child = NULL;
		right_child = NULL;
	}
	bintree_node(t x, bintree_node<t>* l = NULL, bintree_node<t>* r = NULL)
	{//��Ĭ�ϲ����Ĺ��캯��
		data = x;
		left_child = l;
		right_child = r;
	}
};
template<class t>
class bintree
{
public:
	bintree() { root = NULL; }//����Ĭ�ϲ����Ĺ��캯��
	bintree(t value) { ref_value = value;root = NULL;  }//��Ĭ�ϲ����Ĺ��캯��
	~bintree() { destroy(root); };//��������
	bintree_node<t>* get_root(){ return root; }//ȡ��
	int Hight() { return height(root); }//���ظ߶�
	void bintree_count(bintree_node<t>* subtree,int& m1,int& m2);//m1���ܽ����,m2��Ҷ�ӽ����
	void print_bintree( bintree_node<t>* tree);//ǰ��������������
	void set_ref(t ref) { ref_value = ref; }//����������
private:
	t ref_value;//����ֹͣ��־
	bintree_node<t>* root;//���ڵ�
	static void create(istream& in, bintree_node<t>*& subtree, t ref); //��̬��Ա���������ļ����뽨�����ݹ鷽ʽ
	friend istream& operator>>(istream& in, bintree<t>& tree) {//>>����
		create(in, tree.root,tree.ref_value);
		return in;
	}
	void destroy(bintree_node<t>*& subtree);//ɾ��
	int height(bintree_node<t>* subtree);  //�������߶�
};
template<class t>
void bintree<t>::destroy(bintree_node<t>*& subtree)
{//����������ݹ�ɾ��
	if (subtree != NULL)
	{
		destroy(subtree->left_child);
		destroy(subtree->right_child);
		delete subtree;
	}
}
template<class t>
int bintree<t>::height(bintree_node<t>* subtree)
{//����������ݹ����
	if (subtree == NULL)
		return 0;
	else
	{
		int i = height(subtree->left_child);
		int j = height(subtree->right_child);
		return (i > j) ? i + 1 : j + 1;
	}
}
template<class t>
void bintree<t>::create(istream& in, bintree_node<t>*& subtree,t ref)
{//ǰ������������ļ�����
	t item;
	if (!in)
	{
		cout << "�ļ����ܴ򿪣�" << endl;
	}
	else
	{
		in >> item;
		if (item != ref)
		{
			subtree = new bintree_node<t>(item);
			if (subtree == NULL)
			{
				cout << "�ڴ�������" << endl; exit(1);
			}
			create(in,subtree->left_child,ref);
			create(in,subtree->right_child,ref);
		}
		else
			subtree = NULL;
	}
}
template<class t>
void bintree<t>::print_bintree(bintree_node<t>* tree)
{//ǰ����������
	if (tree != NULL)
	{
		cout << tree->data;
		if (tree->left_child != NULL || tree->right_child != NULL)
		{
			cout << "(";
			print_bintree(tree->left_child);
			cout << ",";
			print_bintree(tree->right_child);
			cout << ")";
		}
	}
}
template<class t>
void bintree<t>::bintree_count(bintree_node<t>* subtree,int& m1, int& m2)
{//ǰ�������ͳ�����н���Ҷ�ӽ��
	if (subtree != NULL)
	{
		m1++;//ͳ�����н��
		if (subtree->left_child == NULL && subtree->right_child == NULL)
			m2++;//ͳ��Ҷ�ӽ��
		bintree_count(subtree->left_child, m1, m2);
		bintree_count(subtree->right_child, m1, m2);
	}
}
#endif head_h