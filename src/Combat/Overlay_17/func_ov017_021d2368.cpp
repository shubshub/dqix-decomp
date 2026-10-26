#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct Struct_ov017_021d2368 {
    unsigned char tag;
    unsigned char reserved[3];
    unsigned short kind : 2;
    unsigned short byteOffset : 14;
    unsigned char bytes[14];
};

struct Struct_ov017_021d2368_2 {
    unsigned char bytes[0x2e0];
};

struct BufferReceiverView {
    unsigned char unknown_0_[2];
    unsigned char active;
#if defined(jpn)
    unsigned char unknown_3_[0x218 - 3];
#else
    unsigned char unknown1_3_[0x288 - 3];
#endif
    Struct_ov017_021d2368_2* buffer;
};

extern "C" ARM void func_ov017_021d2368(int unused0, unsigned char* source, int arg2, unsigned char* arg3) {
    Struct_ov017_021d2368* event = (Struct_ov017_021d2368*)source;
    GameResources* resources = (GameResources*)arg3;
    BufferReceiverView* receiver = (BufferReceiverView*)resources->fieldTasks_[13];
    if (!receiver->active) return;
    Struct_ov017_021d2368_2* buffer = receiver->buffer;
    if (buffer == NULL) return;
    unsigned int offset = event->byteOffset;
    int length = sizeof(event->bytes);
    if (offset + sizeof(event->bytes) > sizeof(buffer->bytes)) {
        length = sizeof(buffer->bytes) - offset;
    }
    if (length < 0) return;
    memcpy(buffer->bytes + offset, event->bytes, length);
}
