#include <globaldefs.h>

typedef void (*Type_0204b088)(void*, int, unsigned int);
extern unsigned int data_020e7b98[][4];
extern Type_0204b088 data_020f0218[][4];
struct Struct_0204b088 {
    char unknown_0_[0x14];
    void* unknown_14_;
    unsigned int unknown_18_;
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[2];
    unsigned char unknown_1f_;
};

// Main, originally func_0204b088 (USA 0x0204b088, EUR 0x0204b098, JPN 0x0204bea8)
extern "C" ARM void Background_TransferMap(TransferBuffer0204b088* transfer, void* buffer) {
    if (!buffer) buffer = transfer->buffer;
    if (!buffer) return;
    unsigned int source = transfer->source;
    unsigned int destination = transfer->destination;
    unsigned int mode = transfer->mode;
    unsigned int sizeIndex = transfer->sizeIndex;
    unsigned int size = data_020e7b98[mode][sizeIndex];
    Transfer0204b088 handler = data_020f0218[source][destination];
    transfer = (TransferBuffer0204b088*)buffer;
    handler(transfer, 0, size);
}
