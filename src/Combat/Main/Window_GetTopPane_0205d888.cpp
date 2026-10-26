#include <globaldefs.h>

struct Struct0205d888 {
    char pad0[0x98];
    int field98;
    void* unknown_9c_;
    char pad1[0x14];
    unsigned char fieldB4;
};

// Main, originally GetLastEntry0205d888 (USA 0x0205d888, EUR 0x0205d898, JPN 0x0205eb9c)
extern "C" ARM void* Window_GetTopPane(struct Struct0205d888* p) {
    void* base;
    if (p->field98 == 0) return 0;
    base = p->unknown_9c_;
    if (base == 0) return 0;
    return p->fieldB4 != 0 ? (char*)base + (p->fieldB4 - 1) * 0xE0 : 0;
}
