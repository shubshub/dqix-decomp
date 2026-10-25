#include <globaldefs.h>

int MessageSystem_GetInstance();
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_0215e414
ARM int SetFieldFromGlobalPtryte_0215e414_0215e414(void* obj) {
#if defined(jpn)
    enum { fieldOffset = 0x24 };
#else
    enum { fieldOffset = 0x58 };
#endif
    int base = MessageSystem_GetInstance();
    if (base == 0) return 0;
#if defined(jpn)
    unsigned short v = **(unsigned short**)(base + fieldOffset);
#else
    unsigned char v = **(unsigned char**)(base + fieldOffset);
#endif
    func_ov017_021d6134(obj, v);
    return 1;
}
