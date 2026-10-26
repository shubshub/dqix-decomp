#pragma once

struct Display0201fdd0 {
    unsigned char unknown0[16];
    float y;
};

extern "C" void MapDisplayMemberPanel_DrawStat(Display0201fdd0* display, int row, int combatant,
                             int amount, int maximum, int digitX, int digitY,
                             int barX, int barY, int arg9, int arg10,
                             unsigned int bank);
extern "C" void MapDisplayMemberPanel_DrawHp(Display0201fdd0* display, int row, int combatant);
extern "C" void MapDisplayMemberPanel_DrawMp(Display0201fdd0* display, int row, int combatant);

