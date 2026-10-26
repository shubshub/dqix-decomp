#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7000
#define REGION_OFFSET_1 0xea
#define REGION_OFFSET_2 0xe0
#else
#define REGION_OFFSET_0 0x6e00
#define REGION_OFFSET_1 0xfa
#define REGION_OFFSET_2 0xf0
#endif


// USA: func_ov000_0216346c
extern "C" ARM void func_ov000_0216346c(char* obj, int val) {
    int i;
    for (i = 0; i < *(short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1); i++) {
        if (val == *(short*)(obj + i * 2 + REGION_OFFSET_0 + REGION_OFFSET_2)) break;
    }
    if (i != *(short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1)) return;
    {
        short* var1 = (short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1);
        int var2 = *var1;
        short* var3 = (short*)(obj + *(short*)(obj + REGION_OFFSET_0 + REGION_OFFSET_1) * 2 + REGION_OFFSET_0 + REGION_OFFSET_2);
        *var1 = var2 + 1;
        *var3 = (short)val;
    }
}
