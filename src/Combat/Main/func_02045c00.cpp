#include <globaldefs.h>

#if defined(jpn)
struct Struct_02045c00 {
    char unk0[0x18];
    char key0;
    char key1;
    unsigned char kind;
    unsigned char unknown_1b_0_ : 1;
    unsigned char unknown_1b_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_1b_3_ : 5;
};

struct Struct_02045c00_2 {
    char unk0[0x884];
    int count;
    struct Struct_02045c00 entries[0x80];
    unsigned char active[0x80];
    char unknown_1708_[0x81];
    unsigned char unknown_1789_;
};

extern "C" ARM int func_02045c00(struct Struct_02045c00_2* c, const char* key, int kind) {
    int seen = 0;
    int i;
    for (i = 0; i < 0x80; i++) {
        struct Struct_02045c00* e;
        if (c->active[i] == 0) continue;
        e = &c->entries[i];
        if (e->key0 == key[0] && e->key1 == key[1] && kind == e->kind) {
            if (c->unknown_1789_ & 0x80) {
                if (e->bit2) return i;
            } else if (c->unknown_1789_ & 0x2) {
                if (e->unknown_1b_1_) return i;
            } else {
                return i;
            }
        }
        seen++;
        if (seen == c->count) break;
    }
    return -1;
}
#else
struct Struct_02045c00 {
    char unk0[0x16];
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_16_3_ : 5;
    char unknown_17_;
    int unknown_18_;
};

struct Struct_02045c00_2 {
    char unk0[0x9b8];
    struct Struct_02045c00 entries[0x80];
    unsigned char active[0x80];
    char unknown_1838_[0x123];
    unsigned char unknown_195b_;
};

// USA: func_02045c00
extern "C" ARM int func_02045c00(struct Struct_02045c00_2* c, int id) {
    int i;
    if (id == 0) {
        return -1;
    }
    for (i = 0; i < 0x80; i++) {
        struct Struct_02045c00* e;
        if (c->active[i] == 0) continue;
        e = &c->entries[i];
        if (id != e->unknown_18_) continue;
        if (c->unknown_195b_ & 0x80) {
            if (e->bit2) return i;
        } else if (c->unknown_195b_ & 0x2) {
            if (e->unknown_16_1_) return i;
        } else {
            return i;
        }
    }
    return -1;
}
#endif
