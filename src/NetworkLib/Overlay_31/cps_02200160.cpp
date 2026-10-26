#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Timing.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

typedef unsigned long CPSInAddr;

struct MATHRandContext32 {
    unsigned long long x;
    unsigned long long mul;
    unsigned long long add;
};

struct ArpEntry {
    unsigned int address;
    unsigned char hardware[6];
    unsigned short timestamp;
};

struct CpsSocket {
    unsigned char pad0[0xa];
    unsigned short localPort;
    unsigned char padc[0x18 - 0xc];
    unsigned short remotePort;
    unsigned char pad1a[2];
    unsigned int remoteAddress;
    unsigned char pad20[4];
    unsigned int ackNumber;
    unsigned int seqNumber;
    unsigned char pad2c[0x3c - 0x2c];
    int recvCapacity;
    void* recvBuffer;
    unsigned char pad44[4];
    int sendCapacity;
    void* sendBuffer;
    unsigned char pad50[0x64 - 0x50];
};

struct IpFragment {
    unsigned long source;
    unsigned short count;
    unsigned short identification;
    unsigned short totalBlocks;
    unsigned short totalLength;
    unsigned short starts[8];
    unsigned short ends[8];
    unsigned long timestamp;
    unsigned char* payload;
    unsigned char* allocation;
};

extern unsigned char data_ov031_0224968c[8];
extern unsigned char data_ov031_0224ce68[6];
extern unsigned char data_ov031_0224ced6[0x12c] __attribute__((aligned(2)));

unsigned char data_ov031_0224c980;
static unsigned char ip_conflict;
static unsigned short ipid;
static inline unsigned short NextPingSequence(void) {
    static unsigned short pingseq = 0;
    return pingseq++;
}
static unsigned short ephemeral_port;
static unsigned short mymss;
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
MATHRandContext32 data_ov031_0224c9e8;
ArpEntry data_ov031_0224ca00[8];
CpsSocket data_ov031_0224ca60;
CpsSocket data_ov031_0224cac4;
ProcessorContext data_ov031_0224cb28;
ProcessorContext data_ov031_0224cbe8;
IpFragment data_ov031_0224cca8[8];

struct PendingRequest {
    void* context;
    int type;
    unsigned char status;
};

void ZeroGlobalBuffer0224e3b8_ov031_0220ab78();

// USA: func_ov031_02200160
extern "C" ARM void func_ov031_02200160(int state) {
    int wasConfigured = data_ov031_0224c9d0 != 0;

    cps_state = state;
    data_ov031_0224c9d0 = 0;
    data_ov031_0224c99c = 0;
    data_ov031_0224c9ac = 0;
    data_ov031_0224c9e0[0] = 0;
    data_ov031_0224c9e0[1] = 0;
    dhcp_server = 0;
    if (!wasConfigured) {
        return;
    }

    VectorizedMemset(data_ov031_0224ca00, 0, 0x60);

    ProcessorContext* ctx = data_02111304.firstContext;
    if (ctx != NULL) {
        do {
            PendingRequest* p = (PendingRequest*)ctx->unknown_A4;
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
    IpFragment* fragment = data_ov031_0224cca8;
    do {
        if (fragment->count != 0) {
            data_ov031_0224c9c0(fragment->allocation);
            fragment->count = 0;
        }
        i++;
        fragment++;
    } while (i < 8);

    ZeroGlobalBuffer0224e3b8_ov031_0220ab78();
}

void CycleCurrentPriorityContexts();
void SleepCurrentContext(unsigned int);

// USA: func_ov031_02200264
ARM void DispatchContext02200264(void) {
    unsigned int v = yield_wait;
    if (v == 0) {
        CycleCurrentPriorityContexts();
    } else {
        SleepCurrentContext(v);
    }
}

// USA: func_ov031_0220028c  (semantic: EmptyStub_0220028c)
extern "C" ARM void func_ov031_0220028c(void) {
}

// USA: func_ov031_02200290  (semantic: AlwaysTrue_02200290)
extern "C" ARM int func_ov031_02200290() {
    return 1;
}

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef int BOOL;

typedef struct {
    u32 mode;
    void* (*alloc)(u32);
    void (*free)(void*);
    void (*dhcp_callback)(void);
    BOOL (*link_is_on)(void);
    unsigned long long random_seed;
    u8* lan_buf;
    u32 lan_buflen;
    u32 mymss;
    u32 requested_ip;
    u32 yield_wait;
} CPSConfig;

extern unsigned int data_ov031_02249680;
extern unsigned char data_ov031_0224e1c0[];
extern unsigned char data_ov031_0224d9c0[];
#define CPS_MIDDLEWARE ((const void*)0x02000c04)
extern "C" void OSi_ReferSymbol(const void*);

extern "C" void func_ov031_02203008(void);
extern "C" void func_ov031_02203c6c(void);
extern "C" void OS_GetMacAddress(void*);

static inline void MATH_InitRand32(MATHRandContext32* context, u64 seed) {
    context->x = seed;
    context->mul = (1566083941LL << 32) + 1812433253LL;
    context->add = 2531011;
}

static inline u32 MATH_Rand32(MATHRandContext32* context, u32 max) {
    context->x = context->mul * context->x + context->add;
    if (max == 0) {
        return (u32)(context->x >> 32);
    } else {
        return (u32)(((context->x >> 32) * max) >> 32);
    }
}

// USA: func_ov031_02200298
extern "C" ARM void func_ov031_02200298(CPSConfig* options) {
    OSi_ReferSymbol(CPS_MIDDLEWARE);
    u64 seed = options->random_seed;
    if (seed) {
        MATH_InitRand32(&data_ov031_0224c9e8, seed);
    } else {
        MATH_InitRand32(&data_ov031_0224c9e8, GetCurrentTimestamp());
    }
    if (options->alloc && options->free) {
        data_ov031_0224c994 = options->alloc;
        data_ov031_0224c9c0 = options->free;
    } else {
        data_ov031_0224c994 = (void* (*)(u32))func_ov031_0220028c;
        data_ov031_0224c9c0 = (void (*)(void*))func_ov031_0220028c;
    }
    cps_mode = options->mode;
    if (options->mymss) mymss = options->mymss;
    else mymss = 0x5b4;
    requested_ip = options->requested_ip;
    yield_wait = options->yield_wait;
    if (options->dhcp_callback) dhcp_callback = options->dhcp_callback;
    else dhcp_callback = func_ov031_0220028c;
    if (options->link_is_on) link_is_on = options->link_is_on;
    else link_is_on = func_ov031_02200290;
    lan_buf = options->lan_buf;
    lan_buflen = options->lan_buflen;
    recv_tail = 0;
    recv_head = 0;
    ephemeral_port = 0x400 + MATH_Rand32(&data_ov031_0224c9e8, 0xf88);
    OS_GetMacAddress(data_ov031_0224ce68);
    ip_conflict = 0;
    PopulateContext(&data_ov031_0224cbe8, (unsigned int)func_ov031_02203008, 0, (unsigned int)data_ov031_0224e1c0, 0x800, data_ov031_02249680);
    PopulateContext(&data_ov031_0224cb28, (unsigned int)func_ov031_02203c6c, 0, (unsigned int)data_ov031_0224d9c0, 0x800, data_ov031_02249680);
    MarkContextReadyAndSwitch(&data_ov031_0224cbe8);
    MarkContextReadyAndSwitch(&data_ov031_0224cb28);
}

bool IsContextInactive(ProcessorContext* context);

// USA: func_ov031_022004d4
ARM int MarkContextReadyIfInactive_022004d4(void) {
	int oldIRQ = DisableIRQInterrupts();
	int inactive = IsContextInactive(&data_ov031_0224cb28);
	if (inactive == 0) {
		if (calm_down == 0) {
			calm_down = 1;
			MarkContextReadyAndSwitch(&data_ov031_0224cb28);
		}
	}
	SetIRQInterruptState(oldIRQ);
	return inactive;
}

// USA: func_ov031_02200524
ARM void SetGlobal0224c980Field3c_02200524(int v) {
	scavenger = (void (*)(void))v;
}

// USA: func_ov031_02200534  (semantic: ShutdownAndResetContexts_02200534)
extern "C" ARM void func_ov031_02200534(void) {
    MarkContextReadyIfInactive_022004d4();
    AwaitContextCompletion(&data_ov031_0224cb28);
    ShutdownContext(&data_ov031_0224cbe8);
    recv_waiter = 0;
    func_ov031_02200160(0);
    lan_buf = 0;
    lan_buflen = 0;
}

extern unsigned int data_ov031_02249680;

// USA: func_ov031_0220057c
ARM void SetPriorityAndApplyToContexts_0220057c(unsigned int priority) {
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
		unsigned int t1 = (sum >> 8) & 0xff00ff;
		unsigned int t2 = (sum << 8) & 0xff00ff00;
		sum = t1 | t2;
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
ARM unsigned int NormalizeChecksum_02200668(unsigned int value) {
	unsigned short v = (unsigned short)(value ^ 0xffff);
	if (v == 0) {
		return 0xffff;
	}
	return v;
}

// USA: func_ov031_02200684
ARM unsigned int ComputeNormalizedChecksum_02200684(void* p, unsigned int len) {
	unsigned int sum = func_ov031_022005b4((unsigned char*)p, len, 0);
	return NormalizeChecksum_02200668((unsigned short)sum);
}

// USA: func_ov031_022006a0
ARM int IsChecksumValid_022006a0(void* a, unsigned int len, void* c, unsigned int seed) {
	unsigned int sum = func_ov031_022005b4((unsigned char*)a, len, seed);
	sum = func_ov031_022005b4((unsigned char*)((char*)c + 0xc), 8, sum);
	unsigned int v = sum + len;
	if (v & 0x10000) {
		v = (unsigned short)(v + 1);
	}
	return v != 0xffff;
}

// USA: func_ov031_022006f0
ARM int IsSpecialOrMaskMatch_022006f0(int a) {
	int result = 1;
	if (a != -1 && a != 0x7F000001) {
		unsigned int mask = data_ov031_0224c99c;
		if ((a & mask) != (data_ov031_0224c9d0 & mask)) result = 0;
	}
	return result;
}

// USA: func_ov031_02200730  (semantic: SelectFieldOrValue_02200730)
extern "C" ARM int func_ov031_02200730(int a) {
	int result = a;
	if (IsSpecialOrMaskMatch_022006f0(a) == 0) {
		result = data_ov031_0224c9ac;
	}
	return result;
}

// USA: func_ov031_02200754
ARM int IsMaskComplementSet_02200754(unsigned int a) {
	int result = 0;
	if (IsSpecialOrMaskMatch_022006f0(a) != 0) {
		unsigned int inv = ~data_ov031_0224c99c;
		if (inv == (inv & a)) {
			result = 1;
		}
	}
	return result;
}

// USA: func_ov031_02200790
ARM int IsHighNibbleE_02200790(unsigned int v) {
	return (v & 0xf0000000) == 0xe0000000;
}

// USA: func_ov031_022007a4  (semantic: IsIdAllowed_022007a4)
extern "C" ARM int func_ov031_022007a4(int id) {
	int cur = data_ov031_0224c9d0;
	int allowed = 1;
	int stageB = 1;
	int stageA = 1;
	int fieldOk = 1;
	if (cur != 0 && id != cur) fieldOk = 0;
	if (!fieldOk) {
		if (id != 0x7f000001) stageA = 0;
	}
	if (!stageA) {
		if (IsMaskComplementSet_02200754(id) == 0) stageB = 0;
	}
	if (!stageB) {
		if (IsHighNibbleE_02200790(id) == 0) allowed = 0;
	}
	return allowed;
}

// USA: func_ov031_02200824
ARM int CompareThreeU16sDiffer02200824(unsigned short* a, unsigned short* b) {
	int i = 0;
	do {
		if (*a++ != *b++) return 1;
		i++;
	} while (i < 3);
	return 0;
}

extern "C" int func_ov031_0220f104(void* a, void* b, unsigned int c, void* d, unsigned int e);

// USA: func_ov031_02200850
ARM void CopyHeaderAndDispatch_02200850(void* a, unsigned int b, void* c, unsigned int d) {
	VectorizedInvertedMemcpy(data_ov031_0224968c, (char*)a + 6, 6);
	int result = func_ov031_0220f104(a, (char*)a + 6, b - 6, c, d);
	data_ov031_0224c980 = result < 0;
}

// USA: func_ov031_022008ac
extern "C" ARM void func_ov031_022008ac(void* dstAddr, void* srcAddr, unsigned char* frame, unsigned int len, void* extra, unsigned int extraLen) {
	if (lan_buf == NULL || lan_buflen == 0) {
		return;
	}
	unsigned int total = len + extraLen;
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
	VectorizedInvertedMemcpy(srcAddr, lan_buf + recv_head + 2, 6);
	VectorizedInvertedMemcpy(dstAddr, lan_buf + recv_head + 8, 6);
	VectorizedInvertedMemcpy(frame + 6, lan_buf + recv_head + 0xe, len - 6);
	if (extra != NULL && extraLen != 0) {
		VectorizedInvertedMemcpy(extra, lan_buf + recv_head + 8 + len, extraLen);
	}
	recv_head = next;
}

bool IsContextInactive(ProcessorContext* context);
void MarkContextReadyAndSwitch(ProcessorContext* context);

// USA: func_ov031_02200aa0  (semantic: CheckAndReadyContext_02200aa0)
extern "C" ARM void func_ov031_02200aa0(void* a, int b, void* c, void* d) {
	func_ov031_022008ac(a, (void*)b, (unsigned char*)c, (unsigned int)d, (void*)0, 0);
	if (recv_waiter == NULL) return;
	if (IsContextInactive(recv_waiter)) return;
	MarkContextReadyAndSwitch(recv_waiter);
}

// USA: func_ov031_02200af8  (semantic: DequeueOrBlockUntilAvailable_02200af8)  (semantic: DequeueOrBlockUntilAvailable_02200af8)
extern "C" ARM void* func_ov031_02200af8(unsigned int* outLen) {
	int oldIRQ = DisableIRQInterrupts();
	if (recv_tail == recv_head) {
		do {
			recv_waiter = data_02111304.activeContext;
			BlockCurrentContext(NULL);
			recv_waiter = 0;
		} while (recv_tail == recv_head);
	}
	SetIRQInterruptState(oldIRQ);

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
ARM void AdvanceAndClampField30_02200bb8(void) {
	int oldIRQ = DisableIRQInterrupts();
	recv_tail = recv_tail +
		*(unsigned short*)(lan_buf + recv_tail);
	if (recv_tail >= lan_buflen) {
		recv_tail = 0;
	}
	SetIRQInterruptState(oldIRQ);
}

struct AddressEntry02200bfc { unsigned int address; unsigned char hardware[6]; unsigned short timestamp; };
extern unsigned char data_ov031_02249684[6];

// USA: func_ov031_02200bfc
extern "C" ARM unsigned char* func_ov031_02200bfc(unsigned int address) {
    unsigned int index;
    int irqState = DisableIRQInterrupts();
    unsigned char* hardware = NULL;
    if (address == 0x7f000001 || address == data_ov031_0224c9d0) hardware = data_ov031_0224ce68;
    else if (IsMaskComplementSet_02200754(address) || IsHighNibbleE_02200790(address)) hardware = data_ov031_02249684;
    else {
        AddressEntry02200bfc* entry = (AddressEntry02200bfc*)data_ov031_0224ca00;
        index = 0;
        do {
            if (address == entry->address) {
                unsigned int time = GetCurrentTimestamp() >> 16;
                data_ov031_0224ca00[index].timestamp = time;
                hardware = data_ov031_0224ca00[index].hardware;
                break;
            }
            index++;
            entry++;
        } while (index < 8);
    }
    SetIRQInterruptState(irqState);
    return hardware;
}

struct AddressPacket02200ccc {
    unsigned char destination[6];
    unsigned char source[6];
    unsigned short type;
    unsigned char hardwareHigh;
    unsigned char hardwareLow;
    unsigned char protocolHigh;
    unsigned char protocolLow;
    unsigned short lengths;
    unsigned char operationHigh;
    unsigned char operationLow;
    unsigned char sender[6];
    unsigned short senderHigh;
    unsigned short senderLow;
    unsigned char target[6];
    unsigned short targetHigh;
    unsigned short targetLow;
};

#define Swap16_02200ccc(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_02200ccc
extern "C" ARM void func_ov031_02200ccc(unsigned int address) {
    AddressPacket02200ccc packet;
    VectorizedMemset(&packet, 0, 42);
    VectorizedMemset(packet.destination, 255, 6);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, packet.source, 6);
    packet.type = 0x0608;
    packet.hardwareLow = 1;
    packet.protocolHigh = 8;
    packet.lengths = 0x0406;
    packet.operationLow = 1;
    VectorizedInvertedMemcpy(data_ov031_0224ce68, packet.sender, 6);
    unsigned short targetHigh;
    unsigned short targetLow;
    unsigned int source = data_ov031_0224c9d0;
    unsigned short sourceHigh = source >> 16;
    unsigned short sourceLow = source;
    targetHigh = address >> 16;
    targetLow = address;
    packet.senderHigh = Swap16_02200ccc(sourceHigh);
    packet.senderLow = Swap16_02200ccc(sourceLow);
    packet.targetHigh = Swap16_02200ccc(targetHigh);
    packet.targetLow = Swap16_02200ccc(targetLow);
    CopyHeaderAndDispatch_02200850(&packet, 42, NULL, 0);
}

// USA: func_ov031_02200dc8
ARM int LoopSleepAndCheck_02200dc8(int a) {
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

struct Overlay31AddressEntry {
    unsigned int address;
    unsigned char identifier[6];
    unsigned short timestamp;
};
extern "C" ARM void func_ov031_02200e38(const void* identifier, unsigned int address, int allowInsert) {
    if (address == 0x7f000001 || address == data_ov031_0224c9d0) return;
    if (!IsSpecialOrMaskMatch_022006f0(address)) return;
    if (IsHighNibbleE_02200790(address)) return;
    unsigned short timestamp = GetCurrentTimestamp() >> 16;
    {
    unsigned int i = 0;
    Overlay31AddressEntry* entry = (Overlay31AddressEntry*)data_ov031_0224ca00;
    do {
        if (address == entry->address) {
            data_ov031_0224ca00[i].timestamp = timestamp;
            VectorizedInvertedMemcpy(identifier, data_ov031_0224ca00[i].hardware, 6);
            return;
        }
        ++i;
        ++entry;
    } while (i < 8);
    }
    if (!allowInsert) return;
    unsigned int selected;
    unsigned short oldestAge = 0;
    selected = oldestAge;
    Overlay31AddressEntry* entry = (Overlay31AddressEntry*)data_ov031_0224ca00;
    unsigned int i = 0;
    do {
        if (!entry->address) {
            selected = i;
            break;
        }
        unsigned int age = timestamp - entry->timestamp;
        if (oldestAge < (short)age) {
            selected = i;
            oldestAge = age;
        }
        ++i;
        ++entry;
    } while (i < 8);
    data_ov031_0224ca00[selected].address = address;
    VectorizedInvertedMemcpy(identifier, data_ov031_0224ca00[selected].hardware, 6);
    data_ov031_0224ca00[selected].timestamp = timestamp;
}

// USA: func_ov031_02200f74  (semantic: BuildAndSendPacket_02200f74)
extern "C" ARM void func_ov031_02200f74(unsigned char* buf, unsigned int totalLen, int arg2, int arg3, unsigned int arg4, unsigned short arg5) {
	unsigned short swapped = (unsigned short)((arg5 >> 8) | (arg5 << 8));
	*(unsigned short*)(buf - 2) = swapped;

	if (IsHighNibbleE_02200790(arg4) == 0) {
		int v = func_ov031_02200730((int)arg4);
		if (v == 0) return;
		int r = (int)func_ov031_02200bfc(v);
		if (r == 0) {
			r = LoopSleepAndCheck_02200dc8(v);
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
	CopyHeaderAndDispatch_02200850(buf - 0xe, totalLen + 0xe, (void*)arg2, arg3);
}

struct PacketHeader {
    unsigned short format;
    unsigned short length;
    unsigned short flags;
    unsigned short identifier;
    unsigned short protocol;
    unsigned short checksum;
    unsigned int source;
    unsigned int destination;
};
struct Packet {
    unsigned char prefix[8];
    PacketHeader header;
};

static inline int SwapHalfword(int value) { return (value >> 8) | (value << 8); }

// USA: func_ov031_02201044
extern "C" ARM void func_ov031_02201044(unsigned char* payload, int headerLength, void* data, int dataLength, unsigned int destination, int identifier) {
    unsigned short length = headerLength + 0x14 + dataLength;
    ((PacketHeader*)payload)[-1].length = SwapHalfword(length);
    ((PacketHeader*)payload)[-1].identifier = SwapHalfword((unsigned short)identifier);
    ((PacketHeader*)payload)[-1].checksum = 0;
    int checksum = ComputeNormalizedChecksum_02200684((PacketHeader*)payload - 1, 0x14);
    ((PacketHeader*)payload)[-1].checksum = SwapHalfword(checksum);
    if (destination != 0x7f000001 && destination != data_ov031_0224c9d0) {
        func_ov031_02200f74((unsigned char*)((PacketHeader*)payload - 1), headerLength + 0x14, (int)data, dataLength, destination, 0x800);
    }
    if (destination != 0x7f000001 && destination != data_ov031_0224c9d0) {
        if (!IsHighNibbleE_02200790(destination)) return;
    }
    VectorizedInvertedMemcpy(data_ov031_0224968c, ((Packet*)payload)[-1].prefix, 8);
    int irqState = DisableIRQInterrupts();
    func_ov031_022008ac(data_ov031_0224ce68, data_ov031_0224ce68, (unsigned char*)((Packet*)payload - 1), headerLength + 0x1c, data, dataLength);
    SetIRQInterruptState(irqState);
}

struct InternetHeader0220116c {
    unsigned char version, service;
    unsigned short length, identification, fragment;
    unsigned char ttl, protocol;
    unsigned short checksum, sourceHigh, sourceLow, destinationHigh, destinationLow;
};

static inline unsigned short Swap16_0220116c(unsigned short value) {
    return (value >> 8) | (value << 8);
}
// USA: func_ov031_0220116c
extern "C" ARM void func_ov031_0220116c(unsigned char* payload, unsigned int length,
    const unsigned char* extra, unsigned int extraLength, unsigned int destination,
    unsigned char protocol) {
    InternetHeader0220116c* headerEnd = (InternetHeader0220116c*)payload;
    headerEnd[-1].version = 0x45;
    headerEnd[-1].service = 0;
    ipid++;
    headerEnd[-1].identification = Swap16_0220116c(ipid);
    headerEnd[-1].ttl = 0x80;
    headerEnd[-1].protocol = protocol;
    unsigned short sourceHigh = data_ov031_0224c9d0 >> 16;
    headerEnd[-1].sourceHigh = Swap16_0220116c(sourceHigh);
    unsigned short sourceLow = data_ov031_0224c9d0;
    headerEnd[-1].sourceLow = Swap16_0220116c(sourceLow);
    unsigned short destinationHigh = destination >> 16;
    headerEnd[-1].destinationHigh = Swap16_0220116c(destinationHigh);
    unsigned short destinationLow = destination;
    headerEnd[-1].destinationLow = Swap16_0220116c(destinationLow);
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
            if (extraLength != 0)
                func_ov031_02201044(payload, 0, (void*)cursor, length, destination, fragment | 0x2000);
            else
                func_ov031_02201044(payload, 0, (void*)cursor, length, destination, fragment);
            fragment += length >> 3;
            length = 0;
        }
    }
    if (length + extraLength > 0x5c8) do {
        unsigned int count = 0x5c8 - length;
        func_ov031_02201044(payload, length, (void*)extra, count, destination, fragment | 0x2000);
        extraLength -= count;
        length = 0;
        extra += count;
        fragment += 0xb9;
    } while (extraLength > 0x5c8);
    if (length + extraLength == 0) return;
    func_ov031_02201044(payload, length, (void*)extra, extraLength, destination, fragment);
}

struct EchoHeader02201364 {
    unsigned short typeAndCode;
    unsigned short checksum;
    unsigned short identifier;
    unsigned short sequence;
};
struct EchoPacket02201364 {
    unsigned char prefix[0x22];
    EchoHeader02201364 echo;
};
struct EchoSocket02201364 {
    unsigned char prefix[0xa];
    unsigned short localPort;
    unsigned char paddingC[0x1c - 0xc];
    unsigned int destination;
    unsigned char padding20[0x4c - 0x20];
    EchoPacket02201364* packet;
};

// USA: func_ov031_02201364
extern "C" ARM void func_ov031_02201364(unsigned char* payload, unsigned int length, EchoSocket02201364* socket) {
    EchoPacket02201364* packet = socket->packet;
    packet->echo.typeAndCode = 8;
    packet->echo.identifier = (unsigned int)data_02111304.activeContext;
    packet->echo.checksum = 0;
    unsigned short sequence = NextPingSequence();
    socket->localPort = sequence;
    packet->echo.sequence = sequence;
    unsigned char* headerBytes = (unsigned char*)&packet->echo;
    unsigned int sum = func_ov031_022005b4(headerBytes, 8, 0);
    sum = func_ov031_022005b4(payload, length, sum);
    int checksum = NormalizeChecksum_02200668((unsigned short)sum);
    int swapped = checksum << 8;
    packet->echo.checksum = (checksum >> 8) | swapped;
    func_ov031_0220116c(headerBytes, 8, payload, length, socket->destination, 1);
}

struct Socket02201414 {
    unsigned char pad0[0xa];
    unsigned short localPort;
    unsigned char padc[0xc];
    unsigned short remotePort;
    unsigned char pad1a[2];
    unsigned int remoteAddress;
    unsigned char pad20[0x2c];
    unsigned char* buffer;
};

#define SwapBytes16_02201414(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201414
extern "C" ARM void func_ov031_02201414(void* data, unsigned int length, Socket02201414* socket) {
    unsigned char* udp = socket->buffer + 0x22;
    int high = (unsigned short)(data_ov031_0224c9d0 >> 16);
    *(unsigned short*)(udp - 0xc) = SwapBytes16_02201414(high);
    int low = (unsigned short)data_ov031_0224c9d0;
    *(unsigned short*)(udp - 0xa) = SwapBytes16_02201414(low);
    high = (unsigned short)(socket->remoteAddress >> 16);
    *(unsigned short*)(udp - 0x8) = SwapBytes16_02201414(high);
    low = (unsigned short)socket->remoteAddress;
    *(unsigned short*)(udp - 0x6) = SwapBytes16_02201414(low);
    *(unsigned short*)(udp - 0x4) = 0x1100;
    unsigned short total = (unsigned short)(length + 8);
    *(unsigned short*)(udp + 0x4) = SwapBytes16_02201414(total);
    *(unsigned short*)(udp - 0x2) = *(unsigned short*)(udp + 0x4);
    *(unsigned short*)(udp + 0x2) = SwapBytes16_02201414(socket->remotePort);
    *(unsigned short*)(udp + 0x0) = SwapBytes16_02201414(socket->localPort);
    *(unsigned short*)(udp + 0x6) = 0;
    unsigned int sum = func_ov031_022005b4(udp - 0xc, 0x14, 0);
    sum = func_ov031_022005b4((unsigned char*)data, length, sum);
    int checksum = NormalizeChecksum_02200668((unsigned short)sum);
    *(unsigned short*)(udp + 0x6) = SwapBytes16_02201414(checksum);
    func_ov031_0220116c(udp, 8, (unsigned char*)data, length, socket->remoteAddress, 0x11);
}

extern unsigned char data_ov031_0224ce92[];

struct Socket02201550 {
    unsigned char pad0[0x8];
    unsigned char state;
    unsigned char pad9;
    unsigned short localPort;
    unsigned char padc[0xc];
    unsigned short remotePort;
    unsigned char pad1a[2];
    unsigned int remoteAddress;
    unsigned char pad20[4];
    unsigned int ackNumber;
    unsigned int seqNumber;
    unsigned char pad2c[0x10];
    unsigned int windowLimit;
    unsigned char pad40[4];
    unsigned int windowUsed;
    unsigned char pad48[4];
    unsigned char* buffer;
};

#define SwapBytes16_02201550(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201550
extern "C" ARM void func_ov031_02201550(unsigned char* data, unsigned int length, Socket02201550* socket, int flags, int opt) {
    unsigned char* tcp;
    unsigned int headerLength;
    if (socket->state == 0) return;
    if (data_02111304.activeContext == &data_ov031_0224cbe8) {
        tcp = data_ov031_0224ce92;
    } else {
        tcp = socket->buffer + 0x22;
    }
    if (flags & 2) {
        headerLength = 0x18;
    } else {
        headerLength = 0x14;
    }
    unsigned short total = (unsigned short)(headerLength + length);
    int high = (unsigned short)(data_ov031_0224c9d0 >> 16);
    *(unsigned short*)(tcp - 0xc) = SwapBytes16_02201550(high);
    int low = (unsigned short)data_ov031_0224c9d0;
    *(unsigned short*)(tcp - 0xa) = SwapBytes16_02201550(low);
    high = (unsigned short)(socket->remoteAddress >> 16);
    *(unsigned short*)(tcp - 0x8) = SwapBytes16_02201550(high);
    low = (unsigned short)socket->remoteAddress;
    *(unsigned short*)(tcp - 0x6) = SwapBytes16_02201550(low);
    *(unsigned short*)(tcp - 0x4) = 0x600;
    *(unsigned short*)(tcp - 0x2) = SwapBytes16_02201550(total);
    *(unsigned short*)(tcp + 0x0) = SwapBytes16_02201550(socket->localPort);
    *(unsigned short*)(tcp + 0x2) = SwapBytes16_02201550(socket->remotePort);
    high = (unsigned short)(socket->seqNumber >> 16);
    *(unsigned short*)(tcp + 0x4) = SwapBytes16_02201550(high);
    low = (unsigned short)socket->seqNumber;
    *(unsigned short*)(tcp + 0x6) = SwapBytes16_02201550(low);
    high = (unsigned short)(socket->ackNumber >> 16);
    *(unsigned short*)(tcp + 0x8) = SwapBytes16_02201550(high);
    low = (unsigned short)socket->ackNumber;
    *(unsigned short*)(tcp + 0xa) = SwapBytes16_02201550(low);
    tcp[0xc] = (headerLength >> 2) << 4;
    tcp[0xd] = flags;
    unsigned short window = (unsigned short)(socket->windowLimit - socket->windowUsed);
    *(unsigned short*)(tcp + 0xe) = SwapBytes16_02201550(window);
    *(unsigned short*)(tcp + 0x10) = 0;
    *(unsigned short*)(tcp + 0x12) = 0;
    if (flags & 2) {
        high = (unsigned short)((0x02040000u + mymss) >> 16);
        *(unsigned short*)(tcp + 0x14) = SwapBytes16_02201550(high);
        low = (unsigned short)(0x02040000u + mymss);
        *(unsigned short*)(tcp + 0x16) = SwapBytes16_02201550(low);
    }
    unsigned int sum = func_ov031_022005b4(tcp - 0xc, headerLength + 0xc, 0);
    sum = func_ov031_022005b4(data, length, sum);
    int checksum = NormalizeChecksum_02200668((unsigned short)sum);
    *(unsigned short*)(tcp + 0x10) = SwapBytes16_02201550(checksum);
    func_ov031_0220116c(tcp, headerLength, data, length, socket->remoteAddress, 6);
    socket->seqNumber += length;
    if (flags & 3) {
        socket->seqNumber++;
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
    CopyHeaderAndDispatch_02200850(obj - 0xe, 0x2a, NULL, 0);
}

struct Struct0220186c {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
    unsigned char pad8[6];
    unsigned short fe;
    unsigned short f10;
    unsigned char pad12[6];
    unsigned short f18;
    unsigned short f1a;
};

#define SwapBytes16_0220186c(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_0220186c
extern "C" ARM void func_ov031_0220186c(Struct0220186c* a, unsigned int b) {
    if (b < 0x1c) return;
    if (CompareThreeU16sDiffer02200824((unsigned short*)a->pad8, (unsigned short*)data_ov031_0224ce68) == 0 ||
        data_ov031_0224c9d0 == 0) return;

    if (a->f0 != 0x100 || a->f2 != 8 || a->f4 != 0x406) return;

    unsigned short type = SwapBytes16_0220186c(a->f6);
    if (type != 1 && type != 2) return;

    unsigned int combined = ((unsigned int)SwapBytes16_0220186c(a->fe) << 16) | SwapBytes16_0220186c(a->f10);
    unsigned int combined2 = ((unsigned int)SwapBytes16_0220186c(a->f18) << 16) | SwapBytes16_0220186c(a->f1a);
    const unsigned int* myIp = &data_ov031_0224c9d0;
    int match1 = combined == *myIp;
    int match2 = *myIp == combined2;

    if (!match1) func_ov031_02200e38(a->pad8, combined, match2);

    if (type == 1 && match2) {
        func_ov031_022017c4(a);
        return;
    }
    if (type != 2) return;
    if (match2 && match1) ip_conflict = 1;
}

struct Struct022019b0 { unsigned char pad0[0xc]; unsigned short f0c; unsigned short f0e; };

#define SwapBytes16_022019b0(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_022019b0  (semantic: HandlePacketType8_022019b0)

extern "C" ARM void func_ov031_022019b0(Struct022019b0* a0, void* a1, int a2) {
	unsigned int combined = ((unsigned int)SwapBytes16_022019b0(a0->f0c) << 16) | SwapBytes16_022019b0(a0->f0e);

	int r = func_ov031_02200730(combined);
	if (r == 0) return;

	if (func_ov031_02200bfc(r) == 0) {
		func_ov031_02200ccc(r);
		return;
	}

	*(unsigned char*)a1 = 0;
	*(unsigned short*)((char*)a1 + 2) = 0;
	int cs = (int)ComputeNormalizedChecksum_02200684(a1, a2);
	*(unsigned short*)((char*)a1 + 2) = (unsigned short)((cs >> 8) | (cs << 8));

	unsigned int combined2 = ((unsigned int)SwapBytes16_022019b0(a0->f0c) << 16) | SwapBytes16_022019b0(a0->f0e);

	func_ov031_0220116c((unsigned char*)a1, a2, (unsigned char*)0, 0, combined2, 1);
}

struct Header02201a94 {
    unsigned char pad0[0xc];
    unsigned short f0c;
    unsigned short f0e;
};

#define SwapBytes16_02201a94(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201a94
extern "C" ARM void func_ov031_02201a94(Header02201a94* a, void* b, void* c) {
    unsigned char* entry;
    int priorState = DisableIRQInterrupts();
    ProcessorContext* context = data_02111304.firstContext;
    if (context != NULL) {
        do {
            entry = (unsigned char*)context->unknown_A4;
            if (entry != NULL && *(unsigned int*)entry != 0 && entry[8] == 0xb &&
                *(unsigned short*)((unsigned char*)b + 4) == (unsigned short)*(unsigned int*)entry &&
                *(unsigned short*)(entry + 0xa) == *(unsigned short*)((unsigned char*)b + 6) &&
                *(unsigned int*)(entry + 0x44) == 0) {
                unsigned int seq = ((unsigned int)SwapBytes16_02201a94(a->f0c) << 16) | SwapBytes16_02201a94(a->f0e);
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
    SetIRQInterruptState(priorState);
}

// USA: func_ov031_02201b94
ARM int IsNonzeroAndNotNeg1_02201b94(int a, int b) {
	return a != 0 && a != -1 && b != 0 && b != -1;
}

struct Header02201bb4 {
	char pad0[0xc];
	unsigned short seqHi;
	unsigned short seqLo;
	unsigned short ackHi;
	unsigned short ackLo;
};

#define SwapBytes16_02201bb4(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201bb4  (semantic: ProcessHeader_02201bb4)
extern "C" ARM void func_ov031_02201bb4(Header02201bb4* obj, void* type, void* len) {
	unsigned int checksum = ComputeNormalizedChecksum_02200684(type, (unsigned int)len);
	if (checksum != 0xffff) {
		return;
	}
	unsigned short a = obj->ackLo;
	unsigned short b = obj->ackHi;
	unsigned short c = obj->seqLo;
	unsigned short d = obj->seqHi;
	unsigned int seq = ((unsigned int)SwapBytes16_02201bb4(d) << 16) | SwapBytes16_02201bb4(c);
	unsigned int ack = ((unsigned int)SwapBytes16_02201bb4(b) << 16) | SwapBytes16_02201bb4(a);
	if (!IsNonzeroAndNotNeg1_02201b94((int)seq, (int)ack)) {
		return;
	}
	unsigned char kind = *(unsigned char*)type;
	switch (kind) {
	case 0:
		func_ov031_02201a94((Header02201a94*)obj, type, len);
		return;
	case 8:
		func_ov031_022019b0((Struct022019b0*)obj, type, (int)len);
		return;
	}
}

struct Entry02201c84 {
	int flag0;
	unsigned char pad0[0x8 - 4];
	unsigned char flag8;
	unsigned char pad1;
	unsigned short f0a;
	unsigned char pad2[0x18 - 0xc];
	unsigned short f18;
	unsigned char pad3[0x1c - 0x1a];
	int f1c;
};

struct Node02201c84 {
	unsigned char pad0[0x68];
	Node02201c84* next;
	unsigned char pad1[0xa4 - 0x68 - 4];
	Entry02201c84* field;
};

struct RootStruct02111304 { unsigned char pad[0x8]; void* head; };

struct ArgA02201c84 { unsigned char pad0[0xc]; unsigned short f0c; unsigned short f0e; };
struct ArgB02201c84 { unsigned short f00; unsigned short f02; };

// USA: func_ov031_02201c84
extern "C" ARM void* func_ov031_02201c84(ArgA02201c84* a, ArgB02201c84* b) {
	Entry02201c84* field;
	Node02201c84* node = (Node02201c84*)data_02111304.firstContext;
	if (node) {
	do {
		field = node->field;
		if (field && field->flag0 != 0) {
			if (field->flag8 == 1) {
				unsigned short v = b->f02;
				unsigned short sw = (unsigned short)((v >> 8) | (v << 8));
				if (field->f0a == sw) {
					if (field->f18 != 0) {
						unsigned short v2 = b->f00;
						unsigned short sw2 = (unsigned short)((v2 >> 8) | (v2 << 8));
						if (field->f18 != sw2) goto next;
					}
					if (field->f1c != 0) {
						unsigned short ve = a->f0e;
						unsigned short vc = a->f0c;
						unsigned short swc = (unsigned short)((vc >> 8) | (vc << 8));
						unsigned short swe = (unsigned short)((ve >> 8) | (ve << 8));
						unsigned int combined = ((unsigned int)swc << 0x10) | swe;
						if (field->f1c != (int)combined) goto next;
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

// USA: func_ov031_02201d58  (semantic: CompareEncodedFields_02201d58)
extern "C" ARM int func_ov031_02201d58(void* r0, unsigned short* r1, void* r2) {
	int result = 0;
	int flag1 = 0;
	int flag3 = 0;
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
		unsigned short target2 = *(unsigned short*)((char*)r2 + 0x18);
		if (target2 == (unsigned short)((v2 >> 8) | (v2 << 8))) flag3 = 1;
	}
	if (flag3) {
		unsigned short lo = *(unsigned short*)((char*)r0 + 0xe);
		unsigned short hi = *(unsigned short*)((char*)r0 + 0xc);
		unsigned int targetD = *(unsigned int*)((char*)r2 + 0x1c);
		unsigned int combined = ((unsigned int)(unsigned short)((hi >> 8) | (hi << 8)) << 16) | (unsigned short)((lo >> 8) | (lo << 8));
		if (targetD == combined) result = 1;
	}
	return result;
}

struct RootStruct02201e0c { unsigned char pad[0x8]; void* head; };
struct Node02201e0c { unsigned char pad0[0x68]; Node02201e0c* next; unsigned char pad1[0xa4-0x68-4]; void* field; };

// USA: func_ov031_02201e0c  (semantic: FindMatchingNode_02201e0c)
extern "C" ARM void* func_ov031_02201e0c(void* a, void* b) {
    int* field;
    Node02201e0c* node = (Node02201e0c*)data_02111304.firstContext;
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
                int skip = *cursor - 1;
                remaining -= skip;
                cursor += skip;
                break;
        }
    } while (remaining-- != 0);
}

// USA: func_ov031_02201ef4
ARM int CheckOrDispatch_02201ef4(CPSInAddr address) {
    CPSInAddr targetAddress = func_ov031_02200730(address);
    if (targetAddress == 0) return 1;
    return (int)func_ov031_02200bfc(targetAddress);
}

struct CpsSocket02201f10 {
    char padding[0x1c];
    CPSInAddr remoteIp;
};

// USA: func_ov031_02201f10
extern "C" ARM void func_ov031_02201f10(CpsSocket02201f10* socket, int type, int flags) {
    if (CheckOrDispatch_02201ef4(socket->remoteIp) ||
        data_02111304.activeContext != &data_ov031_0224cbe8) {
        func_ov031_02201550((unsigned char*)0, 0, (Socket02201550*)socket, type, flags);
    } else {
        func_ov031_02200ccc(func_ov031_02200730(socket->remoteIp));
    }
}

// USA: func_ov031_02201f84
ARM void TailCallType16_02201f84(int a, int b) {
	func_ov031_02201f10((CpsSocket02201f10*)a, 0x10, b);
}

// USA: func_ov031_02201f98
ARM void TailCallType17_02201f98(int a, int b) {
	func_ov031_02201f10((CpsSocket02201f10*)a, 0x11, b);
}

struct Header02201fac { unsigned char pad0[0xc]; unsigned short f0c; unsigned short f0e; };
struct Src02201fac { unsigned short f0; unsigned short f2; unsigned short f4; unsigned short f6; unsigned short f8; unsigned short fa; unsigned char pad0; unsigned char flags; };
struct Dst02201fac { unsigned char pad0[0x24]; unsigned int f24; unsigned int f28; };

#define SW16_02201fac(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_02201fac
extern "C" ARM void func_ov031_02201fac(Header02201fac* hdr, Src02201fac* src, unsigned int a, int b) {
	Dst02201fac* dst = (Dst02201fac*)&data_ov031_0224cac4;
	VectorizedMemset(dst, 0, 0x64);
	data_ov031_0224cac4.localPort = SW16_02201fac(src->f2);
	data_ov031_0224cac4.remotePort = SW16_02201fac(src->f0);
	data_ov031_0224cac4.remoteAddress = ((unsigned int)SW16_02201fac(hdr->f0c) << 16) | SW16_02201fac(hdr->f0e);
	if (src->flags & 0x10) {
		dst->f28 = ((unsigned int)SW16_02201fac(src->f8) << 16) | SW16_02201fac(src->fa);
		return func_ov031_02201f10((CpsSocket02201f10*)dst, 4, b);
	}
	dst->f28 = 0;
	unsigned int v = a + (((unsigned int)SW16_02201fac(src->f4) << 16) | SW16_02201fac(src->f6));
	dst->f24 = v;
	if (src->flags & 3) {
		dst->f24 = v + 1;
	}
	return func_ov031_02201f10((CpsSocket02201f10*)dst, 0x14, b);
}

struct Hdr022020e8 { unsigned char pad[0xc]; unsigned short f0c; unsigned short f0e; unsigned short f10; unsigned short f12; };
struct Src022020e8 { unsigned short f0; unsigned char pad1[2]; unsigned short f4; unsigned short f6; };
struct Dst022020e8 {
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

// USA: func_ov031_022020e8  (semantic: BuildAndDispatchPacket_022020e8)
extern "C" ARM void func_ov031_022020e8(Hdr022020e8* hdr, Src022020e8* src, Dst022020e8* dst) {
	dst->f8 = 3;
	dst->f10 = (unsigned int)(GetCurrentTimestamp() >> 16);
	dst->f14 = ((unsigned int)SW16_022020e8(hdr->f10) << 16) | SW16_022020e8(hdr->f12);
	dst->f18 = SW16_022020e8(src->f0);
	dst->f1c = ((unsigned int)SW16_022020e8(hdr->f0c) << 16) | SW16_022020e8(hdr->f0e);
	dst->f24 = (((unsigned int)SW16_022020e8(src->f4) << 16) | SW16_022020e8(src->f6)) + 1;
	func_ov031_02201e70(src, dst);
	func_ov031_02201f10((CpsSocket02201f10*)dst, 0x12, 0);
}

struct PacketNode022021d4 {
    char padding[8];
    unsigned char kind;
    char padding9[0x28 - 9];
    unsigned int counter;
};
struct Hdr022020e8;
struct Src022020e8;
struct Dst022020e8;
struct Header02201fac;
struct Src02201fac;

// USA: func_ov031_022021d4
extern "C" ARM int func_ov031_022021d4(void* header, void* data, int length) {
    PacketNode022021d4* node = (PacketNode022021d4*)func_ov031_02201e0c(header, data);
    if (node != NULL) {
        if (node->kind == 1) {
            func_ov031_022020e8((Hdr022020e8*)header, (Src022020e8*)data, (Dst022020e8*)node);
        } else if ((unsigned char)(node->kind + 0xfd) <= 1) {
            --node->counter;
            func_ov031_022020e8((Hdr022020e8*)header, (Src022020e8*)data, (Dst022020e8*)node);
        } else {
            func_ov031_02201fac((Header02201fac*)header, (Src02201fac*)data, length, 0);
        }
        return 1;
    }
    return 0;
}

void CycleCurrentPriorityContexts(void);

struct Header0220225c { unsigned char pad0[0xc]; unsigned short fc; unsigned short fe; unsigned short f10; unsigned short f12; };

// USA: func_ov031_0220225c
extern "C" ARM void func_ov031_0220225c(Header0220225c* header, void* data, int length) {
	unsigned short v12 = header->f12;
	unsigned short v10 = header->f10;
	unsigned short ve = header->fe;
	unsigned short vc = header->fc;
	unsigned short swc = (unsigned short)((vc >> 8) | (vc << 8));
	unsigned short swe = (unsigned short)((ve >> 8) | (ve << 8));
	unsigned short sw10 = (unsigned short)((v10 >> 8) | (v10 << 8));
	unsigned short sw12 = (unsigned short)((v12 >> 8) | (v12 << 8));
	int a = ((unsigned int)swc << 0x10) | swe;
	int b = ((unsigned int)sw10 << 0x10) | sw12;

	if (!IsNonzeroAndNotNeg1_02201b94(a, b)) {
		return;
	}
	if (func_ov031_022021d4(header, data, length) != 0) {
		return;
	}
	void* field = func_ov031_02201c84((ArgA02201c84*)header, (ArgB02201c84*)data);
	if (field != NULL) {
		func_ov031_022020e8((Hdr022020e8*)header, (Src022020e8*)data, (Dst022020e8*)field);
		return;
	}
	CycleCurrentPriorityContexts();
	field = func_ov031_02201c84((ArgA02201c84*)header, (ArgB02201c84*)data);
	if (field == NULL) {
		return;
	}
	func_ov031_022020e8((Hdr022020e8*)header, (Src022020e8*)data, (Dst022020e8*)field);
}

struct Connection02202334 {
    ProcessorContext* context;
    int pending;
    unsigned char state;
    char pad9[0x1b];
    unsigned int sequence;
    char pad28[4];
    unsigned short window;
    char pad2e[2];
    unsigned int acknowledgement;
};
struct Packet02202334 { unsigned short pad[2]; unsigned short sequenceHigh; unsigned short sequenceLow; unsigned short acknowledgementHigh; unsigned short acknowledgementLow; unsigned short fieldC; unsigned short window; };

#define Swap16_02202334(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_02202334
extern "C" ARM void func_ov031_02202334(void* obj, Packet02202334* packet, int length) {
    Connection02202334* connection = (Connection02202334*)func_ov031_02201e0c(obj, packet);
    if (!connection || connection->state != 2) {
        func_ov031_02201fac((Header02201fac*)obj, (Src02201fac*)packet, length, 0);
        return;
    }
    CycleCurrentPriorityContexts();
    connection->sequence = (((unsigned int)Swap16_02202334(packet->sequenceHigh) << 16) | Swap16_02202334(packet->sequenceLow)) + 1;
    connection->acknowledgement = ((unsigned int)Swap16_02202334(packet->acknowledgementHigh) << 16) | Swap16_02202334(packet->acknowledgementLow);
    connection->window = Swap16_02202334(packet->window);
    func_ov031_02201e70(packet, connection);
    TailCallType16_02201f84((int)connection, 0);
    connection->state = 4;
    if (connection->pending == 1) {
        connection->pending = 0;
        MarkContextReadyAndSwitch(connection->context);
    }
}

struct TcpConnection {
    ProcessorContext* context;
    int pending;
    unsigned char state;
    unsigned char padding9[0x1b];
    unsigned int sequence;
    unsigned char padding28[4];
    unsigned short window;
    unsigned short padding2e;
    unsigned int acknowledgement;
    unsigned int receivedPackets;
    unsigned char padding38[4];
    unsigned int receiveCapacity;
    unsigned char* receiveBuffer;
    unsigned int receivedBytes;
};

struct TcpPacket {
    unsigned short ports[2];
    unsigned short sequenceHigh;
    unsigned short sequenceLow;
    unsigned short acknowledgementHigh;
    unsigned short acknowledgementLow;
    unsigned char headerLength;
    unsigned char flags;
    unsigned short window;
};

#define Swap16_0220242c(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_0220242c
extern "C" ARM void func_ov031_0220242c(void* object, TcpPacket* packet, unsigned int length) {
    TcpConnection* connection = (TcpConnection*)func_ov031_02201e0c(object, packet);
    if (!connection) {
        func_ov031_02201fac((Header02201fac*)object, (Src02201fac*)packet, length, 0);
        return;
    }
    unsigned int acknowledgement = ((unsigned int)Swap16_0220242c(packet->acknowledgementHigh) << 16) | Swap16_0220242c(packet->acknowledgementLow);
    unsigned char flags = packet->flags;
    if ((int)(acknowledgement - connection->acknowledgement) > 0)
        connection->acknowledgement = acknowledgement;
    unsigned int sequence = ((unsigned int)Swap16_0220242c(packet->sequenceHigh) << 16) | Swap16_0220242c(packet->sequenceLow);
    if (connection->state == 4 && connection->sequence != sequence) {
        TailCallType16_02201f84((int)connection, 0);
        return;
    }
    connection->window = Swap16_0220242c(packet->window);
    switch (connection->state) {
    case 0:
    case 2:
        func_ov031_02201fac((Header02201fac*)object, (Src02201fac*)packet, length, 0);
        break;
    case 3:
        connection->state = 4;
        if (connection->pending == 1) {
            connection->pending = 0;
            MarkContextReadyAndSwitch(connection->context);
        }
        if (!length)
            break;
    case 4:
        ++connection->receivedPackets;
        unsigned int capacity = connection->receiveCapacity;
        unsigned int remaining = capacity - connection->receivedBytes;
        int complete;
        if (length > remaining) {
            complete = 0;
            length = remaining;
        } else {
            complete = 1;
        }
        if (length) {
            int irqState = DisableIRQInterrupts();
            int headerBytes = (packet->headerLength & 0xf0) / 4;
            VectorizedInvertedMemcpy((unsigned char*)packet + headerBytes, connection->receiveBuffer + connection->receivedBytes, length);
            connection->receivedBytes += length;
            connection->sequence += length;
            SetIRQInterruptState(irqState);
            if (connection->pending == 2) {
                connection->pending = 0;
                MarkContextReadyAndSwitch(connection->context);
            }
        }
        if (complete && (flags & 1)) {
            connection->state = 6;
            ++connection->sequence;
            TailCallType17_02201f98((int)connection, 0);
            if (!length && connection->pending == 2) {
                connection->pending = 0;
                MarkContextReadyAndSwitch(connection->context);
            }
        } else if (length) {
            TailCallType16_02201f84((int)connection, 0);
        }
        break;
    case 7:
    case 8:
        if (flags & 1) {
            connection->sequence += length + 1;
            TailCallType16_02201f84((int)connection, 0);
            connection->state = 0;
            if (connection->pending == 2) {
                connection->pending = 0;
                MarkContextReadyAndSwitch(connection->context);
            }
        } else {
            if (length) {
                connection->sequence += length;
                TailCallType16_02201f84((int)connection, 0);
            }
            connection->state = 8;
        }
        break;
    case 6:
    case 9:
        connection->state = 0;
        if (connection->pending == 2) {
            connection->pending = 0;
            MarkContextReadyAndSwitch(connection->context);
        }
        break;
    default:
        if (flags & 1)
            ++connection->sequence;
        TailCallType16_02201f84((int)connection, 0);
        break;
    }
    CycleCurrentPriorityContexts();
}

struct ContextEntry02202744 {
	ProcessorContext* field0;
	int field4;
	unsigned char field8;
	unsigned char pad[0x24 - 0x9];
	int field24;
};

// USA: func_ov031_02202744
extern "C" ARM void func_ov031_02202744(int a, int b, int c) {
	ContextEntry02202744* node = (ContextEntry02202744*)func_ov031_02201e0c((void*)a, (void*)b);
	if (!node) return;
	switch (node->field8) {
	case 7:
		node->field24++;
		TailCallType16_02201f84((int)node, 0);
		node->field8 = 9;
		return;
	case 8:
		node->field24++;
		TailCallType16_02201f84((int)node, 0);
		node->field8 = 0;
		if (node->field4 != 2) return;
		node->field4 = 0;
		MarkContextReadyAndSwitch(node->field0);
		return;
	case 4:
		node->field24++;
		TailCallType17_02201f98((int)node, 0);
		node->field8 = 6;
		return;
	default:
		func_ov031_02201fac((Header02201fac*)a, (Src02201fac*)b, c, 0);
		return;
	}
}

struct ContextEntry_02202810 {
	ProcessorContext* field0;
	int field4;
	unsigned char field8;
};

// USA: func_ov031_02202810
ARM int FindAndRescheduleContext_02202810(int a, int b) {
	ContextEntry_02202810* p = (ContextEntry_02202810*)func_ov031_02201e0c((void*)a, (void*)b);
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

struct Header0220225c;

struct Buf0220284c { unsigned char pad[0xc]; unsigned char byte0xc; unsigned char byte0xd; };

// USA: func_ov031_0220284c  (semantic: DispatchByFlagsNibbleAndCode_0220284c)
extern "C" ARM void func_ov031_0220284c(void* c, Buf0220284c* buf, int len) {
    if (IsChecksumValid_022006a0(buf, len, c, 6)) return;

    int v = buf->byte0xc & 0xf0;
    len -= v / 4;
    switch (buf->byte0xd & 0x17) {
    case 0x2:
        if (buf->byte0xd & 0x28) return;
        func_ov031_0220225c((Header0220225c*)c, buf, len);
        return;
    case 0x12:
        if (buf->byte0xd & 0x28) return;
        func_ov031_02202334(c, (Packet02202334*)buf, len);
        return;
    case 0x10:
    case 0x11:
        func_ov031_0220242c(c, (TcpPacket*)buf, len);
        return;
    case 0x1:
        func_ov031_02202744((int)c, (int)buf, len);
        return;
    }
    if (buf->byte0xd & 0x4) {
        FindAndRescheduleContext_02202810((int)c, (int)buf);
    } else {
        func_ov031_02201fac((Header02201fac*)c, (Src02201fac*)buf, len, 0);
    }
}

struct Header0220296c {
    unsigned char pad0[0xc];
    unsigned short f0c;
    unsigned short f0e;
    unsigned short f10;
    unsigned short f12;
};

typedef int (*Callback0220296c)(void*, unsigned int, void*);

#define SwapBytes16_0220296c(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_0220296c
extern "C" ARM void func_ov031_0220296c(Header0220296c* a, void* b, unsigned int c) {
    unsigned char* entry;
    if (*(unsigned short*)((unsigned char*)b + 6) != 0) {
        if (IsChecksumValid_022006a0(b, c, a, 0x11)) return;
    }
    int priorState = DisableIRQInterrupts();
    ProcessorContext* context = data_02111304.firstContext;
    if (context != NULL) {
        do {
            entry = (unsigned char*)context->unknown_A4;
            if (entry != NULL && *(unsigned int*)entry != 0 && entry[8] == 0xa &&
                *(unsigned short*)(entry + 0xa) == SwapBytes16_0220296c(*(unsigned short*)((unsigned char*)b + 2)) &&
                (*(unsigned short*)(entry + 0x18) == 0 ||
                 *(unsigned short*)(entry + 0x18) == SwapBytes16_0220296c(*(unsigned short*)b)) &&
                (*(unsigned int*)(entry + 0x1c) == 0 || *(unsigned int*)(entry + 0x1c) == 0xffffffff ||
                 *(unsigned int*)(entry + 0x1c) == (((unsigned int)SwapBytes16_0220296c(a->f0c) << 16) | SwapBytes16_0220296c(a->f0e)))) {
                *(unsigned int*)(entry + 0x14) = ((unsigned int)SwapBytes16_0220296c(a->f10) << 16) | SwapBytes16_0220296c(a->f12);
                if (*(unsigned int*)(entry + 0x1c) == 0) {
                    *(unsigned int*)(entry + 0x1c) = ((unsigned int)SwapBytes16_0220296c(a->f0c) << 16) | SwapBytes16_0220296c(a->f0e);
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
                    } else if (*(Callback0220296c*)(entry + 0x38) != NULL) {
                        if ((*(Callback0220296c*)(entry + 0x38))(*(void**)(entry + 0x40), *(unsigned int*)(entry + 0x44), entry) != 0) {
                            *(unsigned int*)(entry + 0x44) = 0;
                        }
                    }
                }
                break;
            }
            context = context->pNext;
        } while (context != NULL);
    }
    SetIRQInterruptState(priorState);
}
