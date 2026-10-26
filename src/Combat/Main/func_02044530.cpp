#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02044530_2464 = 0x870, Enum_02044530_6586 = 0x17ea, kSubobjectOffset = 0x50 };
#else
enum { Enum_02044530_2464 = 0x9a0, Enum_02044530_6586 = 0x19ba, kSubobjectOffset = 0x90 };
#endif

extern "C" void func_0205c96c(void* obj, int arg);

// USA: func_02044530
extern "C" ARM void func_02044530(char* base, int arg) {
    if (*(int*)(base + Enum_02044530_2464) != 6) return;
    if (*(unsigned char*)(base + Enum_02044530_6586) == 0) return;
    func_0205c96c(base + kSubobjectOffset, arg);
}
