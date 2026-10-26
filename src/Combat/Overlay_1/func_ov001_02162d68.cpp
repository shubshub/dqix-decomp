#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_ov017_021d6134(void*, int);

struct Struct_ov001_02162d68 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_ov001_02162d68
extern "C" ARM int func_ov001_02162d68(void* ctx) {
    GameObject* c = GameState::GetInstance()->GetPartyMemberByIndex(0);
    if (c == NULL) {
        return 0;
    }
    struct Struct_ov001_02162d68* sub = (struct Struct_ov001_02162d68*)func_02053c6c((unsigned char*)c);
    func_ov017_021d6134(ctx, sub->bit0 == 0);
    return 1;
}
