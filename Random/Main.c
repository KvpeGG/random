#include <raylib.h>
#include <stdio.h>

int main() {
	InitWindow(800, 600, "first \"game\"");
	SetTargetFPS(144);
	float posX = 400;
	float posY = 10;
	int playerSpeed = 350;
	float velocity = 0;
	float acceleration = 0.1;
	
	
	Texture2D playertexture = LoadTexture("resources/Player.png");
	Texture2D enemytexture = LoadTexture("resources/Enemy.png");

	Rectangle player = { posX, posY, playertexture.width * 0.15, playertexture.height * 0.15};
	Rectangle enemy = { 200, 200, enemytexture.width * 0.15, enemytexture.height * 0.15};
	

	while (!WindowShouldClose()) {
		
		
		Vector2 enemyPos;
		enemyPos.x = 200;
		enemyPos.y = 200;



		Vector2 playerPos;
		playerPos.x = posX;
		playerPos.y = posY;
		
		
		

		posY += velocity;
		velocity += acceleration;
		

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

		bool collision = CheckCollisionRecs(player, enemy);

		if (collision)
		{
			printf("Collision\n");
		}
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		//DrawTexture(playertexture, posX, posY, WHITE);
		//DrawRectangle(posX, posY, 20, 20, BLACK);
		DrawFPS(600,580);
		DrawText("first \"game\"", 700, 580, 15, BLACK);
		DrawTextureEx(enemytexture, enemyPos, 0, 0.15, WHITE);
		DrawTextureEx(playertexture,playerPos, 0, 0.15, WHITE);
		

		EndDrawing();
	}
}