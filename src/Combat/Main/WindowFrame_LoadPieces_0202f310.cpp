#include <globaldefs.h>

extern "C" void sprintf(void* buf, void* format, int index);
extern "C" void SprSprite_Init(void* sprite);
extern "C" void SprSprite_Parse(void* sprite, int file, void* allocator);

extern int GetFileFromNARCInMemory(const char* filename);

extern int data_020ef7c4; // "ARC:win%d.spr"

struct SpritePath { char path[0x28]; };

enum { kFramePieceCount = 8, kPieceSize = 0x88 }; // kPieceSize: sizeof(Foo02048004), one .spr sprite

// Loads the window frame's pieces win0-7.spr from the archive mounted as "ARC" (WindowFrame_Load mounts
// data/bin/icon.nsarc); the archive argument itself is not read.
// Main, originally LoadEightEntriesFromTable_0202f310 (USA 0x0202f310, EUR 0x0202f320, JPN 0x0202ee80)
extern "C" ARM void WindowFrame_LoadPieces(char* frame, void* allocator, void* archive) {
    struct SpritePath path;
    char* piece;
    int i;
    piece = frame;
    for (i = 0; i < kFramePieceCount; i++) {
        int file;
        sprintf(&path, &data_020ef7c4, i);
        file = GetFileFromNARCInMemory((const char*)&path);
        SprSprite_Init(piece);
        SprSprite_Parse(piece, file, allocator);
        piece += kPieceSize;
    }
}
