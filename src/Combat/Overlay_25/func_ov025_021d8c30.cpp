#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov025_021d8c30_336 = 0x144, Enum_ov025_021d8c30_2540 = 0x968, Enum_ov025_021d8c30_2528 = 0x95c, Enum_ov025_021d8c30_2086 = 0x7a2, Enum_ov025_021d8c30_1224 = 0x444, Enum_ov025_021d8c30_1220 = 0x440, Enum_ov025_021d8c30_3768 = 0xe34, Enum_ov025_021d8c30_3752 = 0xe24, Enum_ov025_021d8c30_1232 = 0x44c, Field4ca = 0x446, Field2a0 = 0x21c, Enum_ov025_021d8c30_1132 = 0x3e8, Enum_ov025_021d8c30_396 = 0x180, Enum_ov025_021d8c30_3208 = 0xc04, Enum_ov025_021d8c30_14176 = 0x371c, Enum_ov025_021d8c30_28238 = 0x703e, Enum_ov025_021d8c30_28414 = 0x70ee, Enum_ov025_021d8c30_28632 = 0x71c8, Enum_ov025_021d8c30_28648 = 0x71d8, Enum_ov025_021d8c30_30532 = 0x7934, Enum_ov025_021d8c30_30533 = 0x7935, Enum_ov025_021d8c30_30534 = 0x7936, Enum_ov025_021d8c30_28636 = 0x71cc, Enum_ov025_021d8c30_28668 = 0x71ec, Enum_ov025_021d8c30_680 = 0x224, Enum_ov025_021d8c30_2192 = 0x80c, CameraBase = 0xb94, ModeByte = 0xdb4 };
#else
enum { Enum_ov025_021d8c30_336 = 0x150, Enum_ov025_021d8c30_2540 = 0x9ec, Enum_ov025_021d8c30_2528 = 0x9e0, Enum_ov025_021d8c30_2086 = 0x826, Enum_ov025_021d8c30_1224 = 0x4c8, Enum_ov025_021d8c30_1220 = 0x4c4, Enum_ov025_021d8c30_3768 = 0xeb8, Enum_ov025_021d8c30_3752 = 0xea8, Enum_ov025_021d8c30_1232 = 0x4d0, Field4ca = 0x4ca, Field2a0 = 0x2a0, Enum_ov025_021d8c30_1132 = 0x46c, Enum_ov025_021d8c30_396 = 0x18c, Enum_ov025_021d8c30_3208 = 0xc88, Enum_ov025_021d8c30_14176 = 0x3760, Enum_ov025_021d8c30_28238 = 0x6e4e, Enum_ov025_021d8c30_28414 = 0x6efe, Enum_ov025_021d8c30_28632 = 0x6fd8, Enum_ov025_021d8c30_28648 = 0x6fe8, Enum_ov025_021d8c30_30532 = 0x7744, Enum_ov025_021d8c30_30533 = 0x7745, Enum_ov025_021d8c30_30534 = 0x7746, Enum_ov025_021d8c30_28636 = 0x6fdc, Enum_ov025_021d8c30_28668 = 0x6ffc, Enum_ov025_021d8c30_680 = 0x2a8, Enum_ov025_021d8c30_2192 = 0x890, CameraBase = 0xc18, ModeByte = 0xe38 };
#endif

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094 {
    char pad0[0x20];
    unsigned short combatantId;
};

struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8 {
    char pad0[0xe];
    short ids[3];
    unsigned char codes[3];
    unsigned char count;
    unsigned char pad18[4];
    unsigned char unknown_1c_0_ : 7;
    unsigned char unknown_1c_7_ : 1;
};

struct Struct_ov000_0215feb4;

struct Struct_ov025_021d8c30 {
    unsigned long long mask;
    char pad8[4];
    short amount;
    short unknown_e_;
    short unknown_10_;
    short unknown_12_;
    short unknown_14_;
    char pad16[2];
    unsigned int unknown_18_;
    unsigned char show;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
};

struct Struct_ov025_021d8c30_2 {
    char pad0[0xc];
    short value;
    char unknown_e_[0x12];
    struct Struct_ov025_021d8c30_2* next;
};

struct Struct_ov025_021d8c30_3 {
    struct Struct_ov025_021d8c30_2* cells[3];
    char unknown_c_[0xc];
    unsigned char counts[3];
    char unknown_1b_[5];
    struct Struct_ov025_021d8c30_3* next;
};

struct Struct_ov025_021d8c30_4 {
    unsigned short type;
    char pad2[7];
    unsigned char unknown_9_;
    char unknown_a_;
    unsigned char lo : 3;
    unsigned char unknown_b_3_ : 1;
    unsigned char queued : 1;
    unsigned char group : 3;
    char unknown_c_[8];
    struct Struct_ov025_021d8c30_3* rows;
    char pad18[0xa];
    unsigned short unknown_22_;
    unsigned short unknown_24_;
};

struct Struct_ov025_021d8c30_5 {
    char pad0[0x14];
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};

struct Struct_ov025_021d8c30_6 {
    char pad0[0x10];
    unsigned int pad10 : 31;
    unsigned int unknown_13_7_ : 1;
    char unknown_14_[0x10];
    unsigned int unknown_24_0_ : 28;
    unsigned int unknown_27_4_ : 1;
    unsigned int unknown_27_5_ : 3;
};

struct Struct_ov025_021d8c30_7 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Struct_ov025_021d8c30_8 {
    unsigned short duration;
    short strength;
};

struct Struct_ov025_021d8c30_9 {
    void* unknown_0_;
    int w1;
    int w2;
    int unknown_c_;
    int w4;
    unsigned char b;
    unsigned char pad[3];
    short s18;
    short unknown_1a_;
    int unknown_1c_;
};

struct Struct_ov025_021d8c30_10 {
    unsigned int unknown_0_;
    unsigned int w1;
    unsigned int w2;
    unsigned int unknown_c_;
    unsigned int w4;
    unsigned char b;
    unsigned char pad[3];
    short s18;
    short unknown_1a_;
};

struct Struct_ov025_021d8c30_11 {
    unsigned int unknown_0_;
    unsigned int w1;
    unsigned int w2;
    unsigned int unknown_c_;
    unsigned int w4;
    unsigned char b;
};

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char unknown_11_;
    short f12;
    short objectId;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct SePlayer;
struct Obj0203a48c;
struct Vec3Int0203a48c;
struct Obj0203a588;
struct ShortPair0xba0xbc;
struct Struct_ov000_02161c0c_3;
struct Bytes02033b88;
struct Struct_ov000_02176134;
struct Obj02176150;

extern "C" void* LinkSession_GetInstance(void);
extern "C" struct Obj0203a588* NumberPopups_GetInstance(void);
extern "C" int func_ov000_02163524(void* obj);
extern "C" void* func_02079e2c(char* p, int key);
extern "C" unsigned char func_ov025_021dcc64(void* obj);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" void func_ov025_021dcc70(char* obj, char* src);
extern "C" void func_ov025_021dcde8(unsigned char* obj, struct Struct_ov025_021d8c30_11* src);
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" struct Struct_ov000_0215feb4* func_ov000_0215feb4(char* base, int threshold, int slot);
extern "C" int func_ov000_0215ffa0(void* node);
extern "C" void* func_ov000_0215fff4(void* obj, int limit, int idx);
extern "C" void func_ov000_02182498(void* objRaw, int flag);
extern "C" int strcmp(const char* a, const char* b);
extern "C" void func_ov025_021eaf48(unsigned char* obj, int idx, int category, int entry);
extern "C" void func_ov025_021ea604(unsigned char* obj, int idx, int category, int entry);
extern "C" void func_ov000_02162dc4(unsigned char* sl, GameObject* arg1, GameObject* actor, unsigned int flags,
                                    int arg4, int arg5, unsigned long long mask, int zero);
extern "C" void func_02049ae4(unsigned char* obj);
extern "C" void func_ov000_0216f1e4(void* obj, int* arg1, int a, int b);
extern "C" void Camera_Shake(unsigned char* obj, int a, int b);
extern "C" void func_ov000_02163440(void* obj, short a, unsigned short b, unsigned short c);
extern "C" void func_0205ec20(void* obj, void* target, int arg);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_ov025_021ed444(char* obj, int id, int val2, int type, int val3, short arg5, unsigned short arg6);
extern "C" int func_ov025_021ed380(char* obj, int id, int val2, int type, int val3, short arg5, unsigned short arg6);
extern "C" void* func_02057924(void);
extern "C" void func_02078484(struct Struct_02078398_2* p);
extern "C" void func_02057fb4(void* list, int id, void* config);
extern "C" int func_02085078(unsigned char* obj);
extern "C" int func_020850a4(unsigned char* obj);
extern "C" int func_ov000_0215fd90(void* entry, int effect);
extern "C" void GameObject_Shake(ShortPair0xba0xbc* obj, short a, unsigned short b);
extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f08(void* obj);
extern "C" void* func_ov025_021dafd0(char* obj, int id);
extern "C" void func_ov000_0217616c(void* p);
extern "C" void func_0204a00c(unsigned char* obj, int value);
extern "C" void NumberPopups_Add(Obj0203a48c*, int, Vec3Int0203a48c*, int, int, int);
extern "C" void func_02049f28(unsigned char* obj);
extern "C" void func_02048588(unsigned char* self, unsigned char* dst);
extern "C" void func_ov000_02166784(struct Struct_ov000_02161c0c_3* arg0, unsigned char* obj2, unsigned char* arg2);
extern "C" void func_ov000_021677fc(void* p);
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
extern "C" int func_02049ee8(unsigned char* obj);
extern "C" void func_020d7334(unsigned char* base, int index);
extern "C" void func_02049f3c(unsigned char* obj);
extern "C" void func_ov000_02167434(unsigned char* obj, int value);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
extern "C" void func_02054028(void* obj, int n);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
extern "C" void SePlayer_PlayExtra(void* obj, int a, int b);
extern "C" void func_ov000_021823dc(unsigned char* obj, int val);
extern "C" int func_ov000_02163c0c(void* unused, int id);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_ov000_02176134(struct Struct_ov000_02176134* obj, short val);
extern "C" void func_ov000_02176150(struct Obj02176150* obj, short val);
extern "C" void func_ov000_0216ff20(char* obj, unsigned char val);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void func_ov017_021c9d2c(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern struct SePlayer g_sePlayer;
extern char data_ov025_021ef3d0[];
extern char data_ov025_021ef3d5[];
extern char data_ov025_021ef3e0[];
extern char data_ov025_021ef3e8[];
extern char data_ov025_021ef3ef[];
extern char data_ov025_021ef3f5[];
extern char data_ov025_021ef3fc[];
extern const int data_ov025_021eeea4[];
extern const int data_ov025_021eeebc[];

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

static inline int inline_ov000_02156cc4_2(unsigned short id) {
    return id <= 3;
}

static inline unsigned char* inline_01ff91ac_3(Struct_ov000_021600f8* row) {
    return row->codes;
}

static inline int PopupDelay(int inner) {
    return data_ov025_021eeea4[inner];
}

static inline int PopupColor(int inner) {
    return data_ov025_021eeebc[inner];
}

static inline fix32_t inline_ov025_021d8c30_3(fix32_t a, fix32_t b) {
    return FIX32_MULTIPLY(a, b);
}

static inline Vector3fix inline_ov025_021d8c30_4(void* work) {
    return *(Vector3fix*)((unsigned char*)work + Enum_ov025_021d8c30_28636);
}

// USA: func_ov025_021d8c30
extern "C" ARM int func_ov025_021d8c30(unsigned char* sl, struct Struct_ov025_021d8c30_4* sb, int kind, int category,
                                        int idx, int inner, unsigned char flag) {
    Struct_ov000_02160094* first;
    GameState* battle;
    char* ov17;
    unsigned char* camera;
    struct Obj0203a48c* popups;
    int var5;
    struct Struct_ov025_021d8c30_5* entry;
    int var7;
    int result;
    int var9;
    int var10;
    int var11;
    int leadId;
    GameObject* var13;
    Struct_ov000_02160094* var14;
    int var15;
    int var16;
    GameObject* animObj;
    unsigned char var18;
    int var19;
    int cleared;
    int var21;
    int var22;
    int var23;
    int var24;
    GameObject* slotObj;
    int var26;
    int var27;
    void* work;
    int amount;
    unsigned char var30;
    int sfx;
    unsigned char var32;
    unsigned char var33;
    unsigned char party;
    int negAmount;
    void* list;
    int facing;
    int var38;
    int var39;
    int var40;
    int special;
    struct Struct_ov025_021d8c30_8* msg;
    int slot;
    int i;
    int var45;
    unsigned char flags;
    bool var47;

    battle = GameState::GetInstance();
    ov17 = (char*)GetGameResources();
    LinkSession_GetInstance();
    camera = (unsigned char*)battle->GetCamera();
    popups = (struct Obj0203a48c*)NumberPopups_GetInstance();
    var5 = func_ov000_02163524(sl);
    entry = (struct Struct_ov025_021d8c30_5*)func_02079e2c((char*)func_020797dc(), *(short*)sb);
    var7 = 0;
    if (entry != 0 && entry->unknown_19_4_ == 2) {
        var7 = 1;
    }

    if (kind == 0 && sl[Enum_ov025_021d8c30_28238] == 6) return 0;
    if (kind == 1 && sl[Enum_ov025_021d8c30_28238] == 4) return 0;

    *(unsigned short*)(sl + Enum_ov025_021d8c30_2540) = sl[Enum_ov025_021d8c30_2528];

    int id = -1;
    result = 0;
    struct Struct_ov025_021d8c30* target = 0;
    Struct_ov000_021600f8* row = 0;
    const char* animName;
    int var52;

    if (flag == 0) {
        if (func_ov025_021dcc64(sl) != 0) {
            Struct_ov000_021600f8* node = func_ov000_021600f8((Struct_ov000_0215440c*)sb, idx);
            struct Struct_ov025_021d8c30_9 tmp;
            if (node) {
                tmp.s18 = node->ids[1];
                tmp.unknown_1a_ = node->ids[0];
            }
            tmp.w2 = category;
            tmp.unknown_0_ = sb;
            tmp.w1 = kind;
            tmp.unknown_c_ = idx;
            tmp.w4 = inner;
            tmp.b = 1;
            func_ov025_021dcc70((char*)sl, (char*)&tmp);
            return 0;
        }
        int queued = sl[Enum_ov025_021d8c30_28414];
        if (queued > 0) {
            struct Struct_ov025_021d8c30_10 var56;
            var56.w2 = category;
            var56.unknown_0_ = (unsigned int)sb;
            var56.w1 = kind;
            var56.unknown_c_ = idx;
            var56.w4 = inner;
            var56.b = 1;
            func_ov025_021dcde8(sl, (struct Struct_ov025_021d8c30_11*)&var56);
            return result;
        }
    }

    var9 = 0;
    if (kind == 0) {
        Struct_ov000_02160094* node = func_ov000_02160094((Struct_ov000_0215440c_2*)sb, idx);
        if (node) {
            id = node->combatantId;
            if (category == 0) {
                result = (int)func_ov000_0215feb4((char*)node, inner, 0);
            } else if (category == 1) {
                result = (int)func_ov000_0215feb4((char*)node, inner, 2);
            } else if (category == 2) {
                result = (int)func_ov000_0215feb4((char*)node, inner, 3);
            } else if (category == 3) {
                result = (int)func_ov000_0215feb4((char*)node, inner, 5);
            } else if (category == 4) {
                result = (int)func_ov000_0215feb4((char*)node, inner, 4);
            } else if (category == 5) {
                result = (int)func_ov000_0215feb4((char*)node, inner, 1);
            }
        }
    } else if ((unsigned int)(kind - 1) <= 2) {
        Struct_ov000_021600f8* node = func_ov000_021600f8((Struct_ov000_0215440c*)sb, idx);
        if (node) {
            row = node;
            id = func_ov000_0215ffa0(node);
            if (category == 0) {
                result = (int)func_ov000_0215fff4(node, inner, 0);
            } else if (category == 1) {
                result = (int)func_ov000_0215fff4(node, inner, 1);
            } else if (category == 2) {
                result = (int)func_ov000_0215fff4(node, inner, 2);
            }
            var9 = 1;
        }
    }
    if (sb->unknown_b_3_) {
        func_ov000_02182498(sl + Enum_ov025_021d8c30_28668, 1);
    }

    GameObject* actor = battle->GetCombatantByIndex(id);
    if (result != 0) target = (struct Struct_ov025_021d8c30*)result;
    if (id < 0 || actor == 0 || target == 0) {
        return result;
    }

    var10 = 0;
    var11 = 0;
    animName = (const char*)actor->obj3D_.activeAnimationRecord_;
    if (animName != 0 && strcmp(animName, data_ov025_021ef3d0) == 0) {
        var10 = 1;
        var11 = actor->obj3D_.GetCurrentAnimationTime();
    }

    first = func_ov000_02160094((Struct_ov000_0215440c_2*)sb, 0);
    leadId = -1;
    var13 = 0;
    var14 = 0;
    if (first) {
        leadId = first->combatantId;
        var13 = battle->GetCombatantByIndex(leadId);
        var14 = first;
    }

    msg = (struct Struct_ov025_021d8c30_8*)(sl + Enum_ov025_021d8c30_2086);
    var15 = 0;
    sfx = *(short*)(sl + Enum_ov025_021d8c30_1224);
    animObj = actor;
    var16 = *(unsigned short*)(sl + Enum_ov025_021d8c30_1220);
    var19 = var18 = var15;
    if (row != 0 && (row->codes[1] == 8 || row->codes[1] == 7 || row->codes[1] == 6) && row->codes[2] == 3) {
        var16 = 1;
        sfx = 0x1e;
        var19 = var16;
    }

    if (kind == 0) {
        func_ov025_021eaf48(sl + Enum_ov025_021d8c30_680, idx, category, result);
    } else if (kind == 1) {
        func_ov025_021ea604(sl + Enum_ov025_021d8c30_680, idx, category, result);
    } else if (kind == 3) {
        func_ov025_021ea604(sl + Enum_ov025_021d8c30_680, idx, category, result);
    }
    if (kind != 2) {
        func_ov000_02162dc4(sl, var13, actor, target->unknown_18_, target->unknown_1d_, target->unknown_1e_, target->mask, 0);
    }
    if (actor) {
        func_02049ae4((unsigned char*)actor);
    }

    cleared = 0;
    var21 = 0;
    var22 = 0;
    flags = 0;
    var23 = 0;
    var24 = 0;
    var45 = kind - 1;

    if ((unsigned int)var45 <= 1) {
        for (i = 1; i < row->count; i++) {
            slot = i - 1;
            int var60 = row->ids[slot];
            slotObj = battle->GetCombatantByIndex(var60);
            if (slotObj == 0) continue;

            if (row->codes[i] == 3 && kind == 2) {
                Vector3fix pos = *(Vector3fix*)(sl + Enum_ov025_021d8c30_3208);
                fix32_t q = fix32_Divide(0x6000, pos.z);
                pos.y = FIX32_MULTIPLY(pos.y, q);
                pos.z = 0x7000;
                func_ov000_0216f1e4(sl + CameraBase, &pos.x, 0xb33, 0);
                Camera_Shake(sl + CameraBase, 0xcc, 0x3e8);
                if (kind != 2) {
                    func_ov000_02163440(sl, 0x199, 0x258, 0x32);
                }
                if (sl[Enum_ov025_021d8c30_28632]) {
                    func_0205ec20(&g_sePlayer, 0, 0);
                }
                SePlayer_Play(&g_sePlayer, 0x44, 0);
                var24 = 1;
                sfx = -1;
                if (!slotObj->obj3D_.SetAnimationByName(data_ov025_021ef3d5, 9)) {
                    slotObj->obj3D_.SetAnimationByName(data_ov025_021ef3e0, 9);
                }
                var10 = 0;
                if (!IsPartyMember(var60)) {
                    GameObject* f = func_0200fea4(battle, var60);
                    if (f && f->obj3D_.unknown_2_ == 0xf4) {
                        animObj = slotObj;
                        var15 = 1;
                        var16 = 0x1a;
                        flags |= 3;
                    }
                } else {
                    animObj = slotObj;
                    var15 = 1;
                    var16 = 0x22;
                }
                if ((row->codes[slot] == 8 || row->codes[slot] == 7 || row->codes[slot] == 6) && kind != 2) continue;
                if (sl[Enum_ov025_021d8c30_30532] == var60) continue;
                func_ov025_021ed444((char*)(sl + Enum_ov025_021d8c30_2192), 0x1b8, var60, 0, 0, -1, 0);
                sl[Enum_ov025_021d8c30_30532] = var60;
            } else if (row->codes[i] == 1 || row->codes[i] == 2) {
                if (kind != 2) continue;
                var15 = 1;
                var16 = 0xe;
                animObj = slotObj;
                var26 = 0;
                if (row->codes[i] == 2) var26 = 1;
                if (var26) var16 = 0x20;
                void* list = func_02057924();
                struct Struct_02078398_2 req;
                func_02078484(&req);
                Vector3fix off;
                Vector3fix pos = slotObj->obj3D_.position_;
                off.x = 0;
                off.y = pos.y + (slotObj->obj3D_.GetHeight() >> 1);
                off.z = slotObj->obj3D_.GetRadius() >> 1;
                req.offset = off;
                req.objectId = slotObj->obj3D_.actorIndex_;
                func_02057fb4(list, var16, &req);
                int text;
                if (var26) {
                    text = IsPartyMember(var60) ? 0x28 : 0x29;
                } else {
                    text = IsPartyMember(var60) ? 0xa9 : 0xaa;
                }
                func_ov025_021ed444((char*)(sl + Enum_ov025_021d8c30_2192), text, var60, 0, 0, -1, 0);
            } else if (row->codes[i] == 8 || row->codes[i] == 7 || row->codes[i] == 6) {
                var21 = 1;
                if (row->codes[2] == 1 || row->codes[2] == 2) continue;
                var27 = 0;
                if (var14 && inline_ov000_02156cc4_2(var14->combatantId)) {
                    GameObject* var69 = func_0200ff1c(battle, var14->combatantId);
                    if (var69 && (func_02085078(*(unsigned char**)((unsigned char*)var69 + Enum_ov025_021d8c30_336)) ||
                                 func_020850a4(*(unsigned char**)((unsigned char*)var69 + Enum_ov025_021d8c30_336)))) {
                        if (entry && entry->unknown_17_4_ != 2) var27 = 1;
                    }
                }
                if (!var27) {
                    if (entry == 0) continue;
                    if (entry->unknown_17_4_ != 3 && entry->unknown_17_4_ != 4) continue;
                }
                if (sl[Enum_ov025_021d8c30_30533] == row->ids[i] && sl[Enum_ov025_021d8c30_30534] == row->ids[slot]) continue;
                int msgId = 0x7f;
                int var71 = 0;
                if (row->ids[slot] >= 0 && row->ids[slot] <= 3) var71 = 1;
                if (var71) msgId = 0x7e;
                idx = i - 1;
                func_ov025_021ed444((char*)(sl + Enum_ov025_021d8c30_2192), msgId, row->ids[slot], 0, 0, row->ids[i], 0);
                sl[Enum_ov025_021d8c30_30533] = row->ids[i];
                sl[Enum_ov025_021d8c30_30534] = row->ids[idx];
            } else if (row->codes[i] == 0xa) {
                if (sl[Enum_ov025_021d8c30_30532] == var60) continue;
                func_ov025_021ed444((char*)(sl + Enum_ov025_021d8c30_2192), 0x143, var60, 0, 0, -1, 0);
                sl[Enum_ov025_021d8c30_30532] = var60;
            } else if (row->codes[i] == 4 || row->codes[i] == 5) {
                if (sl[Enum_ov025_021d8c30_30532] == var60) continue;
                if (sl[Enum_ov025_021d8c30_28632]) {
                    func_0205ec20(&g_sePlayer, 0, 0);
                }
                SePlayer_Play(&g_sePlayer, 0x44, 0);
                func_ov025_021ed444((char*)(sl + Enum_ov025_021d8c30_2192), 0x142, var60, 0, 0, -1, 0);
                sl[Enum_ov025_021d8c30_30532] = var60;
                if (IsPartyMember(var60)) {
                    animObj = slotObj;
                    var15 = 1;
                    var16 = 0x23;
                } else {
                    GameObject* f = func_0200fea4(battle, var60);
                    if (f && (f->obj3D_.unknown_2_ == 0x3c || f->obj3D_.unknown_2_ == 0x3d)) {
                        slotObj->obj3D_.SetAnimationByName(data_ov025_021ef3e8, 0x19);
                    }
                    animObj = slotObj;
                    var15 = 1;
                    var16 = 0x23;
                }
            }
        }
    }

    if (kind == 2) {
        if (var16 == 0x22 || var16 == 0x1a || var16 == 0x21 || var16 == 0x23) {
            void* list = func_02057924();
            struct Struct_02078398_2 req;
            func_02078484(&req);
            Vector3fix off;
            off.x = 0;
            off.y = animObj->obj3D_.position_.y + (animObj->obj3D_.GetHeight() >> 1);
            off.z = animObj->obj3D_.GetRadius();
            req.objectId = animObj->obj3D_.actorIndex_;
            if (flags & 2) {
                off.z = 0;
                off.y = 0;
                off.x = 0;
            }
            if (var16 == 0x21 || var16 == 0x23) off.z = 0xb33;
            req.offset = off;
            func_02057fb4(list, var16, &req);
        }
        if (sb->unknown_22_) {
            func_ov025_021ed444((char*)(sl + Enum_ov025_021d8c30_2192), sb->unknown_22_, -1, 0, 0, -1, 0);
            sb->unknown_22_ = 0;
        }
        if (sb->unknown_24_) {
            if (var16 == 0xe) {
                if (row->unknown_1c_7_) {
                    short who = -1;
                    for (int j = 1; j < row->count; j++) {
                        if (row->codes[j] == 1) {
                            who = row->ids[j - 1];
                            break;
                        }
                    }
                    func_ov025_021ed380((char*)(sl + Enum_ov025_021d8c30_2192), sb->unknown_24_, -1, 0, 0, who, 0);
                }
            } else {
                func_ov025_021ed380((char*)(sl + Enum_ov025_021d8c30_2192), sb->unknown_24_, -1, 0, 0, -1, 0);
                sb->unknown_24_ = 0;
            }
        }
        return result;
    }

    if (target->show) {
        if (!var7) {
            var16 = 3;
            var18 = 1;
            int var78 = 0;
            if (!IsPartyMember(leadId)) {
                var78 = 1;
                var16 = 1;
            }
            if (row->codes[1] == 3 || row->codes[1] == 4 || row->codes[1] == 5) {
                int var79 = 0;
                if (row->ids[0] >= 0 && row->ids[0] <= 3) var79 = 1;
                if (!var79) {
                    var78 = 1;
                } else {
                    var78 = 0;
                    var16 = 3;
                    var18 = 1;
                }
            } else if (row->codes[2] == 3) {
                var78 = 0;
                var16 = 3;
                var18 = 1;
            }
            if (var78) {
                if (sb->type == 0xf4 || sb->type == 0xf5 || sb->type == 0x48 || sb->type == 0x70) {
                    var16 = 0x24;
                    var18 = 2;
                }
            }
        }
        var23 = 1;
    }

    if (func_ov000_0215fd90(target, 0xc)) {
        if (sb->type != 0x150) {
            var15 = 1;
            var16 = 0x19;
            flags |= 3;
            SePlayer_Play(&g_sePlayer, 0x3b, 0);
        }
    } else if (func_ov000_0215fd90(target, 9) || func_ov000_0215fd90(target, 0xa)) {
        if (func_ov000_0215fd90(target, 9)) {
            int total = 0;
            struct Struct_ov025_021d8c30_3* var81 = sb->rows;
            for (int n = 0; n < sb->unknown_9_; n++) {
                if (var81 == 0) break;
                for (int c = 0; c < 3; c++) {
                    struct Struct_ov025_021d8c30_2* cell = var81->cells[c];
                    if (cell == 0) continue;
                    for (int k = 0; k < var81->counts[c]; k++) {
                        if (cell == 0) break;
                        short v = cell->value;
                        cell = cell->next;
                        if (v > 0) total += v;
                    }
                }
                var81 = var81->next;
            }
            if (total == 0) {
                GameObject_Shake((struct ShortPair0xba0xbc*)actor, 0x800, 0x1f4);
            }
        }
        SePlayer_Play(&g_sePlayer, 0x3a, 0);
    } else if (func_ov000_0215fd90(target, 6)) {
        if (sb->type != 0x1df) {
            var15 = 1;
            var16 = 0x1c;
        }
        SePlayer_Play(&g_sePlayer, 0x39, 0);
        actor->obj3D_.SetAnimationByName(data_ov025_021ef3ef, 0x10);
        var10 = 0;
        var23 = 1;
    } else if (func_ov000_0215fd90(target, 4) || func_ov000_0215fd90(target, 5) || func_ov000_0215fd90(target, 0x26)) {
        if (!func_ov000_0215fd90(target, 0xd)) {
            if (IsPartyMember(id)) {
                SePlayer_Play(&g_sePlayer, 0x36, 0);
            } else {
                SePlayer_Play(&g_sePlayer, 0x37, 0);
            }
            if (func_ov000_0215fd90(target, 5)) {
                if (!var10) {
                    actor->obj3D_.SetAnimationByName(data_ov025_021ef3d0, 1);
                }
            } else {
                GameObject_Shake((struct ShortPair0xba0xbc*)actor, 0xcc, 0x12c);
            }
        }
    }

    if (func_ov000_0215fd90(target, 0x2b)) {
        actor->obj3D_.SetAnimationByName(data_ov025_021ef3f5, 1);
    }

    work = func_ov000_02160130();
    void* off = 0;
    void* hud = 0;
    if (work) off = func_ov000_02160f08(work);
    if (off) hud = func_ov025_021dafd0((char*)off, id);
    if (func_ov000_0215fd90(target, 0x2d) && hud) {
        *(unsigned int*)((unsigned char*)hud + 0x28) &= ~0x100;
        func_ov000_0217616c(hud);
    }
    if (func_ov000_0215fd90(target, 0x27)) {
        func_0204a00c((unsigned char*)actor, (int)target);
    }
    if ((target->unknown_18_ & 0x80000) && target->unknown_1d_ == 0xa) {
        func_0204a00c((unsigned char*)actor, (int)target);
    }
    if (func_ov000_0215fd90(target, 0x23) || func_ov000_0215fd90(target, 7)) {
        int popupId = 0;
        if (func_ov000_0215fd90(target, 7)) {
            popupId = 0x64;
        } else if (target->amount == 1) {
            popupId = 5;
        } else if (target->amount == 2) {
            popupId = 0x14;
        } else if (target->amount == 3) {
            popupId = 0x32;
        }
        Vector3fix pos = actor->obj3D_.position_;
        pos.y += actor->obj3D_.GetHeight();
        NumberPopups_Add(popups, popupId, (Vec3Int0203a48c*)&pos, 4, 0, 0);
    }

    if (func_ov000_0215fd90(target, 3)) {
        func_02049f28((unsigned char*)actor);
        actor->obj3D_.MakeVisible();
        actor->obj3D_.SetInheritedAlpha(0x1f);
        if (actor->obj3D_.unknown_0_ & 0x100) {
            *(unsigned int*)((unsigned char*)actor + Enum_ov025_021d8c30_396) &= ~1;
        } else {
            unsigned char* found = 0;
            for (int j = 0; j < 4; j++) {
                unsigned char* e = ((unsigned char**)(sl + Enum_ov025_021d8c30_3768))[j];
                if (e && *(short*)(e + 2) == actor->obj3D_.unknown_2_) {
                    found = e;
                    break;
                }
            }
            if (found) {
                if (actor->obj3D_.pModel_ == 0) {
                    func_02048588(found, (unsigned char*)actor);
                }
                func_ov000_02166784((struct Struct_ov000_02161c0c_3*)sl, found, (unsigned char*)actor);
                func_ov000_021677fc(sl);
            }
        }
        GameObject_ForceMotionState((struct Bytes02033b88*)actor, 0);
        actor->obj3D_.SkipAnimationTransition();
    } else if (func_ov000_0215fd90(target, 0xd)) {
        if (func_02049ee8((unsigned char*)actor)) {
            GameObject_ForceMotionState((struct Bytes02033b88*)actor, 4);
        }
        func_020d7334((unsigned char*)var5, id);
        func_02049f3c((unsigned char*)actor);
        func_ov000_02167434(sl, actor->obj3D_.GetTexturePaletteOffset());
        func_ov017_02191aac(ov17, 0, id, 2);
        func_ov017_02191aac(ov17, 0, id, 4);
        if (!var7 && kind != 0) {
            LightingManager::GetInstance()->BeginFade(0x800, 0x12c);
            func_ov000_02163440(sl, 0x199, 0x258, 0x96);
            var15 = 1;
            var16 = 0x1b;
            flags |= 1;
            SePlayer_Play(&g_sePlayer, 0x42, 0);
        }
        cleared = 1;
    } else if (func_ov000_0215fd90(target, 0x24)) {
        actor->obj3D_.SetAnimationByName(data_ov025_021ef3fc, 0);
        actor->obj3D_.TransitionInheritedAlpha(0, 0x1f4);
        func_ov000_02167434(sl, actor->obj3D_.GetTexturePaletteOffset());
        SePlayer_Play(&g_sePlayer, 9, 0);
    }

    if (var23) {
        if (!var21 && (*(int*)(sl + Enum_ov025_021d8c30_3752) != 8 || *(int*)(sl + Enum_ov025_021d8c30_1232) == 0) &&
            (sb->type == 1 || sb->type == 2)) {
            LightingManager::GetInstance()->BeginFade(0x800, 0x12c);
            Vector3fix pos = *(Vector3fix*)(sl + Enum_ov025_021d8c30_3208);
            pos.z = FIX32_MULTIPLY(pos.z, 0xe66);
            func_ov000_0216f1e4(sl + CameraBase, &pos.x, 0xccc, 0);
            Camera_Shake(sl + CameraBase, 0xcc, 0x3e8);
        }
        if (!((unsigned char*)battle->GetCamera() == sl + CameraBase && sl[ModeByte] == 2) &&
            *(int*)(sl + Enum_ov025_021d8c30_1232) == 0) {
            func_ov000_02163440(sl, 0x199, 0x2bc, 0x96);
        }
    }

    if ((unsigned int)var45 <= 2 && sb->unknown_22_) {
        func_ov025_021ed444((char*)(sl + Enum_ov025_021d8c30_2192), sb->unknown_22_, -1, 0, 0, -1, 0);
        sb->unknown_22_ = 0;
    }
    if (func_ov000_0215fd90(target, 8)) {
        func_ov017_02191aac(ov17, 0, actor->obj3D_.actorIndex_, 4);
        if (!var9) var22 = 1;
    }
    if (func_ov000_0215fd90(target, 0x2c)) {
        func_ov017_02191aac(ov17, 1, actor->obj3D_.actorIndex_, 2);
    }
    if (func_ov000_0215fd90(target, 0x28)) {
        func_ov017_02191aac(ov17, 0, actor->obj3D_.actorIndex_, 2);
    }

    var52 = 0;
    if ((sb->type == 1 || sb->type == 2 || sb->type == 0xdb) && func_ov000_0215fd90(target, 0x2a)) {
        var52 = 1;
    }

    if (func_ov000_0215fd90(target, 1) && !func_ov000_0215fd90(target, 0x29)) {
        amount = target->amount;
        if (func_ov000_0215fd90(target, 2)) {
            GameObject_ForceMotionState((struct Bytes02033b88*)actor, 4);
            func_020d7334((unsigned char*)var5, id);
            func_02049f3c((unsigned char*)actor);
            func_ov000_02167434(sl, actor->obj3D_.GetTexturePaletteOffset());
            func_ov017_02191aac(ov17, 0, id, 2);
            func_ov017_02191aac(ov17, 0, id, 4);
            cleared = 1;
        } else {
            GameState* gs = GameState::GetInstance();
            if (actor->obj3D_.unknown_0_ & 0x400) {
                GameObject* f = func_0200fea4(gs, actor->obj3D_.actorIndex_);
                unsigned char* info;
                if (f && (info = *(unsigned char**)((unsigned char*)f + 0x144)) != 0) {
                    short k = *(short*)(info + 8);
                    if (k == 0x2d || k == 0x2e || k == 0x2f || k == 0x11b) goto skipFlash;
                }
            }
            if (actor->obj3D_.unknown_0_ & 0x100) {
                func_02054028(actor, 0x64);
            } else {
                actor->obj3D_.SetNoTextureTimer(2);
            }
        skipFlash:
            if (((struct Struct_ov025_021d8c30_7*)((unsigned char*)actor + 0xc1))->hi != 1 && !var10 &&
                func_02049ee8((unsigned char*)actor)) {
                actor->obj3D_.SetAnimationByName(data_ov025_021ef3f5, 9);
            }
        }

        var30 = 0;
        var32 = 0;
        var33 = var30;
        party = IsPartyMember(id);
        if (!party) {
            GameObject* f = func_0200fea4(battle, id);
            struct Struct_ov025_021d8c30_6* m;
            if (f && (m = *(struct Struct_ov025_021d8c30_6**)((unsigned char*)f + 0x148)) != 0) {
                var32 = m->unknown_27_4_;
                var33 = m->unknown_13_7_;
            }
            if (var32) {
                if (cleared) {
                    sfx = 0x25;
                    GameResources* res = battle->GetResources();
                    if (res) {
                        SetMainBrightness(res, 0x10, 0);
                        SetMainBrightness(res, 0, 0x1e);
                        func_ov000_02163440(sl, 0x199, 0x3e8, 0x96);
                    }
                } else if (sfx >= 0) {
                    sfx = 0x24;
                }
            }
        }
        if (sfx >= 0) {
            if (sfx != 0x25) {
                if (var22) {
                    if (party) {
                        sfx = 0x27;
                    } else {
                        sfx = 0x26;
                    }
                } else if (party) {
                    if (sfx < 0x3c || sfx > 0x41) sfx = 0x1f;
                } else if (var33 && !var32) {
                    if (sfx < 0x3c || sfx > 0x41) sfx = 0x20;
                }
                if (target->show) {
                    if (row && (row->codes[1] == 3 || row->codes[1] == 4 || row->codes[1] == 5)) {
                        int var102 = 0;
                        if (row->ids[0] >= 0 && row->ids[0] <= 3) var102 = 1;
                        if (!var102 && var16 == 1) sfx = 0x1f;
                    }
                    if (var18 == 1) {
                        sfx = 0x26;
                    } else if (var18 == 2) {
                        sfx = 0x27;
                    }
                }
            }
            if (!var24) {
                if (!var52) {
                    SePlayer_Play(&g_sePlayer, sfx, 0);
                }
                var30 = 1;
            }
        }
        if (!var30 && (var18 == 1 || var18 == 2)) {
            int se = 0x26;
            if (var18 == 2) se = 0x27;
            SePlayer_Play(&g_sePlayer, se, 0);
        } else if (*(short*)(sl + Field4ca) >= 0 && !var19) {
            SePlayer_PlayExtra(&g_sePlayer, *(short*)(sl + Field4ca), 0);
        }
        if (msg->duration) {
            if (!var52) {
                Camera_Shake(camera, msg->strength, msg->duration);
            }
        } else if (target->show) {
            Camera_Shake(camera, 0x333, 0x1f4);
        }
        Vector3fix pos = actor->obj3D_.position_;
        pos.y += actor->obj3D_.GetHeight();
        int big = 0;
        if (func_ov000_0215fd90(target, 0x2a)) big = 1;
        NumberPopups_Add(popups, amount, (Vec3Int0203a48c*)&pos, big, PopupDelay(inner), PopupColor(inner));
        if (!sb->queued && sl[Enum_ov025_021d8c30_28238] != 4) {
            func_ov000_021823dc(sl + Enum_ov025_021d8c30_28668, sb->group);
            sb->queued = 1;
        }
        var15 = 1;
    }

    if (func_ov000_0215fd90(target, 0x25) || func_ov000_0215fd90(target, 0x22)) {
        int style = 2;
        if (func_ov000_0215fd90(target, 0x22)) style = 3;
        negAmount = -target->amount;
        Vector3fix pos = actor->obj3D_.position_;
        if (kind == 0) {
            SePlayer_Play(&g_sePlayer, 0x65, 0);
        }
        pos.y += actor->obj3D_.GetHeight();
        NumberPopups_Add(popups, negAmount, (Vec3Int0203a48c*)&pos, style, 0, 0);
    }

    if (var15 && var13 && var16 > 0) {
        if (target->mask == 1 && kind == 2 && actor == var13) flags |= 1;
        list = func_02057924();
        struct Struct_02078398_2 req;
        func_02078484(&req);
        if (kind == 3) {
            for (int j = 1; j < row->count; j++) {
                if (row->codes[j] == 3) var13 = battle->GetCombatantByIndex(row->ids[j - 1]);
            }
        }
        Vector3fix out;
        Vector3fix dir;
        Vector3fix var112 = var13->obj3D_.position_;
        Vector3fix var113 = animObj->obj3D_.position_;
        facing = animObj->obj3D_.rotation_.y;
        int var114;
        if (sl[ModeByte] == 1 || sl[ModeByte] == 2) {
            var114 = 1;
        } else {
            var114 = 0;
        }
        var47 = var114 | !var13->obj3D_.IsVisible();
        var38 = animObj->obj3D_.GetRadius() >> 1;
        int var115 = animObj->obj3D_.GetHeight();
        var39 = var13->obj3D_.GetHeight();
        var40 = var13->obj3D_.GetRadius() >> 1;
        int dist = Vector3fix_Distance(&var112, &var113);
        if (var47) {
            fix32_t c = fix32cos(facing);
            fix32_t s = fix32sin(facing);
            Matrix3x3 rot;
            Mat3x3_WriteRotationY(&rot, s, c);
            dir.x = 0;
            dir.y = 0;
            dir.z = 0x1000;
            Mat3x3_ApplyToVector(&dir, &rot, &dir);
            Vector3fixMultiplyScalar(&dir, var38, &dir);
            Vector3fix base = animObj->obj3D_.position_;
            Vector3fix_Add(&base, &dir, &out);
        } else {
            int var121 = 0;
            var112.y = 0;
            var113.y = 0;
            if (IsPartyMember(leadId)) {
                if (dist < var38) var121 = 1;
            }
            if (!var121) {
                Vector3fix_Subtract(&var112, &var113, &dir);
                Vector3fix_Normalize(&dir, &dir);
                Vector3fixMultiplyScalar(&dir, var38, &dir);
                Vector3fix base = animObj->obj3D_.position_;
                Vector3fix_Add(&base, &dir, &out);
            } else {
                Vector3fix_Subtract(&var113, &var112, &dir);
                Vector3fix_Normalize(&dir, &dir);
                Vector3fixMultiplyScalar(&dir, var40 + 0x4cc, &dir);
                Vector3fix base = var13->obj3D_.position_;
                Vector3fix_Add(&base, &dir, &out);
            }
        }

        special = 0;
        if (IsPartyMember(id)) {
            int h = inline_ov025_021d8c30_3(var115, 0x999);
            out.y += h;
        } else if (*((unsigned char*)work + Enum_ov025_021d8c30_28648) == 0) {
            if (var16 == 0x1c) {
                int h = inline_ov025_021d8c30_3(var115, 0x999);
                out.y += h;
            } else {
                out.y += (var39 + var115) >> 2;
                if (func_ov000_02163c0c(sl, id)) {
                    special = 1;
                    out.y += 0x800;
                }
            }
        } else {
            Vector3fix var126 = inline_ov025_021d8c30_4(work);
            out.x += var126.x;
            out.y = var126.y;
            out.z += var126.z;
            Vector3fix zero;
            __clear(&zero, sizeof(zero));
            *(Vector3fix*)(sl + Enum_ov025_021d8c30_28636) = zero;
            sl[Enum_ov025_021d8c30_28648] = 0;
        }
        if (0.8f * var39 < out.y && !special) {
            out.y = 0.8f * var39;
        }
        if (flags & 1) {
            out.x = 0;
            out.z = animObj->obj3D_.GetRadius() >> 1;
            req.objectId = animObj->obj3D_.actorIndex_;
        } else {
            req.rotation = animObj->obj3D_.rotation_;
            req.scale = var13->obj3D_.GetScale();
        }
        if (flags & 2) {
            out.z = 0;
            out.y = 0;
            out.x = 0;
        }
        req.offset = out;
        func_02057fb4(list, var16, &req);
    }

    if (IsPartyMember(id)) {
        unsigned char* e = (unsigned char*)func_ov025_021dafd0((char*)(sl + Enum_ov025_021d8c30_14176), id);
        if (e) {
            if (category != 1 || kind == 0) {
                if (sb->type != 0x3af && sb->type != 0x39a && sb->type != 0x3a0) {
                    short v = target->unknown_e_;
                    func_ov000_02176134((struct Struct_ov000_02176134*)e, v);
                    *(short*)(e + 0xc) = v;
                }
            }
            if (row && (row->codes[1] == 8 || row->codes[1] == 7 || row->codes[1] == 6)) {
                if (target && (func_ov000_0215fd90(target, 0x22) || func_ov000_0215fd90(target, 0x2a))) {
                    short v = target->unknown_10_;
                    func_ov000_02176150((struct Obj02176150*)e, v);
                    *(short*)(e + 0xe) = v;
                }
            } else {
                short v = target->unknown_10_;
                func_ov000_02176150((struct Obj02176150*)e, v);
                *(short*)(e + 0xe) = v;
            }
            *(short*)(e + 8) = target->unknown_12_;
            *(short*)(e + 0xa) = target->unknown_14_;
            *(unsigned int*)(e + 0x28) = target->unknown_18_;
            func_ov000_0217616c(e);
            func_ov000_0216ff20((char*)e, target->unknown_1d_);
            e[0x2f] = target->unknown_1e_;
        }
    }

    if ((*(signed char**)(sl + Field2a0))[0x2a] == GameState_GetProtagonistIndex(battle) && IsPartyMember(id) &&
        func_0200ff1c(battle, id)) {
        func_ov017_021c9d2c(id, target->unknown_e_, target->unknown_12_, target->unknown_10_, target->unknown_14_, target->unknown_18_, 0, 0, 0);
    }

    *(unsigned int*)(sl + Enum_ov025_021d8c30_1132) |= 0x10;
    if (var10 && !cleared) {
        actor->obj3D_.SetAnimationByName(data_ov025_021ef3d0, 1);
        actor->obj3D_.SetCurrentAnimationTime(var11);
    }
    if (cleared) {
        ((struct Struct_ov025_021d8c30_7*)((unsigned char*)actor + 0xc1))->hi = 0;
    }
end:
    return result;
}
