#include <globaldefs.h>

struct Container02080f8c;
struct Struct_02080fa8;

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** texts_;
#endif
    char unknown_8_[0xc];
    void* menu_;
    char unknown_18_[0x30];
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
#if defined(jpn)
    char unknown1_4c_[0x118];
#else
    char unknown_54_[0x11c];
#endif
    char itemNames_[0xc];
#if defined(jpn)
    char unknown1_170_[0x1f2];
#else
    char unknown_17c_[0x1e6];
#endif
    short unknown_362_;
    char unknown_364_[0xc];
    short item_;
    char unknown_372_[0x16];
    unsigned char page_;
    unsigned char pages_;
    unsigned char category_;
    unsigned char count_;
    char unknown_38c_[8];
    unsigned short flags_;
};

extern "C" void func_02080b54(void*, int);
extern "C" void func_02080608(void*, int);
extern "C" void func_020806c4(void*, int);
extern "C" void func_02080b40(void*, int);
extern "C" void* func_020e5294(void*, int);
#if defined(jpn)
struct Container020e0310;
extern "C" const char* KeyTable_Get(Container020e0310*, int);
#endif
extern "C" void func_02080f8c(Container02080f8c*, int, int);
extern "C" void func_02080fa8(Struct_02080fa8*, int, int);
extern "C" void func_020805f4(void*, int);
extern "C" void func_02081130(void*, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_020e4864(const char*, char*, int, int, int, int);
extern "C" void func_020813ec(void*, int);

// USA: func_ov006_0215f4dc
extern "C" ARM void func_ov006_0215f4dc(Struct_ov006_02157a60* self) {
    short category;
    unsigned char* counts;
    unsigned short count;
    short var3;
    void* menu;
    short* items;
    int nameEntry;
    int var7;
    unsigned short position;
    unsigned char row;
    category = self->unknown_362_ - 0x5b;
    position = self->page_ * 8;
    counts = self->unknown_4c_[category];
    items = self->items_[category];
    menu = self->menu_;
    count = self->sizes_[category];
    nameEntry = 0x64;
    var3 = 0x6c;
    var7 = 0x74;
    func_02080b54(menu, 0x11);
    func_02080608(menu, 0x11);
    self->flags_ &= ~4;
    if (count > 8) self->flags_ |= 4;
    for (row = 0; row < 8; row++) {
        if (count > position && items[position] > 0) {
            func_020806c4(menu, nameEntry);
            func_02080b40(menu, nameEntry);
            func_02080b40(menu, var3);
            func_02080b40(menu, var7);
#if defined(jpn)
            func_02080f8c((Container02080f8c*)menu, nameEntry, (int)KeyTable_Get((Container020e0310*)self->itemNames_, items[position]));
#else
            const char** name = (const char**)func_020e5294(self->itemNames_, items[position]);
            if (name != NULL) {
                memset(self->texts_[row], 0, 4);
                func_020e4864(*name, self->texts_[row], 1, 0, 0, 0);
                func_02080f8c((Container02080f8c*)self->menu_, nameEntry, (int)self->texts_[row]);
            }
            func_020805f4(menu, nameEntry);
#endif
            unsigned char amount = counts[position];
            if (self->item_ == items[position]) amount -= self->count_;
            func_02080fa8((Struct_02080fa8*)menu, var7, amount);
        }
        nameEntry = (short)(nameEntry + 1);
        var3++;
        var7 = (short)(var7 + 1);
        position++;
    }
    func_02080b40(menu, 0x7c);
    func_02080b40(menu, 0x7d);
    func_02080b40(menu, 0x7e);
    func_02080fa8((Struct_02080fa8*)menu, 0x7c, self->page_ + 1);
    func_02080fa8((Struct_02080fa8*)menu, 0x7d, self->pages_);
    func_02081130(menu, 0x11, (self->flags_ & 4) ? 1 : 0);
    func_020813ec(menu, 0x11);
}
