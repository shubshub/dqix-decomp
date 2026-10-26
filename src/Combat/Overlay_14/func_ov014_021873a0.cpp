#include <globaldefs.h>

extern "C" short func_02080468(void* obj, int id);
extern "C" void func_ov014_02188a8c(void* self, short key);

struct Struct_ov014_021873a0 {
    Struct_ov014_021873a0* next;
    char pad4[0x16];
    short unknown_1a_;
};

struct Struct_ov014_021873a0_2 {
    char pad0[0x98];
    void* unknown_98_;
    char unknown_9c_[0x1c];
    Struct_ov014_021873a0* fb8;
    Struct_ov014_021873a0* unknown_bc_;
    void* fc0;
    char unknown_c4_[0xb2];
    short unknown_176_;
};

// USA: func_ov014_021873a0
extern "C" ARM Struct_ov014_021873a0* func_ov014_021873a0(Struct_ov014_021873a0_2* self) {
    void* obj = self->fc0;
    short id = func_02080468(obj, 5);
    short target = (short)(self->unknown_176_ - id);
    Struct_ov014_021873a0* node = self->unknown_bc_;
    short count = 0;
    while (node != 0) {
        if (target == count) {
            break;
        }
        Struct_ov014_021873a0* next = node->next;
        if (next == 0) {
            break;
        }
        count = count + 1;
        node = next;
    }
    if (node == 0) {
        self->unknown_bc_ = self->fb8;
        count = 0;
    }
    id = func_02080468(obj, 5);
    self->unknown_176_ = count + id;
    if (node != 0) {
        short key = node->unknown_1a_;
        func_ov014_02188a8c(self, key);
        self->unknown_98_ = (char*)self + 0x182;
    }
    return node;
}
