#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"

struct Struct_ov017_021ab6b0_2 {
    unsigned char pad0[0x566];
    unsigned short id;
};
extern "C" Struct_ov017_021ab6b0_2* func_02053c6c(unsigned char* obj);

struct Struct_ov017_021ab6b0 {
    unsigned short id;
    unsigned short key : 15;
};

struct Struct_ov017_021d83b0 {
    Struct_ov017_021ab6b0* header;
    unsigned short key;
    unsigned short group;
    unsigned short entryId;
    int unknown_c_;
    int field_0x10;
    int unknown_14_;
    short unknown_18_;
};
extern Struct_ov017_021d83b0 data_ov017_021d83b0;

// USA: func_ov017_021ab6b0
extern "C" ARM int func_ov017_021ab6b0(Script::Parameter* params, int numParams) {
    unsigned short key = (params++)->ToInt();
    if (data_ov017_021d83b0.header->key != key) {
        return 0;
    }
    if (key == data_ov017_021d83b0.key && data_ov017_021d83b0.group != 0) {
        return 0;
    }
    unsigned short group = (params++)->ToInt();
    if (group != 0 && group != data_ov017_021d83b0.header->id) {
        return 0;
    }
    int count = (numParams - 2) / 5;
    if (count == 0) {
        if (data_ov017_021d83b0.header->id == group) {
            data_ov017_021d83b0.entryId = 0;
        }
        return 0;
    }
    Struct_ov017_021ab6b0_2* info = func_02053c6c((unsigned char*)GameState::GetInstance()->GetProtagonist());
    unsigned short id;
    float a, b, c, d;
    for (int i = 0; i < count; i++) {
        id = (params++)->ToInt();
        a = (params++)->ToFloat();
        b = (params++)->ToFloat();
        c = (params++)->ToFloat();
        d = (params++)->ToFloat();
        if (id == info->id) {
            break;
        }
    }
    data_ov017_021d83b0.key = key;
    data_ov017_021d83b0.group = group;
    data_ov017_021d83b0.entryId = id;
    data_ov017_021d83b0.unknown_18_ = 4096.0f * a;
    data_ov017_021d83b0.unknown_c_ = 4096.0f * b;
    data_ov017_021d83b0.field_0x10 = 4096.0f * c;
    data_ov017_021d83b0.unknown_14_ = 4096.0f * d;
    return 1;
}
