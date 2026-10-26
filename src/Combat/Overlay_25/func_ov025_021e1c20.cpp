#include <globaldefs.h>

struct Struct_ov025_021e1c20 {
    unsigned char b[6];
};

struct Struct_ov025_021e1c20_2 {
    unsigned char id;
    unsigned char val;
    char pad[2];
    int moved;
    unsigned char* obj;
};

extern "C" void func_ov000_0216f82c(Struct_ov025_021e1c20* out, const int* cell);
extern "C" int func_020493a4(unsigned char*);
extern "C" int func_020493ec(unsigned char*);
extern "C" void func_020493dc(unsigned char*, unsigned char);

// USA: func_ov025_021e1c20
extern "C" ARM void func_ov025_021e1c20(int cell, unsigned char* map, unsigned char* dist, int level, Struct_ov025_021e1c20_2* ents, int n, unsigned char* self) {
    unsigned char var0[8];
    int cur = cell;
    Struct_ov025_021e1c20 tmp;
    Struct_ov025_021e1c20 nb;
    int i;
    int k;
    int j;
    int pos;
    unsigned char b;
    int cnt;
    unsigned int c;
    cnt = 0;
    func_ov000_0216f82c(&tmp, &cur);
    nb = tmp;
    for (i = 0; i < 6; i++) {
        b = nb.b[i];
        if (b != 0xff && dist[b] == level - 1) {
            var0[cnt] = b;
            cnt++;
        }
    }
    for (k = 0; k < cnt; k++) {
        c = var0[k];
        if (c < 0x51) {
            map[c] = 0xff;
        }
        for (j = 0; j < n; j++) {
            if (*self != ents[j].id) {
                pos = func_020493ec(ents[j].obj);
                if (pos >= 0x51) {
                    pos = func_020493a4(ents[j].obj);
                }
                if (pos == c) {
                    ents[j].moved = 1;
                    func_020493dc(ents[j].obj, 0xff);
                }
            }
        }
    }
}
