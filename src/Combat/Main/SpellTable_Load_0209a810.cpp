#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Resource/SpellTable.h"

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char SpellTable_file[];
extern char g_fileLoadBuffer[];
extern char SpellTable_scriptOpcodes[];

// The spell table being loaded: spelltable.bin's opcodes add their {spell, level} entries to it through SpellTable_scriptContext.
struct Ctx0209a810 { void* table; };
extern struct Ctx0209a810* SpellTable_scriptContext;

// Main, originally SetupAndRunBufferedScript0209a810 (USA 0x0209a810, EUR 0x0209a820, JPN 0x0209c588)
ARM void SpellTable_Load(struct Ctx0209a810* ctx, void* table) {
    unsigned int fileSize;
    char script[0x430];

    BackgroundLoader::AddLockGlobal();

    if (LoadFileIntoMemory(SpellTable_file, g_fileLoadBuffer, &fileSize) != NULL) {
        ctx->table = table;
        memset(table, 0, sizeof(SpellTable));
        SpellTable_scriptContext = ctx;
        ((Script*)script)->Initialize();
        ((Script*)script)->SetOpcodeLookup((Script::OpcodeLookupEntry*)SpellTable_scriptOpcodes);
        ((Script*)script)->Load(g_fileLoadBuffer, fileSize);
        ((Script*)script)->Execute();
        SpellTable_scriptContext = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
