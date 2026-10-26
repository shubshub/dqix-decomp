#include <globaldefs.h>

#pragma define_section initcode ".init" RX

void CopyGPCSignature(unsigned int* dst, unsigned int* src);
unsigned int* SetGPCSignatureGPC0(unsigned int* dst);
unsigned int* SetGPCSignatureGPC1(unsigned int* dst);
unsigned int* SetGPCSignatureGPC2(unsigned int* dst);

struct Struct_020f27c0 {
    const char* unknown_0_;
    const char* unknown_4_;
};
extern Struct_020f27c0 data_020f27c0;
extern unsigned int data_020f27c8;
extern unsigned int data_020f27cc;
extern unsigned int data_020f27d0;

// USA: func_020e6710
extern "C" __declspec(initcode) ARM void __sinit_020e6710(void) {
    data_020f27c0.unknown_0_ = data_020f27c0.unknown_4_ + 0xb;
    unsigned int buf3;
    SetGPCSignatureGPC0(&buf3);
    CopyGPCSignature(&data_020f27c8, &buf3);
    unsigned int buf2;
    SetGPCSignatureGPC1(&buf2);
    CopyGPCSignature(&data_020f27cc, &buf2);
    unsigned int buf1;
    SetGPCSignatureGPC2(&buf1);
    CopyGPCSignature(&data_020f27d0, &buf1);
}
