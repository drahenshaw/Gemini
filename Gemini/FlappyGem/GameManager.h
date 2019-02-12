#ifndef GEMINI_GAMEMANAGER
#define GEMINI_GAMEMANAGER

#include "../Gemini//Engine/Engine.h"
#include "../Gemini/Engine/Graphics/Sprite.h"
#include "../Gemini/Engine/IO/Keyboard.h"
#include "../Gemini/Engine/IO/Mouse.h"


#include "Flapper.h"
#include "PipeManager.h"


class GameManager
{

public:

	enum class GameState
	{
		START,
		GAMEPLAY,
		GAMEOVER,
		EXIT,
		COUNT
	};

public:
	static GameManager & get_instance();
	GameManager   (GameManager const&) = delete;
	void operator=(GameManager const&) = delete;

	~GameManager();

	void StartUp();
	void PlayGame(Error * error = 0);
	void WindowCloseCallback(GLFWwindow * window);

private:
	
	void set_game_state(const GameState & state);
	GameManager() {};

private:
	Engine  * game_engine_;
	Flapper * player_;
	PipeManager * pipe_manager_;
	Error * error_;

	GameState state_;
	Sprite start_screen_;
	Sprite end_screen_;
	Sprite level_background_;
};






#endif // !GEMINI_GAMEMANAGER
