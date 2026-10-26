#include <globaldefs.h>

struct IndexNode_0202a9ac {
    char unk[0x34];
    struct IndexNode_0202a9ac* next;
};

struct IndexList_0202a9ac {
    char unk[0x44];
    struct IndexNode_0202a9ac* head;
    char unk2[0x12];
    unsigned short count;
};

extern "C" struct IndexNode_0202a9ac* DebugMenu_GetItem(struct IndexList_0202a9ac* list, int index);
extern "C" void* func_02029560(void* base);
extern "C" void* func_ov015_0218f39c(void*, void*);

struct Struct_ov015_0219015c {
    char pad[0x10];
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
};

struct Struct_ov015_0219015c_2 {
    void* field0;
    char pad[0x34];
    short field0x38;
};

// USA: func_ov015_0219015c
extern "C" ARM void func_ov015_0219015c(struct Struct_ov015_0219015c_2* obj, int delta) {
    struct IndexList_0202a9ac* list = (struct IndexList_0202a9ac*)((char*)obj->field0 + 0x2c4);
    struct IndexNode_0202a9ac* node = DebugMenu_GetItem(list, obj->field0x38);
    if (node == 0) {
        return;
    }
    void* sub = func_02029560(node);
    struct Struct_ov015_0219015c* q = (struct Struct_ov015_0219015c*)func_ov015_0218f39c(obj, sub);
    if (q == 0) {
        return;
    }
    int cap = q->unknown_14_ - q->unknown_10_;
    int v = q->unknown_18_ + delta;
    q->unknown_18_ = v;
    if (v < 0) {
        q->unknown_18_ = 0;
    }
    v = q->unknown_18_;
    if (v > cap) {
        q->unknown_18_ = cap;
    }
}
