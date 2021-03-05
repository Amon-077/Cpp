##### Leetcode 232 用栈实现队列

- 题目

这是一道`简单`题，要求使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（`push`、`pop`、`peek`、`empty`）：

实现 `MyQueue` 类：

`void push(int x)` 将元素 x 推到队列的末尾

`int pop()` 从队列的开头移除并返回元素

`int peek()` 返回队列开头的元素

`boolean empty()` 如果队列为空，返回 true ；否则，返回 false

- 思路

队列是First in First out，然而栈是First in Last out，怎么样才能保持插入元素后数据顺序有序，怎么样才能弹出开头元素？

后一个问题比较好解决，假设一开始数据有序地插入到了栈1，循环地取出栈1的栈顶元素保存在栈2中直到栈1取尽（栈1.empty()为真），最后弹出并返回栈2的栈顶元素，可以实现FIFO。

前一个问题则是要将栈2的元素全部插入到栈1再插入新加入的元素。

peek()的实现几乎与pop()相同。

代码如下。

```c++
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int temp=stk2.top();
        stk2.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        return stk2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (stk1.empty()&&stk2.empty());
    }
private:
    stack<int> stk1,stk2;
};
```

