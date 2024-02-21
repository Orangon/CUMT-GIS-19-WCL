#pragma once
#ifndef head_H
#define head_H

#include<string>
#include<fstream>
#include "seq_list.h"

enum rela 
{ ���� = 0, ����, ����, ͬ�� };

string getz(rela r1)  //��ö����ת��Ϊ�������
{
	switch (r1)
	{
	case 1:return (string)"����";
	case 2:return (string)"����";
	case 3:return (string)"ͬ��";
	}
}

struct person
{
	string number;
	string  name;
	rela r;
	string tel;

	person() //Ĭ�Ϲ��캯��
	{
		number = '\0'; name = "\0"; r = ����; tel = "\0";
	}
	person(string number1, string  name1, rela r1, string tel1)
	{
		number = number1; name = name1; r = r1; tel = tel1;
	}

	void printp()
	{
		cout << endl << "��ǰ��ϵ��Ϊ��" << endl;
		cout << "��ţ� " << number << endl;
		cout << "������ " << name << endl;
		cout << "���飺" << getz(r) << endl;
		cout << "�绰���룺 " << tel << endl;
	}
};

//��ȡ��ʼͨѶ¼
bool read(seq_list<person>& temp)
{
	ifstream openp;			 //���ļ���ȡ��ʼͨѶ¼
	openp.open("ͨѶ¼.txt");
	if (!openp.is_open()) {
		cout << "δ�ɹ����ļ�" << endl;
		return false;
	}
	string n1; string name1; rela r1; string tel1; //���ڴ洢��ȡ����ʱ���� 
	for (int i = 0; i < 6; i++)	//�ļ�û����
	{
		openp >> n1 >> name1 >> (int&)r1 >> tel1;	   //����д�뵽���Ա���
		person tempper(n1, name1, r1, tel1);			   //����д�뵽���Ա���
		bool flag = temp.insert(temp.length(), tempper);

		if (flag == false)			   //���벻�ɹ�
			cout << "�������" << endl;
	}
	openp.close();
	return true;
}

//���ȫ��ͨѶ¼
void print(seq_list<person>& temp)
{
	person tempp;//��ʱ��Ŵ������ϵ��
	for (int i = 0; i < temp.length() ; i++)
	{
		temp.get_data(i + 1, tempp);
		tempp.printp();
	}
}

//�������
void printz(seq_list<person>& temp)
{
	person tempp;//��ʱ��Ŵ������ϵ��
	rela r1;
	do
	{
		cout << "������Ҫ���ҵ����" << endl;
		cout << "1. ���ˣ�  2. ���ѣ�  3. ͬ�£�" << endl;
		cin >> (int&)r1;
		if (r1 != ���� && r1 != ���� && r1 != ͬ��)
		{
			cout << "��������ȷ�ķ��飡" << endl << endl; continue;
		}

		for (int i = 0; i < temp.length() ; i++)	 //��ͷ������Ѱ�ҷ�������������Ԫ��
		{
			temp.get_data(i + 1, tempp);
			if (tempp.r == r1)
				tempp.printp();
		}
		break;//�����ӡ�������˳�
	} while (true);
}
//�����ϵ��
void addper(seq_list<person>& temp)
{
	string n1; string name1; rela r1; string tel1; //����д��������
	cout << "��������Ҫ��ӵ���ϵ����Ϣ" << endl;
	cout << "����������ϵ�˱�ţ�" << endl;
	person tempp;//��ʱ���ÿ�ζ�ȡ������ϵ��
	do
	{
		cin >> n1;
		int flag = 0; //�ж��Ƿ������б���ظ�
		for (int i = 0; i < temp.length() ; i++)
		{
			temp.get_data(i + 1, tempp);
			if (tempp.number == n1)
			{
				cout << "����Ѿ����ڣ�������һ���±��" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)	//flagû����1��ʾû�з����ظ���
			break;

	} while (true);

	cout << "����������ϵ�˵�������" << endl;
	cin >> name1;

	cout << "����������ϵ�˵ķ��飬1. ���ˣ�  2. ���ѣ�  3. ͬ�£�" << endl;
	cin >> (int&)r1;

	cout << "����������ϵ�˵ĵ绰���룺" << endl;
	cin >> tel1;

	person tempper1(n1, name1, r1, tel1);	  //Ҫ�������ϵ��

	bool insert1 = temp.insert(temp.length() , tempper1); //����
	if (insert1)
		cout << "�½���ϵ�˳ɹ���" << endl;
}

//ͨ����Ż����ϵ���ǵڼ���Ԫ��
int numberfind(seq_list<person>& temp, int n)  //n��ʾ�ڲ�ͬ�����е��ã�������ʾ���ֵĸı�
{
	person tempp;//��ʱ��Ŵ������ϵ��
	string fi;//��Ҫ���ҵı��
	cout << "��������Ҫ";

	switch (n)
	{
	case 1:cout << "����"; break;
	case 2:cout << "ɾ��"; break;
	case 3:cout << "�޸�"; break;
	}

	cout << "����ϵ�˱�ţ�" << endl;
	cin >> fi;
	for (int i = 0; i < temp.length() ; i++)	 //��ͷ������Ѱ�ҷ�������������Ԫ��
	{
		temp.get_data(i + 1, tempp);
		if (tempp.number == fi)
			return i;
	}
	return -1;
}

//ͨ�����������ϵ���ǵڼ���Ԫ��
int namefind(seq_list<person>& temp, int n)	  //n��ʾ�ڲ�ͬ�����е��ã�������ʾ���ֵĸı�
{
	person tempp;//��ʱ��Ŵ������ϵ��
	string fstring;//��Ҫ���ҵ�����
	cout << "��������Ҫ";
	switch (n)
	{
	case 1:cout << "����"; break;
	case 2:cout << "ɾ��"; break;
	case 3:cout << "�޸�"; break;
	}
	cout << "����ϵ��������" << endl;
	cin >> fstring;
	for (int i = 0; i < temp.length() ; i++)	 //��ͷ������Ѱ�ҷ�������������Ԫ��
	{
		temp.get_data(i + 1 , tempp);
		if (tempp.name == fstring)
			return i;
	}
	return -1;
}

//������ϵ��
void find(seq_list<person>& temp)
{
	char m; //�����ж����ҷ�ʽ
	int result; //���ҽ��
	person tempper;//���ҵ������ڴ洢�ҵ�����ϵ��
	do
	{
		cout << "��������ͨ�����ַ�ʽ����" << endl;
		cout << "1. ͨ����Ų���   2. ͨ����������" << endl;
		cin >> m;
		if (m == '1')
			result = numberfind(temp, 1); //ѡ���˱�Ų���
		else if (m == '2')
			result = namefind(temp, 1);  //ѡ������������
		else 						  //ѡ�������������ѡ��
		{
			cout << "��������ȷ�ķ�ʽ��" << endl;
			continue;
		}
		if (result == -1)
		{
			cout << "û���ҵ�����ϵ��" << endl;
			break;							//û�ҵ�����������
		}
		else
		{
			cout << "�ҵ��˸���ϵ��" << endl;
			temp.get_data(result, tempper);
			tempper.printp();
			break;						   //�ҵ��ˣ���������
		}
	} while (true);
}

//ɾ����ϵ��
void deleteper(seq_list<person>& temp)
{
	//�Ȳ����Ƿ���Ҫɾ������ϵ��
	int result;//���ڱ�ʾ���ҵ�Ҫɾ������ϵ�����
	char m;//���ڱ�ʾ�����ַ�ʽ�޸�
	do
	{
		cout << "��������ͨ�����ַ�ʽɾ��" << endl;
		cout << "1. ͨ�����ɾ��   2. ͨ������ɾ��" << endl;
		cin >> m;
		if (m == '1')
			result = numberfind(temp, 2); //ѡ���˱��ɾ��
		else if (m == '2')
			result = namefind(temp, 2);  //ѡ��������ɾ��
		else 						  //ѡ�������������ѡ��
		{
			cout << "��������ȷ�ķ�ʽ��" << endl;
			continue;
		}
		if (result == -1)
		{
			cout << "�޸���ϵ��" << endl;
			break;							//��ɾ������ϵ�˲�����
		}
		else
		{
			person tempper;
			temp.remove(result, tempper);
			cout << "ɾ���ɹ���" << endl;
			break;						   //�ҵ��ˣ�ɾ��
		}
	} while (true);
}

//�޸���ϵ��
void reset(seq_list<person>& temp)
{
	//�Ȳ����Ƿ���Ҫ�޸ĵ���ϵ��
	int result;//���ڱ�ʾ���ҵ�Ҫ�޸ĵ���ϵ�����
	char m;//���ڱ�ʾ�����ַ�ʽ�޸�
	do
	{
		cout << "��������ͨ�����ַ�ʽ�޸�" << endl;
		cout << "1. ͨ������޸�   2. ͨ�������޸�" << endl;
		cin >> m;
		if (m == '1')
			result = numberfind(temp, 3); //ѡ���˱���޸�
		else if (m == '2')
			result = namefind(temp, 3);  //ѡ���������޸�
		else 						  //ѡ�������������ѡ��
		{
			cout << "��������ȷ�ķ�ʽ��" << endl;
			continue;
		}
		if (result == -1)
		{
			cout << "�޸���ϵ��" << endl;
			break;							//���޸ĵ���ϵ�˲�����
		}
		else
		{
			person tempper1;  //��������ݣ������������
			temp.get_data(result, tempper1);
			person tempper2;  //����ϵ��
			tempper2.number = tempper1.number;//��Ų���
			tempper2.name = tempper1.name;//��������

			rela r1;   //�·���
			string tel1; //�º���
			cout << "�������·���,��1. ���ˣ�  2. ���ѣ�  3. ͬ�£�" << endl;
			cin >> (int&)r1;
			cout << "�������º���" << endl;
			cin >> tel1;
			tempper2.r = r1;
			tempper2.tel = tel1;

			temp.set_data(result, tempper2);

			cout << "�޸ĳɹ���" << endl;
			break;						   //�ҵ��ˣ��޸�
		}
	} while (true);

}

//��ʼ����
void start(seq_list<person>& temp)
{
	char m;//����ѡ�����ʲô����
	char flag = '1';//�����Ƿ��˳�
	do
	{
		do	  //ѡ�����
		{
			cout << "��������Ҫ�Ĳ����� " << endl;
			cout << "1�� �鿴ȫ����ϵ��" << endl;
			cout << "2�� ����鿴��ϵ��" << endl;
			cout << "3�� ��������ϵ��" << endl;
			cout << "4�� ������ϵ��" << endl;
			cout << "5�� ɾ����ϵ��" << endl;
			cout << "6�� �޸���ϵ����Ϣ" << endl;
			cout << endl << "   �˳��밴 0" << endl;
			cin >> m;
			if (m >= '0' && m <= '6')
				break;
			else
				cout << "��������ȷ�Ĳ�����" << endl;
		} while (true);


		switch (m)	   //����ѡ��Ĳ���ִ�ж���
		{
		case '1': print(temp); break;
		case '2': printz(temp); break;
		case '3': addper(temp); break;
		case '4': find(temp); break;
		case '5': deleteper(temp); break;
		case '6': reset(temp); break;
		default: flag = '0';
		}

		if (flag == '0')//����һ���˵��Ѿ�ѡ���˳��������ٴ�ѯ��
			break;

		do
		{						   //�Ƿ����ִ����һ����
			cout << endl << "�����Ƿ������ " << endl << "0. �˳�  1. ���� " << endl;
			cin >> flag;
			if (flag == '1' || flag == '0')
				break;
			else
			{
				cout << "��������ȷ�Ĳ�����" << endl;
			}

		} while (true);

		if (flag == '0')	   //�˳�
			break;


	} while (true);
}
#endif head_H
