#include <globaldefs.h>

struct Struct_ov025_021ebb90_6 {
    int a;
    unsigned char idx : 6;
    unsigned char mode : 2;
    unsigned char c;
    unsigned char d;
    unsigned char unknown_7_;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    int j;
    short k;
    short l;
    unsigned int m;
    int n;
    unsigned short o;
    short p;
    short q;
    short r;
    short s;
    short t;
    unsigned char u;
    unsigned char v;
    unsigned char w;
    unsigned char unknown_3b_;
    unsigned short x;
    unsigned short unknown_3e_;
};

struct Struct_ov025_021ecc54_3 {
    struct Struct_ov025_021ebb90_6 entries[12];
    unsigned char unknown_300_;
    unsigned char unknown_301_;
    unsigned short unknown_302_;
    short unknown_304_;
    unsigned char unknown_306_;
    unsigned char unknown_307_;
    int unknown_308_;
    void* unknown_30c_;
    unsigned char unknown_310_;
    unsigned char unknown_311_;
};

struct Struct_ov025_021ecc54_4 {
    unsigned long long flags;
    char pad08[0x18];
    struct Struct_ov025_021ecc54_4* next;
};

struct Struct_ov000_021600f8 {
    struct Struct_ov025_021ecc54_4* members;
    char pad04[0x14];
    unsigned char counts[3];
};

struct Struct_ov000_02160094 {
    struct Struct_ov025_021ecc54_4* members[3];
    char unknown_c_[0x1a];
    unsigned char counts[6];
};

struct Struct_ov025_021ecc54 {
    char unknown_0_[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
};

struct Struct_ov025_021ecc54_2 {
    struct Struct_ov025_021ecc54* list;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    short k0;
    short k1;
    int n;
    short unknown_1c_;
    short unknown_1e_;
    unsigned int m;
    unsigned short f24;
    unsigned short flags;
    unsigned short o;
    short p;
    short q;
    short r;
    short s;
    short t;
    unsigned char u;
    unsigned char v;
    char unknown_36_[2];
    unsigned char unknown_38_;
};

struct Struct_ov000_0215440c;
extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c*, int);
struct Struct_ov000_0215440c_2;
extern "C" struct Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" void func_ov025_021ebb24(struct Struct_ov025_021ebb90_6* obj);
extern "C" int func_ov000_0215fd90(struct Struct_ov025_021ecc54_4* member, int flag);
extern "C" void func_ov025_021ed0b8(struct Struct_ov025_021ecc54_3* obj, struct Struct_ov025_021ebb90_6* src);

extern unsigned int data_ov025_021ef010[];
extern const int data_ov025_021ef008[];

// USA: func_ov025_021ecc54
extern "C" ARM void func_ov025_021ecc54(struct Struct_ov025_021ecc54_3* obj, struct Struct_ov025_021ecc54_2* src) {
    int counts[2];
    struct Struct_ov025_021ebb90_6 entry;

    obj->unknown_306_ = 0;
    counts[0] = src->list->unknown_9_;
    counts[1] = src->list->unknown_8_;

    for (int k = 0; k < 2; k++) {
        if (src->flags & data_ov025_021ef010[k]) continue;
        for (int i = 0; i < counts[k]; i++) {
            struct Struct_ov025_021ecc54* list = src->list;
            int total = -1;
            if (data_ov025_021ef008[k] == 1) {
                struct Struct_ov000_021600f8* node = func_ov000_021600f8((Struct_ov000_0215440c*)list, i);
                if (node != 0) {
                    total = node->counts[0];
                    total += node->counts[1];
                    total += node->counts[2];
                }
            } else if (data_ov025_021ef008[k] == 0) {
                struct Struct_ov000_02160094* node = func_ov000_02160094((Struct_ov000_0215440c_2*)list, i);
                if (node != 0) {
                    total = node->counts[0];
                    total += node->counts[2];
                    total += node->counts[3];
                    total += node->counts[4];
                    total += node->counts[5];
                    total += node->counts[1];
                }
            }
            if (total <= 0) continue;

            func_ov025_021ebb24(&entry);
            int found = 0;
            struct Struct_ov025_021ecc54_4** members = 0;
            unsigned char* var10 = 0;
            if (data_ov025_021ef008[k] == 1) {
                found = 1;
            } else if (data_ov025_021ef008[k] == 0) {
                struct Struct_ov000_02160094* node = func_ov000_02160094((Struct_ov000_0215440c_2*)src->list, i);
                if (node != 0) {
                    members = node->members;
                    var10 = node->counts;
                }
            }
            if (members != 0) {
                for (int t = 0; t < 3; t++) {
                    struct Struct_ov025_021ecc54_4* m = *members;
                    int n = *var10;
                    for (int j = 0; j < n; j++) {
                        if (data_ov025_021ef008[k] == 0 && m->flags == 0x100) entry.d |= 6;
                        if (m->flags != 0) {
                            found = 1;
                            break;
                        }
                        m++;
                    }
                    if (found) break;
                    members++;
                    var10++;
                }
            }

            entry.a = (int)src->list;
            entry.idx = i;
            entry.mode = data_ov025_021ef008[k];
            if (src->flags & 0x10) {
                entry.mode = 2;
            } else if (src->flags & 0x20) {
                entry.mode = 3;
            }
            entry.c = 6;
            entry.f = src->f04;
            entry.unknown_14_ = src->f0c;
            entry.unknown_18_ = src->f10;
            entry.g = src->f08;
            entry.n = src->n;
            entry.l = src->unknown_1c_;
            entry.m = src->m;
            entry.o = src->o;
            entry.p = src->p;
            entry.q = src->q;
            entry.u = src->u;
            entry.v = src->v;
            entry.r = src->r;
            entry.s = src->s;
            entry.t = src->t;
            if (src->k1 < 0) {
                entry.k = src->k0;
                entry.l = src->unknown_1c_;
            } else {
                int var16;
                struct Struct_ov025_021ecc54* list2 = src->list;
                if (data_ov025_021ef008[k] == 1) {
                    struct Struct_ov000_021600f8* node = func_ov000_021600f8((Struct_ov000_0215440c*)list2, i);
                    if (node != 0) {
                        for (struct Struct_ov025_021ecc54_4* m = node->members; m != 0; m = m->next) {
                            if (func_ov000_0215fd90(m, 3)) {
                                var16 = 1;
                                goto checked;
                            }
                        }
                    }
                } else if (data_ov025_021ef008[k] == 0) {
                    struct Struct_ov000_02160094* node = func_ov000_02160094((Struct_ov000_0215440c_2*)list2, i);
                    if (node != 0) {
                        for (struct Struct_ov025_021ecc54_4* m = node->members[0]; m != 0; m = m->next) {
                            if (func_ov000_0215fd90(m, 3)) {
                                var16 = 1;
                                goto checked;
                            }
                        }
                    }
                }
                var16 = 0;
            checked:
                if (var16) {
                    entry.k = src->k1;
                    entry.l = src->unknown_1e_;
                    entry.d |= 0x20;
                    entry.n &= ~1;
                } else {
                    entry.k = src->k0;
                    entry.l = src->unknown_1c_;
                }
            }
            if (entry.k < 0) entry.d |= 2;
            if (entry.l < 0) entry.d |= 4;
            if (!found) entry.d |= 6;
            if (src->unknown_38_ != 0) entry.d |= 0x40;
            func_ov025_021ed0b8(obj, &entry);
        }
    }
    obj->unknown_302_ = src->f24;
    if (obj->unknown_300_ != 0) obj->unknown_310_ = 0;
}
