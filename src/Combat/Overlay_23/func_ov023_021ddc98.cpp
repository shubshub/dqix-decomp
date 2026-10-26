#include <globaldefs.h>

struct Struct_ov023_021ddc98 {
#if defined(jpn)
    char pad0[0x6f8];
#else
    char pad0[0x77c];
#endif

    signed char screen_;
};

struct Struct_ov023_021ff9e0_10 {
#if defined(jpn)
    char pad0[0x14];
    void* unknown_4_;
    int pad18;
    Struct_ov023_021ddc98* sWindow;

#else
    void* unknown1_0_;
    void* unknown_4_;
    void* sFieldNames;
    int unknown_c_;
    int unknown_10_;
    void* sTexts;
    int unknown1_18_;
    int unknown_1c_;
    Struct_ov023_021ddc98* sWindow;

#endif
};
extern "C" Struct_ov023_021ff9e0_10 data_ov023_021ff9e0;

struct Struct_ov023_021ddc98_2 {
    char pad0[0xa8];
    short width_;
    short height_;
    short x_;
    short y_;
};

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void LoadToSubBG0CharacterData(const void* src, unsigned int offset, unsigned int size);
extern "C" void LoadToMainBG1CharacterData(const void* src, unsigned int offset, unsigned int size);
extern "C" void LoadToMainBG2CharacterData(const void* src, unsigned int offset, unsigned int size);
extern "C" unsigned short* func_ov023_021db2b8(signed char screen, int arg1);

#if defined(jpn)
extern "C" unsigned short* GetSubBG0ScreenBase();
extern "C" unsigned short* GetMainBG1ScreenBase();
extern "C" unsigned short* GetMainBG2ScreenBase();
#endif
// USA: func_ov023_021ddc98
extern "C" ARM unsigned int func_ov023_021ddc98(Struct_ov023_021ddc98_2* canvas, unsigned int offset, unsigned short palette, int arg3)
{
    unsigned int size = 0;
    short width;
    signed char screen;
    short height;
    short x;
    unsigned int tile;
    int y;
    unsigned short* base;
    short i;
    unsigned short* tiles;
    short j;
    unsigned short value;
    if (data_ov023_021ff9e0.unknown_4_ != NULL && canvas != NULL)
    {
        width = canvas->width_;
        screen = data_ov023_021ff9e0.sWindow->screen_;
        height = canvas->height_;
        size = (width * height) << 5;
        x = canvas->x_;
        y = canvas->y_;
        if (screen == 1)
        {
            CleanInvalidateCacheRange(data_ov023_021ff9e0.unknown_4_, size);
            LoadToSubBG0CharacterData(data_ov023_021ff9e0.unknown_4_, offset, size);
        }
        else
        {
            CleanInvalidateCacheRange(data_ov023_021ff9e0.unknown_4_, size);
            if (arg3)
                LoadToMainBG1CharacterData(data_ov023_021ff9e0.unknown_4_, offset, size);
            else
                LoadToMainBG2CharacterData(data_ov023_021ff9e0.unknown_4_, offset, size);
        }
        tile = (offset << 11) >> 16;
#if defined(jpn)
        if (screen == 1) base = GetSubBG0ScreenBase();
        else if (arg3) base = GetMainBG1ScreenBase();
        else base = GetMainBG2ScreenBase();
#else
        base = func_ov023_021db2b8(screen, arg3);
#endif

        if (base != NULL)
        {
            for (i = 0; i < height; i++)
            {
                tiles = base + (y << 5) + x;
                for (j = 0; j < width; j++)
                {
                    value = tile;
                    value |= palette << 12;
                    CleanInvalidateCacheRange(&value, 2);
                    *tiles = value;
                    tile = (unsigned short)(tile + 1);
                    tiles++;
                }
                y++;
            }
        }
    }
    return size;
}
