#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
enum { Enum_ov025_021e3178_12 = 0x4, Enum_ov025_021e3178_336 = 0x144, Enum_ov025_021e3178_28629 = 0x71c5 };
#else
enum { Enum_ov025_021e3178_12 = 0xc, Enum_ov025_021e3178_336 = 0x150, Enum_ov025_021e3178_28629 = 0x6fd5 };
#endif

struct Struct_ov025_021e3178_5 { int x, y, z; };

struct Struct_ov025_021e3178_6 {
    char pad0[8];
    unsigned short slot;
    unsigned short kind;
    int limit;
};

struct Struct_ov025_021e3178_7 {
    char pad0[0x20];
    unsigned short id;
    char unknown_22_[0xe];
    struct Struct_ov025_021e3178_7* next;
};

struct Struct_ov025_021e3178_8 {
    struct Struct_ov025_021e3178_8* head;
    char pad4[0xa];
    short unknown_e_;
    char pad10[0xb];
    unsigned char unknown_1b_;
    char unknown_1c_[4];
    struct Struct_ov025_021e3178_8* next;
};

struct Struct_ov025_021e3178_9 {
    short id;
    char pad2[2];
    short unknown_4_;
    char pad6[2];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char padA[6];
    struct Struct_ov025_021e3178_7* ents;
    struct Struct_ov025_021e3178_8* unknown_14_;
    unsigned short s18;
};

struct Struct_ov025_021e3178 {
    char pad0[0x14];
    unsigned char codes[3];
    unsigned char count;
    char pad18[4];
    unsigned char unknown_1c_;
    char unknown_1d_[3];
    unsigned short unknown_20_;
    char unknown_22_[4];
    unsigned char unknown_26_[6];
};

static inline unsigned char* inline_02000c9c_9(Struct_ov025_021e3178* n) { return n->codes; }

struct Struct_ov025_021e3178_2 {
    char pad0[0x18];
    unsigned int lo : 5;
    unsigned int kind : 7;
    unsigned int hi : 20;
};

struct Struct_ov025_021e3178_3 {
    char pad0[6];
    unsigned short unknown_6_;
    char pad8[4];
};

struct Struct_ov025_021e3178_4 {
    char pad0[Enum_ov025_021e3178_336];
    unsigned char* flags;
};

extern int data_ov025_021ef988;
extern int data_ov025_021eef40[];

extern "C" void func_ov025_021eb044(void* obj, ...);
extern "C" int func_ov000_0215fd90(void* entry, unsigned char effect);
extern "C" void func_ov000_02162c14(void* work, int id, struct Struct_ov025_021e3178_3* out);
extern "C" void* func_ov000_02160130(void);
extern "C" struct Struct_ov025_021e3178_2* func_02079e2c(char*, int);
struct Struct_ov000_0215440c_2;
extern "C" struct Struct_ov025_021e3178* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
struct Struct_ov000_0215440c;
extern "C" struct Struct_ov025_021e3178* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" struct Struct_ov025_021e3178* func_ov000_0215feb4(char*, int, int);
extern "C" void* func_ov000_0215fff4(void* node, int index, int depth);
extern "C" int func_020850d0(unsigned char* flags);
extern "C" void __clear(void* p, int n);

#define NOTIFY() func_ov025_021eb044(*(void**)((char*)&data_ov025_021ef988 + Enum_ov025_021e3178_12), a->slot)

// USA: func_ov025_021e3178
extern "C" ARM int func_ov025_021e3178(struct Struct_ov025_021e3178_6* a, struct Struct_ov025_021e3178_9* b) {
    GameState* gs = GameState::GetInstance();
    if (a->slot == 0) return 1;
    switch (a->kind) {
    case 1:
    case 2:
    case 3:
    case 4: {
        Vector3fix sum;
        struct Struct_ov025_021e3178_7* e;
        void* o;
        int n;
        int var5;
        __clear(&sum, 0xc);
        n = 0;
        var5 = 0;
        for (e = b->ents; e; e = e->next) {
            o = gs->GetGameObjectByIndex(e->id);
            if (o) {
                Struct_ov025_021e3178_5 tmp = *(Struct_ov025_021e3178_5*)((char*)o + 0x44);
                Vector3fix_Add(&sum, (Vector3fix*)&tmp, &sum);
                var5 += ((Object3D*)o)->GetRadius() / 2;
                n++;
            }
        }
        if (n > 0) {
            int d = n << 12;
            Vector3fixMultiplyScalar(&sum, fix32_Divide(0x1000, d), &sum);
            var5 = fix32_Divide(var5, d);
        }
        Vector3fix var8;
        __clear(&var8, 0xc);
        int n2 = 0;
        int var10 = 0;
        for (struct Struct_ov025_021e3178_8* c = b->unknown_14_; c; c = c->next) {
            void* o = gs->GetGameObjectByIndex(c->unknown_e_);
            if (o) {
                Struct_ov025_021e3178_5 var13 = *(Struct_ov025_021e3178_5*)((char*)o + 0x44);
                Vector3fix_Add(&var8, (Vector3fix*)&var13, &var8);
                var10 += ((Object3D*)o)->GetRadius() / 2;
                n2++;
            }
        }
        if (n2 > 0) {
            int d = n2 << 12;
            Vector3fixMultiplyScalar(&var8, fix32_Divide(0x1000, d), &var8);
            var10 = fix32_Divide(var10, d);
        }
        int diff = Vector3fix_Distance(&sum, &var8) - var5 - var10;
        switch (a->kind) {
        case 1:
            if (diff < a->limit) NOTIFY();
            break;
        case 2:
            if (diff > a->limit) NOTIFY();
            break;
        case 3:
            if (diff <= a->limit) NOTIFY();
            break;
        case 4:
            if (diff >= a->limit) NOTIFY();
            break;
        }
        break;
    }
    case 5: {
        if (b->unknown_8_ == 1 && b->unknown_9_ == 1) {
            struct Struct_ov025_021e3178* var16 = func_ov000_02160094((Struct_ov000_0215440c_2*)b, 0);
            struct Struct_ov025_021e3178* n0 = func_ov000_021600f8((Struct_ov000_0215440c*)b, 0);
            if (var16 && n0) {
                if (var16->unknown_20_ == *(short*)((char*)n0 + 0xe)) NOTIFY();
            }
        }
        break;
    }
    case 6: {
        struct Struct_ov025_021e3178_2* rec = func_02079e2c((char*)func_020797dc(), b->id);
        if (!rec) return 0;
        unsigned short id = b->id;
        if (id == 0x74) {
            for (struct Struct_ov025_021e3178_8* c = b->unknown_14_; c; c = c->next) {
                if (c->unknown_1b_) {
                    NOTIFY();
                    return 1;
                }
            }
        } else if (id == 0xa5) {
            if (b->unknown_4_ > 0) {
                NOTIFY();
                return 1;
            }
        } else if (rec->kind == 0x12) {
            for (struct Struct_ov025_021e3178_8* c = b->unknown_14_; c; c = c->next) {
                for (struct Struct_ov025_021e3178_8* m = c->head; m; m = m->next) {
                    if (func_ov000_0215fd90(m, 3)) {
                        NOTIFY();
                        return 1;
                    }
                }
            }
        }
        break;
    }
    case 11: {
        if (b->unknown_9_ == 0) break;
        struct Struct_ov025_021e3178* node = func_ov000_021600f8((Struct_ov000_0215440c*)b, 0);
        if (!node) break;
        for (int j = 0; j < node->count; j++) {
            int v = ((unsigned char*)((int)node + 0x14))[j];
            if (!(v != 8 && v != 6 && v != 7)) {
                NOTIFY();
                break;
            }
        }
        break;
    }
    case 10: {
        if (b->unknown_9_ == 0) break;
        for (int i = 0; i < b->unknown_9_; i++) {
            struct Struct_ov025_021e3178* node = func_ov000_021600f8((Struct_ov000_0215440c*)b, i);
            if (node) {
                unsigned char* codes = node->codes;
                for (int j = 1; j < node->count; j++) {
                    int v = codes[j];
                    if (v == 3) {
                        NOTIFY();
                        break;
                    }
                    if (v == 8 || v == 7 || v == 6) break;
                }
            }
        }
        break;
    }
    case 7: {
        if (b->unknown_9_ == 0) break;
        for (int i = 0; i < b->unknown_9_; i++) {
            struct Struct_ov025_021e3178* node = func_ov000_021600f8((Struct_ov000_0215440c*)b, i);
            if (node) {
                unsigned char* codes = node->codes;
                for (int j = 1; j < node->count; j++) {
                    int v = codes[j];
                    if (!(v != 2 && v != 5 && v != 4 && v != 3)) {
                        NOTIFY();
                        break;
                    }
                }
            }
        }
        break;
    }
    case 13: {
        if (b->unknown_9_ == 0) break;
        for (int i = 0; i < b->unknown_9_; i++) {
            struct Struct_ov025_021e3178* node = func_ov000_021600f8((Struct_ov000_0215440c*)b, i);
            if (node) {
                for (int j = 1; j < node->count; j++) {
                    if (node->codes[j] == 1) {
                        NOTIFY();
                        break;
                    }
                }
            }
        }
        break;
    }
    case 8: {
        for (int i = 0; i < b->unknown_8_; i++) {
            struct Struct_ov025_021e3178* node = func_ov000_02160094((Struct_ov000_0215440c_2*)b, i);
            if (node) {
                for (int j = 0; j < 6; j++) {
                    if (node->unknown_26_[j]) {
                        NOTIFY();
                        break;
                    }
                }
            }
        }
        break;
    }
    case 12:
    case 14:
    case 17: {
        for (int i = 0; i < b->unknown_8_; i++) {
            struct Struct_ov025_021e3178* node = func_ov000_02160094((Struct_ov000_0215440c_2*)b, i);
            if (node) {
                for (int k = 0; k < 6; k++) {
                    int found = 0;
                    for (int m = 0; m < node->unknown_26_[k]; m++) {
                        void* x = func_ov000_0215feb4((char*)node, m, k & 0xff);
                        if (x) {
                            if (func_ov000_0215fd90(x, 0x22) && a->kind == 0xc) {
                                NOTIFY();
                                found = 1;
                                break;
                            }
                            if (func_ov000_0215fd90(x, 0x25) && a->kind == 0xe) {
                                NOTIFY();
                                found = 1;
                                break;
                            }
                            if (a->kind == 0x11 && (func_ov000_0215fd90(x, 0x23) || func_ov000_0215fd90(x, 7))) {
                                NOTIFY();
                                found = 1;
                                break;
                            }
                        }
                    }
                    if (found) break;
                }
            }
        }
        break;
    }
    case 15: {
        void* w = func_ov000_02160130();
        if (w && *(unsigned char*)((char*)w + Enum_ov025_021e3178_28629)) NOTIFY();
        break;
    }
    case 22:
        if (b->s18 == 0x1ef) {
            NOTIFY();
            break;
        }
    case 16: {
        for (struct Struct_ov025_021e3178_8* c = b->unknown_14_; c; c = c->next) {
            for (struct Struct_ov025_021e3178_8* m = c->head; m; m = m->next) {
                if (func_ov000_0215fd90(m, 7)) {
                    NOTIFY();
                    return 1;
                }
            }
        }
        break;
    }
    case 18: {
        struct Struct_ov025_021e3178_7* ent = b->ents;
        if (!ent) break;
        int id = ent->id;
        void* w = func_ov000_02160130();
        if (!w) break;
        struct Struct_ov025_021e3178_3 buf;
        func_ov000_02162c14(w, id, &buf);
        if (buf.unknown_6_ == 0x520e) {
            NOTIFY();
            return 1;
        }
        break;
    }
    case 23: {
        struct Struct_ov025_021e3178_7* ent = b->ents;
        if (!ent) break;
        int id = ent->id;
        GameState* g = GameState::GetInstance();
        if (!g) break;
        struct Struct_ov025_021e3178_4* c = (Struct_ov025_021e3178_4*)func_0200ff1c(g, id);
        if (!c) break;
        if (func_020850d0(c->flags)) {
            NOTIFY();
            return 1;
        }
        break;
    }
    case 19:
    case 20:
    case 21: {
        if (b->unknown_9_ == 0) break;
        int fa = 0;
        int fb = 0;
        for (int i = 0; i < b->unknown_9_; i++) {
            struct Struct_ov025_021e3178* node = func_ov000_021600f8((Struct_ov000_0215440c*)b, i);
            if (node) {
                for (int j = 1; j < node->count; j++) {
                    if (node->codes[j] == 0xa) {
                        fa = 1;
                        if (a->kind == 0x14) {
                            NOTIFY();
                            break;
                        }
                    }
                }
                struct Struct_ov025_021e3178_7* first = *(struct Struct_ov025_021e3178_7**)node;
                if (first && *(unsigned char*)((char*)first + 0x1c)) {
                    fb = 1;
                    if (a->kind == 0x13) {
                        NOTIFY();
                        break;
                    }
                }
            }
        }
        if (a->kind == 0x15 && fa && fb) NOTIFY();
        break;
    }
    case 9: {
        struct Struct_ov025_021e3178_2* rec = func_02079e2c((char*)func_020797dc(), b->id);
        if (!rec) return 0;
        struct Struct_ov025_021e3178* node = func_ov000_021600f8((Struct_ov000_0215440c*)b, 0);
        if (!node) return 0;
        if (!node) return 0;
        void* p = func_ov000_0215fff4(node, 0, 0);
        if (!p) return 0;
        if (!p) return 0;
        for (int* t = data_ov025_021eef40; *t != -1; t++) {
            if (func_ov000_0215fd90(p, *t)) {
                NOTIFY();
                return 1;
            }
        }
        break;
    }
    default:
    case 0:
        func_ov025_021eb044(*(void**)((char*)&data_ov025_021ef988 + Enum_ov025_021e3178_12));
        break;
    }
    return 1;
}
