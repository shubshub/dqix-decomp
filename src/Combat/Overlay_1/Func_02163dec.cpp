#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* a);
extern "C" void* Zone3D_GetInstance(void);
struct Entry02019508;
struct Base02019508;
ARM struct Entry02019508* FindEntryByKeys02019508(struct Base02019508* base, int key1, int key2);
struct Struct02013380;
void SetFlag0x40AndToggle0x4(Struct02013380* obj, int unused, int clear4);

// USA: func_ov001_02163dec  (semantic: Func_02163dec)
extern "C" ARM int func_ov001_02163dec(void* obj) {
    int key1 = func_ov017_021d60f4(obj);
    int key2 = func_ov017_021d60f4((char*)obj + 0x8);
    void* g = Zone3D_GetInstance();
    if (!g) {
        return 0;
    }
    struct Entry02019508* e = FindEntryByKeys02019508((struct Base02019508*)g, key1, key2);
    if (!e) {
        return 0;
    }
    int c = func_ov017_021d60f4((char*)obj + 0x10);
    SetFlag0x40AndToggle0x4((Struct02013380*)e, key1, c);
    return 1;
}
