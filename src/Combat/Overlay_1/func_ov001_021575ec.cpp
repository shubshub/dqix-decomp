#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov001_02156ba0;
extern "C" void func_ov001_02156ba0(struct Struct_ov001_02156ba0* buf);

// USA: func_ov001_021575ec
extern "C" ARM void func_ov001_021575ec(void* obj) {
    char* p = (char*)obj;
    for (int i = 0; i < 0x10; i++) {
        memset(p + i * 0xc, 0, 0xc);
        memset(p + 0xc0 + i * 0xc, 0, 0xc);
    }
    *(int*)(p + 0x180) = 0;
    *(int*)(p + 0x8c0) = 0;
    *(int*)(p + 0x184) = 0;
    func_ov001_02156ba0((struct Struct_ov001_02156ba0*)(p + 0x188));
    func_ov001_02156ba0((struct Struct_ov001_02156ba0*)(p + 0x524));
}
