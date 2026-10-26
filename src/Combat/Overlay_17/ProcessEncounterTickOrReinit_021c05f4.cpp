#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, RegionOffset18c = 0x180, RegionOffset998 = 0x868, RegionOffsetb3c = 0x91c };
#else
enum { RegionOffset6fc = 0x6fc, RegionOffset18c = 0x18c, RegionOffset998 = 0x998, RegionOffsetb3c = 0xb3c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"



void* MessageSystem_GetInstance(void);
void* GlobalFlags_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int a, unsigned char* p, int bit);
int FieldTaskQueue_IsEmpty(void** p);
int GameObject_IsControlEnabled(void* obj);
int GameObject_IsGesturing(signed char* p);
struct BitField0203402c;
int GameObject_IsSinking(BitField0203402c* p);
struct FlagWord02046708;
int FlagWord_TestBits(FlagWord02046708* w, unsigned int mask);
int GameObject_IsClimbingLadder(char* p);
extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);
struct SePlayer;
int SePlayer_Play(SePlayer* obj, int a, int b);
void MessageSystem_Reset(char* p);
void* TextQueue_GetInstance(void);
struct Obj020d7aa0;
void TextQueue_Reset(Obj020d7aa0* obj);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* func_02017c58(void* a);
void InitObjWithFlag_021c0760(unsigned char* obj, unsigned char flag);
struct List02046a3c;
struct Node02046a3c;
void InsertNodeAfterHead(List02046a3c*, Node02046a3c*);

extern SePlayer g_sePlayer;

// USA: func_ov017_021c05f4  (semantic: ProcessEncounterTickOrReinit_021c05f4)
extern "C" ARM void func_ov017_021c05f4(void* p9, unsigned char p8, unsigned char p7, int p6) {
    void* g = MessageSystem_GetInstance();
    if (p6 != 0) {
        GameObject* combatant = GameState::GetInstance()->GetLeader();
        void* d = GlobalFlags_GetInstance();
        void* f = Scenario_GetInstance();
        if (Scenario_TestFlag((int)f, (unsigned char*)f + 0x8c, 0x119a) == 0) return;
        if (FieldTaskQueue_IsEmpty((void**)*(void**)((char*)p9 + 0x3000 + RegionOffset6fc)) == 0) return;
        if (GameObject_IsControlEnabled(combatant) == 0) return;
        if (GameObject_IsGesturing((signed char*)combatant) != 0) return;
        if (*(int*)((char*)combatant + RegionOffset18c) & 1) return;
        if (GameObject_IsSinking((BitField0203402c*)combatant) != 0 ||
            *(short*)((char*)combatant + 0xac) != 0 ||
            *(int*)((char*)g + RegionOffset998) != 0) return;
        if (FlagWord_TestBits((FlagWord02046708*)d, 0x800) != 0) return;
        if (GameObject_IsClimbingLadder((char*)combatant) != 0) return;
        if (GXx_GetMasterBrightness_((volatile unsigned short*)0x400006c) != 0) return;
        if (g_keyManager.TestKeysPressed(4) == 0) return;
        *(unsigned short*)((char*)combatant + 0xb2) = 0;
        SePlayer_Play(&g_sePlayer, 1, 0);
    } else {
        if (*(int*)((char*)g + RegionOffset998) != 0) MessageSystem_Reset((char*)g);
    }

    void* reset = TextQueue_GetInstance();
    TextQueue_Reset((Obj020d7aa0*)reset);
    func_02017c58(Zone3D_GetInstance());

    InitObjWithFlag_021c0760((unsigned char*)*(void**)((char*)p9 + 0x3000 + RegionOffsetb3c), p8);
    char* base = (char*)p9 + 0x3000;
    *((unsigned char*)*(void**)(base + RegionOffsetb3c) + 0x24) = p7;
    InsertNodeAfterHead((List02046a3c*)(*(void**)(base + RegionOffset6fc)), (Node02046a3c*)(*(void**)(base + RegionOffsetb3c)));
}
