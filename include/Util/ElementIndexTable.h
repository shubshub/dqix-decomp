#pragma once

struct Struct_02019568 {
    char unknown_0_[0x20];
};

struct Struct_020177d4 {
    char unknown_0_[0xc];
    struct Struct_02019568 *unknown_c_;
    int unknown_10_;
};

Element_1f2a4 *BmdjScriptState_GetElementRecord(Manager_1f2a4 *manager, int index);
