#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_0208b9a0(void*, int);

void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

struct StructAllocGroup0208ba54 {
    SafeAllocator* allocatorArray; // 0x0
    unsigned char pad[0xbc - 4];
    int field_bc;
    int field_c0;
};

// USA: func_0208ba54
ARM void DestroyStructAllocGroup0208ba54(struct StructAllocGroup0208ba54* self) {
    int v = (int)BackgroundLoader::GetInstance();
    ((BackgroundLoader*)(v))->RemoveTask((int)(self->field_bc));
    self->field_bc = -1;
    ((BackgroundLoader*)(v))->RemoveTask((int)(self->field_c0));
    self->field_c0 = -1;

    if (self->allocatorArray != NULL) {
        int i;
        for (i = 0; i < 5; i++) {
            if (self->allocatorArray[i].GetSignedAllocator() != NULL) {
                self->allocatorArray[i].Destroy();
            }
        }
    }

    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
    func_0208b9a0(self, 0);
}
