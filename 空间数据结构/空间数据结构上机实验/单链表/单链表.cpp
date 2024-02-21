// 单链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"head_01.h"
#include <iostream>
using namespace std;
int main()
{
    int a(3),b(5),c(1);
    list<int> A;//初始化A
    list<int> B(a);//初始化B
    B.insert(0, b);//第1个元素设为5
    cout << "前插法：" << endl;
    B.input_f(-1);//前插法
    cout << "后插法：" << endl;
    B.input_f(-1);//后插法
    cout << "B的长度:"<<B.length() << endl;//B的长度
    cout << "第1个元素的地址：" << B.locate(c) << endl;//定位
    cout << "元素3的地址：" << B.search(a) << endl;//搜索
    cout << "空为0，不空为1：" << B.is_empty() << endl;//判断是否空
    cout << "链表元素：";
    B.output();//逐个输出
    B.get_data(1, b);///取第1个元素
    B.set_data(1, c); //第1个元素设为1
    cout << "链表元素：";
    B.output();//逐个输出
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
