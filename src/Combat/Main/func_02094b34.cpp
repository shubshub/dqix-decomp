#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
#define func_020965c0 func_jpn_02098210
#endif

#if defined(jpn)
extern "C" int func_020965c0(FontBankLoader*, int);
#endif

// USA: func_02094b34
extern "C" ARM void func_02094b34(FontBankLoader* loader, int first, int second, unsigned char arg3,
                               const volatile unsigned char arg4) {
#if defined(jpn)
    if (loader->unknown_34_ >= 0) return;
    volatile int indices[2];
    indices[1] = second;
    indices[0] = first;
    unsigned char var1 = arg4;
    if (func_020965c0(loader, first)) {
        indices[0] = -1;
        arg3 = 1;
    }
    if (func_020965c0(loader, indices[1])) {
        indices[1] = -1;
        var1 = 1;
    }
    for (unsigned char i = 0; i < 2; ++i) {
        if (indices[0] < 0) {
            indices[0] = indices[1];
            arg3 = var1;
            indices[1] = -1;
            var1 = 1;
        }
    }
    if (indices[0] < 0 && indices[1] < 0) return;
    FontBankLoader_CancelLoads(loader);
    loader->unknown_34_ = indices[0];
    loader->unknown_38_ = indices[1];
    loader->unknown_56_ = 0;
    loader->loadStage = 0;
    loader->unknown_61_ = arg3;
    loader->unknown_62_ = var1;
#endif
}
