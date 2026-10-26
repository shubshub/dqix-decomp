#include <globaldefs.h>

struct Struct_0204fd00_2 {
    char pad0[0x1c];
    unsigned char screen : 4;
    unsigned char bg : 4;
};

struct Struct_0204fd00 {
    Struct_0204fd00* next;
    Struct_0204fd00_2* layer;
    char pad08[0xa8 - 0x8];
    short width;
    short height;
    short x;
    short y;
    char unknown_b0_[0xc5 - 0xb0];
    unsigned char flags;
};

extern "C" int func_0204ea28(short x, short y, short minX, short arg3, short maxX, short arg5);

// USA: func_0204fd00
extern "C" ARM int func_0204fd00(Struct_0204fd00* window, int mask) {
    int result;
    short top;
    short var2;
    short var3;
    short var4;
    short var5;
    short left;
    short right;
    short bottom;
    unsigned char screen;
    Struct_0204fd00* other;
    other = window->next;
    if (other == NULL) {
        return 0;
    }
    left = window->x;
    top = window->y;
    right = left + window->width;
    bottom = top + window->height;
    screen = 0;
    result = 0;
    if (window->layer != NULL) {
        screen = window->layer->screen;
    }
    while (other != NULL) {
        if (other->layer != NULL && window->layer != NULL && screen != other->layer->screen) {
            other = other->next;
            continue;
        }
        if (other->flags & 0x20) {
            other = other->next;
            continue;
        }
        if ((other->flags & 4) && (other->flags & 0x10)) {
            other = other->next;
            continue;
        }
        var2 = other->x;
        var3 = other->y;
        var4 = var2 + other->width;
        var5 = var3 + other->height;
        if (mask & 1) {
            if (func_0204ea28(left, top, var2, var3, var4, var5)) {
                if (left != var2 || top != var3) {
                    result = 5;
                    if (left == var2) {
                        result = 1;
                    } else if (top == var3) {
                        result = 2;
                    }
                    break;
                }
            }
        }
        if (mask & 2) {
            if (func_0204ea28(right - 1, top, var2, var3, var4, var5)) {
                if (right != var4 || top != var3) {
                    result = 5;
                    if (right == var4) {
                        result = 3;
                    } else if (top == var3) {
                        result = 2;
                    }
                    break;
                }
            }
        }
        if (mask & 4) {
            if (func_0204ea28(left, bottom - 1, var2, var3, var4, var5)) {
                if (left != var2 || bottom != var5) {
                    result = 5;
                    if (left == var2) {
                        result = 1;
                    } else if (bottom == var5) {
                        result = 4;
                    }
                    break;
                }
            }
        }
        if (mask & 8) {
            if (func_0204ea28(right - 1, bottom - 1, var2, var3, var4, var5)) {
                if (right != var4 || bottom != var5) {
                    result = 5;
                    if (right == var4) {
                        result = 3;
                    } else if (bottom == var5) {
                        result = 4;
                    }
                    break;
                }
            }
        }
        other = other->next;
    }
    return result;
}
