#include <globaldefs.h>

int WH_GetLastError(void);
int WH_GetSystemState(void);
void SleepCurrentContext(unsigned int);

// USA: func_0202b284
ARM int PollUntilFieldMatchesOrLimit0202b284(int unused, int threshold) {
    unsigned int i = 0;
    int cur;
    while ((cur = WH_GetSystemState()) != threshold) {
        if (WH_GetLastError() == 8) return 3;
        if ((unsigned int)(cur - 9) <= 1) return 1;
        i++;
        if (i > 0x4e20) return 2;
        SleepCurrentContext(1);
    }
    return 0;
}
