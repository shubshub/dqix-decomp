#include <globaldefs.h>

struct Struct_ov001_02165880_6 { char pad[0x1c]; char* base; };
extern struct Struct_ov001_02165880_6 data_ov001_02165880;

// USA: func_ov001_0215ab20
extern "C" ARM int func_ov001_0215ab20(int index) {
    if (index < 0 || index >= 0x18) return 0;
    return (int)(data_ov001_02165880.base + index * 0x588);
}
