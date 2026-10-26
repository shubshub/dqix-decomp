#include <globaldefs.h>

struct Struct_02093980 {
#if defined(jpn)
    char name[11];
    unsigned char unknownB;
#else
    char name[48];
#endif
    short unknown_30_;
    signed char partySlot;
    unsigned char flags;
};

#include "std_library_functions.h"

// USA: func_02093980
extern "C" ARM void func_02093980(char* storage) {
    Struct_02093980* record = reinterpret_cast<Struct_02093980*>(storage);
    memset(record->name, 0, sizeof(record->name));
    record->unknown_30_ = -1;
    record->partySlot = -1;
    record->flags = 0;
}
