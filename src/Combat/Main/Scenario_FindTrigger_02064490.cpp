#include <globaldefs.h>

struct Node02064704 {
    char pad0[0xc];
    struct Node02064704* next;
};

struct Node02064490 {
    char pad0[6];
    unsigned char unknown_6_;
    char unknown_7_;
    struct Node02064704* field8;
    char unknown_c_[4];
    struct Node02064490* field10;
    struct Node02064490* field14;
};

struct Obj02064490 {
    char pad0[0x47c];
    struct Node02064490* unknown_47c_;
    char unknown_480_[0x492 - 0x480];
    unsigned char unknown_492_;
};

extern "C" int Scenario_TestCondition(void*, struct Node02064704*, void*);

// Main, originally func_02064490 (USA 0x02064490, EUR 0x020644a0, JPN 0x0206577c)
extern "C" ARM struct Node02064490* Scenario_FindTrigger(struct Obj02064490* obj, int key, void* extra) {
    struct Node02064490* node;
    for (node = obj->unknown_47c_; node != NULL; node = node->field14) {
        if (node->unknown_6_ == key) break;
    }
    if (node == NULL) return NULL;
    obj->unknown_492_ = 0;
    int ok = 1;
    struct Node02064704* inner;
    for (; node != NULL; node = node->field10) {
        for (inner = node->field8; inner != NULL; inner = inner->next) {
            if (Scenario_TestCondition(obj, inner, extra) == 0) {
                ok = 0;
                break;
            }
            ok = 1;
        }
        if (ok) return node;
    }
    return NULL;
}
