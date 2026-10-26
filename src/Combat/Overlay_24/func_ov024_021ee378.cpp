#include <globaldefs.h>

extern "C" int func_ov000_0215e9fc(void* obj, void* buf, int count, int flag);
extern "C" void func_ov024_021ed8c0(void* arg0, int p1, int p2, int* arg3, short* arg4);

struct Struct_ov024_021ee378 {
    void* field0;
};

// USA: func_ov024_021ee378
extern "C" ARM int func_ov024_021ee378(struct Struct_ov024_021ee378* arg0, int p1, int p2, int* arg3, short* arg4) {
    int r = func_ov000_0215e9fc(arg0->field0, arg4, 4, 1);
    *arg3 = r;
    if (r <= 0) {
        return 0;
    }
    func_ov024_021ed8c0(arg0, p1, p2, arg3, arg4);
    return *arg4 >= 0 ? 1 : 0;
}
