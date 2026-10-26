#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021cb5f8 {
    unsigned char unknown_0_[2];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char reserved : 4;
    unsigned char unknown_b_[0x18 - 0xb];
};
struct Struct_ov017_021cb5f8_5 {
    unsigned char field_0;
    unsigned char unknown_1_0_ : 4;
    unsigned char count : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[2];
    Struct_ov017_021cb5f8 entries[3];
};
struct Struct_ov017_021cb5f8_6 {
    unsigned char unknown_0_[0x70];
    unsigned char primary[15];
    unsigned char unknown_7f_[0x93 - 0x7f];
    unsigned char unknown_93_[15];
    unsigned char unknown_a2_[0xa4 - 0xa2];
};
struct Struct_ov017_021cb5f8_7 {
    unsigned char unknown_0_[8];
    unsigned short id;
    unsigned char unknown_a_[0x158 - 0xa];
    Struct_ov017_021cb5f8_6 elements[8];
};
struct Struct_ov017_021cb5f8_8 {
    unsigned int s0 : 3, s1 : 3, s2 : 3, s3 : 3, unknown_1_4_ : 3;
    unsigned int unknown_1_7_ : 3, unknown_2_2_ : 3, unknown_2_5_ : 3, unknown_3_0_ : 3, unknown_3_3_ : 3;
};
struct Struct_ov017_021cb5f8_2 {
    unsigned int s0 : 3, s1 : 3, s2 : 3, s3 : 3, unknown_1_4_ : 4;
};
struct Struct_ov017_021cb5f8_3 {
    unsigned short id;
    unsigned short slot;
    Struct_ov017_021cb5f8_8 low;
    Struct_ov017_021cb5f8_2 high;
    unsigned char mode;
};
struct Struct_ov017_021cb5f8_4 {
    unsigned char tag;
    unsigned char unknown_1_[3];
    Struct_ov017_021cb5f8_3 fields;
};
extern "C" void* func_ov017_021b8478(void*);
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021cb5f8
extern "C" ARM void func_ov017_021cb5f8(Struct_ov017_021cb5f8_5* self) {
    GameState::GetInstance();
    GameResources* resources = GetGameResources();
    Struct_ov017_021cb5f8_7* state = (Struct_ov017_021cb5f8_7*)func_ov017_021b8478(resources->unknown_ptr_3718);
    void* data = LinkMessageQueue_GetInstance();
    for (int i = 0; i < self->count; i++) {
        Struct_ov017_021cb5f8* entry = &self->entries[i];
        Struct_ov017_021cb5f8_4 first;
        Struct_ov017_021cb5f8_4 second;
        for (int j = 0; j < entry->count; j++) {
            unsigned char id = entry->ids[j];
            if (id >= 8) continue;
            Struct_ov017_021cb5f8_6* element = &state->elements[id];
            Struct_ov017_021cb5f8_3* fields = &first.fields;
            first.tag = 0x61;
            fields->id = state->id;
            fields->slot = entry->ids[j] + 0xc0;
            fields->mode = 1;
            fields->low.s0 = element->primary[0];
            fields->low.s1 = element->primary[1];
            fields->low.s2 = element->primary[2];
            fields->low.s3 = element->primary[3];
            fields->low.unknown_1_4_ = element->primary[4];
            fields->low.unknown_1_7_ = element->primary[5];
            fields->low.unknown_2_2_ = element->primary[6];
            fields->low.unknown_2_5_ = element->primary[7];
            fields->low.unknown_3_0_ = element->primary[8];
            fields->low.unknown_3_3_ = element->primary[9];
            fields->high.s0 = element->primary[10];
            fields->high.s1 = element->primary[11];
            fields->high.s2 = element->primary[12];
            fields->high.s3 = element->primary[13];
            fields->high.unknown_1_4_ = element->primary[14];
            func_0205e330(data, &first, 0);
            fields = &second.fields;
            second.tag = 0x61;
            fields->id = state->id;
            fields->slot = entry->ids[j] + 0xc0;
            fields->mode = 0;
            fields->low.s0 = element->unknown_93_[0];
            fields->low.s1 = element->unknown_93_[1];
            fields->low.s2 = element->unknown_93_[2];
            fields->low.s3 = element->unknown_93_[3];
            fields->low.unknown_1_4_ = element->unknown_93_[4];
            fields->low.unknown_1_7_ = element->unknown_93_[5];
            fields->low.unknown_2_2_ = element->unknown_93_[6];
            fields->low.unknown_2_5_ = element->unknown_93_[7];
            fields->low.unknown_3_0_ = element->unknown_93_[8];
            fields->low.unknown_3_3_ = element->unknown_93_[9];
            fields->high.s0 = element->unknown_93_[10];
            fields->high.s1 = element->unknown_93_[11];
            fields->high.s2 = element->unknown_93_[12];
            fields->high.s3 = element->unknown_93_[13];
            fields->high.unknown_1_4_ = element->unknown_93_[14];
            func_0205e330(data, &second, 0);
        }
    }
}
