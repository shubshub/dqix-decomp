#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" int func_01ff85b8(void* buf, int size);
extern "C" void func_02075acc(int id, void* buf, int size, int flag);
extern char data_020f1bf0;

struct Struct_020aba5c {
    int hdr;
    char pad[4];
    char str[12];
};

// USA: func_020aba5c
extern "C" ARM int func_020aba5c(int flag) {
    int local0;
    if (!func_02075910(0, &local0, 1, 0)) return 0;

    struct Struct_020aba5c buf;
    memset(&buf, 0, 0x14);
    strcpy(buf.str, &data_020f1bf0);
    buf.hdr = func_01ff85b8((char*)&buf + 4, 0x10);
    func_02075acc(flag ? 0x8010 : 0x10, &buf, 0x14, 0);
    return 1;
}
