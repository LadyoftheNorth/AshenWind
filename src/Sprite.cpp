#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* ren, const char* graphic, int width, int height)
{
	//Initialize
	my_renderer = ren;
	spriteTexture = SDL_CreateTextureFromSurface(my_renderer, IMG_Load(graphic));
	spriteWidth = width;
	spriteHeight = height;
}

Sprite::~Sprite()
{
	FreeTexture();
}

bool Sprite::LoadFromFile( std::string path )
{
	//Get rid of preexisting texture
	FreeTexture();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( my_renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			spriteWidth = loadedSurface->w;
			spriteHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	spriteTexture = newTexture;
	return spriteTexture != NULL;
}

void Sprite::FreeTexture()
{
	if( spriteTexture != NULL )
	{
		SDL_DestroyTexture( spriteTexture );
		spriteTexture = NULL;
		spriteWidth = 0;
		spriteHeight = 0;
	}
}

void Sprite::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, spriteWidth, spriteHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( my_renderer, spriteTexture, clip, &renderQuad, angle, center, flip );
}

int Sprite::getWidth()
{
	return spriteWidth;
}

int Sprite::getHeight()
{
	return spriteHeight;
}
