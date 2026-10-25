#include <globaldefs.h>

extern "C" int memcmp(unsigned char* a, unsigned char* b, int len);
void WriteMaskBytes_0221b19c(int val, unsigned char* out);

struct SlotData_02236094 {
    unsigned char bytes[0xf0];
};

struct Slot_02236094 {
    SlotData_02236094 data;
    unsigned char pad[0x10];
};

struct Ctx_02236094 {
    Slot_02236094 slots[4];
    SlotData_02236094 current;
    unsigned char mask[4];
    unsigned char index;
    unsigned char valid;
    unsigned char validPair;
};

extern Ctx_02236094* data_ov031_02290cfc;
extern unsigned char data_ov031_02249248;

// USA: func_ov031_02236094  (semantic: CopySlotAndValidateChecksums_02236094)
extern "C" ARM void func_ov031_02236094(unsigned char param) {
    Ctx_02236094* g = data_ov031_02290cfc;
    unsigned char* slot = g->slots[param].data.bytes;

    g->current = g->slots[param].data;
    g->index = param;

    if (memcmp(slot + 0xc0, &data_ov031_02249248, 4) != 0) {
        data_ov031_02290cfc->valid = 0;
    } else {
        data_ov031_02290cfc->valid = 1;
    }

    if (memcmp(slot + 0xc8, &data_ov031_02249248, 4) != 0 ||
        memcmp(slot + 0xcc, &data_ov031_02249248, 4) != 0) {
        data_ov031_02290cfc->validPair = 0;
    } else {
        data_ov031_02290cfc->validPair = 1;
    }

    WriteMaskBytes_0221b19c(slot[0xd0], data_ov031_02290cfc->mask);
}
