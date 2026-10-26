#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov024_021fe698(char* obj, int type);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int slot, int value);

struct Struct_ov024_021fcc6c {
    char pad[4];
    unsigned short field4;
};

struct Struct_ov024_021fcc6c_2 {
    char pad0[4];
    short field4;
    char pad6[0x148 - 6];
    Struct_ov024_021fcc6c* state;
    char unknown_14c_[0x17c - 0x14c];
    unsigned char slot;
};

struct Struct_ov024_021fcc6c_3 {
    char pad[0x16];
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};

struct Struct_ov024_021fcc6c_4 {
    unsigned char* base;
    char pad4[2];
    unsigned char type;
    char unknown_7_[5];
    int fieldC;
    char pad10[0x7c - 0x10];
    Struct_ov024_021fcc6c_2* entries[8];
    int count;
};

struct Struct_ov024_021fcc6c_5 {
    char prefix[0xc4];
    float threshold;
};

// USA: func_ov024_021fcc6c
extern "C" ARM void func_ov024_021fcc6c(Struct_ov024_021fcc6c_4* obj) {
    float threshold = 1000.0f;
    int ok;
    if (obj->type == 2) {
        ok = 1;
    } else if (obj->type == 0) {
        return;
    } else {
        ok = 1;
        if (obj->fieldC >= 4) threshold = 50.0f;
    }
    if (!ok) return;
    if (!func_ov024_021fe698((char*)obj, 0x12)) return;
    Struct_ov024_021fcc6c_5 buf;
    for (int i = 0; i < obj->count; i++) {
        Struct_ov024_021fcc6c_2* entry = obj->entries[i];
        if ((int)entry->slot >= 0 && (int)entry->slot < 3) {
            Struct_ov024_021fcc6c* state = entry->state;
            if (!state) return;
            if (state->field4 != 0) {
                Struct_ov024_021fcc6c_3* record = (Struct_ov024_021fcc6c_3*)(obj->base + 0x81b4) + entry->slot;
                if (record->unknown_16_ == 0 && record->unknown_17_ == 0) {
                    memset(&buf, 0, sizeof(buf));
                    buf.threshold = threshold;
                    func_ov024_021f9874(obj, &buf, entry->slot, (unsigned char)entry->field4);
                }
            }
        }
    }
}
