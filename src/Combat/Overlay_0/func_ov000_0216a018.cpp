#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);

struct Struct_ov000_02184264_6 {
    char pad0[0x8];
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_6 data_ov000_02184264;

struct Struct_ov000_0216a018 {
    int tag;
    int unused;
    short value;
    short idA;
    short unknown_c_;
    short param0;
    short param2;
    short param1;
    short param3;
};

// USA: func_ov000_0216a018
extern "C" ARM int func_ov000_0216a018(Script::Parameter* params, int count) {
    struct Struct_ov000_0216a018* node = (struct Struct_ov000_0216a018*)data_ov000_02184264.alloc->Allocate(0x18);
    node->tag = 7;
    if (count == 0) {
        node->value = 0;
        node->idA = -1;
        node->unknown_c_ = -1;
        node->param0 = 0;
        node->param1 = 0;
        node->param2 = 0;
        node->param3 = 0;
    } else if (count == 1 && params->type == 2) {
        node->value = (short)(params->ToFloat() * 4096.0f);
        node->idA = -1;
        node->unknown_c_ = -1;
        node->param0 = 0;
        node->param1 = 0;
        node->param2 = 0;
        node->param3 = 0;
    } else {
        node->value = 0;
        node->idA = params[0].ToInt();
        Script::Parameter* p = params + 2;
        node->unknown_c_ = params[1].ToInt();
        if (count < 3) {
            node->param0 = 0;
        } else {
            node->param0 = p->ToInt();
            p++;
        }
        if (count < 4) {
            node->param1 = 0;
        } else {
            node->param1 = p->ToInt();
            p++;
        }
        if (count < 5) {
            node->param2 = 0;
        } else {
            node->param2 = p->ToInt();
            p++;
        }
        if (count < 6) {
            node->param3 = 0;
        } else {
            node->param3 = p->ToInt();
        }
        if (node->idA >= 0 && node->idA < 100) {
            node->idA += 100;
        }
        if (node->unknown_c_ >= 0 && node->unknown_c_ < 100) {
            node->unknown_c_ += 100;
        }
    }
    func_ov000_02169b78(node);
    return 1;
}
