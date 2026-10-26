#include <globaldefs.h>

extern "C" unsigned long long _ull_mod(unsigned long long a, unsigned long long b);

// USA: func_ov023_021f6324
extern "C" ARM void func_ov023_021f6324(int count, unsigned char* ptr) {
    unsigned long long var0 = 0;
    while (count-- > 0) {
        unsigned char b = *ptr++;
        var0 = (var0 << 8) + b;
        var0 = _ull_mod(var0, 0xc2a030d4ULL);
    }
}
