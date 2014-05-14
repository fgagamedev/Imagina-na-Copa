#ifndef CANVAS_Hs
#define CANVAS_H

#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "fillpoints.h"
#include "renderpresent.h"

class Canvas
{
	public:
        virtual void drawLines(const SDL_Renderer* renderer, const int linePosition[4], const int lineColor[4]) = 0;
        virtual void fillPoints(const SDL_Renderer* renderer, const int circlePosition[4]) = 0;
        virtual void drawCircle(const SDL_Renderer* renderer, const int radius, 
        	const int circlePosition[4], const int circleColor[4]) = 0;
        virtual void drawRectangle(const SDL_Renderer* renderer, const int rectPosition[4], const int rectColor[4]) = 0;

<<<<<<< HEAD
        virtual void update(const SDL_Renderer* renderer) = 0;
=======
        void drawLines(int linePosition[4], int lineColor[4]);
        void fillPoints(int circlePosition[4]);
        void drawFilledCircle(int radius, int circlePosition[4], int circleColor[4]);
        void drawRectangle(int rectPosition[4], int rectColor[4]);

        void update();

        // daqui para baixo deve-se refatorar

        void drawElements();
        void drawBackground();
        void drawSun();
        void drawPlatform();
        void drawCaio();
        void drawSebastiao();
        void drawSebastiaoDialogue();
        void drawEnemyCurupira();
        void drawEnemyUrubu();
        void drawBarraHP();
        void drawInventory();
        void drawAim();

    private:
//        Caio* m_caio;
        Window* m_window;
>>>>>>> a1e1f4b7806a829f025ffc432c8f0b81cab8c5cf
};

#endif // CANVAS_H
