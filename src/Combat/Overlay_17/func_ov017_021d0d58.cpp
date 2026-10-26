#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d0d58 {
    unsigned char tag;
    unsigned char pad0[3];
    int val;
    unsigned char pad2[12];
};

// USA: func_ov017_021d0d58
extern "C" ARM void func_ov017_021d0d58(void) {
    Struct_ov017_021d0d58 buf;
    void* p = LinkMessageQueue_GetInstance();
    char* battle = (char*)GameState_GetParty(GameState::GetInstance());
    buf.tag = 0x17;
    buf.val = *(int*)(battle + 0x2000 + 0xc94);
    func_0205e330(p, &buf, 0);
}
