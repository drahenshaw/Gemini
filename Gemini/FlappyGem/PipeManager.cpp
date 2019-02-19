#include "PipeManager.h"

PipeManager::PipeManager() 
{
	initial_ = { 800, 500 };
	current_ = initial_;
	minimum_ = { 200, 300 };
	speed_   = { 10, 10 };
	min_max_spawn_y_ = { 284, Engine::SCREEN_HEIGHT - 284 };
	spawned_pipes_ = 0;
	error_ = new Error();
	{
		Pipe::Initialize();
		CreatePipe();
	}
}

PipeManager::~PipeManager()
{
	for (unsigned int i = 0; i < pipes_.size(); ++i)
	{
		delete pipes_[i];
	}
}

void PipeManager::Update()
{
	std::vector<unsigned int> pipes_delete;

	for (unsigned int i = 0; i < pipes_.size(); ++i)
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
			if (pipes_[i]->get_positon_x() < (Engine::SCREEN_WIDTH - current_.x))
			{
				CreatePipe();
			}
		}

		// Clean Up		

		for (unsigned int i = 0; i < pipes_delete.size(); ++i)
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
	for (unsigned int i = 0; i < pipes_.size(); ++i)
	{
		pipes_[i]->Render();
	}
}

bool PipeManager::CheckCollision(Flapper & flapper)
{
	for (unsigned int i = 0; i < pipes_.size(); ++i)
	{
		if (Rigidbody::IsColliding(flapper.get_rigidbody(), pipes_[i]->get_top_rigidbody())
		||  Rigidbody::IsColliding(flapper.get_rigidbody(), pipes_[i]->get_bottom_rigidbody()))
		{
			return true;
		}
	}
	return false;
}

void PipeManager::Reset()
{
	for (unsigned int i = 0; i < pipes_.size(); ++i)
	{
		delete pipes_[i];
	}
	pipes_.clear();

	current_ = initial_;
	spawned_pipes_ = 0;
	CreatePipe();
}

void PipeManager::CreatePipe()
{
	SpawnPoint spawn;
	spawn.x = Engine::SCREEN_WIDTH / 2;
	spawn.y = (rand() % (int)(min_max_spawn_y_.y - min_max_spawn_y_.x)) + min_max_spawn_y_.x;

	Pipe * pipe = new Pipe(Vector3(Engine::SCREEN_WIDTH, spawn.y, 0), error_);
	pipe->set_gap(current_.y);
	pipes_.push_back(pipe);
	if (error_->IsSet()) return;

	spawned_pipes_++;

	if (spawned_pipes_ % 2 == 0)
	{
		if (current_.x > minimum_.x + speed_.x)
		{
			current_.x -= speed_.x;
		}

		if (current_.y > minimum_.y + speed_.y)
		{
			current_.y -= speed_.y;
		}
	}
}
