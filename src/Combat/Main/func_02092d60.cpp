#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#include "GameState/GameState.h"

struct Vector3i;

struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_021677d8(void* obj, int id);

extern "C" void* Zone3D_GetInstance(void);

extern "C" int func_02011b50(void* obj, int mask);

struct Struct_02092d60 {
    int x, y, z;
};

extern "C" void func_ov017_021cf3c0(struct Struct_02092d60 v, int arg1, int p2, int bits, int byteVal);

struct GlobalStructShort02012fe4 {
    unsigned short f0;
};

struct Struct_02092d60_3 {
    char pad[0x38];
    signed char unknown_38_;
};

// USA: func_02092d60
extern "C" ARM void func_02092d60(struct Struct_02092d60_3* p1, int p2) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetLeader();
    if (c != 0) {
        struct Struct_02092d60 vecBuf;
        *(Vector3i*)&vecBuf.x = *(Vector3i const*)(&c->obj3D_.position_.x);
        int word0 = (int)bs->GetResources();
        struct HeadNode02046b24** listHead = *(struct HeadNode02046b24***)((char*)(int)word0 + (IS_JPN ? 0x34ec : 0x36fc));
        int head = FieldTaskQueue_GetCurrentKind(listHead);
        if (head == 0xa) {
            void* work = func_ov000_02160130();
            if (work != 0) {
                void* slot = func_ov000_021677d8(work, c->obj3D_.actorIndex_);
                if (slot != 0) {
                    *(Vector3i*)&vecBuf.x = *(Vector3i const*)((int*)slot);
                }
            }
        }
        struct GlobalStructShort02012fe4* g = (struct GlobalStructShort02012fe4*)Zone3D_GetInstance();
        unsigned short var9 = g->f0;
        int bits = func_02011b50(bs, 1);
        func_ov017_021cf3c0(vecBuf, var9, p2, bits, p1->unknown_38_);
    }
}
