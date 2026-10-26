#include <globaldefs.h>

extern "C" int func_ov031_02204b50(char* str, char** arg1);

// USA: func_ov031_02204b84
extern "C" ARM int func_ov031_02204b84(char* str, unsigned int* out) {
    unsigned int accum = 0;
    char* p = str;
    int var2 = 0;
    do {
        char* next;
        int val = func_ov031_02204b50(p, &next);
        if (p == next)
            return 0;
        p = next;
        if ((unsigned int)val > 0xff)
            goto fail;
        if (var2 != 3) {
            unsigned char c = *p;
            p = p + 1;
            if (c != '.')
                goto fail;
        }
        if (var2 == 3) {
            if (*(unsigned char*)p != 0)
                goto fail;
        }
        goto accumulate;
fail:
        return 0;
accumulate:
        var2++;
        accum = val | (accum << 8);
    } while (var2 < 4);
    *out = accum;
    return 1;
}
