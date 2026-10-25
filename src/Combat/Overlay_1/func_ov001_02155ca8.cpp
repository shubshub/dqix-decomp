#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* arg0);
extern "C" void* func_020e2ff8(void);
struct Struct_0208ab34;
extern "C" int func_020e34bc(struct Struct_0208ab34* arg0, int arg1);
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

// USA: func_ov001_02155ca8
extern "C" ARM int func_ov001_02155ca8(struct Struct_ov001_02155ca8* arg0) {
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_0202ae18();
    if (arg0->unknown_f8_0_ & 0x10) {
        if (func_0202c508(var1) != 0) {
            void* var2 = func_020e2ff8();
            int var3 = func_020e34bc((struct Struct_0208ab34*)var2, 1);
            if (var3 == 1) {
                func_ov017_021bd5d0();
                GameObject_DisableControl((struct Obj020397cc*)bs->GetUnknownGameObject(), 1);
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
