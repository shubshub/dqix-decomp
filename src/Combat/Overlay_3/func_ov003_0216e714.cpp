#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"

struct Run0216e714;
#if !defined(jpn)
extern "C" struct Run0216e714 *Zone3D_GetInstance(void);
#endif
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord *pac);
extern "C" void *Pac_GetFile(PacRecord *pac, int index, void **outName, int *outSize);
extern "C" void WindowPane_Init(void *obj);
extern "C" void __clear(void *dst, int count);
extern "C" void Font_DecodeText(void *src, void *dst, int flag);
extern "C" void func_0204f41c(void *obj, short x, short y, void *str, int d, int e, short *outA, short *outB, int zero);
struct Container020e0310;
extern "C" int KeyTable_Get(Container020e0310 *c, int key);
extern "C" int Font_GetTextWidth(void *p, int flag);
extern "C" void func_0204e038(void *canvas, char *str, int a, int b, int c, int d, int e, int f);
struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics *obj);
extern "C" void Background_SetMapSize(unsigned char *obj, int value);
extern "C" int Background_SetScroll(struct BackgroundGraphics *obj, int a, int b);
void CleanInvalidateCacheRange(const void *addr, unsigned int size);
extern "C" int LoadToMainBG3ScreenData(int arg0, int arg1, unsigned int arg2);
extern "C" void Background_LoadFile(void *graphics, void *file, SafeAllocator *allocator, unsigned int size);
extern "C" void Background_UploadMap(struct BackgroundGraphics *obj, void *buf);
extern "C" void Background_Destroy(struct BackgroundGraphics *obj);

extern char data_ov003_0218028b[];
extern char data_ov003_0218029b[];
extern char data_ov003_021802a7[];
extern char data_ov003_021802b3[];
extern char data_ov003_021802b6[];
extern char data_ov003_021802b9[];
extern char data_ov003_021802bc[];
extern char data_ov003_0217f5bc[];

struct Struct_01ff8b48_17 {
    unsigned char pad0[0xb38];
    int count;
};

#if defined(jpn)
struct Run0216e714 {
    unsigned char pad0[0x1000];
    struct Struct_01ff8b48_17 progress;
};

struct Game0216e714 {
    unsigned char pad0[0x860];
    struct Run0216e714 run;
};
extern "C" struct Game0216e714 *Zone3D_GetInstance(void);
#else
struct Run0216e714 {
    unsigned char pad0[0x1840];
    struct Struct_01ff8b48_17 progress;
};
#endif

static inline struct Struct_01ff8b48_17 *GetProgress(struct Run0216e714 *run) { return &run->progress; }
static inline int inline_ov003_0216e714(struct Struct_01ff8b48_17 *progress) { return progress->count; }

struct Struct_ov003_0216e714_3 {
    int unk_0;
    int unk_4;
    unsigned char unk_8[3];
    unsigned char year : 7;
    unsigned char unknown_b_7_ : 1;
    unsigned int kind : 4;
    unsigned int category : 4;
    unsigned int unknown_d_0_ : 7;
    unsigned int rank : 4;
    unsigned int level : 5;
    unsigned int unknown_f_0_ : 8;
};

struct Struct_ov003_0216e714_4 {
    char unk_0[8];
    char *text;
    char unk_c[0xa8 - 0xc];
    short width;
    short height;
    char unk_ac[0xb4 - 0xac];
    short unknown_b4_;
    short unknown_b6_;
    char unk_b8[0xe0 - 0xb8];
};

struct Struct_ov003_0216e714_5 {
    char unk_0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char unknown_1d_[3];
};

struct File0216e714 {
    char unk_0[0xc];
    unsigned int size;
    char data[1];
};

struct Struct_ov003_0216e714_7 {
    unsigned char page;
    unsigned char state;
    signed char step;
    unsigned char move;
    unsigned char pages;
    unsigned char count;
    signed char cursor;
    signed char selected;
    char unk_8[0x1c - 0x8];
    int task;
    unsigned short flags;
    char unk_22[0xdc - 0x22];
    char texts[0x18];
    Struct_ov003_0216e714_3 *records[(0x3b0 - 0xf4) / 4];
    int kinds[8];
};

#if defined(jpn)
extern char data_ov003_0217e264[];
extern char data_ov003_0217ea1f[];
extern char data_ov003_0217ea2b[];
extern char data_ov003_0217ea2e[];
extern char data_ov003_0217ea33[];
extern char data_ov003_0217ea38[];
extern char data_ov003_0217ea3d[];
extern char data_ov003_0217ea42[];
extern char data_ov003_0217ea47[];
extern char data_ov003_0217ea4c[];
extern char data_ov003_0217ea51[];
extern char data_ov003_0217ea56[];
extern char data_ov003_0217ea5b[];
extern char data_ov003_0217ea60[];
extern char data_ov003_0217ea65[];
extern char data_ov003_0217ea6a[];
extern char data_ov003_0217ea6f[];
extern char data_ov003_0217ea74[];
extern char data_ov003_0217ea83[];
extern char data_ov003_0217ea86[];
extern char data_ov003_0217ea89[];
extern "C" void func_02050678(void *obj, short x, short y, char *str, int d, int e, short *outA, short *outB);

struct Struct_ov003_0216e714_8 {
    char s[0x40];
};

extern "C" ARM void func_ov003_0216e714(Struct_ov003_0216e714_7 *self) {
    int row;
    int start;
    int index;
    Struct_ov003_0216e714_3 *rec;
    int end;
    Run0216e714 *run         = &Zone3D_GetInstance()->run;
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    if (self->step == 0) {
        Struct_ov003_0216e714_8 path = *(Struct_ov003_0216e714_8 *) data_ov003_0217e264;
        self->task        = loader->QueueLoadFile(path.s, 0);
        if (!(self->flags & 0x20)) {
            ColorEffect_ConfigureAlphaBlend(0x04000050, 0x18, 1, 0, 0x10);
        }
        self->step = 1;
    } else if (self->step == 1) {
        if (loader->GetTaskStatus(self->task) != 0) {
            Struct_ov003_0216e714_4 canvas;
            char text[0x80];
            File0216e714 *files[3];
            int sizes[3];
            Struct_ov003_0216e714_5 bg;
            void *entry;
            void *file;
            unsigned int size;
            short outA;
            short outB;
            int y;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int numFiles = Pac_CountFiles((PacRecord *) file);
            for (int i = 0; i < numFiles; i++) {
                files[i] = (File0216e714 *) Pac_GetFile((PacRecord *) file, i, &entry, &sizes[i]);
            }
            WindowPane_Init(&canvas);
            canvas.text   = (char *) files[0] + 0x10;
            canvas.width  = 0x20;
            canvas.height = 0x18;
            canvas.unknown_b4_  = 10;
            canvas.unknown_b6_  = 10;
            row           = 0;
            start         = (self->page - 1) * 8;
            __clear(text, sizeof(text));
            end = start + 8;
            for (index = start; index < end; row++, index++) {
                if (index >= inline_ov003_0216e714(GetProgress(run))) break;
                rec          = self->records[index];
                canvas.unknown_b4_ = 10;
                canvas.unknown_b6_ = 10;
                if (index == self->selected + (self->page - 1) * 8) {
                    sprintf(text, data_ov003_0217ea1f, rec);
                } else {
                    sprintf(text, data_ov003_0217ea2b, rec);
                }
                func_02050678(&canvas, 0x14, row * 16 + 0x2f, text, 10, 15, &outA, &outB);
                switch (rec->kind) {
                    case 0: sprintf(text, data_ov003_0217ea2e); break;
                    case 1: sprintf(text, data_ov003_0217ea33); break;
                    case 2: sprintf(text, data_ov003_0217ea38); break;
                    case 3: sprintf(text, data_ov003_0217ea3d); break;
                    case 4: sprintf(text, data_ov003_0217ea42); break;
                    case 5: sprintf(text, data_ov003_0217ea47); break;
                    case 6: sprintf(text, data_ov003_0217ea4c); break;
                    case 7: sprintf(text, data_ov003_0217ea51); break;
                    case 8: sprintf(text, data_ov003_0217ea56); break;
                    case 9: sprintf(text, data_ov003_0217ea5b); break;
                    case 10: sprintf(text, data_ov003_0217ea60); break;
                    case 11: sprintf(text, data_ov003_0217ea65); break;
                    case 12: sprintf(text, data_ov003_0217ea6a); break;
                    default: sprintf(text, data_ov003_0217ea6f); break;
                }
                func_02050678(&canvas, 0x51, row * 16 + 0x2f, text, 10, 15, &outA, &outB);
                switch (rec->category) {
                    case 2: sprintf(text, (char *) KeyTable_Get((Container020e0310 *) self->texts, 0)); break;
                    case 3:
                    case 4: sprintf(text, (char *) KeyTable_Get((Container020e0310 *) self->texts, 1)); break;
                    case 5:
                    case 6: sprintf(text, (char *) KeyTable_Get((Container020e0310 *) self->texts, 2)); break;
                    case 9:
                    case 10: sprintf(text, (char *) KeyTable_Get((Container020e0310 *) self->texts, 3)); break;
                    default: sprintf(text, (char *) KeyTable_Get((Container020e0310 *) self->texts, 4)); break;
                }
                func_02050678(&canvas, 0x80, row * 16 + 0x2f, text, 10, 15, &outA, &outB);
                canvas.unknown_b4_ = 8;
                canvas.unknown_b6_ = 8;
                sprintf(text, data_ov003_0217ea74, rec->year + 2000, rec->rank, rec->level);
                func_02050678(&canvas, 0xa0, row * 16 + 0x30, text, 8, 15, &outA, &outB);
            }
            if (inline_ov003_0216e714(GetProgress(run)) > 8) {
                canvas.unknown_b4_ = 8;
                canvas.unknown_b6_ = 8;
                func_02050678(&canvas, 0xc, 0xb2, data_ov003_0217ea83, 8, 15, &outA, &outB);
                func_02050678(&canvas, 0xee, 0xb2, data_ov003_0217ea86, 8, 15, &outA, &outB);
                canvas.unknown_b4_ = 10;
                canvas.unknown_b6_ = 10;
                sprintf(text, data_ov003_0217ea89, self->page, self->pages);
                func_02050678(&canvas, 0x71, 0xaf, text, 8, 15, &outA, &outB);
            }
            switch (self->move) {
                case 1: self->cursor = self->count - 1; break;
                case 2: self->cursor = 0; break;
            }
            self->move = 0;
            if (self->cursor >= self->count) {
                self->cursor = self->count - 1;
            }
            Background_Init((struct BackgroundGraphics *) &bg);
            bg.lo = 0;
            bg.hi = 3;
            Background_SetMapSize((unsigned char *) &bg, 0);
            Background_SetScroll((struct BackgroundGraphics *) &bg, 0, 0);
            BG3CNT = (BG3CNT & 0x43) | 0xf00;
            for (int i = 0; i < numFiles; i++) {
                if (i == 2) {
                    File0216e714 *f  = files[i];
                    unsigned int len = f->size;
                    CleanInvalidateCacheRange((char *) f + 0x10, len);
                    LoadToMainBG3ScreenData((int) ((char *) f + 0x10), 0, len);
                } else {
                    Background_LoadFile(&bg, files[i], 0, sizes[i]);
                }
            }
            Background_UploadMap((struct BackgroundGraphics *) &bg, 0);
            Background_Destroy((struct BackgroundGraphics *) &bg);
            loader->RemoveTask(self->task);
            self->task = -1;
            if (!(self->flags & 0x20)) {
                DISPCNT     = (DISPCNT & ~0x1f00) | 0xf00;
                BG0CNT      = (BG0CNT & ~3) | 3;
                BG1CNT      = BG1CNT & ~3;
                BG2CNT      = (BG2CNT & ~3) | 1;
                BG3CNT      = (BG3CNT & ~3) | 2;
                self->state = 3;
                self->step  = 0;
            } else {
                DISPCNT     = (DISPCNT & ~0x1f00) | 0x1f00;
                BG0CNT      = BG0CNT & ~3;
                BG1CNT      = (BG1CNT & ~3) | 1;
                BG2CNT      = (BG2CNT & ~3) | 2;
                BG3CNT      = (BG3CNT & ~3) | 3;
                self->state = 4;
                self->step  = 0;
            }
        }
    }
}
#else
// USA: func_ov003_0216e714
extern "C" ARM void func_ov003_0216e714(Struct_ov003_0216e714_7 *self) {
    int end;
    Run0216e714 *run         = Zone3D_GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    if (self->step == 0) {
        self->task = loader->QueueLoadFileInGP2(data_ov003_0218028b, data_ov003_0218029b, 0);
        if (!(self->flags & 0x20)) {
            ColorEffect_ConfigureAlphaBlend(0x04000050, 0x18, 1, 0, 0x10);
        }
        self->step = 1;
    } else if (self->step == 1) {
        if (loader->GetTaskStatus(self->task) != 0) {
            Struct_ov003_0216e714_4 canvas;
            char text[0x80];
            File0216e714 *files[7];
            int sizes[7];
            char name[0x30];
            Struct_ov003_0216e714_5 bg;
            void *entry;
            void *file;
            unsigned int size;
            short outA;
            short outB;
            int row;
            int start;
            int index;
            Struct_ov003_0216e714_3 *rec;
            int y;
            int slot;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int numFiles = Pac_CountFiles((PacRecord *) file);
            for (int i = 0; i < numFiles; i++) {
                files[i] = (File0216e714 *) Pac_GetFile((PacRecord *) file, i, &entry, &sizes[i]);
            }
            WindowPane_Init(&canvas);
            canvas.text   = (char *) files[0] + 0x10;
            canvas.width  = 0x20;
            canvas.height = 0x18;
            canvas.unknown_b4_  = 10;
            canvas.unknown_b6_  = 10;
            row           = 0;
            start         = (self->page - 1) * 8;
            __clear(text, sizeof(text));
            slot = 0;
            memset(self->kinds, -1, sizeof(self->kinds));
            end = start + 8;
            for (index = start; index < end; row++, index++) {
                if (index >= inline_ov003_0216e714(GetProgress(run))) break;
                rec          = self->records[index];
                y            = row * 16 + 0x2f;
                canvas.unknown_b4_ = 10;
                canvas.unknown_b6_ = 10;
                __clear(name, sizeof(name));
                Font_DecodeText(rec, name, 1);
                if (index == self->selected + (self->page - 1) * 8) {
                    sprintf(text, data_ov003_021802a7, name);
                } else {
                    sprintf(text, data_ov003_021802b3, name);
                }
                func_0204f41c(&canvas, 0x14, y, text, 10, 15, &outA, &outB, 0);
                self->kinds[slot] = rec->kind;
                slot++;
                int key = 4;
                switch (rec->category) {
                    case 2: key = 0; break;
                    case 3:
                    case 4: key = 1; break;
                    case 5:
                    case 6: key = 2; break;
                    case 9:
                    case 10: key = 3; break;
                }
                sprintf(text, (char *) KeyTable_Get((Container020e0310 *) self->texts, key));
                func_0204f41c(&canvas, 0xb0 - Font_GetTextWidth(text, 0), y, text, 10, 15, &outA, &outB, 0);
                canvas.unknown_b4_ = 8;
                canvas.unknown_b6_ = 8;
                sprintf(text, data_ov003_021802b6, rec->level);
                func_0204f41c(&canvas, 0xc8 - Font_GetTextWidth(text, 0), y, text, 10, 15, &outA, &outB, 0);
                sprintf(text, data_ov003_021802b3,
                        (char *) KeyTable_Get((Container020e0310 *) self->texts,
                                                                                (short) (rec->rank + 0xe)));
                func_0204f41c(&canvas, 0xce, y, text, 10, 15, &outA, &outB, 0);
                sprintf(text, data_ov003_021802b6, rec->year + 2000);
                func_0204f41c(&canvas, 0xf4 - Font_GetTextWidth(text, 0), y, text, 10, 15, &outA, &outB, 0);
            }
            if (inline_ov003_0216e714(GetProgress(run)) > 8) {
                char *str = Font_FindGlyph(8, data_ov003_021802b9);
                if (str != 0) {
                    func_0204e038(&canvas, str, 0xc, 0xb2, 8, 8, 0xf0, 0xf);
                }
                str = Font_FindGlyph(8, data_ov003_021802bc);
                if (str != 0) {
                    func_0204e038(&canvas, str, 0xee, 0xb2, 8, 8, 0xf0, 0xf);
                }
                func_0204f41c(&canvas, 0x7e, 0xaf, data_ov003_0217f5bc, 8, 15, &outA, &outB, 0);
                sprintf(text, data_ov003_021802b6, self->page);
                func_0204f41c(&canvas, 0x7d - Font_GetTextWidth(text, 0), 0xaf, text, 8, 15, &outA, &outB, 0);
                sprintf(text, data_ov003_021802b6, self->pages);
                func_0204f41c(&canvas, 0x82, 0xaf, text, 8, 15, &outA, &outB, 0);
            }
            switch (self->move) {
                case 1: self->cursor = self->count - 1; break;
                case 2: self->cursor = 0; break;
            }
            self->move = 0;
            if (self->cursor >= self->count) {
                self->cursor = self->count - 1;
            }
            Background_Init((struct BackgroundGraphics *) &bg);
            bg.lo = 0;
            bg.hi = 3;
            Background_SetMapSize((unsigned char *) &bg, 0);
            Background_SetScroll((struct BackgroundGraphics *) &bg, 0, 0);
            BG3CNT = (BG3CNT & 0x43) | 0xf00;
            for (int i = 0; i < numFiles; i++) {
                if (i == 2) {
                    File0216e714 *f  = files[i];
                    unsigned int len = f->size;
                    CleanInvalidateCacheRange((char *) f + 0x10, len);
                    LoadToMainBG3ScreenData((int) ((char *) f + 0x10), 0, len);
                } else {
                    Background_LoadFile(&bg, files[i], 0, sizes[i]);
                }
            }
            Background_UploadMap((struct BackgroundGraphics *) &bg, 0);
            Background_Destroy((struct BackgroundGraphics *) &bg);
            loader->RemoveTask(self->task);
            self->task = -1;
            if (!(self->flags & 0x20)) {
                DISPCNT     = (DISPCNT & ~0x1f00) | 0xf00;
                BG0CNT      = (BG0CNT & ~3) | 3;
                BG1CNT      = BG1CNT & ~3;
                BG2CNT      = (BG2CNT & ~3) | 1;
                BG3CNT      = (BG3CNT & ~3) | 2;
                self->state = 3;
                self->step  = 0;
            } else {
                DISPCNT     = (DISPCNT & ~0x1f00) | 0x1f00;
                BG0CNT      = BG0CNT & ~3;
                BG1CNT      = (BG1CNT & ~3) | 1;
                BG2CNT      = (BG2CNT & ~3) | 2;
                BG3CNT      = (BG3CNT & ~3) | 3;
                self->state = 4;
                self->step  = 0;
            }
        }
    }
}
#endif
