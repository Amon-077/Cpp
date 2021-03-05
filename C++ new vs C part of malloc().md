#### C++ new vs C part of malloc()

**Following are the differences between malloc() and operator new.**: 

**Calling Constructors:** new calls constructors, while malloc() does not. In fact primitive data types (char, int, float.. etc) can also be initialized with new. The `new` keyword ensures that your type will have its **constructor called**, so it's more **type-safe** whereas `malloc` is not type-safe at all.



**operator vs function:** new is an operator, while malloc() is a function.



**return type:** new returns exact data type, while malloc() returns void *, so you are required to cast the return from `void*`. 

```c++
#include <cstdlib>

class p {
  int a[10];
}; 

int main() {
  p *f1 = malloc(1); // error, no cast
  p *f2 = static_cast<p*>(malloc(sizeof(p)));
}
```



**Failure Condition:** On failure, malloc() returns NULL where as new throws `bad_alloc` exception.



**Memory:** In case of new, memory is allocated from `free store` where as in malloc() memory allocation is done from `heap`.

[^Free store]: The free store is one of the two dynamic memory areas, allocated/freed by new/delete. Object lifetime can be less than the time the storage is allocated; that is, free store objects can have memory allocated without being immediately initialized, and can be destroyed without the memory being immediately deallocated. During the period when the storage is allocated but outside the object's lifetime, the storage may be accessed and manipulated through a void* but none of the proto-object's nonstatic members or member functions may be accessed, have their addresses taken, or be otherwise manipulated.
[^Heap]: The heap is the other dynamic memory area, allocated/freed by malloc/free and their variants. Note that while the default global new and delete might be implemented in terms of malloc and free by a particular compiler, the heap is not the same as free store and memory allocated in one area cannot be safely deallocated in the other. Memory allocated from the heap can be used for objects of class type by placement-new construction and explicit destruction. If so used, the notes about free store object lifetime apply similarly here.

> In practice, however, they are almost always the same region of memory -- in most cases if you dig into the compiler's implementation of `new`, you'll find it calls `malloc()`.
>
> In other words: from the machine's point of view, heap and free store are the same thing. The distinction exists inside the compiler.
>
> To make things even more confusing, before the advent of C++ we said "heap" to mean what is now called "free store."



**Size:** Required size of memory is calculated by compiler for new, where as we have to manually calculate size for malloc().



```c++
char *str;
/* C style of memory allocation */
str = (char *) malloc(20);
strcpy(str, "memory allocation");

/* C++ style of memory allocation */
string* str_cpp = new string("memory allocation");
```



**Buffer Size:** malloc() allows to change the size of buffer using realloc() while new doesn’t.

| new                            | malloc                      |
| :----------------------------- | :-------------------------- |
| calls constructor              | does not calls constructors |
| It is an operator              | It is a function            |
| Returns exact data type        | Returns void *              |
| on failure, Throws             | On failure, returns NULL    |
| size is calculated by compiler | size is calculated manually |



Unless you have to use C, you should **never use** `malloc`. Always use `new`.

The only way that would be beneficial to use `malloc` would be if you needed to **change the size of your buffer** of data. The `new` keyword does not have an analogous way like `realloc`. The `realloc` function might be able to extend the size of a chunk of memory for you more efficiently.