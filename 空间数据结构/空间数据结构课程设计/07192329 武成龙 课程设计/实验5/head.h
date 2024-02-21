#pragma once
#ifndef head_H
#define head_H
#include <iostream>
using namespace std;
template <class T>
struct linknode	  //节点类
{
	T data;		//数据
	linknode* link;	 //链表指针
	//data缺省的构造函数
	linknode(linknode<T>* p = NULL)
	{
		link = p;
	}
	//初始化data的构造函数
	linknode(const T& temp, linknode<T>* p = NULL)
	{
		data = temp; link = p;
	}
};

template <class T>
class list
{
protected:
	linknode<T>* first;	   //头指针
public:
	list(){first = new linknode<T>;}//默认构造函数
	list(const T& x){first = new linknode<T>(x);}//构造函数
	list(list<T>& x);//复制构造函数
	~list() { makempty(); }//析构函数

	void makempty();//把表变为空表
	int getlength();//返回表长度
	linknode<T>* gethead(){return first;}//返回附加头节点地址
	linknode<T>* search(T x);//返回含x的节点的地址
	linknode<T>* locate(int i);//返回第i个元素的地址
	bool getdata(int i, T& x)const;//把第i个元素的值给x
	bool setdata(int i, T x);//把第i个元素的值改为x
	bool insert(int i, T x);//把x插入到第i个元素后面
	bool remove(int i, T& x);//删除第i个元素的值
	bool isempty()const	//判断是否空
	{
		first->link == NULL ? true : false;
	}
	bool isfull()const		 //是否满
	{
		return false;
	}
	void inputfr(T end);//前插法
	void inputbc(T end);//后插法
	void output();//输出
	list<T>& operator=(list<T>& l);//重载等号
};
//把表变为空表函数
template <class T>
void list<T>::makempty()
{
	linknode<T>* temp;	 //当前结点
	//当链表不空的时候，删除除了表头结点的所有节点
	while (first->link != NULL)
	{
		temp = first->link;
		first->link = temp->link;
		delete temp;
	}
}
//前插法函数
template <class T>
void list<T>::inputfr(T end)
{
	makempty();
	T temp;
	linknode<T>* newnode;
	do {
		cout << "请输入数据(输入-1结束)" << endl;
		cin >> temp;
		if (temp == end)
			break;
		newnode = new linknode<T>(temp);
		if (newnode == NULL)
		{
			cerr << "内存分配错误" << endl; exit(1);
		}
		newnode->link = first->link;
		first->link = newnode;
	} while (true);
}
//后插法函数
template <class T>
void list<T>::inputbc(T end)
{
	makempty();
	linknode<T>* newnode;	 //待插入节点
	linknode<T>* last = first;  //尾节点
	T temp;
	do
	{
		cout << "请输入数据(输入-1结束)" << endl;
		cin >> temp;
		if (temp == end)
			break;
		newnode = new linknode<T>(temp);
		if (newnode == NULL)
		{
			cerr << "内存分配错误" << endl; exit(1);
		}
		last->link = newnode;
		last = newnode;
	} while (true);
	last->link = NULL;
}
//输出函数
template<class T>
void list<T>::output()
{
	linknode<T>* temp = first->link;
	while (temp != NULL)
	{
		cout << temp->data << "   ";
		temp = temp->link;
	}
	cout << endl;
}
//复制构造函数
template<class T>
list<T>::list(list<T>& x)
{
	first = new linknode<T>;
	if (first == NULL)
	{
		cerr << "内存分配错误" << endl; exit(1);
	}
	linknode<T>* src = NULL;
	linknode<T>* des = NULL;
	T temp;
	src = x.gethead()->link;
	des = first;

	while (src != NULL)
	{
		temp = src->data;
		des->link = new linknode<T>(temp);
		if (des->link == NULL)
		{
			cerr << "内存分配错误" << endl; exit(1);
		}
		des = des->link;
		src = src->link;
	}
}
//	返回表长度函数
template<class T>
int list<T>::getlength()
{
	linknode<T>* temp = first->link;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
}
//返回含x的节点的地址函数
template<class T>
linknode<T>* list<T>::search(T x)
{
	linknode<T>* temp = first->link;
	while (temp != NULL)
	{
		if (temp->data == x)
			break;
		temp = temp->link;
	}
	return temp;
}
//返回第i个元素
template<class T>
linknode<T>* list<T>::locate(int i)
{
	if (i <= 0)
	{
		cout << "错误" << endl;
		return NULL;
	}
	linknode<T>* temp = first->link;
	for (int a = 1; a < i; a++)
	{
		if (temp == NULL)
		{
			cout << "表长度不够" << endl;
			return NULL;
		}
		temp = temp->link;
	}
	return temp;
}
//把第i个元素的值给x函数
template<class T>
bool list<T>::getdata(int i, T& x)	const
{
	if (first->link == NULL)
	{
		cout << "空表" << endl; return false;
	}
	linknode<T>* temp = first->link;
	for (int a = 1; a < i; a++)
	{
		if (temp == NULL)
		{
			cout << "表长不够" << endl;
			return false;
		}
		temp = temp->link;
	}
	x = temp->data;
	return true;
}
//把第i个元素的值改为x的函数
template <class T>
bool list<T>::setdata(int i, T x)
{
	if (first->link == NULL)
	{
		cout << "空表" << endl; return false;
	}
	linknode<T>* temp = first->link;
	for (int a = 1; a < i; a++)
	{
		if (temp == NULL)
		{
			cout << "表长不够" << endl;
			return false;
		}
		temp = temp->link;
	}
	temp->data = x;
	return true;
}
//把x插入到第i个元素之后
template<class T>
bool list<T>::insert(int i, T x)
{
	if (i < 0)
		return false;

	linknode<T>* newnode = new linknode<T>(x);
	linknode<T>* temp = first;
	for (int a = 0; a < i; a++)
	{
		temp = temp->link;
		if (temp == NULL)
		{
			cout << "表长度不够,修改失败" << endl;
			return false;
		}
	}
	newnode->link = temp->link;
	temp->link = newnode;
	return true;
}
//把第i个元素删除函数
template<class T>
bool list<T>::remove(int i, T& x)
{
	if (i <= 0)
		return false;

	linknode<T>* del = NULL;
	linknode<T>* temp = first;
	for (int a = 1; a < i; a++)
	{
		temp = temp->link;
		if (temp == NULL)
		{
			cout << "表长度不够,修改失败" << endl;
			return false;
		}
	}
	del = temp->link;
	temp->link = del->link;
	x = del->data;
	delete del;
	return true;
}
template<class T>
list<T>& list<T>::operator=(list<T>& l)
{
	makempty();
	linknode<T>* src = l.gethead()->link;
	linknode<T>* des = first;
	T temp;

	while (src != NULL)
	{
		temp = src->data;
		des->link = new linknode<T>(temp);
		if (des->link == NULL)
		{
			cerr << "内存分配错误" << endl; exit(1);
		}
		des = des->link;
		src = src->link;
	}
	return *this;
}

template <class T>
class linkedstack:  public list<T>
{
public:
	linkedstack() { top = NULL; }	//构造函数
	~linkedstack() { makempty(); }	//析构函数
	void push(const T& x);		//进栈
	bool pop(T& x);				//出栈
	bool gettop(T& x) const;    //读取栈顶元素
	bool isempty() const { return top == NULL ? true : false; }		//是否空
	bool isfull() const { return false; }//是否满
	int getsize() const;		//元素个数
	void makempty();			//置空
	friend ostream& operator<<(ostream& os, linkedstack<T>& s)
	{
		os << "栈中元素个数为：" << s.getsize() << endl;
		linknode<T>* temp = s.top;
		for (int i = 0; i < s.getsize(); i++)
		{
			cout << "第" << i + 1 << "个元素为：" << temp->data << endl;
			temp = temp->link;
		}
		return os;
	}
private:
	linknode<T>* top;
};
//进栈函数
template<class T>
void linkedstack<T>::push(const T& x)
{
	linknode<T>* temp = new linknode<T>(x);

	temp->link = top;
	top = temp;
}
//出栈函数
template<class T>
bool linkedstack<T>::pop(T& x)
{
	if (isempty())
		return false;

	linknode<T>* temp = top;
	top = top->link;
	x = temp->data;
	delete temp;
	return true;
}
//读取栈顶元素
template<class T>
bool linkedstack<T>::gettop(T& x) const
{
	if (isempty())
		return false;
	x = top->data;
	return true;
}
//置空函数
template<class T>
void linkedstack<T>::makempty()
{
	linknode<T>* temp = NULL;
	while (top != NULL)
	{
		temp = top;
		top = temp->link;
		delete temp;
	}
}
 //返回元素个数函数
template<class T>
int linkedstack<T>::getsize()	 const
{
	int size = 0;
	linknode<T>* temp = top;
	while (temp != NULL)
	{
		temp = temp->link;
		size++;
	}
	return size;
}

bool check(char h)	 //检查输入的表达式是否合法
{
	if ((h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z') || (h >= '0' && h <= '9') || h == '.')//是操作数
		return true;
	else if (h == '#' || h == '(' || h == '*' || h == '/' || h == '%' || h == '+' || h == '-' || h == ')')	//是操作符
		return true;
	else		//非法字符
	{
		cout << "表达式中有不合法的字符！请重新输入" << endl;
		return false;
	}
}
void input(char* temp)
{
	while (true)		 //输入原始表达式
	{
		cout << "请输入要转换的表达式" << endl;
		cin.getline(temp, 100);	 //整行输入
		int checkflag = 0;		 //判定是否有非法字符
		int length = strlen(temp);  //输入的表达式的长度
		for (int i = 0; i < length; i++)	 //逐个检查是否有非法字符
		{
			if (!check(temp[i]))	 //出现非法字符
			{
				checkflag = 1;		 //判定变为真
				break;				 //只要发现一个非法字符，整个表达式及非法，无继续判断
			}

		}

		if (checkflag == 0)			//若无非法字符
		{
			temp[length] = '#';		//最后添加表达式结束标志#
			temp[length + 1] = '\0';	//字符串结尾
			cout << endl << "原表达式为（#表示结尾）：" << temp << endl << endl;
			break;
		}
	}
}
bool isnum(char h)	 //判断当前字符是操作数还是操作符
{
	if ((h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z') || (h >= '0' && h <= '9') || h == '.')
		return true;
	else
		return false;
}
int isp(char h)		//返回当前操作符栈内优先级
{
	if (h == '#')
		return 0;
	else if (h == '(')
		return 1;
	else if (h == '*' || h == '/' || h == '%')
		return 5;
	else if (h == '+' || h == '-')
		return 3;
	else
		return 6;
}
int icp(char h)	  //返回当前操作符栈外优先级
{
	if (h == '#')
		return 0;
	else if (h == '(')
		return 6;
	else if (h == '*' || h == '/' || h == '%')
		return 4;
	else if (h == '+' || h == '-')
		return 2;
	else
		return 1;
}
void transfer(char* temp, char* out)
{
	linkedstack<char> opst;
	opst.push('#');	//将#先压入栈
	char topch;//用于取栈顶元素
	char outch;//用于取退栈元素
	int i1 = 0, i2 = 0;
	char ch = temp[i1++]; //利用ch从原中缀表达式中读取字符

	while (opst.isempty() == false)	 //逐个处理
	{
		if (isnum(ch)) //操作数
		{
			out[i2++] = ch;//输出到后缀表达式
			ch = temp[i1++];
		}
		else		 //操作符
		{
			opst.gettop(topch);  //取栈顶操作符给topch

			if (isp(topch) < icp(ch)) //新操作符优先级高
			{
				opst.push(ch);//新操作符入栈
				ch = temp[i1++];  //取下一操作符
			}
			else if (isp(topch) > icp(ch)) //新操作符优先级低
			{
				opst.pop(outch);//退栈
				out[i2++] = outch;//输出退栈元素
			}
			else //栈顶元素和当前操作符优先级相等，即括号或井号
			{
				opst.pop(outch);
				if (outch == '(')
					ch = temp[i1++];
			}
		}
		if (ch == '#')			//收尾工作，把最后一个操作符输出,并且跳出循环
		{
			opst.pop(outch);//退栈
			out[i2++] = outch;//输出退栈元素
			break;
		}
	}
	out[i2] = '\0';		//输出字符串添加结尾
}
#endif head_H