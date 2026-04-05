#pragma once

#pragma warning( disable : 4722 )

#define LIBZHL_API 

#ifdef SWIG
    #define LIBZHL_INTERFACE
    #define __stdcall
    #define LIBZHL_PLACEHOLDER {(void)0;}
    #define __attribute__(x)
#elif defined(_WIN32)
    #define LIBZHL_INTERFACE __declspec(novtable)
    __declspec(noreturn) inline void __cdecl __NOP() {}
    #define LIBZHL_PLACEHOLDER {__NOP();}
#elif defined(__linux__)
    #define LIBZHL_INTERFACE
    #define LIBZHL_PLACEHOLDER {\
        _Pragma("GCC diagnostic push") \
        _Pragma("GCC diagnostic ignored \"-Wreturn-type\"") \
        (void)0; } \
        _Pragma("GCC diagnostic pop")
    #define __stdcall
#endif


#include <windows.h>
#include "zhl.h"
#include "rapidxml.hpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <deque>
#include <stdarg.h>
#include <unordered_map>
#include <math.h>
#include <queue>
#include <cstdint>
#include <array>
#undef LoadImage

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

struct CAchievement;
struct RandomAmount;
struct Point;

typedef std::pair<int, int> std_pair_int_int;
typedef std::pair<float, float> std_pair_float_float;
typedef std::pair<std::string, int> std_pair_std_string_int;
typedef std::pair<std::string, RandomAmount> std_pair_std_string_RandomAmount;
typedef std::pair<std::string, std::string> std_pair_std_string_std_string;
typedef std::pair<CAchievement*, Point> std_pair_CAchievement_ptr_Point;
typedef std::map<std::string, std::string> std_map_std_string_std_string;
typedef std::map<std::string, int> std_map_std_string_int;
typedef std::map<std::string, bool> std_map_std_string_bool;




struct CAchievement;

struct CachedImage;

struct CachedPrimitive;
struct GL_Primitive;

struct CachedPrimitive
{
	LIBZHL_API void destructor();
	
	void *vptr;
	GL_Primitive *primitive;
};

struct GL_Texture;

struct CachedImage : CachedPrimitive
{
	LIBZHL_API void SetImagePath(const std::string &imagePath);
	LIBZHL_API void SetMirrored(bool _mirrored);
	LIBZHL_API void SetPartial(float x_start, float y_start, float x_size, float y_size);
	LIBZHL_API void SetPosition(int x, int y);
	LIBZHL_API void SetRotation(float _rotation);
	LIBZHL_API void SetScale(float wScale, float hScale);
	LIBZHL_API void constructor2(const std::string &path, CachedImage::Centered centered);
	LIBZHL_API void constructor_copy(const CachedImage &other);
	
	std::string imageName;
	GL_Texture *texture;
	int x;
	int y;
	float wScale;
	float hScale;
	float x_start;
	float y_start;
	float x_size;
	float y_size;
	float rotation;
	bool mirrored;
};

struct Point
{
	LIBZHL_API int RelativeDistance(Point other);
	
	int x;
	int y;
};

struct TextString;

struct TextString
{
	LIBZHL_API std::string GetText();
	
	std::string data;
	bool isLiteral;
	uint8_t gap_ex[3];
};

struct CAchievement
{
	LIBZHL_API void OnRender(Point pos, int selected, bool showNew);
	LIBZHL_API void constructor();
	
	std::string name_id;
	std::pair<int, int> progress;
	bool unlocked;
	int8_t gap_ex_custom;
	TextString name;
	TextString description;
	TextString header;
	bool newAchievement;
	bool multiDifficulty;
	int difficulty;
	std::string ship;
	int shipDifficulties[3];
	int dimension;
	CachedImage icon;
	CachedImage miniIcon;
	CachedImage miniIconLocked;
	CachedImage lockImage;
	CachedImage dotOn;
	CachedImage dotOff;
	GL_Primitive *outline;
	GL_Primitive *mini_outline;
	GL_Primitive *lockOverlay;
};

struct RandomAmount
{
	int min;
	int max;
	float chanceNone;
};
	
enum TouchAction
{
  TOUCH_DOWN = 0x1,
  TOUCH_MOVE = 0x2,
  TOUCH_UP = 0x3,
  TOUCH_CANCEL = 0x4,
};

enum InputEventType
{
  INPUT_EVENT_JOYSTICK = 0x1,
  INPUT_EVENT_KEYBOARD = 0x2,
  INPUT_EVENT_MEMORY = 0x3,
  INPUT_EVENT_MOUSE = 0x4,
  INPUT_EVENT_TEXT = 0x5,
  INPUT_EVENT_TOUCH = 0x6,
};

enum InputEventDetail
{
  INPUT_JOYSTICK_CONNECTED = 0x1,
  INPUT_JOYSTICK_DISCONNECTED = 0x2,
  INPUT_JOYSTICK_BUTTON_DOWN = 0x3,
  INPUT_JOYSTICK_BUTTON_UP = 0x4,
  INPUT_JOYSTICK_DPAD_CHANGE = 0x5,
  INPUT_JOYSTICK_STICK_CHANGE = 0x6,
  INPUT_KEYBOARD_KEY_DOWN = 0x7,
  INPUT_KEYBOARD_KEY_UP = 0x8,
  INPUT_KEYBOARD_SYSTEM_KEY_DOWN = 0x9,
  INPUT_KEYBOARD_SYSTEM_KEY_UP = 0xA,
  INPUT_MEMORY_LOW = 0xB,
  INPUT_MOUSE_MOVE = 0xC,
  INPUT_MOUSE_LMB_DOWN = 0xD,
  INPUT_MOUSE_LMB_UP = 0xE,
  INPUT_MOUSE_MMB_DOWN = 0xF,
  INPUT_MOUSE_MMB_UP = 0x10,
  INPUT_MOUSE_RMB_DOWN = 0x11,
  INPUT_MOUSE_RMB_UP = 0x12,
  INPUT_MOUSE_SCROLL_H = 0x13,
  INPUT_MOUSE_SCROLL_V = 0x14,
  INPUT_TEXT_INPUT = 0x15,
  INPUT_TEXT_DONE = 0x16,
  INPUT_TEXT_CANCELLED = 0x17,
  INPUT_TEXT_CLEAR = 0x18,
  INPUT_TEXT_BACKSPACE = 0x19,
  INPUT_TEXT_DELETE = 0x1A,
  INPUT_TEXT_CURSOR_LEFT = 0x1B,
  INPUT_TEXT_CURSOR_RIGHT = 0x1C,
  INPUT_TEXT_CURSOR_HOME = 0x1D,
  INPUT_TEXT_CURSOR_END = 0x1E,
  INPUT_TOUCH_DOWN = 0x1F,
  INPUT_TOUCH_MOVE = 0x20,
  INPUT_TOUCH_UP = 0x21,
  INPUT_TOUCH_CANCEL = 0x22,
};

enum DeleteType
{
  BUFFER = 0x1,
  FRAMEBUFFER = 0x2,
  PROGRAM = 0x3,
  PROGRAM_PIPELINE = 0x4,
  RENDERBUFFER = 0x5,
  SHADER = 0x6,
  TEXTURE = 0x7,
  VERTEX_ARRAY = 0x8,
};

enum FontAlignment
{
  FONT_ALIGN_LEFT = 0x0,
  FONT_ALIGN_CENTER = 0x1,
  FONT_ALIGN_RIGHT = 0x2,
};

enum FramebufferColorType
{
  FBCOLOR_RGB8 = 0x1,
  FBCOLOR_RGBA8 = 0x2,
};

enum GL_StencilMode
{
  STENCIL_IGNORE = 0x0,
  STENCIL_SET = 0x1,
  STENCIL_USE = 0x2,
};

enum ResourceType
{
  RES_UNUSED = 0x0,
  RES_UNKNOWN = 0x1,
  RES_DATA = 0x2,
  RES_TEXTURE = 0x3,
  RES_FONT = 0x4,
  RES_SOUND = 0x5,
  RES_FILE = 0x6,
};


enum SDLKey
{
  SDLK_UNKNOWN = 0x0,
  SDLK_0 = 0x30,
  SDLK_1 = 0x31,
  SDLK_2 = 0x32,
  SDLK_3 = 0x33,
  SDLK_4 = 0x34,
  SDLK_5 = 0x35,
  SDLK_6 = 0x36,
  SDLK_7 = 0x37,
  SDLK_8 = 0x38,
  SDLK_9 = 0x39,
  SDLK_AT = 0x40,
  SDLK_AMPERSAND = 0x26,
  SDLK_ASTERISK = 0x2A,
  SDLK_BACKQUOTE = 0x60,
  SDLK_BACKSLASH = 0x5C,
  SDLK_BACKSPACE = 0x8,
  SDLK_BREAK = 0x13E,
  SDLK_CAPSLOCK = 0x12D,
  SDLK_CARET = 0x5E,
  SDLK_CLEAR = 0xC,
  SDLK_COLON = 0x3A,
  SDLK_COMMA = 0x2C,
  SDLK_COMPOSE = 0x13A,
  SDLK_DELETE = 0x7F,
  SDLK_DOLLAR = 0x24,
  SDLK_DOWN = 0x112,
  SDLK_END = 0x117,
  SDLK_EQUALS = 0x3D,
  SDLK_ESCAPE = 0x1B,
  SDLK_EURO = 0x141,
  SDLK_EXCLAIM = 0x21,
  SDLK_F1 = 0x11A,
  SDLK_F10 = 0x123,
  SDLK_F11 = 0x124,
  SDLK_F12 = 0x125,
  SDLK_F13 = 0x126,
  SDLK_F14 = 0x127,
  SDLK_F15 = 0x128,
  SDLK_F2 = 0x11B,
  SDLK_F3 = 0x11C,
  SDLK_F4 = 0x11D,
  SDLK_F5 = 0x11E,
  SDLK_F6 = 0x11F,
  SDLK_F7 = 0x120,
  SDLK_F8 = 0x121,
  SDLK_F9 = 0x122,
  SDLK_GREATER = 0x3E,
  SDLK_HASH = 0x24,
  SDLK_HELP = 0x13B,
  SDLK_HOME = 0x116,
  SDLK_INSERT = 0x115,
  SDLK_KP0 = 0x100,
  SDLK_KP1 = 0x101,
  SDLK_KP2 = 0x102,
  SDLK_KP3 = 0x103,
  SDLK_KP4 = 0x104,
  SDLK_KP5 = 0x105,
  SDLK_KP6 = 0x106,
  SDLK_KP7 = 0x107,
  SDLK_KP8 = 0x108,
  SDLK_KP9 = 0x109,
  SDLK_KP_PERIOD = 0x10A,
  SDLK_KP_DIVIDE = 0x10B,
  SDLK_KP_MULTIPLY = 0x10C,
  SDLK_KP_MINUS = 0x10D,
  SDLK_KP_PLUS = 0x10E,
  SDLK_KP_ENTER = 0x10F,
  SDLK_KP_EQUALS = 0x110,
  SDLK_LALT = 0x134,
  SDLK_LCTRL = 0x132,
  SDLK_LEFT = 0x114,
  SDLK_LEFTBRACKET = 0x5B,
  SDLK_LEFTPAREN = 0x28,
  SDLK_LESS = 0x3C,
  SDLK_LMETA = 0x136,
  SDLK_LSHIFT = 0x130,
  SDLK_LSUPER = 0x137,
  SDLK_MENU = 0x13F,
  SDLK_MINUS = 0x2D,
  SDLK_MODE = 0x139,
  SDLK_NUMLOCK = 0x12C,
  SDLK_PAGEDOWN = 0x119,
  SDLK_PAGEUP = 0x118,
  SDLK_PAUSE = 0x13,
  SDLK_PERIOD = 0x2E,
  SDLK_PLUS = 0x2B,
  SDLK_POWER = 0x140,
  SDLK_PRINTSCREEN = 0x13C,
  SDLK_QUESTION = 0x3F,
  SDLK_QUOTEDBL = 0x22,
  SDLK_QUOTE = 0x27,
  SDLK_RALT = 0x133,
  SDLK_RCTRL = 0x131,
  SDLK_RETURN = 0xD,
  SDLK_RIGHT = 0x113,
  SDLK_RIGHTBRACKET = 0x5D,
  SDLK_RIGHTPAREN = 0x29,
  SDLK_RMETA = 0x135,
  SDLK_RSHIFT = 0x12F,
  SDLK_RSUPER = 0x138,
  SDLK_SCROLLOCK = 0x12E,
  SDLK_SEMICOLON = 0x3B,
  SDLK_SLASH = 0x2F,
  SDLK_SPACE = 0x20,
  SDLK_SYSREQ = 0x13D,
  SDLK_TAB = 0x9,
  SDLK_UNDERSCORE = 0x5F,
  SDLK_UNDO = 0x142,
  SDLK_UP = 0x111,
  SDLK_a = 0x61,
  SDLK_b = 0x62,
  SDLK_c = 0x63,
  SDLK_d = 0x64,
  SDLK_e = 0x65,
  SDLK_f = 0x66,
  SDLK_g = 0x67,
  SDLK_h = 0x68,
  SDLK_i = 0x69,
  SDLK_j = 0x6A,
  SDLK_k = 0x6B,
  SDLK_l = 0x6C,
  SDLK_m = 0x6D,
  SDLK_n = 0x6E,
  SDLK_o = 0x6F,
  SDLK_p = 0x70,
  SDLK_q = 0x71,
  SDLK_r = 0x72,
  SDLK_s = 0x73,
  SDLK_t = 0x74,
  SDLK_u = 0x75,
  SDLK_v = 0x76,
  SDLK_w = 0x77,
  SDLK_x = 0x78,
  SDLK_y = 0x79,
  SDLK_z = 0x7A,
  SDLK_LAST = 0x143,
};

enum ShaderType
{
  SHADER_TYPE_VERTEX = 0x0,
  SHADER_TYPE_FRAGMENT = 0x1,
};

enum GraphicsPrimitiveType
{
  GRAPHICS_PRIMITIVE_POINTS = 0x1,
  GRAPHICS_PRIMITIVE_LINES = 0x2,
  GRAPHICS_PRIMITIVE_LINE_STRIP = 0x3,
  GRAPHICS_PRIMITIVE_TRIANGLES = 0x4,
  GRAPHICS_PRIMITIVE_TRIANGLE_STRIP = 0x5,
  GRAPHICS_PRIMITIVE_QUADS = 0x6,
  GRAPHICS_PRIMITIVE_QUAD_STRIP = 0x7,
};

enum GraphicsTextureColorType
{
  GRAPHICS_TEXCOLOR_NONE = 0x0,
  GRAPHICS_TEXCOLOR_RGBA = 0x1,
  GRAPHICS_TEXCOLOR_A = 0x2,
  GRAPHICS_TEXCOLOR_L = 0x3,
};

enum GraphicsComparisonType
{
  GRAPHICS_COMPARISON_FALSE = 0x0,
  GRAPHICS_COMPARISON_TRUE = 0x1,
  GRAPHICS_COMPARISON_EQUAL = 0x2,
  GRAPHICS_COMPARISON_NOT_EQUAL = 0x3,
  GRAPHICS_COMPARISON_LESS = 0x4,
  GRAPHICS_COMPARISON_LESS_EQUAL = 0x5,
  GRAPHICS_COMPARISON_GREATER_EQUAL = 0x6,
  GRAPHICS_COMPARISON_GREATER = 0x7,
};

typedef char *ShaderSourceCallback(GraphicsPrimitiveType, int, int, GraphicsTextureColorType, int, int, int, int, int, GraphicsComparisonType);

static DWORD GetBaseAddress()
{
	return (DWORD)GetModuleHandle(NULL);
}


struct AchievementTracker;

struct AnimationTracker;

struct LIBZHL_INTERFACE AnimationTracker
{
	virtual ~AnimationTracker() {}
	LIBZHL_API virtual void Update();
	LIBZHL_API float Progress(float speed);
	LIBZHL_API void SetLoop(bool loop, float loopDelay);
	LIBZHL_API void SetProgress(float time);
	LIBZHL_API void Start(float time);
	LIBZHL_API void StartReverse(float time);
	LIBZHL_API void Stop(bool resetTime);
	
	float time;
	bool loop;
	float current_time;
	bool running;
	bool reverse;
	bool done;
	float loopDelay;
	float currentDelay;
};

struct AchievementTracker
{
	LIBZHL_API void LoadAchievementDescriptions();
	LIBZHL_API void SetAchievement(const std::string &achievement, bool noPopup, bool sendToServer);
	LIBZHL_API void SetFlag(const std::string &flagName);
	LIBZHL_API void SetSectorEight();
	LIBZHL_API void SetVictoryAchievement();
	
	std::vector<CAchievement*> recentlyUnlocked;
	std::vector<std::vector<CAchievement*>> shipUnlocks;
	std::vector<CAchievement*> achievements;
	std::map<std::string, int> gameFlags;
	AnimationTracker achievementPopup;
	GL_Primitive *popupBox;
	GL_Primitive *achievementBox[2];
	GL_Primitive *achievementOverlay[2];
	std::string currentShip;
};

struct Algae
{
};

struct AnaerobicAlien
{
};

struct AnaerobicAnimation
{
};

struct Animation;

struct AnimationDescriptor
{
	int numFrames;
	int imageWidth;
	int imageHeight;
	int stripStartY;
	int stripStartX;
	int frameWidth;
	int frameHeight;
};

struct GL_Color
{
	float r;
	float g;
	float b;
	float a;
};

struct Pointf
{
	float x;
	float y;
};

struct Animation
{
	LIBZHL_API void AddSoundQueue(int frame, const std::string &sound);
	LIBZHL_API bool Done();
	LIBZHL_API void LoadState(int fd);
	LIBZHL_API void OnRender(float opacity, GL_Color color, bool mirror);
	LIBZHL_API int RandomStart();
	LIBZHL_API void SaveState(int fd);
	LIBZHL_API void SetCurrentFrame(int frame);
	LIBZHL_API void Start(bool reset);
	LIBZHL_API void Update();
	
	GL_Texture *animationStrip;
	AnimationDescriptor info;
	AnimationTracker tracker;
	Pointf position;
	std::string soundForward;
	std::string soundReverse;
	bool randomizeFrames;
	float fScale;
	float fYStretch;
	int currentFrame;
	bool bAlwaysMirror;
	std::vector<std::vector<std::string>> soundQueue;
	float fadeOut;
	float startFadeOut;
	std::string animName;
	int mask_x_pos;
	int mask_x_size;
	int mask_y_pos;
	int mask_y_size;
	GL_Primitive *primitive;
	GL_Primitive *mirroredPrimitive;
};

struct AnimationSheet
{
	int w;
	int h;
	int frameHeight;
	int frameWidth;
	GL_Texture *imageId;
};

struct WeaponAnimation;

struct WeaponMount
{
	Point position;
	bool mirror;
	bool rotate;
	int slide;
	int gib;
};

struct WeaponAnimation
{
	LIBZHL_API Point GetFireLocation();
	LIBZHL_API Pointf GetSlide();
	LIBZHL_API void OnRender(float alpha);
	LIBZHL_API void RenderChargeBar(float alpha);
	LIBZHL_API void SaveState(int fd);
	LIBZHL_API void SetBoostLevel(int value);
	LIBZHL_API void SetChargedLevel(float charged);
	LIBZHL_API void SetFireTime(float time);
	LIBZHL_API void SetPowered(bool powered);
	
	Animation anim;
	bool bFireShot;
	bool bFiring;
	float fChargeLevel;
	int iChargedFrame;
	int iFireFrame;
	bool bMirrored;
	bool bRotation;
	Point fireLocation;
	bool bPowered;
	Point mountPoint;
	Point renderPoint;
	Point fireMountVector;
	AnimationTracker slideTracker;
	int slideDirection;
	CachedImage iChargeImage;
	Animation explosionAnim;
	WeaponMount mount;
	float fDelayChargeTime;
	Animation boostAnim;
	int boostLevel;
	bool bShowCharge;
	float fActualChargeLevel;
	int iChargeOffset;
	int iChargeLevels;
	int currentOffset;
	CachedImage chargeBox;
	CachedImage chargeBar;
	int iHackLevel;
	Animation hackSparks;
	bool playerShip;
};

struct AnimationControl
{
	std::map<std::string, AnimationSheet> animSheets;
	std::map<std::string, Animation> animations;
	std::map<std::string, WeaponAnimation> weapAnimations;
};

struct ArmamentBox;

struct GenericButton;

struct Globals
{
	struct Ellipse
	{
		Point center;
		float a;
		float b;
	};
	
	struct Rect
	{
		int x;
		int y;
		int w;
		int h;
	};
	
	LIBZHL_API static Pointf __stdcall GetNextPoint(Pointf current, float mag_speed, Pointf dest);
	LIBZHL_API static int __stdcall GetNextSpaceId();
	
};

struct TouchTooltip;

struct LIBZHL_INTERFACE ArmamentBox
{
	virtual ~ArmamentBox() {}
	virtual bool Empty() LIBZHL_PLACEHOLDER
	virtual std::string Name() LIBZHL_PLACEHOLDER
	virtual bool Powered() LIBZHL_PLACEHOLDER
	virtual void SetDefaultAutofire(bool val) LIBZHL_PLACEHOLDER
	virtual int RealRequiredPower() LIBZHL_PLACEHOLDER
	virtual int GetBonusPower() LIBZHL_PLACEHOLDER
	virtual std::string GetType() LIBZHL_PLACEHOLDER
	virtual GL_Color StatusColor() LIBZHL_PLACEHOLDER
	virtual std::string GenerateTooltip() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void RenderTouchTooltip(int spaceToTop) LIBZHL_PLACEHOLDER
	virtual void OnRender(bool dragging, bool flashPowerBox) LIBZHL_PLACEHOLDER
	virtual void RenderBox(bool dragging, bool flashPowerBox) LIBZHL_PLACEHOLDER
	virtual void RenderLabels() LIBZHL_PLACEHOLDER
	virtual void RenderIcon(Point &p) LIBZHL_PLACEHOLDER
	std::vector<GL_Primitive*> background;
	GL_Primitive *emptyBackground;
	GL_Primitive *hoverHighlight;
	GL_Primitive *outline;
	GL_Primitive *emptyOutline;
	GL_Primitive *powerBarGlow[4];
	GL_Primitive *iconBackground;
	GL_Primitive *iconInsetBackground;
	GL_Primitive *icon;
	GL_Primitive *iconDoubleSize;
	std::string iconName;
	std::string iconBackgroundName;
	Point lastIconPos;
	Point location;
	int xOffset;
	Point largeIconOffset;
	Point nameOffset;
	int nameWidth;
	bool mouseHover;
	bool touchHover;
	bool touchHighlight;
	bool selected;
	int hotKey;
	int activeTouch;
	TouchTooltip *touchTooltip;
	Animation hackAnimation;
	GL_Primitive *touchButtonBorder;
	Globals::Rect touchButtonBorderRect;
	float touchButtonSlidePos;
	std::vector<GenericButton*> touchButtons;
	Globals::Rect touchButtonHitbox;
	GL_Color iconColor;
	bool droneVariation;
	bool bIoned;
};

struct ArmamentControl;
struct CommandGui;

struct ShipManager;

struct LIBZHL_INTERFACE ArmamentControl
{
	virtual ~ArmamentControl() {}
	virtual void OnLanguageChange() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender(bool front) LIBZHL_PLACEHOLDER
	virtual void RenderTouchTooltips() LIBZHL_PLACEHOLDER
	virtual void RenderLabels() LIBZHL_PLACEHOLDER
	virtual void RenderWarnings() LIBZHL_PLACEHOLDER
	virtual void RenderDragging() LIBZHL_PLACEHOLDER
	virtual bool IsDragging() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual void OnCleanup() LIBZHL_PLACEHOLDER
	virtual void Close() LIBZHL_PLACEHOLDER
	virtual void SetOpen(bool open) LIBZHL_PLACEHOLDER
	virtual bool LButton(int mX, int mY, bool shift) LIBZHL_PLACEHOLDER
	virtual bool LButtonUp(int mX, int mY, bool shift) LIBZHL_PLACEHOLDER
	virtual void RButton(int mX, int mY, bool shift) LIBZHL_PLACEHOLDER
	virtual void MouseMove(int mX, int mY) LIBZHL_PLACEHOLDER
	virtual bool OnTouch(TouchAction action, int id, int x, int y, int initialX, int initialY) LIBZHL_PLACEHOLDER
	virtual bool KeyDown(SDLKey sym) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void LinkShip(ShipManager *ship);
	virtual ArmamentBox *CreateArmamentBox(Point loc) LIBZHL_PLACEHOLDER
	virtual int NumArmamentSlots() LIBZHL_PLACEHOLDER
	virtual Point ArmamentBoxOrigin() LIBZHL_PLACEHOLDER
	virtual TextString HolderLabel() LIBZHL_PLACEHOLDER
	virtual SDLKey ArmamentHotkey(unsigned int i) LIBZHL_PLACEHOLDER
	virtual void SelectArmament(unsigned int i) LIBZHL_PLACEHOLDER
	virtual void DeselectArmament(unsigned int i) LIBZHL_PLACEHOLDER
	virtual void SwapArmaments(unsigned int a, unsigned int b) LIBZHL_PLACEHOLDER
	LIBZHL_API void CreateHolderTab();
	
	int systemId;
	CommandGui *gui;
	ShipManager *shipManager;
	std::vector<ArmamentBox*> boxes;
	Point location;
	Globals::Rect touchHitBox;
	GL_Texture *holderImage;
	GL_Primitive *holder;
	GL_Primitive *holderTab;
	std::vector<GL_Primitive*> smallBoxHolder;
	std::vector<Animation> smallBoxHackAnim;
	int smallBoxHolderTop;
	bool bOpen;
	Point lastMouse;
	Point currentMouse;
	int draggingBox;
	int draggingTouch;
	bool bDragging;
	int iLastSwapSlot;
	bool bTutorialFlash;
	int iFlashSlot;
	int activeTouch;
};

struct ArrowDescription
{
	Point location;
	float rotation;
	bool upgradesRelative;
	int hostileRelative;
};

struct ArtilleryBox;
struct ArtillerySystem;

struct CooldownSystemBox;

struct ShipSystem;
struct SystemBox;

struct TapBoxFrame
{
	Point location;
	bool useWideBox;
	int boxHeight;
	std::vector<int> buttonHeights;
	std::vector<GL_Primitive*> primitives;
	Globals::Rect hitBox;
};

struct WarningMessage;

struct WarningMessage
{
	LIBZHL_API void InitText(const TextString &text, Point position, float time, GL_Color textColor, bool centerText, bool flash);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void RenderWithAlpha(float alpha);
	LIBZHL_API void SetLoop(bool loop);
	LIBZHL_API void SetPosition(Point position);
	LIBZHL_API void SetSound(const std::string &sound);
	LIBZHL_API void Start();
	
	void *vptr;
	AnimationTracker tracker;
	Point position;
	bool isImage;
	TextString text;
	bool centerText;
	GL_Color textColor;
	bool useWarningLine;
	CachedImage image;
	std::string imageName;
	bool flash;
	std::string sound;
	AnimationTracker flashTracker;
};

struct LIBZHL_INTERFACE SystemBox
{
	virtual void destroy() LIBZHL_PLACEHOLDER
	virtual ~SystemBox() {}
	virtual bool HasButton() LIBZHL_PLACEHOLDER
	virtual int GetCooldownBarHeight() LIBZHL_PLACEHOLDER
	virtual int GetHeightModifier() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void OnRender(bool ignoreStatus);
	virtual bool GetMouseHover() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void MouseMove(int x, int y);
	LIBZHL_API virtual bool MouseClick(bool shift);
	virtual int MouseRightClick(bool unk) LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void CancelTouch() LIBZHL_PLACEHOLDER
	virtual void CloseTapBox() LIBZHL_PLACEHOLDER
	virtual void IsTouchTooltipOpen() LIBZHL_PLACEHOLDER
	virtual void IsTouchTooltipActive() LIBZHL_PLACEHOLDER
	virtual void CloseTouchTooltip(bool unk) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void KeyDown(SDLKey key, bool shift);
	LIBZHL_API void constructor(Point pos, ShipSystem *sys, bool playerUI);
	LIBZHL_API void destructor();
	
	Point location;
	GL_Primitive *timerCircle[10];
	GL_Primitive *timerLines;
	GL_Primitive *timerStencil;
	int lastTimerStencilCount;
	GL_Primitive *brokenIcon;
	GL_Primitive *lockIcon;
	GL_Primitive *hackIcon;
	ShipSystem *pSystem;
	bool bShowPower;
	uint8_t gap_ex_1[3];
	float powerAlpha;
	bool mouseHover;
	uint8_t gap_ex_2[3];
	int activeTouch;
	Point touchInitialOffset;
	bool tapped;
	bool draggingPower;
	int dragInitialPower;
	float lastDragSpeed;
	int lastDragY;
	double lastDragTime;
	WarningMessage warning;
	int topPower;
	Globals::Rect hitBox;
	int hitBoxTop;
	bool hitBoxTopWasSet;
	GL_Texture *wireImage;
	bool bSimplePower;
	bool bPlayerUI;
	bool useLargeTapIcon;
	Point largeTapIconOffset;
	std::vector<int> tapButtonHeights;
	int tapButtonOffsetY;
	int cooldownOffsetY;
	float keyPressed;
	TouchTooltip *touchTooltip;
	TapBoxFrame tapBoxFrame;
	bool lockedOpen;
};

struct CooldownSystemBox : SystemBox
{
	LIBZHL_API void OnRender(bool ignoreStatus);
	
	GL_Primitive *box[5];
	GL_Texture *bar[5];
	Point boxPosition;
	bool roundDown;
	GL_Primitive *barPrimitive;
	int lastBarHeight;
	int lastBarTop;
};

struct ArtilleryBox : CooldownSystemBox
{
	LIBZHL_API void constructor(Point pos, ArtillerySystem *sys);
	
	ArtillerySystem *artSystem;
	Point buttonOffset;
};

struct ProjectileFactory;

struct CachedRect : CachedPrimitive
{
	int x;
	int y;
	int w;
	int h;
};

struct CachedRectOutline : CachedPrimitive
{
	int x;
	int y;
	int w;
	int h;
	int thickness;
};

struct ShipObject;

struct ShipObject
{
	LIBZHL_API void ClearShipInfo();
	LIBZHL_API int GetAugmentationCount();
	LIBZHL_API std::vector<std::string> GetAugmentationList();
	LIBZHL_API float GetAugmentationValue(const std::string &augment);
	LIBZHL_API int HasAugmentation(const std::string &augment);
	LIBZHL_API int HasEquipment(const std::string &equip);
	
	void *vptr;
	int iShipId;
};

struct TimerHelper;

struct TimerHelper
{
	LIBZHL_API bool Done();
	LIBZHL_API void ResetMinMax(int min, int max);
	LIBZHL_API bool Running();
	LIBZHL_API void SetMaxTime(float max);
	LIBZHL_API void Start(int goal);
	LIBZHL_API void Update();
	
	int maxTime;
	int minTime;
	float currTime;
	float currGoal;
	bool loop;
	bool running;
};

struct WeaponBlueprint;

struct LIBZHL_INTERFACE ShipSystem
{
	virtual ~ShipSystem() {}
	virtual void SetSelected(int selectedState) LIBZHL_PLACEHOLDER
	virtual int GetSelected() LIBZHL_PLACEHOLDER
	virtual bool CompletelyDestroyed() LIBZHL_PLACEHOLDER
	virtual std::string *GetName() LIBZHL_PLACEHOLDER
	virtual void SetName(std::string &name) LIBZHL_PLACEHOLDER
	virtual void Repair() LIBZHL_PLACEHOLDER
	virtual bool PartialRepair(float amount, bool unk) LIBZHL_PLACEHOLDER
	virtual bool PartialDamage(float damage) LIBZHL_PLACEHOLDER
	virtual bool NeedsRepairing() LIBZHL_PLACEHOLDER
	virtual bool Functioning() LIBZHL_PLACEHOLDER
	virtual bool CanBeSabotaged() LIBZHL_PLACEHOLDER
	virtual float GetDamage() LIBZHL_PLACEHOLDER
	virtual void *GetLocation() LIBZHL_PLACEHOLDER
	virtual void *GetGridLocation() LIBZHL_PLACEHOLDER
	virtual void SetDamage(float damage) LIBZHL_PLACEHOLDER
	virtual void SetMaxDamage(float maxDamage) LIBZHL_PLACEHOLDER
	virtual void SetLocation(Point pos) LIBZHL_PLACEHOLDER
	virtual void OnRenderHighlight() LIBZHL_PLACEHOLDER
	virtual int GetId() LIBZHL_PLACEHOLDER
	virtual bool IsRoomBased() LIBZHL_PLACEHOLDER
	virtual int GetRoomId() LIBZHL_PLACEHOLDER
	virtual bool Ioned() LIBZHL_PLACEHOLDER
	virtual void SetRoomId() LIBZHL_PLACEHOLDER
	virtual void SetHackingLevel(int level) LIBZHL_PLACEHOLDER
	virtual void ForceBatteryPower(int power) LIBZHL_PLACEHOLDER
	virtual void RemoveBatteryPower() LIBZHL_PLACEHOLDER
	virtual WeaponBlueprint *GetWeaponInfo() LIBZHL_PLACEHOLDER
	virtual std::string *GetOverrideTooltip() LIBZHL_PLACEHOLDER
	virtual void CheckMaxPower() LIBZHL_PLACEHOLDER
	virtual void SetBonusPower(int unk1, int unk2) LIBZHL_PLACEHOLDER
	virtual void AddDamage(int damage) LIBZHL_PLACEHOLDER
	virtual bool ForceDecreasePower(int power) LIBZHL_PLACEHOLDER
	virtual bool ForceIncreasePower(int power) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void StopHacking();
	virtual void OnRender() LIBZHL_PLACEHOLDER
	virtual void OnRenderFloor() LIBZHL_PLACEHOLDER
	virtual void OnRenderEffects() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void OnLoop();
	virtual bool GetNeedsPower() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool Clickable() LIBZHL_PLACEHOLDER
	virtual bool Powered() LIBZHL_PLACEHOLDER
	virtual void ShipDestroyed() LIBZHL_PLACEHOLDER
	LIBZHL_API void AddLock(int lock);
	LIBZHL_API void ClearStatus();
	LIBZHL_API bool DecreasePower(bool force);
	LIBZHL_API int GetEffectivePower();
	LIBZHL_API static std::string __stdcall GetLevelDescription(int systemId, int level, bool tooltip);
	LIBZHL_API TimerHelper GetLockTimer();
	LIBZHL_API bool GetLocked();
	LIBZHL_API int GetPowerCap();
	LIBZHL_API void IonDamage(int amount);
	LIBZHL_API int IsMannedBoost();
	LIBZHL_API void LoadState(int file);
	LIBZHL_API void LockSystem(int lock);
	LIBZHL_API int RenderPowerBoxes(int x, int y, int width, int height, int gap, int heightMod, bool flash);
	LIBZHL_API void SaveState(int file);
	LIBZHL_API void SetDividePower(int val);
	LIBZHL_API static std::string __stdcall SystemIdToName(int systemId);
	LIBZHL_API bool UpgradeSystem(int amount);
	
	int selectedState;
	ShipObject _shipObj;
	float fDamage;
	Point pLoc;
	float fMaxDamage;
	std::string name;
	int roomId;
	int iRepairCount;
	int iSystemType;
	bool bNeedsManned;
	bool bManned;
	uint8_t gap_ex_1[2];
	int iActiveManned;
	bool bBoostable;
	uint8_t gap_ex_2[2];
	std::pair<int, int> powerState;
	int iRequiredPower;
	GL_Texture *imageIcon;
	GL_Primitive *iconPrimitive;
	GL_Primitive *iconBorderPrimitive;
	GL_Primitive *iconPrimitives[20];
	CachedRect partialDamageRect;
	CachedRectOutline lockOutline;
	Globals::Rect roomShape;
	bool bOnFire;
	bool bBreached;
	std::pair<int, int> healthState;
	float fDamageOverTime;
	float fRepairOverTime;
	bool damagedLastFrame;
	bool repairedLastFrame;
	int originalPower;
	bool bNeedsPower;
	int iTempPowerCap;
	int iTempPowerLoss;
	int iTempDividePower;
	int iLockCount;
	TimerHelper lockTimer;
	bool bExploded;
	bool bOccupied;
	bool bFriendlies;
	std::string interiorImageName;
	GL_Primitive *interiorImage;
	GL_Primitive *interiorImageOn;
	GL_Primitive *interiorImageManned;
	GL_Primitive *interiorImageMannedFancy;
	int lastUserPower;
	int iBonusPower;
	int iLastBonusPower;
	Pointf location;
	int bpCost;
	AnimationTracker flashTracker;
	int maxLevel;
	int iBatteryPower;
	int iHackEffect;
	bool bUnderAttack;
	bool bLevelBoostable;
	bool bTriggerIon;
	std::vector<Animation> damagingEffects;
	int computerLevel;
};

struct Targetable;

struct ArtillerySystem : ShipSystem
{
	ProjectileFactory *projectileFactory;
	Targetable *target;
	bool bCloaked;
};

struct Collideable;

struct CollisionResponse
{
	int collision_type;
	Pointf point;
	int damage;
	int superDamage;
};

struct Damage
{
	int iDamage;
	int iShieldPiercing;
	int fireChance;
	int breachChance;
	int stunChance;
	int iIonDamage;
	int iSystemDamage;
	int iPersDamage;
	bool bHullBuster;
	int ownerId;
	int selfId;
	bool bLockdown;
	bool crystalShard;
	bool bFriendlyFire;
	int iStun;
};

struct LIBZHL_INTERFACE Collideable
{
	virtual ~Collideable() {}
	virtual CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace) LIBZHL_PLACEHOLDER
	virtual bool DamageBeam(Pointf current, Pointf last, Damage damage) LIBZHL_PLACEHOLDER
	virtual bool DamageArea(Pointf location, Damage damage, bool forceHit) LIBZHL_PLACEHOLDER
	virtual bool DamageShield(Pointf location, Damage damage, bool forceHit) LIBZHL_PLACEHOLDER
	virtual bool GetDodged() LIBZHL_PLACEHOLDER
	virtual Pointf GetSuperShield() LIBZHL_PLACEHOLDER
	virtual void SetTempVision(Pointf location) LIBZHL_PLACEHOLDER
	virtual int GetSpaceId() LIBZHL_PLACEHOLDER
	virtual int GetSelfId() LIBZHL_PLACEHOLDER
	virtual int GetOwnerId() LIBZHL_PLACEHOLDER
	virtual bool ValidTargetLocation(Pointf location) LIBZHL_PLACEHOLDER
};

struct Projectile;

struct ShieldPower
{
	int first;
	int second;
	std::pair<int, int> super;
};

struct LIBZHL_INTERFACE Targetable
{
	virtual ~Targetable() {}
	virtual Pointf GetWorldCenterPoint() LIBZHL_PLACEHOLDER
	virtual Pointf GetRandomTargettingPoint(bool unk) LIBZHL_PLACEHOLDER
	virtual std::vector<Pointf> GetAllTargettingPoints() LIBZHL_PLACEHOLDER
	virtual Globals::Ellipse GetShieldShape() LIBZHL_PLACEHOLDER
	virtual ShieldPower GetShieldPower() LIBZHL_PLACEHOLDER
	virtual int GetSpaceId() LIBZHL_PLACEHOLDER
	virtual Pointf GetSpeed() LIBZHL_PLACEHOLDER
	virtual int GetOwnerId() LIBZHL_PLACEHOLDER
	virtual int GetSelfId() LIBZHL_PLACEHOLDER
	virtual bool IsCloaked() LIBZHL_PLACEHOLDER
	virtual void DamageTarget(Pointf pos, Damage damage) LIBZHL_PLACEHOLDER
	virtual bool GetIsDying() LIBZHL_PLACEHOLDER
	virtual bool GetIsJumping() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget() LIBZHL_PLACEHOLDER
	virtual Globals::Rect GetShape() LIBZHL_PLACEHOLDER
	int type;
	bool hostile;
	bool targeted;
};

struct LIBZHL_INTERFACE Projectile : Collideable
{
	virtual void SetWeaponAnimation(WeaponAnimation &animation) LIBZHL_PLACEHOLDER
	virtual void OnRenderSpecific(int spaceId) LIBZHL_PLACEHOLDER
	virtual void CollisionCheck(Collideable *object) LIBZHL_PLACEHOLDER
	virtual void OnUpdate() LIBZHL_PLACEHOLDER
	virtual Pointf GetWorldCenterPoint() LIBZHL_PLACEHOLDER
	virtual Pointf GetRandomTargettingPoint(bool valuable) LIBZHL_PLACEHOLDER
	virtual void ComputeHeading() LIBZHL_PLACEHOLDER
	virtual void SetDestinationSpace(int space) LIBZHL_PLACEHOLDER
	virtual void EnterDestinationSpace() LIBZHL_PLACEHOLDER
	virtual bool Dead() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget() LIBZHL_PLACEHOLDER
	virtual void Kill() LIBZHL_PLACEHOLDER
	virtual Pointf GetSpeed() LIBZHL_PLACEHOLDER
	virtual void SetDamage(Damage damage) LIBZHL_PLACEHOLDER
	virtual int ForceRenderLayer() LIBZHL_PLACEHOLDER
	virtual void SetSpin(float spin) LIBZHL_PLACEHOLDER
	virtual void SaveProjectile(int fd) LIBZHL_PLACEHOLDER
	virtual void LoadProjectile(int fd) LIBZHL_PLACEHOLDER
	virtual int GetType() LIBZHL_PLACEHOLDER
	virtual void SetMovingTarget(Targetable *target) LIBZHL_PLACEHOLDER
	LIBZHL_API static Pointf __stdcall RandomSidePoint(int side);
	
	Targetable _targetable;
	Pointf position;
	Pointf last_position;
	float speed_magnitude;
	Pointf target;
	float heading;
	int ownerId;
	unsigned int selfId;
	Damage damage;
	float lifespan;
	int destinationSpace;
	int currentSpace;
	int targetId;
	bool dead;
	uint8_t gap_ex_1[2];
	Animation death_animation;
	Animation flight_animation;
	Pointf speed;
	bool missed;
	bool hitTarget;
	uint8_t gap_ex_2[2];
	std::string hitSolidSound;
	std::string hitShieldSound;
	std::string missSound;
	float entryAngle;
	bool startedDeath;
	bool passedTarget;
	bool bBroadcastTarget;
	AnimationTracker flashTracker;
	GL_Color color;
};

struct Asteroid : Projectile
{
	GL_Texture *imageId;
	float angle;
};

struct AsteroidGenerator;

struct AsteroidGenerator
{
	LIBZHL_API Projectile *GetNextAsteroid();
	LIBZHL_API float Initialize(int numberOfShips, int shieldCount, bool defense);
	LIBZHL_API void LoadAsteroids(void *file);
	LIBZHL_API void OnLoop();
	LIBZHL_API bool SaveAsteroids(void *file);
	
	std::queue<Projectile*> asteroidQueue;
	RandomAmount spawnRate[3];
	RandomAmount stateLength[3];
	int numberOfShips;
	int iState;
	int currentSpace;
	int iNextDirection;
	float fStateTimer;
	float timer;
	bool bRunning;
	int initShields;
};

struct Blueprint;

struct Description;

struct Description
{
	LIBZHL_API void constructor();
	LIBZHL_API void destructor();
	
	TextString title;
	TextString shortTitle;
	TextString description;
	int cost;
	int rarity;
	int baseRarity;
	int bp;
	bool locked;
	TextString tooltip;
	std::string tip;
};

struct LIBZHL_INTERFACE Blueprint
{
	virtual ~Blueprint() {}
	virtual void RenderIcon(float unk) LIBZHL_PLACEHOLDER
	virtual std::string GetNameLong() LIBZHL_PLACEHOLDER
	virtual std::string GetNameShort() LIBZHL_PLACEHOLDER
	virtual int GetType() LIBZHL_PLACEHOLDER
	std::string name;
	Description desc;
	int type;
};

struct AugmentBlueprint : Blueprint
{
	float value;
	bool stacking;
};

struct AugmentEquipBox;

struct DroneSystem;
struct EquipmentBox;

struct AugmentBlueprint;
struct CrewMember;
struct Drone;

struct EquipmentBoxItem
{
	ProjectileFactory *pWeapon;
	Drone *pDrone;
	CrewMember *pCrew;
	const AugmentBlueprint *augment;
};

struct InfoBox;

struct WeaponSystem;

struct LIBZHL_INTERFACE EquipmentBox
{
	virtual ~EquipmentBox() {}
	virtual void SetPosition(Point pos) LIBZHL_PLACEHOLDER
	virtual void OnRender(bool empty) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void RenderLabels(bool unk);
	virtual void RenderIcon() LIBZHL_PLACEHOLDER
	virtual void SetShipManager(ShipManager *ship) LIBZHL_PLACEHOLDER
	virtual void MouseMove(int x, int y) LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void UpdateBoxImage(bool unk) LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual void AddItem(EquipmentBoxItem item) LIBZHL_PLACEHOLDER
	virtual void RemoveItem() LIBZHL_PLACEHOLDER
	virtual char CanHoldWeapon() LIBZHL_PLACEHOLDER
	virtual char CanHoldDrone() LIBZHL_PLACEHOLDER
	virtual char CanHoldAugment() LIBZHL_PLACEHOLDER
	virtual void CheckContents() LIBZHL_PLACEHOLDER
	virtual int GetType(bool unk) LIBZHL_PLACEHOLDER
	virtual char IsCargoBox() LIBZHL_PLACEHOLDER
	virtual char CanHoldCrew() LIBZHL_PLACEHOLDER
	virtual char CanDoJob() LIBZHL_PLACEHOLDER
	LIBZHL_API void ForceHitBox(Globals::Rect *newBox);
	LIBZHL_API void SetBlueprint(InfoBox *infoBox, bool detailedBox);
	
	GL_Primitive *blocked_overlay;
	GL_Color overlayColor;
	std::string imageName;
	GL_Primitive *empty;
	GL_Primitive *full;
	GL_Primitive *selected_empty;
	GL_Primitive *selected_full;
	WeaponSystem *weaponSys;
	DroneSystem *droneSys;
	Point location;
	Globals::Rect hitBox;
	EquipmentBoxItem item;
	bool bMouseHovering;
	bool bGlow;
	bool bBlocked;
	int slot;
	bool bLocked;
	int value;
	bool bPermanentLock;
	bool blockDetailed;
};

struct AugmentEquipBox : EquipmentBox
{
	LIBZHL_API void constructor(Point loc, ShipManager *shipManager, int slot);
	
	ShipManager *ship;
};

struct AugmentStoreBox;

struct Button;

struct LIBZHL_INTERFACE GenericButton
{
	virtual ~GenericButton() {}
	virtual void Reset() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetLocation(Point pos);
	virtual void SetHitBox(Globals::Rect rect) LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetActive(bool active);
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void MouseMove(int x, int y, bool silent);
	virtual void OnClick() LIBZHL_PLACEHOLDER
	virtual void OnRightClick() LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void ResetPrimitives() LIBZHL_PLACEHOLDER
	
	Point position;
	Globals::Rect hitbox;
	bool allowAnyTouch;
	bool touchSelectable;
	bool bRenderOff;
	bool bRenderSelected;
	bool bFlashing;
	AnimationTracker flashing;
	bool bActive;
	bool bHover;
	bool bActivated;
	bool bSelected;
	int activeTouch;
};

struct Button : GenericButton
{
	LIBZHL_API void OnInit(const std::string &img, Point pos);
	LIBZHL_API void OnRender();
	LIBZHL_API void SetImageBase(const std::string &imageBase);
	
	GL_Texture *images[3];
	GL_Primitive *primitives[3];
	Point imageSize;
	bool bMirror;
};

struct Equipment;

struct StoreBox;

struct LIBZHL_INTERFACE StoreBox
{
	virtual ~StoreBox() {}
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender() LIBZHL_PLACEHOLDER
	virtual void MouseMove(int, int) LIBZHL_PLACEHOLDER
	virtual void MouseClick(int, int) LIBZHL_PLACEHOLDER
	virtual void OnTouch() LIBZHL_PLACEHOLDER
	virtual void Activate() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void Purchase();
	virtual int SetInfoBox(InfoBox&, int) LIBZHL_PLACEHOLDER
	virtual bool CanHold() LIBZHL_PLACEHOLDER
	virtual bool RequiresConfirm() LIBZHL_PLACEHOLDER
	virtual void Confirm(bool) LIBZHL_PLACEHOLDER
	virtual TextString GetConfirmText() LIBZHL_PLACEHOLDER
	virtual int GetExtraData() LIBZHL_PLACEHOLDER
	virtual void SetExtraData(int) LIBZHL_PLACEHOLDER
	LIBZHL_API void SetPosition(Point pos);
	
	int itemId;
	int itemBox;
	std::string buttonImage;
	Button button;
	GL_Primitive *symbol;
	Description desc;
	int count;
	int cost_position;
	ShipManager *shopper;
	Equipment *equipScreen;
	Blueprint *pBlueprint;
	bool bEquipmentBox;
	float fIconScale;
	Point pushIcon;
};

struct AugmentStoreBox : StoreBox
{
	LIBZHL_API void constructor(ShipManager *ship, const AugmentBlueprint *bp);
	
	AugmentBlueprint *blueprint;
};

struct BatteryBox;
struct BatterySystem;

struct BatteryBox : CooldownSystemBox
{
	LIBZHL_API void constructor(Point pos, BatterySystem *sys);
	
	BatterySystem *batterySystem;
	Button batteryButton;
	Point buttonOffset;
};

struct BatterySystem : ShipSystem
{
	bool bTurnedOn;
	TimerHelper timer;
	std::string soundeffect;
};

struct BoardingGoal
{
	float fHealthLimit;
	int causedDamage;
	int targetsDestroyed;
	int target;
	int damageType;
};

struct CrewAnimation;

struct CrewBlueprint;

struct CrewBlueprint : Blueprint
{
	LIBZHL_API GL_Color GetCurrentSkillColor(int skill);
	LIBZHL_API void RandomSkills(int worldLevel);
	LIBZHL_API void RenderSkill(int x, int y, int length, int height, int skill);
	
	TextString crewName;
	TextString crewNameLong;
	std::vector<TextString> powers;
	bool male;
	std::vector<std_pair_int_int> skillLevel;
	std::vector<std::vector<GL_Color>> colorLayers;
	std::vector<int> colorChoices;
};

struct CrewTarget;

struct CrewTask
{
	int taskId;
	int room;
	int system;
};

struct Door;

struct Path
{
	Point start;
	std::vector<Door*> doors;
	Point finish;
	float distance;
};

struct Repairable;

struct SCrewStats
{
	std::vector<int> stat;
	std::string species;
	std::string name;
	bool male;
};

struct Ship;

struct Slot
{
	int roomId;
	int slotId;
	Point worldLocation;
};

struct LIBZHL_INTERFACE CrewMember
{
	virtual ~CrewMember() {}
	virtual Point GetPosition() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual float PositionShift();
	virtual bool InsideRoom(int roomId) LIBZHL_PLACEHOLDER
	virtual bool ApplyDamage(float damage) LIBZHL_PLACEHOLDER
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void Jump();
	virtual bool GetIntruder() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SaveState(int fileHelper);
	LIBZHL_API virtual void LoadState(int fileHelper);
	LIBZHL_API virtual void OnLoop();
	LIBZHL_API virtual void OnRender(bool outlineOnly);
	virtual bool OutOfGame() LIBZHL_PLACEHOLDER
	virtual void SetOutOfGame() LIBZHL_PLACEHOLDER
	virtual bool Functional() LIBZHL_PLACEHOLDER
	virtual bool CountForVictory() LIBZHL_PLACEHOLDER
	virtual bool GetControllable() LIBZHL_PLACEHOLDER
	virtual bool ReadyToFight() LIBZHL_PLACEHOLDER
	virtual bool CanFight() LIBZHL_PLACEHOLDER
	virtual bool CanRepair() LIBZHL_PLACEHOLDER
	virtual bool CanSabotage() LIBZHL_PLACEHOLDER
	virtual bool CanMan() LIBZHL_PLACEHOLDER
	virtual bool CanTeleport() LIBZHL_PLACEHOLDER
	virtual bool CanHeal() LIBZHL_PLACEHOLDER
	virtual bool CanSuffocate() LIBZHL_PLACEHOLDER
	virtual bool CanBurn() LIBZHL_PLACEHOLDER
	virtual int GetMaxHealth() LIBZHL_PLACEHOLDER
	virtual bool IsDead() LIBZHL_PLACEHOLDER
	virtual bool PermanentDeath() LIBZHL_PLACEHOLDER
	virtual bool ShipDamage(float damage) LIBZHL_PLACEHOLDER
	virtual bool FireFightingSoundEffect() LIBZHL_PLACEHOLDER
	virtual std::string GetUniqueRepairing() LIBZHL_PLACEHOLDER
	virtual bool ProvidesVision() LIBZHL_PLACEHOLDER
	virtual float GetMoveSpeedMultiplier() LIBZHL_PLACEHOLDER
	virtual float GetRepairSpeed() LIBZHL_PLACEHOLDER
	virtual float GetDamageMultiplier() LIBZHL_PLACEHOLDER
	virtual bool ProvidesPower() LIBZHL_PLACEHOLDER
	virtual std::string GetSpecies() LIBZHL_PLACEHOLDER
	virtual float GetFireRepairMultiplier() LIBZHL_PLACEHOLDER
	virtual bool IsTelepathic() LIBZHL_PLACEHOLDER
	virtual std::pair<float, float> GetPowerCooldown() LIBZHL_PLACEHOLDER
	virtual bool PowerReady() LIBZHL_PLACEHOLDER
	virtual void ActivatePower() LIBZHL_PLACEHOLDER
	virtual bool HasSpecialPower() LIBZHL_PLACEHOLDER
	virtual void ResetPower() LIBZHL_PLACEHOLDER
	virtual float GetSuffocationMultiplier() LIBZHL_PLACEHOLDER
	virtual int BlockRoom() LIBZHL_PLACEHOLDER
	virtual Damage GetRoomDamage() LIBZHL_PLACEHOLDER
	virtual bool IsAnaerobic() LIBZHL_PLACEHOLDER
	virtual void UpdateRepair() LIBZHL_PLACEHOLDER
	virtual bool CanStim() LIBZHL_PLACEHOLDER
	LIBZHL_API bool AtFinalGoal();
	LIBZHL_API void CheckFighting();
	LIBZHL_API void CheckForTeleport();
	LIBZHL_API void CheckSkills();
	LIBZHL_API void ClearPosition();
	LIBZHL_API void ClearTask();
	LIBZHL_API bool ContainsPoint(int x, int y);
	LIBZHL_API bool DirectModifyHealth(float health);
	LIBZHL_API void EmptySlot();
	LIBZHL_API void ForceMindControl(bool force);
	LIBZHL_API int GetIntegerHealth();
	LIBZHL_API float GetMoveSpeed();
	LIBZHL_API bool GetNewGoal();
	LIBZHL_API Point GetNextGoal();
	LIBZHL_API bool GetResisted();
	LIBZHL_API Slot GetSavedPosition();
	LIBZHL_API int GetSkillLevel(int skillId);
	LIBZHL_API std::pair<int, int> GetSkillProgress(int skillId);
	LIBZHL_API static std::string __stdcall GetSkillTooltip(int skillId, int skillLevel, std::pair<int, int> progress, bool infoScreen);
	LIBZHL_API void InitializeSkills();
	LIBZHL_API void ModifyHealth(float health);
	LIBZHL_API bool MoveToRoom(int roomId, int slotId, bool forceMove);
	LIBZHL_API bool NeedFrozenLocation();
	LIBZHL_API void OnRenderPath();
	LIBZHL_API bool Repairing();
	LIBZHL_API bool RepairingFire();
	LIBZHL_API bool RepairingSystem();
	LIBZHL_API bool Sabotaging();
	LIBZHL_API void SavePosition();
	LIBZHL_API Pointf SelectSabotageTarget();
	LIBZHL_API void SetCurrentShip(int shipId);
	LIBZHL_API void SetCurrentSystem(ShipSystem *sys);
	LIBZHL_API void SetCurrentTarget(CrewTarget *target, bool unk);
	LIBZHL_API void SetDamageBoost(float damageBoost);
	LIBZHL_API void SetFrozenLocation(bool frozenLocation);
	LIBZHL_API void SetMedbay(float health);
	LIBZHL_API void SetResisted(bool resisted);
	LIBZHL_API void SetSavePosition(Slot position);
	LIBZHL_API void SetSex(bool male);
	LIBZHL_API void SetSkillProgress(int skillId, int skillLevel);
	LIBZHL_API void SetTask(CrewTask task);
	LIBZHL_API void StartRepair(Repairable *toRepair);
	LIBZHL_API void StartTeleport();
	LIBZHL_API void StartTeleportArrive();
	LIBZHL_API void UpdateHealth();
	
	int iShipId;
	float x;
	float y;
	float size;
	float scale;
	float goal_x;
	float goal_y;
	int width;
	int height;
	std::pair<float, float> health;
	float speed_x;
	float speed_y;
	Path path;
	bool new_path;
	float x_destination;
	float y_destination;
	Door *last_door;
	Repairable *currentRepair;
	bool bSuffocating;
	int moveGoal;
	int selectionState;
	int iRoomId;
	int iManningId;
	int iRepairId;
	int iStackId;
	Slot currentSlot;
	bool intruder;
	bool bFighting;
	bool bSharedSpot;
	CrewAnimation *crewAnim;
	GL_Texture *selectionImage;
	CachedImage healthBox;
	CachedImage healthBoxRed;
	CachedRect healthBar;
	float fMedbay;
	float lastDamageTimer;
	float lastHealthChange;
	int currentShipId;
	AnimationTracker flashHealthTracker;
	Pointf currentTarget;
	CrewTarget *crewTarget;
	BoardingGoal boardingGoal;
	bool bFrozen;
	bool bFrozenLocation;
	CrewTask task;
	std::string type;
	Ship *ship;
	Slot finalGoal;
	Door *blockingDoor;
	bool bOutOfGame;
	std::string species;
	bool bDead;
	uint8_t gap_ex_1[2];
	int iOnFire;
	bool bActiveManning;
	ShipSystem *currentSystem;
	int usingSkill;
	CrewBlueprint blueprint;
	Animation healing;
	Animation stunned;
	AnimationTracker levelUp;
	int lastLevelUp;
	SCrewStats stats;
	std::vector<std::vector<bool>> skillsEarned;
	bool clone_ready;
	bool bMindControlled;
	int iDeathNumber;
	Animation mindControlled;
	Animation stunIcon;
	std::vector<std::vector<AnimationTracker>> skillUp;
	int healthBoost;
	float fMindDamageBoost;
	float fCloneDying;
	bool bResisted;
	uint8_t gap_ex_2[2];
	Slot savedPosition;
	float fStunTime;
	CachedImage movementTarget;
	bool bCloned;
};

struct DroneBlueprint;

struct LIBZHL_INTERFACE Drone
{
	virtual ~Drone() {}
	virtual void OnInit() LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnDestroy() LIBZHL_PLACEHOLDER
	virtual void SetPowered(bool _powered) LIBZHL_PLACEHOLDER
	virtual void SetInstantPowered() LIBZHL_PLACEHOLDER
	virtual bool GetPowered() LIBZHL_PLACEHOLDER
	virtual void SetCurrentShip(int shipId) LIBZHL_PLACEHOLDER
	virtual void SetDeployed(bool _deployed) LIBZHL_PLACEHOLDER
	virtual void SetDestroyed(bool dead, bool setTimer) LIBZHL_PLACEHOLDER
	virtual void SetHacked(int level) LIBZHL_PLACEHOLDER
	virtual bool GetDeployed() LIBZHL_PLACEHOLDER
	virtual bool NeedsRoom() LIBZHL_PLACEHOLDER
	virtual void SetSlot(int room, int slot) LIBZHL_PLACEHOLDER
	virtual bool Destroyed() LIBZHL_PLACEHOLDER
	virtual Point GetWorldLocation() LIBZHL_PLACEHOLDER
	virtual void SetWorldLocation(Point point) LIBZHL_PLACEHOLDER
	virtual Slot GetDroneSlot() LIBZHL_PLACEHOLDER
	virtual int GetDroneHealth() LIBZHL_PLACEHOLDER
	virtual int GetRequiredPower() LIBZHL_PLACEHOLDER
	virtual void RenderIcon() LIBZHL_PLACEHOLDER
	virtual std::string GetName() LIBZHL_PLACEHOLDER
	virtual bool CanBeDeployed() LIBZHL_PLACEHOLDER
	virtual bool RecallOnJump() LIBZHL_PLACEHOLDER
	virtual bool CanBeRecovered() LIBZHL_PLACEHOLDER
	virtual void SaveState(int fh) LIBZHL_PLACEHOLDER
	virtual void LoadState(int fh) LIBZHL_PLACEHOLDER
	virtual void BlowUp(bool silent) LIBZHL_PLACEHOLDER
	virtual bool GetStunned() LIBZHL_PLACEHOLDER
	int iShipId;
	int selfId;
	bool powered;
	int powerRequired;
	bool deployed;
	int type;
	const DroneBlueprint *blueprint;
	bool bDead;
	int iBonusPower;
	bool poweredAtLocation;
	float destroyedTimer;
	int iHackLevel;
	float hackTime;
};

struct CrewDrone : CrewMember
{
	Drone _drone;
	int droneRoom;
	Animation powerUp;
	Animation powerDown;
	GL_Texture *lightLayer;
	GL_Texture *baseLayer;
};

struct BattleDrone : CrewDrone
{
};

struct BeamWeapon;

struct BeamWeapon : Projectile
{
	LIBZHL_API void constructor(Pointf _position, int _ownerId, int _targetId, Pointf _target, Pointf _target2, int _length, Targetable *_targetable, float heading);
	
	Pointf sub_end;
	Pointf sub_start;
	Pointf shield_end;
	Pointf final_end;
	Pointf target2;
	Pointf target1;
	float lifespan;
	float length;
	float dh;
	CollisionResponse last_collision;
	int soundChannel;
	std::vector<Animation> contactAnimations;
	float animationTimer;
	int lastDamage;
	Targetable *movingTarget;
	float start_heading;
	float timer;
	WeaponAnimation *weapAnimation;
	bool piercedShield;
	bool oneSpace;
	bool bDamageSuperShield;
	int movingTargetId;
	bool checkedCollision;
	std::vector<Animation> smokeAnims;
	Pointf lastSmokeAnim;
};

struct BlueprintManager;

struct DroneBlueprint : Blueprint
{
	std::string typeName;
	int level;
	int targetType;
	int power;
	float cooldown;
	int speed;
	int dodge;
	std::string weaponBlueprint;
	std::string droneImage;
	std::string combatIcon;
};

struct ItemBlueprint : Blueprint
{
};

struct ShipBlueprint : Blueprint
{
	struct SystemTemplate
	{
		int systemId;
		int powerLevel;
		std::vector<int> location;
		int bp;
		int maxPower;
		std::string image;
		int slot;
		int direction;
		std::vector<std::string> weapon;
	};
	
	Description desc;
	std::string blueprintName;
	TextString name;
	TextString shipClass;
	std::string layoutFile;
	std::string imgFile;
	std::string cloakFile;
	std::string shieldFile;
	std::string floorFile;
	std::map<int, SystemTemplate> systemInfo;
	std::vector<int> systems;
	int droneCount;
	int originalDroneCount;
	int droneSlots;
	std::string loadDrones;
	std::vector<std::string> drones;
	std::vector<std::string> augments;
	int weaponCount;
	int originalWeaponCount;
	int weaponSlots;
	std::string loadWeapons;
	std::vector<std::string> weapons;
	int missiles;
	int drone_count;
	int health;
	int originalCrewCount;
	std::vector<std::string> defaultCrew;
	std::vector<CrewBlueprint> customCrew;
	int maxPower;
	int boardingAI;
	int bp_count;
	int maxCrew;
	int maxSector;
	int minSector;
	TextString unlock;
};

struct SystemBlueprint : Blueprint
{
	int maxPower;
	int startPower;
	std::vector<int> upgradeCosts;
};

struct EffectsBlueprint
{
	std::vector<std::string> launchSounds;
	std::vector<std::string> hitShipSounds;
	std::vector<std::string> hitShieldSounds;
	std::vector<std::string> missSounds;
	std::string image;
};

struct WeaponBlueprint : Blueprint
{
	struct BoostPower
	{
		int type;
		float amount;
		int count;
	};
	
	struct MiniProjectile
	{
		std::string image;
		bool fake;
	};
	
	LIBZHL_API Point GetDimensions();
	
	std::string typeName;
	Damage damage;
	int shots;
	int missiles;
	float cooldown;
	int power;
	int length;
	float speed;
	int miniCount;
	EffectsBlueprint effects;
	std::string weaponArt;
	std::string combatIcon;
	std::string explosion;
	int radius;
	std::vector<MiniProjectile> miniProjectiles;
	BoostPower boostPower;
	int drone_targetable;
	int spin;
	int chargeLevels;
	TextString flavorType;
	GL_Color color;
};

struct BlueprintManager
{
	LIBZHL_API float GetAugmentValue(const std::string &name);
	LIBZHL_API ItemBlueprint *GetItemBlueprint(const std::string &name);
	LIBZHL_API std::vector<AugmentBlueprint*> GetRandomAugment(int count, bool demo_lock);
	LIBZHL_API std::vector<DroneBlueprint*> GetRandomDrone(int count, bool demo_lock);
	LIBZHL_API std::vector<WeaponBlueprint*> GetRandomWeapon(int count, bool demo_lock);
	LIBZHL_API ShipBlueprint *GetShipBlueprint(const std::string &name, int sector);
	LIBZHL_API SystemBlueprint *GetSystemBlueprint(const std::string &name);
	LIBZHL_API void SetRarity(const std::string &name, int rarity);
	
	int rarityTotal;
	std::map<std::string, ShipBlueprint> shipBlueprints;
	std::map<std::string, WeaponBlueprint> weaponBlueprints;
	std::map<std::string, DroneBlueprint> droneBlueprints;
	std::map<std::string, AugmentBlueprint> augmentBlueprints;
	std::map<std::string, CrewBlueprint> crewBlueprints;
	std::map<std::string, bool> nameList;
	std::map<std::string, std::string> shortNames;
	std::map<std::string, std_map_std_string_bool> languageNameLists;
	std::map<std::string, ItemBlueprint> itemBlueprints;
	std::map<std::string, SystemBlueprint> systemBlueprints;
	std::map<std::string, std::vector<std::string>> blueprintLists;
	std::vector<std::string> currentNames;
};

struct BoarderDrone : CrewDrone
{
};

struct BoarderDrone;

struct DamageMessage;

struct SpaceDrone;

struct LIBZHL_INTERFACE SpaceDrone : Drone
{
	virtual void PickDestination() LIBZHL_PLACEHOLDER
	virtual void PickTarget() LIBZHL_PLACEHOLDER
	virtual bool HasTarget() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget() LIBZHL_PLACEHOLDER
	virtual float GetWeaponCooldown() LIBZHL_PLACEHOLDER
	virtual void RandomizeStartingPosition() LIBZHL_PLACEHOLDER
	virtual bool HideUnderOwner() LIBZHL_PLACEHOLDER
	virtual Projectile *GetNextProjectile() LIBZHL_PLACEHOLDER
	virtual void SetMovementTarget(Targetable *target) LIBZHL_PLACEHOLDER
	virtual void SetWeaponTarget(Targetable *target) LIBZHL_PLACEHOLDER
	virtual bool ValidTargetObject(Targetable *target) LIBZHL_PLACEHOLDER
	virtual void OnRender(int space) LIBZHL_PLACEHOLDER
	virtual void RenderDrone() LIBZHL_PLACEHOLDER
	virtual std::string *GetTooltip(SpaceDrone *drone) LIBZHL_PLACEHOLDER
	virtual Pointf GetWorldCenterPoint() LIBZHL_PLACEHOLDER
	virtual void SetCurrentLocation(Pointf pos) LIBZHL_PLACEHOLDER
	virtual void MouseMove(int mX, int mY) LIBZHL_PLACEHOLDER
	virtual Pointf GetRandomTargettingPoint(bool unk) LIBZHL_PLACEHOLDER
	virtual Globals::Ellipse *GetShieldShape(SpaceDrone *drone) LIBZHL_PLACEHOLDER
	virtual int GetSpaceId() LIBZHL_PLACEHOLDER
	virtual Pointf GetSpeed() LIBZHL_PLACEHOLDER
	virtual int GetOwnerId() LIBZHL_PLACEHOLDER
	virtual int GetSelfId() LIBZHL_PLACEHOLDER
	virtual CollisionResponse CollisionMoving(Pointf start, Pointf finish, Damage damage, bool raytrace) LIBZHL_PLACEHOLDER
	virtual bool DamageBeam(Pointf pos1, Pointf pos2, Damage damage) LIBZHL_PLACEHOLDER
	virtual bool DamageArea(Pointf pos, Damage damage, bool unk) LIBZHL_PLACEHOLDER
	virtual BoarderDrone *GetBoardingDrone() LIBZHL_PLACEHOLDER
	LIBZHL_API virtual void SetDeployed(bool deployed);
	
	Targetable _targetable;
	Collideable _collideable;
	int currentSpace;
	int destinationSpace;
	Pointf currentLocation;
	Pointf lastLocation;
	Pointf destinationLocation;
	Pointf pointTarget;
	Animation explosion;
	Targetable *weaponTarget;
	Pointf targetLocation;
	Pointf targetSpeed;
	Targetable *movementTarget;
	Pointf speedVector;
	bool poweredLastFrame;
	bool deployedLastFrame;
	bool bFire;
	float pause;
	float additionalPause;
	float weaponCooldown;
	float current_angle;
	float aimingAngle;
	float lastAimingAngle;
	float desiredAimingAngle;
	DamageMessage *message;
	Animation weapon_animation;
	const WeaponBlueprint *weaponBlueprint;
	int lifespan;
	bool bLoadedPosition;
	bool bDisrupted;
	float hackAngle;
	float ionStun;
	Pointf beamCurrentTarget;
	Pointf beamFinalTarget;
	float beamSpeed;
	Animation hackSparks;
};

struct BoarderPodDrone : SpaceDrone
{
	GL_Texture *baseSheet;
	GL_Texture *colorSheet;
	Pointf startingPosition;
	Animation droneImage;
	CachedImage flame;
	BoarderDrone *boarderDrone;
	bool bDeliveredDrone;
	bool diedInSpace;
};

struct BoardingEvent
{
	std::string type;
	int min;
	int max;
	int amount;
	bool breach;
};

struct BombProjectile : Projectile
{
	bool bMissed;
	DamageMessage *missMessage;
	float explosiveDelay;
	bool bSuperShield;
	bool superShieldBypass;
};

struct BossShip;

struct CompleteShip;

struct CombatAI;

struct CombatAI
{
	LIBZHL_API int PrioritizeSystem(int weaponType);
	LIBZHL_API void UpdateMindControl(bool unk);
	
	ShipManager *target;
	std::vector<ProjectileFactory*> weapons;
	std::vector<SpaceDrone*> drones;
	int stance;
	std::vector<int> system_targets;
	bool bFiringWhileCloaked;
	ShipManager *self;
};

struct CrewAI;

struct CrewAI
{
	LIBZHL_API void CheckForHealing();
	LIBZHL_API void CheckForProblems();
	LIBZHL_API int DangerRating(int roomId, int crewId);
	LIBZHL_API int PrioritizeTask(CrewTask task, int crewId);
	LIBZHL_API void UpdateIntruders();
	
	ShipManager *ship;
	bool bAIon;
	bool bAirlockRequested;
	bool bMedbayRequested;
	bool bHurtCrew;
	bool bCalmShip;
	std::vector<CrewMember*> crewList;
	std::vector<CrewMember*> intruderList;
	std::vector<Repairable*> hullBreaches;
	std::vector<CrewTask> desiredTaskList;
	std::vector<CrewTask> bonusTaskList;
	std::vector<bool> breachedRooms;
	int iTeleportRequest;
	bool bUrgentTeleport;
	int startingCrewCount;
	bool bMultiracialCrew;
	bool bOverrideRace;
};

struct PowerProfile
{
};

struct ShipAI;

struct ShipAI
{
	LIBZHL_API std::pair<int, int> GetTeleportCommand();
	LIBZHL_API void SetStalemate(bool stalemate);
	
	ShipManager *ship;
	ShipManager *target;
	CrewAI crewAI;
	CombatAI combatAI;
	bool playerShip;
	bool surrendered;
	bool escaping;
	bool destroyed;
	int surrenderThreshold;
	int escapeThreshold;
	float escapeTimer;
	int lastMaxPower;
	std::map<std::string, PowerProfile> powerProfiles;
	int boardingProfile;
	int iTeleportRequest;
	int iTeleportTarget;
	int brokenSystems;
	int boardingAi;
	int iCrewNeeded;
	bool bStalemateTrigger;
	char field_ED[3];
	float fStalemateTimer;
	int lastHealth;
	bool bBoss;
	char field_F9[3];
	int iTimesTeleported;
};

struct ShipBlueprint;
struct SpaceManager;

struct LIBZHL_INTERFACE CompleteShip
{
	virtual ~CompleteShip() {}
	LIBZHL_API virtual void OnLoop();
	virtual void PauseLoop() LIBZHL_PLACEHOLDER
	virtual bool IsBoss() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool IncomingFire() LIBZHL_PLACEHOLDER
	LIBZHL_API void AddBoarders(int amount, const std::string &race, bool unk2);
	LIBZHL_API CrewMember *AddCrewMember(const CrewBlueprint *blueprint, bool hostile);
	LIBZHL_API CrewMember *AddCrewMember1(const std::string &race, const std::string &name, bool hostile);
	LIBZHL_API bool DeadCrew();
	LIBZHL_API void InitiateTeleport(int targetRoom, int command);
	LIBZHL_API void Jump();
	LIBZHL_API void LoadState(int unk);
	LIBZHL_API void OnInit(const ShipBlueprint *blueprint, int unk);
	LIBZHL_API void OnRenderShip(bool unk1, bool unk2);
	LIBZHL_API void OnRenderSpace();
	LIBZHL_API void SaveState(int unk);
	LIBZHL_API void SetEnemyShip(CompleteShip *other);
	LIBZHL_API void SetShip(ShipManager *ship);
	LIBZHL_API void constructor(SpaceManager *space, bool unk, int unk2);
	
	int iShipId;
	ShipManager *shipManager;
	SpaceManager *spaceManager;
	CompleteShip *enemyShip;
	bool bPlayerShip;
	ShipAI shipAI;
	std::vector<CrewMember*> arrivingParty;
	std::vector<CrewMember*> leavingParty;
	int teleTargetRoom;
};

struct LocationEvent;

struct BossShip : CompleteShip
{
	LIBZHL_API LocationEvent *GetSubEvent();
	LIBZHL_API void LoadBoss(int file);
	LIBZHL_API void StartStage();
	LIBZHL_API void constructor(SpaceManager *space);
	
	int currentStage;
	TimerHelper powerTimer;
	int powerCount;
	std::vector<int> crewCounts;
	bool bDeathBegan;
	int nextStage;
};

struct CApp;

struct CEvent;
struct InputEvent;

struct CEvent
{
	LIBZHL_API void OnEvent(const InputEvent *event);
	
	void *vptr;
};

struct GL_FrameBuffer;

struct FocusWindow;

struct FocusWindow
{
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void SetPosition(Point p);
	LIBZHL_API void constructor();
	
	void *vptr;
	bool bOpen;
	bool bFullFocus;
	uint8_t gap_ex_fw[2];
	Point close;
	bool bCloseButtonSelected;
	Point position;
};

struct LanguageChooser;
struct TextButton;

struct LanguageChooser : FocusWindow
{
	LIBZHL_API void OnRender();
	
	std::vector<TextButton*> buttons;
	int iChoice;
};

struct ChoiceBox;

struct ResourceEvent
{
	int missiles;
	int fuel;
	int drones;
	int scrap;
	int crew;
	bool traitor;
	bool cloneable;
	TextString cloneText;
	std::string crewType;
	const WeaponBlueprint *weapon;
	const DroneBlueprint *drone;
	const AugmentBlueprint *augment;
	CrewBlueprint crewBlue;
	int systemId;
	int weaponCount;
	int droneCount;
	bool steal;
	bool intruders;
	int fleetDelay;
	int hullDamage;
	int upgradeAmount;
	int upgradeId;
	int upgradeSuccessFlag;
	std::string removeItem;
};

struct ChoiceText
{
	int type;
	std::string text;
	ResourceEvent rewards;
};

struct WindowFrame;

struct ChoiceBox : FocusWindow
{
	LIBZHL_API void MouseClick(int mX, int mY);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnRender();
	
	GL_Texture *textBox;
	WindowFrame *box;
	std::string mainText;
	std::vector<ChoiceText> choices;
	unsigned int columnSize;
	std::vector<Globals::Rect> choiceBoxes;
	int potentialChoice;
	int selectedChoice;
	int fontSize;
	bool centered;
	int gap_size;
	float openTime;
	ResourceEvent rewards;
	GL_Color currentTextColor;
	Pointf lastChoice;
};

struct ConfirmWindow;

struct TextButton : GenericButton
{
	LIBZHL_API int GetIdealButtonWidth();
	LIBZHL_API __int64 GetSize_DO_NOT_USE_DIRECTLY();
	LIBZHL_API void OnRender();
	LIBZHL_API void SetAutoWidth(bool autoWidth, bool autoRightAlign, int margin, int min);
	LIBZHL_API void UpdateAutoWidth();
	LIBZHL_API void destructor();
	
	GL_Primitive *primitives[3];
	GL_Texture *baseImage;
	Point baseImageOffset;
	GL_Primitive *basePrimitive;
	bool colorsSet;
	GL_Color colors[3];
	GL_Color textColor;
	Point buttonSize;
	int cornerInset;
	bool autoWidth;
	int autoWidthMargin;
	int autoWidthMin;
	bool autoRightAlign;
	TextString label;
	int font;
	int lineHeight;
	int textYOffset;
	bool autoShrink;
};

struct ConfirmWindow : FocusWindow
{
	LIBZHL_API void Close();
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void OnRender();
	LIBZHL_API void SetPosition(Point pos);
	LIBZHL_API void SetText(const TextString &text_, int minWidth, bool autoCenter, const TextString &yesText_, const TextString &noText_);
	LIBZHL_API void constructor();
	
	TextString text;
	int textHeight;
	int minWidth;
	int windowWidth;
	TextString yesText;
	TextString noText;
	bool autoCenter;
	GL_Texture *windowImage;
	GL_Primitive *window;
	TextButton yesButton;
	TextButton noButton;
	bool result;
};

struct CreditScreen;

struct CreditScreen
{
	LIBZHL_API bool Done();
	
	float scroll;
	std::string shipName;
	std::string crewString;
	float pausing;
	GL_Texture *bg;
	std::vector<std::string> creditNames;
	int lastValidCredit;
	int touchesDown;
	double touchDownTime;
	float skipMessageTimer;
	char gap5C[3];
	char _unk;
};

struct MainMenu;

struct ControlButton;

struct ControlButton
{
	LIBZHL_API void OnRender();
	
	Globals::Rect rect;
	std::string value;
	TextString desc;
	std::string key;
	int state;
	int descLength;
};

struct ControlsScreen
{
	std::vector<ControlButton> buttons[4];
	int selectedButton;
	TextButton defaultButton;
	ConfirmWindow resetDialog;
	Button pageButtons[4];
	int currentPage;
	WindowFrame *customBox;
};

struct OptionsScreen;

struct SlideBar
{
	Globals::Rect box;
	bool hovering;
	bool holding;
	Globals::Rect marker;
	Point mouseStart;
	Point rectStart;
	std::pair<int, int> minMax;
};

struct OptionsScreen : ChoiceBox
{
	LIBZHL_API void OnInit();
	LIBZHL_API void OnLoop();
	
	Point position;
	Point wipeProfilePosition;
	SlideBar soundVolume;
	SlideBar musicVolume;
	bool bCustomizeControls;
	ControlsScreen controls;
	TextButton closeButton;
	TextButton wipeProfileButton;
	int choiceFullscreen;
	int choiceVSync;
	int choiceFrameLimit;
	int choiceLowend;
	int choiceColorblind;
	int choiceLanguage;
	int choiceDialogKeys;
	int choiceShowPaths;
	int choiceAchievementPopups;
	int choiceAutoPause;
	int choiceTouchAutoPause;
	int choiceControls;
	int lastFullScreen;
	bool isSoundTouch;
	bool isMusicTouch;
	LanguageChooser langChooser;
	bool showWipeButton;
	ConfirmWindow wipeProfileDialog;
	ChoiceBox restartRequiredDialog;
};

struct CrewCustomizeBox;

struct ItemBlueprint;

struct SystemBlueprint;

struct InfoBox
{
	LIBZHL_API void Clear();
	LIBZHL_API bool IsEmpty();
	LIBZHL_API void OnRender();
	LIBZHL_API void SetBlueprint(const ItemBlueprint *bp);
	LIBZHL_API void SetDescription(Description *desc, int width, int height, InfoBox::ExpandDir dir);
	LIBZHL_API void SetSystem(ShipSystem *system, int upgrade, int yShift, int forceSystemWidth);
	LIBZHL_API void constructor();
	
	Point location;
	const SystemBlueprint *blueprint;
	Description desc;
	int tempUpgrade;
	int powerLevel;
	int maxPower;
	int systemId;
	int systemWidth;
	int yShift;
	Point descBoxSize;
	const CrewBlueprint *pCrewBlueprint;
	std::string warning;
	bool bDetailed;
	std::string additionalTip;
	std::string additionalWarning;
	WindowFrame *primaryBox;
	int primaryBoxOffset;
	WindowFrame *secondaryBox;
	std::string droneBlueprint;
};

struct ShipAchievementInfo
{
	CAchievement *achievement;
	Point position;
	int dimension;
};

struct ShipBuilder;

struct ShipButton;
struct ShipSelect;

struct UnlockArrow;

struct UnlockArrow
{
	LIBZHL_API void constructor(Point pos, int unk1, int unk2);
	
	int direction;
	int status;
	Globals::Rect shape;
};

struct ShipSelect
{
	LIBZHL_API void Close();
	LIBZHL_API void MouseClick();
	LIBZHL_API void OnLoop();
	
	Point position;
	Point titlePos;
	std::vector<GL_Primitive*> shipListBase;
	std::vector<ShipButton*> shipButtons;
	std::vector<UnlockArrow> arrows;
	bool bOpen;
	int selectedShip;
	InfoBox infoBox;
	int currentType;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	TextButton confirm;
	bool bConfirmed;
	int activeTouch;
	ChoiceBox tutorial;
	int tutorialPage;
};

struct SystemCustomBox;

struct TextInput;

struct TextInput
{
	LIBZHL_API bool GetActive();
	LIBZHL_API void OnLoop();
	LIBZHL_API void Stop();
	
	std::string prompt;
	std::vector<int> text;
	std::vector<int> oldText;
	int pos;
	int lastPos;
	bool bActive;
	int allowedChars;
	int maxChars;
	TimerHelper blinker;
};

struct ShipBuilder
{
	LIBZHL_API void CheckTypes();
	LIBZHL_API void CycleTypeNext();
	LIBZHL_API ShipManager *GetShip();
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnLoop();
	LIBZHL_API void Open();
	LIBZHL_API void SetupShipAchievements();
	LIBZHL_API void SwapType(int variant);
	LIBZHL_API void SwitchShip(int shipType, int shipVariant);
	LIBZHL_API void constructor();
	
	ShipManager *currentShip;
	GL_Primitive *nameBoxPrimitive;
	GL_Primitive *enableAdvancedPrimitive;
	Button resetButton;
	Button clearButton;
	TextButton startButton;
	TextButton backButton;
	TextButton renameButton;
	Button leftButton;
	Button rightButton;
	TextButton listButton;
	TextButton showButton;
	TextButton easyButton;
	TextButton normalButton;
	TextButton hardButton;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	Point typeALoc;
	Point typeBLoc;
	Point typeCLoc;
	TextButton randomButton;
	TextButton advancedOffButton;
	TextButton advancedOnButton;
	std::vector<GenericButton*> buttons;
	std::vector<Animation> animations;
	std::vector<CrewCustomizeBox*> vCrewBoxes;
	bool bOpen;
	GL_Primitive *baseImage;
	GL_Primitive *shipSelectBox;
	GL_Primitive *shipAchBox;
	GL_Primitive *shipEquipBox;
	GL_Primitive *startButtonBox;
	GL_Primitive *advancedButtonBox;
	int typeAOffset;
	int typeBOffset;
	int typeCOffset;
	int shipAchPadding;
	int advancedTitleOffset;
	std::vector<EquipmentBox*> vEquipmentBoxes;
	InfoBox infoBox;
	std::vector<SystemCustomBox*> sysBoxes;
	int shoppingId;
	int currentSlot;
	int currentBox;
	bool bDone;
	const ShipBlueprint *ships[30];
	int currentShipId;
	int storeIds[4];
	bool bRenaming;
	std::string currentName;
	bool bShowRooms;
	bool bCustomizingCrew;
	Animation walkingMan;
	Pointf walkingManPos;
	ShipSelect shipSelect;
	ChoiceBox introScreen;
	bool bShowedIntro;
	int currentType;
	TextInput nameInput;
	int activeTouch;
	bool activeTouchIsShip;
	bool shipDragActive;
	bool shipDragVertical;
	Point shipDragOffset;
	std::vector<ShipAchievementInfo> shipAchievements;
	int selectedAch;
	GL_Texture *arrow;
	WindowFrame *descBox;
	AnimationTracker tracker;
	bool encourageShipList;
};

struct MainMenu
{
	LIBZHL_API bool Open();
	
	bool bOpen;
	int activeTouch;
	GL_Texture *background;
	GL_Texture *glowy;
	AnimationTracker glowTracker;
	Button continueButton;
	Button startButton;
	Button helpButton;
	Button statButton;
	Button optionsButton;
	Button creditsButton;
	Button quitButton;
	bool itbButtonActive;
	Button itbButton;
	Animation *itbAnim;
	std::vector<Button*> buttons;
	int finalChoice;
	ShipBuilder shipBuilder;
	bool bScoreScreen;
	OptionsScreen optionScreen;
	bool bSelectSave;
	ConfirmWindow confirmNewGame;
	ChoiceBox changelog;
	bool bCreditScreen;
	char _unk[4];
	CreditScreen credits;
	bool bChangedLogin;
	std::vector<CrewMember*> testCrew;
	bool bChangedScreen;
	std::string error;
	char gap34A4[3];
	char _unk2;
};

struct WorldManager;

struct CApp : CEvent
{
	LIBZHL_API void GenInputEvents();
	LIBZHL_API int OnExecute();
	LIBZHL_API int OnInit();
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API int SetupWindow();
	LIBZHL_API void UpdateFullScreen();
	
	bool Running;
	bool shift_held;
	CommandGui *gui;
	WorldManager *world;
	MainMenu menu;
	LanguageChooser langChooser;
	int screen_x;
	int screen_y;
	int modifier_x;
	int modifier_y;
	bool fullScreenLastState;
	bool minimized;
	bool minLastState;
	bool focus;
	bool focusLastState;
	bool steamOverlay;
	bool steamOverlayLastState;
	bool rendering;
	bool gameLogic;
	float mouseModifier_x;
	float mouseModifier_y;
	GL_FrameBuffer *framebuffer;
	bool fboSupport;
	int x_bar;
	int y_bar;
	bool lCtrl;
	bool useFrameBuffer;
	bool manualResolutionError;
	int manualResErrorX;
	int manualResErrorY;
	bool nativeFullScreenError;
	bool fbStretchError;
	char __NULL[2];
	char lastLanguage[24];
	char inputFocus;
	char useDirect3D;
};

struct CFPS;

struct CFPS
{
	LIBZHL_API float GetSpeedFactor();
	
	float RunningTime;
	char _unk[4];
	double OldTime;
	double LastTime;
	float SpeedFactor;
	int NumFrames;
	int Frames;
	int speedLevel;
};

struct GL_TexVertex
{
	float x;
	float y;
	float u;
	float v;
};

struct CSurface
{
	LIBZHL_API static void __stdcall AddTexVertices(std::vector<GL_TexVertex> *vec, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2);
	LIBZHL_API static bool __stdcall GL_BlitImagePartial(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror);
	LIBZHL_API static void __stdcall GL_BlitMultiImage(GL_Texture *tex, const std::vector<GL_TexVertex> &texVertices, bool antialias);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateImagePartialPrimitive(GL_Texture *tex, float x, float y, float size_x, float size_y, float start_x, float end_x, float start_y, float end_y, float alpha, GL_Color color, bool mirror);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateMultiImagePrimitive(GL_Texture *tex, std::vector<GL_TexVertex> *vec, GL_Color color);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateRectOutlinePrimitive(int x, int y, int w, int h, GL_Color color, float lineWidth);
	LIBZHL_API static GL_Primitive *__stdcall GL_CreateRectPrimitive(float x, float y, float w, float h, GL_Color color);
	LIBZHL_API static void __stdcall GL_DestroyPrimitive(GL_Primitive *primitive);
	LIBZHL_API static bool __stdcall GL_DrawEllipse(int x, int y, int a1, int b1, GL_Color color);
	LIBZHL_API static bool __stdcall GL_DrawRect(float x1, float y1, float x2, float y2, GL_Color color);
	LIBZHL_API static bool __stdcall GL_DrawRectOutline(int x1, int y1, int x2, int y2, GL_Color color, float lineWidth);
	LIBZHL_API static bool __stdcall GL_DrawTriangle(Point vertex1, Point vertex2, Point vertex3, GL_Color color);
	LIBZHL_API static bool __stdcall GL_EnableBlend();
	LIBZHL_API static GL_Color __stdcall GL_GetColor();
	LIBZHL_API static int __stdcall GL_OrthoProjection(float mx1, float mx2, float mx3, float mx4, float mx5, float mx6);
	LIBZHL_API static int __stdcall GL_PushMatrix();
	LIBZHL_API static void __stdcall GL_RemoveColorTint();
	LIBZHL_API static void __stdcall GL_Rotate(float angle, float x, float y, float z = 1.f);
	LIBZHL_API static void __stdcall GL_Scale(float x, float y, float z);
	LIBZHL_API static int __stdcall GL_SetColor(GL_Color color);
	LIBZHL_API static void __stdcall GL_SetColorTint(GL_Color color);
	LIBZHL_API static void __stdcall GL_SetStencilMode(GL_StencilMode stencilMode, int ref, int mask);
	LIBZHL_API static bool __stdcall GL_Translate(float x, float y, float z = 0.f);
	LIBZHL_API static GL_Color __stdcall GetColorTint();
	
};

struct ChoiceReq
{
	std::string object;
	int min_level;
	int max_level;
	int max_group;
	bool blue;
};

struct CloakingSystem;

struct CloakingBox : CooldownSystemBox
{
	std::vector<Button*> buttons;
	Button *currentButton;
	CloakingSystem *cloakSystem;
	Point buttonOffset;
};

struct CloakingSystem : ShipSystem
{
	LIBZHL_API void FiredWeapon();
	
	bool bTurnedOn;
	TimerHelper timer;
	std::string soundeffect;
	AnimationTracker glowTracker;
	GL_Primitive *glowImage;
};

struct CloneSystem;

struct CloneBox : CooldownSystemBox
{
	CloneSystem *cloneSys;
	GL_Texture *pipe[3];
	GL_Texture *boxBottom;
	GL_Texture *boxMiddle;
	GL_Texture *boxTop;
	GL_Texture *boxSolo;
	GL_Texture *boxFill;
	WarningMessage *dyingCrewWarning;
};

struct CloneSystem : ShipSystem
{
	LIBZHL_API CrewMember *CloneReady();
	LIBZHL_API float GetProgress();
	
	float fTimeToClone;
	CrewMember *clone;
	float fTimeGoal;
	float fDeathTime;
	GL_Texture *bottom;
	GL_Texture *top;
	GL_Texture *gas;
	int slot;
	Animation *currentCloneAnimation;
	std::map<std::string, Animation> cloneAnimations;
};

struct CombatControl;

struct DroneControl;

struct DroneControl : ArmamentControl
{
	LIBZHL_API void OnLoop();
	
	WarningMessage droneMessage;
	WarningMessage noTargetMessage;
	WarningMessage systemMessage;
};

struct HandAnimation
{
	GL_Texture *hand;
	Point start;
	Point finish;
	Pointf location;
	bool bRunning;
	float pause;
};

struct WeaponControl;

struct WeaponControl : ArmamentControl
{
	LIBZHL_API bool KeyDown(SDLKey key);
	LIBZHL_API bool LButton(int x, int y, bool holdingShift);
	LIBZHL_API void LinkShip(ShipManager *ship);
	LIBZHL_API void MouseMove(int x, int y);
	LIBZHL_API void OnLanguageChange();
	LIBZHL_API void OnRender(bool unk);
	LIBZHL_API static void __stdcall RenderBeamAiming(Pointf one, Pointf two, bool bAutoFire);
	LIBZHL_API void RenderWarnings();
	LIBZHL_API void SelectArmament(unsigned int armamentSlot);
	LIBZHL_API void SetAutofiring(bool on, bool simple);
	
	Targetable *currentTarget;
	ProjectileFactory *armedWeapon;
	bool autoFiring;
	TextButton autoFireButton;
	GL_Primitive *autoFireBase;
	GL_Primitive *targetIcon[4];
	GL_Primitive *targetIconYellow[4];
	Pointf autoFireFocus;
	WarningMessage missileMessage;
	WarningMessage systemMessage;
	int armedSlot;
};

struct CombatControl
{
	LIBZHL_API void AddEnemyShip(CompleteShip *ship);
	LIBZHL_API char CanTargetSelf();
	LIBZHL_API void Clear();
	LIBZHL_API void DisarmTeleporter();
	LIBZHL_API void DrawHostileBox(GL_Color color, int stencilBit);
	LIBZHL_API std::string GetCrewTooltip(int x, int y);
	LIBZHL_API std::pair<int, int> GetTeleportationCommand();
	LIBZHL_API void KeyDown(SDLKey key);
	LIBZHL_API void MouseClick(int mX, int mY, bool shift);
	LIBZHL_API bool MouseMove(int mX, int mY);
	LIBZHL_API void OnInit(Point pos);
	LIBZHL_API void OnRenderCombat();
	LIBZHL_API void OnRenderSelfAiming();
	LIBZHL_API void UpdateAiming();
	LIBZHL_API bool WeaponsArmed();
	
	CommandGui *gui;
	ShipManager *shipManager;
	Point playerShipPosition;
	SpaceManager *space;
	WeaponControl weapControl;
	DroneControl droneControl;
	std::vector<SystemBox*> sysBoxes;
	std::vector<CompleteShip*> enemyShips;
	CompleteShip *currentTarget;
	SpaceDrone *currentDrone;
	Point position;
	int selectedRoom;
	int selectedSelfRoom;
	Point targetPosition;
	Point boxPosition;
	WindowFrame *hostileBoxFrame;
	CachedImage healthMask;
	CachedImage shieldCircleCharged[5];
	CachedImage shieldCircleUncharged[5];
	CachedImage shieldCircleHacked[5];
	CachedImage shieldCircleHackedCharged[5];
	CachedImage shieldChargeBox;
	CachedImage superShieldBox5;
	CachedImage superShieldBox12;
	bool open;
	float shipIconSize;
	Pointf potentialAiming;
	std::vector<Pointf> aimingPoints;
	Pointf lastMouse;
	bool mouseDown;
	bool isAimingTouch;
	bool movingBeam;
	Point beamMoveLast;
	bool invalidBeamTouch;
	Point screenReposition;
	std::pair<int, int> teleportCommand;
	int iTeleportArmed;
	CachedImage teleportTarget_send;
	CachedImage teleportTarget_return;
	CachedImage hackTarget;
	CachedImage mindTarget;
	AnimationTracker ftl_timer;
	WarningMessage ftlWarning;
	AnimationTracker hacking_timer;
	std::vector<std::string> hackingMessages;
	bool boss_visual;
	bool bTeachingBeam;
	WindowFrame *tipBox;
	HandAnimation hand;
};

struct CombatDrone : SpaceDrone
{
	Pointf lastDestination;
	float progressToDestination;
	float heading;
	float oldHeading;
	CachedImage drone_image_off;
	CachedImage drone_image_charging;
	CachedImage drone_image_on;
	CachedImage engine_image;
};

struct CrewBox;
struct CrewControl;

struct CrewControl
{
	LIBZHL_API void LinkShip(ShipManager *ship);
	LIBZHL_API void OnLoop();
	
	ShipManager *shipManager;
	std::vector<CrewMember*> selectedCrew;
	std::vector<CrewMember*> potentialSelectedCrew;
	Door *selectedDoor;
	Repairable *selectedRepair;
	Point selectedGrid;
	int selectedRoom;
	bool selectedPlayerShip;
	Point availablePosition;
	std::vector<CrewBox*> crewBoxes;
	Point firstMouse;
	Point currentMouse;
	Point worldFirstMouse;
	Point worldCurrentMouse;
	bool mouseDown;
	bool bUpdated;
	int activeTouch;
	char selectingCrew;
	char selectingCrewOnPlayerShip;
	int _unk;
	double selectingCrewStartTime;
	bool doorControlMode;
	bool doorControlOpen;
	bool doorControlOpenSet;
	CombatControl *combatControl;
	unsigned int selectedCrewBox;
	AnimationTracker crewMessage;
	std::string message;
	Button saveStations;
	Button returnStations;
	GL_Primitive *saveStationsBase;
	GL_Primitive *returnStationsBase;
	int stationsLastY;
	int _unk2;
};

struct CrewEquipBox;
struct CrewManifest;

struct DropBox;

struct DropBox
{
	LIBZHL_API int GetBodySpaceOffset();
	LIBZHL_API void OnInit(Point p, bool isSellBox_, TextString *titleText_, TextString *bodyText_, int bodySpace_, TextString *lowerText_);
	LIBZHL_API void OnRender();
	
	Point position;
	bool isSellBox;
	GL_Texture *boxImage[2];
	int selectedImage;
	TextString titleText;
	TextString bodyText;
	int bodySpace;
	TextString lowerText;
	TextString sellText;
	std::string sellCostText;
	int textWidth;
	int insertHeight;
	int titleInsert;
};

struct CrewManifest : FocusWindow
{
	LIBZHL_API void Open();
	LIBZHL_API void Update();
	
	GL_Primitive *box;
	DropBox overBox;
	ShipManager *shipManager;
	std::vector<CrewEquipBox*> crewBoxes;
	InfoBox infoBox;
	int confirmingDelete;
	ConfirmWindow deleteDialog;
};

struct Equipment : FocusWindow
{
	LIBZHL_API void AddDrone(DroneBlueprint *bp, bool free, bool forceCargo);
	LIBZHL_API void AddWeapon(WeaponBlueprint *bp, bool free, bool forceCargo);
	LIBZHL_API bool IsCompletelyFull(int type);
	LIBZHL_API void Jump();
	LIBZHL_API void Open();
	LIBZHL_API void SetPosition(Point p);
	LIBZHL_API void constructor();
	
	GL_Texture *box;
	GL_Texture *storeBox;
	DropBox overBox;
	DropBox overAugImage;
	DropBox sellBox;
	bool bSellingItem;
	uint8_t gap_ex[2];
	ShipManager *shipManager;
	std::vector<EquipmentBox*> vEquipmentBoxes;
	std::vector<ProjectileFactory*> weaponsTrashList;
	EquipmentBox *overcapacityBox;
	AugmentEquipBox *overAugBox;
	int selectedEquipBox;
	int draggingEquipBox;
	int potentialDraggingBox;
	bool bDragging;
	Point firstMouse;
	Point currentMouse;
	Point dragBoxCenter;
	Point dragBoxOffset;
	InfoBox infoBox;
	std::string sellCostText;
	bool bOverCapacity;
	bool bOverAugCapacity;
	bool bStoreMode;
	int cargoId;
	Point infoBoxLoc;
};

struct FTLButton;

struct TextButton0 : GenericButton
{
	GL_Primitive *primitives[3];
	GL_Texture *baseImage;
	Point baseImageOffset;
	GL_Primitive *basePrimitive;
	bool colorsSet;
	unsigned char gap65[3];
	GL_Color colors[3];
	GL_Color textColor;
	Point buttonSize;
	int cornerInset;
	bool autoWidth;
	unsigned char gapB5[3];
	int autoWidthMargin;
	int autoWidthMin;
	bool autoRightAlign;
	unsigned char gapC1[3];
	TextString label;
	int font;
	int lineHeight;
	int textYOffset;
};

struct FTLButton : TextButton0
{
	LIBZHL_API std::string GetPilotTooltip();
	LIBZHL_API void OnRender();
	
	bool autoShrinkText;
	bool ready;
	float ftl_blink;
	float ftl_blink_dx;
	float pullout;
	ShipManager *ship;
	GL_Primitive *baseImage;
	GL_Primitive *baseImageRed;
	GL_Primitive *pulloutBase;
	GL_Primitive *pulloutBaseRed;
	GL_Primitive *pilotOn;
	GL_Primitive *pilotOff1;
	GL_Primitive *pilotOff2;
	GL_Primitive *enginesOn;
	GL_Primitive *enginesOff1;
	GL_Primitive *enginesOff2;
	GL_Texture *FTL_loadingbars;
	GL_Texture *FTL_loadingbars_off;
	GL_Primitive *loadingBars;
	GL_Primitive *loadingBarsOff;
	int lastBarsWidth;
	WarningMessage *enginesDown;
	bool bOutOfFuel;
	bool bBossFight;
	bool bHoverRaw;
	bool bHoverPilot;
	bool bHoverEngine;
};

struct GameOver;

struct GameOver : FocusWindow
{
	LIBZHL_API void OnLoop();
	
	std::vector<TextButton*> buttons;
	GL_Primitive *box;
	int boxWidth;
	int command;
	std::vector<int> commands;
	bool bShowStats;
	Point position;
	std::string gameoverText;
	bool bVictory;
	float openedTimer;
	CreditScreen credits;
	bool bShowingCredits;
};

struct InputBox;

struct InputBox : FocusWindow
{
	LIBZHL_API void TextEvent(CEvent::TextEvent event);
	
	WindowFrame *textBox;
	std::string mainText;
	bool bDone;
	bool bInvertCaps;
	std::string inputText;
	std::vector<std::string> lastInputs;
	int lastInputIndex;
};

struct Location;

struct MenuScreen;

struct MenuScreen : FocusWindow
{
	LIBZHL_API void Open();
	
	GL_Texture *mainImage;
	GL_Primitive *menuPrimitive;
	int menuWidth;
	std::vector<TextButton*> buttons;
	int command;
	std::vector<int> commands;
	Point position;
	ConfirmWindow confirmDialog;
	int tempCommand;
	GenericButton *saveQuit;
	bool bShowControls;
	Point statusPosition;
	GL_Texture *difficultyBox;
	int difficultyWidth;
	std::string difficultyLabel;
	std::string difficultyText;
	GL_Texture *dlcBox;
	int dlcWidth;
	std::string dlcLabel;
	std::string dlcText;
	GL_Texture *achBox;
	GL_Primitive *achBoxPrimitive;
	int achWidth;
	std::string achLabel;
	std::vector<ShipAchievementInfo> shipAchievements;
	int selectedAch;
	InfoBox info;
};

struct ShipStatus;
struct WarningWithLines;

struct ShipStatus
{
	LIBZHL_API void OnInit(Point location, float size);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void RenderEvadeOxygen(bool renderText);
	LIBZHL_API void RenderHealth(bool renderText);
	LIBZHL_API void RenderResources(bool renderText);
	
	Point location;
	float size;
	ShipManager *ship;
	CombatControl *combat;
	GL_Primitive *hullBox;
	GL_Primitive *hullBox_Red;
	GL_Primitive *shieldBox_On;
	GL_Primitive *shieldBox_Off;
	GL_Primitive *shieldBox_Red;
	GL_Primitive *shieldCircleCharged[4];
	GL_Primitive *shieldCircleUncharged[4];
	GL_Primitive *shieldCircleHacked[4];
	GL_Primitive *shieldCircleHackedCharged[4];
	GL_Primitive *energyShieldBox;
	GL_Primitive *energyShieldBar[5];
	GL_Texture *hullLabel;
	GL_Texture *hullLabel_Red;
	GL_Primitive *shieldBoxPurple;
	GL_Primitive *oxygenPurple;
	GL_Primitive *evadePurple;
	GL_Primitive *evadeOxygenBox;
	GL_Primitive *evadeOxygenBox_topRed;
	GL_Primitive *evadeOxygenBox_bottomRed;
	GL_Primitive *evadeOxygenBox_bothRed;
	GL_Primitive *fuelIcon;
	GL_Primitive *missilesIcon;
	GL_Primitive *dronesIcon;
	GL_Primitive *scrapIcon;
	GL_Primitive *fuelIcon_red;
	GL_Primitive *missilesIcon_red;
	GL_Primitive *dronesIcon_red;
	GL_Primitive *scrapIcon_red;
	GL_Primitive *healthMask;
	GL_Texture *healthMaskTexture;
	int lastHealth;
	Globals::Ellipse baseShield;
	int currentHover;
	Point evadeOxygenBoxLocation;
	int lastFuel;
	int lastDrones;
	int lastScrap;
	int lastMissiles;
	int lastHull;
	WarningWithLines *hullMessage;
	WarningMessage *shieldMessage;
	WarningMessage *oxygenMessage;
	WarningMessage *boardingMessage;
	std::vector<DamageMessage*> resourceMessages;
	AnimationTracker noMoneyTracker;
	AnimationTracker flashTracker;
	bool bBossFight;
	bool bEnemyShip;
	Point noShipShift;
	Point intruderShift;
	Point energyShieldPos;
	Point intruderPos;
};

struct SpaceStatus;

struct SpaceStatus
{
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void OnInit(SpaceManager *space, Point pos);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	
	GL_Primitive *warningImages[10];
	WarningMessage *warningMessage;
	WarningMessage *incomingFire;
	Globals::Rect hitbox;
	Globals::Rect hitbox2;
	int currentEffect;
	int currentEffect2;
	SpaceManager *space;
	Point position;
	int touchedTooltip;
};

struct StarMap;
struct Store;

struct SystemControl;

struct SystemControl
{
	struct PowerBars
	{
		GL_Primitive *normal[30];
		GL_Primitive *tiny[30];
		GL_Primitive *empty[30];
		GL_Primitive *damaged[30];
	};
	
	LIBZHL_API void OnRender(bool front);
	
	ShipManager *shipManager;
	CombatControl *combatControl;
	std::vector<SystemBox*> sysBoxes;
	Globals::Rect SystemPower;
	bool bSystemPowerHover;
	Point position;
	Point systemPowerPosition;
	Point subSystemPosition;
	GL_Primitive *wiresImage;
	GL_Primitive *wiresMask;
	GL_Primitive *noButton;
	GL_Primitive *button;
	GL_Primitive *noButton_cap;
	GL_Primitive *button_cap;
	GL_Primitive *drone;
	GL_Primitive *drone3;
	GL_Primitive *drone2;
	GL_Primitive *sub_box;
	int sub_spacing;
	WarningMessage *notEnoughPower;
	AnimationTracker flashBatteryPower;
	AnimationTracker flashTracker;
};

struct TabbedWindow;

struct TabbedWindow : FocusWindow
{
	LIBZHL_API void Close();
	LIBZHL_API void SetTab(unsigned int tab);
	
	std::vector<Button*> buttons;
	std::vector<FocusWindow*> windows;
	std::vector<std::string> names;
	unsigned int currentTab;
	int buttonType;
	TextButton doneButton;
	Point move;
	bool bBlockClose;
	bool bTutorialMode;
	bool bWindowLock;
};

struct ReactorButton;

struct ReactorButton : Button
{
	LIBZHL_API void OnClick();
	LIBZHL_API void OnRender();
	
	int tempUpgrade;
	ShipManager *ship;
	bool selected;
};

struct UpgradeBox;
struct Upgrades;

struct Upgrades : FocusWindow
{
	LIBZHL_API void OnInit(ShipManager *ship);
	LIBZHL_API void OnLoop();
	
	GL_Texture *box;
	std::vector<UpgradeBox*> vUpgradeBoxes;
	ShipManager *shipManager;
	TextButton undoButton;
	ReactorButton reactorButton;
	InfoBox infoBox;
	Point infoBoxLoc;
	int systemCount;
	int forceSystemInfoWidth;
};

struct CommandGui
{
	LIBZHL_API void CheckGameover();
	LIBZHL_API void ClearLocation();
	LIBZHL_API bool IsGameOver();
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void OnInit();
	LIBZHL_API void RenderPlayerShip(Point &shipCenter, float jumpScale);
	LIBZHL_API void RenderStatic();
	LIBZHL_API void Restart();
	LIBZHL_API void RunCommand(std::string &command);
	
	ShipStatus shipStatus;
	CrewControl crewControl;
	SystemControl sysControl;
	CombatControl combatControl;
	FTLButton ftlButton;
	SpaceStatus spaceStatus;
	StarMap *starMap;
	CompleteShip *shipComplete;
	std::vector<FocusWindow*> focusWindows;
	Point pauseTextLoc;
	GL_Primitive *pauseImage;
	GL_Primitive *pauseImage2;
	GL_Primitive *pauseImageAuto;
	GL_Primitive *pauseCrewImage;
	GL_Primitive *pauseDoorsImage;
	GL_Primitive *pauseHackingImage;
	GL_Primitive *pauseMindImage;
	GL_Primitive *pauseRoomImage;
	GL_Primitive *pauseTargetImage;
	GL_Primitive *pauseTargetBeamImage;
	GL_Primitive *pauseTeleportLeaveImage;
	GL_Primitive *pauseTeleportArriveImage;
	GL_Primitive *flareImage;
	Point shipPosition;
	std::string locationText;
	std::string loadEvent;
	int loadSector;
	ChoiceBox choiceBox;
	bool gameover;
	bool alreadyWon;
	bool outOfFuel;
	MenuScreen menuBox;
	GameOver gameOverScreen;
	OptionsScreen optionsBox;
	bool bPaused;
	bool bAutoPaused;
	bool menu_pause;
	bool event_pause;
	bool touch_pause;
	int touchPauseReason;
	InputBox inputBox;
	float fShakeTimer;
	TabbedWindow shipScreens;
	TabbedWindow storeScreens;
	Upgrades upgradeScreen;
	CrewManifest crewScreen;
	Equipment equipScreen;
	Location *newLocation;
	SpaceManager *space;
	Button upgradeButton;
	WarningMessage upgradeWarning;
	TextButton storeButton;
	Button optionsButton;
	const float pause_anim_time;
	float pause_animation;
	std::vector<Store*> storeTrash;
	TimerHelper flickerTimer;
	TimerHelper showTimer;
	bool bHideUI;
	CompleteShip *enemyShip;
	bool waitLocation;
	bool lastLocationWait;
	bool dangerLocation;
	std::vector<int> commandKey;
	bool jumpComplete;
	int mapId;
	ConfirmWindow leaveCrewDialog;
	bool secretSector;
	int activeTouch;
	bool activeTouchIsButton;
	bool activeTouchIsCrewBox;
	bool activeTouchIsShip;
	bool activeTouchIsNull;
	std::vector<int> extraTouches;
	bool bTutorialWasRunning;
	bool focusAteMouse;
	bool choiceBoxOpen;
	int systemDetailsWidth;
	ChoiceBox writeErrorDialog;
	bool suppressWriteError;
};

struct CrewLaser : Projectile
{
	int r;
	int g;
	int b;
};

struct Particle
{
	float position_x;
	float position_y;
	float speed_x;
	float speed_y;
	float acceleration_x;
	float acceleration_y;
	float lifespan;
	bool alive;
};

struct ParticleEmitter
{
	Particle particles[64];
	float birthRate;
	float birthCounter;
	float lifespan;
	float speedMag;
	float position_x;
	float position_y;
	float max_dx;
	float min_dx;
	float max_dy;
	float min_dy;
	int image_x;
	int image_y;
	GL_Primitive *primitive;
	float emitAngle;
	bool randAngle;
	bool running;
	float maxAlpha;
	float minSize;
	float maxSize;
	int currentCount;
};

struct LIBZHL_INTERFACE CrewAnimation
{
	virtual ~CrewAnimation() {}
	LIBZHL_API virtual void OnRender(float scale, int selectedState, bool outlineOnly);
	virtual void OnRenderProps() LIBZHL_PLACEHOLDER
	virtual void OnUpdateEffects() LIBZHL_PLACEHOLDER
	virtual void UpdateFiring() LIBZHL_PLACEHOLDER
	virtual void UpdateShooting() LIBZHL_PLACEHOLDER
	virtual bool FireShot() LIBZHL_PLACEHOLDER
	virtual int GetFiringFrame() LIBZHL_PLACEHOLDER
	virtual std::string GetShootingSound() LIBZHL_PLACEHOLDER
	virtual std::string GetDeathSound() LIBZHL_PLACEHOLDER
	virtual void Restart() LIBZHL_PLACEHOLDER
	virtual bool CustomDeath() LIBZHL_PLACEHOLDER
	LIBZHL_API void RenderIcon(bool border);
	LIBZHL_API void SetupStrips();
	
	int iShipId;
	std::vector<std::vector<Animation>> anims;
	GL_Texture *baseStrip;
	GL_Texture *colorStrip;
	std::vector<GL_Texture*> layerStrips;
	Pointf lastPosition;
	int direction;
	int sub_direction;
	int status;
	int moveDirection;
	ParticleEmitter smokeEmitter;
	bool bSharedSpot;
	uint8_t gap_ex_1[2];
	std::vector<CrewLaser> shots;
	TimerHelper shootTimer;
	TimerHelper punchTimer;
	Pointf target;
	float fDamageDone;
	bool bPlayer;
	bool bFrozen;
	bool bDrone;
	bool bGhost;
	bool bExactShooting;
	Animation projectile;
	bool bTyping;
	std::string race;
	int currentShip;
	bool bMale;
	bool colorblind;
	uint8_t gap_ex_2[2];
	std::vector<GL_Color> layerColors;
	int forcedAnimation;
	int forcedDirection;
	GL_Color projectileColor;
	bool bStunned;
	bool bDoorTarget;
	bool uniqueBool1;
	bool uniqueBool2;
};

struct CrewBox
{
	LIBZHL_API void RenderCloneDying();
	LIBZHL_API void RenderIcon();
	LIBZHL_API void RenderLabels();
	LIBZHL_API void constructor(Point pos, CrewMember *crew, int number);
	
	Globals::Rect box;
	Globals::Rect skillBox;
	CrewMember *pCrew;
	bool mouseHover;
	uint8_t gap_ex_1[2];
	TextButton powerButton;
	int number;
	bool bSelectable;
	uint8_t gap_ex_2[2];
	AnimationTracker flashHealthTracker;
	GL_Primitive *boxBackground;
	GL_Primitive *boxOutline;
	GL_Primitive *skillBoxBackground;
	GL_Primitive *skillBoxOutline;
	GL_Primitive *cooldownBar;
	CachedImage healthWarning;
	int lastCooldownHeight;
	GL_Primitive *healthBar;
	int lastHealthWidth;
	Animation mindControlled;
	Animation stunned;
	bool hideExtra;
	std::string sTooltip;
};

struct CrewEquipBox : EquipmentBox
{
	LIBZHL_API bool GetConfirmDelete();
	LIBZHL_API void constructor(Point pos, ShipManager *ship, int slot);
	
	ShipManager *ship;
	bool bDead;
	TextButton deleteButton;
	TextButton renameButton;
	bool bShowDelete;
	bool bShowRename;
	bool bQuickRenaming;
	TextInput nameInput;
	GL_Primitive *box;
	GL_Primitive *box_on;
	bool bConfirmDelete;
};

struct CrewCustomizeBox : CrewEquipBox
{
	LIBZHL_API void constructor(Point location, ShipManager *shipManager, int slot);
	
	TextButton customizeButton;
	bool bCustomizing;
	Point customizeLocation;
	TextButton acceptButton;
	TextButton bigRenameButton;
	Button leftButton;
	Button rightButton;
	bool bRenaming;
	bool haveCustomizeTouch;
	bool customizeActivated;
	GL_Primitive *box;
	GL_Primitive *box_on;
	GL_Texture *bigBox;
};

struct CrewDesc
{
	std::string type;
	float prop;
	int amount;
};

struct CrewMemberFactory;

struct CrewMemberFactory
{
	LIBZHL_API void GetCloneReadyList(std::vector<CrewMember*> &vec, bool player);
	LIBZHL_API int GetCrewCount(bool enemy);
	LIBZHL_API void GetCrewList(std::vector<CrewMember*> *vec, int unk, bool unk2);
	LIBZHL_API static bool __stdcall IsRace(const std::string &species);
	
	int playerCrew;
	int enemyCrew;
	int enemyCloneCount;
	std::vector<CrewMember*> crewMembers;
	std::vector<CrewMember*> lostMembers;
};

struct CrewStatTracker
{
	int max;
	std::string name;
	std::string species;
	bool male;
	std::string title_id;
	bool newStat;
};

struct CrewStoreBox : StoreBox
{
	std::string name;
	Animation crewPortrait;
	CrewBlueprint blueprint;
};

struct LIBZHL_INTERFACE CrewTarget
{
	virtual ~CrewTarget() {}
	virtual Point GetPosition() LIBZHL_PLACEHOLDER
	virtual float PositionShift() LIBZHL_PLACEHOLDER
	virtual bool InsideRoom(int roomId) LIBZHL_PLACEHOLDER
	virtual bool ApplyDamage(float damage) LIBZHL_PLACEHOLDER
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	int iShipId;
};

struct CrystalAlien : CrewMember
{
	std::pair<float, float> powerCooldown;
};

struct CrystalAnimation
{
};

struct DamageMessage
{
	AnimationTracker tracker;
	Pointf position;
	GL_Color color;
	bool bFloatDown;
	std::vector<GL_Primitive*> primitives;
};

struct DebugHelper
{
};

struct DefenseDrone;

struct DefenseDrone : SpaceDrone
{
	LIBZHL_API void OnLoop();
	
	int currentTargetId;
	int shotAtTargetId;
	float currentSpeed;
	CachedImage drone_image;
	CachedImage gun_image_off;
	CachedImage gun_image_charging;
	CachedImage gun_image_on;
	CachedImage engine_image;
	int currentTargetType;
};

struct DistressButton : TextButton
{
	TextString labels[2];
	bool state;
};

struct Selectable;

struct LIBZHL_INTERFACE Selectable
{
	virtual ~Selectable() {}
	virtual void SetSelected(int selected) LIBZHL_PLACEHOLDER
	virtual int GetSelected() LIBZHL_PLACEHOLDER
	int selectedState;
};

struct Door : CrewTarget
{
	LIBZHL_API void FakeClose();
	LIBZHL_API void LoadState(int fd);
	LIBZHL_API void OnRender(float alpha, bool bForceView, bool useLargeSprites);
	LIBZHL_API void SaveState(int fd);
	LIBZHL_API void SetBlastDoor(int val);
	
	Selectable _selectable;
	int iRoom1;
	int iRoom2;
	bool bOpen;
	uint8_t gap_ex_1[3];
	int iBlast;
	bool bFakeOpen;
	uint8_t gap_ex_2[3];
	int width;
	int height;
	GL_Primitive *outlinePrimitive;
	GL_Primitive *highlightPrimitive;
	Animation doorAnim;
	Animation doorAnimLarge;
	int iDoorId;
	int baseHealth;
	int health;
	AnimationTracker forcedOpen;
	AnimationTracker gotHit;
	int doorLevel;
	bool bIoned;
	float fakeOpenTimer;
	AnimationTracker lockedDown;
	float lastbase;
	int iHacked;
	int x;
	int y;
	bool bVertical;
};

struct DoorBox : SystemBox
{
	GL_Texture *box;
	Button openDoors;
	Button closeDoors;
	ShipManager *ship;
	Point buttonOffset;
};

struct DroneBox : ArmamentBox
{
	Drone *pDrone;
};

struct DroneEquipBox : EquipmentBox
{
};

struct DroneStoreBox : StoreBox
{
	DroneBlueprint *blueprint;
};

struct DroneSystem : ShipSystem
{
	LIBZHL_API static int __stdcall StringToDrone(std::string &name);
	
	std::vector<Drone*> drones;
	int drone_count;
	int drone_start;
	Targetable *targetShip;
	std::vector<bool> userPowered;
	int slot_count;
	int iStartingBatteryPower;
	std::vector<bool> repowerList;
};

struct LIBZHL_INTERFACE EnergyAlien
{
	virtual ~EnergyAlien() {}
	virtual Point GetPosition() LIBZHL_PLACEHOLDER
	virtual float PositionShift() LIBZHL_PLACEHOLDER
	virtual bool InsideRoom(int roomId) LIBZHL_PLACEHOLDER
	virtual bool ApplyDamage(float damage) LIBZHL_PLACEHOLDER
	virtual int GetPriority() LIBZHL_PLACEHOLDER
	virtual bool ValidTarget(int unk) LIBZHL_PLACEHOLDER
	virtual bool MultiShots() LIBZHL_PLACEHOLDER
	virtual bool ExactTarget() LIBZHL_PLACEHOLDER
	virtual bool IsCrew() LIBZHL_PLACEHOLDER
	virtual bool IsCloned() LIBZHL_PLACEHOLDER
	virtual bool IsDrone() LIBZHL_PLACEHOLDER
	virtual void Jump() LIBZHL_PLACEHOLDER
	virtual bool GetIntruder() LIBZHL_PLACEHOLDER
	virtual void SaveState(int fileHelper) LIBZHL_PLACEHOLDER
	virtual void LoadState(int fileHelper) LIBZHL_PLACEHOLDER
	virtual void OnLoop() LIBZHL_PLACEHOLDER
	virtual void OnRender(bool unk) LIBZHL_PLACEHOLDER
	virtual bool OutOfGame() LIBZHL_PLACEHOLDER
	virtual void SetOutOfGame() LIBZHL_PLACEHOLDER
	virtual bool Functional() LIBZHL_PLACEHOLDER
	virtual bool CountForVictory() LIBZHL_PLACEHOLDER
	virtual bool GetControllable() LIBZHL_PLACEHOLDER
	virtual bool ReadyToFight() LIBZHL_PLACEHOLDER
	virtual bool CanFight() LIBZHL_PLACEHOLDER
	virtual bool CanRepair() LIBZHL_PLACEHOLDER
	virtual bool CanSabotage() LIBZHL_PLACEHOLDER
	virtual bool CanMan() LIBZHL_PLACEHOLDER
	virtual bool CanTeleport() LIBZHL_PLACEHOLDER
	virtual bool CanHeal() LIBZHL_PLACEHOLDER
	virtual bool CanSuffocate() LIBZHL_PLACEHOLDER
	virtual bool CanBurn() LIBZHL_PLACEHOLDER
	virtual int GetMaxHealth() LIBZHL_PLACEHOLDER
	virtual bool IsDead() LIBZHL_PLACEHOLDER
	virtual bool PermanentDeath() LIBZHL_PLACEHOLDER
	virtual bool ShipDamage(float damage) LIBZHL_PLACEHOLDER
	virtual bool FireFightingSoundEffect() LIBZHL_PLACEHOLDER
	virtual std::string GetUniqueRepairing() LIBZHL_PLACEHOLDER
	virtual bool ProvidesVision() LIBZHL_PLACEHOLDER
	virtual float GetMoveSpeedMultiplier() LIBZHL_PLACEHOLDER
	virtual float GetRepairSpeed() LIBZHL_PLACEHOLDER
	virtual float GetDamageMultiplier() LIBZHL_PLACEHOLDER
	virtual bool ProvidesPower() LIBZHL_PLACEHOLDER
	virtual std::string GetSpecies() LIBZHL_PLACEHOLDER
	virtual float GetFireRepairMultiplier() LIBZHL_PLACEHOLDER
	virtual bool IsTelepathic() LIBZHL_PLACEHOLDER
	virtual std::pair<float, float> GetPowerCooldown() LIBZHL_PLACEHOLDER
	virtual bool PowerReady() LIBZHL_PLACEHOLDER
	virtual void ActivatePower() LIBZHL_PLACEHOLDER
	virtual bool HasSpecialPower() LIBZHL_PLACEHOLDER
	virtual void ResetPower() LIBZHL_PLACEHOLDER
	virtual float GetSuffocationMultiplier() LIBZHL_PLACEHOLDER
	virtual int BlockRoom() LIBZHL_PLACEHOLDER
	virtual Damage GetRoomDamage() LIBZHL_PLACEHOLDER
	virtual bool IsAnaerobic() LIBZHL_PLACEHOLDER
	virtual void UpdateRepair() LIBZHL_PLACEHOLDER
	virtual bool CanStim() LIBZHL_PLACEHOLDER
	int iShipId;
	float x;
	float y;
	float size;
	float scale;
	float goal_x;
	float goal_y;
	int width;
	int height;
	std::pair<float, float> health;
	float speed_x;
	float speed_y;
	Path path;
	bool new_path;
	float x_destination;
	float y_destination;
	Door *last_door;
	Repairable *currentRepair;
	bool bSuffocating;
	int moveGoal;
	int selectionState;
	int iRoomId;
	int iManningId;
	int iRepairId;
	int iStackId;
	Slot currentSlot;
	bool intruder;
	bool bFighting;
	bool bSharedSpot;
	CrewAnimation *crewAnim;
	GL_Texture *selectionImage;
	CachedImage healthBox;
	CachedImage healthBoxRed;
	CachedRect healthBar;
	float fMedbay;
	float lastDamageTimer;
	float lastHealthChange;
	int currentShipId;
	AnimationTracker flashHealthTracker;
	Pointf currentTarget;
	CrewTarget *crewTarget;
	BoardingGoal boardingGoal;
	bool bFrozen;
	bool bFrozenLocation;
	CrewTask task;
	std::string type;
	Ship *ship;
	Slot finalGoal;
	Door *blockingDoor;
	bool bOutOfGame;
	std::string species;
	bool bDead;
	uint8_t gap_ex_1[2];
	int iOnFire;
	bool bActiveManning;
	ShipSystem *currentSystem;
	int usingSkill;
	CrewBlueprint blueprint;
	Animation healing;
	Animation stunned;
	AnimationTracker levelUp;
	int lastLevelUp;
	SCrewStats stats;
	std::vector<std::vector<bool>> skillsEarned;
	bool clone_ready;
	bool bMindControlled;
	int iDeathNumber;
	Animation mindControlled;
	Animation stunIcon;
	std::vector<std::vector<AnimationTracker>> skillUp;
	int healthBoost;
	float fMindDamageBoost;
	float fCloneDying;
	bool bResisted;
	uint8_t gap_ex_2[2];
	Slot savedPosition;
	float fStunTime;
	CachedImage movementTarget;
	bool bCloned;
	bool bTriggerExplosion;
	bool bExploded;
};

struct EnergyAnimation
{
};

struct EngiAlien
{
};

struct EngiAnimation
{
};

struct EngineSystem
{
};

struct EventDamage
{
	int system;
	int amount;
	int effect;
};

struct EventGenerator;
struct EventTemplate;

struct EventText
{
	TextString text;
	std::string planet;
	std::string back;
};

struct SectorDescription
{
	std::vector<std_pair_std_string_RandomAmount> eventCounts;
	std::vector<std_pair_std_string_int> rarities;
	bool unique;
	std::vector<TextString> names;
	std::vector<TextString> shortNames;
	std::vector<std::string> musicTracks;
	std::string type;
	TextString name;
	TextString shortName;
	int minSector;
	bool used;
	std::string firstEvent;
};

struct ShipEvent
{
	bool present;
	std::string name;
	std::string blueprint;
	std::string auto_blueprint;
	std::vector<std::string> blueprintList;
	ShipBlueprint actualBlueprint;
	bool hostile;
	std::string surrender;
	std::string escape;
	std::string destroyed;
	std::string deadCrew;
	std::string gotaway;
	int escapeTimer;
	RandomAmount surrenderThreshold;
	RandomAmount escapeThreshold;
	std::vector<CrewDesc> crewOverride;
	std::vector<std::string> weaponOverride;
	int weaponOverCount;
	std::vector<std::string> droneOverride;
	int droneOverCount;
	int shipSeed;
};

struct EventGenerator
{
	LIBZHL_API LocationEvent *CreateEvent(const std::string &name, int worldLevel, bool ignoreUnique);
	LIBZHL_API std::string GetImageFromList(const std::string &listName);
	
	std::vector<std::string> baseEvents;
	std::unordered_map<std::string, SectorDescription> sectors;
	std::unordered_map<std::string, std::vector<std::string>> baseSectors;
	std::unordered_map<std::string, std::vector<std::string>> eventLists;
	std::unordered_map<std::string, EventTemplate*> events;
	std::unordered_map<std::string, EventTemplate*> usedEvents;
	std::unordered_map<std::string, std::vector<EventText>> textLists;
	std::unordered_map<std::string, std::vector<EventText>> usedTextLists;
	std::unordered_map<std::string, std::vector<std::string>> shipTemplateLists;
	std::unordered_map<std::string, ShipEvent> shipTemplates;
	std::unordered_map<std::string, std::vector<std::string>> imageLists;
	std::vector<LocationEvent*> trashList;
	std::unordered_map<std::string, ResourceEvent> resourcesCollected;
	std::unordered_map<std::string, int> eventTypesCreated;
	int shipsCreated;
	bool shiplessEvent;
	bool creatingShipEvent;
	int forceRandomIndex;
};

struct EventSystem;

struct EventSystem
{
	LIBZHL_API void AddEvent(int id);
	
	std::vector<int> lastEvents;
	std::vector<int> newEvents;
};

struct ResourcesTemplate
{
	RandomAmount fuel;
	RandomAmount drones;
	RandomAmount missiles;
	RandomAmount scrap;
	RandomAmount items;
	int crew;
	std::string crewType;
	TextString crewName;
	bool cloneable;
	TextString cloneText;
	std::vector<std_pair_int_int> crewSkills;
	std::string weapon;
	std::string drone;
	std::string augment;
	std::string system;
	bool steal;
	int upgradeAmount;
	int upgradeId;
	std::string removeItem;
};

struct RewardDesc
{
	std::string reward;
	int level;
};

struct ShipTemplate
{
	std::string shipEventName;
	bool hostile;
};

struct StatusEffect
{
	int type;
	int system;
	int amount;
	int target;
};

struct EventTemplate
{
	struct ChoiceTemplate
	{
		TextString text;
		bool loadText;
		std::string eventName;
		bool hiddenReward;
		ChoiceReq requirement;
	};
	
	ResourcesTemplate resources;
	RewardDesc reward;
	TextString text;
	bool loadText;
	bool unique;
	ShipTemplate shipTemplate;
	std::string eventName;
	std::vector<EventDamage> damage;
	int environmentFlag;
	int environmentTarget;
	bool store;
	bool repair;
	bool reveal_map;
	std::vector<StatusEffect> statusEffects;
	bool distressBeacon;
	BoardingEvent boarders;
	int modifyPursuit;
	std::vector<ChoiceTemplate> choices;
	std::vector<std_pair_std_string_std_string> nameDefinitions;
	std::string imageBackground;
	std::string imagePlanet;
	std::string quest;
	TextString unlockShipText;
	int unlockShip;
	int fleet;
	bool secretSector;
};

struct EventsParser;

struct EventsParser
{
	LIBZHL_API void AddAllEvents();
	LIBZHL_API void ProcessBaseNode(rapidxml::xml_node<char> *node, EventGenerator &generator);
	LIBZHL_API std::string ProcessEvent(rapidxml::xml_node<char> *node, const std::string &eventName);
	LIBZHL_API std::vector<std::string> ProcessEventList(rapidxml::xml_node<char> *node, const std::string &listName);
	LIBZHL_API RandomAmount PullMinMax(rapidxml::xml_node<char> *node, const std::string &name);
	
	std::unordered_map<std::string, EventTemplate*> eventTemplates;
	std::vector<EventTemplate*> trashList;
	std::unordered_map<std::string, ShipEvent> shipTemplates;
};

struct ExplosionAnimation : AnimationTracker
{
	ShipObject shipObj;
	std::vector<Animation> explosions;
	std::vector<GL_Texture*> pieces;
	std::vector<std::string> pieceNames;
	std::vector<float> rotationSpeed;
	std::vector<float> rotation;
	std::vector<std_pair_float_float> rotationSpeedMinMax;
	std::vector<Pointf> movementVector;
	std::vector<Pointf> position;
	std::vector<Pointf> startingPosition;
	float explosionTimer;
	float soundTimer;
	bool bFinalBoom;
	bool bJumpOut;
	std::vector<WeaponAnimation*> weaponAnims;
	Point pos;
};

struct FileHelper
{
	LIBZHL_API static void __stdcall closeBinaryFile(int file);
	LIBZHL_API static bool __stdcall fileExists(const std::string &fileName);
	LIBZHL_API static std::string __stdcall getResourceFile();
	LIBZHL_API static std::string __stdcall getSaveFile();
	LIBZHL_API static void __stdcall initFileHelper();
	LIBZHL_API static int __stdcall readBinaryFile(const std::string &fileName);
	LIBZHL_API static char *__stdcall readBuffer(int file, int len, bool nullTerminate);
	LIBZHL_API static float __stdcall readFloat(int file);
	LIBZHL_API static int __stdcall readInteger(int file);
	LIBZHL_API static std::string __stdcall readString(int file);
	LIBZHL_API static bool __stdcall writeFloat(int file, float data);
	LIBZHL_API static bool __stdcall writeInt(int file, int data);
	LIBZHL_API static bool __stdcall writeString(int file, const std::string &data);
	
};

struct LIBZHL_INTERFACE Repairable : Selectable
{
	virtual ~Repairable() {}
	virtual bool CompletelyDestroyed() LIBZHL_PLACEHOLDER
	virtual std::string GetName() LIBZHL_PLACEHOLDER
	virtual void SetName(std::string &name) LIBZHL_PLACEHOLDER
	virtual void Repair() LIBZHL_PLACEHOLDER
	virtual void PartialRepair(float speed, bool autoRepair) LIBZHL_PLACEHOLDER
	virtual void PartialDamage(float amount) LIBZHL_PLACEHOLDER
	virtual bool NeedsRepairing() LIBZHL_PLACEHOLDER
	virtual bool Functioning() LIBZHL_PLACEHOLDER
	virtual bool CanBeSabatoged() LIBZHL_PLACEHOLDER
	virtual float GetDamage() LIBZHL_PLACEHOLDER
	virtual Point GetLocation() LIBZHL_PLACEHOLDER
	virtual Point GetGridLocation() LIBZHL_PLACEHOLDER
	virtual void SetDamage(float diff) LIBZHL_PLACEHOLDER
	virtual void SetMaxDamage(float dam) LIBZHL_PLACEHOLDER
	virtual void SetLocation(Point location) LIBZHL_PLACEHOLDER
	virtual void OnRenderHighlight() LIBZHL_PLACEHOLDER
	virtual int GetId() LIBZHL_PLACEHOLDER
	virtual bool IsRoomBased() LIBZHL_PLACEHOLDER
	virtual int GetRoomId() LIBZHL_PLACEHOLDER
	virtual bool Ioned(int amount) LIBZHL_PLACEHOLDER
	virtual void SetRoomId() LIBZHL_PLACEHOLDER
	ShipObject shipObj;
	float fDamage;
	Point pLoc;
	float fMaxDamage;
	std::string name;
	int roomId;
	int iRepairCount;
};

struct Spreadable : Repairable
{
	std::string soundName;
};

struct Fire : Spreadable
{
	float fDeathTimer;
	float fStartTimer;
	float fOxygen;
	Animation fireAnimation;
	Animation smokeAnimation;
	bool bWasOnFire;
};

struct GL_ColorTexVertex
{
	float x;
	float y;
	float u;
	float v;
	float r;
	float g;
	float b;
	float a;
};

struct GL_FrameBuffer
{
};

struct GL_Line
{
	Pointf start;
	Pointf end;
};

struct GL_Primitive
{
	int type;
	float lineWidth;
	bool hasTexture;
	GL_Texture *texture;
	bool textureAntialias;
	bool hasColor;
	GL_Color color;
	int id;
};

struct GL_Texture
{
	int id_;
	int width_;
	int height_;
	bool isLogical_;
	float u_base_;
	float v_base_;
	float u_size_;
	float v_size_;
};

struct Ghost
{
};

struct HackBox;
struct HackingSystem;

struct HackBox : CooldownSystemBox
{
	LIBZHL_API void constructor(Point pos, HackingSystem *sys, ShipManager *ship);
	
	HackingSystem *hackSys;
	std::vector<Button*> buttons;
	Button *currentButton;
	Point buttonOffset;
	GL_Texture *box;
	GL_Texture *box2;
	Button hackButton;
	Button overlayButton;
	ShipManager *shipManager;
	AnimationTracker flashTracker;
	WarningMessage *superShieldWarning;
};

struct HackingDrone : SpaceDrone
{
	Pointf startingPosition;
	GL_Texture *droneImage_on;
	GL_Texture *droneImage_off;
	GL_Texture *lightImage;
	Pointf finalDestination;
	bool arrived;
	bool finishedSetup;
	AnimationTracker flashTracker;
	Animation flying;
	Animation extending;
	Animation explosion;
	int prefRoom;
};

struct HackingSystem : ShipSystem
{
	LIBZHL_API bool SoundLoop();
	
	bool bHacking;
	HackingDrone drone;
	bool bBlocked;
	bool bArmed;
	ShipSystem *currentSystem;
	std::pair<float, float> effectTimer;
	bool bCanHack;
	ShipSystem *queuedSystem;
	int spendDrone;
};

struct HotkeyDesc
{
	std::string name;
	int key;
};

struct ImageDesc
{
	GL_Texture *tex;
	int resId;
	int w;
	int h;
	int x;
	int y;
	int rot;
};

struct InputEventUnion
{
	char eventData[20];
};

struct InputEvent
{
	InputEventType type;
	InputEventDetail detail;
	double timestamp;
	InputEventUnion event;
};

struct IonDrone : BoarderDrone
{
	int lastRoom;
};

struct IonDroneAnimation : CrewAnimation
{
	Animation ionExplosion;
	Animation ionAnimation;
	Animation doorAnimations[4];
	Animation ionGlow;
	float ionEffect;
	bool damagedDoor;
};

struct ItemStoreBox;

struct ItemStoreBox : StoreBox
{
	LIBZHL_API void constructor(ShipManager *ship, const std::string &resourceName);
	
	ItemBlueprint *blueprint;
};

struct JoystickInputEvent
{
	int device;
	int index;
	float x;
	float y;
};

struct KeyboardInputEvent
{
	int key;
	int system_key;
	unsigned int modifiers;
	char is_repeat;
};

struct LaserBlast;

struct LaserBlast : Projectile
{
	LIBZHL_API void OnInit();
	
	Targetable *movingTarget;
	float spinAngle;
	float spinSpeed;
};

struct Location
{
	Pointf loc;
	std::vector<Location*> connectedLocations;
	bool beacon;
	bool known;
	int visited;
	bool dangerZone;
	bool newSector;
	bool nebula;
	bool boss;
	LocationEvent *event;
	ImageDesc planet;
	ImageDesc space;
	ImageDesc beaconImage;
	GL_Texture *imageId;
	bool questLoc;
	AnimationTracker flashTracker;
	bool fleetChanging;
	std::string planetImage;
	std::string spaceImage;
};

struct LocationEvent
{
	struct Choice
	{
		LocationEvent *event;
		TextString text;
		ChoiceReq requirement;
		bool hiddenReward;
	};
	
	LIBZHL_API void ClearEvent(bool force);
	
	TextString text;
	ShipEvent ship;
	ResourceEvent stuff;
	int environment;
	int environmentTarget;
	bool store;
	bool gap_ex_cleared;
	int fleetPosition;
	bool beacon;
	bool reveal_map;
	bool distressBeacon;
	bool repair;
	int modifyPursuit;
	Store *pStore;
	std::vector<EventDamage> damage;
	std::string quest;
	std::vector<StatusEffect> statusEffects;
	std::vector<std_pair_std_string_std_string> nameDefinitions;
	std::string spaceImage;
	std::string planetImage;
	std::string eventName;
	ResourceEvent reward;
	BoardingEvent boarders;
	std::vector<Choice> choices;
	int unlockShip;
	TextString unlockShipText;
	bool secretSector;
};

struct LockdownShard;

struct LockdownShard
{
	LIBZHL_API void SaveState(int fd);
	LIBZHL_API void Update();
	
	Animation shard;
	Pointf position;
	Pointf goal;
	float speed;
	bool bArrived;
	bool bDone;
	uint8_t gap_ex_1[2];
	float lifeTime;
	bool superFreeze;
	uint8_t gap_ex_2[3];
	int lockingRoom;
};

struct MantisAlien
{
};

struct MantisAnimation : CrewAnimation
{
};

struct MedbaySystem : ShipSystem
{
};

struct MemoryInputEvent
{
	int64_t used_bytes;
	int64_t free_bytes;
};

struct MindBox;
struct MindSystem;

struct MindBox : CooldownSystemBox
{
	LIBZHL_API void constructor(Point pos, MindSystem *sys);
	
	MindSystem *mindSystem;
	Button mindControl;
	Point buttonOffset;
	WarningMessage *superShieldWarning;
};

struct MindSystem : ShipSystem
{
	LIBZHL_API void InitiateMindControl();
	
	std::pair<float, float> controlTimer;
	bool bCanUse;
	int iArmed;
	std::vector<CrewMember*> controlledCrew;
	bool bSuperShields;
	bool bBlocked;
	int iQueuedTarget;
	int iQueuedShip;
	std::vector<CrewMember*> queuedCrew;
};

struct Missile : Projectile
{
};

struct Moddable
{
};

struct MouseControl;

struct MouseControl
{
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRender();
	LIBZHL_API void Reset();
	LIBZHL_API void SetDoor(int state);
	LIBZHL_API void SetTooltip(const std::string &tooltip);
	LIBZHL_API void SetTooltipTitle(const std::string &tooltip);
	LIBZHL_API void SetValid(bool valid, bool newValid);
	
	Point position;
	Point lastPosition;
	int aiming_required;
	int iTeleporting;
	int iMindControlling;
	bool bSellingStuff;
	bool valid;
	bool newHover;
	bool lastValid;
	int animateDoor;
	GL_Texture *validPointer;
	GL_Texture *invalidPointer;
	GL_Texture *selling;
	Animation openDoor;
	int tooltipFont;
	std::string tooltip;
	float tooltipTimer;
	bool bMoving;
	bool bHideMouse;
	GL_Texture *lastIcon;
	GL_Texture *lastAddition;
	bool bForceTooltip;
	std::string tooltipTitle;
	std::string lastTooltipText;
	int iHacking;
	int overrideTooltipWidth;
	Point staticTooltip;
};

struct MouseInputEvent
{
	float x;
	float y;
	float scroll;
};

struct NebulaCloud
{
	Point pos;
	float currAlpha;
	float currScale;
	float deltaAlpha;
	float deltaScale;
	float newTrigger;
	bool newCloud;
	bool bLightning;
	AnimationTracker lightningFlash;
	float flashTimer;
	float lightningRotation;
};

struct OuterHull;

struct OuterHull : Repairable
{
	LIBZHL_API void OnLoop();
	
	Animation breach;
	Animation heal;
};

struct OxygenSystem;

struct OxygenSystem : ShipSystem
{
	LIBZHL_API void ComputeAirLoss(int roomId, float base_loss, bool silent);
	LIBZHL_API void EmptyOxygen(int roomId);
	LIBZHL_API void ModifyRoomOxygen(int roomId, float value);
	LIBZHL_API void UpdateAirlock(int roomId, int count);
	LIBZHL_API void UpdateBreach(int roomId, int count, bool silent);
	
	float max_oxygen;
	std::vector<float> oxygenLevels;
	float fTotalOxygen;
	bool bLeakingO2;
};

struct PDSFire : LaserBlast
{
	Pointf startPoint;
	bool passedTarget;
	float currentScale;
	bool missed;
	Animation explosionAnimation;
};

struct PackageModuleInfo;

struct PackageModuleInfo
{
	char *prefix;
	void **init;
	void **cleanup;
	void **list_files_start;
	void **list_files_next;
	void **file_info;
	void **decompress_get_stack_size;
	void **decompress_init;
	void **decompress;
	void *module_data;
	PackageModuleInfo *next;
	size_t prefixlen;
};

struct PowerManager
{
	std::pair<int, int> currentPower;
	int over_powered;
	float fFuel;
	bool failedPowerup;
	int iTempPowerCap;
	int iTempPowerLoss;
	int iTempDividePower;
	int iHacked;
	std::pair<int, int> batteryPower;
};

struct ProjectileFactory : ShipObject
{
	LIBZHL_API void ClearProjectiles();
	LIBZHL_API void ForceCoolup();
	LIBZHL_API Projectile *GetProjectile();
	LIBZHL_API static Projectile *__stdcall LoadProjectile(int fd);
	LIBZHL_API int NumTargetsRequired();
	LIBZHL_API bool QueuedShots();
	LIBZHL_API void RenderChargeBar(float unk);
	LIBZHL_API static void __stdcall SaveProjectile(Projectile *p, int fd);
	LIBZHL_API void SelectChargeGoal();
	LIBZHL_API void SetAutoFire(bool autoFire);
	LIBZHL_API void SetCooldownModifier(float mod);
	LIBZHL_API static int __stdcall StringToWeapon(const std::string &str);
	
	std::pair<float, float> cooldown;
	std::pair<float, float> subCooldown;
	float baseCooldown;
	const WeaponBlueprint *blueprint;
	Point localPosition;
	Animation flight_animation;
	bool autoFiring;
	bool fireWhenReady;
	bool powered;
	int requiredPower;
	std::vector<Pointf> targets;
	std::vector<Pointf> lastTargets;
	int targetId;
	int iAmmo;
	std::string name;
	int numShots;
	float currentFiringAngle;
	float currentEntryAngle;
	Targetable *currentShipTarget;
	CloakingSystem *cloakingSystem;
	WeaponAnimation weaponVisual;
	WeaponMount mount;
	std::vector<Projectile*> queuedProjectiles;
	int iBonusPower;
	bool bFiredOnce;
	int iSpendMissile;
	float cooldownModifier;
	int shotsFiredAtTarget;
	int radius;
	int boostLevel;
	int lastProjectileId;
	int chargeLevel;
	int iHackLevel;
	int goalChargeLevel;
	bool isArtillery;
};

struct RepairAnimation : CrewAnimation
{
};

struct RepairDrone : CrewDrone
{
};

struct RepairStoreBox : StoreBox
{
	bool repairAll;
	int repairCost;
	TextString buttonText;
};

struct ResourceBoxDesc
{
	int w;
	int h;
	Point row1;
	Point row2;
};

struct ResourceControl;

struct ResourceManager;

struct freetype
{
	struct font_data
	{
		float h;
		int font;
		float fontsize;
		float baseline;
		float lineHeight;
	};
	
};

struct ResourceControl
{
	struct DynamicImageInfo
	{
		std::string name;
		int resid;
	};
	
	struct LogicalTexInfo
	{
		std::string physName;
		int x;
		int y;
		int w;
		int h;
	};
	
	LIBZHL_API freetype::font_data &GetFontData(int size, bool ignoreLanguage);
	LIBZHL_API GL_Texture *GetImageId(const std::string &dir);
	LIBZHL_API void OnInit(int imageSwappingMode);
	LIBZHL_API bool PreloadResources(bool unk);
	LIBZHL_API int RenderImage(GL_Texture *tex, int x, int y, int rotation, GL_Color color, float opacity, bool mirror);
	LIBZHL_API void constructor();
	
	std::unordered_map<std::string, GL_Texture*> images;
	std::unordered_map<int, freetype::font_data> fonts;
	std::unordered_map<GL_Texture*, ImageDesc> imageData;
	std::pair<int, int> preLoadProgress;
	std::string nextImageLoaded;
	int imageSwappingMode;
	std::vector<std::string> playerShipImages;
	std::vector<std::string> hangarShipImages;
	std::vector<std::string> enemyShipImages;
	std::vector<DynamicImageInfo> dynamicImages;
	int dynamicLoadMark;
	std::unordered_map<std::string, LogicalTexInfo> atlasData;
	ResourceManager *resmgr;
	PackageModuleInfo *package;
	GL_Texture *loading_box;
	GL_Texture *loading_bar;
	int screenWidth;
	int screenHeight;
	int renderPointX;
	int renderPointY;
	GL_FrameBuffer *frameBuffer;
	int fbViewportX;
	int fbViewportY;
	int fbViewportW;
	int fbViewportH;
};

struct ResourceManager
{
};

struct RockAlien
{
};

struct RockAnimation : CrewAnimation
{
};

struct Room;

struct Room : Selectable
{
	LIBZHL_API void FillSlot(int slot, bool intruder);
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRenderFloor(float alpha, bool experimental);
	LIBZHL_API void OnRenderWalls(float alpha);
	
	ShipObject _shipObject;
	Globals::Rect rect;
	int iRoomId;
	bool bBlackedOut;
	uint8_t gap_ex_1[2];
	std::vector<int> filledSlots;
	std::vector<std::vector<bool>> slots;
	bool bWarningLight;
	uint8_t gap_ex_2[2];
	AnimationTracker lightTracker;
	int iFireCount;
	std::vector<Animation> fires;
	int primarySlot;
	int primaryDirection;
	float lastO2;
	GL_Primitive *floorPrimitive;
	GL_Primitive *blackoutPrimitive;
	GL_Primitive *highlightPrimitive;
	GL_Primitive *highlightPrimitive2;
	GL_Primitive *o2LowPrimitive;
	GL_Primitive *computerPrimitive;
	GL_Primitive *computerGlowPrimitive;
	GL_Primitive *computerGlowYellowPrimitive;
	GL_Primitive *lightPrimitive;
	GL_Primitive *lightGlowPrimitive;
	Animation stunSparks;
	Animation consoleSparks;
	bool bStunning;
	float fHacked;
	int currentSparkRotation;
	std::vector<Animation> sparks;
	float sparkTimer;
	int sparkCount;
	int iHackLevel;
	Animation roomTapped;
};

struct ScoreKeeper;

struct StatTracker
{
	int max;
	int total;
	int current;
	std::string desc_id;
	int sector;
};

struct TopScore;

struct TopScore
{
	LIBZHL_API void copy_constructor(const TopScore &other);
	
	std::string name;
	std::string blueprint;
	GL_Texture *image;
	int sector;
	int score;
	bool victory;
	int difficulty;
	bool advancedContent;
};

struct ScoreKeeper
{
	LIBZHL_API void AddScrapCollected(int scrap);
	LIBZHL_API void CheckTypes();
	LIBZHL_API std::string GetShipBlueprint(int index);
	LIBZHL_API std::pair<int, int> GetShipId(const std::string &blueprintName);
	LIBZHL_API void MouseClick(int x, int y);
	LIBZHL_API void Open(bool fromGameOver);
	LIBZHL_API void SaveGame(int fd);
	LIBZHL_API void SetSector(int sector);
	LIBZHL_API void SetVictory(bool victory);
	LIBZHL_API void UnlockShip(int shipType, int shipVariant, bool save, bool hidePopup);
	
	StatTracker stats[4];
	CrewStatTracker crewStats[5];
	int gamesPlayed;
	int victories;
	TopScore currentScore;
	std::vector<std::vector<bool>> unlocked;
	bool firstRun;
	std::vector<TopScore> topScores;
	std::vector<std::vector<std::vector<TopScore>>> shipScores;
	bool bSavedScore;
	int newestHighScore;
	int newestShipBest;
	int newestShipType;
	int newestShipLayout;
	std::vector<std_pair_CAchievement_ptr_Point> achievements;
	std::vector<std_pair_CAchievement_ptr_Point> shipAchievements;
	GL_Texture *rightBox[2];
	GL_Texture *leftBox[2];
	Button rightButtons[2];
	Button leftButtons[2];
	bool activatedRight;
	bool activatedLeft;
	GL_Texture *lockIcon;
	InfoBox infoBox;
	TextButton closeButton;
	TextButton typeA;
	TextButton typeB;
	TextButton typeC;
	Button leftButton;
	Button rightButton;
	TextButton listButton;
	std::vector<GenericButton*> buttons;
	int selectedShip;
	int selectedLayout;
	int selectedAch;
	int selectedShipAch;
	ShipSelect shipSelect;
	int activeTouch;
	bool forceUnlockAll;
	bool gotCloseEvent;
	int loadingGameVersion;
	Point shipListCenter;
	Point typeALoc;
	Point typeBLoc;
	Point typeCLoc;
};

struct Scroller
{
	GL_Texture *imageId;
	int size_x;
	int size_y;
	int image_x;
	int image_y;
	float fSpeed;
	float current_x;
	bool bInitialized;
};

struct Sector;

struct Sector
{
	int type;
	bool visited;
	bool reachable;
	std::vector<Sector*> neighbors;
	Point location;
	int level;
	SectorDescription description;
};

struct SettingValues
{
	int fullscreen;
	int currentFullscreen;
	int lastFullscreen;
	int sound;
	int music;
	int difficulty;
	bool commandConsole;
	bool altPause;
	bool touchAutoPause;
	bool lowend;
	bool fbError;
	std::string language;
	bool languageSet;
	Point screenResolution;
	int dialogKeys;
	bool logging;
	bool bShowChangelog;
	int loadingSaveVersion;
	bool achPopups;
	bool vsync;
	bool frameLimit;
	bool manualResolution;
	bool manualWindowed;
	bool manualStretched;
	bool showPaths;
	bool swapTextureType;
	bool colorblind;
	std::array<std::vector<HotkeyDesc>, 4> hotkeys;
	bool holdingModifier;
	bool bDlcEnabled;
	int openedList;
	bool beamTutorial;
};

struct Settings
{
	LIBZHL_API static char __stdcall GetCommandConsole();
	LIBZHL_API static SDLKey __stdcall GetHotkey(const std::string &hotkeyName);
	LIBZHL_API static std::string __stdcall GetHotkeyName(const std::string &name);
	LIBZHL_API static void __stdcall LoadSettings();
	LIBZHL_API static void __stdcall ResetHotkeys();
	
};

struct Shields;

struct Shields : ShipSystem
{
	struct Shield
	{
		float charger;
		ShieldPower power;
		float superTimer;
	};
	
	struct ShieldAnimation
	{
		Pointf location;
		float current_size;
		float end_size;
		float current_thickness;
		float end_thickness;
		float length;
		float dx;
		int side;
		int ownerId;
		int damage;
	};
	
	LIBZHL_API void OnLoop();
	LIBZHL_API void SetBaseEllipse(Globals::Ellipse ellipse);
	LIBZHL_API void SetHackingLevel(int hackingLevel);
	
	float ellipseRatio;
	Point center;
	Globals::Ellipse baseShield;
	int iHighlightedSide;
	float debug_x;
	float debug_y;
	Shield shields;
	bool shields_shutdown;
	std::vector<ShieldAnimation> shieldHits;
	AnimationTracker shieldsDown;
	bool superShieldDown;
	Pointf shieldsDownPoint;
	AnimationTracker shieldsUp;
	GL_Texture *shieldImage;
	GL_Primitive *shieldPrimitive;
	std::string shieldImageName;
	bool bEnemyPresent;
	std::vector<DamageMessage*> damMessages;
	bool bBarrierMode;
	float lastHitTimer;
	float chargeTime;
	int lastHitShieldLevel;
	AnimationTracker superShieldUp;
	Point superUpLoc;
	bool bExcessChargeHack;
};

struct Ship : ShipObject
{
	struct DoorState
	{
		DoorStateType state;
		bool hacked;
		int level;
	};
	
	LIBZHL_API std::pair<int, int> ContainsHullBreach(int roomId);
	LIBZHL_API bool DestroyedDone();
	LIBZHL_API bool FullRoom(int roomId, bool intruder);
	LIBZHL_API Globals::Ellipse GetBaseEllipse();
	LIBZHL_API float GetCloakAlpha(bool complete);
	LIBZHL_API int GetSelectedRoomId(int x, int y, bool unk);
	LIBZHL_API Point GetShipCorner();
	LIBZHL_API void OnInit(ShipBlueprint &bp);
	LIBZHL_API void OnRenderBase(bool unk);
	LIBZHL_API void OnRenderJump(float progress);
	LIBZHL_API bool RoomLocked(int roomId);
	
	std::vector<Room*> vRoomList;
	std::vector<Door*> vDoorList;
	std::vector<OuterHull*> vOuterWalls;
	std::vector<Door*> vOuterAirlocks;
	std::pair<int, int> hullIntegrity;
	std::vector<WeaponMount> weaponMounts;
	std::string floorImageName;
	ImageDesc shipFloor;
	GL_Primitive *floorPrimitive;
	std::string shipImageName;
	ImageDesc shipImage;
	Point glowOffset;
	GL_Primitive *shipImagePrimitive;
	std::string cloakImageName;
	ImageDesc shipImageCloak;
	GL_Primitive *cloakPrimitive;
	GL_Primitive *gridPrimitive;
	GL_Primitive *wallsPrimitive;
	GL_Primitive *doorsPrimitive;
	std::vector<DoorState> doorState;
	bool lastDoorControlMode;
	GL_Texture *thrustersImage;
	GL_Texture *jumpGlare;
	int vertical_shift;
	int horizontal_shift;
	std::string shipName;
	ExplosionAnimation explosion;
	bool bDestroyed;
	Globals::Ellipse baseEllipse;
	Animation engineAnim[2];
	AnimationTracker cloakingTracker;
	bool bCloaked;
	bool bExperiment;
	bool bShowEngines;
	std::vector<LockdownShard> lockdowns;
};

struct ShipButton : Button
{
	GL_Texture *iShipImage;
	bool bShipLocked;
	bool bLayoutLocked;
	bool bNoExist;
	std::vector<CAchievement*> achievements;
	int iSelectedAch;
	bool bSelected;
};

struct ShipEvent;

struct ShipGenerator
{
	LIBZHL_API static ShipManager *__stdcall CreateShip(const std::string &name, int sector, ShipEvent &event);
	LIBZHL_API static std::vector<int> __stdcall GetPossibleSystemUpgrades(ShipManager *ship, std::vector<int> &systemMaxes, int scrap, int type);
	LIBZHL_API static bool __stdcall UpgradeSystem(ShipManager *ship, std::vector<int> &systemMaxes, unsigned int sysId);
	
};

struct ShipGraph;

struct ShipGraph
{
	LIBZHL_API void ComputeCenter();
	LIBZHL_API Door *ConnectingDoor(Point p1, Point p2);
	LIBZHL_API int DoorCount(int roomId);
	LIBZHL_API Path FindPath(Point p1, Point p2, int shipId);
	LIBZHL_API std::vector<Door*> GetDoors(int roomId);
	LIBZHL_API int GetNumSlots(int room);
	LIBZHL_API bool GetRoomBlackedOut(int room);
	LIBZHL_API Globals::Rect GetRoomShape(int room);
	LIBZHL_API int GetSelectedRoom(int x, int y, bool unk);
	LIBZHL_API Point GetSlotWorldPosition(int slotId, int roomId);
	LIBZHL_API static void __stdcall Restart();
	LIBZHL_API int RoomCount();
	
	std::vector<Room*> rooms;
	std::vector<Door*> doors;
	std::vector<int> doorCounts;
	Point center;
	Pointf worldPosition;
	float worldHeading;
	Pointf lastWorldPosition;
	float lastWorldHeading;
	Globals::Rect shipBox;
	std::string shipName;
};

struct ShipInfo
{
	std::map<std::string, int> augList;
	std::map<std::string, int> equipList;
	int augCount;
};

struct CrewDrone;

struct EngineSystem;
struct MedbaySystem;
struct ParticleEmitter;

struct Spreader_Fire : ShipObject
{
	int count;
	std::vector<int> roomCount;
	std::vector<std::vector<Fire>> grid;
};

struct TeleportSystem;

struct ShipManager : ShipObject
{
	LIBZHL_API void AddCrewMember(CrewMember *crew, int roomId);
	LIBZHL_API Drone *AddDrone(const DroneBlueprint *bp, int slot);
	LIBZHL_API int AddWeapon(const WeaponBlueprint *bp, int slot);
	LIBZHL_API void CheckCrystalAugment(Pointf pos);
	LIBZHL_API void ClearStatusSystem(int system);
	LIBZHL_API CollisionResponse CollisionShield(Pointf start, Pointf finish, Damage damage, bool raytrace);
	LIBZHL_API bool CommandCrewMoveRoom(CrewMember *crew, int roomId);
	LIBZHL_API CrewDrone *CreateCrewDrone(const DroneBlueprint *bp);
	LIBZHL_API Drone *CreateDrone(DroneBlueprint *drone);
	LIBZHL_API SpaceDrone *CreateSpaceDrone(const DroneBlueprint *bp);
	LIBZHL_API int CreateSystems();
	LIBZHL_API bool DamageCrew(CrewMember *crew, Damage dmg);
	LIBZHL_API bool DoorsFunction();
	LIBZHL_API bool ForceIncreaseSystemPower(int systemId);
	LIBZHL_API int GetDodgeFactor();
	LIBZHL_API int GetFireCount(int roomId);
	LIBZHL_API int GetNetDodgeFactor();
	LIBZHL_API std::vector<float> GetOxygenLevels();
	LIBZHL_API ShipSystem *GetSystem(int systemId);
	LIBZHL_API int GetSystemAvailablePower(int systemId);
	LIBZHL_API int GetSystemDamage(int systemId);
	LIBZHL_API int GetSystemHealth(int systemId);
	LIBZHL_API ShipSystem *GetSystemInRoom(int roomId);
	LIBZHL_API int GetSystemPower(int systemId);
	LIBZHL_API int GetSystemPowerMax(int systemId);
	LIBZHL_API std::string GetTooltip(int x, int y);
	LIBZHL_API std::vector<ProjectileFactory*> GetWeaponList();
	LIBZHL_API bool HasSystem(int systemId);
	LIBZHL_API bool IncreaseSystemPower(int systemId);
	LIBZHL_API void InstantPowerShields();
	LIBZHL_API bool IsCrewFull();
	LIBZHL_API bool IsCrewOverFull();
	LIBZHL_API int IsSystemHacked2(int systemId);
	LIBZHL_API void ModifyDroneCount(int drones);
	LIBZHL_API void ModifyMissileCount(int missiles);
	LIBZHL_API void ModifyScrapCount(int scrap, bool income);
	LIBZHL_API void OnLoop();
	LIBZHL_API void PrepareSuperDrones();
	LIBZHL_API void PulsarDamage();
	LIBZHL_API void ResetScrapLevel();
	LIBZHL_API bool RestoreCrewPositions();
	LIBZHL_API void SaveCrewPositions();
	LIBZHL_API ShipBlueprint SaveToBlueprint(bool overwrite);
	LIBZHL_API void StartFire(int roomId);
	LIBZHL_API bool SystemFunctions(int systemId);
	LIBZHL_API int SystemRoom(int systemId);
	LIBZHL_API void UpdateEnvironment();
	LIBZHL_API void UpgradeSystem(int id, int amount);
	LIBZHL_API void Wait();
	
	Targetable _targetable;
	Collideable _collideable;
	std::vector<ShipSystem*> vSystemList;
	OxygenSystem *oxygenSystem;
	TeleportSystem *teleportSystem;
	CloakingSystem *cloakSystem;
	BatterySystem *batterySystem;
	MindSystem *mindSystem;
	CloneSystem *cloneSystem;
	HackingSystem *hackingSystem;
	bool showNetwork;
	bool addedSystem;
	uint8_t gap_ex_1[2];
	Shields *shieldSystem;
	WeaponSystem *weaponSystem;
	DroneSystem *droneSystem;
	EngineSystem *engineSystem;
	MedbaySystem *medbaySystem;
	std::vector<ArtillerySystem*> artillerySystems;
	std::vector<CrewMember*> vCrewList;
	Spreader_Fire fireSpreader;
	Ship ship;
	char statusMessages[40];
	bool bGameOver;
	ShipManager *current_target;
	std::pair<float, float> jump_timer;
	int fuel_count;
	bool hostile_ship;
	bool bDestroyed;
	int iLastDamage;
	AnimationTracker jumpAnimation;
	std::vector<DamageMessage*> damMessages;
	std::vector<int> systemKey;
	int currentScrap;
	bool bJumping;
	bool bAutomated;
	uint8_t gap_ex_2[2];
	int shipLevel;
	ShipBlueprint myBlueprint;
	bool lastEngineStatus;
	bool lastJumpReady;
	bool bContainsPlayerCrew;
	int iIntruderCount;
	std::vector<std::vector<int>> crewCounts;
	int tempDroneCount;
	int tempMissileCount;
	std::vector<Animation> explosions;
	std::vector<bool> tempVision;
	bool bHighlightCrew;
	std::vector<Drone*> droneTrash;
	std::vector<SpaceDrone*> spaceDrones;
	std::vector<SpaceDrone*> newDroneArrivals;
	int bpCount;
	int iCustomizeMode;
	bool bShowRoom;
	std::vector<Projectile*> superBarrage;
	bool bInvincible;
	std::vector<SpaceDrone*> superDrones;
	GL_Primitive *highlight;
	int failedDodgeCounter;
	std::vector<float> hitByBeam;
	bool enemyDamagedUncloaked;
	int damageCloaked;
	std::map<int, int> killedByBeam;
	int minBeaconHealth;
	std::vector<ParticleEmitter*> fireExtinguishers;
	bool bWasSafe;
};

struct ShipRepair
{
};

struct ShipRepairDrone : CombatDrone
{
	CachedImage repairBeam;
	std::vector<float> repairBeams;
};

struct SlugAlien
{
};

struct SlugAnimation
{
};

struct SoundControl;

struct SoundControl
{
	LIBZHL_API int PlaySoundMix(const std::string &soundName, float volume, bool loop);
	LIBZHL_API void UpdateSoundLoop(const std::string &loopId, float count);
	
};

struct SpaceManager
{
	struct FleetShip
	{
		GL_Texture *image;
		Point location;
	};
	
	LIBZHL_API void ClearEnvironment();
	LIBZHL_API float GetFlashOpacity();
	LIBZHL_API int GetScreenShake();
	LIBZHL_API void LoadSpace(int fileHelper);
	LIBZHL_API void OnInit();
	LIBZHL_API void OnLoop();
	LIBZHL_API void OnRenderForeground();
	LIBZHL_API void SaveSpace(int fileHelper);
	LIBZHL_API void SetDangerZone(int fleetType);
	LIBZHL_API void SetFireLevel(bool state);
	LIBZHL_API void SetNebula(bool state);
	LIBZHL_API void SetPlanetaryDefense(char state, int target);
	LIBZHL_API void SetPulsarLevel(bool pulsarLevel);
	LIBZHL_API void SetStorm(bool state);
	LIBZHL_API void StartAsteroids(int shieldCount, bool unk);
	LIBZHL_API void UpdatePlanetImage();
	
	std::vector<Projectile*> projectiles;
	AsteroidGenerator asteroidGenerator;
	std::vector<ShipManager*> ships;
	std::vector<SpaceDrone*> drones;
	bool dangerZone;
	GL_Texture *currentBack;
	ImageDesc currentPlanet;
	CachedImage planetImage;
	ImageDesc fleetShip;
	GL_Texture *shipIds[8];
	FleetShip fleetShips[9];
	Scroller asteroidScroller[3];
	GL_Texture *sunImage;
	GL_Texture *sunGlow;
	AnimationTracker sunGlow1;
	AnimationTracker sunGlow2;
	AnimationTracker sunGlow3;
	bool sunLevel;
	bool pulsarLevel;
	GL_Texture *pulsarFront;
	GL_Texture *pulsarBack;
	GL_Texture *lowendPulsar;
	bool bPDS;
	int envTarget;
	Point shipPosition;
	float randomPDSTimer;
	std::vector<Projectile*> pdsQueue;
	TimerHelper flashTimer;
	AnimationTracker flashTracker;
	ImageDesc currentBeacon;
	ImageDesc currentBeaconFlash;
	AnimationTracker beaconTracker;
	bool flashSound;
	bool bNebula;
	bool bStorm;
	std::vector<NebulaCloud> nebulaClouds;
	GL_Texture *lowendNebula;
	GL_Texture *lowendStorm;
	GL_Texture *lowendSun;
	GL_Texture *lowendAsteroids;
	float shipHealth;
	bool gamePaused;
	TimerHelper pdsFireTimer;
	int pdsCountdown;
	std::vector<Animation> pdsSmokeAnims;
	bool queueScreenShake;
	bool playerShipInFront;
};

struct WindowFrame
{
	LIBZHL_API void Draw(int x, int y);
	LIBZHL_API void DrawMask(int unk);
	LIBZHL_API void destructor();
	
	Globals::Rect rect;
	GL_Primitive *outline;
	GL_Primitive *mask;
	GL_Primitive *pattern;
};

struct StarMap : FocusWindow
{
	struct NebulaInfo
	{
		GL_Primitive *primitive;
		int x;
		int y;
		int w;
		int h;
	};
	
	LIBZHL_API bool AddQuest(const std::string &questEvent, bool force);
	LIBZHL_API void AdvanceWorldLevel();
	LIBZHL_API void CheckGameOver();
	LIBZHL_API void ConnectLocations(Point unk0, Point unk1);
	LIBZHL_API std::vector<Location*> Dijkstra(Location *start, Location *finish, bool include_unknown);
	LIBZHL_API void ForceBossJump();
	LIBZHL_API void ForceExitBeacon();
	LIBZHL_API void GenerateSectorMap();
	LIBZHL_API std::string GetLocationText(const Location *loc);
	LIBZHL_API int GetRandomSectorChoice();
	LIBZHL_API void GetWaitLocation();
	LIBZHL_API void InitBossMessageBox();
	LIBZHL_API void InitMapTitle();
	LIBZHL_API void InitNoFuelText();
	LIBZHL_API void ModifyPursuit(int unk0);
	LIBZHL_API void MouseClick(int unk0, int unk1);
	LIBZHL_API Point PointToGrid(float x, float y);
	LIBZHL_API void PushSectorColumn();
	LIBZHL_API void RenderDistressButtons();
	LIBZHL_API void RenderLeftInsetButton(float unk0, float unk1, bool unk2);
	LIBZHL_API void RenderSectorName(Sector *unk0, GL_Color unk1);
	LIBZHL_API void SaveGame(int file);
	LIBZHL_API void SetBossStage(int stage);
	LIBZHL_API void SetupNoFuel(int seed, const std::string &forceEscape);
	LIBZHL_API void StartSecretSector();
	
	float visual_size;
	std::vector<Location*> locations;
	std::map<Point, std::vector<Location*>> locations_grid;
	std::vector<Location*> temp_path;
	Location *currentLoc;
	Location *potentialLoc;
	Location *hoverLoc;
	Point position;
	int iPopulatedTiles;
	int iLocationCount;
	int iEmptyTiles;
	bool bInitializedDisplay;
	Pointf translation;
	bool readyToTravel;
	Point dangerZone;
	float dangerZoneRadius;
	float shipRotation[2];
	TextButton endButton;
	TextButton waitButton;
	DistressButton distressButton;
	TextButton jumpButton;
	int worldLevel;
	bool bMapRevealed;
	int pursuitDelay;
	int sectorNameFont;
	WindowFrame mapBorder;
	GL_Primitive *mapBorderTitle;
	GL_Primitive *mapBorderTitleMask;
	GL_Texture *mapBorderSector;
	GL_Texture *mapInsetTextLeft;
	GL_Texture *mapInsetTextMiddle;
	GL_Texture *mapInsetTextRight;
	GL_Texture *mapInsetTextJump;
	GL_Texture *mapInsetWaitDistress;
	GL_Primitive *redLight;
	GL_Primitive *fuelMessage;
	GL_Primitive *waitingMessage;
	GL_Primitive *unexplored;
	GL_Primitive *explored;
	GL_Primitive *danger;
	GL_Primitive *warning;
	GL_Primitive *yellow_warning;
	GL_Primitive *warning_circle;
	GL_Primitive *nebula_circle;
	GL_Texture *boxGreen[3];
	GL_Texture *boxPurple[3];
	GL_Texture *boxWhite[3];
	GL_Primitive *ship;
	GL_Primitive *shipNoFuel;
	GL_Primitive *bossShip;
	GL_Primitive *dangerZoneEdge;
	GL_Texture *dangerZoneTile;
	GL_Primitive *dangerZoneAdvance;
	GL_Primitive *targetBox;
	GL_Primitive *sectorTargetBox_green;
	GL_Primitive *sectorTargetBox_yellow;
	AnimationTracker targetBoxTimer;
	TextButton closeButton;
	WindowFrame *descBox;
	GL_Primitive *shadow;
	GL_Primitive *warning_shadow;
	GL_Primitive *fuelOverlay;
	GL_Primitive *dangerFlash;
	GL_Primitive *mapsBottom[3];
	GL_Texture *dottedLine;
	GL_Texture *cross;
	GL_Texture *boss_jumps_box;
	std::vector<ImageDesc> smallNebula;
	std::vector<ImageDesc> largeNebula;
	std::vector<NebulaInfo> currentNebulas;
	ShipManager *shipManager;
	bool outOfFuel;
	AnimationTracker waiting;
	int dangerWaitStart;
	AnimationTracker distressAnim;
	bool bTutorialGenerated;
	std::vector<std::string> delayedQuests;
	std::vector<Sector*> sectors;
	Sector *currentSector;
	Sector *secretSector;
	bool bChoosingNewSector;
	bool bSecretSector;
	Location dummyNewSector;
	int mapsAnalyzed;
	int locationsCreated;
	int shipsCreated;
	std::map<std::string, int> scrapCollected;
	std::map<std::string, int> dronesCollected;
	std::map<std::string, int> fuelCollected;
	std::map<std::string, int> weaponFound;
	std::map<std::string, int> droneFound;
	int bossLoc;
	int arrivedAtBase;
	bool reversedPath;
	bool bossJumping;
	std::vector<Location*> boss_path;
	bool bossLevel;
	bool boss_wait;
	Pointf bossPosition;
	std::string forceSectorChoice;
	bool bEnemyShip;
	bool bNebulaMap;
	bool bInfiniteMode;
	std::vector<Sector*> lastSectors;
	TextButton closeSectorButton;
	int sectorMapSeed;
	int currentSectorSeed;
	int fuelEventSeed;
	std::string lastEscapeEvent;
	bool waitedLast;
	std::vector<Store*> storeTrash;
	std::vector<std_pair_std_string_int> addedQuests;
	int bossStage;
	TextString bossMessage;
	WarningMessage *bossJumpingWarning;
	bool crystalAlienFound;
	std::map<Location*, bool> foundMap;
	Point sectorMapOffset;
	int potentialSectorChoice;
	int finalSectorChoice;
	std::vector<Globals::Rect> sectorHitBoxes;
};

struct StateInfo
{
	bool stateContinueNeeded;
	TextString stateText;
	std::vector<ArrowDescription> arrows;
};

struct Store : FocusWindow
{
	LIBZHL_API static void __stdcall DrawBuySellTabText();
	LIBZHL_API void OnInit(ShipManager *shopper, Equipment *equip, int worldLevel);
	LIBZHL_API void SaveStore(int file);
	LIBZHL_API void SetPositions();
	LIBZHL_API void constructor();
	
	GL_Texture *box;
	TextString headingTitle[4];
	Button page1;
	Button page2;
	ConfirmWindow confirmDialog;
	Button *currentButton;
	Description currentDescription;
	std::string unavailable;
	std::vector<StoreBox*> vStoreBoxes;
	std::vector<StoreBox*> vItemBoxes;
	ShipManager *shopper;
	int selectedWeapon;
	int selectedDrone;
	InfoBox infoBox;
	Point infoBoxLoc;
	Button exitButton;
	int worldLevel;
	int sectionCount;
	int types[4];
	bool bShowPage2;
	uint8_t gap_ex_2[2];
	StoreBox *confirmBuy;
	int forceSystemInfoWidth;
};

struct SuperShieldDrone : DefenseDrone
{
	Shields *shieldSystem;
	CachedImage drone_image_on;
	CachedImage drone_image_off;
	CachedImage drone_image_glow;
	float glowAnimation;
};

struct SystemCustomBox : SystemBox
{
	LIBZHL_API void constructor(Point pos, ShipSystem *sys, ShipManager *ship);
	
	ShipManager *shipManager;
	Button button;
};

struct SystemStoreBox;

struct SystemStoreBox : StoreBox
{
	LIBZHL_API void Purchase();
	
	SystemBlueprint *blueprint;
	int type;
	bool bConfirming;
	std::string confirmString;
	std::string freeBlueprint;
	int droneChoice;
};

struct TeleportBox;

struct TeleportBox : SystemBox
{
	LIBZHL_API void constructor(Point pos, TeleportSystem *sys);
	
	GL_Texture *box;
	Button teleportLeave;
	Button teleportArrive;
	TeleportSystem *teleSystem;
	Point buttonOffset;
	WarningMessage superShieldWarning;
};

struct TeleportSystem : ShipSystem
{
	LIBZHL_API bool CanReceive();
	LIBZHL_API void ForceReady();
	LIBZHL_API void InitiateTeleport();
	LIBZHL_API void constructor(int systemId, int roomId, int shipId, int startingPower);
	
	float chargeLevel;
	bool bCanSend;
	bool bCanReceive;
	int iArmed;
	std::vector<bool> crewSlots;
	int iPreparedCrew;
	int iNumSlots;
	bool bSuperShields;
};

struct TextInputEvent
{
	int32_t ch;
};

struct TextLibrary;

struct TextLibrary
{
	LIBZHL_API std::string GetText(const std::string &name, const std::string &lang);
	
	std::map<std::string, std::string> dictionary;
	std::map<std::string, std_map_std_string_std_string> languageDictionaries;
	std::string currentLanguage;
};

struct ToggleButton
{
};

struct TouchInputEvent
{
	unsigned int id;
	float x;
	float y;
	float initial_x;
	float initial_y;
};

struct TouchTooltip
{
};

struct TutorialManager;

struct TutorialManager
{
	LIBZHL_API bool AllowJumping();
	LIBZHL_API bool AllowUpgrades();
	LIBZHL_API void MouseMove(int mX, int mY);
	LIBZHL_API void OnInit(ShipManager *ship, CommandGui *gui, CrewControl *crewControl, Upgrades *upgradesScreen, CombatControl *combatControl, SystemControl *sysControl, TabbedWindow *unk);
	LIBZHL_API void OnRender();
	LIBZHL_API bool Running();
	
	bool bRunning;
	TextButton continueButton;
	int currentState;
	std::string stateName;
	std::vector<std::string> stateOrder;
	std::map<std::string, int> stateValues;
	std::map<std::string, StateInfo> states;
	ShipManager *playerShip;
	CommandGui *gui;
	CrewControl *crewControl;
	StarMap *starMap;
	Upgrades *upgradeScreen;
	CombatControl *combatControl;
	SystemControl *systemControl;
	TabbedWindow *shipInfo;
	bool bGamePaused;
	bool bQuitTutorial;
	AnimationTracker tracker;
	float timerOpen;
	WindowFrame *descBox;
	int descBoxHeight;
	GL_Texture *arrow;
	GL_Texture *arrow2;
	HandAnimation hand;
	bool bTriggerEvent;
};

struct UpgradeBox
{
	LIBZHL_API void constructorEmpty(Point pos, bool subsystem);
	LIBZHL_API void constructorSystem(ShipManager *ship, ShipSystem *sys, Point pos, bool subsystem);
	
	ShipSystem *system;
	ShipManager *ship;
	const SystemBlueprint *blueprint;
	Point location;
	int tempUpgrade;
	Button *currentButton;
	std::string buttonBaseName;
	Button maxButton;
	Button boxButton;
	bool subsystem;
	bool isDummy;
	GL_Primitive *dummyBox;
};

struct WarningWithLines : WarningMessage
{
	GL_Primitive *linePrimitive;
	Point textOrigin;
	TextString topText;
	TextString bottomText;
	int topTextLimit;
	int bottomTextLimit;
};

struct WeaponBox : ArmamentBox
{
	ProjectileFactory *pWeapon;
	bool armed;
	bool armedForAutofire;
	float cooldownMax;
	float cooldownModifier;
	Point cooldownPoint;
	int cooldownWidth;
	int cooldownHeight;
	std::vector<GL_Primitive*> cooldownBox;
	GL_Primitive *cooldownBar;
	std::vector<CachedImage> chargeIcons;
	bool defaultAutofire;
	bool wasCharged;
};

struct WeaponEquipBox : EquipmentBox
{
};

struct WeaponStoreBox : StoreBox
{
	WeaponBlueprint *blueprint;
};

struct WeaponSystem : ShipSystem
{
	Pointf target;
	std::vector<ProjectileFactory*> weapons;
	std::vector<ProjectileFactory*> weaponsTrashList;
	float shot_timer;
	int shot_count;
	int missile_count;
	int missile_start;
	CloakingSystem *cloakingSystem;
	std::vector<bool> userPowered;
	int slot_count;
	int iStartingBatteryPower;
	std::vector<bool> repowerList;
};

struct WeaponSystemBox;

struct WeaponSystemBox : SystemBox
{
	LIBZHL_API void constructor(Point pos, ShipSystem *sys, WeaponControl *weapCtrl);
	
	WeaponControl *weapControl;
	TextButton autofireButton;
	Point buttonOffset;
	TouchTooltip *autofireTouchTooltip;
	bool touchTipWasOpen;
	bool autofireTipWasOpen;
};

struct BoardingEvent;

struct WorldManager
{
	LIBZHL_API bool AddBoarders(BoardingEvent &boardingEvent);
	LIBZHL_API bool CheckRequirements(LocationEvent *event, bool hidden);
	LIBZHL_API void CheckStatusEffects(std::vector<StatusEffect> &vec);
	LIBZHL_API void ClearLocation();
	LIBZHL_API void CreateChoiceBox(LocationEvent *event);
	LIBZHL_API void CreateLocation(Location *loc);
	LIBZHL_API void CreateNewGame();
	LIBZHL_API CompleteShip *CreateShip(ShipEvent *shipEvent, bool boss);
	LIBZHL_API bool HostileEnvironment();
	LIBZHL_API void ModifyEnvironment(int envFlag, int envTarget);
	LIBZHL_API LocationEvent *ModifyResources(LocationEvent *event);
	LIBZHL_API void ModifyStatusEffect(StatusEffect effect, ShipManager *target, int targetType);
	LIBZHL_API int OnInit();
	LIBZHL_API void OnLoop();
	LIBZHL_API void Restart();
	LIBZHL_API void StartGame(ShipManager *ship);
	LIBZHL_API void UpdateLocation(LocationEvent *event);
	LIBZHL_API void constructor();
	
	CompleteShip *playerShip;
	BossShip *bossShip;
	SpaceManager space;
	int currentDifficulty;
	std::vector<CompleteShip*> ships;
	StarMap starMap;
	CommandGui *commandGui;
	LocationEvent *baseLocationEvent;
	LocationEvent *lastLocationEvent;
	ShipEvent currentShipEvent;
	std::vector<StatusEffect> currentEffects;
	std::string startingText;
	Location *newLocation;
	bool bStartedGame;
	bool bLoadingGame;
	bool vAutoSaved;
	bool bExtraChoice;
	std::vector<int> choiceHistory;
	std::string generatedEvent;
	TextString lastMainText;
	int playerCrewCount;
	int killedCrew;
	int playerHull;
	std::vector<int> blueRaceChoices;
	int lastSelectedCrewSeed;
	bool testingBlueprints;
	std::vector<LocationEvent::Choice> originalChoiceList;
};

struct ResourceEvent;
struct RewardDesc;

LIBZHL_API void __stdcall GenerateReward(ResourceEvent &ref, RewardDesc &reward, int worldLevel);
LIBZHL_API void __stdcall GetValue(ResourceEvent &ref, const std::string &type, int level, int worldLevel);
LIBZHL_API float __stdcall font_text_width(freetype::font_data &fontData, const char *str, float size);
LIBZHL_API float __stdcall getSkillBonus(int skill, int level);
LIBZHL_API void __stdcall graphics_clear(float r, float g, float b, float a, float depth, unsigned int stencil);
LIBZHL_API int __stdcall random32();
LIBZHL_API void __stdcall srandom32(unsigned int seed);
LIBZHL_API void __stdcall sys_graphics_set_window_title(char *title);



