#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov003_021539a0_2;

struct Struct_ov003_021539a0_3 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov003_021539a0_4 {
    char unknown_0_[8];
    struct Struct_ov003_021539a0_3 unknown_8_[3];
};

struct Struct_ov003_021539a0_5 {
    short unknown_0_;
    char unknown_2_[0x14];
    unsigned char unknown_16_;
    char unknown_17_;
};

struct Struct_ov003_021539a0_6 {
    int unknown_0_;
    void* unknown_4_;
    struct Struct_ov003_021539a0_5* unknown_8_;
    char unknown_c_[6];
    short unknown_12_;
    unsigned short unknown_14_;
    char unknown_16_[0x4a - 0x16];
    short unknown_4a_;
};

struct Struct_ov003_021539a0_7 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

struct Struct_ov003_021539a0_8 {
    char unknown_0_[8];
    void* unknown_8_;
    char unknown_c_[0x9c];
    short unknown_a8_;
    short unknown_aa_;
    char unknown_ac_[8];
    short unknown_b4_;
    short unknown_b6_;
    short unknown_b8_;
    short unknown_ba_;
    char unknown_bc_[0x24];
};

struct Struct_ov003_021539a0 {
    int unknown_0_;
    void* unknown_4_;
    struct Struct_ov003_021539a0_4* unknown_8_;
    struct Struct_ov003_021539a0_6* unknown_c_;
    int unknown_10_;
    int unknown_14_;
    char unknown_18_[0x38];
    int unknown_50_;
    int unknown_54_;
    char unknown_58_;
    signed char unknown_59_;
    char unknown_5a_[2];
    unsigned char unknown_5c_;
    unsigned char unknown_5d_;
};

struct SafeAllocator;
extern "C" void __clear(void*, int);
extern "C" int sprintf(char* dst, const char* fmt, ...);
void* ResourceScriptEntry_Init(void*);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" int ResourceScriptEntry_LoadLevel(void*, void*, unsigned int, int, int);
struct PacRecord;
char* Pac_GetFile(PacRecord*, int, void**, int*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
struct BackgroundGraphics;
void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void WindowPane_Init(void*);
struct Obj0204b988;
void DispatchIndexedEntry0204b988(Obj0204b988*, unsigned int, int, int, unsigned short);
void Background_UploadMap(BackgroundGraphics*, void*);
struct Container020e0310;
char* KeyTable_Get(Container020e0310*, int);
void* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(void*, int, char*, char*, int, int, int);
void SetEntryFields_021e23d0(void*, int, int, unsigned char, unsigned char);
int AccumulateFlaggedSlotBits02085fb4(unsigned char*);
int AccumulateFlaggedSlotBits02086020(unsigned char*);
int AccumulateFlaggedSlotBits0208608c(unsigned char*);
int AccumulateFlaggedSlotBits020860f8(unsigned char*);
int AccumulateFlaggedSlotBits02086164(unsigned char*);
int AccumulateFlaggedSlotBits020861d0(unsigned char*);
int AccumulateFlaggedSlotBits0208623c(unsigned char*);
int AccumulateSlotBitsFromTable020862a8(unsigned char*);
int AccumulateSlotBitsFromTable02086314(unsigned char*);
void SetPackedFields_021e24b0(void*, int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
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
extern "C" ARM void func_ov003_021539a0(struct Self_021539a0* self) {
    if (self->member < 0) return;
    if (!(self->flags & 1)) return;
    struct Loader* loader = (Loader*)BackgroundLoader::GetInstance();
    if (self->state == 0) {
        char path[0x18];
        __clear(path, 0x18);
        sprintf(path, data_ov003_0217fca0, self->idx);
        self->task50 = ((BackgroundLoader*)loader)->QueueLoadFile(path, (SafeAllocator*)0);
        self->task54 = ((BackgroundLoader*)loader)->QueueLoadFile(data_ov003_0217fcb5, (SafeAllocator*)0);
        self->state++;
    } else if (self->state == 1) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->task50) == 0) return;
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->task54) == 0) return;
        struct Draw_021539a0 draw;
        struct ListObj_021539a0 list;
        int vals[9];
        void* file;
        unsigned int size;
        void* rp;
        int rs;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->task50, &file, &size);
        void* gs = GameState::GetInstance();
        unsigned char* obj = (unsigned char*)((GameState*)gs)->GetPartyMemberByIndex(self->member);
        ResourceScriptEntry_Init(self->stats);
        unsigned char* base = 0;
        unsigned char* gfx;
        if (obj != 0 && file != 0) {
            base = GetFieldAt0x150_02053c6c(obj);
            ResourceScriptEntry_LoadLevel(self->stats, file, size, *(unsigned short*)(base + 0x100 + self->idx * 2 + 0x6c), 0);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->task50);
        self->task50 = -1;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->task54, &file, &size);
        obj = (unsigned char*)Pac_GetFile((PacRecord*)file, 0, &rp, &rs);
        if (obj != 0) {
            list.lo = 1;
            list.hi = 0;
            Background_SetMapSize((unsigned char*)&list, 0);
            Background_SetPriority(&list, 0);
            Background_SetScroll((BackgroundGraphics*)&list, 0, 0);
            gfx = obj + 0x10;
            WindowPane_Init(&draw);
            draw.s28 = 0x20;
            draw.s2a = 0x18;
            draw.s34 = 0xc;
            draw.p8 = gfx;
            draw.s36 = 0x10;
            struct Layout_021539a0* ents;
            struct Stats_021539a0* stats;
            int idx;
            void* cont;
            cont = self->cont;
            idx = self->idx;
            stats = self->stats;
            ents = self->ents;
            if (base != 0) {
                struct Entry_021539a0* e;
                unsigned short i;
                unsigned short count;
                struct Entry_021539a0* arr;
                arr = ents->arr;
                if (arr == NULL) {
                    e = 0;
                } else {
                    var19 = var13->unknown_14_;
                    if (var19 == 0) {
                        var17 = 0;
                    } else {
                        for (var18 = 0; var18 < var19; var18++) {
                            short var21 = var20[var18].unknown_0_;
                            if (var21 == 1) {
                                var17 = &var20[var18];
                                goto found;
                            }
                        }
                        var17 = 0;
                    }
                }
            found:
                if (var17) {
                    var17->unknown_16_ &= ~1;
                }
                DispatchIndexedEntry0204b988((Obj0204b988*)self->list, (unsigned char)(idx + 1) & 0xff, 3, 2, 0xffff);
                Background_UploadMap((BackgroundGraphics*)self->list, 0);
                unsigned char cls = idx - 1;
                draw.s38 = 0xa;
                draw.s3a = 0x10;
                unsigned char key = cls + cls * 2;
                SetEntryFields_021e23d0(ents, 7, (int)KeyTable_Get((Container020e0310*)cont, key), 0xc, 0xf);
                SetEntryFields_021e23d0(ents, 8, (int)KeyTable_Get((Container020e0310*)cont, (short)(key + 1)), 0xc, 0xf);
                SetEntryFields_021e23d0(ents, 9, (int)KeyTable_Get((Container020e0310*)cont, (short)(key + 2)), 0xc, 0xf);
                int off = (idx & 0xff) * 0xc;
                unsigned char* statBase = base + 0x7b8;
                struct Packed3x10* row = (struct Packed3x10*)(statBase + off);
                vals[0] = CAP999(AccumulateFlaggedSlotBits02085fb4(base) + stats->w[0].a + row[0].a);
                vals[1] = CAP999(AccumulateFlaggedSlotBits02086020(base) + stats->w[0].b + row[0].b);
                vals[2] = CAP999(AccumulateFlaggedSlotBits0208608c(base) + stats->w[0].c + row[0].c);
                vals[3] = CAP999(AccumulateFlaggedSlotBits020860f8(base) + stats->w[1].a + row[1].a);
                vals[4] = CAP999(AccumulateFlaggedSlotBits02086164(base) + stats->w[1].b + row[1].b);
                vals[5] = CAP999(AccumulateFlaggedSlotBits020861d0(base) + stats->w[1].c + row[1].c);
                vals[6] = CAP999(AccumulateFlaggedSlotBits0208623c(base) + stats->w[2].a + row[2].a);
                vals[7] = CAP999(AccumulateSlotBitsFromTable020862a8(base) + stats->w[2].b + row[2].b);
                vals[8] = CAP999(AccumulateSlotBitsFromTable02086314(base) + stats->w[2].c + row[2].c);
                for (unsigned char i = 0; data_ov003_0217f288[i] >= 0; i++) {
                    SetPackedFields_021e24b0(ents, data_ov003_0217f288[i], vals[i], 8, 0xf, 1, 3, 0, 0);
                }
                var13->unknown_4_ = &var2;
                var13->unknown_12_ = 1;
                func_ov023_021e257c(var13);
            }
            CleanInvalidateCacheRange(var12, 0x6000);
            LoadToSubBG0CharacterData((int)var12, 0, 0x6000);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->task54);
        self->task54 = -1;
        self->f10 = self->idx;
        void* axis = (void*)((GameState*)gs)->GetResources();
        if ((self->flags & 2) || !IsBrightnessWithinValidRange((GameResources*)axis, true)) {
            self->flags &= ~2;
            self->state++;
        } else {
            arg0->unknown_5d_ &= ~1;
            arg0->unknown_5c_ = 0;
        }
    } else if (self->state == 2) {
        SetSubBrightness((GameResources*)((void*)GameState::GetInstance()->GetResources()), 0, 1);
        self->state = 0;
        self->flags &= ~1;
    }
}
#else
extern "C" ARM void func_ov003_021539a0(struct Self_021539a0* self) {
    if (self->member < 0) return;
    if (!(self->flags & 1)) return;
    struct Loader* loader = (Loader*)BackgroundLoader::GetInstance();
    if (self->state == 0) {
        char path[0x18];
        __clear(path, 0x18);
        sprintf(path, data_ov003_0217fca0, self->idx);
        self->task50 = ((BackgroundLoader*)loader)->QueueLoadFile(path, (SafeAllocator*)0);
        self->task54 = ((BackgroundLoader*)loader)->QueueLoadFileInGP2(data_ov003_0217fcb5, data_ov003_0217fcc7, (SafeAllocator*)0);
        self->state++;
    } else if (self->state == 1) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->task50) == 0) return;
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->task54) == 0) return;
        struct Draw_021539a0 draw;
        char text[0x400];
        char fmt[0x400];
        struct ListObj_021539a0 list;
        int vals[9];
        void* file;
        unsigned int size;
        void* rp;
        int rs;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->task50, &file, &size);
        void* gs = GameState::GetInstance();
        unsigned char* obj = (unsigned char*)((GameState*)gs)->GetPartyMemberByIndex(self->member);
        ResourceScriptEntry_Init(self->stats);
        unsigned char* base = 0;
        unsigned char* gfx;
        if (obj != 0 && file != 0) {
            base = GetFieldAt0x150_02053c6c(obj);
            ResourceScriptEntry_LoadLevel(self->stats, file, size, *(unsigned short*)(base + 0x100 + self->idx * 2 + 0x6c), 0);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->task50);
        self->task50 = -1;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->task54, &file, &size);
        obj = (unsigned char*)Pac_GetFile((PacRecord*)file, 0, &rp, &rs);
        if (obj != 0) {
            list.lo = 1;
            list.hi = 0;
            Background_SetMapSize((unsigned char*)&list, 0);
            Background_SetPriority(&list, 0);
            Background_SetScroll((BackgroundGraphics*)&list, 0, 0);
            gfx = obj + 0x10;
            WindowPane_Init(&draw);
            draw.s28 = 0x20;
            draw.s2a = 0x18;
            draw.s34 = 0xc;
            draw.p8 = gfx;
            draw.s36 = 0x10;
            struct Layout_021539a0* ents;
            struct Stats_021539a0* stats;
            int idx;
            void* cont;
            cont = self->cont;
            idx = self->idx;
            stats = self->stats;
            ents = self->ents;
            if (base != 0) {
                struct Entry_021539a0* e;
                unsigned short i;
                unsigned short count;
                struct Entry_021539a0* arr;
                arr = ents->arr;
                if (arr == NULL) {
                    e = 0;
                } else {
                    var50 = var44->unknown_14_;
                    if (var50 == 0) {
                        var48 = 0;
                    } else {
                        for (var49 = 0; var49 < var50; var49++) {
                            short var52 = var51[var49].unknown_0_;
                            if (var52 == 1) {
                                var48 = &var51[var49];
                                goto found;
                            }
                        }
                        var48 = 0;
                    }
                }
            found:
                if (var48) {
                    var48->unknown_16_ &= ~1;
                }
                DispatchIndexedEntry0204b988((Obj0204b988*)self->list, (unsigned char)(idx + 1) & 0xff, 3, 2, 0xffff);
                Background_UploadMap((BackgroundGraphics*)self->list, 0);
                unsigned char cls = idx - 1;
                draw.s38 = 0xa;
                draw.s3a = 0x10;
                ents->s4a = 0x10;
                __clear(text, 0x400);
                unsigned char key = cls + cls * 2;
                char* s2 = KeyTable_Get((Container020e0310*)cont, (short)(key + 2));
                char* s1 = KeyTable_Get((Container020e0310*)cont, (short)(key + 1));
                char* s0 = KeyTable_Get((Container020e0310*)cont, (short)key);
                sprintf(fmt, data_ov003_0217fcd5, s0, s1, s2);
                MessageSystem_FormatText(MessageSystem_GetInstance(), 0xc, fmt, text, 0xdc, 0, 1);
                SetEntryFields_021e23d0(ents, 7, (int)text, 0xc, 0xf);
                SetEntryFields_021e23d0(ents, 8, (int)data_ov003_0217fcde, 0xc, 0xf);
                SetEntryFields_021e23d0(ents, 9, (int)data_ov003_0217fcde, 0xc, 0xf);
                SetEntryFields_021e23d0(ents, 0x14, (int)data_ov003_0217fcde, 0xc, 0xf);
                int off = (idx & 0xff) * 0xc;
                unsigned char* statBase = base + 0x850;
                struct Packed3x10* row = (struct Packed3x10*)(statBase + off);
                vals[0] = CAP999(AccumulateFlaggedSlotBits02085fb4(base) + stats->w[0].a + row[0].a);
                vals[1] = CAP999(AccumulateFlaggedSlotBits02086020(base) + stats->w[0].b + row[0].b);
                vals[2] = CAP999(AccumulateFlaggedSlotBits0208608c(base) + stats->w[0].c + row[0].c);
                vals[3] = CAP999(AccumulateFlaggedSlotBits020860f8(base) + stats->w[1].a + row[1].a);
                vals[4] = CAP999(AccumulateFlaggedSlotBits02086164(base) + stats->w[1].b + row[1].b);
                vals[5] = CAP999(AccumulateFlaggedSlotBits020861d0(base) + stats->w[1].c + row[1].c);
                vals[6] = CAP999(AccumulateFlaggedSlotBits0208623c(base) + stats->w[2].a + row[2].a);
                vals[7] = CAP999(AccumulateSlotBitsFromTable020862a8(base) + stats->w[2].b + row[2].b);
                vals[8] = CAP999(AccumulateSlotBitsFromTable02086314(base) + stats->w[2].c + row[2].c);
                for (unsigned char i = 0; data_ov003_0217f288[i] >= 0; i++) {
                    SetPackedFields_021e24b0(ents, data_ov003_0217f288[i], vals[i], 8, 0xf, 1, 3, 0, 0);
                }
                var44->unknown_4_ = &var31;
                var44->unknown_12_ = 1;
                func_ov023_021e257c(var44);
            }
            CleanInvalidateCacheRange(var43, 0x6000);
            LoadToSubBG0CharacterData((int)var43, 0, 0x6000);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->task54);
        self->task54 = -1;
        self->f10 = self->idx;
        void* axis = (void*)((GameState*)gs)->GetResources();
        if ((self->flags & 2) || !IsBrightnessWithinValidRange((GameResources*)axis, true)) {
            self->flags &= ~2;
            self->state++;
        } else {
            arg0->unknown_5d_ &= ~1;
            arg0->unknown_5c_ = 0;
        }
    } else if (self->state == 2) {
        SetSubBrightness((GameResources*)((void*)GameState::GetInstance()->GetResources()), 0, 1);
        self->state = 0;
        self->flags &= ~1;
    }
}
#endif
