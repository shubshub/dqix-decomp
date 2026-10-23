#include <globaldefs.h>
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

void VramState_Restore(char* obj);
void VramState_Save(char* obj);

struct Obj020553ac;
void InitStruct020553ac(struct Obj020553ac* obj);
extern "C" int func_020553ec(void* obj, int typeId, void* alloc, void* fileData, unsigned int fileSize);

struct Node020d6d90 {
    unsigned char pad[0x1ec];
    struct Node020d6d90* next;
};

struct NameEntry020d6d90 { char name[12]; };
struct NamesTable020d6d90 { NameEntry020d6d90 items[6]; };
extern const NamesTable020d6d90 data_020ee230;

struct TypeTable020d6d90 { int items[6]; };
extern const TypeTable020d6d90 data_020ee218;

struct Obj020d6d90 {
    char pad0[0xa20];
    Node020d6d90* head;
    char pad1[0xa3c - 0xa24];
    unsigned char flagA3c;
};

// USA: func_020d6d90
ARM int LoadFilesAndBuildNodeList020d6d90(Obj020d6d90* obj, const void* narc, SafeAllocator* alloc, char* pairTablesBuf) {
    TypeTable020d6d90 types;
    NamesTable020d6d90 names;
    NameEntry020d6d90* nameEntry;
    int* typeEntry;
    Node020d6d90* prev;

    obj->flagA3c = 0;
    obj->head = NULL;

    VramState_Restore(pairTablesBuf);

    names = data_020ee230;
    types = data_020ee218;

    nameEntry = &names.items[0];
    typeEntry = &types.items[0];
    prev = NULL;

    while (nameEntry->name[0] != 0) {
        unsigned int fileSize;
        const void* fileData;
        if (GetFileInNarc(narc, nameEntry->name, &fileData, &fileSize, 0)) {
            Node020d6d90* node = (Node020d6d90*)alloc->Allocate(0x1f0);
            void* dataBuf = alloc->Allocate(fileSize);
            if (node != NULL && dataBuf != NULL) {
                memcpy(dataBuf, (void*)fileData, fileSize);
                InitStruct020553ac((struct Obj020553ac*)node);
                if (func_020553ec(node, *typeEntry, alloc, dataBuf, fileSize) != 0) {
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
        typeEntry++;
    }

    VramState_Save(pairTablesBuf);
    return 1;
}
