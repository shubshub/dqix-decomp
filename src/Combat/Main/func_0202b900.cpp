#include <globaldefs.h>
#include "GameState/GameState.h"

extern char data_020feffc[];

int WH_GetSystemState(void);
int AdvanceStateIfState2_0202d0b4(void);
void SleepCurrentContext(unsigned int);
extern "C" int func_0202dc40(int arg0, void* arg1);
unsigned long long GetCurrentTimestamp(void);
extern "C" int memcmp(void* a, void* b, int n);

// USA: func_0202b900
extern "C" ARM int func_0202b900(int* arg0, unsigned char* arg1) {
    char* var0;
    int var1;
    int var2;
    int var3;
    int var4;
    int var5;
    GameState* var6;
    unsigned long long var7;

    i = 0;
    while (WH_GetSystemState() == 2) {
        AdvanceStateIfState2_0202d0b4();
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

    var3 = arg0[3];
    var2 = -1;
    var4 = 0;
    var5 = 0xc0;
    var0 = (char*)arg0;
    var0 += 0x10;

    for (; j < count; j++) {
        if (memcmp(key, entries + j * stride + 4, 6) == 0) {
            Init0202dc40(5, data_020feffc + j * stride);
            *obj = 6;
            battleStruct = GameState::GetInstance();
            ts = GetCurrentTimestamp();
            *(unsigned int*)((char*)battleStruct + 0x3f0) = (unsigned int)ts;
            result = j;
            *(unsigned int*)((char*)battleStruct + 0x3f4) = (unsigned int)(ts >> 32);
            break;
        }
    }
    return var2;
}
