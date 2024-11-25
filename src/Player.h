class Cub{
   public:
    float x = 730;
	float y = 859;
	Vector2 circle2 = {x, y};
	int r2 = 27.0f;
   
   void cubMiscare(){
      y = y - 3;
	  if(IsKeyDown(KEY_S)) y = y + 10;
	  if(IsKeyDown(KEY_A)) x = x - 15;
	  if(IsKeyDown(KEY_D)) x = x + 15;
	
	circle2 = {x, y};
   }

   void cubDraw(){
	 DrawCircleV(circle2, r2, YELLOW);
   }
};