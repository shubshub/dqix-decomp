#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_0220a6bc_2 {
    unsigned char unknown_0_[0x455]; unsigned char status, unknown_456_;
    unsigned char unknown_457_[0x824 - 0x457]; unsigned char* record; unsigned int total, unknown_82c_;
};
struct Struct_ov031_0220a6bc { unsigned char unknown_0_[0xc]; Struct_ov031_0220a6bc_2* context; unsigned char unknown_10_[0x34]; unsigned int available; };
extern "C" unsigned char* func_ov031_02203500(unsigned int*, void*);
extern unsigned char* (*data_ov031_0224c994)(unsigned int);
extern "C" void func_ov031_022035e0(unsigned int, void*);
extern "C" void func_ov031_022098d8(Struct_ov031_0220a6bc_2*, unsigned char*);

// USA: func_ov031_0220a6bc
extern "C" ARM void func_ov031_0220a6bc(Struct_ov031_0220a6bc* session) {
    Struct_ov031_0220a6bc_2* context = session->context;
    unsigned int length;
    if (context->record == NULL) {
        if (session->available < 5) return;
        unsigned char* header = func_ov031_02203500(&length, session);
        length = (header[3] << 8) + header[4] + 5;
        if (length > 0x4805) { context->status = 9; return; }
        context->record = data_ov031_0224c994(length);
        if (context->record == NULL) { context->status = 9; return; }
        context->total = length;
        context->unknown_82c_ = 0;
        context->unknown_456_ = 0;
    } else if (session->available == 0) return;
    unsigned char* source = func_ov031_02203500(&length, session);
    unsigned int remaining = context->total - context->unknown_82c_;
    int var5;
    if (length >= remaining) { length = remaining; var5 = 1; } else var5 = 0;
    VectorizedInvertedMemcpy(source, context->record + context->unknown_82c_, length);
    func_ov031_022035e0(length, session);
    if (var5) {
        func_ov031_022098d8(context, context->record);
        if (context->unknown_456_ == 0) context->record = NULL;
        return;
    }
    context->unknown_82c_ += length;
}
