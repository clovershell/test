/*
    container_of - 从结构体成员指针获取结构体指针
    @ptr: 结构体成员指针
    @type: 结构体类型
    @member: 结构体成员名
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stddef.h>

#define offsetof(type, member) ((size_t) &((type *)0)->member)
#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})


#define container_of2(ptr, type, mem) ((type *)((char *)ptr - ((size_t)&(((type*)0)->mem))))

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next) {
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head) {
    __list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    __list_add(new, head->prev, head);
}

static inline void __list_del(struct list_head *prev, struct list_head *next) {
    next->prev = prev;
    prev->next = next;
}

static inline void list_del(struct list_head *entry) {
    __list_del(entry->prev, entry->next);
    entry->next = NULL;
    entry->prev = NULL;
}

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}


struct student {
    int id ; // id对齐到4字节边界
    char name[10] ; // 姓名对齐到4字节边界
    int age ; // 年龄对齐到4字节边界
};


// 链表
struct task{
    int pid;// 进程id
    char name[32];
    
    struct list_head list; // 链表节点
};

int main()
{
    struct student stu = {1001, "zhangsan", 18};

    int *p_a = &stu.age;
    printf("p_a = %p\n", p_a);

    struct student *p_stu = container_of(p_a, struct student, age);
    struct student *p_stu2 = container_of2(p_a, struct student, age);

    printf("结构体student的地址 = %p\n", &stu);
    printf("反推的首地址 = %p\n", p_stu);
    printf("反推的id地址 = %p\n", &p_stu->id);
    printf("反推的name地址 = %p\n", &p_stu->name);
    printf("反推的age地址 = %p\n", &p_stu->age);

    printf("反推的首地址2 = %p\n", p_stu2);

     
    printf("id = %d\n", p_stu->id);
    printf("name = %s\n", p_stu->name);
    printf("age = %d\n", p_stu->age);



    struct task task1 = {1001, "zhangsan", {NULL, NULL}};

    struct list_head *p_list = &task1.list;
    struct task *p_task = container_of(p_list, struct task, list);
    printf("pid = %d\n", p_task->pid);
    printf("name = %s\n", p_task->name);

    struct list_head head;
    INIT_LIST_HEAD(&head);
    struct task a = {1, "a"};
    struct task b = {2, "b"};
    struct task c = {3, "c"};
    list_add_tail(&a.list, &head);
    list_add_tail(&b.list, &head);
    list_add_tail(&c.list, &head);
    struct list_head *pos;
    for (pos = head.next; pos != &head; pos = pos->next) {
        struct task *t = container_of(pos, struct task, list);
        printf("F %d %s\n", t->pid, t->name);
    }
    for (pos = head.prev; pos != &head; pos = pos->prev) {
        struct task *t = container_of(pos, struct task, list);
        printf("B %d %s\n", t->pid, t->name);
    }
    list_del(&b.list);
    for (pos = head.next; pos != &head; pos = pos->next) {
        struct task *t = container_of(pos, struct task, list);
        printf("D %d %s\n", t->pid, t->name);
    }
    list_add(&b.list, &head);
    for (pos = head.next; pos != &head; pos = pos->next) {
        struct task *t = container_of(pos, struct task, list);
        printf("H %d %s\n", t->pid, t->name);
    }
    printf("E %d\n", list_empty(&head));
    list_del(&a.list);
    list_del(&b.list);
    list_del(&c.list);
    printf("E %d\n", list_empty(&head));

    return 0;
}

 
