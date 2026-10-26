#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
struct Struct_ov011_02184c14;
extern "C" void func_ov011_02184c14(struct Struct_ov011_02184c14* obj);

extern "C" void* func_ov017_021b2164(void);
extern "C" void MapVRAMBanksToSubBG(int v);

struct Struct_ov011_02188904 { int v[4]; };
extern struct Struct_ov011_02188904 data_ov011_02188904;

// USA: func_ov011_02188090
extern "C" ARM int func_ov011_02188090(struct TaggedNumber02184c30* p) {
    void* ctx = func_ov017_021b2164();
    func_ov011_02184c14((struct Struct_ov011_02184c14*)ctx);
    int idx = func_ov011_02184c30(p);
    struct Struct_ov011_02188904 table = data_ov011_02188904;
    MapVRAMBanksToSubBG(table.v[idx]);
    return 1;
}
