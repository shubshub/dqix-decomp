#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "GameState/BattleRecordSnapshot.h"
#include "Grotto/Main/TreasureMapMetadata.h"

struct Struct_ov003_02170d88_2 { char unknown_0_[11]; };
struct Struct_ov003_02170d88_5 { unsigned char unknown_0_[6]; };
struct Struct_ov003_02170d88_6 { short unknown_0_[14]; };
union Struct_ov003_02170d88_8 {
    struct {
        unsigned int unknown_0_;
        unsigned int unknown_4_0_ : 9;
        signed int unknown_5_1_ : 10;
        signed int unknown_6_3_ : 11;
        unsigned int unknown_7_6_ : 2;
        char unknown_8_[116];
    } unknown_0_;
    unsigned int unknown1_0_[31];
};
union Struct_ov003_02170d88_14 {
    struct {
        unsigned int unknown_0_0_ : 14;
        unsigned int unknown_1_6_ : 17;
        unsigned int unknown_3_7_ : 1;
        unsigned int unknown_4_0_ : 14;
        unsigned int unknown_5_6_ : 17;
        unsigned int unknown_7_7_ : 1;
        unsigned int unknown_8_0_ : 7;
        unsigned int unknown_8_7_ : 7;
        unsigned int unknown_9_6_ : 7;
        unsigned int unknown_a_5_ : 7;
        unsigned int unknown_b_4_ : 4;
        unsigned int unknown_c_0_ : 10;
        unsigned int unknown_d_2_ : 14;
        unsigned int unknown_f_0_ : 7;
        unsigned int unknown_f_7_ : 1;
        unsigned int unknown_10_0_ : 9;
        unsigned int unknown_11_1_ : 14;
        unsigned int unknown_12_7_ : 7;
        unsigned int unknown_13_6_ : 2;
        short unknown_14_;
        unsigned char unknown_16_0_ : 1;
        unsigned char unknown_16_1_ : 4;
        unsigned char unknown_16_5_ : 3;
        unsigned char unknown_17_;
    } unknown_0_;
    unsigned int unknown1_0_[6];
};
union Struct_ov003_02170d88 {
    TreasureMapMetadata unknown_0_;
    short unknown1_0_[14];
};

struct Struct_ov003_02170d88_3 {
    Struct_ov003_02170d88_2 unknown_0_;
    unsigned char unknown_b_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    Struct_ov003_02170d88_5 unknown_e_;
    Struct_ov003_02170d88_8 unknown_14_;
    Struct_ov003_02170d88_6 unknown_90_;
    Struct_ov003_02170d88_14 unknown_ac_;
    Struct_ov003_02170d88 unknown_c4_;
};
struct Struct_ov003_02170d88_4 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    unsigned int unknown_4_;
    unsigned char unknown_8_[50][8];
    unsigned char unknown_198_;
#if defined(jpn)
    char unknown_199_[0x19c - 0x199];
    Struct_ov003_02170d88_3 unknown_1c0_;
    char unknown_27c_[0x614 - 0x27c];
#else
    char unknown1_199_[0x1c0 - 0x199];
    Struct_ov003_02170d88_3 unknown_1c0_;
    char unknown_2a0_[0xe0];
    Struct_ov003_02170d88_3 unknown_380_;
    char unknown_460_[0x718 - 0x460];
#endif
    unsigned char unknown_718_;
    char unknown_719_[3];
    int unknown_71c_;
    int unknown_720_;
    int unknown_724_;
    int unknown_728_;
    int unknown_72c_;
    unsigned char unknown_730_;
    signed char unknown_731_;
    signed char unknown_732_;
    unsigned char unknown_733_;
    unsigned char unknown_734_;
    char unknown_735_[3];
    int unknown_738_;
};
struct Struct_ov003_02170d88_7 {
    char unknown_0_[0x16c];
    unsigned short unknown_16c_[13];
    unsigned char unknown_186_[13];
    char unknown_193_[0x49c - 0x193];
    unsigned char unknown_49c_0_ : 1;
    unsigned char unknown_49c_1_ : 7;
    char unknown_49d_[0x56a - 0x49d];
    unsigned char unknown_56a_;
#if defined(jpn)
    char unknown_56b_[0x8b8 - 0x56b];
#else
    char unknown1_56b_[0x950 - 0x56b];
#endif
    unsigned int unknown_950_;
};
struct Struct_ov003_02170d88_9 : GameObject {
#if defined(jpn)
    char unknown_13c_[0x144 - 0x13c];
#else
    char unknown1_13c_[0x150 - 0x13c];
#endif
    Struct_ov003_02170d88_7* unknown_150_;
};
struct Struct_ov003_02170d88_10 {
    char unknown_0_[0x3c];
    Struct_02061c04 unknown_3c_;
};
struct Struct_ov003_02170d88_11 {
#if defined(jpn)
    char unknown_0_[0x543c];
    Struct_ov003_02170d88_8 unknown_569c_;
    char unknown_54b8_[0x72be - 0x54b8];
#else
    char unknown1_0_[0x569c];
    Struct_ov003_02170d88_8 unknown_569c_;
    char unknown_5718_[0x74fe - 0x5718];
#endif
    Struct_ov003_02170d88_5 unknown_74fe_;
    Struct_ov003_02170d88_10 unknown_7504_;
};
struct Struct_ov003_02170d88_12 {
#if defined(jpn)
    char unknown_0_[0x41e4];
#else
    char unknown1_0_[0x4494];
#endif
    int unknown_4494_;
};
struct Field150Holder02052e2c;
struct Struct0200fb08;
struct KeyArrayObj_02171f80;
extern "C" void* LinkSession_GetInstance();
struct Obj_0202aec0;
extern "C" void LinkSession_Reset(Obj_0202aec0*);
void* LinkMessageQueue_GetInstance();
extern "C" void LinkMessageQueue_Reset(void*);
extern "C" void VectorizedMemset(void*, int, unsigned int);
void* ResetBuffer02052a10(char*);
short* GetField150Ptr0x488_02052e2c(Field150Holder02052e2c*);
int CopyOutBattleField0x7ac0_020ac0b4(void*);
int GameState_UpdatePlayClocks(int);
int GetFieldPercentOver307_020a0870(BattleRecordSnapshot*);
int GetFieldPercentOver232_020a08a4(BattleRecordSnapshot*);
int GetFieldPercentOver944_020a08d8(BattleRecordSnapshot*);
int GetFieldPercentOver448_020a090c(BattleRecordSnapshot*);
ProfileCharacterData02170d88* GetFieldAt0x150_02053c6c(unsigned char*);
unsigned char GameState_GetLanguage(Struct0200fb08*);
unsigned char CopyToRegion0x6482IfDst_020119f8(char*, void*);
void ClearUnmatchedKeys_02171f80(KeyArrayObj_02171f80*);
extern "C" void func_ov017_021b1d44(void*, int, int);
extern const char* data_ov003_021805e4[5];
extern const char* data_ov003_021805d0[5];

#if defined(jpn)
static inline Struct_ov003_02170d88_8* inline_ov003_02170d88(Struct_ov003_02170d88_11* arg0) { return &arg0->unknown_569c_; }
#endif

// USA: func_ov003_02170d88
// EUR: func_ov003_02170d88
extern "C" ARM void func_ov003_02170d88(ProfileState02170d88* self) {
    ProfileRecordRegion02170d88* region;
    self->state = 8;
    self->timer = 0;
    self->pending = 0;
    self->accepted = 0;
    self->result = 0;
    Obj_0202aec0* searchState = static_cast<Obj_0202aec0*>(LinkSession_GetInstance());
    LinkSession_Reset(searchState);
    void* searchData = LinkMessageQueue_GetInstance();
    LinkMessageQueue_Reset(searchData);
    GameState* state = GameState::GetInstance();
    GameObject* actorObject = state->GetProtagonist();
    ProfileActor02170d88* actor = static_cast<ProfileActor02170d88*>(actorObject);
#if defined(jpn)
    strcpy(arg0->unknown_1c0_.unknown_0_.unknown_0_, (const char*)var5->baseStats_);
#else
    strcpy(arg0->unknown_1c0_.unknown_0_.unknown_0_, (const char*)func_02052a10((char*)var5));
#endif
    arg0->unknown_1c0_.unknown_b_ = var5->unknown_150_->unknown_950_;
    arg0->unknown_1c0_.unknown_c_ = var5->unknown_150_->unknown_16c_[var5->unknown_150_->unknown_950_];
    Struct_ov003_02170d88_11* var6 = (Struct_ov003_02170d88_11*)var3;
    memcpy(&arg0->unknown_1c0_.unknown_14_, &var6->unknown_569c_, 0x7c);
    memcpy(&arg0->unknown_1c0_.unknown_90_, func_02052e2c((Struct_02052e2c*)var5), 0x1c);
    VectorizedMemset(&arg0->unknown_1c0_.unknown_ac_, 0, 0x18);
    Struct_ov003_02170d88_14* var7 = &arg0->unknown_1c0_.unknown_ac_;
    var0 = &var6->unknown_7504_;
    unsigned int var8 = 0;
    func_020ac0b4(&var8);
    unsigned int var9 = 0;
    unsigned int var10 = 0;
    GameObject* var11 = var3->GetProtagonist();
    Struct_ov003_02170d88_9* var12 = static_cast<Struct_ov003_02170d88_9*>(var11);
    if (var12 != 0) {
        unsigned int var13 = var12->unknown_150_->unknown_950_;
        var9 = var12->unknown_150_->unknown_49c_0_;
        var10 = var12->unknown_150_->unknown_186_[var13];
    }
    GameState_UpdatePlayClocks(0);
#if defined(jpn)
    Struct_ov003_02170d88_8* var14 = inline_ov003_02170d88(var6);
#else
    Struct_ov003_02170d88_8* var14 = &var6->unknown_569c_;
#endif
    VectorizedMemset(var7, 0, 0x18);
    var7->unknown_0_.unknown_0_0_ = var0->unknown_3c_.unknown_0_.unknown_0_.unknown_0_;
    var7->unknown_0_.unknown_8_0_ = var0->unknown_3c_.unknown_0_.unknown_0_.unknown_2_;
    var7->unknown_0_.unknown_4_0_ = var0->unknown_3c_.unknown_0_.unknown_4_.unknown_0_;
    var7->unknown_0_.unknown_8_7_ = var0->unknown_3c_.unknown_0_.unknown_4_.unknown_2_;
    var7->unknown_0_.unknown_5_6_ = var0->unknown_3c_.unknown_8_0_;
    var7->unknown_0_.unknown_1_6_ = var8;
    var7->unknown_0_.unknown_c_0_ = var0->unknown_3c_.unknown_10_0_;
    var7->unknown_0_.unknown_10_0_ = var0->unknown_3c_.unknown_b_0_;
    var7->unknown_0_.unknown_d_2_ = var0->unknown_3c_.unknown_d_6_;
    var7->unknown_0_.unknown_11_1_ = var0->unknown_3c_.unknown_11_1_;
    var7->unknown_0_.unknown_9_6_ = (unsigned char)func_020a0870(&var0->unknown_3c_);
    var7->unknown_0_.unknown_a_5_ = (unsigned char)func_020a08a4(&var0->unknown_3c_);
    var7->unknown_0_.unknown_f_0_ = (unsigned char)func_020a08d8(&var0->unknown_3c_);
    var7->unknown_0_.unknown_12_7_ = (unsigned char)func_020a090c(&var0->unknown_3c_);
    var7->unknown_0_.unknown_14_ = var14->unknown_0_.unknown_6_3_;
    var7->unknown_0_.unknown_16_0_ = (unsigned char)var9;
    var7->unknown_0_.unknown_16_1_ = (unsigned char)var10;
    var7->unknown_0_.unknown_17_ = func_02053c6c((unsigned char*)var12)->unknown_56a_;
#if !defined(jpn)
    var7->unknown_0_.unknown_3_7_ = 1;
#endif
    VectorizedMemset(&arg0->unknown_1c0_.unknown_c4_, 0, 0x1c);
    Struct_ov003_02170d88_5 var15 = var6->unknown_74fe_;
    arg0->unknown_1c0_.unknown_e_ = var15;
#if !defined(jpn)
    unsigned char platformLanguage = GameState_GetLanguage((Struct0200fb08*)state);
    int language = 0;
    switch (platformLanguage) {
    case 2: language = 1; break;
    case 3: language = 2; break;
    case 4: language = 3; break;
    case 5: language = 4; break;
    }
    arg0->unknown_380_.unknown_0_ = arg0->unknown_1c0_.unknown_0_;
    arg0->unknown_380_.unknown_b_ = arg0->unknown_1c0_.unknown_b_;
    arg0->unknown_380_.unknown_c_ = arg0->unknown_1c0_.unknown_c_;
    arg0->unknown_380_.unknown_d_ = arg0->unknown_1c0_.unknown_d_;
    arg0->unknown_380_.unknown_e_ = arg0->unknown_1c0_.unknown_e_;
    arg0->unknown_380_.unknown_14_.unknown1_0_ = arg0->unknown_1c0_.unknown_14_.unknown1_0_;
    arg0->unknown_380_.unknown_90_ = arg0->unknown_1c0_.unknown_90_;
    arg0->unknown_380_.unknown_ac_.unknown1_0_ = arg0->unknown_1c0_.unknown_ac_.unknown1_0_;
    arg0->unknown_380_.unknown_c4_.unknown1_0_ = arg0->unknown_1c0_.unknown_c4_.unknown1_0_;
    memset(arg0->unknown_380_.unknown_0_.unknown_0_, 0, 0xb);
    sprintf(arg0->unknown_380_.unknown_0_.unknown_0_, data_ov003_021805e4[var17]);
    memset(arg0->unknown_380_.unknown_14_.unknown_0_.unknown_8_, 0, 0x74);
    sprintf(arg0->unknown_380_.unknown_14_.unknown_0_.unknown_8_, data_ov003_021805d0[var17]);
    Struct_ov003_02170d88_14* var18 = &arg0->unknown_380_.unknown_ac_;
    if (var14->unknown_0_.unknown_5_1_ >= 310) {
#if defined(eur)
        arg0->unknown_380_.unknown_14_.unknown_0_.unknown_5_1_ = 201;
#else
        arg0->unknown_380_.unknown_14_.unknown_0_.unknown_5_1_ = 203;
#endif
    }
    short var19;
    int var20 = var14->unknown_0_.unknown_6_3_;
    var19 = var20;
    if (var20 >= 750 && var20 < 800) var19 -= 50;
    else if (var20 >= 900) var19 -= 100;
    arg0->unknown_380_.unknown_14_.unknown_0_.unknown_6_3_ = var19;
    var18->unknown_0_.unknown_14_ = var19;
    TreasureMapMetadata var21;
    func_020119f8((char*)var3, &var21);
    if (var21.GetMapType() != TreasureMapType_Invalid) {
        arg0->unknown_380_.unknown_d_ = 1;
        arg0->unknown_380_.unknown_c4_.unknown_0_.DiscoveryStateAndMapTypeAndUnknown = var21.DiscoveryStateAndMapTypeAndUnknown;
        INLINE_MEMCPY(arg0->unknown_380_.unknown_c4_.unknown_0_.DiscoveredBy, var21.DiscoveredBy, 10);
        INLINE_MEMCPY(arg0->unknown_380_.unknown_c4_.unknown_0_.ClearedBy, var21.ClearedBy, 10);
        arg0->unknown_380_.unknown_c4_.unknown_0_.Location = var21.Location;
        arg0->unknown_380_.unknown_c4_.unknown_0_.TreasureDiscoveryFlags = var21.TreasureDiscoveryFlags;
        arg0->unknown_380_.unknown_c4_.unknown_0_.QualityOrLegacyBossID = var21.QualityOrLegacyBossID;
        arg0->unknown_380_.unknown_c4_.unknown_0_.LegacyBossLevel = var21.LegacyBossLevel;
        arg0->unknown_380_.unknown_c4_.unknown_0_.SeedOrMinTurns = var21.SeedOrMinTurns;
        TreasureMapMetadata* var22 = &arg0->unknown_380_.unknown_c4_.unknown_0_;
        memset(var22->DiscoveredBy, 0, 10);
        memset(var22->ClearedBy, 0, 10);
        char var23[11] = {0};
        memset(var23, 0, 11);
        memcpy(var23, data_ov003_021805e4[var17], 11);
        memcpy(var22->DiscoveredBy, var23, 10);
        memset(var23, 0, 11);
        memcpy(var23, data_ov003_021805e4[var17], 11);
        memcpy(var22->ClearedBy, var23, 10);
    }
#endif
    ClearUnmatchedKeys_02171f80((KeyArrayObj_02171f80*)self);
    self->active = 0;
    self->unknown738 = 0;
    self->progress = 0;
    self->flags = 3;
    ((ProfileResourceState02170d88*)GetGameResources())->profileActive = 1;
    func_ov017_021b1d44(GetGameResources()->fieldTasks_[19], 0x20, 1);
}
