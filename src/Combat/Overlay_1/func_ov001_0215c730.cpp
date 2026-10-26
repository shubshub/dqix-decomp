#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);

struct Struct_ov001_02165880_11 { void* unused0; char* base; };
extern Struct_ov001_02165880_11 data_ov001_02165880;

struct Struct_02040668;
struct Struct_020406b0;
extern "C" void func_02040668(struct Struct_02040668*);
extern "C" void func_020406b0(struct Struct_020406b0*);

struct Struct_ov001_0215c730 { int word0; char pad[8]; void* fieldC; };

// USA: func_ov001_0215c730
extern "C" ARM int func_ov001_0215c730(void* self) {
    int idx = func_ov017_021d60f4(self);
    int w = func_ov017_021d60f4((char*)self + 0x8);
    Struct_ov001_0215c730* table = (Struct_ov001_0215c730*)data_ov001_02165880.base;
    if (table[idx].word0 != 2) return 1;
    if (w != 0) {
        func_02040668((struct Struct_02040668*)table[idx].fieldC);
    } else {
        func_020406b0((struct Struct_020406b0*)table[idx].fieldC);
    }
    return 1;
}
