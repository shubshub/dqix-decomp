#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct State021c1af0 { unsigned char pad0, done; char pad2[6]; int step, alternate; };
struct Action021c1af0 {
    unsigned short kind;
    unsigned char unknown_2_;
    char pad3[4];
    unsigned char unknown_7_;
    char pad8[8];
    Vector3i position;
    unsigned short field_1c;
};
struct TailNode020469b4 { char pad[8]; unsigned short kind; };
struct TailList020469b4;
struct Obj02046574;
#if defined(jpn)
enum { Enum_ov017_021c1af0_92 = 0x28, Enum_ov017_021c1af0_2456 = 0x868, BusyOffset = 0x870,
       Enum_ov017_021c1af0_6574 = 0x17de, Enum_ov017_021c1af0_6578 = 0x17e2 };
extern const char data_ov017_021d8730[];
extern const char data_ov017_021d876c[];
#else
enum { Enum_ov017_021c1af0_92 = 0x5c, Enum_ov017_021c1af0_2456 = 0x998, BusyOffset = 0x9a0,
       Enum_ov017_021c1af0_6574 = 0x19ae, Enum_ov017_021c1af0_6578 = 0x19b2 };
#endif
struct Obj020397cc;
struct SearchStruct0202c1a4;
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" int* LinkSession_GetInstance();
extern "C" Obj02046574* MessageSystem_GetInstance();
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" int func_ov017_0219ff58(GameResources*, int, int, int);
extern "C" Action021c1af0* GameState_GetZoneTransition(GameState*);
extern "C" void func_02070378(char*);
extern "C" void func_ov017_021baedc(TailNode020469b4*, int);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" void func_ov017_021d1c2c(unsigned char, unsigned short);
extern "C" void func_ov017_021d1dc0(unsigned short, int, int*, int, int);
extern "C" const char* StandardStrings_Get(int);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_0204500c(void*, const char*, int
#if !defined(jpn)
    , int
#endif
);
extern "C" int func_02011b50(void*, int);
extern "C" void func_ov017_0219c520();
extern "C" void MessageSystem_Reset(char*);
extern "C" void GameObject_EnableControl(void*);

// Overlay 17, originally func_ov017_021c1af0 (USA/EUR 0x021c1af0, JPN 0x021c2074)
extern "C" ARM void FieldTask_BoardVehicle(State021c1af0* state) {
    GameState* game = GameState::GetInstance();
    Zone3D* context = Zone3D_GetInstance();
    if (state->step == 0) {
        GameObject_DisableControl((Obj020397cc*)game->GetProtagonist(), 1);
        FontBankLoader* global = FontBankLoader_GetInstance();
        func_02094b30(global, 0x204, 0);
        if (func_02094b4c(global)) state->step = 1;
    } else if (state->step == 1) {
        Obj02046574* controller = MessageSystem_GetInstance();
        int* search = LinkSession_GetInstance();
        if (!LinkSession_IsActive(search) || (LinkSession_IsActive(search) && LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) == 0)) {
            GameResources* resources = GetGameResources();
            TailList020469b4* list = (TailList020469b4*)resources->fieldTaskQueue_;
            TailNode020469b4* node = static_cast<TailNode020469b4*>(resources->unknown_ptr_array_371c[6]);
            if (func_ov017_0219ff58(resources, 1, 0, 0)) {
                state->step = 2;
                return;
            }
            game->GetProtagonist();
            Action021c1af0* action = GameState_GetZoneTransition(game);
            if (state->alternate == 0) {
                func_02070378((char*)action);
                action->unknown_2_ = 1;
                action->unknown_7_ = 1;
                action->kind = 0x2710;
                action->position = (*reinterpret_cast<Vector3i*>(context->unk_276c + 0x8));
                action->field_1c = (*reinterpret_cast<int*>(context->unk_276c + 0x14));
            } else if ((*reinterpret_cast<unsigned short*>(context->unk_276c + 0x48)) == 3) {
                func_ov017_021baedc(node, 1);
                node->kind = 0x7345;
                (*reinterpret_cast<unsigned char*>(context->unk_276c + 0xb3)) = 1;
                func_020469b4(list, node);
                func_ov017_021d1c2c(0, 1);
                int position[3];
                func_ov017_021d1dc0(0, 0, position, 0x7345, 0);
            } else {
                func_02070378((char*)action);
                action->unknown_2_ = 1;
                action->unknown_7_ = 1;
                action->kind = 0x2774;
                action->position = (*reinterpret_cast<Vector3i*>(context->unk_276c + 0x4c));
                action->field_1c = (*reinterpret_cast<int*>(context->unk_276c + 0x58));
            }
            state->step = 2;
        } else {
            char* buffer = (*reinterpret_cast<char**>(reinterpret_cast<char*>(controller) + Enum_ov017_021c1af0_92));
#if defined(jpn)
            if (state->alternate == 0) sprintf(buffer, data_ov017_021d8730, game->GetLeader()->baseStats_->name);
            else sprintf(buffer, data_ov017_021d876c, game->GetLeader()->baseStats_->name);
            func_0204500c(controller, buffer, 0);
#else
            if (state->alternate == 0) sprintf(buffer, StandardStrings_Get(0x3c));
            else sprintf(buffer, StandardStrings_Get(0x3d));
            MessageSystem_SetStringArgument(controller, 0, (char*)game->GetLeader()->baseStats_);
            func_0204500c(controller, buffer, 0, 0xe3);
#endif
            (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(controller) + Enum_ov017_021c1af0_6578)) = 0;
            (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + Enum_ov017_021c1af0_2456)) = 1;
            state->step = 3;
        }
    } else if (state->step == 2) {
        if (func_02011b50(game, 1)) {
            func_ov017_0219c520();
        }
        FontBankLoader* global = FontBankLoader_GetInstance();
        func_02094b38(global, 0x1f9);
        FontBankLoader_CancelLoads(global);
        state->done = 1;
    } else if (state->step == 3) {
        Obj02046574* controller = MessageSystem_GetInstance();
        (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(controller) + Enum_ov017_021c1af0_6574)) = 0;
        if (!(*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + BusyOffset))) {
            MessageSystem_Reset((char*)controller);
            GameObject_EnableControl(game->GetProtagonist());
            FontBankLoader* global = FontBankLoader_GetInstance();
            func_02094b38(global, 0x204);
            FontBankLoader_CancelLoads(global);
            state->done = 1;
        }
    }
}
