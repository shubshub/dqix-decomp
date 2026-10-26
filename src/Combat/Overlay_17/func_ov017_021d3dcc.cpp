#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" int Zone3D_GetInstance(void);
extern "C" void func_02098efc(char* obj, int offset, const void* src, unsigned int length);
extern "C" void* LinkMessageQueue_GetInstance(void);
struct BitArrayObj0205e804;
extern "C" void func_0205e804(struct BitArrayObj0205e804* obj, int index);

struct Struct_ov017_021d3dcc {
    char pad[0x11];
    unsigned char unknown_11_0_ : 4;
    unsigned char midTag : 3;
    unsigned char unknown_11_7_ : 1;
    unsigned short field12;
};

// USA: func_ov017_021d3dcc
extern "C" ARM void func_ov017_021d3dcc(int p0, struct Struct_ov017_021d3dcc* evt, GameState* battleStruct, int p3, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset0=0x860};
#else
 enum {regionalOffset0=0x840};
#endif
    if (LinkSession_GetOwnSlot(search) != evt->midTag) {
        return;
    }
    char* base = (char*)Zone3D_GetInstance();
    char* p1 = base + regionalOffset0;
    func_02098efc(p1, evt->field12, (const void*)((char*)evt + 4), evt->unknown_11_0_);
    if (!evt->unknown_11_7_) {
        return;
    }
    p1[0x1000 + 0xb62] = 1;
    struct BitArrayObj0205e804* bits = (struct BitArrayObj0205e804*)LinkMessageQueue_GetInstance();
    func_0205e804(bits, 0xb9);
}
