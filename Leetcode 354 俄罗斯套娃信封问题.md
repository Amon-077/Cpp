Leetcode 354 俄罗斯套娃信封问题

- 题目

给定一些标记了宽度和高度的信封，宽度和高度以整数对形式` (w, h)` 出现。**当另一个信封的宽度和高度都比这个信封大的时候**，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

- 思路

这是一道难度`困难`的题目，看到这道题的第一反应就是用dp（动态规划），实际上题解用的也是dp，但写出的dp运行效率不高，时间复杂度为`O(n^2)`，有待优化。

首先，将信件按照其宽排序，这里用到了<algorithm>中的`sort()`。

随后，从第二封信开始计算（第一封信不需要计算），如果之前的信件可以装进这一封信件，那么计算：
$$
dp[k]=max(dp[k-i]+1,dp[k]),i=[0...k-1]且i∈N.
$$
此外，返回最大值用到了<algorithm>中的`max_element()`，注意此函数返回值是一个iterator。

代码如下。

```c++
bool compareVectorInt(vector<int> v1, vector<int> v2)
{
        return (v1[0]<v2[0]);
}
class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int envelopes_num=envelopes.size();

        if(envelopes_num==0) 
            return 0;
        
        sort(envelopes.begin(),envelopes.end(),compareVectorInt);
        
        vector<int> dp(envelopes_num,1);
        
        for(int i=0;i<envelopes_num;i++)
            for(int j=0;j<i;j++)
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                    dp[i]=max(dp[j]+1,dp[i]);
        
        return *max_element(dp.begin(),dp.end());
    }
};
```