---
comments: true
---

# 3.5 C++ 算术操作符

大家可能还对学校里作的算术练习记忆犹新，在计算机上也能够获得同样的乐趣。C++使用操作符来运算。它提供了儿种操作符来完成5种基本的算术计算;加法、减法、乘法、除法以及求模。每种操作符都使用两个值(操作数)来计算结果。操作符及其操作数构成了表达式。例如，在下面的语句中:

``` C++
int add = 4 + 2;
```

4 和 2 都是操作数，+ 是加法操作符， 4 + 2 则是一个表达式，其值为 6。下面是 C++ 的 5 种基本算术操作符:

- \+ 操作符对操作数执行加法运算。例如，4 + 20 等于 24。
- \- 操作符从第一个数中减去第二个数。例如，12 - 3 等于 9。
- \* 操作符将操作数相乘。例如，28 * 4 等于 112。
- / 操作符用第一个数除以第二个数。例如，1000 / 5 等于 200。如果两个操作数都是整数，则结果为商的整数部分。例如，17 / 3 等于 5，小数部分被丢弃。
- % 操作符求模。也就是说，它生成第一个数除以第二个数后的余数。例如，19 % 6 为 1，因为 19 是 6 的 3 倍余 1。两个操作数必须都是整型，将该操作符用于浮点数将导致编译错误。如果其中个是负数，则结果的符号依赖于实现。

当然，变量和常量都可以用作操作数，由于 % 的操作数只能是整数，因此我们将在后面的例子中讨论它。

``` C++ title="程序代码3-3"
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
```

程序的正确输出应该与下列文本相似，从中可以看出 C++ 能够完成简单的算术运算

``` base
输入一个数字：71.16
输入另一个数字：15.30
operands  = 71.160004; operated = 15.300000
operands + operated = 86.460007
operands - operated = 55.860004
operands * operated = 1088.748047
operands / operated = 4.650980
```

也许有细心的读者发现了问题！71.16 与 15.30 相加减后结果出现了 .460007 与 .860004。这不是运算问题，而是由于 `float` 类型表示有效位数的能力有限。C++ 只保证 6 位有效位。如果将 86.460007 四舍五入成 6 位，将得到 86.4600，这是保证精度的正确结果。如果需要更高的精度你可以尝试 `double` 和 `long double`。

## 3.5.1 操作符优先级和结核性

### 操作符优先级

在数学课上，我们学习过，运算符有其基本的优先级，这即为代数优先级（先乘除，后加减，先括号内，后括号外）。同样在 C++ 中我们也有运算符的优先级，很多表达式都包含有多个操作符。但计算机如何理解并优先使用哪个操作符呢？他们将按照下列介绍逐级参与运算。

1.作用域解析操作符（::）

这是优先级最高的操作符，用于指定命名空间、类或全局作用域中的标识符。例如：

``` C++
#include <iostream>
namespace MyNamespace {
    int value = 42;
}

int main() {
    std::cout << MyNamespace::value << std::endl;
    return 0;
}
```

2.后缀操作符（++、-- 等）

后缀自增和自减操作符会在表达式计算完成后再对变量的值进行改变。例如：

``` C++
#include <iostream>
int main() {
    int num = 5;
    int result = num++;  // 先使用 num 的值 5 赋给 result，然后 num 再自增为 6
    std::cout << "result: " << result << ", num: " << num << std::endl;
    return 0;
}
```

3.前缀操作符（++、--、!、~ 等）

前缀自增和自减操作符会先对变量的值进行改变，然后再参与表达式的计算。逻辑非（!）和按位取反（~）操作符也属于这一类。例如：

``` C++
#include <iostream>
int main() {
    int num = 5;
    int result = ++num;  // 先将 num 自增为 6，然后再将 6 赋给 result
    std::cout << "result: " << result << ", num: " << num << std::endl;
    return 0;
}
```

4.乘法、除法和取模操作符（*、/、%）

这些操作符用于执行乘、除和取模运算，它们的优先级相同。例如：

``` C++
#include <iostream>
int main() {
    int a = 10;
    int b = 3;
    int result = a / b * 2;  // 先进行除法运算 10 / 3 = 3，再进行乘法运算 3 * 2 = 6
    std::cout << "result: " << result << std::endl;
    return 0;
}
```

5.加法和减法操作符（+、-）

用于执行加法和减法运算，优先级低于乘法、除法和取模操作符。例如：

``` C++
#include <iostream>
int main() {
    int a = 10;
    int b = 3;
    int result = a + b * 2;  // 先进行乘法运算 3 * 2 = 6，再进行加法运算 10 + 6 = 16
    std::cout << "result: " << result << std::endl;
    return 0;
}
```

6.关系操作符（<、<=、>、>=）

用于比较两个值的大小关系，返回布尔值。例如：

``` C++
#include <iostream>
int main() {
    int a = 10;
    int b = 3;
    bool result = a > b;  // 比较 a 是否大于 b，结果为 true
    std::cout << "result: " << std::boolalpha << result << std::endl;
    return 0;
}
```

7.相等性操作符（==、!=）

用于判断两个值是否相等，返回布尔值。例如：

``` C++
#include <iostream>
int main() {
    int a = 10;
    int b = 3;
    bool result = a == b;  // 判断 a 是否等于 b，结果为 false
    std::cout << "result: " << std::boolalpha << result << std::endl;
    return 0;
}
```

8.逻辑与操作符（&&）

用于逻辑与运算，只有当两个操作数都为真时，结果才为真。例如：

``` C++
#include <iostream>
int main() {
    bool a = true;
    bool b = false;
    bool result = a && b;  // 逻辑与运算，结果为 false
    std::cout << "result: " << std::boolalpha << result << std::endl;
    return 0;
}
```

9.逻辑或操作符（||）

用于逻辑或运算，只要两个操作数中有一个为真，结果就为真。例如：

``` C++
#include <iostream>
int main() {
    bool a = true;
    bool b = false;
    bool result = a || b;  // 逻辑或运算，结果为 true
    std::cout << "result: " << std::boolalpha << result << std::endl;
    return 0;
}
```

10.条件操作符（?:）

这是 C++ 中唯一的三元操作符，用于根据一个条件表达式的结果选择两个值中的一个。例如：

``` C++
#include <iostream>
int main() {
    int a = 10;
    int b = 3;
    int result = (a > b) ? a : b;  // 如果 a 大于 b，则结果为 a，否则为 b
    std::cout << "result: " << result << std::endl;
    return 0;
}
```

11.赋值操作符（=、+=、-= 等）

用于将一个值赋给一个变量，优先级较低。例如：

``` C++
#include <iostream>
int main() {
    int a = 10;
    a += 5;  // 等价于 a = a + 5，将 a 的值更新为 15
    std::cout << "a: " << a << std::endl;
    return 0;
}
```

### 操作符结合性

当一个表达式中出现多个具有相同优先级的操作符时，操作符的结合性决定了它们的计算顺序。结合性分为左结合和右结合：

1.左结合

大多数操作符都是左结合的，即从左到右依次计算。例如，加法和减法操作符就是左结合的：

``` C++
#include <iostream>
int main() {
    int a = 10 - 3 - 2;  // 先计算 10 - 3 = 7，再计算 7 - 2 = 5
    std::cout << "a: " << a << std::endl;
    return 0;
}
```

2.右结合

少数操作符是右结合的，如赋值操作符和条件操作符。例如，赋值操作符的右结合性使得连续赋值成为可能：

``` C++
#include <iostream>
int main() {
    int a, b, c;
    a = b = c = 10;  // 先将 10 赋给 c，再将 c 的值赋给 b，最后将 b 的值赋给 a
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
    return 0;
}
```

!!! tip "注意"
    **操作符优先级和结合性共同决定了表达式的计算顺序。**在编写复杂的 C++ 表达式时，若对操作符的优先级和结合性不确定，建议使用括号 `()` 来明确指定计算顺序，这样可以提高代码的可读性和可维护性，避免因操作符优先级和结合性导致的错误。 

以下是完整的 C++ 操作符优先级和结合性列表，按照优先级从高到低排列，同一组内的操作符优先级相同。

| 优先级 | 操作符 | 名称或含义 | 使用形式 | 结合方向 | 说明 |
| :---: | --- | --- | --- | :---: | --- |
| 1 | `::` | 作用域解析符 | `namespace::name` <br> `class::name` <br> `::name` | 左到右 | 用于指定作用域，可用于访问命名空间、类中的成员，或全局作用域的名称 |
| 2 | `()` | 括号（函数调用、类型转换[^1]） | `func(arg1, arg2)` <br> `(type)expression` | 左到右 | 用于函数调用或强制类型转换 |
| 2 | `[]` | 数组下标 | `array[index]` | 左到右 | 用于访问数组元素 |
| 2 | `->` | 通过指针访问成员 | `ptr->member` | 左到右 | 用于通过指针访问对象的成员 |
| 2 | `.` | 通过对象访问成员 | `obj.member` | 左到右 | 用于通过对象访问其成员 |
| 2 | `++` | 后缀自增 | `var++` | 左到右 | 先使用变量的值，再将变量的值加 1 |
| 2 | `--` | 后缀自减 | `var--` | 左到右 | 先使用变量的值，再将变量的值减 1 |
| 3 | `++` | 前缀自增 | `++var` | 右到左 | 先将变量的值加 1，再使用变量的值 |
| 3 | `--` | 前缀自减 | `--var` | 右到左 | 先将变量的值减 1，再使用变量的值 |
| 3 | `+` | 一元正号 | `+var` | 右到左 | 通常不改变操作数的值，用于表示正数 |
| 3 | `-` | 一元负号 | `-var` | 右到左 | 对操作数取负 |
| 3 | `!` | 逻辑非 | `!condition` | 右到左 | 对布尔表达式取反 |
| 3 | `~` | 按位取反 | `~var` | 右到左 | 对操作数的每一位取反 |
| 3 | `*` | 解引用 | `*ptr` | 右到左 | 用于访问指针所指向的对象 |
| 3 | `&` | 取地址 | `&var` | 右到左 | 获取变量的内存地址 |
| 3 | `sizeof` | 求字节数 | `sizeof(type)` <br> `sizeof expression` | 右到左 | 计算类型或表达式所占的字节数 |
| 3 | `new` <br> `new[]` | 动态内存分配 | `new type` <br> `new type[size]` | 右到左 | 用于在堆上分配内存 |
| 3 | `delete` <br> `delete[]` | 动态内存释放 | `delete ptr` <br> `delete[] arr` | 右到左 | 用于释放堆上分配的内存 |
| 4 | `.*` | 成员指针访问（对象） | `obj.*ptr_to_member` | 左到右 | 通过对象访问成员指针所指向的成员 |
| 4 | `->*` | 成员指针访问（指针） | `ptr->*ptr_to_member` | 左到右 | 通过指针访问成员指针所指向的成员 |
| 5 | `*` | 乘法 | `a * b` | 左到右 | 计算两个数的乘积 |
| 5 | `/` | 除法 | `a / b` | 左到右 | 计算两个数的商 |
| 5 | `%` | 取模（取余） | `a % b` | 左到右 | 计算两个整数相除的余数 |
| 6 | `+` | 加法 | `a + b` | 左到右 | 计算两个数的和 |
| 6 | `-` | 减法 | `a - b` | 左到右 | 计算两个数的差 |
| 7 | `<<` | 按位左移 | `a << n` | 左到右 | 将操作数的二进制位向左移动指定的位数 |
| 7 | `>>` | 按位右移 | `a >> n` | 左到右 | 将操作数的二进制位向右移动指定的位数 |
| 8 | `<` | 小于 | `a < b` | 左到右 | 比较两个值的大小，判断左边是否小于右边 |
| 8 | `<=` | 小于等于 | `a <= b` | 左到右 | 比较两个值的大小，判断左边是否小于等于右边 |
| 8 | `>` | 大于 | `a > b` | 左到右 | 比较两个值的大小，判断左边是否大于右边 |
| 8 | `>=` | 大于等于 | `a >= b` | 左到右 | 比较两个值的大小，判断左边是否大于等于右边 |
| 9 | `==` | 等于 | `a == b` | 左到右 | 判断两个值是否相等 |
| 9 | `!=` | 不等于 | `a != b` | 左到右 | 判断两个值是否不相等 |
| 10 | `&` | 按位与 | `a & b` | 左到右 | 对两个操作数的对应二进制位进行与运算 |
| 11 | `^` | 按位异或 | `a ^ b` | 左到右 | 对两个操作数的对应二进制位进行异或运算 |
| 12 | `|` | 按位或 | `a | b` | 左到右 | 对两个操作数的对应二进制位进行或运算 |
| 13 | `&&` | 逻辑与 | `a && b` | 左到右 | 对两个布尔表达式进行逻辑与运算，有短路特性 |
| 14 | `||` | 逻辑或 | `a || b` | 左到右 | 对两个布尔表达式进行逻辑或运算，有短路特性 |
| 15 | `?:` | 条件运算符 | `condition ? expr1 : expr2` | 右到左 | 根据条件表达式的值选择两个表达式之一进行计算 |
| 16 | `=` | 赋值 | `a = b` | 右到左 | 将右边的值赋给左边的变量 |
| 16 | `+=` | 加赋值 | `a += b` | 右到左 | 等价于 `a = a + b` |
| 16 | `-=` | 减赋值 | `a -= b` | 右到左 | 等价于 `a = a - b` |
| 16 | `*=` | 乘赋值 | `a *= b` | 右到左 | 等价于 `a = a * b` |
| 16 | `/=` | 除赋值 | `a /= b` | 右到左 | 等价于 `a = a / b` |
| 16 | `%=` | 取模赋值 | `a %= b` | 右到左 | 等价于 `a = a % b` |
| 16 | `<<=` | 左移赋值 | `a <<= b` | 右到左 | 等价于 `a = a << b` |
| 16 | `>>=` | 右移赋值 | `a >>= b` | 右到左 | 等价于 `a = a >> b` |
| 16 | `&=` | 按位与赋值 | `a &= b` | 右到左 | 等价于 `a = a & b` |
| 16 | `^=` | 按位异或赋值 | `a ^= b` | 右到左 | 等价于 `a = a ^ b` |
| 16 | `|=` | 按位或赋值 | `a |= b` | 右到左 | 等价于 `a = a | b` |
| 17 | `,` | 逗号运算符 | `expr1, expr2` | 左到右 | 从左到右依次计算表达式，返回最后一个表达式的值 |


**解释说明**

- **优先级**：数值越小，优先级越高。高优先级的操作符会先于低优先级的操作符进行计算。
- **结合性**：
    - **左结合**：表达式中相同优先级的操作符从左到右依次计算。
    - **右结合**：表达式中相同优先级的操作符从右到左依次计算。

!!! tip "再次提醒"

    - **在编写复杂表达式时，为了提高代码的可读性和避免错误，建议使用括号来明确指定操作符的计算顺序。**
    - 逻辑与 `&&` 和逻辑或 `||` 具有短路特性。对于 `&&`，如果第一个表达式为假，则不会计算第二个表达式；对于 `||`，如果第一个表达式为真，则不会计算第二个表达式。 

## 3.5.2 除法分支

在 C++ 里，算术操作符中的除法操作会根据操作数的数据类型呈现出不同的行为，本小节为你详细介绍整数除法和浮点数除法这两个主要分支：

1.整数除法

当除法操作的两个操作数都是整数类型（像 `int`、`long`、`short` 等）时，C++ 执行的是整数除法。整数除法会直接舍弃商的小数部分，只保留整数部分。

2.浮点数除法

要是除法操作的操作数中有一个或两个是浮点数类型（例如 `float`、`double`），C++ 就会执行浮点数除法，其结果会包含小数部分。例如：

``` C++
#include <iostream>
int main() {
    double a = 7.0;
    double b = 2.0;
    double result = a / b;
    std::cout << "浮点数除法结果: " << result << std::endl;
    return 0;
}
```

在这个例子中，`a` 和 `b` 都是 `double` 类型。`a / b` 执行的是浮点数除法，`7.0` 除以 `2.0` 的结果是 `3.5`，因此最终 result 的值为 `3.5`。

3.混合类型除法

当一个操作数是整数类型，另一个是浮点数类型时，整数会被隐式转换为浮点数，然后执行浮点数除法。例如：

``` C++
#include <iostream>
int main() {
    int a = 7;
    double b = 2.0;
    double result = a / b;
    std::cout << "混合类型除法结果: " << result << std::endl;
    return 0;
}
```

在这个例子中，`a` 是 `int` 类型，`b` 是 `double` 类型。在进行除法运算时，`a` 会被隐式转换为 `double` 类型，接着执行浮点数除法，所以结果 `result` 是 `3.5`。

4.特殊情况：除数为零

在 C++ 中，无论是整数除法还是浮点数除法，除数都不能为零。如果除数为零，程序会出现未定义行为。对于整数除法，运行时可能会导致程序崩溃；对于浮点数除法，可能会得到 $NaN$（非数）或者 $\pm Inf$（正负无穷大）。例如：

``` C++
#include <iostream>
int main() {
    int a = 7;
    int b = 0;
    // 以下代码会导致未定义行为，不要这样做
    // int result = a / b;
    // std::cout << result << std::endl;

    double c = 7.0;
    double d = 0.0;
    double result2 = c / d;
    std::cout << "浮点数除以零结果: " << result2 << std::endl;
    return 0;
}
```

在这个例子中，整数除法 `a / b` 由于除数为零会引发未定义行为，不建议这样使用。而浮点数除法 `c / d` 中，`7.0` 除以 `0.0` 会得到 `inf`（正无穷大），输出结果可能会因编译器和系统的不同而有所差异。在实际编程中，要确保除数不为零，避免出现未定义行为。

## 3.5.3 求模操作符

比起求模操作符来说，多数人更熟悉加、减、乘、除，因此这里花些时间介绍这种操作符。

**求模操作符 `%` 用于返回整数除法的余数。**在 C++ 里，当两个整数进行除法运算时，使用 `/` 操作符会得到商的整数部分（即整数除法），而使用 `%` 操作符则会得到除法运算后的余数。求模操作符与整数除法相结合，特别适合解决把一个量拆分成不同整数单元的问题，下面以常见的单位转换为例进行说明：

在长度单位体系中，常见的有米、分米、厘米、毫米，其中 1 米 = 10 分米，1 分米 = 10 厘米，1 厘米 = 10 毫米。我们可以将厘米为单位的长度值转换为米和厘米。

``` C++ title="程序代码3-4"
#include <iostream>

using namespace std;

int main() {
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
```


[^1]: 类型转换的具体讲解参见 3.7 类型转换小节。