#include <globaldefs.h>

struct Struct_ov031_022407e4;
struct Struct_ov031_022407f8;

struct Struct_ov031_0224185c_7 {
    Struct_ov031_0224185c_7* next;
    signed char data[0x200];
};

struct Struct_ov031_0224185c_3 {
    volatile int unknown_0_;
    volatile int unknown_4_;
    int ok;
    int unknown_c_;
    char pad10[0x1c - 0x10];
    Struct_ov031_0224185c_7* blocks;
    signed char hdr[0x400];
};

struct Struct_ov031_0224185c_4 {
    Struct_ov031_0224185c_4* prev;
    Struct_ov031_0224185c_4* next;
    char* name;
    char* value;
};

struct Struct_ov031_0224185c_5 {
    Struct_ov031_0224185c_5* prev;
    Struct_ov031_0224185c_5* next;
    char* name;
    char* value;
    int unknown_10_;
    int unknown_14_;
};

struct Struct_ov031_0224185c_6 {
    int unk0;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    void* unknown_20_;
    char* unknown_24_;
    int unknown_28_;
    void* unknown_2c_;
    Struct_ov031_0224185c_3* unknown_30_;
    Struct_ov031_0224185c_4* unknown_34_;
    Struct_ov031_0224185c_5* params;
    void (*callback)(int, Struct_ov031_0224185c_3*, void*);
    int method;
    char unknown_44_[0x16];
};

struct Struct_ov031_0224185c {
    void* prev;
    void* next;
    int id;
    Struct_ov031_0224185c_6* req;
    int unknown_10_;
};

struct Struct_ov031_0224185c_2 {
    int unknown_0_;
    short events;
    short unknown_6_;
};

struct Struct_ov031_022919bc_3 { int head; int tail; };

extern "C" void* func_ov031_02240310(void);
extern "C" Struct_ov031_0224185c* func_ov031_022402e0(void);
extern "C" void func_ov031_02240324(void);
extern "C" int func_ov031_022403d8(void);
extern "C" int func_ov031_022413b8(void* unused, int id);
extern "C" void func_ov031_02241318(void);
extern "C" int func_ov031_022407e4(Struct_ov031_022407e4* obj, unsigned int val);
extern "C" int func_ov031_022407f8(Struct_ov031_022407f8* obj, int b, int c, int d);

extern "C" int func_ov031_02240fc8(Struct_ov031_0224185c_6* req);
extern "C" int func_ov031_0220783c(Struct_ov031_0224185c_2* arg0, int n, int arg2, int flags);
extern "C" void func_ov031_0224175c(int arg0, void** ctx);
extern "C" int func_ov031_02241338(Struct_ov031_0224185c_6* req);
extern "C" int func_ov031_02241404(Struct_ov031_0224185c_6* req, int arg1, int addr, int arg3);
extern "C" void func_ov031_02241720(void* ctx);
extern "C" int func_ov031_022415a8(const char* s);
extern "C" int func_ov031_022415e0(Struct_ov031_0224185c_6* req, int arg1, int* pos, const char* buf, int count);
extern "C" Struct_ov031_0224185c_4* func_ov031_0223ff38(Struct_ov031_0224185c_4** list);
extern "C" int func_ov031_02242b5c(const char* s);
extern "C" int func_ov031_02242dd4(signed char* out, int n);
extern "C" int func_ov031_02242bc4(signed char* out, int c);
extern "C" int func_ov031_022414cc(Struct_ov031_0224185c_6* req, int arg1, char* buf, int count, int flags);
extern "C" int func_ov031_02241480(Struct_ov031_0224185c_6* req, int arg1, void* buf, int count, int flags);
extern "C" int func_ov031_022406f8(Struct_ov031_0224185c_3* arg0, char* dst, int start, int len);
extern "C" int func_ov031_02241540(const char* a, const char* b, int n);
extern "C" int func_ov031_02242d3c(char* str, int maxLen);
extern "C" int func_ov031_022404e8(Struct_ov031_0224185c_3* arg0, int start, int end, int* arg3);
extern "C" int func_ov031_022410d8(Struct_ov031_0224185c_3* arg0, const char* name, int* arg2);
extern "C" int func_ov031_02240628(Struct_ov031_0224185c_3* arg0, int start, int end, const char* word, int arg4);
extern "C" int func_ov031_02241694(Struct_ov031_0224185c_6* req, int arg1);
extern "C" int func_ov031_02242c54(char* str, int len);
extern "C" int func_ov031_02240820(Struct_ov031_0224185c_6* req, int arg1, int pos, int count, int flags);
extern "C" int func_ov031_02240e70(Struct_ov031_0224185c_6* req);
extern "C" void func_ov031_022417fc(void);

extern Struct_ov031_022919bc_3 data_ov031_022919bc;
extern int data_ov031_02290fd0;
extern Struct_ov031_0224185c* data_ov031_02290fcc;
extern void (*data_ov031_02290fc8)(void*);
extern void* (*data_ov031_02290fc4)(int size, int align);
extern int data_ov031_02290fc0;
extern char data_ov031_02291a04[0x400];
extern char data_ov031_02291a0d[];
extern char data_ov031_0224c794[];
extern char data_ov031_0224c79c[];
extern char data_ov031_0224c7a4[];
extern char data_ov031_0224c7ac[];
extern char data_ov031_0224c7b0[];
extern char data_ov031_0224c7bc[];
extern char data_ov031_0224c7c4[];
extern char data_ov031_0224c7c8[];
extern char data_ov031_0224c7cc[];
extern char data_ov031_0224c7fc[];
extern char data_ov031_0224c830[];
extern char data_ov031_022494d8[];
extern char data_ov031_0224c844[];
extern char data_ov031_02249500[];
extern char data_ov031_0224c848[];
extern char data_ov031_0224c850[];
extern char data_ov031_0224c854[];
extern char data_ov031_0224c858[];
extern char data_ov031_0224c860[];
extern char data_ov031_0224c870[];
extern char data_ov031_0224c87c[];
extern char data_ov031_0224c888[];
extern char data_ov031_0224c89c[];

static inline Struct_ov031_0224185c_7* inline_ov031_0224185c(void) {
    return (Struct_ov031_0224185c_7*)data_ov031_02290fc4(sizeof(Struct_ov031_0224185c_7), 4);
}

#define HTTP_SEND(str, len)                                                 \
    do {                                                                    \
        int sent = func_ov031_022415e0(req, var17, &pos, (str), (len));      \
        if (sent < 0) goto done;                                            \
        if (sent != 0) break;                                               \
        goto retry;                                                         \
    } while (0)

// USA: func_ov031_0224185c
extern "C" ARM void func_ov031_0224185c(void) {
    signed char buf[12];
    void* ctx;
    int pos;
    int tmp;
    int var4;
    Struct_ov031_0224185c_2 var5;
    char var6[3];
    Struct_ov031_0224185c* var7;
    int addr;
    int var9;
    int var10;
    int var11;
    int var12;
    int var13;
    int var14;
    int same;
    int len;
    int var17;
    int total;
    int var19;
    Struct_ov031_0224185c_6* req;
    int id;
    Struct_ov031_0224185c_3* var22;
    int var23;
    int n;
    int i;

    var17 = -1;
    ctx = 0;
    data_ov031_022919bc.head = 0;
    data_ov031_022919bc.tail = 0;
    var11 = 0;
    var9 = -1;
    var10 = -1;
    var14 = 0;
    var12 = 0;
    while (data_ov031_02290fd0 == 0) {
        func_ov031_02240310();
        var7 = func_ov031_022402e0();
        if (var7 == 0) {
            id = -1;
        } else {
            id = var7->id;
            req = var7->req;
            data_ov031_02290fcc = var7;
        }
        func_ov031_02240324();
        if (id < 0) {
            func_ov031_022403d8();
            continue;
        }
        var22 = req->unknown_30_;
        if (req->unknown_4_ != 0) goto done;
        addr = func_ov031_02240fc8(req);
        if (addr == 0) {
            var13 = 4;
            goto done;
        }
        same = 0;
        if (addr == var9 && req->unknown_28_ == var10 && req->unknown_8_ == var12) same = 1;
        var10 = req->unknown_28_;
        var12 = req->unknown_8_;
        var9 = addr;
        var14 = var14 & same;
    retry:
        var13 = 0;
        if (var17 >= 0) {
            var5.events = 9;
            var5.unknown_0_ = var17;
            if (func_ov031_0220783c(&var5, 1, 0xcc8d, 0) <= 0) {
                var14 = 0;
            } else if (var5.unknown_6_ & 0xe0) {
                var14 = 0;
            }
        }
        if (var14 == 0) {
            if (var17 >= 0) {
                if (func_ov031_022413b8(req, var17) < 0) var13 = 10;
                func_ov031_0224175c(var17, &ctx);
                var17 = -1;
                if (var13 != 0) goto done;
            }
            var17 = func_ov031_02241338(req);
            if (var17 < 0) {
                var13 = 3;
                goto done;
            }
            if (req->unknown_8_ != 0) {
                ctx = req->unknown_20_;
                req->unknown_20_ = 0;
            }
            func_ov031_02240310();
            data_ov031_02290fcc->unknown_10_ = var17;
            func_ov031_02240324();
            if (req->unknown_4_ != 0) goto done;
            if (func_ov031_02241404(req, var17, addr, req->unknown_28_) >= 0) {
                var14 = 1;
            } else {
                var14 = 0;
            }
        } else {
            if (req->unknown_8_ != 0) {
                func_ov031_02241720(req->unknown_20_);
                req->unknown_20_ = 0;
            }
            func_ov031_02241318();
            func_ov031_02240310();
            data_ov031_02290fcc->unknown_10_ = var17;
            func_ov031_02240324();
        }
        if (req->unknown_4_ != 0) goto done;
        if (var14 == 0) {
            var13 = 5;
            goto done;
        }
        pos = 0;
        var14 = 0;
        len = func_ov031_022415a8(req->unknown_24_);
        var13 = 10;

        switch (req->method) {
        case 0:
            HTTP_SEND(data_ov031_0224c794, 4);
            break;
        case 1:
            HTTP_SEND(data_ov031_0224c79c, 5);
            break;
        case 2:
            HTTP_SEND(data_ov031_0224c7a4, 5);
            break;
        }
        if (len > req->unknown_10_) {
            n = len - req->unknown_10_;
            if (n != 0) HTTP_SEND(req->unknown_24_ + req->unknown_10_, n);
        } else {
            HTTP_SEND(data_ov031_0224c7ac, 1);
        }
        HTTP_SEND(data_ov031_0224c7b0, 11);

        tmp = req->unknown_8_ != 0 ? 8 : 7;
        HTTP_SEND(data_ov031_0224c7bc, 6);
        n = req->unknown_c_ - tmp;
        if (n != 0) HTTP_SEND(req->unknown_24_ + tmp, n);
        HTTP_SEND(data_ov031_0224c7c4, 2);

        {
            Struct_ov031_0224185c_4* h = func_ov031_0223ff38(&req->unknown_34_);
            while (h != 0) {
                n = func_ov031_022415a8(h->name);
                if (n != 0) HTTP_SEND(h->name, n);
                HTTP_SEND(data_ov031_0224c7c8, 2);
                n = func_ov031_022415a8(h->value);
                if (n != 0) HTTP_SEND(h->value, n);
                HTTP_SEND(data_ov031_0224c7c4, 2);
                data_ov031_02290fc8(h);
                h = func_ov031_0223ff38(&req->unknown_34_);
            }
        }

        if (req->method == 1) {
            Struct_ov031_0224185c_5* list;
            Struct_ov031_0224185c_5* p;
            total = 0;
            list = req->params;
            var11 = 0;
            p = list;
            while (p != 0) {
                if (p->unknown_14_ != 0) {
                    var11 = 1;
                    break;
                }
                if (p == list->prev) break;
                p = p->next;
            }
            if (var11 != 0) {
                while (list != 0) {
                    total += 0x16;
                    total += func_ov031_022415a8(list->name) + 0x29;
                    if (list->unknown_14_ != 0) total += 0x4b;
                    total += 2;
                    total += list->unknown_10_;
                    total += 2;
                    if (list == req->params->prev) break;
                    list = list->next;
                }
                total += 0x18;
                HTTP_SEND(data_ov031_0224c7cc, 0x2c);
                HTTP_SEND(req->unknown_44_ + 2, 0x12);
                HTTP_SEND(data_ov031_0224c7c4, 2);
            } else {
                while (list != 0) {
                    total = total + func_ov031_02242b5c(list->name) + 1;
                    total += func_ov031_02242b5c(list->value);
                    if (list == req->params->prev) break;
                    list = list->next;
                    total++;
                }
                HTTP_SEND(data_ov031_0224c7fc, 0x31);
            }
            HTTP_SEND(data_ov031_0224c830, 0x10);
            tmp = func_ov031_02242dd4(buf, total);
            if (tmp != 0) HTTP_SEND((char*)buf, tmp);
            HTTP_SEND(data_ov031_0224c7c4, 2);
        }
        HTTP_SEND(data_ov031_0224c7c4, 2);

        if (req->method == 1) {
            if (var11 != 0) {
                Struct_ov031_0224185c_5* p = req->params;
                while (p != 0) {
                    HTTP_SEND(req->unknown_44_, 0x14);
                    HTTP_SEND(data_ov031_0224c7c4, 2);
                    HTTP_SEND(data_ov031_022494d8, 0x26);
                    n = func_ov031_022415a8(p->name);
                    if (n != 0) HTTP_SEND(p->name, n);
                    HTTP_SEND(data_ov031_0224c844, 3);
                    if (p->unknown_14_ != 0) HTTP_SEND(data_ov031_02249500, 0x4b);
                    HTTP_SEND(data_ov031_0224c7c4, 2);
                    if (p->unknown_10_ != 0) HTTP_SEND(p->value, p->unknown_10_);
                    HTTP_SEND(data_ov031_0224c7c4, 2);
                    if (p == req->params->prev) break;
                    p = p->next;
                }
                HTTP_SEND(req->unknown_44_, 0x14);
                HTTP_SEND(data_ov031_0224c848, 4);
            } else {
                Struct_ov031_0224185c_5* q = req->params;
                while (q != 0) {
                    for (i = 0; q->name[i] != 0; i++) {
                        tmp = func_ov031_02242bc4(buf, q->name[i]);
                        if (tmp != 0) HTTP_SEND((char*)buf, tmp);
                    }
                    HTTP_SEND(data_ov031_0224c850, 1);
                    for (i = 0; q->value[i] != 0; i++) {
                        tmp = func_ov031_02242bc4(buf, q->value[i]);
                        if (tmp != 0) HTTP_SEND((char*)buf, tmp);
                    }
                    if (q == req->params->prev) break;
                    HTTP_SEND(data_ov031_0224c854, 1);
                    q = q->next;
                }
            }
        }
        if (pos > 0) {
            int var31 = func_ov031_022414cc(req, var17, data_ov031_02291a04, pos, 0);
            if (var31 < 0) goto done;
            if (var31 == 0) goto retry;
        }

        var22->unknown_0_ = 0;
        buf[0] = 0;
        buf[1] = 0;
        buf[2] = 0;
        buf[3] = 0;
        {
            Struct_ov031_0224185c_7* blk = var22->blocks;
            var13 = 7;
            pos = 0;
            for (;;) {
                int var33;
                if (req->unknown_4_ != 0) goto done;
                if (pos < 0x400) {
                    var33 = func_ov031_02241480(req, var17, var22->hdr + pos, 1, 0);
                    buf[pos & 3] = var22->hdr[pos];
                } else {
                    int off = pos & 0x1ff;
                    if (off == 0) {
                        if (blk != 0) {
                            blk->next = inline_ov031_0224185c();
                            blk = blk->next;
                        } else {
                            blk = inline_ov031_0224185c();
                            var22->blocks = blk;
                        }
                        if (blk == 0) {
                            var13 = 1;
                            goto done;
                        }
                        blk->next = 0;
                    }
                    var33 = func_ov031_02241480(req, var17, blk->data + off, 1, 0);
                    buf[pos & 3] = blk->data[off];
                }
                if (var33 <= 0) {
                    var13 = 10;
                    goto done;
                }
                pos += var33;
                if (buf[(pos - 4) & 3] == '\r' && buf[(pos - 3) & 3] == '\n' &&
                    buf[(pos - 2) & 3] == '\r' && buf[(pos - 1) & 3] == '\n') {
                    var22->unknown_0_ = pos;
                    break;
                }
            }
        }
        if (var22->unknown_0_ == 0) goto done;

        if (func_ov031_022406f8(var22, data_ov031_02291a04, 0, 0xe) == 0) goto done;
        if (func_ov031_02241540(data_ov031_02291a04, data_ov031_0224c858, 5) != 0 || data_ov031_02291a04[8] != ' ') goto done;
        if (func_ov031_02242d3c(data_ov031_02291a0d, 3) < 0) goto done;
        if (func_ov031_022404e8(var22, 0xc, var22->unknown_0_, &var4) < 0) goto done;

        len = func_ov031_022410d8(var22, data_ov031_0224c860, &tmp);
        if (len == 0) {
            var13 = 0;
            goto done;
        }
        if (len > 0x400) goto done;
        if (len > 0) {
            if (func_ov031_022406f8(var22, data_ov031_02291a04, tmp, len) == 0) goto done;
            len = func_ov031_02242d3c(data_ov031_02291a04, len);
            if (len < 0) goto done;
            req->unknown_14_ = len;
        } else {
            req->unknown_14_ = -1;
        }

        n = func_ov031_022410d8(var22, data_ov031_0224c870, &tmp);
        var14 = n;
        if (n == 0) goto done;
        if (n < 0) {
            var6[0] = data_ov031_02291a04[5];
            var6[1] = data_ov031_02291a04[7];
            var6[2] = 0;
            if (func_ov031_02242d3c(var6, 2) >= 11) {
                var14 = 1;
            } else {
                var14 = 0;
            }
        } else if (n > 0x400) {
            var14 = 0;
        } else {
            if (func_ov031_02240628(var22, tmp, tmp + var14, data_ov031_0224c87c, 0) == 0) {
                var14 = 1;
            } else {
                var14 = 0;
            }
        }

        n = func_ov031_022410d8(var22, data_ov031_0224c888, &tmp);
        if (n == 0) goto done;
        if (n > 0x400) {
            var19 = 0;
        } else if (n > 0) {
            var19 = func_ov031_02240628(var22, tmp, tmp + n, data_ov031_0224c89c, ';') == 0;
        } else {
            var19 = 0;
        }
        if (req->method == 2) goto done;

        if (len >= 0) {
            while (len > 0 && func_ov031_022407e4((Struct_ov031_022407e4*)var22, var22->unknown_4_) == 0) {
                int var35 = func_ov031_02240820(req, var17, var22->unknown_4_, len, 0);
                if (var35 < 0) goto done;
                if (var35 == 0) break;
                len -= var35;
                var22->unknown_4_ += var35;
            }
            if (len != 0) {
                var13 = func_ov031_022407e4((Struct_ov031_022407e4*)var22, var22->unknown_4_) != 0 ? 6 : 10;
                goto done;
            }
            var13 = 0;
            goto done;
        }
        var13 = 10;
        if (var19 != 0) {
            for (;;) {
                signed char c;
                buf[0] = 0;
                buf[1] = 0;
                pos = 0;
                do {
                    if (func_ov031_02241480(req, var17, data_ov031_02291a04 + pos, 1, 0) < 0) goto done;
                    c = data_ov031_02291a04[pos];
                    buf[pos & 1] = c;
                    if (c == ';' || (c == 0xa && buf[(pos - 1) & 1] == 0xd)) {
                        if (c == 0xa) {
                            tmp = pos - 1;
                        } else {
                            tmp = pos;
                            if (func_ov031_02241694(req, var17) <= 0) goto done;
                        }
                        if (tmp == 0) goto done;
                        var23 = func_ov031_02242c54(data_ov031_02291a04, tmp);
                        if (var23 >= 0) break;
                        goto done;
                    }
                    pos++;
                } while (pos < 0x400);
                if (pos == 0x400) {
                    var13 = 7;
                    goto done;
                }
                if (var23 <= 0) break;
                while (var23 > 0) {
                    int var37 = func_ov031_02240820(req, var17, var22->unknown_4_, var23, 0);
                    if (var37 <= 0) goto done;
                    var22->unknown_4_ += var37;
                    var23 -= var37;
                    if (var23 == 0) {
                        if (func_ov031_02241480(req, var17, data_ov031_02291a04, 1, 0) <= 0) goto done;
                        if (func_ov031_02241480(req, var17, data_ov031_02291a04, 1, 0) <= 0) goto done;
                    }
                }
            }
            func_ov031_02241694(req, var17);
            var13 = 0;
            goto done;
        }
        while (func_ov031_022407e4((Struct_ov031_022407e4*)var22, var22->unknown_4_) == 0) {
            int var38 = func_ov031_022407f8((Struct_ov031_022407f8*)req, var17, var22->unknown_4_, 0);
            if (var38 < 0) goto done;
            if (var38 == 0) {
                var13 = 0;
                goto done;
            }
            var22->unknown_4_ += var38;
            if (func_ov031_022407e4((Struct_ov031_022407e4*)var22, var22->unknown_4_) != 0) {
                var38 = func_ov031_02241480(req, var17, data_ov031_02291a04, 1, 0);
                if (var38 < 0) goto done;
                if (var38 != 0) {
                    var13 = 6;
                    goto done;
                }
            }
        }
    done:
        func_ov031_02240310();
        data_ov031_02290fc8(data_ov031_02290fcc);
        data_ov031_02290fcc = 0;
        func_ov031_02240324();
        if (req->unknown_4_ != 0) var13 = 8;
        if (var17 >= 0) {
            if (var14 == 0 || var13 != 0) {
                if (func_ov031_022413b8(req, var17) < 0) var13 = 10;
                func_ov031_0224175c(var17, &ctx);
                var17 = -1;
                var14 = 0;
            }
        }
        if (var13 == 0) {
            var22->ok = 1;
        } else {
            var22->ok = 0;
            data_ov031_02290fc0 = var13;
        }
        {
            void* var39 = req->unknown_2c_;
            void (*cb)(int, Struct_ov031_0224185c_3*, void*) = req->callback;
            func_ov031_02240e70(req);
            cb(var13, var22, var39);
        }
    }
    if (var17 >= 0) {
        func_ov031_022413b8(req, var17);
        func_ov031_0224175c(var17, &ctx);
    }
    func_ov031_022417fc();
}
