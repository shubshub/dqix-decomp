#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020863a0_2390 = 0x8be };
#else
enum { Enum_020863a0_2390 = 0x956 };
#endif

// USA: func_020863a0
extern "C" ARM void func_020863a0(unsigned char* obj) {
    *(short*)(obj + Enum_020863a0_2390 + 0) = 0;
    *(short*)(obj + Enum_020863a0_2390 + 2) = -1;
    *(short*)(obj + Enum_020863a0_2390 + 4) = 0;
    *(short*)(obj + Enum_020863a0_2390 + 6) = 0;
    *(short*)(obj + Enum_020863a0_2390 + 8) = -1;
}
