#pragma once

// For uint8_t
#include <stdint.h>

// An enumeration that represents the various states of the game
enum class GameState : uint8_t
{
	Titlescreen,
	Gameplay,
	GameOver,
	HighScore,
};