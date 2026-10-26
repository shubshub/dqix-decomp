#include <globaldefs.h>

struct Struct_020b36c0 {
    int _[16];
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c21dc
//
// PROVENANCE: pokediamond/arm9/lib/NitroSDK/src/FX_mtx44.c -- MTX_Identity44_. NitroSDK fx: set 4x4 fixed-point identity matrix.
// C attempted (plain field-by-field and array-index assignment): mwcc emits one str per
// word, never the hand-picked {r1,r2,r3} stm groupings the target uses -- BYTEDIFF, wrong
// shape, not a register-colour issue. Reference itself has this as hand asm in both
// pokediamond and SonicRushAdventure-Decomp; the stm register sets here (paired/tripled
// reuse of r1-r3 chosen per group, not simply "all live regs") is exactly the
// register-block tell no compiler emits.
extern "C" ARM asm void Mat4x4_WriteIdentity(void *dst) {
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2}
    bx lr
}
