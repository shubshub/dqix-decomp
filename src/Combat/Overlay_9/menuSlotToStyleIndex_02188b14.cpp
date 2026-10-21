#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct CreationOptionOrder {
    signed char entries[10];
};
#if defined(jpn)
extern CreationOptionOrder data_ov009_0218b998;
#else
extern CreationOptionOrder data_ov009_0218a9bc;
#endif

// Overlay 9, originally func_ov009_02188b14 (USA/EUR 0x02188b14, JPN 0x021898cc)
extern "C" ARM int menuSlotToStyleIndex(void* storage, int type, int index) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
#if defined(jpn)
    CreationOptionOrder order = data_ov009_0218b998;
#else
    CreationOptionOrder order = data_ov009_0218a9bc;
#endif
    if (type == 5) {
        if (editor->sex) {
            order.entries[0] = 1;
            order.entries[1] = 0;
        } else {
            order.entries[0] = 4;
            order.entries[1] = 0;
            order.entries[2] = 1;
            order.entries[3] = 2;
            order.entries[4] = 3;
        }
        return order.entries[index];
    }
    if (type == 3) {
        if (editor->sex) {
            order.entries[0] = 6;
            order.entries[1] = 0;
            order.entries[2] = 1;
            order.entries[3] = 2;
            order.entries[4] = 3;
            order.entries[5] = 4;
            order.entries[6] = 5;
        }
        return order.entries[index];
    }
    return index;
}
