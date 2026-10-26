#include <globaldefs.h>

struct Struct_020098fc {
    unsigned char unknown_0_;
    char pad1;
    short unknown_2_;
    unsigned char count;
    unsigned char digits[0x20] __attribute__((aligned(1)));
};

// USA: func_02009d1c
extern "C" ARM int func_02009d1c(Struct_020098fc* first, Struct_020098fc* second) {
    unsigned char var0 = first->digits[0];
    if (var0 == 0) return second->digits[0] == 0;
    if (second->digits[0] == 0) return var0 == 0;
    if (first->unknown_2_ != second->unknown_2_) goto different;
    int i;
    int limit;
    int var3;
    var3 = first->count;
    int var4 = second->count;
    i = 0;
    limit = var3;
    if (limit > var4) limit = var4;
    if (limit > 0) {
        do {
            if (first->digits[i] != second->digits[i]) return 0;
            i++;
        } while (i < limit);
    }
    if (limit == var3) first = second;
    if (i < first->count) {
        do {
            if (first->digits[i]) return 0;
            i++;
        } while (i < first->count);
    }
    return 1;
different:
    return 0;
}
