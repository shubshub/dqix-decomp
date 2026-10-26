#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02186c1c {
    unsigned int header;
    unsigned int age : 9;
    int title : 10;
    unsigned int upper : 13;
};
struct Struct_ov012_02186c1c_2 {
    unsigned short count : 5;
    unsigned short other : 11;
};
struct Struct0205de24;
struct Struct_0205c570;
struct TableA68;
struct SePlayer;
struct Struct_ov012_02186a7c;
extern "C" void func_0205de24(Struct0205de24*, unsigned char, unsigned char);
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" void func_ov012_021898bc(char*);
extern "C" void* func_02072a68(TableA68*, int);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" int func_ov023_021e6e20(Struct_ov012_02186a7c*);
extern SePlayer g_sePlayer;
extern "C" void func_ov023_021e6e60(void*);
extern "C" int func_ov023_021e7148(void*);
extern "C" void func_ov012_0218bba0(void*, int, int);
extern "C" void func_ov012_02189be8(void*, int);

static inline Struct_ov012_02186c1c* inline_ov012_02186c1c(GameState* game) {
    return (Struct_ov012_02186c1c*)((char*)game + 0x543c);
}

// USA: func_ov012_02186c1c
extern "C" ARM void func_ov012_02186c1c(char* editor) {
    if (*(unsigned char*)(editor + 0x1340) == 0) {
        *(unsigned char*)(editor + 0x1368) = 0;
        int title = inline_ov012_02186c1c(GameState::GetInstance())->title;
        int cursor;
        if (title < 100) cursor = 2;
        else if (title < 200) cursor = 0;
        else if (title < 300) cursor = 1;
        else if (title == 300) cursor = 3;
        else cursor = 0;
        *(int*)(editor + 0x1430) = cursor;
        func_0205de24((Struct0205de24*)(editor + 0x90), 0, 3);
        func_ov023_021e6e60(editor);
        func_ov012_021898bc(editor);
        (*(unsigned char*)(editor + 0x1340))++;
        return;
    }
    if (*(unsigned char*)(editor + 0x1340) != 1) return;
    *(unsigned char*)(editor + 0x1368) = 1;
    *(int*)(editor + 0x1430) = Window_GetSelectedIndex((Struct_0205c570*)(editor + 0x90));
    if (func_ov023_021e7148(editor)) {
        int var2 = 1;
        switch (*(int*)(editor + 0x1430)) {
        case 0:
            *(unsigned char*)(editor + 0x1341) = 3;
            *(unsigned char*)(editor + 0x1340) = 0;
            break;
        case 1:
            *(unsigned char*)(editor + 0x1341) = 4;
            *(unsigned char*)(editor + 0x1340) = 0;
            break;
        case 2:
            if (((Struct_ov012_02186c1c_2*)(editor + 0x141c))->count) {
                *(unsigned char*)(editor + 0x1341) = 5;
                *(unsigned char*)(editor + 0x1340) = 0;
            } else var2 = 0;
            break;
        case 3: {
            GameState* game = GameState::GetInstance();
            const char* text = (const char*)func_02072a68((TableA68*)(editor + 0x1314), 109);
            inline_ov012_02186c1c(game)->title = 300;
            memset(editor + 0x1498, 0, 64);
            memcpy(editor + 0x1498, text, strlen(text));
            func_ov012_0218bba0(editor, 0, -1);
            func_ov012_02189be8(editor, var2);
            break;
        }
        }
        if (!var2) return;
        SePlayer_Play(&g_sePlayer, 1, 0);
    } else {
        if (!func_ov023_021e6e20((Struct_ov012_02186a7c*)editor)) return;
        func_ov012_02189be8(editor, 1);
    }
}
#else
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct0205de24 {
    char padding0[0x98];
    void* unknown_98_;
    void* unknown_9c_;
    char unknown_a0_[0x12];
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
};
struct Struct_0205c570;
struct Struct_02072a68 { short key; void* value; };
struct TableA68 { Struct_02072a68* entries; short count; };
struct SePlayer;
struct Struct_ov012_02186a7c;
struct Struct_ov012_02186c1c_3 {
    char padding0[4];
    unsigned int unknown4 : 9;
    int title : 10;
    unsigned int unknown_6_3_ : 13;
};
struct Struct_01ff8b48_9 {
    char padding[0x569c];
    Struct_ov012_02186c1c_3 profile;
};
struct Struct_ov012_02185ab8 {
    char padding0[0xac];
    Struct0205de24 entries;
    char unknown_164_[0x133c - 0x164];
    TableA68 strings;
    char unknown_1344_[0x1370 - 0x1344];
    unsigned char step;
    unsigned char state;
    char unknown_1372_[0x13a0 - 0x1372];
    unsigned char active;
    char unknown_13a1_[0x13c4 - 0x13a1];
    unsigned short unknown_13c4_0_ : 5;
    unsigned short unknown_13c4_5_ : 11;
    char unknown_13c6_[0x13d8 - 0x13c6];
    int cursor;
    char unknown_13dc_[0x1440 - 0x13dc];
    char titleText[0x40];
};

static inline Struct_ov012_02186c1c_3* inline_ov012_02186c1c_2(GameState* game) {
    Struct_01ff8b48_9* region = (Struct_01ff8b48_9*)game;
    return &region->profile;
}
extern "C" void func_0205de24(Struct0205de24*, unsigned char, unsigned char);
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" void func_ov012_021898bc(char*);
extern "C" void* func_02072a68(TableA68*, int);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" int func_ov023_021e6e20(Struct_ov012_02186a7c*);
extern SePlayer g_sePlayer;
extern "C" void func_ov023_021e6e60(Struct_ov012_02185ab8*);
extern "C" int func_ov023_021e6de4(Struct_ov012_02185ab8*);
extern "C" void func_ov012_0218adac(Struct_ov012_02185ab8*, int, int, int);
extern "C" void func_ov012_0218930c(Struct_ov012_02185ab8*, int);

// USA: func_ov012_02186c1c
extern "C" ARM void func_ov012_02186c1c(Struct_ov012_02185ab8* self) {
    if (self->step == 0) {
        self->active = 0;
        int title = inline_ov012_02186c1c_2(GameState::GetInstance())->title;
        int cursor;
        if (title < 100) cursor = 2;
        else if (title < 200) cursor = 0;
        else if (title == 300) cursor = 3;
        else if (title < 300) cursor = 1;
        else {
            cursor = 0;
            switch (title) {
            case 310:
                cursor = 0;
                break;
            }
        }
        self->cursor = cursor;
        func_0205de24(&self->entries, 0, 3);
        func_ov023_021e6e60(self);
        func_ov012_021898bc((char*)self);
        self->step++;
        return;
    }
    if (self->step != 1) return;
    self->active = 1;
    self->cursor = Window_GetSelectedIndex((Struct_0205c570*)&self->entries);
    if (func_ov023_021e6de4(self)) {
        int var7 = 1;
        switch (self->cursor) {
        case 0:
            self->state = 3;
            self->step = 0;
            break;
        case 1:
            self->state = 4;
            self->step = 0;
            break;
        case 2:
            if (self->unknown_13c4_0_) {
                self->state = 5;
                self->step = 0;
            } else var7 = 0;
            break;
        case 3: {
            GameState* game = GameState::GetInstance();
            const char* text = (const char*)func_02072a68(&self->strings, 0x6d);
            inline_ov012_02186c1c_2(game)->title = 300;
            memset(self->titleText, 0, sizeof(self->titleText));
            int length = strlen(text);
            memcpy(self->titleText, text, length);
            func_ov012_0218adac(self, 0, -1, 0);
            func_ov012_0218930c(self, var7);
            break;
        }
        }
        if (!var7) return;
        SePlayer_Play(&g_sePlayer, 1, 0);
    } else {
        if (!func_ov023_021e6e20((Struct_ov012_02186a7c*)self)) return;
        func_ov012_0218930c(self, 1);
    }
}
#endif
