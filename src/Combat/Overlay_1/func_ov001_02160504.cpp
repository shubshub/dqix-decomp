#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov001_021601f8(void* a, void* b);

struct Struct_ov001_02165880_42 {
    int field0;
    char pad4[0xc - 4];
    int flag;
    int field10;
    char unknown_14_[0x2c - 0x10 - 4];
    int field2c;
    int unknown_30_;
};
extern Struct_ov001_02165880_42 data_ov001_02165880;

struct Struct_ov001_02164d14_2 { char pad[0x20]; int f20, f24, f28, unknown_2c_; };
extern Struct_ov001_02164d14_2 data_ov001_02164d14;

extern int data_ov001_02164d34[];

struct Struct_ov001_02160504 { char pad0[0x44]; int field44; char pad1[0x54 - 0x48]; Struct_ov001_02160504* next; };
struct Big02160504 {
    
#if defined(jpn)
    char pad0[0x430];
#else
    char pad0[0x410];
#endif

    int unknown_410_;
    char pad1[0x41c - 0x414];
    Struct_ov001_02160504* unknown_41c_;
    char pad2[0x834 - 0x420];
    unsigned char unknown_834_;
};
struct Struct_ov001_02160504_3 { char pad0[0x94]; int field94; int field98; };

// USA: func_ov001_02160504
extern "C" ARM int func_ov001_02160504(void) {
    GameState* battle = GameState::GetInstance();
    Big02160504* big = (Big02160504*)Zone3D_GetInstance();
    Struct_ov001_02160504_3* d = (Struct_ov001_02160504_3*)LightingManager::GetInstance();
    if (big->unknown_834_ != 0) return 1;
    int idx = battle->GetTimeOfDay();
    d->field98 = idx;
    if (!(data_ov001_02165880.flag & 1)) {
        data_ov001_02164d14.f20 = data_ov001_02165880.field0;
        data_ov001_02164d14.f24 = data_ov001_02165880.field10;
        data_ov001_02164d14.f28 = data_ov001_02165880.unknown_30_;
        data_ov001_02164d14.unknown_2c_ = data_ov001_02165880.field2c;
        data_ov001_02165880.flag |= 1;
    }
    d->field94 = data_ov001_02164d34[idx];
    if (big->unknown_410_ == 1) {
        Struct_ov001_02160504* node = big->unknown_41c_;
        while (node != NULL) {
            if (node->field44 != 0) {
                func_ov001_021601f8((void*)node->field44, (char*)node + 4);
            }
            node = node->next;
        }
        big->unknown_834_ = 1;
    }
    return 1;
}
