#include <globaldefs.h>
extern "C" void func_0205d904(unsigned char*);

struct GridCursor;

extern "C" void func_0205d6e4(void* a, int count);
extern "C" void GridCursor_ResetKeyRepeat(struct GridCursor* s);

struct Entry_0205d6a0 {
    char pad0[0x98];
    int unknown_98_;
    int f9c;
    char pad1[0xb3 - 0xa0];
    unsigned char unknown_b3_;
};

// Main, originally ResetEntryList0205d6a0 (USA 0x0205d6a0, EUR 0x0205d6b0, JPN 0x0205e9b4)
extern "C" ARM void Window_ClosePane(struct Entry_0205d6a0* a, int flag) {
    int count;
    if (a->unknown_98_ == 0 || a->f9c == 0) return;
    count = 1;
    if (flag) count = a->unknown_b3_;
    func_0205d6e4(a, count);
    GridCursor_ResetKeyRepeat((struct GridCursor*)((char*)a + 0x54));
    func_0205d904((unsigned char*)(a));
}
