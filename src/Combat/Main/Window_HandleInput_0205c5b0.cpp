#include <globaldefs.h>

struct Struct_0205c5b0_2;
extern "C" int func_0205c6bc(Struct_0205c5b0_2*);
struct Struct_0205bd04;
extern "C" int func_0205bd04(struct Struct_0205bd04*);
struct SelfBB04;
extern "C" void GridCursor_SetSelectedIndex(struct SelfBB04*, int);
struct GridCursor;
extern "C" void GridCursor_ResetKeyRepeat(struct GridCursor*);
struct Struct_0205bc10;
extern "C" void func_0205bc10(struct Struct_0205bc10*);
struct Struct_0205bc2c;
extern "C" int func_0205bc2c(Struct_0205bc2c*, int);
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor*);
extern "C" int GridCursor_Update(void*, void*);
struct Struct_0205bcdc;
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc*, int);

struct Struct_0205c5b0 {
    char pad0[0x34];
    int field34;
    char unknown_38_[0x94 - 0x38];
    unsigned char field94;
    unsigned char unknown_95_;
};

// Main, originally func_0205c5b0 (USA 0x0205c5b0, EUR 0x0205c5c0, JPN 0x0205d910)
extern "C" ARM int Window_HandleInput(void* selfPtr, void* p1) {
    void* param1 = p1;
    struct Struct_0205c5b0* self = (struct Struct_0205c5b0*)selfPtr;
    int result = 0;
    int field34 = self->field34;

    if (self->field94 != 0) {
        if (func_0205c6bc((Struct_0205c5b0_2*)selfPtr) != 0) {
            int sum = func_0205bd04((struct Struct_0205bd04*)((char*)self + 0x4));
            GridCursor_SetSelectedIndex((struct SelfBB04*)((char*)self + 0x54), sum);
            GridCursor_ResetKeyRepeat((struct GridCursor*)((char*)self + 0x54));
            func_0205bc10((struct Struct_0205bc10*)((char*)self + 0x4));
            result = 1;
            goto done;
        }
    }

    if (self->field94 != 0) {
        typedef int (*Type_0205c5b0)(struct Struct_0205bc2c*, void*);
        if (((Type_0205c5b0)func_0205bc2c)((struct Struct_0205bc2c*)((char*)self + 0x4), param1) != 0) {
            int sum = func_0205bd04((struct Struct_0205bd04*)((char*)self + 0x4));
            if (field34 != sum) result = 2;
            GridCursor_SetSelectedIndex((struct SelfBB04*)((char*)self + 0x54), sum);
            GridCursor_ResetKeyRepeat((struct GridCursor*)((char*)self + 0x54));
            goto done;
        }
    }

    if (self->unknown_95_ != 0) {
        int before = GridCursor_GetSelectedIndex((struct GridCursor*)((char*)self + 0x54));
        if (GridCursor_Update((char*)self + 0x54, param1) != 0) {
            int after = GridCursor_GetSelectedIndex((struct GridCursor*)((char*)self + 0x54));
            if (before != after) {
                result = 1;
                int idx = GridCursor_GetSelectedIndex((struct GridCursor*)((char*)self + 0x54));
                GridCursor_SelectIfValid((struct Struct_0205bcdc*)((char*)self + 0x4), idx);
                self->field34 = -1;
                func_0205bc10((struct Struct_0205bc10*)((char*)self + 0x4));
            }
        }
    }

done:
    return result;
}
