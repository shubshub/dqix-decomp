#include <globaldefs.h>
#include "Filesystem/FileIO.h"
#include "World/ZoneLootableRecord.h"

extern "C" void SprSprite_Parse(void* sprite, const void* fileData, int allocator);

// data_02104b6c's sprites: a number sprite and a frame sprite for each popup style.
struct NumberPopups {
    Foo02048004 numberSprites[5];
    Foo02048004 frameSprites[5];
};

struct SpriteFile {
    const char* name;
    Foo02048004* sprite;
};

// data_020e7844: damage_num.spr, damage_m_num.spr, recovery_num.spr, recovery_m_num.spr, tension_num.spr, then the
// five matching *_waku.spr frames; the sprite pointers are filled in here.
union SpriteFileTable {
    unsigned int raw[20];
    struct SpriteFile entries[10];
};

extern const union SpriteFileTable data_020e7844;

// Main, originally LoadObjectResourceFiles02039f04 (USA 0x02039f04, EUR 0x02039f14, JPN 0x0203995c)
extern "C" ARM void NumberPopups_LoadSprites(char* popupsRaw, int allocator, const void* narc) {
    NumberPopups* numberPopups = (NumberPopups*)popupsRaw;
    union SpriteFileTable files;
    int i;

    files = data_020e7844;

    files.entries[0].sprite = &numberPopups->numberSprites[0];
    files.entries[1].sprite = &numberPopups->numberSprites[1];
    files.entries[2].sprite = &numberPopups->numberSprites[2];
    files.entries[3].sprite = &numberPopups->numberSprites[3];
    files.entries[4].sprite = &numberPopups->numberSprites[4];
    files.entries[5].sprite = &numberPopups->frameSprites[0];
    files.entries[6].sprite = &numberPopups->frameSprites[1];
    files.entries[7].sprite = &numberPopups->frameSprites[2];
    files.entries[8].sprite = &numberPopups->frameSprites[3];
    files.entries[9].sprite = &numberPopups->frameSprites[4];

    for (i = 0; i < 10; i++) {
        unsigned int fileSize = 0;
        const void* fileData = 0;
        Foo02048004* sprite;
        GetFileInNarc(narc, files.entries[i].name, &fileData, &fileSize, 0);
        sprite = files.entries[i].sprite;
        SprSprite_Parse(sprite, fileData, allocator);
        sprite->word0 = 0x3e;
    }
}
