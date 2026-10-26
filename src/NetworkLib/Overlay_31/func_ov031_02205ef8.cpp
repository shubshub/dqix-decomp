#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_02205ef8 {
    Struct_ov031_02205ef8* next;
    unsigned short length;
    unsigned short unknown_6_;
    unsigned int address;
    unsigned char data[1];
};

struct Struct_ov031_02205ef8_2 {
    char padding[0xfe];
    signed char unknown_fe_;
    char unknown_ff_;
    Struct_ov031_02205ef8* tail;
    Struct_ov031_02205ef8* volatile head;
    unsigned short unknown_108_;
    char unknown_10a_[2];
    BlockedContextList unknown_10c_;
};

struct Struct_ov031_02205ef8_3 {
    char padding[0x64];
    Struct_ov031_02205ef8_2* queue;
    char unknown_68_[8];
    volatile short flags;
};

struct Struct_ov031_02205ef8_4 {
    char padding[0x1c];
    void (*unknown_1c_)(void*);
};

extern Struct_ov031_02205ef8_4* data_ov031_022496a4;
extern "C" int func_ov031_02207180(void*);

// USA: func_ov031_02205ef8
extern "C" ARM int func_ov031_02205ef8(Struct_ov031_02205ef8_3* arg0, void* buffer, int length,
                                       unsigned short* arg3, unsigned int* arg4, int flags) {
    Struct_ov031_02205ef8_2* queue;
    Struct_ov031_02205ef8* packet;
    int result;
    int var3;
    queue = arg0->queue;
    packet = queue->head;
    var3 = DisableIRQInterrupts();
    packet = queue->head;
    if (packet == NULL) {
        int block = flags & 1;
        do {
            if (!block) {
                result = -6;
                break;
            }
            BlockCurrentContext(&queue->unknown_10c_);
            if (!func_ov031_02207180(arg0)) {
                int var5 = 0;
                if (arg0 != NULL) var5 = (arg0->flags & 1) != 0;
                if (var5) {
                    continue;
                }
            }
            result = -56;
            break;
        } while ((packet = queue->head) == NULL);
    }
    if (packet != NULL) {
        if (length > packet->length) {
            length = packet->length;
        }
        VectorizedInvertedMemcpy(packet->data, buffer, length);
        if (arg3 != NULL) {
            *arg3 = packet->unknown_6_;
        }
        if (arg4 != NULL) {
            *arg4 = packet->address;
        }
        result = packet->length;
        if (queue->unknown_fe_ == 0) {
            queue->head = packet->next;
            if (packet->next == NULL) {
                queue->tail = NULL;
            }
            data_ov031_022496a4->unknown_1c_(packet);
            queue->unknown_108_ -= result;
        }
    }
    SetIRQInterruptState(var3);
    return result;
}
