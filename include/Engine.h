#ifndef ENGINE_H
#define ENGINE_H
#include <GL/glut.h>
#include <vector>
#include <math.h>

#include <iostream>

class Engine {
public:
  static void Init(const char* title,const unsigned int width,const unsigned int height,int gl_argc = 0, char** gl_argv = nullptr);

  // The Engine call this function only once (At the beginning of the game)
  static void Start();
  // Use this function to render your shapes on the game screen
  static void Render();
  // This function runs in each frames of the game (Before the Renderer)
  static void Update();

  // Use this function to limit the Frames Per Second of the game screen's refresh rate
  // 0 means no limit
  static void SetTargetFPS(unsigned int FPS);

  static bool IsMousePressed(unsigned short Mouse_Button);

  static bool mouse[2];

    static bool keyStates[256];

private:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static unsigned int refreshMillis;

    static int mouseX ;
    static int mouseY;



    static void display();
    static void onMouseMotion(int x, int y);
    static void onReshape(int width, int height);
    static void onMouseClick(int button, int state, int x, int y);
    static void onKeyPress(unsigned char key, int x, int y);
    static void onKeyRelease(unsigned char key, int x, int y);
    static void update(int value);
};
void Draw_Circle(float centerX, float centerY, float radius, float angleStart, float angleEnd, int numSegments);



#endif // ENGINE_H
