#ifndef GEMINI_PIPEMANAGER
#define GEMINI_PIPEMANAGER

#include "Pipe.h"
#include "Flapper.h"
#include <vector>

class PipeManager
{
	struct Separation
	{
		float x;
		float y;
	};

	struct SpawnPoint
	{
		float x;
		float y;
	};

public:
	PipeManager();
	~PipeManager();
	
	void Update();
	void Render();

	bool CheckCollision(Flapper & flapper);

	void Reset();

private:
	void CreatePipe();

private:
	std::vector<Pipe*> pipes_;		
	struct Separation initial_;
	struct Separation current_;
	struct Separation minimum_;
	struct Separation speed_;
	struct SpawnPoint min_max_spawn_y_;
	int spawned_pipes_;
	Error * error_;

};

#endif // !GEMINI_PIPEMANAGER