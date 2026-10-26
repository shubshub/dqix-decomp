#include <globaldefs.h>
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);

struct Struct_020553ac;
extern "C" void func_020553ac(struct Struct_020553ac* obj);
extern "C" int func_020553ec(void* obj, int arg1, void* alloc, void* fileData, unsigned int fileSize);

struct Struct_020d6d90 {
    unsigned char pad[0x1ec];
    struct Struct_020d6d90* next;
};

struct Struct_020d6d90_2 { char name[12]; };
struct Struct_020ee230 { Struct_020d6d90_2 items[6]; };
extern const Struct_020ee230 data_020ee230;

struct Struct_020ee218 { int items[6]; };
extern const Struct_020ee218 data_020ee218;

struct Obj020d6d90 {
    char pad0[0xa20];
    Struct_020d6d90* head;
    char pad1[0xa3c - 0xa24];
    unsigned char unknown_a3c_;
};

// USA: func_020d6d90
extern "C" ARM int func_020d6d90(Obj020d6d90* obj, const void* narc, SafeAllocator* alloc, char* pairTablesBuf) {
    Struct_020ee218 types;
    Struct_020ee230 names;
    Struct_020d6d90_2* nameEntry;
    int* var3;
    Struct_020d6d90* prev;

    obj->unknown_a3c_ = 0;
    obj->head = NULL;

    VramState_Restore(pairTablesBuf);

    names = data_020ee230;
    types = data_020ee218;

    nameEntry = &names.items[0];
    var3 = &types.items[0];
    prev = NULL;

    while (nameEntry->name[0] != 0) {
        unsigned int fileSize;
        const void* fileData;
        if (GetFileInNarc(narc, nameEntry->name, &fileData, &fileSize, 0)) {
            Struct_020d6d90* node = (Struct_020d6d90*)alloc->Allocate(0x1f0);
            void* var8 = alloc->Allocate(fileSize);
            if (node != NULL && var8 != NULL) {
                memcpy(var8, (void*)fileData, fileSize);
                func_020553ac((struct Struct_020553ac*)node);
                if (func_020553ec(node, *var3, alloc, var8, fileSize) != 0) {
                    if (prev != NULL) {
                        prev->next = node;
                    } else {
                        obj->head = node;
                    }
                    prev = node;
                }
            }
        }
        nameEntry++;
        var3++;
    }

    VramState_Save(pairTablesBuf);
    return 1;
}
