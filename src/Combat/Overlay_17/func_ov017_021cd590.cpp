#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cd590 {
    unsigned short unknown_0_;
    unsigned short unknown_2_[4];
    unsigned char unknown_a_[4];
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};

// USA: func_ov017_021cd590
extern "C" ARM void func_ov017_021cd590(unsigned short id, unsigned int* list, unsigned char a2, unsigned char a3) {
    void* p = LinkMessageQueue_GetInstance();
    unsigned char buf[0x14];
    Msg021cd590* m = (Msg021cd590*)(buf + 4);
    m->field_e = a2;
    buf[0] = 0x6a;
    m->id = id;
    for (int i = 0; i < 4; i++) {
        unsigned int v = list[i];
        unsigned int hi = v & 0xff0000;
        m->values[i] = v;
        hi >>= 16;
        m->highBytes[i] = hi;
    }
    var2->unknown_f_ = arg3;
    func_0205e330(var0, var1, 0);
}
