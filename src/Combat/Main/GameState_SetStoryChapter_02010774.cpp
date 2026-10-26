#include <globaldefs.h>

extern "C" unsigned char* Scenario_GetInstance(void);

enum { kScenarioStoryRecordIndex = 0x332, kScenarioStoryRecordSize = 0x1c };

// Main, originally SetField5cb0AndRecordByte0_02010774 (USA 0x02010774, EUR 0x02010784, JPN 0x020105d0)
extern "C" ARM void GameState_SetStoryChapter(char* gameState, int chapter) {
#if defined(jpn)
    *(int*)(gameState + 0x5a50) = chapter;
#else
    *(int*)(gameState + 0x5cb0) = chapter;
#endif
    unsigned char* scenario = Scenario_GetInstance();
    scenario[scenario[kScenarioStoryRecordIndex] * kScenarioStoryRecordSize] = chapter;
}
