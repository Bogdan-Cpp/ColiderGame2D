#include "raylib.h"
#include <iostream>

class Cub{
   public:
    int x = 100;
	int y = 100;
   
   void cubMiscare(){
     if(IsKeyDown(KEY_W)) y = y - 1;
	 if(IsKeyDown(KEY_S)) y = y + 1;
	 if(IsKeyDown(KEY_A)) x = x - 1;
	 if(IsKeyDown(KEY_D)) x = x + 1;
	 std::cout << "X: " << x << " Y: " << y << '\n';
   }

   void cubDraw(){
	 DrawRectangle(x, y, 50, 50, RED);
   }
};

class Enemy{
   public:
    int x;
	int y;

   Enemy(int poz_X, int poz_Y){
     poz_X = x;
	 poz_Y = y;
   }
};

int main(){
	bool isActive = false;
	
	InitWindow(600, 600, "joc");
	SetTargetFPS(60);
    Cub cu;
	
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(WHITE);
        cu.cubMiscare();
		cu.cubDraw();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

