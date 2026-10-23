#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct CreationOptionOrder {
    signed char entries[10];
};
extern CreationOptionOrder CharacterCreationUI_styleOrder;

// Overlay 9, originally func_ov009_02188b14 (USA/EUR 0x02188b14, JPN 0x021898cc)
extern "C" ARM int CharacterCreationUI_SlotToStyleIndex(void* storage, int tab, int slot) {
    CharacterCreationUI* self = (CharacterCreationUI*)storage;
    CreationOptionOrder order = CharacterCreationUI_styleOrder;
    if (tab == CreationTab_Face) {
        if (self->sex) {
            order.entries[0] = 1;
            order.entries[1] = 0;
        } else {
            order.entries[0] = 4;
            order.entries[1] = 0;
            order.entries[2] = 1;
            order.entries[3] = 2;
            order.entries[4] = 3;
        }
        return order.entries[slot];
    }
    if (tab == CreationTab_HairStyle) {
        if (self->sex) {
            order.entries[0] = 6;
            order.entries[1] = 0;
            order.entries[2] = 1;
            order.entries[3] = 2;
            order.entries[4] = 3;
            order.entries[5] = 4;
            order.entries[6] = 5;
        }
        return order.entries[slot];
    }
    return slot;
}
