#include<iostream>
using namespace std;
/*template:
* A template parameter is a special kind of parameter 
* that can be used to pass a type as argument.
* These function templates can use these parameters as if they were any other regular type.
*/
template <class random_name>
random_name random_function(random_name a){}//definition
unsigned int random_function(unsigned int a); //explicit instantiation
template<> int random_function(int a) { return a; } //specialization
/*If we want to define a different implementation for a template 
* when a specific type is passed as template parameter, 
* we can declare a specialization of that template.
*/
template <class name> class mycontainer {};
template <> class mycontainer <char> {};

//Non-type parameters for templates
//class template that is used to contain sequences of elements
template <class T, int N>
class mysequence {
    T memblock[N];
public:
    void setmember(int x, T value);
    T getmember(int x);
};

template <class T, int N>
void mysequence<T, N>::setmember(int x, T value) {
    memblock[x] = value;
}

template <class T, int N>
T mysequence<T, N>::getmember(int x) {
    return memblock[x];
}

//It is also possible to set default values or types for class template parameters.
template <unsigned int random_int = 10>
unsigned int random_func(){
    return random_int;
}

int main(int args, char** argv)
{
    cout<<random_func()<<endl;
    cout << sizeof(mycontainer<int>) << " " << sizeof(mycontainer<long>) <<endl;
	return 0;
}
