#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct ResetFieldsStruct {
    int f0;
    short f4;
    short f6;
    short f8;
    char pad0a[2];
    int fc;
    short f10;
    char pad12[2];
    int f14;
    short f18;
};
void PresetTable_Reset(struct ResetFieldsStruct* s);
void PresetTable_Destroy(struct ResetFieldsStruct* s);
void PresetTable_Load(void* param0, void* param1, const char* param2);

struct Entry02089fb0 {
    signed char id;
    unsigned char pad[0x3f];
};
struct EntryArray02089fb0 {
    struct Entry02089fb0* base;
    short count;
};
struct Entry02089fb0* FindEntryBySignedId02089fb0(struct EntryArray02089fb0* arr, int id);

extern "C" int Font_EncodeText(char* str, unsigned char* out, int id);

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

struct FlagByte020a93e0 {
    unsigned char pad[0x13f];
    unsigned char flags : 3;
};

// USA: func_020a93e0  (semantic: ProcessSlotsAndRunBufferedScripts020a93e0)
extern "C" ARM void func_020a93e0(char* param0) {
    char* elem2;
    int end;
    int i;
    for (i = 0; i < 13; i++) {
        char* elem = param0 + i * 0x23c;
        if (((struct FlagByte020a93e0*)elem)->flags != 0) {
            struct ResetFieldsStruct fields;
            SafeAllocator localAlloc;
            localAlloc.ResetAllocatorPointer();
            localAlloc.ResetAllocatorPointer();
            void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x800);
            localAlloc.CreateTypeA(mem, 0x800);
            PresetTable_Reset(&fields);
            PresetTable_Load(&fields, &localAlloc, 0);
            end = *(unsigned char*)(param0 + 0x1d11) + *(unsigned char*)(param0 + 0x1d0c);
            for (; i < end; i++) {
                elem2 = param0 + i * 0x23c;
                int flags2 = ((struct FlagByte020a93e0*)elem2)->flags;
                if (flags2 != 0) {
                    struct Entry02089fb0* e = FindEntryBySignedId02089fb0(
                        (struct EntryArray02089fb0*)&fields, (short)(flags2 + 7));
                    char* str = *(char**)((char*)e + 4);
                    Font_EncodeText(str, (unsigned char*)(elem2 + 0x140), 1);
                }
            }
            SignedAllocatorHeader* sig = localAlloc.GetSignedAllocator();
            PresetTable_Destroy(&fields);
            localAlloc.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, sig);
            return;
        }
    }
}
