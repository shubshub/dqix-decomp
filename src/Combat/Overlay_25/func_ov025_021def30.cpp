#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021def30_30474 = 0x78fa, Enum_ov025_021def30_21976 = 0x57c8, stateOffset = 0xe28, resetOffset = 0x78fc };
#else
enum { Enum_ov025_021def30_30474 = 0x770a, Enum_ov025_021def30_21976 = 0x55d8, stateOffset = 0xeac, resetOffset = 0x770c };
#endif

// USA: func_ov025_021def30
extern "C" ARM void func_ov025_021def30(unsigned char* obj) {
    if (*(unsigned short*)(obj+Enum_ov025_021def30_30474) == 0) {
        *(int*)(obj+Enum_ov025_021def30_21976) += 1;
    }
    *(int*)(obj+stateOffset) = 1;
    *(int*)(obj+resetOffset) = 0;
}
