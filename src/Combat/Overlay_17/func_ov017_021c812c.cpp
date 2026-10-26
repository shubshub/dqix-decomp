#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" ARM void* func_ov017_021b8470(void* obj);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0215eb1c(void* obj, short* buf, int max, int start);
extern "C" int func_020493a4(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c812c {
    unsigned char mode : 4;
    unsigned char flag : 1;
    unsigned char pad : 3;
    unsigned char party[4];
    unsigned char monsters[8];
    unsigned char pad2[3];
};

struct Struct_ov017_021c812c_2 {
    unsigned char tag;
    unsigned char pad[3];
    Struct_ov017_021c812c fields;
};

// USA: func_ov017_021c812c
extern "C" ARM void func_ov017_021c812c(unsigned char mode, int flag) {
#if defined(jpn)
 enum { regionalOffset=0x508 };
#else
 enum { regionalOffset=0x718 };
#endif
    GameState* bs = GameState::GetInstance();
    char* base = (char*)GetGameResources();
    void* data = LinkMessageQueue_GetInstance();

    Struct_ov017_021c812c_2 msg;
    memset(&msg, 0, sizeof(msg));
    msg.tag = 0x74;
    msg.fields.mode = mode;
    msg.fields.flag = flag;
    Struct_ov017_021c812c* fp = &msg.fields;

    if (flag == 0) {
        for (int i = 0; i < 4; i++) {
            fp->party[i] = 0xff;
        }
        for (int i = 0; i < 8; i++) {
            fp->monsters[i] = 0xff;
        }
        void* obj = func_ov017_021b8470(*(void**)(base + 0x3000 + regionalOffset));
        if (obj != NULL) {
            short buf[8];
            int n = func_ov000_0215e9fc(obj, buf, 8, 0x10);
            for (int i = 0; i < n; i++) {
                GameObject* c = bs->GetCombatantByIndex(buf[i]);
                if (c != NULL) {
                    int idx = c->obj3D_.actorIndex_;
                    fp->party[idx] = func_020493a4((unsigned char*)c);
                }
            }
            n = func_ov000_0215eb1c(obj, buf, 8, 0x10);
            for (int i = 0; i < n; i++) {
                GameObject* c = bs->GetCombatantByIndex(buf[i]);
                if (c != NULL) {
                    int idx = c->obj3D_.actorIndex_ - 0xc0;
                    fp->monsters[idx] = func_020493a4((unsigned char*)c);
                }
            }
        }
    }
    func_0205e330(data, &msg, 0);
}
