#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_ov006_021537d0 {
    short id_;
    short item_;
    short ingredients_[3];
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 4;
    unsigned short unknown_b_0_ : 4;
    unsigned short unknown_b_4_ : 4;
};

struct Struct_02071d60;

extern "C" Struct_ov006_021537d0* func_02071d60(Struct_02071d60* list, int key);

struct Struct_ov006_021537c8 {
    Struct_02071d60* table_;
    short** items_;
    unsigned char** unknown_8_;
    unsigned short* sizes_;
};

// USA: func_ov006_02153b9c
extern "C" ARM void func_ov006_02153b9c(Struct_ov006_021537c8* self, short id, unsigned char* arg2) {
    memset(arg2, 0, 3);
    Struct_ov006_021537d0* var0 = func_02071d60(self->table_, id);
    if (var0 == 0)
        return;
    for (int category = 0; category < 9; category++) {
        short* items = self->items_[category];
        unsigned char* counts = self->unknown_8_[category];
        short size = self->sizes_[category];
        for (short i = 0; i < size; i++) {
            short item = items[i];
            if (item > 0) {
                if (item == var0->ingredients_[0])
                    arg2[0] = counts[i];
                else if (item == var0->ingredients_[1])
                    arg2[1] = counts[i];
                else if (item == var0->ingredients_[2])
                    arg2[2] = counts[i];
            }
        }
    }
}
