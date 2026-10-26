#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
struct Obj_0205ead0;
extern "C" void func_0205ead0(struct Obj_0205ead0* a, int b, int c);
extern struct Obj_0205ead0 g_sePlayer;

// USA: func_ov001_02163970
extern "C" ARM int func_ov001_02163970(void* obj) {
    int v = func_ov017_021d60f4(obj);
    func_0205ead0(&g_sePlayer, v, v);
    return 1;
}
