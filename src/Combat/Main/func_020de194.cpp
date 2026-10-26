#include <globaldefs.h>

extern int (*data_020f2adc[])(unsigned short);

// USA: func_020de194
extern "C" ARM int func_020de194(void* s) {
    unsigned int v = *(unsigned short*)((char*)s + 0x1c);
    if (v >= 0xfffb) {
        v = data_020f2adc[0xffff - v](*(unsigned short*)((char*)s + 0x1a));
    }
    return v;
}
