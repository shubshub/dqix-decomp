#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" unsigned int func_020c8534(int arg0);
extern "C" unsigned int func_020c8520(int arg0);
extern "C" unsigned int func_ov016_0218fc78(void);
extern "C" unsigned int func_ov016_0218fc84(void);
extern "C" void func_ov016_0218fc8c(void*, unsigned int);
extern "C" void func_ov016_0218fcac(void*, int);
struct NitroVM;
void NitroVM_Initialize(NitroVM*);
int NitroVM_PrepareReadFileByPath(NitroVM*, char const*);
void NitroVM_FinishRead(NitroVM*);
extern "C" void* func_ov016_0218e558(void* arg0, int arg1);
extern "C" unsigned int func_ov016_0218e690(void* arg0);
extern "C" unsigned int func_ov016_0218e6a8(void* arg0);
extern "C" unsigned int func_ov016_0218e678(void* arg0);
extern "C" void* func_ov016_0218e660(void* arg0);
extern "C" unsigned int func_ov016_0218e750(void* arg0);
extern "C" int func_ov016_0218e6c0(void* arg0);
extern "C" void func_ov016_0218e6e4(void* arg0);
extern "C" void func_ov016_0218e72c(void* arg0);
extern "C" void func_ov016_0218e640(void* arg0);
extern "C" int func_ov016_0218e768(void* arg0, void* arg1);
extern "C" void func_ov016_0218bce8(void* arg0, unsigned int arg1);
extern "C" void func_ov016_0218bec4(void* arg0, int arg1);
extern "C" void func_020d1f0c(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_020d1fd0(int arg0, int arg1);
extern "C" void func_020d24c4(int arg0);
extern "C" void func_020c9778(int arg0, int arg1);
extern "C" void func_020bbd9c(void);
extern "C" int func_020ce89c(int arg0, int arg1, int arg2);
extern "C" unsigned short func_ov016_0218ca70(void);
extern "C" int func_020c7dcc(void);
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
void CleanDataCache(void);
void CleanCacheRange(const void* p, unsigned int n);
struct Alarm;
void ZeroInitializeAlarm(Alarm*);
unsigned long long GetCurrentTimestamp(void);
struct ProcessorContext;
void SetInterval(Alarm*, unsigned long long, unsigned long long, void (*)(ProcessorContext**), ProcessorContext**);
void CancelAlarm(Alarm*);
void SetKeyAndApplyRecord0203ad14(void*, int, void*, int);
struct Obj0203aba8;
void TryDispatchOrFallback0203aba8(Obj0203aba8*, void*, void*);
void UpdateScaleOrApplyRecord0203ae4c(void* a, int b, void* c);
void ScaleAndNotify0203ad88(void* a, void* b, int c);
void SetContextAndDispatch0203ac10(void* a, void* b, int c);
struct Struct0200fb08;
int GameState_GetLanguage(Struct0200fb08*);
void SetFlagAndMaybeIncrement_0218c024(void);

struct Struct_ov016_0218c04c {
	char unknown_0_[0x10];
	unsigned char unknown_10_;
	char unknown_11_;
	short unknown_12_;
	unsigned int unknown_14_;
};

struct Struct_ov016_0219d0c0_7 {
	int unknown_0_;
	int unknown_4_;
	void* unknown_8_;
	char unknown_c_[4];
	int unknown_10_;
	volatile int unknown_14_;
	int unknown_18_;
	int unknown_1c_;
	int unknown_20_;
	unsigned int unknown_24_;
	int unknown_28_;
	short* unknown_2c_;
	short* unknown_30_;
	Struct_ov016_0218c04c* unknown_34_;
	int unknown_38_;
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
extern "C" ARM void func_ov016_0218c04c(const char* arg0, int arg1) {
	unsigned char var0[0x48];
	int var1;
	int var2;
	unsigned short var3;
	bool var4;
	int var5;
	int var6;
	int var7;
	unsigned char var8;
	float var9;
	int var10;
	void* var11;
	int var12;
	unsigned int var13;
	unsigned int var14;
	unsigned int var15;
	unsigned int var16;
	unsigned int var17;

	var12 = 0;
	var3 = 0;
	var4 = false;
	var16 = func_020c8534(3);
	var14 = func_020c8520(3) - var16;
	if (var14 >= func_ov016_0218fc78()) {
		var14 = func_ov016_0218fc78();
	}
	var17 = func_020c8534(4);
	var15 = func_020c8520(4) - var17;
	if (var15 >= func_ov016_0218fc84()) {
		var15 = func_ov016_0218fc84();
	}
	func_ov016_0218fc8c((void*)func_020c8534(3), var14);
	func_ov016_0218fcac((void*)func_020c8534(4), var15);
	NitroVM_Initialize((NitroVM*)var0);

	if (NitroVM_PrepareReadFileByPath((NitroVM*)var0, arg0)) {
	var11 = func_ov016_0218e558(var0, 6);
	if (var11 != 0) {
		unsigned int var18 = 0;

		var5 = 0;
		var6 = func_ov016_0218e690(var11);
		var13 = func_ov016_0218e6a8(var11);
		var7 = (int)(((unsigned long long)(unsigned int)func_ov016_0218e660(var11) << 24) /
			((unsigned long long)var13 * func_ov016_0218e678(var11)));
		data_ov016_0219d0c0.unknown_24_ = (var7 + 1) * 7;
		data_ov016_0219d0c0.unknown_30_ = (short*)((SafeAllocator*)data_ov016_0219d0c0.unknown_8_)->Allocate(data_ov016_0219d0c0.unknown_24_ * var13 * 2);
		data_ov016_0219d0c0.unknown_2c_ = (short*)((SafeAllocator*)data_ov016_0219d0c0.unknown_8_)->Allocate(data_ov016_0219d0c0.unknown_24_ * var13 * 2);
		memset(data_ov016_0219d0c0.unknown_30_, 0, data_ov016_0219d0c0.unknown_24_ * var13 * 2);
		memset(data_ov016_0219d0c0.unknown_2c_, 0, data_ov016_0219d0c0.unknown_24_ * var13 * 2);
		CleanDataCache();
		var8 = 0;
		data_ov016_0219d0c0.unknown_48_ = var8;
		data_ov016_0219d0c0.unknown_28_ = var8;
		data_ov016_0219d0c0.unknown_50_ = var8;
		data_ov016_0219d0c0.unknown_18_ = var8;
		data_ov016_0219d0c0.unknown_14_ = 1;
		data_ov016_0219d0c0.unknown_1c_ = var8;
		data_ov016_0219d0c0.unknown_3c_ = var8;
		data_ov016_0219d0c0.unknown_20_ = var8;
		ZeroInitializeAlarm((Alarm*)&data_ov016_0219d118);
		{
			unsigned long long var19 = GetCurrentTimestamp();
			unsigned long long var20 = (0xf4240ULL << 24) / func_ov016_0218e678(var11);
			unsigned long long var21 = ((var20 * 0x82ea) >> 6) / 1000;
			SetInterval((Alarm*)&data_ov016_0219d118, var19 + 5, (unsigned int)var21, (void (*)(ProcessorContext**))func_ov016_0218c024, (ProcessorContext**)0);
		}
		data_ov016_0219d0c0.unknown_40_ = (GetCurrentTimestamp() << 6) / 0x82ea;
		var9 = (float)func_ov016_0218e678(var11) / 16777216.0f;
		var10 = 0;

		while (CallIfNonNullBool_0218e6c0(node)) {
			if (data_ov016_0219d0c0.started == 0) {
				Info_0218c04c* p = data_ov016_0219d0c0.info;
				unsigned long long t = (GetCurrentTimestamp() << 6) / 0x82ea;
				if (data_ov016_0219d0c0.startTime + p->delay <= t) {
					if (p->isSet != 0) {
						SetKeyAndApplyRecord0203ad14(&g_bgmPlayer, p->id, 0, 0);
					} else {
						TryDispatchOrFallback0203aba8((Obj0203aba8*)&g_bgmPlayer, (void*)p->id, &data_ov016_0219d0cc);
					}
					func_020bbd9c();
					data_ov016_0219d0c0.unknown_10_ = 1;
					var10 = var18;
				}
			}
			if ((*(unsigned short*)0x27fffa8 & 0x8000) >> 15) {
				data_ov016_0219d0c0.busy = 1;
				if (data_ov016_0219d0c0.info->isSet != 0) {
					UpdateScaleOrApplyRecord0203ae4c(&g_bgmPlayer, 1, 0);
					func_020ce89c(0xc, 0, 0);
					*(unsigned int*)(&g_bgmPlayer + 0xa8) =
						(unsigned int)(1000.0f * ((float)(frame - lastFrame) / scale));
					UpdateScaleOrApplyRecord0203ae4c(&g_bgmPlayer, 0, 0);
				} else {
					func_020ce89c(0xc, 0, 0);
				}
				data_ov016_0219d0c0.unknown_38_ = 0;
			}
			func_ov016_0218e6e4(var11);
			var18++;

			if ((func_020c7dcc() & 0x40000000) || (func_020c7dcc() & 0x80000000)) {
				if (func_ov016_0218e660(var11) != 0) {
					unsigned long long var24 = func_ov016_0218e750(var11);
					int var25 = 0;
					int var26 = data_ov016_0219d0c0.unknown_28_;
					unsigned int var27 = var13 * 2;
					for (; var25 < var24; var25++) {
						if (var12 != 0) {
							long long var28; do { var28 = data_ov016_0219d0c0.unknown_50_ - data_ov016_0219d0c0.unknown_48_; } while (data_ov016_0219d0c0.unknown_24_ - var28 == 0);
						}
						func_ov016_0218e768(var11, data_ov016_0219d0c0.unknown_30_ + var26);
						func_ov016_0218e768(var11, data_ov016_0219d0c0.unknown_2c_ + data_ov016_0219d0c0.unknown_28_);
						CleanCacheRange(data_ov016_0219d0c0.unknown_30_ + data_ov016_0219d0c0.unknown_28_, var27);
						CleanCacheRange(data_ov016_0219d0c0.unknown_2c_ + data_ov016_0219d0c0.unknown_28_, var27);
						var26 = data_ov016_0219d0c0.unknown_28_ + var13;
						data_ov016_0219d0c0.unknown_28_ = var26;
						if (var26 == data_ov016_0219d0c0.unknown_24_ * var13) {
							data_ov016_0219d0c0.unknown_28_ = var26 = 0;
						}
						data_ov016_0219d0c0.unknown_50_ = data_ov016_0219d0c0.unknown_50_ + 1;
					}
					if (var12 == 0 && var18 >= 6) {
						func_ov016_0218bce8(func_ov016_0218e660(var11), var13);
						var12 = 1;
					}
				}
			}
			if (var18 >= 6 || func_ov016_0218e660(var11) == 0) {
				int var29 = (int)(data_ov016_0219d0c0.unknown_50_ - data_ov016_0219d0c0.unknown_48_);
				if (data_ov016_0219d0c0.unknown_38_ != 0 ||
					(var29 <= (var7 + 1) * 3 && var8 == 0 && func_ov016_0218e660(var11) != 0)) {
					func_ov016_0218e72c(var11);
					var8 = 1;
				} else {
					func_ov016_0218bec4(var11, arg1);
					var8 = 0;
				}
			}

			{
				unsigned short var30 = func_ov016_0218ca70();
				if (data_ov016_0219d0c0.unknown_0_ == 0) {
					var30 &= ~0xa;
				}
				if (var30 != var3) {
					var3 = var30;
					if (data_ov016_0219d0c0.unknown_0_ == 1) {
						if ((var30 & 1) || (var30 & 2) || (var30 & 0x400) || (var30 & 0x800) || (var30 & 8)) {
							var4 = true;
							break;
						}
					} else if (var30 & 8) {
						if (var12 == 1) {
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
						if (var12 == 1) {
							memset(data_ov016_0219d0c0.unknown_30_, 0, data_ov016_0219d0c0.unknown_24_ * var13 * 2);
							memset(data_ov016_0219d0c0.unknown_2c_, 0, data_ov016_0219d0c0.unknown_24_ * var13 * 2);
							CleanDataCache();
							data_ov016_0219d0c0.unknown_50_ = data_ov016_0219d0c0.unknown_50_ - data_ov016_0219d0c0.unknown_48_;
							data_ov016_0219d0c0.unknown_48_ = 0;
							data_ov016_0219d0c0.unknown_28_ = (int)data_ov016_0219d0c0.unknown_50_ * var13;
							if (data_ov016_0219d0c0.unknown_28_ == data_ov016_0219d0c0.unknown_24_ * var13) {
								data_ov016_0219d0c0.unknown_28_ = 0;
							}
							func_ov016_0218bce8(func_ov016_0218e660(var11), var13);
						}
					} else if (var30 & 2) {
						var4 = true;
						break;
					}
				}
			}

			if (data_ov016_0219d0c0.unknown_0_ == 1) {
				int var31, var32, var33, var34;
				int var35;
				g_touchInput.RefreshState();
				g_touchInput.GetTouchPoint(&sx, &sy);
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
				if (var35) {
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
			var5 = var5 + 1;
			if (var5 == var6) {
				break;
			}
		}

		if (!var4) {
			unsigned int var36;
			for (var36 = 0; var36 < 5; var36++) {
				func_ov016_0218bec4(var11, arg1);
			}
		}
		while (data_ov016_0219d0c0.unknown_14_ == 0) {
		}
		if ((func_020c7dcc() & 0x40000000) || (func_020c7dcc() & 0x80000000)) {
			if (var12 == 1) {
				func_020d1f0c(3, 0, 1, 0);
				func_020d1fd0(3, 0);
				func_020d24c4(1);
			}
		}
		CancelAlarm((Alarm*)&data_ov016_0219d118);
		((SafeAllocator*)data_ov016_0219d0c0.alloc)->Free(data_ov016_0219d0c0.bufL);
		((SafeAllocator*)data_ov016_0219d0c0.alloc)->Free(data_ov016_0219d0c0.bufR);
		ClearAndReset_0218e640(node);
		NitroVM_FinishRead((NitroVM*)vm);
		if (data_ov016_0219d0c0.info->id > -1) {
			if (data_ov016_0219d0c0.info->isSet != 0) {
				ScaleAndNotify0203ad88(&g_bgmPlayer, 0, 0);
			} else {
				SetContextAndDispatch0203ac10(&g_bgmPlayer, &data_ov016_0219d0cc, 0);
			}
			func_020bbd9c();
		}
	}
}
}
