#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_0208b9a0(void*, int);

extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

struct Struct_0208ba54 {
    SafeAllocator* unknown_0_; // 0x0
    unsigned char pad[0xbc - 4];
    int unknown_bc_;
    int unknown_c0_;
};

// USA: func_0208ba54
extern "C" ARM void func_0208ba54(struct Struct_0208ba54* self) {
    int v = (int)BackgroundLoader::GetInstance();
    ((BackgroundLoader*)(v))->RemoveTask((int)(self->unknown_bc_));
    self->unknown_bc_ = -1;
    ((BackgroundLoader*)(v))->RemoveTask((int)(self->unknown_c0_));
    self->unknown_c0_ = -1;

    if (self->unknown_0_ != NULL) {
        int i;
        for (i = 0; i < 5; i++) {
            if (self->unknown_0_[i].GetSignedAllocator() != NULL) {
                self->unknown_0_[i].Destroy();
            }
        }
    }

    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
    func_0208b9a0(self, 0);
}
