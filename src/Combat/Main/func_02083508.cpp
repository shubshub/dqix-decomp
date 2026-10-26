#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif


struct Struct_02083508 {
    void* pB;       // 0x0
    void* unknown_4_;  // 0x4
    char pad[0x18];
};

struct Struct_02082828_6 {
    char data[0x20];
};

struct Struct_02082828_2 {
    char pad[0x194];
    struct Struct_02083508 arrA[11];  // 0x194
    char pad2[IS_JPN ? 0x364 : 0x3fc];
    struct Struct_02082828_6 arrB[11];  // 0x6f0
};

struct StructDE1D4;
extern "C" void ItemRecord_Clear(struct StructDE1D4*);
extern "C" unsigned char* func_0208349c(unsigned char* base, int idx);

// USA: func_02083508
extern "C" ARM void func_02083508(struct Struct_02082828_2* o) {
    int i;
    for (i = 0; i < 11; i++) {
        ItemRecord_Clear((struct StructDE1D4*)&o->arrA[i]);
#if defined(jpn)
        o->arrA[i].unknown_4_ = (unsigned char*)o + 0x56f + i * 0x15;
#else
        o->arrA[i].unknown_4_ = func_0208349c((unsigned char*)o, i);
#endif
        o->arrA[i].pB = &o->arrB[i];
    }
}
