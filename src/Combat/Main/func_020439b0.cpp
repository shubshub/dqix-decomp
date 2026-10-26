#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"
#include "Resource/MessageSystem.h"

#define REG_BG_SCROLL_020439b0 (*(volatile unsigned int*)0x04000018)
#define REG_DISPLAY_020439b0 (*(volatile unsigned int*)0x04000000)

extern "C" void func_0206b804(char* obj, int* out1, int* out2);
extern "C" void func_02044c74(void* obj, void* out);
extern "C" void func_02066cf0(void* self, int flag);
#if defined(jpn)
#define func_02044074 func_0204483c
#endif
extern "C" void func_02044074(struct Struct_02044074* s);
#if defined(jpn)
#define func_02042b98 func_02043270
#define func_02043600 func_02043de0
#endif
extern "C" void func_02042b98(void* self, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_0204408c(struct Struct_020439b0_7* s, short x, short y, short z, short w);
extern "C" void func_02043600(void* a, void* box);
#include "Resource/MessageUpdate.h"
extern "C" void MessageSystem_Stop(void* self);
extern "C" void func_020437bc(void* buf, void* box, int index);

struct Struct_0204394c;
#if defined(jpn)
#define func_0204394c func_02044104
#endif
extern "C" void func_0204394c(struct Struct_0204394c* obj);

struct Struct_020439b0;
extern "C" void func_020e2cc4(struct Struct_020439b0* obj, int enabled);

extern "C" void VramState_Restore(char* obj);
struct Struct_0200f3a4_13;
extern "C" void func_02041754(Struct_0204166c* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void func_02042af4(int unused, unsigned char* arr, int index);

struct Struct_020439b0_3;
extern "C" void func_020e2d2c(struct Struct_020439b0_3* s, int a, int b, int c, int d);

struct Struct_020439b0_4;
extern "C" void func_020e2c34(struct Struct_020439b0_4* obj);

struct Struct_020439b0_5 {
    short x;
    short y;
    short width;
    short height;
    int state;
};

struct Struct_02042b98_3 {
    char pad[0x440];
    Struct_020439b0_5* unknown_440_;
};

struct Struct_020439b0_6 { char unknown_0_[8]; int value; char unknown_c_[0xa8-0xc]; short unknown_a8_, count, unknown_ac_, unknown_ae_; };
struct Struct_02044074 { unsigned short x, y, z, w; };
struct Struct_020439b0_7 { short x, y, z, w; };
union Struct_020439b0_8 { Struct_02044074 zero; Struct_020439b0_7 bounds; };
#if defined(jpn)
enum { Enum_020439b0_52 = 0, Enum_020439b0_324 = 0x104, Enum_020439b0_332 = 0x10c,
       Enum_020439b0_707 = 0x213, Enum_020439b0_2324 = 0x7e4,
       Enum_020439b0_2352 = 0x800, Enum_020439b0_6624 = 0x1804,
       Enum_020439b0_116 = 0x40, Enum_020439b0_6586 = 0x17ea,
       Enum_020439b0_6603 = 0x17fc, Enum_020439b0_6498 = 0x1790 };
#else
enum { Enum_020439b0_52 = 0x34, Enum_020439b0_324 = 0x144, Enum_020439b0_332 = 0x14c,
       Enum_020439b0_707 = 0x2c3, Enum_020439b0_2324 = 0x914,
       Enum_020439b0_2352 = 0x930, Enum_020439b0_6624 = 0x19e0,
       Enum_020439b0_116 = 0x74, Enum_020439b0_6586 = 0x19ba,
       Enum_020439b0_6603 = 0x19cb, Enum_020439b0_6498 = 0x1962 };
#endif

struct Struct_020439b0_9 { short unknown_0_[0x400]; short tiles[0x400]; };
extern void* data_02107800;
#if defined(jpn)
#define TILE_MAP_BUFFER (*(void**)((char*)&data_02107800 + 0x30))
#else
#define TILE_MAP_BUFFER data_02107800
#endif

static inline short inline_020439b0(Struct_020439b0_6* stream) { return stream->unknown_a8_; }

// USA: func_020439b0
extern "C" ARM void func_020439b0(char* self, int flag) {
    MessageSystem* controller = (MessageSystem*)self;
    int dx, dy;
    Struct_020439b0_8 var3, var4, var5;

    if (controller->unknown_19cc_ != 0) {
        func_0206b804(self, &dx, &dy);
        func_02044c74(self, (*(Struct_020439b0_6**)(self + Enum_020439b0_52)));

        Struct_020439b0_6* stream = (*(Struct_020439b0_6**)(self + Enum_020439b0_52));
        int var7 = stream->value;
        if (var7 != 0) {
            stream->value = var7;

            controller->unknown_19cc_ = 0;
            func_02066cf0(self, 1);
            controller->unknown_19cc_ = 1;
            if (controller->unknown_19c0_ != 0) {
                controller->unknown_40_ = 0;
            }

            func_02044074(&var3.zero);
            func_02044074(&var4.zero);
            func_02044074(&var5.zero);

            if (controller->active != 0 && controller->unknown_19b1_ != 0) {
                goto prepareBounds;
            }
            if ((*(unsigned char*)(self + Enum_020439b0_6603)) != 0) {
            prepareBounds:
                if (controller->unknown_19b1_ != 0) {
                    func_02042b98(self, 2, 0x74, 0xfc, 0x4a);
                    func_0204408c(&var3.bounds, dx + 2, dy + 0x74, 0xfc, 0x4a);
                    func_02043600((*(Struct_020439b0_6**)(self + Enum_020439b0_52)), &var3);
                    func_0204408c(&var3.bounds, 2, 0x74, 0xfc, 0x4a);

                }

                if (controller->unknown_19c4_ != 0 && controller->unknown_19c3_ != 0) {
                    struct Struct_02042b98_3* holder = (Struct_02042b98_3*)(self + Enum_020439b0_6624);
                    holder->unknown_440_ = &(*(Struct_020439b0_5*)(self + Enum_020439b0_2352));
                    int cond = (holder->unknown_440_ != 0) ? (holder->unknown_440_->state == 2) : 0;
                    if (cond) {
                        short var10, var11, sz, var13;
                        if (holder->unknown_440_ != 0) {
                            var10 = holder->unknown_440_->x;
                            var11 = holder->unknown_440_->y;
                        }
                        if (holder->unknown_440_ != 0) {
                            sz = holder->unknown_440_->width;
                            var13 = holder->unknown_440_->height;
                        }
                        func_0204408c(&var4.bounds, var10 + dx, var11 + dy, sz, var13);
                        func_02043600((*(Struct_020439b0_6**)(self + Enum_020439b0_52)), &var4);
                        func_0204408c(&var4.bounds, var10, var11, sz, var13);
                    }
                    holder->unknown_440_ = &(*(Struct_020439b0_5*)(self + Enum_020439b0_2324));
                }

                if (controller->mode == 6) {
                    if ((*(unsigned char*)(self + Enum_020439b0_6586)) != 0 && (*(unsigned char*)(self + Enum_020439b0_707)) != 0) {
                        func_0204408c(&var5.bounds, (*(Struct_020439b0_7*)(self + Enum_020439b0_324)).x, (*(Struct_020439b0_7*)(self + Enum_020439b0_324)).y,
                            (*(Struct_020439b0_7*)(self + Enum_020439b0_324)).z, (*(Struct_020439b0_7*)(self + Enum_020439b0_324)).w);
                        func_02043600((*(Struct_020439b0_6**)(self + Enum_020439b0_52)), &var5);
                    }
                }
            }

            Struct_020439b0_6* var14 = (*(Struct_020439b0_6**)(self + Enum_020439b0_52));
            if (var14 != 0) {
                short i;
                int base;
                int val;
                short count;
                int step;
                short var20 = var14->unknown_ac_;
                short var21 = var14->unknown_ae_;
                short var22 = inline_020439b0(var14);
                count = var14->count;
                base = (var20 + (var21 << 5)) << 5;
                val = var14->value;
                i = 0;
                for (; i < count; i++) {
                    step = var22 << 5;
                    StageMemoryToVRAM(VRAMSubregion_MainBG3Character, (const void*)val, base, step, 1, 0);
                    val += step;
                    base += 0x400;
                }
            }

            int var23 = controller->unknown_94c_[0];
            int var24 = controller->unknown_94c_[1];
            REG_BG_SCROLL_020439b0 = ((-var23) & 0x1ff) | (((-var24) << 16) & 0x1ff0000);
            controller->unknown_94c_[0] = dx;
            controller->unknown_94c_[1] = dy;

            if (controller->mode != 1 && controller->mode != 0) {
                memset(TILE_MAP_BUFFER, 0, 0x800);

                if (controller->active != 0 && controller->unknown_19b1_ != 0) {
                    goto stageBounds;
                }
                if ((*(unsigned char*)(self + Enum_020439b0_6603)) != 0) {
                stageBounds:
                    if (controller->unknown_19b1_ != 0) {
                        void* var25 = TILE_MAP_BUFFER;
                        func_020437bc(var25, &var3, 0);
                        func_020437bc(var25, &var4, 1);
                        func_020437bc(var25, &var5, 2);
                        StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, var25, 0, 0x800, 1, 0);
                    }
                }

                if (controller->unknown_19b1_ == 0) {
                    StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, TILE_MAP_BUFFER, 0, 0x800, 1, 0);
                }

                if (!((*(unsigned int*)(self + Enum_020439b0_116)) != controller->unknown_78_ && controller->active != 0)) {
                    Struct_020439b0_9* buf = (Struct_020439b0_9*)TILE_MAP_BUFFER;
                    unsigned short i;
                    for (i = 0; i < 0x100; i++) {
                        buf->tiles[i] = 0;
                    }
                    for (unsigned short tableIndex = 0x100; tableIndex < 0x300; tableIndex++) {
                        buf->tiles[tableIndex] = (short)tableIndex;
                    }
                    StageMemoryToVRAM(VRAMSubregion_MainBG3Screen, buf->tiles, 0, 0x800, 1, 0);
                }
            }

            REG_DISPLAY_020439b0 = (REG_DISPLAY_020439b0 & ~0x1f00) | 0x1d00;
        }

        FreeVRAMStagingMemory((const void*)(*(Struct_020439b0_6**)(self + Enum_020439b0_52))->value);

        if (controller->active == 0) {
            func_02043040((MessageSystem*)self);
            MessageSystem_Stop(self);
            func_020430b0((MessageSystem*)self);
        }
    }

    if ((
#if defined(jpn)
            controller->flags17ff.unknown_0_0_
#else
            controller->unknown_19ce_
#endif
        ) != 0 && controller->unknown_44_ == 0) {
        func_0204394c((struct Struct_0204394c*)(controller->encoder));
    }
    {
        int i;
        for (i = 0; i < 2; i++) {
            func_020e2cc4((Struct_020439b0*)&controller->entries[i], 0);
        }
    }

    if (flag != 0 && controller->active == 0) return;
    {
        void* encoder = controller->encoder;
        if (encoder != 0) {
            Struct_0204166c* entry;
            int j;
            for (j = 0; j < 0x80; j++) {
                if (controller->unknown_17b8_[j] != 0) {
                    entry = &controller->glyphs[j];
                    if (entry->unknown_16_0_) {
                        if (controller->unknown_19cc_ != 0 || (
#if defined(jpn)
            controller->flags17ff.unknown_0_0_
#else
            controller->unknown_19ce_
#endif
        ) != 0) {
                            entry->unknown_16_0_ = 0;
                        } else {
                            VramState_Restore((char*)controller->encoder);
                            func_02041754(entry);
                            VramState_Save((char*)controller->encoder);
                        }
                        func_02042af4((int)self, controller->unknown_2cc_, entry->unknown_8_);
                    }
                }
            }
        }
    }

    if ((*(Struct_020439b0_5*)(self + Enum_020439b0_2324)).state >= 2) {
        func_020e2d2c((Struct_020439b0_3*)&controller->entries[0], 4, 0x76, 0xf8, 0x46);
        if ((*(unsigned char*)(self + Enum_020439b0_6498)) != 0) {
            func_020e2cc4((Struct_020439b0*)&controller->entries[0], 1);
        }
    }

    if ((*(int*)(self + Enum_020439b0_332)) >= 2) {
        int left = (*(Struct_020439b0_7*)(self + Enum_020439b0_324)).x;
        int top = (*(Struct_020439b0_7*)(self + Enum_020439b0_324)).y;
        int right = (*(Struct_020439b0_7*)(self + Enum_020439b0_324)).z;
        int bottom = (*(Struct_020439b0_7*)(self + Enum_020439b0_324)).w;
        func_020e2d2c((Struct_020439b0_3*)&controller->entries[1], left + 2, top + 2, right - 4, bottom - 4);
        if ((*(unsigned char*)(self + Enum_020439b0_6498)) != 0) {
            func_020e2cc4((Struct_020439b0*)&controller->entries[1], 1);
        }
    }

    int k;
    for (k = 0; k < 2; k++) {
        func_020e2c34((Struct_020439b0_4*)&controller->entries[k]);
    }
}
