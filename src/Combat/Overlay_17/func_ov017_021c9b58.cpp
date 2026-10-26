#include <globaldefs.h>

extern "C" int func_ov017_021c9954(int a, int b, int c, int d);

// USA: func_ov017_021c9b58
extern "C" ARM int func_ov017_021c9b58(void* obj, char* rec) {
    return func_ov017_021c9954(*(unsigned short*)(rec + 6), 0, *(unsigned char*)(rec + 0xa), (int)obj);
}
