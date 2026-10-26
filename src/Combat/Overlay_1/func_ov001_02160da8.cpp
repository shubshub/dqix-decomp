#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
#include "Resource/GameResources.h"

struct Struct_ov001_0215b72c { char data[8]; };
struct Struct_ov001_02160da8 {
    unsigned char kind : 4;
    unsigned char group : 4;
    unsigned char action;
    short objectId;
    unsigned char unknown_4_;
    char pad0[3];
    union { char filename[36]; int unknown1_0_; } resource;
    int task;
    unsigned char option;
    unsigned char unknown_31_;
    char pad1[2];
    Struct_ov001_02160da8* next;
};
struct Struct_ov001_02160da8_2 {
    #if defined(jpn)
    char pad0[0xcc]; Struct_ov001_02160da8* commands;
#else
    char pad0[0xd0]; Struct_ov001_02160da8* commands;
#endif
    char pad1[0xf8 - 0xd4]; unsigned int flags : 27; unsigned int nextObject : 5;
    char pad2[0x116 - 0xfc]; signed char unknown_116_;
};
struct Struct_0205faf4_11;
extern "C" int func_ov017_021d60f4(Struct_ov001_0215b72c*);
extern "C" const char* func_ov017_021d612c(Struct_ov001_0215b72c*);
extern "C" int GameState_GetLeaderIndex(GameState*);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" int func_ov001_021612ac(void*);
extern "C" int func_02061bd8(Struct_0205faf4_11*);
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_02165728[];
extern const char data_ov001_02165745[];
extern const char data_ov001_02165775[];
extern const char data_ov001_021657b2[];

// USA: func_ov001_02160da8
extern "C" ARM int func_ov001_02160da8(Struct_ov001_0215b72c* arguments, int count) {
    GameState* game = GameState::GetInstance();
    Struct_ov001_02160da8* command;
    Struct_ov001_02160da8_2* state = (Struct_ov001_02160da8_2*)GetGameResources()->unknown_ptr_array_371c[6];
    SafeAllocator* allocator = data_ov001_021658b8[0];
    unsigned int objectId = state->nextObject + 160;
    if (objectId > 191) return 0;
    command = (Struct_ov001_02160da8*)allocator->Allocate(sizeof(Struct_ov001_02160da8));
    command->kind = 0;
    command->group = 0;
    command->action = 0;
    command->objectId = 0;
    command->unknown_4_ = 0;
    memset(command->resource.filename, 0, sizeof(command->resource.filename));
    command->task = -1;
    command->next = 0;
    command->option = 0;
    command->unknown_31_ = 0;
    command->kind = (unsigned char)func_ov017_021d60f4(arguments);
    switch (command->kind) {
    case 0:
    case 1:
    case 9:
        if (count < 2) return 0;
        command->action = func_ov017_021d60f4(arguments + 1);
        if (command->kind == 1) command->objectId = GameState_GetLeaderIndex(game);
        else if (command->kind == 9) {
            command->objectId = state->unknown_116_;
            if (!func_0200ff1c(game, command->objectId)) command->objectId = GameState_GetLeaderIndex(game);
        }
        if (command->objectId == 0) command->group = 1;
        else command->group = 2;
        break;
    case 11:
    case 12:
    case 13:
        if (count < 2) return 0;
        command->action = func_ov017_021d60f4(arguments + 1);
        command->group = 2;
        GameState_GetLeaderIndex(game);
        if (command->kind == 11) command->objectId = 3;
        else if (command->kind == 12) command->objectId = 2;
        else if (command->kind == 13) command->objectId = 1;
        if (!game->GetGameObjectByIndex(command->objectId)) {
            command->kind = 15;
            return 0;
        }
        break;
    case 10: {
        if (count < 2) return 0;
        command->action = func_ov017_021d60f4(arguments + 1);
        int group = 0;
        GameObject* member = func_0200ff58(game, 0xce);
        if (member) {
            command->objectId = 0xce;
            group = func_ov001_021612ac(member);
        } else {
            int index;
            for (index = 0; index < 4; ++index) {
                GameObject* member = func_0200ff58(game, index);
                if (member && func_02061bd8((Struct_0205faf4_11*)member)) {
                    command->objectId = index;
                    group = func_ov001_021612ac(member);
                    break;
                }
            }
            if (index == 4) return 0;
        }
        command->group = (unsigned char)(group + 2);
        break;
    }
    case 2:
    case 6:
    case 7: {
        if (count < 3) return 0;
        const char* filename = func_ov017_021d612c(arguments + 1);
        if (command->kind == 6) {
            if (!strstr(filename, data_ov001_02165728)) return 0;
            const char* var10 = strrchr(filename, '/');
            if (var10) filename = var10 + 1;
            strcpy(command->resource.filename, filename);
        } else sprintf(command->resource.filename, data_ov001_02165745, filename);
        command->action = func_ov017_021d60f4(arguments + 2);
        command->objectId = state->nextObject + 160;
        ++state->nextObject;
        if (count > 3) command->option = func_ov017_021d60f4(arguments + 3);
        break;
    }
    case 8:
        if (count < 2) return 0;
        sprintf(command->resource.filename, data_ov001_02165775);
        command->action = func_ov017_021d60f4(arguments + 1);
        command->objectId = state->nextObject + 160;
        ++state->nextObject;
        if (count > 2) command->option = func_ov017_021d60f4(arguments + 2);
        break;
    case 3:
        if (count < 3) return 0;
        sprintf(command->resource.filename, data_ov001_021657b2, func_ov017_021d612c(arguments + 1));
        command->action = func_ov017_021d60f4(arguments + 2);
        if (count > 3) command->option = func_ov017_021d60f4(arguments + 3);
        break;
    case 4:
    case 5:
        if (count < 3) return 0;
        command->resource.unknown1_0_ = func_ov017_021d60f4(arguments + 1);
        command->action = func_ov017_021d60f4(arguments + 2);
        if (command->kind == 4) {
            command->objectId = state->nextObject + 160;
            ++state->nextObject;
        }
        break;
    default:
        return 0;
    }
    if (!state->commands) state->commands = command;
    else {
        Struct_ov001_02160da8* tail = state->commands;
        while (tail->next) tail = tail->next;
        tail->next = command;
    }
    return 1;
}
