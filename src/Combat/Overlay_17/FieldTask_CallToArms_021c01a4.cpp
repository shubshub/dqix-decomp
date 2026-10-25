#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
unsigned char* GetFieldIfFlag4_020100f8(char* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void GameObject_EnableControl(void* obj);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
struct Obj02092aa4;
void InitObj02092aa4(Obj02092aa4*, int);
void CreateTypeAFromAllocator_02092a74(SafeAllocator* self, SafeAllocator* src);
extern "C" int func_020a0cc4(int id);
extern "C" void func_020a0c0c();
extern "C" int func_02092bcc(struct Struct_02092aa4* arg0, int arg1);
extern "C" void func_02092b34(struct Struct_02092aa4* arg0);

extern AllocatorUnion g_mainAllocator;
extern struct Obj02092aa4* data_ov017_021d8474;

struct Struct_ov017_021c01a4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    SafeAllocator unknown_8_;
    int unknown_1c_;
    signed char unknown_20_;
};

extern "C" void func_ov017_021c0160(struct Struct_ov017_021c01a4* arg0);

// Overlay 17, originally func_ov017_021c01a4 (USA/EUR 0x021c01a4, JPN 0x021c074c)
extern "C" ARM void FieldTask_CallToArms(struct Obj021c01a4* self) {
    GameState* gs = GameState::GetInstance();
    GameObject* obj = gs->GetUnknownGameObject();
    GameObject_DisableControl((struct Obj020397cc*)obj, 1);
    unsigned char* flags = GetFieldIfFlag4_020100f8((char*)gs);
    SetFlagsAt0x244_020a28a0(flags, 1);

    if (arg0->unknown_1c_ == 0) {
        func_020a0cc4(0xc3c);
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xc3c);
        if (buf == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var3, 0xc3c);
        arg0->unknown_8_.Reset();
        data_ov017_021d8474 = (struct Struct_02092aa4*)arg0->unknown_8_.Allocate(0x3c);
        if (data_ov017_021d8474 == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        func_02092aa4(data_ov017_021d8474, arg0->unknown_20_);
        func_02092a74((SafeAllocator*)data_ov017_021d8474, &arg0->unknown_8_);
        arg0->unknown_1c_++;
    } else if (arg0->unknown_1c_ == 1) {
        if (func_02092bcc(data_ov017_021d8474, GameState::GetInstance()->GetTickCount())) {
            arg0->unknown_1c_++;
        }
    } else if (arg0->unknown_1c_ == 2) {
        func_02092b34(data_ov017_021d8474);
        self->state++;
    } else if (self->state == 3) {
        func_ov017_021c0160(self);
        ClearFlagBits_020a28b0(flags, 1);
        GameObject_EnableControl(obj);
        self->state++;
        self->done = 1;
        func_020a0c0c();
    }
}
