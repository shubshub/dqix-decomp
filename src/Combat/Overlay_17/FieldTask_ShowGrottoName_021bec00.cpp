#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/Brightness.h"
struct Struct_02018300_3;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_ov017_021bec00_3 {
#if defined(jpn)
    char unknown_0_[0x240c];
#else
    char unknown1_0_[0x23ec];
#endif
    ActiveGrottoClass unknown_23ec_;
};
union Struct_ov017_021bec00_4 { struct { int unknown_0_, unknown_4_; }; long long unknown1_0_; };
struct Struct_ov017_021bec00_5 {
#if defined(jpn)
    char unknown_0_[0x7e8];
#else
    char unknown1_0_[0x918];
#endif
    short unknown_918_;
    char unknown_91a_[0x998-0x91a];
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_, unknown_9a4_;
    char unknown_9a8_[0x1858-0x9a8];
    Struct_ov017_021bec00_4 unknown_1858_;
#if defined(jpn)
    char unknown_1730_[0x17de - 0x1730];
#else
    char unknown_1860_[0x19ae - 0x1860];
#endif
    unsigned char unknown_19ae_, unknown_19af_;
    char unknown_19b0_[8];
    unsigned char unknown_19b8_;
};
struct Struct_ov017_021bec00 {
    unsigned short unknown_0_;
    char unknown_2_[2];
    unsigned char unknown_4_;
    char unknown_5_[2];
    unsigned char unknown_7_, unknown_8_, unknown_9_;
    char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    int unknown_10_, unknown_14_, unknown_18_;
    short unknown_1c_, unknown_1e_;
    int unknown_20_[4];
    char unknown_30_[0x6c-0x30];
    short unknown_6c_;
    char unknown_6e_[2];
};
struct Struct_ov017_021bec00_2 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[0x38-2];
    int unknown_38_;
    char unknown_3c_[4];
    int unknown_40_;
    SafeAllocator unknown_44_;
    char unknown_58_[0xa4];
};
extern "C" void LinkSession_GetInstance();
extern "C" ZoneState021bec00* Zone3D_GetInstance();
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void KeyTable_Load(void*, SafeAllocator*, void*, unsigned int);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov017_021bec00_5*, char*, int);
#else
extern "C" void func_0204500c(Struct_ov017_021bec00_5*, char*, int, int);
#endif
#if defined(jpn)
extern "C" void func_02043270(Struct_ov017_021bec00_5*, int, int, int, int);
#else
extern "C" void func_02042b98(Struct_ov017_021bec00_5*, int, int, int, int);
#endif
extern "C" void func_ov017_021bef84(PopupState021bec00*);
PopupController021bec00* MessageSystem_GetInstance();
void GameObject_DisableControl(Obj020397cc*, int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
GrottoTransitionData* GameState_GetZoneTransition(GameState*);
void FieldTask_InitEnterZone(unsigned char*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void MessageSystem_Reset(char*);
void GameObject_EnableControl(void*);
extern AllocatorUnion g_mainAllocator;
#if defined(jpn)
extern char data_ov017_021d86ac[], data_ov017_021d86c6[];
#else
extern char data_ov017_021d7e98[], data_ov017_021d7eb2[];
#endif
// Overlay 17, originally func_ov017_021bec00 (USA/EUR 0x021bec00, JPN 0x021bf1c0)
extern "C" ARM void FieldTask_ShowGrottoName(PopupState021bec00* self) {
    GameState* game = GameState::GetInstance();
    LinkSession_GetInstance();
    GameResources* resources = GetGameResources();
    PopupController021bec00* controller = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = &Zone3D_GetInstance()->grotto;
    game->GetGrottoStruct();
    char text[0x100] = {};
    controller->flag19ae = 0;
    if (self->state == 0) {
        GameObject_DisableControl((Obj020397cc*)game->GetLeader(), 1);
        SetFlags04(resources, 0xc0);
        FontBankLoader* music = FontBankLoader_GetInstance();
        BlankFunction02094b30(music, 0x203, 0);
        if (AlwaysTrue02094b4c(music)) {
            self->state = 1;
            self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xc00), 0xc00);
#if defined(jpn)
            arg0->unknown_40_ = var3->QueueLoadFile(data_ov017_021d86ac, 0);
#else
            arg0->unknown_40_ = var3->QueueLoadFile(data_ov017_021d7e98, 0);
#endif
        }
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->task)) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.Reset();
            KeyTable_Load(&self->script, &self->allocator, data, length);
            loader->RemoveTask(self->task);
            self->task = -1;
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (!IsBrightnessTransitionActive(resources)) {
            if ((unsigned char&)grotto->unknown_260_[2]) {
                GrottoTransitionData* transition = GameState_GetZoneTransition(game);
                VectorizedMemset(transition, 0, 0x70);
                transition->flag4 = 1;
                transition->flag8 = 1;
                transition->flag9 = 1;
                transition->fieldb = -1;
                transition->fields20[0] = -1;
                transition->fields20[1] = -1;
                transition->fields20[2] = -1;
                transition->fields20[3] = -1;
                transition->field1e = -1;
                transition->flagc = 0;
                transition->field6c = -1;
                transition->id = (unsigned short&)grotto->unknown_274_;
                Vector3fix position = *(Vector3fix*)&grotto->unknown_264_[1];
                transition->x = position.x;
                transition->y = position.y;
                transition->z = position.z;
                transition->field1c = 0x3244;
                transition->flag7 = 1;
                TailList020469b4* list;
                unsigned char* node = (unsigned char*)resources->unknown_ptr_array_3700[3];
                list = (TailList020469b4*)resources->fieldTaskQueue_;
                FieldTask_InitEnterZone(node, 0);
                AppendNodeToTail(list, (TailNode020469b4*)node);
                grotto->unknown_260_[2] = 0;
                func_ov017_021bef84(self);
                self->complete = 1;
            } else {
#if defined(jpn)
                sprintf(var5, data_ov017_021d86c6, var4->GetPopupName());
                func_0204500c(var2, var5, 0);
#else
                sprintf(var5, data_ov017_021d7eb2, var4->GetPopupName());
                func_0204500c(var2, var5, 0, 256);
#endif
                var2->unknown_19b8_ = 1;
                var2->unknown_19af_ = 0;
#if defined(jpn)
                func_02043270(var2, (256-var2->unknown_918_)/2, 64, var2->unknown_918_, 30);
#else
                func_02042b98(var2, (256-var2->unknown_918_)/2, 64, var2->unknown_918_, 30);
#endif
                long long var13 = var2->unknown_1858_.unknown1_0_;
                int var14 = (int)var13;
                int var15 = (int)(var13 >> 32) + 3;
                var2->unknown_1858_.unknown_0_ = var14;
                var2->unknown_1858_.unknown_4_ = var15;
                var2->unknown_9a4_ = 1;
                var2->unknown_998_ = 1;
                arg0->unknown_38_ = 3;
            }
        }
    } else if (self->state == 3 && controller->field9a0 == 0) {
        MessageSystem_Reset((char*)controller);
        GameObject_EnableControl(game->GetLeader());
        FontBankLoader* music = FontBankLoader_GetInstance();
        BlankFunction02094b38(music, 0x1f9);
        FontBankLoader_CancelLoads(music);
        func_ov017_021bef84(self);
        self->complete = 1;
    }
}
