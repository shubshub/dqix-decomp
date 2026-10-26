#include <globaldefs.h>

struct Struct_020cee68;
struct Struct_0210cfdc;
extern "C" ARM void func_020cee68(struct Struct_020cee68*, struct Struct_0210cfdc*);

extern int data_02111800;

// USA: func_020cef4c
extern "C" ARM void func_020cef4c(struct Struct_0210cfdc* node) {
    func_020cee68((struct Struct_020cee68*)&data_02111800, node);
}
