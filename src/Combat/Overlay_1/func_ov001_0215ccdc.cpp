#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, unsigned int);
struct Struct_02059cfc_4;

struct Struct_ov001_02165880_12 { void* unused0; char* base; };
extern Struct_ov001_02165880_12 data_ov001_02165880;
struct Struct_ov001_0215ccdc { int word0; char pad[8]; void* fieldC; };

// USA: func_ov001_0215ccdc
extern "C" ARM int func_ov001_0215ccdc(void* self) {
    int idx = func_ov017_021d60f4(self);
    Struct_ov001_0215ccdc* table = (Struct_ov001_0215ccdc*)data_ov001_02165880.base;
    int word0 = table[idx].word0;
    if (word0 == 0 || word0 == 4 || word0 == 5 || word0 == 1 || word0 == 6) {
        void* fieldC = table[idx].fieldC;
        if (fieldC != NULL) {
            int b = ((Object3D*)((struct Struct_02059cfc_4*)fieldC))->HasAnimationStopped();
            unsigned int val = (b == 0) ? 1 : 0;
            func_ov017_021d6134((char*)self + 0x8, val);
        }
    } else {
        func_ov017_021d6134((char*)self + 0x8, 1);
    }
    return 1;
}
