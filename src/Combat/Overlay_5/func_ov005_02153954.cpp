#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct EquipmentMenu {
    SafeAllocator allocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator equippedAllocators_[8];
    SafeAllocator itemAllocators_[16];
    SafeAllocator dragAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator unknown_230_;
    SafeAllocator unknown_244_;
    SafeAllocator unknown_258_;
    SafeAllocator unknown_26c_;
    SafeAllocator unknown_280_;
    char unknown_294_[R(0x3d00, 0x3d88) - 0x294];
    char* pageFiles_;
    char* dragFile_;
    char* equippedFiles_;
    char* itemFile_;
};

// USA: func_ov005_02153954
extern "C" ARM void func_ov005_02153954(EquipmentMenu* self, SafeAllocator* allocator, SafeAllocator* arg2) {
    if (allocator == NULL || arg2 == NULL)
        return;
    self->modelAllocator_.CreateTypeA(arg2->Allocate(0x1300), 0x1300);
    for (int i = 0; i < 8; i++)
        self->equippedAllocators_[i].CreateTypeA(arg2->Allocate(R(0x100, 0xe0)), R(0x100, 0xe0));
    for (int i = 0; i < 16; i++)
        self->itemAllocators_[i].CreateTypeA(arg2->Allocate(R(0x100, 0xe0)), R(0x100, 0xe0));
    self->dragAllocator_.CreateTypeA(arg2->Allocate(R(0x100, 0xe0)), R(0x100, 0xe0));
    self->textAllocator_.CreateTypeA(arg2->Allocate(R(0x600, 0xc00)), R(0x600, 0xc00));
    self->unknown_244_.CreateTypeA(allocator->Allocate(0x1e00), 0x1e00);
    self->allocator_.CreateTypeA(allocator->Allocate(0x4b00), 0x4b00);
    self->unknown_258_.CreateTypeA(allocator->Allocate(0x4a00), 0x4a00);
    self->unknown_26c_.CreateTypeA(allocator->Allocate(0x1e00), 0x1e00);
    self->unknown_280_.CreateTypeA(arg2->Allocate(0x200), 0x200);
    self->pageFiles_ = (char*)allocator->Allocate(0x800);
    self->dragFile_ = (char*)arg2->Allocate(0x200);
    self->equippedFiles_ = (char*)allocator->Allocate(0x800);
    self->itemFile_ = (char*)arg2->Allocate(0x200);
}
