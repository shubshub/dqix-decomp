#include <globaldefs.h>

#if defined(jpn)
#define data_020f1628 data_020f1790
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"

extern char data_020f1628[];
extern Script::OpcodeLookupEntry data_020f1608[];

struct Ctx0209a3dc { void* field0; };
extern struct Ctx0209a3dc* data_02109ba4;

// Main, originally func_0209a3dc (USA 0x0209a3dc, EUR 0x0209a3ec, JPN 0x0209c130)
extern "C" ARM void SkillTable_Load(struct Ctx0209a3dc* ctx, void* value) {
    unsigned int count;
    Script script;

    BackgroundLoader::AddLockGlobal();

    void* header = LoadFileIntoMemory(data_020f1628, g_fileLoadBuffer, &count);
    if (header != NULL) {
        ctx->field0 = value;
        data_02109ba4 = ctx;
        script.Initialize();
        script.SetOpcodeLookup(data_020f1608);
        script.Load(header, count);
        script.Execute();
        data_02109ba4 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
