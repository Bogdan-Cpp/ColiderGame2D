#include "raylib.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

int main(){
	bool isPaused = false;
	
	InitWindow(1600, 900, "ColiderBuilding");
	SetTargetFPS(240);
    Cub cu;
	Enemy en1(200, 400, true);
	Enemy en2(500, 400, true);
	Enemy en3(800, 400, true);
	
	while(!WindowShouldClose()){
		en1.rotation1 += 1.0f;
		en2.rotation1 += -1.0f;
		en3.rotation1 += 1.0f;

		if(IsKeyDown(KEY_E)){
            isPaused = !isPaused;
		}
		BeginDrawing();

		ClearBackground(WHITE);
		if(isPaused){
			DrawText("Press key E to resume the game", 300, 300, 60, BLACK);
		}
		else{
          cu.cubMiscare();
		  cu.cubDraw();
		  en1.draw();
		  en2.draw();
		  en3.draw();
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}