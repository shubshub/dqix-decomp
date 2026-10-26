#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/TextQueue.h"
#if defined(jpn)
extern "C" int sprintf(char*, const char*, ...);
extern char* data_ov017_021d87f4;
#endif

extern "C" void* MessageSystem_GetInstance(void);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" int StandardStrings_Get(int a);
extern "C" void* TextQueue_GetInstance(void);
struct Struct_0208b494;
extern "C" Struct_0208b494* func_0208a9b4(void);
extern "C" void func_0208b494(struct Struct_0208b494* obj);

extern "C" ARM void MessageSystem_FormatText(void* a, int b, int c, void* d, int e, int f, int g);

// USA: func_ov017_021c2ea4
extern "C" ARM void func_ov017_021c2ea4(unsigned char* self) {
    char buf1[0xc];
#if defined(jpn)
    char buf2[0x40];
#else
    char buf2[0x80];
#endif
#if defined(jpn)
    GameState* game = GameState::GetInstance();
#else
    GameState::GetInstance();
#endif
    void* g = MessageSystem_GetInstance();
#if defined(jpn)
    GameObject* member = game->GetPartyMemberByIndex(self[0x95]);
    sprintf(buf2, data_ov017_021d87f4, *(char**)((char*)member + 0x134));
#else
    NameText_InitFromPartyMember(buf1, self[0x95]);
    *(void**)g = buf1;
    int r = StandardStrings_Get(0x31);
    MessageSystem_FormatText(g, 0xc, r, buf2, 0xe3, 0, 1);
#endif
    void* reset = TextQueue_GetInstance();
#if defined(jpn)
    TextQueue_Push(reset, buf2, 0, 0, 1);
#else
    TextQueue_Push(reset, buf2, 0, 0, 1, 1);
#endif
    Struct_0208b494* data = func_0208a9b4();
    func_0208b494(data);
    self[0x8c] = 3;
}
