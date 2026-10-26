#include <globaldefs.h>
struct S02011ff0* GameState_FindPartyMemberData(void*, int);

struct S02011ff0 {
    char pad[0x56b];
    unsigned char f : 4;
};

// USA: func_02011ff0
ARM int GetLowNibbleAt0x56b_02011ff0(void* base, int index) {
    struct S02011ff0* p = GameState_FindPartyMemberData((void*)(base), (int)(index));
    return p ? p->f : 0;
}
