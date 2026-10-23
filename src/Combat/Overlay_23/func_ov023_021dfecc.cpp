#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"
#include "Combat/MapDisplay.h"

struct Struct_ov023_021dcb70;
extern "C" unsigned char func_ov023_021dcb70(struct Struct_ov023_021dcb70* arg0);

struct Struct_020534ac;

void Background_Init(struct List0204af64* obj);

extern "C" void Background_SetPriority(void*, int);
void Background_SetMapSize(unsigned char* obj, int value);

struct Obj0204b5e8;
int Background_SetScroll(struct Obj0204b5e8* obj, int a, int b);

struct ActiveEntry02046900;
int Pac_CountFiles(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);

void Background_FlushFile(void* obj, char* str);

struct SelfTag0204b3a0;
void Background_UploadFile(struct SelfTag0204b3a0* self, char* str);

extern "C" int func_ov023_021e20f0(void*, void*, void*, void*);

extern "C" void func_ov023_021e20c0(void* arg0);

extern "C" void func_ov023_021dde00(void* arg0);
extern "C" void func_ov023_021dbd10(void* arg0, void* arg1);

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);

extern const char* data_ov023_021fda78[];

// USA: func_ov023_021dfecc
extern "C" ARM int func_ov023_021dfecc(void* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021dfecc_1844=0x6b0, Enum_ov023_021dfecc_1792=0x600, Enum_ov023_021dfecc_124=0xf8, Enum_ov023_021dfecc_1912=0x6f4, Enum_ov023_021dfecc_1884=0x6d8, Enum_ov023_021dfecc_123=0xf7, Enum_ov023_021dfecc_1888=0x6dc, Enum_ov023_021dfecc_1896=0x6e4, Enum_ov023_021dfecc_1913=0x6f5, Enum_ov023_021dfecc_116=0xf0, Enum_ov023_021dfecc_1848=0x6b4};
#else
 enum {Enum_ov023_021dfecc_1844=0x734, Enum_ov023_021dfecc_1792=0x700, Enum_ov023_021dfecc_124=0x7c, Enum_ov023_021dfecc_1912=0x778, Enum_ov023_021dfecc_1884=0x75c, Enum_ov023_021dfecc_123=0x7b, Enum_ov023_021dfecc_1888=0x760, Enum_ov023_021dfecc_1896=0x768, Enum_ov023_021dfecc_1913=0x779, Enum_ov023_021dfecc_116=0x74, Enum_ov023_021dfecc_1848=0x738};
#endif
    unsigned char* var0 = (unsigned char*)arg0;
    struct Struct_02020cb8 var1;
    int var2;
    void* var3;
    int var4;
    int var5;
    void* var6;
    int var7;

    int var8 = (int)BackgroundLoader::GetInstance();
    int var9 = *(int*)(var0 + Enum_ov023_021dfecc_1844);
    if (((BackgroundLoader*)(var8))->GetTaskStatus((int)(var9)) != 0) {
        unsigned char var10 = func_ov023_021dcb70((struct Struct_ov023_021dcb70*)*(void**)(var0 + 0x50));
        ((BackgroundLoader*)((struct Struct_020534ac*)var8))->GetLoadedFileByID((int)(*(int*)(var0 + Enum_ov023_021dfecc_1844)), (void**)(&var2), (unsigned int*)(&var4));

#if defined(jpn)
        if (var2 != 0) {
#else
        if (var2 != 0 && var4 != 0) {
#endif

            Background_Init(&listObj);

            signed char var11 = *(signed char*)(var0 + Enum_ov023_021dfecc_1792 + Enum_ov023_021dfecc_124);
            if (var11 == 1) {
                var1.unknown_1c_0_ = var11;
                var1.unknown_1c_4_ = 1;
            } else {
                var1.unknown_1c_0_ = var11;
                var1.unknown_1c_4_ = 3;
            }

            Background_SetPriority(&listObj, 3);
            Background_SetMapSize((unsigned char*)&listObj, 0);
            Background_SetScroll((struct Obj0204b5e8*)&listObj, 0, 0);

            if (*(signed char*)(var0 + Enum_ov023_021dfecc_1792 + Enum_ov023_021dfecc_124) == 1) {
                volatile unsigned int* var12 = (volatile unsigned int*)0x4001000;
                unsigned int var13 = 0x12;
                if (var10 != 0) var13 |= 1;
                *var12 = (*var12 & ~0x1f00) | (var13 << 8);
            }

            if (lookupResult == 0 && *(unsigned char*)(obj + regionalOffset3) != 0) {
                int count = Pac_CountFiles((struct ActiveEntry02046900*)listVal1);
                for (unsigned char i = 0; i < count; i++) {
                    recPtr = Pac_GetFile((struct Rec020467f0*)listVal1, i, &dummyOut, &sizeOut);
                    if (recPtr) {
                        Background_FlushFile(&listObj, (char*)recPtr);
                        Background_UploadFile((struct SelfTag0204b3a0*)&listObj, (char*)recPtr);
                        func_ov023_021e20f0(obj + 0xcc, obj, recPtr, (void*)sizeOut);
                    }
                }
            } else {
                ClearFields_021e20c0(obj + 0xcc);
                ((SafeAllocator*)obj)->Reset();
                for (unsigned char i = 0; i < 4; i++) {
                    if (FindFilesInNarcBySubstring((const void*)listVal1, data_ov023_021fda78[i],
                            (const void**)&recPtr, (unsigned int*)&sizeOut, 1) != 0) {
                        if (i != 3) {
                            Background_FlushFile(&listObj, (char*)recPtr);
                            Background_UploadFile((struct SelfTag0204b3a0*)&listObj, (char*)recPtr);
                        } else {
                            func_ov023_021e20f0(var0 + 0xcc, var0, var3, (void*)var5);
                        }
                    }
                }
            }

            *(int*)(var0 + Enum_ov023_021dfecc_1884) = 0x3800;
            if (*(signed char*)(var0 + Enum_ov023_021dfecc_1792 + Enum_ov023_021dfecc_123) == 1) {
                *(int*)(var0 + Enum_ov023_021dfecc_1884) = 0x2800;
            }
            *(int*)(var0 + Enum_ov023_021dfecc_1888) = 0;
            *(int*)(var0 + Enum_ov023_021dfecc_1896) = 0;

            if (*(signed char*)(var0 + Enum_ov023_021dfecc_1792 + Enum_ov023_021dfecc_124) == 1) {
                memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
                if (*(void**)(var0 + 0x50) != 0) {
                    func_ov023_021dde00(var0);
                    volatile unsigned int* var17 = (volatile unsigned int*)0x4001000;
                    *var17 = (*var17 & ~0x1f00) | 0x1300;
                }
            } else {
                memset((void*)GetMainBG2ScreenBase(), 0, 0x800);
                if (*(void**)(var0 + 0x50) != 0) {
                    func_ov023_021dde00(var0);
                }
            }
            func_ov023_021dbd10(var0 + 0xcc, *(void**)(var0 + 0x50));
        }

        *(unsigned char*)(var0 + Enum_ov023_021dfecc_1913) = var10;
        ((BackgroundLoader*)(var8))->RemoveTask((int)(*(int*)(var0 + Enum_ov023_021dfecc_1844)));
        *(int*)(var0 + Enum_ov023_021dfecc_1844) = -1;
        *(void**)(var0 + 0x4c) = *(void**)(var0 + 0x50);
        *(void**)(var0 + 0x50) = 0;

        unsigned short var18 = *(unsigned short*)(var0 + Enum_ov023_021dfecc_1792 + Enum_ov023_021dfecc_116);
        if (var18 & 0x40) {
            if (!(var18 & 4)) {
                var18 |= 0x20;
                *(unsigned short*)(var0 + Enum_ov023_021dfecc_1792 + Enum_ov023_021dfecc_116) = var18;
            }
        }

        for (int var19 = 0; var19 < 7; var19++) {
            *(int*)(var0 + Enum_ov023_021dfecc_1848 + var19 * 4) = -1;
        }

        var18 = *(unsigned short*)(var0 + Enum_ov023_021dfecc_1792 + Enum_ov023_021dfecc_116);
        var18 |= 0x4;
        var18 |= 0x2000;
        *(unsigned short*)(var0 + Enum_ov023_021dfecc_1792 + Enum_ov023_021dfecc_116) = var18;

        var7 = (*(void**)(var0 + 0x4c) == 0) ? -1 : 2;
    } else {
        var7 = 1;
    }
    return var7;
}
