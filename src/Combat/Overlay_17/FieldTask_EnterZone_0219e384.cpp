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
enum { Field23ec = 0x240c, Enum_ov017_0219e384_2112 = 0x860, Enum_ov017_0219e384_17582 = 0x41fe, Field44ac = 0x41fc, Enum_ov017_0219e384_17129 = 0x40c9, Field3700 = 0x34f0, Field3704 = 0x34f4, Enum_ov017_0219e384_14072 = 0x34e8, Enum_ov017_0219e384_15004 = 0x388c, Field281f = 0x285f, Enum_ov017_0219e384_14132 = 0x3524, Enum_ov017_0219e384_9144 = 0x23d8, Enum_ov017_0219e384_6240 = 0x1860, Enum_ov017_0219e384_14076 = 0x34ec, Enum_ov017_0219e384_23724 = 0x5a4c, Enum_ov017_0219e384_14104 = 0x3508, Field36d0 = 0x34c0, Enum_ov017_0219e384_32608 = 0x7c8c, Enum_ov017_0219e384_10118 = 0x27c6, Enum_ov017_0219e384_10116 = 0x27c4, Enum_ov017_0219e384_10120 = 0x27c8, Enum_ov017_0219e384_10100 = 0x27b4, Enum_ov017_0219e384_10112 = 0x27c0, Enum_ov017_0219e384_17586 = 0x4202, Enum_ov017_0219e384_174 = 0xfe, Enum_ov017_0219e384_17408 = 0x4100 };
#else
enum { Field23ec = 0x23ec, Enum_ov017_0219e384_2112 = 0x840, Enum_ov017_0219e384_17582 = 0x44ae, Field44ac = 0x44ac, Enum_ov017_0219e384_17129 = 0x42e9, Field3700 = 0x3700, Field3704 = 0x3704, Enum_ov017_0219e384_14072 = 0x36f8, Enum_ov017_0219e384_15004 = 0x3a9c, Field281f = 0x281f, Enum_ov017_0219e384_14132 = 0x3734, Enum_ov017_0219e384_9144 = 0x23b8, Enum_ov017_0219e384_6208 = 0x1840, Enum_ov017_0219e384_14076 = 0x36fc, Enum_ov017_0219e384_23724 = 0x5cac, Enum_ov017_0219e384_14104 = 0x3718, Field36d0 = 0x36d0, Enum_ov017_0219e384_32608 = 0x7f60, Enum_ov017_0219e384_10118 = 0x2786, Enum_ov017_0219e384_10116 = 0x2784, Enum_ov017_0219e384_10120 = 0x2788, Enum_ov017_0219e384_10100 = 0x2774, Enum_ov017_0219e384_10112 = 0x2780, Enum_ov017_0219e384_17586 = 0x44b2, Enum_ov017_0219e384_174 = 0xae, Enum_ov017_0219e384_17408 = 0x4400 };
#endif

#if defined(jpn)
enum { Enum_ov017_0219e384_52 = 0x54, MessageField = 0x228 };
#else
enum { Enum_ov017_0219e384_52 = 0x34, MessageField = 0x2d8 };
#endif

struct Vec3 { int v[3]; };

struct Seq0219e384 {
	unsigned char unk0;
	unsigned char done;
	unsigned char unk2[6];
	unsigned char state;
	unsigned char pending;
	unsigned char active;
	unsigned char unknown_b_;
	unsigned char unkc[2];
	unsigned short flagsE;
	unsigned short flags10;
	short unknown_12_;
	short v14;
	short unknown_16_;
	short v18;
	short unknown_1a_;
	short unknown_1c_;
	unsigned char unknown_1e_;
	unsigned char unknown_1f_;
	unsigned char v20;
	unsigned char unknown_21_;
	unsigned short timer;
	unsigned short warp;
	unsigned char unknown_26_[2];
	int accum;
};

struct Field3f8 {
	int inline_ov017_0219e384() const { SDK_NULL_ASSERT(this); return f24; }

	unsigned short mapId;
	unsigned char unk2[8];
	unsigned char active;
	unsigned char unknown_b_;
	unsigned char mode;
	unsigned char unknown_d_;
	unsigned char unknown_e_;
	unsigned char unknown_f_;
	int unknown_10_[3];
	short unknown_1c_;
	short unknown_1e_;
	int f20;
	int f24;
	int f28;
	int unknown_2c_;
	unsigned char unk30[0x33];
	unsigned char unknown_63_;
	unsigned char f64;
	unsigned char unknown_65_[2];
	unsigned char f67;
	unsigned char unk68;
	unsigned char unknown_69_;
	unsigned char unknown_6a_[2];
	short f6c;
	unsigned char flags6e;
};

struct Combatant0219e384 {
	short inline_ov017_0219e384_2() const { SDK_NULL_ASSERT(this); return unknown_4_; }

	unsigned char unk0[4];
	short unknown_4_;
	unsigned char unknown_6_[0x3e];
	int vec44[3];
	unsigned char unk50[4];
	int unknown_54_;
	unsigned char unknown_58_[0x60];
	unsigned short b8;
	unsigned char unknown_ba_[4];
	unsigned char unknown_be_;
	unsigned char unknown_bf_[3];
	unsigned char c2;
	unsigned char unknown_c3_[0x6d];
	unsigned int* unknown_130_;
	unsigned char unknown_134_[0x2c];
	unsigned char unknown_160_[6];
	unsigned short f166;
	unsigned char unknown_168_[2];
	unsigned short unknown_16a_;
#if defined(jpn)
	unsigned char unknown_16c_[0x3a];
#else
	unsigned char unknown1_16c_[0x46];
#endif
	unsigned short unknown_1b2_;
};

struct Npc0219e384 {
	unsigned char unk0[0xbe];
	unsigned char unknown_be_;
	unsigned char unknown_bf_[0x71];
	int mode;
	unsigned char unknown_134_[0x32];
	unsigned short f166;
	unsigned char unknown_168_[2];
	unsigned short unknown_16a_;
};

static inline int inline_ov017_0219e384_3(struct Npc0219e384* c) {
	return *(int*)((char*)c + 0x130);
}

struct Struct_ov017_0219e384_5 {
	unsigned char unknown_0_0_ : 1;
	unsigned char rest : 7;
};

struct Struct_ov017_0219dc90_5 {
	unsigned char unk0[2];
	unsigned char used;
	unsigned char unknown_3_[5];
	void* entry;
	unsigned char unkc[5];
	unsigned char kind;
	unsigned short value;
#if !defined(jpn)
	unsigned char unknown_14_[4];
#endif
};

struct InlineEntry {
	unsigned char unk0[2];
	unsigned short slotIndex : 2;
	unsigned short unknown_2_2_ : 2;
	unsigned short group : 12;
	unsigned short f4;
	unsigned char unknown_6_[7];
	unsigned char unknown_d_;
#if defined(jpn)
	unsigned char unknown_e_[6];
#else
	unsigned char unknown1_e_[0xa];
#endif
	int vec18[3];
	unsigned char unknown_24_[0x10];
	int f34;
};

struct GrottoIds {
	unsigned char unk0[0xf78];
	unsigned char ids[4];
	unsigned char count;
	unsigned char flagF7d;
};

struct Struct_ov017_0219e384_7 {
	unsigned char kind;
	unsigned char actor;
	unsigned short id;
	unsigned short value;
	unsigned short unknown_6_;
	int f8;
	unsigned char fc;
	unsigned char unknown_d_;
	unsigned char fe;
	unsigned char ff;
	unsigned char f10;
	unsigned char unknown_11_;
	unsigned char f12;
	unsigned char unknown_13_;
	int f14;
};

struct Struct_ov017_0219e384_8 {
	unsigned char unk0[0xc];
	int mapId;
	unsigned char unk10[0x24];
};

struct Struct_ov017_0219e384_9 {
	unsigned int size;
	unsigned int fileSize;
	void* buf;
	struct Struct_ov017_0219e384_7 msgF63;
	struct Struct_ov017_0219e384_7 unknown_24_;
	Struct_02014900 unknown_3c_;
	Struct_02014900 unknown_48_;
	Struct_02014900 fieldVec;
	Struct_02014900 unknown_60_;
};

struct Struct_ov017_0219e384_10 {
	Struct_02014900 unknown_0_;
	signed char slot;
	unsigned char unknown_d_[0x2b];
	struct Struct_ov017_0219e384_8 node;
	struct Struct_ov017_0219e384_7 msg;
	Struct_02014900 unknown_84_;
	Struct_02014900 unknown_90_;
	char name[0x10];
	struct Struct_ov017_0219e384_8 turnNode;
};

struct Struct_ov017_0219e384_11 {
	unsigned char unk0[2];
	unsigned char flag2;
	unsigned char unknown_3_[5];
	unsigned short f8;
#if defined(jpn)
	unsigned char unknown_a_[0x8d];
#else
	unsigned char unknown1_a_[0x91];
#endif
	unsigned char unknown_9b_;
	unsigned char f9c;
};

struct Struct_ov017_0219e384_12 { unsigned char unk0[0x28]; };
struct Struct_01ff91ac_19;
struct SearchStruct;
struct BackgroundLoader;
struct Struct_01ff91ac_20 { unsigned short a; unsigned short b; };

extern "C" struct Field3f8* GameState_GetZoneTransition(GameState*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* GameState_GetZoneTable(void* battle);
extern "C" struct InlineEntry* ZoneRecords_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int GameObject_IsClimbingLadder(char* obj);
struct Vector3i;
extern "C" void func_02097cac(void* obj);
struct Struct_0208f944;
extern "C" void func_0208f944(Struct_0208f944*);
extern "C" void func_020a696c(void* obj, int a, int b);
struct SearchTable;
extern "C" void* ZoneTable_FindEntry(SearchTable*, int);
extern "C" int func_0209cd50(int id);
struct ShortField0xb8_0209cae8;
extern "C" int func_0209cae8(ShortField0xb8_0209cae8*);
struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(Actor0209c678*, int);
extern "C" int SoundPlayer_IsStreamPlaying(void* a, void* b);
extern "C" void SoundPlayer_StopStream(void* a, void* b, int c);
struct SePlayer;
extern "C" void SePlayer_Play(SePlayer*, int, int);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void func_ov017_021c4664(int mapId, struct Vec3 v, int w);
extern "C" int LinkSession_IsGuest(void* search);
extern "C" int GameState_GetLeaderIndex(GameState*);
extern "C" void func_ov017_021d035c(unsigned char a, unsigned char b, unsigned char c);
extern "C" void func_ov017_021d257c(unsigned char id, int a);
extern "C" int Scenario_RunTrigger(void* obj, int kind, void* out);
extern "C" void EventQuery_RunQueuedCommands(void* node);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" void func_020531f0(void* obj);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" void* ObjLoading_GetInstance(void);
struct ListHead02046b60;
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" int func_020db2d4(void* obj);
extern "C" void func_020daf9c(int a, int b, int c, int d);
extern "C" int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
extern "C" void* LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void LinkSession_MarkSlotLost(struct SearchStruct* search, int v);
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void func_ov017_0219d250(void* obj, unsigned char v);
extern "C" int func_020bc0f8(int a, int b);
extern "C" void func_ov017_0219c598(int a, int b, int c);
extern "C" int ZoneRecords_Add(struct InlineEntry* base, int id);
struct Entry_02028bd0;
extern "C" struct InlineEntry* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" int ZoneId_IsGrotto(int v);
struct Struct_ov017_0219dc90_3;
extern "C" void func_ov017_021b46d8(Struct_ov017_0219dc90_3*);
extern "C" int ZoneId_IsGrottoBossFloor(int v);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" int LinkSession_IsHostOrSolo(void* search);
extern "C" void func_ov017_021c4854(Zone3D* run, int a, int b, int* vec, int c, int d);
extern "C" int func_02039790(void* obj, int mask);
extern "C" void func_ov017_021bd4d0(void* obj, unsigned char index, int a, int b);
extern "C" void func_ov017_021ce400(unsigned char v, int mapId);
extern "C" void* LootPointList_GetInstance(void);
extern "C" void func_0208e520(void* a, void* b);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int func_020981e4(int, int);
extern "C" int func_02098210(int, int);
extern "C" void* func_0208e9e8(void);
extern "C" signed char* GameState_GetFollowCamera(char*);
struct Actor0209c3b4;
extern "C" void func_0209c3b4(Actor0209c3b4*, int);
struct Obj02086b98;
extern "C" int func_02086b98(Obj02086b98*);
struct Obj0209caa0;
extern "C" void func_0209caa0(Obj0209caa0*, int);
extern "C" void func_02064b98(unsigned char*, int);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
struct Struct_0208f3a8;
extern "C" void func_0208f3a8(Struct_0208f3a8*);
extern "C" void Scenario_LoadZoneTriggers(void* a, void* b);
extern "C" void* func_02094d6c(void);
extern "C" void func_02095b30(void* obj, int v);
extern "C" void func_02097ec8(void* obj);
extern "C" void func_ov017_021a2fa0(void* ov);
extern "C" void func_ov017_0219e180(void* ov, int mapId);
extern "C" void func_0208f168(void* obj, void* alloc);
extern "C" void _ZN8Object3D10SetField06Et(void* obj, int v);
extern "C" void func_0208fc30(void* obj);
struct Struct_020733c8;
extern "C" void func_020733c8(Struct_020733c8*);
extern "C" int NodeGraph_FindClosestNode(int* vec, int* other);
extern "C" void func_ov017_021901ac(void* ov);
extern "C" void func_020a6aac(void* ov, int a, int b);
extern "C" void func_020acecc(void* ov, int a, int b);
extern "C" int func_ov017_021a01f4(void* ov, int mapId, int index, void* combatant, int* out);
extern "C" void func_ov017_0219fc88(void* self, int v);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_02196c08(unsigned char*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_ov017_021b6e70(struct Struct_ov017_0219e384_7* arg0, int v);
extern "C" void func_ov017_021b7104(void* node, struct Struct_ov017_0219e384_7* arg1);
extern "C" int func_020649f4(void* obj, void* out);
int LoadFileIntoMemory(const char* name, void* dst, unsigned int* size);
struct StreamHeader;
extern "C" int func_0208dc00(StreamHeader*, int, int);
extern "C" int Scenario_TestFlag(int a, unsigned char* arr, int bit);
extern "C" void func_ov017_021bba08(struct Struct_ov017_0219e384_11* node, void* header);
extern "C" void Scenario_SetFlag(void* a, unsigned char* arr, int bit, int set);
extern "C" void func_ov017_021d23bc(unsigned short v);
extern "C" void func_020a2788(void* obj, short v);
struct Struct_020a27cc;
extern "C" void func_020a27cc(Struct_020a27cc*);
struct Struct_020a2800;
extern "C" void func_020a2800(Struct_020a2800*);
extern "C" void func_020a2830(void* obj);
struct Struct_020a2868;
extern "C" void func_020a2868(Struct_020a2868*);
struct Struct_0204a170;
extern "C" int func_020a3570(Struct_0204a170*);
extern "C" void Camera_SetTargetKeepOrbit(char*, int*);
extern "C" void func_ov017_021982ac(void* ov);
extern "C" void func_020a2718(char*);
extern "C" void func_020dc2d0(int v);
struct Struct_020a2cbc;
extern "C" void func_020a2cbc(Struct_020a2cbc*, int);
extern "C" void func_020ae53c(int v);
extern "C" void func_020a8740(void);
extern "C" void MapDisplay_RecheckAllMembers(unsigned char*);
extern "C" void func_ov017_021a3338(void* ov);
extern "C" void func_ov017_021a65c4(void* ov, unsigned char a, int b);
extern "C" void func_ov017_021cdaa0(void);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021d2ad0(short, int, int, int, unsigned char);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" void func_ov017_021a7a74(void* ov, struct Struct_ov017_0219e384_7* arg1);
extern "C" int func_02076ccc(void* obj, int mode);
extern "C" void func_020a72ac(void* obj, unsigned char v);
extern "C" void* func_020936f8(void);
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
	void* var2 = battle->GetProtagonist();
	struct Combatant0219e384* actor = (struct Combatant0219e384*)battle->GetLeader();
	struct Field3f8* fld = GameState_GetZoneTransition(battle);
	struct BackgroundLoader* loader = BackgroundLoader::GetInstance();
	Zone3D* run = (Zone3D*)Zone3D_GetInstance();
	char* var7 = (char*)run + Field23ec;
	int var8 = (int)run + Enum_ov017_0219e384_2112;
	void* table468 = GameState_GetZoneTable(battle);
	struct InlineEntry* entryTable = ZoneRecords_GetInstance();
	void* obj5ec34 = Scenario_GetInstance();
	struct GrottoIds* ids = (struct GrottoIds*)GameState_GetParty(battle);
	struct SearchStruct* search = LinkSession_GetInstance();
	char* region = (char*)LootableContainerManager::GetMainInstance();
	void* flags14e04 = GlobalFlags_GetInstance();
	int* var16 = (int*)LightingManager::GetInstance();
	struct Struct_ov017_0219e384_10 workHi;
	struct Struct_ov017_0219e384_9 workLo;

	if (self->state == 0) {
		SubBlock02038508* byte26c = GameObject_GetLadderClimb(actor);
		if (GameObject_IsClimbingLadder((char*)actor) != 0 && byte26c->command != 2 && fld->f6c != 9999) {
			if (fld->f67 != 0) {
				*(Vector3i*)fld->unknown_10_ = *(Vector3i const*)actor->vec44;
			}
			return;
		}
		{
			int delta;
			int axis;
			int limit;
			void* obj;
			int var24;
			int cnt;
			unsigned short* var26;
			void* found;
			unsigned char* hdr;

			func_02097cac((void*)var8);
			func_0208f944((Struct_0208f944*)var7);
			var24 = run->currentZoneID_;
			func_020a696c(ov, fld->mapId, var24);
			found = ZoneTable_FindEntry((SearchTable*)table468, fld->mapId);
			hdr = (unsigned char*)run->pUnknownStruct_8_;
			self->active = 1;
			if (found != 0 && hdr != 0) {
				if (func_0209cd50(fld->mapId) == func_0209cae8((ShortField0xb8_0209cae8*)&g_bgmPlayer)) {
					self->active = 0;
				}
			}
			if (fld->f20 > 0) {
				self->active = 0;
			}
			if (self->active != 0) {
				BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
			}
			if (SoundPlayer_IsStreamPlaying(&g_sePlayer, 0) != 0) {
				SoundPlayer_StopStream(&g_bgmPlayer, 0, 0);
				self->active = 1;
			}
			cnt = *(unsigned short*)((char*)actor->unknown_130_ + 4);
			limit = 15;
			if (cnt <= 0) {
				limit = 60;
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
				limit = 0;
			}
			if ((fld->flags6e & 0x10) == 0) {
				if ((fld->flags6e & 1) != 0) {
					SetMainBrightness((GameResources*)ov, delta, limit);
				} else {
					SetBrightness((GameResources*)ov, delta, limit);
				}
			}
			if (fld->mode == 1) {
				SePlayer_Play((SePlayer*)&g_sePlayer, 15, 0);
			}
			GameObject_DisableControl((Obj020397cc*)actor, 1);
			actor->c2 &= ~0x40;
			var26 = (unsigned short*)(ov + Enum_ov017_0219e384_174);
			var26 = (unsigned short*)((char*)var26 + Enum_ov017_0219e384_17408);
			*(unsigned short*)(ov + Enum_ov017_0219e384_17582) = 0;
			var26[1] = 0;
			func_ov017_021c4664(fld->mapId, *(struct Vec3*)fld->unknown_10_, fld->unknown_1c_);
			if (LinkSession_IsGuest(search) != 0 && fld->f67 != 0 && *(unsigned short*)(ov + Field44ac) != 0) {
				*(unsigned short*)(ov + Field44ac) = 0;
			}
			if (fld->unknown_e_ != 0) {
				func_ov017_021d035c(0, GameState_GetLeaderIndex(battle), 1);
			}
			var24 = run->currentZoneID_;
			if (fld->mapId != var24) {
				struct GrottoIds* list2a04 = (struct GrottoIds*)GameState_GetParty(battle);
				int i;
				for (i = 0; i < list2a04->count; i++) {
					func_ov017_021d257c(list2a04->ids[i], 0);
				}
			}
			if (*(unsigned char*)(ov + Enum_ov017_0219e384_17129) != 0) {
				fld->active = 0;
			}
			obj = Scenario_GetInstance();
			workHi.turnNode.mapId = run->currentZoneID_;
			if (fld->active == 0 && Scenario_RunTrigger(obj, 0x1e, &workHi.turnNode) != 0) {
				EventQuery_RunQueuedCommands(&workHi.turnNode);
			}
			if (axis == 0) {
				self->state = 2;
				return;
			}
			self->state = 1;
		}
		return;
	}
	if (self->state == 1) {
		if (IsBrightnessTransitionActive((GameResources*)ov) == 0) {
			self->state = 2;
		}
		return;
	}
	if (self->state == 2) {
		void* context;
		void** tail;
		if (actor != 0 && GameObject_IsGesturing((signed char*)actor) != 0) {
			func_020531f0(actor);
		}
		if (loader->GetNumQueuedTasks() > 0) {
			return;
		}
		if (FieldTaskQueue_IsEmpty(*(void***)(ov + Field3700)) == 0) {
			return;
		}
		context = ObjLoading_GetInstance();
		tail = *(void***)(ov + Field3704);
		if (FieldTaskQueue_IsEmpty(tail) == 0) {
			if (func_02046b60((ListHead02046b60*)tail, 0x4c) == 0) {
				return;
			}
			if (func_020db2d4(context) != 0) {
				return;
			}
			func_020daf9c(1, 0, 1, 0);
			SetBrightness((GameResources*)ov, -16, 0);
			return;
		}
		if (LinkSession_IsActive((int*)search) != 0 &&
		    LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search) != 0 &&
		    TestFlags00((GameResources*)ov, 2) == 0) {
#if !defined(jpn)
			self->accum = self->accum + battle->GetEffectiveDeltaTime();
			if (self->accum > 15000) {
				self->unknown_b_ = 1;
				LinkSession_MarkSlotLost(search, 0);
			}
#endif
			if (self->unknown_b_ == 0) {
				return;
			}
#if !defined(jpn)
			self->accum = 0;
#endif
		}
		if (fld->flags6e != 1) {
			SetFlags04((GameResources*)ov, 1);
			FlagWord_SetBits((unsigned int*)flags14e04, 1);
		}
		SetFlags00((GameResources*)ov, 0x10);
		func_ov017_0219d250(ov, self->pending);
		self->pending = 0;
		self->state = 3;
		return;
	}
	if (self->state == 3) {
		struct InlineEntry* table;
		int found;
		struct InlineEntry* entry;
		signed char* grotto;
		unsigned char kind;
		unsigned short value;
		char* var39;
		int var40;

		if (func_020bc0f8(0x64, 15) > 0) {
			return;
		}
		if (run->unknown_424_ != 0) {
			return;
		}
		if (loader->GetNumQueuedTasks() > 0) {
			return;
		}
		func_ov017_0219c598(0, 0, 0);
		table = ZoneRecords_GetInstance();
		found = ZoneRecords_Add(table, run->currentZoneID_);
		entry = ZoneRecords_Find((Entry_02028bd0*)table, run->currentZoneID_);
		*(struct InlineEntry**)(ov + Enum_ov017_0219e384_14072) = entry;
		grotto = (signed char*)battle->GetGrottoStruct();
		if (ZoneId_IsGrotto(run->currentZoneID_) != 0) {
			entry->unknown_d_ = grotto[8];
		}
		kind = 0;
		value = 0;
		var39 = &((char*)run)[Field23ec];
		if (found != 0 && entry != 0) {
			void* tail = *(void**)(ov + Field3704);
			int off = entry->slotIndex;
			off *= sizeof(struct Struct_ov017_0219dc90_5);
			struct Struct_ov017_0219dc90_5* slot = (struct Struct_ov017_0219dc90_5*)(ov + Enum_ov017_0219e384_15004 + off);
			if (slot->used == 0) {
				func_ov017_021b46d8((Struct_ov017_0219dc90_3*)slot);
				slot->entry = entry;
				if (ZoneId_IsGrottoBossFloor(run->currentZoneID_) != 0 && ((unsigned char*)grotto)[3] == 0) {
					unsigned char* detail = (unsigned char*)((ActiveGrottoClass*)var39)->GetDetailedData();
					if (detail != 0) {
						unsigned char tag = detail[1];
						if (tag == 1) {
							slot->kind = tag;
							slot->value = *(unsigned short*)(detail + 0x54);
						} else if (tag == 2) {
							slot->kind = tag;
							slot->value = ((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->MaybeGetCurrentAlternateID();
						}
						kind = slot->kind;
						value = slot->value;
					}
				}
				func_020469b4((TailList020469b4*)tail, (TailNode020469b4*)slot);
			}
			self->state = 4;
		} else {
			if (ZoneId_IsGrottoBossFloor(run->currentZoneID_) != 0 && ((unsigned char*)grotto)[3] == 0) {
				unsigned char* detail = (unsigned char*)((ActiveGrottoClass*)var39)->GetDetailedData();
				if (detail != 0) {
					unsigned char tag = detail[1];
					if (tag == 1) {
						kind = tag;
						value = *(unsigned short*)(detail + 0x54);
					} else if (tag == 2) {
						kind = tag;
						value = ((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->MaybeGetCurrentAlternateID();
					}
				}
			}
			self->state = 5;
		}
		var40 = 0;
		if (LinkSession_IsHostOrSolo(search) != 0 && *(unsigned char*)((char*)run + Field281f) != 0) {
			var40 = 1;
		}
		*(unsigned char*)((char*)run + Field281f) = 0;
		if (fld->f20 > 0 || fld->f24 > 0) {
			func_ov017_021d035c(1, actor->unknown_4_, 1);
		}
		func_ov017_021c4854(run, kind, value, actor->vec44, (short)actor->unknown_54_, var40);
		{
			void* target = *(void**)(ov + Enum_ov017_0219e384_14132);
			if (LinkSession_IsActive((int*)search) != 0) {
				int i;
				for (i = 0; i < 4; i++) {
					void* c = battle->GetPartyMemberByIndex(i);
					if (c != 0 && func_02039790(c, 0x20) != 0) {
						func_ov017_021bd4d0(target, i, 0, 1);
					}
				}
			}
		}
		if (LinkSession_IsHostOrSolo(search) != 0 && ids->flagF7d != 0) {
			func_ov017_021ce400(ids->flagF7d, run->currentZoneID_);
		}
		return;
	}
	if (self->state == 4) {
		if (FieldTaskQueue_IsEmpty(*(void***)(ov + Field3704)) != 0) {
			self->state = 5;
		}
		return;
	}
	if (self->state == 5) {
		func_0208e520(LootPointList_GetInstance(), run->pUnknownStruct_8_->mapShortName_);
		((SafeAllocator*)(ov + 0x18c))->Reset();
		((LootableContainerManager*)region)->Reset();
		data_ov017_021d75b8.unknown_4_ = loader->QueueLoadFile(data_ov017_021d75fc, 0);
		self->state = 6;
		return;
	}
	if (self->state == 6) {
		if (loader->GetTaskStatus(data_ov017_021d75b8.unknown_4_) == 0) {
			return;
		}
		if (loader->GetDetailedTaskStatus(data_ov017_021d75b8.unknown_4_) == 2) {
			loader->GetLoadedFileByID(data_ov017_021d75b8.unknown_4_, &workLo.buf, &workLo.fileSize);
			if (workLo.buf != 0) {
				unsigned char* header = (unsigned char*)run->pUnknownStruct_8_;
				if (*(unsigned char*)((char*)run + Enum_ov017_0219e384_9144) != 0) {
					func_0201afd0(run, workLo.buf, workLo.fileSize, 0);
				} else {
					unsigned short id = *(unsigned short*)header;
					if (id >= 0xc546 && id <= 0xc546 + 0x15) {
						sprintf(workHi.name, data_ov017_021d7619, (char*)header + 5, id + (0x61 - 0xc546));
					} else {
						strcpy(workHi.name, (char*)header + 5);
					}
					((LootableContainerManager*)region)->LoadZoneContainers(workLo.buf, workLo.fileSize, workHi.name, (SafeAllocator*)0);
					Zone3D_SetUpContainers(run);
				}
			}
		}
		loader->RemoveTask(data_ov017_021d75b8.unknown_4_);
		{
			unsigned short id = run->currentZoneID_;
			data_ov017_021d75b8.unknown_4_ = -1;
			if (func_020981e4((int)var8, id) != 0 &&
			    func_02098210((int)var8, id) == 0 &&
			    LinkSession_IsGuest(search) != 0) {
				unsigned char* sub = (unsigned char*)var8;
				if (sub[0x1b62] == 0) {
					func_020daf9c(1, 0, 1, 0);
					SetBrightness((GameResources*)ov, -16, 0);
					self->state = 7;
					return;
				}
			}
		}
		self->state = 8;
		return;
	}
	if (self->state == 7) {
		unsigned char* sub = (unsigned char*)var8;
		if (sub[0x1b62] != 0) {
			self->state = 8;
		}
		return;
	}
	if (self->state == 8) {
		void* var56;
		void* var57;
		int mapId;
		int var59;
		unsigned char* header;
		char* var61;
		struct InlineEntry* entry;
		signed char* flag4;
		int var64;
		struct Struct_ov017_0219e384_11* node;

		if (loader->GetNumQueuedTasks() > 0) {
			return;
		}
		if (LinkSession_IsGuest(search) != 0 && fld->f67 != 0 && self->v20 == 0 && fld->f24 <= 0) {
			if (self->warp != 0xffff) {
				if (self->warp != 0) {
					fld->f24 = self->warp;
					fld->unknown_d_ = 1;
				} else if (*(unsigned short*)(ov + Field44ac) != 0) {
					fld->f24 = *(unsigned short*)(ov + Field44ac);
					*(unsigned short*)(ov + Field44ac) = 0;
				} else {
					self->timer = self->timer + battle->GetEffectiveDeltaTime();
					if (self->timer < 1000) {
						return;
					}
				}
			}
		}
		var56 = *(void**)(ov + Enum_ov017_0219e384_14076);
		var57 = func_0208e9e8();
		mapId = run->currentZoneID_;
		var59 = run->previousZoneID_;
		header = (unsigned char*)run->pUnknownStruct_8_;
		var61 = (char*)run + 0xc;
		entry = ZoneRecords_Find((Entry_02028bd0*)entryTable, mapId);
		flag4 = GameState_GetFollowCamera((char*)battle);
		workHi.unknown_90_ = *(Struct_02014900*)actor->vec44;
		var64 = (fld->f20 > 0) ? 1 : 0;
		if (var64 != 0) {
			self->active = 0;
		}
		node = *(struct Struct_ov017_0219e384_11**)(ov + Enum_ov017_0219e384_14132);
		if (node->flag2 != 0 && node->unknown_9b_ != 0) {
			self->active = 0;
			node->unknown_9b_ = 0;
		} else if (fld->inline_ov017_0219e384() >= 0) {
			int hasBit = ((*actor->unknown_130_ & 1) != 0);
			if (hasBit != 0) {
				if (fld->f24 < 21000 || fld->f24 >= 40000) {
					self->active = 1;
				}
			}
		}
		if (self->active != 0) {
			func_0209c3b4((Actor0209c3b4*)&g_bgmPlayer, func_0209cd50(mapId));
			if (LinkSession_IsActive((int*)search) != 0 && func_02086b98((Obj02086b98*)ids) != 0) {
				BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
			}
		}
		func_0209caa0((Obj0209caa0*)&g_bgmPlayer, ((unsigned int)header[0xd] << 24) >> 31);
		func_02064b98((unsigned char*)obj5ec34, *(unsigned short*)header);
		FlagWord_ClearBits((FlagWord020466f4*)flags14e04, 0x200000);
		if (fld->active == 0) {
			func_0208f3a8((Struct_0208f3a8*)var57);
			Scenario_LoadZoneTriggers(obj5ec34, (unsigned char*)run->pUnknownStruct_8_);
			func_02095b30(func_02094d6c(), 0);
		}
		if (LinkSession_IsHostOrSolo(search) != 0) {
			struct InlineEntry* e2 = ZoneRecords_Find((Entry_02028bd0*)entryTable, run->currentZoneID_);
			if (e2 != 0) {
				Zone3D_SetSearchedLootables(run, e2->group);
				Zone3D_OpenDoorsByMask(run, e2->f4);
			}
		} else if (var64 == 0 && *(unsigned char*)((char*)battle + Enum_ov017_0219e384_23724) == 0) {
			Zone3D_SetSearchedLootables(run, self->flagsE);
			Zone3D_OpenDoorsByMask(run, self->flags10);
		}
		func_02097ec8((char*)run + Enum_ov017_0219e384_2112);
		if ((fld->flags6e & 2) == 0) {
			func_ov017_021a2fa0(ov);
		}
		func_ov017_0219e180(ov, mapId);
		if (fld->active == 0) {
			struct Struct_ov017_0219e384_12* alloc = (struct Struct_ov017_0219e384_12*)(ov + 0x18c) + 1;
			((SafeAllocator*)alloc)->Reset();
			func_0208f168(var57, alloc);
		}
		_ZN8Object3D10SetField06Et(var2, mapId);
		func_0208fc30(var7);
		if (entry != 0) {
			func_020733c8((Struct_020733c8*)entry);
			if (entry->f34 != 0) {
				actor->b8 = NodeGraph_FindClosestNode(entry->vec18, actor->vec44);
				actor->c2 |= 0x40;
			}
		}
		ClearFlags04((GameResources*)ov, 1);
		ClearFlags00((GameResources*)ov, 0x10);
		func_ov017_021901ac(ov);
		func_020a6aac(ov, mapId, var59);
		func_020acecc(ov, mapId, var59);
		if ((fld->flags6e & 2) == 0 && LinkSession_IsGuest(search) != 0 && actor != 0) {
			if (func_ov017_021a01f4(ov, mapId, battle->GetTimeOfDay(), actor, (int*)&workHi.unknown_84_) != 0 && actor != 0) {
				*(Vector3i*)actor->vec44 = *(Vector3i const*)((int*)&workHi.unknown_84_);
			}
		}
		if (var64 != 0) {
			func_ov017_0219fc88(self, fld->f20);
		} else if (fld->f28 >= 0 && fld->unknown_2c_ == run->currentZoneID_ && fld->unknown_1e_ != fld->f28) {
			if (ZoneId_IsGrottoBossFloor(run->currentZoneID_) == 0) {
			void* n = *(void**)(ov + Enum_ov017_0219e384_14104);
			func_ov017_021b6f18(n);
			func_ov017_02196c08((unsigned char*)&workHi.msg);
			workHi.msg.kind = 1;
			workHi.msg.actor = GameState_GetProtagonistIndex(battle);
			workHi.msg.value = fld->f28 + 5 + 0x8000;
			workHi.msg.id = 0xffff;
			workHi.msg.f8 = fld->f28;
			workHi.msg.f12 = var16[0x26];
			func_ov017_021b6e70(&workHi.msg, workHi.msg.id);
			func_ov017_021b7104(n, &workHi.msg);
			func_020469b4((TailList020469b4*)var56, (TailNode020469b4*)n);
			fld->f28 = -1;
			fld->flags6e |= 1;
			ClearFlags00((GameResources*)ov, 0x800);
			}
		} else if (fld->f24 >= 0) {
			func_ov017_0219fc88(self, fld->f24);
		} else {
			void* obj2 = Scenario_GetInstance();
			int var71;
			workHi.node.mapId = mapId;
			if (fld->active == 0 && func_020649f4(obj2, &workHi.node) != 0) {
				EventQuery_RunQueuedCommands(&workHi.node);
			}
			var71 = func_02046b60((ListHead02046b60*)var56, 4);
			if (LinkSession_IsActive((int*)search) == 0 || LinkSession_IsHostOrSolo(search) != 0) {
				BackgroundLoader::AddLockGlobal();
				if (LoadFileIntoMemory(data_ov017_021d761e, g_fileLoadBuffer, &workLo.size) != 0 &&
				    func_0208dc00((StreamHeader*)g_fileLoadBuffer, workLo.size, (int)&workHi.slot) != 0 &&
				    Scenario_TestFlag((int)obj2, (unsigned char*)obj2 + 0x8c, workHi.slot + 0xea + 0xb00) == 0) {
					if (var71 == 0) {
						struct Struct_ov017_0219e384_11* n2 = *(struct Struct_ov017_0219e384_11**)(ov + Enum_ov017_0219e384_14132);
						func_ov017_021bba08(n2, (unsigned char*)run->pUnknownStruct_8_);
						n2->f8 = fld->f20;
						func_020469b4((TailList020469b4*)var56, (TailNode020469b4*)n2);
						fld->f20 = -1;
					} else {
						Scenario_SetFlag(obj2, (unsigned char*)obj2 + 0x8c, workHi.slot + 0xea + 0xb00, 1);
					}
				}
				BackgroundLoader::RemoveLockGlobal();
			}
		}
		fld->unknown_1e_ = -1;
		node = *(struct Struct_ov017_0219e384_11**)(ov + Enum_ov017_0219e384_14132);
		if (node->flag2 == 0 || node->f9c != 0 || node->f8 == 0) {
			func_ov017_021d23bc(0xffff);
		}
		if (fld->active == 0) {
			if (var61 != 0) {
				func_020a2788(flag4, *(short*)(var61 + Enum_ov017_0219e384_52));
			}
			switch (((unsigned int)header[0xc] << 25) >> 30) {
			case 0:
				func_020a27cc((Struct_020a27cc*)flag4);
				break;
			case 1:
				func_020a2800((Struct_020a2800*)flag4);
				break;
			case 2:
				func_020a2830(flag4);
				break;
			case 3:
				func_020a2868((Struct_020a2868*)flag4);
				break;
			default:
				func_020a2800((Struct_020a2800*)flag4);
				break;
			}
			if (func_020a3570((Struct_0204a170*)flag4) != 0) {
				workHi.unknown_0_ = *(Struct_02014900*)actor->vec44;
				workLo.fieldVec = *(Struct_02014900*)(flag4 + 0x10);
				Vector3fix_Subtract(&workHi.unknown_0_.vec, &workHi.unknown_90_.vec, &workLo.unknown_60_.vec);
				Vector3fix_Add(&workLo.fieldVec.vec, &workLo.unknown_60_.vec, &workLo.fieldVec.vec);
				Camera_SetTargetKeepOrbit((char*)flag4, (int*)&workLo.fieldVec);
			}
			func_ov017_021982ac(ov);
			func_020a2718((char*)flag4);
		}
		if ((fld->flags6e & 0x40) != 0) {
			func_020a2718((char*)flag4);
		}
		if ((fld->flags6e & 1) == 0) {
			FlagWord_ClearBits((FlagWord020466f4*)flags14e04, 1);
			func_020dc2d0(0);
		}
		func_020a2cbc((Struct_020a2cbc*)flag4, ((struct Struct_ov017_0219e384_5*)(header + 4))->unknown_0_0_ == 0 ? 1 : 0);
		func_020ae53c(1);
		func_020a8740();
		MapDisplay_RecheckAllMembers((unsigned char*)(*(void**)(ov + Field36d0)));
		func_ov017_021a3338(ov);
		if ((fld->flags6e & 8) != 0) {
			self->state = 9;
			return;
		}
		{
			FontBankLoader* g400 = FontBankLoader_GetInstance();
			FontBankLoader_CancelLoads(g400);
			func_02094b34(g400, 0x6f, 5000, 1, 1);
		}
		self->state = 10;
		return;
	}
	if (self->state == 10) {
		if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
			self->state = 9;
		}
		return;
	}
	if (self->state == 9) {
		int var74;
		int var75;
		int i;

		if (fld->unknown_69_ != 0 && func_02046b60((ListHead02046b60*)list, 0x3d) == 0) {
			func_ov017_021a65c4(ov, 1, 0);
		}
		var74 = 1;
		var75 = 1;
		if (func_02046b60((ListHead02046b60*)list, 4) != 0 ||
		    func_02046b60((ListHead02046b60*)list, 0xa) != 0 ||
		    func_02046b60((ListHead02046b60*)list, 0x3d) != 0) {
			var74 = 0;
			var75 = 0;
		}
		if (func_02046b60((ListHead02046b60*)list, 0x2a) != 0 ||
		    func_02046b60((ListHead02046b60*)list, 0xf) != 0) {
			var75 = 0;
		}
		if (func_02046b60((ListHead02046b60*)list, 0x2d) != 0) {
			var74 = 0;
		}
		if (LinkSession_IsHostOrSolo(search) != 0) {
			func_ov017_021cdaa0();
		}
		if (var74 != 0) {
			SetMainBrightness((GameResources*)ov, 0, 15);
		}
		if (var75 != 0) {
			GameObject_EnableControl(actor);
		}
		for (i = 0; i < ids->count; i++) {
			struct Combatant0219e384* c = (struct Combatant0219e384*)battle->GetPartyMemberByIndex(ids->ids[i]);
			if (c != 0 && GameObject_IsClimbingLadder((char*)c) != 0) {
				continue;
			}
			if (c != 0) {
				((Object3D*)c)->EnableFlag(0x4000000);
			}
			if (i > 0 && fld != 0 && fld->active == 0) {
				workLo.unknown_48_ = *(Struct_02014900*)actor->vec44;
				*(Vector3i*)c->vec44 = *(Vector3i const*)((int*)&workLo.unknown_48_);
				if (fld->mapId == 10000) {
					workLo.unknown_48_.entries[0] = 0xff000;
					workLo.unknown_48_.entries[1] = 0;
					workLo.unknown_48_.entries[2] = 0xff000;
				}
				func_ov017_021d2ad0(c->inline_ov017_0219e384_2(), workLo.unknown_48_.entries[0], workLo.unknown_48_.entries[1], workLo.unknown_48_.entries[2], 0);
			}
		}
		if (LinkSession_IsHostOrSolo(search) != 0 && fld != 0 && fld->active == 0) {
			void* c;
			*(Vector3i*)((int*)((char*)battle + Enum_ov017_0219e384_32608)) = *(Vector3i const*)actor->vec44;
			c = battle->GetPartyMemberByIndex(0xce);
			if (c != 0) {
				int* src = (int*)((char*)battle + Enum_ov017_0219e384_32608);
				int z = src[2];
				int y = src[1];
				int x = *(int*)((char*)battle + Enum_ov017_0219e384_32608);
				((struct Combatant0219e384*)c)->vec44[0] = x;
				((struct Combatant0219e384*)c)->vec44[1] = y;
				((struct Combatant0219e384*)c)->vec44[2] = z;
			}
		}
		if (LinkSession_IsHostOrSolo(search) != 0) {
			int* src = (int*)((char*)battle + Enum_ov017_0219e384_32608);
			func_ov017_021d2ad0(0xce, *(int*)((char*)battle + Enum_ov017_0219e384_32608), src[1], src[2], 0);
		}
		if (fld != 0 && (fld->flags6e & 0x20) != 0) {
			func_ov017_0219c598(0, 0, 1);
		}
		*(int*)((char*)MessageSystem_GetInstance() + MessageField) = 0;
		if (fld->f64 != 0) {
			GameState* battle2 = GameState::GetInstance();
			int* data2 = (int*)LightingManager::GetInstance();
			char* var86 = (char*)GetGameResources();
			struct Combatant0219e384* c;
			func_ov017_021b6f18(*(void**)(var86 + Enum_ov017_0219e384_14104));
			c = (struct Combatant0219e384*)battle2->GetPartyMemberByIndex(0);
			func_ov017_02196c08((unsigned char*)&workLo.unknown_24_);
			workLo.unknown_24_.kind = 1;
			workLo.unknown_24_.actor = 0;
			workLo.unknown_24_.value = c->unknown_1b2_;
			workLo.unknown_24_.id = -1;
			workLo.unknown_24_.fe = 1;
			workLo.unknown_24_.f14 = 1;
			workLo.unknown_24_.f12 = data2[0x26];
			func_ov017_021b6e70(&workLo.unknown_24_, -1);
			func_ov017_021a7a74(var86, &workLo.unknown_24_);
		} else if (fld->unknown_63_ != 0) {
			int j;
			int found2;
			unsigned short var90;
			struct InlineEntry* slot;
			unsigned short id;
			int var93;
			int* data2;
			GameState* battle2;
			char* var96;
			struct Combatant0219e384* var97;
			battle2 = GameState::GetInstance();
			data2 = (int*)LightingManager::GetInstance();
			var96 = (char*)GetGameResources();
			var97 = (struct Combatant0219e384*)func_0200ff1c(battle2, 0);
			if (var97 != 0 && var97->unknown_be_ == 2) {
				var90 = var97->unknown_1b2_;
				if (var90 != 0 && var90 >= 1 && var90 <= 0x7fff) {
					slot = *(struct InlineEntry**)(var96 + Enum_ov017_0219e384_14072);
					if (slot != 0) {
						var93 = *(unsigned short*)slot;
						found2 = 0x7fff - 0x8000;
						for (j = 0; j < 12; j++) {
							struct Npc0219e384* c;
							found2 = j + (slot->slotIndex * 12 + 0x70);
							c = (struct Npc0219e384*)battle2->GetFieldMonsterByIndex(found2);
							if (c == 0) {
								continue;
							}
							id = c->unknown_16a_;
							if (id != var90 || c->unknown_be_ != 2) {
								continue;
							}
							if (c->unknown_be_ == 6) {
								continue;
							}
							if (((Object3D*)c)->IsVisible() == 0) {
								continue;
							}
							if (var93 != ((Object3D*)c)->GetField06()) {
								continue;
							}
							if (inline_ov017_0219e384_3(c) != 8 && inline_ov017_0219e384_3(c) != 9 && inline_ov017_0219e384_3(c) != 0) {
								c->f166 = GameState_GetProtagonistIndex(battle2);
								func_02076ccc(c, 8);
							}
							var90 = id;
							break;
						}
						if (found2 >= 0) {
							func_ov017_021b6f18(*(void**)(var96 + Enum_ov017_0219e384_14104));
							func_ov017_02196c08((unsigned char*)&workLo.msgF63);
							workLo.msgF63.kind = 1;
							workLo.msgF63.actor = GameState_GetProtagonistIndex(battle2);
							workLo.msgF63.value = var90;
							workLo.msgF63.id = found2;
							func_ov017_021b6e70(&workLo.msgF63, found2);
							workLo.msgF63.f12 = data2[0x26];
							func_ov017_021a7a74(var96, &workLo.msgF63);
						}
					}
				}
			}
		}
		if (self->unknown_12_ != 0) {
			Zone3D* run2 = (Zone3D*)Zone3D_GetInstance();
			*(unsigned short*)((char*)run2 + Enum_ov017_0219e384_10118) = self->unknown_12_;
			if (((self->v14 << 18) >> 18) != -1) {
				*(unsigned short*)((char*)run2 + Enum_ov017_0219e384_10116) = (self->v14 << 18) >> 18;
			}
			*(unsigned char*)((char*)run2 + Enum_ov017_0219e384_10120) = (self->v14 << 16) >> 30;
			workLo.unknown_3c_.entries[0] = self->unknown_16_ << 7;
			workLo.unknown_3c_.entries[1] = self->v18 << 7;
			workLo.unknown_3c_.entries[2] = self->unknown_1a_ << 7;
			*(Vector3i*)((int*)((char*)run2 + Enum_ov017_0219e384_10100)) = *(Vector3i const*)((int*)&workLo.unknown_3c_);
			*(int*)((char*)run2 + Enum_ov017_0219e384_10112) = self->unknown_1c_;
			func_020a72ac(run2, self->unknown_1e_);
			VectorizedMemset(&self->unknown_12_, 0, 0xe);
		}
		if (*(short*)(ov + Enum_ov017_0219e384_17586) >= 0) {
			void* var100 = func_020936f8();
			func_02094030(var100, *(short*)(ov + Enum_ov017_0219e384_17586), -1, 0);
			*(short*)(ov + Enum_ov017_0219e384_17586) = -1;
		}
		self->done = 1;
	}
}
