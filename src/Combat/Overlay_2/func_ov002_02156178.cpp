#include <globaldefs.h>

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

extern "C" int func_ov023_021dc488(void* obj);

// USA: func_ov002_02156178
extern "C" ARM void func_ov002_02156178(unsigned char* obj) {
    if ((*(int*)(obj + 0x2000 + RG(0x47c, 0x2ac)) & 1) == 0) return;
    if (func_ov023_021dc488(obj + RG(0x50, 0x38)) != 0) {
        *(int*)(obj + 0x2000 + RG(0x47c, 0x2ac)) &= ~1;
    }
}
