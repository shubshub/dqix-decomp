#include <globaldefs.h>

extern "C" void FontBankLoader_CancelLoads(int a);
extern "C" void func_ov017_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);

int FontBankLoader_GetInstance(void);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);

struct ResetObj020d7a5c;
void ResetAndClearFlags020d7a5c(struct ResetObj020d7a5c* o);

struct Flags020d7aa0 {
    unsigned char lo : 6;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

struct Obj020d7aa0 {
    #if defined(jpn)
    unsigned char pad[0xf0];
#else
    unsigned char pad[0x150];
#endif
    struct Flags020d7aa0 flags;
};

// Main, originally TeardownAndResetState020d7aa0 (USA 0x020d7aa0, EUR 0x020d7ab0, JPN 0x020d94a4)
ARM void TextQueue_Reset(struct Obj020d7aa0* obj) {
    int g = FontBankLoader_GetInstance();
    if (obj->flags.bit7) {
        FontBankLoader_CancelLoads(g);
    }
    if (obj->flags.bit6) {
        MessageSystem_Reset((char*)MessageSystem_GetInstance());
        obj->flags.bit6 = 0;
    }
    func_ov017_0218b5c0(1, -1);
    func_ov017_0218b5f8(-1);
    ResetAndClearFlags020d7a5c((struct ResetObj020d7a5c*)obj);
}
