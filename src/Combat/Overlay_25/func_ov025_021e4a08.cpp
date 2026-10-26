#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e4a08_12 = 0x4 };
#else
enum { Enum_ov025_021e4a08_12 = 0xc };
#endif

#include "Filesystem/BackgroundLoader.h"

struct Struct_ov025_021ef988_9 { char pad[Enum_ov025_021e4a08_12]; void* target; };
extern struct Struct_ov025_021ef988_9 data_ov025_021ef988;

extern "C" void* func_ov025_021e8a54(char* obj);
extern "C" void func_ov025_021e278c(int value, char* dst);
extern "C" int func_ov025_021e25a4(char* buf);
extern "C" void func_ov025_021eb05c(void* ctx, int val);

// USA: func_ov025_021e4a08
extern "C" ARM int func_ov025_021e4a08(unsigned char* obj) {
    char buf[0x50];
    (int)BackgroundLoader::GetInstance();
    func_ov025_021e8a54((char*)data_ov025_021ef988.target);
    int v = *(int*)(obj + 8);
    func_ov025_021e278c(v, buf);
    int r = func_ov025_021e25a4(buf);
    func_ov025_021eb05c(data_ov025_021ef988.target, r);
    return 1;
}
