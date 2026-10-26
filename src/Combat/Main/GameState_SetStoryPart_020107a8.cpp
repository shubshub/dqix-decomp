#include <globaldefs.h>

extern "C" unsigned char* Scenario_GetInstance(void);

enum { kScenarioStoryRecordIndex = 0x332, kScenarioStoryRecordSize = 0x1c };

// Main, originally SetField5cb4AndRecordByte1_020107a8 (USA 0x020107a8, EUR 0x020107b8, JPN 0x02010604)
ARM void GameState_SetStoryPart(char* gameState, int part) {
#if defined(jpn)
    *(int*)(gameState + 0x5a54) = part;
#else
    *(int*)(gameState + 0x5cb4) = part;
#endif
    unsigned char* scenario = Scenario_GetInstance();
    unsigned char* storyRecord = scenario + scenario[kScenarioStoryRecordIndex] * kScenarioStoryRecordSize;
    storyRecord[1] = part;
}
