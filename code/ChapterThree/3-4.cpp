/**
 * @file 3-4.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief Commonly used length conversion.
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
    // 定义总厘米长度
    int totalCentimeters = 235;

    // 使用整数除法计算米数
    int meters = totalCentimeters / 100;

    // 使用求模操作符计算剩余的厘米数
    int remainingCentimeters = totalCentimeters % 100;

    // 输出转换结果
    cout << totalCentimeters << " 厘米等于 " << meters << " 米 " << remainingCentimeters << " 厘米" << endl;

    return 0;
}