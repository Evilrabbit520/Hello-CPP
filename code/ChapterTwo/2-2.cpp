/**
 * @file 2-2.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief 探究变量和赋值
 * @version 1.0.0
 * @date 2024-02-26
 * 
 * @copyright Copyright (c) 2024 Hello-Cpp
 * 
 */

#include <iostream>

using namespace std;

int main()
{
    int age;            //声明 int 类型的 age 变量
    age = 18;           //将 age 变量的值修改(赋值)为18

    string name;        //声明 string 类型的 name 变量
    name = "Hello-CPP"; //将 name 变量的值修改(赋值)为 Hello-CPP

    cout << "My name is: " << name <<", my age is: " << age << endl;
    
    return 0;
}