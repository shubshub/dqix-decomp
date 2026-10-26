#include <globaldefs.h>

struct Struct_ov017_021d4a38_2 {
	int type;
	union { int i; float f; };
};

struct Struct_ov017_021d4e38 {
	int unknown_0_;
	int arg;
	union { int unknown_8_; float unknown1_8_; };
};

struct Struct_ov017_021d4e38_2 {
	unsigned char unknown_0_[0x14];
	Struct_ov017_021d4a38_2* unknown_14_;
	unsigned char pad18[4];
	int globals;
	unsigned char pad20[4];
	int unknown_24_;
	int unknown_28_;
	unsigned char pad2c[4];
	int frame;
	void* unknown_34_;
	Struct_ov017_021d4e38* pc;
	int unknown_3c_;
	int unknown_40_;
	unsigned char unknown_44_[4];
	int code;
	int result;
	int steps;
};

struct Struct_ov017_021d4a38;
struct Struct_ov017_021d4a78_2;
struct Struct_ov017_021d4a98_2;
struct Struct_ov017_021d4ab8_2;
struct Struct_ov017_021d4b9c_2;
struct Struct_ov017_021d4bc8_2;
struct Struct_ov017_021d4bc8;
struct Struct_ov017_021d4af8_2;
struct Struct_ov017_021d4af8;

extern "C" void func_ov017_021d4a38(Struct_ov017_021d4a38* obj, Struct_ov017_021d4a38_2 v);
extern "C" void func_ov017_021d4a64(Struct_ov017_021d4a38_2* dst, Struct_ov017_021d4a38_2* src);
extern "C" void func_ov017_021d4a78(Struct_ov017_021d4a78_2* obj, int v);
extern "C" void func_ov017_021d4a98(Struct_ov017_021d4a98_2* obj, int v);
extern "C" void func_ov017_021d4ab8(Struct_ov017_021d4ab8_2* arg0, int arg1);
extern "C" int func_ov017_021d4b9c(Struct_ov017_021d4b9c_2* obj);
extern "C" void func_ov017_021d4bc8(Struct_ov017_021d4bc8_2* a, Struct_ov017_021d4bc8* b, int c);
extern "C" int func_ov017_021d4af8(Struct_ov017_021d4af8_2* self, Struct_ov017_021d4af8* arg, int arg2);

extern "C" int func_ov017_021d49ac(Struct_ov017_021d4a38_2 v);
extern "C" int func_ov017_021d4980(Struct_ov017_021d4a38_2 v, void* arg1);
extern "C" void func_ov017_021d4ad8(Struct_ov017_021d4e38_2* self, float v);

extern "C" void func_0200159c(int code) __attribute__((noreturn));
extern "C" void func_02001878(void* text);
extern "C" float _d2f(double v);
extern "C" double func_02009424(double v);
extern "C" double func_02008dcc(double v);
extern int data_020eec2c;

#define IsTruthy func_ov017_021d49ac
#define Resolve func_ov017_021d4980
#define PushFloat func_ov017_021d4ad8
#define PushInt(s, v) func_ov017_021d4a78((Struct_ov017_021d4a78_2*)(s), (v))
#define PushCode(s, v) func_ov017_021d4a98((Struct_ov017_021d4a98_2*)(s), (v))
#define PushRef(s, v) func_ov017_021d4ab8((Struct_ov017_021d4ab8_2*)(s), (v))
#define Push(s, v) func_ov017_021d4a38((Struct_ov017_021d4a38*)(s), (v))

#define SlotPtr(base, idx) (((Struct_ov017_021d4a38_2*)(base)) + (idx))
#define Slot(base, idx) (*SlotPtr((base), (idx)))

inline Struct_ov017_021d4a38_2 inline_ov017_021d4e38(Struct_ov017_021d4e38_2* self) {
	self->unknown_14_--;
	return *self->unknown_14_;
}

#pragma opt_dead_assignments off

// USA: func_ov017_021d4e38
extern "C" ARM void func_ov017_021d4e38(Struct_ov017_021d4e38_2* self, Struct_ov017_021d4e38* start) {
	Struct_ov017_021d4a38_2 var0, rhs, lhs;

	self->pc = start;
	for (;;) {
		switch (self->pc->unknown_0_) {
		case 1:
			switch (self->pc->unknown_8_) {
			case 1:
				Push(self, Slot(self->frame, self->pc->arg));
				break;
			case 0x40:
				Push(self, Slot(self->globals, self->pc->arg));
				break;
			case 2: {
				int idx = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
				Push(self, SlotPtr(self->frame, self->pc->arg)[idx]);
				break;
			}
			case 4: {
				int idx = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
				Push(self, Slot(Slot(self->frame, self->pc->arg).i, idx));
				break;
			}
			case 8:
				Slot(self->frame, self->pc->arg).type = 1;
				Push(self, Slot(self->frame, self->pc->arg));
				break;
			case 0x200:
				Slot(self->globals, self->pc->arg).type = 1;
				Push(self, Slot(self->globals, self->pc->arg));
				break;
			case 0x10: {
				int idx = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
				SlotPtr(self->frame, self->pc->arg)[idx].type = 1;
				Push(self, SlotPtr(self->frame, self->pc->arg)[idx]);
				break;
			}
			case 0x20: {
				int idx = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
				Slot(Slot(self->frame, self->pc->arg).i, idx).type = 1;
				Push(self, Slot(Slot(self->frame, self->pc->arg).i, idx));
				break;
			}
			}
			break;

		case 2:
			switch (self->pc->unknown_8_) {
			case 1:
				PushRef(self, (int)SlotPtr(self->frame, self->pc->arg));
				break;
			case 0x40:
				PushRef(self, (int)SlotPtr(self->globals, self->pc->arg));
				break;
			case 2: {
				int idx = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
				PushRef(self, (int)(SlotPtr(self->frame, self->pc->arg) + idx));
				break;
			}
			case 4: {
				int idx = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
				PushRef(self, (int)SlotPtr(Slot(self->frame, self->pc->arg).i, idx));
				break;
			}
			case 8:
				PushRef(self, (int)SlotPtr(self->frame, self->pc->arg));
				break;
			case 0x200:
				PushRef(self, (int)SlotPtr(self->globals, self->pc->arg));
				break;
			case 0x10: {
				int idx = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
				PushRef(self, (int)(SlotPtr(self->frame, self->pc->arg) + idx));
				break;
			}
			case 0x20: {
				int idx = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
				PushRef(self, (int)SlotPtr(Slot(self->frame, self->pc->arg).i, idx));
				break;
			}
			}
			break;

		case 5:
			var0 = inline_ov017_021d4e38(self);
			func_ov017_021d4a64((Struct_ov017_021d4a38_2*)inline_ov017_021d4e38(self).i, &var0);
			Push(self, var0);
			break;

		case 3:
			if (self->pc->arg == 1) {
				PushInt(self, self->pc->unknown_8_);
			} else if (self->pc->arg == 3) {
				PushCode(self, self->code + self->pc->unknown_8_);
			} else if (self->pc->arg == 2) {
				PushFloat(self, self->pc->unknown1_8_);
			}
			break;

		case 4:
			self->unknown_14_--;
			break;

		case 16:
			if (self->unknown_40_ == 0) {
				self->pc = (Struct_ov017_021d4e38*)(self->code + self->pc->arg);
				continue;
			}
			break;

		case 18:
			if (self->unknown_40_ != 0) {
				break;
			}
			if (IsTruthy(inline_ov017_021d4e38(self))) {
				if (self->pc->unknown_8_ != 0) {
					PushInt(self, 1);
				}
				self->pc = (Struct_ov017_021d4e38*)(self->code + self->pc->arg);
				continue;
			}
			break;

		case 17:
			if (self->unknown_40_ != 0) {
				break;
			}
			if (!IsTruthy(inline_ov017_021d4e38(self))) {
				if (self->pc->unknown_8_ != 0) {
					PushInt(self, 0);
				}
				self->pc = (Struct_ov017_021d4e38*)(self->code + self->pc->arg);
				continue;
			}
			break;

		case 14:
			rhs = inline_ov017_021d4e38(self);
			lhs = inline_ov017_021d4e38(self);
			if (lhs.type == 0 && rhs.type == 0) {
				switch (self->pc->arg) {
				case 0x28: PushInt(self, rhs.i == lhs.i); break;
				case 0x29: PushInt(self, rhs.i != lhs.i); break;
				case 0x2a: PushInt(self, lhs.i < rhs.i); break;
				case 0x2b: PushInt(self, lhs.i <= rhs.i); break;
				case 0x2c: PushInt(self, lhs.i > rhs.i); break;
				case 0x2d: PushInt(self, lhs.i >= rhs.i); break;
				}
			} else {
				float var11, var12;
				if (lhs.type == 1 && rhs.type == 1) {
					var11 = rhs.f;
					var12 = lhs.f;
				} else if (lhs.type == 0 && rhs.type == 1) {
					var11 = rhs.f;
					var12 = (float)lhs.i;
				} else if (lhs.type == 1 && rhs.type == 0) {
					var11 = (float)rhs.i;
					var12 = lhs.f;
				} else {
					func_0200159c(-1);
				}
				switch (self->pc->arg) {
				case 0x28: PushInt(self, var11 == var12); break;
				case 0x29: PushInt(self, var11 != var12); break;
				case 0x2a: PushInt(self, var12 < var11); break;
				case 0x2b: PushInt(self, var12 <= var11); break;
				case 0x2c: PushInt(self, var12 > var11); break;
				case 0x2d: PushInt(self, var12 >= var11); break;
				}
			}
			break;

		case 6:
			rhs = inline_ov017_021d4e38(self);
			lhs = inline_ov017_021d4e38(self);
			if (lhs.type == 0 && rhs.type == 0) {
				PushInt(self, lhs.i + rhs.i);
			} else if (lhs.type == 1 && rhs.type == 1) {
				PushFloat(self, lhs.f + rhs.f);
			} else if (lhs.type == 0 && rhs.type == 1) {
				PushFloat(self, (float)lhs.i + rhs.f);
			} else if (lhs.type == 1 && rhs.type == 0) {
				PushFloat(self, lhs.f + (float)rhs.i);
			} else {
				func_0200159c(-1);
			}
			break;

		case 7:
			rhs = inline_ov017_021d4e38(self);
			lhs = inline_ov017_021d4e38(self);
			if (lhs.type == 0 && rhs.type == 0) {
				PushInt(self, lhs.i - rhs.i);
			} else if (lhs.type == 1 && rhs.type == 1) {
				PushFloat(self, lhs.f - rhs.f);
			} else if (lhs.type == 0 && rhs.type == 1) {
				PushFloat(self, (float)lhs.i - rhs.f);
			} else if (lhs.type == 1 && rhs.type == 0) {
				PushFloat(self, lhs.f - (float)rhs.i);
			} else {
				func_0200159c(-1);
			}
			break;

		case 8:
			rhs = inline_ov017_021d4e38(self);
			lhs = inline_ov017_021d4e38(self);
			if (lhs.type == 0 && rhs.type == 0) {
				PushInt(self, lhs.i * rhs.i);
			} else if (lhs.type == 1 && rhs.type == 1) {
				PushFloat(self, lhs.f * rhs.f);
			} else if (lhs.type == 0 && rhs.type == 1) {
				PushFloat(self, (float)lhs.i * rhs.f);
			} else if (lhs.type == 1 && rhs.type == 0) {
				PushFloat(self, lhs.f * (float)rhs.i);
			} else {
				func_0200159c(-1);
			}
			break;

		case 9:
			rhs = inline_ov017_021d4e38(self);
			lhs = inline_ov017_021d4e38(self);
			if (lhs.type == 0 && rhs.type == 0) {
				PushInt(self, lhs.i / rhs.i);
			} else if (lhs.type == 1 && rhs.type == 1) {
				PushFloat(self, lhs.f / rhs.f);
			} else if (lhs.type == 0 && rhs.type == 1) {
				PushFloat(self, (float)lhs.i / rhs.f);
			} else if (lhs.type == 1 && rhs.type == 0) {
				PushFloat(self, lhs.f / (float)rhs.i);
			} else {
				func_0200159c(-1);
			}
			break;

		case 10: {
			int r = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
			int l = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
			PushInt(self, l % r);
			break;
		}

		case 24: {
			int r = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
			int l = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
			PushInt(self, r & l);
			break;
		}

		case 25: {
			int r = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
			int l = Resolve(inline_ov017_021d4e38(self), self->unknown_34_);
			PushInt(self, r | l);
			break;
		}

		case 11:
			rhs = inline_ov017_021d4e38(self);
			if (rhs.type == 0) {
				PushInt(self, -rhs.i);
			} else if (rhs.type == 1) {
				PushFloat(self, -rhs.f);
			} else {
				func_0200159c(-1);
			}
			break;

		case 29:
			rhs = inline_ov017_021d4e38(self);
			if (rhs.type == 0) {
				PushFloat(self, _d2f(func_02009424((double)((float)rhs.i))));
			} else if (rhs.type == 1) {
				PushFloat(self, _d2f(func_02009424((double)(rhs.f))));
			} else {
				func_0200159c(-1);
			}
			break;

		case 30:
			rhs = inline_ov017_021d4e38(self);
			if (rhs.type == 0) {
				PushFloat(self, _d2f(func_02008dcc((double)((float)rhs.i))));
			} else if (rhs.type == 1) {
				PushFloat(self, _d2f(func_02008dcc((double)(rhs.f))));
			} else {
				func_0200159c(-1);
			}
			break;

		case 26:
			rhs = inline_ov017_021d4e38(self);
			if (rhs.type == 0) {
				PushInt(self, rhs.i == 0);
			} else {
				func_0200159c(-1);
			}
			break;

		case 12:
			rhs = inline_ov017_021d4e38(self);
			if (rhs.type == 0) {
				PushFloat(self, (float)rhs.i);
			} else if (rhs.type == 1) {
				PushFloat(self, rhs.f);
			} else {
				func_0200159c(-1);
			}
			break;

		case 13:
			rhs = inline_ov017_021d4e38(self);
			if (rhs.type == 0) {
				PushInt(self, rhs.i);
			} else if (rhs.type == 1) {
				PushInt(self, (int)rhs.f);
			} else {
				func_0200159c(-1);
			}
			break;

		case 20: {
			self->unknown_14_ -= self->pc->arg;
			Struct_ov017_021d4a38_2* p = self->unknown_14_;
			int n = self->pc->arg;
			for (int i = 0; i < n; i++, p++) {
				func_02001878(&data_020eec2c);
			}
			break;
		}

		case 21:
			self->unknown_14_ -= self->pc->arg;
			if (self->unknown_40_ == 0) {
				func_ov017_021d4bc8((Struct_ov017_021d4bc8_2*)self, (Struct_ov017_021d4bc8*)self->unknown_14_,
				                                self->pc->arg);
			}
			break;

		case 27:
			self->unknown_3c_ = 1;
			self->pc = NULL;
			return;

		case 19:
			self->pc = (Struct_ov017_021d4e38*)(func_ov017_021d4af8((Struct_ov017_021d4af8_2*)self,
			                                               (Struct_ov017_021d4af8*)(self->code + self->pc->unknown_8_),
			                                               (int)self->pc) - 0xc);
			break;

		case 15:
			var0 = inline_ov017_021d4e38(self);
			if (self->unknown_28_ != self->unknown_24_) {
				self->unknown_14_ = (Struct_ov017_021d4a38_2*)self->frame;
				self->pc = (Struct_ov017_021d4e38*)func_ov017_021d4b9c((Struct_ov017_021d4b9c_2*)self);
			} else {
				self->result = var0.i;
				Push(self, var0);
				self->pc = NULL;
				self->unknown_3c_ = 1;
				return;
			}
			Push(self, var0);
			break;

		case 23:
			if (self->unknown_40_ != 0) {
				break;
			}
			self->pc = self->pc + 1;
			return;

		case 28:
			self->steps++;
			if (self->unknown_40_ != 0) {
				self->unknown_40_ = 0;
				self->pc = self->pc + 1;
				return;
			}
			break;
		}
		self->pc++;
	}
}

#pragma opt_dead_assignments reset
