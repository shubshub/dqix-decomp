#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

struct AllocatorUnion;
struct Struct_020979c0;

extern "C" void func_020a0cc4(unsigned int arg0);
extern "C" void func_020a0c0c(void);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void InitStruct020979c0(Obj020979c0* obj, unsigned char flag);
extern "C" void func_020a1940(unsigned int id);
void PushInputLogB_020a1ef0(int value);
void PopStack1AndTrigger_020a1f4c(int value);
extern "C" void func_ov014_02186a70(void* obj);
extern "C" void func_ov014_021868b8(void* obj, SafeAllocator* allocator);
extern "C" int func_ov014_02186bc8(void* obj, unsigned int tick);
extern "C" void func_ov014_02186b30(void* obj);
extern "C" int func_02097a04(void* obj);
extern "C" void func_02097b34(void* obj);
extern char g_mainAllocator;

struct Struct_ov017_021c03a4 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[8 - 2];
    SafeAllocator unknown_8_;
    void* unknown_1c_;
    void* unknown_20_;
    unsigned char unknown_24_;
};

extern "C" void func_ov017_021c0364(Struct_ov017_021c03a4* arg0);

// Overlay 17, originally func_ov017_021c03a4 (USA/EUR 0x021c03a4, JPN 0x021c094c)
extern "C" ARM void FieldTask_OpenMonsterList(Task021c03a4* task) {
    if (task->step == 0) {
        *(unsigned short*)0x4000304 |= 0x8000;
        func_020a0cc4(0x3f000);
        void* buffer = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x3f000);
        if (buffer == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var0, 0x3f000);
        arg0->unknown_8_.Reset();
        arg0->unknown_1c_ = arg0->unknown_8_.Allocate(0x20);
        arg0->unknown_20_ = arg0->unknown_8_.Allocate(0x194);
        if (arg0->unknown_1c_ == NULL || arg0->unknown_20_ == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        func_020979c0((Struct_020979c0*)arg0->unknown_1c_, 1);
        func_020a1940(OVERLAY_ID(14));
        func_020a1ef0(1);
        func_ov014_02186a70(arg0->unknown_20_);
        func_ov014_021868b8(arg0->unknown_20_, &arg0->unknown_8_);
        arg0->unknown_24_++;
        return;
    }
    if (arg0->unknown_24_ == 1) {
        if (func_02097a04(arg0->unknown_1c_)) {
            arg0->unknown_24_++;
        }
        return;
    }
    if (arg0->unknown_24_ == 2) {
        if (func_ov014_02186bc8(arg0->unknown_20_, GameState::GetInstance()->GetTickCount())) {
            arg0->unknown_24_++;
        }
        return;
    }
    if (arg0->unknown_24_ != 3) {
        return;
    }
    func_ov014_02186b30(arg0->unknown_20_);
    func_02097b34(arg0->unknown_1c_);
    func_ov017_021c0364(arg0);
    func_020a0c0c();
    func_020a1f4c(1);
    arg0->unknown_1_ = 1;
}
