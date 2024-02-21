// 字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "string_head.h"

using namespace std;
int main()
{
    char a[]= "dream",b[]="ea";
    a_string A(a);
    a_string B(b);
    a_string C(A);
    cout<<"\nA的长度为："<<A.get_length();
    cout << "\n两者是否相等："<<(A == B);
    //cout << (A.operator==(B));//等效于上一行，用函数实现
    cout << "\n两者是否不等：" <<(A != B);
    cout << "\nA是否为空：" <<!A;//A!不行
    //A.operator!();//等效于上一行
    cout << "\n" << A.find(B);//搜索成功返回第一个下标，失败返回-1
    cout << "\n" << B.find(A);
    A += B;//连接
    cout << "\n连接后：";
    A.output();
    A = B;//赋值
    cout << "\n赋值后：";
    A.output();
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
