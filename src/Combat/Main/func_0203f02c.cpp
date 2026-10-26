#include <globaldefs.h>
#include "Graphics/itcm/VRAMStaging.h"

extern "C" int func_0204027c(void* list, int a, int b, int c, int d);
extern "C" int NNS_GfdAllocFrmTexVram(int a, int b, int c);

extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);

struct Struct_02040468;
struct Struct_0203f02c {
    char pad0[0x1c];
    int unknown_1c_;
    void* unknown_20_;
    int unknown_24_;
    char pad1[0xc];
    int field0x34;
};
extern "C" struct Struct_0203f02c* func_02040468(struct Struct_02040468* list, int index);

int CancelVRAMStagingOperation(int value);
int StageMemoryToVRAM(VRAMSubregion subregion, const void* data, unsigned int offset,
    unsigned int length, bool highPriority, bool allocateStagingSpace);

struct Struct_0203d028_14 {
    struct Struct_02040468* list;
    char pad1[0x24];
    short unknown_28_;
    char pad2[0x22];
    int unknown_4c_;
    char pad3[0xa];
    short unknown_5a_;
};

// USA: func_0203f02c
extern "C" ARM void func_0203f02c(struct Struct_0203d028_14* obj, int param1, int param2, char* param3, int arg4, int arg5) {
    VramState_Restore(param3);

    int result;
    if (arg4) {
        result = func_0204027c(obj->list, param1, param2, arg4, arg5);
    } else {
        result = func_0204027c(obj->list, param1, param2, 0, 0);
    }
    obj->unknown_28_ = result;

    struct Struct_0203f02c* element = func_02040468(obj->list, obj->unknown_28_);
    if (element != NULL) {
        int v = NNS_GfdAllocFrmTexVram(element->field0x34, 0, 0);
        obj->unknown_4c_ = ((unsigned int)v << 16) >> 13;
        CancelVRAMStagingOperation(obj->unknown_5a_);
        obj->unknown_5a_ = StageMemoryToVRAM(VRAMSubregion_TexturePalette, element->unknown_20_, element->unknown_24_, element->unknown_1c_ << 1, false, false);
    }

    VramState_Save(param3);
}
