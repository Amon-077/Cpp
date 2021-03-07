##### RAII, Resource Acquisition Is Initialization.

汉语：资源获取即初始化。

Make sure that objects are initialized before they're used. C part of C++ doesn't make sure that while STL part of C++ does.

It is worth noting that assignment and initialization are different concepts.



```c++
class Person{
public:
    Person(const std::string name, const std::string phoneNumber, const int age);
private:
    std::string theName;
    std::string thePhoneNumber;
    int theAge;
}
Person::Person(const std::string name, const std::string phoneNumber, const int age)
{
    // These are assignment.
    theName = name;
    thePhoneNumber = phoneNumber;
    theAge = age;
}
```

```C++
Person::Person(const std::string name, const std::string phoneNumber, const int age)
    :theName(name), thePhoneNumber(phoneNumber), theAge(age)
{}
    // Using member initialization list, it's initialization.
```



In RAII, holding a resource is a class invariant, and is tied to object lifetime: resource allocation (or acquisition) is done during object creation (specifically initialization), by the constructor, while resource deallocation (release) is done during object destruction (specifically finalization), by the destructor.



The following example is a wrapper class demonstrating usage of RAII. Note that it lacks copy-constructor and copy-assignment operator.

```c++
class string_ptr_wrapper
{
public:
    string_ptr_wrapper(string value = "") :
    pString(new string(value)) // initialization
    {}

    ~string_ptr_wrapper()
    {
        delete pString;
    }    
private:
    String* pString;
};
```



The advantages of RAII as a resource management technique are that it provides encapsulation, exception safety (for stack resources), and locality (it allows acquisition and release logic to be written next to each other).



https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization
