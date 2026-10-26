#include <globaldefs.h>

extern "C" ARM void* func_ov031_022133f8(unsigned int flags);

// USA: func_ov031_02214afc
extern "C" ARM int func_ov031_02214afc(int target) {
    unsigned char* base = (unsigned char*)func_ov031_022133f8(0x10) + 0xd00;
    unsigned char i;
    unsigned char count;
    unsigned short flags = *(unsigned short*)(base + 0x16);
    if (flags == 0) {
        return -1;
    }
    i = 0;
    count = i;
    do {
        if (flags & (1 << i)) {
            if (count == target) {
                return (signed char)i;
            }
            count++;
        }
        i++;
    } while (i < 13);
    return -1;
}
