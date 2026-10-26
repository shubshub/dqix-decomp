#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_02083738_2 {
    void* pB;
    void* unknown_4_;
    char pad[0x18];
};

struct Struct_0200f3a4_14 {
    char data[0x20];
};

struct Struct_02083738 {
    char pad[0x194];
    struct Struct_02083738_2 arrA[11];
    #if defined(jpn)
    char pad2[0x364];
#else
    char pad2[0x3fc];
#endif
    struct Struct_0200f3a4_14 arrB[11];
};

struct StructDE1D4;
extern "C" void ItemRecord_Clear(struct StructDE1D4*);
extern "C" unsigned char* func_0208349c(unsigned char* base, int idx);

// USA: func_02083738
extern "C" ARM void func_02083738(struct Struct_02083738* o, int a1) {
    int i = -1;
    int j = -1;
    switch (a1) {
    case 0: i = 8; j = 7; break;
    case 1: i = 9; j = 8; break;
    case 4: i = 7; j = 6; break;
    case 2: i = 0; j = 0; break;
    case 5: i = 5; j = 4; break;
    case 3: i = 1; j = 1; break;
    case 6: i = 6; j = 5; break;
    case 7: i = 10; j = 9; break;
    }
    if (i >= 0 && j >= 0) {
        struct Struct_02083738_2* e = &o->arrA[i];
        void* pb = e->pB;
        void* var4 = e->unknown_4_;
        *(short*)((char*)o + j * 2 + 0x488) = -1;
        memset(pb, 0, 0x20);
#if defined(jpn)
        memset(var4, 0, 0x14);
#else
        *(unsigned char*)var4 = 0;
#endif
        ItemRecord_Clear((struct StructDE1D4*)e);
        e->pB = &o->arrB[i];
#if defined(jpn)
        e->unknown_4_ = (unsigned char*)o + 0x56f + i * 0x15;
#else
        e->unknown_4_ = func_0208349c((unsigned char*)o, i);
#endif
    }
}
