#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"
#include "Combat/MapDisplay.h"

struct Struct_ov023_021dcb70;
extern "C" unsigned char func_ov023_021dcb70(struct Struct_ov023_021dcb70* p);

struct Struct_020534ac;

extern "C" void Background_Init(struct BackgroundGraphics* obj);

extern "C" void Background_SetPriority(void*, int);
extern "C" void Background_SetMapSize(unsigned char* obj, int value);

struct BackgroundGraphics;
extern "C" int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);

struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);

extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

extern "C" void Background_FlushFile(void* obj, char* str);

extern "C" void Background_UploadFile(struct BackgroundGraphics* self, char* str);

extern "C" int func_ov023_021e20f0(void*, void*, void*, void*);

extern "C" void func_ov023_021e20c0(void* p);

extern "C" void func_ov023_021dde00(void* obj);
extern "C" void func_ov023_021dbd10(void* obj, void* p);

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);

extern const char* data_ov023_021fda78[];

// USA: func_ov023_021dfecc
extern "C" ARM int func_ov023_021dfecc(void* objRaw) {
#if defined(jpn)
 enum {regionalOffset0=0x6b0, regionalOffset1=0x600, regionalOffset2=0xf8, regionalOffset3=0x6f4, regionalOffset4=0x6d8, regionalOffset5=0xf7, regionalOffset6=0x6dc, Enum_ov023_021dfecc_1896=0x6e4, Enum_ov023_021dfecc_1913=0x6f5, regionalOffset9=0xf0, Enum_ov023_021dfecc_1848=0x6b4};
#else
 enum {regionalOffset0=0x734, regionalOffset1=0x700, regionalOffset2=0x7c, regionalOffset3=0x778, regionalOffset4=0x75c, regionalOffset5=0x7b, regionalOffset6=0x760, Enum_ov023_021dfecc_1896=0x768, Enum_ov023_021dfecc_1913=0x779, regionalOffset9=0x74, Enum_ov023_021dfecc_1848=0x738};
#endif
    unsigned char* obj = (unsigned char*)objRaw;
    struct BackgroundGraphics listObj;
    int listVal1;
    void* recPtr;
    int var4;
    int sizeOut;
    void* dummyOut;
    int result;

    int var8 = (int)BackgroundLoader::GetInstance();
    int handle = *(int*)(obj + regionalOffset0);
    if (((BackgroundLoader*)(var8))->GetTaskStatus((int)(handle)) != 0) {
        unsigned char var10 = func_ov023_021dcb70((struct Struct_ov023_021dcb70*)*(void**)(obj + 0x50));
        ((BackgroundLoader*)((struct Struct_020534ac*)var8))->GetLoadedFileByID((int)(*(int*)(obj + regionalOffset0)), (void**)(&listVal1), (unsigned int*)(&var4));

#if defined(jpn)
        if (listVal1 != 0) {
#else
        if (listVal1 != 0 && var4 != 0) {
#endif

            Background_Init(&listObj);

            signed char f7c = *(signed char*)(obj + regionalOffset1 + regionalOffset2);
            if (f7c == 1) {
                listObj.subScreen_ = f7c;
                listObj.bgNumber_ = 1;
            } else {
                listObj.subScreen_ = f7c;
                listObj.bgNumber_ = 3;
            }

            Background_SetPriority(&listObj, 3);
            Background_SetMapSize((unsigned char*)&listObj, 0);
            Background_SetScroll((struct BackgroundGraphics*)&listObj, 0, 0);

            if (*(signed char*)(obj + regionalOffset1 + regionalOffset2) == 1) {
                volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
                unsigned int bits = 0x12;
                if (var10 != 0) bits |= 1;
                *reg = (*reg & ~0x1f00) | (bits << 8);
            }

            if (var10 == 0 && *(unsigned char*)(obj + regionalOffset3) != 0) {
                int count = Pac_CountFiles((struct PacRecord*)listVal1);
                for (unsigned char i = 0; i < count; i++) {
                    recPtr = Pac_GetFile((struct PacRecord*)listVal1, i, &dummyOut, &sizeOut);
                    if (recPtr) {
                        Background_FlushFile(&listObj, (char*)recPtr);
                        Background_UploadFile((struct BackgroundGraphics*)&listObj, (char*)recPtr);
                        func_ov023_021e20f0(obj + 0xcc, obj, recPtr, (void*)sizeOut);
                    }
                }
            } else {
                func_ov023_021e20c0(obj + 0xcc);
                ((SafeAllocator*)obj)->Reset();
                for (unsigned char i = 0; i < 4; i++) {
                    if (FindFilesInNarcBySubstring((const void*)listVal1, data_ov023_021fda78[i],
                            (const void**)&recPtr, (unsigned int*)&sizeOut, 1) != 0) {
                        if (i != 3) {
                            Background_FlushFile(&listObj, (char*)recPtr);
                            Background_UploadFile((struct BackgroundGraphics*)&listObj, (char*)recPtr);
                        } else {
                            func_ov023_021e20f0(obj + 0xcc, obj, recPtr, (void*)sizeOut);
                        }
                    }
                }
            }

            *(int*)(obj + regionalOffset4) = 0x3800;
            if (*(signed char*)(obj + regionalOffset1 + regionalOffset5) == 1) {
                *(int*)(obj + regionalOffset4) = 0x2800;
            }
            *(int*)(obj + regionalOffset6) = 0;
            *(int*)(obj + Enum_ov023_021dfecc_1896) = 0;

            if (*(signed char*)(obj + regionalOffset1 + regionalOffset2) == 1) {
                memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
                if (*(void**)(obj + 0x50) != 0) {
                    func_ov023_021dde00(obj);
                    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
                    *reg = (*reg & ~0x1f00) | 0x1300;
                }
            } else {
                memset((void*)GetMainBG2ScreenBase(), 0, 0x800);
                if (*(void**)(obj + 0x50) != 0) {
                    func_ov023_021dde00(obj);
                }
            }
            func_ov023_021dbd10(obj + 0xcc, *(void**)(obj + 0x50));
        }

        *(unsigned char*)(obj + Enum_ov023_021dfecc_1913) = var10;
        ((BackgroundLoader*)(var8))->RemoveTask((int)(*(int*)(obj + regionalOffset0)));
        *(int*)(obj + regionalOffset0) = -1;
        *(void**)(obj + 0x4c) = *(void**)(obj + 0x50);
        *(void**)(obj + 0x50) = 0;

        unsigned short var18 = *(unsigned short*)(obj + regionalOffset1 + regionalOffset9);
        if (var18 & 0x40) {
            if (!(var18 & 4)) {
                var18 |= 0x20;
                *(unsigned short*)(obj + regionalOffset1 + regionalOffset9) = var18;
            }
        }

        for (int i = 0; i < 7; i++) {
            *(int*)(obj + Enum_ov023_021dfecc_1848 + i * 4) = -1;
        }

        var18 = *(unsigned short*)(obj + regionalOffset1 + regionalOffset9);
        var18 |= 0x4;
        var18 |= 0x2000;
        *(unsigned short*)(obj + regionalOffset1 + regionalOffset9) = var18;

        result = (*(void**)(obj + 0x4c) == 0) ? -1 : 2;
    } else {
        result = 1;
    }
    return result;
}
