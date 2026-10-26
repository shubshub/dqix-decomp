#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* func_020e2ff8(void);
extern "C" void* func_020e3580(void);
extern "C" int func_0202b000(void* obj);
extern "C" void func_ov017_021c37a4(void);
extern "C" void func_0202c778(unsigned char* obj);
extern "C" int func_0202b7ec(void* obj);
extern "C" void LinkMessageQueue_Reset(void* obj);
struct Struct_020e3004;
extern "C" void func_020e3004(struct Struct_020e3004* p);
struct Struct_020e358c;
extern "C" void func_020e358c(struct Struct_020e358c* s);
extern "C" void func_ov017_02195748(unsigned char* base);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_0202c360(void* obj, int val);
extern "C" void LinkSession_Update(void* obj);
extern "C" void func_0202b828(unsigned char* obj);
extern "C" void func_020d84dc(void);
extern "C" void Party_ReformLine(int, int, int, int, int);
extern "C" void func_ov017_02191234(int a);
extern "C" void LinkSession_UpdateMemberCount(void* obj);
extern "C" ARM void func_ov017_021972cc(char* p);
extern "C" void func_ov017_02195520(void* obj);

// USA: func_ov017_021c35ac
extern "C" ARM void func_ov017_021c35ac(void) {
    GameState* battle = GameState::GetInstance();
    int g = ((int)GetGameResources());
    void* search = LinkSession_GetInstance();
    void* d100044 = LinkMessageQueue_GetInstance();
    void* var4 = func_020e2ff8();
    void* var5 = func_020e3580();

    if (func_0202b000(search) != 0) {
        func_ov017_021c37a4();
        return;
    }

#if defined(jpn)

#else
    func_0202c778((unsigned char*)search);
#endif

    func_0202b7ec(search);
    LinkMessageQueue_Reset(d100044);
    func_020e3004((struct Struct_020e3004*)var4);
    func_020e358c((struct Struct_020e358c*)var5);
    func_ov017_02195748((unsigned char*)g);

    GameObject* combatant = battle->GetProtagonist();
    func_02053c6c((unsigned char*)combatant);
    int var7 = *(int*)((char*)combatant + 0x134);
    func_0202c360(search, var7);
    LinkSession_Update(search);
    func_0202b828((unsigned char*)search);
    ClearFlags00((GameResources*)g, 2);
    func_020d84dc();
    Party_ReformLine(g, 1, 1, 1, 1);
    func_ov017_02191234(g);
    LinkSession_UpdateMemberCount(search);
    func_ov017_021972cc((char*)g);
    func_ov017_02195520((void*)g);
}
