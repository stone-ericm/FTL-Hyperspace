#include "FTLGameWin32.h"
#include "zhl_internal.h"

#ifdef _WIN32
    #define FUNC_NAKED __declspec(naked)
#elif defined(__linux__)
    #if __clang__
    #elif __GNUC__ < 8
        #error "GCC version too old, must be at least version 8"
    #endif
    #define FUNC_NAKED __attribute__((naked))
#endif

using namespace ZHL;

namespace _func0
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::LoadAchievementDescriptions", typeid(void (AchievementTracker::*)()), "57b87c0201008d7c240883e4f0ff77fc", argdata, 1, 5, &func);
}

void AchievementTracker::LoadAchievementDescriptions()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func0::func;
	return execfunc(this);
}

namespace _func1
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetVictoryAchievement", typeid(void (AchievementTracker::*)()), "578d7c240883e4f0ff77fc5589e55756538d7dc0", argdata, 1, 5, &func);
}

void AchievementTracker::SetVictoryAchievement()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func1::func;
	return execfunc(this);
}

namespace _func2
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetAchievement", typeid(void (AchievementTracker::*)(const std::string &, bool , bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b4704894dc40f", argdata, 4, 5, &func);
}

void AchievementTracker::SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &achievement_arg, bool noPopup_arg, bool sendToServer_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func2::func;
	return execfunc(this, achievement, noPopup, sendToServer);
}

namespace _func3
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AchievementTracker::SetFlag", typeid(void (AchievementTracker::*)(const std::string &)), "57ba050000008d7c240883e4f0ff77fc", argdata, 2, 5, &func);
}

void AchievementTracker::SetFlag(const std::string &flagName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg, const std::string &flagName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func3::func;
	return execfunc(this, flagName);
}

namespace _func4
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AchievementTracker::SetSectorEight", typeid(void (AchievementTracker::*)()), "578d7c240883e4f0ff77fc5589e55756538d45d08d5d", argdata, 1, 5, &func);
}

void AchievementTracker::SetSectorEight()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AchievementTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func4::func;
	return execfunc(this);
}

namespace _func5
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::OnRender", typeid(void (Animation::*)(float , GL_Color , bool )), "5589e557565389cb83e4f083ec408b45", argdata, 4, 5, &func);
}

void Animation::OnRender(float opacity, GL_Color color, bool mirror)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, float opacity_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func5::func;
	return execfunc(this, opacity, color, mirror);
}

namespace _func6
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::Update", typeid(void (Animation::*)()), "57660fefdb8d7c240883e4f0ff77fc55", argdata, 1, 5, &func);
}

void Animation::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func6::func;
	return execfunc(this);
}

namespace _func7
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SetCurrentFrame", typeid(void (Animation::*)(int )), "8b5104538b5c24088d42ff39d80f4fc3", argdata, 2, 5, &func);
}

void Animation::SetCurrentFrame(int frame)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, int frame_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func7::func;
	return execfunc(this, frame);
}

namespace _func8
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Animation::AddSoundQueue", typeid(void (Animation::*)(int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec3c8b178b", argdata, 3, 5, &func);
}

void Animation::AddSoundQueue(int frame, const std::string &sound)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, int frame_arg, const std::string &sound_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func8::func;
	return execfunc(this, frame, sound);
}

namespace _func9
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::RandomStart", typeid(int (Animation::*)()), "5589e55389cb83e4f0803d????????00754e", argdata, 1, 1, &func);
}

int Animation::RandomStart()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func9::func;
	return execfunc(this);
}

namespace _func10
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::SaveState", typeid(void (Animation::*)(int )), "5589e5565389cb83e4f083ec100fb641", argdata, 2, 5, &func);
}

void Animation::SaveState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func10::func;
	return execfunc(this, fd);
}

namespace _func11
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::LoadState", typeid(void (Animation::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b37893424e8204a", argdata, 2, 5, &func);
}

void Animation::LoadState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func11::func;
	return execfunc(this, fd);
}

namespace _func12
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Animation::Done", typeid(bool (Animation::*)()), "0fb6413284c0740e660fefc00f2e8194", argdata, 1, 1, &func);
}

bool Animation::Done()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func12::func;
	return execfunc(this);
}

namespace _func13
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Animation::Start", typeid(void (Animation::*)(bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec20803f000f", argdata, 2, 5, &func);
}

void Animation::Start(bool reset)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Animation *this_arg, bool reset_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func13::func;
	return execfunc(this, reset);
}

namespace _func14
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AnimationTracker::Update", typeid(void (AnimationTracker::*)()), "807910000f84f80000005589e55389cb", argdata, 1, 5, &func);
}

void AnimationTracker::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func14::func;
	return execfunc(this);
}

namespace _func15
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::SetLoop", typeid(void (AnimationTracker::*)(bool , float )), "8b442404f30f10442408f30f114114c7", argdata, 3, 5, &func);
}

void AnimationTracker::SetLoop(bool loop, float loopDelay)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool loop_arg, float loopDelay_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func15::func;
	return execfunc(this, loop, loopDelay);
}

namespace _func16
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Stop", typeid(void (AnimationTracker::*)(bool )), "807c240400c6411000660fefc07405f3", argdata, 2, 5, &func);
}

void AnimationTracker::Stop(bool resetTime)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, bool resetTime_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func16::func;
	return execfunc(this, resetTime);
}

namespace _func17
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Start", typeid(void (AnimationTracker::*)(float )), "f30f10442404c6411200c6411001f30f", argdata, 2, 5, &func);
}

void AnimationTracker::Start(float time)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func17::func;
	return execfunc(this, time);
}

namespace _func18
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::StartReverse", typeid(void (AnimationTracker::*)(float )), "660fefc9c6411200f30f10442404c641", argdata, 2, 5, &func);
}

void AnimationTracker::StartReverse(float time)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func18::func;
	return execfunc(this, time);
}

namespace _func19
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::SetProgress", typeid(void (AnimationTracker::*)(float )), "f30f104104f30f59442404f30f11410c", argdata, 2, 5, &func);
}

void AnimationTracker::SetProgress(float time)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func19::func;
	return execfunc(this, time);
}

namespace _func20
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AnimationTracker::Progress", typeid(float (AnimationTracker::*)(float )), "83ec0480791000f30f104c2408660fef", argdata, 2, 1, &func);
}

float AnimationTracker::Progress(float speed)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(AnimationTracker *this_arg, float speed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func20::func;
	return execfunc(this, speed);
}

namespace _func21
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ArmamentControl::LinkShip", typeid(void (ArmamentControl::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565331f689cb81", argdata, 2, 5, &func);
}

void ArmamentControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func21::func;
	return execfunc(this, ship);
}

namespace _func22
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ArmamentControl::CreateHolderTab", typeid(void (ArmamentControl::*)()), "578d7c240883e4f0ff77fc5589e55756538d7dc88d45", argdata, 1, 5, &func);
}

void ArmamentControl::CreateHolderTab()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArmamentControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func22::func;
	return execfunc(this);
}

namespace _func23
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ArtilleryBox::constructor", typeid(void (ArtilleryBox::*)(Point , ArtillerySystem *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b7708", argdata, 3, 5, &func);
}

void ArtilleryBox::constructor(Point pos, ArtillerySystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ArtilleryBox *this_arg, Point pos_arg, ArtillerySystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func23::func;
	return execfunc(this, pos, sys);
}

namespace _func24
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::GetNextAsteroid", typeid(Projectile *(AsteroidGenerator::*)()), "8b511839511c0f84b9010000578d7c24", argdata, 1, 1, &func);
}

Projectile *AsteroidGenerator::GetNextAsteroid()
{
	typedef Projectile *__attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func24::func;
	return execfunc(this);
}

namespace _func25
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::LoadAsteroids", typeid(void (AsteroidGenerator::*)(void *)), "5589e5565389cb83e4f083ec108b7508893424e838", argdata, 2, 5, &func);
}

void AsteroidGenerator::LoadAsteroids(void *file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, void *file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func25::func;
	return execfunc(this, file);
}

namespace _func26
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("AsteroidGenerator::OnLoop", typeid(void (AsteroidGenerator::*)()), "80b988000000007507f3c3908d742600", argdata, 1, 5, &func);
}

void AsteroidGenerator::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func26::func;
	return execfunc(this);
}

namespace _func27
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::Initialize", typeid(float (AsteroidGenerator::*)(int , int , bool )), "5589e55389cb8b450c83e4f089c28981", argdata, 4, 1, &func);
}

float AsteroidGenerator::Initialize(int numberOfShips, int shieldCount, bool defense)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, int numberOfShips_arg, int shieldCount_arg, bool defense_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func27::func;
	return execfunc(this, numberOfShips, shieldCount, defense);
}

namespace _func28
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("AsteroidGenerator::SaveAsteroids", typeid(bool (AsteroidGenerator::*)(void *)), "5589e5565389ce83e4f083ec108b5d08f30f1005", argdata, 2, 1, &func);
}

bool AsteroidGenerator::SaveAsteroids(void *file)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(AsteroidGenerator *this_arg, void *file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func28::func;
	return execfunc(this, file);
}

namespace _func29
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AugmentEquipBox::constructor", typeid(void (AugmentEquipBox::*)(Point , ShipManager *, int )), "578d7c240883e4f0ff77fc5589f889e557565389cb8d4db8", argdata, 4, 5, &func);
}

void AugmentEquipBox::constructor(Point loc, ShipManager *shipManager, int slot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AugmentEquipBox *this_arg, Point loc_arg, ShipManager *shipManager_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func29::func;
	return execfunc(this, loc, shipManager, slot);
}

namespace _func30
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("AugmentStoreBox::constructor", typeid(void (AugmentStoreBox::*)(ShipManager *, const AugmentBlueprint *)), "578d7c240883e4f0ff77fc5589f889e557565389cb8d4dd083ec4c8b7004", argdata, 3, 5, &func);
}

void AugmentStoreBox::constructor(ShipManager *ship, const AugmentBlueprint *bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(AugmentStoreBox *this_arg, ShipManager *ship_arg, const AugmentBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func30::func;
	return execfunc(this, ship, bp);
}

namespace _func31
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("BatteryBox::constructor", typeid(void (BatteryBox::*)(Point , BatterySystem *)), "578d7c240883e4f0ff77fc5589f889e557565389cf8d75d0", argdata, 3, 5, &func);
}

void BatteryBox::constructor(Point pos, BatterySystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BatteryBox *this_arg, Point pos_arg, BatterySystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func31::func;
	return execfunc(this, pos, sys);
}

namespace _func32
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x2ff, 0x2ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BeamWeapon::constructor", typeid(void (BeamWeapon::*)(Pointf , int , int , Pointf , Pointf , int , Targetable *, float )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b57", argdata, 9, 5, &func);
}

void BeamWeapon::constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float heading)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BeamWeapon *this_arg, Pointf _position_arg, int _ownerId_arg, int _targetId_arg, Pointf _target_arg, Pointf _target2_arg, int _length_arg, Targetable *_targetable_arg, float heading_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func32::func;
	return execfunc(this, _position, _ownerId, _targetId, _target, _target2, _length, _targetable, heading);
}

namespace _func33
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetShipBlueprint", typeid(ShipBlueprint *(BlueprintManager::*)(const std::string &, int )), "578d7c240883e4f0ff77fc5589e55756538d45d883ec5c", argdata, 3, 1, &func);
}

ShipBlueprint *BlueprintManager::GetShipBlueprint(const std::string &name, int sector)
{
	typedef ShipBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg, int sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func33::func;
	return execfunc(this, name, sector);
}

namespace _func34
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetAugmentValue", typeid(float (BlueprintManager::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d714c", argdata, 2, 1, &func);
}

float BlueprintManager::GetAugmentValue(const std::string &name)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func34::func;
	return execfunc(this, name);
}

namespace _func35
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::SetRarity", typeid(void (BlueprintManager::*)(const std::string &, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b378b47048d7964", argdata, 3, 5, &func);
}

void BlueprintManager::SetRarity(const std::string &name, int rarity)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg, int rarity_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func35::func;
	return execfunc(this, name, rarity);
}

namespace _func36
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetItemBlueprint", typeid(ItemBlueprint *(BlueprintManager::*)(const std::string &)), "578d91c80000008d7c240883e4f0ff77", argdata, 2, 1, &func);
}

ItemBlueprint *BlueprintManager::GetItemBlueprint(const std::string &name)
{
	typedef ItemBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func36::func;
	return execfunc(this, name);
}

namespace _func37
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomAugment", typeid(std::vector<AugmentBlueprint*> (BlueprintManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57040fb64f08895424088d504c", argdata, 4, 1, &func);
}

std::vector<AugmentBlueprint*> BlueprintManager::GetRandomAugment(int count, bool demo_lock)
{
	typedef std::vector<AugmentBlueprint*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func37::func;
	return execfunc(this, count, demo_lock);
}

namespace _func38
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetSystemBlueprint", typeid(SystemBlueprint *(BlueprintManager::*)(const std::string &)), "578d91e00000008d7c240883e4f0ff77", argdata, 2, 1, &func);
}

SystemBlueprint *BlueprintManager::GetSystemBlueprint(const std::string &name)
{
	typedef SystemBlueprint *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func38::func;
	return execfunc(this, name);
}

namespace _func39
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomWeapon", typeid(std::vector<WeaponBlueprint*> (BlueprintManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57040fb64f08895424088d501c", argdata, 4, 1, &func);
}

std::vector<WeaponBlueprint*> BlueprintManager::GetRandomWeapon(int count, bool demo_lock)
{
	typedef std::vector<WeaponBlueprint*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func39::func;
	return execfunc(this, count, demo_lock);
}

namespace _func40
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("BlueprintManager::GetRandomDrone", typeid(std::vector<DroneBlueprint*> (BlueprintManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57040fb64f08895424088d5034", argdata, 4, 1, &func);
}

std::vector<DroneBlueprint*> BlueprintManager::GetRandomDrone(int count, bool demo_lock)
{
	typedef std::vector<DroneBlueprint*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(BlueprintManager *this_arg, int count_arg, bool demo_lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func40::func;
	return execfunc(this, count, demo_lock);
}

namespace _func41
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::constructor", typeid(void (BossShip::*)(SpaceManager *)), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b0783", argdata, 2, 5, &func);
}

void BossShip::constructor(SpaceManager *space)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg, SpaceManager *space_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func41::func;
	return execfunc(this, space);
}

namespace _func42
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("BossShip::LoadBoss", typeid(void (BossShip::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec3c8b0789", argdata, 2, 5, &func);
}

void BossShip::LoadBoss(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func42::func;
	return execfunc(this, file);
}

namespace _func43
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::StartStage", typeid(void (BossShip::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8dbd", argdata, 1, 5, &func);
}

void BossShip::StartStage()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func43::func;
	return execfunc(this);
}

namespace _func44
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("BossShip::GetSubEvent", typeid(LocationEvent *(BossShip::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4ce805", argdata, 1, 1, &func);
}

LocationEvent *BossShip::GetSubEvent()
{
	typedef LocationEvent *__attribute__((thiscall)) (*custom_arg_funcptr_t)(BossShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func44::func;
	return execfunc(this);
}

namespace _func45
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Button::OnRender", typeid(void (Button::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b4154", argdata, 1, 5, &func);
}

void Button::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func45::func;
	return execfunc(this);
}

namespace _func46
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Button::SetImageBase", typeid(void (Button::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d45a889cb83ec7c8b3f", argdata, 2, 5, &func);
}

void Button::SetImageBase(const std::string &imageBase)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg, const std::string &imageBase_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func46::func;
	return execfunc(this, imageBase);
}

namespace _func47
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Button::OnInit", typeid(void (Button::*)(const std::string &, Point )), "57ba????????8d7c240883e4f0ff77fc5589e557565389ce", argdata, 3, 5, &func);
}

void Button::OnInit(const std::string &img, Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Button *this_arg, const std::string &img_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func47::func;
	return execfunc(this, img, pos);
}

namespace _func48
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CAchievement::OnRender", typeid(void (CAchievement::*)(Point , int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ecac0000008b078b57", argdata, 4, 5, &func);
}

void CAchievement::OnRender(Point pos, int selected, bool showNew)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CAchievement *this_arg, Point pos_arg, int selected_arg, bool showNew_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func48::func;
	return execfunc(this, pos, selected, showNew);
}

namespace _func49
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CAchievement::constructor", typeid(void (CAchievement::*)()), "578d41088d7c240883e4f0ff77fc5589e557565389cf", argdata, 1, 5, &func);
}

void CAchievement::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CAchievement *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func49::func;
	return execfunc(this);
}

namespace _func50
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnLoop", typeid(void (CApp::*)()), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec4c", argdata, 1, 5, &func);
}

void CApp::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func50::func;
	return execfunc(this);
}

namespace _func51
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::SetupWindow", typeid(int (CApp::*)()), "5589e55389cb83e4f083ec3080b93936", argdata, 1, 1, &func);
}

int CApp::SetupWindow()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func51::func;
	return execfunc(this);
}

namespace _func52
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::GenInputEvents", typeid(void (CApp::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec20e836", argdata, 1, 5, &func);
}

void CApp::GenInputEvents()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func52::func;
	return execfunc(this);
}

namespace _func53
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnRender", typeid(void (CApp::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5ce825", argdata, 1, 5, &func);
}

void CApp::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func53::func;
	return execfunc(this);
}

namespace _func54
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::UpdateFullScreen", typeid(void (CApp::*)()), "803d????????007407f3c3908d7426005589e557", argdata, 1, 5, &func);
}

void CApp::UpdateFullScreen()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func54::func;
	return execfunc(this);
}

namespace _func55
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnInit", typeid(int (CApp::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4cc7", argdata, 1, 1, &func);
}

int CApp::OnInit()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func55::func;
	return execfunc(this);
}

namespace _func56
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CApp::OnExecute", typeid(int (CApp::*)()), "578d7c240883e4f0ff77fc5589e557565389ceb9????????81ec2c", argdata, 1, 1, &func);
}

int CApp::OnExecute()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CApp *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func56::func;
	return execfunc(this);
}

namespace _func57
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CEvent::OnEvent", typeid(void (CEvent::*)(const InputEvent *)), "578d7c240883e4f0ff77fc5589e557565383ec4c8b1f8b43", argdata, 2, 5, &func);
}

void CEvent::OnEvent(const InputEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CEvent *this_arg, const InputEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func57::func;
	return execfunc(this, event);
}

namespace _func58
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CFPS::GetSpeedFactor", typeid(float (CFPS::*)()), "83ec04f30f104118f30f110424d90424", argdata, 1, 1, &func);
}

float CFPS::GetSpeedFactor()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CFPS *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func58::func;
	return execfunc(this);
}

namespace _func59
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_GetColor", typeid(GL_Color (*)()), "8b4424048b15????????89108b15????", argdata, 1, 2, &func);
}

GL_Color CSurface::GL_GetColor()
{
	typedef GL_Color __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func59::func;
	return execfunc();
}

namespace _func60
{
    static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColorTint", typeid(void (*)(GL_Color )), "8d4c240483e4f0ff71fc5589e55183ec14a1????????3b", argdata, 1, 6, &func);
}

void CSurface::GL_SetColorTint(GL_Color color)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func60::func;
	return execfunc(color);
}

namespace _func61
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_SetStencilMode", typeid(void (*)(GL_StencilMode , int , int )), "5589e5565383e4f083ec108b45088b5d0c8b751083", argdata, 3, 6, &func);
}

void CSurface::GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_StencilMode stencilMode_arg, int ref_arg, int mask_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func61::func;
	return execfunc(stencilMode, ref, mask);
}

namespace _func62
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_OrthoProjection", typeid(int (*)(float , float , float , float , float , float )), "5589e583e4f083ec20f30f10451cf30f", argdata, 6, 2, &func);
}

int CSurface::GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(float mx1_arg, float mx2_arg, float mx3_arg, float mx4_arg, float mx5_arg, float mx6_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func62::func;
	return execfunc(mx1, mx2, mx3, mx4, mx5, mx6);
}

namespace _func63
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_PushMatrix", typeid(int (*)()), "a1????????83f80f774689c10f2805??", argdata, 0, 2, &func);
}

int CSurface::GL_PushMatrix()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func63::func;
	return execfunc();
}

namespace _func64
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Scale", typeid(void (*)(float , float , float )), "55b90000000089e583e4f083ec10f30f", argdata, 3, 6, &func);
}

void CSurface::GL_Scale(float x, float y, float z)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func64::func;
	return execfunc(x, y, z);
}

namespace _func65
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Translate", typeid(bool (*)(float , float , float )), "55660fefc0b90000000089e583e4f083", argdata, 3, 2, &func);
}

bool CSurface::GL_Translate(float x, float y, float z)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func65::func;
	return execfunc(x, y, z);
}

namespace _func66
{
    static void *func = 0;
	static short argdata[] = {0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_SetColor", typeid(int (*)(GL_Color )), "5589e583e4f083ec208b4508f30f1045", argdata, 1, 2, &func);
}

int CSurface::GL_SetColor(GL_Color color)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func66::func;
	return execfunc(color);
}

namespace _func67
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_RemoveColorTint", typeid(void (*)()), "a1????????3b05????????740883e810", argdata, 0, 6, &func);
}

void CSurface::GL_RemoveColorTint()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func67::func;
	return execfunc();
}

namespace _func68
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GetColorTint", typeid(GL_Color (*)()), "8b15????????8b0d????????5539d189", argdata, 1, 2, &func);
}

GL_Color CSurface::GetColorTint()
{
	typedef GL_Color __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func68::func;
	return execfunc();
}

namespace _func69
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("CSurface::GL_EnableBlend", typeid(bool (*)()), "5589e583e4f083ec10c7442408040000", argdata, 0, 2, &func);
}

bool CSurface::GL_EnableBlend()
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func69::func;
	return execfunc();
}

namespace _func70
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitImagePartial", typeid(bool (*)(GL_Texture *, float , float , float , float , float , float , float , float , float , GL_Color , bool )), "5589e557565383e4f083ec60????????8b", argdata, 12, 2, &func);
}

bool CSurface::GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float start_x_arg, float end_x_arg, float start_y_arg, float end_y_arg, float alpha_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func70::func;
	return execfunc(tex, x, y, size_x, size_y, start_x, end_x, start_y, end_y, alpha, color, mirror);
}

namespace _func71
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DestroyPrimitive", typeid(void (*)(GL_Primitive *)), "5589e55383e4f083ec108b5d0885db74138b4324", argdata, 1, 6, &func);
}

void CSurface::GL_DestroyPrimitive(GL_Primitive *primitive)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Primitive *primitive_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func71::func;
	return execfunc(primitive);
}

namespace _func72
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectPrimitive", typeid(GL_Primitive *(*)(float , float , float , float , GL_Color )), "5589e55383e4f083ec50f30f10450cc7", argdata, 5, 2, &func);
}

GL_Primitive *CSurface::GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(float x_arg, float y_arg, float w_arg, float h_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func72::func;
	return execfunc(x, y, w, h, color);
}

namespace _func73
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateMultiImagePrimitive", typeid(GL_Primitive *(*)(GL_Texture *, std::vector<GL_TexVertex> *, GL_Color )), "8d4c240483e4f0ff71fc5589e55756535183ec588b71", argdata, 3, 2, &func);
}

GL_Primitive *CSurface::GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, std::vector<GL_TexVertex> *vec_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func73::func;
	return execfunc(tex, vec, color);
}

namespace _func74
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRectOutline", typeid(bool (*)(int , int , int , int , GL_Color , float )), "5589e583e4f081ecc00100008b55108b", argdata, 6, 2, &func);
}

bool CSurface::GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x1_arg, int y1_arg, int x2_arg, int y2_arg, GL_Color color_arg, float lineWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func74::func;
	return execfunc(x1, y1, x2, y2, color, lineWidth);
}

namespace _func75
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateImagePartialPrimitive", typeid(GL_Primitive *(*)(GL_Texture *, float , float , float , float , float , float , float , float , float , GL_Color , bool )), "8d4c240483e4f0ff71fc5589e55756535183ec7880", argdata, 12, 2, &func);
}

GL_Primitive *CSurface::GL_CreateImagePartialPrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, float x_arg, float y_arg, float size_x_arg, float size_y_arg, float start_x_arg, float end_x_arg, float start_y_arg, float end_y_arg, float alpha_arg, GL_Color color_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func75::func;
	return execfunc(tex, x, y, size_x, size_y, start_x, end_x, start_y, end_y, alpha, color, mirror);
}

namespace _func76
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawRect", typeid(bool (*)(float , float , float , float , GL_Color )), "5589e583e4f081ec90000000a1??????", argdata, 5, 2, &func);
}

bool CSurface::GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(float x1_arg, float y1_arg, float x2_arg, float y2_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func76::func;
	return execfunc(x1, y1, x2, y2, color);
}

namespace _func77
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::AddTexVertices", typeid(void (*)(std::vector<GL_TexVertex> *, float , float , float , float , float , float , float , float )), "8d4c240483e4f0ff71fc5589e55756535183ec388b39f3", argdata, 9, 6, &func);
}

void CSurface::AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(std::vector<GL_TexVertex> *vec_arg, float x1_arg, float y1_arg, float u1_arg, float v1_arg, float x2_arg, float y2_arg, float u2_arg, float v2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func77::func;
	return execfunc(vec, x1, y1, u1, v1, x2, y2, u2, v2);
}

namespace _func78
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_BlitMultiImage", typeid(void (*)(GL_Texture *, const std::vector<GL_TexVertex> &, bool )), "5589e557565383e4f083ec508b45108b15????????8b5d088b7d0c89442434", argdata, 3, 6, &func);
}

void CSurface::GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(GL_Texture *tex_arg, const std::vector<GL_TexVertex> &texVertices_arg, bool antialias_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func78::func;
	return execfunc(tex, texVertices, antialias);
}

namespace _func79
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x2ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawTriangle", typeid(bool (*)(Point , Point , Point , GL_Color )), "5589e557565383e4f083ec608b45088b", argdata, 4, 2, &func);
}

bool CSurface::GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(Point vertex1_arg, Point vertex2_arg, Point vertex3_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func79::func;
	return execfunc(vertex1, vertex2, vertex3, color);
}

namespace _func80
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_Rotate", typeid(void (*)(float , float , float , float )), "55660fefe489e5565383e4f081ec0001", argdata, 4, 6, &func);
}

void CSurface::GL_Rotate(float angle, float x, float y, float z)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float angle_arg, float x_arg, float y_arg, float z_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func80::func;
	return execfunc(angle, x, y, z);
}

namespace _func81
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("CSurface::GL_DrawEllipse", typeid(bool (*)(int , int , int , int , GL_Color )), "8d4c240483e4f0ff71fc5589e55756535181ece80000008b41", argdata, 5, 2, &func);
}

bool CSurface::GL_DrawEllipse(int x, int y, int a1, int b1, GL_Color color)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, int a1_arg, int b1_arg, GL_Color color_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func81::func;
	return execfunc(x, y, a1, b1, color);
}

namespace _func82
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CSurface::GL_CreateRectOutlinePrimitive", typeid(GL_Primitive *(*)(int , int , int , int , GL_Color , float )), "55660fefdb660fefe489e553660fefd2", argdata, 6, 2, &func);
}

GL_Primitive *CSurface::GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth)
{
	typedef GL_Primitive *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int x_arg, int y_arg, int w_arg, int h_arg, GL_Color color_arg, float lineWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func82::func;
	return execfunc(x, y, w, h, color, lineWidth);
}

namespace _func83
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetImagePath", typeid(void (CachedImage::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec1c", argdata, 2, 5, &func);
}

void CachedImage::SetImagePath(const std::string &imagePath)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &imagePath_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func83::func;
	return execfunc(this, imagePath);
}

namespace _func84
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::constructor2", typeid(void (CachedImage::*)(const std::string &, CachedImage::Centered )), "578d51108d7c240883e4f0ff77fc5589", argdata, 3, 5, &func);
}

void CachedImage::constructor2(const std::string &path, CachedImage::Centered centered)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const std::string &path_arg, CachedImage::Centered centered_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func84::func;
	return execfunc(this, path, centered);
}

namespace _func85
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::constructor_copy", typeid(void (CachedImage::*)(const CachedImage &)), "578d41108d7c240883e4f0ff77fc5589", argdata, 2, 5, &func);
}

void CachedImage::constructor_copy(const CachedImage &other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, const CachedImage &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func85::func;
	return execfunc(this, other);
}

namespace _func86
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetRotation", typeid(void (CachedImage::*)(float )), "5589e55383e4f083ec20f30f1045080f", argdata, 2, 5, &func);
}

void CachedImage::SetRotation(float _rotation)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float _rotation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func86::func;
	return execfunc(this, _rotation);
}

namespace _func87
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetMirrored", typeid(void (CachedImage::*)(bool )), "5589e5565383e4f083ec108b750889f0", argdata, 2, 5, &func);
}

void CachedImage::SetMirrored(bool _mirrored)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, bool _mirrored_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func87::func;
	return execfunc(this, _mirrored);
}

namespace _func88
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetScale", typeid(void (CachedImage::*)(float , float )), "5589e55383e4f083ec10f30f1045080f2e412c", argdata, 3, 5, &func);
}

void CachedImage::SetScale(float wScale, float hScale)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float wScale_arg, float hScale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func88::func;
	return execfunc(this, wScale, hScale);
}

namespace _func89
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetPartial", typeid(void (CachedImage::*)(float , float , float , float )), "5589e55383e4f083ec10f30f1045080f2e4134", argdata, 5, 5, &func);
}

void CachedImage::SetPartial(float x_start, float y_start, float x_size, float y_size)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, float x_start_arg, float y_start_arg, float x_size_arg, float y_size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func89::func;
	return execfunc(this, x_start, y_start, x_size, y_size);
}

namespace _func90
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CachedImage::SetPosition", typeid(void (CachedImage::*)(int , int )), "5589e557565383e4f083ec108b7508397124", argdata, 3, 5, &func);
}

void CachedImage::SetPosition(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedImage *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func90::func;
	return execfunc(this, x, y);
}

namespace _func91
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CachedPrimitive::destructor", typeid(void (CachedPrimitive::*)()), "5589e583e4f083ec108b4104c701????", argdata, 1, 5, &func);
}

void CachedPrimitive::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CachedPrimitive *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func91::func;
	return execfunc(this);
}

namespace _func92
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ChoiceBox::MouseMove", typeid(void (ChoiceBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b470489", argdata, 3, 5, &func);
}

void ChoiceBox::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func92::func;
	return execfunc(this, x, y);
}

namespace _func93
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ChoiceBox::MouseClick", typeid(void (ChoiceBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e55783ec14833d", argdata, 3, 5, &func);
}

void ChoiceBox::MouseClick(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func93::func;
	return execfunc(this, mX, mY);
}

namespace _func94
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ChoiceBox::OnRender", typeid(void (ChoiceBox::*)()), "578d7c240883e4f0ff77fc5589e557565389ce81ecdc02", argdata, 1, 5, &func);
}

void ChoiceBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ChoiceBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func94::func;
	return execfunc(this);
}

namespace _func95
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloakingSystem::FiredWeapon", typeid(void (CloakingSystem::*)()), "57????????008d7c240883e4f0ff77fc5589e55756538d45d08d75d889cb83c1", argdata, 1, 5, &func);
}

void CloakingSystem::FiredWeapon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloakingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func95::func;
	return execfunc(this);
}

namespace _func96
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloneSystem::GetProgress", typeid(float (CloneSystem::*)()), "5589e55389cb83e4f083ec10e85f69ff", argdata, 1, 1, &func);
}

float CloneSystem::GetProgress()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func96::func;
	return execfunc(this);
}

namespace _func97
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CloneSystem::CloneReady", typeid(CrewMember *(CloneSystem::*)()), "5589e5538b99c4010000c781c4010000", argdata, 1, 1, &func);
}

CrewMember *CloneSystem::CloneReady()
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CloneSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func97::func;
	return execfunc(this);
}

namespace _func98
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatAI::PrioritizeSystem", typeid(int (CombatAI::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4ca1", argdata, 2, 1, &func);
}

int CombatAI::PrioritizeSystem(int weaponType)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatAI *this_arg, int weaponType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func98::func;
	return execfunc(this, weaponType);
}

namespace _func99
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatAI::UpdateMindControl", typeid(void (CombatAI::*)(bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b4130", argdata, 2, 5, &func);
}

void CombatAI::UpdateMindControl(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatAI *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func99::func;
	return execfunc(this, unk);
}

namespace _func100
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::OnRenderCombat", typeid(void (CombatControl::*)()), "80b9a80e0000000f8423010000578d7c", argdata, 1, 5, &func);
}

void CombatControl::OnRenderCombat()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func100::func;
	return execfunc(this);
}

namespace _func101
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::AddEnemyShip", typeid(void (CombatControl::*)(CompleteShip *)), "578d7c240883e4f0ff77fc5589e557565383ec5c8b91", argdata, 2, 5, &func);
}

void CombatControl::AddEnemyShip(CompleteShip *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, CompleteShip *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func101::func;
	return execfunc(this, ship);
}

namespace _func102
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::UpdateAiming", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b8170", argdata, 1, 5, &func);
}

void CombatControl::UpdateAiming()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func102::func;
	return execfunc(this);
}

namespace _func103
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("CombatControl::OnInit", typeid(void (CombatControl::*)(Point )), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b078b", argdata, 2, 5, &func);
}

void CombatControl::OnInit(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func103::func;
	return execfunc(this, pos);
}

namespace _func104
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::WeaponsArmed", typeid(bool (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b4904c7042409000000e8ec", argdata, 1, 1, &func);
}

bool CombatControl::WeaponsArmed()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func104::func;
	return execfunc(this);
}

namespace _func105
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::KeyDown", typeid(void (CombatControl::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565389cb83c11483ec1c", argdata, 2, 5, &func);
}

void CombatControl::KeyDown(SDLKey key)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func105::func;
	return execfunc(this, key);
}

namespace _func106
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::DisarmTeleporter", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b4904c7042409", argdata, 1, 5, &func);
}

void CombatControl::DisarmTeleporter()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func106::func;
	return execfunc(this);
}

namespace _func107
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::GetCrewTooltip", typeid(std::string (CombatControl::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b17", argdata, 4, 1, &func);
}

std::string CombatControl::GetCrewTooltip(int x, int y)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func107::func;
	return execfunc(this, x, y);
}

namespace _func108
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::Clear", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec1cc7", argdata, 1, 5, &func);
}

void CombatControl::Clear()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func108::func;
	return execfunc(this);
}

namespace _func109
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::GetTeleportationCommand", typeid(std::pair<int, int> (CombatControl::*)()), "5589e55756538b815c07000089ce83e4", argdata, 1, 9, &func);
}

std::pair<int, int> CombatControl::GetTeleportationCommand()
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func109::func;
	return execfunc(this);
}

namespace _func110
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseClick", typeid(void (CombatControl::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83c11483ec6c", argdata, 4, 5, &func);
}

void CombatControl::MouseClick(int mX, int mY, bool shift)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func110::func;
	return execfunc(this, mX, mY, shift);
}

namespace _func111
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::MouseMove", typeid(bool (CombatControl::*)(int , int )), "57660fefc08d7c240883e4f0ff77fc5589e557565383", argdata, 3, 1, &func);
}

bool CombatControl::MouseMove(int mX, int mY)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func111::func;
	return execfunc(this, mX, mY);
}

namespace _func112
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff, 0x1ff};
	static FunctionDefinition funcObj("CombatControl::DrawHostileBox", typeid(void (CombatControl::*)(GL_Color , int )), "578d7c240883e4f0ff77fc5589e55756538d5dc8", argdata, 3, 5, &func);
}

void CombatControl::DrawHostileBox(GL_Color color, int stencilBit)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg, GL_Color color_arg, int stencilBit_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func112::func;
	return execfunc(this, color, stencilBit);
}

namespace _func113
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::OnRenderSelfAiming", typeid(void (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83c114", argdata, 1, 5, &func);
}

void CombatControl::OnRenderSelfAiming()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func113::func;
	return execfunc(this);
}

namespace _func114
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CombatControl::CanTargetSelf", typeid(char (CombatControl::*)()), "578d7c240883e4f0ff77fc5589e557565383ec5c8b81a4", argdata, 1, 1, &func);
}

char CombatControl::CanTargetSelf()
{
	typedef char __attribute__((thiscall)) (*custom_arg_funcptr_t)(CombatControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func114::func;
	return execfunc(this);
}

namespace _func115
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::RunCommand", typeid(void (CommandGui::*)(std::string &)), "578d7c240883e4f0ff77fc5589e55756538d459081ec9c", argdata, 2, 5, &func);
}

void CommandGui::RunCommand(std::string &command)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, std::string &command_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func115::func;
	return execfunc(this, command);
}

namespace _func116
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::RenderStatic", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c803d", argdata, 1, 5, &func);
}

void CommandGui::RenderStatic()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func116::func;
	return execfunc(this);
}

namespace _func117
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::RenderPlayerShip", typeid(void (CommandGui::*)(Point &, float )), "578d7c240883e4f0ff77fc5589e557565389cb8d4dd883ec3c8b37", argdata, 3, 5, &func);
}

void CommandGui::RenderPlayerShip(Point &shipCenter, float jumpScale)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, Point &shipCenter_arg, float jumpScale_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func117::func;
	return execfunc(this, shipCenter, jumpScale);
}

namespace _func118
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CommandGui::MouseMove", typeid(void (CommandGui::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ceb9????????81ecfc", argdata, 3, 5, &func);
}

void CommandGui::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func118::func;
	return execfunc(this, mX, mY);
}

namespace _func119
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::CheckGameover", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d45", argdata, 1, 5, &func);
}

void CommandGui::CheckGameover()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func119::func;
	return execfunc(this);
}

namespace _func120
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::IsGameOver", typeid(bool (CommandGui::*)()), "803d????????0075695589e55389cb8b", argdata, 1, 1, &func);
}

bool CommandGui::IsGameOver()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func120::func;
	return execfunc(this);
}

namespace _func121
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::ClearLocation", typeid(void (CommandGui::*)()), "5589e5538b8108170000c78154170000", argdata, 1, 5, &func);
}

void CommandGui::ClearLocation()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func121::func;
	return execfunc(this);
}

namespace _func122
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::Restart", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e557568db1780100005389cb8dbbc803000083ec2cc681d419000000c681d519000000c681d61900000089f1e812", argdata, 1, 5, &func);
}

void CommandGui::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func122::func;
	return execfunc(this);
}

namespace _func123
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CommandGui::OnInit", typeid(void (CommandGui::*)()), "578d7c240883e4f0ff77fc5589e55756538d9920", argdata, 1, 5, &func);
}

void CommandGui::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CommandGui *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func123::func;
	return execfunc(this);
}

namespace _func124
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::constructor", typeid(void (CompleteShip::*)(SpaceManager *, bool , int )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b47", argdata, 4, 5, &func);
}

void CompleteShip::constructor(SpaceManager *space, bool unk, int unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, SpaceManager *space_arg, bool unk_arg, int unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func124::func;
	return execfunc(this, space, unk, unk2);
}

namespace _func125
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetShip", typeid(void (CompleteShip::*)(ShipManager *)), "5783c1188d7c240883e4f0ff77fc5589e55783ec148b078b", argdata, 2, 5, &func);
}

void CompleteShip::SetShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func125::func;
	return execfunc(this, ship);
}

namespace _func126
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnInit", typeid(void (CompleteShip::*)(const ShipBlueprint *, int )), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec2c8b50", argdata, 3, 5, &func);
}

void CompleteShip::OnInit(const ShipBlueprint *blueprint, int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const ShipBlueprint *blueprint_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func126::func;
	return execfunc(this, blueprint, unk);
}

namespace _func127
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember1", typeid(CrewMember *(CompleteShip::*)(const std::string &, const std::string &, bool )), "578d7c240883e4f0ff77fc5589e557565381ec8c02", argdata, 4, 1, &func);
}

CrewMember *CompleteShip::AddCrewMember1(const std::string &race, const std::string &name, bool hostile)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const std::string &race_arg, const std::string &name_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func127::func;
	return execfunc(this, race, name, hostile);
}

namespace _func128
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SaveState", typeid(void (CompleteShip::*)(int )), "5589e583e4f083ec108b813001000089", argdata, 2, 5, &func);
}

void CompleteShip::SaveState(int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func128::func;
	return execfunc(this, unk);
}

namespace _func129
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::LoadState", typeid(void (CompleteShip::*)(int )), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b078904", argdata, 2, 5, &func);
}

void CompleteShip::LoadState(int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func129::func;
	return execfunc(this, unk);
}

namespace _func130
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::InitiateTeleport", typeid(void (CompleteShip::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b811c", argdata, 3, 5, &func);
}

void CompleteShip::InitiateTeleport(int targetRoom, int command)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int targetRoom_arg, int command_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func130::func;
	return execfunc(this, targetRoom, command);
}

namespace _func131
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnLoop", typeid(void (CompleteShip::*)()), "578d7c240883e4f0ff77fc5589e557565389cf31db83ec2c", argdata, 1, 5, &func);
}

void CompleteShip::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func131::func;
	return execfunc(this);
}

namespace _func132
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::Jump", typeid(void (CompleteShip::*)()), "8b811801000089811c0100008b812401", argdata, 1, 5, &func);
}

void CompleteShip::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func132::func;
	return execfunc(this);
}

namespace _func133
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::DeadCrew", typeid(bool (CompleteShip::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c0fb641", argdata, 1, 1, &func);
}

bool CompleteShip::DeadCrew()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func133::func;
	return execfunc(this);
}

namespace _func134
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddCrewMember", typeid(CrewMember *(CompleteShip::*)(const CrewBlueprint *, bool )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b378b7f0485", argdata, 3, 1, &func);
}

CrewMember *CompleteShip::AddCrewMember(const CrewBlueprint *blueprint, bool hostile)
{
	typedef CrewMember *__attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, const CrewBlueprint *blueprint_arg, bool hostile_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func134::func;
	return execfunc(this, blueprint, hostile);
}

namespace _func135
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::AddBoarders", typeid(void (CompleteShip::*)(int , const std::string &, bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec3c8b178b5f0485d2750485db757329d383fb0f895de4772683fb018b06755c0fb61288108b5de48b06895e04c60418008d65f45b5e5f5d8d67f85fc208008d45e489f1c7442404000000008955d4890424e8551d", argdata, 4, 5, &func);
}

void CompleteShip::AddBoarders(int amount, const std::string &race, bool unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, int amount_arg, const std::string &race_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func135::func;
	return execfunc(this, amount, race, unk2);
}

namespace _func136
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::SetEnemyShip", typeid(void (CompleteShip::*)(CompleteShip *)), "5783c1188d7c240883e4f0ff77fc5589e55783ec148b078941", argdata, 2, 5, &func);
}

void CompleteShip::SetEnemyShip(CompleteShip *other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, CompleteShip *other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func136::func;
	return execfunc(this, other);
}

namespace _func137
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CompleteShip::OnRenderSpace", typeid(void (CompleteShip::*)()), "578d7c240883e4f0ff77fc5589e55783ec148b510c", argdata, 1, 5, &func);
}

void CompleteShip::OnRenderSpace()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func137::func;
	return execfunc(this);
}

namespace _func138
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CompleteShip::OnRenderShip", typeid(void (CompleteShip::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b43048b37", argdata, 3, 5, &func);
}

void CompleteShip::OnRenderShip(bool unk1, bool unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CompleteShip *this_arg, bool unk1_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func138::func;
	return execfunc(this, unk1, unk2);
}

namespace _func139
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::SetText", typeid(void (ConfirmWindow::*)(const TextString &, int , bool , const TextString &, const TextString &)), "578d7c240883e4f0ff77fc5589f889e557565389cb83ec7c8b50", argdata, 6, 5, &func);
}

void ConfirmWindow::SetText(const TextString &text_, int minWidth, bool autoCenter, const TextString &yesText_, const TextString &noText_)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, const TextString &text__arg, int minWidth_arg, bool autoCenter_arg, const TextString &yesText__arg, const TextString &noText__arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func139::func;
	return execfunc(this, text_, minWidth, autoCenter, yesText_, noText_);
}

namespace _func140
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::OnRender", typeid(void (ConfirmWindow::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81eccc0000008b81", argdata, 1, 5, &func);
}

void ConfirmWindow::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func140::func;
	return execfunc(this);
}

namespace _func141
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("ConfirmWindow::SetPosition", typeid(void (ConfirmWindow::*)(Point )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b078b570489", argdata, 2, 5, &func);
}

void ConfirmWindow::SetPosition(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func141::func;
	return execfunc(this, pos);
}

namespace _func142
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ConfirmWindow::MouseMove", typeid(void (ConfirmWindow::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec1c807904", argdata, 3, 5, &func);
}

void ConfirmWindow::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func142::func;
	return execfunc(this, mX, mY);
}

namespace _func143
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::constructor", typeid(void (ConfirmWindow::*)()), "5589e55389cb83e4f0e8323a01008d43", argdata, 1, 5, &func);
}

void ConfirmWindow::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func143::func;
	return execfunc(this);
}

namespace _func144
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ConfirmWindow::Close", typeid(void (ConfirmWindow::*)()), "5589e55389cb83e4f083ec10????????0000890424e856", argdata, 1, 5, &func);
}

void ConfirmWindow::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ConfirmWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func144::func;
	return execfunc(this);
}

namespace _func145
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ControlButton::OnRender", typeid(void (ControlButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b41", argdata, 1, 5, &func);
}

void ControlButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ControlButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func145::func;
	return execfunc(this);
}

namespace _func146
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CooldownSystemBox::OnRender", typeid(void (CooldownSystemBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c0f", argdata, 2, 5, &func);
}

void CooldownSystemBox::OnRender(bool ignoreStatus)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CooldownSystemBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func146::func;
	return execfunc(this, ignoreStatus);
}

namespace _func147
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CreditScreen::Done", typeid(bool (CreditScreen::*)()), "55660fefc089e553bbabaaaaaa83e4f0", argdata, 1, 1, &func);
}

bool CreditScreen::Done()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CreditScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func147::func;
	return execfunc(this);
}

namespace _func148
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x3ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::PrioritizeTask", typeid(int (CrewAI::*)(CrewTask , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b70", argdata, 3, 1, &func);
}

int CrewAI::PrioritizeTask(CrewTask task, int crewId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg, CrewTask task_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func148::func;
	return execfunc(this, task, crewId);
}

namespace _func149
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::CheckForProblems", typeid(void (CrewAI::*)()), "578d7c240883e4f0ff77fc5589e557565389cf83ec7c8b", argdata, 1, 5, &func);
}

void CrewAI::CheckForProblems()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func149::func;
	return execfunc(this);
}

namespace _func150
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::CheckForHealing", typeid(void (CrewAI::*)()), "8b510c3b5110c64107000f840b020000", argdata, 1, 5, &func);
}

void CrewAI::CheckForHealing()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func150::func;
	return execfunc(this);
}

namespace _func151
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAI::DangerRating", typeid(int (CrewAI::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b47048b1f89", argdata, 3, 1, &func);
}

int CrewAI::DangerRating(int roomId, int crewId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg, int roomId_arg, int crewId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func151::func;
	return execfunc(this, roomId, crewId);
}

namespace _func152
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAI::UpdateIntruders", typeid(void (CrewAI::*)()), "8b411839411c0f8434020000578d7c24", argdata, 1, 5, &func);
}

void CrewAI::UpdateIntruders()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func152::func;
	return execfunc(this);
}

namespace _func153
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::OnRender", typeid(void (CrewAnimation::*)(float , int , bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec7c8b59", argdata, 4, 5, &func);
}

void CrewAnimation::OnRender(float scale, int selectedState, bool outlineOnly)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, float scale_arg, int selectedState_arg, bool outlineOnly_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func153::func;
	return execfunc(this, scale, selectedState, outlineOnly);
}

namespace _func154
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewAnimation::SetupStrips", typeid(void (CrewAnimation::*)()), "578d7c240883e4f0ff77fc5589e557568d8578", argdata, 1, 5, &func);
}

void CrewAnimation::SetupStrips()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func154::func;
	return execfunc(this);
}

namespace _func155
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewAnimation::RenderIcon", typeid(void (CrewAnimation::*)(bool )), "578d7c240883e4f0ff77fc5589e55756538db51c", argdata, 2, 5, &func);
}

void CrewAnimation::RenderIcon(bool border)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewAnimation *this_arg, bool border_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func155::func;
	return execfunc(this, border);
}

namespace _func156
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RandomSkills", typeid(void (CrewBlueprint::*)(int )), "578d7c240883e4f0ff77fc5589fa89e557565389cb83ec3c", argdata, 2, 5, &func);
}

void CrewBlueprint::RandomSkills(int worldLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func156::func;
	return execfunc(this, worldLevel);
}

namespace _func157
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::GetCurrentSkillColor", typeid(GL_Color (CrewBlueprint::*)(int )), "8b54240489c88b4c2408660fefc0660f", argdata, 3, 1, &func);
}

GL_Color CrewBlueprint::GetCurrentSkillColor(int skill)
{
	typedef GL_Color __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int skill_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func157::func;
	return execfunc(this, skill);
}

namespace _func158
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBlueprint::RenderSkill", typeid(void (CrewBlueprint::*)(int , int , int , int , int )), "57660fefc0660fefc98d7c240883e4f0ff77fc5589e55756", argdata, 6, 5, &func);
}

void CrewBlueprint::RenderSkill(int x, int y, int length, int height, int skill)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBlueprint *this_arg, int x_arg, int y_arg, int length_arg, int height_arg, int skill_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func158::func;
	return execfunc(this, x, y, length, height, skill);
}

namespace _func159
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewBox::constructor", typeid(void (CrewBox::*)(Point , CrewMember *, int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ec9c", argdata, 4, 5, &func);
}

void CrewBox::constructor(Point pos, CrewMember *crew, int number)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg, Point pos_arg, CrewMember *crew_arg, int number_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func159::func;
	return execfunc(this, pos, crew, number);
}

namespace _func160
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::RenderLabels", typeid(void (CrewBox::*)()), "578d7c240883e4f0ff77fc5589e55756538d5dd089ce83ec6c", argdata, 1, 5, &func);
}

void CrewBox::RenderLabels()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func160::func;
	return execfunc(this);
}

namespace _func161
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::RenderIcon", typeid(void (CrewBox::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b09", argdata, 1, 5, &func);
}

void CrewBox::RenderIcon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func161::func;
	return execfunc(this);
}

namespace _func162
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewBox::RenderCloneDying", typeid(void (CrewBox::*)()), "80b91c010000000f85a30000008b4120", argdata, 1, 5, &func);
}

void CrewBox::RenderCloneDying()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func162::func;
	return execfunc(this);
}

namespace _func163
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewControl::OnLoop", typeid(void (CrewControl::*)()), "578d7c240883e4f0ff77fc5589e557568db18c", argdata, 1, 5, &func);
}

void CrewControl::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func163::func;
	return execfunc(this);
}

namespace _func164
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewControl::LinkShip", typeid(void (CrewControl::*)(ShipManager *)), "5589e55389cb8b450883e4f08901e8dd", argdata, 2, 5, &func);
}

void CrewControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func164::func;
	return execfunc(this, ship);
}

namespace _func165
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewCustomizeBox::constructor", typeid(void (CrewCustomizeBox::*)(Point , ShipManager *, int )), "578d7c240883e4f0ff77fc5589f889e557565389cb81ecbc", argdata, 4, 5, &func);
}

void CrewCustomizeBox::constructor(Point location, ShipManager *shipManager, int slot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewCustomizeBox *this_arg, Point location_arg, ShipManager *shipManager_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func165::func;
	return execfunc(this, location, shipManager, slot);
}

namespace _func166
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewEquipBox::constructor", typeid(void (CrewEquipBox::*)(Point , ShipManager *, int )), "578d7c240883e4f0ff77fc5589e557565389cb8d4d98", argdata, 4, 5, &func);
}

void CrewEquipBox::constructor(Point pos, ShipManager *ship, int slot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg, Point pos_arg, ShipManager *ship_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func166::func;
	return execfunc(this, pos, ship, slot);
}

namespace _func167
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewEquipBox::GetConfirmDelete", typeid(bool (CrewEquipBox::*)()), "0fb681d0020000c681d002000000c390", argdata, 1, 1, &func);
}

bool CrewEquipBox::GetConfirmDelete()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewEquipBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func167::func;
	return execfunc(this);
}

namespace _func168
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::Open", typeid(void (CrewManifest::*)()), "5589e55389cb83e4f0e8d23d08008d8b", argdata, 1, 5, &func);
}

void CrewManifest::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func168::func;
	return execfunc(this);
}

namespace _func169
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewManifest::Update", typeid(void (CrewManifest::*)()), "578d7c240883e4f0ff77fc5589e55756538d45dc", argdata, 1, 5, &func);
}

void CrewManifest::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewManifest *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func169::func;
	return execfunc(this);
}

namespace _func170
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Jump", typeid(void (CrewMember::*)()), "8b81f00400005589e583e4f083400c01", argdata, 1, 5, &func);
}

void CrewMember::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func170::func;
	return execfunc(this);
}

namespace _func171
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::PositionShift", typeid(float (CrewMember::*)()), "55660fefc989e583ec04f30f2a899000", argdata, 1, 1, &func);
}

float CrewMember::PositionShift()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func171::func;
	return execfunc(this);
}

namespace _func172
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SaveState", typeid(void (CrewMember::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565389cf31f6", argdata, 2, 5, &func);
}

void CrewMember::SaveState(int fileHelper)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func172::func;
	return execfunc(this, fileHelper);
}

namespace _func173
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::LoadState", typeid(void (CrewMember::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec2c8b3089", argdata, 2, 5, &func);
}

void CrewMember::LoadState(int fileHelper)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func173::func;
	return execfunc(this, fileHelper);
}

namespace _func174
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetResisted", typeid(void (CrewMember::*)(bool )), "8b4424048881f4060000c20400906690", argdata, 2, 5, &func);
}

void CrewMember::SetResisted(bool resisted)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool resisted_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func174::func;
	return execfunc(this, resisted);
}

namespace _func175
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetResisted", typeid(bool (CrewMember::*)()), "0fb681f4060000c681f406000000c390", argdata, 1, 1, &func);
}

bool CrewMember::GetResisted()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func175::func;
	return execfunc(this);
}

namespace _func176
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSkillProgress", typeid(void (CrewMember::*)(int , int )), "8b81140300008b5424048b4c2408890c", argdata, 3, 5, &func);
}

void CrewMember::SetSkillProgress(int skillId, int skillLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg, int skillLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func176::func;
	return execfunc(this, skillId, skillLevel);
}

namespace _func177
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillLevel", typeid(int (CrewMember::*)(int )), "8b542404b80100000083fa0577268b81", argdata, 2, 1, &func);
}

int CrewMember::GetSkillLevel(int skillId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func177::func;
	return execfunc(this, skillId);
}

namespace _func178
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::EmptySlot", typeid(void (CrewMember::*)()), "8b818800000085c00f88b2000000578d", argdata, 1, 5, &func);
}

void CrewMember::EmptySlot()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func178::func;
	return execfunc(this);
}

namespace _func179
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RepairingSystem", typeid(bool (CrewMember::*)()), "8b516885d274????????02000085c07e", argdata, 1, 1, &func);
}

bool CrewMember::RepairingSystem()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func179::func;
	return execfunc(this);
}

namespace _func180
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Sabotaging", typeid(bool (CrewMember::*)()), "8b416885c074395589e5538b1089cb89", argdata, 1, 1, &func);
}

bool CrewMember::Sabotaging()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func180::func;
	return execfunc(this);
}

namespace _func181
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::RepairingFire", typeid(bool (CrewMember::*)()), "8b516831c085d2741d8b910002000085", argdata, 1, 1, &func);
}

bool CrewMember::RepairingFire()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func181::func;
	return execfunc(this);
}

namespace _func182
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SavePosition", typeid(void (CrewMember::*)()), "8b81880000008981f80600008b818c00", argdata, 1, 5, &func);
}

void CrewMember::SavePosition()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func182::func;
	return execfunc(this);
}

namespace _func183
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearPosition", typeid(void (CrewMember::*)()), "c781fc060000ffffffffc781f8060000", argdata, 1, 5, &func);
}

void CrewMember::ClearPosition()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func183::func;
	return execfunc(this);
}

namespace _func184
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSavedPosition", typeid(Slot (CrewMember::*)()), "8b54240489c88b8af806000089088b8a", argdata, 2, 1, &func);
}

Slot CrewMember::GetSavedPosition()
{
	typedef Slot __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func184::func;
	return execfunc(this);
}

namespace _func185
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("CrewMember::SetSavePosition", typeid(void (CrewMember::*)(Slot )), "8b4424048981f80600008b4424088981", argdata, 2, 5, &func);
}

void CrewMember::SetSavePosition(Slot position)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Slot position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func185::func;
	return execfunc(this, position);
}

namespace _func186
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::Repairing", typeid(bool (CrewMember::*)()), "8b416885c00f95c0c3908db600000000", argdata, 1, 1, &func);
}

bool CrewMember::Repairing()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func186::func;
	return execfunc(this);
}

namespace _func187
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetFrozenLocation", typeid(void (CrewMember::*)(bool )), "8b4424048881a1010000c20400906690", argdata, 2, 5, &func);
}

void CrewMember::SetFrozenLocation(bool frozenLocation)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool frozenLocation_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func187::func;
	return execfunc(this, frozenLocation);
}

namespace _func188
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x3ff};
	static FunctionDefinition funcObj("CrewMember::SetTask", typeid(void (CrewMember::*)(CrewTask )), "8b4424048981a40100008b4424088981", argdata, 2, 5, &func);
}

void CrewMember::SetTask(CrewTask task)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewTask task_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func188::func;
	return execfunc(this, task);
}

namespace _func189
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::ClearTask", typeid(void (CrewMember::*)()), "8b4178c781ac010000ffffffffc781a4", argdata, 1, 5, &func);
}

void CrewMember::ClearTask()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func189::func;
	return execfunc(this);
}

namespace _func190
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetDamageBoost", typeid(void (CrewMember::*)(float )), "f30f10442404f30f1181ec060000c204", argdata, 2, 5, &func);
}

void CrewMember::SetDamageBoost(float damageBoost)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float damageBoost_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func190::func;
	return execfunc(this, damageBoost);
}

namespace _func191
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::NeedFrozenLocation", typeid(bool (CrewMember::*)()), "0fb681a00100005589e584c0744c660f", argdata, 1, 1, &func);
}

bool CrewMember::NeedFrozenLocation()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func191::func;
	return execfunc(this);
}

namespace _func192
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentShip", typeid(void (CrewMember::*)(int )), "8b4424048b919c000000898160010000", argdata, 2, 5, &func);
}

void CrewMember::SetCurrentShip(int shipId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func192::func;
	return execfunc(this, shipId);
}

namespace _func193
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckFighting", typeid(void (CrewMember::*)()), "8b818801000085c00f958199000000c3", argdata, 1, 5, &func);
}

void CrewMember::CheckFighting()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func193::func;
	return execfunc(this);
}

namespace _func194
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ForceMindControl", typeid(void (CrewMember::*)(bool )), "8b44240488813d050000c20400906690", argdata, 2, 5, &func);
}

void CrewMember::ForceMindControl(bool force)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func194::func;
	return execfunc(this, force);
}

namespace _func195
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnRenderPath", typeid(void (CrewMember::*)()), "8b410485c00f85f6000000660fefc9f3", argdata, 1, 5, &func);
}

void CrewMember::OnRenderPath()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func195::func;
	return execfunc(this);
}

namespace _func196
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::AtFinalGoal", typeid(bool (CrewMember::*)()), "660fefc9f30f1015????????f30f1041", argdata, 1, 1, &func);
}

bool CrewMember::AtFinalGoal()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func196::func;
	return execfunc(this);
}

namespace _func197
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetIntegerHealth", typeid(int (CrewMember::*)()), "31c080b9fc01000000750ff30f2c4128", argdata, 1, 1, &func);
}

int CrewMember::GetIntegerHealth()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func197::func;
	return execfunc(this);
}

namespace _func198
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentTarget", typeid(void (CrewMember::*)(CrewTarget *, bool )), "5589e55756538b0189cb8b75088b7d0c", argdata, 3, 5, &func);
}

void CrewMember::SetCurrentTarget(CrewTarget *target, bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, CrewTarget *target_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func198::func;
	return execfunc(this, target, unk);
}

namespace _func199
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ContainsPoint", typeid(bool (CrewMember::*)(int , int )), "f30f1005????????f30f594114f30f10", argdata, 3, 1, &func);
}

bool CrewMember::ContainsPoint(int x, int y)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func199::func;
	return execfunc(this, x, y);
}

namespace _func200
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetMedbay", typeid(void (CrewMember::*)(float )), "5589e55389cb83e4f083ec108b11f30f", argdata, 2, 5, &func);
}

void CrewMember::SetMedbay(float health)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func200::func;
	return execfunc(this, health);
}

namespace _func201
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::StartRepair", typeid(void (CrewMember::*)(Repairable *)), "57660fefc98d7c240883e4f0ff77fc5589e5575383", argdata, 2, 5, &func);
}

void CrewMember::StartRepair(Repairable *toRepair)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, Repairable *toRepair_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func201::func;
	return execfunc(this, toRepair);
}

namespace _func202
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetSex", typeid(void (CrewMember::*)(bool )), "5589e556538b750889cb8b899c000000", argdata, 2, 5, &func);
}

void CrewMember::SetSex(bool male)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool male_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func202::func;
	return execfunc(this, male);
}

namespace _func203
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillTooltip", typeid(std::string (*)(int , int , std::pair<int, int> , bool )), "8d4c240483e4f0ff71fc5589e55756535181ec280100008b79", argdata, 5, 2, &func);
}

std::string CrewMember::GetSkillTooltip(int skillId, int skillLevel, std::pair<int, int> progress, bool infoScreen)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int skillId_arg, int skillLevel_arg, std::pair<int, int> progress_arg, bool infoScreen_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func203::func;
	return execfunc(skillId, skillLevel, progress, infoScreen);
}

namespace _func204
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::SetCurrentSystem", typeid(void (CrewMember::*)(ShipSystem *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b018b37c6", argdata, 2, 5, &func);
}

void CrewMember::SetCurrentSystem(ShipSystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, ShipSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func204::func;
	return execfunc(this, sys);
}

namespace _func205
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::DirectModifyHealth", typeid(bool (CrewMember::*)(float )), "57660fefc931c08d7c240883e4f0ff77fc5589e55756", argdata, 2, 1, &func);
}

bool CrewMember::DirectModifyHealth(float health)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func205::func;
	return execfunc(this, health);
}

namespace _func206
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckSkills", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b8908", argdata, 1, 5, &func);
}

void CrewMember::CheckSkills()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func206::func;
	return execfunc(this);
}

namespace _func207
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::UpdateHealth", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b490c85", argdata, 1, 5, &func);
}

void CrewMember::UpdateHealth()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func207::func;
	return execfunc(this);
}

namespace _func208
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::ModifyHealth", typeid(void (CrewMember::*)(float )), "578d7c240883e4f0ff77fc5589e5575389cbb9????????83ec20f30f100ff30f114df4e828", argdata, 2, 5, &func);
}

void CrewMember::ModifyHealth(float health)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, float health_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func208::func;
	return execfunc(this, health);
}

namespace _func209
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::OnLoop", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec8c00000080b9", argdata, 1, 5, &func);
}

void CrewMember::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func209::func;
	return execfunc(this);
}

namespace _func210
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetNextGoal", typeid(Point (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec30f30f10410c", argdata, 1, 9, &func);
}

Point CrewMember::GetNextGoal()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func210::func;
	return execfunc(this);
}

namespace _func211
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::GetSkillProgress", typeid(std::pair<int, int> (CrewMember::*)(int )), "558b811403000089e58b55085d8d14d0", argdata, 2, 9, &func);
}

std::pair<int, int> CrewMember::GetSkillProgress(int skillId)
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int skillId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func211::func;
	return execfunc(this, skillId);
}

namespace _func212
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::InitializeSkills", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565389cf31f631", argdata, 1, 5, &func);
}

void CrewMember::InitializeSkills()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func212::func;
	return execfunc(this);
}

namespace _func213
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetMoveSpeed", typeid(float (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e55756538d75d08d7d", argdata, 1, 1, &func);
}

float CrewMember::GetMoveSpeed()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func213::func;
	return execfunc(this);
}

namespace _func214
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StartTeleport", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e5575383ec108b999c0000008b4308c7433806000000c74330000000008b08c744240400000000c704240000000081c1e8040000e80a", argdata, 1, 5, &func);
}

void CrewMember::StartTeleport()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func214::func;
	return execfunc(this);
}

namespace _func215
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::SelectSabotageTarget", typeid(Pointf (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec308b4968", argdata, 1, 9, &func);
}

Pointf CrewMember::SelectSabotageTarget()
{
	typedef Pointf __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func215::func;
	return execfunc(this);
}

namespace _func216
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::StartTeleportArrive", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e5575383ec108b999c0000008b4308c7433806000000c74330000000008b08c744240400000000c704240000000081c1e8040000e89a", argdata, 1, 5, &func);
}

void CrewMember::StartTeleportArrive()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func216::func;
	return execfunc(this);
}

namespace _func217
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::CheckForTeleport", typeid(void (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565383ec1c8bb1", argdata, 1, 5, &func);
}

void CrewMember::CheckForTeleport()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func217::func;
	return execfunc(this);
}

namespace _func218
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("CrewMember::GetNewGoal", typeid(bool (CrewMember::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b4964", argdata, 1, 1, &func);
}

bool CrewMember::GetNewGoal()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func218::func;
	return execfunc(this);
}

namespace _func219
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::OnRender", typeid(void (CrewMember::*)(bool )), "578d7c240883e4f0ff77fc5589e5575383ec3080b9fc", argdata, 2, 5, &func);
}

void CrewMember::OnRender(bool outlineOnly)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, bool outlineOnly_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func219::func;
	return execfunc(this, outlineOnly);
}

namespace _func220
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMember::MoveToRoom", typeid(bool (CrewMember::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565381ec8c0000008b378b57", argdata, 4, 1, &func);
}

bool CrewMember::MoveToRoom(int roomId, int slotId, bool forceMove)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMember *this_arg, int roomId_arg, int slotId_arg, bool forceMove_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func220::func;
	return execfunc(this, roomId, slotId, forceMove);
}

namespace _func221
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewCount", typeid(int (CrewMemberFactory::*)(bool )), "807c2404008b41040f4401c204006690", argdata, 2, 1, &func);
}

int CrewMemberFactory::GetCrewCount(bool enemy)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, bool enemy_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func221::func;
	return execfunc(this, enemy);
}

namespace _func222
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::IsRace", typeid(bool (*)(const std::string &)), "8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e89e", argdata, 1, 2, &func);
}

bool CrewMemberFactory::IsRace(const std::string &species)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &species_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func222::func;
	return execfunc(species);
}

namespace _func223
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCloneReadyList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> &, bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b078945e08b47048945e40f", argdata, 3, 5, &func);
}

void CrewMemberFactory::GetCloneReadyList(std::vector<CrewMember*> &vec, bool player)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> &vec_arg, bool player_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func223::func;
	return execfunc(this, vec, player);
}

namespace _func224
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("CrewMemberFactory::GetCrewList", typeid(void (CrewMemberFactory::*)(std::vector<CrewMember*> *, int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b078945e08b47048945e48b", argdata, 4, 5, &func);
}

void CrewMemberFactory::GetCrewList(std::vector<CrewMember*> *vec, int unk, bool unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(CrewMemberFactory *this_arg, std::vector<CrewMember*> *vec_arg, int unk_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func224::func;
	return execfunc(this, vec, unk, unk2);
}

namespace _func225
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DefenseDrone::OnLoop", typeid(void (DefenseDrone::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4ce8f5a1", argdata, 1, 5, &func);
}

void DefenseDrone::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DefenseDrone *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func225::func;
	return execfunc(this);
}

namespace _func226
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Description::constructor", typeid(void (Description::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10c70424????????e81f", argdata, 1, 5, &func);
}

void Description::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Description *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func226::func;
	return execfunc(this);
}

namespace _func227
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Description::destructor", typeid(void (Description::*)()), "558d918c00000089e55389cb83e4f083", argdata, 1, 5, &func);
}

void Description::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Description *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func227::func;
	return execfunc(this);
}

namespace _func228
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Door::SaveState", typeid(void (Door::*)(int )), "5589e5565389ce83e4f083ec108b5d088b81d0", argdata, 2, 5, &func);
}

void Door::SaveState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func228::func;
	return execfunc(this, fd);
}

namespace _func229
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Door::LoadState", typeid(void (Door::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b37893424e870", argdata, 2, 5, &func);
}

void Door::LoadState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func229::func;
	return execfunc(this, fd);
}

namespace _func230
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Door::FakeClose", typeid(void (Door::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c80791800c6", argdata, 1, 5, &func);
}

void Door::FakeClose()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func230::func;
	return execfunc(this);
}

namespace _func231
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Door::OnRender", typeid(void (Door::*)(float , bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b77", argdata, 4, 5, &func);
}

void Door::OnRender(float alpha, bool bForceView, bool useLargeSprites)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg, float alpha_arg, bool bForceView_arg, bool useLargeSprites_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func231::func;
	return execfunc(this, alpha, bForceView, useLargeSprites);
}

namespace _func232
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Door::SetBlastDoor", typeid(void (Door::*)(int )), "80b92c020000008b4424040f85a30000", argdata, 2, 5, &func);
}

void Door::SetBlastDoor(int val)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Door *this_arg, int val_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func232::func;
	return execfunc(this, val);
}

namespace _func233
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DroneControl::OnLoop", typeid(void (DroneControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b490cc7", argdata, 1, 5, &func);
}

void DroneControl::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DroneControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func233::func;
	return execfunc(this);
}

namespace _func234
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("DroneSystem::StringToDrone", typeid(int (*)(std::string &)), "8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e84e", argdata, 1, 2, &func);
}

int DroneSystem::StringToDrone(std::string &name)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func234::func;
	return execfunc(name);
}

namespace _func235
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DropBox::GetBodySpaceOffset", typeid(int (DropBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b81ac", argdata, 1, 1, &func);
}

int DropBox::GetBodySpaceOffset()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func235::func;
	return execfunc(this);
}

namespace _func236
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("DropBox::OnRender", typeid(void (DropBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec6c010000e822f7", argdata, 1, 5, &func);
}

void DropBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DropBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func236::func;
	return execfunc(this);
}

namespace _func237
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("DropBox::OnInit", typeid(void (DropBox::*)(Point , bool , TextString *, TextString *, int , TextString *)), "578d7c240883e4f0ff77fc5589e5575653be????????89", argdata, 7, 5, &func);
}

void DropBox::OnInit(Point p, bool isSellBox_, TextString *titleText_, TextString *bodyText_, int bodySpace_, TextString *lowerText_)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(DropBox *this_arg, Point p_arg, bool isSellBox__arg, TextString *titleText__arg, TextString *bodyText__arg, int bodySpace__arg, TextString *lowerText__arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func237::func;
	return execfunc(this, p, isSellBox_, titleText_, bodyText_, bodySpace_, lowerText_);
}

namespace _func238
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Equipment::Open", typeid(void (Equipment::*)()), "5589e5565389ce83e4f0e8915603008d", argdata, 1, 5, &func);
}

void Equipment::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func238::func;
	return execfunc(this);
}

namespace _func239
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Equipment::constructor", typeid(void (Equipment::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10e8761c", argdata, 1, 5, &func);
}

void Equipment::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func239::func;
	return execfunc(this);
}

namespace _func240
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Equipment::Jump", typeid(void (Equipment::*)()), "5589e55389cb8b895402000083e4f08b", argdata, 1, 5, &func);
}

void Equipment::Jump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func240::func;
	return execfunc(this);
}

namespace _func241
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Equipment::IsCompletelyFull", typeid(bool (Equipment::*)(int )), "5589e557565389cf83e4f083ec108b89", argdata, 2, 1, &func);
}

bool Equipment::IsCompletelyFull(int type)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func241::func;
	return execfunc(this, type);
}

namespace _func242
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddDrone", typeid(void (Equipment::*)(DroneBlueprint *, bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c807f08", argdata, 4, 5, &func);
}

void Equipment::AddDrone(DroneBlueprint *bp, bool free, bool forceCargo)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, DroneBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func242::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func243
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Equipment::AddWeapon", typeid(void (Equipment::*)(WeaponBlueprint *, bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b4708", argdata, 4, 5, &func);
}

void Equipment::AddWeapon(WeaponBlueprint *bp, bool free, bool forceCargo)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, WeaponBlueprint *bp_arg, bool free_arg, bool forceCargo_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func243::func;
	return execfunc(this, bp, free, forceCargo);
}

namespace _func244
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Equipment::SetPosition", typeid(void (Equipment::*)(Point )), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b078b5704", argdata, 2, 5, &func);
}

void Equipment::SetPosition(Point p)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Equipment *this_arg, Point p_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func244::func;
	return execfunc(this, p);
}

namespace _func245
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::SetBlueprint", typeid(void (EquipmentBox::*)(InfoBox *, bool )), "5731c08d7c240883e4f0ff77fc5589e557565389cb", argdata, 3, 5, &func);
}

void EquipmentBox::SetBlueprint(InfoBox *infoBox, bool detailedBox)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, InfoBox *infoBox_arg, bool detailedBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func245::func;
	return execfunc(this, infoBox, detailedBox);
}

namespace _func246
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::RenderLabels", typeid(void (EquipmentBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec8c0000008b4160", argdata, 2, 5, &func);
}

void EquipmentBox::RenderLabels(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func246::func;
	return execfunc(this, unk);
}

namespace _func247
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EquipmentBox::ForceHitBox", typeid(void (EquipmentBox::*)(Globals::Rect *)), "8b4424048b108951508b50048951548b", argdata, 2, 5, &func);
}

void EquipmentBox::ForceHitBox(Globals::Rect *newBox)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EquipmentBox *this_arg, Globals::Rect *newBox_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func247::func;
	return execfunc(this, newBox);
}

namespace _func248
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::GetImageFromList", typeid(std::string (EventGenerator::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b1f8b7f", argdata, 3, 1, &func);
}

std::string EventGenerator::GetImageFromList(const std::string &listName)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &listName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func248::func;
	return execfunc(this, listName);
}

namespace _func249
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventGenerator::CreateEvent", typeid(LocationEvent *(EventGenerator::*)(const std::string &, int , bool )), "578d7c240883e4f0ff77fc5589e557565381ec6c03", argdata, 4, 1, &func);
}

LocationEvent *EventGenerator::CreateEvent(const std::string &name, int worldLevel, bool ignoreUnique)
{
	typedef LocationEvent *__attribute__((thiscall)) (*custom_arg_funcptr_t)(EventGenerator *this_arg, const std::string &name_arg, int worldLevel_arg, bool ignoreUnique_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func249::func;
	return execfunc(this, name, worldLevel, ignoreUnique);
}

namespace _func250
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("EventSystem::AddEvent", typeid(void (EventSystem::*)(int )), "538b54240885d278138b590c8b411029", argdata, 2, 5, &func);
}

void EventSystem::AddEvent(int id)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventSystem *this_arg, int id_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func250::func;
	return execfunc(this, id);
}

namespace _func251
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::PullMinMax", typeid(RandomAmount (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb8d4da0", argdata, 4, 1, &func);
}

RandomAmount EventsParser::PullMinMax(rapidxml::xml_node<char> *node, const std::string &name)
{
	typedef RandomAmount __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func251::func;
	return execfunc(this, node, name);
}

namespace _func252
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("EventsParser::AddAllEvents", typeid(void (EventsParser::*)()), "578d7c240883e4f0ff77fc5589e55756538d5dd08d7dd883ec5c", argdata, 1, 5, &func);
}

void EventsParser::AddAllEvents()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func252::func;
	return execfunc(this);
}

namespace _func253
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessBaseNode", typeid(void (EventsParser::*)(rapidxml::xml_node<char> *, EventGenerator &)), "578d7c240883e4f0ff77fc5589e5575653be????????81ec6c", argdata, 3, 5, &func);
}

void EventsParser::ProcessBaseNode(rapidxml::xml_node<char> *node, EventGenerator &generator)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, EventGenerator &generator_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func253::func;
	return execfunc(this, node, generator);
}

namespace _func254
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessEvent", typeid(std::string (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb81ecec0100008b0789", argdata, 4, 1, &func);
}

std::string EventsParser::ProcessEvent(rapidxml::xml_node<char> *node, const std::string &eventName)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &eventName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func254::func;
	return execfunc(this, node, eventName);
}

namespace _func255
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("EventsParser::ProcessEventList", typeid(std::vector<std::string> (EventsParser::*)(rapidxml::xml_node<char> *, const std::string &)), "5789c88d7c240883e4f0ff77fc5589e557565383ec5c", argdata, 4, 1, &func);
}

std::vector<std::string> EventsParser::ProcessEventList(rapidxml::xml_node<char> *node, const std::string &listName)
{
	typedef std::vector<std::string> __attribute__((thiscall)) (*custom_arg_funcptr_t)(EventsParser *this_arg, rapidxml::xml_node<char> *node_arg, const std::string &listName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func255::func;
	return execfunc(this, node, listName);
}

namespace _func256
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("FTLButton::OnRender", typeid(void (FTLButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ecec0100008b89", argdata, 1, 5, &func);
}

void FTLButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FTLButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func256::func;
	return execfunc(this);
}

namespace _func257
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("FTLButton::GetPilotTooltip", typeid(std::string (FTLButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b378b8e", argdata, 2, 1, &func);
}

std::string FTLButton::GetPilotTooltip()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(FTLButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func257::func;
	return execfunc(this);
}

namespace _func258
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeString", typeid(bool (*)(int , const std::string &)), "8d4c240483e4f0ff71fc5589e55756535183ec488b41048b318b38", argdata, 2, 2, &func);
}

bool FileHelper::writeString(int file, const std::string &data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, const std::string &data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func258::func;
	return execfunc(file, data);
}

namespace _func259
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeInt", typeid(bool (*)(int , int )), "8d4c240483e4f0ff71fc5589e556535183ec3c803d????????008b71", argdata, 2, 2, &func);
}

bool FileHelper::writeInt(int file, int data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, int data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func259::func;
	return execfunc(file, data);
}

namespace _func260
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readString", typeid(std::string (*)(int )), "8d4c240483e4f0ff71fc5589e55756535183ec488b71048b1981", argdata, 2, 2, &func);
}

std::string FileHelper::readString(int file)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func260::func;
	return execfunc(file);
}

namespace _func261
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::fileExists", typeid(bool (*)(const std::string &)), "8d4c240483e4f031d2ff71fc5589e557", argdata, 1, 2, &func);
}

bool FileHelper::fileExists(const std::string &fileName)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func261::func;
	return execfunc(fileName);
}

namespace _func262
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readFloat", typeid(float (*)(int )), "8d4c240483e4f0ff71fc5589e55756535183ec488b013dfffeff7f7e733d00ffff7f741d3d02ffff7f0f8512", argdata, 1, 2, &func);
}

float FileHelper::readFloat(int file)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func262::func;
	return execfunc(file);
}

namespace _func263
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readBinaryFile", typeid(int (*)(const std::string &)), "8d4c240483e4f0ff71fc5589e55756535181ec380400008b", argdata, 1, 2, &func);
}

int FileHelper::readBinaryFile(const std::string &fileName)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &fileName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func263::func;
	return execfunc(fileName);
}

namespace _func264
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::readInteger", typeid(int (*)(int )), "8d4c240483e4f0ff71fc5589e55756535183ec488b013dfffeff7f7e733d00ffff7f741d3d02ffff7f0f8501", argdata, 1, 2, &func);
}

int FileHelper::readInteger(int file)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func264::func;
	return execfunc(file);
}

namespace _func265
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getSaveFile", typeid(std::string (*)()), "8d4c240483e4f0ff71fc5589e5575653518d7dd0", argdata, 1, 2, &func);
}

std::string FileHelper::getSaveFile()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func265::func;
	return execfunc();
}

namespace _func266
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::getResourceFile", typeid(std::string (*)()), "8d4c240483e4f0ff71fc5589e5575653518d75d883", argdata, 1, 2, &func);
}

std::string FileHelper::getResourceFile()
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func266::func;
	return execfunc();
}

namespace _func267
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("FileHelper::initFileHelper", typeid(void (*)()), "8d4c240483e4f0ff71fc5589e5575653518d45b8", argdata, 0, 6, &func);
}

void FileHelper::initFileHelper()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func267::func;
	return execfunc();
}

namespace _func268
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::writeFloat", typeid(bool (*)(int , float )), "8d4c240483e4f0ff71fc5589e556535183ec3c803d????????008b19", argdata, 2, 2, &func);
}

bool FileHelper::writeFloat(int file, float data)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, float data_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func268::func;
	return execfunc(file, data);
}

namespace _func269
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("FileHelper::closeBinaryFile", typeid(void (*)(int )), "8d4c240483e4f0ff71fc5589e5535183ec108b013d", argdata, 1, 6, &func);
}

void FileHelper::closeBinaryFile(int file)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func269::func;
	return execfunc(file);
}

namespace _func270
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FileHelper::readBuffer", typeid(char *(*)(int , int , bool )), "8d4c240483e4f0ff71fc5589e55756535181ec78", argdata, 3, 2, &func);
}

char *FileHelper::readBuffer(int file, int len, bool nullTerminate)
{
	typedef char *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int file_arg, int len_arg, bool nullTerminate_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func270::func;
	return execfunc(file, len, nullTerminate);
}

namespace _func271
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FocusWindow::MouseClick", typeid(void (FocusWindow::*)(int , int )), "80791000750ac208008db42600000000", argdata, 3, 5, &func);
}

void FocusWindow::MouseClick(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FocusWindow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func271::func;
	return execfunc(this, x, y);
}

namespace _func272
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("FocusWindow::constructor", typeid(void (FocusWindow::*)()), "578d7c240883e4f0ff77fc5589e5575389cb8d490883ec10c741f8????????c6", argdata, 1, 5, &func);
}

void FocusWindow::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FocusWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func272::func;
	return execfunc(this);
}

namespace _func273
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("FocusWindow::SetPosition", typeid(void (FocusWindow::*)(Point )), "5589e58b45088b550c5d894114895118", argdata, 2, 5, &func);
}

void FocusWindow::SetPosition(Point p)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FocusWindow *this_arg, Point p_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func273::func;
	return execfunc(this, p);
}

namespace _func274
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("FocusWindow::MouseMove", typeid(void (FocusWindow::*)(int , int )), "578d7c240883e4f0ff77fc5589e5575383ec108b4108", argdata, 3, 5, &func);
}

void FocusWindow::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(FocusWindow *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func274::func;
	return execfunc(this, x, y);
}

namespace _func275
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("GameOver::OnLoop", typeid(void (GameOver::*)()), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec5ce8", argdata, 1, 5, &func);
}

void GameOver::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GameOver *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func275::func;
	return execfunc(this);
}

namespace _func276
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("GenericButton::SetActive", typeid(void (GenericButton::*)(bool )), "8b44240484c08841407508????????c6", argdata, 2, 5, &func);
}

void GenericButton::SetActive(bool active)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg, bool active_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func276::func;
	return execfunc(this, active);
}

namespace _func277
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GenericButton::MouseMove", typeid(void (GenericButton::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e5575383ec108b178b41", argdata, 4, 5, &func);
}

void GenericButton::MouseMove(int x, int y, bool silent)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg, int x_arg, int y_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func277::func;
	return execfunc(this, x, y, silent);
}

namespace _func278
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("GenericButton::SetLocation", typeid(void (GenericButton::*)(Point )), "5589e557568b4508538b59048b550c83", argdata, 2, 5, &func);
}

void GenericButton::SetLocation(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(GenericButton *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func278::func;
	return execfunc(this, pos);
}

namespace _func279
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("font_text_width", typeid(float (*)(freetype::font_data &, const char *, float )), "5589e557565383e4f083ec408b4d088b750c85c9", argdata, 3, 2, &func);
}

float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(freetype::font_data &fontData_arg, const char *str_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func279::func;
	return execfunc(fontData, str, size);
}

namespace _func280
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("random32", typeid(int (*)()), "556905????????????????89e556536935????????????????83e4f801c6b8????????f725????????01f283c00183d200a3????????8915????????", argdata, 0, 0, &func);
}

int __stdcall random32()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func280::func;
	return execfunc();
}

namespace _func281
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("srandom32", typeid(void (*)(unsigned int )), "55c705????????????????89e583e4f88b4508a3????????", argdata, 1, 6, &func);
}

void __stdcall srandom32(unsigned int seed)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(unsigned int seed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func281::func;
	return execfunc(seed);
}

namespace _func282
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("getSkillBonus", typeid(float (*)(int , int )), "83ec048b4424088b54240c83f80577??ff2485????????89f68dbc270000000085d2660fefc074??83fa010f84????????", argdata, 2, 2, &func);
}

float __stdcall getSkillBonus(int skill, int level)
{
	typedef float __attribute__((cdecl)) (*custom_arg_funcptr_t)(int skill_arg, int level_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func282::func;
	return execfunc(skill, level);
}

namespace _func283
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GenerateReward", typeid(void (*)(ResourceEvent &, RewardDesc &, int )), "8d4c240483e4f0ff71fc5589e55756535181ec????????8b018b79088985d4fcffff8b410489bdd0fcffff8985ccfcffff8b4018", argdata, 3, 6, &func);
}

void __stdcall GenerateReward(ResourceEvent &ref, RewardDesc &reward, int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceEvent &ref_arg, RewardDesc &reward_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func283::func;
	return execfunc(ref, reward, worldLevel);
}

namespace _func284
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("GetValue", typeid(void (*)(ResourceEvent &, const std::string &, int , int )), "8d4c240483e4f0ff71fc5589e55756535183ec288b59048b410c8b398b7108c70424????????89d98945e4e8????????83ec0485c00f84????????", argdata, 4, 6, &func);
}

void __stdcall GetValue(ResourceEvent &ref, const std::string &type, int level, int worldLevel)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(ResourceEvent &ref_arg, const std::string &type_arg, int level_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func284::func;
	return execfunc(ref, type, level, worldLevel);
}

namespace _func285
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("sys_graphics_set_window_title", typeid(void (*)(char *)), "5589e55383e4f083ec10a1????????8b5d08890424e8????????", argdata, 1, 6, &func);
}

void __stdcall sys_graphics_set_window_title(char *title)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(char *title_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func285::func;
	return execfunc(title);
}

namespace _func286
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("graphics_clear", typeid(void (*)(float , float , float , float , float , unsigned int )), "55660fefc089e583e4f083ec30f30f106d180f2ee8f30f106508f30f105d0cf30f105510f30f104d14", argdata, 6, 6, &func);
}

void __stdcall graphics_clear(float r, float g, float b, float a, float depth, unsigned int stencil)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(float r_arg, float g_arg, float b_arg, float a_arg, float depth_arg, unsigned int stencil_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func286::func;
	return execfunc(r, g, b, a, depth, stencil);
}

namespace _func287
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Globals::GetNextSpaceId", typeid(int (*)()), "8b15????????8d420185????????0000", argdata, 0, 0, &func);
}

int Globals::GetNextSpaceId()
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func287::func;
	return execfunc();
}

namespace _func288
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("Globals::GetNextPoint", typeid(Pointf (*)(Pointf , float , Pointf )), "8d4c240483e4f0ff71fc5589e55183ec44f3", argdata, 3, 10, &func);
}

Pointf Globals::GetNextPoint(Pointf current, float mag_speed, Pointf dest)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf current_arg, float mag_speed_arg, Pointf dest_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func288::func;
	return execfunc(current, mag_speed, dest);
}

namespace _func289
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("HackBox::constructor", typeid(void (HackBox::*)(Point , HackingSystem *, ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389fe89cb81", argdata, 4, 5, &func);
}

void HackBox::constructor(Point pos, HackingSystem *sys, ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackBox *this_arg, Point pos_arg, HackingSystem *sys_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func289::func;
	return execfunc(this, pos, sys, ship);
}

namespace _func290
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("HackingSystem::SoundLoop", typeid(bool (HackingSystem::*)()), "80b9c001000000750731c0c38d7426005589e55389cb83e4f0e8c2", argdata, 1, 1, &func);
}

bool HackingSystem::SoundLoop()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(HackingSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func290::func;
	return execfunc(this);
}

namespace _func291
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::OnRender", typeid(void (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec5c", argdata, 1, 5, &func);
}

void InfoBox::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func291::func;
	return execfunc(this);
}

namespace _func292
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::Clear", typeid(void (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e55756538d45cc8d", argdata, 1, 5, &func);
}

void InfoBox::Clear()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func292::func;
	return execfunc(this);
}

namespace _func293
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetDescription", typeid(void (InfoBox::*)(Description *, int , int , InfoBox::ExpandDir )), "578d7c240883e4f0ff77fc5589e557565389cb83c10c83ec2c", argdata, 5, 5, &func);
}

void InfoBox::SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, Description *desc_arg, int width_arg, int height_arg, InfoBox::ExpandDir dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func293::func;
	return execfunc(this, desc, width, height, dir);
}

namespace _func294
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::IsEmpty", typeid(bool (InfoBox::*)()), "83b9b4000000ff740731c0c38d742600", argdata, 1, 1, &func);
}

bool InfoBox::IsEmpty()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func294::func;
	return execfunc(this);
}

namespace _func295
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("InfoBox::constructor", typeid(void (InfoBox::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10c744240400", argdata, 1, 5, &func);
}

void InfoBox::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func295::func;
	return execfunc(this);
}

namespace _func296
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetSystem", typeid(void (InfoBox::*)(ShipSystem *, int , int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b378b47", argdata, 5, 5, &func);
}

void InfoBox::SetSystem(ShipSystem *system, int upgrade, int yShift, int forceSystemWidth)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, ShipSystem *system_arg, int upgrade_arg, int yShift_arg, int forceSystemWidth_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func296::func;
	return execfunc(this, system, upgrade, yShift, forceSystemWidth);
}

namespace _func297
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("InfoBox::SetBlueprint", typeid(void (InfoBox::*)(const ItemBlueprint *)), "8b442404398140010000742485c07420", argdata, 2, 5, &func);
}

void InfoBox::SetBlueprint(const ItemBlueprint *bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InfoBox *this_arg, const ItemBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func297::func;
	return execfunc(this, bp);
}

namespace _func298
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("InputBox::TextEvent", typeid(void (InputBox::*)(CEvent::TextEvent )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b0783", argdata, 2, 5, &func);
}

void InputBox::TextEvent(CEvent::TextEvent event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(InputBox *this_arg, CEvent::TextEvent event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func298::func;
	return execfunc(this, event);
}

namespace _func299
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ItemStoreBox::constructor", typeid(void (ItemStoreBox::*)(ShipManager *, const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d45d889", argdata, 3, 5, &func);
}

void ItemStoreBox::constructor(ShipManager *ship, const std::string &resourceName)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ItemStoreBox *this_arg, ShipManager *ship_arg, const std::string &resourceName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func299::func;
	return execfunc(this, ship, resourceName);
}

namespace _func300
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LanguageChooser::OnRender", typeid(void (LanguageChooser::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d4da0", argdata, 1, 5, &func);
}

void LanguageChooser::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LanguageChooser *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func300::func;
	return execfunc(this);
}

namespace _func301
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LaserBlast::OnInit", typeid(void (LaserBlast::*)()), "5589e5538b417489cbc7413801000000", argdata, 1, 5, &func);
}

void LaserBlast::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LaserBlast *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func301::func;
	return execfunc(this);
}

namespace _func302
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("LocationEvent::ClearEvent", typeid(void (LocationEvent::*)(bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c83b9", argdata, 2, 5, &func);
}

void LocationEvent::ClearEvent(bool force)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LocationEvent *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func302::func;
	return execfunc(this, force);
}

namespace _func303
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("LockdownShard::SaveState", typeid(void (LockdownShard::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b37f30f1081", argdata, 2, 5, &func);
}

void LockdownShard::SaveState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LockdownShard *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func303::func;
	return execfunc(this, fd);
}

namespace _func304
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("LockdownShard::Update", typeid(void (LockdownShard::*)()), "578d7c240883e4f0ff77fc5589e5575389cbb9????????83ec30e821", argdata, 1, 5, &func);
}

void LockdownShard::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(LockdownShard *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func304::func;
	return execfunc(this);
}

namespace _func305
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MainMenu::Open", typeid(bool (MainMenu::*)()), "578d7c240883e4f0ff77fc5589e557565381ecfc02", argdata, 1, 1, &func);
}

bool MainMenu::Open()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(MainMenu *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func305::func;
	return execfunc(this);
}

namespace _func306
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MenuScreen::Open", typeid(void (MenuScreen::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83c14c", argdata, 1, 5, &func);
}

void MenuScreen::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MenuScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func306::func;
	return execfunc(this);
}

namespace _func307
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("MindBox::constructor", typeid(void (MindBox::*)(Point , MindSystem *)), "578d7c240883e4f0ff77fc5589e557565389cb81ecbc0000008b07", argdata, 3, 5, &func);
}

void MindBox::constructor(Point pos, MindSystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MindBox *this_arg, Point pos_arg, MindSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func307::func;
	return execfunc(this, pos, sys);
}

namespace _func308
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MindSystem::InitiateMindControl", typeid(void (MindSystem::*)()), "578d7c240883e4f0ff77fc5589e557565383ec5c8b81ec", argdata, 1, 5, &func);
}

void MindSystem::InitiateMindControl()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MindSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func308::func;
	return execfunc(this);
}

namespace _func309
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetTooltip", typeid(void (MouseControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b3f8b", argdata, 2, 5, &func);
}

void MouseControl::SetTooltip(const std::string &tooltip)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func309::func;
	return execfunc(this, tooltip);
}

namespace _func310
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetDoor", typeid(void (MouseControl::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b1f83", argdata, 2, 5, &func);
}

void MouseControl::SetDoor(int state)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, int state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func310::func;
	return execfunc(this, state);
}

namespace _func311
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetValid", typeid(void (MouseControl::*)(bool , bool )), "807c2408008b44240488411d7404c641", argdata, 3, 5, &func);
}

void MouseControl::SetValid(bool valid, bool newValid)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, bool valid_arg, bool newValid_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func311::func;
	return execfunc(this, valid, newValid);
}

namespace _func312
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::OnLoop", typeid(void (MouseControl::*)()), "5589e55389cb83e4f083ec1080b91801", argdata, 1, 5, &func);
}

void MouseControl::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func312::func;
	return execfunc(this);
}

namespace _func313
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::OnRender", typeid(void (MouseControl::*)()), "80b919010000000f8563030000578d7c", argdata, 1, 5, &func);
}

void MouseControl::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func313::func;
	return execfunc(this);
}

namespace _func314
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("MouseControl::Reset", typeid(void (MouseControl::*)()), "578d7c240883e4f0ff77fc5589e5575389cb8d89fc", argdata, 1, 5, &func);
}

void MouseControl::Reset()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func314::func;
	return execfunc(this);
}

namespace _func315
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("MouseControl::SetTooltipTitle", typeid(void (MouseControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55783ec148b912c", argdata, 2, 5, &func);
}

void MouseControl::SetTooltipTitle(const std::string &tooltip)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(MouseControl *this_arg, const std::string &tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func315::func;
	return execfunc(this, tooltip);
}

namespace _func316
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OptionsScreen::OnLoop", typeid(void (OptionsScreen::*)()), "57660fefc9660fefc08d7c240883e4f0", argdata, 1, 5, &func);
}

void OptionsScreen::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OptionsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func316::func;
	return execfunc(this);
}

namespace _func317
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OptionsScreen::OnInit", typeid(void (OptionsScreen::*)()), "578d7c240883e4f0ff77fc5589e557565389cbb9????????8d", argdata, 1, 5, &func);
}

void OptionsScreen::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OptionsScreen *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func317::func;
	return execfunc(this);
}

namespace _func318
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("OuterHull::OnLoop", typeid(void (OuterHull::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b018b4028", argdata, 1, 5, &func);
}

void OuterHull::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OuterHull *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func318::func;
	return execfunc(this);
}

namespace _func319
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateBreach", typeid(void (OxygenSystem::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e5575383ec108b47", argdata, 4, 5, &func);
}

void OxygenSystem::UpdateBreach(int roomId, int count, bool silent)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, int count_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func319::func;
	return execfunc(this, roomId, count, silent);
}

namespace _func320
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::UpdateAirlock", typeid(void (OxygenSystem::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b5f048b17", argdata, 3, 5, &func);
}

void OxygenSystem::UpdateAirlock(int roomId, int count)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, int count_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func320::func;
	return execfunc(this, roomId, count);
}

namespace _func321
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::EmptyOxygen", typeid(void (OxygenSystem::*)(int )), "8b81c40100008b542404c70490000000", argdata, 2, 5, &func);
}

void OxygenSystem::EmptyOxygen(int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func321::func;
	return execfunc(this, roomId);
}

namespace _func322
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ModifyRoomOxygen", typeid(void (OxygenSystem::*)(int , float )), "8b81c40100008b5424048d0490f30f10", argdata, 3, 5, &func);
}

void OxygenSystem::ModifyRoomOxygen(int roomId, float value)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, float value_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func322::func;
	return execfunc(this, roomId, value);
}

namespace _func323
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("OxygenSystem::ComputeAirLoss", typeid(void (OxygenSystem::*)(int , float , bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec3c0f", argdata, 4, 5, &func);
}

void OxygenSystem::ComputeAirLoss(int roomId, float base_loss, bool silent)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(OxygenSystem *this_arg, int roomId_arg, float base_loss_arg, bool silent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func323::func;
	return execfunc(this, roomId, base_loss, silent);
}

namespace _func324
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("Point::RelativeDistance", typeid(int (Point::*)(Point )), "558b018b510489e52b45082b550c5d0f", argdata, 2, 1, &func);
}

int Point::RelativeDistance(Point other)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Point *this_arg, Point other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func324::func;
	return execfunc(this, other);
}

namespace _func325
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Projectile::RandomSidePoint", typeid(Pointf (*)(int )), "8d4c240483e4f0ff71fc5589e5535183ec208b198d", argdata, 1, 10, &func);
}

Pointf Projectile::RandomSidePoint(int side)
{
	typedef Pointf __attribute__((cdecl)) (*custom_arg_funcptr_t)(int side_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func325::func;
	return execfunc(side);
}

namespace _func326
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetCooldownModifier", typeid(void (ProjectileFactory::*)(float )), "f30f1041080f28c8f30f10542404f30f", argdata, 2, 5, &func);
}

void ProjectileFactory::SetCooldownModifier(float mod)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float mod_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func326::func;
	return execfunc(this, mod);
}

namespace _func327
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ForceCoolup", typeid(void (ProjectileFactory::*)()), "80b9f600000000745c8b411cf30f1041", argdata, 1, 5, &func);
}

void ProjectileFactory::ForceCoolup()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func327::func;
	return execfunc(this);
}

namespace _func328
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::QueuedShots", typeid(bool (ProjectileFactory::*)()), "8b81000600003981040600000f95c0c3", argdata, 1, 1, &func);
}

bool ProjectileFactory::QueuedShots()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func328::func;
	return execfunc(this);
}

namespace _func329
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::NumTargetsRequired", typeid(int (ProjectileFactory::*)()), "8b411c83b8d8010000017e158b812c06", argdata, 1, 1, &func);
}

int ProjectileFactory::NumTargetsRequired()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func329::func;
	return execfunc(this);
}

namespace _func330
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::GetProjectile", typeid(Projectile *(ProjectileFactory::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81c148", argdata, 1, 1, &func);
}

Projectile *ProjectileFactory::GetProjectile()
{
	typedef Projectile *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func330::func;
	return execfunc(this);
}

namespace _func331
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::ClearProjectiles", typeid(void (ProjectileFactory::*)()), "8b8100060000898104060000c3906690", argdata, 1, 5, &func);
}

void ProjectileFactory::ClearProjectiles()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func331::func;
	return execfunc(this);
}

namespace _func332
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::LoadProjectile", typeid(Projectile *(*)(int )), "8d4c240483e4f0ff71fc5589e556535183ec6c8b", argdata, 1, 2, &func);
}

Projectile *ProjectileFactory::LoadProjectile(int fd)
{
	typedef Projectile *__attribute__((cdecl)) (*custom_arg_funcptr_t)(int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func332::func;
	return execfunc(fd);
}

namespace _func333
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SaveProjectile", typeid(void (*)(Projectile *, int )), "8d4c240483e4f0ff71fc5589e556535183ec1c8b198b71048b", argdata, 2, 6, &func);
}

void ProjectileFactory::SaveProjectile(Projectile *p, int fd)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Projectile *p_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func333::func;
	return execfunc(p, fd);
}

namespace _func334
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::SetAutoFire", typeid(void (ProjectileFactory::*)(bool )), "8b44240484c0751e80b9f40000000074", argdata, 2, 5, &func);
}

void ProjectileFactory::SetAutoFire(bool autoFire)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, bool autoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func334::func;
	return execfunc(this, autoFire);
}

namespace _func335
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::RenderChargeBar", typeid(void (ProjectileFactory::*)(float )), "5781c1480100008d7c240883e4f0ff77fc5589e55783ec14f3", argdata, 2, 5, &func);
}

void ProjectileFactory::RenderChargeBar(float unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg, float unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func335::func;
	return execfunc(this, unk);
}

namespace _func336
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("ProjectileFactory::StringToWeapon", typeid(int (*)(const std::string &)), "8d4c240483e4f0ff71fc5589e5535183ec108b19c70424????????89d9e80e", argdata, 1, 2, &func);
}

int ProjectileFactory::StringToWeapon(const std::string &str)
{
	typedef int __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &str_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func336::func;
	return execfunc(str);
}

namespace _func337
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ProjectileFactory::SelectChargeGoal", typeid(void (ProjectileFactory::*)()), "5589e55389cb83e4f0803d????????00751e", argdata, 1, 5, &func);
}

void ProjectileFactory::SelectChargeGoal()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ProjectileFactory *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func337::func;
	return execfunc(this);
}

namespace _func338
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ReactorButton::OnClick", typeid(void (ReactorButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c8b4970", argdata, 1, 5, &func);
}

void ReactorButton::OnClick()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func338::func;
	return execfunc(this);
}

namespace _func339
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ReactorButton::OnRender", typeid(void (ReactorButton::*)()), "578d7c240883e4f0ff77fc5589e557565389ce81ec6c", argdata, 1, 5, &func);
}

void ReactorButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ReactorButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func339::func;
	return execfunc(this);
}

namespace _func340
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ResourceControl::constructor", typeid(void (ResourceControl::*)()), "8d4118f30f1005????????c741040100", argdata, 1, 5, &func);
}

void ResourceControl::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func340::func;
	return execfunc(this);
}

namespace _func341
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetImageId", typeid(GL_Texture *(ResourceControl::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d459081ecac", argdata, 2, 1, &func);
}

GL_Texture *ResourceControl::GetImageId(const std::string &dir)
{
	typedef GL_Texture *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, const std::string &dir_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func341::func;
	return execfunc(this, dir);
}

namespace _func342
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::GetFontData", typeid(freetype::font_data &(ResourceControl::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565389fe83", argdata, 3, 1, &func);
}

freetype::font_data &ResourceControl::GetFontData(int size, bool ignoreLanguage)
{
	typedef freetype::font_data &__attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, int size_arg, bool ignoreLanguage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func342::func;
	return execfunc(this, size, ignoreLanguage);
}

namespace _func343
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::OnInit", typeid(void (ResourceControl::*)(int )), "5589e55389cb83e4f083ec108b4508c781", argdata, 2, 5, &func);
}

void ResourceControl::OnInit(int imageSwappingMode)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, int imageSwappingMode_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func343::func;
	return execfunc(this, imageSwappingMode);
}

namespace _func344
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::RenderImage", typeid(int (ResourceControl::*)(GL_Texture *, int , int , int , GL_Color , float , bool )), "578d7c240883e4f0ff77fc5589e557565383ec5c8b570c", argdata, 8, 1, &func);
}

int ResourceControl::RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, GL_Texture *tex_arg, int x_arg, int y_arg, int rotation_arg, GL_Color color_arg, float opacity_arg, bool mirror_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func344::func;
	return execfunc(this, tex, x, y, rotation, color, opacity, mirror);
}

namespace _func345
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ResourceControl::PreloadResources", typeid(bool (ResourceControl::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec1c02", argdata, 2, 1, &func);
}

bool ResourceControl::PreloadResources(bool unk)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ResourceControl *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func345::func;
	return execfunc(this, unk);
}

namespace _func346
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::OnRenderFloor", typeid(void (Room::*)(float , bool )), "5589e55383e4f083ec308b517cf30f10", argdata, 3, 5, &func);
}

void Room::OnRenderFloor(float alpha, bool experimental)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, float alpha_arg, bool experimental_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func346::func;
	return execfunc(this, alpha, experimental);
}

namespace _func347
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Room::FillSlot", typeid(void (Room::*)(int , bool )), "565389cb0fb64424108b73348b4c240c????????00000001d08d048689cec1ee058b008d34b0b801000000d3e08b0e85c175", argdata, 3, 5, &func);
}

void Room::FillSlot(int slot, bool intruder)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, int slot_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func347::func;
	return execfunc(this, slot, intruder);
}

namespace _func348
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Room::OnLoop", typeid(void (Room::*)()), "578d7c240883e4f0ff77fc5589e55756538d9960", argdata, 1, 5, &func);
}

void Room::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func348::func;
	return execfunc(this);
}

namespace _func349
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Room::OnRenderWalls", typeid(void (Room::*)(float )), "????????7406807924007404c2040090", argdata, 2, 5, &func);
}

void Room::OnRenderWalls(float alpha)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Room *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func349::func;
	return execfunc(this, alpha);
}

namespace _func350
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetVictory", typeid(void (ScoreKeeper::*)(bool )), "8b44240484c088818802000074078381", argdata, 2, 5, &func);
}

void ScoreKeeper::SetVictory(bool victory)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool victory_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func350::func;
	return execfunc(this, victory);
}

namespace _func351
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::MouseClick", typeid(void (ScoreKeeper::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c80b9c4", argdata, 3, 5, &func);
}

void ScoreKeeper::MouseClick(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func351::func;
	return execfunc(this, x, y);
}

namespace _func352
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ScoreKeeper::CheckTypes", typeid(void (ScoreKeeper::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db3cc", argdata, 1, 5, &func);
}

void ScoreKeeper::CheckTypes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func352::func;
	return execfunc(this);
}

namespace _func353
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::AddScrapCollected", typeid(void (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cbb9????????83ec3c", argdata, 2, 5, &func);
}

void ScoreKeeper::AddScrapCollected(int scrap)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int scrap_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func353::func;
	return execfunc(this, scrap);
}

namespace _func354
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SaveGame", typeid(void (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b1fa1", argdata, 2, 5, &func);
}

void ScoreKeeper::SaveGame(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func354::func;
	return execfunc(this, fd);
}

namespace _func355
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::SetSector", typeid(void (ScoreKeeper::*)(int )), "8b442404c7412400000000????????00", argdata, 2, 5, &func);
}

void ScoreKeeper::SetSector(int sector)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int sector_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func355::func;
	return execfunc(this, sector);
}

namespace _func356
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipId", typeid(std::pair<int, int> (ScoreKeeper::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec5c8b37c7", argdata, 2, 9, &func);
}

std::pair<int, int> ScoreKeeper::GetShipId(const std::string &blueprintName)
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, const std::string &blueprintName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func356::func;
	return execfunc(this, blueprintName);
}

namespace _func357
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::Open", typeid(void (ScoreKeeper::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3c80b9c4", argdata, 2, 5, &func);
}

void ScoreKeeper::Open(bool fromGameOver)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, bool fromGameOver_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func357::func;
	return execfunc(this, fromGameOver);
}

namespace _func358
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::GetShipBlueprint", typeid(std::string (ScoreKeeper::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b47048d", argdata, 3, 1, &func);
}

std::string ScoreKeeper::GetShipBlueprint(int index)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int index_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func358::func;
	return execfunc(this, index);
}

namespace _func359
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ScoreKeeper::UnlockShip", typeid(void (ScoreKeeper::*)(int , int , bool , bool )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b17", argdata, 5, 5, &func);
}

void ScoreKeeper::UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ScoreKeeper *this_arg, int shipType_arg, int shipVariant_arg, bool save_arg, bool hidePopup_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func359::func;
	return execfunc(this, shipType, shipVariant, save, hidePopup);
}

namespace _func360
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::GetCommandConsole", typeid(char (*)()), "0fb605????????c3908db426000000005589e583e4f083ec100f", argdata, 0, 0, &func);
}

char Settings::GetCommandConsole()
{
	typedef char __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func360::func;
	return execfunc();
}

namespace _func361
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::ResetHotkeys", typeid(void (*)()), "8d4c240483e4f0ff71fc5589e557565351be", argdata, 0, 6, &func);
}

void Settings::ResetHotkeys()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func361::func;
	return execfunc();
}

namespace _func362
{
    static void *func = 0;
	static short argdata[] = {0x1ff};
	static FunctionDefinition funcObj("Settings::GetHotkey", typeid(SDLKey (*)(const std::string &)), "5589e557565331f689cb83e4f083ec108b9148", argdata, 1, 2, &func);
}

SDLKey Settings::GetHotkey(const std::string &hotkeyName)
{
	typedef SDLKey __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &hotkeyName_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func362::func;
	return execfunc(hotkeyName);
}

namespace _func363
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Settings::GetHotkeyName", typeid(std::string (*)(const std::string &)), "8d4c240483e4f0ff71fc5589e5575653518db5e0", argdata, 2, 2, &func);
}

std::string Settings::GetHotkeyName(const std::string &name)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &name_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func363::func;
	return execfunc(name);
}

namespace _func364
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Settings::LoadSettings", typeid(void (*)()), "8d4c240483e4f0ff71fc5589e5575653518d9d", argdata, 0, 6, &func);
}

void Settings::LoadSettings()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func364::func;
	return execfunc();
}

namespace _func365
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff};
	static FunctionDefinition funcObj("Shields::SetBaseEllipse", typeid(void (Shields::*)(Globals::Ellipse )), "5589e5f30f104d108b4508f30f104514", argdata, 2, 5, &func);
}

void Shields::SetBaseEllipse(Globals::Ellipse ellipse)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, Globals::Ellipse ellipse_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func365::func;
	return execfunc(this, ellipse);
}

namespace _func366
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Shields::SetHackingLevel", typeid(void (Shields::*)(int )), "538b44240883f8017e0983b9a8010000", argdata, 2, 5, &func);
}

void Shields::SetHackingLevel(int hackingLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg, int hackingLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func366::func;
	return execfunc(this, hackingLevel);
}

namespace _func367
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Shields::OnLoop", typeid(void (Shields::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db564", argdata, 1, 5, &func);
}

void Shields::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Shields *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func367::func;
	return execfunc(this);
}

namespace _func368
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::ContainsHullBreach", typeid(std::pair<int, int> (Ship::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565331db89cf83ec2c", argdata, 2, 9, &func);
}

std::pair<int, int> Ship::ContainsHullBreach(int roomId)
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func368::func;
	return execfunc(this, roomId);
}

namespace _func369
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::RoomLocked", typeid(bool (Ship::*)(int )), "538b81bc0300008b89c00300008b5c24", argdata, 2, 1, &func);
}

bool Ship::RoomLocked(int roomId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func369::func;
	return execfunc(this, roomId);
}

namespace _func370
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Ship::DestroyedDone", typeid(bool (Ship::*)()), "0fb681f001000084c074070fb6815201", argdata, 1, 1, &func);
}

bool Ship::DestroyedDone()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func370::func;
	return execfunc(this);
}

namespace _func371
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::FullRoom", typeid(bool (Ship::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b5908", argdata, 3, 1, &func);
}

bool Ship::FullRoom(int roomId, bool intruder)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int roomId_arg, bool intruder_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func371::func;
	return execfunc(this, roomId, intruder);
}

namespace _func372
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Ship::GetShipCorner", typeid(Point (Ship::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec208b410489", argdata, 1, 9, &func);
}

Point Ship::GetShipCorner()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func372::func;
	return execfunc(this);
}

namespace _func373
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetBaseEllipse", typeid(Globals::Ellipse (Ship::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b1f8b83", argdata, 2, 1, &func);
}

Globals::Ellipse Ship::GetBaseEllipse()
{
	typedef Globals::Ellipse __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func373::func;
	return execfunc(this);
}

namespace _func374
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetCloakAlpha", typeid(float (Ship::*)(bool )), "578d7c240883e4f0ff77fc5589e5575383ec2080b9", argdata, 2, 1, &func);
}

float Ship::GetCloakAlpha(bool complete)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, bool complete_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func374::func;
	return execfunc(this, complete);
}

namespace _func375
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderJump", typeid(void (Ship::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b41", argdata, 2, 5, &func);
}

void Ship::OnRenderJump(float progress)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, float progress_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func375::func;
	return execfunc(this, progress);
}

namespace _func376
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnInit", typeid(void (Ship::*)(ShipBlueprint &)), "57b81c0201008d7c240883e4f0ff77fc", argdata, 2, 5, &func);
}

void Ship::OnInit(ShipBlueprint &bp)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, ShipBlueprint &bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func376::func;
	return execfunc(this, bp);
}

namespace _func377
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Ship::GetSelectedRoomId", typeid(int (Ship::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b41048b57048b378b5f088904248955e4e8a6", argdata, 4, 1, &func);
}

int Ship::GetSelectedRoomId(int x, int y, bool unk)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, int x_arg, int y_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func377::func;
	return execfunc(this, x, y, unk);
}

namespace _func378
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Ship::OnRenderBase", typeid(void (Ship::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec6c", argdata, 2, 5, &func);
}

void Ship::OnRenderBase(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Ship *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func378::func;
	return execfunc(this, unk);
}

namespace _func379
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipAI::SetStalemate", typeid(void (ShipAI::*)(bool )), "8b44240484c0740980b9ec0000000075", argdata, 2, 5, &func);
}

void ShipAI::SetStalemate(bool stalemate)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipAI *this_arg, bool stalemate_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func379::func;
	return execfunc(this, stalemate);
}

namespace _func380
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipAI::GetTeleportCommand", typeid(std::pair<int, int> (ShipAI::*)()), "8b410485c074498b0185c07443578d7c", argdata, 1, 9, &func);
}

std::pair<int, int> ShipAI::GetTeleportCommand()
{
	typedef std::pair<int, int> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipAI *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func380::func;
	return execfunc(this);
}

namespace _func381
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CheckTypes", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db32c", argdata, 1, 5, &func);
}

void ShipBuilder::CheckTypes()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func381::func;
	return execfunc(this);
}

namespace _func382
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwitchShip", typeid(void (ShipBuilder::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b17", argdata, 3, 5, &func);
}

void ShipBuilder::SwitchShip(int shipType, int shipVariant)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int shipType_arg, int shipVariant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func382::func;
	return execfunc(this, shipType, shipVariant);
}

namespace _func383
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::SwapType", typeid(void (ShipBuilder::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b09", argdata, 2, 5, &func);
}

void ShipBuilder::SwapType(int variant)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int variant_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func383::func;
	return execfunc(this, variant);
}

namespace _func384
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::OnLoop", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cbb9????????81ec8c", argdata, 1, 5, &func);
}

void ShipBuilder::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func384::func;
	return execfunc(this);
}

namespace _func385
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::constructor", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83c10c8d", argdata, 1, 5, &func);
}

void ShipBuilder::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func385::func;
	return execfunc(this);
}

namespace _func386
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::CycleTypeNext", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cf31f683ec1c", argdata, 1, 5, &func);
}

void ShipBuilder::CycleTypeNext()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func386::func;
	return execfunc(this);
}

namespace _func387
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::GetShip", typeid(ShipManager *(ShipBuilder::*)()), "80b9a810000000744b578d7c240883e4", argdata, 1, 1, &func);
}

ShipManager *ShipBuilder::GetShip()
{
	typedef ShipManager *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func387::func;
	return execfunc(this);
}

namespace _func388
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::Open", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565381ec4c05000089", argdata, 1, 5, &func);
}

void ShipBuilder::Open()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func388::func;
	return execfunc(this);
}

namespace _func389
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipBuilder::SetupShipAchievements", typeid(void (ShipBuilder::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8b816c", argdata, 1, 5, &func);
}

void ShipBuilder::SetupShipAchievements()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func389::func;
	return execfunc(this);
}

namespace _func390
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipBuilder::MouseMove", typeid(void (ShipBuilder::*)(int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ecac01", argdata, 3, 5, &func);
}

void ShipBuilder::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipBuilder *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func390::func;
	return execfunc(this, x, y);
}

namespace _func391
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::GetPossibleSystemUpgrades", typeid(std::vector<int> (*)(ShipManager *, std::vector<int> &, int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec6c8945c0c70000000000c7400400000000c740080000000031c08955bcc745c8000000008db426000000008944", argdata, 5, 2, &func);
}

std::vector<int> ShipGenerator::GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type)
{
	typedef std::vector<int> __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, int scrap_arg, int type_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func391::func;
	return execfunc(ship, systemMaxes, scrap, type);
}

namespace _func392
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::UpgradeSystem", typeid(bool (*)(ShipManager *, std::vector<int> &, unsigned int )), "8d4c240483e4f0ff71fc5589e55756535183ec288b7908", argdata, 3, 2, &func);
}

bool ShipGenerator::UpgradeSystem(ShipManager *ship, std::vector<int> &systemMaxes, unsigned int sysId)
{
	typedef bool __attribute__((cdecl)) (*custom_arg_funcptr_t)(ShipManager *ship_arg, std::vector<int> &systemMaxes_arg, unsigned int sysId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func392::func;
	return execfunc(ship, systemMaxes, sysId);
}

namespace _func393
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGenerator::CreateShip", typeid(ShipManager *(*)(const std::string &, int , ShipEvent &)), "8d4c240483e4f0ff71fc5589e55756535131f6", argdata, 3, 2, &func);
}

ShipManager *ShipGenerator::CreateShip(const std::string &name, int sector, ShipEvent &event)
{
	typedef ShipManager *__attribute__((cdecl)) (*custom_arg_funcptr_t)(const std::string &name_arg, int sector_arg, ShipEvent &event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func393::func;
	return execfunc(name, sector, event);
}

namespace _func394
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::DoorCount", typeid(int (ShipGraph::*)(int )), "538b411c8b59188b54240829d8c1f802", argdata, 2, 1, &func);
}

int ShipGraph::DoorCount(int roomId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func394::func;
	return execfunc(this, roomId);
}

namespace _func395
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetDoors", typeid(std::vector<Door*> (ShipGraph::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b37c7", argdata, 3, 1, &func);
}

std::vector<Door*> ShipGraph::GetDoors(int roomId)
{
	typedef std::vector<Door*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func395::func;
	return execfunc(this, roomId);
}

namespace _func396
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetNumSlots", typeid(int (ShipGraph::*)(int )), "8b5424048b018b04908b50348b421c2b", argdata, 2, 1, &func);
}

int ShipGraph::GetNumSlots(int room)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func396::func;
	return execfunc(this, room);
}

namespace _func397
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::FindPath", typeid(Path (ShipGraph::*)(Point , Point , int )), "578d7c240883e4f0ff77fc5589f889e557565383ec6c8b50", argdata, 5, 1, &func);
}

Path ShipGraph::FindPath(Point p1, Point p2, int shipId)
{
	typedef Path __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg, int shipId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func397::func;
	return execfunc(this, p1, p2, shipId);
}

namespace _func398
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipGraph::ComputeCenter", typeid(void (ShipGraph::*)()), "578d7c240883e4f0ff77fc5589e557565383ec4c8b79", argdata, 1, 5, &func);
}

void ShipGraph::ComputeCenter()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func398::func;
	return execfunc(this);
}

namespace _func399
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipGraph::RoomCount", typeid(int (ShipGraph::*)()), "8b41042b01c1f802c3908db600000000", argdata, 1, 1, &func);
}

int ShipGraph::RoomCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func399::func;
	return execfunc(this);
}

namespace _func400
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomShape", typeid(Globals::Rect (ShipGraph::*)(int )), "5789c88d7c240883e4f0ff77fc5589e557565383ec2c8b17", argdata, 3, 1, &func);
}

Globals::Rect ShipGraph::GetRoomShape(int room)
{
	typedef Globals::Rect __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func400::func;
	return execfunc(this, room);
}

namespace _func401
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetRoomBlackedOut", typeid(bool (ShipGraph::*)(int )), "5653b8010000008b5c240c85db78158b", argdata, 2, 1, &func);
}

bool ShipGraph::GetRoomBlackedOut(int room)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int room_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func401::func;
	return execfunc(this, room);
}

namespace _func402
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSlotWorldPosition", typeid(Point (ShipGraph::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b57048b01", argdata, 3, 9, &func);
}

Point ShipGraph::GetSlotWorldPosition(int slotId, int roomId)
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int slotId_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func402::func;
	return execfunc(this, slotId, roomId);
}

namespace _func403
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("ShipGraph::ConnectingDoor", typeid(Door *(ShipGraph::*)(Point , Point )), "578d7c240883e4f0ff77fc5589e5575383ec108b5f088b078b57048b7f0c895c2408890424897c240c89542404e84e", argdata, 3, 1, &func);
}

Door *ShipGraph::ConnectingDoor(Point p1, Point p2)
{
	typedef Door *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, Point p1_arg, Point p2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func403::func;
	return execfunc(this, p1, p2);
}

namespace _func404
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("ShipGraph::Restart", typeid(void (*)()), "8d4c240483e4f0ff71fc5589e55756535181ec88000000a1????????8b15", argdata, 0, 6, &func);
}

void ShipGraph::Restart()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func404::func;
	return execfunc();
}

namespace _func405
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipGraph::GetSelectedRoom", typeid(int (ShipGraph::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589f889e557565389ce83ec2c8b09", argdata, 4, 1, &func);
}

int ShipGraph::GetSelectedRoom(int x, int y, bool unk)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipGraph *this_arg, int x_arg, int y_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func405::func;
	return execfunc(this, x, y, unk);
}

namespace _func406
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetNetDodgeFactor", typeid(int (ShipManager::*)()), "5589e5565389cb83e4f0e801feffff89", argdata, 1, 1, &func);
}

int ShipManager::GetNetDodgeFactor()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func406::func;
	return execfunc(this);
}

namespace _func407
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::OnLoop", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d8d1c", argdata, 1, 5, &func);
}

void ShipManager::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func407::func;
	return execfunc(this);
}

namespace _func408
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::IncreaseSystemPower", typeid(bool (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b81c80400008b178b", argdata, 2, 1, &func);
}

bool ShipManager::IncreaseSystemPower(int systemId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func408::func;
	return execfunc(this, systemId);
}

namespace _func409
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::CreateSystems", typeid(int (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b8108", argdata, 1, 1, &func);
}

int ShipManager::CreateSystems()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func409::func;
	return execfunc(this);
}

namespace _func410
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::UpdateEnvironment", typeid(void (ShipManager::*)()), "578d41708d7c240883e4f0ff77fc5589e557565389cf89", argdata, 1, 5, &func);
}

void ShipManager::UpdateEnvironment()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func410::func;
	return execfunc(this);
}

namespace _func411
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddCrewMember", typeid(void (ShipManager::*)(CrewMember *, int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b41048b77", argdata, 3, 5, &func);
}

void ShipManager::AddCrewMember(CrewMember *crew, int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func411::func;
	return execfunc(this, crew, roomId);
}

namespace _func412
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PulsarDamage", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec6c8b01", argdata, 1, 5, &func);
}

void ShipManager::PulsarDamage()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func412::func;
	return execfunc(this);
}

namespace _func413
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyScrapCount", typeid(void (ShipManager::*)(int , bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b378b47", argdata, 3, 5, &func);
}

void ShipManager::ModifyScrapCount(int scrap, bool income)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int scrap_arg, bool income_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func413::func;
	return execfunc(this, scrap, income);
}

namespace _func414
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyMissileCount", typeid(void (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b81c80400008b1783780cff7530", argdata, 2, 5, &func);
}

void ShipManager::ModifyMissileCount(int missiles)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int missiles_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func414::func;
	return execfunc(this, missiles);
}

namespace _func415
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ModifyDroneCount", typeid(void (ShipManager::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b81c80400008b17837810ff7530", argdata, 2, 5, &func);
}

void ShipManager::ModifyDroneCount(int drones)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int drones_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func415::func;
	return execfunc(this, drones);
}

namespace _func416
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCrewFull", typeid(bool (ShipManager::*)()), "5731c08d7c240883e4f0ff77fc5589e5575389cb83ec108b5104b9????????85d20f95c0890424e804", argdata, 1, 1, &func);
}

bool ShipManager::IsCrewFull()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func416::func;
	return execfunc(this);
}

namespace _func417
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::IsCrewOverFull", typeid(bool (ShipManager::*)()), "5731c08d7c240883e4f0ff77fc5589e5575389cb83ec108b5104b9????????85d20f95c0890424e854", argdata, 1, 1, &func);
}

bool ShipManager::IsCrewOverFull()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func417::func;
	return execfunc(this);
}

namespace _func418
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateCrewDrone", typeid(CrewDrone *(ShipManager::*)(const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b178b82", argdata, 2, 1, &func);
}

CrewDrone *ShipManager::CreateCrewDrone(const DroneBlueprint *bp)
{
	typedef CrewDrone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func418::func;
	return execfunc(this, bp);
}

namespace _func419
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CommandCrewMoveRoom", typeid(bool (ShipManager::*)(CrewMember *, int )), "578d7c240883e4f0ff77fc5589e55783ec148b47048b0fc7", argdata, 3, 1, &func);
}

bool ShipManager::CommandCrewMoveRoom(CrewMember *crew, int roomId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func419::func;
	return execfunc(this, crew, roomId);
}

namespace _func420
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPower", typeid(int (ShipManager::*)(int )), "558b81c804000089e583e4f08b55088b049083f8ff740b", argdata, 2, 1, &func);
}

int ShipManager::GetSystemPower(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func420::func;
	return execfunc(this, systemId);
}

namespace _func421
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystem", typeid(ShipSystem *(ShipManager::*)(int )), "8b44240483f8ff74178b91c80400008b", argdata, 2, 1, &func);
}

ShipSystem *ShipManager::GetSystem(int systemId)
{
	typedef ShipSystem *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func421::func;
	return execfunc(this, systemId);
}

namespace _func422
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::IsSystemHacked2", typeid(int (ShipManager::*)(int )), "538b5424088b81c804000083fa118b1c", argdata, 2, 1, &func);
}

int ShipManager::IsSystemHacked2(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func422::func;
	return execfunc(this, systemId);
}

namespace _func423
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ClearStatusSystem", typeid(void (ShipManager::*)(int )), "5589e583e4f083ec108b450883f811742f", argdata, 2, 5, &func);
}

void ShipManager::ClearStatusSystem(int system)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int system_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func423::func;
	return execfunc(this, system);
}

namespace _func424
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::ResetScrapLevel", typeid(void (ShipManager::*)()), "a1????????c781d40400001e00000083", argdata, 1, 5, &func);
}

void ShipManager::ResetScrapLevel()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func424::func;
	return execfunc(this);
}

namespace _func425
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddWeapon", typeid(int (ShipManager::*)(const WeaponBlueprint *, int )), "5731c08d7c240883e4f0ff77fc5589e5575383ec10", argdata, 3, 1, &func);
}

int ShipManager::AddWeapon(const WeaponBlueprint *bp, int slot)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const WeaponBlueprint *bp_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func425::func;
	return execfunc(this, bp, slot);
}

namespace _func426
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemFunctions", typeid(bool (ShipManager::*)(int )), "558b81c804000089e583e4f08b55088b149031c083faff740b8b41188b0c908b", argdata, 2, 1, &func);
}

bool ShipManager::SystemFunctions(int systemId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func426::func;
	return execfunc(this, systemId);
}

namespace _func427
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::StartFire", typeid(void (ShipManager::*)(int )), "5783c1708d7c240883e4f0ff77fc5589e55783ec148b07c7", argdata, 2, 5, &func);
}

void ShipManager::StartFire(int roomId)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func427::func;
	return execfunc(this, roomId);
}

namespace _func428
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("ShipManager::CheckCrystalAugment", typeid(void (ShipManager::*)(Pointf )), "578d7c240883e4f0ff77fc5589e55756538d5dd089ce83ec7c", argdata, 2, 5, &func);
}

void ShipManager::CheckCrystalAugment(Pointf pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func428::func;
	return execfunc(this, pos);
}

namespace _func429
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::InstantPowerShields", typeid(void (ShipManager::*)()), "8b81c80400008b0083f8ff7455578d7c", argdata, 1, 5, &func);
}

void ShipManager::InstantPowerShields()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func429::func;
	return execfunc(this);
}

namespace _func430
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemDamage", typeid(int (ShipManager::*)(int )), "8b81c80400008b5424048b049083f8ff7412", argdata, 2, 1, &func);
}

int ShipManager::GetSystemDamage(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func430::func;
	return execfunc(this, systemId);
}

namespace _func431
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemHealth", typeid(int (ShipManager::*)(int )), "8b81c80400008b5424048b049083f8ff740c", argdata, 2, 1, &func);
}

int ShipManager::GetSystemHealth(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func431::func;
	return execfunc(this, systemId);
}

namespace _func432
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetFireCount", typeid(int (ShipManager::*)(int )), "5783c1708d7c240883e4f0ff77fc5589e55783ec148b0789", argdata, 2, 1, &func);
}

int ShipManager::GetFireCount(int roomId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func432::func;
	return execfunc(this, roomId);
}

namespace _func433
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::DoorsFunction", typeid(bool (ShipManager::*)()), "8b81c80400008b402083f8ff74525589", argdata, 1, 1, &func);
}

bool ShipManager::DoorsFunction()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func433::func;
	return execfunc(this);
}

namespace _func434
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x2ff, 0xdff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CollisionShield", typeid(CollisionResponse (ShipManager::*)(Pointf , Pointf , Damage , bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d4d9c81ecdc", argdata, 6, 1, &func);
}

CollisionResponse ShipManager::CollisionShield(Pointf start, Pointf finish, Damage damage, bool raytrace)
{
	typedef CollisionResponse __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, Pointf start_arg, Pointf finish_arg, Damage damage_arg, bool raytrace_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func434::func;
	return execfunc(this, start, finish, damage, raytrace);
}

namespace _func435
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::UpgradeSystem", typeid(void (ShipManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec1c8b1f8b47", argdata, 3, 5, &func);
}

void ShipManager::UpgradeSystem(int id, int amount)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int id_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func435::func;
	return execfunc(this, id, amount);
}

namespace _func436
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::Wait", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b81c8", argdata, 1, 5, &func);
}

void ShipManager::Wait()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func436::func;
	return execfunc(this);
}

namespace _func437
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateDrone", typeid(Drone *(ShipManager::*)(DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b37893424e8e0", argdata, 2, 1, &func);
}

Drone *ShipManager::CreateDrone(DroneBlueprint *drone)
{
	typedef Drone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, DroneBlueprint *drone_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func437::func;
	return execfunc(this, drone);
}

namespace _func438
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::SaveCrewPositions", typeid(void (ShipManager::*)()), "57b9????????8d7c240883e4f0ff77fc5589e55753", argdata, 1, 5, &func);
}

void ShipManager::SaveCrewPositions()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func438::func;
	return execfunc(this);
}

namespace _func439
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetOxygenLevels", typeid(std::vector<float> (ShipManager::*)()), "5589e557565389cb83e4f083ec208b45088b90c8040000837a10", argdata, 2, 1, &func);
}

std::vector<float> ShipManager::GetOxygenLevels()
{
	typedef std::vector<float> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func439::func;
	return execfunc(this);
}

namespace _func440
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::ForceIncreaseSystemPower", typeid(bool (ShipManager::*)(int )), "5731c08d7c240883e4f0ff77fc5589e55783ec148b1783faff742a8bb9c80400008b149783faff741c8b49188b0c9185c974128b01c7042401000000ff9084", argdata, 2, 1, &func);
}

bool ShipManager::ForceIncreaseSystemPower(int systemId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func440::func;
	return execfunc(this, systemId);
}

namespace _func441
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::HasSystem", typeid(bool (ShipManager::*)(int )), "8b542404b80100000083fa11740d8b81", argdata, 2, 1, &func);
}

bool ShipManager::HasSystem(int systemId)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func441::func;
	return execfunc(this, systemId);
}

namespace _func442
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SystemRoom", typeid(int (ShipManager::*)(int )), "558b81c804000089e583e4f08b55088b049083f8ff7415", argdata, 2, 1, &func);
}

int ShipManager::SystemRoom(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func442::func;
	return execfunc(this, systemId);
}

namespace _func443
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::RestoreCrewPositions", typeid(bool (ShipManager::*)()), "57b9????????8d7c240883e4f0ff77fc5589e55756538d45b0", argdata, 1, 1, &func);
}

bool ShipManager::RestoreCrewPositions()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func443::func;
	return execfunc(this);
}

namespace _func444
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemAvailablePower", typeid(int (ShipManager::*)(int )), "5589e557568b5508538b81c804000083", argdata, 2, 1, &func);
}

int ShipManager::GetSystemAvailablePower(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func444::func;
	return execfunc(this, systemId);
}

namespace _func445
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::AddDrone", typeid(Drone *(ShipManager::*)(const DroneBlueprint *, int )), "578d7c240883e4f0ff77fc5589e557565383ec1c8b81c80400008b37", argdata, 3, 1, &func);
}

Drone *ShipManager::AddDrone(const DroneBlueprint *bp, int slot)
{
	typedef Drone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg, int slot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func445::func;
	return execfunc(this, bp, slot);
}

namespace _func446
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetTooltip", typeid(std::string (ShipManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec7c8b47048b37", argdata, 4, 1, &func);
}

std::string ShipManager::GetTooltip(int x, int y)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func446::func;
	return execfunc(this, x, y);
}

namespace _func447
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::SaveToBlueprint", typeid(ShipBlueprint (ShipManager::*)(bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b188b40", argdata, 3, 1, &func);
}

ShipBlueprint ShipManager::SaveToBlueprint(bool overwrite)
{
	typedef ShipBlueprint __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, bool overwrite_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func447::func;
	return execfunc(this, overwrite);
}

namespace _func448
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemPowerMax", typeid(int (ShipManager::*)(int )), "8b81c80400008b5424048b149031c083", argdata, 2, 1, &func);
}

int ShipManager::GetSystemPowerMax(int systemId)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func448::func;
	return execfunc(this, systemId);
}

namespace _func449
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::PrepareSuperDrones", typeid(void (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec7c8b91", argdata, 1, 5, &func);
}

void ShipManager::PrepareSuperDrones()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func449::func;
	return execfunc(this);
}

namespace _func450
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0xdff};
	static FunctionDefinition funcObj("ShipManager::DamageCrew", typeid(bool (ShipManager::*)(CrewMember *, Damage )), "578d7c240883e4f0ff77fc5589f889e557565383ec2c80", argdata, 3, 1, &func);
}

bool ShipManager::DamageCrew(CrewMember *crew, Damage dmg)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, CrewMember *crew_arg, Damage dmg_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func450::func;
	return execfunc(this, crew, dmg);
}

namespace _func451
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipManager::GetDodgeFactor", typeid(int (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e557565381ec5c02", argdata, 1, 1, &func);
}

int ShipManager::GetDodgeFactor()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func451::func;
	return execfunc(this);
}

namespace _func452
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetWeaponList", typeid(std::vector<ProjectileFactory*> (ShipManager::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec308b018b400c", argdata, 2, 1, &func);
}

std::vector<ProjectileFactory*> ShipManager::GetWeaponList()
{
	typedef std::vector<ProjectileFactory*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func452::func;
	return execfunc(this);
}

namespace _func453
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::CreateSpaceDrone", typeid(SpaceDrone *(ShipManager::*)(const DroneBlueprint *)), "578d7c240883e4f0ff77fc5589e557565383ec3c8b3f", argdata, 2, 1, &func);
}

SpaceDrone *ShipManager::CreateSpaceDrone(const DroneBlueprint *bp)
{
	typedef SpaceDrone *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, const DroneBlueprint *bp_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func453::func;
	return execfunc(this, bp);
}

namespace _func454
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipManager::GetSystemInRoom", typeid(ShipSystem *(ShipManager::*)(int )), "8b511839511c74685589e557565389ce", argdata, 2, 1, &func);
}

ShipSystem *ShipManager::GetSystemInRoom(int roomId)
{
	typedef ShipSystem *__attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipManager *this_arg, int roomId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func454::func;
	return execfunc(this, roomId);
}

namespace _func455
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationList", typeid(std::vector<std::string> (ShipObject::*)()), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b008b40", argdata, 2, 1, &func);
}

std::vector<std::string> ShipObject::GetAugmentationList()
{
	typedef std::vector<std::string> __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func455::func;
	return execfunc(this);
}

namespace _func456
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationCount", typeid(int (ShipObject::*)()), "8b510431c085d20f94c06bc0340305??", argdata, 1, 1, &func);
}

int ShipObject::GetAugmentationCount()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func456::func;
	return execfunc(this);
}

namespace _func457
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipObject::ClearShipInfo", typeid(void (ShipObject::*)()), "578d7c240883e4f0ff77fc5589e557565331db83ec2c8b41", argdata, 1, 5, &func);
}

void ShipObject::ClearShipInfo()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func457::func;
	return execfunc(this);
}

namespace _func458
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasEquipment", typeid(int (ShipObject::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e55756538d75a8", argdata, 2, 1, &func);
}

int ShipObject::HasEquipment(const std::string &equip)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &equip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func458::func;
	return execfunc(this, equip);
}

namespace _func459
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::GetAugmentationValue", typeid(float (ShipObject::*)(const std::string &)), "578d7c240883e4f0ff77fc5589e557565389ce83ec3c8b178b5f0485d2750485db757329d383fb0f895de4772683fb018b06755c0fb61288108b5de48b06895e04c60418008d65f45b5e5f5d8d67f85fc208008d45e489f1c7442404000000008955d4890424e885a5", argdata, 2, 1, &func);
}

float ShipObject::GetAugmentationValue(const std::string &augment)
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func459::func;
	return execfunc(this, augment);
}

namespace _func460
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipObject::HasAugmentation", typeid(int (ShipObject::*)(const std::string &)), "5731c08d7c240883e4f0ff77fc5589e557565383ec5c", argdata, 2, 1, &func);
}

int ShipObject::HasAugmentation(const std::string &augment)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipObject *this_arg, const std::string &augment_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func460::func;
	return execfunc(this, augment);
}

namespace _func461
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::OnLoop", typeid(void (ShipSelect::*)()), "80b948050000007507f3c3908d742600", argdata, 1, 5, &func);
}

void ShipSelect::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func461::func;
	return execfunc(this);
}

namespace _func462
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::MouseClick", typeid(void (ShipSelect::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec1080b948", argdata, 1, 5, &func);
}

void ShipSelect::MouseClick()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func462::func;
	return execfunc(this);
}

namespace _func463
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSelect::Close", typeid(void (ShipSelect::*)()), "5581c144050000c681f0faffff0089e5", argdata, 1, 5, &func);
}

void ShipSelect::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSelect *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func463::func;
	return execfunc(this);
}

namespace _func464
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderHealth", typeid(void (ShipStatus::*)(bool )), "578d7c240883e4f0ff77fc5589e557565381ecbc00000080", argdata, 2, 5, &func);
}

void ShipStatus::RenderHealth(bool renderText)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool renderText_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func464::func;
	return execfunc(this, renderText);
}

namespace _func465
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::OnInit", typeid(void (ShipStatus::*)(Point , float )), "578d7c240883e4f0ff77fc5589e55756538db5c0", argdata, 3, 5, &func);
}

void ShipStatus::OnInit(Point location, float size)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, Point location_arg, float size_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func465::func;
	return execfunc(this, location, size);
}

namespace _func466
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderEvadeOxygen", typeid(void (ShipStatus::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec8c02", argdata, 2, 5, &func);
}

void ShipStatus::RenderEvadeOxygen(bool renderText)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool renderText_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func466::func;
	return execfunc(this, renderText);
}

namespace _func467
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipStatus::OnRender", typeid(void (ShipStatus::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10e8269b", argdata, 1, 5, &func);
}

void ShipStatus::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func467::func;
	return execfunc(this);
}

namespace _func468
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipStatus::RenderResources", typeid(void (ShipStatus::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c80792c", argdata, 2, 5, &func);
}

void ShipStatus::RenderResources(bool renderText)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg, bool renderText_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func468::func;
	return execfunc(this, renderText);
}

namespace _func469
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipStatus::OnLoop", typeid(void (ShipStatus::*)()), "578d7c240883e4f0ff77fc5589e557565331db89ce83ec2c8b3f", argdata, 1, 5, &func);
}

void ShipStatus::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func469::func;
	return execfunc(this);
}

namespace _func470
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::IsMannedBoost", typeid(int (ShipSystem::*)()), "8b414885c07e1b????????74158b9104", argdata, 1, 1, &func);
}

int ShipSystem::IsMannedBoost()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func470::func;
	return execfunc(this);
}

namespace _func471
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SystemIdToName", typeid(std::string (*)(int )), "8d4c240483e4f0ff71fc5589e5535183ec108b41048b1983f811", argdata, 2, 2, &func);
}

std::string ShipSystem::SystemIdToName(int systemId)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemId_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func471::func;
	return execfunc(systemId);
}

namespace _func472
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::OnLoop", typeid(void (ShipSystem::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b8128", argdata, 1, 5, &func);
}

void ShipSystem::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func472::func;
	return execfunc(this);
}

namespace _func473
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SetDividePower", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b0783", argdata, 2, 5, &func);
}

void ShipSystem::SetDividePower(int val)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int val_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func473::func;
	return execfunc(this, val);
}

namespace _func474
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetPowerCap", typeid(int (ShipSystem::*)()), "8b811c01000083f8077f1585c0ba0000", argdata, 1, 1, &func);
}

int ShipSystem::GetPowerCap()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func474::func;
	return execfunc(this);
}

namespace _func475
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::LockSystem", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b0783", argdata, 2, 5, &func);
}

void ShipSystem::LockSystem(int lock)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func475::func;
	return execfunc(this, lock);
}

namespace _func476
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetEffectivePower", typeid(int (ShipSystem::*)()), "8b414831d285c07e14????????740e8b", argdata, 1, 1, &func);
}

int ShipSystem::GetEffectivePower()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func476::func;
	return execfunc(this);
}

namespace _func477
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::ClearStatus", typeid(void (ShipSystem::*)()), "83b91c010000077e0a8b812001000085", argdata, 1, 5, &func);
}

void ShipSystem::ClearStatus()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func477::func;
	return execfunc(this);
}

namespace _func478
{
    static void *func = 0;
	static short argdata[] = {0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetLevelDescription", typeid(std::string (*)(int , int , bool )), "8d4c240483e4f0ff71fc5589e55756535181eca801", argdata, 4, 2, &func);
}

std::string ShipSystem::GetLevelDescription(int systemId, int level, bool tooltip)
{
	typedef std::string __attribute__((cdecl)) (*custom_arg_funcptr_t)(int systemId_arg, int level_arg, bool tooltip_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func478::func;
	return execfunc(systemId, level, tooltip);
}

namespace _func479
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::AddLock", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec148b8128", argdata, 2, 5, &func);
}

void ShipSystem::AddLock(int lock)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int lock_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func479::func;
	return execfunc(this, lock);
}

namespace _func480
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::StopHacking", typeid(void (ShipSystem::*)()), "8b01c681ac010000008b40643d??????", argdata, 1, 5, &func);
}

void ShipSystem::StopHacking()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func480::func;
	return execfunc(this);
}

namespace _func481
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::SaveState", typeid(void (ShipSystem::*)(int )), "5589e5565389ce83e4f083ec108b5d088b811c", argdata, 2, 5, &func);
}

void ShipSystem::SaveState(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func481::func;
	return execfunc(this, file);
}

namespace _func482
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::LoadState", typeid(void (ShipSystem::*)(int )), "5589e5565389cb83e4f083ec108b7508893424e868", argdata, 2, 5, &func);
}

void ShipSystem::LoadState(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func482::func;
	return execfunc(this, file);
}

namespace _func483
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::UpgradeSystem", typeid(bool (ShipSystem::*)(int )), "8b015589e556538b401089cb8b750883", argdata, 2, 1, &func);
}

bool ShipSystem::UpgradeSystem(int amount)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func483::func;
	return execfunc(this, amount);
}

namespace _func484
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::GetLockTimer", typeid(TimerHelper (ShipSystem::*)()), "8b54240489c88b8a2c01000089088b8a", argdata, 2, 1, &func);
}

TimerHelper ShipSystem::GetLockTimer()
{
	typedef TimerHelper __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func484::func;
	return execfunc(this);
}

namespace _func485
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::DecreasePower", typeid(bool (ShipSystem::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec3c8b178b5f0485d2750485db757329d383fb0f895de4772683fb018b06755c0fb61288108b5de48b06895e04c60418008d65f45b5e5f5d8d67f85fc208008d45e489f1c7442404000000008955d4890424e8d5", argdata, 2, 1, &func);
}

bool ShipSystem::DecreasePower(bool force)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func485::func;
	return execfunc(this, force);
}

namespace _func486
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("ShipSystem::GetLocked", typeid(bool (ShipSystem::*)()), "8b912801000085d20f9fc083faff0f94", argdata, 1, 1, &func);
}

bool ShipSystem::GetLocked()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func486::func;
	return execfunc(this);
}

namespace _func487
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::IonDamage", typeid(void (ShipSystem::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec2c8b3785f67e", argdata, 2, 5, &func);
}

void ShipSystem::IonDamage(int amount)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int amount_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func487::func;
	return execfunc(this, amount);
}

namespace _func488
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("ShipSystem::RenderPowerBoxes", typeid(int (ShipSystem::*)(int , int , int , int , int , int , bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec9c0000008b07", argdata, 8, 1, &func);
}

int ShipSystem::RenderPowerBoxes(int x, int y, int width, int height, int gap, int heightMod, bool flash)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(ShipSystem *this_arg, int x_arg, int y_arg, int width_arg, int height_arg, int gap_arg, int heightMod_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func488::func;
	return execfunc(this, x, y, width, height, gap, heightMod, flash);
}

namespace _func489
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::UpdateSoundLoop", typeid(void (SoundControl::*)(const std::string &, float )), "578d7c240883e4f0ff77fc5589e557565383ec4c8039", argdata, 3, 5, &func);
}

void SoundControl::UpdateSoundLoop(const std::string &loopId, float count)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SoundControl *this_arg, const std::string &loopId_arg, float count_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func489::func;
	return execfunc(this, loopId, count);
}

namespace _func490
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SoundControl::PlaySoundMix", typeid(int (SoundControl::*)(const std::string &, float , bool )), "578d7c240883e4f0ff77fc5589e557565381ec9c0000008039", argdata, 4, 1, &func);
}

int SoundControl::PlaySoundMix(const std::string &soundName, float volume, bool loop)
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(SoundControl *this_arg, const std::string &soundName_arg, float volume_arg, bool loop_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func490::func;
	return execfunc(this, soundName, volume, loop);
}

namespace _func491
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceDrone::SetDeployed", typeid(void (SpaceDrone::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b018b378b50", argdata, 2, 5, &func);
}

void SpaceDrone::SetDeployed(bool deployed)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceDrone *this_arg, bool deployed_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func491::func;
	return execfunc(this, deployed);
}

namespace _func492
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetScreenShake", typeid(int (SpaceManager::*)()), "0fb68188030000c6818803000000c390", argdata, 1, 1, &func);
}

int SpaceManager::GetScreenShake()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func492::func;
	return execfunc(this);
}

namespace _func493
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::StartAsteroids", typeid(void (SpaceManager::*)(int , bool )), "5789ca83c10c8d7c240883e4f0ff77fc", argdata, 3, 5, &func);
}

void SpaceManager::StartAsteroids(int shieldCount, bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int shieldCount_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func493::func;
	return execfunc(this, shieldCount, unk);
}

namespace _func494
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::GetFlashOpacity", typeid(float (SpaceManager::*)()), "57660fefc08d7c240883e4f0ff77fc5589e5575383", argdata, 1, 1, &func);
}

float SpaceManager::GetFlashOpacity()
{
	typedef float __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func494::func;
	return execfunc(this);
}

namespace _func495
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnInit", typeid(void (SpaceManager::*)()), "578d7c240883e4f0ff77fc5589e557568d45d8", argdata, 1, 5, &func);
}

void SpaceManager::OnInit()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func495::func;
	return execfunc(this);
}

namespace _func496
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::ClearEnvironment", typeid(void (SpaceManager::*)()), "c6818802000000c6818902000000c681", argdata, 1, 5, &func);
}

void SpaceManager::ClearEnvironment()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func496::func;
	return execfunc(this);
}

namespace _func497
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetFireLevel", typeid(void (SpaceManager::*)(bool )), "578d7c240883e4f0ff77fc5589f889e55756538d99b802000089cf8d75d083ec3c8b00888188", argdata, 2, 5, &func);
}

void SpaceManager::SetFireLevel(bool state)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func497::func;
	return execfunc(this, state);
}

namespace _func498
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPlanetaryDefense", typeid(void (SpaceManager::*)(char , int )), "578d7c240883e4f0ff77fc5589e557565389cb81ecbc0000008b47", argdata, 3, 5, &func);
}

void SpaceManager::SetPlanetaryDefense(char state, int target)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, char state_arg, int target_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func498::func;
	return execfunc(this, state, target);
}

namespace _func499
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::UpdatePlanetImage", typeid(void (SpaceManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c8b59", argdata, 1, 5, &func);
}

void SpaceManager::UpdatePlanetImage()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func499::func;
	return execfunc(this);
}

namespace _func500
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetStorm", typeid(void (SpaceManager::*)(bool )), "578d7c240883e4f0ff77fc5589e557538d5d", argdata, 2, 5, &func);
}

void SpaceManager::SetStorm(bool state)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func500::func;
	return execfunc(this, state);
}

namespace _func501
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetPulsarLevel", typeid(void (SpaceManager::*)(bool )), "578d7c240883e4f0ff77fc5589f889e55756538d99b802000089cf8d75d083ec3c8b00888189", argdata, 2, 5, &func);
}

void SpaceManager::SetPulsarLevel(bool pulsarLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool pulsarLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func501::func;
	return execfunc(this, pulsarLevel);
}

namespace _func502
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnLoop", typeid(void (SpaceManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81c120", argdata, 1, 5, &func);
}

void SpaceManager::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func502::func;
	return execfunc(this);
}

namespace _func503
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetDangerZone", typeid(void (SpaceManager::*)(int )), "578d7c240883e4f0ff77fc5589e557565383ec3c8b0785c08945d0", argdata, 2, 5, &func);
}

void SpaceManager::SetDangerZone(int fleetType)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fleetType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func503::func;
	return execfunc(this, fleetType);
}

namespace _func504
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SetNebula", typeid(void (SpaceManager::*)(bool )), "578d7c240883e4f0ff77fc5589e55756538d5dac", argdata, 2, 5, &func);
}

void SpaceManager::SetNebula(bool state)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, bool state_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func504::func;
	return execfunc(this, state);
}

namespace _func505
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::LoadSpace", typeid(void (SpaceManager::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8b078904248945c8", argdata, 2, 5, &func);
}

void SpaceManager::LoadSpace(int fileHelper)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func505::func;
	return execfunc(this, fileHelper);
}

namespace _func506
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SpaceManager::SaveSpace", typeid(void (SpaceManager::*)(int )), "578d7c240883e4f0ff77fc5589e557565389ce83ec2c0fb681", argdata, 2, 5, &func);
}

void SpaceManager::SaveSpace(int fileHelper)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg, int fileHelper_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func506::func;
	return execfunc(this, fileHelper);
}

namespace _func507
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceManager::OnRenderForeground", typeid(void (SpaceManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ec9c", argdata, 1, 5, &func);
}

void SpaceManager::OnRenderForeground()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func507::func;
	return execfunc(this);
}

namespace _func508
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff};
	static FunctionDefinition funcObj("SpaceStatus::OnInit", typeid(void (SpaceStatus::*)(SpaceManager *, Point )), "578d7c240883e4f0ff77fc5589e557565389cb89", argdata, 3, 5, &func);
}

void SpaceStatus::OnInit(SpaceManager *space, Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg, SpaceManager *space_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func508::func;
	return execfunc(this, space, pos);
}

namespace _func509
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceStatus::OnRender", typeid(void (SpaceStatus::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b492c", argdata, 1, 5, &func);
}

void SpaceStatus::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func509::func;
	return execfunc(this);
}

namespace _func510
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SpaceStatus::MouseMove", typeid(void (SpaceStatus::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b378b41", argdata, 3, 5, &func);
}

void SpaceStatus::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func510::func;
	return execfunc(this, mX, mY);
}

namespace _func511
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SpaceStatus::OnLoop", typeid(void (SpaceStatus::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81eccc0000008b41", argdata, 1, 5, &func);
}

void SpaceStatus::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SpaceStatus *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func511::func;
	return execfunc(this);
}

namespace _func512
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::ModifyPursuit", typeid(void (StarMap::*)(int )), "8b442404018198040000c20400906690", argdata, 2, 5, &func);
}

void StarMap::ModifyPursuit(int unk0)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func512::func;
	return execfunc(this, unk0);
}

namespace _func513
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetWaitLocation", typeid(void (StarMap::*)()), "????????741a80b9ac060000007411c6", argdata, 1, 5, &func);
}

void StarMap::GetWaitLocation()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func513::func;
	return execfunc(this);
}

namespace _func514
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ForceExitBeacon", typeid(void (StarMap::*)()), "8b4150c6401401c3908db42600000000", argdata, 1, 5, &func);
}

void StarMap::ForceExitBeacon()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func514::func;
	return execfunc(this);
}

namespace _func515
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::ForceBossJump", typeid(void (StarMap::*)()), "80b97008000000c6817108000001751a", argdata, 1, 5, &func);
}

void StarMap::ForceBossJump()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func515::func;
	return execfunc(this);
}

namespace _func516
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetBossStage", typeid(void (StarMap::*)(int )), "8b4424048981e4090000c20400906690", argdata, 2, 5, &func);
}

void StarMap::SetBossStage(int stage)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int stage_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func516::func;
	return execfunc(this, stage);
}

namespace _func517
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::CheckGameOver", typeid(void (StarMap::*)()), "31c083b96c080000047405f3????????", argdata, 1, 5, &func);
}

void StarMap::CheckGameOver()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func517::func;
	return execfunc(this);
}

namespace _func518
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::PushSectorColumn", typeid(void (StarMap::*)()), "5589e557565389cf83e4f083ec208b81fc", argdata, 1, 5, &func);
}

void StarMap::PushSectorColumn()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func518::func;
	return execfunc(this);
}

namespace _func519
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x4ff};
	static FunctionDefinition funcObj("StarMap::RenderSectorName", typeid(void (StarMap::*)(Sector *, GL_Color )), "578d7c240883e4f0ff77fc5589e55756538d85d0", argdata, 3, 5, &func);
}

void StarMap::RenderSectorName(Sector *unk0, GL_Color unk1)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Sector *unk0_arg, GL_Color unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func519::func;
	return execfunc(this, unk0, unk1);
}

namespace _func520
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::RenderLeftInsetButton", typeid(void (StarMap::*)(float , float , bool )), "578d7c240883e4f0ff77fc5589e557565389cb81ec9c0000008b7708", argdata, 4, 5, &func);
}

void StarMap::RenderLeftInsetButton(float unk0, float unk1, bool unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, float unk0_arg, float unk1_arg, bool unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func520::func;
	return execfunc(this, unk0, unk1, unk2);
}

namespace _func521
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitBossMessageBox", typeid(void (StarMap::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c8bb1", argdata, 1, 5, &func);
}

void StarMap::InitBossMessageBox()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func521::func;
	return execfunc(this);
}

namespace _func522
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::Dijkstra", typeid(std::vector<Location*> (StarMap::*)(Location *, Location *, bool )), "578d7c240883e4f0ff77fc5589f889e557565383ec2c0f", argdata, 5, 1, &func);
}

std::vector<Location*> StarMap::Dijkstra(Location *start, Location *finish, bool include_unknown)
{
	typedef std::vector<Location*> __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Location *start_arg, Location *finish_arg, bool include_unknown_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func522::func;
	return execfunc(this, start, finish, include_unknown);
}

namespace _func523
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::StartSecretSector", typeid(void (StarMap::*)()), "578d7c240883e4f0ff77fc5589e55756538d75d08d5dd883ec3c", argdata, 1, 5, &func);
}

void StarMap::StartSecretSector()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func523::func;
	return execfunc(this);
}

namespace _func524
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::PointToGrid", typeid(Point (StarMap::*)(float , float )), "578d7c240883e4f0ff77fc5589e5578d4df083ec34", argdata, 3, 9, &func);
}

Point StarMap::PointToGrid(float x, float y)
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, float x_arg, float y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func524::func;
	return execfunc(this, x, y);
}

namespace _func525
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::GetLocationText", typeid(std::string (StarMap::*)(const Location *)), "578d41148d7c240883e4f0ff77fc5589e557565389cf83", argdata, 3, 1, &func);
}

std::string StarMap::GetLocationText(const Location *loc)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, const Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func525::func;
	return execfunc(this, loc);
}

namespace _func526
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SaveGame", typeid(void (StarMap::*)(int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec3c8b89", argdata, 2, 5, &func);
}

void StarMap::SaveGame(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func526::func;
	return execfunc(this, file);
}

namespace _func527
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GenerateSectorMap", typeid(void (StarMap::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b078b7f", argdata, 1, 5, &func);
}

void StarMap::GenerateSectorMap()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func527::func;
	return execfunc(this);
}

namespace _func528
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::MouseClick", typeid(void (StarMap::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb81ec9c00000080b9", argdata, 3, 5, &func);
}

void StarMap::MouseClick(int unk0, int unk1)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int unk0_arg, int unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func528::func;
	return execfunc(this, unk0, unk1);
}

namespace _func529
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x2ff};
	static FunctionDefinition funcObj("StarMap::ConnectLocations", typeid(void (StarMap::*)(Point , Point )), "578d7c240883e4f0ff77fc5589e55756538d712c8d", argdata, 3, 5, &func);
}

void StarMap::ConnectLocations(Point unk0, Point unk1)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, Point unk0_arg, Point unk1_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func529::func;
	return execfunc(this, unk0, unk1);
}

namespace _func530
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::AdvanceWorldLevel", typeid(void (StarMap::*)()), "8b819004000083c00183f80389819004", argdata, 1, 5, &func);
}

void StarMap::AdvanceWorldLevel()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func530::func;
	return execfunc(this);
}

namespace _func531
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitNoFuelText", typeid(void (StarMap::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8d7dc88d75d083", argdata, 1, 5, &func);
}

void StarMap::InitNoFuelText()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func531::func;
	return execfunc(this);
}

namespace _func532
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::RenderDistressButtons", typeid(void (StarMap::*)()), "578d7c240883e4f0ff77fc5589e55756538d7dc889", argdata, 1, 5, &func);
}

void StarMap::RenderDistressButtons()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func532::func;
	return execfunc(this);
}

namespace _func533
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::AddQuest", typeid(bool (StarMap::*)(const std::string &, bool )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec3c8b300f", argdata, 3, 1, &func);
}

bool StarMap::AddQuest(const std::string &questEvent, bool force)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, const std::string &questEvent_arg, bool force_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func533::func;
	return execfunc(this, questEvent, force);
}

namespace _func534
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::InitMapTitle", typeid(void (StarMap::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d7d", argdata, 1, 5, &func);
}

void StarMap::InitMapTitle()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func534::func;
	return execfunc(this);
}

namespace _func535
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StarMap::GetRandomSectorChoice", typeid(int (StarMap::*)()), "5589e583e4f0803d????????007431e84c", argdata, 1, 1, &func);
}

int StarMap::GetRandomSectorChoice()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func535::func;
	return execfunc(this);
}

namespace _func536
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("StarMap::SetupNoFuel", typeid(void (StarMap::*)(int , const std::string &)), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c807f04", argdata, 3, 5, &func);
}

void StarMap::SetupNoFuel(int seed, const std::string &forceEscape)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StarMap *this_arg, int seed_arg, const std::string &forceEscape_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func536::func;
	return execfunc(this, seed, forceEscape);
}

namespace _func537
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::constructor", typeid(void (Store::*)()), "5589e55389cb83e4f0e872080b008d43", argdata, 1, 5, &func);
}

void Store::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func537::func;
	return execfunc(this);
}

namespace _func538
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("Store::DrawBuySellTabText", typeid(void (*)()), "8d4c240483e4f0ff71fc5589e5575653518d45d0", argdata, 0, 4, &func);
}

void Store::DrawBuySellTabText()
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)();
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func538::func;
	return execfunc();
}

namespace _func539
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("Store::OnInit", typeid(void (Store::*)(ShipManager *, Equipment *, int )), "578d7c240883e4f0ff77fc5589e557565389cb31f683ec2c", argdata, 4, 5, &func);
}

void Store::OnInit(ShipManager *shopper, Equipment *equip, int worldLevel)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, ShipManager *shopper_arg, Equipment *equip_arg, int worldLevel_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func539::func;
	return execfunc(this, shopper, equip, worldLevel);
}

namespace _func540
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Store::SaveStore", typeid(void (Store::*)(int )), "5589e557565389cf83e4f083ec208b8164", argdata, 2, 5, &func);
}

void Store::SaveStore(int file)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg, int file_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func540::func;
	return execfunc(this, file);
}

namespace _func541
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Store::SetPositions", typeid(void (Store::*)()), "578d7c240883e4f0ff77fc5589e557565389ce31db81", argdata, 1, 5, &func);
}

void Store::SetPositions()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Store *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func541::func;
	return execfunc(this);
}

namespace _func542
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("StoreBox::SetPosition", typeid(void (StoreBox::*)(Point )), "578d7c240883e4f0ff77fc5589e5575389cb8d4df083ec208b078b570489042489542404e8f7", argdata, 2, 5, &func);
}

void StoreBox::SetPosition(Point pos)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg, Point pos_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func542::func;
	return execfunc(this, pos);
}

namespace _func543
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("StoreBox::Purchase", typeid(void (StoreBox::*)()), "57????????008d7c240883e4f0ff77fc5589e55756538d7dd08d75d889cbb9????????83ec3c8975d0668955d8c744240800000000c7442404000080bf893c24c645da79c745d403000000c645db00e8fc", argdata, 1, 5, &func);
}

void StoreBox::Purchase()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(StoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func543::func;
	return execfunc(this);
}

namespace _func544
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::OnRender", typeid(void (SystemBox::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec7c0f", argdata, 2, 5, &func);
}

void SystemBox::OnRender(bool ignoreStatus)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, bool ignoreStatus_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func544::func;
	return execfunc(this, ignoreStatus);
}

namespace _func545
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::constructor", typeid(void (SystemBox::*)(Point , ShipSystem *, bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d9e", argdata, 4, 5, &func);
}

void SystemBox::constructor(Point pos, ShipSystem *sys, bool playerUI)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, Point pos_arg, ShipSystem *sys_arg, bool playerUI_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func545::func;
	return execfunc(this, pos, sys, playerUI);
}

namespace _func546
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::MouseMove", typeid(void (SystemBox::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b378b81", argdata, 3, 5, &func);
}

void SystemBox::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func546::func;
	return execfunc(this, x, y);
}

namespace _func547
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::KeyDown", typeid(void (SystemBox::*)(SDLKey , bool )), "578d7c240883e4f0ff77fc5589e557565389ce8d5db8", argdata, 3, 5, &func);
}

void SystemBox::KeyDown(SDLKey key, bool shift)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, SDLKey key_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func547::func;
	return execfunc(this, key, shift);
}

namespace _func548
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SystemBox::destructor", typeid(void (SystemBox::*)()), "5589e55756538d79348d591089ce83e4", argdata, 1, 5, &func);
}

void SystemBox::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func548::func;
	return execfunc(this);
}

namespace _func549
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemBox::MouseClick", typeid(bool (SystemBox::*)(bool )), "5589e5565389cb8b494c8b750883e4f0", argdata, 2, 1, &func);
}

bool SystemBox::MouseClick(bool shift)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemBox *this_arg, bool shift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func549::func;
	return execfunc(this, shift);
}

namespace _func550
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("SystemControl::OnRender", typeid(void (SystemControl::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec6c8b09", argdata, 2, 5, &func);
}

void SystemControl::OnRender(bool front)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemControl *this_arg, bool front_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func550::func;
	return execfunc(this, front);
}

namespace _func551
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("SystemCustomBox::constructor", typeid(void (SystemCustomBox::*)(Point , ShipSystem *, ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec6c8b078b77", argdata, 4, 5, &func);
}

void SystemCustomBox::constructor(Point pos, ShipSystem *sys, ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemCustomBox *this_arg, Point pos_arg, ShipSystem *sys_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func551::func;
	return execfunc(this, pos, sys, ship);
}

namespace _func552
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("SystemStoreBox::Purchase", typeid(void (SystemStoreBox::*)()), "578d7c240883e4f0ff77fc5589e557565389cb8db338", argdata, 1, 5, &func);
}

void SystemStoreBox::Purchase()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(SystemStoreBox *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func552::func;
	return execfunc(this);
}

namespace _func553
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TabbedWindow::Close", typeid(void (TabbedWindow::*)()), "5589e5538b51408b412889cb83e4f08b", argdata, 1, 5, &func);
}

void TabbedWindow::Close()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TabbedWindow *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func553::func;
	return execfunc(this);
}

namespace _func554
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TabbedWindow::SetTab", typeid(void (TabbedWindow::*)(unsigned int )), "578d7c240883e4f0ff77fc5589f889e557565389cf81ecac00", argdata, 2, 5, &func);
}

void TabbedWindow::SetTab(unsigned int tab)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TabbedWindow *this_arg, unsigned int tab_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func554::func;
	return execfunc(this, tab);
}

namespace _func555
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportBox::constructor", typeid(void (TeleportBox::*)(Point , TeleportSystem *)), "578d7c240883e4f0ff77fc5589e557565389cb81ecbc0000008b57", argdata, 3, 5, &func);
}

void TeleportBox::constructor(Point pos, TeleportSystem *sys)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportBox *this_arg, Point pos_arg, TeleportSystem *sys_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func555::func;
	return execfunc(this, pos, sys);
}

namespace _func556
{
    static void *func = 0;
	static const short *argdata = NULL;
	static FunctionDefinition funcObj("TeleportSystem::__DO_NOT_HOOK", typeid(void (TeleportSystem::*)()), "8d4c240483e4f0ff71fc5589e5535183ec40", argdata, 0, 4, &func);
}

namespace _func557
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TeleportSystem::constructor", typeid(void (TeleportSystem::*)(int , int , int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b7704", argdata, 5, 5, &func);
}

void TeleportSystem::constructor(int systemId, int roomId, int shipId, int startingPower)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg, int systemId_arg, int roomId_arg, int shipId_arg, int startingPower_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func557::func;
	return execfunc(this, systemId, roomId, shipId, startingPower);
}

namespace _func558
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::ForceReady", typeid(void (TeleportSystem::*)()), "578d7c240883e4f0ff77fc5589e55783ec14c781", argdata, 1, 5, &func);
}

void TeleportSystem::ForceReady()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func558::func;
	return execfunc(this);
}

namespace _func559
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::CanReceive", typeid(bool (TeleportSystem::*)()), "5589e556538b750883e4f080b9c50100", argdata, 1, 1, &func);
}

bool TeleportSystem::CanReceive()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func559::func;
	return execfunc(this);
}

namespace _func560
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TeleportSystem::InitiateTeleport", typeid(void (TeleportSystem::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec30e8c6", argdata, 1, 5, &func);
}

void TeleportSystem::InitiateTeleport()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TeleportSystem *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func560::func;
	return execfunc(this);
}

namespace _func561
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::OnRender", typeid(void (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ecac00000080", argdata, 1, 5, &func);
}

void TextButton::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func561::func;
	return execfunc(this);
}

namespace _func562
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::destructor", typeid(void (TextButton::*)()), "5589e55389cb81c3cc00000083e4f083", argdata, 1, 5, &func);
}

void TextButton::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func562::func;
	return execfunc(this);
}

namespace _func563
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::GetSize_DO_NOT_USE_DIRECTLY", typeid(__int64 (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec5c80b9b4", argdata, 1, 9, &func);
}

FUNC_NAKED __int64 TextButton::GetSize_DO_NOT_USE_DIRECTLY()
{
	__asm__
	(
		"pushl %%ebp\n\t"
		"movl %%esp, %%ebp\n\t"
		"pushl %%ecx\n\t"
		"pushl %%ebx\n\t"
		"pushl %%esi\n\t"
		"pushl %%edi\n\t"
			// ecx has this
		"call *%0\n\t"
		"popl %%edi\n\t"
		"popl %%esi\n\t"
		"popl %%ebx\n\t"
		"popl %%ecx\n\t"
		"movl %%ebp, %%esp\n\t"
		"popl %%ebp\n\t"
		"ret\n\t"
		 :: "m"(_func563::func)
	);
}

namespace _func564
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextButton::SetAutoWidth", typeid(void (TextButton::*)(bool , bool , int , int )), "8b5424048b4424108891b40000008b54", argdata, 5, 5, &func);
}

void TextButton::SetAutoWidth(bool autoWidth, bool autoRightAlign, int margin, int min)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg, bool autoWidth_arg, bool autoRightAlign_arg, int margin_arg, int min_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func564::func;
	return execfunc(this, autoWidth, autoRightAlign, margin, min);
}

namespace _func565
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::UpdateAutoWidth", typeid(void (TextButton::*)()), "80b9b4000000007507f3c3908d742600", argdata, 1, 5, &func);
}

void TextButton::UpdateAutoWidth()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func565::func;
	return execfunc(this);
}

namespace _func566
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextButton::GetIdealButtonWidth", typeid(int (TextButton::*)()), "578d7c240883e4f0ff77fc5589e557565389cf81ecbc", argdata, 1, 1, &func);
}

int TextButton::GetIdealButtonWidth()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextButton *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func566::func;
	return execfunc(this);
}

namespace _func567
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::OnLoop", typeid(void (TextInput::*)()), "5589e5538b413083e4f03941347407c7", argdata, 1, 5, &func);
}

void TextInput::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func567::func;
	return execfunc(this);
}

namespace _func568
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::GetActive", typeid(bool (TextInput::*)()), "0fb64138c3????????8dbc2700000000", argdata, 1, 1, &func);
}

bool TextInput::GetActive()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func568::func;
	return execfunc(this);
}

namespace _func569
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TextInput::Stop", typeid(void (TextInput::*)()), "55c641380089e583e4f0e851351500c9", argdata, 1, 5, &func);
}

void TextInput::Stop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextInput *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func569::func;
	return execfunc(this);
}

namespace _func570
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TextLibrary::GetText", typeid(std::string (TextLibrary::*)(const std::string &, const std::string &)), "578d7c240883e4f0ff77fc5589e557565383ec5c8b178b", argdata, 4, 1, &func);
}

std::string TextLibrary::GetText(const std::string &name, const std::string &lang)
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextLibrary *this_arg, const std::string &name_arg, const std::string &lang_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func570::func;
	return execfunc(this, name, lang);
}

namespace _func571
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TextString::GetText", typeid(std::string (TextString::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b17807a18", argdata, 2, 1, &func);
}

std::string TextString::GetText()
{
	typedef std::string __attribute__((thiscall)) (*custom_arg_funcptr_t)(TextString *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func571::func;
	return execfunc(this);
}

namespace _func572
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::Start", typeid(void (TimerHelper::*)(int )), "5589e55653c6411101c7410800000000", argdata, 2, 5, &func);
}

void TimerHelper::Start(int goal)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, int goal_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func572::func;
	return execfunc(this, goal);
}

namespace _func573
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::ResetMinMax", typeid(void (TimerHelper::*)(int , int )), "8b44240889018b442404894104c20800", argdata, 3, 5, &func);
}

void TimerHelper::ResetMinMax(int min, int max)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, int min_arg, int max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func573::func;
	return execfunc(this, min, max);
}

namespace _func574
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Done", typeid(bool (TimerHelper::*)()), "0fb6411184c0746bf30f1041080f2e41", argdata, 1, 1, &func);
}

bool TimerHelper::Done()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func574::func;
	return execfunc(this);
}

namespace _func575
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Update", typeid(void (TimerHelper::*)()), "80791100750af3c3908db42600000000", argdata, 1, 5, &func);
}

void TimerHelper::Update()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func575::func;
	return execfunc(this);
}

namespace _func576
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TimerHelper::SetMaxTime", typeid(void (TimerHelper::*)(float )), "f30f104908f30f5e490cf30f10442404", argdata, 2, 5, &func);
}

void TimerHelper::SetMaxTime(float max)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg, float max_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func576::func;
	return execfunc(this, max);
}

namespace _func577
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TimerHelper::Running", typeid(bool (TimerHelper::*)()), "0fb64111c3????????8dbc2700000000", argdata, 1, 1, &func);
}

bool TimerHelper::Running()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TimerHelper *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func577::func;
	return execfunc(this);
}

namespace _func578
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("TopScore::copy_constructor", typeid(void (TopScore::*)(const TopScore &)), "578d41088d7c240883e4f0ff77fc5589e557565389cb83ec3c8b37", argdata, 2, 5, &func);
}

void TopScore::copy_constructor(const TopScore &other)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TopScore *this_arg, const TopScore &other_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func578::func;
	return execfunc(this, other);
}

namespace _func579
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TutorialManager::OnInit", typeid(void (TutorialManager::*)(ShipManager *, CommandGui *, CrewControl *, Upgrades *, CombatControl *, SystemControl *, TabbedWindow *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec7c8b470c", argdata, 8, 5, &func);
}

void TutorialManager::OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg, ShipManager *ship_arg, CommandGui *gui_arg, CrewControl *crewControl_arg, Upgrades *upgradesScreen_arg, CombatControl *combatControl_arg, SystemControl *sysControl_arg, TabbedWindow *unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func579::func;
	return execfunc(this, ship, gui, crewControl, upgradesScreen, combatControl, sysControl, unk);
}

namespace _func580
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("TutorialManager::MouseMove", typeid(void (TutorialManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b0780", argdata, 3, 5, &func);
}

void TutorialManager::MouseMove(int mX, int mY)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg, int mX_arg, int mY_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func580::func;
	return execfunc(this, mX, mY);
}

namespace _func581
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TutorialManager::AllowJumping", typeid(bool (TutorialManager::*)()), "57????????008d7c240883e4f0ff77fc5589e55756538d45d08d5dd889ce83ec4c89", argdata, 1, 1, &func);
}

bool TutorialManager::AllowJumping()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func581::func;
	return execfunc(this);
}

namespace _func582
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TutorialManager::Running", typeid(bool (TutorialManager::*)()), "0fb601c38db6000000008dbf00000000", argdata, 1, 1, &func);
}

bool TutorialManager::Running()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func582::func;
	return execfunc(this);
}

namespace _func583
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TutorialManager::OnRender", typeid(void (TutorialManager::*)()), "803900750bf3c389f68dbc2700000000578d7c240883e4f0ff77fc5589e557565389cf", argdata, 1, 5, &func);
}

void TutorialManager::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func583::func;
	return execfunc(this);
}

namespace _func584
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("TutorialManager::AllowUpgrades", typeid(bool (TutorialManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb81ec9c0000008079", argdata, 1, 1, &func);
}

bool TutorialManager::AllowUpgrades()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(TutorialManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func584::func;
	return execfunc(this);
}

namespace _func585
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("UnlockArrow::constructor", typeid(void (UnlockArrow::*)(Point , int , int )), "578d7c240883e4f0ff77fc5589f889e557565389cf83ec4c8b1080", argdata, 4, 5, &func);
}

void UnlockArrow::constructor(Point pos, int unk1, int unk2)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UnlockArrow *this_arg, Point pos_arg, int unk1_arg, int unk2_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func585::func;
	return execfunc(this, pos, unk1, unk2);
}

namespace _func586
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::constructorEmpty", typeid(void (UpgradeBox::*)(Point , bool )), "578d51248d7c240883e4f0ff77fc5589f8", argdata, 3, 5, &func);
}

void UpgradeBox::constructorEmpty(Point pos, bool subsystem)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, Point pos_arg, bool subsystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func586::func;
	return execfunc(this, pos, subsystem);
}

namespace _func587
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("UpgradeBox::constructorSystem", typeid(void (UpgradeBox::*)(ShipManager *, ShipSystem *, Point , bool )), "578d7c240883e4f0ff77fc5589fa89e557565389cb83ec5c", argdata, 5, 5, &func);
}

void UpgradeBox::constructorSystem(ShipManager *ship, ShipSystem *sys, Point pos, bool subsystem)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(UpgradeBox *this_arg, ShipManager *ship_arg, ShipSystem *sys_arg, Point pos_arg, bool subsystem_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func587::func;
	return execfunc(this, ship, sys, pos, subsystem);
}

namespace _func588
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("Upgrades::OnInit", typeid(void (Upgrades::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389ce8d5de0", argdata, 2, 5, &func);
}

void Upgrades::OnInit(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func588::func;
	return execfunc(this, ship);
}

namespace _func589
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("Upgrades::OnLoop", typeid(void (Upgrades::*)()), "807938000f8466010000578d7c240883", argdata, 1, 5, &func);
}

void Upgrades::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(Upgrades *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func589::func;
	return execfunc(this);
}

namespace _func590
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::Start", typeid(void (WarningMessage::*)()), "80791400755a578d7c240883e4f0ff77", argdata, 1, 5, &func);
}

void WarningMessage::Start()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func590::func;
	return execfunc(this);
}

namespace _func591
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::RenderWithAlpha", typeid(void (WarningMessage::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cb81ec8c0000008079", argdata, 2, 5, &func);
}

void WarningMessage::RenderWithAlpha(float alpha)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func591::func;
	return execfunc(this, alpha);
}

namespace _func592
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::OnLoop", typeid(void (WarningMessage::*)()), "578d7c240883e4f0ff77fc5589e557568d7104", argdata, 1, 5, &func);
}

void WarningMessage::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func592::func;
	return execfunc(this);
}

namespace _func593
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff};
	static FunctionDefinition funcObj("WarningMessage::SetPosition", typeid(void (WarningMessage::*)(Point )), "578d7c240883e4f0ff77fc5589e55783ec14807928", argdata, 2, 5, &func);
}

void WarningMessage::SetPosition(Point position)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, Point position_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func593::func;
	return execfunc(this, position);
}

namespace _func594
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetLoop", typeid(void (WarningMessage::*)(bool )), "5783c1048d7c240883e4f0ff77fc5589", argdata, 2, 5, &func);
}

void WarningMessage::SetLoop(bool loop)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, bool loop_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func594::func;
	return execfunc(this, loop);
}

namespace _func595
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::SetSound", typeid(void (WarningMessage::*)(const std::string &)), "5781c1c80000008d7c240883e4f0ff77", argdata, 2, 5, &func);
}

void WarningMessage::SetSound(const std::string &sound)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const std::string &sound_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func595::func;
	return execfunc(this, sound);
}

namespace _func596
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WarningMessage::OnRender", typeid(void (WarningMessage::*)()), "80791600754a807914007444578d7c24", argdata, 1, 5, &func);
}

void WarningMessage::OnRender()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func596::func;
	return execfunc(this);
}

namespace _func597
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x2ff, 0x1ff, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WarningMessage::InitText", typeid(void (WarningMessage::*)(const TextString &, Point , float , GL_Color , bool , bool )), "578d7c240883e4f0ff77fc5589e557565389cb8d492c", argdata, 7, 5, &func);
}

void WarningMessage::InitText(const TextString &text, Point position, float time, GL_Color textColor, bool centerText, bool flash)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WarningMessage *this_arg, const TextString &text_arg, Point position_arg, float time_arg, GL_Color textColor_arg, bool centerText_arg, bool flash_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func597::func;
	return execfunc(this, text, position, time, textColor, centerText, flash);
}

namespace _func598
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SaveState", typeid(void (WeaponAnimation::*)(int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b37893424e890af15008d", argdata, 2, 5, &func);
}

void WeaponAnimation::SaveState(int fd)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, int fd_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func598::func;
	return execfunc(this, fd);
}

namespace _func599
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SetBoostLevel", typeid(void (WeaponAnimation::*)(int )), "578d7c240883e4f0ff77fc5589e55783ec1480b9cd000000008b", argdata, 2, 5, &func);
}

void WeaponAnimation::SetBoostLevel(int value)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, int value_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func599::func;
	return execfunc(this, value);
}

namespace _func600
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SetFireTime", typeid(void (WeaponAnimation::*)(float )), "8b5104660fefc0660fefc989d02b81d4", argdata, 2, 5, &func);
}

void WeaponAnimation::SetFireTime(float time)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float time_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func600::func;
	return execfunc(this, time);
}

namespace _func601
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponAnimation::GetSlide", typeid(Pointf (WeaponAnimation::*)()), "578d7c240883e4f0ff77fc5589e5575389cb81c104", argdata, 1, 9, &func);
}

Pointf WeaponAnimation::GetSlide()
{
	typedef Pointf __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func601::func;
	return execfunc(this);
}

namespace _func602
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SetPowered", typeid(void (WeaponAnimation::*)(bool )), "578d7c240883e4f0ff77fc5589e5575389cb83ec2080b9e8", argdata, 2, 5, &func);
}

void WeaponAnimation::SetPowered(bool powered)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, bool powered_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func602::func;
	return execfunc(this, powered);
}

namespace _func603
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::SetChargedLevel", typeid(void (WeaponAnimation::*)(float )), "578d7c240883e4f0ff77fc5589e55783ec1480b9cd00000000f3", argdata, 2, 5, &func);
}

void WeaponAnimation::SetChargedLevel(float charged)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float charged_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func603::func;
	return execfunc(this, charged);
}

namespace _func604
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponAnimation::GetFireLocation", typeid(Point (WeaponAnimation::*)()), "578d7c240883e4f0ff77fc5589e55783ec248b81f8", argdata, 1, 9, &func);
}

Point WeaponAnimation::GetFireLocation()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func604::func;
	return execfunc(this);
}

namespace _func605
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::OnRender", typeid(void (WeaponAnimation::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cb83ec5cf3", argdata, 2, 5, &func);
}

void WeaponAnimation::OnRender(float alpha)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func605::func;
	return execfunc(this, alpha);
}

namespace _func606
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponAnimation::RenderChargeBar", typeid(void (WeaponAnimation::*)(float )), "578d7c240883e4f0ff77fc5589e557565389cb83ec3ce835", argdata, 2, 5, &func);
}

void WeaponAnimation::RenderChargeBar(float alpha)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponAnimation *this_arg, float alpha_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func606::func;
	return execfunc(this, alpha);
}

namespace _func607
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponBlueprint::GetDimensions", typeid(Point (WeaponBlueprint::*)()), "5781c16c0100008d7c240883e4f0ff77fc5589e55756", argdata, 1, 9, &func);
}

Point WeaponBlueprint::GetDimensions()
{
	typedef Point __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponBlueprint *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func607::func;
	return execfunc(this);
}

namespace _func608
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::LButton", typeid(bool (WeaponControl::*)(int , int , bool )), "578d7c240883e4f0ff77fc5589e557565383ec2c80b9d8000000008b1f", argdata, 4, 1, &func);
}

bool WeaponControl::LButton(int x, int y, bool holdingShift)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, int x_arg, int y_arg, bool holdingShift_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func608::func;
	return execfunc(this, x, y, holdingShift);
}

namespace _func609
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::KeyDown", typeid(bool (WeaponControl::*)(SDLKey )), "578d7c240883e4f0ff77fc5589e557565389ce83ec4c8b3f", argdata, 2, 1, &func);
}

bool WeaponControl::KeyDown(SDLKey key)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, SDLKey key_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func609::func;
	return execfunc(this, key);
}

namespace _func610
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::SelectArmament", typeid(void (WeaponControl::*)(unsigned int )), "578d7c240883e4f0ff77fc5589e557565389ce81ecdc00", argdata, 2, 5, &func);
}

void WeaponControl::SelectArmament(unsigned int armamentSlot)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, unsigned int armamentSlot_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func610::func;
	return execfunc(this, armamentSlot);
}

namespace _func611
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponControl::RenderWarnings", typeid(void (WeaponControl::*)()), "5589e55389cb83e4f083ec10e88f9104", argdata, 1, 5, &func);
}

void WeaponControl::RenderWarnings()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func611::func;
	return execfunc(this);
}

namespace _func612
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WeaponControl::OnLanguageChange", typeid(void (WeaponControl::*)()), "578d7c240883e4f0ff77fc5589e557565389cf8d75b0", argdata, 1, 5, &func);
}

void WeaponControl::OnLanguageChange()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func612::func;
	return execfunc(this);
}

namespace _func613
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::SetAutofiring", typeid(void (WeaponControl::*)(bool , bool )), "578d7c240883e4f0ff77fc5589e557565389ce83ec5c8b078b7f", argdata, 3, 5, &func);
}

void WeaponControl::SetAutofiring(bool on, bool simple)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, bool on_arg, bool simple_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func613::func;
	return execfunc(this, on, simple);
}

namespace _func614
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::LinkShip", typeid(void (WeaponControl::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e5575389cb83ec308b0789", argdata, 2, 5, &func);
}

void WeaponControl::LinkShip(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func614::func;
	return execfunc(this, ship);
}

namespace _func615
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::MouseMove", typeid(void (WeaponControl::*)(int , int )), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b378b7f04893424897c2404e819", argdata, 3, 5, &func);
}

void WeaponControl::MouseMove(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func615::func;
	return execfunc(this, x, y);
}

namespace _func616
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::OnRender", typeid(void (WeaponControl::*)(bool )), "578d7c240883e4f0ff77fc5589e557565389cb83ec2c8b490c", argdata, 2, 5, &func);
}

void WeaponControl::OnRender(bool unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponControl *this_arg, bool unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func616::func;
	return execfunc(this, unk);
}

namespace _func617
{
    static void *func = 0;
	static short argdata[] = {0x2ff, 0x2ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponControl::RenderBeamAiming", typeid(void (*)(Pointf , Pointf , bool )), "8d4c240483e4f0ff71fc5589e55756535189cf81", argdata, 3, 6, &func);
}

void WeaponControl::RenderBeamAiming(Pointf one, Pointf two, bool bAutoFire)
{
	typedef void __attribute__((cdecl)) (*custom_arg_funcptr_t)(Pointf one_arg, Pointf two_arg, bool bAutoFire_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func617::func;
	return execfunc(one, two, bAutoFire);
}

namespace _func618
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x2ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WeaponSystemBox::constructor", typeid(void (WeaponSystemBox::*)(Point , ShipSystem *, WeaponControl *)), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b57048b4f088b7f0cc7", argdata, 4, 5, &func);
}

void WeaponSystemBox::constructor(Point pos, ShipSystem *sys, WeaponControl *weapCtrl)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WeaponSystemBox *this_arg, Point pos_arg, ShipSystem *sys_arg, WeaponControl *weapCtrl_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func618::func;
	return execfunc(this, pos, sys, weapCtrl);
}

namespace _func619
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::Draw", typeid(void (WindowFrame::*)(int , int )), "5589e55389cb83e4f083ec10e89fd501", argdata, 3, 5, &func);
}

void WindowFrame::Draw(int x, int y)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WindowFrame *this_arg, int x_arg, int y_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func619::func;
	return execfunc(this, x, y);
}

namespace _func620
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WindowFrame::DrawMask", typeid(void (WindowFrame::*)(int )), "5589e55389cb83e4f083ec108b4508c7042401", argdata, 2, 5, &func);
}

void WindowFrame::DrawMask(int unk)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WindowFrame *this_arg, int unk_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func620::func;
	return execfunc(this, unk);
}

namespace _func621
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WindowFrame::destructor", typeid(void (WindowFrame::*)()), "5589e55389cb83e4f083ec108b411089", argdata, 1, 5, &func);
}

void WindowFrame::destructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WindowFrame *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func621::func;
	return execfunc(this);
}

namespace _func622
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::constructor", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e5575389cb8d490883ec10c741f800", argdata, 1, 5, &func);
}

void WorldManager::constructor()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func622::func;
	return execfunc(this);
}

namespace _func623
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnInit", typeid(int (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557568d7108", argdata, 1, 1, &func);
}

int WorldManager::OnInit()
{
	typedef int __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func623::func;
	return execfunc(this);
}

namespace _func624
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateShip", typeid(CompleteShip *(WorldManager::*)(ShipEvent *, bool )), "578d7c240883e4f0ff77fc5589e557565389ce81ec8c04", argdata, 3, 1, &func);
}

CompleteShip *WorldManager::CreateShip(ShipEvent *shipEvent, bool boss)
{
	typedef CompleteShip *__attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, ShipEvent *shipEvent_arg, bool boss_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func624::func;
	return execfunc(this, shipEvent, boss);
}

namespace _func625
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::ClearLocation", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389cb83c10881", argdata, 1, 5, &func);
}

void WorldManager::ClearLocation()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func625::func;
	return execfunc(this);
}

namespace _func626
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyEnvironment", typeid(void (WorldManager::*)(int , int )), "578d7c240883e4f0ff77fc5589e5575389cb83ec108b078b570483", argdata, 3, 5, &func);
}

void WorldManager::ModifyEnvironment(int envFlag, int envTarget)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, int envFlag_arg, int envTarget_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func626::func;
	return execfunc(this, envFlag, envTarget);
}

namespace _func627
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x4ff, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyStatusEffect", typeid(void (WorldManager::*)(StatusEffect , ShipManager *, int )), "578d7c240883e4f0ff77fc5589f889e557565383ec5c8b70", argdata, 4, 5, &func);
}

void WorldManager::ModifyStatusEffect(StatusEffect effect, ShipManager *target, int targetType)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, StatusEffect effect_arg, ShipManager *target_arg, int targetType_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func627::func;
	return execfunc(this, effect, target, targetType);
}

namespace _func628
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::StartGame", typeid(void (WorldManager::*)(ShipManager *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec4c8b09", argdata, 2, 5, &func);
}

void WorldManager::StartGame(ShipManager *ship)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, ShipManager *ship_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func628::func;
	return execfunc(this, ship);
}

namespace _func629
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::Restart", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e5575389cb83ec10e816a2", argdata, 1, 5, &func);
}

void WorldManager::Restart()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func629::func;
	return execfunc(this);
}

namespace _func630
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::HostileEnvironment", typeid(bool (WorldManager::*)()), "5589e55389cb83c10883e4f0e8bf5be0", argdata, 1, 1, &func);
}

bool WorldManager::HostileEnvironment()
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func630::func;
	return execfunc(this);
}

namespace _func631
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::UpdateLocation", typeid(void (WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b018b378b48088b018b40443d????????7527", argdata, 2, 5, &func);
}

void WorldManager::UpdateLocation(LocationEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func631::func;
	return execfunc(this, event);
}

namespace _func632
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckRequirements", typeid(bool (WorldManager::*)(LocationEvent *, bool )), "578d7c240883e4f0ff77fc5589e557565383ec4c8b3785", argdata, 3, 1, &func);
}

bool WorldManager::CheckRequirements(LocationEvent *event, bool hidden)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg, bool hidden_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func632::func;
	return execfunc(this, event, hidden);
}

namespace _func633
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateLocation", typeid(void (WorldManager::*)(Location *)), "578d7c240883e4f0ff77fc5589e557565389ce81ecfc04", argdata, 2, 5, &func);
}

void WorldManager::CreateLocation(Location *loc)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, Location *loc_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func633::func;
	return execfunc(this, loc);
}

namespace _func634
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::AddBoarders", typeid(bool (WorldManager::*)(BoardingEvent &)), "578d7c240883e4f0ff77fc5589e557565381ec5c0100008b07", argdata, 2, 1, &func);
}

bool WorldManager::AddBoarders(BoardingEvent &boardingEvent)
{
	typedef bool __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, BoardingEvent &boardingEvent_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func634::func;
	return execfunc(this, boardingEvent);
}

namespace _func635
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CreateChoiceBox", typeid(void (WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565389cb83ec1c8b018b378b48088b018b40443d????????752a", argdata, 2, 5, &func);
}

void WorldManager::CreateChoiceBox(LocationEvent *event)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func635::func;
	return execfunc(this, event);
}

namespace _func636
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::OnLoop", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce81eccc00", argdata, 1, 5, &func);
}

void WorldManager::OnLoop()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func636::func;
	return execfunc(this);
}

namespace _func637
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::CheckStatusEffects", typeid(void (WorldManager::*)(std::vector<StatusEffect> &)), "578d911c1200008d7c240883e4f0ff77", argdata, 2, 5, &func);
}

void WorldManager::CheckStatusEffects(std::vector<StatusEffect> &vec)
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, std::vector<StatusEffect> &vec_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func637::func;
	return execfunc(this, vec);
}

namespace _func638
{
    static void *func = 0;
	static short argdata[] = {0x101};
	static FunctionDefinition funcObj("WorldManager::CreateNewGame", typeid(void (WorldManager::*)()), "578d7c240883e4f0ff77fc5589e557565389ce8d5dd8", argdata, 1, 5, &func);
}

void WorldManager::CreateNewGame()
{
	typedef void __attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func638::func;
	return execfunc(this);
}

namespace _func639
{
    static void *func = 0;
	static short argdata[] = {0x101, 0x1ff};
	static FunctionDefinition funcObj("WorldManager::ModifyResources", typeid(LocationEvent *(WorldManager::*)(LocationEvent *)), "578d7c240883e4f0ff77fc5589e557565389cb8d8d2c", argdata, 2, 1, &func);
}

LocationEvent *WorldManager::ModifyResources(LocationEvent *event)
{
	typedef LocationEvent *__attribute__((thiscall)) (*custom_arg_funcptr_t)(WorldManager *this_arg, LocationEvent *event_arg);
	custom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func639::func;
	return execfunc(this, event);
}

