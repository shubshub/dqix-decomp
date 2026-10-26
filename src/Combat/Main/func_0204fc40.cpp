#include <globaldefs.h>

extern "C" int STD_GetStringLength(const char* s);
extern "C" int memcmp(unsigned char* a, unsigned char* b, int n);
extern "C" int func_02005a94(void* p);

// USA: func_0204fc40
extern "C" ARM int func_0204fc40(void* unused0, char** cursor, char* tag, short* out, int max) {
    int len = STD_GetStringLength(tag);
    char* p = *cursor;
    if (memcmp((unsigned char*)p, (unsigned char*)tag, len) == 0) {
        p += len;
        short i;
        for (i = 0; i < max; i++) {
            int val = func_02005a94(p);
            out[i] = (short)val;
            if (i == max - 1) break;
            while (*p != ',') p++;
            p++;
        }
        while (*p != '>' && *p != 0) p++;
        *cursor = p + 1;
        return 1;
    }
    return 0;
}
