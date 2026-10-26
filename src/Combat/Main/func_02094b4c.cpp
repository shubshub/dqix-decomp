#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int FlagWord_TestBits(void*, unsigned int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);

typedef void (FontBankLoader::*Type_0200f3a4_5)(void);
extern unsigned int data_02109400;
extern Type_0200f3a4_5 __ptmf_null;
extern Type_0200f3a4_5 data_020f148c[2];
extern Type_0200f3a4_5 data_020f148c_dup[2];
#endif

// USA: func_02094b4c
extern "C" ARM int func_02094b4c(FontBankLoader* loader) {
#if defined(jpn)
    if (loader->unknown_34_ < 0) return 1;
    if (FlagWord_TestBits(GlobalFlags_GetInstance(), 0x10)) {
        void* var0 = _ZN16BackgroundLoader11GetInstanceEv();
        for (unsigned char i = 0; i < 8; ++i) {
            if (loader->unknown_14_[i] >= 0) {
                _ZN16BackgroundLoader10RemoveTaskEi(var0, loader->unknown_14_[i]);
                loader->unknown_14_[i] = -1;
            }
        }
        loader->unknown_56_ = 0;
        loader->loadStage = 0;
        return 0;
    }
    if (!(data_02109400 & 1)) {
        data_020f148c[1] = __ptmf_null;
        data_02109400 |= 1;
    }
    if (!data_020f148c_dup[loader->unknown_56_]) return 1;
    (loader->*data_020f148c_dup[loader->unknown_56_])();
    return 0;
#else
    return 1;
#endif
}
