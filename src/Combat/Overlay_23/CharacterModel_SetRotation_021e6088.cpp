#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };
void SetWords_021e60c4_021e60c4(void* obj, struct Words021e60c4* src);

// Overlay 23, originally SetFourWordBlocks_021e6088 (USA/EUR 0x021e6088, JPN 0x021e626c)
ARM void CharacterModel_SetRotation(void* obj, struct Words021e60c4* src) {
    SetWords_021e60c4_021e60c4(obj, src);
    SetWords_021e60c4_021e60c4((char*)obj + 0x408, src);
    SetWords_021e60c4_021e60c4((char*)obj + 0xac, src);
    SetWords_021e60c4_021e60c4((char*)obj + 0x35c, src);
}
