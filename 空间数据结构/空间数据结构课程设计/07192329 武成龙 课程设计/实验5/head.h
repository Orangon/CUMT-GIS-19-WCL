#pragma once
#ifndef head_H
#define head_H
#include <iostream>
using namespace std;
template <class T>
struct linknode	  //�ڵ���
{
	T data;		//����
	linknode* link;	 //����ָ��
	//dataȱʡ�Ĺ��캯��
	linknode(linknode<T>* p = NULL)
	{
		link = p;
	}
	//��ʼ��data�Ĺ��캯��
	linknode(const T& temp, linknode<T>* p = NULL)
	{
		data = temp; link = p;
	}
};

template <class T>
class list
{
protected:
	linknode<T>* first;	   //ͷָ��
public:
	list(){first = new linknode<T>;}//Ĭ�Ϲ��캯��
	list(const T& x){first = new linknode<T>(x);}//���캯��
	list(list<T>& x);//���ƹ��캯��
	~list() { makempty(); }//��������

	void makempty();//�ѱ��Ϊ�ձ�
	int getlength();//���ر���
	linknode<T>* gethead(){return first;}//���ظ���ͷ�ڵ��ַ
	linknode<T>* search(T x);//���غ�x�Ľڵ�ĵ�ַ
	linknode<T>* locate(int i);//���ص�i��Ԫ�صĵ�ַ
	bool getdata(int i, T& x)const;//�ѵ�i��Ԫ�ص�ֵ��x
	bool setdata(int i, T x);//�ѵ�i��Ԫ�ص�ֵ��Ϊx
	bool insert(int i, T x);//��x���뵽��i��Ԫ�غ���
	bool remove(int i, T& x);//ɾ����i��Ԫ�ص�ֵ
	bool isempty()const	//�ж��Ƿ��
	{
		first->link == NULL ? true : false;
	}
	bool isfull()const		 //�Ƿ���
	{
		return false;
	}
	void inputfr(T end);//ǰ�巨
	void inputbc(T end);//��巨
	void output();//���
	list<T>& operator=(list<T>& l);//���صȺ�
};
//�ѱ��Ϊ�ձ���
template <class T>
void list<T>::makempty()
{
	linknode<T>* temp;	 //��ǰ���
	//�������յ�ʱ��ɾ�����˱�ͷ�������нڵ�
	while (first->link != NULL)
	{
		temp = first->link;
		first->link = temp->link;
		delete temp;
	}
}
//ǰ�巨����
template <class T>
void list<T>::inputfr(T end)
{
	makempty();
	T temp;
	linknode<T>* newnode;
	do {
		cout << "����������(����-1����)" << endl;
		cin >> temp;
		if (temp == end)
			break;
		newnode = new linknode<T>(temp);
		if (newnode == NULL)
		{
			cerr << "�ڴ�������" << endl; exit(1);
		}
		newnode->link = first->link;
		first->link = newnode;
	} while (true);
}
//��巨����
template <class T>
void list<T>::inputbc(T end)
{
	makempty();
	linknode<T>* newnode;	 //������ڵ�
	linknode<T>* last = first;  //β�ڵ�
	T temp;
	do
	{
		cout << "����������(����-1����)" << endl;
		cin >> temp;
		if (temp == end)
			break;
		newnode = new linknode<T>(temp);
		if (newnode == NULL)
		{
			cerr << "�ڴ�������" << endl; exit(1);
		}
		last->link = newnode;
		last = newnode;
	} while (true);
	last->link = NULL;
}
//�������
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
//���ƹ��캯��
template<class T>
list<T>::list(list<T>& x)
{
	first = new linknode<T>;
	if (first == NULL)
	{
		cerr << "�ڴ�������" << endl; exit(1);
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
			cerr << "�ڴ�������" << endl; exit(1);
		}
		des = des->link;
		src = src->link;
	}
}
//	���ر��Ⱥ���
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
//���غ�x�Ľڵ�ĵ�ַ����
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
//���ص�i��Ԫ��
template<class T>
linknode<T>* list<T>::locate(int i)
{
	if (i <= 0)
	{
		cout << "����" << endl;
		return NULL;
	}
	linknode<T>* temp = first->link;
	for (int a = 1; a < i; a++)
	{
		if (temp == NULL)
		{
			cout << "���Ȳ���" << endl;
			return NULL;
		}
		temp = temp->link;
	}
	return temp;
}
//�ѵ�i��Ԫ�ص�ֵ��x����
template<class T>
bool list<T>::getdata(int i, T& x)	const
{
	if (first->link == NULL)
	{
		cout << "�ձ�" << endl; return false;
	}
	linknode<T>* temp = first->link;
	for (int a = 1; a < i; a++)
	{
		if (temp == NULL)
		{
			cout << "������" << endl;
			return false;
		}
		temp = temp->link;
	}
	x = temp->data;
	return true;
}
//�ѵ�i��Ԫ�ص�ֵ��Ϊx�ĺ���
template <class T>
bool list<T>::setdata(int i, T x)
{
	if (first->link == NULL)
	{
		cout << "�ձ�" << endl; return false;
	}
	linknode<T>* temp = first->link;
	for (int a = 1; a < i; a++)
	{
		if (temp == NULL)
		{
			cout << "������" << endl;
			return false;
		}
		temp = temp->link;
	}
	temp->data = x;
	return true;
}
//��x���뵽��i��Ԫ��֮��
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
			cout << "���Ȳ���,�޸�ʧ��" << endl;
			return false;
		}
	}
	newnode->link = temp->link;
	temp->link = newnode;
	return true;
}
//�ѵ�i��Ԫ��ɾ������
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
			cout << "���Ȳ���,�޸�ʧ��" << endl;
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
			cerr << "�ڴ�������" << endl; exit(1);
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
	linkedstack() { top = NULL; }	//���캯��
	~linkedstack() { makempty(); }	//��������
	void push(const T& x);		//��ջ
	bool pop(T& x);				//��ջ
	bool gettop(T& x) const;    //��ȡջ��Ԫ��
	bool isempty() const { return top == NULL ? true : false; }		//�Ƿ��
	bool isfull() const { return false; }//�Ƿ���
	int getsize() const;		//Ԫ�ظ���
	void makempty();			//�ÿ�
	friend ostream& operator<<(ostream& os, linkedstack<T>& s)
	{
		os << "ջ��Ԫ�ظ���Ϊ��" << s.getsize() << endl;
		linknode<T>* temp = s.top;
		for (int i = 0; i < s.getsize(); i++)
		{
			cout << "��" << i + 1 << "��Ԫ��Ϊ��" << temp->data << endl;
			temp = temp->link;
		}
		return os;
	}
private:
	linknode<T>* top;
};
//��ջ����
template<class T>
void linkedstack<T>::push(const T& x)
{
	linknode<T>* temp = new linknode<T>(x);

	temp->link = top;
	top = temp;
}
//��ջ����
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
//��ȡջ��Ԫ��
template<class T>
bool linkedstack<T>::gettop(T& x) const
{
	if (isempty())
		return false;
	x = top->data;
	return true;
}
//�ÿպ���
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
 //����Ԫ�ظ�������
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

bool check(char h)	 //�������ı��ʽ�Ƿ�Ϸ�
{
	if ((h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z') || (h >= '0' && h <= '9') || h == '.')//�ǲ�����
		return true;
	else if (h == '#' || h == '(' || h == '*' || h == '/' || h == '%' || h == '+' || h == '-' || h == ')')	//�ǲ�����
		return true;
	else		//�Ƿ��ַ�
	{
		cout << "���ʽ���в��Ϸ����ַ�������������" << endl;
		return false;
	}
}
void input(char* temp)
{
	while (true)		 //����ԭʼ���ʽ
	{
		cout << "������Ҫת���ı��ʽ" << endl;
		cin.getline(temp, 100);	 //��������
		int checkflag = 0;		 //�ж��Ƿ��зǷ��ַ�
		int length = strlen(temp);  //����ı��ʽ�ĳ���
		for (int i = 0; i < length; i++)	 //�������Ƿ��зǷ��ַ�
		{
			if (!check(temp[i]))	 //���ַǷ��ַ�
			{
				checkflag = 1;		 //�ж���Ϊ��
				break;				 //ֻҪ����һ���Ƿ��ַ����������ʽ���Ƿ����޼����ж�
			}

		}

		if (checkflag == 0)			//���޷Ƿ��ַ�
		{
			temp[length] = '#';		//�����ӱ��ʽ������־#
			temp[length + 1] = '\0';	//�ַ�����β
			cout << endl << "ԭ���ʽΪ��#��ʾ��β����" << temp << endl << endl;
			break;
		}
	}
}
bool isnum(char h)	 //�жϵ�ǰ�ַ��ǲ��������ǲ�����
{
	if ((h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z') || (h >= '0' && h <= '9') || h == '.')
		return true;
	else
		return false;
}
int isp(char h)		//���ص�ǰ������ջ�����ȼ�
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
int icp(char h)	  //���ص�ǰ������ջ�����ȼ�
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
	opst.push('#');	//��#��ѹ��ջ
	char topch;//����ȡջ��Ԫ��
	char outch;//����ȡ��ջԪ��
	int i1 = 0, i2 = 0;
	char ch = temp[i1++]; //����ch��ԭ��׺���ʽ�ж�ȡ�ַ�

	while (opst.isempty() == false)	 //�������
	{
		if (isnum(ch)) //������
		{
			out[i2++] = ch;//�������׺���ʽ
			ch = temp[i1++];
		}
		else		 //������
		{
			opst.gettop(topch);  //ȡջ����������topch

			if (isp(topch) < icp(ch)) //�²��������ȼ���
			{
				opst.push(ch);//�²�������ջ
				ch = temp[i1++];  //ȡ��һ������
			}
			else if (isp(topch) > icp(ch)) //�²��������ȼ���
			{
				opst.pop(outch);//��ջ
				out[i2++] = outch;//�����ջԪ��
			}
			else //ջ��Ԫ�غ͵�ǰ���������ȼ���ȣ������Ż򾮺�
			{
				opst.pop(outch);
				if (outch == '(')
					ch = temp[i1++];
			}
		}
		if (ch == '#')			//��β�����������һ�����������,��������ѭ��
		{
			opst.pop(outch);//��ջ
			out[i2++] = outch;//�����ջԪ��
			break;
		}
	}
	out[i2] = '\0';		//����ַ�����ӽ�β
}
#endif head_H