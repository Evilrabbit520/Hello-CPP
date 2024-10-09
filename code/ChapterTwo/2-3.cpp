/**
 * @file 2-3.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief 使用 cin 从键盘输入
 * @version 1.0.0
 * @date 2024-10-08
 * 
 * @copyright Copyright (c) 2024 Hello-Cpp
 * 
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int age;            //声明 int 类型的 age 变量
    cout << "Please enter the value of age." << endl;
    cin >> age;         //通过键盘输入 age 变量的值

    string name;        //声明 string 类型的 name 变量
    cout << "Please enter the value of name." << endl;
    cin >> name;        //通过键盘输入 name 变量的值

    cout << "My name is: " << name <<", my age is: " << age << endl;
    
    return 0;
}