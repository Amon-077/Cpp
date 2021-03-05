##### Leetcode 372 超级次方

题目：你的任务是计算 `ab` 对 `1337` 取模，`a` 是一个正整数，`b` 是一个非常大的正整数且会以数组形式给出。

思路：

观察题目，发现给出的默认函数，底数为a，指数按位存储在<int>向量中。

```c++
int superPow(int a, vector<int>& b) {

}
```

由于指数很大，底数也很大，考虑使用分治法。那么怎么处理指数？怎么处理底数？

对于指数来说，每一次取最后一位与底数求得幂后，将最后一位弹出(调用std::vector::pop_back())；

对于底数来说，由于`(i*k + j)^b % k = j^b % k`，所以计算开始前可以进行取模减小运算量，这样做能防止计算结果超出<int>上限。

在提交答案前也需要一次取模。


调整了代码字符间距。

```c++
class Solution {
public:
    int a_pow(int a, int b) {
        a %= 1337;
        int res = a;
        if (b == 1) return res;
        if (a == 1 || b == 0) return 1;
        for (int i = 0; i < b - 1; i++)
            res = (res * a) % 1337;
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        a %= 1337;
        int result = a;
        while (!b.empty())
        {
            int temp = a_pow(a, b.back());
            b.pop_back();
            result = (temp * a_pow(superPow(a, b), 10)) % 1337;
        }
        return result;
    }
};
```

