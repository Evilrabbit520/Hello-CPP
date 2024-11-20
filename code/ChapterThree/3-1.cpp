/**
 * @file 3-1.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief char 和字符常量
 * @version 1.0.0
 * @date 2024-10-26
 * 
 * @copyright Copyright (c) 2024 Hello-Cpp
 * 
 */
#include <iostream>

using namespace std;

int main()
{
    char character;                             //声明 char 类型的 character 变量
    cout << "Please enter a character: ";
    cin >> character;                           //输入一个字符
    cout << character << endl;                  //程序输出输入的字符 第一次结果输出

    int decCharacter = character;               //声明 int 类型的 decCharacter 变量，用于存储字符的十进制值
    int newCharacter = decCharacter + 1;        //声明 int 类型的 newCharacter 变量，用于存储输入字符下一个字符的十进制值
    char nextCharacter = newCharacter;          //将新的结果存储(转换)为 char 类型的值

    cout << "Input characters: " << character << endl;
    cout << "Enter the decimal value of the character: " << decCharacter << endl;
    cout << "The character that is the decimal value of the input character plus one: " << nextCharacter << endl;
    
    return 0;
}