#include <globaldefs.h>
extern int data_ov031_02250c0c;
// USA: func_ov031_022274c0
extern "C" ARM void func_ov031_022274c0(int v) {
	*(int*)((char*)&data_ov031_02250c0c + 0xc) = v;
}
