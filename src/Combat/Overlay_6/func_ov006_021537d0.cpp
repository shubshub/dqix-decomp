#include <globaldefs.h>

struct Struct_ov006_021537d0 {
    short id_;
    short item_;
    short ingredients_[3];
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 4;
    unsigned short unknown_b_0_ : 4;
    unsigned short unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 10;
    unsigned int kind_ : 8;
    unsigned int unknown_f_4_ : 4;
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int unknown_12_4_ : 2;
    unsigned int unknown_12_6_ : 1;
    unsigned int unknown_12_7_ : 9;
    short unknown_14_;
    short unk_16;
    short unknown_18_;
    short unk_1a;
    Struct_ov006_021537d0* unknown_1c_;
};

struct Struct_02071d60;

extern "C" Struct_ov006_021537d0* func_02071d60(Struct_02071d60* list, int key);

struct Struct_ov006_021537c8 {
    Struct_02071d60* table_;
    short** items_;
    unsigned char** unknown_8_;
    unsigned short* sizes_;
    Struct_ov006_021537d0* unknown_10_;
    short unknown_14_[3];
    signed char category_[3];
    void* unknown_20_;
    unsigned short unknown_24_;
};

// USA: func_ov006_021537d0
extern "C" ARM int func_ov006_021537d0(Struct_ov006_021537c8* self, short id) {
    if (self->sizes_ == 0)
        return 0;
    self->unknown_10_ = func_02071d60(self->table_, id);
    if (self->unknown_10_ == 0)
        return 0;
    if (self->unknown_10_->ingredients_[0] > 0 && self->unknown_10_->unknown_a_0_ != 0) {
        self->unknown_14_[0] = -1;
        self->category_[0] = -1;
        for (signed char category = 0; category < 9; category++) {
            short* items = self->items_[category];
            unsigned short size = self->sizes_[category];
            for (unsigned short i = 0; i < size; i++) {
                if (self->unknown_10_->ingredients_[0] == items[i]) {
                    self->unknown_14_[0] = i;
                    self->category_[0] = category;
                    break;
                }
            }
        }
        if (self->unknown_14_[0] < 0)
            return 0;
        if (self->unknown_10_->unknown_a_0_ > self->unknown_8_[self->category_[0]][self->unknown_14_[0]])
            return 0;
    }
    if (self->unknown_10_->ingredients_[1] > 0 && self->unknown_10_->unknown_a_4_ != 0) {
        self->unknown_14_[1] = -1;
        self->category_[1] = -1;
        for (signed char category = 0; category < 9; category++) {
            short* items = self->items_[category];
            unsigned short size = self->sizes_[category];
            for (unsigned short i = 0; i < size; i++) {
                if (self->unknown_10_->ingredients_[1] == items[i]) {
                    self->unknown_14_[1] = i;
                    self->category_[1] = category;
                    break;
                }
            }
        }
        if (self->unknown_14_[1] < 0)
            return 0;
        if (self->unknown_10_->unknown_a_4_ > self->unknown_8_[self->category_[1]][self->unknown_14_[1]])
            return 0;
    }
    if (self->unknown_10_->ingredients_[2] > 0 && self->unknown_10_->unknown_b_0_ != 0) {
        self->unknown_14_[2] = -1;
        self->category_[2] = -1;
        for (signed char category = 0; category < 9; category++) {
            short* items = self->items_[category];
            unsigned short size = self->sizes_[category];
            for (unsigned short i = 0; i < size; i++) {
                if (self->unknown_10_->ingredients_[2] == items[i]) {
                    self->unknown_14_[2] = i;
                    self->category_[2] = category;
                    break;
                }
            }
        }
        if (self->unknown_14_[2] < 0)
            return 0;
        if (self->unknown_10_->unknown_b_0_ > self->unknown_8_[self->category_[2]][self->unknown_14_[2]])
            return 0;
    }
    return 1;
}
