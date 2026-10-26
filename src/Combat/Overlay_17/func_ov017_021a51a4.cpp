#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "Input/Input.h"


#if defined(jpn)
enum { Enum_ov017_021a51a4_14032 = 0x34c0, Enum_ov017_021a51a4_14036 = 0x34c4, Enum_ov017_021a51a4_14076 = 0x34ec, Enum_ov017_021a51a4_14080 = 0x34f0, Enum_ov017_021a51a4_14108 = 0x350c, Enum_ov017_021a51a4_14112 = 0x3510, Enum_ov017_021a51a4_15180 = 0x392c, Enum_ov017_021a51a4_15184 = 0x3930, Enum_ov017_021a51a4_15216 = 0x3950, Enum_ov017_021a51a4_15220 = 0x3954, Enum_ov017_021a51a4_16832 = 0x3fa0, Enum_ov017_021a51a4_16836 = 0x3fa4, Enum_ov017_021a51a4_17124 = 0x40c4, Enum_ov017_021a51a4_396 = 0x180 };
#else
enum { Enum_ov017_021a51a4_14032 = 0x36d0, Enum_ov017_021a51a4_14036 = 0x36d4, Enum_ov017_021a51a4_14076 = 0x36fc, Enum_ov017_021a51a4_14080 = 0x3700, Enum_ov017_021a51a4_14108 = 0x371c, Enum_ov017_021a51a4_14112 = 0x3720, Enum_ov017_021a51a4_15180 = 0x3b4c, Enum_ov017_021a51a4_15184 = 0x3b50, Enum_ov017_021a51a4_15216 = 0x3b70, Enum_ov017_021a51a4_15220 = 0x3b74, Enum_ov017_021a51a4_16832 = 0x41c0, Enum_ov017_021a51a4_16836 = 0x41c4, Enum_ov017_021a51a4_17124 = 0x42e4, Enum_ov017_021a51a4_396 = 0x18c };
#endif

struct SearchStruct;
struct FlagWord02046708;
struct BitField0203402c;
struct Struct0200fb08;
struct Obj021befe4;
struct SePlayer;
struct Obj020397cc;
struct S021b2ba0;
struct TailList020469b4;
struct TailNode020469b4;
struct SetFlagStruct;
struct FlagBlob02027bac;
struct SafeAllocator;

int MessageSystem_GetInstance();
extern "C" SearchStruct* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
FlagWord02046708* GlobalFlags_GetInstance();
unsigned char* GameState_GetZoneTransition(GameState* gs);
int FieldTaskQueue_IsEmpty(void** list);
int GameObject_IsControlEnabled(void* obj);
int GameObject_IsGesturing(signed char* obj);
int FlagWord_TestBits(FlagWord02046708* flags, unsigned int mask);
int GameObject_IsSinking(BitField0203402c* obj);
extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* reg);
int GameState_GetLanguage(Struct0200fb08* obj);
extern "C" int LinkSession_IsHostOrSolo(SearchStruct* search);
extern "C" int LinkSession_IsGuest(SearchStruct* search);
void InitState53_021befe4(Obj021befe4* obj);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void GameObject_DisableControl(Obj020397cc* obj, int flag);
void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_ov017_021a5568(void* node);
int GameObject_IsClimbingLadder(char* obj);
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int handler, int overlayId);
void SetCombatModeFromCase020dc2d0(int mode);
void MapDisplay_SetHoldSubScreenDark(SetFlagStruct* obj, int value);
void SetFlagsAt0xa97(FlagBlob02027bac* obj, unsigned char value);
void AllocateAndCopyBuf28_0216ae2c(SafeAllocator* allocator, void* arg);
extern char g_sePlayer;
extern char data_ov017_021d76dc;

struct Struct_ov017_021d6a80 {
    short unknown_0_[5];
};

extern Struct_ov017_021d6a80 data_ov017_021d6a80;

struct Struct_ov017_021a51a4 {
    char unknown_0_[0xac];
    short unknown_ac_;
    char unknown_ae_[0xb2 - 0xae];
    short unknown_b2_;
    char unknown_b4_[Enum_ov017_021a51a4_396 - 0xb4];
    int unknown_18c_;
};

struct Struct_ov017_021a51a4_2 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    char unknown_25_[0x28 - 0x25];
    int unknown_28_;
    int unknown_2c_;
};

struct Struct_ov017_021a51a4_3 {
    char unknown_0_[0xc];
    unsigned char unknown_c_0_ : 4;
};

struct Struct_ov017_021a51a4_4 {
    char unknown_0_[Enum_ov017_021a51a4_14032];
    Struct_020213fc* unknown_36d0_;
    char unknown_36d4_[Enum_ov017_021a51a4_14076 - Enum_ov017_021a51a4_14036];
    Struct_0201bdac_2* unknown_36fc_;
    char unknown_3700_[Enum_ov017_021a51a4_14108 - Enum_ov017_021a51a4_14080];
    Struct_ov017_021a51a4_2* unknown_371c_;
    char unknown_3720_[Enum_ov017_021a51a4_15180 - Enum_ov017_021a51a4_14112];
    unsigned char* unknown_3b4c_;
    char unknown_3b50_[Enum_ov017_021a51a4_15216 - Enum_ov017_021a51a4_15184];
    Struct_ov017_021befe4* unknown_3b70_;
    char unknown_3b74_[Enum_ov017_021a51a4_16832 - Enum_ov017_021a51a4_15220];
    int unknown_41c0_;
    char unknown_41c4_[Enum_ov017_021a51a4_17124 - Enum_ov017_021a51a4_16836];
    unsigned char unknown_42e4_;
};

// USA: func_ov017_021a51a4
extern "C" ARM void func_ov017_021a51a4(Res021a51a4* res) {
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
    if (var1->unknown_18c_ & 1) {
        return;
    }
    if (var1->unknown_ac_ > 0) {
        return;
    }
    if (var5[2] != 0) {
        return;
    }
    start = 0;
    if (!FlagWord_TestBits(flagWord, 0x800)) {
        if ((g_keyManager.TestKeysPressed(0x400) || res->pending == 1) && unknown->fac == 0) {
            if (!GameObject_IsSinking((BitField0203402c*)unknown)) {
                start = 1;
            }
        }
    } else {
        arg0->unknown_42e4_ = var6;
    }
    x = g_touchInput.pressX_;
    y = g_touchInput.pressY_;
    if (GXx_GetMasterBrightness_((volatile unsigned short*)0x400006c) != 0) {
        return;
    }
    var9 = (unsigned char*)var0->GetGrottoStruct();
#if !defined(jpn)
    Thresholds021d6a80 thresholds = data_ov017_021d6a80;
    level = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
#endif
    int var13;
    if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld &&
#if defined(jpn)
        0xb0 <= var7
#else
        var12.unknown_0_[var10 - 1] <= var7
#endif
         && var7 <= 0xf8 && var8 >= 0xa2 && var8 <= 0xb2) {
        var13 = 1;
    } else {
        var13 = 0;
    }
    if (LinkSession_IsHostOrSolo(search) && grotto[0] != 0 && grottoInfo->kind == 0
        && (g_keyManager.TestKeysPressed(0x800) || touched)) {
        InitState53_021befe4(res->state53);
        AppendNodeToTail(res->list, (TailNode020469b4*)res->state53);
        return;
    }
    if (start) {
        GameObject_DisableControl((Obj020397cc*)unknown, 1);
        unknown->fb2 = 0;
        res->pending = 0;
        SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
        func_ov017_021a5568(res->node);
        Node021a51a4* node = res->node;
        node->f24 = 0;
        node->f28 = 0;
        node->f2c = -1;
        AppendNodeToTail(res->list, (TailNode020469b4*)res->node);
        return;
    }
    if (grotto[0] != 0 && LinkSession_IsGuest(search) == 0 && grottoInfo->kind == 0) {
        return;
    }
    if (arg0->unknown_41c0_ != 0) {
        return;
    }
    if (!g_keyManager.TestKeysPressed(0x800)) {
        return;
    }
    if (arg0->unknown_42e4_ != 0 || var1->unknown_ac_ != 0) {
        return;
    }
    if (GameObject_IsSinking((BitField0203402c*)unknown)) {
        return;
    }
    if (GameObject_IsClimbingLadder((char*)unknown)) {
        return;
    }
    GameObject_DisableControl((Obj020397cc*)unknown, 1);
    unknown->fb2 = 0;
    dialog = res->dialog;
    InitObjState_021b2174(dialog);
    SetNameChecked_021b2ba0((S021b2ba0*)dialog, &data_ov017_021d76dc);
    SetFields30And34_021b2bd0(dialog, (int)AllocateAndCopyBuf28_0216ae2c, OVERLAY_ID(4));
    AppendNodeToTail(res->list, (TailNode020469b4*)dialog);
    SetCombatModeFromCase020dc2d0(3);
    MapDisplay_SetHoldSubScreenDark(res->flags, 1);
    SetFlagsAt0xa97((FlagBlob02027bac*)res->flags, 1);
}
