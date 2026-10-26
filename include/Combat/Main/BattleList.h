#pragma once

struct PrimaryCombatStats {
    unsigned short currHP;
    unsigned short currMP;
    unsigned short maxHP;
    unsigned short maxMP;
    unsigned short attack;
    unsigned short defense;
    unsigned short agility;
    unsigned short unk;
    unsigned int charm : 10;
    unsigned int magicalMight : 10;
    unsigned int magicalMending : 10;
};

struct BaseCombatStats {
    char name[0x2C];   // the combatant's name: printed with %s and passed as a message string argument
    struct PrimaryCombatStats primaryStats;
};

struct ModifiableCombatStats {
    struct PrimaryCombatStats primaryStats; // 0xE
    char unk1[0x44];
    signed int attackBuff : 3;
    signed int defenseBuff : 3;
    signed int agilityBuff : 3;
    signed int charmBuff : 3;
    signed int magicalMightBuff : 3;
    signed int magicalMendingBuff : 3;
    signed int unknown_5a_2_ : 3;
};

class GameState;
class GameObject;

extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);
extern "C" void* GameState_GetParty(GameState* gameState);
extern "C" int func_02011538(GameState* gameState);