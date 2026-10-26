#if defined(jpn)
enum { Enum_ov017_021b5348_68 = 0x40, Enum_ov017_021b5348_772 = 0x300, Enum_ov017_021b5348_776 = 0x304 };
#else
enum { Enum_ov017_021b5348_68 = 0x44, Enum_ov017_021b5348_772 = 0x304, Enum_ov017_021b5348_776 = 0x308 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
struct List0202fe68;
struct List0202fec8;
extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
extern "C" ARM unsigned short func_0209c0c0(struct Struct_0209c0c0* arg0, struct Struct_0209c0c0* arg1);
struct Struct_020287b4_4;
extern "C" void func_0206ee60(struct Struct_020287b4_4* arg0);
struct Struct_02013fb4;
extern "C" void func_0206ee80(void* arg0, void* arg1, struct Struct_02013fb4* arg2, int arg3, void* arg4, short arg5);
extern "C" void func_ov017_021b5648(void* arg0);

extern char data_ov017_021d7bdc;

struct Struct_ov017_021b5348_2 {
    char unknown_0_[8];
    void* unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
};

struct Struct_ov017_021b5348 {
    char unknown_0_[Enum_ov017_021b5348_776];
    unsigned char unknown_308_;
};

// USA: func_ov017_021b5348
extern "C" ARM void func_ov017_021b5348(struct Struct_ov017_021b5348_2* arg0) {
    void* var0;
    GameState::GetInstance();
    int list = (int)BackgroundLoader::GetInstance();
    LinkSession_GetInstance();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    var0 = arg0->unknown_8_;
    if (((BackgroundLoader*)((struct Struct_020534ac_2*)var1))->GetDetailedTaskStatus((int)(arg0->unknown_c_)) == 2) {
        int var2, var3;
        ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(arg0->unknown_c_), (void**)(&var3), (unsigned int*)(&var2));
        if (var3 != 0) {
            char* var4 = (char*)arg0->unknown_8_;
            unsigned short var5[12];
            __clear(var5, 0x18);
            short var6 = (short)func_0209c0c0((struct Struct_0209c0c0*)(var4 + Enum_ov017_021b5348_68), (struct Struct_0209c0c0*)var5);
            func_0206ee60((struct Struct_020287b4_4*)((char*)var0 + Enum_ov017_021b5348_772));
            void* var7 = *(void**)((char*)arg0->unknown_8_ + 0x10);
            func_0206ee80((char*)var0 + Enum_ov017_021b5348_772, var7, (struct Struct_02013fb4*)var3, (short)var2, var5, var6);
        }
    }

    ((BackgroundLoader*)(var1))->RemoveTask((int)(arg0->unknown_c_));
    arg0->unknown_c_ = -1;
    int var8 = 0;
    if (((struct Struct_ov017_021b5348*)var0)->unknown_308_ > var8) {
        arg0->unknown_c_ = ((BackgroundLoader*)(var1))->QueueLoadFile((const char*)((int)&data_ov017_021d7bdc), (SafeAllocator*)(0));
        arg0->unknown_10_ = 8;
    } else {
        func_ov017_021b5648(arg0);
    }
}
