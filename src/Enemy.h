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
      int raza;
      int x;
      int y;

   badFood(int r, int poz_X, int poz_Y){
      raza = r;
      x = poz_X;
      y = poz_Y;
   }

   void draw(){
      DrawCircle(x, y, raza, ORANGE);
   }
};