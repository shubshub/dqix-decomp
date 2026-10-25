#include <globaldefs.h>

extern void* data_ov031_02290cf8;
extern unsigned char data_ov031_022491fc[6];
extern "C" int memcmp(void* a, void* b, int n);

// USA: func_ov031_02235984  (semantic: CountMismatches_02235984)
extern "C" ARM int func_ov031_02235984(void** out) {
    int count = 0;
    int i = 0;
    char* p = (char*)data_ov031_02290cf8 + 0x1300;
    *out = p;
    do {
        int r = memcmp(p + 0x20, data_ov031_022491fc, 6);
        i++;
        if (r != 0) count++;
        p += 0x2a;
    } while (i < 20);
    return count;
}
