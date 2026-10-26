#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void WindowPane_Init(void* obj);
int AllocateVRAMStagingMemory(unsigned int);

#if defined(jpn)
enum { Enum_02044c74_2509 = 0x7fe, Enum_02044c74_8 = 12 };
#else
enum { Enum_02044c74_2509 = 0x9cd, Enum_02044c74_8 = 8 };
#endif

// USA: func_02044c74
extern "C" ARM void func_02044c74(void* obj, void* out) {
    char* o = (char*)obj;
    char* dst = (char*)out;
    WindowPane_Init(out);
    void* buf = (void*)AllocateVRAMStagingMemory(0x4800);
    if (buf) {
        unsigned char* p = (unsigned char*)(o + 0x1000);
        if (p[Enum_02044c74_2509]) {
            p[Enum_02044c74_2509] = 0;
            memset(buf, 0, 0x4800);
        }
        *(short*)(dst + 0xac) = 0;
        *(short*)(dst + 0xae) = 6;
        *(short*)(dst + 0xa8) = 0x20;
        *(short*)(dst + 0xaa) = 0x12;
        *(void**)(dst + 0x8) = buf;
        *(int*)(dst + 0xa4) = 0x4800;
        *(int*)(dst + 0xa0) = 0;
        *(short*)(dst + 0xc2) = 0;
        *(short*)(dst + 0xb0) = 0;
        *(short*)(dst + 0xb2) = 0;
        *(short*)(dst + 0xb4) = Enum_02044c74_8;
        *(short*)(dst + 0xb6) = Enum_02044c74_8;
        *(short*)(dst + 0xb8) = Enum_02044c74_8;
        *(short*)(dst + 0xba) = Enum_02044c74_8;
    }
}
