#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_0215f3d8 func_ov006_021607f8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_ov006_02157a60 {
    char unk_0[R(0x40, 0x48)];
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
};

extern "C" const unsigned short data_ov006_0215fffe[9];

// USA: func_ov006_02158fd8
extern "C" ARM void func_ov006_02158fd8(Struct_ov006_02157a60* self, unsigned int category, short item, unsigned char count) {
    if (item <= 0 || count == 0)
        return;
    short* items = self->items_[category];
    unsigned char* counts = self->unknown_4c_[category];
    unsigned short* size = &self->sizes_[category];
    unsigned short sizes[9];
    memcpy(sizes, data_ov006_0215fffe, sizeof(sizes));
    unsigned short capacity = sizes[category];
    for (unsigned short i = 0; i < capacity; i++) {
        short entry = items[i];
        if (entry <= 0) {
            items[i] = item;
            counts[i] = count;
            (*size)++;
            return;
        }
        if (entry == item) {
            counts[i] += count;
            return;
        }
    }
}
