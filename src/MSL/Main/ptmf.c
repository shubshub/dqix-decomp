typedef struct __ptmf {
    void* func_addr;
    long this_delta;
} __ptmf;

// USA: __ptmf_null
const __ptmf __ptmf_null = {0, 0};
