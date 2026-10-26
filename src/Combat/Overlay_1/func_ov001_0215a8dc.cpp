#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov001_021588bc { int f0; int f4; };
#if defined(jpn)
extern "C" int func_ov001_021588bc(struct Struct_ov001_021588bc* obj, int a, int b);
#else
extern "C" int func_ov001_021588bc(struct Struct_ov001_021588bc* obj, int a, int b);
#endif

struct Struct_ov001_02159d44;
extern "C" int func_ov001_02159d44(struct Struct_ov001_02159d44* a, void* entries, int count);

extern "C" void func_ov001_0215a79c(void);

struct Struct_ov001_02165880_3 { char pad0[8]; int field8; char pad1[0x10]; char* field1c; void* field20; struct Struct_ov001_021588bc* field24; };
extern Struct_ov001_02165880_3 data_ov001_02165880;

// USA: func_ov001_0215a8dc
extern "C" ARM void func_ov001_0215a8dc(void) {
    *(unsigned short*)0x4000060 &= 0xcffb;
    func_ov001_021588bc(data_ov001_02165880.field24, data_ov001_02165880.field8, 8);
    for (int i = 0; i < 0x18; i++) {
        func_ov001_02159d44((struct Struct_ov001_02159d44*)(data_ov001_02165880.field1c + i * 0x588), data_ov001_02165880.field20, 0x1c);
    }
    func_ov001_0215a79c();
}
