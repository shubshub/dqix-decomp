#include <globaldefs.h>

#include "Combat/BattleSkillEligibility.h"
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"


extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void SpriteContext_DrawSprite(void* a, void* b);

extern "C" int GameObject_GetGestureSlot(void* obj);
extern "C" int MessageSystem_GetInstance();
extern "C" void* ObjLoading_GetInstance(void);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);

struct Struct_02015a2c_2;
extern "C" int func_02015a2c(struct Struct_02015a2c_2* obj);

extern "C" int func_020db2d4(void* obj);

struct Node0x20_021a5ad0;
extern "C" void func_ov017_021a5ad0(struct Node0x20_021a5ad0* arr, int count, int val);
extern "C" void func_ov017_021a5b08(struct Node0x20_021a5ad0* arr, int count);

struct Struct0200fb08;
extern "C" unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
extern "C" void Window_ClearLayers(Cont0205d1e0*);
extern "C" void Window_DrawPanes(Cont0205d228*);
extern "C" void Window_FlushLayers(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(Obj0205d2bc*);

extern unsigned short data_ov017_021d6a9e[5];

// USA: func_ov017_021a63d0
#if defined(jpn)
static const int OFF_41c0 = 0x3fa0;
static const int OFF_41b4 = 0x3f94;
static const int OFF_4080 = 0x3e60;
static const int OFF_36fc = 0x34ec;
static const int OFF_998 = 0x868;
static const int OFF_4094 = 0x3e74;
static const int OFF_41b8 = 0x3f98;
static const int OFF_4090 = 0x3e70;
static const int OFF_41c4 = 0x3fa4;
#else
static const int OFF_41c0 = 0x41c0;
static const int OFF_41b4 = 0x41b4;
static const int OFF_4080 = 0x4080;
static const int OFF_36fc = 0x36fc;
static const int OFF_998 = 0x998;
static const int OFF_4094 = 0x4094;
static const int OFF_41b8 = 0x41b8;
static const int OFF_4090 = 0x4090;
static const int OFF_41c4 = 0x41c4;
#endif

extern "C" ARM void func_ov017_021a63d0(unsigned char* base) {
 #if !defined(jpn)
    short buf[5];
 #endif

    if (*(int*)(base + OFF_41c0) == 0) return;
    if (*(int*)(base + OFF_41b4) == 0) return;

    void* searchObj = LinkSession_GetInstance();
    int f260 = GameObject_GetGestureSlot(GameState::GetInstance()->GetProtagonist());
    int glob1c = MessageSystem_GetInstance();
    void* g = Zone3D_GetInstance();
    void* ctx = ObjLoading_GetInstance();

    if (GameState::GetInstance()->GetGrottoStruct()->unknown_0[0] == 0) return;

    int var6 = *(int*)(base + OFF_4080);
    if (var6 != 0) return;
    if (f260 != -1) return;

    if (!FieldTaskQueue_IsEmpty(*(void***)(base + OFF_36fc))) return;
    if (LinkSession_IsGuest(searchObj)) return;

    if (GameState_IsInGrotto(GameState::GetInstance()) != 0) return;
    if (*(int*)((char*)glob1c + OFF_998) != 0) return;
    if (func_02015a2c((struct Struct_02015a2c_2*)g)) return;
    if (func_020db2d4(ctx)) return;

    func_ov017_021a5ad0((struct Node0x20_021a5ad0*)(base + OFF_4094), 2, 0x800);

 #if !defined(jpn)
    {
        unsigned short* dst = (unsigned short*)buf;
        unsigned short* src = data_ov017_021d6a9e;
        int n = 5;
        do {
            unsigned short* d = dst++;
            unsigned short t = *src++;
            *d = t;
        } while (--n);
    }

    unsigned char count = GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance());

 #endif

    if (*(int*)(base + OFF_41b8) >= 3) {
        void* sub = *(void**)(base + OFF_4090);
        Window_ClearLayers((Cont0205d1e0*)sub);
        Window_DrawPanes((Cont0205d228*)sub);
        func_0205da88(sub, 1, 2, 1);
        Window_FlushLayers((Cont0205d274*)sub);
        Window_TransferLayers((Obj0205d2bc*)sub);

        unsigned char* p = *(unsigned char**)(base + OFF_41c4);
        int var15 = *(int*)(p + 0x40);
        unsigned char* q = 0;
        if (var15 != 0) {
            if (*(unsigned short*)(p + 0x4e) > 6) {
                q = (unsigned char*)var15 + 0xf0;
            }
        }

        if (q) {
#if defined(jpn)
            int val = 0xb7000;
#else
            int val = (buf[count - 1] + 7) << 12;
#endif
            *(int*)(q + 0x14) = val;
            *(int*)(q + 0x18) = 0xab000;
            q[0x22] = 0x7e;
            q[0x26] = 0;
            *(int*)(q + 0xc) = 0x1000;
            *(int*)(q + 0x10) = 0x1000;
            void* p2 = *(void**)(base + OFF_41c4);
            SpriteContext_DrawSprite(p2, q);
        }
    }

    func_ov017_021a5b08((struct Node0x20_021a5ad0*)(base + OFF_4094), 2);
}
