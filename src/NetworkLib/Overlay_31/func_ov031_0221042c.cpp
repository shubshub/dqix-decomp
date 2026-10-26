#include <globaldefs.h>

extern void* data_ov031_0224e588;
extern "C" void func_ov031_02210358(int a, int b);
extern "C" ARM int func_ov031_02207360(int a, int b, int c);

// USA: func_ov031_0221042c
extern "C" ARM int func_ov031_0221042c(unsigned char* buf) {
    int n = 0;
    unsigned int var1;
    if (data_ov031_0224e588 == NULL) {
        return n - 0x1c;
    }
    unsigned int total = *(unsigned int*)buf;
    if (total > 0x414) {
        func_ov031_02210358(6, -0x32);
        return ~0x22;
    }
    var1 = n;
    if (var1 < total) {
        do {
            int handle = *(int*)((char*)data_ov031_0224e588 + 0x1b8);
            n = func_ov031_02207360(handle, (int)buf, total - var1);
            if (n > 0) {
                var1 += n;
                buf += n;
                if (var1 >= total) {
                    return var1;
                }
            } else if (n < 0) {
                func_ov031_02210358(6, -0x32);
                return n;
            }
        } while (var1 < total);
    }
    return n;
}
