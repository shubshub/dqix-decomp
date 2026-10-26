#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0224e3b8_5 {
    char pad[0x50];
    unsigned int unknown_50_;
    char pad1[0x5a - 0x54];
    unsigned char unknown_5a_;
    char pad2[0x5c - 0x5b];
};

extern Struct_ov031_0224e3b8_5 data_ov031_0224e3b8[4];

struct Struct_ov031_0220aa98 {
    void* context;
    int type;
    unsigned char status;
    unsigned char flags;
    char* ctx;
    unsigned int unknown_10_;
};

void MarkContextReadyAndSwitch(struct ProcessorContext*);

// USA: func_ov031_0220aa98
extern "C" ARM void func_ov031_0220aa98(unsigned int now) {
    int var0 = DisableIRQInterrupts();
    int i = 0;
    Struct_ov031_0224e3b8_5* entry = data_ov031_0224e3b8;
    do {
        if (entry->unknown_5a_ != 0 && (int)(now - entry->unknown_50_) > 0x3bd) {
            entry->unknown_5a_ = 0;
        }
        i++;
        entry++;
    } while (i < 4);
    SetIRQInterruptState(var0);

    ProcessorContext* ctx = data_02111304.firstContext;
    if (ctx == 0) {
        return;
    }
    do {
        Struct_ov031_0220aa98* p = (Struct_ov031_0220aa98*)ctx->unknown_A4;
        if (p != 0 && p->context != 0 && p->flags != 0 && p->status == 4 &&
            (unsigned char)p->ctx[0x455] < 8 && (int)(now - p->unknown_10_) > 0xef && p->type == 2) {
            p->status = 0;
            p->type = 0;
            MarkContextReadyAndSwitch((ProcessorContext*)p->context);
        }
        ctx = ctx->pNext;
    } while (ctx != 0);
}
