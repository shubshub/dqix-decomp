#include <globaldefs.h>

#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
extern char data_ov023_021fce18[];
extern char data_ov023_021fce2d[];
enum { Enum_ov023_021dd4cc_1908 = 0x6f0, Enum_ov023_021dd4cc_1917 = 0x6f9, Enum_ov023_021dd4cc_1786 = 0x6fa, Enum_ov023_021dd4cc_1788 = 0x6fc };
#else
extern char data_ov023_021fdb40[];
extern char data_ov023_021fdb52[];
extern char data_ov023_021fdb60[];
extern char data_ov023_021fdb72[];
enum { Enum_ov023_021dd4cc_1908 = 0x774, Enum_ov023_021dd4cc_1917 = 0x77d, Enum_ov023_021dd4cc_1918 = 0x77e, Enum_ov023_021dd4cc_1920 = 0x780 };
#endif

struct Struct_ov023_021dd4cc {
    char unknown0[Enum_ov023_021dd4cc_1908];
    unsigned short flags;
    char unknown_776_[Enum_ov023_021dd4cc_1917 - Enum_ov023_021dd4cc_1908 - sizeof(unsigned short)];
    signed char currentMode;
    signed char unknown_77e_;
    char unknown_77f_;
    int taskId;
};

// USA: func_ov023_021dd4cc
extern "C" ARM void func_ov023_021dd4cc(Struct_ov023_021dd4cc* request, int mode) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    signed char currentMode = request->currentMode;
    if (mode == currentMode) {
        if (request->taskId < 0) return;
        loader->RemoveTask(request->taskId);
        request->taskId = -1;
        request->unknown_77e_ = request->currentMode;
        return;
    }
    signed char other = request->unknown_77e_;
    if (mode == other) return;
    if (request->taskId >= 0) {
        loader->RemoveTask(request->taskId);
        request->taskId = -1;
        request->unknown_77e_ = -1;
    }
    int result;
    if (mode == 2) {
#if defined(jpn)
        result = loader->QueueLoadFile(data_ov023_021fce18, NULL);
#else
        result = loader->QueueLoadFileInGP2(data_ov023_021fdb40, data_ov023_021fdb52, NULL);
#endif
    } else {
#if defined(jpn)
        result = loader->QueueLoadFile(data_ov023_021fce2d, NULL);
#else
        result = loader->QueueLoadFileInGP2(data_ov023_021fdb60, data_ov023_021fdb72, NULL);
#endif
    }
    request->taskId = result;
    request->flags |= 8;
    request->unknown_77e_ = (char)mode;
}
