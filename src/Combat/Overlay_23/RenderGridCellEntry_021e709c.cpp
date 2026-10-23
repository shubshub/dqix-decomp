#include <globaldefs.h>

extern int data_ov023_021fdd6c;
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_0204f914(void* ctx, int mode, int x, int y, int x2, int y2);
void* Font_GetCharacter(int idx, int tableIdx);
struct Entry0204254c;
Entry0204254c* Font_FindCharacter(int key, int tableIdx);
extern "C" void func_0204f41c(void* ctx, short x, short y, int val, int d, int e, void* f, void* g, int h);

// USA: func_ov023_021e709c  (semantic: RenderGridCellEntry_021e709c)
extern "C" ARM void func_ov023_021e709c(void* ctx, unsigned char* arr, int index) {
    if (index < 0 || index >= 0x39) {
        return;
    }
    unsigned char id = arr[index];
    int rem = index % 0x13;
    int x = rem * 0xc + 0xf;
    int quot = index / 0x13;
    int y = quot * 0x13 + 8;
    func_0204f914(ctx, 1, (short)x, (short)y, (short)(x + 0xc), (short)(y + 0xc));
    if (id == 0xff) {
        return;
    }
    void* entry = Font_GetCharacter(id, 1);
    if (id == 0) {
        entry = Font_FindCharacter((int)&data_ov023_021fdd6c, 1);
    }
    short outHigh;
    short outLow;
    func_0204f41c(ctx, (short)x, (short)y, *(int*)entry, 0xc, 0xf, &outHigh, &outLow, 1);
}
