#include "raylib.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

int main(){
	bool isPaused;
	
	InitWindow(1600, 900, "ColiderBuilding");
	SetTargetFPS(240);
    Cub cu;
	Rotator rot(750, 400, true);
	badFood bdf(5, 100, 300);
	
	while(!WindowShouldClose()){
		rot.rotation1 += 1.0f;

		if(IsKeyDown(KEY_E)){
            isPaused = !isPaused;
		}
		BeginDrawing();

		ClearBackground(BLACK);
		if(isPaused){
			DrawText("Press key E to resume the game", 300, 300, 60, WHITE);
		}
		else{
          cu.cubMiscare();
		  bdf.draw();
		  cu.cubDraw();
		  rot.draw();
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}