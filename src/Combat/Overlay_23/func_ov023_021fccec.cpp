#include <globaldefs.h>

struct Struct_ov023_021fccec_2 { unsigned int v[3]; };
struct Words021e60c4 { struct Struct_ov023_021fccec_2 unknown_0_; };
struct Struct_ov023_021fccec { unsigned char pad[0x864]; unsigned char flag : 1; };
extern "C" void CharacterModel_GetRotation(struct Words021e60c4* dst, void* src);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void func_020c54a4(int enable, unsigned int arg1, unsigned int arg2, unsigned short arg3);
extern "C" void CharacterModel_SetRotation(void* obj, struct Words021e60c4* src);

// USA: func_ov023_021fccec
extern "C" ARM void func_ov023_021fccec(void* obj) {
    func_020c54a4(0, 0, 0, 0);
    unsigned int flag = ((struct Struct_ov023_021fccec*)((char*)obj + 0x1000))->flag;
    void* entry = (char*)obj + 0x20 + flag * 0xc20;
    struct Words021e60c4 copy;
    struct Words021e60c4 tmp;
    CharacterModel_GetRotation(&tmp, entry);
    copy.unknown_0_ = tmp.unknown_0_;
    copy.unknown_0_.v[1] = copy.unknown_0_.v[1] + 0xFFFFFE67u;
    copy.unknown_0_.v[1] = fix32ReduceAngle0To2Pi(copy.unknown_0_.v[1]);
    CharacterModel_SetRotation(entry, &copy);
}
