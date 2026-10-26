#include <globaldefs.h>

struct Struct_0209a104_2 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    unsigned short f8;
    unsigned short fa;
};

extern "C" void func_0209a530(struct Struct_0209a104_2* dst, struct Struct_0209a104_2* src);

struct Struct_0209a4f0 {
    struct Struct_0209a104_2* items;
    int count;
};

// USA: func_0209a4f0
extern "C" ARM void func_0209a4f0(struct Struct_0209a4f0* list, struct Struct_0209a104_2* src) {
    struct Struct_0209a104_2* items;
    int count;
    items = list->items;
    if (items == NULL) return;
    count = list->count;
    if (count >= 0x11f) return;
    list->count = count + 1;
    func_0209a530(&list->items[count], src);
}
