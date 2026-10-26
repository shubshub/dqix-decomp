#include <globaldefs.h>
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069408(void*, unsigned short);
extern "C" int func_02069430(void*, unsigned short);
extern "C" void func_0206cb14(void*, int, unsigned short);
extern "C" void __clear(void*, int);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern const char data_020f07ce[];
extern const char data_020f0aeb[];

// JPN: func_0206c794
extern "C" ARM void func_0206c794(void* context) {
    MessageSystem* self = static_cast<MessageSystem*>(context);
    unsigned short caption[16];
    unsigned char length = 0;
    __clear(caption, sizeof(caption));
    unsigned short* cursor = static_cast<unsigned short*>(self->unknown_1c_);
    int changed = 0;
    self->unknown_1774_ = 0;
    unsigned char var5 = self->unknown_17f3_;
    for (;;) {
        if (func_02069408(self, *cursor)) {
            length = 0;
            self->unknown_1774_ = -1;
            self->unknown_1772_ = 0;
            self->unknown_19c4_ = 0;
            changed = 1;
            break;
        }
        if (!func_02069430(self, *cursor)) {
            if (memcmp(cursor, data_020f07ce, 2) == 0) {
                self->unknown_17f3_ = 0;
                break;
            }
            caption[length] = *cursor;
            length = (unsigned char)(length + 1) & 15;
        }
        self->unknown_1774_++;
        cursor++;
    }
    cursor++;
    for (;;) {
        if (func_02069408(self, *cursor)) break;
        if (!func_02069430(self, *cursor)) {
            if (memcmp(cursor, data_020f0aeb, 2) == 0) {
                length = 0;
                self->unknown_1774_ = -1;
                self->unknown_1772_ = 0;
                self->unknown_19c4_ = 0;
                self->unknown_17f3_ = var5;
                changed = 1;
                break;
            }
            if (memcmp(cursor, data_020f07ce, 2) == 0) break;
        }
        cursor++;
    }
    if (!self->unknown_17f3_ && length) {
        unsigned short slot;
        for (unsigned char i = 0; i < self->unknown_1772_; i++) {
            slot = self->unknown_1752_[i];
            if (!func_02069430(self, slot)) {
                Struct_0204166c* glyph = &self->glyphs[slot];
                if (glyph->unknown_8_ >= 0 &&
                    glyph->unknown1_18_ != caption[i]) {
                    changed = 1;
                    break;
                }
            }
        }
    }
    if (changed) {
        for (unsigned char i = 0; i < self->unknown_1772_; i++)
            func_0206cb14(self, 10, self->unknown_1752_[i]);
        memset(self->unknown_1752_, 0xff01, sizeof(self->unknown_1752_));
        self->unknown_19c3_ = 0;
    } else if (self->unknown_1772_) {
        self->unknown_6c_ = (short)self->unknown_1774_;
        self->unknown1_40_ = self->unknown_1774_;
        self->unknown_78_ = (short)self->unknown_1774_;
        return;
    }
    self->unknown_1772_ = 0;
}
#else

struct Entry0204254c { int value; signed char width; signed char advance : 6; signed char field5 : 2; unsigned char field6[2]; };
extern "C" Entry0204254c* Font_FindCharacter(int, int);
extern "C" int Font_GetFallbackWidth(int);
struct Struct_0204500c_4;
extern "C" void func_0206b198(Struct_0204500c_4*, unsigned short);
extern char data_020f08dc[];
extern char data_020f0979[];
extern char data_020f097c[];
extern "C" void __clear(void*, int);
struct Struct_0206ad74 {
    unsigned char field0[0x50];
    char* text;
    unsigned char field54[0x74-0x54];
    int start;
    int end;
    unsigned char field7c[8];
    int unknown_84_;
    int unknown_88_;
    unsigned char unknown_8c_[0x912-0x8c];
    unsigned char mode;
    unsigned char unknown_913_[0x934-0x913];
    short unknown_934_;
    short unknown_936_;
    unsigned char unknown_938_[0x1882-0x938];
    unsigned short slots[64];
    char caption[64];
    unsigned short count;
    short width;
    short unknown_1946_;
    unsigned char unknown_1948_[0x19c2-0x1948];
    unsigned char status;
    unsigned char changed;
    unsigned char unknown_19c4_[0x19dc-0x19c4];
    unsigned char font;
};

// USA: func_0206ad74
extern "C" ARM void func_0206ad74(Struct_0206ad74* self) {
    int defaultWidth;
    int length = 0;
    self->unknown_84_ = 0;
    self->unknown_88_ = 0;
    self->width = 0;
    self->count = 0;
    self->unknown_1946_ = 0;
    unsigned char var2 = self->status;
    int changed = 1;
    int var4 = 0;
    char caption[64];
    __clear(caption, sizeof(caption));
    unsigned char fontWidth;
    char* cursor;
    char* text = self->text;
    char* start = strstr(text, data_020f08dc);
    char* middle = strstr(text, data_020f0979);
    char* alternate = strstr(text, data_020f097c);
    fontWidth = Font_GetFallbackWidth(self->font);
    if (start) {
        for (;;) {
            if (text == start) break;
            unsigned short code;
            memcpy(&code, text, 2);
            var4++;
            if ((code & 0xff00) == 0xff00) text++;
            text++;
        }
        char* selected = start + 2;
        char* var14 = strstr(selected, data_020f08dc);
        if (var14) {
            length = var14 - selected;
            memcpy(caption, selected, length);
            changed = 0;
            self->status = changed;
            cursor = caption;
            for (;;) {
                defaultWidth = fontWidth + 1;
                if (!*cursor) break;
                Entry0204254c* entry = Font_FindCharacter((int)cursor, self->font);
                if (entry) {
                    self->count++;
                    int width = entry->width;
                    int advance = entry->advance;
                    self->width += width + 1;
                    cursor += advance;
                } else {
                    self->count++;
                    cursor++;
                    self->width += defaultWidth;
                }
            }
            self->unknown_1946_ = var14 - start;
            self->unknown_1946_ += 3;
            self->unknown_1946_ += var4 - 2;
            self->mode = 4;
            short padding = 8 - (self->width & 7);
            self->unknown_934_ = self->width + 18 + padding;
            self->unknown_936_ = 22;
        } else self->status = var2;
    } else {
        if (middle || alternate) self->mode = 3;
        else self->unknown_1946_ = -1;
    }
    if (!self->status && length) changed = strcmp(self->caption, caption);
    if (changed) {
        for (int i = 0; i < self->count; i++) func_0206b198((Struct_0204500c_4*)self, self->slots[i]);
        memset(self->slots, 0xff01, sizeof(self->slots));
        memset(self->caption, 0, sizeof(self->caption));
        memcpy(self->caption, caption, length);
        self->changed = 0;
        if (self->count) {
            self->unknown_84_ = self->unknown_1946_;
            self->unknown_88_ = self->count + var4 + 3;
        }
    } else if (self->count) {
        self->unknown_84_ = self->unknown_1946_;
        self->unknown_88_ = self->count + var4 + 3;
        self->start = self->count + var4 + 3;
        self->end = self->count + var4 + 3;
        self->count++;
        return;
    }
    self->count = 0;
}

#endif
