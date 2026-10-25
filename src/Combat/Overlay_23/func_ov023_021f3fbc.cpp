#if defined(jpn)
enum {Enum_ov023_021f3fbc_3756=0xe28, Enum_ov023_021f3fbc_21896=0x5778};
#else
enum {Enum_ov023_021f3fbc_3756=0xeac, Enum_ov023_021f3fbc_21896=0x5588};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_0209ca2c(void* arg0);
extern "C" void func_ov023_021d8af8(void* arg0);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
void* GameState_GetParty(GameState*);
extern "C" void func_ov017_021cc730(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4*, unsigned int);
void SetFieldsAndSignalData02184220_ov000_02160d80(void* p, int val);
struct Actor0209c678;
void BgmPlayer_FadeOut(struct Actor0209c678*, int);
void PopStack1AndTrigger_020a1f4c(int);

extern char g_bgmPlayer;

// USA: func_ov023_021f3fbc  (semantic: ResetAndDispatchIfIdle_021f3fbc)
extern "C" ARM int func_ov023_021f3fbc(char* obj) {
    if (IsAnimationActive0209ca2c(&g_bgmPlayer)) {
        return *(int*)(obj + regionalOffset0);
    }

    if (*(void**)(arg0 + Enum_ov023_021f3fbc_21896) != 0) {
        func_ov023_021d8af8(*(void**)(arg0 + Enum_ov023_021f3fbc_21896));
        *(void**)(arg0 + Enum_ov023_021f3fbc_21896) = 0;
    }

    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())) {
        GameState* battleStruct = GameState::GetInstance();
        unsigned char* list = (unsigned char*)GameState_GetParty(battleStruct);
        for (int i = 0; i < list[0xf7c]; i++) {
            unsigned char* p = list + i;
            func_ov017_021cc730(p[0xf78], 0, 0, 1);
        }
    }

    int g = MessageSystem_GetInstance();
    MessageSystem_Reset((char*)g);
    MessageSystem_Stop((char*)g);
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x20000);
    SetFieldsAndSignalData02184220_ov000_02160d80(obj, 4);
    BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0);
    PopStack1AndTrigger_020a1f4c(1);
    return *(int*)(obj + regionalOffset0);
}
