#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct SePlayer;
struct Entry_0205d6a0;

struct Struct_ov000_0217d438 {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int field94c;
};

struct Struct_ov000_0217d438_2 {
    char pad0[0x24];
    unsigned char field24;
    char unknown_25_[0x4c - 0x25];
    int memberIndex;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

struct Struct_ov000_0217d438_3 {
    char pad0[0x188];
    char elements[0x958 - 0x188];
    struct Struct_ov000_0217d438_2 entries[4];
#if defined(jpn)
    char unknown_1b78_[0x1f98 - (0x958 + 4 * 0x488)];
#else
    char unknown_1a78_[0x1d60 - 0x1a78];
#endif
    unsigned char unknown_1d60_[8];
    signed char depth;
    char unknown_1d69_[0x1d6b - 0x1d69];
    signed char selection;
    signed char field1D6C;
    char unknown_1d6d_[0x1d72 - 0x1d6d];
    unsigned short flags;
    signed char members[4];
};

extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
extern "C" int func_ov000_0217c5f4(void* objRaw);
extern "C" int func_ov000_0217c594(void* objRaw, int limit);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern "C" void* func_ov000_02161318(void* obj, int index);
extern "C" struct Struct_ov000_0217d438* func_02053c6c(unsigned char* obj);
extern "C" void func_ov000_02170ffc(void* obj);
extern "C" int func_ov000_02177798(void* obj);
extern "C" void func_ov017_021c847c();
extern "C" void func_ov000_0217fa60(void* obj);
extern "C" void func_ov000_02174c14(void* obj);
extern struct SePlayer g_sePlayer;

static inline int inline_ov000_02156cc4_2(signed char index) {
    return index >= 0 && index <= 3;
}

// USA: func_ov000_0217d438
extern "C" ARM void func_ov000_0217d438(struct Struct_ov000_0217d438_3* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    menu->field1D6C = Window_GetSelectedIndex((struct Struct_0205c570*)menu->elements);
    if (func_ov000_0217c594(menu, 0) != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        GameState* gs = GameState::GetInstance();
        menu->flags |= 0x100;
        signed char member = menu->members[menu->selection];
        if (inline_ov000_02156cc4_2(member)) {
            void* entry = func_ov000_02161318(menu, member);
            if (entry != NULL) {
                GameObject* obj = gs->GetPartyMemberByIndex(member);
                if (obj != NULL) {
                    struct Struct_ov000_0217d438* data = func_02053c6c((unsigned char*)obj);
                    if ((signed char)data->field94c != menu->field1D6C) {
                        data->field94c = menu->field1D6C;
                        func_ov000_02170ffc(entry);
                        func_ov000_02177798(menu);
                    }
                }
            }
        } else {
            struct Struct_ov000_0217d438_2* entry;
            for (int i = 0; i < 4; i++) {
                entry = &menu->entries[i];
                GameObject* obj = gs->GetPartyMemberByIndex(entry->memberIndex);
                if (obj == NULL) {
                    continue;
                }
                if (entry->field24 & 2) {
                    continue;
                }
                if (!(obj->obj3D_.unknown_0_ & 0x1000)) {
                    continue;
                }
                struct Struct_ov000_0217d438* data = func_02053c6c((unsigned char*)obj);
                if ((signed char)data->field94c == menu->field1D6C) {
                    continue;
                }
                data->field94c = menu->field1D6C;
                func_ov000_02170ffc(entry);
            }
            func_ov017_021c847c();
            func_ov000_0217fa60(menu);
            func_ov000_02174c14(menu);
            return;
        }
        Window_ClosePane((struct Entry_0205d6a0*)menu->elements, 0);
        menu->unknown_1d60_[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
        func_ov017_021c847c();
    } else if (func_ov000_0217c5f4(menu) != 0) {
        Window_ClosePane((struct Entry_0205d6a0*)menu->elements, 0);
        menu->unknown_1d60_[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
    }
}
