#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021caea8 {
    unsigned char unknown_0_[2];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char reserved : 4;
    unsigned char unknown_b_[0x18 - 0xb];
};
struct Struct_ov017_021caea8_4 {
    unsigned char field_0;
    unsigned char unknown_1_0_ : 4;
    unsigned char count : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[2];
    Struct_ov017_021caea8 entries[3];
};
struct Struct_ov017_021caea8_5 {
    unsigned char unknown_0_[0x36];
    unsigned short value;
    unsigned char unknown_38_[0x5c - 0x38];
    unsigned char primary[20];
    unsigned char unknown_70_[0x7f - 0x70];
    unsigned char unknown_7f_[20];
    unsigned char unknown_93_[0xa4 - 0x93];
};
struct Struct_ov017_021caea8_6 {
    unsigned char unknown_0_[8];
    unsigned short id;
    unsigned char unknown_a_[0x158 - 0xa];
    Struct_ov017_021caea8_5 elements[8];
};
struct Struct_ov017_021caea8_7 {
    unsigned int s0 : 3, s1 : 3, s2 : 3, s3 : 3, unknown_1_4_ : 3;
    unsigned int unknown_1_7_ : 3, unknown_2_2_ : 3, unknown_2_5_ : 3, unknown_3_0_ : 3, unknown_3_3_ : 3;
};
struct Struct_ov017_021caea8_2 {
    unsigned short id;
    unsigned short slot;
    Struct_ov017_021caea8_7 low;
    Struct_ov017_021caea8_7 high;
    unsigned short value;
    unsigned char primary;
    unsigned char unknown_f_;
};
struct Struct_ov017_021caea8_3 {
    unsigned char tag;
    unsigned char unknown_1_[3];
    Struct_ov017_021caea8_2 fields;
};
extern "C" void* func_ov017_021b8478(void*);
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021caea8
extern "C" ARM void func_ov017_021caea8(Struct_ov017_021caea8_4* self) {
    GameState::GetInstance();
    GameResources* resources = GetGameResources();
    Struct_ov017_021caea8_6* state = (Struct_ov017_021caea8_6*)func_ov017_021b8478(resources->unknown_ptr_3718);
    void* data = LinkMessageQueue_GetInstance();
    for (int i = 0; i < self->count; i++) {
        Struct_ov017_021caea8* entry = &self->entries[i];
        Struct_ov017_021caea8_3 first;
        Struct_ov017_021caea8_3 second;
        for (int j = 0; j < entry->count; j++) {
            unsigned char id = entry->ids[j];
            if (id >= 8) continue;
            Struct_ov017_021caea8_5* element = &state->elements[id];
            Struct_ov017_021caea8_2* fields = &first.fields;
            first.tag = 0x60;
            fields->id = state->id;
            fields->slot = entry->ids[j] + 0xc0;
            fields->primary = 1;
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
            fields->high.unknown_1_7_ = element->primary[15];
            fields->high.unknown_2_2_ = element->primary[16];
            fields->high.unknown_2_5_ = element->primary[17];
            fields->high.unknown_3_0_ = element->primary[18];
            fields->high.unknown_3_3_ = element->primary[19];
            fields->value = element->value;
            func_0205e330(data, &first, 0);
            fields = &second.fields;
            second.tag = 0x60;
            fields->id = state->id;
            fields->slot = entry->ids[j] + 0xc0;
            fields->primary = 0;
            fields->low.s0 = element->unknown_7f_[0];
            fields->low.s1 = element->unknown_7f_[1];
            fields->low.s2 = element->unknown_7f_[2];
            fields->low.s3 = element->unknown_7f_[3];
            fields->low.unknown_1_4_ = element->unknown_7f_[4];
            fields->low.unknown_1_7_ = element->unknown_7f_[5];
            fields->low.unknown_2_2_ = element->unknown_7f_[6];
            fields->low.unknown_2_5_ = element->unknown_7f_[7];
            fields->low.unknown_3_0_ = element->unknown_7f_[8];
            fields->low.unknown_3_3_ = element->unknown_7f_[9];
            fields->high.s0 = element->unknown_7f_[10];
            fields->high.s1 = element->unknown_7f_[11];
            fields->high.s2 = element->unknown_7f_[12];
            fields->high.s3 = element->unknown_7f_[13];
            fields->high.unknown_1_4_ = element->unknown_7f_[14];
            fields->high.unknown_1_7_ = element->unknown_7f_[15];
            fields->high.unknown_2_2_ = element->unknown_7f_[16];
            fields->high.unknown_2_5_ = element->unknown_7f_[17];
            fields->high.unknown_3_0_ = element->unknown_7f_[18];
            fields->high.unknown_3_3_ = element->unknown_7f_[19];
            func_0205e330(data, &second, 0);
        }
    }
}
