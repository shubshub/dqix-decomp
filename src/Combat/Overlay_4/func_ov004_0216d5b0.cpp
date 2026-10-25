#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* arg0);
#define NODE_KIND_CALL func_ov023_021f6f10
#else
extern "C" int func_ov024_021f6f10(void* arg0);
#define NODE_KIND_CALL func_ov024_021f6f10
#endif
extern "C" void* func_ov023_021fa598(void* p);
int MessageSystem_GetInstance();
extern "C" int func_020abb64(void);
struct Struct_02072a68_2;
extern "C" void* func_02072a68(struct Struct_02072a68_2* arg0, int arg1);
extern "C" void func_0200fb94(char* arg0, unsigned char arg1);
extern "C" void func_02012028(void* arg0, unsigned char arg1);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);

// USA: func_ov004_0216d5b0
extern "C" ARM int func_ov004_0216d5b0(void* arg0) {
    void* var0 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x192);
    if (!var0) return 0;
    if (NODE_KIND_CALL(var0) != 4) return 0;

    struct TableA68* table = (struct TableA68*)func_ov023_021fa598(node);
    GameState* battle = GameState::GetInstance();
    MessageSystem* message = (MessageSystem*)MessageSystem_GetInstance();

    if (func_020abb64() == 0) {
        void* var4 = func_02072a68(var1, 0x5dd);
#if defined(jpn)
        func_0204500c(var3, (const char*)var4, 0);
#else
        func_0204500c(var3, (const char*)var4, 0, 0xe3);
#endif
        var3->unknown_19ca_ = 0;
        var3->unknown_19af_ = 0;
        func_02012028(var2, 0);
        return 0;
    }

    void* var5 = func_02072a68(var1, 0x4b1);
#if defined(jpn)
    func_0204500c(var3, (const char*)var5, 0);
#else
    func_0204500c(var3, (const char*)var5, 0, 0xe3);
#endif
    func_0200fb94((char*)var2, 7);
    func_02012028(var2, 0);
    func_ov011_021848a0(arg0, 0x97);
    return 0;
}
