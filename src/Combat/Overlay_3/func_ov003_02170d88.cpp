#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "GameState/BattleRecordSnapshot.h"
#include "Grotto/Main/TreasureMapMetadata.h"

struct Struct_ov003_02170d88_2 { char text[11]; };
struct Struct_ov003_02170d88_5 { unsigned char bytes[6]; };
struct Struct_ov003_02170d88_6 { short values[14]; };
union Struct_ov003_02170d88_8 {
    struct {
        unsigned int flags;
        unsigned int unknown0 : 9;
        signed int unknown_5_1_ : 10;
        signed int unknown_6_3_ : 11;
        unsigned int unknown30 : 2;
        char message[116];
    } fields;
    unsigned int words[31];
};
union Struct_ov003_02170d88_14 {
    struct {
        unsigned int unknown_0_0_ : 14;
        unsigned int counter : 17;
        unsigned int captured : 1;
        unsigned int unknown_4_0_ : 14;
        unsigned int unknown_5_6_ : 17;
        unsigned int unknown_7_7_ : 1;
        unsigned int unknown_8_0_ : 7;
        unsigned int unknown_8_7_ : 7;
        unsigned int unknown_9_6_ : 7;
        unsigned int unknown_a_5_ : 7;
        unsigned int unknown28 : 4;
        unsigned int value0 : 10;
        unsigned int value10 : 14;
        unsigned int unknown_f_0_ : 7;
        unsigned int unknown3 : 1;
        unsigned int unknown_10_0_ : 9;
        unsigned int unknown_11_1_ : 14;
        unsigned int unknown_12_7_ : 7;
        unsigned int unknown4 : 2;
        short unknown_14_;
        unsigned char flag : 1;
        unsigned char unknown_16_1_ : 4;
        unsigned char unknown16 : 3;
        unsigned char unknown_17_;
    } fields;
    unsigned int words[6];
};
union Struct_ov003_02170d88 {
    TreasureMapMetadata unknown_0_;
    short values[14];
};

struct Struct_ov003_02170d88_3 {
    Struct_ov003_02170d88_2 name;
    unsigned char vocation;
    unsigned char level;
    unsigned char unknown_d_;
    Struct_ov003_02170d88_5 code;
    Struct_ov003_02170d88_8 settings;
    Struct_ov003_02170d88_6 effects;
    Struct_ov003_02170d88_14 record;
    Struct_ov003_02170d88 map;
};
struct Struct_ov003_02170d88_4 {
    unsigned char state;
    char unknown_1_[3];
    unsigned int timer;
    unsigned char keys[50][8];
    unsigned char keyCount;
#if defined(jpn)
    char unknown_199_[0x19c - 0x199];
    Struct_ov003_02170d88_3 current;
    char unknown_27c_[0x614 - 0x27c];
#else
    char unknown1_199_[0x1c0 - 0x199];
    Struct_ov003_02170d88_3 current;
    char unknown_2a0_[0xe0];
    Struct_ov003_02170d88_3 sample;
    char unknown_460_[0x718 - 0x460];
#endif
    unsigned char active;
    char unknown_719_[3];
    int pending;
    int unknown_720_;
    int result;
    int unknown_728_;
    int progress;
    unsigned char flags;
    signed char unknown_731_;
    signed char unknown_732_;
    unsigned char unknown_733_;
    unsigned char unknown_734_;
    char unknown_735_[3];
    int unknown_738_;
};
struct Struct_ov003_02170d88_7 {
    char unknown0[0x16c];
    unsigned short unknown_16c_[13];
    unsigned char unknown_186_[13];
    char unknown_193_[0x49c - 0x193];
    unsigned char flag : 1;
    unsigned char unknown_49c_1_ : 7;
    char unknown_49d_[0x56a - 0x49d];
    unsigned char unknown_56a_;
#if defined(jpn)
    char unknown_56b_[0x8b8 - 0x56b];
#else
    char unknown1_56b_[0x950 - 0x56b];
#endif
    unsigned int vocation;
};
struct Struct_ov003_02170d88_9 : GameObject {
#if defined(jpn)
    char unknown_13c_[0x144 - 0x13c];
#else
    char unknown1_13c_[0x150 - 0x13c];
#endif
    Struct_ov003_02170d88_7* data;
};
struct Struct_ov003_02170d88_10 {
    char unknown0[0x3c];
    Struct_02061c04 record;
};
struct Struct_ov003_02170d88_11 {
#if defined(jpn)
    char unknown0[0x543c];
    Struct_ov003_02170d88_8 settings;
    char unknown_54b8_[0x72be - 0x54b8];
#else
    char unknown0[0x569c];
    Struct_ov003_02170d88_8 settings;
    char unknown_5718_[0x74fe - 0x5718];
#endif
    Struct_ov003_02170d88_5 code;
    Struct_ov003_02170d88_10 region;
};
struct Struct_ov003_02170d88_12 {
#if defined(jpn)
    char unknown0[0x41e4];
#else
    char unknown0[0x4494];
#endif
    int unknown_4494_;
};
struct Field150Holder02052e2c;
struct Struct0200fb08;
struct Struct_ov003_02170d88_13;
extern "C" void* LinkSession_GetInstance();
struct Obj_0202aec0;
extern "C" void LinkSession_Reset(Obj_0202aec0*);
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void LinkMessageQueue_Reset(void*);
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" void* func_02052a10(char*);
extern "C" short* func_02052e2c(Field150Holder02052e2c*);
extern "C" int func_020ac0b4(void*);
extern "C" int GameState_UpdatePlayClocks(int);
extern "C" int func_020a0870(Struct_02061c04*);
extern "C" int func_020a08a4(Struct_02061c04*);
extern "C" int func_020a08d8(Struct_02061c04*);
extern "C" int func_020a090c(Struct_02061c04*);
extern "C" Struct_ov003_02170d88_7* func_02053c6c(unsigned char*);
extern "C" unsigned char GameState_GetLanguage(Struct0200fb08*);
extern "C" unsigned char func_020119f8(char*, void*);
extern "C" void func_ov003_02171f80(Struct_ov003_02170d88_13*);
extern "C" void func_ov017_021b1d44(void*, int, int);
extern const char* data_ov003_021805e4[5];
extern const char* data_ov003_021805d0[5];

#if defined(jpn)
static inline Struct_ov003_02170d88_8* inline_ov003_02170d88(Struct_ov003_02170d88_11* saved) { return &saved->settings; }
#endif

// USA: func_ov003_02170d88
// EUR: func_ov003_02170d88
extern "C" ARM void func_ov003_02170d88(Struct_ov003_02170d88_4* self) {
    Struct_ov003_02170d88_10* region;
    self->state = 8;
    self->timer = 0;
    self->pending = 0;
    self->unknown_720_ = 0;
    self->result = 0;
    Obj_0202aec0* searchState = static_cast<Obj_0202aec0*>(LinkSession_GetInstance());
    LinkSession_Reset(searchState);
    void* searchData = LinkMessageQueue_GetInstance();
    LinkMessageQueue_Reset(searchData);
    GameState* state = GameState::GetInstance();
    GameObject* var4 = state->GetProtagonist();
    Struct_ov003_02170d88_9* actor = static_cast<Struct_ov003_02170d88_9*>(var4);
#if defined(jpn)
    strcpy(self->current.name.text, (const char*)actor->baseStats_);
#else
    strcpy(self->current.name.text, (const char*)func_02052a10((char*)actor));
#endif
    self->current.vocation = actor->data->vocation;
    self->current.level = actor->data->unknown_16c_[actor->data->vocation];
    Struct_ov003_02170d88_11* saved = (Struct_ov003_02170d88_11*)state;
    memcpy(&self->current.settings, &saved->settings, 0x7c);
    memcpy(&self->current.effects, func_02052e2c((Field150Holder02052e2c*)actor), 0x1c);
    VectorizedMemset(&self->current.record, 0, 0x18);
    Struct_ov003_02170d88_14* output = &self->current.record;
    region = &saved->region;
    unsigned int counter = 0;
    func_020ac0b4(&counter);
    unsigned int flag = 0;
    unsigned int var10 = 0;
    GameObject* var11 = state->GetProtagonist();
    Struct_ov003_02170d88_9* protagonist = static_cast<Struct_ov003_02170d88_9*>(var11);
    if (protagonist != 0) {
        unsigned int vocation = protagonist->data->vocation;
        flag = protagonist->data->flag;
        var10 = protagonist->data->unknown_186_[vocation];
    }
    GameState_UpdatePlayClocks(0);
#if defined(jpn)
    Struct_ov003_02170d88_8* settings = inline_ov003_02170d88(saved);
#else
    Struct_ov003_02170d88_8* settings = &saved->settings;
#endif
    VectorizedMemset(output, 0, 0x18);
    output->fields.unknown_0_0_ = region->record.unknown_0_.elapsed.hours;
    output->fields.unknown_8_0_ = region->record.unknown_0_.elapsed.minutes;
    output->fields.unknown_4_0_ = region->record.unknown_0_.unknown_4_.hours;
    output->fields.unknown_8_7_ = region->record.unknown_0_.unknown_4_.minutes;
    output->fields.unknown_5_6_ = region->record.unknown_8_0_;
    output->fields.counter = counter;
    output->fields.value0 = region->record.unknown_10_0_;
    output->fields.unknown_10_0_ = region->record.unknown_b_0_;
    output->fields.value10 = region->record.unknown_d_6_;
    output->fields.unknown_11_1_ = region->record.unknown_11_1_;
    output->fields.unknown_9_6_ = (unsigned char)func_020a0870(&region->record);
    output->fields.unknown_a_5_ = (unsigned char)func_020a08a4(&region->record);
    output->fields.unknown_f_0_ = (unsigned char)func_020a08d8(&region->record);
    output->fields.unknown_12_7_ = (unsigned char)func_020a090c(&region->record);
    output->fields.unknown_14_ = settings->fields.unknown_6_3_;
    output->fields.flag = (unsigned char)flag;
    output->fields.unknown_16_1_ = (unsigned char)var10;
    output->fields.unknown_17_ = func_02053c6c((unsigned char*)protagonist)->unknown_56a_;
#if !defined(jpn)
    output->fields.captured = 1;
#endif
    VectorizedMemset(&self->current.map, 0, 0x1c);
    Struct_ov003_02170d88_5 code = saved->code;
    self->current.code = code;
#if !defined(jpn)
    unsigned char platformLanguage = GameState_GetLanguage((Struct0200fb08*)state);
    int language = 0;
    switch (platformLanguage) {
    case 2: language = 1; break;
    case 3: language = 2; break;
    case 4: language = 3; break;
    case 5: language = 4; break;
    }
    self->sample.name = self->current.name;
    self->sample.vocation = self->current.vocation;
    self->sample.level = self->current.level;
    self->sample.unknown_d_ = self->current.unknown_d_;
    self->sample.code = self->current.code;
    self->sample.settings.words = self->current.settings.words;
    self->sample.effects = self->current.effects;
    self->sample.record.words = self->current.record.words;
    self->sample.map.values = self->current.map.values;
    memset(self->sample.name.text, 0, 0xb);
    sprintf(self->sample.name.text, data_ov003_021805e4[language]);
    memset(self->sample.settings.fields.message, 0, 0x74);
    sprintf(self->sample.settings.fields.message, data_ov003_021805d0[language]);
    Struct_ov003_02170d88_14* var18 = &self->sample.record;
    if (settings->fields.unknown_5_1_ >= 310) {
#if defined(eur)
        self->sample.settings.fields.unknown_5_1_ = 201;
#else
        self->sample.settings.fields.unknown_5_1_ = 203;
#endif
    }
    short var19;
    int var20 = settings->fields.unknown_6_3_;
    var19 = var20;
    if (var20 >= 750 && var20 < 800) var19 -= 50;
    else if (var20 >= 900) var19 -= 100;
    self->sample.settings.fields.unknown_6_3_ = var19;
    var18->fields.unknown_14_ = var19;
    TreasureMapMetadata map;
    func_020119f8((char*)state, &map);
    if (map.GetMapType() != TreasureMapType_Invalid) {
        self->sample.unknown_d_ = 1;
        self->sample.map.unknown_0_.DiscoveryStateAndMapTypeAndUnknown = map.DiscoveryStateAndMapTypeAndUnknown;
        INLINE_MEMCPY(self->sample.map.unknown_0_.DiscoveredBy, map.DiscoveredBy, 10);
        INLINE_MEMCPY(self->sample.map.unknown_0_.ClearedBy, map.ClearedBy, 10);
        self->sample.map.unknown_0_.Location = map.Location;
        self->sample.map.unknown_0_.TreasureDiscoveryFlags = map.TreasureDiscoveryFlags;
        self->sample.map.unknown_0_.QualityOrLegacyBossID = map.QualityOrLegacyBossID;
        self->sample.map.unknown_0_.LegacyBossLevel = map.LegacyBossLevel;
        self->sample.map.unknown_0_.SeedOrMinTurns = map.SeedOrMinTurns;
        TreasureMapMetadata* var22 = &self->sample.map.unknown_0_;
        memset(var22->DiscoveredBy, 0, 10);
        memset(var22->ClearedBy, 0, 10);
        char name[11] = {0};
        memset(name, 0, 11);
        memcpy(name, data_ov003_021805e4[language], 11);
        memcpy(var22->DiscoveredBy, name, 10);
        memset(name, 0, 11);
        memcpy(name, data_ov003_021805e4[language], 11);
        memcpy(var22->ClearedBy, name, 10);
    }
#endif
    func_ov003_02171f80((Struct_ov003_02170d88_13*)self);
    self->active = 0;
    self->unknown_738_ = 0;
    self->progress = 0;
    self->flags = 3;
    ((Struct_ov003_02170d88_12*)GetGameResources())->unknown_4494_ = 1;
    func_ov017_021b1d44(GetGameResources()->fieldTasks_[19], 0x20, 1);
}
