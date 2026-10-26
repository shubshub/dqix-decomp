#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov015_02190d7c;
extern "C" void func_ov015_021931b4(struct Struct_ov015_02190d7c* s, int v);
extern "C" void func_ov015_02192700(void* obj, int a1);

struct Struct_ov015_02191ea4 {
    int value;
    struct Struct_ov015_02191ea4* next;
};

struct Struct_ov015_02191ea4_2 {
    char pad0[0x2c];
    struct Struct_ov015_02191ea4* list;
    char pad1[0x34 - 0x2c - 4];
    int field34;
    char pad2[0x1a4 - 0x34 - 4];
    int field1a4;
};

// USA: func_ov015_02191ea4
extern "C" ARM void func_ov015_02191ea4(struct Struct_ov015_02191ea4_2* obj, int count) {
    int i;
    struct Struct_ov015_02191ea4* node = obj->list;
    if (node == 0) {
        return;
    }

    for (i = 0; i < count; i++) {
        node = node->next;
    }

    if (node == 0) {
        return;
    }

    obj->field34 = node->value;
    func_ov015_021931b4((struct Struct_ov015_02190d7c*)obj, obj->field1a4);
    obj->field1a4 = 0x25;
    func_ov015_02192700(obj, 0);
}
