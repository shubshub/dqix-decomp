#include <globaldefs.h>

extern "C" void func_ov004_02154618(void* obj);
extern "C" void* func_ov004_02153944(void* a, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

// USA: func_ov004_02154718
extern "C" ARM void* func_ov004_02154718(void* obj) {
    void* node;
    func_ov004_02154618(obj);
    node = func_ov004_02153944(obj, 0x37);
    if (node) {
        func_ov023_021f809c(node, obj);
    }
    return 0;
}
