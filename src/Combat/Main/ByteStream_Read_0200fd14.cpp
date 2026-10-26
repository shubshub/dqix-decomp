#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Stream0200fd14 { char* ptr; };

// USA: func_0200fd14
// Copies 'length' bytes out of the stream at stream->ptr and advances the pointer.
// Main, originally ReadStreamBlock0200fd14 (USA 0x0200fd14, EUR 0x0200fd24, JPN 0x0200fb70)
ARM void ByteStream_Read(struct Stream0200fd14* stream, void* dst, unsigned int length) {
    VectorizedInvertedMemcpy(stream->ptr, dst, length);
    stream->ptr += length;
}
