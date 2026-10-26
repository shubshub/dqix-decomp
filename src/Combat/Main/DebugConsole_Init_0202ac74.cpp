#include <globaldefs.h>

extern "C" void DebugConsole_LoadGlyphTiles(void* firstCharacter, int count, int tileIndex);
extern "C" void LoadToMainBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" void MIi_CpuClearFast(int value, void* destination, int size);

// Shift-JIS characters (ROM): "（", "０", "＝", "Ａ", "／", "．", "－"
extern char data_020ef788;
extern char data_020ef78b;
extern char data_020ef78e;
extern char data_020ef791;
extern char data_020ef794;
extern char data_020ef797;
extern char data_020ef79a;
extern char data_020e7170;
extern char data_020fe9cc;

// The full BG palette: 256 colours.
enum { kBGPaletteBytes = 256 * sizeof(unsigned short) };
// A 32x24-tile BG screen map.
enum { kScreenBytes = 32 * 24 * sizeof(unsigned short) };

// Each glyph goes to the tile whose index is the ASCII code of the same character, the code func_0202ad4c
// writes into the screen map.
// Main, originally InitPaletteTables0202ac74 (USA 0x0202ac74, EUR 0x0202ac84, JPN 0x0202a82c)
extern "C" ARM void DebugConsole_Init() {
    DebugConsole_LoadGlyphTiles(&data_020ef788, 2, '(');
    DebugConsole_LoadGlyphTiles(&data_020ef78b, 12, '0');
    DebugConsole_LoadGlyphTiles(&data_020ef78e, 1, '=');
    DebugConsole_LoadGlyphTiles(&data_020ef791, 26, 'A');
    DebugConsole_LoadGlyphTiles(&data_020ef794, 26, '/');
    DebugConsole_LoadGlyphTiles(&data_020ef797, 1, '.');
    DebugConsole_LoadGlyphTiles(&data_020ef79a, 1, '-');
    LoadToMainBGStandardPalette((int)&data_020e7170, 0, kBGPaletteBytes);
    MIi_CpuClearFast(0, &data_020fe9cc, kScreenBytes);
}
