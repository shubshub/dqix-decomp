#include <globaldefs.h>

struct Struct_ov031_0223bbd8_2 {
    unsigned long unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};
struct Struct_ov031_0223bbd8 {
    unsigned char padding[8];
    Struct_ov031_0223bbd8_2* entries;
    unsigned char count;
};

static inline void inline_ov031_0223bbd8(const Struct_ov031_0223bbd8_2* oam, unsigned long* x, unsigned long* y) {
    *x = (oam->unknown_0_ & 0x01ff0000UL) >> 16;
    *y = oam->unknown_0_ & 0xffUL;
}

static inline void inline_ov031_0223bbd8_2(Struct_ov031_0223bbd8_2* oam, int x, int y) {
    oam->unknown_0_ = (oam->unknown_0_ & ~0x01ff00ffUL) | (y & 0xffUL) | ((x & 0x1ffUL) << 16);
}

// USA: func_ov031_0223bbd8
extern "C" ARM void func_ov031_0223bbd8(Struct_ov031_0223bbd8* list, int index, int x, int y) {
    Struct_ov031_0223bbd8_2* entries = list->entries;
    if (index >= 0) {
        inline_ov031_0223bbd8_2(&entries[index], x, y);
        return;
    }
    int i;
    int originX, originY;
    inline_ov031_0223bbd8(entries, (unsigned long*)&originX, (unsigned long*)&originY);
    inline_ov031_0223bbd8_2(entries, x, y);
    int var4 = x - originX;
    int var5 = y - originY;
    for (i = 1; i < list->count; i++) {
        int positionX, positionY;
        inline_ov031_0223bbd8(&entries[i], (unsigned long*)&positionX, (unsigned long*)&positionY);
        inline_ov031_0223bbd8_2(&entries[i], positionX + var4, positionY + var5);
    }
}
