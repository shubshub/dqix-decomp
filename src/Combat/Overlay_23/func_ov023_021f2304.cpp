#include <globaldefs.h>

extern "C" int STD_GetStringLength(const char* s);
extern "C" void* memset(void* dst, int val, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern char data_ov023_021fe144;

// USA: func_ov023_021f2304
extern "C" ARM void func_ov023_021f2304(void* obj, char* label) {
    if (label == NULL) {
        return;
    }
    memset((char*)obj + 0xc, 0, 0x38);
    sprintf((char*)obj + 0xc + STD_GetStringLength((char*)obj + 0xc), &data_ov023_021fe144, label);
}
