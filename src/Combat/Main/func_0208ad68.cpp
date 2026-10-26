#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0208ad68_1744 = 0x4c0 };
#else
enum { Enum_0208ad68_1744 = 0x6d0 };
#endif

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_020482e0_2 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
};
struct Struct_020482e0 {
    char unknown_0_[0x130];
    struct Struct_020482e0_2* unknown_130_;
};
extern "C" int func_020482e0(struct Struct_020482e0* arg0, int arg1, int arg2);

extern "C" void func_02026f08(unsigned char* arg0, int arg1, int arg2);
extern "C" void func_02026f20(int arg0, int arg1);

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_0208ad68
extern "C" ARM void func_0208ad68(void* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    char* var1 = (char*)GetGameResources() + 0x3000;
    int* var2 = *(int**)(var1 + Enum_0208ad68_1744);
    struct Struct_020482e0* var3 = (struct Struct_020482e0*)var0->GetPartyMemberByIndex(arg1);
    unsigned char var4 = ((unsigned char*)arg0)[5];
    unsigned short var5 = var3->unknown_130_->unknown_4_;
    func_020482e0(var3, var4, 0);
    unsigned short var6 = var3->unknown_130_->unknown_4_;
    if (var5 != var6) {
        func_02026f08((unsigned char*)var2, arg1, 1);
        func_02026f20((int)var2, arg1);
    }
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        func_ov017_021c9e00(id, 1, 0, 1);
    }
}
