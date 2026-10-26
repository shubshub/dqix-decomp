#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"


extern "C" void HaltSystem(void);

struct Slot021dd118 {
    void* f0;
    void* f4;
    void* f8;
    unsigned int fc;
};

struct Container021dd118 {
    unsigned char pad0[0x30];
    Slot021dd118 slots[4];
};

// USA: func_ov027_021dd118  (semantic: InsertSlotEntry_021dd118)
extern "C" ARM void func_ov027_021dd118(Container021dd118* obj, void* p1, void* p2, void* p3, unsigned int p4) {
    Slot021dd118* end;
    int ime;
    ime = DisableIRQInterrupts();
    Slot021dd118* slot = obj->slots;
    end = obj->slots + 4;
    for (;;) {
        if (slot >= end) {
            HaltSystem();
        }
        if (slot->fc == 0) {
            slot->f0 = p1;
            slot->f4 = p2;
            slot->f8 = p3;
            slot->fc = p4;
            break;
        }
        slot++;
    }
    SetIRQInterruptState(ime);
}
