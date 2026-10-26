#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov000_02169b2c { char pad[4]; struct Struct_ov000_02169b2c* next; };
extern "C" void func_ov000_02169b2c(struct Struct_ov000_02169b2c* node, struct Struct_ov000_02169b2c* arg1);

struct Struct_ov000_02169b78 { char pad[8]; struct Struct_ov000_02169b2c* head; };
struct Struct_ov000_02184264 { char pad0[4]; struct Struct_ov000_02169b78* unknown_4_; };
extern struct Struct_ov000_02184264 data_ov000_02184264;

// USA: func_ov000_02169b78
extern "C" ARM void func_ov000_02169b78(struct Struct_ov000_02169b2c* arg0) {
    struct Struct_ov000_02169b78* var0 = data_ov000_02184264.unknown_4_;
    if (!var0) {
        return;
    }
    struct Struct_ov000_02169b2c* head = var0->head;
    if (!head) {
        var0->head = arg0;
        arg0->next = NULL;
        return;
    }
    func_ov000_02169b2c(head, arg0);
}
