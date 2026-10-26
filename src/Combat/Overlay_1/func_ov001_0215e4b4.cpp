#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();
extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_0215e4b4
extern "C" ARM int func_ov001_0215e4b4(void* obj) {
#if defined(jpn)
    enum { flagOffset = 0x789, Enum_ov001_0215e4b4_2472 = 0x878 };
#else
    enum { flagOffset = 0x95b, Enum_ov001_0215e4b4_2472 = 0x9a8 };
#endif
    char* p = (char*)MessageSystem_GetInstance();
    if (p == NULL) return 0;
    int v = func_ov017_021d60f4(obj);
    p += 0x1000;
    *(unsigned char*)(p + flagOffset) |= 0x4;
    *(int*)(p - 0x1000 + Enum_ov001_0215e4b4_2472) = v;
    return 1;
}
