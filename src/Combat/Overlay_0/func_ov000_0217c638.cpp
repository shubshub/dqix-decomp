#include <globaldefs.h>
#include "GameState/GameState.h"

struct GridCursor;
struct Struct_0205bcdc;
struct Struct_0205cf1c;

extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_ov000_02174da4(int, void*);
extern "C" void* LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int func_ov000_0218155c(void*);
extern "C" void* func_ov000_02161318(void*, int);
extern "C" void* func_02053c6c(unsigned char*);
extern "C" void func_0205cf10(void*);
extern "C" void func_0205cf1c(Struct_0205cf1c*);
extern "C" void func_0205cef8(void*);
extern "C" void func_0205cf04(void*);
extern "C" void GridCursor_SetDimensions(GridCursor*, int, int, int);
extern "C" void GridCursor_SetCount(GridCursor*, int);
extern "C" void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(void*, int);

#if defined(jpn)
extern int data_ov000_02184294[3];
#else
extern int data_ov000_02184294[2];
#endif

struct Party {
    char pad[0xf7c];
    unsigned char count;
};

struct Struct_ov000_0217c638 {
#if defined(jpn)
    char pad[0x8b4];
#else
    char pad[0x94c];
#endif
    int value;
};

struct Struct_ov000_0217c638_2 {
    int head;
    int level;
    char rest[0x48];
};

struct Struct_ov000_0217c638_3 {
    char pad0[0x1a];
    signed char unknown_1a_;
    char unknown_1b_;
    signed char unknown_1c_;
    char unknown_1d_[0x66 - 0x1d];
    short unknown_66_;
    char pad68[0x79 - 0x68];
    unsigned char limit;
    char unknown_7a_[0x188 - 0x7a];
    char flags[4];
    Struct_ov000_0217c638_2 first;
    Struct_ov000_0217c638_2 second;
#if defined(jpn)
    char unknown_22c_[0x1f98 - 0x22c];
#else
    char unknown1_22c_[0x1d60 - 0x22c];
#endif
    signed char commands[8];
    signed char index;
    signed char sel[7];
    char unknown_1d70_[4];
    signed char table[8];
};

// USA: func_ov000_0217c638
extern "C" ARM void func_ov000_0217c638(Struct_ov000_0217c638_3* battle, int a, int b) {
    int columns = 1;
    int total = b;
    int rows;
    int pages = columns;
    signed char selected;
#if defined(jpn)
    data_ov000_02184294[2] = a;
    data_ov000_02184294[1] = b;
#else
    data_ov000_02184294[1] = a;
    data_ov000_02184294[0] = b;
#endif
    GameState* gs = GameState::GetInstance();
    Party* party = (Party*)GameState_GetParty(gs);
    switch (battle->commands[battle->index]) {
    case 1: {
        int buf[4];
        total = 0;
        func_ov000_02174da4((int)battle, buf);
        for (int i = 0; i < 4; i++) {
            if (buf[i] >= 0) total++;
        }
        rows = total;
        selected = battle->sel[0];
        break;
    }
    case 2: {
        void* state = LinkSession_GetInstance();
        rows = 3;
        if (LinkSession_IsActive((int*)state)) {
            if (GameState_GetProtagonistIndex(gs) == 0) rows = 4;
        }
        total = rows;
        selected = battle->sel[1];
        break;
    }
    case 3:
        total = party->count;
        selected = battle->sel[2];
        rows = total;
        break;
    case 5:
        total = party->count;
        selected = battle->sel[2];
        rows = total;
        break;
    case 6: {
        rows = 4;
        int n = func_ov000_0218155c(battle);
        total = n;
        selected = battle->sel[5];
        if (n < 4) rows = n;
        pages = (n + 3) / 4;
        break;
    }
    case 7: {
        total = battle->unknown_66_;
        selected = battle->sel[6];
        rows = 4;
        if (total < 4) rows = total;
        pages = (total + 3) / 4;
        break;
    }
    case 4: {
        columns = 2;
        rows = 3;
        int slot = battle->table[battle->sel[2]];
        total = 6;
        signed char sl = 0;
        int ok = slot >= 0 && slot <= 3;
        if (ok && func_ov000_02161318(battle, slot)) {
            GameObject* member = gs->GetPartyMemberByIndex(slot);
            if (member) {
                sl = (signed char)((Struct_ov000_0217c638*)func_02053c6c((unsigned char*)member))->value;
            }
        }
        battle->sel[3] = sl;
        selected = battle->sel[3];
        break;
    }
    case 8:
        total = battle->limit;
        selected = battle->sel[2];
        rows = total;
        break;
    case 23:
        rows = battle->unknown_1a_;
        selected = battle->sel[4];
        total = rows;
        break;
    case 25:
        rows = 1;
        columns = total;
        pages = rows;
        selected = battle->unknown_1c_;
        break;
    default:
        func_0205cf10(battle->flags);
        func_0205cf1c((Struct_0205cf1c*)battle->flags);
        return;
    }
    func_0205cef8(battle->flags);
    func_0205cf04(battle->flags);
    GridCursor_SetDimensions((GridCursor*)&battle->first, columns, rows, 0);
    GridCursor_SetDimensions((GridCursor*)&battle->second, columns, rows, 0);
    GridCursor_SetCount((GridCursor*)&battle->first, total);
    GridCursor_SetCount((GridCursor*)&battle->second, total);
    battle->first.level = pages;
    battle->second.level = pages;
    GridCursor_SelectIfValid((Struct_0205bcdc*)&battle->first, selected);
    GridCursor_SetSelectedIndex(&battle->second, selected);
}
