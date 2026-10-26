#include <globaldefs.h>

struct Struct_ov025_021e1d54 {
    unsigned char cells[6];
};

struct Struct_ov025_021e1d54_2 {
    unsigned char pad0;
    unsigned char marker;
    char pad2[2];
    int force;
    unsigned char* obj;
};

extern "C" int func_020493a4(unsigned char* obj);
extern "C" void func_020493b8(unsigned char* obj, unsigned char value);
extern "C" void func_ov025_021e169c(unsigned char* p, int val);
extern "C" void func_ov000_0216f82c(Struct_ov025_021e1d54* out, const int* cell);
extern "C" void func_ov025_021e13e0(unsigned char* grid, Struct_ov025_021e1d54_2* unit);
extern "C" void __clear(void* p, int n);

static inline int inline_ov025_021e1d54(unsigned char v) {
    return v >= 0xf2 ? 1 : 0;
}

// USA: func_ov025_021e1d54
extern "C" ARM void func_ov025_021e1d54(Struct_ov025_021e1d54_2* unit, unsigned char* grid) {
    Struct_ov025_021e1d54 var0;
    unsigned char counts[6];
    Struct_ov025_021e1d54 var2;
    Struct_ov025_021e1d54 tmp;
    int cell;
    Struct_ov025_021e1d54 var5;
    int from;
    cell = func_020493a4(unit->obj);
    func_ov000_0216f82c(&tmp, &cell);
    var0 = tmp;
    unsigned char var7 = 0;
    for (int i = 0; i < 6; i++) {
        if (var0.cells[i] == 0xff) continue;
        if (inline_ov025_021e1d54(grid[var0.cells[i]]) == 0) var7++;
    }
    if (unit->force == 0 && var7 >= 4) return;
    __clear(counts, 6);
    int best = 0;
    int var10 = 0xff;
    for (int i = 0; i < 6; i++) {
        int c = var0.cells[i];
        if (c == 0xff) continue;
        from = c;
        func_ov000_0216f82c(&var5, &from);
        var2 = var5;
        for (int j = 0; j < 6; j++) {
            int c2 = var2.cells[j];
            if (c2 == 0xff) continue;
            if (inline_ov025_021e1d54(grid[c2]) != 0) continue;
            counts[i]++;
            if (best < counts[i]) {
                best = counts[i];
                var10 = c2;
            }
        }
    }
    if (var10 >= 0x51) return;
    if (var7 < best || unit->force != 0) {
        func_ov025_021e169c(grid, unit->marker);
        if (var10 < 0x51) {
            func_ov025_021e13e0(grid, unit);
        }
        func_020493b8(unit->obj, var10);
    }
}
