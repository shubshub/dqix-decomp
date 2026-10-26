#include <globaldefs.h>

// USA: func_ov000_0215ed34
extern "C" ARM int func_ov000_0215ed34(char* obj, unsigned short* out, int maxCount) {
    int idx;
    int outCount = 0;
    idx = outCount;
    while (idx < (int)(((unsigned int)*(unsigned char*)(obj + 0x81b1) << 26) >> 30)) {
        unsigned short v = *(unsigned short*)(obj + idx * 0x18 + 0x81b4);
        out[outCount] = v;
        outCount++;
        if (outCount == maxCount) {
            return outCount;
        }
        idx++;
    }
    return outCount;
}
