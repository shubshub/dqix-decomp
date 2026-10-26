#include <globaldefs.h>

typedef void* (*Type_ov031_02218fa0)(void*, int);

struct Struct_ov031_02218fa0_2 { unsigned int w[3]; };

struct Struct_ov031_02218fa0 {
    Struct_ov031_02218fa0_2 words;
};

struct Struct_ov031_0224e60c {
    void* base;
    int field4;
    char pad8[0x14 - 8];
    void* field14;
};

extern Struct_ov031_0224e60c data_ov031_0224e60c;
extern unsigned char data_ov031_0224a038;
extern unsigned char data_ov031_0224a04c;
extern "C" void VectorizedMemset(void* dst, int val, int size);
struct Struct_01ffd34c;
struct Mutex;
void ZeroInitializeMutex(Mutex*);
extern "C" void func_ov031_02219238(void);

// USA: func_ov031_02218fa0
extern "C" ARM int func_ov031_02218fa0(Struct_ov031_02218fa0* params) {
    Type_ov031_02218fa0 load = (Type_ov031_02218fa0)params->words.w[0];
    if (data_ov031_0224e60c.base != NULL) {
        return 4;
    }
    void* p = load(&data_ov031_0224a038, 0x11f4);
    data_ov031_0224e60c.base = p;
    if (p == NULL) {
        return 4;
    }
    VectorizedMemset(p, 0, 0x11f4);

    *(unsigned int*)((char*)data_ov031_0224e60c.base + 0x1000 + 4) = 0xfffe7961;
    *(Struct_ov031_02218fa0_2*)((char*)data_ov031_0224e60c.base + 0x1108) = params->words;

    if (data_ov031_0224e60c.field14 != NULL) {
        return 4;
    }
    void* q = load(&data_ov031_0224a04c, 0x1c14);
    data_ov031_0224e60c.field14 = q;
    if (q == NULL) {
        return 4;
    }
    data_ov031_0224e60c.field4 = 0;
    ZeroInitializeMutex((Mutex*)((char*)data_ov031_0224e60c.base + 0x1dc + 0x1000));
    func_ov031_02219238();
    return 0;
}
