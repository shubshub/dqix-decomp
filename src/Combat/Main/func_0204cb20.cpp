#include <globaldefs.h>
#include <NitroSDK/Cache.h>

#if defined(jpn)
#define func_0204e3e0 func_0204f6a0
#define func_0204cd60 func_0204daf8
#endif

struct Struct_0204cb20 {
    char pad0[0x1c];
    unsigned char low : 4;
    unsigned char high : 4;
    inline int inline_0204cb20() { return high; }
};
struct Struct_0204cb20_2 {
    int field0;
    Struct_0204cb20* unknown_4_;
    void* buffer;
    char unknown_c_[0xa0 - 0xc];
    int offset;
    int unknown_a4_;
    short width, height;
    short unknown_ac_, unknown_ae_;
    short x, y, fieldB4, lineHeight;
    char unknown_b8_[0xc7 - 0xb8];
    unsigned char font;
};
extern "C" void __clear(void*, unsigned int);
extern "C" void* MessageSystem_GetInstance();
#if defined(jpn)
extern "C" void func_020474a8(void*, int, const char*, char*);
extern "C" int func_0204e3e0(Struct_0204cb20_2*, char*, int, int, int);
extern "C" void func_0204cd60(Struct_0204cb20_2*, char*, int);
#else
extern "C" void MessageSystem_FormatText(void*, int, const char*, char*, int, int, int);
extern "C" int func_0204e3e0(Struct_0204cb20_2*, char*, int, int, int, int);
extern "C" void func_0204cd60(Struct_0204cb20_2*, char*, int, int);
#endif
extern "C" void func_02050100(Struct_0204cb20_2*, int);
typedef void (*Type_0204cb20)(void*, int, unsigned int);
extern "C" Type_0204cb20 func_0204a5e4(int, int);

// USA: func_0204cb20
#if defined(jpn)
extern "C" ARM void func_0204cb20(Struct_0204cb20_2* self, const char* text, short mode) {
    char formatted[0x800];
    short width;
    short height;
    short x;
    short y;
    short fieldB4;
    short lineHeight;
    int var7;
    if (self->unknown_4_ && self->buffer && text) {
        width = self->width;
        height = self->height;
        x = self->x;
        y = self->y;
        fieldB4 = self->fieldB4;
        lineHeight = self->lineHeight;
        var7 = self->unknown_a4_;
        __clear(formatted, sizeof(formatted));
        func_020474a8(MessageSystem_GetInstance(), self->font, text, formatted);
        int border = func_0204e3e0(self, formatted, 0, 0, mode);
        self->width = width;
        self->height = height;
        self->x = x;
        self->y = y;
        self->fieldB4 = fieldB4;
        self->lineHeight = lineHeight;
        self->unknown_a4_ = var7;
        func_0204cd60(self, formatted, border);
        func_02050100(self, 0);
        int high = self->unknown_4_->inline_0204cb20();
        int low = self->unknown_4_->low;
        Type_0204cb20 var11 = func_0204a5e4(low, high);
        CleanInvalidateCacheRange(self->buffer, self->unknown_a4_);
        var11(self->buffer, self->offset, self->unknown_a4_);
    }
}
#else
extern "C" ARM void func_0204cb20(Struct_0204cb20_2* self, const char* text, int mode, int font) {
    char formatted[0x800];
    short height;
    short y;
    short fieldB4;
    short lineHeight;
    short x;
    int limit;
    int var19;
    short width;
    if (self->unknown_4_ && self->buffer && text) {
        width = self->width;
        height = self->height;
        limit = (width << 3) - 4;
        x = self->x;
        y = self->y;
        if (mode) limit = 0x100;
        fieldB4 = self->fieldB4;
        lineHeight = self->lineHeight;
        var19 = self->unknown_a4_;
        __clear(formatted, sizeof(formatted));
        MessageSystem_FormatText(MessageSystem_GetInstance(), self->font, text, formatted, limit, x, font);
        int border = func_0204e3e0(self, formatted, 0, 0, mode, font);
        self->width = width;
        self->height = height;
        self->x = x;
        self->y = y;
        self->fieldB4 = fieldB4;
        self->lineHeight = lineHeight;
        self->unknown_a4_ = var19;
        func_0204cd60(self, formatted, border, font);
        func_02050100(self, 0);
        int high = self->unknown_4_->inline_0204cb20();
        int low = self->unknown_4_->low;
        Type_0204cb20 var24 = func_0204a5e4(low, high);
        CleanInvalidateCacheRange(self->buffer, self->unknown_a4_);
        var24(self->buffer, self->offset, self->unknown_a4_);
    }
}
#endif
