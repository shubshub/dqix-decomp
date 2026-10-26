#include <globaldefs.h>

extern "C" void* GetMainBG0CharacterBase(void);
extern "C" void* GetMainBG1CharacterBase(void);
extern "C" void* GetMainBG2CharacterBase(void);
extern "C" void* GetMainBG3CharacterBase(void);
extern "C" void* GetSubBG0CharacterBase(void);
extern "C" void* GetSubBG1CharacterBase(void);
extern "C" void* GetSubBG2CharacterBase(void);
extern "C" void* GetSubBG3CharacterBase(void);

struct Struct_020e12c0 { char pad0[8]; unsigned char kind; };

// USA: func_020e12c0
extern "C" ARM void* func_020e12c0(Struct_020e12c0* obj) {
    void* result = 0;
    switch (obj->kind) {
    case 1: result = GetMainBG0CharacterBase(); break;
    case 2: result = GetMainBG1CharacterBase(); break;
    case 3: result = GetMainBG2CharacterBase(); break;
    case 4: result = GetMainBG3CharacterBase(); break;
    case 5: result = (void*)0x6400000; break;
    case 6: result = GetSubBG0CharacterBase(); break;
    case 7: result = GetSubBG1CharacterBase(); break;
    case 8: result = GetSubBG2CharacterBase(); break;
    case 9: result = GetSubBG3CharacterBase(); break;
    case 10: result = (void*)0x6600000; break;
    }
    return result;
}
