// KEEP-NAME
// USA: func_ov006_0215a33c
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
extern "C" void func_ov006_02156e54(void*);
extern const char* g_itemDataArchive;
#else
extern "C" void func_ov006_02156e54(void*);
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
#endif

struct Obj0215a33c {
#if defined(jpn)
    unsigned char unknown[8];
    void* pot;
    unsigned char unknownAfterPot[0x354 - 0xc];
#else
    unsigned char unknown[0x10];
    void* pot;
    unsigned char unknownAfterPot[0x354 - 0x14];
#endif
    int backgroundTask;
};

ARM void Func_0215a33c(Obj0215a33c* owner, int) {
#if defined(jpn)
    func_ov006_02156e54(owner->pot);
#else
    func_ov006_02156e54(owner->pot);
#endif
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    loader->AddFence();
#if defined(jpn)
    owner->backgroundTask = loader->QueueLoadGP1(g_itemDataArchive, 0);
#else
    owner->backgroundTask = loader->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, 0);
#endif
}
