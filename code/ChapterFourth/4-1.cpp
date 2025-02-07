/**
 * @file 4-1.cpp
 * @author Hello-Cpp (www.hi-cpp.com)
 * @brief Hotel room reservation procedure
 * @version 1.0.0
 * @date 2025-02-08
 *
 * @copyright Copyright (c) 2024 Hello-Cpp
 *
 */
#include <iostream>

using namespace std;

int main()
{
    // 定义布尔数组来表示 3 个房间的使用状态，初始都为空闲
    bool roomStatus[3] = {false, false, false};

    // 显示房间初始状态
    cout << "房间 1：" << (roomStatus[0] ? "已使用" : "空闲") << endl;
    cout << "房间 2：" << (roomStatus[1] ? "已使用" : "空闲") << endl;
    cout << "房间 3：" << (roomStatus[2] ? "已使用" : "空闲") << endl;

    // 模拟预订房间 2
    roomStatus[1] = true;

    // 显示房间更新后的状态
    cout << "\n更新后：" << endl;
    cout << "房间 1：" << (roomStatus[0] ? "已使用" : "空闲") << endl;
    cout << "房间 2：" << (roomStatus[1] ? "已使用" : "空闲") << endl;
    cout << "房间 3：" << (roomStatus[2] ? "已使用" : "空闲") << endl;

    return 0;
}