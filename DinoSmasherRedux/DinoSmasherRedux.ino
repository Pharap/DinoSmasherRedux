//
// Dino Smasher Redux
//
// An enhanced version of Crait's DinoSmasher.
// Heavily modified by Pharap.
//

//
// External Includes
//

#include <Arduboy2.h>

//
// Internal Includes
//

#include "GameState.h"
#include "TileImages.h"
#include "Tile.h"
#include "World.h"

//
// Constants
//

// The height and width of the player
constexpr uint8_t playerWidth = 16;
constexpr uint8_t playerHeight = 16;

// The offset into the screen in which the player is drawn
constexpr uint8_t playerXOffset = ((WIDTH / 2) - (playerWidth / 2));
constexpr uint8_t playerYOffset = ((HEIGHT / 2) - (playerHeight / 2));

//
constexpr uint8_t playerLeft = playerXOffset;
constexpr uint8_t playerRight = (playerXOffset + playerWidth);
constexpr uint8_t playerTop = playerYOffset;
constexpr uint8_t playerBottom = (playerYOffset + playerHeight);

//
// GlobalVariables
//

// The Arduboy2 library object
Arduboy2 arduboy;

// The game state object (see "GameState.h")
GameState gameState = GameState::Titlescreen;

// The map offset
int mapX = 0;
int mapY = 0;

// The setup function, called once on start up
void setup()
{
	// Initialise the Arduboy
	arduboy.begin();
}

// The loop function, called continuously
void loop()
{
	// If it's not time to draw the next frame
	if(!arduboy.nextFrame())
		// Exit from this call to loop
		return;

	// Update the button state
	arduboy.pollButtons();

	// Clear the screen
	arduboy.clear();

	// Update and render the current game state
	dispatchState();

	// Update the screen
	arduboy.display();
}

// Update and render the current game state
void dispatchState()
{
	switch(gameState)
	{
		case GameState::Titlescreen:
			updateTitlescreenState();
			renderTitlescreenState();
			break;

		case GameState::Gameplay:
			updateGameplayState();
			renderGameplayState();
			break;

		case GameState::GameOver:
			updateGameOverState();
			renderGameOverState();
			break;

		case GameState::HighScore:
			updateHighScoreState();
			renderHighScoreState();
			break;
	}
}

void updateTitlescreenState()
{
	if (arduboy.justPressed(A_BUTTON))
		gameState = GameState::Gameplay;
}

void renderTitlescreenState()
{
	arduboy.print(F("Title Screen\n"));
}

void updateGameOverState()
{
	if (arduboy.justPressed(A_BUTTON))
		gameState = GameState::HighScore;
}

void renderGameOverState()
{
	arduboy.print(F("Game Over Screen\n"));
}

void updateHighScoreState()
{
	if (arduboy.justPressed(A_BUTTON))
		gameState = GameState::Titlescreen;
}

void renderHighScoreState()
{
	arduboy.print(F("High Score Screen\n"));
}


void updateGameplayState()
{
	handlePlayerInput();

	if (arduboy.justPressed(A_BUTTON))
		gameState = GameState::GameOver;
}

void handlePlayerInput()
{
	if (arduboy.pressed(UP_BUTTON))
		if (mapY < playerTop)
			++mapY;

	const int mapYEnd = (mapY + (tileHeight * worldHeight));
	if (arduboy.pressed(DOWN_BUTTON))
		if (playerBottom < mapYEnd)
			--mapY;

	if (arduboy.pressed(LEFT_BUTTON))
		if (mapX < playerLeft)
			++mapX;

	const int mapXEnd = (mapX + (tileWidth * worldWidth));
	if (arduboy.pressed(RIGHT_BUTTON))
		if (playerRight < mapXEnd)
			--mapX;
}

void renderGameplayState()
{
	drawTiles();
	drawMapCoords();
	drawPlayer();
}

void drawTiles()
{
	constexpr size_t horizontalTileCount = ((WIDTH / tileWidth) + 1);
	constexpr size_t verticalTileCount = ((HEIGHT / tileHeight) + 1);

	for (size_t y = 0; y < verticalTileCount; ++y)
	{
		const int tileY = (y - (mapY / tileHeight));

		// If tileY is out of bounds
		if ((tileY < 0) || (tileY >= worldHeight))
			// continue with the next iteration
			continue;

		for (size_t x = 0; x < horizontalTileCount; x++)
		{
			const int tileX = (x - (mapX / tileWidth));

			// If tileY is out of bounds
			if ((tileX < 0) || (tileX >= worldWidth))
				// continue with the next iteration
				continue;
			
			const size_t drawX = ((x * tileWidth) + (mapX % tileWidth));
			const size_t drawY = ((y * tileHeight) + (mapY % tileHeight));

			const size_t frameIndex = getTileIndex(world[tileY][tileX]);

			Sprites::drawOverwrite(drawX, drawY, tileImages, frameIndex);
		}
	}
}

// Draws the map coords in the top left of the screen
void drawMapCoords()
{
	// Draw a black rectangle first
	arduboy.fillRect(0, 0, 48, 8, BLACK);

	// Print the coordinates over top of the rectangle
	arduboy.print(mapX);
	arduboy.print(F(", "));
	arduboy.print(mapY);
}

// Draws the player
void drawPlayer()
{
	// Draw the player as a filled black rectangle
	// Swap this with a sprite drawing function to draw a player sprite
	arduboy.fillRect(playerXOffset, playerYOffset, playerWidth, playerHeight, BLACK);
}