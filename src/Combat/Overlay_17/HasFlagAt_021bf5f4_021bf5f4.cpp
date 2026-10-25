#include <globaldefs.h>

struct Base02019508;
struct Entry02019508;
extern "C" struct Base02019508* Zone3D_GetInstance(void* self);
struct Entry02019508* FindEntryByKeys02019508(struct Base02019508* base, int key1, int key2);

// USA: func_ov017_021bf5f4
ARM int HasFlagAt_021bf5f4_021bf5f4(void* self) {
    struct Base02019508* base = Zone3D_GetInstance(self);
    char* obj = *(char**)((char*)self + 0xc);
    unsigned short key1 = *(unsigned short*)(obj + 0x2c);
    unsigned short key2 = *(unsigned short*)(obj + 0x2e);
    struct Entry02019508* e = FindEntryByKeys02019508(base, key1, key2);
    return e != 0 && *(int*)((char*)e + 0x54) != 0;
}
