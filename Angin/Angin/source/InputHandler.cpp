#include "InputHandler.h"
#include <SDL_keycode.h>


InputHandler* InputHandler::m_inputHandler = nullptr;

InputHandler::InputHandler()
{
	keyDown[KEY::KEY_0] = false;	
	keyDown[KEY::KEY_1] = false;
	keyDown[KEY::KEY_2] = false;					
	keyDown[KEY::KEY_3] = false;					
	keyDown[KEY::KEY_4] = false;					
	keyDown[KEY::KEY_5] = false;					
	keyDown[KEY::KEY_6] = false;					
	keyDown[KEY::KEY_7] = false;					
	keyDown[KEY::KEY_8] = false;					
	keyDown[KEY::KEY_9] = false;					
	keyDown[KEY::KEY_A] = false;					
	keyDown[KEY::KEY_B] = false;					
	keyDown[KEY::KEY_C] = false;					
	keyDown[KEY::KEY_D] = false;					
	keyDown[KEY::KEY_E] = false;					
	keyDown[KEY::KEY_F] = false;					
	keyDown[KEY::KEY_G] = false;					
	keyDown[KEY::KEY_H] = false;					
	keyDown[KEY::KEY_I] = false;					
	keyDown[KEY::KEY_J] = false;					
	keyDown[KEY::KEY_K] = false;					
	keyDown[KEY::KEY_L] = false;					
	keyDown[KEY::KEY_M] = false;					
	keyDown[KEY::KEY_N] = false;					
	keyDown[KEY::KEY_O] = false;					
	keyDown[KEY::KEY_P] = false;					
	keyDown[KEY::KEY_Q] = false;					
	keyDown[KEY::KEY_R] = false;					
	keyDown[KEY::KEY_S] = false;					
	keyDown[KEY::KEY_T] = false;					
	keyDown[KEY::KEY_U] = false;					
	keyDown[KEY::KEY_V] = false;					
	keyDown[KEY::KEY_W] = false;					
	keyDown[KEY::KEY_X] = false;					
	keyDown[KEY::KEY_Y] = false;					
	keyDown[KEY::KEY_Z] = false;					
	keyDown[KEY::KEY_F1] = false;					
	keyDown[KEY::KEY_F2] = false;					
	keyDown[KEY::KEY_F3] = false;					
	keyDown[KEY::KEY_F4] = false;					
	keyDown[KEY::KEY_F5] = false;					
	keyDown[KEY::KEY_F6] = false;					
	keyDown[KEY::KEY_F7] = false;					
	keyDown[KEY::KEY_F8] = false;					
	keyDown[KEY::KEY_F9] = false;					
	keyDown[KEY::KEY_F10] = false;					
	keyDown[KEY::KEY_F11] = false;					
	keyDown[KEY::KEY_F12] = false;					
	keyDown[KEY::KEY_RIGHT] = false;	
	keyDown[KEY::KEY_LEFT] = false;	
	keyDown[KEY::KEY_DOWN] = false;	
	keyDown[KEY::KEY_UP] = false;	
	keyDown[KEY::KEY_KP_DIVIDE] = false;			
	keyDown[KEY::KEY_KP_MULTIPLY] = false;			
	keyDown[KEY::KEY_KP_MINUS] = false;			
	keyDown[KEY::KEY_KP_PLUS] = false;				
	keyDown[KEY::KEY_KP_ENTER] = false;			
	keyDown[KEY::KEY_KP_1] = false;				
	keyDown[KEY::KEY_KP_2] = false;				
	keyDown[KEY::KEY_KP_3] = false;				
	keyDown[KEY::KEY_KP_4] = false;				
	keyDown[KEY::KEY_KP_5] = false;				
	keyDown[KEY::KEY_KP_6] = false;				
	keyDown[KEY::KEY_KP_7] = false;				
	keyDown[KEY::KEY_KP_8] = false;				
	keyDown[KEY::KEY_KP_9] = false;				
	keyDown[KEY::KEY_KP_0] = false;				
	keyDown[KEY::KEY_KP_PERIOD] = false;			
	keyDown[KEY::KEY_NUMLOCKCLEAR] = false;		
	keyDown[KEY::KEY_RETURN] = false;				
	keyDown[KEY::KEY_ESCAPE] = false;				
	keyDown[KEY::KEY_BACKSPACE] = false;			
	keyDown[KEY::KEY_TAB] = false;					
	keyDown[KEY::KEY_SPACE] = false;				
	keyDown[KEY::KEY_EXCLAIM] = false;				
	keyDown[KEY::KEY_QUOTEDBL] = false;			
	keyDown[KEY::KEY_HASH] = false;				
	keyDown[KEY::KEY_PERCENT] = false;				
	keyDown[KEY::KEY_DOLLAR] = false;				
	keyDown[KEY::KEY_AMPERSAND] = false;			
	keyDown[KEY::KEY_QUOTE] = false;				
	keyDown[KEY::KEY_LEFTPAREN] = false;			
	keyDown[KEY::KEY_RIGHTPAREN] = false;			
	keyDown[KEY::KEY_ASTERISK] = false;			
	keyDown[KEY::KEY_PLUS] = false;				
	keyDown[KEY::KEY_COMMA] = false;				
	keyDown[KEY::KEY_MINUS] = false;				
	keyDown[KEY::KEY_PERIOD] = false;				
	keyDown[KEY::KEY_SLASH] = false;				
	keyDown[KEY::KEY_COLON] = false;				
	keyDown[KEY::KEY_SEMICOLON] = false;			
	keyDown[KEY::KEY_LESS] = false;				
	keyDown[KEY::KEY_EQUALS] = false;			
	keyDown[KEY::KEY_GREATER] = false;				
	keyDown[KEY::KEY_QUESTION] = false;			
	keyDown[KEY::KEY_AT] = false;					
	keyDown[KEY::KEY_LEFTBRACKET] = false;			
	keyDown[KEY::KEY_BACKSLASH] = false;			
	keyDown[KEY::KEY_RIGHTBRACKET] = false;		
	keyDown[KEY::KEY_CARET] = false;				
	keyDown[KEY::KEY_UNDERSCORE] = false;			
	keyDown[KEY::KEY_BACKQUOTE] = false;			
	keyDown[KEY::KEY_CAPSLOCK] = false;			
	keyDown[KEY::KEY_PRINTSCREEN] = false;			
	keyDown[KEY::KEY_SCROLLLOCK] = false;			
	keyDown[KEY::KEY_PAUSE] = false;				
	keyDown[KEY::KEY_INSERT] = false;				
	keyDown[KEY::KEY_HOME] = false;				
	keyDown[KEY::KEY_PAGEUP] = false;				
	keyDown[KEY::KEY_DELETE] = false;				
	keyDown[KEY::KEY_END] = false;					
	keyDown[KEY::KEY_PAGEDOWN] = false;			
	keyDown[KEY::KEY_APPLICATION] = false;			
	keyDown[KEY::KEY_POWER] = false;				
	keyDown[KEY::KEY_KP_EQUALS] = false;			
	keyDown[KEY::KEY_F13] = false;					
	keyDown[KEY::KEY_F14] = false;					
	keyDown[KEY::KEY_F15] = false;					
	keyDown[KEY::KEY_F16] = false;					
	keyDown[KEY::KEY_F17] = false;					
	keyDown[KEY::KEY_F18] = false;					
	keyDown[KEY::KEY_F19] = false;					
	keyDown[KEY::KEY_F20] = false;					
	keyDown[KEY::KEY_F21] = false;					
	keyDown[KEY::KEY_F22] = false;					
	keyDown[KEY::KEY_F23] = false;					
	keyDown[KEY::KEY_F24] = false;								
	keyDown[KEY::KEY_HELP] = false;				
	keyDown[KEY::KEY_MENU] = false;				
	keyDown[KEY::KEY_SELECT] = false;				
	keyDown[KEY::KEY_STOP] = false;				
	keyDown[KEY::KEY_AGAIN] = false;				
	keyDown[KEY::KEY_UNDO] = false;				
	keyDown[KEY::KEY_CUT] = false;					
	keyDown[KEY::KEY_COPY] = false;				
	keyDown[KEY::KEY_PASTE] = false;				
	keyDown[KEY::KEY_FIND] = false;				
	keyDown[KEY::KEY_MUTE] = false;				
	keyDown[KEY::KEY_VOLUMEUP] = false;			
	keyDown[KEY::KEY_VOLUMEDOWN] = false;			
	keyDown[KEY::KEY_KP_COMMA] = false;			
	keyDown[KEY::KEY_KP_EQUALSAS400] = false;		
	keyDown[KEY::KEY_ALTERASE] = false;			
	keyDown[KEY::KEY_SYSREQ] = false;				
	keyDown[KEY::KEY_CANCEL] = false;				
	keyDown[KEY::KEY_CLEAR] = false;				
	keyDown[KEY::KEY_PRIOR] = false;				
	keyDown[KEY::KEY_RETURN2] = false;				
	keyDown[KEY::KEY_SEPARATOR] = false;			
	keyDown[KEY::KEY_OUT] = false;					
	keyDown[KEY::KEY_OPER] = false;				
	keyDown[KEY::KEY_CLEARAGAIN] = false;			
	keyDown[KEY::KEY_CRSEL] = false;				
	keyDown[KEY::KEY_EXSEL] = false;				
	keyDown[KEY::KEY_KP_00] = false;				
	keyDown[KEY::KEY_KP_000] = false;				
	keyDown[KEY::KEY_THOUSANDSSEPARATOR] = false;	
	keyDown[KEY::KEY_DECIMALSEPARATOR] = false;	
	keyDown[KEY::KEY_CURRENCYUNIT] = false;		
	keyDown[KEY::KEY_CURRENCYSUBUNIT] = false;		
	keyDown[KEY::KEY_KP_LEFTPAREN] = false;		
	keyDown[KEY::KEY_KP_RIGHTPAREN] = false;		
	keyDown[KEY::KEY_KP_LEFTBRACE] = false;		
	keyDown[KEY::KEY_KP_RIGHTBRACE] = false;		
	keyDown[KEY::KEY_KP_TAB] = false;				
	keyDown[KEY::KEY_KP_BACKSPACE] = false;		
	keyDown[KEY::KEY_KP_A] = false;				
	keyDown[KEY::KEY_KP_B] = false;				
	keyDown[KEY::KEY_KP_C] = false;				
	keyDown[KEY::KEY_KP_D] = false;				
	keyDown[KEY::KEY_KP_E] = false;				
	keyDown[KEY::KEY_KP_F] = false;				
	keyDown[KEY::KEY_KP_XOR] = false;				
	keyDown[KEY::KEY_KP_POWER] = false;			
	keyDown[KEY::KEY_KP_PERCENT] = false;			
	keyDown[KEY::KEY_KP_LESS] = false;				
	keyDown[KEY::KEY_KP_GREATER] = false;
	keyDown[KEY::KEY_KP_AMPERSAND] = false;
	keyDown[KEY::KEY_KP_DBLAMPERSAND] = false;	
	keyDown[KEY::KEY_KP_VERTICALBAR] = false;
	keyDown[KEY::KEY_KP_DBLVERTICALBAR] = false;
	keyDown[KEY::KEY_KP_COLON] = false;
	keyDown[KEY::KEY_KP_HASH] = false;	
	keyDown[KEY::KEY_KP_SPACE] = false;
	keyDown[KEY::KEY_KP_AT] = false;
	keyDown[KEY::KEY_KP_EXCLAM] = false;
	keyDown[KEY::KEY_KP_MEMSTORE] = false;	
	keyDown[KEY::KEY_KP_MEMRECALL] = false;
	keyDown[KEY::KEY_KP_MEMCLEAR] = false;	
	keyDown[KEY::KEY_KP_MEMADD] = false;
	keyDown[KEY::KEY_KP_MEMSUBTRACT] = false;
	keyDown[KEY::KEY_KP_MEMMULTIPLY] = false;
	keyDown[KEY::KEY_KP_MEMDIVIDE] = false;
	keyDown[KEY::KEY_KP_PLUSMINUS] = false;
	keyDown[KEY::KEY_KP_CLEAR] = false;
	keyDown[KEY::KEY_KP_CLEARENTRY] = false;
	keyDown[KEY::KEY_KP_BINARY] = false;
	keyDown[KEY::KEY_KP_OCTAL] = false;
	keyDown[KEY::KEY_KP_DECIMAL] = false;
	keyDown[KEY::KEY_KP_HEXADECIMAL] = false;
	keyDown[KEY::KEY_LCTRL] = false;
	keyDown[KEY::KEY_LSHIFT] = false;
	keyDown[KEY::KEY_LALT] = false;
	keyDown[KEY::KEY_LGUI] = false;
	keyDown[KEY::KEY_RCTRL] = false;
	keyDown[KEY::KEY_RSHIFT] = false;
	keyDown[KEY::KEY_RALT] = false;
	keyDown[KEY::KEY_RGUI] = false;
	keyDown[KEY::KEY_MODE] = false;
	keyDown[KEY::KEY_AUDIONEXT] = false;
	keyDown[KEY::KEY_AUDIOPREV] = false;
	keyDown[KEY::KEY_AUDIOSTOP] = false;
	keyDown[KEY::KEY_AUDIOPLAY] = false;
	keyDown[KEY::KEY_AUDIOMUTE] = false;
	keyDown[KEY::KEY_MEDIASELECT] = false;	
	keyDown[KEY::KEY_WWW] = false;	
	keyDown[KEY::KEY_MAIL] = false;
	keyDown[KEY::KEY_CALCULATOR] = false;
	keyDown[KEY::KEY_COMPUTER] = false;
	keyDown[KEY::KEY_AC_SEARCH] = false;
	keyDown[KEY::KEY_AC_HOME] = false;	
	keyDown[KEY::KEY_AC_BACK] = false;	
	keyDown[KEY::KEY_AC_FORWARD] = false;
	keyDown[KEY::KEY_AC_STOP] = false;	
	keyDown[KEY::KEY_AC_REFRESH] = false;
	keyDown[KEY::KEY_AC_BOOKMARKS] = false;
	keyDown[KEY::KEY_BRIGHTNESSDOWN] = false;
	keyDown[KEY::KEY_BRIGHTNESSUP] = false;
	keyDown[KEY::KEY_DISPLAYSWITCH] = false;
	keyDown[KEY::KEY_KBDILLUMTOGGLE] = false;
	keyDown[KEY::KEY_KBDILLUMDOWN] = false;
	keyDown[KEY::KEY_KBDILLUMUP] = false;
	keyDown[KEY::KEY_EJECT] = false;
	keyDown[KEY::KEY_SLEEP] = false;

	mouseDown[MB::MB_LEFT] = false;
	mouseDown[MB::MB_MIDDLE] = false;
	mouseDown[MB::MB_RIGHT] = false;
	mouseDown[MB::MB_X1] = false;
	mouseDown[MB::MB_X2] = false;
	mouseDown[MB::MB_LMASK] = false;
	mouseDown[MB::MB_MMASK] = false;
	mouseDown[MB::MB_RMASK] = false;
	mouseDown[MB::MB_X1MASK] = false;
	mouseDown[MB::MB_X2MASK] = false;
}

InputHandler::~InputHandler()
{

}

void InputHandler::Create()
{
	if (m_inputHandler == nullptr)
		m_inputHandler = new InputHandler();
}

void InputHandler::Destroy()
{
	if (m_inputHandler != nullptr)
	{
		delete m_inputHandler;
		m_inputHandler = nullptr;
	}
}

bool InputHandler::IsKeyDown(const KEY a_keyCode)
{
	return keyDown[a_keyCode];
}