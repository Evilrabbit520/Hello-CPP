/**
 * @file 3-6.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief Explicit type conversion
 * @version 1.0.0
 * @date 2025-02-07
 *
 * @copyright Copyright (c) 2024 Hello-Cpp
 *
 */
#include <iostream>

// 用于演示 const_cast 的函数
void modifyValue(const int *ptr)
{
    // 使用 const_cast 去除 const 限定符
    int *nonConstPtr = const_cast<int *>(ptr);
    *nonConstPtr = 20;
}

int main()
{
    // static_cast 示例
    double doubleNum = 3.14;
    // 使用 static_cast 将 double 类型转换为 int 类型
    int intNum = static_cast<int>(doubleNum);
    std::cout << "static_cast: 把 " << doubleNum << " 从 double 类型转换为 int 类型后的值为 " << intNum << std::endl;

    // const_cast 示例
    int num = 10;
    const int *constPtr = &num;
    // 调用函数修改被 const 指针指向的值
    modifyValue(constPtr);
    std::cout << "const_cast: 修改后 num 的值为 " << num << std::endl;

    // reinterpret_cast 示例
    int num2 = 10;
    int *numPtr = &num2;
    // 使用 reinterpret_cast 将指针转换为 long 类型
    long address = reinterpret_cast<long>(numPtr);
    std::cout << "reinterpret_cast: num2 的地址以整数形式表示为 " << address << std::endl;

    return 0;
}