#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };

struct WordsInner021fcc68 { unsigned int v[3]; };
struct LocalWords021fcc68 { struct WordsInner021fcc68 mid; };
struct FlagByte021fcc68 { unsigned char pad[0x864]; unsigned char flag : 1; };
extern "C" void CharacterModel_GetRotation(struct LocalWords021fcc68* dst, void* src);
int fix32ReduceAngle0To2Pi(int angle);
void SetFogState_020c54a4(int enable, unsigned int fogMode, unsigned int fogShift, unsigned short fogOffset);
void CharacterModel_SetRotation(void* obj, struct Words021e60c4* src);

// USA: func_ov023_021fcc68  (semantic: ResetFogAndSelectedEntryAngle_021fcc68)
extern "C" ARM void func_ov023_021fcc68(void* obj) {
    SetFogState_020c54a4(0, 0, 0, 0);
    unsigned int flag = ((struct FlagByte021fcc68*)((char*)obj + 0x1000))->flag;
    void* entry = (char*)obj + 0x20 + flag * 0xc20;
    struct LocalWords021fcc68 copy;
    struct LocalWords021fcc68 tmp;
    CharacterModel_GetRotation(&tmp, entry);
    copy.mid = tmp.mid;
    copy.mid.v[1] = copy.mid.v[1] + 0x199u;
    copy.mid.v[1] = fix32ReduceAngle0To2Pi(copy.mid.v[1]);
    CharacterModel_SetRotation(entry, (struct Words021e60c4*)&copy);
}
