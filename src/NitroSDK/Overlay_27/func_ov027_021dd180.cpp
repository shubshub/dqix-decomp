#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

struct Struct_ov027_021dd180_2 {
    unsigned int base;
    unsigned int size;
    void* unknown_8_;
    unsigned int type;
};

struct Struct_ov027_021dd180 {
    int status;
    unsigned char unk4[0x2c];
    Struct_ov027_021dd180_2 unknown_30_[4];
};

// USA: func_ov027_021dd180
extern "C" ARM int func_ov027_021dd180(Struct_ov027_021dd180* table, unsigned int addr, void* dst, unsigned int len) {
    Struct_ov027_021dd180_2* end;
    Struct_ov027_021dd180_2* region;
    int result = 0;
    int var3 = DisableIRQInterrupts();

    region = table->unknown_30_;
    end = table->unknown_30_ + 4;
    if (region < end) {
        do {
            if (region->type >= 2) {
                int offset = addr - region->base;
                if (offset >= 0 && offset + len <= region->size) {
                    VectorizedInvertedMemcpy((char*)region->unknown_8_ + offset, dst, len);
                    table->status = 0;
                    result = 1;
                    break;
                }
            }
            region++;
        } while (region < end);
    }

    SetIRQInterruptState(var3);
    return result;
}
