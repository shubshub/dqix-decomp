#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02169430_1256 = 0x4e4 };
enum { kRegione4 = 0xe0 };
enum { Enum_ov003_02169430_2400 = 0x800 };
enum { Enum_ov003_02169430_2456 = 0x868 };
enum { Enum_ov003_02169430_1260 = 0x4e8 };
#else
enum { Enum_ov003_02169430_1256 = 0x4e8 };
enum { kRegione4 = 0xe4 };
enum { Enum_ov003_02169430_2400 = 0x960 };
enum { Enum_ov003_02169430_2456 = 0x998 };
enum { Enum_ov003_02169430_1260 = 0x4ec };
#endif

#if defined(jpn)
extern "C" void func_0204500c(void*, void*, int);
#endif
#include "std_library_functions.h"

extern "C" int MessageSystem_GetInstance(void);
extern "C" int func_0205d6e4(void* obj, int flag);
extern "C" void func_ov003_0216abd8(void* obj, void* buf);
#if !defined(jpn)
extern "C" void func_0204500c(void* dst, void* src, int a, int b);
#endif

// USA: func_ov003_02169430
extern "C" ARM void func_ov003_02169430(void* p) {
    char* obj = (char*)p;
    int g = MessageSystem_GetInstance();
    unsigned char state = *(unsigned char*)(obj + Enum_ov003_02169430_1256);
    if (state == 0) {
        func_0205d6e4(obj + kRegione4, 1);
        memset(*(void**)(obj + 0x7c), 0, Enum_ov003_02169430_2400);
        func_ov003_0216abd8(obj, *(void**)(obj + 0x7c));
#if defined(jpn)
        func_0204500c((void*)g, *(void**)(obj + 0x7c), 0);
#else
        func_0204500c((void*)g, *(void**)(obj + 0x7c), 0, 0xe3);
#endif
        *(unsigned char*)(obj + Enum_ov003_02169430_1256) = *(unsigned char*)(obj + Enum_ov003_02169430_1256) + 1;
    } else if (state == 1) {
        if (*(int*)((char*)g + Enum_ov003_02169430_2456) == 0) {
            *(unsigned char*)(obj + Enum_ov003_02169430_1260) = 6;
            *(unsigned char*)(obj + Enum_ov003_02169430_1256) = 0;
        }
    }
}
