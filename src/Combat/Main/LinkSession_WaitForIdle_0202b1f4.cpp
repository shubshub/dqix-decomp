#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x5a68 };
#else
enum { kRegionalFieldOffset = 0x5cc8 };
#endif

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

void* GlobalFlags_GetInstance(void);
struct FlagWord02046708;
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);
int PollUntilFieldMatchesOrLimit0202b284(int unused, int threshold);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void func_ov017_021c37a4(void);
struct GameResources;
void SetBrightness(GameResources*, int, int);
struct StateBits5ccc_11544;
void SetFlag0x5cccBit0_02011544(struct StateBits5ccc_11544* state);

// Main, originally func_0202b1f4 (USA 0x0202b1f4, EUR 0x0202b204, JPN 0x0202ada4)
extern "C" ARM int LinkSession_WaitForIdle(int* outPtr) {
    GameState* battleStruct = GameState::GetInstance();
    int ctx = ((int)GetGameResources());
    struct FlagWord02046708* flagWord = (struct FlagWord02046708*)GlobalFlags_GetInstance();
    if (FlagWord_TestBits(flagWord, 0x1000000)) {
        return 3;
    }
    int result = PollUntilFieldMatchesOrLimit0202b284((int)outPtr, 1);
    if ((unsigned int)((result + 0xfe) & 0xff) > 1) {
        return result;
    }
    FlagWord_SetBits((unsigned int*)flagWord, 0x1000000);
    func_ov017_021c37a4();
    SetBrightness((GameResources*)ctx, -16, 10);
    *(unsigned char*)((char*)battleStruct + kRegionalFieldOffset) = 4;
    SetFlag0x5cccBit0_02011544((struct StateBits5ccc_11544*)battleStruct);
    *outPtr = 3;
    return 3;
}
