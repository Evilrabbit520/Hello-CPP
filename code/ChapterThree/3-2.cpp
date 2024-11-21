/**
 * @file 3-2.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief wcha_t
 * @version 1.0.0
 * @date 2024-11-21
 * 
 * @copyright Copyright (c) 2024 Hello-Cpp
 * 
 */
#include <iostream>
#include <cwchar>

using namespace std;

int main()
{
    wchar_t wstr[] = L"Hello, 世界";                         //声明 wcha_t 类型的 wstr 数组变量，并赋值
    int length = wcslen(wstr);                              //求 wster 字符串的长度
    wcout << L"宽字符串长度为: " << length << endl;           //使用 wcout 输出

    return 0;
}