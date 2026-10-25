#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c1af0 { unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; int unknown_8_, unknown_c_; };
struct Struct_ov017_021c1af0_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    char unknown_3_[4];
    unsigned char unknown_7_;
    char unknown_8_[8];
    Vector3i unknown_10_;
    unsigned short unknown_1c_;
};
struct Struct_0201bdac { char unknown_0_[8]; unsigned short unknown_8_; };
struct Struct_0201bdac_2;
struct Struct_02046574_2;
#if defined(jpn)
enum { Enum_ov017_021c1af0_92 = 0x28, Enum_ov017_021c1af0_2456 = 0x868, Enum_ov017_021c1af0_2464 = 0x870,
       Enum_ov017_021c1af0_6574 = 0x17de, Enum_ov017_021c1af0_6578 = 0x17e2 };
extern const char data_ov017_021d8730[];
extern const char data_ov017_021d876c[];
#else
enum { Enum_ov017_021c1af0_92 = 0x5c, Enum_ov017_021c1af0_2456 = 0x998, Enum_ov017_021c1af0_2464 = 0x9a0,
       Enum_ov017_021c1af0_6574 = 0x19ae, Enum_ov017_021c1af0_6578 = 0x19b2 };
#endif
struct Obj020397cc;
struct SearchStruct0202c1a4;
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" int* func_0202ae18();
Obj02046574* MessageSystem_GetInstance();
void GameObject_DisableControl(Obj020397cc*, int);
int CheckField0NonZero_0202b7d8(int*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" int func_ov017_0219ff58(GameResources*, int, int, int);
Action021c1af0* GetField0x3f8Address_0200fd0c(GameState*);
void InitStruct02070378(char*);
extern "C" void func_ov017_021baedc(TailNode020469b4*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char, unsigned short);
void EnqueueEventTagB5_021d1dc0(unsigned short, int, int*, int, int);
const char* StandardStrings_Get(int);
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_0204500c(void*, const char*, int
#if !defined(jpn)
    , int
#endif
);
extern "C" int func_02011b50(void*, int);
extern "C" void func_ov017_0219c520();
void MessageSystem_Reset(char*);
void GameObject_EnableControl(void*);

// Overlay 17, originally func_ov017_021c1af0 (USA/EUR 0x021c1af0, JPN 0x021c2074)
extern "C" ARM void FieldTask_BoardVehicle(State021c1af0* state) {
    GameState* game = GameState::GetInstance();
    Zone3D* context = Zone3D_GetInstance();
    if (state->step == 0) {
        GameObject_DisableControl((Obj020397cc*)game->GetProtagonist(), 1);
        FontBankLoader* global = FontBankLoader_GetInstance();
        BlankFunction02094b30(global, 0x204, 0);
        if (AlwaysTrue02094b4c(global)) state->step = 1;
    } else if (state->step == 1) {
        Obj02046574* controller = MessageSystem_GetInstance();
        int* search = func_0202ae18();
        if (!CheckField0NonZero_0202b7d8(search) || (CheckField0NonZero_0202b7d8(search) && GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) == 0)) {
            GameResources* resources = GetGameResources();
            TailList020469b4* list = (TailList020469b4*)resources->fieldTaskQueue_;
            TailNode020469b4* node = static_cast<TailNode020469b4*>(resources->unknown_ptr_array_371c[6]);
            if (func_ov017_0219ff58(resources, 1, 0, 0)) {
                state->step = 2;
                return;
            }
            var0->GetProtagonist();
            Struct_ov017_021c1af0_2* var8 = func_0200fd0c(var0);
            if (arg0->unknown_c_ == 0) {
                func_02070378((char*)var8);
                var8->unknown_2_ = 1;
                var8->unknown_7_ = 1;
                var8->unknown_0_ = 0x2710;
                var8->unknown_10_ = (*reinterpret_cast<Vector3i*>(var1->unk_276c + 0x8));
                var8->unknown_1c_ = (*reinterpret_cast<int*>(var1->unk_276c + 0x14));
            } else if ((*reinterpret_cast<unsigned short*>(var1->unk_276c + 0x48)) == 3) {
                func_ov017_021baedc(var7, 1);
                var7->unknown_8_ = 0x7345;
                (*reinterpret_cast<unsigned char*>(var1->unk_276c + 0xb3)) = 1;
                func_020469b4(var6, var7);
                func_ov017_021d1c2c(0, 1);
                int var9[3];
                func_ov017_021d1dc0(0, 0, var9, 0x7345, 0);
            } else {
                func_02070378((char*)var8);
                var8->unknown_2_ = 1;
                var8->unknown_7_ = 1;
                var8->unknown_0_ = 0x2774;
                var8->unknown_10_ = (*reinterpret_cast<Vector3i*>(var1->unk_276c + 0x4c));
                var8->unknown_1c_ = (*reinterpret_cast<int*>(var1->unk_276c + 0x58));
            }
            arg0->unknown_8_ = 2;
        } else {
            char* var10 = (*reinterpret_cast<char**>(reinterpret_cast<char*>(var3) + Enum_ov017_021c1af0_92));
#if defined(jpn)
            if (state->alternate == 0) sprintf(buffer, data_ov017_021d8730, game->GetUnknownGameObject()->baseStats_->name);
            else sprintf(buffer, data_ov017_021d876c, game->GetUnknownGameObject()->baseStats_->name);
            func_0204500c(controller, buffer, 0);
#else
            if (state->alternate == 0) sprintf(buffer, StandardStrings_Get(0x3c));
            else sprintf(buffer, StandardStrings_Get(0x3d));
            MessageSystem_SetStringArgument(controller, 0, (char*)game->GetUnknownGameObject()->baseStats_);
            func_0204500c(controller, buffer, 0, 0xe3);
#endif
            (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(var3) + Enum_ov017_021c1af0_6578)) = 0;
            (*reinterpret_cast<int*>(reinterpret_cast<char*>(var3) + Enum_ov017_021c1af0_2456)) = 1;
            arg0->unknown_8_ = 3;
        }
    } else if (arg0->unknown_8_ == 2) {
        if (func_02011b50(var0, 1)) {
            func_ov017_0219c520();
        }
        FontBankLoader* global = FontBankLoader_GetInstance();
        BlankFunction02094b38(global, 0x1f9);
        FontBankLoader_CancelLoads(global);
        state->done = 1;
    } else if (state->step == 3) {
        Obj02046574* controller = MessageSystem_GetInstance();
        (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(controller) + MessageFlagOffset)) = 0;
        if (!(*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + BusyOffset))) {
            MessageSystem_Reset((char*)controller);
            GameObject_EnableControl(game->GetProtagonist());
            FontBankLoader* global = FontBankLoader_GetInstance();
            BlankFunction02094b38(global, 0x204);
            FontBankLoader_CancelLoads(global);
            state->done = 1;
        }
    }
}
