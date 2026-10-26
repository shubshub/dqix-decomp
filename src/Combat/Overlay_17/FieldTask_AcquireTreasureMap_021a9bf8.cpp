#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"


struct Obj020397cc;
struct Obj02046574;
struct Struct_02011818 {
    unsigned char type;
    unsigned char quality;
    unsigned char unknown_2_;
    char unknown_3_;
    unsigned short seed;
    unsigned char unknown_6_;
    signed char unknown_7_;
    char unknown_8_[0xb];
    signed char unknown_13_;
    char unknown_14_[0xc];
    unsigned int location;
    unsigned char unknown_24_;
    char unknown_25_;
    unsigned short unknown_26_;
};
struct Struct_ov017_021a9bf8_2 { unsigned char count; unsigned char unknown_1_; TreasureMapMetadata unknown_2_[99]; };
#if defined(jpn)
enum { TextOffset = 0x2c, Enum_ov017_021a9bf8_712 = 0x218, BusyOffset = 0x868, Enum_ov017_021a9bf8_6578 = 0x17e2 };
extern const char data_ov017_021d7c96[];
extern const char data_ov017_021d7cbf[];
extern const char data_ov017_021d7ccb[];
extern const char data_ov017_021d7cd1[];
#else
enum { TextOffset = 0x60, Enum_ov017_021a9bf8_712 = 0x2c8, BusyOffset = 0x998, Enum_ov017_021a9bf8_6578 = 0x19b2 };
#endif
struct MapTask021a9bf8 {
    unsigned char field_0;
    unsigned char unknown_1_;
    char unknown_2_[6];
    unsigned char stage;
    char unknown_9_;
    TreasureMapMetadata unknown_a_;
    DetailedTreasureMapData unknown_28_;
#if defined(jpn)
    char name[4][0x20];
    char description[0x80];
#else
    char name[0x40];
    char description[0x40];
#endif
    unsigned char error;
    unsigned char type;
    unsigned char quality;
    char unknown_26f_;
    unsigned short seed;
};
extern "C" unsigned char* GameState_GetFollowCamera(char*);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov017_021a9f58(int);
extern "C" void func_020a27b8(unsigned char*);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void func_020e11a4();
extern "C" char* MessageSystem_GetInstance();
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" const char* StandardStrings_Get(int);
extern "C" unsigned char func_02011804(GameState* gameState);
extern "C" void func_020ac760(void*);
extern "C" void func_020ac734(void*);
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
extern "C" int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void*);
extern "C" void GameObject_EnableControl(void*);
extern "C" void FieldTask_EndAcquireTreasureMap(MapTask021a9bf8*);
extern const char data_ov017_021d781f[];
extern const char data_ov017_021d782b[];

// Overlay 17, originally func_ov017_021a9bf8 (USA/EUR 0x021a9bf8, JPN 0x021aa43c)
extern "C" ARM void FieldTask_AcquireTreasureMap(MapTask021a9bf8* self) {
    GameState* state = GameState::GetInstance();
    unsigned char* field = GameState_GetFollowCamera((char*)state);
    Struct_ov017_021a9bf8_2 var2;
    Struct_02011818 names;
    unsigned char nodes[0x34];
    if (func_ov017_021959b4()) { func_ov017_021a9f58((int)self); return; }
    GameObject* object = state->GetLeader();
    if (!object) { self->unknown_1_ = 1; return; }
    if (self->stage == 0) {
        FontBankLoader* global = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(global);
        func_02094b3c(global, 12);
        func_02094b30(global, 0x203, 0);
        func_020a27b8(field);
        self->stage = 1;
    } else if (self->stage == 1) {
        if (!func_02094b4c(FontBankLoader_GetInstance())) return;
        GameObject_DisableControl((Obj020397cc*)object, 1);
        func_020e11a4();
        char* window = MessageSystem_GetInstance();
        char* text = (*reinterpret_cast<char**>(window + TextOffset));
#if defined(jpn)
        char* protagonistName = state->GetLeader()->baseStats_->name;
        sprintf(text, data_ov017_021d7c96, protagonistName, self->description);
#else
        MessageSystem_SetStringArgument((Obj02046574*)window, 1, self->description);
        sprintf(text, StandardStrings_Get(0x40));
#endif
        if (func_02011804(state) >= 99) {
            self->error = 1;
#if defined(jpn)
            strcat(text, data_ov017_021d7cbf);
#else
            strcat(text, data_ov017_021d781f);
#endif
            self->stage = 2;
        } else {
            func_020ac760(&var2);
            VectorizedMemset(&var2.unknown_2_[var2.count], 0, 0x1c);
            VectorizedInvertedMemcpy(&self->unknown_a_, &var2.unknown_2_[var2.count], 0x1c);
            var2.count++;
            func_020ac734(&var2);
#if defined(jpn)
            strcat(text, data_ov017_021d7ccb);
#else
            strcat(text, data_ov017_021d782b);
#endif
            self->stage = 4;
        }
        func_0204500c(window, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<int*>(window + BusyOffset)) = 1;
        (*reinterpret_cast<unsigned char*>(window + Enum_ov017_021a9bf8_6578)) = 0;
    } else if (self->stage == 2) {
        char* window = MessageSystem_GetInstance();
        if ((*reinterpret_cast<int*>(window + BusyOffset))) return;
        char* text = (*reinterpret_cast<char**>(window + TextOffset));
#if defined(jpn)
        char* protagonistName = state->GetLeader()->baseStats_->name;
        sprintf(text, data_ov017_021d7cd1, self->description, protagonistName, self->description);
#else
        MessageSystem_SetStringArgument((Obj02046574*)window, 0, self->description);
        sprintf(text, StandardStrings_Get(0x41));
#endif
        (*reinterpret_cast<int*>(window + Enum_ov017_021a9bf8_712)) = 1;
        func_0204500c(window, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<int*>(window + BusyOffset)) = 1;
        (*reinterpret_cast<unsigned char*>(window + Enum_ov017_021a9bf8_6578)) = 1;
        self->stage = 3;
    } else if (self->stage == 3) {
        char* window = MessageSystem_GetInstance();
        if ((*reinterpret_cast<int*>(window + BusyOffset))) return;
        int choice = func_020457e0(window);
        if (choice == 0) self->stage = 4;
        else if (choice == 1) {
            VectorizedMemset(&names, 0, 0x28);
            names.unknown_7_ = 0;
            names.unknown_13_ = 0;
            names.unknown_6_ = 0;
            names.location = -1;
            names.type = self->type;
            names.quality = self->quality;
            names.unknown_2_ = self->seed;
            names.seed = self->seed;
            names.unknown_6_ = 0;
            names.location = self->unknown_a_.Location;
            func_02011818(state, &names);
            func_02011ab8((char*)state);
#if defined(jpn)
            func_02011a74((char*)state, 0, self->name[0]);
            func_02011a74((char*)state, 1, self->name[1]);
            func_02011a74((char*)state, 2, self->name[2]);
            func_02011a74((char*)state, 3, self->name[3]);
#else
            func_02011a74((char*)state, 0, self->name);
#endif
            func_ov017_021a9ff0(0);
            self->stage = 5;
        }
    } else if (self->stage == 4) {
        if ((*reinterpret_cast<int*>(MessageSystem_GetInstance() + BusyOffset))) return;
        FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
        if (Scenario_RunTrigger(Scenario_GetInstance(), 0x1b, nodes)) EventQuery_RunQueuedCommands(nodes);
        self->stage = 5;
    }
    if (self->stage == 5) {
        GameObject_EnableControl(state->GetLeader());
        FieldTask_EndAcquireTreasureMap(self);
    }
}
