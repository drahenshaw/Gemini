#include "PipeManager.h"

PipeManager::PipeManager() 
{
	initial_ = { 800, 500 };
	current_ = initial_;
	minimum_ = { 200, 300 };
	speed_   = { 10, 10 };
	min_max_spawn_y_ = { 284, Engine::SCREEN_HEIGHT - 284 };
	spawned_pipes_ = 0; //Do I even need this?

}

PipeManager::~PipeManager()
{
	for (GLushort i = 0; i < pipes_.size(); ++i)
	{
		delete pipes_[i];
	}
}

void PipeManager::Update()
{
	std::vector<GLushort> pipes_delete;

	for (GLushort i = 0; i < pipes_.size(); ++i)
	{
		// Update each Pipe
		pipes_[i]->Update();

		// If Pipe goes off screen mark for deletion
		if (pipes_[i]->get_positon_x() < -(pipes_[i]->get_width() / 2))
		{
			pipes_delete.push_back(i);
		}

		// On the last element determine if a new pipe should spawn - past half screen
		if (i == pipes_.size() - 1)
		{
			if (pipes_[i]->get_positon_x < Engine::SCREEN_WIDTH - current_.x)
			{
				CreatePipe();
			}
		}

		// Clean Up		

		for (GLushort i = 0; i < pipes_delete.size(); ++i)
		{
			// Delete nth pipe via Pipe pointer
			delete pipes_[pipes_delete[i]];

			// Erase the nth pipe from the clean up vector using an iterator
			pipes_.erase(pipes_.begin() + pipes_delete[i]);
		}
	}
}

void PipeManager::Render()
{
	for (GLushort i = 0; i < pipes_.size(); ++i)
	{
		pipes_[i]->Render();
	}
}

bool PipeManager::CheckCollision(Flapper & flapper)
{
	if (flapper.get_rigidbody().IsColliding(flapper.get_rigidbody()))
	{

	}
}

void PipeManager::Reset()
{
}

void PipeManager::CreatePipe()
{
}
