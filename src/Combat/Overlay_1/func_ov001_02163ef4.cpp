#include <globaldefs.h>

union Struct_020117f0_2 { int i; float f; };
struct Struct_ov001_02163ef4 { int type; Struct_020117f0_2 value; };

extern "C" int func_ov017_021d60f4(Struct_ov001_02163ef4* a);
extern "C" float func_ov017_021d6110(Struct_ov001_02163ef4* a);
extern "C" void* Zone3D_GetInstance(void);
struct Entry02019508;
struct Base02019508;
extern "C" ARM struct Entry02019508* Zone3D_FindSceneElement(struct Base02019508* base, int key1, int key2);

// USA: func_ov001_02163ef4
extern "C" ARM int func_ov001_02163ef4(Struct_ov001_02163ef4* obj) {
    int key1 = func_ov017_021d60f4(obj);
    int key2 = func_ov017_021d60f4((Struct_ov001_02163ef4*)((char*)obj + 0x8));
    void* g = Zone3D_GetInstance();
    if (!g) {
        return 0;
    }
    struct Entry02019508* e = Zone3D_FindSceneElement((struct Base02019508*)g, key1, key2);
    if (!e) {
        return 0;
    }
    float val = func_ov017_021d6110((Struct_ov001_02163ef4*)((char*)obj + 0x10));
    *(short*)((char*)e + 0x6) = (short)(4096.0f * val);
    return 1;
}
