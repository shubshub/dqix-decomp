#include <globaldefs.h>

extern "C" void func_020464a4(char* src, char* dst, int size);

#if defined(jpn)
enum { Enum_02046504_940 = 0x27c };
#else
enum { Enum_02046504_940 = 0x3ac };
#endif

// USA: func_02046504
extern "C" ARM void func_02046504(char* base, char* src) {
    func_020464a4(src, base + Enum_02046504_940, 0x40);
}
