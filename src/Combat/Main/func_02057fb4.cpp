#include <globaldefs.h>

extern "C" void* func_02057f8c(void* list, int id);
extern "C" void func_02057fd8(void* a1, void* node, void* config);

// USA: func_02057fb4
extern "C" ARM void func_02057fb4(void* list, int id, void* config) {
    void* node = func_02057f8c(list, id);
    func_02057fd8(list, node, config);
}
