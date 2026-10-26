#include <globaldefs.h>

extern "C" ARM void* func_ov031_02200af8(int* count);
extern "C" ARM void func_ov031_02202e44(void* p, int len);
extern "C" ARM void func_ov031_0220186c(void* p, int len);
extern "C" ARM void func_ov031_02200bb8(void);

// USA: func_ov031_02203008
extern "C" ARM void func_ov031_02203008(void) {
    int count;
    for (;;) {
        char* p = (char*)func_ov031_02200af8(&count);
        if ((unsigned int)count > 0x22) {
            unsigned short tag = *(unsigned short*)(p + 0xc);
            unsigned short swapped = (tag >> 8) | (tag << 8);
            switch (swapped) {
            case 0x800:
                func_ov031_02202e44(p + 0xe, count - 0xe);
                break;
            case 0x806:
                func_ov031_0220186c(p + 0xe, count - 0xe);
                break;
            }
        }
        func_ov031_02200bb8();
    }
}
