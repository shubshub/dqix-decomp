#include <globaldefs.h>

extern "C" void func_020464a4(char* src, char* dst, int size);

// USA: func_020464e8
#if defined(jpn)
extern "C" ARM void func_020464e8(char* base, char* src) {
    func_020464a4(src, base + 0x23c, 0x40);
}
#else
extern "C" ARM void func_020464e8(char* base, int index, char* src) {
    func_020464a4(src, base + 0x2ec + index * 0x40, 0x40);
}
#endif
