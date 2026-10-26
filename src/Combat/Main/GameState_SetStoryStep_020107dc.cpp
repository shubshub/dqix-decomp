#include <globaldefs.h>

extern "C" unsigned char* Scenario_GetInstance(void);

enum { kScenarioStoryRecordIndex = 0x332, kScenarioStoryRecordSize = 0x1c };

// Main, originally SetSlotByte020107dc (USA 0x020107dc, EUR 0x020107ec, JPN 0x02010638)
extern "C" ARM void GameState_SetStoryStep(char* gameState, int step) {
    unsigned char* storyRecord;
#if defined(jpn)
    *(int*)(gameState + 0x5a58) = step;
#else
    *(int*)(gameState + 0x5cb8) = step;
#endif
    storyRecord = Scenario_GetInstance();
    storyRecord += storyRecord[kScenarioStoryRecordIndex] * kScenarioStoryRecordSize;
    storyRecord[2] = (unsigned char)step;
}
