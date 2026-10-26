#include <globaldefs.h>

struct Struct_0202bad4 {
    char unk_0[4];
    unsigned char id[6];
    char unk_a[0x43 - 0xa];
    unsigned char removed;
    char unknown_44_[0x50 - 0x44];
    unsigned char name[0x63 - 0x50];
    signed char level;
    char unk_64;
    unsigned char unknown_65_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char hidden : 1;
    unsigned char present : 1;
    unsigned char visible : 1;
    unsigned char unknown_65_6_ : 1;
    unsigned char flag7 : 1;
    char unknown_66_[0xc0 - 0x66];
};
struct Struct_0202bad4_2;

struct Struct_ov003_0215f698_2 {
    unsigned char active : 1;
    unsigned char level : 6;
    unsigned char unknown_0_7_ : 1;
    char name[0x30];
    unsigned char id[6];
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int func_0202bae4(void* obj);
extern "C" struct Struct_0202bad4* func_0202bad4(struct Struct_0202bad4_2* base, int index);
extern "C" int memcmp(void* a, void* b, int n);
extern "C" void __clear(void* buf, int size);
extern "C" void Font_DecodeText(void* src, char* dst, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void* memcpy(void* dst, const void* src, int size);

// USA: func_ov003_0215f698
#if defined(jpn)
struct Struct_ov003_0215f698 {
    unsigned char active : 1;
    unsigned char level : 6;
    unsigned char unknown_0_7_ : 1;
    char name[0x13];
    signed char unknown_14_;
    unsigned char id[6];
};

extern "C" ARM void func_ov003_0215f698(struct Struct_ov003_0215f698* records, short* count) {
    void* ctx = LinkSession_GetInstance();
    int n = func_0202bae4(ctx);

    struct Struct_ov003_0215f698* rec = records;
    for (short i = 0; i < 10; i++) {
        rec->active = 0;
        rec++;
    }

    for (int k = 0; k < n; k++) {
        struct Struct_0202bad4* elem = func_0202bad4((struct Struct_0202bad4_2*)ctx, k);
        int found = 0;
        for (short j = 0; j < *count; j++) {
            rec = &records[j];
            if (elem->removed == 0 && memcmp(rec->id, elem->id, 6) == 0 && !elem->hidden && !elem->present) {
                rec->unknown_0_7_ = 1;
                rec->active = 1;
                memcpy(rec->name, elem->name, 0x14);
                memcpy(rec->id, elem->id, 6);
                rec->level = rec->unknown_14_;
                found = 1;
                break;
            }
        }
        if (!found && *count < 10 && elem->removed == 0 && !elem->hidden && !elem->present && elem->level > 0) {
            struct Struct_ov003_0215f698* added = &records[*count];
            added->unknown_0_7_ = 1;
            added->active = 1;
            memcpy(added->name, elem->name, 0x14);
            memcpy(added->id, elem->id, 6);
            added->level = elem->level;
            (*count)++;
        }
    }
}
#else
extern "C" ARM void func_ov003_0215f698(struct Struct_ov003_0215f698_2* records, short* count) {
    void* ctx = LinkSession_GetInstance();
    int n = func_0202bae4(ctx);

    struct Struct_ov003_0215f698_2* rec = records;
    for (short i = 0; i < 10; i++) {
        rec->active = 0;
        rec++;
    }

    for (int k = 0; k < n; k++) {
        struct Struct_0202bad4* elem = func_0202bad4((struct Struct_0202bad4_2*)ctx, k);
        int found = 0;
        for (short j = 0; j < *count; j++) {
            rec = &records[j];
            if (elem->removed == 0 && memcmp(rec->id, elem->id, 6) == 0 && !elem->hidden && elem->present &&
                elem->visible) {
                char buf[0x30];
                rec->unknown_0_7_ = 1;
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
            struct Struct_ov003_0215f698_2* added = &records[*count];
            added->unknown_0_7_ = 1;
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
