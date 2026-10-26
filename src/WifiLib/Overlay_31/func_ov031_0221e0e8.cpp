#include <globaldefs.h>

extern unsigned short data_ov031_0224f448;
extern unsigned char data_ov031_0224f44a[];
extern "C" THUMB unsigned char func_ov031_0221e2bc(void*, int);
extern "C" THUMB void* func_ov031_0221c49c(int);
extern "C" THUMB unsigned short func_ov031_0221e664();
extern "C" THUMB void func_ov031_0221e51c(void*, const void*, unsigned int);
extern "C" THUMB void func_ov031_0221e1ec(void*, void*, int, int);
extern "C" THUMB void func_ov031_0221e250(void*, unsigned char*, unsigned char*, unsigned int);
extern "C" THUMB void func_ov031_0221c4ac(int);
struct Struct_ov031_0221e0e8 {
    unsigned int first;
    unsigned int second;
    void* buffer;
    unsigned int size;
};

// USA: func_ov031_0221e0e8
extern "C" THUMB int func_ov031_0221e0e8(void* input, void* output, int length, unsigned char* status, unsigned short* arg4, void* data, int arg6) {
    unsigned short seed;
    Struct_ov031_0221e0e8 stream;
    *status = func_ov031_0221e2bc(input, length);
    stream.buffer = func_ov031_0221c49c(length);
    if (!stream.buffer) return -1;
    seed = func_ov031_0221e664();
    func_ov031_0221e51c(arg4, &seed, 2);
    func_ov031_0221e51c(&data_ov031_0224f448, arg4, 2);
    func_ov031_0221e51c(data_ov031_0224f44a, data, arg6);
    func_ov031_0221e1ec(&stream, &data_ov031_0224f448, arg6 + 2, length);
    func_ov031_0221e250(&stream, static_cast<unsigned char*>(output), static_cast<unsigned char*>(input), length);
    func_ov031_0221c4ac((int)stream.buffer);
    return 0;
}
