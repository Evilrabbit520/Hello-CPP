---
comments: true
---

# 2.1 正式学习 C++

最早的计算机所需执行的任务便是由人们输入一些指令，并将运算所得的再输出出来，这里我们也将介绍一个最简单的可以执行输入并输出的 C++ 程序。程序代码2-1实现了用户输入什么内容，程序边输出什么内容。

程序代码2-1先使用 `std::cin` 输入，再使用 `std::cout` 输出。代码中包含了一些提供程序员或任何读到这段源码的读者所阅读的文字内容，这称作注释，这些注释都以 `//` 开头，在实际代码编译过程中，编译器会忽略它们。

``` C++ title="程序代码2-1"
#include <iostream>     // 引入 iostream 头文件

using namespace std;    // 使用标准命名空间 std

int main()              // 声明 main 函数
{                       // 函数体开始
    string strA;        // 声明 strA 变量
    cin >> strA;        // 从标准输入流读取后赋值给 strA 变量
    cout << strA;       // 向标准输出流写入 strA 变量的值

    return 0;           // 通常用于表示程序成功运行并正常结束。
}                       // 函数体结束
```

C++ 对大小写敏感，也就是说在开发过程中，需要严格区分大小写字符，比如将 `cin` 替换为 `CIN` 或 `Cin` 程序将无法通过编译(编译器提示：使用了未知的标识符)。同样编译器也是对拼写敏感的，因此如果你将 `cin` 替换为 `in` 或 `cing` 程序也将无法通过编译。这也意味着，你的程序中拼写与大小写必须与示例中相同。

C++ 中，通常将代码分为头文件、源文件和可能的其他文件(如实现文件)。头文件通常用 `.h` 或 `.hpp` 后缀；源文件通常用 `.cpp` 后缀；实现文件通常用 `.cxx` 或 `.cc` 后缀。这是一种我们建议的组织代码的方式。

!!! example ""

    如果你使用过 C 语言，在看到 cout 函数(而不是 `printf()` 函数)时可能会略显惊讶。事实上，C++ 完全可以使用原有 C 语言的所有功能，例如 `scanf()` 、 `printf()` ，你只需要包含常规 C 语言的 `stdio.h` 头文件即可。但本书讲解的是 C++ 语言，所以将使用 C++ 的特性和功能，他们在 C 版本的基础上进行了很多改进。从某些方面来讲，这将极大的提高你的开发效率。

使用函数来创建 C++ 程序。通常先将程序组织为主要任务，然后设计独立的函数来处理这些任务(通常在程序设计的部分我们要大体遵循一个原则：“高内聚，低耦合”)。

!!! tip "提示"

    **高内聚 (High Cohesion):** 意味着一个模块（类、函数等）应该关注于单一责任，执行一个明确定义的任务。高内聚的模块内部各部分应该彼此关联，共同服务于同一目标。高内聚的设计使得模块更容易理解、修改和维护。例如，一个处理用户输入的类应该专注于处理用户输入，而不涉及过多与其他模块无关的任务。如果一个模块承担了过多的任务，它的内聚性就较低。

    **低耦合 (Low Coupling):** 表示模块之间的相互依赖应该尽量减少。模块之间的关系应该是松散的，一个模块的修改不应该对其他模块造成过多的影响。低耦合的设计使得系统更容易维护、测试和重构。例如，如果一个模块修改了其内部实现，不应该导致其他模块的大规模修改。模块之间的接口应该清晰明了，避免不必要的依赖。

    综合来说，高内聚低耦合的设计原则旨在创建结构清晰、易于理解和可维护的代码，从而提高软件系统的质量和可扩展性。

