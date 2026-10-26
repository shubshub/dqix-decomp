#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov001_021601f8(void* a, void* b);

struct Struct_ov001_02160338 { char pad0[0x44]; int field44; char pad1[0x54 - 0x48]; struct Struct_ov001_02160338* next; };
struct Big_02160338 { 
#if defined(jpn)
    char pad0[0x430];
#else
    char pad0[0x410];
#endif
 int unknown_410_; char pad1[0x41c - 0x414]; struct Struct_ov001_02160338* unknown_41c_; char pad2[0x834 - 0x420]; unsigned char unknown_834_; };
struct Struct_ov001_02160338_3 { char pad[0x90]; int field90; };

// USA: func_ov001_02160338
extern "C" ARM int func_ov001_02160338(void* obj) {
    Big_02160338* big = (Big_02160338*)Zone3D_GetInstance();
    Struct_ov001_02160338_3* d = (Struct_ov001_02160338_3*)LightingManager::GetInstance();
    if (big->unknown_834_ != 0) {
        return 1;
    }
    d->field90 = func_ov017_021d60f4(obj);
    if (big->unknown_410_ == 1) {
        Struct_ov001_02160338* node = big->unknown_41c_;
        while (node != NULL) {
            if (node->field44 != 0) {
                func_ov001_021601f8((void*)node->field44, (char*)node + 4);
            }
            node = node->next;
        }
        big->unknown_834_ = 1;
    }
    return 1;
}
