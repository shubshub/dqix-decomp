#include <globaldefs.h>
#include "Filesystem/Pac.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* arg0, int arg1);

void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

int Pac_CountFiles(struct PacRecord* entry);

struct BackgroundGraphics;
void Background_AllocateScreens(struct BackgroundGraphics* obj, int count, SafeAllocator* alloc);

extern "C" void Background_LoadFile(struct BackgroundGraphics* obj, void* data, SafeAllocator* alloc, int field44);

extern char data_ov023_021fe5f4[];

struct Struct_ov023_021f7688 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
};

// USA: func_ov023_021f7aac
extern "C" ARM void func_ov023_021f7aac(struct Obj021f7aac* obj, void* keyObj, struct PacRecord* entry, unsigned int entryLength) {
#if defined(jpn)
 enum {Enum_ov023_021f7aac_40=0x24};
#else
 enum {Enum_ov023_021f7aac_40=0x28};
#endif
    if (arg2 == 0 || arg3 == 0) return;

    void* var0 = func_ov011_021845f8(arg1, arg0->unknown_8_);
    if (var0 == 0) return;

    int count = Pac_CountFiles((struct PacRecord*)entry);
    int matchCount = 0;
    int i;
    for (i = 0; i < count; i++) {
        int field44;
        void* rec;
        Pac_GetFile(entry, i, &rec, &field44);
        if (strstr((char*)rec, data_ov023_021fe5f4) != NULL) matchCount++;
    }

    if (matchCount > 0) {
        Background_AllocateScreens((struct BackgroundGraphics*)((char*)obj + regionalOffset), (unsigned char)matchCount, (SafeAllocator*)((char*)base + 4));
    }

    int j;
    for (j = 0; j < count; j++) {
        int field44;
        void* rec;
        void* data = Pac_GetFile(entry, j, &rec, &field44);
        if (data != 0) {
            Background_LoadFile((struct BackgroundGraphics*)((char*)obj + regionalOffset), data, (SafeAllocator*)((char*)base + 4), field44);
        }
    }
}
