C++ 生成真随机数

可以使用srand()和rand()生成随机数，

```c++
#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std; 

int main()
{ 
        srand((unsigned)time(NULL)); 
        for(int i = 0; i < 10;i++ ) 
                cout << rand() << " ";
        cout << endl; 
        return 0;
}
```

但在这两种情况下，根据系统时钟的当前时间被用作种子。
请注意，如果种子相同，rand()将创建相同的随机数。
因此，如果两个不同的用户同时运行我的应用程序，那么他们将拥有相同的随机数。
如何创建不基于系统时间的随机种子？

> 如果不使用特殊的硬件(即使那样，这也是有争议的)，就没有真正的随机数是由计算机产生的。
>
> 使用当前时间作为种子的一部分是合理的，但这还不够，因为两个程序可以同时生成它们的种子。
>
> 所以你可以加入进程ID、硬件MAC地址等尽量令生成数独一无二。

> 可以使用哈希函数，
>
> ```c++
> unsigned int hash3(unsigned int h1, unsigned int h2, unsigned int h3)
> {
>     return ((h1 * 2654435789U) + h2) * 2654435789U) + h3;
> };
> struct timeval;
> gettimeofday(&time, NULL);
> srand(hash3(time.tv_sec, time.tv_usec, getpid()));
> ```

https://stackoverflow.com/questions/12662810/generating-truly-random-numbers
