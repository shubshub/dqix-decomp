#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_020c8784;
extern "C" Struct_020c8784* func_020c8784(Struct_020c8784* head, Struct_020c8784* node);

struct Struct_020c87ac;
extern "C" Struct_020c87ac* func_020c87ac(Struct_020c87ac* head, Struct_020c87ac* blk);

struct Struct_020c8854 {
    int unk0;
    struct Struct_020c87ac* unknown_4_;
    struct Struct_020c8784* unknown_8_;
};

struct Struct_020c8854_2 {
    int unknown_0_;
    char pad4[0xc];
    struct Struct_020c8854* entries;
};

extern struct Struct_020c8854_2* data_02111564[];

// USA: func_020c895c
extern "C" ARM void func_020c895c(int tableIdx, int count, char* addr) {
    struct Struct_020c8854_2* table;
    struct Struct_020c8854* entry;
    char* blk;
    int state = DisableIRQInterrupts();
    table = data_02111564[tableIdx];
    if (count < 0) {
        count = table->unknown_0_;
    }
    entry = &table->entries[count];
    blk = addr - 0x20;
    entry->unknown_8_ = func_020c8784(entry->unknown_8_, (struct Struct_020c8784*)blk);
    entry->unknown_4_ = func_020c87ac(entry->unknown_4_, (struct Struct_020c87ac*)blk);
    SetIRQInterruptState(state);
}
