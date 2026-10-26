#include <globaldefs.h>

extern "C" void func_ov031_022415b4(void* dst, unsigned int size);
extern "C" void func_ov031_022415c8(void* dst, const void* src, unsigned int size);
extern "C" int func_ov031_022415a8(const char* s);
extern "C" int func_ov031_02241540(const char* a, const char* b, int n);
extern "C" int func_ov031_02242c54(const char* text, int length);
extern "C" int func_ov031_02242f14(const char* p, int len);

extern int data_ov031_02290fc0;
extern void* (*data_ov031_02290fc4)(unsigned int size, int align);
extern void (*data_ov031_02290fc8)(void* p);
extern const char data_ov031_0224c770[];
extern const char data_ov031_0224c778[];
extern const unsigned char data_ov031_022494c0[];

struct Struct_ov031_02240890 {
    char pad0[0x800];
    char* unknown_800_;
    char unknown_804_[0x2c];
};

struct Struct_ov031_02240890_2 {
    char pad0[0xc];
    unsigned int len;
    char pad10[8];
    void* buf;
    char unknown_1c_[0x404];
};

struct Struct_ov031_02218098_2 {
    char pad0[8];
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    char unknown_14_[0xc];
    Struct_ov031_02240890* unknown_20_;
    char* unknown_24_;
    int unknown_28_;
    void* param;
    Struct_ov031_02240890_2* body;
    char unknown_34_[8];
    void* callback;
    int method;
    unsigned char header[0x14];
};

// USA: func_ov031_02240890
extern "C" ARM Struct_ov031_02218098_2* func_ov031_02240890(const char* arg0, int method, void* buf, unsigned int len,
                                                void* callback, void* param) {
    int prefix;
    int var1;
    int i;
    int j;
    const char* p;
    int var5;
    int var6;
    signed char c;
    Struct_ov031_02218098_2* req = 0;
    int state;

    if (method != 0 && method != 1 && method != 2) {
        data_ov031_02290fc0 = 0xb;
        goto fail;
    }
    if (len == 0) {
        data_ov031_02290fc0 = 0xb;
        goto fail;
    }
    req = (Struct_ov031_02218098_2*)data_ov031_02290fc4(sizeof(Struct_ov031_02218098_2), 4);
    if (req == 0) {
        data_ov031_02290fc0 = 1;
        goto fail;
    }
    func_ov031_022415b4(req, sizeof(Struct_ov031_02218098_2));
    req->body = (Struct_ov031_02240890_2*)data_ov031_02290fc4(sizeof(Struct_ov031_02240890_2), 4);
    if (req->body == 0) {
        data_ov031_02290fc0 = 1;
        goto fail;
    }
    func_ov031_022415b4(req->body, sizeof(Struct_ov031_02240890_2));
    req->body->buf = buf;
    req->body->len = len;

    var1 = func_ov031_022415a8(arg0);
    if (var1 <= 7) {
        data_ov031_02290fc0 = 4;
        goto fail;
    }
    prefix = 7;
    req->unknown_28_ = 80;
    if (func_ov031_02241540(arg0, data_ov031_0224c770, prefix) != 0) {
        if (func_ov031_02241540(arg0, data_ov031_0224c778, 8) != 0) {
            data_ov031_02290fc0 = 4;
            goto fail;
        }
        req->unknown_8_ = 1;
        req->unknown_28_ = 443;
        prefix = 8;
    }
    var1 -= prefix;
    p = arg0 + prefix;
    if (var1 <= 0) {
        data_ov031_02290fc0 = 4;
        goto fail;
    }

    for (i = 0, var5 = 0, state = 0; i < var1 && p[i] != '/'; i++) {
        if (state == 2) {
            state--;
        } else if (state == 1) {
            c = func_ov031_02242c54(&p[i - 1], 2);
            state--;
            if (c < 0) {
                data_ov031_02290fc0 = 4;
                goto fail;
            }
            if (c == '/') {
                var5--;
                break;
            }
        } else if (p[i] == '%') {
            state = 2;
            var5++;
        }
    }
    if (state != 0) {
        data_ov031_02290fc0 = 4;
        goto fail;
    }

    req->unknown_24_ = (char*)data_ov031_02290fc4(prefix + var1 - var5 * 2 + 1, 4);
    if (req->unknown_24_ == 0) {
        data_ov031_02290fc0 = 1;
        goto fail;
    }
    func_ov031_022415c8(req->unknown_24_, arg0, prefix);

    for (i = 0, j = 0, state = 0, var6 = 0; i < var1; i++) {
        if (state == 2) {
            state--;
        } else if (state == 1) {
            c = func_ov031_02242c54(&p[i - 1], 2);
            req->unknown_24_[prefix + j - 1] = c;
            state--;
            if (c == '/') {
                var6 = 1;
            }
        } else {
            c = p[i];
            if (c == '/') {
                var6 = 1;
            }
            if (var6 == 0 && c == '%') {
                state = 2;
            } else {
                req->unknown_24_[prefix + j] = c;
            }
            j++;
        }
    }
    req->unknown_24_[prefix + j] = 0;

    {
        const char* var10 = req->unknown_24_ + prefix;
        int k;
        for (k = 0; k < j; k++) {
            if (var10[k] == '/' || var10[k] == ':') {
                req->unknown_c_ = k + prefix;
                break;
            }
        }
        if (k == j) {
            req->unknown_c_ = k + prefix;
            req->unknown_10_ = k + prefix;
        } else if (var10[k] == '/') {
            req->unknown_10_ = req->unknown_c_;
        } else if (var10[k] == ':') {
            for (; k < j; k++) {
                if (var10[k] == '/') {
                    req->unknown_10_ = k + prefix;
                    break;
                }
            }
            if (k == j) {
                req->unknown_10_ = k + prefix;
            } else {
                int start = req->unknown_c_ + 1;
                int var13 = func_ov031_02242f14(req->unknown_24_ + start, req->unknown_10_ - start);
                if (var13 < 0) {
                    var13 = req->unknown_28_;
                } else if (var13 > 0xffff) {
                    data_ov031_02290fc0 = 4;
                    goto fail;
                }
                req->unknown_28_ = (unsigned short)var13;
            }
        }
    }

    if (req->unknown_8_ != 0) {
        int var14 = req->unknown_c_ - prefix;
        req->unknown_20_ = (Struct_ov031_02240890*)data_ov031_02290fc4(sizeof(Struct_ov031_02240890), 4);
        if (req->unknown_20_ == 0) {
            data_ov031_02290fc0 = 1;
            goto fail;
        }
        func_ov031_022415b4(req->unknown_20_, sizeof(Struct_ov031_02240890));
        req->unknown_20_->unknown_800_ = (char*)data_ov031_02290fc4(var14 + 1, 4);
        if (req->unknown_20_->unknown_800_ == 0) {
            data_ov031_02290fc0 = 1;
            goto fail;
        }
        func_ov031_022415c8(req->unknown_20_->unknown_800_, req->unknown_24_ + prefix, var14);
        req->unknown_20_->unknown_800_[var14] = 0;
    }

    func_ov031_022415c8(req->header, data_ov031_022494c0, sizeof(req->header));
    req->param = param;
    req->method = method;
    req->callback = callback;
    return req;

fail:
    if (req != 0) {
        if (req->unknown_20_ != 0) {
            if (req->unknown_20_->unknown_800_ != 0) {
                data_ov031_02290fc8(req->unknown_20_->unknown_800_);
            }
            data_ov031_02290fc8(req->unknown_20_);
        }
        if (req->unknown_24_ != 0) {
            data_ov031_02290fc8(req->unknown_24_);
        }
        if (req->body != 0) {
            data_ov031_02290fc8(req->body);
        }
        data_ov031_02290fc8(req);
    }
    return 0;
}
