#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021caea8 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    unsigned char unknown_b_[0x18 - 0xb];
};
struct Struct_ov017_021caea8_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[2];
    Struct_ov017_021caea8 unknown_4_[3];
};
struct Struct_ov017_021caea8_5 {
    unsigned char unknown_0_[0x36];
    unsigned short unknown_36_;
    unsigned char unknown_38_[0x5c - 0x38];
    unsigned char unknown_5c_[20];
    unsigned char unknown_70_[0x7f - 0x70];
    unsigned char unknown_7f_[20];
    unsigned char unknown_93_[0xa4 - 0x93];
};
struct Struct_ov017_021caea8_6 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
    unsigned char unknown_a_[0x158 - 0xa];
    Struct_ov017_021caea8_5 unknown_158_[8];
};
struct Struct_ov017_021caea8_7 {
    unsigned int unknown_0_0_ : 3, unknown_0_3_ : 3, unknown_0_6_ : 3, unknown_1_1_ : 3, unknown_1_4_ : 3;
    unsigned int unknown_1_7_ : 3, unknown_2_2_ : 3, unknown_2_5_ : 3, unknown_3_0_ : 3, unknown_3_3_ : 3;
};
struct Struct_ov017_021caea8_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    Struct_ov017_021caea8_7 unknown_4_;
    Struct_ov017_021caea8_7 unknown_8_;
    unsigned short unknown_c_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};
struct Struct_ov017_021caea8_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021caea8_2 unknown_4_;
};
extern "C" void* func_ov017_021b8478(void*);
void* LinkMessageQueue_GetInstance();
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021caea8
extern "C" ARM void func_ov017_021caea8(Struct_ov017_021caea8_4* arg0) {
    GameState::GetInstance();
    GameResources* resources = GetGameResources();
    StatState021caea8* state = (StatState021caea8*)func_ov017_021b8478(resources->unknown_ptr_3718);
    void* data = LinkMessageQueue_GetInstance();
    for (int i = 0; i < self->count; i++) {
        StatEntry021caea8* entry = &self->entries[i];
        StatMessage021caea8 first;
        StatMessage021caea8 second;
        for (int j = 0; j < entry->count; j++) {
            unsigned char id = entry->ids[j];
            if (id >= 8) continue;
            StatElement021caea8* element = &state->elements[id];
            StatFields021caea8* fields = &first.fields;
            first.tag = 0x60;
            fields->id = state->id;
            fields->slot = entry->ids[j] + 0xc0;
            fields->primary = 1;
            fields->low.s0 = element->primary[0];
            fields->low.s1 = element->primary[1];
            fields->low.s2 = element->primary[2];
            fields->low.s3 = element->primary[3];
            fields->low.s4 = element->primary[4];
            fields->low.s5 = element->primary[5];
            fields->low.s6 = element->primary[6];
            fields->low.s7 = element->primary[7];
            fields->low.s8 = element->primary[8];
            fields->low.s9 = element->primary[9];
            fields->high.s0 = element->primary[10];
            fields->high.s1 = element->primary[11];
            fields->high.s2 = element->primary[12];
            fields->high.s3 = element->primary[13];
            fields->high.s4 = element->primary[14];
            fields->high.s5 = element->primary[15];
            fields->high.s6 = element->primary[16];
            fields->high.s7 = element->primary[17];
            fields->high.s8 = element->primary[18];
            fields->high.s9 = element->primary[19];
            fields->value = element->value;
            func_0205e330(data, &first, 0);
            fields = &second.fields;
            second.tag = 0x60;
            fields->id = state->id;
            fields->slot = entry->ids[j] + 0xc0;
            fields->primary = 0;
            fields->low.s0 = element->secondary[0];
            fields->low.s1 = element->secondary[1];
            fields->low.s2 = element->secondary[2];
            fields->low.s3 = element->secondary[3];
            fields->low.s4 = element->secondary[4];
            fields->low.s5 = element->secondary[5];
            fields->low.s6 = element->secondary[6];
            fields->low.s7 = element->secondary[7];
            fields->low.s8 = element->secondary[8];
            fields->low.s9 = element->secondary[9];
            fields->high.s0 = element->secondary[10];
            fields->high.s1 = element->secondary[11];
            fields->high.s2 = element->secondary[12];
            fields->high.s3 = element->secondary[13];
            fields->high.s4 = element->secondary[14];
            fields->high.s5 = element->secondary[15];
            fields->high.s6 = element->secondary[16];
            fields->high.s7 = element->secondary[17];
            fields->high.s8 = element->secondary[18];
            fields->high.s9 = element->secondary[19];
            func_0205e330(data, &second, 0);
        }
    }
}
