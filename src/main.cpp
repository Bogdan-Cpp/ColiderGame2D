#include "raylib.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

void start();
void badFod_collision(badFood *&bdf, Cub *cu);
void Rotator_collision(Cub *cu, Rotator *rot, bool &isRestarted);
void goodFood_collision(Cub *cu, goodFood *&gdf);

int main(){
	InitWindow(1600, 900, "ColiderBuilding");
	SetTargetFPS(60);
    start();
	CloseWindow();
	return 0;
}

void start(){
	bool isPaused= false;
	bool isRestarted = false;
    Cub *cu = new Cub;
	Rotator *rot = new Rotator(750, 400, 500, 30);
	badFood *bdf = new badFood(5, 100, 300);
	goodFood *gdf = new goodFood(50, 100, 7);

	while(!WindowShouldClose()){
		std::cout << cu->r2 << '\n';
        //collision
        badFod_collision(bdf, cu);
		Rotator_collision(cu, rot, isRestarted);
	    goodFood_collision(cu, gdf);

        if(cu->x > 1620 || cu->x < -20 || cu->y > 920) {
			isRestarted = true;
		}
		
		if(IsKeyPressed(KEY_E)){isPaused = !isPaused;}
		
		if(isRestarted){
           delete cu;
		   delete rot;
		   delete bdf;
		   delete gdf;

		   cu = new Cub;
		   rot = new Rotator(750, 400, 500, 30);
		   bdf = new badFood(5, 100, 300);
		   gdf = new goodFood(50, 100, 7);

		   isPaused = false;
		   isRestarted = false;
		}
		
		BeginDrawing();
        
        ClearBackground(BLACK);

		if(isPaused){
			DrawText("Press key E to resume the game", 300, 300, 60, WHITE);
		}
		 
		else{
            cu->cubMiscare();
		    cu->cubDraw();
		    rot->draw();
			if(gdf != nullptr){
               gdf->draw();
			}
			if(bdf != nullptr){
				bdf->draw();
			}
		}
		EndDrawing();
	}
	delete cu;
	delete rot;
    delete bdf;
	delete gdf;
}

void badFod_collision(badFood *&bdf, Cub *cu){
	if(bdf != nullptr && CheckCollisionCircles(cu->circle2, cu->r2, bdf->cerc1, bdf->r1)){
		cu->r2 += 3;
		delete bdf;
		bdf = nullptr;
	}
}

void goodFood_collision(Cub *cu, goodFood *&gdf){
	if(gdf != nullptr && CheckCollisionCircles(cu->circle2, cu->r2, gdf->circle, gdf->r)){
		if(cu->r2 <= 20.0f){cu->r2 += 0;}
		if(cu->r2 == 21.0f){cu->r2 -= 1;}
		if(cu->r2 > 21){cu->r2 -= 2;}
		
		delete gdf;
		gdf = nullptr;
	}
}

void Rotator_collision(Cub *cu, Rotator *rot, bool &isRestarted){
    if(CheckCollisionCircleRec(cu->circle2, cu->r2, rot->prop)){
		isRestarted = true;
	}
}