#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov027_021dd3f8 {
	Struct_ov027_021dd3f8* next;
	union {
		unsigned int flags;
		struct {
			unsigned int active : 1;
			unsigned int priority : 31;
		};
	};
	unsigned int f8;
	unsigned int fc;
};

struct Struct_ov027_021e3420_3 { void* field0; };
extern Struct_ov027_021e3420_3 data_ov027_021e3420;

extern "C" int func_ov027_021dd3b0(void);

// USA: func_ov027_021dd3f8
extern "C" ARM void func_ov027_021dd3f8(void* a0, unsigned int a1, unsigned int a2, unsigned int a3) {
	Struct_ov027_021dd3f8* node = (Struct_ov027_021dd3f8*)a0;
	ProcessorContext* ctx = (ProcessorContext*)data_ov027_021e3420.field0;
	if (!func_ov027_021dd3b0()) return;
	if (node->active) return;

	unsigned int var2 = a3;
	if (var2 > 0x1f) {
		unsigned int var3 = GetContextPriority(ctx);
		if (var2 == 0x20) {
			var2 = (var3 != 0) ? (var3 - 1) : 0;
		} else if (var2 == 0x21) {
			var2 = (var3 < 0x1f) ? (var3 + 1) : 0x1f;
		} else if (var2 == 0x22) {
			var2 = var3;
		} else {
			var2 = 0x1f;
		}
	}

	int state = DisableIRQInterrupts();
	node->active = 1;
	node->priority = var2;
	node->f8 = a1;
	node->fc = a2;

	Struct_ov027_021dd3f8** var5 = (Struct_ov027_021dd3f8**)((char*)ctx + 0xc0);
	Struct_ov027_021dd3f8* head = *var5;
	if (head == 0) {
		if (node == (Struct_ov027_021dd3f8*)((char*)ctx + 0xc4)) {
			data_ov027_021e3420.field0 = 0;
		}
		*var5 = node;
		MarkContextReadyAndSwitch(ctx);
	} else {
		Struct_ov027_021dd3f8* var7 = *(Struct_ov027_021dd3f8* volatile*)var5;
		if (node == (Struct_ov027_021dd3f8*)((char*)ctx + 0xc4)) {
			Struct_ov027_021dd3f8* last = var7;
			Struct_ov027_021dd3f8* var9 = last->next;
			if (var9 != 0) {
				do {
					last = var9;
					var9 = last->next;
				} while (var9 != 0);
			}
			last->next = node;
			data_ov027_021e3420.field0 = 0;
		} else {
			if (var2 < var7->priority) {
				*var5 = node;
				node->next = var7;
			} else {
				Struct_ov027_021dd3f8* prev = var7;
				Struct_ov027_021dd3f8* cur;
				goto test_cur;
				do {
					prev = cur;
				test_cur:
					cur = prev->next;
				} while (cur != 0 && var2 >= cur->priority);
				node->next = cur;
				prev->next = node;
			}
		}
	}
	SetIRQInterruptState(state);
}
