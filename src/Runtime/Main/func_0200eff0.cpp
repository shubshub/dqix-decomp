#include <globaldefs.h>

struct Struct_0200e984_2 {
    unsigned int unknown_0_;
    unsigned char* pattern;
};

// USA: func_0200eff0
extern "C" ARM int func_0200eff0(const unsigned char* text, const unsigned char* pattern, Struct_0200e984_2* state) {
    const unsigned char* cursor = pattern;
    state->unknown_0_ = 0;
    if (!pattern) return 1;
    if (*cursor == 'P') {
        ++cursor;
        if (*cursor == 'V') ++cursor;
        if (*cursor == 'K') ++cursor;
        if (*cursor == 'v' && (*text == 'P' || *text == '*')) return 1;
        cursor = pattern;
    }
    if (*text == '!' || *text == '*') {
        if (*text++ != *cursor++) return 0;
        for (;;) {
            for (;;) {
                unsigned int current = *text;
                if (current != *cursor++) break;
                ++text;
                if (current == '!') {
                    unsigned int var2 = 0;
                    if (*text != '!') {
                        do {
                            var2 = var2 * 10 + *text++ - '0';
                        } while (*text != '!');
                    }
                    state->unknown_0_ = var2;
                    return 1;
                }
            }
            while (*text++ != '!') {}
            while (*text++ != '!') {}
            if (!*text) return 0;
            cursor = pattern + 1;
        }
    }
    while ((*text == 'P' || *text == 'R') && *text == *cursor) {
        ++cursor;
        ++text;
        if (*cursor == 'K') {
            if (*text == 'K') ++text;
            ++cursor;
        }
        if (*text == 'K') return 0;
        const unsigned char* next = text;
        if (*cursor == 'V') {
            if (*next == 'V') ++next;
            ++cursor;
        }
        if (*next == 'V') return 0;
        text = next;
    }
    if (*text == *cursor) do {
        if (!*text) return 1;
    } while (*++text == *++cursor);
    return 0;
}
