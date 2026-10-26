#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#if defined(jpn)
struct GameState { static GameState* GetInstance(); };
struct GameObject { char unknown0[0x134]; const char* name; };
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" int STD_GetStringLength(const char*);
#endif

#if defined(jpn)
#define func_ov008_02188730 func_ov008_02189444
#endif

struct Struct_ov008_02188730 {
    unsigned char unknown_0_[0x14];
    int x, y;
    unsigned char unknown_1c_[6];
    unsigned char alpha;
    unsigned char unknown_23_[2];
    signed char palette;
    signed char priority;
    unsigned char unknown_27_;
};
struct Struct_ov008_02188730_2 {
    unsigned char unknown_0_[0x730];
    void* renderer;
    Struct_ov008_02188730* spriteEntries;
    unsigned char unknown_738_[4];
    void* extraRenderer;
    Struct_ov008_02188730* unknown_740_;
    unsigned char entries[8];
    unsigned char count;
    unsigned char unknown_74d_[3];
    unsigned char cursor[0x40];
    unsigned char unknown_790_[0xb10 - 0x790];
    signed char phase;
    unsigned char unknown_b11_[7];
    unsigned int flags;
    unsigned char unknown_b1c_[0xb29 - 0xb1c];
    unsigned char page;
    unsigned char unknown_b2a_[2];
    int unknown_b2c_;
};

extern "C" {
    void* LinkSession_GetInstance();
    bool LinkSession_IsGuest(void*);
    int GridCursor_GetSelectedIndex(void*);
    void SpriteContext_SetSpritePalette(void*, void*, int);
    void func_0205af84(void*, void*, int);
    void SpriteContext_DrawSprite(void*, void*);

    void func_ov008_02188730(Struct_ov008_02188730_2* menu) {
        if (menu->flags & 0x80000) {
            int drawn = 0;
            for (int i = 0; i < 6; ++i) {
                int entry = menu->entries[menu->page + i];
                if (entry == 0xff)
                    continue;
                Struct_ov008_02188730* sprite = &menu->spriteEntries[entry];
                sprite->x = 0x10000;
                sprite->y = ((drawn % 6) << 16) + 0x8000;
                int selected = GridCursor_GetSelectedIndex(menu->cursor) - menu->page;
                int style = 1;
                if (selected == i)
                    style = 2;
                else if (menu->phase == 12)
                    style = 3;
                if (LinkSession_IsGuest(LinkSession_GetInstance()) && entry == 5)
                    style = 3;
                SpriteContext_SetSpritePalette(menu->renderer, &menu->spriteEntries[entry], style);
                func_0205af84(menu->renderer, &menu->spriteEntries[entry], 1);
                SpriteContext_DrawSprite(menu->renderer, &menu->spriteEntries[entry]);
                ++drawn;
            }
        }
        if (menu->flags & 0x10000) {
            Struct_ov008_02188730* entry = menu->unknown_740_;
#if defined(jpn)
            GameState* game = GameState::GetInstance();
            GameObject* hero = func_0200ff1c(game, GameState_GetProtagonistIndex(game));
            entry->x = ((STD_GetStringLength(hero->name) >> 1) * 10 + 0x74) << 12;
            entry->y = 0;
#else
            entry->x = menu->unknown_b2c_;
            entry->y = 0x4000;
#endif
            entry->priority = 1;
            entry->palette = 0;
            entry->alpha = 0x7f;
            SpriteContext_DrawSprite(menu->extraRenderer, entry);
        }
    }
}
