#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void __clear(char* buf, int len);
extern "C" int Font_EncodeText(int value, char* buf, int flag);
extern "C" void GameState_CollectPartyObjectIndices(GameState* bs, int* outList, int* outCount);

#if defined(jpn)
typedef const char* Type_0202c360;
#else
typedef int Type_0202c360;
#endif
// USA: func_0202c360
extern "C" ARM void func_0202c360(void* self, Type_0202c360 value) {
    char buf[0x14];
    int list[4];
    int count;
    GameState* bs = GameState::GetInstance();
    unsigned char* var4 = (unsigned char*)self + 0x1028;
#if defined(jpn)
    strcpy((char*)self + 0x1014, value);
    *var4 = strlen(value);
#else
    __clear(buf, 0x14);
    Font_EncodeText(value, buf, 1);
    *var4 = strlen(buf);
    memcpy((char*)self + 0x1014, buf, *var4 + 1);
#endif
    GameState_CollectPartyObjectIndices(bs, list, &count);
    *((unsigned char*)self + 0x1027) = (unsigned char)count;
}
