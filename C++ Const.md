C++ Const



`const` 关键词对初学者来说并不是一个很轻易能掌握的知识点。

`const` 的含义：除了初始化时，不能更改`const`变量的值。编译器会确保这一点。

预测以下例子，程序运行的结果是什么？

```c++
#include <iostream> 
using namespace std; 
class Point 
{ 
private:
    int x, y; 
public: 
    Point(int i = 0, int j = 0) 
    {
        x = i; y = j; 
    } 
    int getX() const 
    { 
        return x; 
    } 
    int getY() 
    {
        return y;
    } 
}; 

int main() 
{ 
	const Point p; 
	cout << p.getX() << " "; 
	cout << p.getY() << endl;
	return 0; 
} 
```

结果是报错：`“int Point::getY(void)”: 不能将“this”指针从“const Point”转换为“Point &”`。

为什么？因为`const`对象只能调用`const`函数。

`const`修饰成员函数是用来做什么？当我们不想修改参数并将其作为引用或指针传递时，我们可以使用`const`限定符，使得参数不会意外地被修改。



除了类的成员函数和一般变量，`const `还能用来修饰什么？

函数参数，变量的引用，

```c++
// ref is a const reference to the argument passed in, not a copy
void changeN(const int& ref)
{
	ref = 6; // not allowed, ref is const
}
```

以及类的数据成员（包括静态成员）。

```c++
const static int foo = 42;
```



再看一段代码：

```c++
#include <iostream> 
using namespace std; 
int main() 
{ 
	const char* p = "12345"; 
	const char**q = &p; 
	*q = "abcde"; 
	const char *s = ++p; 
	p = "XYZWVU"; 
	cout << *++s; 
	return 0; 
} 
```

const char * p = “12345”声明一个指向常量的指针。因此，我们无法为* p分配其他内容，但可以为p分配新值。也就是说，我们不能通过*p来修改赋给它的内容，但能让p指向其他值。

```c++
const char* p = "12345"; // ptr to char
//*p = '2'; illegal, assignment of read-only location *p
p = "XYZWVU"; // works, the ptr changes
```



##### `const T *`p, `T * const` p and `const T * const` p 之间的不同



当 `const` 与 `int` , `char` 等类按不同次序排列，意义不是固定的，这很容易导致迷惑的错误。

限定符const可以应用于任何变量的声明，以指定其值不会被更改。



`const T *` p：这是指向常量字符的指针。您不能更改ptr所指向的值，但是可以更改指针本身 [参见上方const char* p: **“const char *”是指向const char的（非const）指针。**]

**注意**：`const T * p` 和 `T const * p`之间没有区别，因为它们都是指向`const T`的指针，并且`*`的位置也相同。



`T * const` p：这是指向非恒定字符的恒定指针。您不能更改指针p，但可以更改ptr指向的值。

```c++
char a = 'a', b = 'b';
char* const p = &a; // const ptr to char
*p = 'k'; // works
p = &b; // illegal statement
```



`const T* const` p：这是指向常量字符的常量指针。您既不能更改ptr所指向的值，也不能更改指针ptr。

```C++
char a ='A', b ='B'; 
const char *const ptr = &a; 
      
printf( "Value pointed to by ptr: %c\n", *ptr); 
printf( "Address ptr is pointing to: %d\n\n", ptr); 
  
// ptr = &b; illegal statement (assignment of read-only variable ptr) 
// *ptr = b; illegal statement (assignment of read-only location *ptr)
```
