#include <globaldefs.h>

void PartyMember_LearnSpell(unsigned char* obj, int index);

// USA: func_02083b8c
ARM void SetBitsFromIndexList02083b8c(unsigned char* obj, unsigned char* list, unsigned int count) {
    unsigned int i;
    for (i = 0; i < count; i++) {
        PartyMember_LearnSpell(obj, list[i]);
    }
}
