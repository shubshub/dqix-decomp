#include <globaldefs.h>

struct Foo0207df50;
ARM void VramState_Rewind(struct Foo0207df50 *p);
ARM void VramState_Restore(char* obj);
ARM void VramState_Save(char* obj);
extern "C" void VramState_Reserve(void* p, int a, int b);

struct PairEntry020543ec { int a; int b; };
extern struct PairEntry020543ec data_020e7ce0[];
extern struct PairEntry020543ec data_020e7ce4[];

// USA: func_020543ec
ARM void InitSlotEntries020543ec(char* obj, char* p) {
    int i;
    VramState_Rewind((struct Foo0207df50*)p);
    VramState_Restore(p);
    for (i = 0; i < 10; i++) {
        VramState_Reserve(obj + 0xcc + i * 0x70, data_020e7ce0[i].a, data_020e7ce4[i].a);
    }
    VramState_Reserve(obj + 0x168 + 0x400, 0x240, 0x20);
    VramState_Save(p);
}
