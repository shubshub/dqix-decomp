#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0209f634_4 {
    char field_0x0[0x12];
    short kind;
    char unknown_14_[0x10];
    unsigned char category;
    char field_0x25[0x1b];
};

struct Struct_0209f634 {
    union {
        struct {
            char field_0x0[0x5c60];
            Struct_0209f634_4 records[256];
        };
        struct {
            char unknown1_0_[0x8e07];
            unsigned char count;
        };
    };
};

struct Struct_0209f634_2 {
    Struct_0209f634_4 records[16];
    int unknown_400_;
};

struct Struct_0209f634_3 {
    int field_0x0;
    Struct_0209f634* table;
    char unknown_8_[0x90];
    int count;
    Struct_0209f634_2 primary;
    Struct_0209f634_4 unknown_4a0_[16];
};

// USA: func_0209f634
extern "C" ARM void func_0209f634(Struct_0209f634_3* context, int mode, int category) {
    int recordSize = sizeof(Struct_0209f634_4);
    if (mode == 0) {
        int count;
        int index;
        context->count = 0;
        count = context->table->count;
        for (index = 0; index < count; index++) {
            Struct_0209f634_4* record = &context->table->records[index];
            if (record == NULL) continue;
            int excluded = 0;
            if (record->kind >= 7 && record->kind <= 18) excluded = 1;
            if (!excluded && record->category == category) {
                int destination = context->count++;
                memcpy(&context->primary.records[destination], record, recordSize);
            }
        }
        return;
    }
    context->primary.unknown_400_ = 0;
    memset(context->unknown_4a0_, 0, 0x400);
    {
        Struct_0209f634_2* primary = &context->primary;
        int index;
        for (index = 0; index < context->count; index++) {
            Struct_0209f634_4* record = &primary->records[index];
            int excluded = 0;
            if (record->kind >= 7 && record->kind <= 18) excluded = 1;
            if (!excluded && record->category == category) {
                int destination = context->primary.unknown_400_;
                int current = primary->unknown_400_;
                primary->unknown_400_ = current + 1;
                memcpy(&context->unknown_4a0_[destination], record, recordSize);
            }
        }
    }
    context->count = context->primary.unknown_400_;
    memcpy(context->primary.records, context->unknown_4a0_, 0x400);
}
