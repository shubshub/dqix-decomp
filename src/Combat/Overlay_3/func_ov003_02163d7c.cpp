#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov003_02163d7c_1788 = 0x4ec };
enum { Enum_ov003_02163d7c_1844 = 0x524 };
enum { Enum_ov003_02163d7c_1024 = 0x200 };
enum { Enum_ov003_02163d7c_162 = 0xca };
enum { Enum_ov003_02163d7c_205 = 0xc9 };
enum { Enum_ov003_02163d7c_206 = 0xca };
enum { Enum_ov003_02163d7c_207 = 0xcb };
enum { Enum_ov003_02163d7c_1187 = 0x2cb };
enum { Enum_ov003_02163d7c_1124 = 0x28c };
#else
enum { Enum_ov003_02163d7c_1788 = 0x6fc };
enum { Enum_ov003_02163d7c_1844 = 0x734 };
enum { Enum_ov003_02163d7c_1024 = 0x400 };
enum { Enum_ov003_02163d7c_162 = 0xa2 };
enum { Enum_ov003_02163d7c_205 = 0xcd };
enum { Enum_ov003_02163d7c_206 = 0xce };
enum { Enum_ov003_02163d7c_207 = 0xcf };
enum { Enum_ov003_02163d7c_1187 = 0x4a3 };
enum { Enum_ov003_02163d7c_1124 = 0x464 };
#endif

struct Field150 {
    char pad[0x14];
    unsigned char flag : 1;
};

struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_ov017_02195530(unsigned char*);
struct Field150Holder02052e2c;
extern "C" Field150* func_02052e2c(Field150Holder02052e2c*);
extern "C" char* Zone3D_GetInstance();
extern "C" char* LinkSession_GetInstance();
extern "C" int LinkSession_IsHostOrSolo(char*);
extern "C" void func_ov003_02161480();
extern "C" void func_ov017_021bbae4(char*, unsigned int, int);

// USA: func_ov003_02163d7c
extern "C" ARM void func_ov003_02163d7c(char* self) {
    func_ov003_02161480();
    GameState* state = GameState::GetInstance();
    char* info = Zone3D_GetInstance();
    GameResources* res = GetGameResources();
    char* list = *(char**)((char*)res + 0x3000 + Enum_ov003_02163d7c_1788);
    char* node = *(char**)((char*)res + 0x3000 + Enum_ov003_02163d7c_1844);
    Field150* field = func_02052e2c((Field150Holder02052e2c*)(state->GetGameObjectByIndex(*(signed char*)(self + Enum_ov003_02163d7c_1024 + Enum_ov003_02163d7c_162))));
    char* entry = LinkSession_GetInstance();
    func_ov017_021bbae4(node, *(unsigned int*)(info + 0x8), 1);
    node[Enum_ov003_02163d7c_205] = *(signed char*)(self + Enum_ov003_02163d7c_1024 + Enum_ov003_02163d7c_162);
    node[Enum_ov003_02163d7c_206] = field->flag;
    node[Enum_ov003_02163d7c_207] = 0;
    func_020469b4((TailList020469b4*)list, (TailNode020469b4*)node);
    self[Enum_ov003_02163d7c_1187] = 0x10;
    *(unsigned int*)(self + Enum_ov003_02163d7c_1124) &= ~0x8000;
    if (!LinkSession_IsActive((int*)entry)) {
        return;
    }
    if (!LinkSession_IsHostOrSolo(entry)) {
        return;
    }
    func_ov017_02195530((unsigned char*)res);
}
