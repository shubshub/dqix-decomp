#include <globaldefs.h>

class Struct_ov023_021f69bc {
public:
    virtual void inline_ov023_021f69bc_3();
    virtual void inline_ov023_021f69bc();
    virtual void inline_ov023_021f69bc_2();
    char pad[0x14];
    Struct_ov023_021f69bc* next;
};
struct Struct_ov011_02184750 { Struct_ov023_021f69bc* first; };

// USA: func_ov023_021f69bc
extern "C" ARM void func_ov023_021f69bc(struct Struct_ov011_02184750* head) {
    Struct_ov023_021f69bc* node = head->first;
    while (node != NULL) {
        node->inline_ov023_021f69bc_2();
        node = node->next;
    }
}
