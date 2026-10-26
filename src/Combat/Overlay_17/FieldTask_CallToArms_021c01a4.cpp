#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" unsigned char* GameState_GetFollowCamera(char* obj);
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void func_020a28b0(unsigned char* obj, int mask);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
struct Struct_02092aa4;
extern "C" void func_02092aa4(Struct_02092aa4*, int);
extern "C" void func_02092a74(SafeAllocator* self, SafeAllocator* src);
extern "C" int func_020a0cc4(int id);
extern "C" void ROMFilesystem_InitFileTables();
extern "C" int func_02092bcc(struct Struct_02092aa4* obj, int delta);
extern "C" void func_02092b34(struct Struct_02092aa4* obj);

extern AllocatorUnion g_mainAllocator;
extern struct Struct_02092aa4* data_ov017_021d8474;

struct Obj021c01a4 {
    unsigned char byte0;
    unsigned char done;
    unsigned char pad2[6];
    SafeAllocator alloc;
    int state;
    signed char unknown_20_;
};

extern "C" void func_ov017_021c0160(struct Obj021c01a4* self);

// Overlay 17, originally func_ov017_021c01a4 (USA/EUR 0x021c01a4, JPN 0x021c074c)
extern "C" ARM void FieldTask_CallToArms(struct Obj021c01a4* self) {
    GameState* gs = GameState::GetInstance();
    GameObject* obj = gs->GetLeader();
    GameObject_DisableControl((struct Obj020397cc*)obj, 1);
    unsigned char* flags = GameState_GetFollowCamera((char*)gs);
    func_020a28a0(flags, 1);

    if (self->state == 0) {
        func_020a0cc4(0xc3c);
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xc3c);
        if (buf == NULL) {
            ROMFilesystem_InitFileTables();
            self->done = 1;
            return;
        }
        self->alloc.CreateTypeA(buf, 0xc3c);
        self->alloc.Reset();
        data_ov017_021d8474 = (struct Struct_02092aa4*)self->alloc.Allocate(0x3c);
        if (data_ov017_021d8474 == NULL) {
            ROMFilesystem_InitFileTables();
            self->done = 1;
            return;
        }
        func_02092aa4(data_ov017_021d8474, self->unknown_20_);
        func_02092a74((SafeAllocator*)data_ov017_021d8474, &self->alloc);
        self->state++;
    } else if (self->state == 1) {
        if (func_02092bcc(data_ov017_021d8474, GameState::GetInstance()->GetTickCount())) {
            self->state++;
        }
    } else if (self->state == 2) {
        func_02092b34(data_ov017_021d8474);
        self->state++;
    } else if (self->state == 3) {
        func_ov017_021c0160(self);
        func_020a28b0(flags, 1);
        GameObject_EnableControl(obj);
        self->state++;
        self->done = 1;
        ROMFilesystem_InitFileTables();
    }
}
