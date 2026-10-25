#include <globaldefs.h>

struct Struct_02064490_3 {
    char unknown_0_[0xc];
    struct Struct_02064490_3* unknown_c_;
};

struct Struct_02064490 {
    char unknown_0_[6];
    unsigned char unknown_6_;
    char unknown_7_;
    struct Struct_02064490_3* unknown_8_;
    char unknown_c_[4];
    struct Struct_02064490* unknown_10_;
    struct Struct_02064490* unknown_14_;
};

struct Struct_02064490_2 {
    char unknown_0_[0x47c];
    struct Struct_02064490* unknown_47c_;
    char unknown_480_[0x492 - 0x480];
    unsigned char unknown_492_;
};

extern "C" int Scenario_TestCondition(void*, struct Node02064704*, void*);

// Main, originally func_02064490 (USA 0x02064490, EUR 0x020644a0, JPN 0x0206577c)
extern "C" ARM struct Node02064490* Scenario_FindTrigger(struct Obj02064490* obj, int key, void* extra) {
    struct Node02064490* node;
    for (node = obj->list47c; node != NULL; node = node->field14) {
        if (node->byte6 == key) break;
    }
    if (node == NULL) return NULL;
    obj->byte492 = 0;
    int ok = 1;
    struct Node02064704* inner;
    for (; node != NULL; node = node->field10) {
        for (inner = node->field8; inner != NULL; inner = inner->next) {
            if (Scenario_TestCondition(obj, inner, extra) == 0) {
                ok = 0;
                break;
            }
            var1 = 1;
        }
        if (var1) return var0;
    }
    return NULL;
}
