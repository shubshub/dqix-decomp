#include <globaldefs.h>

extern int data_ov002_0216c9c0;

// USA: func_ov002_0215a9cc
extern "C" ARM void func_ov002_0215a9cc(void* obj, int val) {
#if defined(jpn)
    enum { Enum_ov002_0215a9cc_7168 = 0x1a00, Enum_ov002_0215a9cc_10 = 0xd2, Enum_ov002_0215a9cc_3196 = 0xb40 };
#else
    enum { Enum_ov002_0215a9cc_7168 = 0x1c00, Enum_ov002_0215a9cc_10 = 0xa, Enum_ov002_0215a9cc_3196 = 0xc7c };
#endif
    unsigned char* p = (unsigned char*)obj + Enum_ov002_0215a9cc_7168;
    short idx = *(short*)(p + Enum_ov002_0215a9cc_10);
    int off = (&data_ov002_0216c9c0)[idx];
    unsigned char* q = (unsigned char*)obj + off + 0x1000;
    q[Enum_ov002_0215a9cc_3196] = (unsigned char)val;
}
