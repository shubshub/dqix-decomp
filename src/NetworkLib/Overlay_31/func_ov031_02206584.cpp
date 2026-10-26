#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_02206584_3 {
    char unknown_0_[0x102];
    unsigned short count;
    BlockedContextList blocked;
};
struct Struct_ov031_02206584 {
    char unknown_0_[0x48];
    int length;
    char* buffer;
    char unknown_50_[0x18];
    Struct_ov031_02206584_3* queue;
    char unknown_6c_[4];
    short flags;
    char unknown_72_;
    signed char mode;
};
struct Struct_ov031_02206584_2 {
    int field_0x0;
    Struct_ov031_02206584* channel;
    char unknown_8_[8];
    char* unknown_10_;
    int unknown_14_;
    char* unknown_18_;
    int unknown_1c_;
    unsigned short count;
    unsigned short unknown_22_;
    unsigned short first;
    unsigned short second;
    unsigned int update;
};
extern "C" void func_ov031_022031bc(int, unsigned short, unsigned int);
extern "C" void func_ov031_02203424();
extern "C" int func_ov031_022066b4(int);
extern "C" int func_ov031_02206758(char*, int, Struct_ov031_02206584_2*);
extern "C" int func_ov031_02203a84(char*, int);

static inline bool inline_ov031_02206584(Struct_ov031_02206584* channel) {
    return channel->mode == 0 || channel->mode == 4;
}

// USA: func_ov031_02206584
extern "C" ARM int func_ov031_02206584(Struct_ov031_02206584_2* arg0) {
    char* buffer;
    Struct_ov031_02206584* channel;
    Struct_ov031_02206584_3* queue;
    int result;
    channel = arg0->channel;
    result = 0;
    queue = channel->queue;
    if (inline_ov031_02206584(channel)) {
        if (!(channel->flags & 4)) goto failed;
    }
    if (arg0->update != 0) {
        func_ov031_022031bc(arg0->first, arg0->second, arg0->update);
    }
    {
        buffer = channel->buffer;
        int headerSize = (channel->mode == 0 || channel->mode == 4) ? 0x36 : 0x2a;
        int length;
        if (channel->mode == 0 || channel->mode == 4) length = func_ov031_022066b4(channel->length - headerSize);
        else length = channel->length - headerSize;
        for (;;) {
            int copied = func_ov031_02206758(buffer + headerSize, length, arg0);
            if (copied <= 0) break;
            int var7 = func_ov031_02203a84(buffer + headerSize, copied);
            if (var7 <= 0) {
                if (inline_ov031_02206584(channel)) {
                    channel->flags &= ~0xe;
                    channel->flags |= 0x80;
                    func_ov031_02203424();
                }
                result = -76;
                break;
            }
            result += var7;
        }
        goto completed;
    }
failed:
    result = -76;
completed:
    queue->count = arg0->count;
    UnblockContexts(&queue->blocked);
    return result;
}
