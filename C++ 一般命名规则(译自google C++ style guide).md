C++ 一般命名规则 (译自google C++ style guide)

- 使用清晰的命名来优化可读性，使得即使是来自不同团队的人也能轻易理解它。

  > 使用描述对象目的或意图的名称。
  >
  > 不必为节约水平空间而担忧，因为让新读者立即理解您的代码更为重要。
  >
  > 尽量减少项目外人员可能不知道的缩写（尤其是首字母缩写词和首字母缩写）的使用。
  >
  > 请勿通过删除单词中的字母来缩写。（如果在Wikipedia中有缩写，则可以。）
  >
  > 一般来说，描述性应与名称的可见性范围成正比。例如，`n`在短短几行的函数中可能是一个好名字，但在类的范围内，它可能太含糊了。
  >
  > 请注意，某些通用的缩写是可以的，例如`i`表示迭代变量，`T`表示模板参数。



- 文件名应全部小写，并可以包含下划线（_）或破折号（-）。请遵循项目使用的约定。如果没有一致的局部模式，请选择“ _”。通常地，要使文件名非常具体。例如，使用`http_server_logs.h`而不是`logs.h`。



- 类型名称以大写字母开头，每个新单词都有一个大写字母，没有下划线：`MyExcitingClass`，`MyExcitingEnum`。所有类型的名称（类，结构，类型别名，枚举和类型模板参数）都有相同的命名约定。类型名称应以大写字母开头，并且每个新单词都有一个大写字母。没有下划线。例如：

  ```c++
  // classes and structs
  class UrlTable { ...
  class UrlTableTester { ...
  struct UrlTableProperties { ...
  
  // typedefs
  typedef hash_map<UrlTableProperties *, std::string> PropertiesMap;
  
  // using aliases
  using PropertiesMap = hash_map<UrlTableProperties *, std::string>;
  
  // enums
  enum class UrlTableError { ...
  ```



- 变量（包括函数参数）和数据成员的名称均为小写，并在单词之间加下划线。类（而不是结构）的数据成员还带有结尾的下划线。

  一些示例：`a_local_variable`, `a_struct_data_member`, `a_class_data_member_`.



- 常量，即声明为`constexpr`或`const`或其值在程序持续时间内固定的变量，命名前缀带"k"，后跟混合大小写。

  ```c++
  const int kDaysInAWeek = 7;
  const int kAndroid8_0_0 = 24;  // Android 8.0.0
  ```



- 函数命名应以大写字母开头，每个新单词都有一个大写字母，总体使用混合大小写。

  ```c++
  AddTableEntry()
  DeleteUrl()
  OpenFileOrDie()
  ```



- 命名空间的名称均为小写字母，单词之间用下划线分隔。

  > 请记住，禁止使用缩写名称的规则也适用于命名空间。命名空间中的代码很少需要提及命名空间名称，因此，通常不需要特意缩写。



- 宏。虽然通常不应使用宏，但是，如果绝对需要它们，则应使用大写字母和下划线来命名它们。

  ```c++
  #define ROUND(x) ...
  #define PI_ROUNDED 3.0
  ```



- 枚举器名称应该像常量一样命名。

  ```c++
  enum class UrlTableError {
    kOk = 0,
    kOutOfMemory,
    kMalformedInput,
  };
  ```



- ##### 总结：

  | 命名对象     | 命名方式                                              |
  | ------------ | ----------------------------------------------------- |
  | 文件         | 均为小写，并使用下划线（_）或破折号（-）              |
  | 类型         | 大写字母开头，每个新单词都有一个大写字母，没有下划线  |
  | 变量         | 均为小写，并使用下划线，类数据成员还有结尾下划线      |
  | 常量与枚举器 | 命名前缀带"k"，每个新单词都有一个大写字母，混合大小写 |
  | 函数         | 大写字母开头，每个新单词都有一个大写字母，混合大小写  |
  | 命名空间     | 均为小写字母，单词之间使用下划线                      |
  | 宏           | 均为大写，并使用下划线                                |
