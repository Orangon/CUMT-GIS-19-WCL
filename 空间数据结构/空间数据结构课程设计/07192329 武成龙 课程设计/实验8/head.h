#pragma once
#ifndef head_h
#define head_h
#include<iostream>
#include <fstream> 
using namespace std;
template <class t>
struct bintree_node
{
	t data;//数值域
	bintree_node<t>* left_child, * right_child;//链域
	bintree_node()  //不带默认参数的构造函数
	{
		left_child = NULL;
		right_child = NULL;
	}
	bintree_node(t x, bintree_node<t>* l = NULL, bintree_node<t>* r = NULL)
	{//带默认参数的构造函数
		data = x;
		left_child = l;
		right_child = r;
	}
};
template<class t>
class bintree
{
public:
	bintree() { root = NULL; }//不带默认参数的构造函数
	bintree(t value) { ref_value = value;root = NULL;  }//带默认参数的构造函数
	~bintree() { destroy(root); };//析构函数
	bintree_node<t>* get_root(){ return root; }//取根
	int Hight() { return height(root); }//返回高度
	void bintree_count(bintree_node<t>* subtree,int& m1,int& m2);//m1是总结点数,m2是叶子结点数
	void print_bintree( bintree_node<t>* tree);//前序遍历输出二叉树
	void set_ref(t ref) { ref_value = ref; }//结束符设置
private:
	t ref_value;//数据停止标志
	bintree_node<t>* root;//根节点
	static void create(istream& in, bintree_node<t>*& subtree, t ref); //静态成员函数，从文件读入建树，递归方式
	friend istream& operator>>(istream& in, bintree<t>& tree) {//>>重载
		create(in, tree.root,tree.ref_value);
		return in;
	}
	void destroy(bintree_node<t>*& subtree);//删除
	int height(bintree_node<t>* subtree);  //返回树高度
};
template<class t>
void bintree<t>::destroy(bintree_node<t>*& subtree)
{//后序遍历，递归删除
	if (subtree != NULL)
	{
		destroy(subtree->left_child);
		destroy(subtree->right_child);
		delete subtree;
	}
}
template<class t>
int bintree<t>::height(bintree_node<t>* subtree)
{//后序遍历，递归访问
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
{//前序遍历，读入文件建树
	t item;
	if (!in)
	{
		cout << "文件不能打开！" << endl;
	}
	else
	{
		in >> item;
		if (item != ref)
		{
			subtree = new bintree_node<t>(item);
			if (subtree == NULL)
			{
				cout << "内存分配错误！" << endl; exit(1);
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
{//前序遍历，输出
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
{//前序遍历，统计所有结点和叶子结点
	if (subtree != NULL)
	{
		m1++;//统计所有结点
		if (subtree->left_child == NULL && subtree->right_child == NULL)
			m2++;//统计叶子结点
		bintree_count(subtree->left_child, m1, m2);
		bintree_count(subtree->right_child, m1, m2);
	}
}
#endif head_h