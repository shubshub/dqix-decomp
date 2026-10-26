// The files CharacterCreationUI_HandleNewGameFinish loads; it fills in each allocator and name, and a NULL
// allocator ends the list. taskSlot picks the modelTasks entry; slot 2 is a loose file, the rest come from
// CharacterCreationUI_characterArchive. Originally CharacterCreationUI_finishModelFiles (USA/EUR 0x0218aa98, JPN 0x0218ba4c).
typedef struct SafeAllocator SafeAllocator;

typedef struct FinishModelFile {
    SafeAllocator* allocator;
    const char* name;
    unsigned char taskSlot;
} FinishModelFile;

typedef struct FinishModelFiles {
    FinishModelFile files[4];
} FinishModelFiles;

const FinishModelFiles CharacterCreationUI_finishModelFiles = {{
    {0, 0, 0},
    {0, 0, 1},
    {0, 0, 2},
    {0, 0, 0},
}};
