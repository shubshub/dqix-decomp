#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" void* __clear(void*, int);
extern "C" int func_ov012_021859f4(void*, unsigned char*, int, int);

// USA: func_ov012_02185684
extern "C" ARM int func_ov012_02185684(void* owner, unsigned char* pattern,
    unsigned char* text, int unused, int limit) {
    unsigned char* var0 = static_cast<unsigned char*>(owner);
    unsigned int any;
    unsigned int open;
    unsigned int close;
    unsigned int var4;
    unsigned int var5;
    unsigned int special;
    int offset;
    any = var0[0x2a];
    open = var0[0x2b];
    close = var0[0x2c];
    var4 = var0[0x2d];
    var5 = var0[0x2e];
    special = var0[0x31];
    offset = 0;
    while (offset < limit) {
        unsigned char* p = pattern;
        unsigned char* q = text;
        for (;;) {
            int token = *p;
            if (token == 0) return 1;
            unsigned int current;
            int length;
            int minimum = 1;
            current = *q;
            int maximum = minimum;
            unsigned char* next = p;
            if (token == open) {
                for (;;) {
                    if (*next == close) { ++next; break; }
                    ++next;
                }
            } else next = p + 1;
            if (*next == var4) {
                minimum = next[1] - 8;
                maximum = next[3] - 8;
                if (next[4] - 8 == 0) maximum *= 10;
            }
            int matched = 1;
            if (token == special) {
                if (minimum == 0 && maximum == 60) {
                    unsigned int terminator = p[7];
                    for (;;) {
                        unsigned int c = *q;
                        if (c == 0 || c == 0xff) return 0;
                        if (terminator == c) break;
                        ++q;
                    }
                    p += 8;
                    ++q;
                    continue;
                }
            } else if (token == any) {
                if (current < 0x12 || current > 0x2b) matched = 0;
            } else if (token == open) {
                unsigned char group[8];
                __clear(group, sizeof(group));
                int var20 = 0;
                unsigned char* src;
                unsigned char* dst;
                dst = group;
                src = p + 1;
                length = var20;
                unsigned int var23;
                unsigned int var24;
                unsigned int end;
                end = var0[0x2c];
                var24 = var0[0x2f];
                var23 = var0[0x30];
                while (*src != end) {
                    unsigned int c = *src;
                    *dst = c;
                    if (c == var24) length = 2;
                    if (c == var23) var20 = 1;
                    ++src;
                    ++dst;
                }
                var20 += length;
                length = strlen(reinterpret_cast<char*>(group));
                if (var20 == 0)
                    matched = func_ov012_021859f4(owner, group, length, current);
                else if (var20 == 1) {
                    unsigned int low = group[0];
                    unsigned int high = group[length - 1];
                    matched = low <= current && current <= high;
                }
                else if (var20 == 2)
                    matched = !func_ov012_021859f4(owner, group + 1, length - 1, current);
                else if (var20 == 3) {
                    unsigned char* var29 = group + 1;
                    unsigned int high = var29[length - 2];
                    unsigned int low = group[1];
                    matched = !(low <= current && current <= high);
                }
                p += length + 1;
            } else if (token != current) matched = 0;
            if (matched) {
                int n = 0;
                while (n < minimum) {
                    if (current != *q) { matched = 0; break; }
                    ++n;
                    ++q;
                }
                if (!matched) break;
                while (minimum < maximum) {
                    if (current != *q) break;
                    ++minimum;
                    ++q;
                }
            } else if (matched == 0 && minimum != 0) break;
            ++p;
            if (*p == var4) {
                for (;;) {
                    if (*p != var5) ++p;
                    else break;
                }
                ++p;
            }
        }
        ++offset;
        ++text;
    }
    return 0;
}
