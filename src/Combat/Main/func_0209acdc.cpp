#include <globaldefs.h>

struct Struct_0209a9dc_2;
struct Struct_0209a9dc_3 { unsigned short id; unsigned short pad; };

extern "C" struct Struct_0209a9dc_3* func_0209a9dc(struct Struct_0209a9dc_2* h, int i);

// USA: func_0209acdc
extern "C" ARM int func_0209acdc(struct Struct_0209a9dc_2* holder, unsigned char* ids, unsigned int count, unsigned short* out) {
    unsigned int i;
    int outCount = 0;
    for (i = 0; i < count; i++) {
        struct Struct_0209a9dc_3* e = func_0209a9dc(holder, ids[i]);
        if (e != NULL) {
            out[outCount] = e->pad;
            outCount++;
        }
    }
    return outCount;
}
