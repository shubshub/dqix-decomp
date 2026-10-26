#include <globaldefs.h>
#include "NitroSDK/Memory.h"

typedef void* (*Type_ov031_02217c00)(const char*, unsigned int);
union Struct_ov031_02217c00 {
    struct {
        const char* name;
        int unknown_4_;
        int capacity;
        Type_ov031_02217c00 unknown_c_;
        int unknown_10_;
        int unknown_14_;
        int field_18;
    } fields;
    unsigned int words[7];
};
struct Struct_ov031_02217c00_2 {
    char unknown_0_[0x1000];
    struct Header {
        unsigned char state;
        char unknown_1_[3];
        Struct_ov031_02217c00 config;
        int result;
    } header;
    char unknown_1024_[0x9a8];
    void* unknown_19cc_;
    void* unknown_19d0_;
    char unknown_19d4_[0x34];
    struct {
        char unknown_0_[0x28];
        int unknown_28_;
        int unknown_2c_;
        char unknown_30_[0x1dc];
    } storage;
};
extern "C" int func_ov031_022187a4(char*, void*, int);
extern "C" int func_ov031_022188e4(Struct_ov031_02217c00_2*, const char*);
extern "C" int func_ov031_02218468(Struct_ov031_02217c00_2*);
extern const char data_ov031_02249db4[];
extern const char data_ov031_02249dcc[];

static inline Struct_ov031_02217c00_2::Header* inline_ov031_02217c00(Struct_ov031_02217c00_2* work) {
    return &work->header;
}

// USA: func_ov031_02217c00
extern "C" ARM int func_ov031_02217c00(Struct_ov031_02217c00_2* work, Struct_ov031_02217c00* config) {
    Type_ov031_02217c00 var0 = config->fields.unknown_c_;
    VectorizedMemset(work, 0, 0x1c14);
    work->storage.unknown_28_ = -1;
    work->storage.unknown_2c_ = -1;
    work->header.config = *config;
    work->unknown_19cc_ = var0(data_ov031_02249db4, 0xb68);
    if (!work->unknown_19cc_) {
        work->header.result = 1;
        return 1;
    }
    work->unknown_19d0_ = var0(data_ov031_02249dcc, 0x5ea);
    if (!work->unknown_19d0_) {
        work->header.result = 1;
        return 1;
    }
    switch (func_ov031_022187a4((char*)work, &work->storage, work->header.config.fields.capacity)) {
    case 0: {
        Struct_ov031_02217c00_2::Header* header = inline_ov031_02217c00(work);
        int result = 1;
        header->result = result;
        return result;
    }
    default:
        break;
    }
    switch (func_ov031_022188e4(work, config->fields.name)) {
    case 0: {
        Struct_ov031_02217c00_2::Header* header = inline_ov031_02217c00(work);
        int result = 1;
        header->result = result;
        return result;
    }
    default:
        break;
    }
    work->header.result = func_ov031_02218468(work);
    if (work->header.result == 0) work->header.state = 0xff;
    return work->header.result;
}
