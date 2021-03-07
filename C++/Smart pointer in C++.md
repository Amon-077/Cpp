#### C++ Smart pointer

##### auto_ptr, unique_ptr, shared_ptr and weak_ptr

In modern C++ programming, the Standard Library includes smart pointers, which are used to help ensure that programs are free of memory and resource leaks and are exception-safe.  -- from microsoft docs

Smart pointers are defined in the std namespace in the <memory> header file.

```c++
void UseRawPointer()
{
    // Using a raw pointer -- not recommended.
    Song* pSong = new Song(L"Nothing on You", L"Bruno Mars"); 

    // Use pSong...
    
    // Don't forget to delete!
    delete pSong;   

}


void UseSmartPointer()
{
    // Declare a smart pointer on stack and pass it the raw pointer.
    unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));

    // Use song2...
    wstring s = song2->duration_;
    //...

} // song2 is deleted automatically here.
```



##### auto_ptr

Auto_ptr is a deprecated class template. Unique_ptr is a similar facility with better security.

An object when described using auto_ptr class it stores a pointer to a single allocated object which ensures that when it goes out of scope, the object it points to must get automatically destroyed.

##### Usage

```c++
// C++ program to illustrate the use of auto_ptr 
#include <iostream> 
#include <memory> 
using namespace std; 

class A { 
public: 
	void show() { cout << "A::show()" << endl; } 
}; 

int main() 
{ 
	// p1 is an auto_ptr of type A 
	auto_ptr<A> p1(new A); 
	p1->show(); 

	// returns the memory address of p1 
	cout << p1.get() << endl; 

	// copy constructor called, this makes p1 empty. 
	auto_ptr<A> p2(p1); 
	p2->show(); 

	// p1 is empty now 
	cout << p1.get() << endl; 

	// p1 gets copied in p2 
	cout << p2.get() << endl; 

	return 0; 
} 
/*
Output:

A::show()
0x1b42c20
A::show()
0          
0x1b42c20
*/
```

An object when described using auto_ptr class it stores a pointer to a single allocated object which ensures that when it goes out of scope, the object it points to must get automatically destroyed. It is based on **exclusive ownership model** i.e. two pointers of the same type can’t point to the same resource at the same time.



##### unique_ptr

std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr.

unique_ptr explicitly prevents copying of its contained pointer, as it allows exactly one owner of the underlying pointer.

```C++
unique_ptr<A> ptr1(new A);

// Error: can't copy unique_ptr
// unique_ptr<A> ptr2(ptr1);
unique_ptr<A> ptr2 = ptr1;
```

But unique_ptr can be moved using move() function.

```c++
// Resource now stored in ptr2
unique_ptr<A> ptr2 = move(ptr1); 
```



##### shared_ptr

unique_ptr doesn't share its pointer while shared_ptr does. It's designed for scenarios in which multiple owners manage the lifetime of the object in memory.

```c++
shared_ptr<A> p1(new A); 
//It works. Resource now stored in both p1 and p2.
shared_ptr<A> p2(p1); 

// Returns the number of shared_ptr objects 
// referring to the same managed object. 
// In this case, the output is 2.
cout << p1.use_count() << endl; 
cout << p2.use_count() << endl; 

// Relinquishes ownership of p1 on the object 
// and pointer becomes NULL 
p1.reset(); 

cout << p1.get() << endl; 
// In this case, the output is 1.
cout << p2.use_count() << endl; 
cout << p2.get() << endl; 
```



##### weak_ptr

A weak_ptr is created as a copy of shared_ptr. It provides access to an object that is owned by one or more shared_ptr instances but does not participate in reference counting.

The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies.



**Reference:**

https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-160

https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/
