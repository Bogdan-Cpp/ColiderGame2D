class Cub{
   public:
    float x = 730;
	float y = 859;
	Vector2 circle2 = {x, y};
	int r2 = 21.0f;
   
   void cubMiscare(){
      y = y - 3;
	  if(IsKeyDown(KEY_A)) x = x - 1000 * GetFrameTime();
	  if(IsKeyDown(KEY_D)) x = x + 1000 * GetFrameTime();
	
	circle2 = {x, y};
   }

   void cubDraw(){
	 DrawCircleV(circle2, r2, YELLOW);
   }
};