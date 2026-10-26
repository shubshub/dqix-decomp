#pragma once

struct Elem0209998c {
    unsigned short f0;
    unsigned short f2;
    unsigned char f4;
    char unknown_5_[7];
    unsigned char fc;
    unsigned char unknown_d_;
    unsigned char fe;
    unsigned char pad;
};

struct List0209998c {
    struct Elem0209998c *data;
    int count;
    int cap;
};

extern "C" void *GameState_GetZoneTable(void *obj);
extern "C" Elem0209998c *ZoneTable_FindEntryByMapCode(List0209998c *list, const char *name);
