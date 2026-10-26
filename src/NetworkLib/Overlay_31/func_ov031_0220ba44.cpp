#include <globaldefs.h>

struct Struct_ov031_0220ba44 {
    unsigned char index;
    unsigned char unknown_1_;
    unsigned char unknown_2_[256];
};

// USA: func_ov031_0220ba44
extern "C" ARM void func_ov031_0220ba44(Struct_ov031_0220ba44* state, const unsigned char* key, int arg2) {
    int value;
    state->index = 0;
    state->unknown_1_ = 0;
    unsigned char* var1 = state->unknown_2_;
    int var2 = 0;
    do {
        var1[var2] = var2;
        var2++;
    } while (var2 < 256);
    unsigned char var3;
    unsigned char var4 = 0;
    var3 = var4;
    int index = var4;
    do {
        value = var1[index];
        unsigned char var6 = key[var4];
        var4++;
        var3 = var3 + (value + var6);
        unsigned char var7 = var1[var3];
        if (var4 >= arg2) var4 = 0;
        var1[index] = var7;
        var1[var3] = value;
        index++;
    } while (index < 256);
}
