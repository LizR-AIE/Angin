#pragma once

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

#include <SDL.h>
#include <SDL_keycode.h>
#include <map>
#include "glm\vec2.hpp"

enum class KEY : SDL_Keycode
{
	KEY_0					= SDLK_0					,
	KEY_1					= SDLK_1					,
	KEY_2					= SDLK_2					,
	KEY_3					= SDLK_3					,
	KEY_4					= SDLK_4					,
	KEY_5					= SDLK_5					,
	KEY_6					= SDLK_6					,
	KEY_7					= SDLK_7					,
	KEY_8					= SDLK_8					,
	KEY_9					= SDLK_9					,

	KEY_A					= SDLK_a					,
	KEY_B					= SDLK_b					,
	KEY_C					= SDLK_c					,
	KEY_D					= SDLK_d					,
	KEY_E					= SDLK_e					,
	KEY_F					= SDLK_f					,
	KEY_G					= SDLK_g					,
	KEY_H					= SDLK_h					,
	KEY_I					= SDLK_i					,
	KEY_J					= SDLK_j					,
	KEY_K					= SDLK_k					,
	KEY_L					= SDLK_l					,
	KEY_M					= SDLK_m					,
	KEY_N					= SDLK_n					,
	KEY_O					= SDLK_o					,
	KEY_P					= SDLK_p					,
	KEY_Q					= SDLK_q					,
	KEY_R					= SDLK_r					,
	KEY_S					= SDLK_s					,
	KEY_T					= SDLK_t					,
	KEY_U					= SDLK_u					,
	KEY_V					= SDLK_v					,
	KEY_W					= SDLK_w					,
	KEY_X					= SDLK_x					,
	KEY_Y					= SDLK_y					,
	KEY_Z					= SDLK_z					,

	KEY_F1					= SDLK_F1					,
	KEY_F2					= SDLK_F2					,
	KEY_F3					= SDLK_F3					,
	KEY_F4					= SDLK_F4					,
	KEY_F5					= SDLK_F5					,
	KEY_F6					= SDLK_F6					,
	KEY_F7					= SDLK_F7					,
	KEY_F8					= SDLK_F8					,
	KEY_F9					= SDLK_F9					,
	KEY_F10					= SDLK_F10					,
	KEY_F11					= SDLK_F11					,
	KEY_F12					= SDLK_F12					,

	KEY_RIGHT				= SDLK_RIGHT				,
	KEY_LEFT				= SDLK_LEFT					,
	KEY_DOWN				= SDLK_DOWN					,
	KEY_UP					= SDLK_UP					,

	KEY_KP_DIVIDE			= SDLK_KP_DIVIDE			,
	KEY_KP_MULTIPLY			= SDLK_KP_MULTIPLY			,
	KEY_KP_MINUS			= SDLK_KP_MINUS				,
	KEY_KP_PLUS				= SDLK_KP_PLUS				,
	KEY_KP_ENTER			= SDLK_KP_ENTER				,
	KEY_KP_1				= SDLK_KP_1					,
	KEY_KP_2				= SDLK_KP_2					,
	KEY_KP_3				= SDLK_KP_3					,
	KEY_KP_4				= SDLK_KP_4					,
	KEY_KP_5				= SDLK_KP_5					,
	KEY_KP_6				= SDLK_KP_6					,
	KEY_KP_7				= SDLK_KP_7					,
	KEY_KP_8				= SDLK_KP_8					,
	KEY_KP_9				= SDLK_KP_9					,
	KEY_KP_0				= SDLK_KP_0					,
	KEY_KP_PERIOD			= SDLK_KP_PERIOD			,
	KEY_NUMLOCKCLEAR		= SDLK_NUMLOCKCLEAR			,

	KEY_RETURN				= SDLK_RETURN				,
	KEY_ESCAPE				= SDLK_ESCAPE				,
	KEY_BACKSPACE			= SDLK_BACKSPACE			,
	KEY_TAB					= SDLK_TAB					,
	KEY_SPACE				= SDLK_SPACE				,
	KEY_EXCLAIM				= SDLK_EXCLAIM				,
	KEY_QUOTEDBL			= SDLK_QUOTEDBL				,
	KEY_HASH				= SDLK_HASH					,
	KEY_PERCENT				= SDLK_PERCENT				,
	KEY_DOLLAR				= SDLK_DOLLAR				,
	KEY_AMPERSAND			= SDLK_AMPERSAND			,
	KEY_QUOTE				= SDLK_QUOTE				,
	KEY_LEFTPAREN			= SDLK_LEFTPAREN			,
	KEY_RIGHTPAREN			= SDLK_RIGHTPAREN			,
	KEY_ASTERISK			= SDLK_ASTERISK				,
	KEY_PLUS				= SDLK_PLUS					,
	KEY_COMMA				= SDLK_COMMA				,
	KEY_MINUS				= SDLK_MINUS				,
	KEY_PERIOD				= SDLK_PERIOD				,
	KEY_SLASH				= SDLK_SLASH				,
		
	KEY_COLON				= SDLK_COLON				,
	KEY_SEMICOLON			= SDLK_SEMICOLON			,
	KEY_LESS				= SDLK_LESS					,
	KEY_EQUALS				= SDLK_EQUALS				,
	KEY_GREATER				= SDLK_GREATER				,
	KEY_QUESTION			= SDLK_QUESTION				,
	KEY_AT					= SDLK_AT					,
	KEY_LEFTBRACKET			= SDLK_LEFTBRACKET			,
	KEY_BACKSLASH			= SDLK_BACKSLASH			,
	KEY_RIGHTBRACKET		= SDLK_RIGHTBRACKET			,
	KEY_CARET				= SDLK_CARET				,
	KEY_UNDERSCORE			= SDLK_UNDERSCORE			,
	KEY_BACKQUOTE			= SDLK_BACKQUOTE			,
				
	KEY_CAPSLOCK			= SDLK_CAPSLOCK				,

	KEY_PRINTSCREEN			= SDLK_PRINTSCREEN			,
	KEY_SCROLLLOCK			= SDLK_SCROLLLOCK			,
	KEY_PAUSE				= SDLK_PAUSE				,

	KEY_INSERT				= SDLK_INSERT				,
	KEY_HOME				= SDLK_HOME					,
	KEY_PAGEUP				= SDLK_PAGEUP				,
	KEY_DELETE				= SDLK_DELETE				,
	KEY_END					= SDLK_END					,
	KEY_PAGEDOWN			= SDLK_PAGEDOWN				,
				
	KEY_APPLICATION			= SDLK_APPLICATION			,
	KEY_POWER				= SDLK_POWER				,
	KEY_KP_EQUALS			= SDLK_KP_EQUALS			,
	KEY_F13					= SDLK_F13					,
	KEY_F14					= SDLK_F14					,
	KEY_F15					= SDLK_F15					,
	KEY_F16					= SDLK_F16					,
	KEY_F17					= SDLK_F17					,
	KEY_F18					= SDLK_F18					,
	KEY_F19					= SDLK_F19					,
	KEY_F20					= SDLK_F20					,
	KEY_F21					= SDLK_F21					,
	KEY_F22					= SDLK_F22					,
	KEY_F23					= SDLK_F23					,
	KEY_F24					= SDLK_F24					,
	//KEY_EXECUTE			= SDLK_EXECUTE 				,
	KEY_HELP				= SDLK_HELP					,
	KEY_MENU				= SDLK_MENU					,
	KEY_SELECT				= SDLK_SELECT 				,
	KEY_STOP				= SDLK_STOP 				,
	KEY_AGAIN				= SDLK_AGAIN 				,
	KEY_UNDO				= SDLK_UNDO 				,
	KEY_CUT					= SDLK_CUT 					,
	KEY_COPY				= SDLK_COPY					,
	KEY_PASTE				= SDLK_PASTE				,
	KEY_FIND				= SDLK_FIND 				,
	KEY_MUTE				= SDLK_MUTE 				,
	KEY_VOLUMEUP			= SDLK_VOLUMEUP 			,
	KEY_VOLUMEDOWN			= SDLK_VOLUMEDOWN 			,
	KEY_KP_COMMA			= SDLK_KP_COMMA 			,
	KEY_KP_EQUALSAS400		= SDLK_KP_EQUALSAS400		,
		
	KEY_ALTERASE			= SDLK_ALTERASE 			,
	KEY_SYSREQ				= SDLK_SYSREQ 				,
	KEY_CANCEL				= SDLK_CANCEL 				,
	KEY_CLEAR				= SDLK_CLEAR 				,
	KEY_PRIOR				= SDLK_PRIOR 				,
	KEY_RETURN2				= SDLK_RETURN2 				,
	KEY_SEPARATOR			= SDLK_SEPARATOR 			,
	KEY_OUT					= SDLK_OUT 					,
	KEY_OPER				= SDLK_OPER 				,
	KEY_CLEARAGAIN			= SDLK_CLEARAGAIN 			,
	KEY_CRSEL				= SDLK_CRSEL 				,
	KEY_EXSEL				= SDLK_EXSEL 				,
		
	KEY_KP_00				= SDLK_KP_00 				,
	KEY_KP_000				= SDLK_KP_000 				,
	KEY_THOUSANDSSEPARATOR	= SDLK_THOUSANDSSEPARATOR	, 
	KEY_DECIMALSEPARATOR	= SDLK_DECIMALSEPARATOR 	,
	KEY_CURRENCYUNIT		= SDLK_CURRENCYUNIT 		,
	KEY_CURRENCYSUBUNIT		= SDLK_CURRENCYSUBUNIT 		,
	KEY_KP_LEFTPAREN		= SDLK_KP_LEFTPAREN 		,
	KEY_KP_RIGHTPAREN		= SDLK_KP_RIGHTPAREN 		,
	KEY_KP_LEFTBRACE		= SDLK_KP_LEFTBRACE 		,
	KEY_KP_RIGHTBRACE		= SDLK_KP_RIGHTBRACE 		,
	KEY_KP_TAB				= SDLK_KP_TAB 				,
	KEY_KP_BACKSPACE		= SDLK_KP_BACKSPACE 		,
	KEY_KP_A				= SDLK_KP_A 				,
	KEY_KP_B				= SDLK_KP_B 				,
	KEY_KP_C				= SDLK_KP_C 				,
	KEY_KP_D				= SDLK_KP_D 				,
	KEY_KP_E				= SDLK_KP_E 				,
	KEY_KP_F				= SDLK_KP_F 				,
	KEY_KP_XOR				= SDLK_KP_XOR 				,
	KEY_KP_POWER			= SDLK_KP_POWER 			,
	KEY_KP_PERCENT			= SDLK_KP_PERCENT 			,
	KEY_KP_LESS				= SDLK_KP_LESS 				,
	KEY_KP_GREATER			= SDLK_KP_GREATER 			,
	KEY_KP_AMPERSAND		= SDLK_KP_AMPERSAND 		,
	KEY_KP_DBLAMPERSAND		= SDLK_KP_DBLAMPERSAND 		,
	KEY_KP_VERTICALBAR		= SDLK_KP_VERTICALBAR 		,
	KEY_KP_DBLVERTICALBAR	= SDLK_KP_DBLVERTICALBAR	,
	KEY_KP_COLON			= SDLK_KP_COLON 			,
	KEY_KP_HASH				= SDLK_KP_HASH 				,
	KEY_KP_SPACE			= SDLK_KP_SPACE 			,
	KEY_KP_AT				= SDLK_KP_AT 				,
	KEY_KP_EXCLAM			= SDLK_KP_EXCLAM 			,
	KEY_KP_MEMSTORE			= SDLK_KP_MEMSTORE 			,
	KEY_KP_MEMRECALL		= SDLK_KP_MEMRECALL 		,
	KEY_KP_MEMCLEAR			= SDLK_KP_MEMCLEAR 			,
	KEY_KP_MEMADD			= SDLK_KP_MEMADD 			,
	KEY_KP_MEMSUBTRACT		= SDLK_KP_MEMSUBTRACT 		,
	KEY_KP_MEMMULTIPLY		= SDLK_KP_MEMMULTIPLY 		,
	KEY_KP_MEMDIVIDE		= SDLK_KP_MEMDIVIDE 		,
	KEY_KP_PLUSMINUS		= SDLK_KP_PLUSMINUS 		,
	KEY_KP_CLEAR			= SDLK_KP_CLEAR 			,
	KEY_KP_CLEARENTRY		= SDLK_KP_CLEARENTRY 		,
	KEY_KP_BINARY			= SDLK_KP_BINARY 			,
	KEY_KP_OCTAL			= SDLK_KP_OCTAL 			,
	KEY_KP_DECIMAL			= SDLK_KP_DECIMAL 			,
	KEY_KP_HEXADECIMAL		= SDLK_KP_HEXADECIMAL 		,
		
	KEY_LCTRL				= SDLK_LCTRL 				,
	KEY_LSHIFT				= SDLK_LSHIFT 				,
	KEY_LALT				= SDLK_LALT 				,
	KEY_LGUI				= SDLK_LGUI 				,
	KEY_RCTRL				= SDLK_RCTRL 				,
	KEY_RSHIFT				= SDLK_RSHIFT 				,
	KEY_RALT				= SDLK_RALT 				,
	KEY_RGUI				= SDLK_RGUI 				,
		
	KEY_MODE				= SDLK_MODE 				,
		
	KEY_AUDIONEXT			= SDLK_AUDIONEXT 			,
	KEY_AUDIOPREV			= SDLK_AUDIOPREV 			,
	KEY_AUDIOSTOP			= SDLK_AUDIOSTOP 			,
	KEY_AUDIOPLAY			= SDLK_AUDIOPLAY 			,
	KEY_AUDIOMUTE			= SDLK_AUDIOMUTE 			,
	KEY_MEDIASELECT			= SDLK_MEDIASELECT 			,
	KEY_WWW					= SDLK_WWW 					,
	KEY_MAIL				= SDLK_MAIL 				,
	KEY_CALCULATOR			= SDLK_CALCULATOR 			,
	KEY_COMPUTER			= SDLK_COMPUTER 			,
	KEY_AC_SEARCH			= SDLK_AC_SEARCH 			,
	KEY_AC_HOME				= SDLK_AC_HOME 				,
	KEY_AC_BACK				= SDLK_AC_BACK 				,
	KEY_AC_FORWARD			= SDLK_AC_FORWARD 			,
	KEY_AC_STOP				= SDLK_AC_STOP 				,
	KEY_AC_REFRESH			= SDLK_AC_REFRESH 			,
	KEY_AC_BOOKMARKS		= SDLK_AC_BOOKMARKS 		,
		
	KEY_BRIGHTNESSDOWN		= SDLK_BRIGHTNESSDOWN		,
	KEY_BRIGHTNESSUP		= SDLK_BRIGHTNESSUP 		,
	KEY_DISPLAYSWITCH		= SDLK_DISPLAYSWITCH 		,
	KEY_KBDILLUMTOGGLE		= SDLK_KBDILLUMTOGGLE 		,
	KEY_KBDILLUMDOWN		= SDLK_KBDILLUMDOWN 		,
	KEY_KBDILLUMUP			= SDLK_KBDILLUMUP 			,
	KEY_EJECT				= SDLK_EJECT 				,
	KEY_SLEEP				= SDLK_SLEEP 
};

enum class MB
{
	MB_LEFT		= SDL_BUTTON_LEFT		,
	MB_MIDDLE	= SDL_BUTTON_MIDDLE		,
	MB_RITE		= SDL_BUTTON_RIGHT		,
	MB_X1		= SDL_BUTTON_X1			,
	MB_X2		= SDL_BUTTON_X2			,
	MB_LMASK	= SDL_BUTTON_LMASK		,
	MB_MMASK	= SDL_BUTTON_MMASK		,
	MB_RMASK	= SDL_BUTTON_RMASK		,
	MB_X1MASK	= SDL_BUTTON_X1MASK		,
	MB_X2MASK	= SDL_BUTTON_X2MASK		
};

class InputHandler
{
	friend class Game;
public:
	//--------------------------------
	// Keys enum
	//--------------------------------
	

	//--------------------------------
	// Singleton Related
	//--------------------------------
	ANGIN_API static void Create();
	ANGIN_API static void Destroy();
	ANGIN_API inline static InputHandler * Get(){ return m_inputHandler; }
	
	ANGIN_API bool IsKeyDown(const KEY KeyCode);
	ANGIN_API bool IsMouseDown(const MB MouseCode);

private:
	// Singleton instance
	static InputHandler * m_inputHandler;
	
	//--------------------------------
	// Instance Related
	//--------------------------------

	// Call Create instead
	ANGIN_API InputHandler();
	
public:
	ANGIN_API virtual ~InputHandler();
	ANGIN_API glm::vec2 GetRelativeMouseMovement();
	
protected:
	std::map<KEY, bool> keyDown;
	std::map<MB, bool> mouseDown;

	glm::vec2 thisMouse;
	glm::vec2 lastMouse;
};

