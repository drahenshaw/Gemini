#include "GameManager.h"

GameManager & GameManager::get_instance()
{
	static GameManager instance;
	return instance;
}

GameManager::~GameManager()
{
	delete game_engine_;
	delete player_;
	delete pipe_manager_;
}

void GameManager::StartUp()
{
	game_engine_->get_instance();
	game_engine_->StartUp("Flappy Gemini", error_);

	Sprite flapper_sprite = Sprite();
	flapper_sprite.setScale(0.70f);
	player_ = new Flapper(flapper_sprite);

	pipe_manager_ = new PipeManager();

	start_screen_     = Sprite();
	level_background_ = Sprite();

	state_ = GameState::START;
}

void GameManager::PlayGame(Error * error)
{
	while (!game_engine_->should_window_close())
	{
		if (Keyboard::KeyDown(GLFW_KEY_ESCAPE))
		{
			break;
		}

		game_engine_->Update();

		switch (state_)
		{
		case GameState::START:
		{
			game_engine_->BeginRender();
			start_screen_.Render();
			game_engine_->EndRender();

			if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
			{
				set_game_state(GameState::GAMEPLAY);
			}
			break;
		}
		case GameState::GAMEPLAY:
		{
			player_->Update();
			pipe_manager_->Update();

			game_engine_->BeginRender();
			level_background_.Render();
			player_->Render();
			pipe_manager_->Render();
			game_engine_->EndRender();

			bool is_colliding = pipe_manager_->CheckCollision(*player_);

			if (is_colliding)
			{
				set_game_state(GameState::GAMEOVER);
			}

			if (player_->get_sprite().get_position()->y_ < 0 || player_->get_sprite().get_position()->y_ > Engine::SCREEN_HEIGHT)
			{
				set_game_state(GameState::GAMEOVER);
			}
			break;
		}
		case GameState::GAMEOVER:
		{
			game_engine_->BeginRender();
			player_->Render();
			pipe_manager_->Render();
			end_screen_.Render();
			game_engine_->EndRender();

			if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
			{
				set_game_state(GameState::GAMEPLAY);
			}
			break;
		}
		default:
			error->set_errorStatus(true);
			error->set_errorDescription("Unhandled Game State: " + static_cast<int> (state_));
			error->set_errorName(Error::EngineErrors::kUnhandledGameState);
			std::cout << error;
			break;
		}
	}
}

void GameManager::WindowCloseCallback(GLFWwindow * window)
{
	set_game_state(GameState::EXIT);
}

void GameManager::set_game_state(const GameState & state)
{
	state_ = state;

	if (state == GameState::START)
	{
		player_->Reset();
		pipe_manager_->Reset();
	}
}
