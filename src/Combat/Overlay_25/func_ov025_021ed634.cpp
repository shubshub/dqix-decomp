#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov025_021ed634 { char pad[0xc]; short v; };
struct Struct_ov000_02159f7c;
struct Struct_020e4e38;
struct Struct_02054000;
struct StoreStruct;

struct Struct_ov000_0215440c {
    unsigned short id;
    short s2;
    char pad4[2];
    short unknown_6_;
    char pad8;
    unsigned char count;
};
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c_5 {
    char pad0[0xe];
    short unknown_e_;
    char pad10[8];
    unsigned char count;
    char unknown_19_[4];
    unsigned char bit0 : 1;
};
struct Struct_ov000_0215440c_4 {
    char pad0[0x18];
    float f18;
    char unknown_1c_[4];
    unsigned short unknown_20_;
};
struct Struct_ov025_021ebb90 {
    char pad[0x18];
    unsigned int pad5 : 5;
    unsigned int kind : 7;
};
struct Struct_ov025_021ed634_5 { char pad[0xc]; short v; };
struct Struct_ov025_021ed634_6 { char pad[0x2c]; short v; };
struct Struct_ov025_021ed634_7 { char pad[0x18]; short v; };
struct Struct_ov025_021ed634_8 { char pad[0x138]; unsigned char* unknown_138_; char unknown_13c_[0xc]; char* unknown_148_; char unknown_14c_[0x41]; unsigned char unknown_18d_; };

struct Struct_ov025_021e9fc4 {
    unsigned short ids[16];
    short unknown_20_[16];
    short unknown_40_[16];
    short unknown_60_[16];
    unsigned short unknown_80_[16];
    unsigned char types[16];
    Struct_ov025_021ed634* unknown_b0_[16];
    int unknown_f0_[16];
    char unknown_130_[0x24];
    short unknown_154_;
    char unknown_156_[2];
    int unknown_158_;
    char unknown_15c_[2];
    unsigned short unknown_15e_;
    unsigned short unknown_160_;
    unsigned short unknown_162_;
    Struct_ov000_0215440c* list;
    void* unknown_168_;
    char pad16c[0x40];
    unsigned short unknown_1ac_;
};

struct Struct_ov025_021ed634_2 {
    int f0;
    int pad4;
    int f8;
    int unknown_c_;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
};
struct Struct_ov025_021ed634_3 { void* a; void* b; int c; };
struct Struct_ov025_021ef020 { short v[16]; };
struct Struct_ov025_021ed634_4 {
    unsigned char unknown_0_[0x30];
    unsigned char unknown_30_;
    unsigned char unknown_31_;
};

extern Struct_ov025_021ef020 data_ov025_021ef040;
extern Struct_ov025_021ef020 data_ov025_021ef060;
extern Struct_ov025_021ef020 data_ov025_021ef020;

extern "C" int func_ov025_021ed2f4(void* obj);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* obj);
extern "C" ARM void* __clear(void* dst, int count);
extern "C" void func_ov025_021ed1f0(void* self);
extern "C" Struct_ov000_0215440c_4* func_ov000_02160094(Struct_ov000_0215440c_2* list, int index);
extern "C" Struct_ov000_0215440c_5* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" void func_ov025_021ed2a0(char* self);
extern "C" void* func_ov000_0215fff4(void* obj, int limit, int idx);
extern "C" short func_ov000_0215ffa0(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int func_ov000_02159f7c(void* obj, Struct_ov000_02159f7c* bits);
extern "C" int func_ov000_0215fd90(void* obj, int flag);
extern "C" void func_020465c0(StoreStruct* base, int index, int value);
extern "C" void NameText_InitFromPartyMember(void* obj, int id);
class GameObject;
extern "C" GameObject* func_0200fea4(GameState* gs, int id);
extern "C" GameObject* func_0200ff1c(GameState* gs, int id);
extern "C" void func_020e4ce8(void* dst, void* src, int flag);
extern "C" void func_02046504(char* g, char* s);
extern "C" void func_020464dc(void*, signed char);
extern "C" void func_0204653c(void* g, char* s);
extern "C" int func_ov000_0215fb9c(int obj, unsigned short id);
extern "C" void func_020488ec(char* s);
extern "C" void func_02046558(void* g, char* s);
extern "C" Struct_ov025_021ebb90* func_02079e2c(char* table, int key);
extern "C" void func_020e4e38(void* obj, Struct_020e4e38* src);
extern "C" void func_02046520(char* g, char* s);
extern "C" void* func_ov000_02160130(void);
extern "C" char* func_ov000_02160f08(void* w);
extern "C" void* func_ov025_021dafd0(char* obj, int id);
extern "C" Struct_ov025_021ed634_7* func_02054000(Struct_02054000* o);
extern "C" void NameText_Clear(void* p);
extern "C" void func_020dcf7c(int count, void* buf);
extern "C" unsigned char GameState_GetPartyOrder(char*, void*);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" char* func_ov000_0216fcfc(void* work, int key);
extern "C" unsigned int strlen(const char* s);
extern "C" int sprintf(char* buf, const char* fmt, ...);
#if !defined(jpn)
extern "C" void func_0204500c(void* g, char* s, int a, int b);
#endif
extern "C" void func_02042b98(void* self, int a, int b, int c, int d);

#if defined(jpn)
extern "C" void func_020464e8(char*, char*);
extern "C" void func_02047410(void*, int);
extern "C" int func_ov025_021ed5a4(int, char*);
extern "C" void* func_ov000_02171674(void*, int);
extern "C" void* func_ov000_0217199c(void*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020474a8(void*, int, char*, char*);
extern "C" void func_0204500c(void*, char*, int);
extern "C" void func_02043270(void*, int, int, int, int);
extern "C" char* strcpy(char*, const char*);
extern "C" char* strcat(char*, const char*);
extern char data_ov025_021efbfc[];
#endif

#if defined(jpn)
#define COPY_FIELD func_02046520
#define STATE_OFFSET 0x870
#else
#define COPY_FIELD func_0204653c
#define STATE_OFFSET 0x9a0
#endif

static inline int inline_ov025_021ed634(int x) { return x >= 0 && x <= 3; }
static inline int inline_ov025_021ed634_2(short x) { return x >= 0 && x <= 3; }
static inline int inline_ov025_021ed634_3(unsigned short x) { return x >= 0 && x <= 3; }

// USA: func_ov025_021ed634
extern "C" ARM void func_ov025_021ed634(Struct_ov025_021e9fc4* self) {
    if (func_ov025_021ed2f4(self) != 0) return;
    if (self->list == 0) return;
    GameState* gs = GameState::GetInstance();
    char* g = (char*)MessageSystem_GetInstance();
#if defined(jpn)

#else
    func_02046380(g);
#endif
#if defined(jpn)
    char output[0x100];
    char buf[0x100];
    Struct_ov025_021ef020 var13;
    Struct_ov025_021ef020 arrB;
    Struct_ov025_021ef020 arrA;
    char nameB[0x40];
    char nameA[0x40];
    char var5[0x24];
    char name[1];
#else
    char var6[0x80];
    char var7[0x80];
    char buf[0x100];
    char objB[12];
    char objA[12];
    char var11[12];
    Struct_ov025_021ed634_3 objD;
    Struct_ov025_021ef020 var13;
    Struct_ov025_021ef020 arrB;
    Struct_ov025_021ef020 arrA;
    char out[5];
    char name[1];
#endif
    __clear(name, 1);
    if (self->unknown_15e_ == 0) {
        int type = self->types[0];
        int id = self->ids[0];
        int v20 = self->unknown_20_[0];
        Struct_ov025_021ed634* ptr = self->unknown_b0_[0];
        short var22 = self->unknown_60_[0];
#if defined(jpn)
        int v40 = self->unknown_40_[0];
        int var24 = self->unknown_80_[0];
#else
        int var24 = self->unknown_80_[0];
        int v40 = self->unknown_40_[0];
#endif
        func_ov025_021ed1f0(self);
        if (id <= 0) return;
        Struct_ov000_0215440c_4* node = func_ov000_02160094((Struct_ov000_0215440c_2*)self->list, 0);
        int var27 = 0;
        int fp = 0;
        int var29 = 0;
        int var30 = 0;
        int var31 = 0;
        int flag = inline_ov025_021ed634(v20) ? 1 : 0;
        var13 = data_ov025_021ef040;
        int cnt[2];
        cnt[0] = 0;
        arrB = data_ov025_021ef060;
        short who;
        int sb = 0;
        int var36 = 0;
        int var37 = self->list->count;
        if (self->list->id == 0x61) {
            Struct_ov000_0215440c_5* var38 = func_ov000_021600f8(self->list, 0);
            if (var38 != 0) {
                if (var38->bit0 == 0) var36 = 1;
            }
        }
        if (var36 != 0 || self->list->id == 0x1b) {
            if (ptr != 0) fp = ptr->v;
        } else if (id == 0x172) {
            fp = self->unknown_f0_[0];
            func_ov025_021ed2a0((char*)self);
        } else if (self->list->id == 0x3a6) {
            for (int i = 0; i < self->list->count; i++) {
                Struct_ov000_0215440c_5* var40 = func_ov000_021600f8(self->list, i);
                if (var40 != 0 && var40->unknown_e_ == v20) {
                    for (int j = 0; j < var40->count; j++) {
                        Struct_ov025_021ed634* n = (Struct_ov025_021ed634*)func_ov000_0215fff4(var40, j, 0);
                        if (n != 0 && n->v >= 0) {
                            fp = n->v;
                            var27++;
                            break;
                        }
                    }
                    if (var27 != 0) break;
                }
            }
        } else if (type == 3) {
            if (ptr != 0) {
                int v = ptr->v;
                if (v >= 0) { if (v > 0) fp += v; }
                else { var30 -= v; var29++; }
            }
        } else {
            arrA = data_ov025_021ef020;
            cnt[1] = 0;
            for (int i = 0; i < self->list->count; i++) {
                Struct_ov000_0215440c_5* var45 = func_ov000_021600f8(self->list, i);
                if (var45 == 0) continue;
                who = func_ov000_0215ffa0(var45);
                if (inline_ov025_021ed634_2(who) != 0) {
                    if (flag == 0) continue;
                }
                if (inline_ov025_021ed634_2(who) == 0) {
                    if (flag != 0) continue;
                }
                for (int k = 0; k < var45->count; k++) {
                    Struct_ov025_021ed634* n = (Struct_ov025_021ed634*)func_ov000_0215fff4(var45, k, 0);
                    if (n == 0) continue;
                    int v = n->v;
                    if (v >= 0) { if (v > 0) fp += v; }
                    else { var30 -= v; var29++; }
                    void* obj = func_ov017_021b8470(GetGameResources()->unknown_ptr_3718);
                    if (n->v > 0) {
                        int found = 0;
                        for (int m = 0; m < cnt[0]; m++) {
                            if (who == var13.v[m]) { found = 1; break; }
                        }
                        if (found == 0) { var13.v[cnt[0]] = who; cnt[0]++; }
                    } else {
                        if (func_ov000_02159f7c(obj, (Struct_ov000_02159f7c*)n) != 0 || func_ov000_0215fd90(n, 4) != 0) {
                            int found = 0;
                            for (int m = 0; m < sb; m++) {
                                if (who == arrB.v[m]) { found = 1; break; }
                            }
                            if (found == 0) { arrB.v[sb] = who; sb++; }
                        }
                    }
                    if (flag == 0) {
                        if (func_ov000_0215fd90(n, 2) != 0) {
                            int found = 0;
                            for (int m = 0; m < cnt[1]; m++) {
                                if (who == arrA.v[m]) { found = 1; break; }
                            }
                            if (found == 0) { arrA.v[cnt[1]] = who; cnt[1]++; var31++; }
                        }
                    }
                }
            }
        }
        if (var29 > 0) {
            int var56 = var30 / var29;
            if (var56 == 0 && var30 != 0) var56 = -1;
            #if defined(jpn)
func_02047410(g, var56);
#else
func_020465c0((StoreStruct*)g, 0, var56);
#endif
        } else if (cnt[0] != 0) {
            int var57 = fp / cnt[0];
            if ((unsigned int)(id - 0x261) <= 1) var57 = fp;
            if (var57 == 0 && fp != 0) var57 = 1;
            #if defined(jpn)
func_02047410(g, var57);
#else
func_020465c0((StoreStruct*)g, 0, var57);
#endif
        } else {
            #if defined(jpn)
func_02047410(g, fp);
#else
func_020465c0((StoreStruct*)g, 0, fp);
#endif
        }
        if (type == 5) {
            v20 = var13.v[0];
            if (v20 < 0) {
                v20 = arrB.v[0];
                if (v20 < 0) {
                    Struct_ov000_0215440c_5* var58 = func_ov000_021600f8(self->list, 0);
                    if (var58 != 0) v20 = func_ov000_0215ffa0(var58);
                }
            }
#if defined(jpn)
        }

#else
            if (inline_ov025_021ed634(v20)) {
                NameText_InitFromPartyMember(objA, v20);
            } else {
                GameObject* c = func_0200fea4(gs, v20);
                if (c != 0) {
                    func_020e4ce8(objA, c, 1);
                    ((Struct_ov025_021ed634_2*)g)->f20 = (int)objA;
                }
            }
            ((Struct_ov025_021ed634_2*)g)->f10 = (int)objA;
        }

#endif
#if defined(jpn)
        func_020464e8((char*)g, name);
#else
        func_02046504((char*)g, name);
#endif
#if defined(jpn)
        if (v40 < 0) {
            if (node != 0) v40 = node->unknown_20_;
        }
        if (v40 >= 0) {
            if (func_ov025_021ed5a4(v40, nameB)) func_020464e8((char*)g, nameB);
            func_020464dc(g, (signed char)v40);
        }

#else
        if (v40 < 0) {
            if (node != 0) v40 = node->unknown_20_;
            int b = inline_ov025_021ed634(v40) ? 1 : 0;
            if (b != 0) {
                NameText_InitFromPartyMember(objB, v40);
                ((Struct_ov025_021ed634_2*)g)->f0 = (int)objB;
            } else {
                GameObject* c = func_0200fea4(gs, v40);
                if (c != 0) {
                    func_020e4ce8(objB, c, 1);
                    ((Struct_ov025_021ed634_2*)g)->f0 = (int)objB;
                }
            }
        }
        if (v40 >= 0) {
            func_020464dc(g, (signed char)v40);
            int b = inline_ov025_021ed634(v40) ? 1 : 0;
            if (b != 0) {
                NameText_InitFromPartyMember(objB, v40);
                ((Struct_ov025_021ed634_2*)g)->f0 = (int)objB;
            } else {
                GameObject* c = func_0200fea4(gs, v40);
                if (c != 0) {
                    func_020e4ce8(objB, c, 1);
                    ((Struct_ov025_021ed634_2*)g)->f0 = (int)objB;
                }
            }
        }

#endif
        if ((unsigned int)(id - 0xf1) <= 1) {
            int t = self->list->unknown_6_;
            if (t >= 0) v20 = t;
        }
        COPY_FIELD(g, name);
        if (func_ov000_0215fb9c((int)func_ov017_021b8470(GetGameResources()->unknown_ptr_3718), self->list->id) != 0) {
            Struct_ov025_021ed634_8* c = (Struct_ov025_021ed634_8*)func_0200fea4(gs, v20);
            if (c != 0) {
                c->unknown_138_[0x25] = c->unknown_18d_;
                func_020488ec((char*)c);
                COPY_FIELD(g, (char*)c + 0x14c);
            }
#if defined(jpn)

#else
            func_020e4ce8(objA, c, 1);
            ((Struct_ov025_021ed634_2*)g)->f10 = (int)objA;
#endif
        } else {
#if defined(jpn)
            if (func_ov025_021ed5a4(v20, nameA)) func_02046520(g, nameA);
        }

#else
            if (inline_ov025_021ed634(v20)) {
                NameText_InitFromPartyMember(objA, v20);
            } else {
                GameObject* c = func_0200fea4(gs, v20);
                func_020e4ce8(objA, c, 1);
            }
            if (v40 == v20) ((Struct_ov025_021ed634_2*)g)->f10 = (int)objB;
            else ((Struct_ov025_021ed634_2*)g)->f10 = (int)objA;
        }

#endif
        if (id == 0xf2 || id == 0x207) {
            Struct_ov025_021ed634_8* c = (Struct_ov025_021ed634_8*)func_0200fea4(gs, v20);
            if (c != 0 && c->unknown_148_ != 0) COPY_FIELD(g, c->unknown_148_ + 0x2c);
        }
#if defined(jpn)
        func_0204653c(g, name);
#else
        func_02046558(g, name);
#endif
        ActionDataTables* data = func_020797dc();
        Struct_ov000_0215440c* l = self->list;
        Struct_ov025_021ebb90* row;
        if (l->id == 0x1f8 || l->id == 0x3a9 || l->id == 0x3a7 || l->id == 0x3ac || l->id == 0x3ad || l->id == 0x392) {
            row = func_02079e2c((char*)data, l->s2);
        } else {
            row = func_02079e2c((char*)data, (short)l->id);
        }
        if (row != 0) {
#if defined(jpn)
            func_0204653c(g, *(char**)row);
#else
            func_020e4e38(var11, (Struct_020e4e38*)row);
            ((Struct_ov025_021ed634_2*)g)->f8 = (int)var11;
            ((Struct_ov025_021ed634_2*)g)->f18 = (int)var11;
#endif
        }
#if defined(jpn)
        func_02046504(g, name);
#else
        func_02046520(g, name);
#endif
#if defined(jpn)
        if (node != 0) {
            char* w = func_ov000_02160f08(func_ov000_02160130());
            int index = node->unknown_20_;
            char* entry;
            if (inline_ov025_021ed634(index)) {
                for (int n = 0; n < 4; n++) {
                    if (*(int*)(w + 0x9a4 + n * 0x488) == index) {
                        entry = w + 0x958 + n * 0x488;
                        goto found_entry;
                    }
                }
            }
            entry = 0;
found_entry:
            if (entry != 0) {
                void* a = func_ov000_02171674(entry, *(signed char*)(entry + 0x20));
                void* b = func_ov000_0217199c(entry, *(short*)(entry + 0x1e));
                if (*(signed char*)self->pad16c != 0) {
                    func_02046504(g, self->pad16c);
                    if (*(short*)((char*)self->list + 4) != 0)
                        MessageSystem_SetStringArgument((Obj02046574*)g, 0, self->pad16c);
                } else if (a != 0) func_02046504(g, *(char**)a);
                else if (b != 0) func_02046504(g, *(char**)b);
            }
        }

#else
        if (node != 0) {
            char* w = func_ov000_02160f08(func_ov000_02160130());
            Struct_ov025_021ed634_6* e = (Struct_ov025_021ed634_6*)func_ov025_021dafd0(w, node->unknown_20_);
            if (inline_ov025_021ed634_3(node->unknown_20_)) {
                int cnt = e->v;
                if (self->unknown_1ac_ != 0) cnt = (short)self->unknown_1ac_;
                if (id == 0x257 || id == 0xc) {
                    GameObject* c = func_0200ff1c(gs, node->unknown_20_);
                    if (c != 0) {
                        Struct_ov025_021ed634_7* s = func_02054000((Struct_02054000*)c);
                        if (s != 0) cnt = s->v;
                    }
                }
                if (cnt > 0) {
                    NameText_Clear(&objD);
                    __clear(var6, 0x80);
                    __clear(var7, 0x80);
                    objD.a = var6;
                    objD.b = var7;
                    func_020dcf7c(cnt, &objD);
                    ((Struct_ov025_021ed634_2*)g)->f18 = (int)&objD;
                }
            }
        }

#endif
#if defined(jpn)
        if ((id == 9 && var31 >= 2) || (id == 4 && sb >= 2) || (id == 7 && sb >= 2)
            || (row != 0 && row->kind == 1 && id == 0x1b && sb >= 2)) {
            strcpy(var5, nameA);
            strcat(var5, data_ov025_021efbfc);
            func_02046520(g, var5);
        }

#else
        if ((id == 9 && var31 >= 2) || (id == 4 && sb >= 2) || (id == 7 && sb >= 2)
            || ((id == 0xf0 || id == 0x209) && var37 >= 2)
            || (row != 0 && row->kind == 1 && (id == 0x20c || id == 0x11f || id == 0x11d || id == 0x20b) && var37 >= 2)
            || (row != 0 && row->kind == 1 && id == 0x1b && sb >= 2)
            || (row != 0 && row->kind == 1 && id == 0x26d && sb >= var37)) {
            *(g + 0x1000 + 0x9d7) = 1;
        }
        int n5 = GameState_GetPartyOrder((char*)gs, out);
        unsigned char var83 = 0;
        unsigned char var84 = 0;
        unsigned char* tb = (unsigned char*)func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
        char* var86 = func_ov000_02160f08(func_ov000_02160130());
        for (int q = 0; q < n5; q++) {
            Struct_ov025_021ed634_5* e = (Struct_ov025_021ed634_5*)func_ov025_021dafd0(var86, (unsigned char)out[q]);
            if (e != 0 && func_020a35e0(tb, out[q]) != 0) {
                ++var84;
                if (e->v > 0) ++var83;
            }
        }
        ((Struct_ov025_021ed634_4*)g)->unknown_30_ = var84;
        ((Struct_ov025_021ed634_4*)g)->unknown_31_ = var83;

#endif
        char* fmt = func_ov000_0216fcfc(self->unknown_168_, (short)id);
        if (fmt == 0) return;
        if (strlen(fmt) == 0) return;
#if defined(jpn)
        __clear(output, 0x100);
#endif
        if (id == 0x205 || id == 0x1be || id == 0x1bf || id == 0x224 || id == 0x1c0 || id == 0x225 || id == 0x263
            || (unsigned int)(id - 0x266) <= 3) {
            __clear(buf, 0x100);
            void* obj = func_ov017_021b8470(GetGameResources()->unknown_ptr_3718);
            if (id == 0x205) {
                sprintf(buf, fmt, (double)node->f18);
            } else if (obj != 0) {
                sprintf(buf, fmt, (double)*(float*)((char*)obj + 0x8e3c));
            }
            if (id == 0x1bf || id == 0x224 || id == 0x1c0 || id == 0x225 || (unsigned int)(id - 0x264) <= 7) {
                Struct_ov025_021ed634_8* c = (Struct_ov025_021ed634_8*)func_0200fea4(gs, self->list->unknown_6_);
                if (c != 0 && c->unknown_148_ != 0) COPY_FIELD(g, c->unknown_148_ + 0x2c);
            }
#if defined(jpn)
            func_020474a8(g, 0xc, buf, output);
#else
            func_0204500c(g, buf, 0, 0xe3);
#endif
        } else {
#if defined(jpn)
            func_020474a8(g, 0xc, fmt, output);
#else
            func_0204500c(g, fmt, 0, 0xe3);
#endif
        }
#if defined(jpn)
        func_0204500c(g, output, 0);
        *(g + 0x17e1) = 0;
        *(int*)(g + 0x1730) = 0xc;
        *(int*)(g + 0x1734) = 0x12;
        func_02043270(g, *(int*)(g + 0x1730), 0x92, 0x100, 0x30);
        *(g + 0x17e2) = 0;
        *(unsigned char*)(g + 0x1789) |= 2;
        *(g + 0x17f6) = 1;
        *(int*)(g + 0x868) = 1;
#else
        *(g + 0x1000 + 0x9b1) = 0;
        func_02042b98(g, 2, 0x92, 0xfc, 0x4a);
        *(g + 0x1000 + 0x9b2) = 0;
        *(unsigned char*)(g + 0x1000 + 0x95b) |= 2;
        *(g + 0x1000 + 0x9c5) = 1;
        *(int*)(g + 0x998) = 1;
#endif
        self->unknown_160_ = self->unknown_162_;
        if (var24 != 0) self->unknown_160_ = var24;
        self->unknown_158_ = (int)ptr;
        self->unknown_154_ = var22;
        self->unknown_15e_ = 1;
    } else if (self->unknown_15e_ == 1 && *(int*)(g + STATE_OFFSET) == 0) {
        unsigned int var92 = gs->GetEffectiveDeltaTime();
        unsigned int t = self->unknown_160_;
        if (var92 < t) {
            self->unknown_160_ = t - var92;
        } else {
            self->unknown_160_ = 0;
            self->unknown_15e_ = 0;
            self->unknown_158_ = 0;
            self->unknown_154_ = 0;
        }
    }
}
