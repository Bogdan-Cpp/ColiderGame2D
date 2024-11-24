#include "raylib.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

void start();
void collisionCheck(badFood *&bdf, Cub *cu);

int main(){
	InitWindow(1600, 900, "ColiderBuilding");
	SetTargetFPS(240);
    start();
	CloseWindow();
	return 0;
}

void start(){
	bool isPaused= false;
    Cub *cu = new Cub;
	Rotator *rot = new Rotator(750, 400);
	badFood *bdf = new badFood(5, 100, 300);

	while(!WindowShouldClose()){
		rot->rotation1 += 1.0f;
        //collision
        collisionCheck(bdf, cu);

        if(cu->x > 1620 || cu->x < -20 || cu->y > 920) {
			delete cu;
			delete rot;
			delete bdf;
			cu = new Cub;
			rot = new Rotator(750, 400);
			bdf = new badFood(5, 100, 300);
			isPaused = false;
		}
		if(IsKeyPressed(KEY_E)){isPaused = !isPaused;}

		BeginDrawing();
        
        ClearBackground(BLACK);

		if(isPaused){
			DrawText("Press key E to resume the game", 300, 300, 60, WHITE);
		}
		 
		else{
            cu->cubMiscare();
		    cu->cubDraw();
		    rot->draw();
			if(bdf != nullptr){
				bdf->draw();
			}
		}
		EndDrawing();
	}
	delete cu;
	delete rot;
    delete bdf;
}

void collisionCheck(badFood *&bdf, Cub *cu){
	if(bdf != nullptr && CheckCollisionCircles(cu->circle2, cu->r2, bdf->cerc1, bdf->r1)){
		cu->r2 += 3;
		delete bdf;
		bdf = nullptr;
	}
}