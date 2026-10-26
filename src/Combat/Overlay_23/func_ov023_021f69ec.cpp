#include <globaldefs.h>

class Struct_ov023_021f69ec {
public:
    virtual void inline_ov023_021f69ec_6();
    virtual void inline_ov023_021f69ec();
    virtual void inline_ov023_021f69ec_2();
    virtual void inline_ov023_021f69ec_3();
    virtual void inline_ov023_021f69ec_4();
    virtual void inline_ov023_021f69ec_5();
    char pad[0x14];
    Struct_ov023_021f69ec* next;
};
struct Struct_ov011_02184760 { Struct_ov023_021f69ec* first; };

// USA: func_ov023_021f69ec
extern "C" ARM void func_ov023_021f69ec(struct Struct_ov011_02184760* head) {
    Struct_ov023_021f69ec* node = head->first;
    while (node != NULL) {
        node->inline_ov023_021f69ec_5();
        node = node->next;
    }
}
