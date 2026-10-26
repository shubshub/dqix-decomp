#include <globaldefs.h>

struct Struct_ov031_02239368 { unsigned char pad[0x40]; int field40; };
struct Struct_ov031_02290d18_4 { void (*fn)(int, void*, int); struct Struct_ov031_02239368* inner; };
extern struct Struct_ov031_02290d18_4 data_ov031_02290d18;
extern int data_ov031_0224c318[];
extern int data_ov031_0224c340;
extern int data_ov031_0224c348;

// USA: func_ov031_02239368
extern "C" ARM void func_ov031_02239368(int val) {
    if (data_ov031_02290d18.fn != 0) {
        data_ov031_02290d18.fn(0x8000000, &data_ov031_0224c340, data_ov031_0224c318[data_ov031_02290d18.inner->field40]);
    }
    data_ov031_02290d18.inner->field40 = val;
    if (data_ov031_02290d18.fn != 0) {
        data_ov031_02290d18.fn(0x8000000, &data_ov031_0224c348, data_ov031_0224c318[data_ov031_02290d18.inner->field40]);
    }
}
