#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};
void KeyTable_Reset(Struct020dfc40* p);

struct Slot020e5114 {
    Struct020dfc40 inner;
    unsigned char pad2[4];
};

extern Slot020e5114 data_02153694[2];
extern SafeAllocator data_02153680;


extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);

extern char data_020f2dd4;
extern char data_020f2de9;
extern char data_020f2dfa;
extern char data_020f2e0e;

// USA: func_020e5114
ARM int ResetAndLoadAllocatorSlots020e5114(void) {
    data_02153680.Reset();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    for (int i = 0; i < 2; i++) {
        Slot020e5114* slot = &data_02153694[i];
        KeyTable_Reset(&slot->inner);
        unsigned int size;
        void* fileData;
        if (i != 0) {
            fileData = ExtractFileFromGP2((const char*)&data_020f2dd4, (const char*)&data_020f2de9, &size);
        } else {
            fileData = ExtractFileFromGP2((const char*)&data_020f2dfa, (const char*)&data_020f2e0e, &size);
        }
        if (fileData != NULL) {
            KeyTable_Load(slot, &data_02153680, fileData, size);
        }
    }
    BackgroundLoader::RemoveLockGlobal();
    return 0;
}
