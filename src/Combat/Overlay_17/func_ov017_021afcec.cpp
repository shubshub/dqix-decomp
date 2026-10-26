#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"

struct GameResources;
extern "C" int MessageSystem_GetInstance(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void func_ov017_021b6c78(void);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" void func_ov017_021afb8c(char* self, char* name);
extern "C" void* __clear(void* dst, int count);
extern "C" void Font_DecodeText(char* name, void* buf, int flag);
extern "C" void func_ov017_0218b5c0(int set, int bit);
extern "C" void func_020daf9c(int a, int b, int c, int d);
extern "C" void func_ov017_0219aa5c(unsigned char* obj);
extern "C" int GameResources_GetTouchWalk(void* obj);
struct ThreeByteStruct;
extern "C" void func_020966cc(struct ThreeByteStruct* s);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_ov017_021afcec
extern "C" ARM int func_ov017_021afcec(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x214};
#else
 enum {regionalOffset0=0x284};
#endif
    GameState* bs = GameState::GetInstance();
    GameResources* ov = GetGameResources();
    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();
    unsigned int* dataPtr = (unsigned int*)GlobalFlags_GetInstance();

    if (obj[9] == 2) {
        func_ov017_021b6c78();
    }
    if (obj[regionalOffset0] != 0) {
        GameObject* c = bs->GetLeader();
        if (c != NULL) {
            GameObject_DisableControl((struct Obj020397cc*)c, 0);
        }
    }
    if (obj[9] != 2) {
        func_ov017_021afb8c((char*)obj, (char*)obj + 0xe);
#if defined(jpn)
        strcpy(ov->partyNames[obj[0xc]], (char*)obj + 0xe);

#else
        char* dst = ov->partyNames[obj[0xc]];
        char buf[0x30];
        __clear(buf, 0x30);
        Font_DecodeText((char*)obj + 0xe, buf, 1);
        strcpy(dst, buf);

#endif
    }
    SetFlags04(ov, 0x40);
    func_ov017_0218b5c0(0, -1);
    func_020daf9c(1, 1, 0, 1);
#if defined(jpn)
    g[0x17ff] |= 4;
#else
    g[0x1000 + 0x9d0] = 1;
#endif

    func_ov017_0219aa5c((unsigned char*)ov);
    func_020966cc((struct ThreeByteStruct*)GameResources_GetTouchWalk(ov));
    FlagWord_SetBits(dataPtr, 0x40000);
    return 1;
}
