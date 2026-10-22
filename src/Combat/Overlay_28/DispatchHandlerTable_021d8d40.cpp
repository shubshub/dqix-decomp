#include <globaldefs.h>

class PMFClass021d8d40 { public: virtual void Dummy021d8d40(); };
typedef void (PMFClass021d8d40::*MemFnPtr021d8d40)(unsigned short);

struct Entry021d8d40 { unsigned int a; unsigned int b; };
struct Table021d8d40 { struct Entry021d8d40 e[4]; };
extern struct Table021d8d40 data_ov028_021d9a34;
extern struct Entry021d8d40 __ptmf_null;

union PMFCast021d8d40 { struct Entry021d8d40* raw; MemFnPtr021d8d40* fn; };

// USA: func_ov028_021d8d40
ARM int DispatchHandlerTable_021d8d40(PMFClass021d8d40* obj1, unsigned short arg2) {
    struct Table021d8d40 t = data_ov028_021d9a34;
    t.e[3].b = __ptmf_null.b;
    t.e[3].a = __ptmf_null.a;
    unsigned char idx = *(unsigned char*)((char*)obj1 + 0x80);
    if (t.e[idx].a == 0) {
        return 1;
    }
    union PMFCast021d8d40 pmf;
    pmf.raw = &t.e[idx];
    (obj1->*(*pmf.fn))(arg2);
    return 0;
}
