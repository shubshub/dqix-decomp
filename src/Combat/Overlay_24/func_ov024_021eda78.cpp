#include <globaldefs.h>

struct Struct_0200fd38_4 {
    char pad0[0x21];
    unsigned char unknown_21_;
};

struct Struct_ov024_021eda78_3 {
    char pad0[0x138];
    struct Struct_0200fd38_4* stats;
};

struct Struct_0200fd38_3;

struct Struct_ov024_021eda78_4 {
    struct Struct_0200fd38_3* battle;
};

struct Struct_ov024_021eda78_3* GetCombatantByID(int, int);
struct GameObject;
extern "C" int func_ov024_021eda60(GameObject*);
extern "C" int func_ov024_021edbc0(GameObject*);
extern "C" int func_ov024_021edbd8(GameObject*);
extern "C" int func_ov024_021edbf0(GameObject*);
struct Struct_ov024_021eda78_5;
extern "C" int func_ov024_021edc08(Struct_ov024_021eda78_5*);
struct Struct_ov024_021eda78_6;
extern "C" int func_ov024_021edc20(Struct_ov024_021eda78_6*);
struct Struct_ov024_021eda78_7;
extern "C" int func_ov024_021edc38(Struct_ov024_021eda78_7*);
struct Struct_ov024_021e4604;
extern "C" int func_ov024_021e47dc(Struct_ov024_021e4604*);
struct Struct_ov024_021eda78_8;
extern "C" int func_ov024_021edc50(Struct_ov024_021eda78_8*);
struct Struct_ov024_021eda78_9;
extern "C" int func_ov024_021edc68(Struct_ov024_021eda78_9*);
struct Struct_ov024_021eda78;
extern "C" int func_ov024_021edc80(Struct_ov024_021eda78*);
struct Struct_ov024_021eda78_2;
extern "C" int func_ov024_021edca4(Struct_ov024_021eda78_2*);

static inline int inline_ov024_021eda78(struct Struct_ov024_021eda78_3* c) {
    return c->stats->unknown_21_ == 1;
}

static inline int inline_ov024_021eda78_2(struct Struct_ov024_021eda78_3* c) {
    return c->stats->unknown_21_ == 2;
}

// USA: func_ov024_021eda78
extern "C" ARM int func_ov024_021eda78(struct Struct_ov024_021eda78_4* ctx, int id) {
    struct Struct_ov024_021eda78_3* c = GetCombatantByID((int)ctx->battle, id);
    if (!c) {
        return 0;
    }
    if (func_ov024_021eda60((GameObject*)c)) {
        return 1;
    }
    if (func_ov024_021edbc0((GameObject*)c)) {
        return 1;
    }
    if (inline_ov024_021eda78(c)) {
        return 1;
    }
    if (inline_ov024_021eda78_2(c)) {
        return 1;
    }
    if (func_ov024_021edbd8((GameObject*)c)) {
        return 1;
    }
    if (func_ov024_021edbf0((GameObject*)c)) {
        return 1;
    }
    if (func_ov024_021edc08((Struct_ov024_021eda78_5*)c)) {
        return 1;
    }
    if (func_ov024_021edc20((Struct_ov024_021eda78_6*)c)) {
        return 1;
    }
    if (func_ov024_021edc38((Struct_ov024_021eda78_7*)c)) {
        return 1;
    }
    if (func_ov024_021e47dc((Struct_ov024_021e4604*)c)) {
        return 1;
    }
    if (func_ov024_021edc50((Struct_ov024_021eda78_8*)c)) {
        return 1;
    }
    if (func_ov024_021edc68((Struct_ov024_021eda78_9*)c)) {
        return 1;
    }
    if (func_ov024_021edc80((Struct_ov024_021eda78*)c)) {
        return 1;
    }
    if (func_ov024_021edca4((Struct_ov024_021eda78_2*)c)) {
        return 1;
    }
    return func_ov024_021edc20((Struct_ov024_021eda78_6*)c);
}
