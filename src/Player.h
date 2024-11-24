class Cub{
   public:
    float x = 730;
	float y = 859;
	Vector2 circle2 = {x, y};
	int r2 = 40.0f;
   
   void cubMiscare(){
	  if(IsKeyDown(KEY_Q)){
	  y = y - 4;
	  if(IsKeyDown(KEY_S)) y = y + 5;
	  if(IsKeyDown(KEY_A)) x = x - 5;
	  if(IsKeyDown(KEY_D)) x = x + 5;
	}
	
	else{
      y = y - 1;
	  if(IsKeyDown(KEY_S)) y = y + 3;
	  if(IsKeyDown(KEY_A)) x = x - 3;
	  if(IsKeyDown(KEY_D)) x = x + 3;
	}
	circle2 = {x, y};
   }

   void cubDraw(){
	 DrawCircleV(circle2, r2, YELLOW);
   }
};