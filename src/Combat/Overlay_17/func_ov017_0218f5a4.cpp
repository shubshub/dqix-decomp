#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov017_0218f5a4_1844 = 0x524, Field150 = 0x144, Enum_ov017_0218f5a4_396 = 0x180, Enum_ov017_0218f5a4_1792 = 0x4f0 };
#else
enum { Enum_ov017_0218f5a4_1844 = 0x734, Field150 = 0x150, Enum_ov017_0218f5a4_396 = 0x18c, Enum_ov017_0218f5a4_1792 = 0x700 };
#endif

extern "C" void LinkSession_GetInstance(void);
extern "C" int func_ov017_021925e0(void* p);
extern "C" void func_ov017_021bd440(void* obj, int arg);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);
extern "C" void func_02072afc(int id, int* arr, short* arr2);
extern "C" void* func_ov017_021a4658(void* p0, int p1);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_0218f5a4
extern "C" ARM int func_ov017_0218f5a4(char* self, int combatantId, int flag2, int arg3, int flag4) {
    GameState* bs = GameState::GetInstance();
    LinkSession_GetInstance();
    void* base = *(void**)(self + 0x3000 + Enum_ov017_0218f5a4_1844);

    if (func_ov017_021925e0(self + 0x3000) != 0) {
        GameObject* c = bs->GetPartyMemberByIndex(combatantId);
        if (c != 0) {
            unsigned short w = c->obj3D_.unknown_0_;
            if (w & 0x1000) {
                func_ov017_021bd440(base, combatantId & 0xff);
                return 0;
            }
        }
    }

    GameObject* c2 = func_0200ff1c(bs, combatantId);
    if (c2 == 0) return 0;
    if (func_02053c6c((unsigned char*)c2) == 0) return 0;

    if (flag4 == 0) {
        unsigned char* ptr = *(unsigned char**)((char*)c2 + Field150);
        int byteVal = ptr ? ptr[0x56e] : 0;
        if (byteVal == 0 && flag2 == 0) {
            if (func_02061bd8((struct Struct_0205faf4_11*)c2) == 0) {
                int arr[0xb];
                short arr2[0xb];
                func_02072afc(combatantId, arr, arr2);
                int matched = 0;
                int i;
                for (i = 0; i < 0xb; i++) {
                    if (i == 0xa) continue;
                    GameObject* c3 = bs->GetGameObjectByIndex(arr[i]);
                    if (c3 != 0) {
                        short v1 = arr2[i];
                        short v2 = c3->obj3D_.unknown_2_;
                        if (v1 != v2) matched = 1;
                    }
                }
                if (matched == 0) return 0;
            }
        }
    }

    void* node = func_ov017_021a4658(self, combatantId);
    if (node != 0) {
        *(short*)((char*)node + 8) = (short)combatantId;
        if (flag2 != 0) {
            ((unsigned char*)node)[0xb] |= 0x2;
        }
        if (arg3 != 0 || (*(int*)((char*)c2 + Enum_ov017_0218f5a4_396) & 0x40)) {
            ((unsigned char*)node)[0xb] |= 0x4;
        }
        if (flag4 != 0) {
            ((unsigned char*)node)[0xb] |= 0x1;
        }
        if (((unsigned char*)node)[2] == 0) {
            func_020469b4((struct TailList020469b4*)*(void**)(self + 0x3000 + Enum_ov017_0218f5a4_1792), (struct TailNode020469b4*)node);
        }
    }
    return 1;
}
