#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void*);
struct Struct_ov001_0215cdf8;

struct Struct_ov001_02165880_14 { void* unused0; char* base; };
extern Struct_ov001_02165880_14 data_ov001_02165880;
struct Struct_ov001_0215cdf8_2 { int word0; char pad[8]; void* fieldC; };

// USA: func_ov001_0215cdf8
extern "C" ARM int func_ov001_0215cdf8(void* self) {
    int idx = func_ov017_021d60f4(self);
    void* fieldC = NULL;
    Struct_ov001_0215cdf8_2* table = (Struct_ov001_0215cdf8_2*)data_ov001_02165880.base;
    int word0 = table[idx].word0;
    if (word0 == 0 || word0 == 4 || word0 == 5 || word0 == 1 || word0 == 6) {
        fieldC = table[idx].fieldC;
    }
    if (fieldC == NULL) return 0;
    ((Object3D*)((struct Struct_ov001_0215cdf8*)fieldC))->Detach();
    return 1;
}
