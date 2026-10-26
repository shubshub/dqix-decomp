#if defined(jpn)
#define R(j,u) (j)
#define func_ov008_021889f8 func_ov008_0218973c
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_0207fd88;
extern "C" unsigned int func_0207fd88(Struct_0207fd88*);
extern "C" void func_ov014_02185c90(char*);

// USA: func_ov014_02186dc8
extern "C" ARM void func_ov014_02186dc8(char* self) {
    if (*(unsigned char*)(self + 0x17a) != 0) {
        func_0207fd88((Struct_0207fd88*)(*(unsigned int*)(self + 0xc0)));
    }
    func_ov014_02185c90(self);
}
