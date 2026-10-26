#include <globaldefs.h>

class Struct_ov023_021f698c {
public:
    virtual void inline_ov023_021f698c_2();
    virtual void inline_ov023_021f698c();
    char pad[0x14];
    Struct_ov023_021f698c* next;
};
struct Struct_ov011_02184740 { Struct_ov023_021f698c* first; };

// USA: func_ov023_021f698c
extern "C" ARM void func_ov023_021f698c(struct Struct_ov011_02184740* head) {
    Struct_ov023_021f698c* node = head->first;
    while (node != NULL) {
        node->inline_ov023_021f698c();
        node = node->next;
    }
}
