#include <globaldefs.h>
#include "std_library_functions.h"
#include "Input/Input.h"

struct DebugMenuItem {
    int type;
    char text[0x30];
    DebugMenuItem* next;
    int disabled;
    char unknown_3c_[4];
    int value;
    char unknown_44_[8];
    unsigned short flags;
};

struct DebugMenu {
    int type;
    char text[0x40];
    DebugMenuItem* items;
    char unknown_48_[8];
    short x;
    short y;
    short width;
    short height;
    short shownHeight;
    unsigned short count;
    short first;
    short last;
    short selected;
    unsigned short visibleCount;
    unsigned short visibleFirst;
    unsigned short visibleLast;
    char unknown_68_[4];
    unsigned char state;
    unsigned char flags;
    unsigned char activated;
    unsigned char repeating;
    unsigned char paging;
    unsigned char touching;
    unsigned char touchEnabled;
    unsigned char touchList;
    unsigned char touchBar;
};

struct Struct_020ef74c_2 {
    int field_0;
    int rowHeight;
    int unknown_8_;
    int font;
};

#if defined(jpn)
#define data_020fe9a4 data_020fe6fc
#define data_020ef75c data_020ef650
#define data_020ef75f data_020ef653
#define data_020ef763 data_020ef655
#define data_020ef767 data_020ef657
#define data_020ef76b data_020ef65b
#define data_020ef76f data_020ef65f
#define data_020ef77d data_020ef66d
#define data_020ef782 data_020ef672
#endif

struct Struct_020fe9a4 {
#if !defined(jpn)
    void* buffer;
#endif
    int highlight;
};

struct IndexList_0202a9ac;
struct Struct_02029634_3;
struct Struct_02029988;

extern "C" void func_02029634(DebugMenu* menu, int ticks);
extern "C" DebugMenuItem* DebugMenu_GetItem(IndexList_0202a9ac*, int);
extern "C" void func_0202a91c(Struct_02029634_3*);
extern "C" void DebugMenu_Open(char*, int);
extern "C" void func_0202ad98(int a, int b, int c, const char* fmt, ...);
extern "C" void func_020290e8(int a, int b, const char* fmt, ...);
extern "C" void func_0202a678(Struct_02029988*, int);
extern "C" void DebugMenu_UpdateLayout(DebugMenu* menu);
extern "C" void* __clear(void*, int);
extern "C" int func_02029384(int, int, int, int);
extern "C" void func_02029470(int, int, int, int, int, int);
extern "C" void func_020292ec(int a0, int a1, int a2, int a3, int a4);

extern Struct_020ef74c_2 data_020ef74c;
extern Struct_020fe9a4 data_020fe9a4;
extern const char data_020ef75c[];
extern const char data_020ef75f[];
extern const char data_020ef763[];
extern const char data_020ef767[];
extern const char data_020ef76b[];
extern const char data_020ef76f[];
extern const char data_020ef772[];
extern const char data_020ef775[];
extern const char data_020ef778[];
extern const char data_020ef77d[];
extern const char data_020ef782[];

static inline DebugMenuItem* inline_02029988(DebugMenu* menu, int index) {
    return DebugMenu_GetItem((IndexList_0202a9ac*)menu, index);
}

// USA: func_02029988
extern "C" ARM void func_02029988(DebugMenu* menu, int ticks) {
    int var0;
    float scale;
    int barX;
    DebugMenu* cur;
    int barY;

    func_02029634(menu, ticks);
    if (menu->flags & 8) return;
    var0 = 0;
    barX = 0;
    barY = 0;

    if (menu->state == 0) {
        cur = (DebugMenu*)inline_02029988(menu, menu->selected);
        int row;
        int len;
        DebugMenuItem* item;
        int first = menu->first;
        int span = menu->last - first;
        int extra = menu->visibleCount - (menu->count - (menu->last - first));
        scale = (float)menu->height / (float)span;
        var0 = scale * extra;
        barX = menu->x + menu->width - 9;
        barY = menu->y + scale * (menu->visibleFirst - first);

        if (menu->touchEnabled) {
            if (g_touchInput.pressed_) {
                int tx, ty;
                menu->touching = 1;
                g_touchInput.GetTouchPoint(&tx, &ty);
                if (menu->x < tx && tx < menu->x + menu->width - 12 &&
                    menu->y < ty && ty < menu->y + menu->height) {
                    menu->touchList = 1;
                } else if (menu->x + menu->width - 12 < tx && tx < menu->x + menu->width + 4 &&
                           menu->y < ty && ty < menu->y + menu->height) {
                    menu->touchBar = 1;
                }
            } else if (menu->touching && menu->touchList && g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) {
                int tx, ty;
                g_touchInput.GetTouchPoint(&tx, &ty);
                if (menu->x < tx && tx < menu->x + menu->width - 12 &&
                    menu->y < ty && ty < menu->y + menu->height) {
                    int row = (ty - menu->y) / data_020ef74c.rowHeight - 1;
                    if (first <= row && row <= first + extra) {
                        int sel = menu->visibleFirst + (row - first);
                        if (menu->first <= sel && sel <= menu->last) {
                            menu->selected = sel;
                        }
                    }
                }
            } else if (menu->touching && menu->touchBar && g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) {
                int tx, ty;
                g_touchInput.GetTouchPoint(&tx, &ty);
                barY = ty - var0 / 2;
                if (barY < menu->y) {
                    barY = menu->y;
                } else if (menu->y + menu->width < barY + var0) {
                    barY = menu->y + menu->height - var0;
                }
                menu->visibleFirst = first + (barY - menu->y) / scale;
                menu->visibleLast = menu->visibleFirst + extra;
                if (menu->selected < menu->visibleFirst) menu->selected = menu->visibleFirst;
                if (menu->visibleLast < menu->selected) menu->selected = menu->visibleLast;
            } else if (menu->touching && g_touchInput.released_) {
                int tx = g_touchInput.prevX_;
                int ty = g_touchInput.prevY_;
                if (menu->touchList &&
                    menu->x < tx && tx < menu->x + menu->width - 12 &&
                    menu->y < ty && ty < menu->y + menu->height) {
                    int row = (ty - menu->y) / data_020ef74c.rowHeight - 1;
                    if (first <= row && row <= first + extra) {
                        int sel = menu->visibleFirst + (row - first);
                        if (menu->first <= sel && sel <= menu->last) {
                            menu->selected = sel;
                            if (menu->selected < 0 || cur->type != 1) {
                                if (menu->flags & 2) return;
                                func_0202a91c((Struct_02029634_3*)menu);
                                menu->activated = 1;
                                return;
                            }
                            if (cur->type != 1) return;
                            DebugMenu_Open((char*)cur, 1);
                            menu->state = 4;
                            return;
                        }
                    }
                }
                menu->touching = 0;
                menu->touchList = 0;
                menu->touchBar = 0;
            }
        }

        if (menu->visibleLast < menu->selected) {
            menu->visibleFirst = menu->selected - extra;
            menu->visibleLast = menu->selected;
        } else if (menu->selected < menu->visibleFirst) {
            menu->visibleFirst = menu->selected;
            menu->visibleLast = menu->selected + extra;
        }

        if (data_020ef74c.font == 0) {
            func_0202ad98(menu->x / 8 + 1, menu->y / 8 + 1, 7, menu->text);
        } else if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
            data_020fe9a4.highlight = 0;
            func_020290e8(menu->x + data_020ef74c.unknown_8_, menu->y + data_020ef74c.rowHeight, menu->text);
        }

        {
            char buf[0x80];
            item = inline_02029988(menu, 0);
            for (row = 0; row < first; row++) {
                if (item == NULL) break;
                sprintf(buf, data_020ef75c, item->text);
                data_020fe9a4.highlight = 0;
                if (item->disabled) data_020fe9a4.highlight = 1;
                if (data_020ef74c.font == 0) {
                    func_0202ad98(menu->x / 8 + 1, menu->y / 8 + 2 + row, 7, buf);
                } else if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
                    int px = menu->x + data_020ef74c.unknown_8_;
                    int var25 = data_020ef74c.rowHeight * (row + 2);
                    func_020290e8(px, var25 + menu->y, buf);
                }
                item = item->next;
            }
        }

        {
            char buf[0x80];
            item = inline_02029988(menu, menu->last + 1);
            for (row = menu->last + 1; row < menu->count; row++) {
                if (item == NULL) break;
                sprintf(buf, data_020ef75c, item->text);
                data_020fe9a4.highlight = 0;
                if (item->disabled) data_020fe9a4.highlight = 1;
                if (data_020ef74c.font == 0) {
                    func_0202ad98(menu->x / 8 + 1, menu->y / 8 + 2 + row, 7, buf);
                } else if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
                    int px = menu->x + data_020ef74c.unknown_8_;
                    int var28 = data_020ef74c.rowHeight * (row + 2);
                    func_020290e8(px, var28 + menu->y, buf);
                }
                item = item->next;
            }
        }

        {
            char line[0x80];
            char number[0x10];
            item = inline_02029988(menu, menu->visibleFirst);
            for (row = menu->visibleFirst; row <= menu->visibleLast; row++) {
                if (item == NULL) break;
                data_020fe9a4.highlight = 0;
                len = 0;
                if (item->disabled) data_020fe9a4.highlight = 1;
                if (menu->first <= row && row <= menu->last) {
                    if (menu->selected == row) {
                        sprintf(line, data_020ef75f);
                    } else {
                        sprintf(line, data_020ef763);
                    }
#if defined(jpn)
                    enum { Enum_02029988_3 = 1 };
#else
                    enum { Enum_02029988_3 = 3 };
#endif
                    len += Enum_02029988_3;
                }
                {
                    int suffix;
                    if (item->type == 2) {
                        if (menu->selected == row && item->disabled == 0 &&
                            g_keyManager.TestKeysPressed(0x30)) {
                            item->value = item->value == 0;
                        }
                        if (item->value) {
                            sprintf(line + len, data_020ef767);
                        } else {
                            sprintf(line + len, data_020ef76b);
                        }
                        len += 3;
                    }
                    __clear(number, sizeof(number));
                    suffix = 0;
                    if (item->type == 3) {
                        item->flags &= ~2;
                        item->flags &= ~0xc;
                        if (menu->selected == row && item->disabled == 0) {
                            int var32 = 0;
                            int var33;
                            int var34;
                            int old = item->value;
                            int step = 1;
                            if (g_keyManager.TestKeysHeld(8)) step = 100;
                            if (g_keyManager.TestKeyRepeat(0x10)) {
                                func_0202a678((Struct_02029988*)item, step);
                                var32 = 1;
                            }
                            if (g_keyManager.TestKeyRepeat(0x20)) {
                                func_0202a678((Struct_02029988*)item, -step);
                                var32 = 1;
                            }
                            if (g_keyManager.TestKeyRepeat(0x100)) {
                                func_0202a678((Struct_02029988*)item, step * 10);
                                var32 = 1;
                            }
                            if (g_keyManager.TestKeyRepeat(0x200)) {
                                func_0202a678((Struct_02029988*)item, step * -10);
                                var32 = 1;
                            }
                            if (var32) {
                                var33 = menu->visibleFirst;
                                var34 = menu->visibleLast;
                                DebugMenu_UpdateLayout(menu);
                                menu->visibleFirst = var33;
                                menu->visibleLast = var34;
                                item->flags |= 2;
                                if (old < item->value) item->flags |= 4;
                                if (old > item->value) item->flags |= 8;
                            }
                        }
                        if (!(item->flags & 0x40)) {
                            if (item->flags & 0x20) {
                                if (item->flags & 1) {
                                    sprintf(number, data_020ef76f, item->value);
                                } else if (item->flags & 0x80) {
                                    sprintf(number, data_020ef772, item->value + 0x40);
                                } else {
                                    sprintf(number, data_020ef775, item->value);
                                }
                            } else {
                                if (item->flags & 1) {
                                    sprintf(number, data_020ef778, item->value);
                                } else if (item->flags & 0x80) {
                                    sprintf(number, data_020ef77d, item->value + 0x40);
                                } else {
                                    sprintf(number, data_020ef782, item->value);
                                }
                            }
                            suffix = 1;
                            if (item->flags & 0x10) suffix = 2;
                        }
                    }
                    if (suffix == 1) {
                        sprintf(line + len, data_020ef75c, number);
                        len += strlen(number);
                    }
                    sprintf(line + len, data_020ef75c, item->text);
                    len += strlen(item->text);
                    if (suffix == 2) {
                        sprintf(line + len, data_020ef75c, number);
                        len += strlen(number);
                    }
                    if (data_020ef74c.font == 0) {
                        func_0202ad98(menu->x / 8 + 1, menu->y / 8 + 2 + (first + (row - menu->visibleFirst)), 7, line);
                    } else if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
                        int px = menu->x + data_020ef74c.unknown_8_;
                        int var38 = data_020ef74c.rowHeight * (first + (row - menu->visibleFirst) + 2);
                        func_020290e8(px, var38 + menu->y, line);
                    }
                }
                item = item->next;
            }
        }
    }

    if (menu->state == 4) {
        cur = (DebugMenu*)inline_02029988(menu, menu->selected);
        if (cur != NULL && cur->type == 1) {
            func_02029988(cur, ticks);
            if (cur->state == 1 ? 1 : 0) {
                DebugMenu_Open((char*)menu, 0);
            }
        }
    }

    switch (menu->state) {
    case 0:
        if (func_02029384(menu->x, menu->y, menu->width, menu->height)) {
            if (menu->visibleLast - menu->visibleFirst + 1 < menu->count) {
                func_02029470(0, 1, 3, 0, 0, 0);
                func_020292ec(menu->x + menu->width - 9, menu->y + 1, 8, menu->height - 2, 0x7fff);
                func_02029470(0, 1, 3, 0, 0x1f, 0);
                if (var0 < 0 || var0 >= 0x100) {
                    barY = menu->y + 1;
                    var0 = menu->height - 2;
                }
                func_020292ec(barX, barY, 8, var0, 0x7fff);
            }
        }
        break;
    case 1:
        break;
    case 2:
        menu->shownHeight = menu->height;
        menu->state = 0;
        func_02029384(menu->x, menu->y, menu->width, menu->shownHeight);
        break;
    case 3:
        menu->shownHeight = 0;
        menu->state = 1;
        func_02029384(menu->x, menu->y, menu->width, menu->shownHeight);
        break;
    }
}
