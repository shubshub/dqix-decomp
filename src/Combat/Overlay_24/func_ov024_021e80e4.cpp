#include <globaldefs.h>

struct Struct_ov024_021e80e4_6 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov024_021e80e4_5 {
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Struct_ov024_021e80e4_7 {
    unsigned int unknown_0_0_ : 5;
    unsigned int kind : 7;
    unsigned int sub : 4;
    unsigned int rest : 16;
};

struct Struct_ov024_021e80e4_8 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_ov024_021e80e4_9 {
    char pad0[4];
    struct Struct_ov024_021e80e4_5 f4;
    char pad1[0x10];
    struct Struct_ov024_021e80e4_7 f18;
    char pad2[8];
    struct Struct_ov024_021e80e4_8 f24;
    struct Struct_ov024_021e80e4_8 f28;
};

struct Struct_ov024_021e80e4_10 {
    unsigned short f0;
    char pad0[2];
    struct Struct_ov024_021e80e4_10* next;
};

struct Struct_ov024_021e80e4_11 {
    char pad0[8];
    struct Struct_ov024_021e80e4_10* f8;
    short fc;
    char pad1[0x12];
    struct Struct_ov024_021e80e4_11* next;
};

struct Struct_ov024_021e80e4 {
    struct Struct_ov024_021e80e4_11* f0;
    char pad0[4];
    struct Struct_ov024_021e80e4_11* f8;
    char pad1[0xc];
    unsigned char f18;
    char pad2[7];
    struct Struct_ov024_021e80e4* next;
};

struct Struct_ov024_021e80e4_2 {
    char pad0[0x20];
    unsigned short f20;
};

struct Struct_ov024_021e80e4_3 {
    char pad0[6];
    short unknown_6_;
    char pad1;
    unsigned char count;
    char pad2[2];
    struct Struct_ov024_021e80e4_6 fc;
    char pad3[7];
    struct Struct_ov024_021e80e4* head;
    char pad4[2];
    unsigned short unknown_1a_;
    unsigned short f1c;
    unsigned short unknown_1e_;
    unsigned short f20;
};

struct Struct_ov024_021e80e4_4 {
    int f0;
    struct Struct_ov024_021e80e4_3* f4;
    char pad0[8];
    void* f10;
    int f14;
    char pad1[0x2c];
    short unknown_44_;
    char pad2[0x31];
    unsigned char unknown_77_;
};

struct Struct_ov024_021fe800 {
    short v[16];
};

#define IN_RANGE_021e80e4(x) (((x) >= 0 && (x) <= 3) ? 1 : 0)

extern "C" struct Struct_ov024_021fe800 data_ov024_021fe800;

extern "C" int func_ov000_0215fc60(char*);
struct Struct_ov000_0215440c_2;
extern "C" struct Struct_ov024_021e80e4_2* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
struct Struct_ov000_0215440c;
extern "C" struct Struct_ov024_021e80e4* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" short func_ov000_0215ffa0(struct Struct_ov024_021e80e4* node);
struct Struct_ov000_02159f7c;
extern "C" int func_ov000_02159f7c(void*, Struct_ov000_02159f7c*);
extern "C" int func_ov000_0215fd90(struct Struct_ov024_021e80e4_11* entry, int kind);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" unsigned short func_ov024_021e9b24(struct Struct_ov024_021e80e4_4* self, int id, struct Struct_ov024_021e80e4_9* rec, int flag);

// USA: func_ov024_021e80e4
extern "C" ARM void func_ov024_021e80e4(struct Struct_ov024_021e80e4_4* self, struct Struct_ov024_021e80e4_3* list, struct Struct_ov024_021e80e4_9* rec, int arg3, unsigned char forced, struct Struct_ov024_021e80e4_9* arg5) {
    struct Struct_ov024_021fe800 ids;

    if (func_ov000_0215fc60((char*)self->f10) != 0) {
        struct Struct_ov024_021e80e4_2* var1 = func_ov000_02160094((Struct_ov000_0215440c_2*)list, 0);
        if (var1 != 0) {
            if (var1->f20 == 0) {
                list->unknown_1a_ = 0x260;
                return;
            }
        }
    }
    if (rec->f4.id == 0x61 && forced == 0) return;

    int idCount = 0;
    int var3 = 0;
    int var4 = 0;
    int var5 = 0;
    int var6 = 0;
    int var7 = 0;
    int var8 = 0;
    unsigned char var9 = 1;
    unsigned char var10 = 1;
    int var11 = self->f14;
    int var12 = var11;
    if (rec->f18.kind == 1) {
        var11 = var12 = 0;
    }
    ids = data_ov024_021fe800;

    for (int i = 0; i < list->count; i++) {
        struct Struct_ov024_021e80e4* node = func_ov000_021600f8((Struct_ov000_0215440c*)list, i);
        if (node == 0) continue;
        int id = func_ov000_0215ffa0(node);
        struct Struct_ov024_021e80e4_11* e;
        int active = 1;
        if (rec->f18.kind == 1) {
            active = 0;
            for (e = node->f0; e != 0; e = e->next) {
                if (func_ov000_02159f7c(self->f10, (Struct_ov000_02159f7c*)e) != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        var9 = 0;
                        var5++;
                    } else {
                        var10 = 0;
                        var6++;
                    }
                } else if (func_ov000_0215fd90(e, 0xd) != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        var7++;
                    } else {
                        var8 = 0;
                    }
                    continue;
                } else if (func_ov000_0215fd90(e, 4) != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        var5++;
                    } else {
                        var6++;
                    }
                }
                if (e->fc != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        var11++;
                    } else {
                        var12++;
                    }
                    active = 1;
                }
            }
            for (e = node->f8; e != 0; e = e->next) {
                if (func_ov000_0215fd90(e, 0xd) != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        var7++;
                    } else {
                        var8++;
                    }
                }
            }
        }
        if (active == 0) continue;
        int found = 0;
        for (int j = 0; j < idCount; j++) {
            if (id == ids.v[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            ids.v[idCount++] = id;
            if (IN_RANGE_021e80e4(id)) {
                var3++;
            } else {
                var4++;
            }
        }
        if (i == 0xf) break;
    }

    unsigned char var20 = 0;
    unsigned char var21 = 0;
    int var22;
    unsigned char var23;
    int var24;
    var24 = var22 = 0;
    var23 = 0;
    int kind = rec->f18.kind;
    if (kind == 1) {
        if (var3 > 1) {
            var24 = 3;
        } else {
            var24 = var11 > 1 ? 0x261 : 2;
        }
        if (var4 > 1) {
            var22 = 6;
        } else {
            var22 = var12 > 1 ? 0x262 : 5;
        }
        var23 = 1;
        if (var11 + var5 >= 2) {
            var9 = 1;
            var20 = 1;
        }
        if (var12 + var6 >= 2) {
            var10 = 1;
            var21 = 1;
        }
        if (var7 != 0) var9 = 0;
        if (var8 != 0) var10 = 0;
    }
    if (rec->f4.id == 0x166 || rec->f4.id == 0x167 || rec->f4.id == 0x38c || rec->f4.id == 0x38d || rec->f4.id == 0x38e || rec->f4.id == 0x38f) {
        var22 = list->count > 1 ? 0x218 : 0x38;
    }
    if (kind == 0x31) {
        if (self->f14 > 1) {
            var22 = 0xf2;
            var24 = var22;
        } else {
            var22 = 0xf1;
            var24 = var22;
        }
        if (self->f14 == 0) {
            if (list->count >= 2) {
                var21 = 1;
                var20 = 1;
            } else {
                struct Struct_ov024_021e80e4* node = func_ov000_021600f8((Struct_ov000_0215440c*)list, 0);
                if (node != 0 && node->f0 != 0) {
                    if (func_ov000_02159f7c(self->f10, (Struct_ov000_02159f7c*)node->f0) != 0) {
                        var10 = 0;
                        var9 = 0;
                    }
                }
            }
        }
        list->unknown_6_ = self->unknown_44_;
    }
    if (rec->f4.id == 0x9a) {
        if (self->f14 == 0) {
            var24 = 0x1f;
        } else {
            var24 = list->count <= 1 ? 0xcb : 0xcc;
        }
        var22 = var24;
    }
    if (rec->f4.id == 0x20f) {
        struct Struct_ov024_021e80e4_3* all;
        int count = 0;
        struct Struct_ov024_021e80e4* first = 0;
        all = self->f4;
        for (int k = 0; k < all->count; k++) {
            struct Struct_ov024_021e80e4* node = func_ov000_021600f8((Struct_ov000_0215440c*)all, k);
            if (node == 0) continue;
            if (IN_RANGE_021e80e4(func_ov000_0215ffa0(node))) continue;
            if (first == 0) first = node;
            count++;
        }
        int msg = count > 1 ? 0x24a : 0x5b;
        if (first != 0 && first->f0 != 0) {
            func_ov000_0215a88c(self->f10, first->f0, (unsigned short)msg);
        }
        return;
    }

    if (var20 != 0 || var21 != 0) {
        for (int i = 0; i < list->count; i++) {
            struct Struct_ov024_021e80e4* node = func_ov000_021600f8((Struct_ov000_0215440c*)list, i);
            if (node == 0) continue;
            int id = func_ov000_0215ffa0(node);
            if (IN_RANGE_021e80e4(id) && var20 == 0) continue;
            if (!IN_RANGE_021e80e4(id) && var21 == 0) continue;
            for (struct Struct_ov024_021e80e4_11* e = node->f0; e != 0; e = e->next) {
                for (struct Struct_ov024_021e80e4_10* step = e->f8; step != 0; step = step->next) {
                    if (step->f0 == 0x96 || step->f0 == 0x255 || step->f0 == 0x97 || step->f0 == 0x1b9 || step->f0 == 0x24d || step->f0 == 0x2b) {
                        step->f0 = 0;
                    }
                }
            }
        }
    }

    struct Struct_ov024_021e80e4_9* var38 = rec;
    struct Struct_ov024_021e80e4_9* var39 = rec;
    if (rec->f18.kind == 1 && forced != 0) {
        struct Struct_ov024_021e80e4_2* var40 = func_ov000_02160094((Struct_ov000_0215440c_2*)list, 0);
        if (var40 != 0) {
            if (IN_RANGE_021e80e4(var40->f20)) {
                var39 = arg5;
            } else {
                var38 = arg5;
            }
        }
    }

    if (var3 < 1) {
        if (var9 != 0) list->unknown_1a_ = var38->f24.b;
    } else {
        struct Struct_ov024_021e80e4* head = list->head;
        struct Struct_ov024_021e80e4_11* e = head->f0;
        if (!(e != 0 && e->f8 != 0 && var24 == 0)) {
            if (list->count > 1) {
                if (var11 > 0) {
                    list->unknown_1a_ = var24;
                } else if (var9 != 0) {
                    list->unknown_1a_ = func_ov024_021e9b24(self, func_ov000_0215ffa0(head), var38, 1);
                }
            } else if (var11 > 0) {
                if (head->f18 > 1) {
                    list->unknown_1a_ = var24;
                } else if (e == 0 || func_ov000_0215fd90(e, 0xd) == 0) {
                    list->unknown_1a_ = func_ov024_021e9b24(self, func_ov000_0215ffa0(list->head), var38, 0);
                    if (list->unknown_1a_ == 0) {
                        if (var23 != 0) list->unknown_1a_ = 2;
                    }
                }
            } else if (var9 != 0) {
                list->unknown_1a_ = func_ov024_021e9b24(self, func_ov000_0215ffa0(head), var38, 1);
            }
        }
    }

    if (var4 < 1) {
        if (var10 != 0) list->f1c = var39->f24.c;
    } else {
        struct Struct_ov024_021e80e4* head = list->head;
        struct Struct_ov024_021e80e4_11* e = head->f0;
        if (!(e != 0 && e->f8 != 0 && var22 == 0)) {
            if (list->count > 1) {
                if (var12 > 0) {
                    list->f1c = var22;
                } else if (var10 != 0) {
                    list->f1c = func_ov024_021e9b24(self, func_ov000_0215ffa0(head), var39, 1);
                }
            } else if (var12 > 0) {
                if (head->f18 > 1) {
                    list->f1c = var22;
                } else if (e == 0 || func_ov000_0215fd90(e, 0xd) == 0) {
                    list->f1c = func_ov024_021e9b24(self, func_ov000_0215ffa0(list->head), var39, 0);
                    if (list->f1c == 0) {
                        if (var23 != 0) list->f1c = 5;
                    }
                }
            } else if (var10 != 0) {
                list->f1c = func_ov024_021e9b24(self, func_ov000_0215ffa0(head), var39, 1);
            }
        }
    }

    if (rec->f18.kind == 1) {
        if (list->unknown_1a_ == 3 || list->unknown_1a_ == 0x261) {
            list->fc.b0 = 1;
            list->fc.b1 = 1;
        } else if (list->unknown_1a_ == 2) {
            list->fc.b0 = 1;
            if (var11 + var5 >= 2) list->fc.b1 = 1;
        } else {
            if (var20 != 0) list->fc.b1 = 1;
        }
        if (list->f1c == 6 || list->f1c == 0x262) {
            list->fc.b3 = 1;
            list->fc.unknown_0_4_ = 1;
        } else if (list->f1c == 5) {
            list->fc.b3 = 1;
            if (var12 + var6 >= 2) list->fc.unknown_0_4_ = 1;
        } else {
            if (var21 != 0) list->fc.unknown_0_4_ = 1;
        }
    }

    if (arg3 == 0) return;
    list->unknown_1e_ = var38->f28.a;
    list->f20 = var39->f28.b;
    if (forced == 0 && self->unknown_77_ == 0) return;
    if (var39->f28.a != 0) {
        if (var39->f28.b == 0) list->f20 = 9;
    }
}
