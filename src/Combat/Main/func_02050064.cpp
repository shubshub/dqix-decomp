#include <globaldefs.h>

extern "C" void* GetMainBG0CharacterBase(void);
extern "C" void* GetMainBG1CharacterBase(void);
extern "C" void* GetMainBG2CharacterBase(void);
extern "C" void* GetMainBG3CharacterBase(void);
extern "C" void* GetSubBG0CharacterBase(void);
extern "C" void* GetSubBG1CharacterBase(void);
extern "C" void* GetSubBG2CharacterBase(void);
extern "C" void* GetSubBG3CharacterBase(void);

struct Struct_02050064 { char pad0[0x1c]; unsigned char sub : 4; unsigned char idx : 4; };
struct Struct_02050064_2 { char pad0[4]; Struct_02050064* s; };

// USA: func_02050064
extern "C" ARM void* func_02050064(Struct_02050064_2* obj) {
    void* result = 0;
    Struct_02050064* s = obj->s;
    if (!s->sub) {
        switch (s->idx) {
        case 0: result = GetMainBG0CharacterBase(); break;
        case 1: result = GetMainBG1CharacterBase(); break;
        case 2: result = GetMainBG2CharacterBase(); break;
        case 3: result = GetMainBG3CharacterBase(); break;
        }
    } else {
        switch (s->idx) {
        case 0: result = GetSubBG0CharacterBase(); break;
        case 1: result = GetSubBG1CharacterBase(); break;
        case 2: result = GetSubBG2CharacterBase(); break;
        case 3: result = GetSubBG3CharacterBase(); break;
        }
    }
    return result;
}
