#include <globaldefs.h>

struct Struct_020b0e48 {
    unsigned int words[2];
};

struct Struct_ov031_0223c308 {
    Struct_020b0e48 unknown_0_[2];
    unsigned char slots[0x660];
    void* unknown_670_;
    void* unknown_674_[2];
};

extern "C" void* func_ov031_0223cf4c(int size, int align);
extern "C" int func_ov031_0223beec(int count, int array, int stride);
extern "C" int func_ov031_02227548(void);
extern "C" void* func_ov031_0223b61c(int id, int a, int b);
extern "C" void func_020b0e48(Struct_020b0e48* reader, void* data);

extern Struct_ov031_0223c308* data_ov031_02290d38;
extern int data_ov031_0224c570[];
extern int data_ov031_0224c578[];

// USA: func_ov031_0223c308
extern "C" ARM void func_ov031_0223c308(void) {
    Struct_ov031_0223c308* globals = (Struct_ov031_0223c308*)func_ov031_0223cf4c(0x680, 4);

    data_ov031_02290d38 = globals;
    data_ov031_02290d38->unknown_670_ = (void*)func_ov031_0223beec(0x20, (int)globals->slots, 0x30);

    switch (func_ov031_02227548()) {
    case 6: {
        int i = 0;
        int offset = 0;
        do {
            data_ov031_02290d38->unknown_674_[i] = func_ov031_0223b61c(data_ov031_0224c570[i], 0, 4);
            func_020b0e48((Struct_020b0e48*)((char*)data_ov031_02290d38 + offset),
                               data_ov031_02290d38->unknown_674_[i]);
            i++;
            offset += 8;
        } while (i < 2);
        break;
    }
    default: {
        int offset;
        int i = 0;
        offset = 0;
        do {
            data_ov031_02290d38->unknown_674_[i] = func_ov031_0223b61c(data_ov031_0224c578[i], 0, 4);
            func_020b0e48((Struct_020b0e48*)((char*)data_ov031_02290d38 + offset),
                               data_ov031_02290d38->unknown_674_[i]);
            i++;
            offset += 8;
        } while (i < 2);
        break;
    }
    }
}
