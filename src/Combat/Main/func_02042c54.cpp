#include <globaldefs.h>

struct Struct_02042b98_2 {
    int left;
    int top;
    int right;
    int bottom;
};

// USA: func_02042c54
extern "C" ARM void func_02042c54(struct Struct_02042b98_2* rect, int left, int top, int right, int bottom) {
    rect->left = left;
    rect->top = top;
    rect->right = right;
    rect->bottom = bottom;
}
