#include <globaldefs.h>

struct Struct_020974b0_2 {
    struct Struct_020974b0_2* next;
    char pad[0xe];
    signed char unknown_12_;
    unsigned char bit0 : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char rest : 6;
    unsigned char* data;
    unsigned char len;
    char pad2[0x20 - 0x19];
};

struct Struct_020974b0 {
    struct Struct_020974b0_2* head;
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Struct_020974b0_2* arr;
};

extern "C" void func_02097628(void*);
extern "C" void func_020976e0(void*);
extern "C" void func_02097844(struct Struct_020974b0_2**, int);

extern "C" {
// USA: func_020974b0
extern "C" ARM struct Struct_020974b0_2* func_020974b0(struct Struct_020974b0* list, int arg1, int target, bool arg3, short arg4, short* outCount) {
    unsigned short n = list->count;
    struct Struct_020974b0_2* arr = list->arr;
    list->head = NULL;
    short i1;
    for (i1 = 0; i1 < n; i1++) {
        struct Struct_020974b0_2* f = &arr[i1];
        f->next = NULL;
        f->bit0 = 1;
    }
    if (arg1 >= 0) {
        short i2;
        for (i2 = 0; i2 < n; i2++) {
            struct Struct_020974b0_2* e = &arr[i2];
            e->bit0 = (e->unknown_12_ == arg1);
        }
    }
    if (target >= 0) {
        unsigned char t = target;
        short var7;
        for (var7 = 0; var7 < n; var7++) {
            struct Struct_020974b0_2* e = &arr[var7];
            e->bit0 = 0;
            unsigned char j;
            for (j = 0; j < e->len; j++) {
                if (e->data[j] == t) {
                    e->bit0 = 1;
                    break;
                }
            }
        }
    }
    if (!arg3) {
        func_02097628(list);
    } else {
        func_020976e0(list);
    }
    *outCount = 0;
    struct Struct_020974b0_2* p = list->head;
    while (p != NULL) {
        (*outCount)++;
        p = p->next;
    }
    func_02097844((struct Struct_020974b0_2**)&list->head, arg4);
    return list->head;
}
}
