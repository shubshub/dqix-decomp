#include <globaldefs.h>

extern "C" void WindowPane_Init(void* buf);
int InitBufferFromDataField4_021ddc34(void* obj, short a, short b, short c, short d);
#if defined(jpn)
#define func_ov023_021dcedc func_ov023_021dd7e0
#endif
extern "C" void func_ov023_021dcedc(void* arg0, void* arg1);
extern "C" int func_ov023_021ddc98(void* arg0, int arg1, unsigned short arg2, int arg3);
extern int data_ov023_021ff9e0[];

struct Struct_ov023_021dd344 {
    #if defined(jpn)
    char unknown_0_[0x717];
#else
    char unknown1_0_[0x79b];
#endif
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

#if defined(jpn)
#define TEXT_POSITION 0x6d8
#define TEXT_SAVED_POSITION 0x6dc
#define TEXT_LAST_LENGTH 0x6e0
#else
#define TEXT_POSITION 0x75c
#define TEXT_SAVED_POSITION 0x760
#define TEXT_LAST_LENGTH 0x764
#endif

// USA: func_ov023_021dd344
extern "C" ARM void func_ov023_021dd344(struct Struct_ov023_021dd344* arg0) {
    if (!arg0->unknown_79b_1_) return;

    char buf[0xe0];
    WindowPane_Init(buf);

    if (!func_ov023_021ddc34(var0, 3, 0x10, 0x1a, 6)) return;

    func_ov023_021dcedc(arg0, var0);

    if (*(int*)((char*)arg0 + TEXT_SAVED_POSITION) != 0) {
        func_ov023_021ddc98(var0, *(int*)((char*)arg0 + TEXT_SAVED_POSITION), (unsigned short)data_ov023_021ff9e0[3], 1);
    } else {
        int var1 = func_ov023_021ddc98(var0, *(int*)((char*)arg0 + TEXT_POSITION), (unsigned short)data_ov023_021ff9e0[3], 1);
        *(int*)((char*)arg0 + TEXT_SAVED_POSITION) = *(int*)((char*)arg0 + TEXT_POSITION);
        *(int*)((char*)arg0 + TEXT_LAST_LENGTH) = var1;
        *(int*)((char*)arg0 + TEXT_POSITION) = *(int*)((char*)arg0 + TEXT_POSITION) + var1;
    }
}
