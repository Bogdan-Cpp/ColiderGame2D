#include "raylib.h"

class Rotator{
   public:
    Rectangle prop;
    int x;
	 int y;
    int w;
    int h;

   Rotator(int poz_X, int poz_Y, int width, int height){
     x = poz_X;
	  y = poz_Y;
     w = width;
     h = height;
     prop = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(w), static_cast<float>(h)};
   }

   void draw(){
	  DrawRectangle(x, y, w, h, BLUE);
   }
};

class badFood{
   public:
      float x;
      float y;
      Vector2 cerc1 {x, y};
      int r1 = 6.0f;

   badFood(int raza, float poz_X, float poz_Y){
      r1 = raza;
      x = poz_X;
      y = poz_Y;
      cerc1 = {x, y};
   }

   void draw(){
      DrawCircleV(cerc1, r1, ORANGE);
   }
};