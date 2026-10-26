#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "Combat/ResourceScriptEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
#define data_ov004_0217052d data_ov004_02170deb
#endif

struct StreamHeader;
struct Struct_ov004_02162dd8 { int field0; SafeAllocator allocator; };

struct Struct_ov004_02162dd8_2 {
    ResourceScriptPackedTriple t[4];
    int pad[2];
};

struct Struct_ov004_021707e8_8 {
#if defined(jpn)
    char pad0[0xa];
    unsigned char active;
    unsigned char running;
    char unknown_c_[8];
#else
    unsigned char running;
    char pad1[3];
    unsigned char active;
    char pad5[0xf];
#endif
    Struct_ov004_02162dd8_2* entries;
};

extern Struct_ov004_021707e8_8 data_ov004_021707e8;
extern int data_ov004_02170854[];
extern char data_ov004_0217052d[];
extern unsigned char g_fileLoadBuffer[0x30000];

extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" Struct_ov004_02162dd8* func_ov011_021845f8(void*, int);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_0208274c(void* ctx, StreamHeader* script, int size, int arg3);

static inline Struct_ov004_02162dd8_2* inline_ov000_0217fa60_2(int vocation, Struct_ov004_02162dd8_2* slots, int member) {
    int row = member * 12;
    return &slots[row + (vocation - 1)];
}

static inline short inline_ov004_02162dd8(ResourceScriptPackedTriple* t) {
    return t->low;
}

static inline short inline_ov004_02162dd8_2(ResourceScriptPackedTriple* t) {
    return t->middle;
}

static inline short inline_ov004_02162dd8_3(ResourceScriptPackedTriple* t) {
    return t->high;
}

// USA: func_ov004_02162dd8
extern "C" ARM int func_ov004_02162dd8(void* param) {
    if (data_ov004_021707e8.active == 0) {
        return 0;
    }
    data_ov004_021707e8.running = 1;
    GameState* gs = GameState::GetInstance();
    unsigned char ids[4];
    int count = GameState_GetPartyOrder((char*)gs, ids);
    data_ov004_021707e8.entries = 0;
    data_ov004_021707e8.entries = (Struct_ov004_02162dd8_2*)func_ov011_021845f8(param, 4)->allocator.Allocate(0x480);
    if (data_ov004_021707e8.entries != 0) {
        memset(data_ov004_021707e8.entries, 0, 0x480);
        BackgroundLoader::AddLockGlobal();
        for (int i = 0; i < count; i++) {
            for (int j = 1; j < 13; j++) {
                {
                    char path[0x20] = {0};
                    unsigned int size;
                    ResourceScriptEntry script;
                    sprintf(path, data_ov004_0217052d, data_ov004_02170854[j]);
                    if (LoadFileIntoMemory(path, &g_fileLoadBuffer, &size) != 0) {
                        GameObject* c = func_0200ff1c(gs, ids[i]);
                        if (c != 0) {
                            unsigned char* f = (unsigned char*)func_02053c6c((unsigned char*)c);
                            if (f != 0) {
                                func_0208274c(&script, (StreamHeader*)&g_fileLoadBuffer, size, *(unsigned short*)(f + data_ov004_02170854[j] * 2 + 0x16c));
                                Struct_ov004_02162dd8_2* slot = inline_ov000_0217fa60_2(data_ov004_02170854[j], data_ov004_021707e8.entries, ids[i]);
                                slot->t[0].low = inline_ov004_02162dd8(&script.initial.value8);
                                slot->t[0].middle = inline_ov004_02162dd8_2(&script.initial.value8) & 0x3ff;
                                slot->t[0].high = inline_ov004_02162dd8_3(&script.initial.value8) & 0x3ff;
                                slot->t[1].low = inline_ov004_02162dd8(&script.initial.valueC);
                                slot->t[1].middle = inline_ov004_02162dd8_2(&script.initial.valueC) & 0x3ff;
                                slot->t[1].high = inline_ov004_02162dd8_3(&script.initial.valueC) & 0x3ff;
                                slot->t[2].low = inline_ov004_02162dd8(&script.initial.value10);
                                slot->t[2].middle = inline_ov004_02162dd8_2(&script.initial.value10) & 0x3ff;
                                slot->t[2].high = inline_ov004_02162dd8_3(&script.initial.value10) & 0x3ff;
                                slot->t[3].low = inline_ov004_02162dd8_2(&script.initial.valueC);
                            }
                        }
                    }
                }
            }
        }
        BackgroundLoader::RemoveLockGlobal();
    }
    data_ov004_021707e8.active = 0;
    data_ov004_021707e8.running = 0;
    return 0;
}
