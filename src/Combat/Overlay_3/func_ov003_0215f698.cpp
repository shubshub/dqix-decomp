#include <globaldefs.h>

struct Struct_0202bad4 {
    char unknown_0_[4];
    unsigned char unknown_4_[6];
    char unknown_a_[0x43 - 0xa];
    unsigned char unknown_43_;
    char unknown_44_[0x50 - 0x44];
    unsigned char unknown_50_[0x63 - 0x50];
    signed char unknown_63_;
    char unknown_64_;
    unsigned char unknown_65_0_ : 1;
    unsigned char unknown_65_1_ : 1;
    unsigned char unknown_65_2_ : 1;
    unsigned char unknown_65_3_ : 1;
    unsigned char unknown_65_4_ : 1;
    unsigned char unknown_65_5_ : 1;
    unsigned char unknown_65_6_ : 1;
    unsigned char unknown_65_7_ : 1;
    char unknown_66_[0xc0 - 0x66];
};
struct Struct_0202bad4_2;

struct Struct_ov003_0215f698_2 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 6;
    unsigned char unknown_0_7_ : 1;
    char unknown_1_[0x30];
    unsigned char unknown_31_[6];
};

extern "C" void* func_0202ae18(void);
int GetField0xc_0202bae4(void* obj);
struct Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4* base, int index);
extern "C" int memcmp(void* a, void* b, int n);
extern "C" void __clear(void* buf, int size);
extern "C" void Font_DecodeText(void* src, char* dst, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void* memcpy(void* dst, const void* src, int size);

// USA: func_ov003_0215f698
#if defined(jpn)
struct Struct_ov003_0215f698 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 6;
    unsigned char unknown_0_7_ : 1;
    char unknown_1_[0x13];
    signed char unknown_14_;
    unsigned char unknown_15_[6];
};

extern "C" ARM void func_ov003_0215f698(struct Struct_ov003_0215f698* arg0, short* arg1) {
    void* var0 = func_0202ae18();
    int var1 = func_0202bae4(var0);

    struct Struct_ov003_0215f698* var2 = arg0;
    for (short var3 = 0; var3 < 10; var3++) {
        var2->unknown_0_0_ = 0;
        var2++;
    }

    for (int k = 0; k < n; k++) {
        struct Element0202bad4* elem = GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)ctx, k);
        int found = 0;
        for (short j = 0; j < *count; j++) {
            rec = &records[j];
            if (elem->removed == 0 && memcmp(rec->id, elem->id, 6) == 0 && !elem->hidden && !elem->present) {
                rec->valid = 1;
                rec->active = 1;
                memcpy(rec->name, elem->name, 0x14);
                memcpy(rec->id, elem->id, 6);
                rec->level = rec->nameLevel;
                found = 1;
                break;
            }
        }
        if (!var6 && *arg1 < 10 && var5->unknown_43_ == 0 && !var5->unknown_65_3_ && !var5->unknown_65_4_ && var5->unknown_63_ > 0) {
            struct Struct_ov003_0215f698* var8 = &arg0[*arg1];
            var8->unknown_0_7_ = 1;
            var8->unknown_0_0_ = 1;
            memcpy(var8->unknown_1_, var5->unknown_50_, 0x14);
            memcpy(var8->unknown_15_, var5->unknown_4_, 6);
            var8->unknown_0_1_ = var5->unknown_63_;
            (*arg1)++;
        }
    }
}
#else
extern "C" ARM void func_ov003_0215f698(struct Struct_ov003_0215f698_2* arg0, short* arg1) {
    void* var9 = func_0202ae18();
    int var10 = func_0202bae4(var9);

    struct Struct_ov003_0215f698_2* var11 = arg0;
    for (short var12 = 0; var12 < 10; var12++) {
        var11->unknown_0_0_ = 0;
        var11++;
    }

    for (int k = 0; k < n; k++) {
        struct Element0202bad4* elem = GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)ctx, k);
        int found = 0;
        for (short j = 0; j < *count; j++) {
            rec = &records[j];
            if (elem->removed == 0 && memcmp(rec->id, elem->id, 6) == 0 && !elem->hidden && elem->present &&
                elem->visible) {
                char buf[0x30];
                rec->valid = 1;
                rec->active = 1;
                __clear(buf, 0x30);
                Font_DecodeText(elem->name, buf, 1);
                sprintf(rec->name, buf);
                memcpy(rec->id, elem->id, 6);
                rec->level = elem->level;
                found = 1;
                break;
            }
        }
        if (!found && *count < 10 && elem->removed == 0 && !elem->hidden && elem->present && elem->visible &&
            elem->level > 0) {
            char buf[0x30];
            struct Record0215f698* added = &records[*count];
            added->valid = 1;
            added->active = 1;
            __clear(buf, 0x30);
            Font_DecodeText(elem->name, buf, 1);
            sprintf(added->name, buf);
            memcpy(added->id, elem->id, 6);
            added->level = elem->level;
            (*count)++;
        }
    }
}
#endif
