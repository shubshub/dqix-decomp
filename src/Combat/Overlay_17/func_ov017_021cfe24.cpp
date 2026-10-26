#include <globaldefs.h>

extern "C" int Zone3D_MarkLootableSearched(int a, int b, int c);

// USA: func_ov017_021cfe24
extern "C" ARM int func_ov017_021cfe24(void* obj, char* rec) {
    return Zone3D_MarkLootableSearched(*(unsigned short*)(rec + 4), *(unsigned short*)(rec + 6), *(unsigned short*)(rec + 8));
}
