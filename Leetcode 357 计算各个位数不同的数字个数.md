Leetcode 357 计算各个位数不同的数字个数

tag: `回溯法`

- 题目

给定一个**非负**整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。

- 思路

很容易想到的一点，数字的位数一旦大于10，各位数字不可能都不同，因为一位数只有10个。

所以当n＞10，其结果与n＝10的输出应是一样的。

考虑一下，如果n＝k，那么它的输出和n＝k - 1的输出会有什么样的关系？在这里假设n＝k的输出为f(k)。

很显然，f(k) = f(k - 1) + k位数各位数不同的答案。后者是个简单的数学问题。

```c++
class Solution {
public:
    int diff_k(int k)
    {
        int temp = 9;
        if(k==1) return 10;
        else
            while(--k)
                temp*=(10-k);
        
        return temp;
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> f(11);
        if(n==0) return 1;
        if(n>10) return countNumbersWithUniqueDigits(10);
        for(int i=1;i<=n;i++)
            f[i]=f[i-1]+diff_k(i);
        return f[n];
    }
};
```

