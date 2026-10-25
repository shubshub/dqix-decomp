#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(void* dst, void* fmt, int val);
extern "C" int Font_GetTextWidth(void* builder, void* obj);
extern char data_020f0046;

// USA: func_02042658
ARM void FormatAbsIntToString02042658(void* obj, int value) {
    char buf[0x20];
    __clear(buf, 0x20);
    if (value < 0) value = -value;
    sprintf(buf, &data_020f0046, value);
    Font_GetTextWidth(buf, obj);
}
