#include <globaldefs.h>

// USA: func_020cf7e4
extern "C" ARM int func_020cf7e4(unsigned int packed) {
    int result = 0;
    int i;
    int shift;
    i = 0;
    shift = 0;
    do {
        if (((packed >> shift) & 0xf) >= 0xa) {
            return 0;
        }
        i++;
        shift += 4;
    } while (i < 8);
    {
        int mult;
        int var4;
        int var5;
        var5 = 0;
        var4 = 0;
        mult = 1;
        do {
            int digit = (packed >> var4) & 0xf;
            result += mult * digit;
            mult = mult * 10;
            var5++;
            var4 += 4;
        } while (var5 < 8);
    }
    return result;
}
