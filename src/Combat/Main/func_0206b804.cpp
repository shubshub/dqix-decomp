#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0206b804_6592 = 0x17f0, Enum_0206b804_6605 = 0x17fe, Enum_0206b804_64 = 0xc, Enum_0206b804_6493 = 0x178b };
#else
enum { Enum_0206b804_6592 = 0x19c0, Enum_0206b804_6605 = 0x19cd, Enum_0206b804_64 = 0x40, Enum_0206b804_6493 = 0x195d };
#endif

extern const signed char data_020e7e10[];
extern const signed char data_020e7e1c[];

// USA: func_0206b804
extern "C" ARM void func_0206b804(char* obj, int* out1, int* out2) {
    *out2 = 0;
    *out1 = 0;
    if (*(unsigned char*)(obj + Enum_0206b804_6592) != 0) {
        int idx;
        *(unsigned char*)(obj + Enum_0206b804_6605) = 1;
        *(int*)(obj + Enum_0206b804_64) = 0;
        idx = *(unsigned char*)(obj + Enum_0206b804_6493) & 3;
        *out1 = data_020e7e10[idx];
        *out2 = data_020e7e1c[idx];
    }
}
