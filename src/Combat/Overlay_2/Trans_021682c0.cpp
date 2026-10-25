#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Entry_0205d6a0;
void Window_ClosePane(Entry_0205d6a0*, int);
struct Container02186e74;
struct SafeAllocator;
void InitAllocatorArray02186e74(Container02186e74*, SafeAllocator*);
int GetField110ArrayValue021574d4(void*, int);
void SetPendingFlagAndSync_0215a878(char*);
void ResetAllocatorsAndClearFields0215b428(unsigned char*);
#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif
extern "C" void func_ov013_02186eec(void*, int);

// USA: func_ov002_021682c0  (semantic: Trans_021682c0)
extern "C" ARM void func_ov002_021682c0(char* self) {
    *(unsigned int*)(self + RG(0x247c, 0x22ac)) &= ~0x4;
    SetPendingFlagAndSync_0215a878(self);
    Window_ClosePane((Entry_0205d6a0*)(self + RG(0xec8, 0xe20)), 1);
    *(unsigned char*)(self + RG(0x2454, 0x2288)) = 0;
    *(unsigned char*)(self + RG(0x2455, 0x2289)) = 0;
#if !defined(jpn)
    ResetAllocatorsAndClearFields0215b428((unsigned char*)self);
#endif
    ((SafeAllocator*)(self + RG(0x850, 0x7b4)))->Reset();
    func_ov013_02186eec(self + RG(0x1d04, 0x1bc8), 1);
    InitAllocatorArray02186e74((Container02186e74*)(self + RG(0x1d04, 0x1bc8)), (SafeAllocator*)(self + RG(0x850, 0x7b4)));
    *(unsigned char*)(self + RG(0x1d6b, 0x1c1b)) = GetField110ArrayValue021574d4(self, *(short*)(self + RG(0x1c08, 0x1ad0)));
    (*(int*)(self + RG(0x1bc0, 0x1a88)))++;
}
