#include <globaldefs.h>

struct Words021e60c4 { unsigned int a, b, c; };
void CharacterModel_SetAngle(void* obj, unsigned int val);
void CharacterModel_SetRotation(void* obj, Words021e60c4* src);
extern "C" void CharacterModel_GetRotation(Words021e60c4* dst, char* src);
extern "C" void CharacterModel_InvalidatePart(void* obj, int index);

struct Struct_ov023_021e447c {
#if defined(jpn)
    char unknown_0_[0x124];
#else
    char unknown1_0_[0x128];
#endif
    void* unknown_128_;
    void* unknown_12c_;
#if defined(jpn)
    char unknown1_12c_[0x56c - 0x12c];
#else
    char unknown_130_[0x634 - 0x130];
#endif
    unsigned short unknown_634_;
};

// USA: func_ov023_021e447c
extern "C" ARM void func_ov023_021e447c(Obj021e447c* obj) {
    if (!(obj->f634 & 0x8)) return;
    if (*(unsigned char*)((char*)obj->f12c + 0xc12) != 0) return;
    if (obj->f634 & 0x40) {
        CharacterModel_SetAngle(obj->f128, 0x1eb);
        CharacterModel_SetAngle(obj->f12c, 0x1eb);
    } else {
        Words021e60c4 tmp;
        CharacterModel_GetRotation(&tmp, (char*)obj->f128);
        CharacterModel_SetRotation(obj->f12c, &tmp);
    }
    void* t = obj->f128;
    obj->f128 = obj->f12c;
    obj->f12c = t;
    CharacterModel_InvalidatePart(obj->f12c, 0);
    CharacterModel_InvalidatePart(obj->f12c, 1);
    CharacterModel_InvalidatePart(obj->f12c, 5);
    CharacterModel_InvalidatePart(obj->f12c, 6);
    CharacterModel_InvalidatePart(obj->f12c, 2);
    CharacterModel_InvalidatePart(obj->f12c, 3);
    CharacterModel_InvalidatePart(obj->f12c, 4);
    obj->f634 &= ~0x8;
    obj->f634 &= ~0x40;
}
