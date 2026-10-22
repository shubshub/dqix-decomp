#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Input/Input.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

extern "C" int func_020421a0(void);
extern "C" unsigned char func_020100b0(GameState* arg0);
extern "C" int func_02039874(void* arg0);
extern "C" int func_02053604(signed char* arg0);

extern "C" void func_020531f0(void* arg0);
struct ObjectArchiveLoadInfo;
extern "C" void* func_02012fe4(void);
extern "C" void func_0205308c(void* arg0, int arg1);
extern "C" void* func_0205ec34(void);
extern "C" void func_0206f81c(void* arg0);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern "C" void func_0205eabc(void* arg0, void* arg1, int arg2);
extern "C" int func_02064a9c(void* arg0, void* arg1);
extern "C" int func_020100f8(char* arg0);
extern "C" void func_ov017_021cc2f0(int);
extern "C" void func_020a28a0(unsigned char* arg0, unsigned char arg1);
extern "C" void func_020a28b0(unsigned char* arg0, int arg1);

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

    int var2 = var0[OBJECT_OFFSET(0x17c)] > 0 ? 1 : 0;
    if (var2 != 0) {
        short var3 = *(short*)(var0 + 4);
        int var4 = func_020100b0(var1);
        if (var4 == var3
            && ((unsigned char*)func_020421a0())[GLOBAL_ACTIVE_OFFSET] != 0) {
            func_020531f0(var0);
            return;
        }
    }

    GameObject* var5 = var1->GetPartyMemberByIndex(*(short*)(var0 + 4));
    int var6 = var0[OBJECT_OFFSET(0x17c)] > 0 ? 1 : 0;
    if (var6 != 0) {
        if (func_02039874(var5) > 0) {
            func_020531f0(var0);
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
            if (((Object3D*)var0)->MaybeSetRegularAnimation(&data_020f0477, 1) == 0) {
                if (((Object3D*)var0)->MaybeSetRegularAnimation(&data_020f047e, 1) == 0) {
                    func_020531f0(var0);
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
                unsigned short val = *(unsigned short*)func_02012fe4();
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
                short var20 = *(short*)(var0 + 4);
                if (var20 == func_020100b0(var1)) {
                    void* var21 = func_0205ec34();
                    unsigned char var22[0x34];
                    for (int var23 = 0; var23 < 4; var23++) {
                        char* var24 = var0 + var23 + 0x100;
                        ((signed char*)(var22 + 0x2a))[var23] = var24[OBJECT_OFFSET(0x78)];
                    }
                    if (func_02064a9c(var21, var22) != 0) {
                        func_0206f81c(var22);
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
                if (((Object3D*)var0)->MaybeSetRegularAnimation(&data_020f0481, var25) != 0) {
                    var0[OBJECT_OFFSET(0x17e)] = 2;
                    return;
                }
                func_020531f0(var0);
                return;
            } else {
                func_020531f0(var0);
                return;
            }
        } else if (var7 == 2) {
            var1 = GameState::GetInstance();
            int var26 = func_020100f8((char*)var1);
            int var27 = 0;
            if (var0[OBJECT_OFFSET(0x17c)] > 1) {
                if (((Object3D*)var0)->HasAnimationStopped() != 0) {
                    var27 = 1;
                }
            } else {
                short var28 = *(short*)(var0 + 4);
                if (var28 == func_020100b0(var1)
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
            if (((Object3D*)var0)->MaybeSetRegularAnimation(&data_020f0486, 1) == 0) {
                func_020531f0(var0);
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
            short var33 = *(short*)(var0 + 4);
            if (var33 == func_020100b0(var1)) {
                void* var34 = func_0205ec34();
                unsigned char var35[0x34];
                for (int var36 = 0; var36 < 4; var36++) {
                    char* var37 = var0 + var36 + 0x100;
                    ((signed char*)(var35 + 0x2a))[var36] = var37[OBJECT_OFFSET(0x78)];
                }
                if (func_02064a9c(var34, var35) != 0) {
                    func_0206f81c(var35);
                }
            }
            func_020531f0(var0);
            return;
        }
    }
}
