#include <globaldefs.h>

extern "C" int func_0200d8a8(void);

// USA: func_0200d8cc
extern "C" ARM int func_0200d8cc(int unused, unsigned char* buffer, unsigned int* arg2) {
    unsigned int i = 0;
    unsigned int max = *arg2;
    if (i >= max) goto end;
    do {
        int ch = func_0200d8a8();
        int var3 = ch & 0xff;
        buffer[i] = (unsigned char)ch;
        if (var3 == 0xd || var3 == 0xa) {
            *arg2 = i + 1;
            goto end;
        }
        i++;
    } while (i < max);
end:
    return 0;
}
