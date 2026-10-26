#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cbbd0 { unsigned char pad[0x8]; unsigned short val; };
struct Struct_ov017_021cbbd0_2 {
    unsigned char tag;
    unsigned char pad[3];
    unsigned short val;
    unsigned char pad2[14];
};

// USA: func_ov017_021cbbd0
extern "C" ARM void func_ov017_021cbbd0(unsigned char* obj) {
    Struct_ov017_021cbbd0_2 buf;
    void* p = LinkMessageQueue_GetInstance();
    buf.tag = 0x63;
    Struct_ov017_021cbbd0* src = *(Struct_ov017_021cbbd0**)(obj + 0x8e18);
    buf.val = src->val;
    func_0205e330(p, &buf, 1);
}
