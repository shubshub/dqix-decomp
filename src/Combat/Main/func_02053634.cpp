#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Input/Input.h"


int MessageSystem_GetInstance(void);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
int GameObject_GetLinePosition(void* obj);
int GetIndexedEntryField0x178_02053604(signed char* obj);

extern "C" void func_020531f0(void* arg0);
struct ObjectArchiveLoadInfo;
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_0205308c(void* obj, int val);
extern "C" void* Scenario_GetInstance(void);
extern "C" void EventQuery_RunQueuedCommands(void* p);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

void ForwardToTargetOrDefault0205eabc(void* obj, void* target, int arg);
int SetTargetFieldAndForEach02064a9c(void* param0, void* param1);
int GameState_GetFollowCamera(char* obj);
void EnqueueEventTag6_021cc2f0(int);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);

struct Struct_02053634 {
    int unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    void* unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};

struct Struct_020e7c94 { short unknown_0_; short unknown_2_; };
extern struct Struct_020e7c94 data_020e7c94[];

extern char data_020f0477;
extern char data_020f047e;
extern int g_sePlayer;
extern char data_020f0481;
extern char data_020f0486;

#if defined(jpn)
#define OBJECT_OFFSET(offset) ((offset) - 0xc)
#define GLOBAL_ACTIVE_OFFSET 0x17e1
#else
#define OBJECT_OFFSET(offset) (offset)
#define GLOBAL_ACTIVE_OFFSET 0x19b1
#endif

// USA: func_02053634
extern "C" ARM void func_02053634(void* arg0) {
    char* var0 = (char*)arg0;
    GameState* var1 = GameState::GetInstance();

    int hasEntries0 = ctx[OBJECT_OFFSET(0x17c)] > 0 ? 1 : 0;
    if (hasEntries0 != 0) {
        short cid0 = *(short*)(ctx + 4);
        int activeCid0 = GameState_GetLeaderIndex(bs);
        if (activeCid0 == cid0
            && ((unsigned char*)MessageSystem_GetInstance())[GLOBAL_ACTIVE_OFFSET] != 0) {
            func_020531f0(ctx);
            return;
        }
    }

    GameObject* combatant = bs->GetPartyMemberByIndex(*(short*)(ctx + 4));
    int hasEntries = ctx[OBJECT_OFFSET(0x17c)] > 0 ? 1 : 0;
    if (hasEntries != 0) {
        if (GameObject_GetLinePosition(combatant) > 0) {
            func_020531f0(ctx);
            return;
        }
    }

    signed char var7 = var0[OBJECT_OFFSET(0x17e)];
    if (var7 == 0) {
        BackgroundLoader* var8 = BackgroundLoader::GetInstance();
        if (var8->GetTaskStatus(*(int*)(var0 + OBJECT_OFFSET(0x180))) == 0) {
            return;
        }
        if (*(int*)(var0 + OBJECT_OFFSET(0x194)) >= 0) {
            if (var8->GetTaskStatus(*(int*)(var0 + OBJECT_OFFSET(0x194))) == 0) {
                return;
            }
        }

        int var9 = 0;
        if (var8->GetDetailedTaskStatus(*(int*)(var0 + OBJECT_OFFSET(0x180))) != 2) {
            goto detailFail;
        }
        {
        ((Object3D*)var0)->RemoveAnimationPackageByID(2);
        void* var10;
        unsigned int var11;
        var8->GetLoadedFileByID(*(int*)(var0 + OBJECT_OFFSET(0x180)), &var10, &var11);
        if (var10 != 0) {
            void* var12 = *(void**)(var0 + OBJECT_OFFSET(0x154));
            void* var13 = (char*)var12 + 0x554;
            ((SafeAllocator*)var13)->Reset();

            struct Struct_02053634 var14;
            var14.unknown_4_ = var10;
            var14.unknown_0_ = 0;
            var14.unknown_14_ = 0;
            var14.unknown_18_ = 0;
            var14.unknown_8_ = var11;
            var14.unknown_c_ = var13;
            var14.unknown_1c_ = 2;
            var14.unknown_10_ = 1;
            if (((Object3D*)var0)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&var14, (int (*)(BCFG::AnimationRecord*))0) == 0) {
                goto loadFail;
            }
            if (((Object3D*)ctx)->SetAnimationByName(&data_020f0477, 1) == 0) {
                if (((Object3D*)ctx)->SetAnimationByName(&data_020f047e, 1) == 0) {
                    func_020531f0(ctx);
                    return;
                }
                var0[OBJECT_OFFSET(0x17f)] = 1;
            } else {
                var0[OBJECT_OFFSET(0x17f)] = 0;
            }

            if (var0[OBJECT_OFFSET(0x17f)] == 0) {
                if (var0[OBJECT_OFFSET(0x17d)] + 1 < var0[OBJECT_OFFSET(0x17c)]) {
                    var9 = 1;
                }
            }

            struct Struct_020e7c94* var15 = data_020e7c94;
            for (; var15->unknown_0_ > 0; var15++) {
                if (var15->unknown_0_ != func_02053604((signed char*)var0)) continue;
                void* var16 = 0;
                if (var15->unknown_2_ == 0x4e) {
                    var16 = var0 + OBJECT_OFFSET(0x198);
                }
                unsigned short val = *(unsigned short*)Zone3D_GetInstance();
                if (val == ((Object3D*)ctx)->GetField06()) {
                    SePlayer_Play((struct SePlayer*)&g_sePlayer, e->kind, (int)arg2);
                }
                break;
            }
            var0[OBJECT_OFFSET(0x17e)] = 1;
            goto loadOK;
        loadFail:
            func_020531f0(var0);
            return;
        } else {
            goto loadOK;
        }
    loadOK:
        var0[OBJECT_OFFSET(0x185)] = 1;
        goto detailOK;
    detailFail:
        func_020531f0(var0);
        return;
        }
    detailOK:
        var8->RemoveTask(*(int*)(var0 + OBJECT_OFFSET(0x180)));
        *(int*)(var0 + OBJECT_OFFSET(0x180)) = -1;
        if (var9 != 0) {
            if (*(unsigned char*)(var0 + OBJECT_OFFSET(0x185)) != 0) {
                var0[OBJECT_OFFSET(0x186)] = 1;
            } else {
                signed char var18 = var0[OBJECT_OFFSET(0x17d)];
                char* var19 = var0 + (var18 + 1) + 0x100;
                func_0205308c(var0, var19[OBJECT_OFFSET(0x78)]);
            }
        }
    } else {
        if (var7 == 1) {
            if (((Object3D*)var0)->HasAnimationStopped() == 0) {
                return;
            }
            if (var0[OBJECT_OFFSET(0x17f)] == 0) {
                var0[OBJECT_OFFSET(0x17d)] = var0[OBJECT_OFFSET(0x17d)] + 1;
                if (var0[OBJECT_OFFSET(0x17d)] < var0[OBJECT_OFFSET(0x17c)]) {
                    var0[OBJECT_OFFSET(0x17e)] = 0;
                    *(int*)(var0 + OBJECT_OFFSET(0x190)) = 0;
                    return;
                }
                short cid = *(short*)(ctx + 4);
                if (cid == GameState_GetLeaderIndex(bs)) {
                    void* p = Scenario_GetInstance();
                    unsigned char req[0x34];
                    for (int i = 0; i < 4; i++) {
                        char* q = ctx + i + 0x100;
                        ((signed char*)(req + 0x2a))[i] = q[OBJECT_OFFSET(0x78)];
                    }
                    if (SetTargetFieldAndForEach02064a9c(p, req) != 0) {
                        EventQuery_RunQueuedCommands(req);
                    }
                }
                func_020531f0(var0);
                return;
            } else if (ctx[OBJECT_OFFSET(0x17f)] == 1) {
                int mode = 0;
                if (ctx[OBJECT_OFFSET(0x17c)] > 1) {
                    mode = 1;
                    if (GetIndexedEntryField0x178_02053604((signed char*)ctx) == 0x19) {
                        ForwardToTargetOrDefault0205eabc((void*)&g_sePlayer, ctx + OBJECT_OFFSET(0x198), 0);
                    }
                }
                if (((Object3D*)ctx)->SetAnimationByName(&data_020f0481, mode) != 0) {
                    ctx[OBJECT_OFFSET(0x17e)] = 2;
                    return;
                }
                func_020531f0(var0);
                return;
            } else {
                func_020531f0(var0);
                return;
            }
        } else if (state == 2) {
            bs = GameState::GetInstance();
            int target = GameState_GetFollowCamera((char*)bs);
            int flag = 0;
            if (ctx[OBJECT_OFFSET(0x17c)] > 1) {
                if (((Object3D*)ctx)->HasAnimationStopped() != 0) {
                    flag = 1;
                }
            } else {
                short cid = *(short*)(ctx + 4);
                if (cid == GameState_GetLeaderIndex(bs)
                    && g_keyManager.TestKeysPressed(0xc03) != 0) {
                    var27 = 1;
                    func_ov017_021cc2f0(*(short*)(var0 + 4));
                } else {
                    if (*(unsigned char*)(var0 + OBJECT_OFFSET(0x184)) != 0) {
                        var0[OBJECT_OFFSET(0x184)] = *(unsigned char*)(var0 + OBJECT_OFFSET(0x184)) - 1;
                        var27 = 1;
                    } else if (var26 != 0) {
                        func_020a28a0((unsigned char*)var26, 1);
                    }
                }
                if (var27 != 0 && var26 != 0) {
                    func_020a28b0((unsigned char*)var26, 1);
                }
            }
            if (var27 == 0) {
                return;
            }
            if (((Object3D*)ctx)->SetAnimationByName(&data_020f0486, 1) == 0) {
                func_020531f0(ctx);
                return;
            }
            {
                signed char var29 = var0[OBJECT_OFFSET(0x17d)];
                signed char var30 = var0[OBJECT_OFFSET(0x17c)];
                int var31 = var29 + 1;
                if (var31 < var30) {
                    char* var32 = var0 + var31 + 0x100;
                    func_0205308c(var0, var32[OBJECT_OFFSET(0x78)]);
                }
            }
            var0[OBJECT_OFFSET(0x17e)] = 3;
            return;
        } else if (var7 == 3) {
            if (((Object3D*)var0)->HasAnimationStopped() == 0) {
                return;
            }
            if (GetIndexedEntryField0x178_02053604((signed char*)ctx) == 0x19) {
                ForwardToTargetOrDefault0205eabc((void*)&g_sePlayer, ctx + OBJECT_OFFSET(0x198), 0);
            }
            var0[OBJECT_OFFSET(0x17d)] = var0[OBJECT_OFFSET(0x17d)] + 1;
            if (var0[OBJECT_OFFSET(0x17d)] < var0[OBJECT_OFFSET(0x17c)]) {
                var0[OBJECT_OFFSET(0x17e)] = 0;
                *(int*)(var0 + OBJECT_OFFSET(0x190)) = 0;
                return;
            }
            short cid = *(short*)(ctx + 4);
            if (cid == GameState_GetLeaderIndex(bs)) {
                void* p = Scenario_GetInstance();
                unsigned char req[0x34];
                for (int i = 0; i < 4; i++) {
                    char* q = ctx + i + 0x100;
                    ((signed char*)(req + 0x2a))[i] = q[OBJECT_OFFSET(0x78)];
                }
                if (SetTargetFieldAndForEach02064a9c(p, req) != 0) {
                    EventQuery_RunQueuedCommands(req);
                }
            }
            func_020531f0(var0);
            return;
        }
    }
}
