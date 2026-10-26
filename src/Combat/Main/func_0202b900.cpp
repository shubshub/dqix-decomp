#include <globaldefs.h>
#include "GameState/GameState.h"

extern char data_020feffc[];

extern "C" int WH_GetSystemState(void);
extern "C" int func_0202d0b4(void);
void SleepCurrentContext(unsigned int);
extern "C" int func_0202dc40(int mode, void* src);
unsigned long long GetCurrentTimestamp(void);
extern "C" int memcmp(void* a, void* b, int n);

// USA: func_0202b900
extern "C" ARM int func_0202b900(int* obj, unsigned char* key) {
    char* entries;
    int i;
    int result;
    int count;
    int j;
    int stride;
    GameState* battleStruct;
    unsigned long long var7;

    i = 0;
    while (WH_GetSystemState() == 2) {
        func_0202d0b4();
        i++;
        if (i > 0x1388) {
            return -1;
        }
        SleepCurrentContext(1);
    }

    i = 0;
    while (WH_GetSystemState() != 1) {
        i++;
        if (i > 0x1388) {
            return -1;
        }
        SleepCurrentContext(1);
    }

    count = obj[3];
    result = -1;
    j = 0;
    stride = 0xc0;
    entries = (char*)obj;
    entries += 0x10;

    for (; j < count; j++) {
        if (memcmp(key, entries + j * stride + 4, 6) == 0) {
            func_0202dc40(5, data_020feffc + j * stride);
            *obj = 6;
            battleStruct = GameState::GetInstance();
            var7 = GetCurrentTimestamp();
            *(unsigned int*)((char*)battleStruct + 0x3f0) = (unsigned int)var7;
            result = j;
            *(unsigned int*)((char*)battleStruct + 0x3f4) = (unsigned int)(var7 >> 32);
            break;
        }
    }
    return result;
}
