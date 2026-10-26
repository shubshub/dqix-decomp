#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cd35c {
    unsigned short b;
    unsigned short c : 15;
    unsigned short unknown_3_7_ : 1;
    unsigned char e;
    signed char f;
};

struct Struct_ov017_021cd35c_2 {
    unsigned short id;
    unsigned short b;
    unsigned short c;
    signed char d;
    unsigned char e;
    signed char f;
};

// USA: func_ov017_021cd35c
extern "C" ARM void func_ov017_021cd35c(unsigned short id, Struct_ov017_021cd35c* list, int count, signed char last) {
    void* p = LinkMessageQueue_GetInstance();
    unsigned char buf[0x14];
    buf[0] = 0x68;
    struct Struct_ov017_021cd35c_2* m = (struct Struct_ov017_021cd35c_2*)(buf + 4);
    m->id = id;
    if (count != 0) {
        int i;
        int var4 = -1;
        for (i = 0; i < count; i++, list++) {
            m->b = list->b;
            m->c = list->c;
            m->e = list->e;
            m->f = list->f;
            if (i == count - 1) m->d = last;
            else m->d = var4;
            func_0205e330(p, buf, 0);
        }
    } else {
        m->b = 0;
        m->c = 0;
        m->d = 0;
        m->f = -1;
        func_0205e330(p, buf, 0);
    }
}
