#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int GameState_UpdatePlayClocks(int commit);
extern "C" int* func_020936f8(void);
extern "C" void func_02094030(int* g, short h4, short h6, signed char b8);
extern "C" void func_ov017_021d1118(int a, int b, int c, int d);

struct Struct_ov017_021d1078 {
    char pad0[4];
    unsigned char value : 7;
    unsigned char unknown_4_7_ : 1;
    unsigned char field5;
};

// USA: func_ov017_021d1078
extern "C" ARM void func_ov017_021d1078(int id, Struct_ov017_021d1078* node, void* unused0, void* unused1, void* searchObj) {
    signed char cur = LinkSession_GetOwnSlot((SearchStruct0202c1a4*)searchObj);
    if (!node->unknown_4_7_) {
        if (cur != node->value) return;
        GameState_UpdatePlayClocks(LinkSession_IsActive((int*)searchObj) != 0);
        func_ov017_021d1118(id, 0xff, 0, 0);
        func_02094030(func_020936f8(), 0x4e20, -1, id);
        return;
    }
    unsigned char flags = 1;
    if (node->field5 == 1) flags |= 4;
    func_ov017_021d1118(id, flags, 1, node->field5);
}
