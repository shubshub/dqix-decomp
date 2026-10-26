#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov006_0215e69c_4 {
    short id;
    char pad2[0x14 - 0x2];
    short count;
};

struct Struct_ov006_0215e69c {
    char pad0[0x14];
    unsigned char active;
};

struct Struct_ov006_0215e69c_2 {
#if defined(jpn)
    char pad0[0x962];
    unsigned short flags;
    char unknown_964_[0x109c - 0x964];
#else
    char pad0[0xae2];
    unsigned short flags;
    char unknown_ae4_[0x12a0 - 0xae4];
#endif
    Struct_ov006_0215e69c task;

    Struct_ov006_0215e69c* inline_ov006_0215e69c_2() { return &task; }
};

struct Struct_ov006_0215e69c_3 {
    char pad0[0x4];
    void** buffer;
#if defined(jpn)
    Struct_ov006_0215e69c_2* ctx;
    void* elements;
    char pad10[0x2c - 0x10];
    Struct_ov006_0215e69c_4* entry;
    char unknown_30_[0x34 - 0x30];
    char loader[0x6c - 0x34];
    char table[0x140 - 0x6c];
    char out[0x164 - 0x140];
    char lookup[0x17c - 0x164];
#else
    char pad8[0x10 - 0x8];
    Struct_ov006_0215e69c_2* ctx;
    void* elements;
    char pad18[0x34 - 0x18];
    Struct_ov006_0215e69c_4* entry;
    char unknown_38_[0x3c - 0x38];
    char loader[0x74 - 0x3c];
    char table[0x14c - 0x74];
    char out[0x170 - 0x14c];
    char lookup[0x17c - 0x170];
#endif
    char list[0x1ec - 0x17c];
    short lookupId;
    char unknown_1ee_[0x37e - 0x1ee];
    short message;
    char unknown_380_[0x382 - 0x380];
    short unknown_382_;
    char unknown_384_[0x387 - 0x384];
    unsigned char unknown_387_;
    unsigned char unknown_388_;
    unsigned char unknown_389_;
    char unknown_38a_[0x38f - 0x38a];
    unsigned char mode;
    unsigned char state;
    char unknown_391_;
    unsigned char unknown_392_;
    char unknown_393_;
    unsigned short flags;
    unsigned char variant;
    unsigned char shown;
    char unknown_398_[0x3b4 - 0x398];
    int busy;
    char unknown_3b8_[0x428 - 0x3b8];
    int taskId;
    unsigned char unknown_42c_;
    unsigned char unknown_42d_;
    unsigned char nextState;
    unsigned char unknown_42f_;

    int inline_ov006_0215e69c() { return (flags & 0x40) != 0; }
};

extern "C" int func_ov006_02153f24(void* table, int id);
struct Struct_ov006_0215a33c;
extern "C" void func_ov006_0215a33c(Struct_ov006_0215a33c*, int);
extern "C" int func_ov006_0215a384(Struct_ov006_0215e69c_3* self, int arg1);
extern "C" void func_ov006_0215fe34(Struct_ov006_0215e69c_3* self, void* list);
extern "C" int func_ov006_0215fecc(Struct_ov006_0215e69c_3* self);
extern "C" void func_ov006_02159db0(Struct_ov006_0215e69c_3* self);
extern "C" int func_ov006_02159e50(Struct_ov006_0215e69c_3* self);
void* GetBTRandom(void);
struct Random;
unsigned int NextRandomMax(Random*, int);
struct Struct_0207fdcc_2;
extern "C" void func_02080c04(Struct_0207fdcc_2*, int);
extern "C" void func_02080c20(Struct_0207fdcc_2*, int);
extern "C" int func_ov006_02158c70(Struct_ov006_0215e69c_3* self);
extern "C" void func_ov006_02153cbc(void* table, int a, int b, void* out);
extern "C" void func_ov006_0215759c(void* list, Struct_ov006_0215e69c_4* entry, int count);
extern "C" void func_ov006_02158de0(Struct_ov006_0215e69c_3* self);
extern "C" unsigned int* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int bits);
struct Struct020a9ea4;
extern "C" void func_020a9ea4(Struct020a9ea4*);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int func_020aad1c(void* loader, void* name, int a, int b);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void** func_020e5294(void* lookup, int id);
#if defined(jpn)
struct Container020e0310;
extern "C" int KeyTable_Get(Container020e0310*, int);
#endif
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void func_020e4864(void* src, void* dst, int a, int b, int c, int d);
struct Container02080f8c;
extern "C" void func_02080f8c(Container02080f8c*, int, int);
extern "C" void func_020805f4(void* elements, int key);
extern "C" void func_020813ec(void* elements, int key);
extern "C" void func_ov006_021571fc(char*);
struct Struct0209c830;
extern "C" void func_0209c830(Struct0209c830*, int);
extern "C" void func_0207fdcc(Struct_0207fdcc_2*, int);
extern "C" void func_ov006_0215728c(void*);
extern "C" void func_02080c68(void* elements, int key, int value);
struct Struct_ov006_0215e5f8;
extern "C" void func_ov006_0215e5f8(Struct_ov006_0215e5f8*, Struct_0207fdcc_2*, int, unsigned char*);

static inline short* inline_ov006_0215cc70_2(Struct_ov006_0215e69c_3* self) { return (short*)((char*)self + 0x382); }
static inline short* inline_ov006_0215cc70_3(Struct_ov006_0215e69c_3* self) { return (short*)self; }

static inline int inline_01ff91ac_4(Struct_ov006_0215e69c* task) { return task != 0 && task->active != 0; }

extern int g_fileLoadBuffer;
extern int g_bgmPlayer;

// USA: func_ov006_0215e69c
extern "C" ARM void func_ov006_0215e69c(Struct_ov006_0215e69c_3* self) {
    Struct_ov006_0215e69c_2* ctx = self->ctx;
    BackgroundLoader::GetInstance();

    if (self->state == 0) {
        self->busy = 0;
        if (func_ov006_02158c70(self)) {
            func_0207fdcc((Struct_0207fdcc_2*)self->elements, 0);
            func_0207fdcc((Struct_0207fdcc_2*)self->elements, 1);
            func_02080c68(self->elements, 9, 0);
            self->flags &= ~0x40;
            if (self->entry->count >= 0) {
                self->unknown_382_ = func_ov006_02153f24(self->table, self->entry->count);
                self->message = 0xd;
                self->unknown_392_ = 0;
                self->flags |= 0x20;
                self->state++;
                if (NextRandomMax((Random*)GetBTRandom(), 10000) / 100 < self->unknown_382_) {
                    self->flags |= 0x40;
                }
                func_ov006_0215a33c((Struct_ov006_0215a33c*)self, self->inline_ov006_0215e69c());
            } else {
                ctx->flags &= ~0x40;
                self->unknown_42d_ = 0;
                self->nextState = 100;
                self->state = 0x96;
                func_ov006_0215e5f8((Struct_ov006_0215e5f8*)self, (Struct_0207fdcc_2*)self->elements, 0, &self->shown);
            }
        }
    } else if (self->state == 1) {
        if (func_ov006_02158c70(self) && self->taskId == -1) {
            if (func_ov006_0215a384(self, self->inline_ov006_0215e69c())) {
                func_ov006_0215fe34(self, self->list);
            }
        } else if (self->taskId != -1) {
            if (func_ov006_0215fecc(self)) {
                self->message = self->variant + 0xe;
                self->unknown_392_ = 0;
                self->state++;
            }
        }
    } else if (self->state == 2) {
        if (func_ov006_02158c70(self)) {
            short id = 0x10;
            if (self->unknown_382_ >= 3 && self->unknown_382_ < 10) {
                id = 0x11;
            } else if (*inline_ov006_0215cc70_2(self) >= 10 && *inline_ov006_0215cc70_2(self) <= 99) {
                id = 0x12;
            } else if (inline_ov006_0215cc70_3(self)[0x382 / 2] == 100) {
                id = self->variant + 0x16;
            }
            self->message = id;
            self->unknown_392_ = 0;
            self->state++;
        }
    } else if (self->state == 3) {
        if (func_ov006_02158c70(self)) {
            short id = 0x13;
            self->state++;
            if (self->unknown_382_ == 100) {
                self->state = 6;
                id = 0x18;
            }
            self->message = id;
            self->unknown_392_ = 0;
        }
    } else if (self->state == 4) {
        if (func_ov006_02158c70(self)) {
            self->message = 0x14;
            self->unknown_392_ = 0;
            self->state++;
        }
    } else if (self->state == 5) {
        if (func_ov006_02158c70(self)) {
            self->message = 0x15;
            self->unknown_392_ = 0;
            self->state++;
        }
    } else if (self->state == 6) {
        func_ov006_02159db0(self);
        self->state++;
    } else if (self->state == 7) {
        int r = func_ov006_02159e50(self);
        if (r != -1) {
            if (r == 1) {
                unsigned char a;
                unsigned char b;
                if (self->inline_ov006_0215e69c()) {
                    func_ov006_02153cbc(self->table, self->entry->count, self->entry->id, self->out);
                } else {
                    func_ov006_02153cbc(self->table, self->entry->id, -1, self->out);
                }
                func_ov006_0215759c(self->list, self->entry, self->unknown_387_);
                a = self->unknown_388_;
                b = self->unknown_389_;
                func_ov006_02158de0(self);
                self->unknown_388_ = a;
                self->unknown_389_ = b;
                self->state++;
            }
        } else {
            self->message = 0x19;
            self->unknown_392_ = 0;
            self->flags = (self->flags | 0x20) & ~0x40;
            self->state = 0x5a;
        }
    } else if (self->state == 0x5a) {
        if (func_ov006_02158c70(self)) {
            func_02080c20((Struct_0207fdcc_2*)self->elements, 0);
            self->message = 1;
            self->unknown_392_ = 0;
            self->flags |= 0x20;
            self->state = 0x79;
        }
    } else if (self->state == 8) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            self->state++;
        }
    } else if (self->state == 9) {
        self->message = 0x36;
        self->unknown_392_ = 0;
        func_02080c04((Struct_0207fdcc_2*)self->elements, 0);
        self->state++;
    } else if (self->state == 0xa) {
        self->flags |= 0x200;
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() <= 0) {
            FlagWord_SetBits(GlobalFlags_GetInstance(), 0x80);
            func_020a9ea4((Struct020a9ea4*)self->loader);
            self->state++;
        }
    } else if (self->state == 0xb) {
        int size;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        size = 8;
        if (LinkSession_IsGuest(LinkSession_GetInstance())) {
            size = 0x14;
        }
        if (func_020aad1c(self->loader, &g_fileLoadBuffer, size, 0) == 1) {
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
            self->state++;
            self->flags &= ~0x200;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (self->state == 0xc) {
        self->message = 0x37;
        self->unknown_392_ = 0;
        self->state++;
    } else if (self->state == 0xd) {
        if (func_ov006_02158c70(self)) {
            self->message = 0x1a;
            self->unknown_392_ = 0;
            self->flags |= 0x20;
            self->state++;
        }
    } else if (self->state == 0xe) {
        self->unknown_42c_ = 0;
        if (func_ov006_02158c70(self)) {
            func_ov006_0215e5f8((Struct_ov006_0215e5f8*)self, (Struct_0207fdcc_2*)self->elements, 0, &self->shown);
            ctx->flags &= ~0x40;
            self->unknown_42d_ = 0;
            self->nextState = 0xf;
            self->state = 0x96;
        }
    } else if (self->state == 0xf) {
        ctx->flags |= 0x100;
        self->state++;
    } else if (self->state == 0x10) {
        ctx->flags |= 0x200;
        self->state++;
    } else if (self->state == 0x11) {
        void** res;
        int sound;
        self->busy = 1;
#if defined(jpn)
        func_02080f8c((Container02080f8c*)self->elements, 0x7f,
            KeyTable_Get((Container020e0310*)self->lookup, self->lookupId));
#else
        res = func_020e5294(self->lookup, self->lookupId);
        if (res != 0) {
            memset(*self->buffer, 0, 0x80);
            func_020e4864(*res, *self->buffer, 1, 0, 0, 0);
            func_02080f8c((Container02080f8c*)self->elements, 0x7f, (int)(*self->buffer));
        }
        func_020805f4(self->elements, 0x7f);
#endif
        func_020813ec(self->elements, 0x12);
        ctx->flags |= 0x400;
        self->unknown_42f_ = 1;
        sound = 0x3e;
        if (self->inline_ov006_0215e69c()) {
            sound = 0x3f;
            func_ov006_021571fc((char*)self->ctx);
        }
        func_0209c830((Struct0209c830*)&g_bgmPlayer, sound);
        func_02080c04((Struct_0207fdcc_2*)self->elements, 0);
        self->message = 0xc;
        self->unknown_392_ = 0;
        self->state++;
    } else if (self->state == 0x12) {
        if (func_ov006_02158c70(self)) {
            if (self->inline_ov006_0215e69c()) {
                func_ov006_0215728c(ctx);
            }
            self->message = 0x38;
            self->unknown_392_ = 0;
            self->state++;
        }
    } else if (self->state == 0x13) {
        if (func_ov006_02158c70(self)) {
            short id;
            func_0207fdcc((Struct_0207fdcc_2*)self->elements, 0x12);
            self->busy = 0;
            ctx->flags &= ~0x800;
            id = 0x1f;
            if (self->inline_ov006_0215e69c()) {
                id = self->variant + 0x1b;
            }
            self->flags |= 0x20;
            self->message = id;
            self->unknown_392_ = 0;
            self->state++;
        }
    } else if (self->state == 0x14) {
        if (func_ov006_02158c70(self)) {
            short id = 0x20;
            if (self->inline_ov006_0215e69c()) {
                id = self->variant + 0x1d;
            }
            self->message = id;
            self->unknown_392_ = 0;
            self->state = 0x78;
        }
    } else if (self->state == 100) {
        ctx->flags |= 0x100;
        self->state++;
    } else if (self->state == 0x65) {
        ctx->flags |= 0x200;
        self->state++;
    } else if (self->state == 0x66) {
        void** res;
        unsigned char a;
        unsigned char b;
        func_ov006_02153cbc(self->table, self->entry->id, -1, self->out);
        func_ov006_0215759c(self->list, self->entry, self->unknown_387_);
        a = self->unknown_388_;
        b = self->unknown_389_;
        func_ov006_02158de0(self);
        self->unknown_388_ = a;
        self->unknown_389_ = b;
        self->busy = 1;
#if defined(jpn)
        func_02080f8c((Container02080f8c*)self->elements, 0x7f,
            KeyTable_Get((Container020e0310*)self->lookup, self->lookupId));
#else
        res = func_020e5294(self->lookup, self->lookupId);
        if (res != 0) {
            memset(*self->buffer, 0, 0x80);
            func_020e4864(*res, *self->buffer, 1, 0, 0, 0);
            func_02080f8c((Container02080f8c*)self->elements, 0x7f, (int)(*self->buffer));
        }
        func_020805f4(self->elements, 0x7f);
#endif
        func_020813ec(self->elements, 0x12);
        ctx->flags |= 0x400;
        self->unknown_42f_ = 1;
        func_0209c830((Struct0209c830*)&g_bgmPlayer, 0x3e);
        self->message = 0xc;
        self->unknown_392_ = 0;
        self->state++;
    } else if (self->state == 0x67) {
        if (func_ov006_02158c70(self)) {
            self->message = 0x38;
            self->unknown_392_ = 0;
            self->state = 0x78;
        }
    } else if (self->state == 0x78) {
        if (self->unknown_42f_ != 0) {
            self->unknown_42c_ = 0;
        } else {
            Struct_ov006_0215e69c* task = ctx->inline_ov006_0215e69c_2();
            if (!(task != 0 && task->active != 0) && func_ov006_02158c70(self)) {
                func_0207fdcc((Struct_0207fdcc_2*)self->elements, 0x12);
                self->busy = 0;
                ctx->flags &= ~0x800;
                self->message = 1;
                self->unknown_392_ = 0;
                self->flags |= 0x20;
                self->state++;
            }
        }
    } else if (self->state == 0x79) {
        if (func_ov006_02158c70(self)) {
            func_ov006_0215e5f8((Struct_ov006_0215e5f8*)self, (Struct_0207fdcc_2*)self->elements, 1, &self->shown);
            func_0207fdcc((Struct_0207fdcc_2*)self->elements, 0);
            func_0207fdcc((Struct_0207fdcc_2*)self->elements, 1);
            self->mode = 0xa;
            self->state = 0;
        }
    } else if (self->state == 0x96) {
        unsigned short* flags = &ctx->flags;
        ctx->flags |= 0x2000;
        self->unknown_42d_++;
        if (self->unknown_42d_ >= 10) {
            self->unknown_42d_ = 0;
            *flags &= ~0x2000;
            *flags |= 0x80;
            self->state = self->nextState;
        }
    }
}
