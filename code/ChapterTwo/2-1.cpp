/**
 * @file 2-1.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief 实现从标准输入读取字符串并输出
 * @version 1.1.0
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024 Hello-Cpp
 * 
 */

#include <iostream>     // 引入 iostream 头文件
#include <string>       // 引入 string 头文件（string）

using namespace std;    // 使用标准命名空间 std

int main()              // 声明 main 函数
{                       // 函数体开始
    string strA;        // 声明 strA 变量
    cin >> strA;        // 从标准输入流读取后赋值给 strA 变量
    cout << strA;       // 向标准输出流写入 strA 变量的值

    return 0;           // 通常用于表示程序成功运行并正常结束。
}                       // 函数体结束