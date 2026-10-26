#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02086380_2400 = 0x8c8, Enum_02086380_2402 = 0x8ca };
#else
enum { Enum_02086380_2400 = 0x960, Enum_02086380_2402 = 0x962 };
#endif

extern "C" void func_020863a0(unsigned char* obj);

// USA: func_02086380
extern "C" ARM void func_02086380(unsigned char* obj) {
    func_020863a0(obj);
    *(unsigned short*)(obj + Enum_02086380_2400) = 0;
    *(unsigned short*)(obj + Enum_02086380_2402) = 0;
}
