#pragma once
#ifndef head_H
#define head_H

#include<string>
#include<fstream>
#include "seq_list.h"

enum rela 
{ 其他 = 0, 亲人, 朋友, 同事 };

string getz(rela r1)  //将枚举类转化为文字输出
{
	switch (r1)
	{
	case 1:return (string)"亲人";
	case 2:return (string)"朋友";
	case 3:return (string)"同事";
	}
}

struct person
{
	string number;
	string  name;
	rela r;
	string tel;

	person() //默认构造函数
	{
		number = '\0'; name = "\0"; r = 其他; tel = "\0";
	}
	person(string number1, string  name1, rela r1, string tel1)
	{
		number = number1; name = name1; r = r1; tel = tel1;
	}

	void printp()
	{
		cout << endl << "当前联系人为：" << endl;
		cout << "编号： " << number << endl;
		cout << "姓名： " << name << endl;
		cout << "分组：" << getz(r) << endl;
		cout << "电话号码： " << tel << endl;
	}
};

//读取初始通讯录
bool read(seq_list<person>& temp)
{
	ifstream openp;			 //打开文件读取初始通讯录
	openp.open("通讯录.txt");
	if (!openp.is_open()) {
		cout << "未成功打开文件" << endl;
		return false;
	}
	string n1; string name1; rela r1; string tel1; //用于存储读取的临时数据 
	for (int i = 0; i < 6; i++)	//文件没结束
	{
		openp >> n1 >> name1 >> (int&)r1 >> tel1;	   //用于写入到线性表中
		person tempper(n1, name1, r1, tel1);			   //用于写入到线性表中
		bool flag = temp.insert(temp.length(), tempper);

		if (flag == false)			   //插入不成功
			cout << "插入错误" << endl;
	}
	openp.close();
	return true;
}

//输出全部通讯录
void print(seq_list<person>& temp)
{
	person tempp;//临时存放待输出联系人
	for (int i = 0; i < temp.length() ; i++)
	{
		temp.get_data(i + 1, tempp);
		tempp.printp();
	}
}

//分组输出
void printz(seq_list<person>& temp)
{
	person tempp;//临时存放待输出联系人
	rela r1;
	do
	{
		cout << "请输入要查找的组别：" << endl;
		cout << "1. 亲人；  2. 朋友；  3. 同事：" << endl;
		cin >> (int&)r1;
		if (r1 != 亲人 && r1 != 朋友 && r1 != 同事)
		{
			cout << "请输入正确的分组！" << endl << endl; continue;
		}

		for (int i = 0; i < temp.length() ; i++)	 //从头遍历，寻找分组满足条件的元素
		{
			temp.get_data(i + 1, tempp);
			if (tempp.r == r1)
				tempp.printp();
		}
		break;//分组打印结束，退出
	} while (true);
}
//添加联系人
void addper(seq_list<person>& temp)
{
	string n1; string name1; rela r1; string tel1; //用于写入新数据
	cout << "请输入想要添加的联系人信息" << endl;
	cout << "请输入新联系人编号：" << endl;
	person tempp;//临时存放每次读取到的联系人
	do
	{
		cin >> n1;
		int flag = 0; //判定是否与已有编号重复
		for (int i = 0; i < temp.length() ; i++)
		{
			temp.get_data(i + 1, tempp);
			if (tempp.number == n1)
			{
				cout << "编号已经存在，请输入一个新编号" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)	//flag没被置1表示没有发现重复项
			break;

	} while (true);

	cout << "请输入新联系人的姓名：" << endl;
	cin >> name1;

	cout << "请输入新联系人的分组，1. 亲人；  2. 朋友；  3. 同事：" << endl;
	cin >> (int&)r1;

	cout << "请输入新联系人的电话号码：" << endl;
	cin >> tel1;

	person tempper1(n1, name1, r1, tel1);	  //要插入的联系人

	bool insert1 = temp.insert(temp.length() , tempper1); //插入
	if (insert1)
		cout << "新建联系人成功！" << endl;
}

//通过编号获得联系人是第几个元素
int numberfind(seq_list<person>& temp, int n)  //n表示在不同场景中调用，控制提示文字的改变
{
	person tempp;//临时存放待输出联系人
	string fi;//想要查找的编号
	cout << "请输入想要";

	switch (n)
	{
	case 1:cout << "查找"; break;
	case 2:cout << "删除"; break;
	case 3:cout << "修改"; break;
	}

	cout << "的联系人编号：" << endl;
	cin >> fi;
	for (int i = 0; i < temp.length() ; i++)	 //从头遍历，寻找分组满足条件的元素
	{
		temp.get_data(i + 1, tempp);
		if (tempp.number == fi)
			return i;
	}
	return -1;
}

//通过姓名获得联系人是第几个元素
int namefind(seq_list<person>& temp, int n)	  //n表示在不同场景中调用，控制提示文字的改变
{
	person tempp;//临时存放待输出联系人
	string fstring;//想要查找的姓名
	cout << "请输入想要";
	switch (n)
	{
	case 1:cout << "查找"; break;
	case 2:cout << "删除"; break;
	case 3:cout << "修改"; break;
	}
	cout << "的联系人姓名：" << endl;
	cin >> fstring;
	for (int i = 0; i < temp.length() ; i++)	 //从头遍历，寻找分组满足条件的元素
	{
		temp.get_data(i + 1 , tempp);
		if (tempp.name == fstring)
			return i;
	}
	return -1;
}

//查找联系人
void find(seq_list<person>& temp)
{
	char m; //用于判定查找方式
	int result; //查找结果
	person tempper;//若找到，用于存储找到的联系人
	do
	{
		cout << "请输入想通过哪种方式查找" << endl;
		cout << "1. 通过编号查找   2. 通过姓名查找" << endl;
		cin >> m;
		if (m == '1')
			result = numberfind(temp, 1); //选择了编号查找
		else if (m == '2')
			result = namefind(temp, 1);  //选择了姓名查找
		else 						  //选项错误，重新输入选项
		{
			cout << "请输入正确的方式！" << endl;
			continue;
		}
		if (result == -1)
		{
			cout << "没有找到该联系人" << endl;
			break;							//没找到，结束查找
		}
		else
		{
			cout << "找到了该联系人" << endl;
			temp.get_data(result, tempper);
			tempper.printp();
			break;						   //找到了，结束查找
		}
	} while (true);
}

//删除联系人
void deleteper(seq_list<person>& temp)
{
	//先查找是否有要删除的联系人
	int result;//用于表示查找到要删除的联系人与否
	char m;//用于表示用哪种方式修改
	do
	{
		cout << "请输入想通过哪种方式删除" << endl;
		cout << "1. 通过编号删除   2. 通过姓名删除" << endl;
		cin >> m;
		if (m == '1')
			result = numberfind(temp, 2); //选择了编号删除
		else if (m == '2')
			result = namefind(temp, 2);  //选择了姓名删除
		else 						  //选项错误，重新输入选项
		{
			cout << "请输入正确的方式！" << endl;
			continue;
		}
		if (result == -1)
		{
			cout << "无该联系人" << endl;
			break;							//想删除的联系人不存在
		}
		else
		{
			person tempper;
			temp.remove(result, tempper);
			cout << "删除成功！" << endl;
			break;						   //找到了，删除
		}
	} while (true);
}

//修改联系人
void reset(seq_list<person>& temp)
{
	//先查找是否有要修改的联系人
	int result;//用于表示查找到要修改的联系人与否
	char m;//用于表示用哪种方式修改
	do
	{
		cout << "请输入想通过哪种方式修改" << endl;
		cout << "1. 通过编号修改   2. 通过姓名修改" << endl;
		cin >> m;
		if (m == '1')
			result = numberfind(temp, 3); //选择了编号修改
		else if (m == '2')
			result = namefind(temp, 3);  //选择了姓名修改
		else 						  //选项错误，重新输入选项
		{
			cout << "请输入正确的方式！" << endl;
			continue;
		}
		if (result == -1)
		{
			cout << "无该联系人" << endl;
			break;							//想修改的联系人不存在
		}
		else
		{
			person tempper1;  //存放老数据（编号与姓名）
			temp.get_data(result, tempper1);
			person tempper2;  //新联系人
			tempper2.number = tempper1.number;//编号不变
			tempper2.name = tempper1.name;//姓名不变

			rela r1;   //新分组
			string tel1; //新号码
			cout << "请输入新分组,，1. 亲人；  2. 朋友；  3. 同事：" << endl;
			cin >> (int&)r1;
			cout << "请输入新号码" << endl;
			cin >> tel1;
			tempper2.r = r1;
			tempper2.tel = tel1;

			temp.set_data(result, tempper2);

			cout << "修改成功！" << endl;
			break;						   //找到了，修改
		}
	} while (true);

}

//开始运行
void start(seq_list<person>& temp)
{
	char m;//用于选择进行什么操作
	char flag = '1';//用于是否退出
	do
	{
		do	  //选择操作
		{
			cout << "请输入需要的操作： " << endl;
			cout << "1： 查看全部联系人" << endl;
			cout << "2： 分组查看联系人" << endl;
			cout << "3： 插入新联系人" << endl;
			cout << "4： 查找联系人" << endl;
			cout << "5： 删除联系人" << endl;
			cout << "6： 修改联系人信息" << endl;
			cout << endl << "   退出请按 0" << endl;
			cin >> m;
			if (m >= '0' && m <= '6')
				break;
			else
				cout << "请输入正确的操作！" << endl;
		} while (true);


		switch (m)	   //根据选择的操作执行动作
		{
		case '1': print(temp); break;
		case '2': printz(temp); break;
		case '3': addper(temp); break;
		case '4': find(temp); break;
		case '5': deleteper(temp); break;
		case '6': reset(temp); break;
		default: flag = '0';
		}

		if (flag == '0')//若上一级菜单已经选择退出，不必再次询问
			break;

		do
		{						   //是否继续执行下一操作
			cout << endl << "请问是否继续？ " << endl << "0. 退出  1. 继续 " << endl;
			cin >> flag;
			if (flag == '1' || flag == '0')
				break;
			else
			{
				cout << "请输入正确的操作！" << endl;
			}

		} while (true);

		if (flag == '0')	   //退出
			break;


	} while (true);
}
#endif head_H
