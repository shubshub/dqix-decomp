#include <globaldefs.h>
#include "Combat/BattleHeapOwner.h"
#if defined(jpn)
#define data_ov003_02180cc8 data_ov003_0217ef40
#endif
void InitEntryManager020e2490(EntryManager020e2490*, int, int, void*, SafeAllocator*, int, unsigned char);
void Sprite_Init(Struct0205a198*);
extern unsigned int data_ov003_02180cc8[2];

#if defined(jpn)
extern char data_ov003_0217ece4[];
char *data_ov003_0217ece0 = data_ov003_0217ece4;
char data_ov003_0217ece4[] = "\x82\xbb\x82\xa4\x82\xd1\x82\xc8\x82\xb5";
#endif

// USA: func_ov003_02173f70
extern "C" ARM void func_ov003_02173f70(Struct_ov003_02173f70* arg0, SafeAllocator* arg1) {
    if (arg1 != NULL) {
        arg0->unknown_4_ = static_cast<SafeAllocator*>(arg1->Allocate(0x78));
        arg0->unknown_830_ = static_cast<Struct_02043368_2*>(arg1->Allocate(0x528));
        arg0->unknown_89c_ = static_cast<Struct_0207f7f0*>(arg1->Allocate(sizeof(Struct_0207f7f0)));
        arg0->unknown_82c_ = static_cast<Struct_02043368*>(arg1->Allocate(8));
        arg0->unknown_0_ = static_cast<Struct_020e2490*>(arg1->Allocate(0x24));
#if defined(jpn)
        func_020e2490(arg0->unknown_0_, 0, 1, arg0->unknown_82c_, arg1, 3, 0x40);
        static unsigned int sizes[6] = {0, 0x1800, 0x1e00, 0x400, 0x9800, 0x6000};
#else
        func_020e2490(arg0->unknown_0_, 0, 1, arg0->unknown_82c_, arg1, 4, 0x40);
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
        for (unsigned char var0 = 0; var0 < 6; ++var0) {
            unsigned int var1 = sizes[var0];
            SafeAllocator* var2 = &arg0->unknown_4_[var0];
            var2->ResetAllocatorPointer();
            var2->CreateTypeA(arg1->Allocate(var1), var1);
            var2->Reset();
        }
        func_0207f84c(self->menu);
        Manager0207f7f0* menu = self->menu;
        menu->lists = self->entries;
        menu->mode = 2;
        InitNodeChain0207f7f0(self->menu, self->nodes, 8);
        self->menu->active = 2;
        for (unsigned char i = 0; i < 0x21; ++i)
            Sprite_Init(&self->allocatedRecords[i]);
        self->active = 0;
        self->records = self->allocatedRecords;
        self->count = 0x21;
        self->list = self->allocatedList;
    }
}
