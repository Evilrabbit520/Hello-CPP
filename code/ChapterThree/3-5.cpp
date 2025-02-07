/**
 * @file 3-5.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief Implicit type conversion
 * @version 1.0.0
 * @date 2025-02-07
 *
 * @copyright Copyright (c) 2024 Hello-Cpp
 *
 */
#include <iostream>

// 定义一个函数，用于打印整数
void printNumber(int num)
{
    std::cout << "传入函数的数字: " << num << std::endl;
}

int main()
{
    // 算术运算中的类型提升示例
    int a = 10;
    double b = 3.14;
    // 在加法运算中，int 类型的 a 会自动转换为 double 类型
    double result = a + b;
    std::cout << "算术运算结果（类型提升）: " << result << std::endl;

    // 赋值时的类型转换示例
    double num = 3.14;
    // double 类型的 num 会自动转换为 int 类型，小数部分丢失
    int integerNum = num;
    std::cout << "赋值转换后的整数: " << integerNum << std::endl;

    // 函数调用时的类型转换示例
    short s = 10;
    // short 类型的 s 会自动转换为 int 类型传递给函数
    printNumber(s);

    return 0;
}