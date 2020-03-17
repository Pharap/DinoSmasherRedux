#pragma once

// For uint8_t
#include <stdint.h>

// For pgm_read_byte
#include <avr/pgmspace.h>

// An enumeration that represents the different tile types
enum class Tile : uint8_t
{
	Grass,
	Water,
	Tree,
	Stone,
};

// Converts the tile types into the frame index
// needed to draw a tile
constexpr size_t getTileIndex(Tile tile)
{
	return static_cast<size_t>(tile);
}

// Required if 'world' is put into progmem
inline Tile readTileFromProgmem(const Tile * tile)
{
	return static_cast<Tile>(pgm_read_byte(tile));
}