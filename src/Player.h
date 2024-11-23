class Cub{
   public:
    int x = 730;
	int y = 859;
   
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
   }

   void cubDraw(){
	 DrawCircle(x, y, 40, YELLOW);
   }
};