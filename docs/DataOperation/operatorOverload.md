---
comments: true
---

# 3.6 操作符重载

!!! tip "章节阅读提示"

    在学习 C++ 的过程中，**操作符重载是一个具有一定难度的知识点**，可能对于当前阶段只学习到“C++ 算数操作符”的你来说有点超纲。为了让你能更顺畅地学习 C++，我们给出以下阅读建议。

    **现阶段建议**

    **目前先跳过操作符重载这部分内容的学习。因为操作符重载涉及到对类和对象、函数重载等更深入知识的理解，而你当前的知识储备可能还不足以完全掌握它。过早接触可能会让你感到困惑，影响学习的积极性和效果。**

    **后续学习指引**
    
    当你完成以下几个关键部分的学习后，就可以返回阅读操作符重载这一小节了：

    1. **类和对象**

    2. **函数重载**

    3. **构造函数和析构函数**

    当你完成上述内容的学习后，你将具备足够的知识基础来深入学习操作符重载。此时再返回阅读操作符重载这部分内容，你会发现理解起来更加轻松，也能更好地掌握这一重要的 C++ 特性。

    祝坚持到现在的你，在 C++ 的学习之旅中取得进步！

    <p style="text-align: right;">—— Evilrabbit</p>

在 C++ 中，操作符重载允许我们为自定义类型（如类和结构体）重新定义操作符的行为。结合前面提到的除法分支（整数除法和浮点数除法），我们可以通过操作符重载让自定义类型也支持除法运算。操作符重载是 C++ 的一项特性，它允许程序员为自定义类型重新定义操作符的行为。通过操作符重载，我们可以让自定义类型像内置类型一样使用各种操作符，增强代码的可读性和可维护性。对于除法操作符 `/`，我们可以为自定义类型定义其除法行为。

## 整数除法重载示例

假设我们有一个自定义的 `Fraction` 类表示分数，我们可以重载除法操作符来实现分数之间的除法。

``` C++
#include <iostream>

class Fraction {
private:
    int numerator, denominator;;   // 定义分子和分母

public:
    // 构造函数
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero!");
        }
    }

    // 重载除法操作符
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero fraction!");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // 打印分数
    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main() {
    Fraction f1(2, 3);
    Fraction f2(4, 5);

    try {
        Fraction result = f1 / f2;
        std::cout << "Result of division: ";
        result.print();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

在上述代码中：
- `Fraction` 类有两个私有成员变量 `numerator` 和 `denominator` 分别表示分子和分母。
- 构造函数用于初始化分数对象，并检查分母是否为零。
- `operator/` 函数是对除法操作符的重载，它接受一个 `Fraction` 类型的参数 `other`，并返回一个新的 `Fraction` 对象，表示两个分数相除的结果。在进行除法时，也会检查除数的分子是否为零。
- `print` 函数用于打印分数的信息。

### 浮点数除法重载示例

假设我们有一个自定义的 `Complex` 类表示复数，我们可以重载除法操作符来实现复数之间的除法。

``` C++
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 重载除法操作符
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw std::invalid_argument("Division by zero complex number!");
        }
        double newReal = (real * other.real + imag * other.imag) / denominator;
        double newImag = (imag * other.real - real * other.imag) / denominator;
        return Complex(newReal, newImag);
    }

    // 打印复数
    void print() const {
        std::cout << real;
        if (imag >= 0) {
            std::cout << " + " << imag << "i" << std::endl;
        } else {
            std::cout << " - " << -imag << "i" << std::endl;
        }
    }
};

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(4.0, 5.0);

    try {
        Complex result = c1 / c2;
        std::cout << "Result of division: ";
        result.print();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

在上述代码中：
- `Complex` 类有两个私有成员变量 `real` 和 `imag` 分别表示实部和虚部。
- 构造函数用于初始化复数对象。
- `operator/` 函数是对除法操作符的重载，它接受一个 `Complex` 类型的参数 `other`，并返回一个新的 `Complex` 对象，表示两个复数相除的结果。在进行除法时，会计算分母并检查是否为零。
- `print` 函数用于打印复数的信息。

!!! warning "注意⚠️"
    
    - **操作符重载不能改变操作符的优先级和结合性**：操作符重载只是为自定义类型重新定义了操作符的行为，但不会改变操作符原有的优先级和结合性。
    - **避免滥用操作符重载**：操作符重载应该遵循操作符的常规语义，避免让操作符的行为变得难以理解。
    - **处理特殊情况**：在重载除法操作符时，一定要处理除数为零的情况，避免出现未定义行为。

通过操作符重载，我们可以让自定义类型像内置类型一样方便地进行除法运算，提高代码的可读性和可维护性。 