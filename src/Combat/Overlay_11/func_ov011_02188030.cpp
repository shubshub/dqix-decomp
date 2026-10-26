#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" void func_ov011_02184c00(void* obj);

extern "C" void* func_ov017_021b2164(void);
extern "C" void MapVRAMBanksToMainBG(int v);

struct Struct_ov011_02188954 { int v[17]; };
extern struct Struct_ov011_02188954 data_ov011_02188954;

// USA: func_ov011_02188030
extern "C" ARM int func_ov011_02188030(struct TaggedNumber02184c30* p) {
	func_ov011_02184c00(func_ov017_021b2164());
	int idx = func_ov011_02184c30(p);
	struct Struct_ov011_02188954 table = data_ov011_02188954;
	MapVRAMBanksToMainBG(table.v[idx]);
	return 1;
}
