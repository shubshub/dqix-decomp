#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* func_ov000_02160130();
extern "C" void* func_ov000_02160f20(void* work);
struct Struct_ov000_0215440c_2;
extern "C" void* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
struct Struct_ov000_0215440c;
extern "C" void* func_ov000_021600f8(Struct_ov000_0215440c*, int);
struct GameState;
extern "C" void* func_0200fea4(GameState*, int);
extern "C" void SePlayer_LoadExtraArchiveB(void* obj, int a, int b);
extern "C" void func_0205eabc(void* obj, void* target, int arg);
extern "C" void* func_02079e2c(char*, int);
extern "C" int func_ov025_021eb42c(void* self, short b, short c);
extern "C" int func_ov025_021eb148(void*, short, int, unsigned char);
extern "C" void* func_ov000_0215ffa0(void* node);
extern "C" void* func_ov000_0215fff4(void* node, int limit, int idx);
extern "C" int func_ov000_0215fd90(void* obj, int flag);
extern "C" void func_ov025_021ed124(unsigned char* obj);
extern "C" void func_ov025_021ebab4(char* obj);
extern "C" void func_ov025_021ed31c(char*, int);
extern "C" void func_ov025_021ed324(void* obj, const char* name);
extern "C" void func_ov025_021ed314(char*, int);
struct Struct_ov000_0216fe48;
extern "C" void func_ov000_0216fe48(Struct_ov000_0216fe48*);
struct Struct_ov000_0216fd0c;
extern "C" void func_ov000_0216fd0c(Struct_ov000_0216fd0c*);
#if defined(jpn)
struct SafeAllocator;
extern int data_ov025_021efb88;
#else
#endif
extern "C" void* func_ov000_02160f08(void* work);
extern "C" short* func_ov025_021dafd0(char*, int);
extern "C" void func_ov025_021ded50(void* work, void* rec);

extern int data_ov025_021ef990;
extern int data_ov025_021ef9a4;
extern int data_ov025_021ef9c0;
extern int g_sePlayer;
extern int data_ov025_021ef9a8[6];
extern int data_ov025_021ef8b4;
extern int data_ov025_021ef8ca;

static inline int inline_ov000_0215f57c(int v) {
    return v >= 0xc0 && v <= 0xc7;
}

#if defined(jpn)
enum { Enum_ov025_021e8d20_20 = 0x8 };
#else
enum { Enum_ov025_021e8d20_20 = 0x14 };
#endif

struct Slot {
    unsigned short type;
    short pad2;
    short id;
    short pad6;
    char pad8;
    unsigned char count;
    char padA[2];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_c_4_ : 1;
    unsigned char unknown_c_5_ : 1;
    char padD[3];
    struct Struct_ov000_0215b278* head;
};

struct Struct_ov000_0215b278 {
    char pad0[0x20];
    unsigned short id;
    char unknown_22_[10];
    unsigned char unknown_2c_;
    char unknown_2d_[3];
    struct Struct_ov000_0215b278* next;
};

struct Entry {
    char pad0[0x14];
    unsigned int unknown_14_;
    unsigned int f18;
    unsigned int unknown_1c_;
    unsigned int unknown_20_0_ : 10;
};

struct Struct_ov014_02185c90_4 {
    short a;
    short b;
    short c;
};

struct Struct_ov000_0215ab88 {
    char pad0[2];
    short id;
    char pad4[0x134];
    char* unknown_138_;
    char unknown_13c_[Enum_ov025_021e8d20_20];
    char* extra;
};

// USA: func_ov025_021e8d20
extern "C" ARM void func_ov025_021e8d20(char* self, char* arg) {
    char* var0;
    int in;
    int var2;
    void* gs = GameState::GetInstance();
    ActionDataTables* data = func_020797dc();
    void* work = func_ov000_02160130();
    Slot* slot = (Slot*)func_ov000_02160f20(work);
    *(char**)self = arg;
    *(int*)(self + 4) = *(int*)(arg + 8);
    int flag = 0;
    data_ov025_021ef9a4 = 0;
    data_ov025_021ef990 = 0;
    data_ov025_021ef9c0 = 0;
    *(int*)(self + 0x1c4) = 0;
    *(int*)(self + 0x1d8) = 0;
    *(short*)(self + 0x21c) = 1;
    *(short*)(self + 0x21e) = 0;
    *(short*)(self + 0x220) = 0x1e;
    *(short*)(self + 0x222) = -1;
    self[0x5ca] = 0;
    self[0x5cb] = 0;
    self[0x5cc] = 0;
    self[0x5d0] = 0;
    self[0x5d1] = 0;
    *(int*)(self + 0x5e4) = 0;
    Struct_ov000_0215b278* first = (Struct_ov000_0215b278*)func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0);
    if (first != 0) {
        if (inline_ov000_0215f57c(first->id)) {
            flag = 1;
            void* obj = ((GameState*)gs)->GetGameObjectByIndex(first->id);
            if (obj != 0) {
                int a = ((Object3D*)obj)->GetSoundGroup();
                int b = ((Object3D*)obj)->GetSoundArchive();
                SePlayer_LoadExtraArchiveB(&g_sePlayer, a, b);
            }
        }
    }
    if (slot->type == 1 || slot->type == 2) {
        *(int*)(self + 0x224) = 1;
    } else {
        *(int*)(self + 0x224) = 0;
    }
    Entry* entry = (Entry*)func_02079e2c((char*)data, (short)slot->type);
    *(Entry**)(self + 8) = entry;
    if ((entry != 0 && ((entry->f18 << 16) >> 28) == 2) || slot->type == 0x1f8 || slot->type == 0x392) {
        int low = 0;
        func_ov000_02160094((Struct_ov000_0215440c_2*)slot, low);
        Struct_ov000_0215b278* n = (Struct_ov000_0215b278*)func_ov000_02160094((Struct_ov000_0215440c_2*)slot, low);
        if (n->id <= 3) low = 1;
        if (low != 0) {
            func_ov025_021eb42c(self, 4, 0x14);
            *(int*)(self + 0x1c4) |= 2;
        } else {
            func_ov025_021eb42c(self, 4, 0x6f);
        }
    }
    for (int i = 0; i < slot->count; i++) {
        char* node = (char*)func_ov000_021600f8((Struct_ov000_0215440c*)slot, i);
        if (node == 0) continue;
        unsigned char* kinds = (unsigned char*)node + 0x14;
        int j = 1;
        for (; j < (unsigned char)node[0x17]; j++) {
            int k = kinds[j];
            if (k == 3) {
                unsigned short prev = *(unsigned short*)(node + (j - 1) * 2 + 0xe);
                int var21 = prev <= 3 ? 1 : 0;
                if (var21 == 0) {
                    Struct_ov000_0215ab88* c = (Struct_ov000_0215ab88*)func_0200fea4((GameState*)gs, prev);
                    if (c != 0 && c->id == 0xf4) {
                        func_ov025_021eb148(self, 0x1a, 0xcfe5, 1);
                    }
                    flag = 1;
                } else {
                    func_ov025_021eb42c(self, 0x22, 1);
                }
            } else if (k == 2) {
                func_ov025_021eb148(self, 0x20, 0x2c6, 3);
            } else if (!(k != 5 && k != 4)) {
                short prev = *(short*)(node + (j - 1) * 2 + 0xe);
                in = 0;
                if (prev >= 0) in = prev <= 3;
                if (in == 0) flag = 1;
                func_ov025_021eb148(self, 0x23, 0x4d8, 3);
            }
        }
        {
            void* cid = func_ov000_0215ffa0(node);
            Struct_ov000_0215ab88* c = (Struct_ov000_0215ab88*)((GameState*)gs)->GetCombatantByIndex((int)cid);
            if (c != 0 && (*(unsigned int*)(c->unknown_138_ + 0x18) & 0x20)) {
                func_ov025_021eb148(self, 0x1f, 0xb2c, 3);
                *(short*)(self + 0x21c) = 0x1f;
            }
        }
        for (int k = 0; k < 3; k++) {
            var2 = (unsigned char)k;
            int m = 0;
            var0 = node + k;
            for (; m < (unsigned char)var0[0x18]; m++) {
                void* f = func_ov000_0215fff4(node, m, var2);
                if (f != 0 && f != 0) {
                    if (func_ov000_0215fd90(f, 0xd)) {
                        func_ov025_021eb42c(self, 0x1b, 0x3c);
                    }
                    if (func_ov000_0215fd90(f, 0xc)) {
                        func_ov025_021eb148(self, 0x19, 0x38e, 2);
                    } else if (func_ov000_0215fd90(f, 6) == 0) {
                        func_0205eabc(&g_sePlayer, 0, 0);
                        if (((unsigned char*)f)[0x1c] != 0 && flag != 0) {
                            unsigned int t = slot->type;
                            if (t == 0xf4 || t == 0xf5 || t == 0x48 || t == 0x70) {
                                func_ov025_021eb42c(self, 0x24, 0xb);
                            }
                        }
                    }
                }
            }
        }
    }
    memset(self + 0x1c8, 0, 0x10);
    data_ov025_021ef9a8[0] = 0;
    data_ov025_021ef9a8[1] = -1;
    data_ov025_021ef9a8[2] = 0;
    data_ov025_021ef9a8[3] = 0;
    data_ov025_021ef9a8[4] = 0;
    data_ov025_021ef9a8[5] = 0;
    func_ov025_021ed124((unsigned char*)(self + 0x5e8));
    func_ov025_021ebab4(self + 0x22c);
    *(char**)(self + 0x538) = self + 0x5e8;
    *(int*)(self + 0x540) = 0;
    *(int*)(self + 0x544) = 0;
    *(int*)(self + 0x548) = 0;
    *(int*)(self + 0x54c) = 0;
    *(int*)(self + 0x550) = 0;
    *(short*)(self + 0x554) = -1;
    *(short*)(self + 0x556) = -1;
    *(int*)(self + 0x558) = 0;
    *(short*)(self + 0x55c) = -1;
    *(short*)(self + 0x55e) = -1;
    *(int*)(self + 0x560) = 0;
    *(short*)(self + 0x564) = 0;
    *(short*)(self + 0x566) = 0;
    *(short*)(self + 0x568) = 0;
    *(short*)(self + 0x56c) = 0;
    *(short*)(self + 0x56a) = 0;
    *(short*)(self + 0x572) = 0;
    *(short*)(self + 0x570) = 0;
    *(short*)(self + 0x56e) = 0;
    self[0x574] = 0;
    self[0x575] = 0;
    self[0x578] = 0;
    entry = (Entry*)func_02079e2c((char*)data, (short)slot->type);
    if (entry != 0) {
        unsigned int kind = entry->unknown_14_ >> 28;
        if (!(kind != 3 && kind != 4)) {
            if (((entry->f18 << 20) >> 25) == 1) self[0x53d] = 1;
        }
    }
    if (slot->type == 1 && first != 0) {
        Struct_ov000_0215ab88* c = (Struct_ov000_0215ab88*)(void*)func_0200ff1c((GameState*)gs, first->id);
        if (c != 0) {
            char* p = c->extra + 0x294;
            if (p != 0) {
                unsigned int f = (*(unsigned int*)(p + 8) << 23) >> 27;
                if (f == 4 || f == 10) self[0x53d] = 1;
            }
        }
    }
    if ((slot->b1 && slot->b2) || (slot->unknown_c_4_ && slot->unknown_c_5_)) {
        self[0x5d0] = 1;
    }
    func_ov025_021ed31c(self + 0x5e8, (int)(self + 0x798));
    func_ov025_021ed324(self + 0x5e8, 0);
    func_ov025_021ed314(self + 0x5e8, (int)slot);
    func_ov000_0216fe48((Struct_ov000_0216fe48*)(self + 0x798));
    func_ov000_0216fd0c((Struct_ov000_0216fd0c*)(self + 0x798));
    self[0x87c] = 0;
    *(int*)(self + 0x880) = -1;
    void* loader = BackgroundLoader::GetInstance();
    int id = 0;
    Struct_ov000_0215b278* var36 = (Struct_ov000_0215b278*)func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0);
    void* var37 = func_ov000_02160f08(work);
    short* e = 0;
    if (var36 != 0) e = func_ov025_021dafd0((char*)var37, var36->id);
    if (e != 0) id = e[0x2c / 2];
    if (slot->id != 0) id = slot->id;
    if (id > 0) {
        if (id == *(int*)(self + 0x884)) {
            func_ov025_021ed324(self + 0x5e8, self + 0x83c);
#if !defined(jpn)
            *(short*)(self + 0x794) = id;
#endif
            self[0x87c] = 1;
        } else {
            *(int*)(self + 0x884) = id;
#if defined(jpn)
            *(int*)(self + 0x880) = ((BackgroundLoader*)loader)->QueueLoadFile((const char*)&data_ov025_021efb88, (SafeAllocator*)0);
#else
            *(int*)(self + 0x880) = ((BackgroundLoader*)loader)->QueueLoadFileInGP2((const char*)&data_ov025_021ef8b4, (const char*)&data_ov025_021ef8ca, (SafeAllocator*)0);
#endif
            if (*(int*)(self + 0x880) < 0) self[0x87c] = 1;
        }
    } else {
        *(int*)(self + 0x884) = 0;
        self[0x87c] = 1;
        func_ov025_021ed324(self + 0x5e8, 0);
    }
    for (Struct_ov000_0215b278* n = slot->head; n != 0; n = n->next) {
        void* c = ((GameState*)gs)->GetCombatantByIndex(n->id);
        if (c != 0) {
            ((Object3D*)c)->EnableFlag(0x800);
            if (n->unknown_2c_ != 0) {
                int var41 = n->id <= 3 ? 1 : 0;
                if (var41 != 0) {
                    void* t = func_02079e2c((char*)data, 0x39a);
                    if (t != 0) {
                        Struct_ov014_02185c90_4 rec;
                        rec.a = n->id;
                        rec.b = 0x39a;
                        rec.c = ((Entry*)t)->unknown_20_0_;
                        func_ov025_021ded50(work, &rec);
                    }
                }
            }
        }
    }
    *(short*)(self + 0x57c) = 0;
    *(short*)(self + 0x57e) = 0;
    *(short*)(self + 0x580) = 0x333;
    self[0x582] = 0;
    self[0x5c5] = 0;
    self[0x5c6] = 0;
    *(int*)(self + 0x228) = 0;
    *(short*)(self + 0x5c8) = 0xff;
    *(short*)(self + 0x5ce) = 0;
}
