#include <globaldefs.h>
#if defined(jpn)
#define data_020f1f14 data_020f2080
#define data_020f1ef8 data_020f2064
#endif

struct Struct_020f1f14_2 { unsigned char pad[0x18]; };
struct Struct_020f1ef8 {
    unsigned char pad[8];
    struct Struct_020f1f14_2 *e0, *e1, *e2, *e3, *e4;
};

extern struct Struct_020f1f14_2 data_020f1f14[];
extern struct Struct_020f1ef8 data_020f1ef8;

// USA: func_020bb444
extern "C" ARM void func_020bb444(int arg0, int i1, int i2, int arg3, int arg4) {
    data_020f1ef8.e0 = &data_020f1f14[arg0];
    data_020f1ef8.e1 = &data_020f1f14[i1];
    data_020f1ef8.e2 = &data_020f1f14[i2];
    data_020f1ef8.e3 = &data_020f1f14[arg3];
    data_020f1ef8.e4 = &data_020f1f14[arg4];
}
