/*
    定义一个颜色枚举类型，包含RED, GREEN, BLUE, YELLOW四种颜色。
    实现一个函数ColorToString，输入一个颜色枚举值，返回对应的颜色字符串。

    X-Macro 是一种宏定义的技巧，用于在编译时生成重复的代码。
    这里使用 X-Macro 定义颜色枚举类型和颜色字符串转换函数。
*/

#include <stdio.h>


#define COLOR_LIST \
    X(RED, 0)       \
    X(GREEN, 1)     \
    X(BLUE, 2)      \
    X(YELLOW, 3)

#define X(name, value) COLOR_##name = value,
enum COLOR {
    COLOR_LIST
};
#undef X

#define X(name, value) case COLOR_##name: return #name;
const char* ColorToString(enum COLOR color) {
    switch (color) {
        COLOR_LIST
        default: return "UNKNOWN";
    }
}


int main() {
    enum COLOR color = COLOR_RED;
    printf("%s\n", ColorToString(color));
    for (int i = 0; i < 4; i++) {
        printf("%s\n", ColorToString((enum COLOR)i));
    }
    return 0;
}