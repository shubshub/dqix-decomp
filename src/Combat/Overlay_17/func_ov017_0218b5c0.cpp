#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD_0 0x4c0
#else
#define REGION_FIELD_0 0x6d0
#endif

extern "C" void MapDisplay_SetMemberUpdatesEnabled(unsigned char* base, int set, int bit);

struct Struct_ov017_021d82e0_4 { int a; int b; };
extern Struct_ov017_021d82e0_4 data_ov017_021d82e0;

// USA: func_ov017_0218b5c0
extern "C" ARM void func_ov017_0218b5c0(int set, int bit) {
    int b = data_ov017_021d82e0.b;
    if (b == 0) return;
    int val = *(int*)((char*)b + 0x3000 + REGION_FIELD_0);
    if (val == 0) return;
    MapDisplay_SetMemberUpdatesEnabled((unsigned char*)val, set, bit);
}
