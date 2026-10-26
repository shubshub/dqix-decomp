#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov001_021601f8(void* a, void* b);
extern "C" void Zone3D_Draw(void* big);

struct Struct_ov001_021603d8 { char pad0[0x44]; int field44; char pad1[0x54 - 0x48]; struct Struct_ov001_021603d8* next; };
struct Big_021603d8 {
#if defined(jpn)
    char pad0[0x430];
#else
    char pad0[0x410];
#endif
    int unknown_410_;
#if defined(jpn)
    char pad1[0x43c - 0x434];
#else
    char pad1[0x41c - 0x414];
#endif
    struct Struct_ov001_021603d8* unknown_41c_;
#if defined(jpn)
    char pad2[0x852 - 0x440];
#else
    char pad2[0x832 - 0x420];
#endif
    unsigned char unknown_832_;
    unsigned char unknown_833_;
    unsigned char unknown_834_;
};
struct Struct_ov001_021603d8_3 { char pad0[0x90]; int field90; int field94; int field98; };

struct Struct_ov001_02165880_41 {
    int field0;
    unsigned char pad0[0x10 - 0x4];
    int field10;
    int field14;
    unsigned char pad1[0x2c - 0x18];
    int field2c;
    int unknown_30_;
};
extern Struct_ov001_02165880_41 data_ov001_02165880;

struct Struct_ov001_02164d14 {
    unsigned char pad0[0x10];
    int field10;
    int field14;
    int field18;
    int field1c;
};
extern Struct_ov001_02164d14 data_ov001_02164d14;

extern int data_ov001_02164d24[];

// USA: func_ov001_021603d8
extern "C" ARM int func_ov001_021603d8(void* obj) {
    Big_021603d8* big = (Big_021603d8*)Zone3D_GetInstance();
    Struct_ov001_021603d8_3* d = (Struct_ov001_021603d8_3*)LightingManager::GetInstance();
    int idx = func_ov017_021d60f4(obj);
    d->field98 = idx;
    if (!(data_ov001_02165880.field14 & 1)) {
        data_ov001_02164d14.field10 = data_ov001_02165880.field0;
        data_ov001_02164d14.field14 = data_ov001_02165880.field10;
        data_ov001_02164d14.field18 = data_ov001_02165880.unknown_30_;
        data_ov001_02164d14.field1c = data_ov001_02165880.field2c;
        data_ov001_02165880.field14 |= 1;
    }
    d->field94 = data_ov001_02164d24[idx];

    if (big->unknown_410_ == 1) {
        if (big->unknown_834_ != 0) {
            return 1;
        }
        Struct_ov001_021603d8* node = big->unknown_41c_;
        while (node != NULL) {
            if (node->field44 != 0) {
                func_ov001_021601f8((void*)node->field44, (char*)node + 4);
            }
            node = node->next;
        }
        big->unknown_834_ = 1;
    } else {
        int local[4];
        local[0] = data_ov001_02165880.field0;
        local[1] = data_ov001_02165880.field10;
        local[2] = data_ov001_02165880.unknown_30_;
        local[3] = data_ov001_02165880.field2c;
        d->field94 = local[idx];
        d->field90 = 0;
        ((LightingManager*)d)->RecomputeAdvancedLighting();
    }

    big->unknown_832_ = 1;
    big->unknown_833_ = 1;
    Zone3D_Draw(big);
    return 1;
}
