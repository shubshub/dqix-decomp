#include <globaldefs.h>

struct Struct_ov031_022492e2 {
    unsigned short l;
    unsigned short t;
    unsigned short r;
    unsigned short b;
};

// USA: func_ov031_0223cc18
extern "C" ARM void func_ov031_0223cc18(int arg0, int window, const Struct_ov031_022492e2* bounds) {
    if (arg0 == 1) {
        if (window == 0) {
            int x1 = bounds->l;
            int var1 = bounds->t;
            int x2 = bounds->r;
            int y2 = bounds->b;
            *(volatile unsigned short*)0x04001040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04001044 = ((var1 << 8) & 0xff00) | (y2 & 0xff);
        } else {
            int x1 = bounds->l;
            int var5 = bounds->t;
            int x2 = bounds->r;
            int y2 = bounds->b;
            *(volatile unsigned short*)0x04001042 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04001046 = ((var5 << 8) & 0xff00) | (y2 & 0xff);
        }
    } else {
        if (window == 0) {
            int x1 = bounds->l;
            int var9 = bounds->t;
            int x2 = bounds->r;
            int y2 = bounds->b;
            *(volatile unsigned short*)0x04000040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04000044 = ((var9 << 8) & 0xff00) | (y2 & 0xff);
        } else {
            int x1 = bounds->l;
            int var13 = bounds->t;
            int x2 = bounds->r;
            int y2 = bounds->b;
            *(volatile unsigned short*)0x04000042 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04000046 = ((var13 << 8) & 0xff00) | (y2 & 0xff);
        }
    }
}
