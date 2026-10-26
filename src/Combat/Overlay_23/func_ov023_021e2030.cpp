#include <globaldefs.h>

extern "C" void func_0204e1c8(int flag, void* entry, void* p2, void* p3, int a, int b, int c, int d);

// USA: func_ov023_021e2030
extern "C" ARM void func_ov023_021e2030(int a, int arg1, int arg2, void* cursor) {
    short var0;
    for (int y = 0; y < 2; y++) {
        var0 = (short)(arg2 + (y << 3));
        for (int x = 0; x < 2; x++) {
            short var3 = (short)(arg1 + (x << 3));
            func_0204e1c8(a, cursor, (void*)(int)var3, (void*)(int)var0, 8, 8, 0xf0, 0xf);
            cursor = (char*)cursor + 0x20;
        }
    }
}
