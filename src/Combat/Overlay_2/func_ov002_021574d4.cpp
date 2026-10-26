#include <globaldefs.h>

extern "C" void func_ov002_02157480(void* obj, int* arr);

// USA: func_ov002_021574d4
extern "C" ARM int func_ov002_021574d4(void* obj, int index) {
    int arr[4];
    if (index < 0) {
        return -1;
    }
    func_ov002_02157480(obj, arr);
    return arr[index];
}
