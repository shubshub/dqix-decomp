#include <globaldefs.h>

struct Struct_ov006_021537c8 {
    char unk_0[0x4];
    short** items_;
    unsigned char** unknown_8_;
    unsigned short* sizes_;
};

// USA: func_ov006_021537c8
extern "C" ARM void func_ov006_021537c8(Struct_ov006_021537c8* self, short** items, unsigned char** counts, unsigned short* sizes) {
    self->items_ = items;
    self->unknown_8_ = counts;
    self->sizes_ = sizes;
}
