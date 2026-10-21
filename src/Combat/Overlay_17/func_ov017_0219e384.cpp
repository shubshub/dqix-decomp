#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "World/ZoneChest.h"
#include "Combat/ActorAction.h"
#include "GameState/Overlay17DayCycle.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/LootableContainer.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Memory.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_020daf90 func_020dc998
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

#if defined(jpn)
enum { Enum_ov017_0219e384_9196 = 0x240c, Enum_ov017_0219e384_2112 = 0x860, Enum_ov017_0219e384_17582 = 0x41fe, Enum_ov017_0219e384_17580 = 0x41fc, Enum_ov017_0219e384_17129 = 0x40c9, Enum_ov017_0219e384_14080 = 0x34f0, Enum_ov017_0219e384_14084 = 0x34f4, Enum_ov017_0219e384_14072 = 0x34e8, Enum_ov017_0219e384_15004 = 0x388c, Enum_ov017_0219e384_10271 = 0x285f, Enum_ov017_0219e384_14132 = 0x3524, Enum_ov017_0219e384_9144 = 0x23d8, Enum_ov017_0219e384_6240 = 0x1860, Enum_ov017_0219e384_14076 = 0x34ec, Enum_ov017_0219e384_23724 = 0x5a4c, Enum_ov017_0219e384_14104 = 0x3508, Enum_ov017_0219e384_14032 = 0x34c0, Enum_ov017_0219e384_32608 = 0x7c8c, Enum_ov017_0219e384_10118 = 0x27c6, Enum_ov017_0219e384_10116 = 0x27c4, Enum_ov017_0219e384_10120 = 0x27c8, Enum_ov017_0219e384_10100 = 0x27b4, Enum_ov017_0219e384_10112 = 0x27c0, Enum_ov017_0219e384_17586 = 0x4202, Enum_ov017_0219e384_174 = 0xfe, Enum_ov017_0219e384_17408 = 0x4100 };
#else
enum { Enum_ov017_0219e384_9196 = 0x23ec, Enum_ov017_0219e384_2112 = 0x840, Enum_ov017_0219e384_17582 = 0x44ae, Enum_ov017_0219e384_17580 = 0x44ac, Enum_ov017_0219e384_17129 = 0x42e9, Enum_ov017_0219e384_14080 = 0x3700, Enum_ov017_0219e384_14084 = 0x3704, Enum_ov017_0219e384_14072 = 0x36f8, Enum_ov017_0219e384_15004 = 0x3a9c, Enum_ov017_0219e384_10271 = 0x281f, Enum_ov017_0219e384_14132 = 0x3734, Enum_ov017_0219e384_9144 = 0x23b8, Enum_ov017_0219e384_6208 = 0x1840, Enum_ov017_0219e384_14076 = 0x36fc, Enum_ov017_0219e384_23724 = 0x5cac, Enum_ov017_0219e384_14104 = 0x3718, Enum_ov017_0219e384_14032 = 0x36d0, Enum_ov017_0219e384_32608 = 0x7f60, Enum_ov017_0219e384_10118 = 0x2786, Enum_ov017_0219e384_10116 = 0x2784, Enum_ov017_0219e384_10120 = 0x2788, Enum_ov017_0219e384_10100 = 0x2774, Enum_ov017_0219e384_10112 = 0x2780, Enum_ov017_0219e384_17586 = 0x44b2, Enum_ov017_0219e384_174 = 0xae, Enum_ov017_0219e384_17408 = 0x4400 };
#endif

#if defined(jpn)
enum { Enum_ov017_0219e384_52 = 0x54, Enum_ov017_0219e384_728 = 0x228 };
#else
enum { Enum_ov017_0219e384_52 = 0x34, Enum_ov017_0219e384_728 = 0x2d8 };
#endif

struct Struct_ov009_0218aa28 { int unknown_0_[3]; };

struct Struct_ov017_0219e384_2 {
	unsigned char unknown_0_;
	unsigned char unknown_1_;
	unsigned char unknown_2_[6];
	unsigned char unknown_8_;
	unsigned char unknown_9_;
	unsigned char unknown_a_;
	unsigned char unknown_b_;
	unsigned char unknown_c_[2];
	unsigned short unknown_e_;
	unsigned short unknown_10_;
	short unknown_12_;
	short unknown_14_;
	short unknown_16_;
	short unknown_18_;
	short unknown_1a_;
	short unknown_1c_;
	unsigned char unknown_1e_;
	unsigned char unknown_1f_;
	unsigned char unknown_20_;
	unsigned char unknown_21_;
	unsigned short unknown_22_;
	unsigned short unknown_24_;
	unsigned char unknown_26_[2];
	int unknown_28_;
};

struct Struct_ov017_0219e384 {
	int inline_ov017_0219e384() const { SDK_NULL_ASSERT(this); return unknown_24_; }

	unsigned short unknown_0_;
	unsigned char unknown_2_[8];
	unsigned char unknown_a_;
	unsigned char unknown_b_;
	unsigned char unknown_c_;
	unsigned char unknown_d_;
	unsigned char unknown_e_;
	unsigned char unknown_f_;
	int unknown_10_[3];
	short unknown_1c_;
	short unknown_1e_;
	int unknown_20_;
	int unknown_24_;
	int unknown_28_;
	int unknown_2c_;
	unsigned char unknown_30_[0x33];
	unsigned char unknown_63_;
	unsigned char unknown_64_;
	unsigned char unknown_65_[2];
	unsigned char unknown_67_;
	unsigned char unknown_68_;
	unsigned char unknown_69_;
	unsigned char unknown_6a_[2];
	short unknown_6c_;
	unsigned char unknown_6e_;
};

struct Struct_ov017_0219e384_3 {
	short inline_ov017_0219e384_2() const { SDK_NULL_ASSERT(this); return unknown_4_; }

	unsigned char unknown_0_[4];
	short unknown_4_;
	unsigned char unknown_6_[0x3e];
	int unknown_44_[3];
	unsigned char unknown_50_[4];
	int unknown_54_;
	unsigned char unknown_58_[0x60];
	unsigned short unknown_b8_;
	unsigned char unknown_ba_[4];
	unsigned char unknown_be_;
	unsigned char unknown_bf_[3];
	unsigned char unknown_c2_;
	unsigned char unknown_c3_[0x6d];
	unsigned int* unknown_130_;
	unsigned char unknown_134_[0x2c];
	unsigned char unknown_160_[6];
	unsigned short unknown_166_;
	unsigned char unknown_168_[2];
	unsigned short unknown_16a_;
#if defined(jpn)
	unsigned char unknown_16c_[0x3a];
#else
	unsigned char unknown1_16c_[0x46];
#endif
	unsigned short unknown_1b2_;
};

struct Struct_ov017_0219e384_4 {
	unsigned char unknown_0_[0xbe];
	unsigned char unknown_be_;
	unsigned char unknown_bf_[0x71];
	int unknown_130_;
	unsigned char unknown_134_[0x32];
	unsigned short unknown_166_;
	unsigned char unknown_168_[2];
	unsigned short unknown_16a_;
};

static inline int inline_ov017_0219e384_3(struct Struct_ov017_0219e384_4* arg0) {
	return *(int*)((char*)arg0 + 0x130);
}

struct Struct_ov017_0219e384_5 {
	unsigned char unknown_0_0_ : 1;
	unsigned char unknown_0_1_ : 7;
};

struct Struct_ov017_0219dc90_5 {
	unsigned char unknown_0_[2];
	unsigned char unknown_2_;
	unsigned char unknown_3_[5];
	void* unknown_8_;
	unsigned char unknown_c_[5];
	unsigned char unknown_11_;
	unsigned short unknown_12_;
#if !defined(jpn)
	unsigned char unknown_14_[4];
#endif
};

struct Struct_ov017_0219dc90_2 {
	unsigned char unknown_0_[2];
	unsigned short unknown_2_0_ : 2;
	unsigned short unknown_2_2_ : 2;
	unsigned short unknown_2_4_ : 12;
	unsigned short unknown_4_;
	unsigned char unknown_6_[7];
	unsigned char unknown_d_;
#if defined(jpn)
	unsigned char unknown_e_[6];
#else
	unsigned char unknown1_e_[0xa];
#endif
	int unknown_18_[3];
	unsigned char unknown_24_[0x10];
	int unknown_34_;
};

struct Struct_ov017_0219e384_6 {
	unsigned char unknown_0_[0xf78];
	unsigned char unknown_f78_[4];
	unsigned char unknown_f7c_;
	unsigned char unknown_f7d_;
};

struct Struct_ov017_0219e384_7 {
	unsigned char unknown_0_;
	unsigned char unknown_1_;
	unsigned short unknown_2_;
	unsigned short unknown_4_;
	unsigned short unknown_6_;
	int unknown_8_;
	unsigned char unknown_c_;
	unsigned char unknown_d_;
	unsigned char unknown_e_;
	unsigned char unknown_f_;
	unsigned char unknown_10_;
	unsigned char unknown_11_;
	unsigned char unknown_12_;
	unsigned char unknown_13_;
	int unknown_14_;
};

struct Struct_ov017_0219e384_8 {
	unsigned char unknown_0_[0xc];
	int unknown_c_;
	unsigned char unknown_10_[0x24];
};

struct Struct_ov017_0219e384_9 {
	unsigned int unknown_0_;
	unsigned int unknown_4_;
	void* unknown_8_;
	struct Struct_ov017_0219e384_7 unknown_c_;
	struct Struct_ov017_0219e384_7 unknown_24_;
	Struct_02014900 unknown_3c_;
	Struct_02014900 unknown_48_;
	Struct_02014900 unknown_54_;
	Struct_02014900 unknown_60_;
};

struct Struct_ov017_0219e384_10 {
	Struct_02014900 unknown_0_;
	signed char unknown_c_;
	unsigned char unknown_d_[0x2b];
	struct Struct_ov017_0219e384_8 unknown_38_;
	struct Struct_ov017_0219e384_7 unknown_6c_;
	Struct_02014900 unknown_84_;
	Struct_02014900 unknown_90_;
	char unknown_9c_[0x10];
	struct Struct_ov017_0219e384_8 unknown_ac_;
};

struct Struct_ov017_0219e384_11 {
	unsigned char unknown_0_[2];
	unsigned char unknown_2_;
	unsigned char unknown_3_[5];
	unsigned short unknown_8_;
#if defined(jpn)
	unsigned char unknown_a_[0x8d];
#else
	unsigned char unknown1_a_[0x91];
#endif
	unsigned char unknown_9b_;
	unsigned char unknown_9c_;
};

struct Struct_ov017_0219e384_12 { unsigned char unknown_0_[0x28]; };
struct Struct_01ff91ac_19;
struct Struct_0202b2f0;
struct BackgroundLoader;
struct Struct_01ff91ac_20 { unsigned short unknown_0_; unsigned short unknown_2_; };

extern "C" struct Struct_ov017_0219e384* func_0200fd0c(GameState*);
extern "C" void* func_02012fe4(void);
extern "C" void* func_02011584(void* arg0);
extern "C" struct Struct_ov017_0219dc90_2* func_02027ca4(void);
extern "C" void* func_0205ec34(void);
extern "C" struct Struct_0202b2f0* func_0202ae18(void);
extern "C" void* func_020d6c00(void);
extern "C" int func_02039d7c(char* arg0);
struct Vector3i;
extern "C" void func_02097cac(void* arg0);
struct Struct_0208f944;
extern "C" void func_0208f944(Struct_0208f944*);
extern "C" void func_020a696c(void* arg0, int arg1, int arg2);
struct Struct_02095924_2;
extern "C" void* func_02099950(Struct_02095924_2*, int);
extern "C" int func_0209cd50(int arg0);
struct Struct_0209cae8;
extern "C" int func_0209cae8(Struct_0209cae8*);
struct Struct_02109bf4_4;
extern "C" void func_0209c678(Struct_02109bf4_4*, int);
extern "C" int func_0203adfc(void* arg0, void* arg1);
extern "C" void func_0203ad88(void* arg0, void* arg1, int arg2);
struct Struct_02108760;
extern "C" void func_0205eaa0(Struct_02108760*, int, int);
struct Struct_02018300_3;
extern "C" void func_020397cc(Struct_02018300_3*, int);
extern "C" void func_ov017_021c4664(int arg0, struct Struct_ov009_0218aa28 arg1, int arg2);
extern "C" int func_0202c540(void* arg0);
extern "C" int func_020100b0(GameState*);
extern "C" void func_ov017_021d035c(unsigned char arg0, unsigned char arg1, unsigned char arg2);
extern "C" void func_ov017_021d257c(unsigned char arg0, int arg1);
extern "C" int func_020649b0(void* arg0, int arg1, void* arg2);
extern "C" void func_0206f81c(void* arg0);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_020535c8(signed char* arg0);
extern "C" void func_020531f0(void* arg0);
extern "C" int func_02046b08(void** arg0);
extern "C" void* func_020daf90(void);
struct Struct_02038598_5;
extern "C" int func_02046b60(Struct_02038598_5*, int);
extern "C" int func_020db2d4(void* arg0);
extern "C" void func_020daf9c(int arg0, int arg1, int arg2, int arg3);
extern "C" int func_0202b7d8(int* arg0);
struct Struct_0202c1a4;
extern "C" void* func_0202c1a4(Struct_0202c1a4*);
extern "C" void func_0202c5bc(struct Struct_0202b2f0* arg0, int arg1);
extern "C" void func_020466e4(unsigned int*, unsigned int);
extern "C" void func_ov017_0219d250(void* arg0, unsigned char arg1);
extern "C" int func_020bc0f8(int arg0, int arg1);
extern "C" void func_ov017_0219c598(int arg0, int arg1, int arg2);
extern "C" int func_02028a54(struct Struct_ov017_0219dc90_2* arg0, int arg1);
struct Struct_020fdd44;
extern "C" struct Struct_ov017_0219dc90_2* func_02028bd0(Struct_020fdd44*, int);
extern "C" int func_0201b588(int arg0);
struct Struct_ov017_0219dc90_3;
extern "C" void func_ov017_021b46d8(Struct_ov017_0219dc90_3*);
extern "C" int func_0201b5d8(int arg0);
struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(Struct_0201bdac_2*, Struct_0201bdac*);
extern "C" int func_0202c508(void* arg0);
extern "C" void func_ov017_021c4854(Zone3D* arg0, int arg1, int arg2, int* arg3, int arg4, int arg5);
extern "C" int func_02039790(void* arg0, int arg1);
extern "C" void func_ov017_021bd4d0(void* arg0, unsigned char arg1, int arg2, int arg3);
extern "C" void func_ov017_021ce400(unsigned char arg0, int arg1);
extern "C" void* func_0208e0a8(void);
extern "C" void func_0208e520(void* arg0, void* arg1);
extern "C" int sprintf(char* arg0, const char* arg1, ...);
extern "C" char* strcpy(char* arg0, const char* arg1);
extern "C" int func_020981e4(int, int);
extern "C" int func_02098210(int, int);
extern "C" void* func_0208e9e8(void);
extern "C" signed char* func_020100f8(char*);
struct Struct_0209c3b4_2;
extern "C" void func_0209c3b4(Struct_0209c3b4_2*, int);
struct Struct_0201bdac_4;
extern "C" int func_02086b98(Struct_0201bdac_4*);
struct Struct_0209caa0;
extern "C" void func_0209caa0(Struct_0209caa0*, int);
extern "C" void func_02064b98(unsigned char*, int);
struct Struct_02038598_4;
extern "C" void func_020466f4(Struct_02038598_4*, unsigned int);
struct Struct_0208f3a8;
extern "C" void func_0208f3a8(Struct_0208f3a8*);
extern "C" void func_0206461c(void* arg0, void* arg1);
extern "C" void* func_02094d6c(void);
extern "C" void func_02095b30(void* arg0, int arg1);
extern "C" void func_02097ec8(void* arg0);
extern "C" void func_ov017_021a2fa0(void* arg0);
extern "C" void func_ov017_0219e180(void* arg0, int arg1);
extern "C" void func_0208f168(void* arg0, void* arg1);
extern "C" void _ZN8Object3D10SetField06Et(void* arg0, int arg1);
extern "C" void func_0208fc30(void* arg0);
struct Struct_020733c8;
extern "C" void func_020733c8(Struct_020733c8*);
extern "C" int func_02028460(int* arg0, int* arg1);
extern "C" void func_ov017_021901ac(void* arg0);
extern "C" void func_020a6aac(void* arg0, int arg1, int arg2);
extern "C" void func_020acecc(void* arg0, int arg1, int arg2);
extern "C" int func_ov017_021a01f4(void* arg0, int arg1, int arg2, void* arg3, int* arg4);
extern "C" void func_ov017_0219fc88(void* arg0, int arg1);
extern "C" void func_ov017_021b6f18(void* arg0);
extern "C" void func_ov017_02196c08(unsigned char*);
extern "C" int func_020100a8(GameState*);
extern "C" void func_ov017_021b6e70(struct Struct_ov017_0219e384_7* arg0, int arg1);
extern "C" void func_ov017_021b7104(void* arg0, struct Struct_ov017_0219e384_7* arg1);
extern "C" int func_020649f4(void* arg0, void* arg1);
int LoadFileIntoMemory(const char* name, void* dst, unsigned int* size);
struct Struct_02013fb4;
extern "C" int func_0208dc00(Struct_02013fb4*, int, int);
extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
extern "C" void func_ov017_021bba08(struct Struct_ov017_0219e384_11* arg0, void* arg1);
extern "C" void func_0206df6c(void* arg0, unsigned char* arg1, int arg2, int arg3);
extern "C" void func_ov017_021d23bc(unsigned short arg0);
extern "C" void func_020a2788(void* arg0, short arg1);
struct Struct_020a27cc;
extern "C" void func_020a27cc(Struct_020a27cc*);
struct Struct_020a2800;
extern "C" void func_020a2800(Struct_020a2800*);
extern "C" void func_020a2830(void* arg0);
struct Struct_020a2868;
extern "C" void func_020a2868(Struct_020a2868*);
struct Struct_0204a170;
extern "C" int func_020a3570(Struct_0204a170*);
extern "C" void func_0202ec5c(char*, int*);
extern "C" void func_ov017_021982ac(void* arg0);
extern "C" void func_020a2718(char*);
extern "C" void func_020dc2d0(int arg0);
struct Struct_020a2cbc;
extern "C" void func_020a2cbc(Struct_020a2cbc*, int);
extern "C" void func_020ae53c(int arg0);
extern "C" void func_020a8740(void);
extern "C" void func_02026b7c(unsigned char*);
extern "C" void func_ov017_021a3338(void* arg0);
extern "C" void func_ov017_021a65c4(void* arg0, unsigned char arg1, int arg2);
extern "C" void func_ov017_021cdaa0(void);
extern "C" void func_020397c0(void* arg0);
extern "C" void func_ov017_021d2ad0(short, int, int, int, unsigned char);
extern "C" void* func_020421a0(void);
extern "C" void func_ov017_021a7a74(void* arg0, struct Struct_ov017_0219e384_7* arg1);
extern "C" int func_02076ccc(void* arg0, int arg1);
extern "C" void func_020a72ac(void* arg0, unsigned char arg1);
extern "C" void* func_020936f8(void);
extern "C" void func_02094030(void* arg0, int arg1, int arg2, int arg3);

extern int data_02109bf4;
extern int data_02108760;
extern const char data_ov017_021d75fc[];
extern const char data_ov017_021d7619[];
extern const char data_ov017_021d761e[];
extern char data_0211e33c[];

// USA: func_ov017_0219e384
extern "C" ARM void func_ov017_0219e384(struct Struct_ov017_0219e384_2* arg0, void* arg1) {
	GameState* var0 = GameState::GetInstance();
	char* var1 = (char*)GetGameResources();
	void* var2 = var0->GetProtagonist();
	struct Struct_ov017_0219e384_3* var3 = (struct Struct_ov017_0219e384_3*)var0->GetUnknownGameObject();
	struct Struct_ov017_0219e384* var4 = func_0200fd0c(var0);
	struct BackgroundLoader* var5 = BackgroundLoader::GetInstance();
	Zone3D* var6 = (Zone3D*)func_02012fe4();
	char* var7 = (char*)var6 + Enum_ov017_0219e384_9196;
	int var8 = (int)var6 + Enum_ov017_0219e384_2112;
	void* var9 = func_02011584(var0);
	struct Struct_ov017_0219dc90_2* var10 = func_02027ca4();
	void* var11 = func_0205ec34();
	struct Struct_ov017_0219e384_6* var12 = (struct Struct_ov017_0219e384_6*)func_02010828(var0);
	struct Struct_0202b2f0* var13 = func_0202ae18();
	char* var14 = (char*)LootableContainerManager::GetMainInstance();
	void* var15 = func_020d6c00();
	int* var16 = (int*)LightingManager::GetInstance();
	struct Struct_ov017_0219e384_10 var17;
	struct Struct_ov017_0219e384_9 var18;

	if (arg0->unknown_8_ == 0) {
		Struct_02037d10* var19 = func_020399a8(var3);
		if (func_02039d7c((char*)var3) != 0 && var19->unknown_1_ != 2 && var4->unknown_6c_ != 9999) {
			if (var4->unknown_67_ != 0) {
				*(Vector3i*)var4->unknown_10_ = *(Vector3i const*)var3->unknown_44_;
			}
			return;
		}
		{
			int var20;
			int var21;
			int var22;
			void* var23;
			int var24;
			int var25;
			unsigned short* var26;
			void* var27;
			unsigned char* var28;

			func_02097cac((void*)var8);
			func_0208f944((Struct_0208f944*)var7);
			var24 = var6->currentZoneID_;
			func_020a696c(var1, var4->unknown_0_, var24);
			var27 = func_02099950((Struct_02095924_2*)var9, var4->unknown_0_);
			var28 = (unsigned char*)var6->pUnknownStruct_8_;
			arg0->unknown_a_ = 1;
			if (var27 != 0 && var28 != 0) {
				if (func_0209cd50(var4->unknown_0_) == func_0209cae8((Struct_0209cae8*)&data_02109bf4)) {
					arg0->unknown_a_ = 0;
				}
			}
			if (var4->unknown_20_ > 0) {
				arg0->unknown_a_ = 0;
			}
			if (arg0->unknown_a_ != 0) {
				func_0209c678((Struct_02109bf4_4*)&data_02109bf4, 0);
			}
			if (func_0203adfc(&data_02108760, 0) != 0) {
				func_0203ad88(&data_02109bf4, 0, 0);
				arg0->unknown_a_ = 1;
			}
			var25 = *(unsigned short*)((char*)var3->unknown_130_ + 4);
			var22 = 15;
			if (var25 <= 0) {
				var22 = 60;
			}
			delta = -16;
			axis = 1;
			if (IsBrightnessZero((GameResources*)ov, false) == 0 &&
			    IsBrightnessZero((GameResources*)ov, true) == 0 &&
			    GetBrightnessTransitionStates((GameResources*)ov) != 0x101) {
				axis = 0;
				if (GetBrightness((GameResources*)ov, axis) > Brightness_Normal) {
					delta = 16;
				}
				var22 = 0;
			}
			if ((var4->unknown_6e_ & 0x10) == 0) {
				if ((var4->unknown_6e_ & 1) != 0) {
					SetMainBrightness((GameResources*)var1, var20, var22);
				} else {
					SetBrightness((GameResources*)var1, var20, var22);
				}
			}
			if (var4->unknown_c_ == 1) {
				func_0205eaa0((Struct_02108760*)&data_02108760, 15, 0);
			}
			func_020397cc((Struct_02018300_3*)var3, 1);
			var3->unknown_c2_ &= ~0x40;
			var26 = (unsigned short*)(var1 + Enum_ov017_0219e384_174);
			var26 = (unsigned short*)((char*)var26 + Enum_ov017_0219e384_17408);
			*(unsigned short*)(var1 + Enum_ov017_0219e384_17582) = 0;
			var26[1] = 0;
			func_ov017_021c4664(var4->unknown_0_, *(struct Struct_ov009_0218aa28*)var4->unknown_10_, var4->unknown_1c_);
			if (func_0202c540(var13) != 0 && var4->unknown_67_ != 0 && *(unsigned short*)(var1 + Enum_ov017_0219e384_17580) != 0) {
				*(unsigned short*)(var1 + Enum_ov017_0219e384_17580) = 0;
			}
			if (var4->unknown_e_ != 0) {
				func_ov017_021d035c(0, func_020100b0(var0), 1);
			}
			var24 = var6->currentZoneID_;
			if (var4->unknown_0_ != var24) {
				struct Struct_ov017_0219e384_6* var29 = (struct Struct_ov017_0219e384_6*)func_02010828(var0);
				int var30;
				for (var30 = 0; var30 < var29->unknown_f7c_; var30++) {
					func_ov017_021d257c(var29->unknown_f78_[var30], 0);
				}
			}
			if (*(unsigned char*)(var1 + Enum_ov017_0219e384_17129) != 0) {
				var4->unknown_a_ = 0;
			}
			var23 = func_0205ec34();
			var17.unknown_ac_.unknown_c_ = var6->currentZoneID_;
			if (var4->unknown_a_ == 0 && func_020649b0(var23, 0x1e, &var17.unknown_ac_) != 0) {
				func_0206f81c(&var17.unknown_ac_);
			}
			if (var21 == 0) {
				arg0->unknown_8_ = 2;
				return;
			}
			arg0->unknown_8_ = 1;
		}
		return;
	}
	if (arg0->unknown_8_ == 1) {
		if (IsBrightnessTransitionActive((GameResources*)var1) == 0) {
			arg0->unknown_8_ = 2;
		}
		return;
	}
	if (arg0->unknown_8_ == 2) {
		void* var31;
		void** var32;
		if (var3 != 0 && func_020535c8((signed char*)var3) != 0) {
			func_020531f0(var3);
		}
		if (var5->GetNumQueuedTasks() > 0) {
			return;
		}
		if (func_02046b08(*(void***)(var1 + Enum_ov017_0219e384_14080)) == 0) {
			return;
		}
		var31 = func_020daf90();
		var32 = *(void***)(var1 + Enum_ov017_0219e384_14084);
		if (func_02046b08(var32) == 0) {
			if (func_02046b60((Struct_02038598_5*)var32, 0x4c) == 0) {
				return;
			}
			if (func_020db2d4(var31) != 0) {
				return;
			}
			func_020daf9c(1, 0, 1, 0);
			SetBrightness((GameResources*)var1, -16, 0);
			return;
		}
		if (func_0202b7d8((int*)var13) != 0 &&
		    func_0202c1a4((Struct_0202c1a4*)var13) != 0 &&
		    TestFlags00((GameResources*)var1, 2) == 0) {
#if !defined(jpn)
			arg0->unknown_28_ = arg0->unknown_28_ + var0->GetEffectiveDeltaTime();
			if (arg0->unknown_28_ > 15000) {
				arg0->unknown_b_ = 1;
				func_0202c5bc(var13, 0);
			}
#endif
			if (arg0->unknown_b_ == 0) {
				return;
			}
#if !defined(jpn)
			arg0->unknown_28_ = 0;
#endif
		}
		if (var4->unknown_6e_ != 1) {
			SetFlags04((GameResources*)var1, 1);
			func_020466e4((unsigned int*)var15, 1);
		}
		SetFlags00((GameResources*)var1, 0x10);
		func_ov017_0219d250(var1, arg0->unknown_9_);
		arg0->unknown_9_ = 0;
		arg0->unknown_8_ = 3;
		return;
	}
	if (arg0->unknown_8_ == 3) {
		struct Struct_ov017_0219dc90_2* var33;
		int var34;
		struct Struct_ov017_0219dc90_2* var35;
		signed char* var36;
		unsigned char var37;
		unsigned short var38;
		char* var39;
		int var40;

		if (func_020bc0f8(0x64, 15) > 0) {
			return;
		}
		if (var6->unknown_424_ != 0) {
			return;
		}
		if (var5->GetNumQueuedTasks() > 0) {
			return;
		}
		func_ov017_0219c598(0, 0, 0);
		var33 = func_02027ca4();
		var34 = func_02028a54(var33, var6->currentZoneID_);
		var35 = func_02028bd0((Struct_020fdd44*)var33, var6->currentZoneID_);
		*(struct Struct_ov017_0219dc90_2**)(var1 + Enum_ov017_0219e384_14072) = var35;
		var36 = (signed char*)var0->GetGrottoStruct();
		if (func_0201b588(var6->currentZoneID_) != 0) {
			var35->unknown_d_ = var36[8];
		}
		var37 = 0;
		var38 = 0;
		var39 = &((char*)var6)[Enum_ov017_0219e384_9196];
		if (var34 != 0 && var35 != 0) {
			void* var41 = *(void**)(var1 + Enum_ov017_0219e384_14084);
			int var42 = var35->unknown_2_0_;
			var42 *= sizeof(struct Struct_ov017_0219dc90_5);
			struct Struct_ov017_0219dc90_5* var43 = (struct Struct_ov017_0219dc90_5*)(var1 + Enum_ov017_0219e384_15004 + var42);
			if (var43->unknown_2_ == 0) {
				func_ov017_021b46d8((Struct_ov017_0219dc90_3*)var43);
				var43->unknown_8_ = var35;
				if (func_0201b5d8(var6->currentZoneID_) != 0 && ((unsigned char*)var36)[3] == 0) {
					unsigned char* var44 = (unsigned char*)((ActiveGrottoClass*)var39)->GetDetailedData();
					if (var44 != 0) {
						unsigned char var45 = var44[1];
						if (var45 == 1) {
							var43->unknown_11_ = var45;
							var43->unknown_12_ = *(unsigned short*)(var44 + 0x54);
						} else if (var45 == 2) {
							var43->unknown_11_ = var45;
							var43->unknown_12_ = ((DetailedTreasureMapData::LegacyBossMapData*)(var44 + 0x4c))->MaybeGetCurrentAlternateID();
						}
						var37 = var43->unknown_11_;
						var38 = var43->unknown_12_;
					}
				}
				func_020469b4((Struct_0201bdac_2*)var41, (Struct_0201bdac*)var43);
			}
			arg0->unknown_8_ = 4;
		} else {
			if (func_0201b5d8(var6->currentZoneID_) != 0 && ((unsigned char*)var36)[3] == 0) {
				unsigned char* var46 = (unsigned char*)((ActiveGrottoClass*)var39)->GetDetailedData();
				if (var46 != 0) {
					unsigned char var47 = var46[1];
					if (var47 == 1) {
						var37 = var47;
						var38 = *(unsigned short*)(var46 + 0x54);
					} else if (var47 == 2) {
						var37 = var47;
						var38 = ((DetailedTreasureMapData::LegacyBossMapData*)(var46 + 0x4c))->MaybeGetCurrentAlternateID();
					}
				}
			}
			arg0->unknown_8_ = 5;
		}
		var40 = 0;
		if (func_0202c508(var13) != 0 && *(unsigned char*)((char*)var6 + Enum_ov017_0219e384_10271) != 0) {
			var40 = 1;
		}
		*(unsigned char*)((char*)var6 + Enum_ov017_0219e384_10271) = 0;
		if (var4->unknown_20_ > 0 || var4->unknown_24_ > 0) {
			func_ov017_021d035c(1, var3->unknown_4_, 1);
		}
		func_ov017_021c4854(var6, var37, var38, var3->unknown_44_, (short)var3->unknown_54_, var40);
		{
			void* var48 = *(void**)(var1 + Enum_ov017_0219e384_14132);
			if (func_0202b7d8((int*)var13) != 0) {
				int var49;
				for (var49 = 0; var49 < 4; var49++) {
					void* var50 = var0->GetPartyMemberByIndex(var49);
					if (var50 != 0 && func_02039790(var50, 0x20) != 0) {
						func_ov017_021bd4d0(var48, var49, 0, 1);
					}
				}
			}
		}
		if (func_0202c508(var13) != 0 && var12->unknown_f7d_ != 0) {
			func_ov017_021ce400(var12->unknown_f7d_, var6->currentZoneID_);
		}
		return;
	}
	if (arg0->unknown_8_ == 4) {
		if (func_02046b08(*(void***)(var1 + Enum_ov017_0219e384_14084)) != 0) {
			arg0->unknown_8_ = 5;
		}
		return;
	}
	if (arg0->unknown_8_ == 5) {
		func_0208e520(func_0208e0a8(), var6->pUnknownStruct_8_->mapShortName_);
		((SafeAllocator*)(var1 + 0x18c))->Reset();
		((LootableContainerManager*)var14)->Reset();
		data_ov017_021d75b8.unknown_4_ = var5->QueueLoadFile(data_ov017_021d75fc, 0);
		arg0->unknown_8_ = 6;
		return;
	}
	if (arg0->unknown_8_ == 6) {
		if (var5->GetTaskStatus(data_ov017_021d75b8.unknown_4_) == 0) {
			return;
		}
		if (var5->GetDetailedTaskStatus(data_ov017_021d75b8.unknown_4_) == 2) {
			var5->GetLoadedFileByID(data_ov017_021d75b8.unknown_4_, &var18.unknown_8_, &var18.unknown_4_);
			if (var18.unknown_8_ != 0) {
				unsigned char* var51 = (unsigned char*)var6->pUnknownStruct_8_;
				if (*(unsigned char*)((char*)var6 + Enum_ov017_0219e384_9144) != 0) {
					func_0201afd0(var6, var18.unknown_8_, var18.unknown_4_, 0);
				} else {
					unsigned short var52 = *(unsigned short*)var51;
					if (var52 >= 0xc546 && var52 <= 0xc546 + 0x15) {
						sprintf(var17.unknown_9c_, data_ov017_021d7619, (char*)var51 + 5, var52 + (0x61 - 0xc546));
					} else {
						strcpy(var17.unknown_9c_, (char*)var51 + 5);
					}
					((LootableContainerManager*)var14)->LoadZoneContainers(var18.unknown_8_, var18.unknown_4_, var17.unknown_9c_, (SafeAllocator*)0);
					func_0201647c(var6);
				}
			}
		}
		var5->RemoveTask(data_ov017_021d75b8.unknown_4_);
		{
			unsigned short var53 = var6->currentZoneID_;
			data_ov017_021d75b8.unknown_4_ = -1;
			if (func_020981e4((int)var8, var53) != 0 &&
			    func_02098210((int)var8, var53) == 0 &&
			    func_0202c540(var13) != 0) {
				unsigned char* var54 = (unsigned char*)var8;
				if (var54[0x1b62] == 0) {
					func_020daf9c(1, 0, 1, 0);
					SetBrightness((GameResources*)var1, -16, 0);
					arg0->unknown_8_ = 7;
					return;
				}
			}
		}
		arg0->unknown_8_ = 8;
		return;
	}
	if (arg0->unknown_8_ == 7) {
		unsigned char* var55 = (unsigned char*)var8;
		if (var55[0x1b62] != 0) {
			arg0->unknown_8_ = 8;
		}
		return;
	}
	if (arg0->unknown_8_ == 8) {
		void* var56;
		void* var57;
		int var58;
		int var59;
		unsigned char* var60;
		char* var61;
		struct Struct_ov017_0219dc90_2* var62;
		signed char* var63;
		int var64;
		struct Struct_ov017_0219e384_11* var65;

		if (var5->GetNumQueuedTasks() > 0) {
			return;
		}
		if (func_0202c540(var13) != 0 && var4->unknown_67_ != 0 && arg0->unknown_20_ == 0 && var4->unknown_24_ <= 0) {
			if (arg0->unknown_24_ != 0xffff) {
				if (arg0->unknown_24_ != 0) {
					var4->unknown_24_ = arg0->unknown_24_;
					var4->unknown_d_ = 1;
				} else if (*(unsigned short*)(var1 + Enum_ov017_0219e384_17580) != 0) {
					var4->unknown_24_ = *(unsigned short*)(var1 + Enum_ov017_0219e384_17580);
					*(unsigned short*)(var1 + Enum_ov017_0219e384_17580) = 0;
				} else {
					arg0->unknown_22_ = arg0->unknown_22_ + var0->GetEffectiveDeltaTime();
					if (arg0->unknown_22_ < 1000) {
						return;
					}
				}
			}
		}
		var56 = *(void**)(var1 + Enum_ov017_0219e384_14076);
		var57 = func_0208e9e8();
		var58 = var6->currentZoneID_;
		var59 = var6->previousZoneID_;
		var60 = (unsigned char*)var6->pUnknownStruct_8_;
		var61 = (char*)var6 + 0xc;
		var62 = func_02028bd0((Struct_020fdd44*)var10, var58);
		var63 = func_020100f8((char*)var0);
		var17.unknown_90_ = *(Struct_02014900*)var3->unknown_44_;
		var64 = (var4->unknown_20_ > 0) ? 1 : 0;
		if (var64 != 0) {
			arg0->unknown_a_ = 0;
		}
		var65 = *(struct Struct_ov017_0219e384_11**)(var1 + Enum_ov017_0219e384_14132);
		if (var65->unknown_2_ != 0 && var65->unknown_9b_ != 0) {
			arg0->unknown_a_ = 0;
			var65->unknown_9b_ = 0;
		} else if (var4->inline_ov017_0219e384() >= 0) {
			int var66 = ((*var3->unknown_130_ & 1) != 0);
			if (var66 != 0) {
				if (var4->unknown_24_ < 21000 || var4->unknown_24_ >= 40000) {
					arg0->unknown_a_ = 1;
				}
			}
		}
		if (arg0->unknown_a_ != 0) {
			func_0209c3b4((Struct_0209c3b4_2*)&data_02109bf4, func_0209cd50(var58));
			if (func_0202b7d8((int*)var13) != 0 && func_02086b98((Struct_0201bdac_4*)var12) != 0) {
				func_0209c678((Struct_02109bf4_4*)&data_02109bf4, 0);
			}
		}
		func_0209caa0((Struct_0209caa0*)&data_02109bf4, ((unsigned int)var60[0xd] << 24) >> 31);
		func_02064b98((unsigned char*)var11, *(unsigned short*)var60);
		func_020466f4((Struct_02038598_4*)var15, 0x200000);
		if (var4->unknown_a_ == 0) {
			func_0208f3a8((Struct_0208f3a8*)var57);
			func_0206461c(var11, (unsigned char*)var6->pUnknownStruct_8_);
			func_02095b30(func_02094d6c(), 0);
		}
		if (func_0202c508(var13) != 0) {
			struct Struct_ov017_0219dc90_2* var67 = func_02028bd0((Struct_020fdd44*)var10, var6->currentZoneID_);
			if (var67 != 0) {
				func_02013cb0(var6, var67->unknown_2_4_);
				func_02018c74(var6, var67->unknown_4_);
			}
		} else if (var64 == 0 && *(unsigned char*)((char*)var0 + Enum_ov017_0219e384_23724) == 0) {
			func_02013cb0(var6, arg0->unknown_e_);
			func_02018c74(var6, arg0->unknown_10_);
		}
		func_02097ec8((char*)var6 + Enum_ov017_0219e384_2112);
		if ((var4->unknown_6e_ & 2) == 0) {
			func_ov017_021a2fa0(var1);
		}
		func_ov017_0219e180(var1, var58);
		if (var4->unknown_a_ == 0) {
			struct Struct_ov017_0219e384_12* var68 = (struct Struct_ov017_0219e384_12*)(var1 + 0x18c) + 1;
			((SafeAllocator*)var68)->Reset();
			func_0208f168(var57, var68);
		}
		_ZN8Object3D10SetField06Et(var2, var58);
		func_0208fc30(var7);
		if (var62 != 0) {
			func_020733c8((Struct_020733c8*)var62);
			if (var62->unknown_34_ != 0) {
				var3->unknown_b8_ = func_02028460(var62->unknown_18_, var3->unknown_44_);
				var3->unknown_c2_ |= 0x40;
			}
		}
		ClearFlags04((GameResources*)var1, 1);
		ClearFlags00((GameResources*)var1, 0x10);
		func_ov017_021901ac(var1);
		func_020a6aac(var1, var58, var59);
		func_020acecc(var1, var58, var59);
		if ((var4->unknown_6e_ & 2) == 0 && func_0202c540(var13) != 0 && var3 != 0) {
			if (func_ov017_021a01f4(var1, var58, var0->GetTimeOfDay(), var3, (int*)&var17.unknown_84_) != 0 && var3 != 0) {
				*(Vector3i*)var3->unknown_44_ = *(Vector3i const*)((int*)&var17.unknown_84_);
			}
		}
		if (var64 != 0) {
			func_ov017_0219fc88(arg0, var4->unknown_20_);
		} else if (var4->unknown_28_ >= 0 && var4->unknown_2c_ == var6->currentZoneID_ && var4->unknown_1e_ != var4->unknown_28_) {
			if (func_0201b5d8(var6->currentZoneID_) == 0) {
			void* var69 = *(void**)(var1 + Enum_ov017_0219e384_14104);
			func_ov017_021b6f18(var69);
			func_ov017_02196c08((unsigned char*)&var17.unknown_6c_);
			var17.unknown_6c_.unknown_0_ = 1;
			var17.unknown_6c_.unknown_1_ = func_020100a8(var0);
			var17.unknown_6c_.unknown_4_ = var4->unknown_28_ + 5 + 0x8000;
			var17.unknown_6c_.unknown_2_ = 0xffff;
			var17.unknown_6c_.unknown_8_ = var4->unknown_28_;
			var17.unknown_6c_.unknown_12_ = var16[0x26];
			func_ov017_021b6e70(&var17.unknown_6c_, var17.unknown_6c_.unknown_2_);
			func_ov017_021b7104(var69, &var17.unknown_6c_);
			func_020469b4((Struct_0201bdac_2*)var56, (Struct_0201bdac*)var69);
			var4->unknown_28_ = -1;
			var4->unknown_6e_ |= 1;
			ClearFlags00((GameResources*)var1, 0x800);
			}
		} else if (var4->unknown_24_ >= 0) {
			func_ov017_0219fc88(arg0, var4->unknown_24_);
		} else {
			void* var70 = func_0205ec34();
			int var71;
			var17.unknown_38_.unknown_c_ = var58;
			if (var4->unknown_a_ == 0 && func_020649f4(var70, &var17.unknown_38_) != 0) {
				func_0206f81c(&var17.unknown_38_);
			}
			var71 = func_02046b60((Struct_02038598_5*)var56, 4);
			if (func_0202b7d8((int*)var13) == 0 || func_0202c508(var13) != 0) {
				BackgroundLoader::AddLockGlobal();
				if (LoadFileIntoMemory(data_ov017_021d761e, data_0211e33c, &var18.unknown_0_) != 0 &&
				    func_0208dc00((Struct_02013fb4*)data_0211e33c, var18.unknown_0_, (int)&var17.unknown_c_) != 0 &&
				    func_0206dfb0((int)var70, (unsigned char*)var70 + 0x8c, var17.unknown_c_ + 0xea + 0xb00) == 0) {
					if (var71 == 0) {
						struct Struct_ov017_0219e384_11* var72 = *(struct Struct_ov017_0219e384_11**)(var1 + Enum_ov017_0219e384_14132);
						func_ov017_021bba08(var72, (unsigned char*)var6->pUnknownStruct_8_);
						var72->unknown_8_ = var4->unknown_20_;
						func_020469b4((Struct_0201bdac_2*)var56, (Struct_0201bdac*)var72);
						var4->unknown_20_ = -1;
					} else {
						func_0206df6c(var70, (unsigned char*)var70 + 0x8c, var17.unknown_c_ + 0xea + 0xb00, 1);
					}
				}
				BackgroundLoader::RemoveLockGlobal();
			}
		}
		var4->unknown_1e_ = -1;
		var65 = *(struct Struct_ov017_0219e384_11**)(var1 + Enum_ov017_0219e384_14132);
		if (var65->unknown_2_ == 0 || var65->unknown_9c_ != 0 || var65->unknown_8_ == 0) {
			func_ov017_021d23bc(0xffff);
		}
		if (var4->unknown_a_ == 0) {
			if (var61 != 0) {
				func_020a2788(var63, *(short*)(var61 + Enum_ov017_0219e384_52));
			}
			switch (((unsigned int)var60[0xc] << 25) >> 30) {
			case 0:
				func_020a27cc((Struct_020a27cc*)var63);
				break;
			case 1:
				func_020a2800((Struct_020a2800*)var63);
				break;
			case 2:
				func_020a2830(var63);
				break;
			case 3:
				func_020a2868((Struct_020a2868*)var63);
				break;
			default:
				func_020a2800((Struct_020a2800*)var63);
				break;
			}
			if (func_020a3570((Struct_0204a170*)var63) != 0) {
				var17.unknown_0_ = *(Struct_02014900*)var3->unknown_44_;
				var18.unknown_54_ = *(Struct_02014900*)(var63 + 0x10);
				Vector3fix_Subtract(&var17.unknown_0_.unknown1_0_, &var17.unknown_90_.unknown1_0_, &var18.unknown_60_.unknown1_0_);
				Vector3fix_Add(&var18.unknown_54_.unknown1_0_, &var18.unknown_60_.unknown1_0_, &var18.unknown_54_.unknown1_0_);
				func_0202ec5c((char*)var63, (int*)&var18.unknown_54_);
			}
			func_ov017_021982ac(var1);
			func_020a2718((char*)var63);
		}
		if ((var4->unknown_6e_ & 0x40) != 0) {
			func_020a2718((char*)var63);
		}
		if ((var4->unknown_6e_ & 1) == 0) {
			func_020466f4((Struct_02038598_4*)var15, 1);
			func_020dc2d0(0);
		}
		func_020a2cbc((Struct_020a2cbc*)var63, ((struct Struct_ov017_0219e384_5*)(var60 + 4))->unknown_0_0_ == 0 ? 1 : 0);
		func_020ae53c(1);
		func_020a8740();
		func_02026b7c((unsigned char*)(*(void**)(var1 + Enum_ov017_0219e384_14032)));
		func_ov017_021a3338(var1);
		if ((var4->unknown_6e_ & 8) != 0) {
			arg0->unknown_8_ = 9;
			return;
		}
		{
			Struct_0208cb08* var73 = func_02094a00();
			func_02094ab0(var73);
			func_02094b34(var73, 0x6f, 5000, 1, 1);
		}
		arg0->unknown_8_ = 10;
		return;
	}
	if (arg0->unknown_8_ == 10) {
		if (func_02094b4c(func_02094a00()) != 0) {
			arg0->unknown_8_ = 9;
		}
		return;
	}
	if (arg0->unknown_8_ == 9) {
		int var74;
		int var75;
		int var76;

		if (var4->unknown_69_ != 0 && func_02046b60((Struct_02038598_5*)arg1, 0x3d) == 0) {
			func_ov017_021a65c4(var1, 1, 0);
		}
		var74 = 1;
		var75 = 1;
		if (func_02046b60((Struct_02038598_5*)arg1, 4) != 0 ||
		    func_02046b60((Struct_02038598_5*)arg1, 0xa) != 0 ||
		    func_02046b60((Struct_02038598_5*)arg1, 0x3d) != 0) {
			var74 = 0;
			var75 = 0;
		}
		if (func_02046b60((Struct_02038598_5*)arg1, 0x2a) != 0 ||
		    func_02046b60((Struct_02038598_5*)arg1, 0xf) != 0) {
			var75 = 0;
		}
		if (func_02046b60((Struct_02038598_5*)arg1, 0x2d) != 0) {
			var74 = 0;
		}
		if (func_0202c508(var13) != 0) {
			func_ov017_021cdaa0();
		}
		if (var74 != 0) {
			SetMainBrightness((GameResources*)var1, 0, 15);
		}
		if (var75 != 0) {
			func_020397c0(var3);
		}
		for (var76 = 0; var76 < var12->unknown_f7c_; var76++) {
			struct Struct_ov017_0219e384_3* var77 = (struct Struct_ov017_0219e384_3*)var0->GetPartyMemberByIndex(var12->unknown_f78_[var76]);
			if (var77 != 0 && func_02039d7c((char*)var77) != 0) {
				continue;
			}
			if (var77 != 0) {
				((Object3D*)var77)->EnableFlag(0x4000000);
			}
			if (var76 > 0 && var4 != 0 && var4->unknown_a_ == 0) {
				var18.unknown_48_ = *(Struct_02014900*)var3->unknown_44_;
				*(Vector3i*)var77->unknown_44_ = *(Vector3i const*)((int*)&var18.unknown_48_);
				if (var4->unknown_0_ == 10000) {
					var18.unknown_48_.unknown_0_[0] = 0xff000;
					var18.unknown_48_.unknown_0_[1] = 0;
					var18.unknown_48_.unknown_0_[2] = 0xff000;
				}
				func_ov017_021d2ad0(var77->inline_ov017_0219e384_2(), var18.unknown_48_.unknown_0_[0], var18.unknown_48_.unknown_0_[1], var18.unknown_48_.unknown_0_[2], 0);
			}
		}
		if (func_0202c508(var13) != 0 && var4 != 0 && var4->unknown_a_ == 0) {
			void* var78;
			*(Vector3i*)((int*)((char*)var0 + Enum_ov017_0219e384_32608)) = *(Vector3i const*)var3->unknown_44_;
			var78 = var0->GetPartyMemberByIndex(0xce);
			if (var78 != 0) {
				int* var79 = (int*)((char*)var0 + Enum_ov017_0219e384_32608);
				int var80 = var79[2];
				int var81 = var79[1];
				int var82 = *(int*)((char*)var0 + Enum_ov017_0219e384_32608);
				((struct Struct_ov017_0219e384_3*)var78)->unknown_44_[0] = var82;
				((struct Struct_ov017_0219e384_3*)var78)->unknown_44_[1] = var81;
				((struct Struct_ov017_0219e384_3*)var78)->unknown_44_[2] = var80;
			}
		}
		if (func_0202c508(var13) != 0) {
			int* var83 = (int*)((char*)var0 + Enum_ov017_0219e384_32608);
			func_ov017_021d2ad0(0xce, *(int*)((char*)var0 + Enum_ov017_0219e384_32608), var83[1], var83[2], 0);
		}
		if (var4 != 0 && (var4->unknown_6e_ & 0x20) != 0) {
			func_ov017_0219c598(0, 0, 1);
		}
		*(int*)((char*)func_020421a0() + Enum_ov017_0219e384_728) = 0;
		if (var4->unknown_64_ != 0) {
			GameState* var84 = GameState::GetInstance();
			int* var85 = (int*)LightingManager::GetInstance();
			char* var86 = (char*)GetGameResources();
			struct Struct_ov017_0219e384_3* var87;
			func_ov017_021b6f18(*(void**)(var86 + Enum_ov017_0219e384_14104));
			var87 = (struct Struct_ov017_0219e384_3*)var84->GetPartyMemberByIndex(0);
			func_ov017_02196c08((unsigned char*)&var18.unknown_24_);
			var18.unknown_24_.unknown_0_ = 1;
			var18.unknown_24_.unknown_1_ = 0;
			var18.unknown_24_.unknown_4_ = var87->unknown_1b2_;
			var18.unknown_24_.unknown_2_ = -1;
			var18.unknown_24_.unknown_e_ = 1;
			var18.unknown_24_.unknown_14_ = 1;
			var18.unknown_24_.unknown_12_ = var85[0x26];
			func_ov017_021b6e70(&var18.unknown_24_, -1);
			func_ov017_021a7a74(var86, &var18.unknown_24_);
		} else if (var4->unknown_63_ != 0) {
			int var88;
			int var89;
			unsigned short var90;
			struct Struct_ov017_0219dc90_2* var91;
			unsigned short var92;
			int var93;
			int* var94;
			GameState* var95;
			char* var96;
			struct Struct_ov017_0219e384_3* var97;
			var95 = GameState::GetInstance();
			var94 = (int*)LightingManager::GetInstance();
			var96 = (char*)GetGameResources();
			var97 = (struct Struct_ov017_0219e384_3*)func_0200ff1c(var95, 0);
			if (var97 != 0 && var97->unknown_be_ == 2) {
				var90 = var97->unknown_1b2_;
				if (var90 != 0 && var90 >= 1 && var90 <= 0x7fff) {
					var91 = *(struct Struct_ov017_0219dc90_2**)(var96 + Enum_ov017_0219e384_14072);
					if (var91 != 0) {
						var93 = *(unsigned short*)var91;
						var89 = 0x7fff - 0x8000;
						for (var88 = 0; var88 < 12; var88++) {
							struct Struct_ov017_0219e384_4* var98;
							var89 = var88 + (var91->unknown_2_0_ * 12 + 0x70);
							var98 = (struct Struct_ov017_0219e384_4*)var95->GetMaybeFieldMonsterByIndex(var89);
							if (var98 == 0) {
								continue;
							}
							var92 = var98->unknown_16a_;
							if (var92 != var90 || var98->unknown_be_ != 2) {
								continue;
							}
							if (var98->unknown_be_ == 6) {
								continue;
							}
							if (((Object3D*)var98)->IsVisible() == 0) {
								continue;
							}
							if (var93 != ((Object3D*)var98)->GetField06()) {
								continue;
							}
							if (inline_ov017_0219e384_3(var98) != 8 && inline_ov017_0219e384_3(var98) != 9 && inline_ov017_0219e384_3(var98) != 0) {
								var98->unknown_166_ = func_020100a8(var95);
								func_02076ccc(var98, 8);
							}
							var90 = var92;
							break;
						}
						if (var89 >= 0) {
							func_ov017_021b6f18(*(void**)(var96 + Enum_ov017_0219e384_14104));
							func_ov017_02196c08((unsigned char*)&var18.unknown_c_);
							var18.unknown_c_.unknown_0_ = 1;
							var18.unknown_c_.unknown_1_ = func_020100a8(var95);
							var18.unknown_c_.unknown_4_ = var90;
							var18.unknown_c_.unknown_2_ = var89;
							func_ov017_021b6e70(&var18.unknown_c_, var89);
							var18.unknown_c_.unknown_12_ = var94[0x26];
							func_ov017_021a7a74(var96, &var18.unknown_c_);
						}
					}
				}
			}
		}
		if (arg0->unknown_12_ != 0) {
			Zone3D* var99 = (Zone3D*)func_02012fe4();
			*(unsigned short*)((char*)var99 + Enum_ov017_0219e384_10118) = arg0->unknown_12_;
			if (((arg0->unknown_14_ << 18) >> 18) != -1) {
				*(unsigned short*)((char*)var99 + Enum_ov017_0219e384_10116) = (arg0->unknown_14_ << 18) >> 18;
			}
			*(unsigned char*)((char*)var99 + Enum_ov017_0219e384_10120) = (arg0->unknown_14_ << 16) >> 30;
			var18.unknown_3c_.unknown_0_[0] = arg0->unknown_16_ << 7;
			var18.unknown_3c_.unknown_0_[1] = arg0->unknown_18_ << 7;
			var18.unknown_3c_.unknown_0_[2] = arg0->unknown_1a_ << 7;
			*(Vector3i*)((int*)((char*)var99 + Enum_ov017_0219e384_10100)) = *(Vector3i const*)((int*)&var18.unknown_3c_);
			*(int*)((char*)var99 + Enum_ov017_0219e384_10112) = arg0->unknown_1c_;
			func_020a72ac(var99, arg0->unknown_1e_);
			VectorizedMemset(&arg0->unknown_12_, 0, 0xe);
		}
		if (*(short*)(var1 + Enum_ov017_0219e384_17586) >= 0) {
			void* var100 = func_020936f8();
			func_02094030(var100, *(short*)(var1 + Enum_ov017_0219e384_17586), -1, 0);
			*(short*)(var1 + Enum_ov017_0219e384_17586) = -1;
		}
		arg0->unknown_1_ = 1;
	}
}
