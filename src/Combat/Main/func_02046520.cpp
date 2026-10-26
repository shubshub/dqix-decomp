#include <globaldefs.h>

extern "C" void func_020464a4(char* src, char* dst, int size);

#if defined(jpn)
enum { Enum_02046520_1004 = 0x2bc };
#else
enum { Enum_02046520_1004 = 0x3ec };
#endif

// USA: func_02046520
extern "C" ARM void func_02046520(char* base, char* src) {
    func_020464a4(src, base + Enum_02046520_1004, 0x40);
}
