#include <globaldefs.h>
#include "World/Object3D.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_0218fcf8(int a, int b, int c);
extern "C" int func_ov017_0218f92c(int a, int b, int c);

struct Struct_ov001_02165880_15 { int pad0; unsigned char* elems; };
extern Struct_ov001_02165880_15 data_ov001_02165880;

struct Struct_ov001_0215cf98 { int type; char pad4[8]; void* unknown_c_; };

// USA: func_ov001_0215cf98
extern "C" ARM int func_ov001_0215cf98(void* self, int mode) {
    int ctx = (int)GetGameResources();
    int id = func_ov017_021d60f4(self);
    struct Struct_ov001_0215cf98* e = (struct Struct_ov001_0215cf98*)(data_ov001_02165880.elems + id * 0x10);

    if (e->type == 0 || e->type == 1 || e->type == 4 || e->type == 5 || e->type == 6) {
        void* p = e->unknown_c_;
        if (p) {
            short var4 = *(short*)((char*)p + 4);
            int a = func_ov017_021d60f4((char*)self + 8);
            int b = func_ov017_021d60f4((char*)self + 0x10);
            int c = func_ov017_021d60f4((char*)self + 0x18);
            unsigned short packed = (unsigned short)(a | (b << 5) | (c << 10));
            int extra = 0;
            if (mode - 4 > 0) {
                extra = func_ov017_021d60f4((char*)self + 0x20);
            }
            ((Object3D*)((unsigned char*)p))->SetField9e((unsigned char)(extra & 0xff));

            int cond = (var4 >= 0 && var4 <= 3);
            if (cond) {
                func_ov017_0218fcf8(ctx, var4, packed);
            } else {
                func_ov017_0218f92c(ctx, var4, packed);
            }
        }
    }
    return 1;
}
