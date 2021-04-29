#include <iostream>
#include <string>

#include "enemy.h"
#include <SDL2/SDL_timer.h>

Enemy::Enemy(){
   isMovingLeft = false;
   isMovingRight = false;
   timer = 10;
   speed = 8;
}

Enemy::~Enemy(){
}

void Enemy::moveLeft(int tempX){
   tempX += speed;
   timer--;
}

void Enemy::moveRight(int tempX){
   tempX -= speed;
   timer--;
}

//Acts as the 'Idle' stage of the state machine
int Enemy::enemyMove(int currX){
   if(isMovingLeft == true && timer > 0){
	moveLeft(currX);
   }

   if(isMovingLeft == true && timer == 0){
	isMovingLeft = false;
	isMovingRight = true;
   }

   if(isMovingRight == true && timer > 0){
	moveRight(currX);
   }

   if(isMovingRight == true && timer == 0){
        isMovingLeft = true;
        isMovingRight = false;
   }

   return currX;
}
