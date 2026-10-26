#include <globaldefs.h>

struct Struct_0208d994 {
    short h0;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
};

struct Struct_0208bf78_5 {
    struct Struct_0208d994* base;
    short count;
};

extern "C" struct Struct_0208d994* func_0208d994(struct Struct_0208bf78_5* l, int key);

// USA: func_0208da18
extern "C" ARM int func_0208da18(struct Struct_0208bf78_5* list, int key, int arg2) {
    int result;
    struct Struct_0208d994* e;
    int* arr;
    result = 0;
    e = func_0208d994(list, key);
    if (e != NULL) {
    switch (arg2) {
        case 1:
            arr = (int*)e->unknown_c_;
            result = arr[0];
            break;
        case 2:
            arr = (int*)e->unknown_c_;
            result = arr[1];
            break;
        case 3:
            arr = (int*)e->unknown_c_;
            result = arr[2];
            break;
        case 4:
            arr = (int*)e->unknown_c_;
            result = arr[3];
            break;
        case 5:
            arr = (int*)e->unknown_c_;
            result = arr[4];
            break;
        case 6:
            arr = (int*)e->unknown_c_;
            result = arr[5];
            break;
        case 7:
            arr = (int*)e->unknown_c_;
            result = arr[6];
            break;
        case 8:
            arr = (int*)e->unknown_c_;
            result = arr[7];
            break;
        default:
            break;
    }
    }
    return result;
}
