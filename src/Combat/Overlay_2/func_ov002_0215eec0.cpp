#include <globaldefs.h>

extern "C" void* __clear(void* arg0, int arg1);
extern "C" void func_020dd040(int arg0, char* arg1);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_FormatText(int arg0, int arg1, void* arg2, int arg3, int arg4, int arg5, int arg6);

struct Struct_ov002_0215eec0 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 20;
};

// USA: func_ov002_0215eec0
#if defined(jpn)
extern "C" ARM void func_ov002_0215eec0(unsigned char* arg0, char* arg1) {
    if (arg1) {
        *(short*)(arg0 + 0x1a00 + 0xee) = -1;

        int var1 = *(short*)(arg0 + 0x1a00 + 0xc2);
        if (var1 >= 0 && var1 < 0x20) {
            void* var2 = *(void**)(arg0 + var1 * 4 + 0x22d0);
            struct Struct_ov002_0215eec0* var3 = (struct Struct_ov002_0215eec0*)((char*)var2 + 4);
            *(short*)(arg0 + 0x1a00 + 0xee) = var3->unknown_0_0_;
        }

        func_020dd040(*(short*)(arg0 + 0x1a00 + 0xee), arg1);
    }
}
#else
extern "C" ARM void func_ov002_0215eec0(unsigned char* arg0, int arg1) {
    char var0[0x100];

    if (arg1) {
        *(short*)(arg0 + 0x1c00 + 0x26) = -1;

        int var1 = *(short*)(arg0 + 0x1b00 + 0xfa);
        if (var1 >= 0 && var1 < 0x20) {
            void* var2 = *(void**)(arg0 + var1 * 4 + 0x24a0);
            struct Struct_ov002_0215eec0* var3 = (struct Struct_ov002_0215eec0*)((char*)var2 + 4);
            *(short*)(arg0 + 0x1c00 + 0x26) = var3->unknown_0_0_;
        }

        __clear(var0, 0x100);
        func_020dd040(*(short*)(arg0 + 0x1c00 + 0x26), var0);

        int var4 = MessageSystem_GetInstance();
        MessageSystem_FormatText(var4, 0xc, var0, arg1, 0x74, 0, 0);
    }
}
#endif
