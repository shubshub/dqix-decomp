#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020da244_2 {
    unsigned char pad0[8];
    int field8;
};

struct Struct_020da244 {
    void* f0;
    int f4;
    unsigned char pad8[0xc - 0x8];
    unsigned char fc;
    unsigned char unknown_d_;
    unsigned char fe;
    unsigned char ff;
    unsigned char pad10[0x14 - 0x10];
    Struct_020da244_2 slots[4];
};

extern "C" void func_020dabd0(void* ctx);
extern "C" void func_020da2e4(unsigned char* entry);

// USA: func_020da244
extern "C" ARM void func_020da244(Struct_020da244* sb) {
    func_020dabd0(sb);
    Struct_020da244_2* entry = sb->slots;
    int var1 = (int)BackgroundLoader::GetInstance();
    if (var1 != 0) {
        for (unsigned char i = 0; i < 4; i++, entry++) {
            if (entry->field8 != -1) {
                ((BackgroundLoader*)(var1))->RemoveTask((int)(entry->field8 != -1));
                func_020da2e4((unsigned char*)entry);
            }
        }
    }
    if (sb->f0 != 0) {
        ((SafeAllocator*)sb->f0)->Destroy();
        ((SafeAllocator*)sb->f0)->ResetAllocatorPointer();
    }
    sb->f0 = 0;
    sb->f4 = 0;
    sb->fc = 0;
    sb->unknown_d_ = 0;
    sb->fe = 0;
    sb->ff = 0;
}
