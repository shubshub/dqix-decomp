#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_021725a4_1816 = 0x614 };
enum { Enum_ov003_021725a4_1120 = 0x35c };
#else
enum { Enum_ov003_021725a4_1816 = 0x718 };
enum { Enum_ov003_021725a4_1120 = 0x460 };
#endif


extern "C" int memcmp(void* a, void* b, int n);

// USA: func_ov003_021725a4
extern "C" ARM int func_ov003_021725a4(void* obj, void* other) {
    int i;
    unsigned int field = *(unsigned int*)((char*)other + 0x6c);
    if (((field << 5) >> 31) == 0) {
        return 0;
    }
    unsigned char count = *((unsigned char*)obj + Enum_ov003_021725a4_1816);
    if (count == 0) {
        return 1;
    }
    for (i = 0; i < count; i++) {
        char* base = (char*)obj + Enum_ov003_021725a4_1120;
        if (memcmp(base + i * 0xe8 + 0x14, (char*)other + 0x14, 6) == 0) {
            return 0;
        }
    }
    return 1;
}
