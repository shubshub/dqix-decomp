#include <globaldefs.h>

ARM void* GetTableEntry020421b0(int idx);
extern "C" ARM void Canvas_DrawTile(void* mgr, void* entry, short x, short y, int w, int h);
extern "C" ARM void* __clear(void* dst, int count);

extern unsigned char data_020ee94c;

// USA: func_020e2110
extern "C" ARM void func_020e2110(void* arg0) {
    void* var0 = *(void**)((char*)arg0 + 4);
    void* var1 = *(void**)((char*)var0 + 4);
    unsigned char var2 = ((unsigned char*)var0)[0x3a];
    unsigned char var3 = ((unsigned char*)var0)[0x3b];

    void* e1 = GetTableEntry020421b0(1);
    void* e6 = GetTableEntry020421b0(6);
    if (e1 != 0 && e6 != 0) {
        int x, i;
        int n = width - 9;
        for (x = 8, i = 0; i < n >> 3; x += 8, i++) {
            Canvas_DrawTile(mgr, e1, x, 0, 8, 0xf);
            Canvas_DrawTile(mgr, e6, x, (short)(height - 8), 8, 0xf);
        }
    }

    void* e3 = GetTableEntry020421b0(3);
    void* e4 = GetTableEntry020421b0(4);
    if (e3 != 0 && e4 != 0) {
        int y, j;
        int m = height - 9;
        for (y = 8, j = 0; j < m >> 3; y += 8, j++) {
            Canvas_DrawTile(mgr, e3, 0, y, 8, 0xf);
            Canvas_DrawTile(mgr, e4, (short)(width - 8), y, 8, 0xf);
        }
    }

    short var14[4];
    short var15[4];
    __clear(var14, 8);
    short var16 = (short)(var2 - 8);
    var14[1] = var16;
    var14[3] = var16;
    __clear(var15, 8);
    short var17 = (short)(var3 - 8);
    var15[2] = var17;
    var15[3] = var17;

    int k;
    for (k = 0; k < 4; k++) {
        int idx = (&data_020ee94c)[k];
        void* entry = GetTableEntry020421b0(idx);
        if (entry != 0) {
            Canvas_DrawTile(mgr, entry, xs[k], ys[k], 8, 0xf);
        }
    }
}
