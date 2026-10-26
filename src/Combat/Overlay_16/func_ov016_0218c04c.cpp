#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" unsigned int GetArenaLow(int i);
extern "C" unsigned int GetArenaHigh(int i);
extern "C" unsigned int func_ov016_0218fc78(void);
extern "C" unsigned int func_ov016_0218fc84(void);
extern "C" void func_ov016_0218fc8c(void*, unsigned int);
extern "C" void func_ov016_0218fcac(void*, int);
struct NitroVM;
void NitroVM_Initialize(NitroVM*);
int NitroVM_PrepareReadFileByPath(NitroVM*, char const*);
void NitroVM_FinishRead(NitroVM*);
extern "C" void* func_ov016_0218e558(void* vm, int n);
extern "C" unsigned int func_ov016_0218e690(void* p);
extern "C" unsigned int func_ov016_0218e6a8(void* p);
extern "C" unsigned int func_ov016_0218e678(void* p);
extern "C" void* func_ov016_0218e660(void* p);
extern "C" unsigned int func_ov016_0218e750(void* p);
extern "C" int func_ov016_0218e6c0(void* p);
extern "C" void func_ov016_0218e6e4(void* p);
extern "C" void func_ov016_0218e72c(void* p);
extern "C" void func_ov016_0218e640(void* p);
extern "C" int func_ov016_0218e768(void* p, void* buf);
extern "C" void func_ov016_0218bce8(void* p, unsigned int n);
extern "C" void func_ov016_0218bec4(void* p, int n);
extern "C" void func_020d1f0c(int a, int b, int c, int d);
extern "C" void func_020d1fd0(int a, int b);
extern "C" void func_020d24c4(int a);
extern "C" void func_020c9778(int a, int b);
extern "C" void func_020bbd9c(void);
extern "C" int EnterSleepMode(int a, int b, int c);
extern "C" unsigned short func_ov016_0218ca70(void);
extern "C" int func_020c7dcc(void);
extern "C" void* memset(void* p, int c, unsigned int n);
void CleanDataCache(void);
void CleanCacheRange(const void* p, unsigned int n);
struct Alarm;
void ZeroInitializeAlarm(Alarm*);
unsigned long long GetCurrentTimestamp(void);
struct ProcessorContext;
void SetInterval(Alarm*, unsigned long long, unsigned long long, void (*)(ProcessorContext**), ProcessorContext**);
void CancelAlarm(Alarm*);
extern "C" void func_0203ad14(void*, int, void*, int);
struct Obj0203aba8;
extern "C" void SoundPlayer_StartSeq(Obj0203aba8*, void*, void*);
extern "C" void func_0203ae4c(void* a, int b, void* c);
extern "C" void SoundPlayer_StopStream(void* a, void* b, int c);
extern "C" void SoundPlayer_StopSeqOnHandle(void* a, void* b, int c);
struct Struct0200fb08;
extern "C" int GameState_GetLanguage(Struct0200fb08*);
extern "C" void func_ov016_0218c024(void);

struct Struct_ov016_0218c04c {
	char pad0[0x10];
	unsigned char isSet;
	char unknown_11_;
	short id;
	unsigned int delay;
};

struct Struct_ov016_0219d0c0_7 {
	int unknown_0_;
	int flag4;
	void* alloc;
	char unknown_c_[4];
	int started;
	volatile int unknown_14_;
	int unknown_18_;
	int f1c;
	int f20;
	unsigned int frames;
	int pos;
	short* unknown_2c_;
	short* unknown_30_;
	Struct_ov016_0218c04c* info;
	int busy;
	int unknown_3c_;
	unsigned long long unknown_40_;
	volatile long long unknown_48_;
	long long unknown_50_;
};

extern Struct_ov016_0219d0c0_7 data_ov016_0219d0c0;
extern char data_ov016_0219d0cc;
extern char data_ov016_0219d118;
extern char g_bgmPlayer;

// USA: func_ov016_0218c04c
extern "C" ARM void func_ov016_0218c04c(const char* path, int arg1) {
	unsigned char vm[0x48];
	int var1;
	int var2;
	unsigned short var3;
	bool var4;
	int cnt;
	int var6;
	int q;
	unsigned char paused;
	float scale;
	int var10;
	void* node;
	int state;
	unsigned int unit;
	unsigned int sz3;
	unsigned int sz4;
	unsigned int base3;
	unsigned int base4;

	state = 0;
	var3 = 0;
	var4 = false;
	base3 = GetArenaLow(3);
	sz3 = GetArenaHigh(3) - base3;
	if (sz3 >= func_ov016_0218fc78()) {
		sz3 = func_ov016_0218fc78();
	}
	base4 = GetArenaLow(4);
	sz4 = GetArenaHigh(4) - base4;
	if (sz4 >= func_ov016_0218fc84()) {
		sz4 = func_ov016_0218fc84();
	}
	func_ov016_0218fc8c((void*)GetArenaLow(3), sz3);
	func_ov016_0218fcac((void*)GetArenaLow(4), sz4);
	NitroVM_Initialize((NitroVM*)vm);

	if (NitroVM_PrepareReadFileByPath((NitroVM*)vm, path)) {
	node = func_ov016_0218e558(vm, 6);
	if (node != 0) {
		unsigned int frame = 0;

		cnt = 0;
		var6 = func_ov016_0218e690(node);
		unit = func_ov016_0218e6a8(node);
		q = (int)(((unsigned long long)(unsigned int)func_ov016_0218e660(node) << 24) /
			((unsigned long long)unit * func_ov016_0218e678(node)));
		data_ov016_0219d0c0.frames = (q + 1) * 7;
		data_ov016_0219d0c0.unknown_30_ = (short*)((SafeAllocator*)data_ov016_0219d0c0.alloc)->Allocate(data_ov016_0219d0c0.frames * unit * 2);
		data_ov016_0219d0c0.unknown_2c_ = (short*)((SafeAllocator*)data_ov016_0219d0c0.alloc)->Allocate(data_ov016_0219d0c0.frames * unit * 2);
		memset(data_ov016_0219d0c0.unknown_30_, 0, data_ov016_0219d0c0.frames * unit * 2);
		memset(data_ov016_0219d0c0.unknown_2c_, 0, data_ov016_0219d0c0.frames * unit * 2);
		CleanDataCache();
		paused = 0;
		data_ov016_0219d0c0.unknown_48_ = paused;
		data_ov016_0219d0c0.pos = paused;
		data_ov016_0219d0c0.unknown_50_ = paused;
		data_ov016_0219d0c0.unknown_18_ = paused;
		data_ov016_0219d0c0.unknown_14_ = 1;
		data_ov016_0219d0c0.f1c = paused;
		data_ov016_0219d0c0.unknown_3c_ = paused;
		data_ov016_0219d0c0.f20 = paused;
		ZeroInitializeAlarm((Alarm*)&data_ov016_0219d118);
		{
			unsigned long long now = GetCurrentTimestamp();
			unsigned long long per = (0xf4240ULL << 24) / func_ov016_0218e678(node);
			unsigned long long iv = ((per * 0x82ea) >> 6) / 1000;
			SetInterval((Alarm*)&data_ov016_0219d118, now + 5, (unsigned int)iv, (void (*)(ProcessorContext**))func_ov016_0218c024, (ProcessorContext**)0);
		}
		data_ov016_0219d0c0.unknown_40_ = (GetCurrentTimestamp() << 6) / 0x82ea;
		scale = (float)func_ov016_0218e678(node) / 16777216.0f;
		var10 = 0;

		while (func_ov016_0218e6c0(node)) {
			if (data_ov016_0219d0c0.started == 0) {
				Struct_ov016_0218c04c* p = data_ov016_0219d0c0.info;
				unsigned long long t = (GetCurrentTimestamp() << 6) / 0x82ea;
				if (data_ov016_0219d0c0.unknown_40_ + p->delay <= t) {
					if (p->isSet != 0) {
						func_0203ad14(&g_bgmPlayer, p->id, 0, 0);
					} else {
						SoundPlayer_StartSeq((Obj0203aba8*)&g_bgmPlayer, (void*)p->id, &data_ov016_0219d0cc);
					}
					func_020bbd9c();
					data_ov016_0219d0c0.started = 1;
					var10 = frame;
				}
			}
			if ((*(unsigned short*)0x27fffa8 & 0x8000) >> 15) {
				data_ov016_0219d0c0.busy = 1;
				if (data_ov016_0219d0c0.info->isSet != 0) {
					func_0203ae4c(&g_bgmPlayer, 1, 0);
					EnterSleepMode(0xc, 0, 0);
					*(unsigned int*)(&g_bgmPlayer + 0xa8) =
						(unsigned int)(1000.0f * ((float)(frame - var10) / scale));
					func_0203ae4c(&g_bgmPlayer, 0, 0);
				} else {
					EnterSleepMode(0xc, 0, 0);
				}
				data_ov016_0219d0c0.busy = 0;
			}
			func_ov016_0218e6e4(node);
			frame++;

			if ((func_020c7dcc() & 0x40000000) || (func_020c7dcc() & 0x80000000)) {
				if (func_ov016_0218e660(node) != 0) {
					unsigned long long total = func_ov016_0218e750(node);
					int j = 0;
					int pos = data_ov016_0219d0c0.pos;
					unsigned int bytes = unit * 2;
					for (; j < total; j++) {
						if (state != 0) {
							long long used; do { used = data_ov016_0219d0c0.unknown_50_ - data_ov016_0219d0c0.unknown_48_; } while (data_ov016_0219d0c0.frames - used == 0);
						}
						func_ov016_0218e768(node, data_ov016_0219d0c0.unknown_30_ + pos);
						func_ov016_0218e768(node, data_ov016_0219d0c0.unknown_2c_ + data_ov016_0219d0c0.pos);
						CleanCacheRange(data_ov016_0219d0c0.unknown_30_ + data_ov016_0219d0c0.pos, bytes);
						CleanCacheRange(data_ov016_0219d0c0.unknown_2c_ + data_ov016_0219d0c0.pos, bytes);
						pos = data_ov016_0219d0c0.pos + unit;
						data_ov016_0219d0c0.pos = pos;
						if (pos == data_ov016_0219d0c0.frames * unit) {
							data_ov016_0219d0c0.pos = pos = 0;
						}
						data_ov016_0219d0c0.unknown_50_ = data_ov016_0219d0c0.unknown_50_ + 1;
					}
					if (state == 0 && frame >= 6) {
						func_ov016_0218bce8(func_ov016_0218e660(node), unit);
						state = 1;
					}
				}
			}
			if (frame >= 6 || func_ov016_0218e660(node) == 0) {
				int diff = (int)(data_ov016_0219d0c0.unknown_50_ - data_ov016_0219d0c0.unknown_48_);
				if (data_ov016_0219d0c0.busy != 0 ||
					(diff <= (q + 1) * 3 && paused == 0 && func_ov016_0218e660(node) != 0)) {
					func_ov016_0218e72c(node);
					paused = 1;
				} else {
					func_ov016_0218bec4(node, arg1);
					paused = 0;
				}
			}

			{
				unsigned short keys = func_ov016_0218ca70();
				if (data_ov016_0219d0c0.unknown_0_ == 0) {
					keys &= ~0xa;
				}
				if (keys != var3) {
					var3 = keys;
					if (data_ov016_0219d0c0.unknown_0_ == 1) {
						if ((keys & 1) || (keys & 2) || (keys & 0x400) || (keys & 0x800) || (keys & 8)) {
							var4 = true;
							break;
						}
					} else if (keys & 8) {
						if (state == 1) {
							func_020d1f0c(3, 0, 1, 0);
							func_020d1fd0(3, 0);
							func_020d24c4(1);
						}
						while (func_ov016_0218ca70() != 0) {
							func_020c9778(0, 1);
						}
						while ((func_ov016_0218ca70() & 8) == 0) {
							func_020c9778(0, 1);
						}
						if (state == 1) {
							memset(data_ov016_0219d0c0.unknown_30_, 0, data_ov016_0219d0c0.frames * unit * 2);
							memset(data_ov016_0219d0c0.unknown_2c_, 0, data_ov016_0219d0c0.frames * unit * 2);
							CleanDataCache();
							data_ov016_0219d0c0.unknown_50_ = data_ov016_0219d0c0.unknown_50_ - data_ov016_0219d0c0.unknown_48_;
							data_ov016_0219d0c0.unknown_48_ = 0;
							data_ov016_0219d0c0.pos = (int)data_ov016_0219d0c0.unknown_50_ * unit;
							if (data_ov016_0219d0c0.pos == data_ov016_0219d0c0.frames * unit) {
								data_ov016_0219d0c0.pos = 0;
							}
							func_ov016_0218bce8(func_ov016_0218e660(node), unit);
						}
					} else if (keys & 2) {
						var4 = true;
						break;
					}
				}
			}

			if (data_ov016_0219d0c0.unknown_0_ == 1) {
				int var31, var32, var33, var34;
				int touched;
				g_touchInput.RefreshState();
				g_touchInput.GetTouchPoint(&var1, &var2);
				touched = (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ? 1 : 0;
				switch (GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance())) {
				case 1:
					var31 = 0x4c; var32 = 0xbd; var33 = 0x67; var34 = 0x98;
					break;
				case 2:
					var31 = 0x4c; var32 = 0xbd; var33 = 0x5d; var34 = 0xa2;
					break;
				case 3:
					var31 = 0x42; var32 = 0xc7; var33 = 0x57; var34 = 0xa7;
					break;
				case 4:
					var31 = 0x56; var32 = 0xb3; var33 = 0x67; var34 = 0x98;
					break;
				case 5:
					var31 = 0x46; var32 = 0xc3; var33 = 0x5d; var34 = 0xa2;
					break;
				default:
					var31 = 0x4c; var32 = 0xbd; var33 = 0x67; var34 = 0x98;
					break;
				}
				if (touched) {
					if (var31 <= var1 && var1 <= var32 && var2 >= 0x88 && var2 <= 0x97) {
						var4 = true;
						break;
					}
					if (var33 <= var1 && var1 <= var34 && var2 >= 0x98 && var2 <= 0xa9) {
						var4 = true;
						break;
					}
				}
			}
			cnt = cnt + 1;
			if (cnt == var6) {
				break;
			}
		}

		if (!var4) {
			unsigned int k;
			for (k = 0; k < 5; k++) {
				func_ov016_0218bec4(node, arg1);
			}
		}
		while (data_ov016_0219d0c0.unknown_14_ == 0) {
		}
		if ((func_020c7dcc() & 0x40000000) || (func_020c7dcc() & 0x80000000)) {
			if (state == 1) {
				func_020d1f0c(3, 0, 1, 0);
				func_020d1fd0(3, 0);
				func_020d24c4(1);
			}
		}
		CancelAlarm((Alarm*)&data_ov016_0219d118);
		((SafeAllocator*)data_ov016_0219d0c0.alloc)->Free(data_ov016_0219d0c0.unknown_30_);
		((SafeAllocator*)data_ov016_0219d0c0.alloc)->Free(data_ov016_0219d0c0.unknown_2c_);
		func_ov016_0218e640(node);
		NitroVM_FinishRead((NitroVM*)vm);
		if (data_ov016_0219d0c0.info->id > -1) {
			if (data_ov016_0219d0c0.info->isSet != 0) {
				SoundPlayer_StopStream(&g_bgmPlayer, 0, 0);
			} else {
				SoundPlayer_StopSeqOnHandle(&g_bgmPlayer, &data_ov016_0219d0cc, 0);
			}
			func_020bbd9c();
		}
	}
}
}
