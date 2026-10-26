#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_021d612c(void*);

struct Struct_ov001_0215cd50;
struct Object3D;

struct Struct_ov001_02165880_13 { void* unused0; char* base; };
extern Struct_ov001_02165880_13 data_ov001_02165880;
struct Struct_ov001_0215cd50_2 { int word0; char pad[8]; void* fieldC; };

// USA: func_ov001_0215cd50
extern "C" ARM int func_ov001_0215cd50(void* self, int mode) {
    int idx1 = func_ov017_021d60f4(self);
    int idx2 = func_ov017_021d60f4((char*)self + 0x8);
    int extra = 0;
    if (mode >= 3) {
        extra = func_ov017_021d612c((char*)self + 0x10);
    }
    Struct_ov001_0215cd50_2* table = (Struct_ov001_0215cd50_2*)data_ov001_02165880.base;
    void* var4 = NULL;
    void* var5 = var4;
    int w = table[idx1].word0;
    if (w == 0 || w == 4 || w == 5 || w == 1 || w == 6) {
        var4 = table[idx1].fieldC;
    }
    w = table[idx2].word0;
    if (w == 0 || w == 4 || w == 5 || w == 1 || w == 6) {
        var5 = table[idx2].fieldC;
    }
    if (var4 == NULL || var5 == NULL) return 0;
    ((Object3D*)((struct Struct_ov001_0215cd50*)var4))->Attach((Object3D*)var5, (char*)extra);
    return 1;
}
