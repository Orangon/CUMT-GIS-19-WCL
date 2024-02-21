// 顺序表1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "seq_list.h"
using namespace std;
int main()
{
    int a = 3, b = 0, c = 5;
    seq_list<int> go(a);//调用构造函数
    go.input();//输入元素
    cout << "最大元素个数为：" << go.size() << endl;
    cout << "实际长度为：" <<go.length() << endl;
    go.output();//输出元素
    cout << go.search(a) << endl;//在顺序表中搜索值为a的元素，若找到返回是第几个元素，没找到返回0
    cout<<go.locate(1) << endl;//在顺序表中搜索第i个元素，若找到返回第i个元素位置，没找到返回0
    go.get_data(2, b);//取第2个表项的值
    go.set_data(1, c);//用c修改第1个表项的值
    go.insert(0, b);//在第0个表项之后插入b
    go.remove(1, b);//删除第1个表项，通过b返回表项的值
    seq_list<int> to(c);//复制构造函数
    to = go;//重载=
    cout << go.is_empty()<<endl;//判断go是否空，空返回true，否则返回false
    cout<<go.is_full() << endl;;//判断go是否满，满返回true，否则返回false
    go.RESIZE(8);//改变data数组空间大小
    go.output();//输出元素
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
