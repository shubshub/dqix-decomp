#include <globaldefs.h>

extern "C" int func_ov017_021959b4(void);
void ResetBattlePhaseController020936b0(void* obj);
extern "C" void func_02092e0c(void* obj);
extern "C" void func_02092f00(void* obj);

struct HandlerEntry02092bcc {
    void* fn;
    int flags;
};

struct FullTable02092bcc {
    unsigned int w[10];
};

union Table02092bcc {
    struct FullTable02092bcc raw;
    struct HandlerEntry02092bcc e[5];
};

extern struct FullTable02092bcc data_020e8d84;
extern struct HandlerEntry02092bcc __ptmf_null;

// USA: func_02092bcc  (semantic: AdvanceBattlePhaseTimerAndDispatch_02092bcc)
extern "C" ARM int func_02092bcc(unsigned char* obj, int delta) {
    union Table02092bcc table;
    unsigned char id;
    struct HandlerEntry02092bcc* e;
    short v;

    if (obj[0x3a] == 0) {
        if (func_ov017_021959b4() != 0) {
            obj[0x3a] = 1;
            ResetBattlePhaseController020936b0(obj);
        }
    }

    v = *(short*)(obj + 0x32);
    if (v > 0) {
        *(short*)(obj + 0x32) = v - delta;
        if (*(short*)(obj + 0x32) < 0) {
            *(short*)(obj + 0x32) = 0;
        }
    }

    func_02092e0c(obj);
    func_02092f00(obj);

    if (obj[0x37] & 0x4) {
        return 0;
    }

    table.raw = data_020e8d84;
    {
        int flagsVal = __ptmf_null.flags;
        void* fnVal = __ptmf_null.fn;
        ((struct HandlerEntry02092bcc*)&table)[4].flags = flagsVal;
        ((struct HandlerEntry02092bcc*)&table)[4].fn = fnVal;
    }

    id = obj[0x34];
    if (table.e[id].fn == 0) {
        return 1;
    }
    {
        e = &table.e[id];
        void* adjusted = obj + (e->flags >> 1);
        void* target;
        if (e->flags & 1) {
            void** vtable = (void**)*(void**)adjusted;
            target = *(void**)((char*)vtable + (int)e->fn);
        } else {
            target = e->fn;
        }
        ((void (*)(void*))target)(adjusted);
    }
    return 0;
}
