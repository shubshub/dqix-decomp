#include <globaldefs.h>

struct Struct_ov025_021d8c30_11 {
    unsigned int unknown_0_;
    unsigned int w1;
    unsigned int w2;
    unsigned int unknown_c_;
    unsigned int w4;
    unsigned char b;
};

extern "C" void func_ov025_021dcd28(struct Struct_ov025_021d8c30_11* dst, struct Struct_ov025_021d8c30_11* src);

#if defined(jpn)
#define SLOT_COUNT 0x70f0
#define SLOT_DATA 0x70f8
#define SLOT_BASE 0x7100
#define SLOT_FIELD(n) ((n) - 0x10)
#else
#define SLOT_COUNT 0x6f00
#define SLOT_DATA 0x6f08
#define SLOT_BASE 0x6f00
#define SLOT_FIELD(n) (n)
#endif

// USA: func_ov025_021dcde8
extern "C" ARM void func_ov025_021dcde8(unsigned char* obj, struct Struct_ov025_021d8c30_11* src) {
    if (*(unsigned char*)(obj + SLOT_COUNT) >= 5) {
        return;
    }
    func_ov025_021dcd28((struct Struct_ov025_021d8c30_11*)(obj + SLOT_DATA + *(unsigned char*)(obj + SLOT_COUNT) * 0x1c), src);
    *(unsigned short*)(obj + *(unsigned char*)(obj + SLOT_COUNT) * 0x1c + SLOT_BASE + SLOT_FIELD(0x20)) = 0;
    *(unsigned short*)(obj + *(unsigned char*)(obj + SLOT_COUNT) * 0x1c + SLOT_BASE + SLOT_FIELD(0x22)) = 0;
    if (*(unsigned char*)(obj + SLOT_COUNT) != 0) {
        int count = *(unsigned char*)(obj + SLOT_COUNT);
        unsigned short prev = *(unsigned short*)(obj + (count - 1) * 0x1c + SLOT_BASE + SLOT_FIELD(0x20));
        *(unsigned short*)(obj + count * 0x1c + SLOT_BASE + SLOT_FIELD(0x22)) = prev;
    }
    *(unsigned char*)(obj + SLOT_COUNT) = *(unsigned char*)(obj + SLOT_COUNT) + 1;
}
