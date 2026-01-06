/*
    _Generic - 泛型选择器
    @x: 表达式
    @type: 类型列表

    c11的泛型选择器可以根据表达式的类型选择不同的函数实现。(伪重载)
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_int(int i) {printf("%d\n", i);}
void print_str(char *str) {printf("%s\n", str);}
void print_float(float f) {printf("%f\n", f);}
void print_double(double d) {printf("%lf\n", d);}

#define print(x) _Generic((x), \
    int: print_int, \
    char *: print_str, \
    float: print_float, \
    double: print_double \
)(x)

int add_int(int a, int b) {return a + b;}
float add_float(float a, float b) {return a + b;}
double add_double(double a, double b) {return a + b;}
char *add_str(const char *a, const char *b) {
    size_t la = strlen(a), lb = strlen(b);
    char *s = (char *)malloc(la + lb + 1);
    if (!s) return NULL;
    memcpy(s, a, la);
    memcpy(s + la, b, lb);
    s[la + lb] = '\0';
    return s;
}

#define add2(x, y) _Generic((x), \
    int: add_int, \
    char *: add_str, \
    float: add_float, \
    double: add_double \
)(x, y)




int main()
{
    int i = 1001;
    char *str = "zhangsan";
    float f = 1.234f;
    double d = 1.23456789;

    print(i);
    print(str);
    print(f);
    print(d);


    print(add2(i, 100));
    print(add2(f, 1.234f));
    print(add2(d, 1.23456789));
    char *s = add2(str, "lisi");
    print(s);
    free(s);

    return 0;
}
