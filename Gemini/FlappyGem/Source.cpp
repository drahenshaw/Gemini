#include <iostream>
#include <time.h>
#include "GameManager.h"

int main(void)
{
	srand(time(NULL));
	static GameManager & gameManager = GameManager::get_instance();
	gameManager.StartUp();
	gameManager.PlayGame();
	return 0;
}