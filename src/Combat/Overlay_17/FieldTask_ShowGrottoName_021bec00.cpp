#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/Brightness.h"
struct Obj020397cc;
struct TailList020469b4;
struct TailNode020469b4;
struct ZoneState021bec00 {
#if defined(jpn)
    char padding[0x240c];
#else
    char padding[0x23ec];
#endif
    ActiveGrottoClass grotto;
};
union Struct_ov017_021bec00_4 { struct { int x, y; }; long long packed; };
struct PopupController021bec00 {
#if defined(jpn)
    char padding0[0x7e8];
#else
    char padding0[0x918];
#endif
    short width;
    char unknown_91a_[0x998-0x91a];
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_, unknown_9a4_;
    char unknown_9a8_[0x1858-0x9a8];
    Struct_ov017_021bec00_4 offset;
#if defined(jpn)
    char unknown_1730_[0x17de - 0x1730];
#else
    char unknown_1860_[0x19ae - 0x1860];
#endif
    unsigned char unknown_19ae_, unknown_19af_;
    char unknown_19b0_[8];
    unsigned char unknown_19b8_;
};
struct GrottoTransitionData {
    unsigned short id;
    char padding2[2];
    unsigned char flag4;
    char unknown_5_[2];
    unsigned char flag7, flag8, unknown_9_;
    char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    int x, y, z;
    short field1c, unknown_1e_;
    int unknown_20_[4];
    char unknown_30_[0x6c-0x30];
    short unknown_6c_;
    char unknown_6e_[2];
};
struct PopupState021bec00 {
    unsigned char type, unknown_1_;
    char padding2[0x38-2];
    int state;
    char unknown_3c_[4];
    int task;
    SafeAllocator allocator;
    char script[0xa4];
};
extern "C" void LinkSession_GetInstance();
extern "C" ZoneState021bec00* Zone3D_GetInstance();
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void KeyTable_Load(void*, SafeAllocator*, void*, unsigned int);
#if defined(jpn)
extern "C" void func_0204500c(PopupController021bec00*, char*, int);
#else
extern "C" void func_0204500c(PopupController021bec00*, char*, int, int);
#endif
#if defined(jpn)
extern "C" void func_02043270(PopupController021bec00*, int, int, int, int);
#else
extern "C" void func_02042b98(PopupController021bec00*, int, int, int, int);
#endif
extern "C" void func_ov017_021bef84(PopupState021bec00*);
extern "C" PopupController021bec00* MessageSystem_GetInstance();
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" GrottoTransitionData* GameState_GetZoneTransition(GameState*);
extern "C" void FieldTask_InitEnterZone(unsigned char*, int);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" void MessageSystem_Reset(char*);
extern "C" void GameObject_EnableControl(void*);
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
    controller->unknown_19ae_ = 0;
    if (self->state == 0) {
        GameObject_DisableControl((Obj020397cc*)game->GetLeader(), 1);
        SetFlags04(resources, 0xc0);
        FontBankLoader* music = FontBankLoader_GetInstance();
        func_02094b30(music, 0x203, 0);
        if (func_02094b4c(music)) {
            self->state = 1;
            self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xc00), 0xc00);
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov017_021d86ac, 0);
#else
            self->task = loader->QueueLoadFile(data_ov017_021d7e98, 0);
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
                transition->unknown_9_ = 1;
                transition->unknown_b_ = -1;
                transition->unknown_20_[0] = -1;
                transition->unknown_20_[1] = -1;
                transition->unknown_20_[2] = -1;
                transition->unknown_20_[3] = -1;
                transition->unknown_1e_ = -1;
                transition->unknown_c_ = 0;
                transition->unknown_6c_ = -1;
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
                func_020469b4(list, (TailNode020469b4*)node);
                grotto->unknown_260_[2] = 0;
                func_ov017_021bef84(self);
                self->unknown_1_ = 1;
            } else {
#if defined(jpn)
                sprintf(text, data_ov017_021d86c6, grotto->GetPopupName());
                func_0204500c(controller, text, 0);
#else
                sprintf(text, data_ov017_021d7eb2, grotto->GetPopupName());
                func_0204500c(controller, text, 0, 256);
#endif
                controller->unknown_19b8_ = 1;
                controller->unknown_19af_ = 0;
#if defined(jpn)
                func_02043270(controller, (256-controller->width)/2, 64, controller->width, 30);
#else
                func_02042b98(controller, (256-controller->width)/2, 64, controller->width, 30);
#endif
                long long offset = controller->offset.packed;
                int value = (int)offset;
                int count = (int)(offset >> 32) + 3;
                controller->offset.x = value;
                controller->offset.y = count;
                controller->unknown_9a4_ = 1;
                controller->unknown_998_ = 1;
                self->state = 3;
            }
        }
    } else if (self->state == 3 && controller->unknown_9a0_ == 0) {
        MessageSystem_Reset((char*)controller);
        GameObject_EnableControl(game->GetLeader());
        FontBankLoader* music = FontBankLoader_GetInstance();
        func_02094b38(music, 0x1f9);
        FontBankLoader_CancelLoads(music);
        func_ov017_021bef84(self);
        self->unknown_1_ = 1;
    }
}
