#include <globaldefs.h>
#include "Combat/BattleHeapOwner.h"
#if defined(jpn)
#define data_ov003_02180cc8 data_ov003_0217ef40
#endif
extern "C" void func_020e2490(Struct_020e2490*, int, int, void*, SafeAllocator*, int, unsigned char);
extern "C" void Sprite_Init(Struct0205a198*);
extern unsigned int data_ov003_02180cc8[2];

#if defined(jpn)
extern char data_ov003_0217ece4[];
char *data_ov003_0217ece0 = data_ov003_0217ece4;
char data_ov003_0217ece4[] = "\x82\xbb\x82\xa4\x82\xd1\x82\xc8\x82\xb5";
#endif

// USA: func_ov003_02173f70
extern "C" ARM void func_ov003_02173f70(Struct_ov003_02173f70* self, SafeAllocator* allocator) {
    if (allocator != NULL) {
        self->allocators = static_cast<SafeAllocator*>(allocator->Allocate(0x78));
        self->allocatedRecords = static_cast<Struct0205a198*>(allocator->Allocate(0x528));
        self->menu = static_cast<Manager0207f7f0*>(allocator->Allocate(sizeof(Manager0207f7f0)));
        self->unknown_82c_ = static_cast<ClearTarget0205a234*>(allocator->Allocate(8));
        self->manager = static_cast<Struct_020e2490*>(allocator->Allocate(0x24));
#if defined(jpn)
        func_020e2490(self->manager, 0, 1, self->unknown_82c_, allocator, 3, 0x40);
        static unsigned int sizes[6] = {0, 0x1800, 0x1e00, 0x400, 0x9800, 0x6000};
#else
        func_020e2490(self->manager, 0, 1, self->unknown_82c_, allocator, 4, 0x40);
        static unsigned int sizes[6] = {0, 0x2800, 0x1e00, 0x400, 0x9800, 0x6000};
#endif
        if (!(data_ov003_02180cc8[1] & 1)) {
#if defined(jpn)
            sizes[0] = 0x15c00;
#else
            sizes[0] = 0x16a66;
#endif
            data_ov003_02180cc8[1] |= 1;
        }
        for (unsigned char i = 0; i < 6; ++i) {
            unsigned int size = sizes[i];
            SafeAllocator* item = &self->allocators[i];
            item->ResetAllocatorPointer();
            item->CreateTypeA(allocator->Allocate(size), size);
            item->Reset();
        }
        func_0207f84c(self->menu);
        Manager0207f7f0* menu = self->menu;
        menu->lists = self->entries;
        menu->mode = 2;
        func_0207f7f0(self->menu, self->nodes, 8);
        self->menu->active = 2;
        for (unsigned char i = 0; i < 0x21; ++i)
            Sprite_Init(&self->allocatedRecords[i]);
        self->active = 0;
        self->records = self->allocatedRecords;
        self->count = 0x21;
        self->list = self->unknown_82c_;
    }
}
