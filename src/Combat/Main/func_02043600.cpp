#include <globaldefs.h>

struct Struct_02043600_2 {
    char padding[0xae];
    short unknown_ae_;
};

struct Struct_02043600 {
    short x, y, width, height;
};

extern "C" void func_020435a8(int, void*, void*, int);

inline short inline_02043600(const Struct_02043600* arg0) { return arg0->x; }

#if defined(jpn)
#define func_02043600 func_02043de0
#endif

// JPN: func_02043de0
// USA: func_02043600
extern "C" ARM void func_02043600(Struct_02043600_2* border, const Struct_02043600* arg1) {
    if (border == NULL || arg1 == NULL) return;
    short left = inline_02043600(arg1);
    short top = arg1->y;
    short right = left + arg1->width;
    short bottom = top + arg1->height;
    top -= border->unknown_ae_ * 8;
    bottom -= border->unknown_ae_ * 8;
    right -= 8;
    bottom -= 8;
#if !defined(jpn)
    if (left < 0 || top < 0 || bottom < 0 || right < 0) return;
#endif
    for (short x = left + 8; x < right; x += 8)
        func_020435a8((int)border, (void*)x, (void*)top, 1);
    for (short x = left + 8; x < right; x += 8)
        func_020435a8((int)border, (void*)x, (void*)bottom, 6);
    for (short y = top + 8; y < bottom; y += 8)
        func_020435a8((int)border, (void*)left, (void*)y, 3);
    for (short y = top + 8; y < bottom; y += 8)
        func_020435a8((int)border, (void*)right, (void*)y, 4);
    func_020435a8((int)border, (void*)left, (void*)top, 0);
    func_020435a8((int)border, (void*)right, (void*)top, 2);
    func_020435a8((int)border, (void*)left, (void*)bottom, 5);
    func_020435a8((int)border, (void*)right, (void*)bottom, 7);
}

#if defined(jpn)
#undef func_02043600
#endif
