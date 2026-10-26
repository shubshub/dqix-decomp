#include <globaldefs.h>
#include "Combat/MenuNodeChain.h"

struct Struct_0207f510;
struct Struct_0207ef60;
extern "C" void func_0207f510(Struct_0207f510*);
extern "C" void func_0207ef60(Struct_0207ef60*);

// USA: func_0207f84c
extern "C" ARM void func_0207f84c(Manager0207f7f0* self) {
    self->field0 = 0;
    func_0207f510((Struct_0207f510*)self->sub4);
    func_0207ef60((Struct_0207ef60*)self->unknown_c_);
    self->field14 = 0;
    self->field18 = 0;
#if defined(jpn)
    self->field1c = -1;
#else
    self->tasks[0] = self->tasks[1] = self->tasks[2] = self->field1c = -1;
#endif
    self->lists = 0;
    self->nodes = 0;
    self->field34 = 8;
    self->unknown_36_ = -1;
    self->mode = 0;
    self->count = 0;
    self->active = 0;
    self->unknown_3b_ = 0x10;
    self->field3c = 0x10;
}
