#include <globaldefs.h>

struct Struct_0203f008_2;
struct Struct_02040468;
extern "C" struct Struct_0203f008_2* func_02040468(struct Struct_02040468* list, int index);

extern "C" void* func_0203f1c8(unsigned char* obj, unsigned int index);

struct Struct_0203f2b0 {
    char pad0[0x10];
    unsigned int* field10;
};

struct Struct_0203f2b0_2;
struct Struct_0203f2b0_3 {
    char pad0[8];
    unsigned int len;
    void* unknown_c_;
};
struct Struct_0203f2b0_4 {
    char pad0[4];
    unsigned short unknown_4_;
    char pad1[2];
    struct Struct_0203f2b0_3* records;
};
extern "C" struct Struct_0203f2b0_4* func_0203f354(struct Struct_0203f2b0_2* list, unsigned int index);

void CleanInvalidateCacheRange(const void* where, unsigned int len);

struct Struct_0203f2b0_5 {
    struct Struct_02040468* list;
    char pad1[0x28 - 4];
    short field28;
    char pad2[0x30 - 0x2a];
    int unknown_30_;
    int field34;
    char pad3[0x44 - 0x38];
    int field44;
    int field48;
};

// USA: func_0203f2b0
extern "C" ARM void func_0203f2b0(struct Struct_0203f2b0_5* self) {
    int index = self->field28;
    if (index < 0) return;
    if (self->field34 == self->field48 && self->unknown_30_ == self->field44) return;

    struct Struct_0203f008_2* element = func_02040468(self->list, index);
    if (element == 0) return;

    struct Struct_0203f2b0* stride = (struct Struct_0203f2b0*)func_0203f1c8((unsigned char*)element + 0x10, self->unknown_30_);
    if (stride == 0) return;

    unsigned int idx2 = stride->field10[self->field34];
    struct Struct_0203f2b0_4* entry = func_0203f354((struct Struct_0203f2b0_2*)((char*)element + 0x10), idx2);
    if (entry == 0 || entry->records == 0) return;

    struct Struct_0203f2b0_3* rec = entry->records;
    int i;
    for (i = 0; i < entry->unknown_4_; i++, rec++) {
        CleanInvalidateCacheRange(rec->unknown_c_, rec->len);
    }
}
