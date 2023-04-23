#include <raylib.h>

int main() {
	InitWindow(800, 600, "first \"game\"");
	SetTargetFPS(144);
	float posX = 400;
	float posY = 10;
	int playerSpeed = 350;
	float velocity = 0;
	float acceleration = 0.1;
	Rectangle player = {posX, posY, 20, 20};
	Rectangle enemy = { 200, 200, 20, 20 };
	Texture2D playertexture = LoadTexture("E:/images/Player.png");
	Texture2D enemytexture = LoadTexture("E:/images/Enemy.png");

	SetTextureFilter(enemytexture, TEXTURE_FILTER_BILINEAR);
	SetTextureFilter(playertexture, TEXTURE_FILTER_BILINEAR);

	while (!WindowShouldClose()) {
		
		
		Vector2 enemyPos;
		enemyPos.x = 21;
		enemyPos.y = 21;



		Vector2 playerPos;
		playerPos.x = posX;
		playerPos.y = posY;

		//collision detection:
		bool collision = CheckCollisionRecs(player, enemy);
		
		if (collision) {
			DrawText("collision", 500, 300, 12, BLUE);
		}
		

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