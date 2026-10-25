#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"


struct Struct_02018300_3;
struct Struct_02046574_2;
struct Struct_02011818 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    char unknown_3_;
    unsigned short unknown_4_;
    unsigned char unknown_6_;
    signed char unknown_7_;
    char unknown_8_[0xb];
    signed char unknown_13_;
    char unknown_14_[0xc];
    unsigned int unknown_20_;
    unsigned char unknown_24_;
    char unknown_25_;
    unsigned short unknown_26_;
};
struct Struct_ov017_021a9bf8_2 { unsigned char unknown_0_; unsigned char unknown_1_; TreasureMapMetadata unknown_2_[99]; };
#if defined(jpn)
enum { Enum_ov017_021a9bf8_96 = 0x2c, Enum_ov017_021a9bf8_712 = 0x218, Enum_ov017_021a9bf8_2456 = 0x868, Enum_ov017_021a9bf8_6578 = 0x17e2 };
extern const char data_ov017_021d7c96[];
extern const char data_ov017_021d7cbf[];
extern const char data_ov017_021d7ccb[];
extern const char data_ov017_021d7cd1[];
#else
enum { Enum_ov017_021a9bf8_96 = 0x60, Enum_ov017_021a9bf8_712 = 0x2c8, Enum_ov017_021a9bf8_2456 = 0x998, Enum_ov017_021a9bf8_6578 = 0x19b2 };
#endif
struct Struct_ov017_021a9bf8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    unsigned char unknown_8_;
    char unknown_9_;
    TreasureMapMetadata unknown_a_;
    DetailedTreasureMapData unknown_28_;
#if defined(jpn)
    char unknown_20c_[4][0x20];
    char unknown_28c_[0x80];
#else
    char unknown_1ec_[0x40];
    char unknown_22c_[0x40];
#endif
    unsigned char unknown_26c_;
    unsigned char unknown_26d_;
    unsigned char unknown_26e_;
    char unknown_26f_;
    unsigned short unknown_270_;
};
extern "C" unsigned char* func_020100f8(char*);
extern "C" int func_ov017_021959b4();
void Something_021a9f58(int);
void ClearIntAt0x23c_020a27b8(unsigned char*);
void GameObject_DisableControl(Obj020397cc*, int);
void ResetElapsedState020e11a4();
char* MessageSystem_GetInstance();
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
const char* StandardStrings_Get(int);
unsigned char ReadBattleField0x64f4Byte_02011804(GameState* gameState);
void CopyOutBattleRegion0x64f4_020ac760(void*);
void CopyToBattleRegion0x64f4_020ac734(void*);
extern "C" void func_0204500c(char*, char*, int
#if !defined(jpn)
    , int
#endif
);
extern "C" int func_020457e0(char*);
extern "C" void func_02011818(void*, Struct_02011818*);
extern "C" void func_02011ab8(char*);
extern "C" void func_02011a74(char*, unsigned int, const char*);
extern "C" void func_ov017_021a9ff0(int);
extern "C" void* Scenario_GetInstance();
int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void*);
void GameObject_EnableControl(void*);
extern "C" void FieldTask_EndAcquireTreasureMap(MapTask021a9bf8*);
extern const char data_ov017_021d781f[];
extern const char data_ov017_021d782b[];

// Overlay 17, originally func_ov017_021a9bf8 (USA/EUR 0x021a9bf8, JPN 0x021aa43c)
extern "C" ARM void FieldTask_AcquireTreasureMap(MapTask021a9bf8* self) {
    GameState* state = GameState::GetInstance();
    unsigned char* field = GetFieldIfFlag4_020100f8((char*)state);
    MapHistory021a9bf8 history;
    Src02011818 names;
    unsigned char nodes[0x34];
    if (func_ov017_021959b4()) { Something_021a9f58((int)self); return; }
    GameObject* object = state->GetUnknownGameObject();
    if (!object) { self->complete = 1; return; }
    if (self->stage == 0) {
        FontBankLoader* global = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(global);
        BlankFunction02094b3c(global, 12);
        BlankFunction02094b30(global, 0x203, 0);
        ClearIntAt0x23c_020a27b8(field);
        self->stage = 1;
    } else if (self->stage == 1) {
        if (!AlwaysTrue02094b4c(FontBankLoader_GetInstance())) return;
        GameObject_DisableControl((Obj020397cc*)object, 1);
        ResetElapsedState020e11a4();
        char* window = MessageSystem_GetInstance();
        char* text = (*reinterpret_cast<char**>(window + TextOffset));
#if defined(jpn)
        char* protagonistName = state->GetUnknownGameObject()->baseStats_->name;
        sprintf(text, data_ov017_021d7c96, protagonistName, self->description);
#else
        MessageSystem_SetStringArgument((Obj02046574*)window, 1, self->description);
        sprintf(text, StandardStrings_Get(0x40));
#endif
        if (func_02011804(var0) >= 99) {
            arg0->unknown_26c_ = 1;
#if defined(jpn)
            strcat(var8, data_ov017_021d7cbf);
#else
            strcat(var8, data_ov017_021d781f);
#endif
            arg0->unknown_8_ = 2;
        } else {
            func_020ac760(&var2);
            VectorizedMemset(&var2.unknown_2_[var2.unknown_0_], 0, 0x1c);
            VectorizedInvertedMemcpy(&arg0->unknown_a_, &var2.unknown_2_[var2.unknown_0_], 0x1c);
            var2.unknown_0_++;
            func_020ac734(&var2);
#if defined(jpn)
            strcat(var8, data_ov017_021d7ccb);
#else
            strcat(var8, data_ov017_021d782b);
#endif
            arg0->unknown_8_ = 4;
        }
        func_0204500c(var7, var8, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<int*>(window + BusyOffset)) = 1;
        (*reinterpret_cast<unsigned char*>(window + ChoiceFlagOffset)) = 0;
    } else if (self->stage == 2) {
        char* window = MessageSystem_GetInstance();
        if ((*reinterpret_cast<int*>(window + BusyOffset))) return;
        char* text = (*reinterpret_cast<char**>(window + TextOffset));
#if defined(jpn)
        char* protagonistName = state->GetUnknownGameObject()->baseStats_->name;
        sprintf(text, data_ov017_021d7cd1, self->description, protagonistName, self->description);
#else
        MessageSystem_SetStringArgument((Obj02046574*)window, 0, self->description);
        sprintf(text, StandardStrings_Get(0x41));
#endif
        (*reinterpret_cast<int*>(var10 + Enum_ov017_021a9bf8_712)) = 1;
        func_0204500c(var10, var11, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<int*>(window + BusyOffset)) = 1;
        (*reinterpret_cast<unsigned char*>(window + ChoiceFlagOffset)) = 1;
        self->stage = 3;
    } else if (self->stage == 3) {
        char* window = MessageSystem_GetInstance();
        if ((*reinterpret_cast<int*>(window + BusyOffset))) return;
        int choice = func_020457e0(window);
        if (choice == 0) self->stage = 4;
        else if (choice == 1) {
            VectorizedMemset(&names, 0, 0x28);
            names.discoveredBy = 0;
            names.clearedBy = 0;
            names.field_6 = 0;
            names.location = -1;
            names.type = self->type;
            names.quality = self->quality;
            names.legacyLevel = self->seed;
            names.seed = self->seed;
            names.field_6 = 0;
            names.location = self->metadata.Location;
            SetNameEntries02011818(state, &names);
            ClearRegion0x649e_02011ab8((char*)state);
#if defined(jpn)
            func_02011a74((char*)var0, 0, arg0->unknown_20c_[0]);
            func_02011a74((char*)var0, 1, arg0->unknown_20c_[1]);
            func_02011a74((char*)var0, 2, arg0->unknown_20c_[2]);
            func_02011a74((char*)var0, 3, arg0->unknown_20c_[3]);
#else
            func_02011a74((char*)var0, 0, arg0->unknown_1ec_);
#endif
            func_ov017_021a9ff0(0);
            arg0->unknown_8_ = 5;
        }
    } else if (self->stage == 4) {
        if ((*reinterpret_cast<int*>(MessageSystem_GetInstance() + BusyOffset))) return;
        FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
        if (Scenario_RunTrigger(Scenario_GetInstance(), 0x1b, nodes)) EventQuery_RunQueuedCommands(nodes);
        self->stage = 5;
    }
    if (self->stage == 5) {
        GameObject_EnableControl(state->GetUnknownGameObject());
        FieldTask_EndAcquireTreasureMap(self);
    }
}
