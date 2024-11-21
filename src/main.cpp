#include "raylib.h"
#include <iostream>

class Cub{
   public:
    int x = 100;
	int y = 100;
   
   void cubMiscare(){
	  if(IsKeyDown(KEY_LEFT_SHIFT)){
	  if(IsKeyDown(KEY_W)) y = y - 5;
	  if(IsKeyDown(KEY_S)) y = y + 5;
	  if(IsKeyDown(KEY_A)) x = x - 5;
	  if(IsKeyDown(KEY_D)) x = x + 5;
	}
	
	else{
      if(IsKeyDown(KEY_W)) y = y - 3;
	  if(IsKeyDown(KEY_S)) y = y + 3;
	  if(IsKeyDown(KEY_A)) x = x - 3;
	  if(IsKeyDown(KEY_D)) x = x + 3;

	}
   }

   void cubDraw(){
	 DrawCircle(x, y, 40, BLACK);
   }
};

class Enemy{
   public:
    int x;
	int y;

   Enemy(int poz_X, int poz_Y){
     x = poz_X;
	 y = poz_Y;
   }
   
   void draw(){
	 DrawRectangle(x, y, 30, 70, BLUE);
   }
};

int main(){
	bool isPaused = false;
	
	InitWindow(1600, 900, "ColiderBuilding");
	SetTargetFPS(60);
    Cub cu;
	Enemy en(200, 400);
	
	while(!WindowShouldClose()){
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
		  en.draw();
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

