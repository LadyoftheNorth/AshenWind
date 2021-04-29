#ifndef Enemy_h
#define Enemy_h

//#include <SDL/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_timer.h>

class Enemy {
   public:
      Enemy();
      ~Enemy();
      void moveLeft(int tempX);
      void moveRight(int tempX);
      int enemyMove(int currX);

   private:
      bool isMovingLeft;
      bool isMovingRight;
      int timer;
      int speed;
};
#endif
