#include "raylib.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

void start();

int main(){
	InitWindow(1600, 900, "ColiderBuilding");
	SetTargetFPS(240);
    start();
	CloseWindow();
	return 0;
}

void start(){
	bool isPaused;
    Cub *cu = new Cub;
	Rotator *rot = new Rotator(750, 400, true);
	badFood *bdf = new badFood(5, 100, 300);

	while(!WindowShouldClose()){
		
		rot->rotation1 += 1.0f;
		if(IsKeyDown(KEY_E)){isPaused = !isPaused;}

		BeginDrawing();
        if(cu->x > 1620 || cu->x < -20 || cu->y > 920) {
			start();
			delete cu;
			delete rot;
			delete bdf;
		}
	    
		else{
          ClearBackground(BLACK);
		  if(isPaused){
			DrawText("Press key E to resume the game", 300, 300, 60, WHITE);
		  }
		 
		  else{
            cu->cubMiscare();
		    bdf->draw();
		    cu->cubDraw();
		    rot->draw();
		  }
		 EndDrawing();
		}
	}
	delete cu;
	delete rot;
	delete bdf;
}