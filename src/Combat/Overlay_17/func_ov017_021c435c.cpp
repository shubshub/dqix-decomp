#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void* func_ov017_021b8478(void* obj);

struct Struct_0203d028_13;

struct Struct_ov017_021c435c {
    unsigned char pad0[4];
    unsigned char field4;
    unsigned char loNibble : 4;
    unsigned char hiNibble : 4;
    unsigned short field6;
    unsigned short field8;
};

// USA: func_ov017_021c435c
extern "C" ARM void func_ov017_021c435c(int unused0, struct Struct_ov017_021c435c* src, GameState* battleStruct, unsigned char* obj, struct SearchStruct0202c1a4* search) {
#if defined(jpn)
 enum {regionalOffset0=0x508, regionalOffset1=0x150};
#else
 enum {regionalOffset0=0x718, regionalOffset1=0x15c};
#endif
    if (src->field4 & 1) {
        if (LinkSession_GetOwnSlot(search) != src->hiNibble) return;
    }
    unsigned int idx = src->loNibble;
    if (idx == LinkSession_GetOwnSlot(search)) return;
    GameObject* c = func_0200ff1c(battleStruct, idx);
    if (!c) return;
    unsigned short val = src->field6;
    if (src->field4 & 2) val = src->field8;
    unsigned char* node = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    void* p = func_ov017_021b8478(node);
    if (node[2] != 0) {
        if (func_020a35e0((unsigned char*)p, src->loNibble)) {
            *(unsigned int*)((char*)c + regionalOffset1) = val;
            return;
        }
    }
    ((Object3D*)((struct Struct_0203d028_13*)c))->SetField06(val);
}
