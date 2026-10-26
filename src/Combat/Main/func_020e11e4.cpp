#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long arg0, unsigned int arg1, unsigned int flag);

struct Struct_02153628_4 {
    unsigned int field0;
};
extern struct Struct_02153628_4 data_02153628;

// USA: func_020e11e4
extern "C" ARM int func_020e11e4(void) {
    unsigned long long now = GetCurrentTimestamp();
    unsigned long long var1 = *(unsigned long long*)((char*)&data_02153628 + 4);
    unsigned long long diff = now - var1;
    unsigned long long var3 = diff << 6;
    unsigned long long var4 = _ll_udiv(var3, 0x82ea, 0);
    return var4 < data_02153628.field0;
}
