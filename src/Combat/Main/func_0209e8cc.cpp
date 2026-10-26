#include <globaldefs.h>
#include "Combat/Main/CandidateFilter.h"
#include "std_library_functions.h"

struct Struct_0209e8cc {
    unsigned int words[16];
};

struct Struct_0209e8cc_2 {
    int count;
    Struct_0209e8cc entries[16];
};

struct Struct_0209e8cc_3 {
    char pad0[4];
    char* data;
    char pad8[0x90];
    Struct_0209e8cc_2 list;
    Struct_0209e8cc_2 scratch;
};

// USA: func_0209e8cc
extern "C" ARM void func_0209e8cc(Struct_0209e8cc_3* ctx, int arg1, int param) {
    if (arg1 == 0) {
        ctx->list.count = 0;
        int total = *(unsigned char*)(ctx->data + 0x8e07);
        int i = 0;
        while (i < total) {
            Struct_0209e8cc* entry = (Struct_0209e8cc*)(ctx->data + 0x5c60 + (i << 6));
            if (entry != NULL && func_0209e1cc(ctx, entry, 0, param)) {
                int n = ctx->list.count;
                ctx->list.count = ctx->list.count + 1;
                memcpy(&ctx->list.entries[n], entry, 0x40);
            }
            i++;
        }
    } else {
        ctx->scratch.count = 0;
        memset(ctx->scratch.entries, 0, 0x400);
        int i = 0;
        while (i < ctx->list.count) {
            Struct_0209e8cc* entry = &ctx->list.entries[i];
            if (func_0209e1cc(ctx, entry, 0, param)) {
                int n = ctx->scratch.count;
                ctx->scratch.count = ctx->scratch.count + 1;
                memcpy(&ctx->scratch.entries[n], entry, 0x40);
            }
            i++;
        }
        ctx->list.count = ctx->scratch.count;
        memcpy(ctx->list.entries, ctx->scratch.entries, 0x400);
    }
}
