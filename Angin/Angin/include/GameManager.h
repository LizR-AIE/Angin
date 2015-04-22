#pragma once

#ifdef ANGIN_EXPORTS
#	define ANGIN_API __declspec(dllexport)
#else
#	define ANGIN_API __declspec(dllimport)
#endif

class GameManager
{
public:
	ANGIN_API GameManager();
	ANGIN_API ~GameManager();


};