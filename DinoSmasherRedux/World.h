#pragma once

// For uint8_t
#include <stdint.h>

#include "Tile.h"

// The dimensions of the world, in tiles
constexpr uint8_t worldWidth = 14;
constexpr uint8_t worldHeight = 7;

// A mutable array representing the world
Tile world[worldHeight][worldWidth]
{
	{ Tile::Tree, Tile::Grass, Tile::Grass, Tile::Water, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Tree, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Tree },
	{ Tile::Grass, Tile::Water, Tile::Water, Tile::Water, Tile::Grass, Tile::Water, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Stone, Tile::Grass, Tile::Grass },
	{ Tile::Grass, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Water, Tile::Stone, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Tree, Tile::Grass, Tile::Grass, Tile::Grass },
	{ Tile::Stone, Tile::Grass, Tile::Grass, Tile::Stone, Tile::Tree, Tile::Water, Tile::Water, Tile::Water, Tile::Grass, Tile::Water, Tile::Water, Tile::Grass, Tile::Tree, Tile::Grass },
	{ Tile::Grass, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Tree, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Tree, Tile::Water, Tile::Grass, Tile::Grass, Tile::Stone, Tile::Tree },
	{ Tile::Grass, Tile::Grass, Tile::Grass, Tile::Water, Tile::Stone, Tile::Grass, Tile::Grass, Tile::Tree, Tile::Tree, Tile::Tree, Tile::Grass, Tile::Grass, Tile::Water, Tile::Water },
	{ Tile::Grass, Tile::Water, Tile::Water, Tile::Tree, Tile::Grass, Tile::Water, Tile::Water, Tile::Tree, Tile::Tree, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Grass, Tile::Stone }
};