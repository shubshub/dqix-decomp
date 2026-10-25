#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/TextQueue.h"
#include "World/FieldTask.h"

#if defined(jpn)
extern "C" int sprintf(char* out, const char* format, ...);
extern "C" void TextQueue_Push(void* receiver, void* input, int style, int flag, unsigned char option);
extern "C" char data_ov017_021d70e0[];
extern "C" char data_ov017_021d7108[];
enum { ResourceFlag = 0x40c8, GrottoReset = 0x27d4 };
#else
enum { ResourceFlag = 0x42e8, GrottoReset = 0x2794 };
#endif

struct SearchStruct;
extern "C" struct SearchStruct* func_0202ae18(void);
extern "C" int func_0202c508(struct SearchStruct* obj);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void MessageSystem_FormatText(void* a, int b, int c, void* d, int e, int f, int g);
extern "C" int func_ov017_021959b4(void);
extern "C" int func_ov017_021a23e4(char* c, int a0, unsigned int f8, unsigned int fc);

void* TextQueue_GetInstance(void);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
void* MessageSystem_GetInstance(void);
void NameText_InitFromPartyMember(void* obj, int combatantId);
int StandardStrings_Get(int a);
void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
void SePlayer_PlayExtra(void* obj, int a, int b);
void InitContext020e1154(void* obj);
struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
struct Obj020d7aa0;
void TextQueue_Reset(struct Obj020d7aa0* obj);
struct BitFlags02037170;
struct BitFlags02037180;
void SePlayer_UnloadExtraArchiveB(void* obj);
void GameObject_EnableControl(void* obj);
int GetBitflagForCombatantColor_021a26e8(GameResources* unused0, int combatantId);
void EnqueueEventTag139_021d09cc(int a, int b, int c, int d);
GameObject* FindCombatantByField0x16a_0200ffe0(GameState* battleStruct, int id);

extern int g_sePlayer;

// Overlay 17, originally func_ov017_021c2784 (USA/EUR 0x021c2784, JPN 0x021c2cf0)
extern "C" ARM void FieldTask_Whistle(WhistleTask* obj) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* ov = GetGameResources();
    struct SearchStruct* search = func_0202ae18();
    void* reset = TextQueue_GetInstance();

    GameObject* a = battleStruct->GetPartyMemberByIndex(obj->partyMember);
    int fieldVal = GameState_GetLeaderIndex(battleStruct);
    GameObject* c = battleStruct->GetPartyMemberByIndex(fieldVal);
    if (!a || !c) {
        obj->done = 1;
    }
    if (func_ov017_021959b4()) {
        obj->done = 1;
        return;
    }

    if (obj->step == 0) {
        *(unsigned char*)((char*)ov + ResourceFlag) = 1;
        GameObject_DisableControl((struct Obj020397cc*)c, 1);
        *(unsigned short*)((char*)c + 0xb2) = 0;
        if (obj->silent != 0) {
            obj->timer = 0;
        } else {
#if defined(jpn)
            char buf2[0x50];
            sprintf(buf2, data_ov017_021d70e0, *(char**)((char*)a + 0x134));
            TextQueue_Push(reset, buf2, 0, 0, 1);
#else
            void* g = MessageSystem_GetInstance();
            char buf1[0xc];
            char buf2[0x50];
            NameText_InitFromPartyMember(buf1, obj->partyMember);
            *(void**)g = buf1;
            int ret = StandardStrings_Get(0x26);
            MessageSystem_FormatText(g, 0xc, ret, buf2, 0xe3, 0, 1);
            TextQueue_Push(reset, buf2, 0, 0, 1, 1);
#endif
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0x79, 0x79);
            SePlayer_PlayExtra(&g_sePlayer, 0, 0);
            obj->timer = 0x3e8;
        }
        obj->step = 1;
        return;
    } else if (obj->step == 1) {
        unsigned int v = (unsigned int)battleStruct->GetEffectiveDeltaTime();
        if (v < obj->timer) {
            obj->timer -= v;
            return;
        }
        obj->timer = (obj->silent != 0) ? 0x64 : 0x384;

        unsigned short* p = Zone3D_GetInstance();
        if (*p == 0x2710) {
            *(int*)((char*)p + GrottoReset) = 0;
            InitContext020e1154((void*)0x7d0);
            obj->step = 5;
            return;
        }
        if (func_0202c508(search)) {
            int fv2 = GameState_GetLeaderIndex(battleStruct);
            int ret = func_ov017_021a23e4((char*)ov, fv2, 0, obj->monsterId);
            obj->summonedId = (unsigned short)ret;
            if (obj->summonedId != 0) {
                obj->step = 5;
                return;
            }
            obj->step = 2;
            return;
        }
        int fv3 = GameState_GetLeaderIndex(battleStruct);
        int bitflag = GetBitflagForCombatantColor_021a26e8(ov, fv3);
        EnqueueEventTag139_021d09cc(0, 0, bitflag, obj->monsterId);
        obj->step = 4;
        return;
    } else if (obj->step == 2) {
        int val;
        if (obj->silent != 0) {
            val = 0;
        } else {
            TextQueue_Reset((struct Obj020d7aa0*)reset);
#if defined(jpn)
            TextQueue_Push(reset, data_ov017_021d7108, 0, 0, 1);
#else
            int cbv = StandardStrings_Get(0x27);
            TextQueue_Push(reset, (void*)cbv, 0, 0, 1, 1);
#endif
            val = 0xbb8;
        }
        obj->timer = val;
        obj->step = 3;
        return;
    } else if (obj->step == 3) {
        unsigned int v = (unsigned int)battleStruct->GetEffectiveDeltaTime();
        if (v < obj->timer) {
            obj->timer -= v;
            return;
        }
        GameObject* combatant = battleStruct->GetMaybeFieldMonsterByIndex(obj->summonedIndex);
        if (obj->summonedIndex > 0 && combatant != NULL) {
            if (((Object3D*)((struct BitFlags02037170*)combatant))->HasAnimationStopped() == 0) {
                if (((Object3D*)((struct BitFlags02037180*)combatant))->HasAnimationReachedEnd() == 0) {
                    return;
                }
            }
        }
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        GameObject_EnableControl(c);
        obj->done = 1;
        return;
    } else if (obj->step == 4) {
        unsigned int v = (unsigned int)battleStruct->GetEffectiveDeltaTime();
        if (v < obj->timer) {
            obj->timer -= v;
            return;
        }
        obj->timer = 0;
        return;
    } else if (obj->step == 5) {
        GameObject* found = FindCombatantByField0x16a_0200ffe0(battleStruct, obj->summonedId);
        if (obj->summonedId != 0) {
            if (found == NULL) {
                return;
            }
            obj->summonedIndex = found->obj3D_.actorIndex_;
        }
        *(unsigned char*)((char*)c + 0xc3) = 0;
        obj->step = 3;
    }
}
