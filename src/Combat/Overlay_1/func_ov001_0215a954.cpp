#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov001_021588bc { int f0; int f4; };
#if defined(jpn)
extern "C" int func_ov001_021588bc(Struct_ov001_021588bc* obj, int a, int b);
#else
extern "C" int func_ov001_021588bc(Struct_ov001_021588bc* obj, int a, int b);
#endif

struct Struct_ov001_02165880_4 { char pad0[8]; int field8; char pad1[0x18]; Struct_ov001_021588bc* field24; };
extern Struct_ov001_02165880_4 data_ov001_02165880;

struct Struct_ov001_021658b8_2 { char pad0[0xe4]; int unknown_e4_; char pad1[4]; int unknown_ec_; };
extern Struct_ov001_021658b8_2 data_ov001_021658b8;

// USA: func_ov001_0215a954
extern "C" ARM void func_ov001_0215a954(void) {
    *(unsigned short*)0x4000060 = (*(unsigned short*)0x4000060 & ~0x3000) | 4;
    *(unsigned short*)0x4000340 = 0;
    func_ov001_021588bc(data_ov001_02165880.field24, data_ov001_02165880.field8, 8);
    data_ov001_021658b8.unknown_ec_ = 0;
    if (data_ov001_021658b8.unknown_e4_) data_ov001_021658b8.unknown_e4_ = 0;
}
