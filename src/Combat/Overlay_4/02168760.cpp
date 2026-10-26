#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"

struct Struct_02011b24;
extern "C" void func_02011b24(struct Struct_02011b24* block);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" void func_ov017_021cf594(unsigned short, int, int);
extern "C" void* Zone3D_GetInstance(void);

// USA: func_ov004_02168760
extern "C" ARM int func_ov004_02168760(void) {
    GameState* bs = GameState::GetInstance();
    func_02011b24((struct Struct_02011b24*)bs);

    char buf[0x70];
    VectorizedMemset(buf, 0, 0x70);

    unsigned char one = 1;
    buf[8] = one;
    buf[9] = one;
    int var3 = one - 2;
    *(signed char*)(buf + 0xb) = var3;
    *(int*)(buf + 0x20) = var3;
    *(int*)(buf + 0x24) = var3;
    *(int*)(buf + 0x28) = var3;
    *(int*)(buf + 0x2c) = var3;
    *(short*)(buf + 0x1e) = var3;
    buf[0xc] = 0;
    *(short*)(buf + 0x6c) = var3;

    *(unsigned short*)buf = 0x1130;
    *(int*)(buf + 0x14) = -0x5ccc;
    *(int*)(buf + 0x18) = 0x1000;
    *(short*)(buf + 0x1c) = 0x323d;
    buf[2] = one;
    buf[4] = 0;
    buf[5] = 0;
    *(int*)(buf + 0x10) = 0;
    buf[7] = one;

    func_0200fba4(bs, buf);

    unsigned short zone = *(unsigned short*)Zone3D_GetInstance();

    for (signed char i = 1; i < 4; i++) {
        GameObject* member = bs->GetPartyMemberByIndex(i);
        if (!member) continue;
        if (func_0200ff58(bs, i)) continue;
        if (member->obj3D_.GetField06() != zone) continue;
        func_ov017_021cf594(0x1130, i, 1);
    }
    return 0;
}
