#include <globaldefs.h>

struct Struct_02046b8c_2 {
    signed char id;
    char pad[3];
    struct Struct_02046b8c_2* next;
};

struct Struct_02046b8c {
    struct Struct_02046b8c_2* head;
    struct Struct_02046b8c_2* tail;
};

// USA: func_02046b8c
extern "C" ARM void func_02046b8c(struct Struct_02046b8c* list, int id) {
    struct Struct_02046b8c_2* prev;
    struct Struct_02046b8c_2* var1;
    struct Struct_02046b8c_2* p = list->head;
    struct Struct_02046b8c_2* t = p;
    while (t != 0) {
        t = t->next;
    }
    prev = 0;
    var1 = 0;
    while (p != 0) {
        struct Struct_02046b8c_2* next = p->next;
        if (p->id == id) {
            if (prev != 0) {
                prev->next = next;
            } else {
                list->head = next;
            }
            p->next = 0;
            if (var1 != 0) {
                struct Struct_02046b8c_2* q = var1;
                struct Struct_02046b8c_2* n;
                while ((n = q->next) != 0) {
                    q = n;
                }
                q->next = p;
            } else {
                var1 = p;
            }
        } else {
            prev = p;
        }
        p = next;
    }
    if (var1 != 0) {
        t = var1;
        while (t->next != 0) {
            t = t->next;
        }
        struct Struct_02046b8c_2* h = list->head;
        t->next = h;
        list->head = var1;
        t = var1;
        while (t->next != 0) {
            t = t->next;
        }
        list->tail = t;
        t = list->head;
        while (t != 0) {
            t = t->next;
        }
    }
}