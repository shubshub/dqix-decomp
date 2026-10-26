#include <globaldefs.h>
#include "Graphics/itcm/VRAMStaging.h"

struct Struct_02040468;
struct Struct_0203f430_5 {
    char pad0[0x1c];
    int field1c;
    void* field20;
    int field24;
};
extern "C" struct Struct_0203f430_5* func_02040468(struct Struct_02040468* list, int index);

struct Struct_0203f430_2 {
    char pad0[0x10];
    unsigned int* field10;
};
extern "C" void* func_0203f1c8(unsigned char* obj, unsigned int index);

struct Struct_0203f430_3 {
    char pad0[8];
    unsigned int len;
    void* unknown_c_;
};

struct Struct_0203f2b0_2;
struct Struct_0203f430_4 {
    char pad0[4];
    unsigned short unknown_4_;
    char pad1[2];
    struct Struct_0203f430_3* records;
    int fieldC;
    const void* field10;
};
extern "C" struct Struct_0203f430_4* func_0203f354(struct Struct_0203f2b0_2* list, unsigned int index);

void CleanInvalidateCacheRange(const void* where, unsigned int len);
int CancelVRAMStagingOperation(int value);
int StageMemoryToVRAM(VRAMSubregion subregion, const void* data, unsigned int offset,
    unsigned int length, bool highPriority, bool allocateStagingSpace);

struct Struct_0203f430 {
    struct Struct_02040468* list;
    char pad1[0x28 - 4];
    short field28;
    char pad2[0x30 - 0x2a];
    int unknown_30_;
    int field34;
    char pad3[0x44 - 0x38];
    int field44;
    int field48;
    int field4c;
    char pad4[0x58 - 0x50];
    short unknown_58_;
    short unknown_5a_;
};

// USA: func_0203f430
extern "C" ARM void func_0203f430(struct Struct_0203f430* self) {
    struct Struct_0203f430_5* element = func_02040468(self->list, self->field28);
    if (element == 0) return;

    struct Struct_0203f430_2* stride = (struct Struct_0203f430_2*)func_0203f1c8((unsigned char*)element + 0x10, self->unknown_30_);
    if (stride == 0) return;

    unsigned int idx2 = stride->field10[self->field34];
    struct Struct_0203f430_4* entry = func_0203f354((struct Struct_0203f2b0_2*)((char*)element + 0x10), idx2);
    if (entry == 0 || entry->records == 0) return;

    struct Struct_0203f430_3* rec = entry->records;
    int i;
    for (i = 0; i < entry->unknown_4_; i++, rec++) {
        CleanInvalidateCacheRange(rec->unknown_c_, rec->len);
    }

    CleanInvalidateCacheRange(element->field20, element->field1c << 1);

    if (entry->unknown_4_ != 0) {
        CancelVRAMStagingOperation(self->unknown_58_);
        self->unknown_58_ = StageMemoryToVRAM(VRAMSubregion_TextureImage, entry->field10, self->field4c, entry->fieldC, false, false);
    }
    CancelVRAMStagingOperation(self->unknown_5a_);
    self->unknown_5a_ = StageMemoryToVRAM(VRAMSubregion_TexturePalette, element->field20, element->field24, element->field1c << 1, false, false);
    self->field44 = self->unknown_30_;
    self->field48 = self->field34;
}
