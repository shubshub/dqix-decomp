#include <globaldefs.h>

extern "C" void func_ov002_02157424(void* obj, int* arr);

// USA: func_ov002_021573f8
extern "C" ARM int func_ov002_021573f8(void* obj, int index) {
    int arr[7];
    if (index < 0) {
        return -1;
    }
    func_ov002_02157424(obj, arr);
    return arr[index];
}
