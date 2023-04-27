#include <raylib.h>
#include <time.h>

#include <stdlib.h>
#include <stdio.h>


struct Item
{
	double posX, posY;

};


int main() {
	struct Item enemies[3];

	for (int i = 0; i < 3; i++)
	{

	}


	InitWindow(800, 600, "first \"game\"");
	SetTargetFPS(144);
	float posX = 400;
	float posY = 10;
	int playerSpeed = 350;
	float velocity = 0;
	float acceleration = 0.1;
	float itemPosY = 70;
	float itemPosX = 70;
	
	Texture2D playertexture = LoadTexture("resources/Player.png");
	Texture2D itemtexture = LoadTexture("resources/enemy.png");

	Rectangle player = { posX, posY, playertexture.width * 0.15, playertexture.height * 0.15};
	Rectangle item = { itemPosX, itemPosY, itemtexture.width * 0.15, itemtexture.height * 0.15};
	

	while (!WindowShouldClose()) {
		
		Vector2 itemPos;
		itemPos.x = itemPosX;
		itemPos.y = itemPosY;



		Vector2 playerPos;
		playerPos.x = posX;
		playerPos.y = posY;
		
		
		
		


		posY += velocity;
		velocity += acceleration;
		
		itemPosY++;

		if (itemPosY >= 564) {
			itemPosY = -200;
		}


		if (IsKeyPressed(KEY_W)) {
			velocity = -3;
		}

		if (IsKeyDown(KEY_A)) {
			posX += -playerSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_D)) {
			posX += playerSpeed * GetFrameTime();
		}
		if (posX <= 0) {
			posX = 0;
		}
		if (posX >= 755) {
			posX = 755;
		}
		if (posY <= 0) {
			posY = 0;
		}
		if (posY >= 564) {
			posY = 564;
		}
		
		player.x = posX;
		player.y = posY;
		item.x = itemPosX;
		item.y = itemPosY;

		bool collision = CheckCollisionRecs(player, item);

		if (collision)
		{
			printf("Collision\n");
		}
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawFPS(600,580);
		DrawText("first \"game\"", 700, 580, 15, BLACK);
		DrawTextureEx(itemtexture, itemPos, 0, 0.15, WHITE);
		DrawTextureEx(playertexture,playerPos, 0, 0.15, WHITE);
		

		EndDrawing();
	}
}