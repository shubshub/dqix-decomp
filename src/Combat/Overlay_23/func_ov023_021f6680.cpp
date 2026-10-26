#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void);
extern "C" int func_ov023_021f809c(void*, void*);

// USA: func_ov023_021f6680
extern "C" ARM int func_ov023_021f6680(void* obj, int id) {
    void* sub = func_ov011_021849c8(obj);
    void* node = func_ov023_021f6880(sub, id);
    if (node == NULL) return (int)node;
    int state = func_ov023_021f6f10();
    if (state != 6) return state;
    return func_ov023_021f809c(node, obj);
}
