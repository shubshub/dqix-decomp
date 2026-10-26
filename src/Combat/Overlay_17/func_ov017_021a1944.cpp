#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0207d78c(void);
struct Struct_0207d7f4;
extern "C" struct Struct_0207d7f4* func_0207d9bc(struct Struct_0207d7f4* arg0, unsigned short arg1);

extern unsigned char data_ov017_021d7654[4];

// USA: func_ov017_021a1944
extern "C" ARM unsigned short func_ov017_021a1944(void) {
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_0207d78c();
    int var2, var3;
retry:
    if (*(unsigned short*)(data_ov017_021d7654) > 0x7ff7) {
        *(unsigned short*)(data_ov017_021d7654) = 1;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 0xc; j++) {
            GameObject* c = bs->GetFieldMonsterByIndex(i * 0xc + 0x70 + j);
            if (c != NULL) {
                unsigned short field = *(unsigned short*)((char*)c + 0x16a);
                if (*(unsigned short*)(data_ov017_021d7654) == field) {
                    *(unsigned short*)(data_ov017_021d7654) = *(unsigned short*)(data_ov017_021d7654) + 1;
                    goto retry;
                }
            }
        }
    }
    if (func_0207d9bc((struct Struct_0207d7f4*)var1, *(unsigned short*)(data_ov017_021d7654)) != NULL) {
        *(unsigned short*)(data_ov017_021d7654) = *(unsigned short*)(data_ov017_021d7654) + 1;
        goto retry;
    }
    unsigned short var6 = *(unsigned short*)(data_ov017_021d7654);
    *(unsigned short*)(data_ov017_021d7654) = var6 + 1;
    return var6;
}
