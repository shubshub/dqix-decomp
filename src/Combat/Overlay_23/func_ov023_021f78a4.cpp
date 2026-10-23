#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" int func_ov023_021f6bb8(void* arg0);
extern "C" void func_ov023_021f6bb0(void* arg0, int arg1);

struct Struct_020534ac_2;

struct Struct_020534ac;

extern "C" void func_ov023_021f7b98(void* obj, void* ctx, int flag, int v1, unsigned int entryLength);
extern "C" void Background_TransferMap(void* p, int flag);

struct Struct_ov023_021f78a4 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    char unknown_d_[0x1c - 0xd];
    int unknown_1c_;
    void* unknown_20_;
};

// USA: func_ov023_021f78a4
extern "C" ARM void func_ov023_021f78a4(struct Struct_ov023_021f78a4* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021f78a4_40=0x24};
#else
 enum {Enum_ov023_021f78a4_40=0x28};
#endif
    if (arg0->unknown_c_ & 0x2) {
        void* var0 = arg0->unknown_20_;
        void* var1 = func_ov011_021849c8(var0);
        int var2 = (int)BackgroundLoader::GetInstance();
        int var3 = func_ov023_021f6bb8(var1);
        if (((BackgroundLoader*)(var2))->GetTaskStatus((int)(var3))) {
            if (((BackgroundLoader*)((struct Struct_020534ac_2*)var2))->GetDetailedTaskStatus((int)(var3)) == 2) {
                int var4, var5;
                ((BackgroundLoader*)((struct Struct_020534ac*)var2))->GetLoadedFileByID((int)(var3), (void**)(&var4), (unsigned int*)(&var5));
                if (var4 != 0 && var5 != 0) {
                    func_ov023_021f7b98(arg0, var0, 0, var4, var5);
                }
            }
            ((BackgroundLoader*)(var2))->RemoveTask((int)(var3));
            func_ov023_021f6bb0(var1, -1);
            arg0->unknown_1c_ = 2;
        }
    }

    if (!(obj->flags0xc & 0x1)) {
        Background_TransferMap((char*)obj + regionalOffset, 0);
    }
}
