#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, RegionOffset18c = 0x180, RegionOffset998 = 0x868, RegionOffsetb3c = 0x91c };
#else
enum { RegionOffset6fc = 0x6fc, RegionOffset18c = 0x18c, RegionOffset998 = 0x998, RegionOffsetb3c = 0xb3c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"


#if defined(jpn)
#define func_020c39c8 func_020c5494
#endif

void* MessageSystem_GetInstance(void);
void* GlobalFlags_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int a, unsigned char* p, int bit);
int IsField0Null_02046b08(void** p);
int GetByteField0x252_02039820(void* obj);
int CheckSubstructByte0x7cPositive_020535c8(signed char* p);
struct BitField0203402c;
int CheckField0xc4Low15BitsNonZero(BitField0203402c* p);
struct FlagWord02046708;
int TestFlags02046708(FlagWord02046708* w, unsigned int mask);
int GetByte0x26c_02039d7c(char* p);
extern "C" int func_020c39c8(volatile unsigned short* p);
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
        GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
        void* d = GlobalFlags_GetInstance();
        void* f = Scenario_GetInstance();
        if (Scenario_TestFlag((int)f, (unsigned char*)f + 0x8c, 0x119a) == 0) return;
        if (IsField0Null_02046b08((void**)*(void**)((char*)p9 + 0x3000 + RegionOffset6fc)) == 0) return;
        if (GetByteField0x252_02039820(combatant) == 0) return;
        if (CheckSubstructByte0x7cPositive_020535c8((signed char*)combatant) != 0) return;
        if (*(int*)((char*)combatant + RegionOffset18c) & 1) return;
        if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)combatant) != 0 ||
            *(short*)((char*)combatant + 0xac) != 0 ||
            *(int*)((char*)g + RegionOffset998) != 0) return;
        if (TestFlags02046708((FlagWord02046708*)d, 0x800) != 0) return;
        if (GetByte0x26c_02039d7c((char*)combatant) != 0) return;
        if (func_020c39c8((volatile unsigned short*)0x400006c) != 0) return;
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
