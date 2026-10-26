#include <globaldefs.h>

struct Struct_ov031_02290c5c_6 { unsigned char idx; int field4; };
extern Struct_ov031_02290c5c_6 data_ov031_02290c5c;
extern unsigned char data_ov031_02248dc4[];

extern "C" int func_ov031_02234ff8(int, int, int);

// USA: func_ov031_02229748
extern "C" ARM int func_ov031_02229748(void) {
    unsigned char idx = data_ov031_02290c5c.idx;
    int field4 = data_ov031_02290c5c.field4;
    unsigned char val = data_ov031_02248dc4[idx];
    return func_ov031_02234ff8(field4, val, val);
}
