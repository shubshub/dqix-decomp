#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_02083738_2 {
    void* unknown_0_;
    void* unknown_4_;
    char unknown_8_[0x18];
};

struct Struct_0200f3a4_14 {
    char unknown_0_[0x20];
};

struct Struct_02083738 {
    char unknown_0_[0x194];
    struct Struct_02083738_2 unknown_194_[11];
    #if defined(jpn)
    char unknown_2f4_[0x364];
#else
    char unknown1_2f4_[0x3fc];
#endif
    struct Struct_0200f3a4_14 unknown_6f0_[11];
};

struct StructDE1D4;
void ItemRecord_Clear(struct StructDE1D4*);
unsigned char* GetIndexedBlockPointer0208349c(unsigned char* base, int idx);

// USA: func_02083738
extern "C" ARM void func_02083738(struct Struct_02083738* arg0, int arg1) {
    int var0 = -1;
    int var1 = -1;
    switch (arg1) {
    case 0: var0 = 8; var1 = 7; break;
    case 1: var0 = 9; var1 = 8; break;
    case 4: var0 = 7; var1 = 6; break;
    case 2: var0 = 0; var1 = 0; break;
    case 5: var0 = 5; var1 = 4; break;
    case 3: var0 = 1; var1 = 1; break;
    case 6: var0 = 6; var1 = 5; break;
    case 7: var0 = 10; var1 = 9; break;
    }
    if (var0 >= 0 && var1 >= 0) {
        struct Struct_02083738_2* var2 = &arg0->unknown_194_[var0];
        void* var3 = var2->unknown_0_;
        void* var4 = var2->unknown_4_;
        *(short*)((char*)arg0 + var1 * 2 + 0x488) = -1;
        memset(var3, 0, 0x20);
#if defined(jpn)
        memset(var4, 0, 0x14);
#else
        *(unsigned char*)var4 = 0;
#endif
        ItemRecord_Clear((struct StructDE1D4*)e);
        e->pB = &o->arrB[i];
#if defined(jpn)
        var2->unknown_4_ = (unsigned char*)arg0 + 0x56f + var0 * 0x15;
#else
        var2->unknown_4_ = func_0208349c((unsigned char*)arg0, var0);
#endif
    }
}
