#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);
extern "C" void __clear(void* buf, int size);

struct Struct_ov000_02184264_2 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_2 data_ov000_02184264;

struct Struct_ov000_0216a68c {
    int tag;
    int unused;
    char* name;
    unsigned char fieldC;
    signed char unknown_d_;
    short unknown_e_;
    unsigned char field10;
    Vector3fix16 pos;
    short angle;
    unsigned char flagA;
    unsigned char unknown_1b_;
};

// USA: func_ov000_0216a68c
extern "C" ARM int func_ov000_0216a68c(Script::Parameter* p, int n) {
    Struct_ov000_0216a68c* node = (Struct_ov000_0216a68c*)data_ov000_02184264.alloc->Allocate(sizeof(Struct_ov000_0216a68c));
    int var1;
    int var2 = -1;
    const char* s;
    char* name = NULL;
    int field10 = 0;
    int fieldC = 1;
    int flagA = 0;
    int var8 = 0;
    short angle = 0;
    Vector3fix16 pos;
    __clear(&pos, sizeof(pos));
    if (p[0].type == 1) {
        if (n >= 3 && p[2].type == 0) {
            var1 = p++->ToInt();
            var2 = p++->ToInt() - 0x1a;
            s = p++->ToString();
            if (s != NULL) {
                name = (char*)data_ov000_02184264.alloc->Allocate(strlen(s) + 1);
                strcpy(name, s);
            }
            if (n >= 4) {
                fieldC = p++->ToInt();
            }
            if (n >= 5) {
                flagA = p++->ToInt() != 0;
            }
            if (n >= 6) {
                var8 = p++->ToInt() != 0;
            }
        } else {
            var1 = p++->ToInt() + 100;
            if (n >= 2) {
                field10 = p++->ToInt();
            }
            if (n >= 3) {
                p->ToVec3fix16(&pos);
            }
        }
    } else if (p[0].type == 2) {
        angle = p++->ToFloat() * 4096.0f;
        if (n >= 2) {
            var1 = p++->ToInt() + 100;
        } else {
            return 0;
        }
        if (n >= 3) {
            field10 = p++->ToInt();
        }
        if (n >= 4) {
            p->ToVec3fix16(&pos);
        }
    } else {
        return 0;
    }
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x15;
    node->angle = angle;
    node->unknown_e_ = var1;
    node->unknown_d_ = var2;
    node->field10 = field10;
    node->name = name;
    node->fieldC = fieldC;
    Vector3fix16Copy(&node->pos, &pos);
    node->flagA = flagA;
    node->unknown_1b_ = var8;
    func_ov000_02169b78(node);
    return 1;
}
