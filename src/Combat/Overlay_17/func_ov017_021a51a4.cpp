#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "Input/Input.h"


#if defined(jpn)
enum { Field36d0 = 0x34c0, Enum_ov017_021a51a4_14036 = 0x34c4, Enum_ov017_021a51a4_14076 = 0x34ec, Field3700 = 0x34f0, Enum_ov017_021a51a4_14108 = 0x350c, Enum_ov017_021a51a4_14112 = 0x3510, Enum_ov017_021a51a4_15180 = 0x392c, Enum_ov017_021a51a4_15184 = 0x3930, Enum_ov017_021a51a4_15216 = 0x3950, Enum_ov017_021a51a4_15220 = 0x3954, Enum_ov017_021a51a4_16832 = 0x3fa0, Enum_ov017_021a51a4_16836 = 0x3fa4, Enum_ov017_021a51a4_17124 = 0x40c4, Enum_ov017_021a51a4_396 = 0x180 };
#else
enum { Field36d0 = 0x36d0, Enum_ov017_021a51a4_14036 = 0x36d4, Enum_ov017_021a51a4_14076 = 0x36fc, Field3700 = 0x3700, Enum_ov017_021a51a4_14108 = 0x371c, Enum_ov017_021a51a4_14112 = 0x3720, Enum_ov017_021a51a4_15180 = 0x3b4c, Enum_ov017_021a51a4_15184 = 0x3b50, Enum_ov017_021a51a4_15216 = 0x3b70, Enum_ov017_021a51a4_15220 = 0x3b74, Enum_ov017_021a51a4_16832 = 0x41c0, Enum_ov017_021a51a4_16836 = 0x41c4, Enum_ov017_021a51a4_17124 = 0x42e4, Enum_ov017_021a51a4_396 = 0x18c };
#endif

struct SearchStruct;
struct FlagWord02046708;
struct BitField0203402c;
struct Struct0200fb08;
struct Struct_ov017_021befe4;
struct SePlayer;
struct Obj020397cc;
struct Struct_0206f81c_2;
struct TailList020469b4;
struct TailNode020469b4;
struct SetFlagStruct;
struct Struct_02027bac;
struct SafeAllocator;

extern "C" int MessageSystem_GetInstance();
extern "C" SearchStruct* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" FlagWord02046708* GlobalFlags_GetInstance();
extern "C" unsigned char* GameState_GetZoneTransition(GameState* gs);
extern "C" int FieldTaskQueue_IsEmpty(void** list);
extern "C" int GameObject_IsControlEnabled(void* obj);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int FlagWord_TestBits(FlagWord02046708* flags, unsigned int mask);
extern "C" int GameObject_IsSinking(BitField0203402c* obj);
extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* reg);
extern "C" int GameState_GetLanguage(Struct0200fb08* obj);
extern "C" int LinkSession_IsHostOrSolo(SearchStruct* search);
extern "C" int LinkSession_IsGuest(SearchStruct* search);
extern "C" void func_ov017_021befe4(Struct_ov017_021befe4* obj);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int flag);
extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_ov017_021a5568(void* node);
extern "C" int GameObject_IsClimbingLadder(char* obj);
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* name);
extern "C" void func_ov017_021b2bd0(void* obj, int handler, int arg2);
extern "C" void func_020dc2d0(int mode);
extern "C" void MapDisplay_SetHoldSubScreenDark(SetFlagStruct* obj, int value);
extern "C" void func_02027bac(Struct_02027bac* obj, unsigned char value);
extern "C" void func_ov004_0216ae2c(SafeAllocator* allocator, void* arg);
extern char g_sePlayer;
extern char data_ov017_021d76dc;

struct Struct_ov017_021d6a80 {
    short values[5];
};

extern Struct_ov017_021d6a80 data_ov017_021d6a80;

struct Unknown021a51a4 {
    char pad0[0xac];
    short unknown_ac_;
    char pad1[0xb2 - 0xae];
    short unknown_b2_;
    char pad2[Enum_ov017_021a51a4_396 - 0xb4];
    int unknown_18c_;
};

struct Struct_ov017_021a51a4_2 {
    char pad0[0x24];
    unsigned char f24;
    char pad1[0x28 - 0x25];
    int f28;
    int unknown_2c_;
};

struct Grotto021a51a4 {
    char pad0[0xc];
    unsigned char kind : 4;
};

struct Struct_ov017_021a51a4_4 {
    char pad0[Field36d0];
    SetFlagStruct* flags;
    char pad1[Enum_ov017_021a51a4_14076 - Enum_ov017_021a51a4_14036];
    TailList020469b4* list;
    char pad2[Enum_ov017_021a51a4_14108 - Field3700];
    Struct_ov017_021a51a4_2* node;
    char pad3[Enum_ov017_021a51a4_15180 - Enum_ov017_021a51a4_14112];
    unsigned char* dialog;
    char pad4[Enum_ov017_021a51a4_15216 - Enum_ov017_021a51a4_15184];
    Struct_ov017_021befe4* unknown_3b70_;
    char pad5[Enum_ov017_021a51a4_16832 - Enum_ov017_021a51a4_15220];
    int unknown_41c0_;
    char pad6[Enum_ov017_021a51a4_17124 - Enum_ov017_021a51a4_16836];
    unsigned char pending;
};

// USA: func_ov017_021a51a4
extern "C" ARM void func_ov017_021a51a4(Struct_ov017_021a51a4_4* res) {
    GameState* gs;
    Unknown021a51a4* unknown;
    unsigned char* dialog;
    SearchStruct* search;
    FlagWord02046708* flagWord;
    unsigned char* field3f8;
    int start;
    int x;
    int y;
    unsigned char* grotto;
    int level;
    Grotto021a51a4* grottoInfo;
    gs = GameState::GetInstance();
    unknown = (Unknown021a51a4*)gs->GetLeader();
    MessageSystem_GetInstance();
    search = LinkSession_GetInstance();
    grottoInfo = *(Grotto021a51a4**)((char*)Zone3D_GetInstance() + 8);
    flagWord = GlobalFlags_GetInstance();
    field3f8 = GameState_GetZoneTransition(gs);
    if (!FieldTaskQueue_IsEmpty((void**)res->list)) {
        return;
    }
    if (!GameObject_IsControlEnabled(unknown)) {
        return;
    }
    if (GameObject_IsGesturing((signed char*)unknown)) {
        return;
    }
    if (unknown->unknown_18c_ & 1) {
        return;
    }
    if (unknown->unknown_ac_ > 0) {
        return;
    }
    if (field3f8[2] != 0) {
        return;
    }
    start = 0;
    if (!FlagWord_TestBits(flagWord, 0x800)) {
        if ((g_keyManager.TestKeysPressed(0x400) || res->pending == 1) && unknown->unknown_ac_ == 0) {
            if (!GameObject_IsSinking((BitField0203402c*)unknown)) {
                start = 1;
            }
        }
    } else {
        res->pending = start;
    }
    x = g_touchInput.pressX_;
    y = g_touchInput.pressY_;
    if (GXx_GetMasterBrightness_((volatile unsigned short*)0x400006c) != 0) {
        return;
    }
    grotto = (unsigned char*)gs->GetGrottoStruct();
#if !defined(jpn)
    Struct_ov017_021d6a80 var12 = data_ov017_021d6a80;
    level = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
#endif
    int touched;
    if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld &&
#if defined(jpn)
        0xb0 <= x
#else
        var12.values[level - 1] <= x
#endif
         && x <= 0xf8 && y >= 0xa2 && y <= 0xb2) {
        touched = 1;
    } else {
        touched = 0;
    }
    if (LinkSession_IsHostOrSolo(search) && grotto[0] != 0 && grottoInfo->kind == 0
        && (g_keyManager.TestKeysPressed(0x800) || touched)) {
        func_ov017_021befe4(res->unknown_3b70_);
        func_020469b4(res->list, (TailNode020469b4*)res->unknown_3b70_);
        return;
    }
    if (start) {
        GameObject_DisableControl((Obj020397cc*)unknown, 1);
        unknown->unknown_b2_ = 0;
        res->pending = 0;
        SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
        func_ov017_021a5568(res->node);
        Struct_ov017_021a51a4_2* node = res->node;
        node->f24 = 0;
        node->f28 = 0;
        node->unknown_2c_ = -1;
        func_020469b4(res->list, (TailNode020469b4*)res->node);
        return;
    }
    if (grotto[0] != 0 && LinkSession_IsGuest(search) == 0 && grottoInfo->kind == 0) {
        return;
    }
    if (res->unknown_41c0_ != 0) {
        return;
    }
    if (!g_keyManager.TestKeysPressed(0x800)) {
        return;
    }
    if (res->pending != 0 || unknown->unknown_ac_ != 0) {
        return;
    }
    if (GameObject_IsSinking((BitField0203402c*)unknown)) {
        return;
    }
    if (GameObject_IsClimbingLadder((char*)unknown)) {
        return;
    }
    GameObject_DisableControl((Obj020397cc*)unknown, 1);
    unknown->unknown_b2_ = 0;
    dialog = res->dialog;
    func_ov017_021b2174(dialog);
    func_ov017_021b2ba0((Struct_0206f81c_2*)dialog, &data_ov017_021d76dc);
    func_ov017_021b2bd0(dialog, (int)func_ov004_0216ae2c, OVERLAY_ID(4));
    func_020469b4(res->list, (TailNode020469b4*)dialog);
    func_020dc2d0(3);
    MapDisplay_SetHoldSubScreenDark(res->flags, 1);
    func_02027bac((Struct_02027bac*)res->flags, 1);
}
