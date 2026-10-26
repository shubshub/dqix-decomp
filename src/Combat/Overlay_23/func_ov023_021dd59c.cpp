#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"


extern "C" int func_ov023_021ddbb8(void* obj, int a, int b);
struct Struct_ov023_021dd59c;
extern "C" int func_ov023_021ddbf8(struct Struct_ov023_021dd59c* obj);
extern "C" void func_020dc2bc(void);

struct Struct_02074b64;
extern "C" void func_02074b64(struct Struct_02074b64* obj);
extern "C" void func_02074af4(void* p);

struct Struct_020534ac;
struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);
extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);

extern "C" void func_ov023_021dcc58(void* obj);
extern "C" ARM void func_ov023_021db2e4(volatile int* p);

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

#if defined(jpn)
struct Struct_ov023_021ff9e0_8 { unsigned int pad0[5]; void* field4; };
#else
struct Struct_ov023_021ff9e0_8 { unsigned int pad0; void* field4; };
#endif

extern struct Struct_ov023_021ff9e0_8 data_ov023_021ff9e0;

extern int data_ov023_021fdb40;
extern int data_ov023_021fdb52;
extern int data_ov023_021fdb60;
extern int data_ov023_021fdb72;
extern int data_ov023_021fdb80;
extern int data_ov023_021fdb99;

#if defined(jpn)
extern char data_ov023_021fce2d[];
extern char data_ov023_021fce42[];
#endif
// USA: func_ov023_021dd59c
extern "C" ARM void func_ov023_021dd59c(void* objRaw) {
#if defined(jpn)
 enum {regionalOffset0=0x6f3, regionalOffset1=0x6f0, regionalOffset2=0x6f7, regionalOffset3=0x6f8, regionalOffset4=0x178, regionalOffset5=0x168, regionalOffset6=0x17c, Enum_ov023_021dd59c_376=0x174, Enum_ov023_021dd59c_1844=0x6b0, regionalOffset9=0x128, Enum_ov023_021dd59c_1917=0x6f9, Enum_ov023_021dd59c_1840=0x6ac, Enum_ov023_021dd59c_1910=0x6f2, Enum_ov023_021dd59c_1848=0x6b4, Enum_ov023_021dd59c_1876=0x6d0, Enum_ov023_021dd59c_280=0x114};
#else
 enum {regionalOffset0=0x777, regionalOffset1=0x774, regionalOffset2=0x77b, regionalOffset3=0x77c, regionalOffset4=0x17c, regionalOffset5=0x16c, regionalOffset6=0x180, Enum_ov023_021dd59c_376=0x178, Enum_ov023_021dd59c_1844=0x734, regionalOffset9=0x12c, Enum_ov023_021dd59c_1917=0x77d, Enum_ov023_021dd59c_1840=0x730, Enum_ov023_021dd59c_1910=0x776, Enum_ov023_021dd59c_1848=0x738, Enum_ov023_021dd59c_1876=0x754, Enum_ov023_021dd59c_280=0x118};
#endif
    char* obj = (char*)objRaw;
    int var1 = (int)BackgroundLoader::GetInstance();
    GameState::GetInstance()->GetResources();

    if (*(unsigned char*)(obj + regionalOffset0) == 0) {
        if (data_ov023_021ff9e0.field4 == 0) {
            data_ov023_021ff9e0.field4 = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x1800);
        }
        if (!(*(unsigned short*)(obj + regionalOffset1) & 0x40)) {
            *(unsigned char*)(obj + regionalOffset0) = 2;
            return;
        }
        if (*(signed char*)(obj + regionalOffset2) != 1) {
            func_ov023_021ddbb8(obj, ~0xf, 8);
        }
        *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 1) {
        if (func_ov023_021ddbf8((struct Struct_ov023_021dd59c*)obj) == 0) {
            if (*(signed char*)(obj + regionalOffset2) != 1) {
                func_020dc2bc();
            }
            *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
        }
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 2) {
        if (*(unsigned short*)(obj + regionalOffset1) & 0x10) {
            *(unsigned char*)(obj + regionalOffset0) = 4;
            return;
        }
        FontBankLoader* g = FontBankLoader_GetInstance();
        func_02094b30(g, 0x1fa, 0);
        *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
    } else if (*(unsigned char*)(obj + regionalOffset0) == 3) {
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
        }
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 4) {
        if (*(signed char*)(obj + regionalOffset3) == 1) {
            func_02074b64((struct Struct_02074b64*)(obj + Enum_ov023_021dd59c_280));
        } else {
            func_02074af4(obj + Enum_ov023_021dd59c_280);
        }
        *(char*)(obj + regionalOffset4) = *(signed char*)(obj + regionalOffset3);
        *(void**)(obj + regionalOffset5) = obj + regionalOffset6;
        *(short*)(obj + Enum_ov023_021dd59c_376) = 30;
#if defined(jpn)
        *(int*)(obj + Enum_ov023_021dd59c_1844) = ((BackgroundLoader*)(var1))->QueueLoadFile(data_ov023_021fce2d, (SafeAllocator*)0);
#else
        *(int*)(obj + Enum_ov023_021dd59c_1844) = ((BackgroundLoader*)(var1))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021fdb60), (const char*)((int)&data_ov023_021fdb72), (SafeAllocator*)(0));
#endif

        *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
    } else if (*(unsigned char*)(obj + regionalOffset0) == 5) {
        if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(*(int*)(obj + Enum_ov023_021dd59c_1844))) != 0) {
            ((SafeAllocator*)(*(void**)(obj + 0x44)))->Reset();
            void* dummyOut;
            int out1, out2;
            int fieldOut;
            ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(*(int*)(obj + Enum_ov023_021dd59c_1844)), (void**)(&out1), (unsigned int*)(&out2));
#if defined(jpn)
            {
#else
            if (out1 != 0 && out2 != 0) {
#endif

                int count = Pac_CountFiles((struct PacRecord*)out1);
                for (int i = 0; i < count; i++) {
                    void* result = Pac_GetFile((struct PacRecord*)out1, i, &dummyOut, &fieldOut);
                    SpriteContext_LoadFile(obj + regionalOffset9, result, fieldOut, *(void**)(obj + 0x44));
                }
            }
            *(signed char*)(obj + Enum_ov023_021dd59c_1917) = 1;
            ((BackgroundLoader*)(var1))->RemoveTask((int)(*(int*)(obj + Enum_ov023_021dd59c_1844)));
            *(int*)(obj + Enum_ov023_021dd59c_1844) = -1;
            *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
        }
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 6) {
#if defined(jpn)
        *(int*)(obj + Enum_ov023_021dd59c_1844) = ((BackgroundLoader*)(var1))->QueueLoadFile(data_ov023_021fce42, (SafeAllocator*)0);
#else
        *(int*)(obj + Enum_ov023_021dd59c_1844) = ((BackgroundLoader*)(var1))->QueueLoadFileInGP2((const char*)((int)&data_ov023_021fdb80), (const char*)((int)&data_ov023_021fdb99), (SafeAllocator*)(0));
#endif

        *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
    } else if (*(unsigned char*)(obj + regionalOffset0) == 7) {
        if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(*(int*)(obj + Enum_ov023_021dd59c_1844))) != 0) {
            int out1b, out2b;
            ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(*(int*)(obj + Enum_ov023_021dd59c_1844)), (void**)(&out1b), (unsigned int*)(&out2b));
            ((SafeAllocator*)(obj + 0x14))->Reset();
#if defined(jpn)
            {
#else
            if (out1b != 0 && out2b != 0) {
#endif

                KeyTable_Load(obj + 0x54, obj + 0x14, (void*)out1b, (unsigned int)out2b);
            }
            ((BackgroundLoader*)(var1))->RemoveTask((int)(*(int*)(obj + Enum_ov023_021dd59c_1844)));
            *(int*)(obj + Enum_ov023_021dd59c_1844) = -1;
            *(unsigned char*)(obj + regionalOffset0) = *(unsigned char*)(obj + regionalOffset0) + 1;
        }
    }

    if (*(unsigned char*)(obj + regionalOffset0) == 8) {
        unsigned int val;
        if (*(signed char*)(obj + regionalOffset3) == 1) {
            val = *(volatile unsigned int*)0x4001000;
        } else {
            val = *(volatile unsigned int*)0x4000000;
        }
        *(int*)(obj + Enum_ov023_021dd59c_1840) = (val & 0x1f00) >> 8;
        if (*(signed char*)(obj + regionalOffset2) != 1) {
            func_ov023_021dcc58(obj);
        }
        *(unsigned char*)(obj + Enum_ov023_021dd59c_1910) = 1;
        *(unsigned char*)(obj + regionalOffset0) = 0;
        func_ov023_021db2e4((volatile int*)(obj + Enum_ov023_021dd59c_1844));
        for (int i = 0; i < 7; i++) {
            func_ov023_021db2e4((volatile int*)(obj + Enum_ov023_021dd59c_1848 + i * 4));
        }
        *(int*)(obj + Enum_ov023_021dd59c_1876) = 0;
        *(unsigned short*)(obj + regionalOffset1) |= 1;
    }
}
