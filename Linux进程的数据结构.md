#### Linux进程的数据结构(C)

​	在Linux中，进程用task_struct表示，源文件见[`include/linux/sched.h`]。

​	所有进程被组织到以`init_task`为表头的双向链表中，该链表是全系统唯一的。

​	系统维护一个名为task的数组，task包含指向系统所有进程的task_struct结构的指针。当前运行进程的结构用current指针指示。

​	每个用户进程都有至少一个线程，因此每个进程都映射到一个或多个`task_struct`。

​	更具体地说，一个进程是一个或多个`task`，它们共享某些资源-文件描述符，地址空间/内存映射，信号处理，进程和进程组ID等。

task_struct: https://github.com/torvalds/linux/blob/master/include/linux/sched.h



该文件有：

- task_struct成员预声明（按字母顺序排列）；

- task状态位掩码，设置了表示状态信息的标志集合。例如，

```c++
/* Used in tsk->state: */
#define TASK_RUNNING			0x0000

/* Used in tsk->exit_state: */
#define EXIT_DEAD			    0x0010
#define EXIT_ZOMBIE			  0x0020
```

- task_struct定义

……

###### Linux中task_struct的信息可分为8类:

> 标识号: 进程标识号\用户标识号\组标识号
> 状态信息: 运行、等待、停止、僵死
> 调度信息: 策略、优先级、实时优先级、计数器
> 有关进程间通信的信息
> 进程链信息: 父进程指针、兄弟进程指针、子进程
> 时间和定时器: 进程的建立时间、使用的CPU时间
> 文件系统信息: 进程打开文件的描述符信息等
> 进程上下文信息: 进程的运行环境信息，包括寄存器的值以及堆栈信息



##### LINUX examples

1. 在LINUX系统中用户键入一个命令（如date, ls )，shell就创建一个进程； 
2. 用户程序可使用fork()系统调用创建多个进程，每个进程执行一个程序段；
3. 在fork()后 ,exec()系统调用用一个新进程替代旧进程。

fork(): https://en.wikipedia.org/wiki/Fork_(system_call)

exec(): https://en.wikipedia.org/wiki/Exec_(system_call)

