#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cd590 {
    unsigned short id;
    unsigned short values[4];
    unsigned char unknown_a_[4];
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};

// USA: func_ov017_021cd590
extern "C" ARM void func_ov017_021cd590(unsigned short id, unsigned int* list, unsigned char a2, unsigned char a3) {
    void* p = LinkMessageQueue_GetInstance();
    unsigned char buf[0x14];
    Struct_ov017_021cd590* m = (Struct_ov017_021cd590*)(buf + 4);
    m->unknown_e_ = a2;
    buf[0] = 0x6a;
    m->id = id;
    for (int i = 0; i < 4; i++) {
        unsigned int v = list[i];
        unsigned int hi = v & 0xff0000;
        m->values[i] = v;
        hi >>= 16;
        m->unknown_a_[i] = hi;
    }
    m->unknown_f_ = a3;
    func_0205e330(p, buf, 0);
}
