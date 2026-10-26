#pragma once

struct Struct_0201cb60 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned char unknown_4_;
    char unknown_5_[7];
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};

struct Struct_0201cb60_2 {
    struct Struct_0201cb60 *unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

void *GameState_GetZoneTable(void *obj);
Elem0209998c *ZoneTable_FindEntryByMapCode(List0209998c *list, const char *name);
