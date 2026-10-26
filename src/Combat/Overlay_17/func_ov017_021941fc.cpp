#include <globaldefs.h>
#include "Combat/SearchEntry.h"

#if defined(jpn)
enum {
    Enum_ov017_021941fc_371 = 0x16f,
    Enum_ov017_021941fc_1788 = 0x4ec,
    Enum_ov017_021941fc_1844 = 0x524,
    kRegionOffset4400 = 0x4100,
    kRegionOffsetac = 0xfc,
    Enum_ov017_021941fc_739 = 0xc3,
    Enum_ov017_021941fc_207 = 0xcb,
    kRegionOffset2e2 = 0xc2,
    Enum_ov017_021941fc_969 = 0x139,
    Enum_ov017_021941fc_737 = 0xc1,
    Enum_ov017_021941fc_1052 = 0x16c,
    Enum_ov017_021941fc_741 = 0xc5,
    Enum_ov017_021941fc_752 = 0xd0,
    Enum_ov017_021941fc_798 = 0xfe,
    Enum_ov017_021941fc_2816 = 0x8e0,
    Enum_ov017_021941fc_2864 = 0x910,
    Enum_ov017_021941fc_348 = 0x150,
    Enum_ov017_021941fc_352 = 0x154,
    Enum_ov017_021941fc_364 = 0x160,
    Enum_ov017_021941fc_2860 = 0x90c,
    Enum_ov017_021941fc_1816 = 0x508,
    Enum_ov017_021941fc_2908 = 0x93c,
    Enum_ov017_021941fc_2812 = 0x8dc,
    Enum_ov017_021941fc_2828 = 0x8ec,
    Enum_ov017_021941fc_2832 = 0x8f0,
    Enum_ov017_021941fc_2852 = 0x904,
    Enum_ov017_021941fc_2856 = 0x908,
    Enum_ov017_021941fc_2952 = 0x968,
    Enum_ov017_021941fc_3004 = 0x99c,
    Enum_ov017_021941fc_1804 = 0x4fc,
    Enum_ov017_021941fc_85 = 0x35,
    Enum_ov017_021941fc_17152 = 0x4100,
    Enum_ov017_021941fc_178 = 0xa6,
    Enum_ov017_021941fc_853 = 0x135,
};
#else
enum {
    Enum_ov017_021941fc_371 = 0x173,
    Enum_ov017_021941fc_1788 = 0x6fc,
    Enum_ov017_021941fc_1844 = 0x734,
    kRegionOffset4400 = 0x4400,
    kRegionOffsetac = 0xac,
    Enum_ov017_021941fc_739 = 0x2e3,
    Enum_ov017_021941fc_207 = 0xcf,
    kRegionOffset2e2 = 0x2e2,
    Enum_ov017_021941fc_969 = 0x3c9,
    Enum_ov017_021941fc_737 = 0x2e1,
    Enum_ov017_021941fc_1052 = 0x41c,
    Enum_ov017_021941fc_741 = 0x2e5,
    Enum_ov017_021941fc_752 = 0x2f0,
    Enum_ov017_021941fc_798 = 0x31e,
    Enum_ov017_021941fc_2816 = 0xb00,
    Enum_ov017_021941fc_2864 = 0xb30,
    Enum_ov017_021941fc_348 = 0x15c,
    Enum_ov017_021941fc_352 = 0x160,
    Enum_ov017_021941fc_364 = 0x16c,
    Enum_ov017_021941fc_2860 = 0xb2c,
    Enum_ov017_021941fc_1816 = 0x718,
    Enum_ov017_021941fc_2908 = 0xb5c,
    Enum_ov017_021941fc_2812 = 0xafc,
    Enum_ov017_021941fc_2828 = 0xb0c,
    Enum_ov017_021941fc_2832 = 0xb10,
    Enum_ov017_021941fc_2852 = 0xb24,
    Enum_ov017_021941fc_2856 = 0xb28,
    Enum_ov017_021941fc_2952 = 0xb88,
    Enum_ov017_021941fc_3004 = 0xbbc,
    Enum_ov017_021941fc_1804 = 0x70c,
    Enum_ov017_021941fc_85 = 0x55,
    Enum_ov017_021941fc_17152 = 0x4300,
    Enum_ov017_021941fc_178 = 0xb2,
    Enum_ov017_021941fc_853 = 0x355,
};
#endif
#include "Combat/NameEntryQueue.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Input/Input.h"


struct SearchStruct;
struct SearchStruct0202c1a4;
struct Struct_0209494c {
    char pad[Enum_ov017_021941fc_969];
    unsigned char bit0 : 1;
    unsigned char rest : 7;
    unsigned char unknown_3ca_;
    signed char unknown_3cb_;
};
struct FlagWord02046708;
struct FlagWord020466f4;
struct HeadList020469f8;
struct HeadNode020469f8;
struct HeadNode02046b24;
struct ListHead02046b60;
struct BitField0203402c;
struct U16Field0x6_020375f8;
struct Obj_021bd3a4;
struct Obj02033834;
struct Obj02033874;
struct Obj02033b68;
struct Struct_02028460_3 {
    int x;
    int y;
    int z;
};

struct Struct_02061c04_10 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    short unknown_6_;
    unsigned char f8;
    unsigned short fa;
    signed char fc;
    unsigned char pad;
    float f10;
};

struct Slot021941fc {
    unsigned short f0 : 8;
    unsigned short kind : 8;
    unsigned short active : 1;
    unsigned short members : 4;
    unsigned short unknown_2_5_ : 6;
    unsigned short bit11 : 1;
    unsigned short unknown_3_4_ : 1;
    unsigned short bit13 : 1;
    unsigned short unknown_3_6_ : 1;
    unsigned short unknown_3_7_ : 1;
    unsigned short f4 : 16;
    unsigned short unknown_6_0_ : 16;
    short x;
    short y;
    short z;
    short angle;
};
struct Struct_ov017_021941fc_3 {
    unsigned char low : 2;
    unsigned char high : 6;
};
extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int* func_020936f8(void);
extern "C" void* func_020e3580(void);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" void func_ov017_021cd6d8(struct Struct_02061c04_10* src);
extern "C" void func_ov017_0219577c(int a, int b, int c);
extern "C" void func_ov017_0219593c(void);
extern "C" void func_020939dc(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_020dc2d0(int mode);
extern "C" void func_02093a14(char* obj);
extern "C" void func_02094030(int* a, int b, int c, signed char d);
extern "C" int func_0209494c(struct Struct_0209494c* obj);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" unsigned int FlagWord_TestBits(struct FlagWord02046708* obj, unsigned int mask);
extern "C" void func_020939fc(unsigned char* obj);
extern "C" void func_ov017_021c37a4(void);
extern "C" int LinkSession_IsHostOrSolo(struct SearchStruct* obj);
extern "C" int LinkSession_IsSlotLost(struct SearchStruct* obj, int value);
extern "C" int func_0202c758(struct SearchStruct* obj, int value);
extern "C" void func_ov017_021d1810(int, int, signed char);
extern "C" void func_ov017_021cea34(int a0);
extern "C" void func_0202c6dc(struct SearchStruct* obj, int value);
extern "C" int func_ov017_02195658(unsigned char* self);
extern "C" int LinkSession_IsGuest(struct SearchStruct* obj);
extern "C" void func_ov017_02195618(unsigned char* obj);
extern "C" void func_020e35a0(unsigned char* p);
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* obj, unsigned int mask);
extern "C" int func_ov017_0219531c(void* obj, void* arg1);
extern "C" int GameState_GetOwnPartyOrder(char* obj, void* dst);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void func_ov017_02195250(void* d, void* buf);
extern "C" int LinkSession_IsSlotConnected(struct SearchStruct* obj, int value);
extern "C" void FlagWord_SetBits(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_021cc198(unsigned char a, int b);
extern "C" void func_ov017_021d0b30(int a, int b, void* c);
extern "C" void func_0202c69c(struct SearchStruct* obj, int value);
extern "C" void func_0202c718(struct SearchStruct* obj, int value);
extern "C" void func_0202c660(struct SearchStruct* obj, int value);
extern "C" int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" GameObject* func_0200fee0(GameState* battleStruct, int combatantId);
extern "C" void func_ov017_02195494(void* obj, int index, int val);
extern "C" int func_0202bd68(struct SearchStruct* self, int arg1);
extern "C" void func_ov003_02167240(void* obj);
extern "C" int abs(int x);
extern "C" void func_ov017_021af59c(void* obj);
extern "C" void func_020469f8(struct HeadList020469f8* list, struct HeadNode020469f8* node);
extern "C" int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
extern "C" void func_ov017_021905b8(unsigned char* ov, int combatantId, int mode);
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" void* LinkSession_GetOwnRecord(void* base);
extern "C" int func_02053ed0(void* obj);
extern "C" int GameObject_IsSinking(struct BitField0203402c* p);
extern "C" int fix32_Divide(int a, int b);
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
extern "C" unsigned short LinkSession_GetConnectedAids(struct SearchStruct* obj);
extern "C" int func_ov017_021bd3a4(struct Obj_021bd3a4* obj);
extern "C" int GameObject_GetLineLeader(void* obj);
struct Vector3i;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int value);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int value);
extern "C" int GameObject_IsGesturing(signed char* p);
extern "C" void func_020531f0(void* obj);
extern "C" GameObject* func_0200ffe0(GameState* battleStruct, int id);
extern "C" void func_02076ccc(void* obj, int mode);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int value);
extern "C" void func_ov017_021bd4d0(void* obj, unsigned char id, int a, int b);
extern "C" void func_ov017_021d48f0(void);
extern "C" void* func_0207d78c(void);
extern "C" void func_0207dba8(void* p);
extern int data_ov017_021d63f0;
extern int data_ov017_021d63d8;
extern int data_ov017_021d63e4;
extern int data_ov017_021d63fc;
// USA: func_ov017_021941fc
extern "C" ARM void func_ov017_021941fc(unsigned char* ov, unsigned char* mode, void** list) {
    struct Struct_02061c04_10 params;
    unsigned char entry[15];
    int var2[3];
    int var3[3];
    struct Struct_02028460_3 target;
    unsigned char region[4];

    GameState* battle;
    struct SearchStruct* search;
    GameObject* actor;
    void* flags;
    int ctx;
    void* loader;
    void* owner;
    int* g;
    unsigned char* status;
    battle = GameState::GetInstance();
    ctx = ((int)GetGameResources());
    search = LinkSession_GetInstance();
    actor = battle->GetLeader();
    loader = (void*)(int)BackgroundLoader::GetInstance();
    list = *(void***)(ov + 0x3000 + Enum_ov017_021941fc_1788);
    owner = Scenario_GetInstance();
    flags = GlobalFlags_GetInstance();
    g = func_020936f8();
    mode = *(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_1844);
    status = (unsigned char*)func_020e3580();
    if (FieldTaskQueue_IsEmpty(list) != 0 && *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac) != 0) {
        params.f0 = 0;
        params.f2 = 0;
        params.f4 = 0;
        params.unknown_6_ = 0;
        params.f8 = 0;
        params.fa = 0;
        params.f10 = 0.0f;
        params.fc = -1;
        params.f2 = *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac);
        func_ov017_021cd6d8(&params);
        *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac) = 0;
    }
    if (IsBrightnessZero((GameResources*)ov, false) != 0) {
        int restart = 0;
        if (*(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_739) != 0) {
            unsigned char* m = *(unsigned char**)((unsigned char*)ctx + 0x3000 + Enum_ov017_021941fc_1844);
            if (m[3] != 0 && *(unsigned short*)(m + 8) == 0 && m[Enum_ov017_021941fc_207] == 2) {
                func_ov017_0219577c(0, 0, 0);
            } else {
                func_ov017_0219593c();
                func_020939dc(func_020936f8());
            }
            restart = 1;
        } else if (FieldTaskQueue_IsEmpty(list) != 0 && *(unsigned char*)(ov + 0x4000 + kRegionOffset2e2) != 0) {
            if (GameState_GetProtagonistIndex(battle) != 0) {
                func_ov017_0219577c(0, 1, 1);
            }
            restart = 1;
        }
        if (restart != 0) {
            func_020dc2d0(0);
            func_02093a14((char*)g);
            func_02094030(g, 4, -1, 0);
            *(unsigned char*)(ov + 0x4000 + kRegionOffset2e2) = 0;
            *(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_739) = 0;
        }
    }
    if (((struct Struct_0209494c*)g)->bit0 &&
        func_0209494c((struct Struct_0209494c*)g) != 0 &&
        LinkSession_IsActive((int*)search) == 0 &&
        FlagWord_TestBits((struct FlagWord02046708*)flags, 0x1000) == 0) {
        func_020939fc((unsigned char*)g);
    }
    if (TestFlags00((GameResources*)ov, 2) != 0) return;
    if (LinkSession_IsActive((int*)search) == 0) return;
    if (*(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_737) != 0 &&
        ((BackgroundLoader*)loader)->GetNumQueuedTasks() == 0) {
        func_ov017_021c37a4();
        *(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_737) = 0;
    }
    if (LinkSession_IsHostOrSolo(search) != 0) {
        int var17 = -1;
        for (int i = 1; i < 4; i++) {
            if (LinkSession_IsSlotLost(search, i) == 0) continue;
            if (func_0202c758(search, i) != 0) continue;
            func_02094030(func_020936f8(), 3, var17, i);
            func_ov017_021d1810(3, var17, i);
            func_ov017_021cea34(i);
            func_0202c6dc(search, i);
        }
    }
    if (FlagWord_TestBits((struct FlagWord02046708*)flags, 0x40000) == 0) {
        func_ov017_02195658(ov);
    }
    if (LinkSession_IsGuest(search) != 0) {
        if (LinkSession_IsSlotLost(search, 0) != 0) {
            func_ov017_02195618(ov);
        }
    } else {
        for (int i = 1; i < 4; i++) {
            if (LinkSession_IsSlotLost(search, i) == 0) continue;
            if (func_0202c758(search, i) != 0) continue;
            func_ov017_021cea34(i);
            func_0202c6dc(search, i);
        }
    }
    func_020e35a0(status);
    if ((*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] == 0) {
        if (LinkSession_IsHostOrSolo(search) != 0) {
            if (status[1] != 0) goto dispatched;
            FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x800);
            if (func_ov017_0219531c(ov, entry) == 0) goto dispatched;
            int accept = 1;
            int used = GameState_GetOwnPartyOrder((char*)battle, region);
            if (used + entry[1] > 4) accept = 0;
            if (Scenario_TestFlag((int)owner, (unsigned char*)owner + 0x8c, 3) != 0) {
                func_ov017_02195250(ov, entry);
                accept = 0;
            }
            if (LinkSession_IsSlotConnected(search, entry[0]) == 0) accept = 0;
            if (entry[0xe] != 0) accept = 0;
            if (accept != 0) {
                FlagWord_SetBits((unsigned int*)flags, 0x800);
                func_ov017_021cc198(entry[0], 1);
                func_ov017_021d0b30(0, entry[0], entry + 2);
                func_0202c69c(search, entry[0]);
                func_0202c718(search, entry[0]);
                (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] = 1;
                (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[1] = 0;
                func_ov017_02195214((Struct_ov017_021941fc *) (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052) + 2),
                    (Struct_ov017_021941fc *) entry);
                *(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_741) = 1;
            } else {
                func_ov017_021cc198(entry[0], 0);
                func_0202c660(search, entry[0]);
                if (*(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_752) == 0) {
                    FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x800);
                }
            }
        } else if (*(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_798) != 0 &&
                   LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search) > 0) {
            int slot = 0;
            for (int i = 1; i < 4; i++) {
                if ((*(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_798) & (1 << i)) != 0) {
                    *(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_798) &= ~(1 << i);
                    slot = i;
                    break;
                }
            }
            int var24;
            if (func_0200fee0(battle,
                    LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search)) != NULL) {
                var24 = 1;
            } else {
                var24 = 2;
            }
            (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] = 1;
            (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[1] = (unsigned char)var24;
            func_ov017_02195494(ov, slot,
                (int)(*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052) + 2));
            (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[2] = (unsigned char)slot;
            (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[3] = 1;
            if (var24 == 1) *(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_741) = 1;
        }
    } else if ((*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] == 1) {
        if (func_0202bd68(search, (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[2]) != 0) {
            if ((*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[1] == 2) {
                void* holder = *(void**)(*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2816) + 0x24);
                if (holder != NULL) func_ov003_02167240(holder);
                (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] = 2;
            } else {
                if (LinkSession_IsHostOrSolo(search) != 0 && *(int*)((char*)search + 0xfc0) == 0) {
                    if (LinkSession_IsSlotConnected(search,
                            (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[2]) == 0) {
                        unsigned char* st = *(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052);
                        st[0] = 0;
                        st[1] = 0;
                    }
                }
                int ok = 1;
                if (FieldTaskQueue_IsEmpty(list) == 0) ok = 0;
                if (mode[3] != 0 && mode[Enum_ov017_021941fc_207] == 2) ok = 1;
                int dx = abs(GetBrightness((GameResources*)ov, false));
                if (dx + abs(GetBrightness((GameResources*)ov, true)) > 0) ok = 0;
                if (*(short*)((char*)actor + 0xac) != 0) ok = 0;
                if (FlagWord_TestBits((struct FlagWord02046708*)flags, 0x200) != 0) ok = 1;
                if (FlagWord_TestBits((struct FlagWord02046708*)flags, 0x400) != 0) ok = 0;
                if (((BackgroundLoader*)loader)->GetNumQueuedTasks() > 0) ok = 0;
                if (ok != 0) {
                    unsigned char* node = *(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2864);
                    func_ov017_021af59c(node);
                    node[9] = (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[1];
                    func_ov017_02195214((Struct_ov017_021941fc *) (node + 0xc),
                        (Struct_ov017_021941fc *) (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052) + 2));
                    func_020469f8((struct HeadList020469f8*)list,
                        (struct HeadNode020469f8*)node);
                    (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] = 2;
                } else if (*(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_741) != 0) {
                    func_02094030(g, 5, -1, 0);
                    *(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_741) = 0;
                }
            }
        } else if (LinkSession_IsSlotMember(search,
                       (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[2]) != 0) {
            if (FlagWord_TestBits((struct FlagWord02046708*)flags, 0x40000) == 0) {
                func_ov017_021905b8(ov,
                    (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[2], 0);
            }
        } else if ((*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[1] != 2) {
            (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] = 2;
        }
    } else if ((*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] == 2) {
        if (func_02046b60((struct ListHead02046b60*)list, 0x26) != 0) goto dispatched;
        if (*(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_752) == 0) {
            FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x800);
        }
        (*(unsigned char**)(ov + 0x4000 + Enum_ov017_021941fc_1052))[0] = 0;
    }
dispatched:
    if (TestFlags00((GameResources*)ov, 2) != 0) return;
    if (LinkSession_IsActive((int*)search) == 0) return;
    struct Slot021941fc* slot = (struct Slot021941fc*)LinkSession_GetOwnRecord(search);
    if (TestFlags00((GameResources*)ov, 0x40) == 0) {
        int kind = 0;
        unsigned char var32 = 0;
        if (((Object3D*)((struct U16Field0x6_020375f8*)actor))->GetField06() == 10000 ||
            *(int*)((char*)actor + Enum_ov017_021941fc_348) == 10000) {
            *(Vector3i*)var2 = *(Vector3i const*)&data_ov017_021d63f0;
            *(Vector3i*)var3 = *(Vector3i const*)&data_ov017_021d63d8;
            kind = 0;
        } else if (((Object3D*)((struct U16Field0x6_020375f8*)actor))->GetField06() == 10100 ||
                   *(int*)((char*)actor + Enum_ov017_021941fc_348) == 10100) {
            *(Vector3i*)var2 = *(Vector3i const*)&data_ov017_021d63e4;
            *(Vector3i*)var3 = *(Vector3i const*)&data_ov017_021d63fc;
            kind = 0;
        } else if (func_02053ed0(actor) == 0) {
            *(Vector3i*)var2 = *(Vector3i const*)(&actor->obj3D_.position_.x);
            *(Vector3i*)var3 = *(Vector3i const*)(&actor->obj3D_.rotation_.x);
            if (GameObject_IsSinking((struct BitField0203402c*)actor) != 0) {
                var2[1] = var2[1] - fix32_Divide(actor->obj3D_.GetHeight(), 0x1800);
            }
            kind = *(unsigned char*)((char*)actor + 0xbe);
            if (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)list) == 0x26) kind = 0;
            var32 = 1;
        } else {
            *(Vector3i*)var2 = *(Vector3i const*)((int*)((char*)actor + Enum_ov017_021941fc_352));
            *(Vector3i*)var3 = *(Vector3i const*)((int*)((char*)actor + Enum_ov017_021941fc_364));
            if (func_02053ed0(actor) == 1) {
                kind = 2;
            } else {
                kind = var32;
            }
        }
        slot->x = (short)(var2[0] >> 7);
        slot->y = (short)(var2[1] >> 7);
        slot->z = (short)(var2[2] >> 7);
        slot->angle = (short)var3[1];
        slot->kind = (unsigned short)kind;
        slot->f4 = LinkSession_GetConnectedAids(search);
        slot->unknown_6_0_ = g_keyManager.currentKeys_;
        slot->unknown_3_4_ = 1;
        slot->unknown_3_7_ = var32;
        slot->members = 0;
        for (int i = 0; i < 4; i++) {
            if (battle->GetGameObjectByIndex(i) != NULL) {
                slot->members |= (1 << i);
            }
        }
        if (func_ov017_021bd3a4(
                *(struct Obj_021bd3a4**)(ov + 0x3000 + Enum_ov017_021941fc_1844)) != 0) {
            unsigned char* base = *(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_1844);
            base++;
            slot->members &= ~base[Enum_ov017_021941fc_371];
        }
    } else {
        slot->kind = 0;
    }
    unsigned char* actorNode = *(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2864);
    unsigned char* var36 = *(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2860);
    unsigned char* var37 = *(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_1816);
    unsigned char* var38 = *(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2908);
    slot->active = 0;
    slot->active |= actorNode[3];
    slot->active |= var36[3];
    slot->bit11 = 0;
    slot->bit11 |= var37[3];
    slot->bit11 |= var38[3];
    slot->bit13 = 1;
    if (FieldTaskQueue_IsEmpty(list) == 0) {
        slot->bit13 = 0;
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2812))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2828))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2832))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2852))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2856))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_2952))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_3004))[3];
    }
    slot->unknown_3_6_ = (*(unsigned char**)(ov + 0x3000 + Enum_ov017_021941fc_1804))[3];
    if (mode[Enum_ov017_021941fc_207] == 2) {
        slot->active |= mode[3];
    }
    if (TestFlags00((GameResources*)ov, 0x40) == 0) {
    unsigned char* pending = ov + Enum_ov017_021941fc_17152 + Enum_ov017_021941fc_85;
    for (int i = 0; i < 4; i++) {
        if (i == 0 && TestFlags00((GameResources*)ov, 0x200) != 0) continue;
        if (LinkSession_IsSlotMember(search, i) == 0) continue;
        if (i == LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search)) continue;
        SearchEntry0202c178* other = LinkSession_GetReceivedRecord(search, i);
        if (other == NULL) continue;
        GameObject* c = battle->GetPartyMemberByIndex(i);
        if (c == NULL) continue;
        c = battle->GetPartyMemberByIndex(GameObject_GetLineLeader(c));
        if (c == NULL) continue;
        if ((((struct Struct_ov017_021941fc_3*)((char*)c + 0xc1))->low & 1) == 0 && other->unknown_3_4_) {
            target.x = other->x << 7;
            target.y = other->y << 7;
            target.z = other->z << 7;
            int angle = other->angle;
            *(Vector3i*)((int*)((char*)c + 0xd4)) = *(Vector3i const*)((int*)&target);
            *(unsigned char*)((char*)c + 0xe0) |= 0x10;
            GameObject_SetFacing((struct Obj02033834*)c, angle);
            struct Struct_02028460_3 current = *(struct Struct_02028460_3*)((char*)c + 0x44);
            if (Vector3fix_Distance((const Vector3fix*)&target, (const Vector3fix*)&current) > 0x1000) {
                *(Vector3i*)(&c->obj3D_.position_.x) = *(Vector3i const*)((int*)&target);
                GameObject_SnapFacing((struct Obj02033874*)c, angle);
            }
        }
        if (other->flags.kind == 2) {
            if (GameObject_IsGesturing((signed char*)c) != 0) {
                func_020531f0(c);
            }
            GameObject* var45 = func_0200ffe0(battle,
                *(unsigned short*)((char*)c + 0x100 + Enum_ov017_021941fc_178));
            if (var45 != NULL && *(int*)((char*)var45 + 0x130) != 9) {
                if ((**(int**)((char*)c + 0x130) & 1) == 0) {
                    func_02076ccc(var45, 9);
                }
            }
        }
        if ((((struct Struct_ov017_021941fc_3*)((char*)c + 0xc1))->low & 2) == 0) {
            int face = *(unsigned char*)((char*)c + 0xbe);
            if (face == 2 && other->flags.kind != 2) {
                func_ov017_021917f0(i, 0);
            } else if (other->flags.kind == 2 && face != 2) {
                func_ov017_021917f0(i, 1);
            }
            GameObject_SetMotionState((struct Obj02033b68*)c, other->flags.kind);
        }
        if ((*(unsigned char*)(ov + 0x4000 + Enum_ov017_021941fc_853) & (1 << i)) == 0) continue;
        if (other->unknown_3_7_ != 1) continue;
        func_ov017_021bd4d0(*(void**)(ov + 0x3000 + Enum_ov017_021941fc_1844), i, 1, 1);
        *pending = *pending & ~(1 << i);
    }
    }
    func_ov017_021d48f0();
    func_0207dba8(func_0207d78c());
}
