#include <globaldefs.h>

extern "C" void FontBankLoader_CancelLoads(int a);
extern "C" void func_ov017_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);

extern "C" int FontBankLoader_GetInstance(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);

struct ResetObj020d7a5c;
extern "C" void func_020d7a5c(struct ResetObj020d7a5c* o);

struct Struct_020d7aa0 {
    unsigned char lo : 6;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Obj020d7aa0 {
    #if defined(jpn)
    unsigned char pad[0xf0];
#else
    unsigned char pad[0x150];
#endif
    struct Struct_020d7aa0 flags;
};

// Main, originally TeardownAndResetState020d7aa0 (USA 0x020d7aa0, EUR 0x020d7ab0, JPN 0x020d94a4)
extern "C" ARM void TextQueue_Reset(struct Obj020d7aa0* obj) {
    int g = FontBankLoader_GetInstance();
    if (obj->flags.unknown_0_7_) {
        FontBankLoader_CancelLoads(g);
    }
    if (obj->flags.unknown_0_6_) {
        MessageSystem_Reset((char*)MessageSystem_GetInstance());
        obj->flags.unknown_0_6_ = 0;
    }
    func_ov017_0218b5c0(1, -1);
    func_ov017_0218b5f8(-1);
    func_020d7a5c((struct ResetObj020d7a5c*)obj);
}
