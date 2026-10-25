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
#define func_020daf90 func_020dc998
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

struct Field3f8* GetField0x3f8Address_0200fd0c(GameState*);
extern "C" void* Zone3D_GetInstance(void);
void* GetPtrField0x468_02011584(void* battle);
struct InlineEntry* ZoneRecords_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" struct SearchStruct* func_0202ae18(void);
void* GlobalFlags_GetInstance(void);
int GetByte0x26c_02039d7c(char* obj);
struct Vector3i;
extern "C" void func_02097cac(void* obj);
struct Obj0208f944;
void HandleGrottoTurnTransition0208f944(Obj0208f944*);
void ConfigureFieldVec3ForDateWindow_020a696c(void* obj, int a, int b);
struct SearchTable;
void* FindEntryByHalfwordKey_02099950(SearchTable*, int);
extern "C" int func_0209cd50(int id);
struct ShortField0xb8_0209cae8;
int GetShortAt0xb8(ShortField0xb8_0209cae8*);
struct Actor0209c678;
void BgmPlayer_FadeOut(Actor0209c678*, int);
int IsScaledFieldPositive0203adfc(void* a, void* b);
void ScaleAndNotify0203ad88(void* a, void* b, int c);
struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void func_ov017_021c4664(int mapId, struct Vec3 v, int w);
extern "C" int func_0202c540(void* search);
int GameState_GetLeaderIndex(GameState*);
void EnqueueEventTag150_021d035c(unsigned char a, unsigned char b, unsigned char c);
void EnqueueEventTag31_021d257c(unsigned char id, int a);
int Scenario_RunTrigger(void* obj, int kind, void* out);
extern "C" void EventQuery_RunQueuedCommands(void* node);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_020535c8(signed char* arg0);
extern "C" void func_020531f0(void* arg0);
extern "C" int func_02046b08(void** arg0);
extern "C" void* func_020daf90(void);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
int GetField0x50_020db2d4(void* obj);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
int CheckField0NonZero_0202b7d8(int* obj);
struct SearchStruct0202c1a4;
void* GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void SetFlagBitAt0xe_0202c5bc(struct SearchStruct* search, int v);
void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void func_ov017_0219d250(void* obj, unsigned char v);
int CountEntriesType2WithIds_020bc0f8(int a, int b);
extern "C" void func_ov017_0219c598(int a, int b, int c);
extern "C" int func_02028a54(struct InlineEntry* base, int id);
struct Entry_02028bd0;
struct InlineEntry* FindInlineEntryById(Entry_02028bd0*, int);
int IsInRange0201b588(int v);
struct Struct021b46d8;
void InitStruct_021b46d8(Struct021b46d8*);
int IsValueInRange0201b5d8(int v);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
extern "C" int func_0202c508(void* search);
extern "C" void func_ov017_021c4854(Zone3D* run, int a, int b, int* vec, int c, int d);
int GetByteFieldMasked0x1ce_02039790(void* obj, int mask);
extern "C" void func_ov017_021bd4d0(void* obj, unsigned char index, int a, int b);
extern "C" void func_ov017_021ce400(unsigned char v, int mapId);
extern "C" void* func_0208e0a8(void);
extern "C" void func_0208e520(void* a, void* b);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" char* strcpy(char* dst, const char* src);
int IsIdInRange020981e4(int, int);
int IsIdInSet02098210(int, int);
void* GetData02109020_0208e9e8(void);
signed char* GetFieldIfFlag4_020100f8(char*);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(Actor0209c3b4*, int);
struct Obj02086b98;
int AreListedCombatantsBit0Set(Obj02086b98*);
struct Obj0209caa0;
void SetFlag0x2AndNotify0209caa0(Obj0209caa0*, int);
void ClassifyPriceCategoryAndNotifyBattle_02064b98(unsigned char*, int);
struct FlagWord020466f4;
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
struct Obj0208f3a8;
void ClearFieldAt0xc0208f3a8(Obj0208f3a8*);
extern "C" void Scenario_LoadZoneTriggers(void* a, void* b);
void* GetGlobal02109418_02094d6c(void);
extern "C" void func_02095b30(void* obj, int v);
extern "C" void func_02097ec8(void* obj);
extern "C" void func_ov017_021a2fa0(void* ov);
extern "C" void func_ov017_0219e180(void* ov, int mapId);
extern "C" void func_0208f168(void* obj, void* alloc);
extern "C" void _ZN8Object3D10SetField06Et(void* obj, int v);
extern "C" void func_0208fc30(void* obj);
struct Obj020733c8;
void ClearField0x8020733c8(Obj020733c8*);
extern "C" int func_02028460(int* vec, int* other);
extern "C" void _Z34SetupCombatantAllocations_021901acv(void* ov);
extern "C" void func_020a6aac(void* ov, int a, int b);
extern "C" void func_020acecc(void* ov, int a, int b);
int FindAndApplyEntryVec3_021a01f4(void* ov, int mapId, int index, void* combatant, int* out);
extern "C" void func_ov017_0219fc88(void* self, int v);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char*);
int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_ov017_021b6e70(struct Msg021b6e70* fnMsg, int v);
extern "C" void func_ov017_021b7104(void* node, struct Msg021b6e70* fnMsg);
int Dispatch020649f4(void* obj, void* out);
int LoadFileIntoMemory(const char* name, void* dst, unsigned int* size);
struct StreamHeader;
int InitStreamAndRun0208dc00(StreamHeader*, int, int);
int Scenario_TestFlag(int a, unsigned char* arr, int bit);
extern "C" void func_ov017_021bba08(struct ListNode021bba08* node, void* header);
extern "C" void Scenario_SetFlag(void* a, unsigned char* arr, int bit, int set);
void EnqueueEventTag158_021d23bc(unsigned short v);
void SetField0x246_020a2788(void* obj, short v);
struct Struct020a27cc;
void SetVec3ComponentsAndApply020a27cc(Struct020a27cc*);
struct Struct020A2800;
void ConfigureVec3AndApply020a2800(Struct020A2800*);
void InitVec3ParamsVariant8b33_020a2830(void* obj);
struct Struct020a2868;
void SetVec3ComponentsAndApply020a2868(Struct020a2868*);
struct S020a3570;
int GetField0x218(S020a3570*);
void CopyVec3ToField0x10AndCall0202e5d8_0202ec5c(char*, int*);
extern "C" void func_ov017_021982ac(void* ov);
void ApplyVecFromField0x246_020a2718(char*);
void SetCombatModeFromCase020dc2d0(int v);
struct ByteField0x2c5_020a2cbc;
void SetByteAt0x2c5(ByteField0x2c5_020a2cbc*, int);
extern "C" void func_020ae53c(int v);
void NotifyOv017OnFlag0x1130_020a8740(void);
void MarkActiveCombatantSlots02026b7c(unsigned char*);
void SyncVec3ForFlaggedCombatants_021a3338(void* ov);
void InitAndAppendState61_021a65c4(void* ov, unsigned char a, int b);
void EnqueueEventTag147_021cdaa0(void);
void GameObject_EnableControl(void* obj);
void EnqueueEventTag35_021d2ad0(short, int, int, int, unsigned char);
void* MessageSystem_GetInstance(void);
extern "C" void func_ov017_021a7a74(void* ov, struct Msg021b6e70* fnMsg);
int TrySetMode02076ccc(void* obj, int mode);
extern "C" void func_020a72ac(void* obj, unsigned char v);
void* GetGlobal02109030_020936f8(void);
extern "C" void func_02094030(void* obj, int a, int b, int c);

extern int g_bgmPlayer;
extern int g_sePlayer;
extern const char data_ov017_021d75fc[];
extern const char data_ov017_021d7619[];
extern const char data_ov017_021d761e[];
extern char g_fileLoadBuffer[];

// Overlay 17, originally func_ov017_0219e384 (USA/EUR 0x0219e384, JPN 0x0219ee70)
extern "C" ARM void FieldTask_EnterZone(struct Seq0219e384* self, void* list) {
	GameState* battle = GameState::GetInstance();
	char* ov = (char*)GetGameResources();
	void* c3ac = battle->GetProtagonist();
	struct Combatant0219e384* actor = (struct Combatant0219e384*)battle->GetUnknownGameObject();
	struct Field3f8* fld = GetField0x3f8Address_0200fd0c(battle);
	struct BackgroundLoader* loader = BackgroundLoader::GetInstance();
	Zone3D* run = (Zone3D*)Zone3D_GetInstance();
	char* runSub = (char*)run + Field23ec;
	int runContext = (int)run + Field840;
	void* table468 = GetPtrField0x468_02011584(battle);
	struct InlineEntry* entryTable = ZoneRecords_GetInstance();
	void* obj5ec34 = Scenario_GetInstance();
	struct GrottoIds* ids = (struct GrottoIds*)GameState_GetParty(battle);
	struct SearchStruct* search = func_0202ae18();
	char* region = (char*)LootableContainerManager::GetMainInstance();
	void* flags14e04 = GlobalFlags_GetInstance();
	int* data7930 = (int*)LightingManager::GetInstance();
	struct WorkHi workHi;
	struct WorkLo workLo;

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

			func_02097cac((void*)runContext);
			HandleGrottoTurnTransition0208f944((Obj0208f944*)runSub);
			runMapId = run->currentZoneID_;
			ConfigureFieldVec3ForDateWindow_020a696c(ov, fld->mapId, runMapId);
			found = FindEntryByHalfwordKey_02099950((SearchTable*)table468, fld->mapId);
			hdr = (unsigned char*)run->pUnknownStruct_8_;
			self->active = 1;
			if (found != 0 && hdr != 0) {
				if (func_0209cd50(fld->mapId) == GetShortAt0xb8((ShortField0xb8_0209cae8*)&g_bgmPlayer)) {
					self->active = 0;
				}
			}
			if (var4->unknown_20_ > 0) {
				arg0->unknown_a_ = 0;
			}
			if (self->active != 0) {
				BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
			}
			if (IsScaledFieldPositive0203adfc(&g_sePlayer, 0) != 0) {
				ScaleAndNotify0203ad88(&g_bgmPlayer, 0, 0);
				self->active = 1;
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
			if (fld->mode == 1) {
				SePlayer_Play((SePlayer*)&g_sePlayer, 15, 0);
			}
			GameObject_DisableControl((Obj020397cc*)actor, 1);
			actor->c2 &= ~0x40;
			warpSlot = (unsigned short*)(ov + WarpLow);
			warpSlot = (unsigned short*)((char*)warpSlot + WarpHigh);
			*(unsigned short*)(ov + Field44ae) = 0;
			warpSlot[1] = 0;
			func_ov017_021c4664(fld->mapId, *(struct Vec3*)fld->vec10, fld->s1c);
			if (func_0202c540(search) != 0 && fld->f67 != 0 && *(unsigned short*)(ov + Field44ac) != 0) {
				*(unsigned short*)(ov + Field44ac) = 0;
			}
			if (fld->flagE != 0) {
				EnqueueEventTag150_021d035c(0, GameState_GetLeaderIndex(battle), 1);
			}
			runMapId = run->currentZoneID_;
			if (fld->mapId != runMapId) {
				struct GrottoIds* list2a04 = (struct GrottoIds*)GameState_GetParty(battle);
				int i;
				for (i = 0; i < list2a04->count; i++) {
					EnqueueEventTag31_021d257c(list2a04->ids[i], 0);
				}
			}
			if (*(unsigned char*)(var1 + Enum_ov017_0219e384_17129) != 0) {
				var4->unknown_a_ = 0;
			}
			obj = Scenario_GetInstance();
			workHi.turnNode.mapId = run->currentZoneID_;
			if (fld->active == 0 && Scenario_RunTrigger(obj, 0x1e, &workHi.turnNode) != 0) {
				EventQuery_RunQueuedCommands(&workHi.turnNode);
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
		if (fld->flags6e != 1) {
			SetFlags04((GameResources*)ov, 1);
			FlagWord_SetBits((unsigned int*)flags14e04, 1);
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
		table = ZoneRecords_GetInstance();
		found = func_02028a54(table, run->currentZoneID_);
		entry = FindInlineEntryById((Entry_02028bd0*)table, run->currentZoneID_);
		*(struct InlineEntry**)(ov + Field36f8) = entry;
		grotto = (signed char*)battle->GetGrottoStruct();
		if (IsInRange0201b588(run->currentZoneID_) != 0) {
			entry->fd = grotto[8];
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
					((LootableContainerManager*)region)->LoadZoneContainers(workLo.buf, workLo.fileSize, workHi.name, (SafeAllocator*)0);
					Zone3D_SetUpContainers(run);
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
		if (self->active != 0) {
			SetStateAndDispatch0209c3b4((Actor0209c3b4*)&g_bgmPlayer, func_0209cd50(mapId));
			if (CheckField0NonZero_0202b7d8((int*)search) != 0 && AreListedCombatantsBit0Set((Obj02086b98*)ids) != 0) {
				BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
			}
		}
		SetFlag0x2AndNotify0209caa0((Obj0209caa0*)&g_bgmPlayer, ((unsigned int)header[0xd] << 24) >> 31);
		ClassifyPriceCategoryAndNotifyBattle_02064b98((unsigned char*)obj5ec34, *(unsigned short*)header);
		FlagWord_ClearBits((FlagWord020466f4*)flags14e04, 0x200000);
		if (fld->active == 0) {
			ClearFieldAt0xc0208f3a8((Obj0208f3a8*)obj09020);
			Scenario_LoadZoneTriggers(obj5ec34, (unsigned char*)run->pUnknownStruct_8_);
			func_02095b30(GetGlobal02109418_02094d6c(), 0);
		}
		if (func_0202c508(search) != 0) {
			struct InlineEntry* e2 = FindInlineEntryById((Entry_02028bd0*)entryTable, run->currentZoneID_);
			if (e2 != 0) {
				Zone3D_SetSearchedLootables(run, e2->group);
				Zone3D_OpenDoorsByMask(run, e2->f4);
			}
		} else if (moving == 0 && *(unsigned char*)((char*)battle + Field5cac) == 0) {
			Zone3D_SetSearchedLootables(run, self->flagsE);
			Zone3D_OpenDoorsByMask(run, self->flags10);
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
		if (moving != 0) {
			func_ov017_0219fc88(self, fld->f20);
		} else if (fld->f28 >= 0 && fld->f2c == run->currentZoneID_ && fld->s1e != fld->f28) {
			if (IsValueInRange0201b5d8(run->currentZoneID_) == 0) {
			void* n = *(void**)(ov + Field3718);
			func_ov017_021b6f18(n);
			InitStruct_02196c08((unsigned char*)&workHi.msg);
			workHi.msg.kind = 1;
			workHi.msg.actor = GameState_GetProtagonistIndex(battle);
			workHi.msg.value = fld->f28 + 5 + 0x8000;
			workHi.msg.id = 0xffff;
			workHi.msg.f8 = fld->f28;
			workHi.msg.f12 = data7930[0x26];
			func_ov017_021b6e70(&workHi.msg, workHi.msg.id);
			func_ov017_021b7104(n, &workHi.msg);
			AppendNodeToTail((TailList020469b4*)tailList, (TailNode020469b4*)n);
			fld->f28 = -1;
			fld->flags6e |= 1;
			ClearFlags00((GameResources*)ov, 0x800);
			}
		} else if (var4->unknown_24_ >= 0) {
			func_ov017_0219fc88(arg0, var4->unknown_24_);
		} else {
			void* obj2 = Scenario_GetInstance();
			int listed;
			workHi.node.mapId = mapId;
			if (fld->active == 0 && Dispatch020649f4(obj2, &workHi.node) != 0) {
				EventQuery_RunQueuedCommands(&workHi.node);
			}
			var71 = func_02046b60((Struct_02038598_5*)var56, 4);
			if (func_0202b7d8((int*)var13) == 0 || func_0202c508(var13) != 0) {
				BackgroundLoader::AddLockGlobal();
				if (LoadFileIntoMemory(data_ov017_021d761e, g_fileLoadBuffer, &workLo.size) != 0 &&
				    InitStreamAndRun0208dc00((StreamHeader*)g_fileLoadBuffer, workLo.size, (int)&workHi.slot) != 0 &&
				    Scenario_TestFlag((int)obj2, (unsigned char*)obj2 + 0x8c, workHi.slot + 0xea + 0xb00) == 0) {
					if (listed == 0) {
						struct ListNode021bba08* n2 = *(struct ListNode021bba08**)(ov + Field3734);
						func_ov017_021bba08(n2, (unsigned char*)run->pUnknownStruct_8_);
						n2->f8 = fld->f20;
						AppendNodeToTail((TailList020469b4*)tailList, (TailNode020469b4*)n2);
						fld->f20 = -1;
					} else {
						Scenario_SetFlag(obj2, (unsigned char*)obj2 + 0x8c, workHi.slot + 0xea + 0xb00, 1);
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
		if ((fld->flags6e & 1) == 0) {
			FlagWord_ClearBits((FlagWord020466f4*)flags14e04, 1);
			SetCombatModeFromCase020dc2d0(0);
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
			FontBankLoader* g400 = FontBankLoader_GetInstance();
			FontBankLoader_CancelLoads(g400);
			BlankFunction02094b34(g400, 0x6f, 5000, 1, 1);
		}
		arg0->unknown_8_ = 10;
		return;
	}
	if (self->state == 10) {
		if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()) != 0) {
			self->state = 9;
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
		if (wantByte != 0) {
			GameObject_EnableControl(actor);
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
		*(int*)((char*)MessageSystem_GetInstance() + MessageField) = 0;
		if (fld->f64 != 0) {
			GameState* battle2 = GameState::GetInstance();
			int* data2 = (int*)LightingManager::GetInstance();
			char* ov2 = (char*)GetGameResources();
			struct Combatant0219e384* c;
			func_ov017_021b6f18(*(void**)(ov2 + Field3718));
			c = (struct Combatant0219e384*)battle2->GetPartyMemberByIndex(0);
			InitStruct_02196c08((unsigned char*)&workLo.msgF64);
			workLo.msgF64.kind = 1;
			workLo.msgF64.actor = 0;
			workLo.msgF64.value = c->f1b2;
			workLo.msgF64.id = -1;
			workLo.msgF64.fe = 1;
			workLo.msgF64.f14 = 1;
			workLo.msgF64.f12 = data2[0x26];
			func_ov017_021b6e70(&workLo.msgF64, -1);
			func_ov017_021a7a74(ov2, &workLo.msgF64);
		} else if (fld->f63 != 0) {
			int j;
			int found2;
			unsigned short want;
			struct InlineEntry* slot;
			unsigned short id;
			int mapId2;
			int* data2;
			GameState* battle2;
			char* ov2;
			struct Combatant0219e384* lead;
			battle2 = GameState::GetInstance();
			data2 = (int*)LightingManager::GetInstance();
			ov2 = (char*)GetGameResources();
			lead = (struct Combatant0219e384*)GetCombatantWithFlag0x100_0200ff1c(battle2, 0);
			if (lead != 0 && lead->be == 2) {
				want = lead->f1b2;
				if (want != 0 && want >= 1 && want <= 0x7fff) {
					slot = *(struct InlineEntry**)(ov2 + Field36f8);
					if (slot != 0) {
						mapId2 = *(unsigned short*)slot;
						found2 = 0x7fff - 0x8000;
						for (j = 0; j < 12; j++) {
							struct Npc0219e384* c;
							found2 = j + (slot->slotIndex * 12 + 0x70);
							c = (struct Npc0219e384*)battle2->GetMaybeFieldMonsterByIndex(found2);
							if (c == 0) {
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
							if (GetNpcMode(c) != 8 && GetNpcMode(c) != 9 && GetNpcMode(c) != 0) {
								c->f166 = GameState_GetProtagonistIndex(battle2);
								TrySetMode02076ccc(c, 8);
							}
							var90 = var92;
							break;
						}
						if (found2 >= 0) {
							func_ov017_021b6f18(*(void**)(ov2 + Field3718));
							InitStruct_02196c08((unsigned char*)&workLo.msgF63);
							workLo.msgF63.kind = 1;
							workLo.msgF63.actor = GameState_GetProtagonistIndex(battle2);
							workLo.msgF63.value = want;
							workLo.msgF63.id = found2;
							func_ov017_021b6e70(&workLo.msgF63, found2);
							workLo.msgF63.f12 = data2[0x26];
							func_ov017_021a7a74(ov2, &workLo.msgF63);
						}
					}
				}
			}
		}
		if (self->v12 != 0) {
			Zone3D* run2 = (Zone3D*)Zone3D_GetInstance();
			*(unsigned short*)((char*)run2 + Field2786) = self->v12;
			if (((self->v14 << 18) >> 18) != -1) {
				*(unsigned short*)((char*)run2 + Field2784) = (self->v14 << 18) >> 18;
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
