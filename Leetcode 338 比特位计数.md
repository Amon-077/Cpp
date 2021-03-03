##### Leetcode 338 比特位计数

- 题目

给定一个非负整数 **num**。对于 **0 ≤ i ≤ num** 范围中的每个数字 **i** ，计算其二进制数中的 1 的数目并将它们作为数组返回。

- 思路

从**1**开始计算至**num**，当前数的二进制表示中**1**的数目等于当前数右移一位后**1**的数目加上当前数最后一位与1的与运算结果。

即 'solution[i] = solution[i >> 1] + i & 1'

值得注意的一点是，&的优先级较低，在C++代码中要在 'i & 1' 两边加上 '()'，否则实际运行的代码相当于：

```c++
solution[i] = (solution[i >> 1] + i) & 1;
```

代码如下：

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> solution(num + 1);
        for (int i = 1; i <= num; i++) {
            solution[i] = solution[i >> 1] + (i & 1);
        }
        return solution;
    }
};
```

