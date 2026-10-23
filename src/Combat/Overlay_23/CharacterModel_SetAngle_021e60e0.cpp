#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };
extern "C" void __clear(void*, int);
void SetWords_021e60c4_021e60c4(void* obj, struct Words021e60c4* src);

// Overlay 23, originally InitWordsQuad_021e60e0 (USA/EUR 0x021e60e0, JPN 0x021e62c4)
ARM void CharacterModel_SetAngle(void* obj, unsigned int val) {
    struct Words021e60c4 local;
    __clear(&local, 0xc);
    local.b = val;
    SetWords_021e60c4_021e60c4(obj, &local);
    SetWords_021e60c4_021e60c4((char*)obj + 0x8 + 0x400, &local);
    SetWords_021e60c4_021e60c4((char*)obj + 0xac, &local);
    SetWords_021e60c4_021e60c4((char*)obj + 0x35c, &local);
}
