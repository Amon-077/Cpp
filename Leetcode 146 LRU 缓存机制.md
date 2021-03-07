##### Leetcode 146 LRU 缓存机制

- 题目

运用你所掌握的数据结构，设计和实现一个  `LRU (最近最少使用) 缓存机制` 。
实现 `LRUCache` 类：

- `LRUCache(int capacity)` 以正整数作为容量 `capacity` 初始化 LRU 缓存。
- `int get(int key)` 如果关键字 `key` 存在于缓存中，则返回关键字的值，否则返回 -1 。
- `void put(int key, int value)` 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前**删除最久未使用的数据值**，从而为新的数据值留出空间。



- 思路

什么是LRU?

`A Least Recently Used (LRU) Cache organizes items in order of use, allowing you to quickly identify which item hasn't been used for the longest amount of time.`

`Under the hood, an LRU cache is often implemented by pairing [a doubly linked list] with [a hash map].`

## Costs

|                              | Worst Case |
| :--------------------------- | :--------- |
| space                        | *O*(*n*)   |
| get least recently used item | *O*(1)     |
| access item                  | *O*(1)     |



梳理一下这个LRU Cache要满足的条件？

1. 它的存储上限在一开始被输入，值为`capacity`；
2. 键值查询与存储，可以用`unordered_map`存储键值对，再单独对键维护一个`表示最近使用时间`的数据结构；
3. 输入键值对，先在`unordered_map`中寻找键，找到后修改键对应值，没有找到就检查是否达到存储上限，如果达到就在近期使用数据结构中找到最不常用的键值对去除它（还要去掉它在`unordered_map`中的存储），如果没有达到，直接将数据添加至两个数据结构中。



对键专门维护的`表示最近使用时间`的数据结构用什么比较好？

考虑使用deque，即双端队列，每一次用到键或插入数据，就将键从当前位置取出放到队列头，当要删除最不常用数据时选择队列最后的键。



代码如下。

```C++
class LRUCache {
public:
    LRUCache(int capacity) {
        cache_space=capacity;
    }
    
    inline void Refresh(int key)
    {
        deque<int>::iterator it=lru_deque.begin();
        while(*it!=key) it++;
        lru_deque.erase(it);
        lru_deque.push_front(key);
    }
    
    inline void PushNewKey(int key, int value)
    {
        int temp=lru_deque.back();
        lru_deque.pop_back();
        lru_map.erase(temp);
        lru_map[key]=value;
        lru_deque.push_front(key);
    }
    
    int get(int key) {
        if(!lru_map.count(key)) return -1;

        Refresh(key);
        return lru_map[key];
    }
    
    void put(int key, int value) {
        if(lru_map.count(key))
        {
            lru_map[key]=value;
            Refresh(key);
        }
        else if(curr_space==cache_space)
        {
            PushNewKey(key, value);
        }
        else
        {
            curr_space++;
            lru_map[key]=value;
            lru_deque.push_front(key);
        }
    }
private:
    int cache_space;
    int curr_space=0;
    deque<int> lru_deque;
    unordered_map<int,int> lru_map;
};
```

`LRU`是一种缓存文件置换机制，其他缓存文件置换方法还有：

`先进先出算法（FIFO）`：最先进入的内容作为替换对象，具体实现的数据结构是队列(queue)；

`最近最少使用算法（LFU）`：最近最少使用的内容作为替换对象，此方法的标准特征涉及系统跟踪内存中引用块的次数。当缓存已满并且需要更多空间时，系统将以最低参考频率清除项目。

`非最近使用算法（NMRU）`：在最近没有使用的内容中随机选择一个作为替换对象。
