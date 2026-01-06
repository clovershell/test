# 模块测试功能概览

**test_container_of.c（指针反推 + 双向链表）**
- 成员反推：`container_of`与`container_of2`从成员指针反推出宿主结构体指针（`test_container_of.c:14-19`）
- 链表节点：`struct list_head`定义双向链表结构（`test_container_of.c:21-24`）
- 基础操作：`INIT_LIST_HEAD`、`list_add`、`list_add_tail`、`list_del`、`list_empty`（`test_container_of.c:26-59`）
- 测试点：
- 通过`age`反推`student`首地址与各字段（`test_container_of.c:81-99`）
- 通过`list_head*`反推`task`（`test_container_of.c:104-107`）
- 前向/后向遍历、删除节点、头插重连与判空（`test_container_of.c:117-140`）

**test_Generic.c（C11 _Generic 泛型分发）**
- 打印族：`print(x)`按表达式类型选择`print_int/print_str/print_float/print_double`（`test_Generic.c:15-25`）
- 加法族：`add2(x,y)`按首参类型选择`add_int/add_float/add_double/add_str`（`test_Generic.c:27-45`）
- 测试点：
- 分别对`int/float/double/char*`进行打印（`test_Generic.c:57-60`）
- 对不同类型进行加法；字符串返回新分配拼接结果并释放（`test_Generic.c:63-69`）

**test_0_array.c（柔性数组用法）**
- 结构体尾部柔性数组：`char data[]`用于承载变长数据（`test_0_array.c:12-16`）
- 测试点：
- 动态分配`sizeof(struct Packet)+N`（`test_0_array.c:22`）
- 写入数据、读取打印、计算实际占用大小（`test_0_array.c:24-30`）
- 释放内存（`test_0_array.c:31-32`）

**构建与运行**
- 自动编译：`make` 或并行 `make -j`
- 单个可执行为源文件同名，例如：`./test_container_of`、`./test_Generic`、`./test_0_array`
