C++ virtual table

为了实现虚函数，C++ 使用一种特殊形式的后期绑定，称为虚表。

虚表是一种函数查找表，用于解析动态/后期绑定方式的函数。

首先，每个使用虚函数的类（或派生自使用虚函数的类）都被赋予自己的虚表。该表只是编译器在编译时设置的静态数组。

一个虚表还会为每个能被该类对象调用的虚函数保存一个入口。这里的入口是指函数指针。虚表中的每个条目都只是一个函数指针，指向该类可访问的 `most-derived` 的函数。

其次，编译器还会向基类添加一个隐藏的指针，我们将其称为`* __ vptr`。创建类实例时，会自动设置`* __ vptr`，令它指向该类的虚表。与`* this`指针（`*this`其实是编译器用来解析自引用的函数参数）不同，`* __ vptr`是**真实**的指针。

 * `*this` 指向当前对象。在这里阅读更多，https://stackoverflow.com/questions/16492736/what-is-the-this-pointer

因此，它（`* __ vptr`）使分配的每个类对象的大小都增加一个指针的大小。这也意味着`* __ vptr`将被派生类继承。



下面是一个例子及其对应的虚表。

```c++
class Base
{
public:
    virtual void function1() {};
    virtual void function2() {};
};
 
class D1: public Base
{
public:
    virtual void function1() {};
};
 
class D2: public Base
{
public:
    virtual void function2() {};
};
```

| 类   | *___vptr指向的VTable中所有条目指向的函数(函数入口->实际指向的函数) |
| ---- | ------------------------------------------------------------ |
| Base | Base VTable: funtion1() -> Base::function1() , function2() -> Base::function2() |
| D1   | D1 VTable: funtion1() -> D1::function1() , function2() -> Base::function2() |
| D2   | D2 VTable: funtion1() -> Base::function1() , function2() -> D2::function2() |



看看下面一个例子。

```c++
D1 d1;
D2 d2;
Base *dPtr = &d1; 
dPtr->function1(); // Guess which funtion will be called?
```

调用的是`D1::function1()`。为什么？

因为`dPtr->__vptr` 指向的是D1的虚表。当调用`dPtr->function1()` 时，因为这是虚函数，会寻找dPtr指向的对象（在这里是类D1的实例d1）的`*__vptr`，当然指向的是D1的虚表了。

之后再让dPtr指向d2，再调用`dPtr->function1()`，实际调用的就是`Base::function1()`了。

```c++
D1 d1;
D2 d2;
Base* ptr= &d1;
ptr->function1(); // Call D1::function1()
ptr = &d2;
ptr->function1(); // Call Base::function1()
```

很明显，相对于一般成员函数，虚函数效率是较低的。使用虚函数不仅增加了一次指针查找，还需要跳转到虚表，有cache-miss的可能性，还不能作内联函数，很多其他的优化也不能使用在虚函数上，如果虚函数有很多实现方式，分支预测的成功率还会降低。

尽管如此，虚函数的开销仍然是可以忽略的。
