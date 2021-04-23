#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "build/SDL2.dll"
#include <SDL2.dll/SDL.h> 
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "Player.h"
#include "Sprite.h"

enum GAME_STATE_ENUM {INVALID = -1 , STOPPED = 0 , PAUSED = 1 , RUNNING = 2};

class GameEngine
{
private:

    GAME_STATE_ENUM currentState;

    //Screen dimension
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //1 second in MS divided by expected frame rate
    const int FRAME_DURATION = 1000 / 60; 

    //Player Character
    Player player;

public:

    SDL_Window* my_window = NULL;
    SDL_Renderer* my_renderer = NULL;
    SDL_Event* input;

    GameEngine();
    ~GameEngine();

    GAME_STATE_ENUM GetCurrentGameState();
    void StopCurrentGame();
    void PauseCurrentGame();
    void RunCurrentGame();

    void HandleEvents();

    void UpdateMechanics();

    void Render();
};