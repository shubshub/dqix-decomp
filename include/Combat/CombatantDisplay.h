#pragma once

struct Struct_020fdc60_2 {
    unsigned char unknown_0_[16];
    float unknown_10_;
};

extern "C" void MapDisplayMemberPanel_DrawStat(Display0201fdd0* display, int row, int combatant,
                             int amount, int maximum, int digitX, int digitY,
                             int barX, int barY, int fillCode, int frameCode,
                             unsigned int bank);
void MapDisplayMemberPanel_DrawHp(Display0201fdd0* display, int row, int combatant);
void MapDisplayMemberPanel_DrawMp(Display0201fdd0* display, int row, int combatant);

