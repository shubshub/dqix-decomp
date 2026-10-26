#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

void* LinkMessageQueue_GetInstance(void);
ARM void* GetField6b0_021b8470(void* obj);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int start);
int GetSubstructByte0x1c_020493a4(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c812c {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 3;
    unsigned char unknown_1_[4];
    unsigned char unknown_5_[8];
    unsigned char unknown_d_[3];
};

struct Struct_ov017_021c812c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021c812c unknown_4_;
};

// USA: func_ov017_021c812c
extern "C" ARM void func_ov017_021c812c(unsigned char arg0, int arg1) {
#if defined(jpn)
 enum { Enum_ov017_021c812c_1816=0x508 };
#else
 enum { Enum_ov017_021c812c_1816=0x718 };
#endif
    GameState* bs = GameState::GetInstance();
    char* base = (char*)GetGameResources();
    void* data = LinkMessageQueue_GetInstance();

    Struct_ov017_021c812c_2 var3;
    memset(&var3, 0, sizeof(var3));
    var3.unknown_0_ = 0x74;
    var3.unknown_4_.unknown_0_0_ = arg0;
    var3.unknown_4_.unknown_0_4_ = arg1;
    Struct_ov017_021c812c* var4 = &var3.unknown_4_;

    if (arg1 == 0) {
        for (int var5 = 0; var5 < 4; var5++) {
            var4->unknown_1_[var5] = 0xff;
        }
        for (int var6 = 0; var6 < 8; var6++) {
            var4->unknown_5_[var6] = 0xff;
        }
        void* obj = GetField6b0_021b8470(*(void**)(base + 0x3000 + regionalOffset));
        if (obj != NULL) {
            short buf[8];
            int n = func_ov000_0215e9fc(obj, buf, 8, 0x10);
            for (int i = 0; i < n; i++) {
                GameObject* c = bs->GetCombatantByIndex(buf[i]);
                if (c != NULL) {
                    int idx = c->obj3D_.actorIndex_;
                    fp->party[idx] = GetSubstructByte0x1c_020493a4((unsigned char*)c);
                }
            }
            n = func_ov000_0215eb1c(obj, buf, 8, 0x10);
            for (int i = 0; i < n; i++) {
                GameObject* c = bs->GetCombatantByIndex(buf[i]);
                if (c != NULL) {
                    int idx = c->obj3D_.actorIndex_ - 0xc0;
                    fp->monsters[idx] = GetSubstructByte0x1c_020493a4((unsigned char*)c);
                }
            }
        }
    }
    func_0205e330(var2, &var3, 0);
}
