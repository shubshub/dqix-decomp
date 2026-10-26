#include <globaldefs.h>

extern "C" int func_ov017_021c9954(int a, int b, int c, int d);

// USA: func_ov017_021c9b74
extern "C" ARM int func_ov017_021c9b74(void* obj, char* rec) {
    return func_ov017_021c9954(*(unsigned short*)(rec + 6), 0, 0, (int)obj);
}
