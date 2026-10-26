#if defined(jpn)
enum {regionalOffset0=0xe28, regionalOffset1=0x5778};
#else
enum {regionalOffset0=0xeac, regionalOffset1=0x5588};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_0209ca2c(void* obj);
extern "C" void func_ov023_021d8af8(void* obj);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_ov017_021cc730(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4*, unsigned int);
extern "C" void func_ov000_02160d80(void* p, int val);
struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678*, int);
extern "C" void func_020a1f4c(int);

extern char g_bgmPlayer;

// USA: func_ov023_021f3fbc
extern "C" ARM int func_ov023_021f3fbc(char* obj) {
    if (func_0209ca2c(&g_bgmPlayer)) {
        return *(int*)(obj + regionalOffset0);
    }

    if (*(void**)(obj + regionalOffset1) != 0) {
        func_ov023_021d8af8(*(void**)(obj + regionalOffset1));
        *(void**)(obj + regionalOffset1) = 0;
    }

    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
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
    func_ov000_02160d80(obj, 4);
    BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0);
    func_020a1f4c(1);
    return *(int*)(obj + regionalOffset0);
}
