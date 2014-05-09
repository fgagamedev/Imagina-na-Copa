#ifndef CANVAS_H
#define CANVAS_H

#include "window.h"
//#include "caio.h"

class Canvas
{
	public:
        Canvas(Window *window);
        ~Canvas();

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
        //Caio* m_caio;
        Window* m_window;
};

#endif // CANVAS_H
