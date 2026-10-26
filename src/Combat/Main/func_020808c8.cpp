#include <globaldefs.h>

extern "C" int STD_GetStringLength(const char*);

struct TableA68;
struct Struct_0207f524 {
    void* entries;
    short count;
    short capacity;
};

struct Struct_020808c8 {
    TableA68* unknown_0_;
    Struct_0207f524 entries;
};

extern "C" void* func_0207f6ac(struct Struct_0207f524* list, int entryId);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" int func_02042190(int x);
extern "C" int Font_GetTextWidth(void* value, int flag);

struct Struct_020808c8_2 {
    const char* literalText;
    char pad1[0xa - 4];
    short width;
    short height;
    short textId;
    char pad2[0x12 - 0x10];
    unsigned char kind;
    unsigned char unknown_13_0_ : 4;
    unsigned char unknown_13_4_ : 4;
};

// USA: func_020808c8

extern "C" ARM void func_020808c8(void* container, int entryId, short* width, short* height) {
    Struct_020808c8* menu = static_cast<Struct_020808c8*>(container);
    struct Struct_020808c8_2* entry = (struct Struct_020808c8_2*)func_0207f6ac(&menu->entries, entryId);
    if (entry == NULL) {
        return;
    }

#if !defined(jpn)
    int isTwelve = func_02042190(entry->unknown_13_0_);
#endif
    int kind = entry->kind;

    switch (kind) {
    case 0: {
        void* found = func_02072a68(menu->unknown_0_, entry->textId);
        if (found == NULL) {
            return;
        }
#if defined(jpn)
        int glyphUnits = STD_GetStringLength((const char*)found) >> 1;
        int var6 = entry->unknown_13_0_;
        *width = (short)(glyphUnits * var6);
#else
        *width = (short)Font_GetTextWidth(found, isTwelve);
#endif
        *height = entry->unknown_13_0_;
        break;
    }
    case 1:
        *width = entry->width;
        *height = entry->height;
        break;
    case 4: {
        if (entry->literalText == NULL) {
            return;
        }
#if defined(jpn)
        int glyphUnits = STD_GetStringLength(entry->literalText) >> 1;
        int var8 = entry->unknown_13_0_;
        *width = (short)(glyphUnits * var8);
#else
        *width = (short)Font_GetTextWidth(const_cast<char*>(entry->literalText), isTwelve);
#endif
        *height = entry->unknown_13_0_;
        break;
    }
    default:
        *height = 0;
        *width = 0;
        break;
    }
}
