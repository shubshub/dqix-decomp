#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
void* GetData02153637_020e2ff8(void);
struct Container020e34bc;
int GetEntryStatusForKey020e34bc(struct Container020e34bc* obj, int key);
extern "C" void func_ov017_021bd5d0(void);
struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
void Dispatch020e3428(void* a, int b);
struct Entry020e3054;
void ClearEntryIfCurrentArrMatches020e3468(struct Entry020e3054* list, int key);
void StoreInFirstEmptySlot_020e3368(unsigned char* base, unsigned char val);
struct Self02154de4;
int ProcessAndDispatchState_02154de4(struct Self02154de4* self);

struct Struct_ov001_02155ca8 {
    char unknown_0_[0xa];
    unsigned short unknown_a_;
    #if defined(jpn)
    char unknown_c_[0xf4 - 0xc];
#else
    char unknown1_c_[0xf8 - 0xc];
#endif
    unsigned int unknown_f8_0_ : 27;
    unsigned int unknown_fb_3_ : 5;
};

// USA: func_ov001_02155ca8  (semantic: HandleEntryStatusOrProcessState_02155ca8)
extern "C" ARM int func_ov001_02155ca8(struct Self02155ca8* obj) {
    GameState* bs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    if (obj->flag_f8 & 0x10) {
        if (LinkSession_IsHostOrSolo(search) != 0) {
            void* key = GetData02153637_020e2ff8();
            int status = GetEntryStatusForKey020e34bc((struct Container020e34bc*)key, 1);
            if (status == 1) {
                func_ov017_021bd5d0();
                GameObject_DisableControl((struct Obj020397cc*)bs->GetLeader(), 1);
                Dispatch020e3428(key, 1);
            } else {
                if ((unsigned int)(var3 - 3) > 2) {
                    return arg0->unknown_a_;
                }
                func_020e3468((struct Struct_0208ab34_2*)var2, 1);
                func_020e3368((unsigned char*)var2, 1);
                return arg0->unknown_a_;
            }
        }
    }
    return func_ov001_02154de4((struct Struct_ov001_02154de4*)arg0);
}
