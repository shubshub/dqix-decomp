#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void* func_020e2ff8(void);
struct Struct_0208ab34;
extern "C" int func_020e34bc(struct Struct_0208ab34* obj, int key);
extern "C" void func_ov017_021bd5d0(void);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" void func_020e3428(void* a, int b);
struct Struct_0208ab34_2;
extern "C" void func_020e3468(struct Struct_0208ab34_2* list, int key);
extern "C" void func_020e3368(unsigned char* base, unsigned char val);
struct Struct_ov001_02154de4;
extern "C" int func_ov001_02154de4(struct Struct_ov001_02154de4* self);

struct Struct_ov001_02155ca8 {
    char pad0[0xa];
    unsigned short field_a;
    #if defined(jpn)
    char pad1[0xf4 - 0xc];
#else
    char pad1[0xf8 - 0xc];
#endif
    unsigned int flag_f8 : 27;
    unsigned int unknown_fb_3_ : 5;
};

// USA: func_ov001_02155ca8
extern "C" ARM int func_ov001_02155ca8(struct Struct_ov001_02155ca8* obj) {
    GameState* bs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    if (obj->flag_f8 & 0x10) {
        if (LinkSession_IsHostOrSolo(search) != 0) {
            void* key = func_020e2ff8();
            int status = func_020e34bc((struct Struct_0208ab34*)key, 1);
            if (status == 1) {
                func_ov017_021bd5d0();
                GameObject_DisableControl((struct Obj020397cc*)bs->GetLeader(), 1);
                func_020e3428(key, 1);
            } else {
                if ((unsigned int)(status - 3) > 2) {
                    return obj->field_a;
                }
                func_020e3468((struct Struct_0208ab34_2*)key, 1);
                func_020e3368((unsigned char*)key, 1);
                return obj->field_a;
            }
        }
    }
    return func_ov001_02154de4((struct Struct_ov001_02154de4*)obj);
}
