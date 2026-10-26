#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" int func_ov031_02207dd4(unsigned char**);
extern "C" void func_ov031_02207e24(char*, const char*, int);
extern "C" int func_ov031_02207e90(unsigned char*, int);

extern const char* data_ov031_02249704[];

struct Struct_ov031_02207f10 {
    char pad0[0x458];
    int unknown_458_;
    int unknown_45c_;
    int unknown_460_;
    int unknown_464_;
    char pad1[0x484 - 0x468];
    int unknown_484_;
    unsigned char* unknown_488_;
    int unknown_48c_;
    unsigned char* unknown_490_;
    char unknown_494_[0x100];
    int unknown_594_;
    char unknown_598_[8];
    int unknown_5a0_;
    unsigned char* unknown_5a4_;
    int unknown_5a8_;
    unsigned char unknown_5ac_;
    unsigned char unknown_5ad_;
    unsigned char unknown_5ae_;
    unsigned char unknown_5af_;
    char unknown_5b0_[0x100];
    char unknown_6b0_[0x100];
    char unknown_7b0_[0x5c];
    unsigned int unknown_80c_;
};

// USA: func_ov031_02207f10
extern "C" ARM int func_ov031_02207f10(Struct_ov031_02207f10* c, unsigned char** arg1, int depth, int flag, int mode) {
    unsigned char* s = *arg1;
    unsigned char* p = s + 1;
    unsigned char tag = *s;
    int len = func_ov031_02207dd4(&p);
    if (len < 0 || len > 2000) {
        return 1;
    }
    switch (tag & 0x1f) {
    case 2:
        if (c->unknown_5ad_) {
            if (flag == 0) {
                if (*p == 0) {
                    do {
                        p++;
                        len--;
                    } while (*p == 0);
                }
                switch (mode) {
                case 0:
                    if (len <= 0x100) {
                        VectorizedInvertedMemcpy(p, c->unknown_494_, len);
                        c->unknown_594_ = len;
                    }
                    break;
                case 2:
                    c->unknown_484_ = len;
                    c->unknown_488_ = p;
                    break;
                }
            } else if (flag == 1) {
                if (*p == 0) {
                    do {
                        p++;
                        len--;
                    } while (*p == 0);
                }
                switch (mode) {
                case 0:
                    if (len <= 8) {
                        VectorizedInvertedMemcpy(p, c->unknown_598_, len);
                        c->unknown_5a0_ = len;
                    }
                    break;
                case 2:
                    c->unknown_48c_ = len;
                    c->unknown_490_ = p;
                    break;
                }
            }
        }
        p += len;
        break;
    case 3:
        if (depth == 1 && mode != 2) {
            c->unknown_5a4_ = p + 1;
            c->unknown_5a8_ = len - 1;
        }
        if (c->unknown_5ad_) {
            p++;
            if (func_ov031_02207f10(c, &p, depth, 0, mode)) {
                return 1;
            }
            c->unknown_5ad_ = 0;
        } else {
            p += len;
        }
        break;
    case 6: {
        int i;
        unsigned char* q = p;
        i = 0;
        do {
            const char* s = data_ov031_02249704[i];
            if (memcmp(q, s, strlen(s)) == 0) {
                switch (i) {
                case 1:
                case 2:
                    if (mode == 0) {
                        c->unknown_45c_ = i;
                    }
                    c->unknown_5ad_ = i;
                    break;
                case 3:
                case 4:
                    if (mode != 2) {
                        c->unknown_458_ = i;
                    }
                    break;
                case 5:
                    if (mode != 2) {
                        c->unknown_5ae_ = i;
                    }
                    break;
                }
                break;
            }
            i++;
        } while (i < 6);
        p += len;
        break;
    }
    case 12:
    case 19:
    case 20:
    case 22:
        if (mode != 2) {
            if (c->unknown_5ac_) {
                func_ov031_02207e24(c->unknown_6b0_, (const char*)p, len);
                if (c->unknown_5ae_ == 5 && len <= 0x4f) {
                    VectorizedInvertedMemcpy(p, c->unknown_7b0_, len);
                    c->unknown_7b0_[len] = 0;
                }
            } else {
                func_ov031_02207e24(c->unknown_5b0_, (const char*)p, len);
            }
        }
        c->unknown_5ae_ = 0;
        p += len;
        break;
    case 23:
    case 24:
        if (mode != 2) {
            unsigned int d = func_ov031_02207e90(p, tag & 0x1f);
            if (flag == 0) {
                if (c->unknown_80c_ >= d) {
                    c->unknown_5af_ = 1;
                }
            } else {
                if (c->unknown_80c_ > d) {
                    c->unknown_5af_ = 0;
                }
            }
        }
        p += len;
        c->unknown_5ac_ = 1;
        break;
    case 16: {
        if (depth == 0 && flag == 0 && mode != 2) {
            c->unknown_460_ = (int)p;
        }
        unsigned char* end = p + len;
        int i = 0;
        if (p < end) {
            do {
                int r = func_ov031_02207f10(c, &p, depth + 1, i, mode);
                i++;
                if (r) {
                    return 1;
                }
            } while (p < end);
        }
        if (depth == 1 && flag == 0 && mode != 2) {
            c->unknown_464_ = (int)p;
        }
        break;
    }
    case 17: {
        unsigned char* end = p + len;
        if (p < end) {
            do {
                if (func_ov031_02207f10(c, &p, depth + 1, 0, mode)) {
                    return 1;
                }
            } while (p < end);
        }
        break;
    }
    default:
        if (tag == 0xa0) {
            unsigned char* end = p + len;
            if (p < end) {
                do {
                    if (func_ov031_02207f10(c, &p, depth + 1, 0, mode)) {
                        return 1;
                    }
                } while (p < end);
            }
        } else {
            p += len;
        }
        break;
    }
    *arg1 = p;
    return 0;
}
