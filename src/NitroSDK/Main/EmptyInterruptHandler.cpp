#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020c69c8
//
// PROVENANCE: pokediamond/arm9/lib/NitroSDK/src/crt0.c -- _start_AutoloadDoneCallback (a
// no-op placeholder handler with the same single-instruction body); named for our
// interrupt-vector-table usage per the auto-inferred signature.
ARM void EmptyInterruptHandler(void) {
}
