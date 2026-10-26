#include <globaldefs.h>
#include <std_library_functions.h>

struct SearchStruct0202c1a4;
struct Struct_ov017_021d1118_8 { unsigned char bytes[6]; };
struct Struct_ov017_021d15b0 {
    Struct_ov017_021d1118_8 unknown_0_;
    signed char sender;
    unsigned char active;
    unsigned char length;
    signed char record;
};
struct Struct_ov017_021d15b0_2 {
    Struct_ov017_021d1118_8 unknown_0_;
    char unknown_6_[0xc];
    unsigned short unknown_12_0_ : 14;
    unsigned short enabled : 1;
    unsigned short unknown_13_7_ : 1;
    unsigned char payload[24];
};
struct Struct_ov017_021d15b0_3 {
#if defined(jpn)
    char unknown_0_[0x6fc0];
#else
    char unknown1_0_[0x7200];
#endif
    Struct_ov017_021d15b0_2 records[16];
    Struct_ov017_021d15b0 slots[3];
};
#if defined(jpn)
struct Struct_ov017_021d15b0_4 { char unknown_0_[0x3964]; void* handler; };
#else
struct Struct_ov017_021d15b0_4 { char unknown_0_[0x3b84]; void* handler; };
#endif
struct Struct_ov017_021d1118 {
    char unknown_0_[4];
    unsigned char payload[14];
    unsigned char recipient : 2;
    unsigned char mode : 2;
    unsigned char unknown_12_4_ : 4;
    unsigned char type : 2;
    unsigned char length : 4;
    unsigned char unknown_13_6_ : 1;
    unsigned char unknown_13_7_ : 1;
};
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov017_021a99dc(void*, void*, int, int, int);

// USA: func_ov017_021d15b0
extern "C" ARM void func_ov017_021d15b0(int sender, Struct_ov017_021d1118* packet, Struct_ov017_021d15b0_3* store, Struct_ov017_021d15b0_4* context, SearchStruct0202c1a4* search) {
    void* handler = context->handler;
    int recipient = LinkSession_GetOwnSlot(search);
    if (!packet->unknown_13_7_) {
        if (recipient == packet->recipient) func_ov017_021a99dc(handler, packet->payload, packet->type, packet->length, packet->unknown_13_6_);
        return;
    }
    if (packet->type == 2) {
        if (packet->mode != 1) return;
        Struct_ov017_021d15b0* slot = store->slots;
        for (int i = 0; i < 3; i++, slot++) {
            if (slot->sender == sender) return;
            if (slot->sender < 0) {
                memcpy(slot, packet->payload, packet->length);
                slot->sender = sender;
                return;
            }
        }
        return;
    }
    if (packet->type != 0) return;
    if (packet->mode == 0 && recipient != packet->recipient) return;
    Struct_ov017_021d15b0* slot = store->slots;
    for (int i = 0; i < 3; i++, slot++) {
        if (slot->sender != sender) continue;
        if (slot->record < 0) {
            Struct_ov017_021d15b0_2* record = store->records;
            int recordIndex;
            for (recordIndex = 0; recordIndex < 16; recordIndex++, record++) {
                if (record->enabled) {
                    Struct_ov017_021d1118_8 var8 = slot->unknown_0_;
                    int var9;
                    for (int var10 = 0; var10 < 6; var10++) {
                        if (var8.bytes[var10] != record->unknown_0_.bytes[var10]) {
                            var9 = 0;
                            goto compared;
                        }
                    }
                    var9 = 1;
compared:
                    if (var9) {
                        slot->record = recordIndex;
                        slot->active = 1;
                        break;
                    }
                }
            }
            if (recordIndex == 16) return;
        }
        Struct_ov017_021d15b0_2* destination = &store->records[slot->record];
        memcpy(destination->payload + slot->length, packet->payload, packet->length);
        slot->length += packet->length;
        if (!packet->unknown_13_6_) return;
        slot->active = 0;
        slot->length = 0;
        slot->record = -1;
        return;
    }
}
