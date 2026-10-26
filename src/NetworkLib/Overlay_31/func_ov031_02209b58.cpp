#include <globaldefs.h>

struct Struct_ov031_02209b58_3 { unsigned char padding[0x454]; unsigned char unknown_454_; unsigned char status; };
struct Struct_ov031_02209b58 { unsigned char padding[0xc]; Struct_ov031_02209b58_3* state; };
struct Struct_ov031_02209b58_2 { unsigned char type; unsigned char unknown_1_; unsigned char unknown_2_; unsigned char unknown_3_; unsigned char unknown_4_; };

extern "C" int func_ov031_02203500(unsigned int*, void*);
extern "C" int func_ov031_02209840(void*, int, void*);
extern "C" void func_ov031_022098ac(void*, int, int);
extern "C" void func_ov031_022035e0(int, Struct_ov031_02209b58*);
extern "C" void func_ov031_02208ab0(Struct_ov031_02209b58_3*, void*);
extern "C" void func_ov031_022098d8(Struct_ov031_02209b58_3*, void*);
extern void* (*data_ov031_0224c994)(unsigned int);
extern void (*data_ov031_0224c9c0)(void*);

// USA: func_ov031_02209b58
extern "C" ARM int func_ov031_02209b58(Struct_ov031_02209b58* session) {
    Struct_ov031_02209b58_3* state = session->state;
    unsigned int length;
    Struct_ov031_02209b58_2* record;
    while (1) {
        record = (Struct_ov031_02209b58_2*)func_ov031_02203500(&length, session);
        if (length == 0) { state->status = 9; return state->status; }
        if (length >= 5) break;
    }
    if (record->type == 0x80) {
        if (state->unknown_454_ != 0 && state->status == 0) {
            length = record->unknown_1_;
            func_ov031_022035e0(2, session);
            unsigned char* data = (unsigned char*)data_ov031_0224c994(length);
            if (!data) { state->status = 9; return state->status; }
            if (func_ov031_02209840(data, length, session) != 0 || data[0] != 1) {
                state->status = 9;
            } else {
                func_ov031_02208ab0(state, data + 1);
            }
            func_ov031_022098ac(state, (int)data, length);
            data_ov031_0224c9c0(data);
        } else { state->status = 9; }
    } else {
        length = (record->unknown_3_ << 8) + record->unknown_4_ + 5;
        if (length > 0x4805) { state->status = 9; return state->status; }
        void* data = data_ov031_0224c994(length);
        if (!data) { state->status = 9; return state->status; }
        if (func_ov031_02209840(data, length, session) != 0) {
            data_ov031_0224c9c0(data);
            state->status = 9;
            return state->status;
        }
        func_ov031_022098d8(state, data);
    }
    return state->status;
}
