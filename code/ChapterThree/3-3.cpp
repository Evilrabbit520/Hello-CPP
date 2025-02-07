/**
 * @file 3-3.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief arithmetic operator
 * @version 1.0.0
 * @date 2025-02-07
 * 
 * @copyright Copyright (c) 2024 Hello-Cpp
 * 
 */
#include <iostream>

using namespace std;

int main()
{
    float operands, operated;
    /**
     * 设置为固定点表示法（fixed-point notation）浮点数会以固定的小数位数进行输出，不用科学计数法
     * 如果读者的编译器不接受 ios_base::fixed 也可以使用 ios::fixed
     */
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "输入一个数字：";
    cin >> operands;    //操作数
    cout << "输入另一个数字：";
    cin >> operated;    //被操作数

    cout << "operands  = " << operands << "; operated = " << operated << endl;  // 确认输入
    cout << "operands + operated = " << operands + operated << endl;            //加操作
    cout << "operands - operated = " << operands - operated << endl;            //减操作
    cout << "operands * operated = " << operands * operated << endl;            //乘操作
    cout << "operands / operated = " << operands / operated << endl;            //除操作
    return 0;
}