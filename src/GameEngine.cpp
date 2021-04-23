#include "GameEngine.h"

GameEngine::GameEngine()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  my_window = SDL_CreateWindow("Ashen Wind", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);

  my_renderer = SDL_CreateRenderer(my_window,-1,0);

  player = new Player();

  RunCurrentGame();
}

GameEngine::~GameEngine()
{
  SDL_DestroyRenderer(my_renderer);
  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
}

GAME_STATE_ENUM GameEngine::GetCurrentGameState()
{
    return (this->currentState < 0 || this->currentState > RUNNING) ? 
        INVALID : 
        this->currentState;
} 

void GameEngine::StopCurrentGame()
{
    currentState = STOPPED;
}

void GameEngine::PauseCurrentGame()
{
    currentState = PAUSED;
}

void GameEngine::RunCurrentGame()
{
    currentState = RUNNING;
}

void GameEngine::HandleEvents()
{
    //Player Health Check & Game Over


    //Player Input Handling
    SDL_Event gameEvent;
    while (SDL_PollEvent(&gameEvent))
    {
        if (gameEvent.type == SDL_QUIT) {
            StopCurrentGame();
        }
        else { 
            switch (gameEvent.key.keysym.sym)
            {
            case SDLK_w:
                break;
            
            case SDLK_a:
                break;

            case SDLK_s:
                break;

            case SDLK_d:
                break;

            default:
                break;
            }
        }
    }

    //Collision Check/Handling
}

void GameEngine::UpdateMechanics()
{
    //FunctionNotImplementedException
}

void GameEngine::Render()
{
    //Establish Surfaces, Create Textures and Rectangles, Free Surfaces

    //SDL_Surface* standinSurface = IMG_Load("./img");
    //SDL_Texture* standinTexture = SDL_CreateTextureFromSurface(my_renderer, standinSurface)
    //SDL_Rect standinRect {x, y, w, h};
    //SDL_FreeSurface(standinSurface);

    //Render Clear
    SDL_RenderClear(my_renderer);

    //Render Copy and/or Render Fill

    //SDL_RenderCopy(my_renderer, standinTexture, NULL, &standinRect);
    //SDL_RenderFillRect(my_renderer, &standinFillRect);
    
    //Render Present
    SDL_RenderPresent(my_renderer);
}