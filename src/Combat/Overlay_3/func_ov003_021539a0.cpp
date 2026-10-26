#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov003_021539a0_2;

struct Struct_ov003_021539a0_3 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int pad : 2;
};

struct Struct_ov003_021539a0_4 {
    char pad0[8];
    struct Struct_ov003_021539a0_3 w[3];
};

struct Struct_ov003_021539a0_5 {
    short id;
    char pad2[0x14];
    unsigned char unknown_16_;
    char unknown_17_;
};

struct Struct_ov003_021539a0_6 {
    int pad0;
    void* p4;
    struct Struct_ov003_021539a0_5* arr;
    char unknown_c_[6];
    short unknown_12_;
    unsigned short count;
    char pad16[0x4a - 0x16];
    short unknown_4a_;
};

struct Struct_ov003_021539a0_7 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad2[3];
};

struct Struct_ov003_021539a0_8 {
    char pad0[8];
    void* p8;
    char pad1[0x9c];
    short unknown_a8_;
    short unknown_aa_;
    char pad2[8];
    short unknown_b4_;
    short unknown_b6_;
    short unknown_b8_;
    short unknown_ba_;
    char pad3[0x24];
};

struct Struct_ov003_021539a0 {
    int pad0;
    void* cont;
    struct Struct_ov003_021539a0_4* stats;
    struct Struct_ov003_021539a0_6* ents;
    int f10;
    int idx;
    char list[0x38];
    int unknown_50_;
    int unknown_54_;
    char unknown_58_;
    signed char member;
    char unknown_5a_[2];
    unsigned char state;
    unsigned char flags;
};

struct SafeAllocator;
extern "C" void __clear(void*, int);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void* ResourceScriptEntry_Init(void*);
extern "C" unsigned char* func_02053c6c(unsigned char*);
extern "C" int ResourceScriptEntry_LoadLevel(void*, void*, unsigned int, int, int);
struct PacRecord;
extern "C" char* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
struct BackgroundGraphics;
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void WindowPane_Init(void*);
struct Struct_0204b988;
extern "C" void func_0204b988(Struct_0204b988*, unsigned int, int, int, unsigned short);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
struct Container020e0310;
extern "C" char* KeyTable_Get(Container020e0310*, int);
extern "C" void* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(void*, int, char*, char*, int, int, int);
extern "C" void func_ov023_021e23d0(void*, int, int, unsigned char, unsigned char);
extern "C" int func_02085fb4(unsigned char*);
extern "C" int func_02086020(unsigned char*);
extern "C" int func_0208608c(unsigned char*);
extern "C" int func_020860f8(unsigned char*);
extern "C" int func_02086164(unsigned char*);
extern "C" int func_020861d0(unsigned char*);
extern "C" int func_0208623c(unsigned char*);
extern "C" int func_020862a8(unsigned char*);
extern "C" int func_02086314(unsigned char*);
extern "C" void func_ov023_021e24b0(void*, int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void func_ov023_021e257c(void*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToSubBG0CharacterData(int, int, unsigned int);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);

extern char data_ov003_0217fca0[];
extern char data_ov003_0217fcb5[];
extern char data_ov003_0217fcc7[];
extern char data_ov003_0217fcd5[];
extern char data_ov003_0217fcde[];
extern short data_ov003_0217f288[];

#if defined(jpn)
#define data_ov003_0217fca0 data_ov003_0217e520
#define data_ov003_0217f288 data_ov003_0217df8c
extern char data_ov003_0217e520[];
extern short data_ov003_0217df8c[];
#endif

#define CAP999(x) ((x) > 999 ? 999 : (x))

// USA: func_ov003_021539a0
#if defined(jpn)
extern "C" ARM void func_ov003_021539a0(struct Struct_ov003_021539a0* self) {
    if (self->member < 0) return;
    if (!(self->flags & 1)) return;
    struct Struct_ov003_021539a0_2* loader = (Struct_ov003_021539a0_2*)BackgroundLoader::GetInstance();
    if (self->state == 0) {
        char path[0x18];
        __clear(path, 0x18);
        sprintf(path, data_ov003_0217fca0, self->idx);
        self->unknown_50_ = ((BackgroundLoader*)loader)->QueueLoadFile(path, (SafeAllocator*)0);
        self->unknown_54_ = ((BackgroundLoader*)loader)->QueueLoadFile(data_ov003_0217fcb5, (SafeAllocator*)0);
        self->state++;
    } else if (self->state == 1) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->unknown_50_) == 0) return;
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->unknown_54_) == 0) return;
        struct Struct_ov003_021539a0_8 draw;
        struct Struct_ov003_021539a0_7 list;
        int var4[9];
        void* file;
        unsigned int size;
        void* rp;
        int rs;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->unknown_50_, &file, &size);
        void* gs = GameState::GetInstance();
        unsigned char* obj = (unsigned char*)((GameState*)gs)->GetPartyMemberByIndex(self->member);
        ResourceScriptEntry_Init(self->stats);
        unsigned char* base = 0;
        unsigned char* gfx;
        if (obj != 0 && file != 0) {
            base = func_02053c6c(obj);
            ResourceScriptEntry_LoadLevel(self->stats, file, size, *(unsigned short*)(base + 0x100 + self->idx * 2 + 0x6c), 0);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->unknown_50_);
        self->unknown_50_ = -1;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->unknown_54_, &file, &size);
        obj = (unsigned char*)Pac_GetFile((PacRecord*)file, 0, &rp, &rs);
        if (obj != 0) {
            list.lo = 1;
            list.hi = 0;
            Background_SetMapSize((unsigned char*)&list, 0);
            Background_SetPriority(&list, 0);
            Background_SetScroll((BackgroundGraphics*)&list, 0, 0);
            gfx = obj + 0x10;
            WindowPane_Init(&draw);
            draw.unknown_a8_ = 0x20;
            draw.unknown_aa_ = 0x18;
            draw.unknown_b4_ = 0xc;
            draw.p8 = gfx;
            draw.unknown_b6_ = 0x10;
            struct Struct_ov003_021539a0_6* ents;
            struct Struct_ov003_021539a0_4* stats;
            int idx;
            void* cont;
            cont = self->cont;
            idx = self->idx;
            stats = self->stats;
            ents = self->ents;
            if (base != 0) {
                struct Struct_ov003_021539a0_5* e;
                unsigned short i;
                unsigned short count;
                struct Struct_ov003_021539a0_5* arr;
                arr = ents->arr;
                if (arr == NULL) {
                    e = 0;
                } else {
                    count = ents->count;
                    if (count == 0) {
                        e = 0;
                    } else {
                        for (i = 0; i < count; i++) {
                            short id = arr[i].id;
                            if (id == 1) {
                                e = &arr[i];
                                goto found;
                            }
                        }
                        e = 0;
                    }
                }
            found:
                if (e) {
                    e->unknown_16_ &= ~1;
                }
                func_0204b988((Struct_0204b988*)self->list, (unsigned char)(idx + 1) & 0xff, 3, 2, 0xffff);
                Background_UploadMap((BackgroundGraphics*)self->list, 0);
                unsigned char var22 = idx - 1;
                draw.unknown_b8_ = 0xa;
                draw.unknown_ba_ = 0x10;
                unsigned char key = var22 + var22 * 2;
                func_ov023_021e23d0(ents, 7, (int)KeyTable_Get((Container020e0310*)cont, key), 0xc, 0xf);
                func_ov023_021e23d0(ents, 8, (int)KeyTable_Get((Container020e0310*)cont, (short)(key + 1)), 0xc, 0xf);
                func_ov023_021e23d0(ents, 9, (int)KeyTable_Get((Container020e0310*)cont, (short)(key + 2)), 0xc, 0xf);
                int off = (idx & 0xff) * 0xc;
                unsigned char* var25 = base + 0x7b8;
                struct Struct_ov003_021539a0_3* row = (struct Struct_ov003_021539a0_3*)(var25 + off);
                var4[0] = CAP999(func_02085fb4(base) + stats->w[0].a + row[0].a);
                var4[1] = CAP999(func_02086020(base) + stats->w[0].b + row[0].b);
                var4[2] = CAP999(func_0208608c(base) + stats->w[0].c + row[0].c);
                var4[3] = CAP999(func_020860f8(base) + stats->w[1].a + row[1].a);
                var4[4] = CAP999(func_02086164(base) + stats->w[1].b + row[1].b);
                var4[5] = CAP999(func_020861d0(base) + stats->w[1].c + row[1].c);
                var4[6] = CAP999(func_0208623c(base) + stats->w[2].a + row[2].a);
                var4[7] = CAP999(func_020862a8(base) + stats->w[2].b + row[2].b);
                var4[8] = CAP999(func_02086314(base) + stats->w[2].c + row[2].c);
                for (unsigned char i = 0; data_ov003_0217f288[i] >= 0; i++) {
                    func_ov023_021e24b0(ents, data_ov003_0217f288[i], var4[i], 8, 0xf, 1, 3, 0, 0);
                }
                ents->p4 = &draw;
                ents->unknown_12_ = 1;
                func_ov023_021e257c(ents);
            }
            CleanInvalidateCacheRange(gfx, 0x6000);
            LoadToSubBG0CharacterData((int)gfx, 0, 0x6000);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->unknown_54_);
        self->unknown_54_ = -1;
        self->f10 = self->idx;
        void* axis = (void*)((GameState*)gs)->GetResources();
        if ((self->flags & 2) || !IsScreenNotFullyFaded((GameResources*)axis, true)) {
            self->flags &= ~2;
            self->state++;
        } else {
            self->flags &= ~1;
            self->state = 0;
        }
    } else if (self->state == 2) {
        SetSubBrightness((GameResources*)((void*)GameState::GetInstance()->GetResources()), 0, 1);
        self->state = 0;
        self->flags &= ~1;
    }
}
#else
extern "C" ARM void func_ov003_021539a0(struct Struct_ov003_021539a0* self) {
    if (self->member < 0) return;
    if (!(self->flags & 1)) return;
    struct Struct_ov003_021539a0_2* loader = (Struct_ov003_021539a0_2*)BackgroundLoader::GetInstance();
    if (self->state == 0) {
        char path[0x18];
        __clear(path, 0x18);
        sprintf(path, data_ov003_0217fca0, self->idx);
        self->unknown_50_ = ((BackgroundLoader*)loader)->QueueLoadFile(path, (SafeAllocator*)0);
        self->unknown_54_ = ((BackgroundLoader*)loader)->QueueLoadFileInGP2(data_ov003_0217fcb5, data_ov003_0217fcc7, (SafeAllocator*)0);
        self->state++;
    } else if (self->state == 1) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->unknown_50_) == 0) return;
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->unknown_54_) == 0) return;
        struct Struct_ov003_021539a0_8 draw;
        char text[0x400];
        char fmt[0x400];
        struct Struct_ov003_021539a0_7 list;
        int var35[9];
        void* file;
        unsigned int size;
        void* rp;
        int rs;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->unknown_50_, &file, &size);
        void* gs = GameState::GetInstance();
        unsigned char* obj = (unsigned char*)((GameState*)gs)->GetPartyMemberByIndex(self->member);
        ResourceScriptEntry_Init(self->stats);
        unsigned char* base = 0;
        unsigned char* gfx;
        if (obj != 0 && file != 0) {
            base = func_02053c6c(obj);
            ResourceScriptEntry_LoadLevel(self->stats, file, size, *(unsigned short*)(base + 0x100 + self->idx * 2 + 0x6c), 0);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->unknown_50_);
        self->unknown_50_ = -1;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->unknown_54_, &file, &size);
        obj = (unsigned char*)Pac_GetFile((PacRecord*)file, 0, &rp, &rs);
        if (obj != 0) {
            list.lo = 1;
            list.hi = 0;
            Background_SetMapSize((unsigned char*)&list, 0);
            Background_SetPriority(&list, 0);
            Background_SetScroll((BackgroundGraphics*)&list, 0, 0);
            gfx = obj + 0x10;
            WindowPane_Init(&draw);
            draw.unknown_a8_ = 0x20;
            draw.unknown_aa_ = 0x18;
            draw.unknown_b4_ = 0xc;
            draw.p8 = gfx;
            draw.unknown_b6_ = 0x10;
            struct Struct_ov003_021539a0_6* ents;
            struct Struct_ov003_021539a0_4* stats;
            int idx;
            void* cont;
            cont = self->cont;
            idx = self->idx;
            stats = self->stats;
            ents = self->ents;
            if (base != 0) {
                struct Struct_ov003_021539a0_5* e;
                unsigned short i;
                unsigned short count;
                struct Struct_ov003_021539a0_5* arr;
                arr = ents->arr;
                if (arr == NULL) {
                    e = 0;
                } else {
                    count = ents->count;
                    if (count == 0) {
                        e = 0;
                    } else {
                        for (i = 0; i < count; i++) {
                            short id = arr[i].id;
                            if (id == 1) {
                                e = &arr[i];
                                goto found;
                            }
                        }
                        e = 0;
                    }
                }
            found:
                if (e) {
                    e->unknown_16_ &= ~1;
                }
                func_0204b988((Struct_0204b988*)self->list, (unsigned char)(idx + 1) & 0xff, 3, 2, 0xffff);
                Background_UploadMap((BackgroundGraphics*)self->list, 0);
                unsigned char var53 = idx - 1;
                draw.unknown_b8_ = 0xa;
                draw.unknown_ba_ = 0x10;
                ents->unknown_4a_ = 0x10;
                __clear(text, 0x400);
                unsigned char key = var53 + var53 * 2;
                char* s2 = KeyTable_Get((Container020e0310*)cont, (short)(key + 2));
                char* s1 = KeyTable_Get((Container020e0310*)cont, (short)(key + 1));
                char* s0 = KeyTable_Get((Container020e0310*)cont, (short)key);
                sprintf(fmt, data_ov003_0217fcd5, s0, s1, s2);
                MessageSystem_FormatText(MessageSystem_GetInstance(), 0xc, fmt, text, 0xdc, 0, 1);
                func_ov023_021e23d0(ents, 7, (int)text, 0xc, 0xf);
                func_ov023_021e23d0(ents, 8, (int)data_ov003_0217fcde, 0xc, 0xf);
                func_ov023_021e23d0(ents, 9, (int)data_ov003_0217fcde, 0xc, 0xf);
                func_ov023_021e23d0(ents, 0x14, (int)data_ov003_0217fcde, 0xc, 0xf);
                int off = (idx & 0xff) * 0xc;
                unsigned char* var59 = base + 0x850;
                struct Struct_ov003_021539a0_3* row = (struct Struct_ov003_021539a0_3*)(var59 + off);
                var35[0] = CAP999(func_02085fb4(base) + stats->w[0].a + row[0].a);
                var35[1] = CAP999(func_02086020(base) + stats->w[0].b + row[0].b);
                var35[2] = CAP999(func_0208608c(base) + stats->w[0].c + row[0].c);
                var35[3] = CAP999(func_020860f8(base) + stats->w[1].a + row[1].a);
                var35[4] = CAP999(func_02086164(base) + stats->w[1].b + row[1].b);
                var35[5] = CAP999(func_020861d0(base) + stats->w[1].c + row[1].c);
                var35[6] = CAP999(func_0208623c(base) + stats->w[2].a + row[2].a);
                var35[7] = CAP999(func_020862a8(base) + stats->w[2].b + row[2].b);
                var35[8] = CAP999(func_02086314(base) + stats->w[2].c + row[2].c);
                for (unsigned char i = 0; data_ov003_0217f288[i] >= 0; i++) {
                    func_ov023_021e24b0(ents, data_ov003_0217f288[i], var35[i], 8, 0xf, 1, 3, 0, 0);
                }
                ents->p4 = &draw;
                ents->unknown_12_ = 1;
                func_ov023_021e257c(ents);
            }
            CleanInvalidateCacheRange(gfx, 0x6000);
            LoadToSubBG0CharacterData((int)gfx, 0, 0x6000);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->unknown_54_);
        self->unknown_54_ = -1;
        self->f10 = self->idx;
        void* axis = (void*)((GameState*)gs)->GetResources();
        if ((self->flags & 2) || !IsScreenNotFullyFaded((GameResources*)axis, true)) {
            self->flags &= ~2;
            self->state++;
        } else {
            self->flags &= ~1;
            self->state = 0;
        }
    } else if (self->state == 2) {
        SetSubBrightness((GameResources*)((void*)GameState::GetInstance()->GetResources()), 0, 1);
        self->state = 0;
        self->flags &= ~1;
    }
}
#endif
