#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Timing.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

typedef unsigned long Type_ov031_02201ef4;

struct Struct_ov031_0224c9e8 {
    unsigned long long x;
    unsigned long long mul;
    unsigned long long unknown_10_;
};

struct Struct_ov031_0224ca00 {
    unsigned int address;
    unsigned char unknown_4_[6];
    unsigned short unknown_a_;
};

struct Struct_ov031_0224ca60 {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char unknown_c_[0x18 - 0xc];
    unsigned short unknown_18_;
    unsigned char pad1a[2];
    unsigned int unknown_1c_;
    unsigned char pad20[4];
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    unsigned char pad2c[0x3c - 0x2c];
    int unknown_3c_;
    void* unknown_40_;
    unsigned char unknown_44_[4];
    int unknown_48_;
    void* sendBuffer;
    unsigned char unknown_50_[0x64 - 0x50];
};

struct Struct_ov031_0224cca8 {
    unsigned long source;
    unsigned short count;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_[8];
    unsigned short unknown_1c_[8];
    unsigned long unknown_2c_;
    unsigned char* payload;
    unsigned char* allocation;
};

extern unsigned char data_ov031_0224968c[8];
extern unsigned char data_ov031_0224ce68[6];
extern unsigned char data_ov031_0224ced6[0x12c] __attribute__((aligned(2)));

unsigned char data_ov031_0224c980;
static unsigned char data_ov031_0224c981;
static unsigned short data_ov031_0224c986;
static inline unsigned short inline_ov031_02201364(void) {
    static unsigned short pingseq = 0;
    return pingseq++;
}
static unsigned short ephemeral_port;
static unsigned short data_ov031_0224c982;
static unsigned short unk_0a;
static volatile unsigned int lan_buflen;
static unsigned int dhcp_server;
static ProcessorContext* volatile recv_waiter;
unsigned int data_ov031_0224c9d0;
static void (*dhcp_callback)(void);
static unsigned int cps_mode;
static int calm_down;
void (*data_ov031_0224c9c0)(void*);
static void (*scavenger)(void);
unsigned int data_ov031_0224c9ac;
static unsigned int requested_ip;
static unsigned int dhcp_retry;
static unsigned int lease_time;
static unsigned char* lan_buf;
static unsigned int yield_wait;
static int cps_state;
unsigned int data_ov031_0224c99c;
void* (*data_ov031_0224c994)(unsigned long);
static volatile unsigned int recv_head;
static volatile unsigned int recv_tail;
static int (*link_is_on)(void);
unsigned int data_ov031_0224c9e0[2];
Struct_ov031_0224c9e8 data_ov031_0224c9e8;
Struct_ov031_0224ca00 data_ov031_0224ca00[8];
Struct_ov031_0224ca60 data_ov031_0224ca60;
Struct_ov031_0224ca60 data_ov031_0224cac4;
ProcessorContext data_ov031_0224cb28;
ProcessorContext data_ov031_0224cbe8;
Struct_ov031_0224cca8 data_ov031_0224cca8[8];

struct Struct_ov031_02200160 {
    void* context;
    int type;
    unsigned char status;
};

extern "C" void func_ov031_0220ab78();

// USA: func_ov031_02200160
extern "C" ARM void func_ov031_02200160(int state) {
    int var0 = data_ov031_0224c9d0 != 0;

    cps_state = state;
    data_ov031_0224c9d0 = 0;
    data_ov031_0224c99c = 0;
    data_ov031_0224c9ac = 0;
    data_ov031_0224c9e0[0] = 0;
    data_ov031_0224c9e0[1] = 0;
    dhcp_server = 0;
    if (!var0) {
        return;
    }

    VectorizedMemset(data_ov031_0224ca00, 0, 0x60);

    ProcessorContext* ctx = data_02111304.firstContext;
    if (ctx != NULL) {
        do {
            Struct_ov031_02200160* p = (Struct_ov031_02200160*)ctx->unknown_A4;
            if (p != NULL && p->context != NULL) {
                if (p->status != 0xa && p->status != 0xb) {
                    p->status = 0;
                }
                if (p->type != 0) {
                    p->type = 0;
                    MarkContextReadyAndSwitch((ProcessorContext*)p->context);
                }
            }
            ctx = ctx->pNext;
        } while (ctx != NULL);
    }

    int i = 0;
    Struct_ov031_0224cca8* fragment = data_ov031_0224cca8;
    do {
        if (fragment->count != 0) {
            data_ov031_0224c9c0(fragment->allocation);
            fragment->count = 0;
        }
        i++;
        fragment++;
    } while (i < 8);

    func_ov031_0220ab78();
}

void CycleCurrentPriorityContexts();
void SleepCurrentContext(unsigned int);

// USA: func_ov031_02200264
extern "C" ARM void func_ov031_02200264(void) {
    unsigned int v = yield_wait;
    if (v == 0) {
        CycleCurrentPriorityContexts();
    } else {
        SleepCurrentContext(v);
    }
}

// USA: func_ov031_0220028c
extern "C" ARM void func_ov031_0220028c(void) {
}

// USA: func_ov031_02200290
extern "C" ARM int func_ov031_02200290() {
    return 1;
}

typedef unsigned char Type_020b1300;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long Type_020b11c8_2;
typedef int Type_020b0a1c_2;

typedef struct {
    u32 mode;
    void* (*alloc)(u32);
    void (*unknown_8_)(void*);
    void (*unknown_c_)(void);
    Type_020b0a1c_2 (*unknown_10_)(void);
    unsigned long long unknown_18_;
    Type_020b1300* unknown_20_;
    u32 unknown_24_;
    u32 unknown_28_;
    u32 unknown_2c_;
    u32 unknown_30_;
} Struct_ov031_02200298;

extern unsigned int data_ov031_02249680;
extern unsigned char data_ov031_0224e1c0[];
extern unsigned char data_ov031_0224d9c0[];
#define CPS_MIDDLEWARE ((const void*)0x02000c04)
extern "C" void OSi_ReferSymbol(const void*);

extern "C" void func_ov031_02203008(void);
extern "C" void func_ov031_02203c6c(void);
extern "C" void OS_GetMacAddress(void*);

static inline void inline_ov031_02200298(Struct_ov031_0224c9e8* context, Type_020b11c8_2 seed) {
    context->x = seed;
    context->mul = (1566083941LL << 32) + 1812433253LL;
    context->unknown_10_ = 2531011;
}

static inline u32 inline_ov031_02200298_2(Struct_ov031_0224c9e8* context, u32 max) {
    context->x = context->mul * context->x + context->unknown_10_;
    if (max == 0) {
        return (u32)(context->x >> 32);
    } else {
        return (u32)(((context->x >> 32) * max) >> 32);
    }
}

// USA: func_ov031_02200298
extern "C" ARM void func_ov031_02200298(Struct_ov031_02200298* arg0) {
    OSi_ReferSymbol(CPS_MIDDLEWARE);
    Type_020b11c8_2 seed = arg0->unknown_18_;
    if (seed) {
        inline_ov031_02200298(&data_ov031_0224c9e8, seed);
    } else {
        inline_ov031_02200298(&data_ov031_0224c9e8, GetCurrentTimestamp());
    }
    if (arg0->alloc && arg0->unknown_8_) {
        data_ov031_0224c994 = arg0->alloc;
        data_ov031_0224c9c0 = arg0->unknown_8_;
    } else {
        data_ov031_0224c994 = (void* (*)(u32))func_ov031_0220028c;
        data_ov031_0224c9c0 = (void (*)(void*))func_ov031_0220028c;
    }
    cps_mode = arg0->mode;
    if (arg0->unknown_28_) data_ov031_0224c982 = arg0->unknown_28_;
    else data_ov031_0224c982 = 0x5b4;
    requested_ip = arg0->unknown_2c_;
    yield_wait = arg0->unknown_30_;
    if (arg0->unknown_c_) dhcp_callback = arg0->unknown_c_;
    else dhcp_callback = func_ov031_0220028c;
    if (arg0->unknown_10_) link_is_on = arg0->unknown_10_;
    else link_is_on = func_ov031_02200290;
    lan_buf = arg0->unknown_20_;
    lan_buflen = arg0->unknown_24_;
    recv_tail = 0;
    recv_head = 0;
    ephemeral_port = 0x400 + inline_ov031_02200298_2(&data_ov031_0224c9e8, 0xf88);
    OS_GetMacAddress(data_ov031_0224ce68);
    data_ov031_0224c981 = 0;
    PopulateContext(&data_ov031_0224cbe8, (unsigned int)func_ov031_02203008, 0, (unsigned int)data_ov031_0224e1c0, 0x800, data_ov031_02249680);
    PopulateContext(&data_ov031_0224cb28, (unsigned int)func_ov031_02203c6c, 0, (unsigned int)data_ov031_0224d9c0, 0x800, data_ov031_02249680);
    MarkContextReadyAndSwitch(&data_ov031_0224cbe8);
    MarkContextReadyAndSwitch(&data_ov031_0224cb28);
}

bool IsContextInactive(ProcessorContext* context);

// USA: func_ov031_022004d4
extern "C" ARM int func_ov031_022004d4(void) {
	int var0 = DisableIRQInterrupts();
	int var1 = IsContextInactive(&data_ov031_0224cb28);
	if (var1 == 0) {
		if (calm_down == 0) {
			calm_down = 1;
			MarkContextReadyAndSwitch(&data_ov031_0224cb28);
		}
	}
	SetIRQInterruptState(var0);
	return var1;
}

// USA: func_ov031_02200524
extern "C" ARM void func_ov031_02200524(int v) {
	scavenger = (void (*)(void))v;
}

// USA: func_ov031_02200534
extern "C" ARM void func_ov031_02200534(void) {
    func_ov031_022004d4();
    AwaitContextCompletion(&data_ov031_0224cb28);
    ShutdownContext(&data_ov031_0224cbe8);
    recv_waiter = 0;
    func_ov031_02200160(0);
    lan_buf = 0;
    lan_buflen = 0;
}

extern unsigned int data_ov031_02249680;

// USA: func_ov031_0220057c
extern "C" ARM void func_ov031_0220057c(unsigned int priority) {
	data_ov031_02249680 = priority;
	ChangeContextPriority(&data_ov031_0224cbe8, priority);
	ChangeContextPriority(&data_ov031_0224cb28, priority);
}

// USA: func_ov031_022005b4
extern "C" ARM unsigned int func_ov031_022005b4(unsigned char* addr, unsigned int len, unsigned int sum) {
	if ((unsigned int)addr & 1) {
		if (len > 1) {
			do {
				unsigned short v = ((unsigned int)addr[0] << 8) | addr[1];
				sum += v;
				addr += 2;
				len -= 2;
			} while (len > 1);
		}
	} else {
		unsigned short s = (unsigned short)sum;
		sum = (unsigned short)((s >> 8) | (s << 8));
		if (len > 1) {
			do {
				sum += *(unsigned short*)addr;
				addr += 2;
				len -= 2;
			} while (len > 1);
		}
		unsigned int var2 = (sum >> 8) & 0xff00ff;
		unsigned int t2 = (sum << 8) & 0xff00ff00;
		sum = var2 | t2;
		sum = (sum >> 16) | (sum << 16);
	}
	if (len != 0) {
		sum += (unsigned int)addr[0] << 8;
	}
	sum = (sum & 0xffff) + (sum >> 16);
	sum += sum >> 16;
	return (unsigned short)sum;
}

// USA: func_ov031_02200668
extern "C" ARM unsigned int func_ov031_02200668(unsigned int value) {
	unsigned short v = (unsigned short)(value ^ 0xffff);
	if (v == 0) {
		return 0xffff;
	}
	return v;
}

// USA: func_ov031_02200684
extern "C" ARM unsigned int func_ov031_02200684(void* p, unsigned int len) {
	unsigned int sum = func_ov031_022005b4((unsigned char*)p, len, 0);
	return func_ov031_02200668((unsigned short)sum);
}

// USA: func_ov031_022006a0
extern "C" ARM int func_ov031_022006a0(void* a, unsigned int len, void* c, unsigned int seed) {
	unsigned int sum = func_ov031_022005b4((unsigned char*)a, len, seed);
	sum = func_ov031_022005b4((unsigned char*)((char*)c + 0xc), 8, sum);
	unsigned int v = sum + len;
	if (v & 0x10000) {
		v = (unsigned short)(v + 1);
	}
	return v != 0xffff;
}

// USA: func_ov031_022006f0
extern "C" ARM int func_ov031_022006f0(int a) {
	int result = 1;
	if (a != -1 && a != 0x7F000001) {
		unsigned int mask = data_ov031_0224c99c;
		if ((a & mask) != (data_ov031_0224c9d0 & mask)) result = 0;
	}
	return result;
}

// USA: func_ov031_02200730
extern "C" ARM int func_ov031_02200730(int a) {
	int result = a;
	if (func_ov031_022006f0(a) == 0) {
		result = data_ov031_0224c9ac;
	}
	return result;
}

// USA: func_ov031_02200754
extern "C" ARM int func_ov031_02200754(unsigned int a) {
	int result = 0;
	if (func_ov031_022006f0(a) != 0) {
		unsigned int var1 = ~data_ov031_0224c99c;
		if (var1 == (var1 & a)) {
			result = 1;
		}
	}
	return result;
}

// USA: func_ov031_02200790
extern "C" ARM int func_ov031_02200790(unsigned int v) {
	return (v & 0xf0000000) == 0xe0000000;
}

// USA: func_ov031_022007a4
extern "C" ARM int func_ov031_022007a4(int id) {
	int cur = data_ov031_0224c9d0;
	int var1 = 1;
	int var2 = 1;
	int var3 = 1;
	int var4 = 1;
	if (cur != 0 && id != cur) var4 = 0;
	if (!var4) {
		if (id != 0x7f000001) var3 = 0;
	}
	if (!var3) {
		if (func_ov031_02200754(id) == 0) var2 = 0;
	}
	if (!var2) {
		if (func_ov031_02200790(id) == 0) var1 = 0;
	}
	return var1;
}

// USA: func_ov031_02200824
extern "C" ARM int func_ov031_02200824(unsigned short* a, unsigned short* b) {
	int i = 0;
	do {
		if (*a++ != *b++) return 1;
		i++;
	} while (i < 3);
	return 0;
}

extern "C" int func_ov031_0220f104(void* a, void* b, unsigned int c, void* d, unsigned int e);

// USA: func_ov031_02200850
extern "C" ARM void func_ov031_02200850(void* a, unsigned int b, void* c, unsigned int d) {
	VectorizedInvertedMemcpy(data_ov031_0224968c, (char*)a + 6, 6);
	int result = func_ov031_0220f104(a, (char*)a + 6, b - 6, c, d);
	data_ov031_0224c980 = result < 0;
}

// USA: func_ov031_022008ac
extern "C" ARM void func_ov031_022008ac(void* arg0, void* arg1, unsigned char* frame, unsigned int len, void* extra, unsigned int arg5) {
	if (lan_buf == NULL || lan_buflen == 0) {
		return;
	}
	unsigned int total = len + arg5;
	if (total < 8 || total > 0x5e4) {
		return;
	}
	if (frame[0] != data_ov031_0224968c[0] || frame[1] != data_ov031_0224968c[1] ||
	    frame[2] != data_ov031_0224968c[2] || frame[6] != 8) {
		return;
	}
	if (frame[7] != 0 && frame[7] != 6) {
		return;
	}
	unsigned short size = (total + 9) & ~1;
	unsigned int next = recv_head + size;
	if (recv_head < recv_tail && recv_tail <= next) {
		return;
	}
	if (next == lan_buflen) {
		next = 0;
		if (recv_tail == 0) {
			return;
		}
	} else if (next > lan_buflen) {
		next = size;
		if (recv_tail <= size) {
			return;
		}
	}
	if (recv_head + size > lan_buflen) {
		if (lan_buflen - recv_head >= 2) {
			*(unsigned short*)(lan_buf + recv_head) = 0;
		}
		recv_head = 0;
	}
	*(unsigned short*)(lan_buf + recv_head) = size;
	VectorizedInvertedMemcpy(arg1, lan_buf + recv_head + 2, 6);
	VectorizedInvertedMemcpy(arg0, lan_buf + recv_head + 8, 6);
	VectorizedInvertedMemcpy(frame + 6, lan_buf + recv_head + 0xe, len - 6);
	if (extra != NULL && arg5 != 0) {
		VectorizedInvertedMemcpy(extra, lan_buf + recv_head + 8 + len, arg5);
	}
	recv_head = next;
}

bool IsContextInactive(ProcessorContext* context);
void MarkContextReadyAndSwitch(ProcessorContext* context);

// USA: func_ov031_02200aa0
extern "C" ARM void func_ov031_02200aa0(void* a, int b, void* c, void* d) {
	func_ov031_022008ac(a, (void*)b, (unsigned char*)c, (unsigned int)d, (void*)0, 0);
	if (recv_waiter == NULL) return;
	if (IsContextInactive(recv_waiter)) return;
	MarkContextReadyAndSwitch(recv_waiter);
}

// USA: func_ov031_02200af8
extern "C" ARM void* func_ov031_02200af8(unsigned int* outLen) {
	int var0 = DisableIRQInterrupts();
	if (recv_tail == recv_head) {
		do {
			recv_waiter = data_02111304.activeContext;
			BlockCurrentContext(NULL);
			recv_waiter = 0;
		} while (recv_tail == recv_head);
	}
	SetIRQInterruptState(var0);

	unsigned char* base = lan_buf;
	unsigned int value;
	do {
		if (lan_buflen - recv_tail < 2) {
			recv_tail = 0;
		}
		value = *(unsigned short*)(base + recv_tail);
		if (value == 0) {
			recv_tail = 0;
		}
	} while (value == 0);

	*outLen = value - 2;
	return lan_buf + recv_tail + 2;
}

// USA: func_ov031_02200bb8
extern "C" ARM void func_ov031_02200bb8(void) {
	int var0 = DisableIRQInterrupts();
	recv_tail = recv_tail +
		*(unsigned short*)(lan_buf + recv_tail);
	if (recv_tail >= lan_buflen) {
		recv_tail = 0;
	}
	SetIRQInterruptState(var0);
}

struct Struct_ov031_02200bfc { unsigned int address; unsigned char unknown_4_[6]; unsigned short unknown_a_; };
extern unsigned char data_ov031_02249684[6];

// USA: func_ov031_02200bfc
extern "C" ARM unsigned char* func_ov031_02200bfc(unsigned int address) {
    unsigned int index;
    int var1 = DisableIRQInterrupts();
    unsigned char* var2 = NULL;
    if (address == 0x7f000001 || address == data_ov031_0224c9d0) var2 = data_ov031_0224ce68;
    else if (func_ov031_02200754(address) || func_ov031_02200790(address)) var2 = data_ov031_02249684;
    else {
        Struct_ov031_02200bfc* entry = (Struct_ov031_02200bfc*)data_ov031_0224ca00;
        index = 0;
        do {
            if (address == entry->address) {
                unsigned int time = GetCurrentTimestamp() >> 16;
                data_ov031_0224ca00[index].unknown_a_ = time;
                var2 = data_ov031_0224ca00[index].unknown_4_;
                break;
            }
            index++;
            entry++;
        } while (index < 8);
    }
    SetIRQInterruptState(var1);
    return var2;
}

struct Struct_ov031_02200ccc {
    unsigned char destination[6];
    unsigned char source[6];
    unsigned short type;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned short unknown_12_;
    unsigned char unknown_14_;
    unsigned char unknown_15_;
    unsigned char sender[6];
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    unsigned char target[6];
    unsigned short unknown_26_;
    unsigned short unknown_28_;
};

#define Swap16_02200ccc(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_02200ccc
extern "C" ARM void func_ov031_02200ccc(unsigned int address) {
    Struct_ov031_02200ccc packet;
    VectorizedMemset(&packet, 0, 42);
    VectorizedMemset(packet.destination, 255, 6);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, packet.source, 6);
    packet.type = 0x0608;
    packet.unknown_f_ = 1;
    packet.unknown_10_ = 8;
    packet.unknown_12_ = 0x0406;
    packet.unknown_15_ = 1;
    VectorizedInvertedMemcpy(data_ov031_0224ce68, packet.sender, 6);
    unsigned short var1;
    unsigned short var2;
    unsigned int source = data_ov031_0224c9d0;
    unsigned short var4 = source >> 16;
    unsigned short var5 = source;
    var1 = address >> 16;
    var2 = address;
    packet.unknown_1c_ = Swap16_02200ccc(var4);
    packet.unknown_1e_ = Swap16_02200ccc(var5);
    packet.unknown_26_ = Swap16_02200ccc(var1);
    packet.unknown_28_ = Swap16_02200ccc(var2);
    func_ov031_02200850(&packet, 42, NULL, 0);
}

// USA: func_ov031_02200dc8
extern "C" ARM int func_ov031_02200dc8(int a) {
	unsigned int i = 0;
	do {
		func_ov031_02200ccc(a);
		unsigned int j = 0;
		do {
			if (data_ov031_0224c9d0 == 0) {
				return 0;
			}
			SleepCurrentContext(100);
			int r = (int)func_ov031_02200bfc(a);
			if (r != 0) {
				return r;
			}
			j++;
		} while (j < 20);
		i++;
	} while (i < 8);
	return 0;
}

struct Struct_ov031_02200e38 {
    unsigned int address;
    unsigned char unknown_4_[6];
    unsigned short unknown_a_;
};
extern "C" ARM void func_ov031_02200e38(const void* arg0, unsigned int address, int arg2) {
    if (address == 0x7f000001 || address == data_ov031_0224c9d0) return;
    if (!func_ov031_022006f0(address)) return;
    if (func_ov031_02200790(address)) return;
    unsigned short var0 = GetCurrentTimestamp() >> 16;
    {
    unsigned int i = 0;
    Struct_ov031_02200e38* entry = (Struct_ov031_02200e38*)data_ov031_0224ca00;
    do {
        if (address == entry->address) {
            data_ov031_0224ca00[i].unknown_a_ = var0;
            VectorizedInvertedMemcpy(arg0, data_ov031_0224ca00[i].unknown_4_, 6);
            return;
        }
        ++i;
        ++entry;
    } while (i < 8);
    }
    if (!arg2) return;
    unsigned int selected;
    unsigned short var4 = 0;
    selected = var4;
    Struct_ov031_02200e38* entry = (Struct_ov031_02200e38*)data_ov031_0224ca00;
    unsigned int i = 0;
    do {
        if (!entry->address) {
            selected = i;
            break;
        }
        unsigned int age = var0 - entry->unknown_a_;
        if (var4 < (short)age) {
            selected = i;
            var4 = age;
        }
        ++i;
        ++entry;
    } while (i < 8);
    data_ov031_0224ca00[selected].address = address;
    VectorizedInvertedMemcpy(arg0, data_ov031_0224ca00[selected].unknown_4_, 6);
    data_ov031_0224ca00[selected].unknown_a_ = var0;
}

// USA: func_ov031_02200f74
extern "C" ARM void func_ov031_02200f74(unsigned char* buf, unsigned int arg1, int arg2, int arg3, unsigned int arg4, unsigned short arg5) {
	unsigned short swapped = (unsigned short)((arg5 >> 8) | (arg5 << 8));
	*(unsigned short*)(buf - 2) = swapped;

	if (func_ov031_02200790(arg4) == 0) {
		int v = func_ov031_02200730((int)arg4);
		if (v == 0) return;
		int r = (int)func_ov031_02200bfc(v);
		if (r == 0) {
			r = func_ov031_02200dc8(v);
		}
		if (r == 0) return;
		VectorizedInvertedMemcpy((const void*)r, buf - 0xe, 6);
	} else {
		buf[-0xe] = 1;
		buf[-0xd] = 0;
		buf[-0xc] = 0x5e;
		buf[-0xb] = (arg4 >> 16) & 0x7f;
		buf[-0xa] = (unsigned char)(arg4 >> 8);
		buf[-9] = (unsigned char)arg4;
	}

	VectorizedInvertedMemcpy(data_ov031_0224ce68, buf - 8, 6);
	func_ov031_02200850(buf - 0xe, arg1 + 0xe, (void*)arg2, arg3);
}

struct Struct_ov031_02201044 {
    unsigned short format;
    unsigned short length;
    unsigned short flags;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned int source;
    unsigned int destination;
};
struct Struct_ov017_021d1118 {
    unsigned char prefix[8];
    Struct_ov031_02201044 header;
};

static inline int inline_ov031_02201044(int value) { return (value >> 8) | (value << 8); }

// USA: func_ov031_02201044
extern "C" ARM void func_ov031_02201044(unsigned char* payload, int headerLength, void* data, int arg3, unsigned int destination, int arg5) {
    unsigned short length = headerLength + 0x14 + arg3;
    ((Struct_ov031_02201044*)payload)[-1].length = inline_ov031_02201044(length);
    ((Struct_ov031_02201044*)payload)[-1].unknown_6_ = inline_ov031_02201044((unsigned short)arg5);
    ((Struct_ov031_02201044*)payload)[-1].unknown_a_ = 0;
    int var1 = func_ov031_02200684((Struct_ov031_02201044*)payload - 1, 0x14);
    ((Struct_ov031_02201044*)payload)[-1].unknown_a_ = inline_ov031_02201044(var1);
    if (destination != 0x7f000001 && destination != data_ov031_0224c9d0) {
        func_ov031_02200f74((unsigned char*)((Struct_ov031_02201044*)payload - 1), headerLength + 0x14, (int)data, arg3, destination, 0x800);
    }
    if (destination != 0x7f000001 && destination != data_ov031_0224c9d0) {
        if (!func_ov031_02200790(destination)) return;
    }
    VectorizedInvertedMemcpy(data_ov031_0224968c, ((Struct_ov017_021d1118*)payload)[-1].prefix, 8);
    int var2 = DisableIRQInterrupts();
    func_ov031_022008ac(data_ov031_0224ce68, data_ov031_0224ce68, (unsigned char*)((Struct_ov017_021d1118*)payload - 1), headerLength + 0x1c, data, arg3);
    SetIRQInterruptState(var2);
}

struct Struct_ov031_0220116c {
    unsigned char unknown_0_, unknown_1_;
    unsigned short length, unknown_4_, fragment;
    unsigned char unknown_8_, unknown_9_;
    unsigned short unknown_a_, unknown_c_, unknown_e_, unknown_10_, unknown_12_;
};

static inline unsigned short inline_ov031_0220116c(unsigned short value) {
    return (value >> 8) | (value << 8);
}
// USA: func_ov031_0220116c
extern "C" ARM void func_ov031_0220116c(unsigned char* payload, unsigned int length,
    const unsigned char* extra, unsigned int arg3, unsigned int destination,
    unsigned char arg5) {
    Struct_ov031_0220116c* var0 = (Struct_ov031_0220116c*)payload;
    var0[-1].unknown_0_ = 0x45;
    var0[-1].unknown_1_ = 0;
    data_ov031_0224c986++;
    var0[-1].unknown_4_ = inline_ov031_0220116c(data_ov031_0224c986);
    var0[-1].unknown_8_ = 0x80;
    var0[-1].unknown_9_ = arg5;
    unsigned short var1 = data_ov031_0224c9d0 >> 16;
    var0[-1].unknown_c_ = inline_ov031_0220116c(var1);
    unsigned short var2 = data_ov031_0224c9d0;
    var0[-1].unknown_e_ = inline_ov031_0220116c(var2);
    unsigned short var3 = destination >> 16;
    var0[-1].unknown_10_ = inline_ov031_0220116c(var3);
    unsigned short var4 = destination;
    var0[-1].unknown_12_ = inline_ov031_0220116c(var4);
    unsigned short fragment = 0;
    if (length > 0x5c8) {
        const unsigned char* cursor = payload;
        if (length > 0x5c8) do {
            func_ov031_02201044(payload, 0, (void*)cursor, 0x5c8, destination, fragment | 0x2000);
            cursor += 0x5c8;
            length -= 0x5c8;
            fragment += 0xb9;
        } while (length > 0x5c8);
        if (length != 0) {
            if (arg3 != 0)
                func_ov031_02201044(payload, 0, (void*)cursor, length, destination, fragment | 0x2000);
            else
                func_ov031_02201044(payload, 0, (void*)cursor, length, destination, fragment);
            fragment += length >> 3;
            length = 0;
        }
    }
    if (length + arg3 > 0x5c8) do {
        unsigned int count = 0x5c8 - length;
        func_ov031_02201044(payload, length, (void*)extra, count, destination, fragment | 0x2000);
        arg3 -= count;
        length = 0;
        extra += count;
        fragment += 0xb9;
    } while (arg3 > 0x5c8);
    if (length + arg3 == 0) return;
    func_ov031_02201044(payload, length, (void*)extra, arg3, destination, fragment);
}

struct Struct_ov031_02201364 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};
struct Struct_ov031_02201364_2 {
    unsigned char prefix[0x22];
    Struct_ov031_02201364 unknown_22_;
};
struct Struct_ov031_02201364_3 {
    unsigned char prefix[0xa];
    unsigned short unknown_a_;
    unsigned char unknown_c_[0x1c - 0xc];
    unsigned int destination;
    unsigned char unknown_20_[0x4c - 0x20];
    Struct_ov031_02201364_2* packet;
};

// USA: func_ov031_02201364
extern "C" ARM void func_ov031_02201364(unsigned char* payload, unsigned int length, Struct_ov031_02201364_3* arg2) {
    Struct_ov031_02201364_2* packet = arg2->packet;
    packet->unknown_22_.unknown_0_ = 8;
    packet->unknown_22_.unknown_4_ = (unsigned int)data_02111304.activeContext;
    packet->unknown_22_.unknown_2_ = 0;
    unsigned short var1 = inline_ov031_02201364();
    arg2->unknown_a_ = var1;
    packet->unknown_22_.unknown_6_ = var1;
    unsigned char* var2 = (unsigned char*)&packet->unknown_22_;
    unsigned int sum = func_ov031_022005b4(var2, 8, 0);
    sum = func_ov031_022005b4(payload, length, sum);
    int var4 = func_ov031_02200668((unsigned short)sum);
    int swapped = var4 << 8;
    packet->unknown_22_.unknown_2_ = (var4 >> 8) | swapped;
    func_ov031_0220116c(var2, 8, payload, length, arg2->destination, 1);
}

struct Struct_ov031_02201414 {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned char unknown_c_[0xc];
    unsigned short unknown_18_;
    unsigned char pad1a[2];
    unsigned int unknown_1c_;
    unsigned char pad20[0x2c];
    unsigned char* buffer;
};

#define SwapBytes16_02201414(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201414
extern "C" ARM void func_ov031_02201414(void* data, unsigned int length, Struct_ov031_02201414* arg2) {
    unsigned char* var0 = arg2->buffer + 0x22;
    int high = (unsigned short)(data_ov031_0224c9d0 >> 16);
    *(unsigned short*)(var0 - 0xc) = SwapBytes16_02201414(high);
    int low = (unsigned short)data_ov031_0224c9d0;
    *(unsigned short*)(var0 - 0xa) = SwapBytes16_02201414(low);
    high = (unsigned short)(arg2->unknown_1c_ >> 16);
    *(unsigned short*)(var0 - 0x8) = SwapBytes16_02201414(high);
    low = (unsigned short)arg2->unknown_1c_;
    *(unsigned short*)(var0 - 0x6) = SwapBytes16_02201414(low);
    *(unsigned short*)(var0 - 0x4) = 0x1100;
    unsigned short total = (unsigned short)(length + 8);
    *(unsigned short*)(var0 + 0x4) = SwapBytes16_02201414(total);
    *(unsigned short*)(var0 - 0x2) = *(unsigned short*)(var0 + 0x4);
    *(unsigned short*)(var0 + 0x2) = SwapBytes16_02201414(arg2->unknown_18_);
    *(unsigned short*)(var0 + 0x0) = SwapBytes16_02201414(arg2->unknown_a_);
    *(unsigned short*)(var0 + 0x6) = 0;
    unsigned int sum = func_ov031_022005b4(var0 - 0xc, 0x14, 0);
    sum = func_ov031_022005b4((unsigned char*)data, length, sum);
    int var5 = func_ov031_02200668((unsigned short)sum);
    *(unsigned short*)(var0 + 0x6) = SwapBytes16_02201414(var5);
    func_ov031_0220116c(var0, 8, (unsigned char*)data, length, arg2->unknown_1c_, 0x11);
}

extern unsigned char data_ov031_0224ce92[];

struct Struct_ov031_02201550 {
    unsigned char pad0[0x8];
    unsigned char state;
    unsigned char unknown_9_;
    unsigned short unknown_a_;
    unsigned char unknown_c_[0xc];
    unsigned short unknown_18_;
    unsigned char pad1a[2];
    unsigned int unknown_1c_;
    unsigned char pad20[4];
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    unsigned char pad2c[0x10];
    unsigned int unknown_3c_;
    unsigned char unknown_40_[4];
    unsigned int unknown_44_;
    unsigned char unknown_48_[4];
    unsigned char* buffer;
};

#define SwapBytes16_02201550(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201550
extern "C" ARM void func_ov031_02201550(unsigned char* data, unsigned int length, Struct_ov031_02201550* arg2, int flags, int opt) {
    unsigned char* var0;
    unsigned int headerLength;
    if (arg2->state == 0) return;
    if (data_02111304.activeContext == &data_ov031_0224cbe8) {
        var0 = data_ov031_0224ce92;
    } else {
        var0 = arg2->buffer + 0x22;
    }
    if (flags & 2) {
        headerLength = 0x18;
    } else {
        headerLength = 0x14;
    }
    unsigned short total = (unsigned short)(headerLength + length);
    int high = (unsigned short)(data_ov031_0224c9d0 >> 16);
    *(unsigned short*)(var0 - 0xc) = SwapBytes16_02201550(high);
    int low = (unsigned short)data_ov031_0224c9d0;
    *(unsigned short*)(var0 - 0xa) = SwapBytes16_02201550(low);
    high = (unsigned short)(arg2->unknown_1c_ >> 16);
    *(unsigned short*)(var0 - 0x8) = SwapBytes16_02201550(high);
    low = (unsigned short)arg2->unknown_1c_;
    *(unsigned short*)(var0 - 0x6) = SwapBytes16_02201550(low);
    *(unsigned short*)(var0 - 0x4) = 0x600;
    *(unsigned short*)(var0 - 0x2) = SwapBytes16_02201550(total);
    *(unsigned short*)(var0 + 0x0) = SwapBytes16_02201550(arg2->unknown_a_);
    *(unsigned short*)(var0 + 0x2) = SwapBytes16_02201550(arg2->unknown_18_);
    high = (unsigned short)(arg2->unknown_28_ >> 16);
    *(unsigned short*)(var0 + 0x4) = SwapBytes16_02201550(high);
    low = (unsigned short)arg2->unknown_28_;
    *(unsigned short*)(var0 + 0x6) = SwapBytes16_02201550(low);
    high = (unsigned short)(arg2->unknown_24_ >> 16);
    *(unsigned short*)(var0 + 0x8) = SwapBytes16_02201550(high);
    low = (unsigned short)arg2->unknown_24_;
    *(unsigned short*)(var0 + 0xa) = SwapBytes16_02201550(low);
    var0[0xc] = (headerLength >> 2) << 4;
    var0[0xd] = flags;
    unsigned short window = (unsigned short)(arg2->unknown_3c_ - arg2->unknown_44_);
    *(unsigned short*)(var0 + 0xe) = SwapBytes16_02201550(window);
    *(unsigned short*)(var0 + 0x10) = 0;
    *(unsigned short*)(var0 + 0x12) = 0;
    if (flags & 2) {
        high = (unsigned short)((0x02040000u + data_ov031_0224c982) >> 16);
        *(unsigned short*)(var0 + 0x14) = SwapBytes16_02201550(high);
        low = (unsigned short)(0x02040000u + data_ov031_0224c982);
        *(unsigned short*)(var0 + 0x16) = SwapBytes16_02201550(low);
    }
    unsigned int sum = func_ov031_022005b4(var0 - 0xc, headerLength + 0xc, 0);
    sum = func_ov031_022005b4(data, length, sum);
    int var7 = func_ov031_02200668((unsigned short)sum);
    *(unsigned short*)(var0 + 0x10) = SwapBytes16_02201550(var7);
    func_ov031_0220116c(var0, headerLength, data, length, arg2->unknown_1c_, 6);
    arg2->unknown_28_ += length;
    if (flags & 3) {
        arg2->unknown_28_++;
    }
}

// USA: func_ov031_022017c4
extern "C" ARM void func_ov031_022017c4(void* a) {
    char* obj = (char*)a;
    *(unsigned short*)(obj + 0x6) = 0x200;
    VectorizedInvertedMemcpy(obj + 0x8, obj + 0x12, 0xa);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, obj + 0x8, 6);

    unsigned int v = data_ov031_0224c9d0;
    unsigned short hi = (unsigned short)(v >> 16);
    hi = (unsigned short)((hi >> 8) | (hi << 8));
    *(unsigned short*)(obj + 0xe) = hi;

    unsigned int v2 = data_ov031_0224c9d0;
    unsigned short lo = (unsigned short)v2;
    lo = (unsigned short)((lo >> 8) | (lo << 8));
    *(unsigned short*)(obj + 0x10) = lo;

    VectorizedInvertedMemcpy(obj + 0x12, obj - 0xe, 6);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, obj - 0x8, 6);
    func_ov031_02200850(obj - 0xe, 0x2a, NULL, 0);
}

struct Struct_ov031_0220186c {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned char pad8[6];
    unsigned short fe;
    unsigned short f10;
    unsigned char pad12[6];
    unsigned short f18;
    unsigned short unknown_1a_;
};

#define SwapBytes16_0220186c(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_0220186c
extern "C" ARM void func_ov031_0220186c(Struct_ov031_0220186c* a, unsigned int b) {
    if (b < 0x1c) return;
    if (func_ov031_02200824((unsigned short*)a->pad8, (unsigned short*)data_ov031_0224ce68) == 0 ||
        data_ov031_0224c9d0 == 0) return;

    if (a->f0 != 0x100 || a->f2 != 8 || a->f4 != 0x406) return;

    unsigned short type = SwapBytes16_0220186c(a->unknown_6_);
    if (type != 1 && type != 2) return;

    unsigned int var1 = ((unsigned int)SwapBytes16_0220186c(a->fe) << 16) | SwapBytes16_0220186c(a->f10);
    unsigned int var2 = ((unsigned int)SwapBytes16_0220186c(a->f18) << 16) | SwapBytes16_0220186c(a->unknown_1a_);
    const unsigned int* var3 = &data_ov031_0224c9d0;
    int var4 = var1 == *var3;
    int var5 = *var3 == var2;

    if (!var4) func_ov031_02200e38(a->pad8, var1, var5);

    if (type == 1 && var5) {
        func_ov031_022017c4(a);
        return;
    }
    if (type != 2) return;
    if (var5 && var4) data_ov031_0224c981 = 1;
}

struct Struct_ov031_022019b0 { unsigned char pad0[0xc]; unsigned short f0c; unsigned short unknown_e_; };

#define SwapBytes16_022019b0(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_022019b0

extern "C" ARM void func_ov031_022019b0(Struct_ov031_022019b0* a0, void* a1, int a2) {
	unsigned int var0 = ((unsigned int)SwapBytes16_022019b0(a0->f0c) << 16) | SwapBytes16_022019b0(a0->unknown_e_);

	int r = func_ov031_02200730(var0);
	if (r == 0) return;

	if (func_ov031_02200bfc(r) == 0) {
		func_ov031_02200ccc(r);
		return;
	}

	*(unsigned char*)a1 = 0;
	*(unsigned short*)((char*)a1 + 2) = 0;
	int cs = (int)func_ov031_02200684(a1, a2);
	*(unsigned short*)((char*)a1 + 2) = (unsigned short)((cs >> 8) | (cs << 8));

	unsigned int var3 = ((unsigned int)SwapBytes16_022019b0(a0->f0c) << 16) | SwapBytes16_022019b0(a0->unknown_e_);

	func_ov031_0220116c((unsigned char*)a1, a2, (unsigned char*)0, 0, var3, 1);
}

struct Struct_ov031_02201a94 {
    unsigned char pad0[0xc];
    unsigned short f0c;
    unsigned short unknown_e_;
};

#define SwapBytes16_02201a94(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201a94
extern "C" ARM void func_ov031_02201a94(Struct_ov031_02201a94* a, void* b, void* c) {
    unsigned char* entry;
    int var1 = DisableIRQInterrupts();
    ProcessorContext* context = data_02111304.firstContext;
    if (context != NULL) {
        do {
            entry = (unsigned char*)context->unknown_A4;
            if (entry != NULL && *(unsigned int*)entry != 0 && entry[8] == 0xb &&
                *(unsigned short*)((unsigned char*)b + 4) == (unsigned short)*(unsigned int*)entry &&
                *(unsigned short*)(entry + 0xa) == *(unsigned short*)((unsigned char*)b + 6) &&
                *(unsigned int*)(entry + 0x44) == 0) {
                unsigned int seq = ((unsigned int)SwapBytes16_02201a94(a->f0c) << 16) | SwapBytes16_02201a94(a->unknown_e_);
                if (*(unsigned int*)(entry + 0x1c) == seq) {
                    unsigned int capacity = *(unsigned int*)(entry + 0x3c);
                    if ((unsigned int)c - 8 > capacity) {
                        *(unsigned int*)(entry + 0x44) = capacity;
                    } else {
                        *(unsigned int*)(entry + 0x44) = (unsigned int)c - 8;
                    }
                    VectorizedInvertedMemcpy((unsigned char*)b + 8, *(void**)(entry + 0x40), *(unsigned int*)(entry + 0x44));
                    if (*(unsigned int*)(entry + 4) == 3) {
                        *(unsigned int*)(entry + 4) = 0;
                        MarkContextReadyAndSwitch(*(ProcessorContext**)entry);
                    }
                    break;
                }
            }
            context = context->pNext;
        } while (context != NULL);
    }
    SetIRQInterruptState(var1);
}

// USA: func_ov031_02201b94
extern "C" ARM int func_ov031_02201b94(int a, int b) {
	return a != 0 && a != -1 && b != 0 && b != -1;
}

struct Struct_ov031_02201bb4 {
	char pad0[0xc];
	unsigned short unknown_c_;
	unsigned short unknown_e_;
	unsigned short unknown_10_;
	unsigned short unknown_12_;
};

#define SwapBytes16_02201bb4(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201bb4
extern "C" ARM void func_ov031_02201bb4(Struct_ov031_02201bb4* obj, void* type, void* len) {
	unsigned int var0 = func_ov031_02200684(type, (unsigned int)len);
	if (var0 != 0xffff) {
		return;
	}
	unsigned short a = obj->unknown_12_;
	unsigned short b = obj->unknown_10_;
	unsigned short c = obj->unknown_e_;
	unsigned short d = obj->unknown_c_;
	unsigned int seq = ((unsigned int)SwapBytes16_02201bb4(d) << 16) | SwapBytes16_02201bb4(c);
	unsigned int var6 = ((unsigned int)SwapBytes16_02201bb4(b) << 16) | SwapBytes16_02201bb4(a);
	if (!func_ov031_02201b94((int)seq, (int)var6)) {
		return;
	}
	unsigned char kind = *(unsigned char*)type;
	switch (kind) {
	case 0:
		func_ov031_02201a94((Struct_ov031_02201a94*)obj, type, len);
		return;
	case 8:
		func_ov031_022019b0((Struct_ov031_022019b0*)obj, type, (int)len);
		return;
	}
}

struct Struct_ov031_02201c84 {
	int unknown_0_;
	unsigned char pad0[0x8 - 4];
	unsigned char flag8;
	unsigned char pad1;
	unsigned short unknown_a_;
	unsigned char pad2[0x18 - 0xc];
	unsigned short f18;
	unsigned char pad3[0x1c - 0x1a];
	int f1c;
};

struct Struct_ov031_02201c84_2 {
	unsigned char pad0[0x68];
	Struct_ov031_02201c84_2* next;
	unsigned char pad1[0xa4 - 0x68 - 4];
	Struct_ov031_02201c84* field;
};

struct Struct_01ff8300 { unsigned char pad[0x8]; void* head; };

struct Struct_ov031_02201c84_3 { unsigned char pad0[0xc]; unsigned short f0c; unsigned short unknown_e_; };
struct Struct_ov031_02201c84_4 { unsigned short unknown_0_; unsigned short unknown_2_; };

// USA: func_ov031_02201c84
extern "C" ARM void* func_ov031_02201c84(Struct_ov031_02201c84_3* a, Struct_ov031_02201c84_4* b) {
	Struct_ov031_02201c84* field;
	Struct_ov031_02201c84_2* node = (Struct_ov031_02201c84_2*)data_02111304.firstContext;
	if (node) {
	do {
		field = node->field;
		if (field && field->unknown_0_ != 0) {
			if (field->flag8 == 1) {
				unsigned short v = b->unknown_2_;
				unsigned short var3 = (unsigned short)((v >> 8) | (v << 8));
				if (field->unknown_a_ == var3) {
					if (field->f18 != 0) {
						unsigned short v2 = b->unknown_0_;
						unsigned short var5 = (unsigned short)((v2 >> 8) | (v2 << 8));
						if (field->f18 != var5) goto next;
					}
					if (field->f1c != 0) {
						unsigned short var6 = a->unknown_e_;
						unsigned short vc = a->f0c;
						unsigned short var8 = (unsigned short)((vc >> 8) | (vc << 8));
						unsigned short var9 = (unsigned short)((var6 >> 8) | (var6 << 8));
						unsigned int var10 = ((unsigned int)var8 << 0x10) | var9;
						if (field->f1c != (int)var10) goto next;
					}
					return field;
				}
			}
		}
	next:
		node = node->next;
	} while (node);
	}
	return NULL;
}

// USA: func_ov031_02201d58
extern "C" ARM int func_ov031_02201d58(void* r0, unsigned short* r1, void* r2) {
	int result = 0;
	int flag1 = 0;
	int var2 = 0;
	int flag2 = 0;
	unsigned char type = *(unsigned char*)((char*)r2 + 0x8);
	if (type != 0xa && type != 0xb) flag1 = 1;
	if (flag1) {
		unsigned short v = r1[1];
		unsigned short target = *(unsigned short*)((char*)r2 + 0xa);
		if (target == (unsigned short)((v >> 8) | (v << 8))) flag2 = 1;
	}
	if (flag2) {
		unsigned short v2 = r1[0];
		unsigned short var8 = *(unsigned short*)((char*)r2 + 0x18);
		if (var8 == (unsigned short)((v2 >> 8) | (v2 << 8))) var2 = 1;
	}
	if (var2) {
		unsigned short lo = *(unsigned short*)((char*)r0 + 0xe);
		unsigned short hi = *(unsigned short*)((char*)r0 + 0xc);
		unsigned int var11 = *(unsigned int*)((char*)r2 + 0x1c);
		unsigned int var12 = ((unsigned int)(unsigned short)((hi >> 8) | (hi << 8)) << 16) | (unsigned short)((lo >> 8) | (lo << 8));
		if (var11 == var12) result = 1;
	}
	return result;
}

struct Struct_01ff8300_2 { unsigned char pad[0x8]; void* head; };
struct Struct_ov031_02201e0c { unsigned char pad0[0x68]; Struct_ov031_02201e0c* next; unsigned char pad1[0xa4-0x68-4]; void* field; };

// USA: func_ov031_02201e0c
extern "C" ARM void* func_ov031_02201e0c(void* a, void* b) {
    int* field;
    Struct_ov031_02201e0c* node = (Struct_ov031_02201e0c*)data_02111304.firstContext;
    if (node) {
        do {
            field = (int*)node->field;
            if (field && *field != 0) {
                if (func_ov031_02201d58(a, (unsigned short*)b, field) != 0) return field;
            }
            node = node->next;
        } while (node);
    }
    return NULL;
}

// USA: func_ov031_02201e70
extern "C" ARM void func_ov031_02201e70(void *source, void *destination) {
    unsigned char *bytes  = (unsigned char *)source;
    unsigned short *value = (unsigned short *)((unsigned char *)destination + 0x2e);
    *value                = 0x218;
    int length            = (bytes[0xc] & 0xf0) / 4 - 0x14;
    int remaining         = length - 1;
    unsigned char *cursor = bytes + 0x14;
    if (length == 0) {
        return;
    }
    do {
        int tag = *cursor++;
        switch (tag) {
            case 0: return;
            case 1: break;
            case 2:
                *value = (cursor[1] << 8) | cursor[2];
                cursor += 3;
                remaining -= 3;
                break;
            default:
                int var6 = *cursor - 1;
                remaining -= var6;
                cursor += var6;
                break;
        }
    } while (remaining-- != 0);
}

// USA: func_ov031_02201ef4
extern "C" ARM int func_ov031_02201ef4(Type_ov031_02201ef4 address) {
    Type_ov031_02201ef4 var0 = func_ov031_02200730(address);
    if (var0 == 0) return 1;
    return (int)func_ov031_02200bfc(var0);
}

struct Struct_ov031_02201f10 {
    char padding[0x1c];
    Type_ov031_02201ef4 unknown_1c_;
};

// USA: func_ov031_02201f10
extern "C" ARM void func_ov031_02201f10(Struct_ov031_02201f10* arg0, int type, int flags) {
    if (func_ov031_02201ef4(arg0->unknown_1c_) ||
        data_02111304.activeContext != &data_ov031_0224cbe8) {
        func_ov031_02201550((unsigned char*)0, 0, (Struct_ov031_02201550*)arg0, type, flags);
    } else {
        func_ov031_02200ccc(func_ov031_02200730(arg0->unknown_1c_));
    }
}

// USA: func_ov031_02201f84
extern "C" ARM void func_ov031_02201f84(int a, int b) {
	func_ov031_02201f10((Struct_ov031_02201f10*)a, 0x10, b);
}

// USA: func_ov031_02201f98
extern "C" ARM void func_ov031_02201f98(int a, int b) {
	func_ov031_02201f10((Struct_ov031_02201f10*)a, 0x11, b);
}

struct Struct_ov031_02201fac { unsigned char pad0[0xc]; unsigned short f0c; unsigned short unknown_e_; };
struct Struct_ov031_02201fac_2 { unsigned short f0; unsigned short f2; unsigned short f4; unsigned short unknown_6_; unsigned short f8; unsigned short fa; unsigned char pad0; unsigned char flags; };
struct Struct_ov031_02201fac_3 { unsigned char pad0[0x24]; unsigned int f24; unsigned int f28; };

#define SW16_02201fac(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201fac
extern "C" ARM void func_ov031_02201fac(Struct_ov031_02201fac* hdr, Struct_ov031_02201fac_2* src, unsigned int a, int b) {
	Struct_ov031_02201fac_3* dst = (Struct_ov031_02201fac_3*)&data_ov031_0224cac4;
	VectorizedMemset(dst, 0, 0x64);
	data_ov031_0224cac4.unknown_a_ = SW16_02201fac(src->f2);
	data_ov031_0224cac4.unknown_18_ = SW16_02201fac(src->f0);
	data_ov031_0224cac4.unknown_1c_ = ((unsigned int)SW16_02201fac(hdr->f0c) << 16) | SW16_02201fac(hdr->unknown_e_);
	if (src->flags & 0x10) {
		dst->f28 = ((unsigned int)SW16_02201fac(src->f8) << 16) | SW16_02201fac(src->fa);
		return func_ov031_02201f10((Struct_ov031_02201f10*)dst, 4, b);
	}
	dst->f28 = 0;
	unsigned int v = a + (((unsigned int)SW16_02201fac(src->f4) << 16) | SW16_02201fac(src->unknown_6_));
	dst->f24 = v;
	if (src->flags & 3) {
		dst->f24 = v + 1;
	}
	return func_ov031_02201f10((Struct_ov031_02201f10*)dst, 0x14, b);
}

struct Struct_ov031_022020e8 { unsigned char pad[0xc]; unsigned short f0c; unsigned short unknown_e_; unsigned short f10; unsigned short f12; };
struct Struct_ov031_022020e8_2 { unsigned short f0; unsigned char pad1[2]; unsigned short f4; unsigned short unknown_6_; };
struct Struct_ov031_022020e8_3 {
	unsigned char pad0[8];
	unsigned char f8;
	unsigned char pad1[0x10 - 0x8 - 1];
	unsigned int f10;
	unsigned int f14;
	unsigned short f18;
	unsigned char pad2[0x1c - 0x18 - 2];
	unsigned int f1c;
	unsigned char pad3[0x24 - 0x1c - 4];
	unsigned int f24;
};

#define SW16_022020e8(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_022020e8
extern "C" ARM void func_ov031_022020e8(Struct_ov031_022020e8* hdr, Struct_ov031_022020e8_2* src, Struct_ov031_022020e8_3* dst) {
	dst->f8 = 3;
	dst->f10 = (unsigned int)(GetCurrentTimestamp() >> 16);
	dst->f14 = ((unsigned int)SW16_022020e8(hdr->f10) << 16) | SW16_022020e8(hdr->f12);
	dst->f18 = SW16_022020e8(src->f0);
	dst->f1c = ((unsigned int)SW16_022020e8(hdr->f0c) << 16) | SW16_022020e8(hdr->unknown_e_);
	dst->f24 = (((unsigned int)SW16_022020e8(src->f4) << 16) | SW16_022020e8(src->unknown_6_)) + 1;
	func_ov031_02201e70(src, dst);
	func_ov031_02201f10((Struct_ov031_02201f10*)dst, 0x12, 0);
}

struct Struct_ov031_022021d4 {
    char padding[8];
    unsigned char kind;
    char unknown_9_[0x28 - 9];
    unsigned int counter;
};
struct Struct_ov031_022020e8;
struct Struct_ov031_022020e8_2;
struct Struct_ov031_022020e8_3;
struct Struct_ov031_02201fac;
struct Struct_ov031_02201fac_2;

// USA: func_ov031_022021d4
extern "C" ARM int func_ov031_022021d4(void* header, void* data, int length) {
    Struct_ov031_022021d4* node = (Struct_ov031_022021d4*)func_ov031_02201e0c(header, data);
    if (node != NULL) {
        if (node->kind == 1) {
            func_ov031_022020e8((Struct_ov031_022020e8*)header, (Struct_ov031_022020e8_2*)data, (Struct_ov031_022020e8_3*)node);
        } else if ((unsigned char)(node->kind + 0xfd) <= 1) {
            --node->counter;
            func_ov031_022020e8((Struct_ov031_022020e8*)header, (Struct_ov031_022020e8_2*)data, (Struct_ov031_022020e8_3*)node);
        } else {
            func_ov031_02201fac((Struct_ov031_02201fac*)header, (Struct_ov031_02201fac_2*)data, length, 0);
        }
        return 1;
    }
    return 0;
}

void CycleCurrentPriorityContexts(void);

struct Struct_ov031_0220225c { unsigned char pad0[0xc]; unsigned short fc; unsigned short fe; unsigned short f10; unsigned short f12; };

// USA: func_ov031_0220225c
extern "C" ARM void func_ov031_0220225c(Struct_ov031_0220225c* header, void* data, int length) {
	unsigned short var0 = header->f12;
	unsigned short v10 = header->f10;
	unsigned short var2 = header->fe;
	unsigned short vc = header->fc;
	unsigned short var4 = (unsigned short)((vc >> 8) | (vc << 8));
	unsigned short var5 = (unsigned short)((var2 >> 8) | (var2 << 8));
	unsigned short var6 = (unsigned short)((v10 >> 8) | (v10 << 8));
	unsigned short var7 = (unsigned short)((var0 >> 8) | (var0 << 8));
	int a = ((unsigned int)var4 << 0x10) | var5;
	int b = ((unsigned int)var6 << 0x10) | var7;

	if (!func_ov031_02201b94(a, b)) {
		return;
	}
	if (func_ov031_022021d4(header, data, length) != 0) {
		return;
	}
	void* field = func_ov031_02201c84((Struct_ov031_02201c84_3*)header, (Struct_ov031_02201c84_4*)data);
	if (field != NULL) {
		func_ov031_022020e8((Struct_ov031_022020e8*)header, (Struct_ov031_022020e8_2*)data, (Struct_ov031_022020e8_3*)field);
		return;
	}
	CycleCurrentPriorityContexts();
	field = func_ov031_02201c84((Struct_ov031_02201c84_3*)header, (Struct_ov031_02201c84_4*)data);
	if (field == NULL) {
		return;
	}
	func_ov031_022020e8((Struct_ov031_022020e8*)header, (Struct_ov031_022020e8_2*)data, (Struct_ov031_022020e8_3*)field);
}

struct Struct_ov031_02202334 {
    ProcessorContext* context;
    int pending;
    unsigned char state;
    char unknown_9_[0x1b];
    unsigned int unknown_24_;
    char pad28[4];
    unsigned short window;
    char unknown_2e_[2];
    unsigned int unknown_30_;
};
struct Struct_ov031_02202334_2 { unsigned short pad[2]; unsigned short unknown_4_; unsigned short unknown_6_; unsigned short unknown_8_; unsigned short unknown_a_; unsigned short fieldC; unsigned short window; };

#define Swap16_02202334(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_02202334
extern "C" ARM void func_ov031_02202334(void* obj, Struct_ov031_02202334_2* packet, int length) {
    Struct_ov031_02202334* var0 = (Struct_ov031_02202334*)func_ov031_02201e0c(obj, packet);
    if (!var0 || var0->state != 2) {
        func_ov031_02201fac((Struct_ov031_02201fac*)obj, (Struct_ov031_02201fac_2*)packet, length, 0);
        return;
    }
    CycleCurrentPriorityContexts();
    var0->unknown_24_ = (((unsigned int)Swap16_02202334(packet->unknown_4_) << 16) | Swap16_02202334(packet->unknown_6_)) + 1;
    var0->unknown_30_ = ((unsigned int)Swap16_02202334(packet->unknown_8_) << 16) | Swap16_02202334(packet->unknown_a_);
    var0->window = Swap16_02202334(packet->window);
    func_ov031_02201e70(packet, var0);
    func_ov031_02201f84((int)var0, 0);
    var0->state = 4;
    if (var0->pending == 1) {
        var0->pending = 0;
        MarkContextReadyAndSwitch(var0->context);
    }
}

struct Struct_ov031_0220242c {
    ProcessorContext* context;
    int pending;
    unsigned char state;
    unsigned char unknown_9_[0x1b];
    unsigned int unknown_24_;
    unsigned char padding28[4];
    unsigned short window;
    unsigned short unknown_2e_;
    unsigned int unknown_30_;
    unsigned int unknown_34_;
    unsigned char padding38[4];
    unsigned int unknown_3c_;
    unsigned char* receiveBuffer;
    unsigned int unknown_44_;
};

struct Struct_ov031_0220242c_2 {
    unsigned short unknown_0_[2];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char headerLength;
    unsigned char flags;
    unsigned short window;
};

#define Swap16_0220242c(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_0220242c
extern "C" ARM void func_ov031_0220242c(void* object, Struct_ov031_0220242c_2* packet, unsigned int length) {
    Struct_ov031_0220242c* var0 = (Struct_ov031_0220242c*)func_ov031_02201e0c(object, packet);
    if (!var0) {
        func_ov031_02201fac((Struct_ov031_02201fac*)object, (Struct_ov031_02201fac_2*)packet, length, 0);
        return;
    }
    unsigned int var1 = ((unsigned int)Swap16_0220242c(packet->unknown_8_) << 16) | Swap16_0220242c(packet->unknown_a_);
    unsigned char flags = packet->flags;
    if ((int)(var1 - var0->unknown_30_) > 0)
        var0->unknown_30_ = var1;
    unsigned int var3 = ((unsigned int)Swap16_0220242c(packet->unknown_4_) << 16) | Swap16_0220242c(packet->unknown_6_);
    if (var0->state == 4 && var0->unknown_24_ != var3) {
        func_ov031_02201f84((int)var0, 0);
        return;
    }
    var0->window = Swap16_0220242c(packet->window);
    switch (var0->state) {
    case 0:
    case 2:
        func_ov031_02201fac((Struct_ov031_02201fac*)object, (Struct_ov031_02201fac_2*)packet, length, 0);
        break;
    case 3:
        var0->state = 4;
        if (var0->pending == 1) {
            var0->pending = 0;
            MarkContextReadyAndSwitch(var0->context);
        }
        if (!length)
            break;
    case 4:
        ++var0->unknown_34_;
        unsigned int capacity = var0->unknown_3c_;
        unsigned int remaining = capacity - var0->unknown_44_;
        int var6;
        if (length > remaining) {
            var6 = 0;
            length = remaining;
        } else {
            var6 = 1;
        }
        if (length) {
            int var7 = DisableIRQInterrupts();
            int var8 = (packet->headerLength & 0xf0) / 4;
            VectorizedInvertedMemcpy((unsigned char*)packet + var8, var0->receiveBuffer + var0->unknown_44_, length);
            var0->unknown_44_ += length;
            var0->unknown_24_ += length;
            SetIRQInterruptState(var7);
            if (var0->pending == 2) {
                var0->pending = 0;
                MarkContextReadyAndSwitch(var0->context);
            }
        }
        if (var6 && (flags & 1)) {
            var0->state = 6;
            ++var0->unknown_24_;
            func_ov031_02201f98((int)var0, 0);
            if (!length && var0->pending == 2) {
                var0->pending = 0;
                MarkContextReadyAndSwitch(var0->context);
            }
        } else if (length) {
            func_ov031_02201f84((int)var0, 0);
        }
        break;
    case 7:
    case 8:
        if (flags & 1) {
            var0->unknown_24_ += length + 1;
            func_ov031_02201f84((int)var0, 0);
            var0->state = 0;
            if (var0->pending == 2) {
                var0->pending = 0;
                MarkContextReadyAndSwitch(var0->context);
            }
        } else {
            if (length) {
                var0->unknown_24_ += length;
                func_ov031_02201f84((int)var0, 0);
            }
            var0->state = 8;
        }
        break;
    case 6:
    case 9:
        var0->state = 0;
        if (var0->pending == 2) {
            var0->pending = 0;
            MarkContextReadyAndSwitch(var0->context);
        }
        break;
    default:
        if (flags & 1)
            ++var0->unknown_24_;
        func_ov031_02201f84((int)var0, 0);
        break;
    }
    CycleCurrentPriorityContexts();
}

struct Struct_ov031_02202744 {
	ProcessorContext* field0;
	int field4;
	unsigned char field8;
	unsigned char pad[0x24 - 0x9];
	int field24;
};

// USA: func_ov031_02202744
extern "C" ARM void func_ov031_02202744(int a, int b, int c) {
	Struct_ov031_02202744* node = (Struct_ov031_02202744*)func_ov031_02201e0c((void*)a, (void*)b);
	if (!node) return;
	switch (node->field8) {
	case 7:
		node->field24++;
		func_ov031_02201f84((int)node, 0);
		node->field8 = 9;
		return;
	case 8:
		node->field24++;
		func_ov031_02201f84((int)node, 0);
		node->field8 = 0;
		if (node->field4 != 2) return;
		node->field4 = 0;
		MarkContextReadyAndSwitch(node->field0);
		return;
	case 4:
		node->field24++;
		func_ov031_02201f98((int)node, 0);
		node->field8 = 6;
		return;
	default:
		func_ov031_02201fac((Struct_ov031_02201fac*)a, (Struct_ov031_02201fac_2*)b, c, 0);
		return;
	}
}

struct Struct_ov031_02202810 {
	ProcessorContext* field0;
	int field4;
	unsigned char field8;
};

// USA: func_ov031_02202810
extern "C" ARM int func_ov031_02202810(int a, int b) {
	Struct_ov031_02202810* p = (Struct_ov031_02202810*)func_ov031_02201e0c((void*)a, (void*)b);
	if (p == NULL) {
		return (int)p;
	}
	CycleCurrentPriorityContexts();
	p->field8 = 0;
	if ((unsigned int)(p->field4 - 1) > 1) {
		return p->field4 - 1;
	}
	p->field4 = 0;
	MarkContextReadyAndSwitch(p->field0);
}

struct Struct_ov031_0220225c;

struct Struct_ov031_0220284c { unsigned char pad[0xc]; unsigned char unknown_c_; unsigned char unknown_d_; };

// USA: func_ov031_0220284c
extern "C" ARM void func_ov031_0220284c(void* c, Struct_ov031_0220284c* buf, int len) {
    if (func_ov031_022006a0(buf, len, c, 6)) return;

    int v = buf->unknown_c_ & 0xf0;
    len -= v / 4;
    switch (buf->unknown_d_ & 0x17) {
    case 0x2:
        if (buf->unknown_d_ & 0x28) return;
        func_ov031_0220225c((Struct_ov031_0220225c*)c, buf, len);
        return;
    case 0x12:
        if (buf->unknown_d_ & 0x28) return;
        func_ov031_02202334(c, (Struct_ov031_02202334_2*)buf, len);
        return;
    case 0x10:
    case 0x11:
        func_ov031_0220242c(c, (Struct_ov031_0220242c_2*)buf, len);
        return;
    case 0x1:
        func_ov031_02202744((int)c, (int)buf, len);
        return;
    }
    if (buf->unknown_d_ & 0x4) {
        func_ov031_02202810((int)c, (int)buf);
    } else {
        func_ov031_02201fac((Struct_ov031_02201fac*)c, (Struct_ov031_02201fac_2*)buf, len, 0);
    }
}

struct Struct_ov031_0220296c {
    unsigned char pad0[0xc];
    unsigned short f0c;
    unsigned short unknown_e_;
    unsigned short f10;
    unsigned short f12;
};

typedef int (*Type_ov031_0220296c)(void*, unsigned int, void*);

#define SwapBytes16_0220296c(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_0220296c
extern "C" ARM void func_ov031_0220296c(Struct_ov031_0220296c* a, void* b, unsigned int c) {
    unsigned char* entry;
    if (*(unsigned short*)((unsigned char*)b + 6) != 0) {
        if (func_ov031_022006a0(b, c, a, 0x11)) return;
    }
    int var1 = DisableIRQInterrupts();
    ProcessorContext* context = data_02111304.firstContext;
    if (context != NULL) {
        do {
            entry = (unsigned char*)context->unknown_A4;
            if (entry != NULL && *(unsigned int*)entry != 0 && entry[8] == 0xa &&
                *(unsigned short*)(entry + 0xa) == SwapBytes16_0220296c(*(unsigned short*)((unsigned char*)b + 2)) &&
                (*(unsigned short*)(entry + 0x18) == 0 ||
                 *(unsigned short*)(entry + 0x18) == SwapBytes16_0220296c(*(unsigned short*)b)) &&
                (*(unsigned int*)(entry + 0x1c) == 0 || *(unsigned int*)(entry + 0x1c) == 0xffffffff ||
                 *(unsigned int*)(entry + 0x1c) == (((unsigned int)SwapBytes16_0220296c(a->f0c) << 16) | SwapBytes16_0220296c(a->unknown_e_)))) {
                *(unsigned int*)(entry + 0x14) = ((unsigned int)SwapBytes16_0220296c(a->f10) << 16) | SwapBytes16_0220296c(a->f12);
                if (*(unsigned int*)(entry + 0x1c) == 0) {
                    *(unsigned int*)(entry + 0x1c) = ((unsigned int)SwapBytes16_0220296c(a->f0c) << 16) | SwapBytes16_0220296c(a->unknown_e_);
                    *(unsigned short*)(entry + 0x18) = SwapBytes16_0220296c(*(unsigned short*)b);
                }
                if (*(unsigned int*)(entry + 0x44) == 0) {
                    unsigned int capacity = *(unsigned int*)(entry + 0x3c);
                    if (c - 8 > capacity) {
                        *(unsigned int*)(entry + 0x44) = capacity;
                    } else {
                        *(unsigned int*)(entry + 0x44) = c - 8;
                    }
                    VectorizedInvertedMemcpy((unsigned char*)b + 8, *(void**)(entry + 0x40), *(unsigned int*)(entry + 0x44));
                    if (*(unsigned int*)(entry + 4) == 3) {
                        *(unsigned int*)(entry + 4) = 0;
                        MarkContextReadyAndSwitch(*(ProcessorContext**)entry);
                    } else if (*(Type_ov031_0220296c*)(entry + 0x38) != NULL) {
                        if ((*(Type_ov031_0220296c*)(entry + 0x38))(*(void**)(entry + 0x40), *(unsigned int*)(entry + 0x44), entry) != 0) {
                            *(unsigned int*)(entry + 0x44) = 0;
                        }
                    }
                }
                break;
            }
            context = context->pNext;
        } while (context != NULL);
    }
    SetIRQInterruptState(var1);
}
