#include <globaldefs.h>

extern "C" void PartyMember_LearnSpell(unsigned char* obj, int index);

// USA: func_02083b8c
extern "C" ARM void func_02083b8c(unsigned char* obj, unsigned char* list, unsigned int count) {
    unsigned int i;
    for (i = 0; i < count; i++) {
        PartyMember_LearnSpell(obj, list[i]);
    }
}
