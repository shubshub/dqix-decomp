#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
void* NNS_SndArcSetCurrent(void* value);
int GetListEntryWord8020bd8ac(unsigned int index);
void SetListEntryWord8020bd8d4(unsigned int index, int value);

// USA: func_020be3f4
ARM void ClearListEntryIfMatch020be3f4(int a0, void* a1, unsigned int a2) {
    if (a1 == NULL) return;
    void* prev;
    unsigned int mask = DisableIRQInterrupts();
    prev = NNS_SndArcSetCurrent(a1);
    int val = GetListEntryWord8020bd8ac(a2);
    if (a0 == val) {
        SetListEntryWord8020bd8d4(a2, 0);
    }
    NNS_SndArcSetCurrent(prev);
    SetIRQInterruptState(mask);
}
