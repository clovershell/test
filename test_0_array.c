/*
    柔性数组 - 结构体最后一个成员为数组，数组大小可以根据需要动态分配
    柔性数组的优势：
        1. 可以根据需要动态分配内存，避免了内存浪费
        2. 可以将数据和结构体放在一起，减少了内存访问次数
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Packet{
    int head;
    int len;
    char data[]; // 柔性数组
};

#define PACKET_MAX_LEN 1024

int main()
{
    struct Packet *p = (struct Packet *)malloc(sizeof(struct Packet) + PACKET_MAX_LEN);
    if (!p) return 1;
    p->head = 0x1234;
    p->len = PACKET_MAX_LEN;
    memcpy(p->data, "hello", p->len);
    printf("%d %d %s\n", p->head, p->len, p->data);
    // 结构体实际大小
    printf("%ld\n", sizeof(struct Packet) + p->len);

    free(p);
    return 0;
}
