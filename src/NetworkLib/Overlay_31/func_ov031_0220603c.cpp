#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Memory.h"

struct Struct_ov031_0220603c {
    Struct_ov031_0220603c* next;
    unsigned short length, type;
    unsigned int unknown_8_;
    unsigned char payload[1];
};
struct Struct_ov031_0220603c_2 {
    char unknown_0_[0x100];
    union { Struct_ov031_0220603c* last; signed int unknown1_100_; };
    Struct_ov031_0220603c* first;
    unsigned short used, capacity;
    BlockedContextList blocked;
};
struct Struct_ov031_0220603c_3 {
    char unknown_0_[0xa]; unsigned short unknown_a_;
    char unknown_c_[0xc]; unsigned short type, unknown_1a_;
    unsigned int unknown_1c_, unknown_20_;
    char unknown_24_[0x40]; Struct_ov031_0220603c_2* queue;
    char unknown_68_[0xc]; unsigned short pending;
};
struct Struct_ov031_0220603c_4 {
    char unknown_0_[0x18]; void* (*unknown_18_)(int);
};
struct Struct_ov031_0224e224 { unsigned int allocation, capacity; };
extern Struct_ov031_0220603c_4* data_ov031_022496a4;
extern Struct_ov031_0224e224 data_ov031_0224e224;

// USA: func_ov031_0220603c
extern "C" ARM int func_ov031_0220603c(const void* source, unsigned int length, Struct_ov031_0220603c_3* context) {
    Struct_ov031_0220603c_2* queue = context->queue;
    Struct_ov031_0220603c* packet;
    int var2 = DisableIRQInterrupts();
    if (queue->capacity >= queue->used + length) {
        packet = (Struct_ov031_0220603c*)data_ov031_022496a4->unknown_18_(length + 0xc);
        if (packet) {
            queue->used += length;
            packet->next = 0;
            packet->length = length;
            packet->type = context->type;
            packet->unknown_8_ = context->unknown_1c_;
            VectorizedInvertedMemcpy(source, packet->payload, length);
            if (queue->unknown1_100_) queue->last->next = packet;
            queue->last = packet;
            if (!queue->first) queue->first = packet;
        } else data_ov031_0224e224.allocation++;
    } else {
        data_ov031_0224e224.capacity++;
    }
    if (!context->pending) context->pending = context->unknown_a_;
    context->type = context->unknown_1a_;
    context->unknown_1c_ = context->unknown_20_;
    UnblockContexts(&queue->blocked);
    SetIRQInterruptState(var2);
    return 1;
}
