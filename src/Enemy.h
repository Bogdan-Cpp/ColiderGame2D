#include "raylib.h"

class Rotator{
   public:
    Rectangle prop;
    Vector2 org;
    float rotation1 = 0.0f;
    int x;
	 int y;
	 bool r;

   Rotator(int poz_X, int poz_Y, bool isLeft){
     x = poz_X;
	  y = poz_Y;
	  r = isLeft;

     prop = {static_cast<float>(x), static_cast<float>(y), 20, 500};
     org = {prop.width / 2, prop.height / 2};
   }

   void draw(){
	 DrawRectanglePro(prop, org, rotation1, BLUE);
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