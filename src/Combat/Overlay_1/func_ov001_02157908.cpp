#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov001_02156ba0;
extern "C" void func_ov001_02156ba0(Struct_ov001_02156ba0* buf);

// USA: func_ov001_02157908
extern "C" ARM void func_ov001_02157908(void* self) {
    int i;
    for (i = 0; i < 0x10; i++) {
        memset((char*)self + i * 0xc, 0, 0xc);
    }
    *(int*)((char*)self + 0xc0) = 0;
    *(int*)((char*)self + 0xc4) = 0;
    func_ov001_02156ba0((Struct_ov001_02156ba0*)((char*)self + 0xc8));
    *(int*)((char*)self + 0x464) = 0;
    *(int*)((char*)self + 0x468) = 0;
}
