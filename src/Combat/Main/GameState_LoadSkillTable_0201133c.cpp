#if defined(jpn)
#define SKILL_TABLE_CONTEXT_OFFSET 0x54cc
#else
#define SKILL_TABLE_CONTEXT_OFFSET 0x572c
#endif
#if defined(jpn)
#define SKILL_TABLE_OFFSET 0x54d4
#else
#define SKILL_TABLE_OFFSET 0x5734
#endif
#define SKILL_TABLE_SIZE 0x570
#include <globaldefs.h>
#include "std_library_functions.h"

struct Pair0209a338;
void ClearFirstTwoWords0209a338(Pair0209a338* p);
extern "C" void SkillTable_Load(void* a, void* b);

// Main, originally Init0201133c (USA 0x0201133c, EUR 0x0201134c, JPN 0x020110b0)
ARM void GameState_LoadSkillTable(char* gameState) {
    memset(gameState + SKILL_TABLE_OFFSET, 0, SKILL_TABLE_SIZE);
    ClearFirstTwoWords0209a338((Pair0209a338*)(gameState + SKILL_TABLE_CONTEXT_OFFSET));
    SkillTable_Load(gameState + SKILL_TABLE_CONTEXT_OFFSET, gameState + SKILL_TABLE_OFFSET);
}
