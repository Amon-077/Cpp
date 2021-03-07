C++ 内存管理

C++ 允许我们在运行时分配变量或数组的内存。这称为动态内存分配。

在其他编程语言（例如Java和Python）中，编译器自动管理分配给变量的内存。但C++ 不是这样的情况。

C++ 需要我们手动管理动态分配的内存，在变量不再使用后回收它。



动态分配的内存在内存的哪个区域呢？

通常，一个进程分配了5个不同的内存区域：代码段、初始化的数据 - data段、未初始化的数据 – bss段、堆和栈。

[^BSS]: BSS 的意思是 ‘Block Started by Symbol’，它包含未初始化的全局和静态变量。

下面列出了一部分可执行文件的通用部分的名称与描述（根据编译器/链接器的不同，它们的名称可能不同）

| **Section** | **Description**                                              |
| ----------- | ------------------------------------------------------------ |
| .text       | This section contains the executable instruction codes and is shared among every process running the same binary. This section usually has READ and EXECUTE permissions only. This section is the one most affected by optimization. |
| .bss        | BSS stands for ‘Block Started by Symbol’. It holds un-initialized **global and static variables**. Since the BSS only holds variables that don't have any values yet, it doesn't actually need to store the image of these variables. The size that BSS will require at runtime is recorded in the object file, but the BSS (unlike the data section) doesn't take up any actual space in the object file. |
| .data       | Contains the initialized **global and static variables and their values**. It is usually the largest part of the executable. It usually has READ/WRITE permissions. |
| .rdata      | Also known as .rodata (**read-only** data) section. This contains constants and string literals. |



C++ 中，由new分配的内存块放在”堆“上，释放由我们控制，一般一个`new`要对应一个 `delete`。如果程序员没有释放掉，那么在程序结束后，操作系统会自动回收。

请注意，名称堆与堆数据结构无关。之所以称其为堆，是因为它是一堆可供程序员分配和取消分配的内存空间。



data段与bss段有时被合称为全局/静态存储区。



栈中的数据分配发生在函数调用栈中，编译器知道分配的内存大小，每当调用函数时，其变量就会在栈上得到分配的内存。每当函数调用结束时，变量的内存就会被释放。所有这些都使用编译器中的一些预定义例程进行。程序员不必担心堆中变量内存的分配和释放。

这种内存分配也称为临时内存分配，因为一旦函数执行完毕，该函数所属的所有数据就会自动从栈中清除。



read-only data section也被称作常量存储区，存放着不允许被修改的常量。