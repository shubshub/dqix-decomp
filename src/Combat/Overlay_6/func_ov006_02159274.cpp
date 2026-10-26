#include <globaldefs.h>

struct Struct_ov006_02157a60 {
    char unk_0[0x362];
    short unknown_362_;
    short unknown_364_;
    char unknown_366_[0x22];
    unsigned char page_;
};

struct Struct_ov006_021591ec;

extern "C" short* func_ov006_0215919c(void* self);
extern "C" unsigned char* func_ov006_021591c4(void* self);
extern "C" unsigned short func_ov006_021591ec(Struct_ov006_021591ec* self);

// USA: func_ov006_02159274
extern "C" ARM void func_ov006_02159274(Struct_ov006_02157a60* self, unsigned char* category, short* item, unsigned char* count) {
    *category = 0;
    *item = -1;
    *count = 0;
    if (self->unknown_364_ < 0)
        return;
    short index = self->unknown_362_ - 0x5b;
    short* items = func_ov006_0215919c(self);
    unsigned char* counts = func_ov006_021591c4(self);
    unsigned short size = func_ov006_021591ec((Struct_ov006_021591ec*)self);
    if (items != 0 && counts != 0 && size != 0) {
        unsigned short position = (unsigned short)(self->page_ * 8);
        position += self->unknown_364_ - 0x64;
        *category = index;
        *item = items[position];
        *count = counts[position];
    }
}
