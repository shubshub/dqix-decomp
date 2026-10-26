#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#if defined(jpn)
struct GameState { static GameState* GetInstance(); };
struct GameObject { char unknown0[0x134]; const char* name; };
int GameState_GetProtagonistIndex(GameState*);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
int STD_GetStringLength(const char*);
#endif

#if defined(jpn)
#define func_ov008_02188730 func_ov008_02189444
#endif

struct Overlay8SpriteEntry {
    unsigned char unknown00[0x14];
    int x, y;
    unsigned char unknown1c[6];
    unsigned char alpha;
    unsigned char unknown23[2];
    signed char palette;
    signed char priority;
    unsigned char unknown27;
};
struct Overlay8SpriteView {
    unsigned char unknown000[0x730];
    void* renderer;
    Overlay8SpriteEntry* spriteEntries;
    unsigned char unknown738[4];
    void* extraRenderer;
    Overlay8SpriteEntry* extraEntry;
    unsigned char entries[8];
    unsigned char count;
    unsigned char unknown74d[3];
    unsigned char cursor[0x40];
    unsigned char unknown790[0xb10 - 0x790];
    signed char phase;
    unsigned char unknownb11[7];
    unsigned int flags;
    unsigned char unknownb1c[0xb29 - 0xb1c];
    unsigned char page;
    unsigned char unknownb2a[2];
    int extraX;
};

extern "C" {
    void* LinkSession_GetInstance();
    bool LinkSession_IsGuest(void*);
    int _Z27GridCursor_GetSelectedIndexP10GridCursor(void*);
    void _Z30SpriteContext_SetSpritePaletteiPvi(void*, void*, int);
    void _Z19SetBitfield0205af84iPvi(void*, void*, int);
    void SpriteContext_DrawSprite(void*, void*);

    void func_ov008_02188730(Overlay8SpriteView* menu) {
        if (menu->flags & 0x80000) {
            int drawn = 0;
            for (int i = 0; i < 6; ++i) {
                int entry = menu->entries[menu->page + i];
                if (entry == 0xff)
                    continue;
                Overlay8SpriteEntry* sprite = &menu->spriteEntries[entry];
                sprite->x = 0x10000;
                sprite->y = ((drawn % 6) << 16) + 0x8000;
                int selected = _Z27GridCursor_GetSelectedIndexP10GridCursor(menu->cursor) - menu->page;
                int style = 1;
                if (selected == i)
                    style = 2;
                else if (menu->phase == 12)
                    style = 3;
                if (LinkSession_IsGuest(LinkSession_GetInstance()) && entry == 5)
                    style = 3;
                _Z30SpriteContext_SetSpritePaletteiPvi(menu->renderer, &menu->spriteEntries[entry], style);
                _Z19SetBitfield0205af84iPvi(menu->renderer, &menu->spriteEntries[entry], 1);
                SpriteContext_DrawSprite(menu->renderer, &menu->spriteEntries[entry]);
                ++drawn;
            }
        }
        if (menu->flags & 0x10000) {
            Overlay8SpriteEntry* entry = menu->extraEntry;
#if defined(jpn)
            GameState* game = GameState::GetInstance();
            GameObject* hero = GetCombatantWithFlag0x100_0200ff1c(game, GameState_GetProtagonistIndex(game));
            entry->x = ((STD_GetStringLength(hero->name) >> 1) * 10 + 0x74) << 12;
            entry->y = 0;
#else
            entry->x = menu->extraX;
            entry->y = 0x4000;
#endif
            entry->priority = 1;
            entry->palette = 0;
            entry->alpha = 0x7f;
            SpriteContext_DrawSprite(menu->extraRenderer, entry);
        }
    }
}
