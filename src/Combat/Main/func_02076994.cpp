#include <globaldefs.h>

extern "C" int LoadToMainObjVRAM(int, int, unsigned int);
extern "C" int LoadToSubObjVRAM(int, int, unsigned int);

struct Struct_02076994 {
    char pad0[0x50];
    int unknown_50_;
    char unknown_54_[0xa];
    unsigned char unknown_5e_;
    char unknown_5f_[1];
};

// USA: func_02076994
extern "C" ARM void func_02076994(struct Struct_02076994* s, char* src, char* dest, unsigned int width, unsigned int rows) {
    unsigned int var0 = rows;
    unsigned int n = width >> 3;
    unsigned int tile = 4;
    unsigned int row = 0x20;
    if (s->unknown_50_ == 1) {
        tile = 8;
        row = 0x40;
    }
    unsigned int step = n * tile;
    unsigned int var5 = n * row;
    unsigned int base = 0;
    unsigned int m;
    unsigned int i;
    unsigned int c;
    unsigned int j, o;
    char* d = dest;

    for (o = 0; o < (var0 >> 3); o++) {
        m = base;
        for (i = 0; i < n; i++) {
            c = m;
            for (j = 0; j < 8; j++) {
                if (s->unknown_5e_ == 0) {
                    LoadToMainObjVRAM((int)(src + c), (int)d, tile);
                } else {
                    LoadToSubObjVRAM((int)(src + c), (int)d, tile);
                }
                d += tile;
                c += step;
            }
            m += tile;
        }
        base += var5;
    }
}
