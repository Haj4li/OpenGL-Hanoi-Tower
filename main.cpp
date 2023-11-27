#include "Engine.h"

int n = 10;
int disk_height = 5;
int disk_width = 150;

int A_Offset = 50;
int B_Offset = 250;
int C_Offset = 450;

struct move {
    int from;
    int to;
    move(int a,int b)
    {
        from = a;
        to =b;
    }
};
std::vector<int> towerA;
std::vector<int> towerB;
std::vector<int> towerC;
std::vector<int> towers[3];
std::vector<move> moves;

int current_move = 0;
bool repeat = false;

int speed = 20;

int selectedDisk = -1;
int selectedTower = -1;;


// Function to move a disk from one tower to another
void MoveDisk(std::vector<int>& sourceTower, std::vector<int>& destinationTower) {
    int disk = sourceTower.back();
    sourceTower.pop_back();
    destinationTower.push_back(disk);
}

void towerOfHanoi(int n, int a, int b,  int c)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, a, c, b);
    moves.push_back(move(a,b));
    towerOfHanoi(n - 1, c, b, a);
}

void Engine::Start()
{
    Engine::SetTargetFPS(25);
    for (int i = 0; i <n; ++i) {

        towerA.push_back(i);
    }
    towerOfHanoi(n,0,1,2);
    towers[0] = towerA;
    towers[1] = towerB;
    towers[2] = towerC;
}
void Engine::Update()
{
    if (keyStates[97] )
    {
        keyStates[97] = false;
        repeat = true;

    }
    if (keyStates[98])
    {
        if (speed < 60)
        {
            speed += 5;
        }
        Engine::SetTargetFPS(speed);
    }
    if (keyStates[99])
    {
        if (speed > 10)
        {
            speed -= 5;
        }
        Engine::SetTargetFPS(speed);
    }
    if (current_move == moves.size() )
    {
        if (repeat)
        {
            current_move = 0;
            towers[0] = towerA;
            towers[1] = towerB;
            towers[2] = towerC;
            repeat = false;
        }


    }
    else
    {
        std::cout << "Move : " << current_move << " {" << moves[current_move].from << " : " << moves[current_move].to  << "}"<< std::endl;
        MoveDisk(towers[moves[current_move].from],towers[moves[current_move].to]);
        current_move++;
    }


}
void Show()
{


    glLineWidth(disk_height);
    glBegin(GL_LINES);
    // render towers
    // A
    glColor3ub(0,0,0);
    glVertex2f(A_Offset,100);
    glVertex2f(A_Offset+disk_width,100);
    glVertex2f(A_Offset+(disk_width/2),100);
    glVertex2f(A_Offset+(disk_width/2),100+(n*disk_height)+20);
    // B
    glVertex2f(B_Offset,100);
    glVertex2f(B_Offset+disk_width,100);
    glVertex2f(B_Offset+(disk_width/2),100);
    glVertex2f(B_Offset+(disk_width/2),100+(n*disk_height)+20);
    // C
    glVertex2f(C_Offset,100);
    glVertex2f(C_Offset+disk_width,100);
    glVertex2f(C_Offset+(disk_width/2),100);
    glVertex2f(C_Offset+(disk_width/2),100+(n*disk_height)+20);


    // Render disks on tower A
    for (int i = 0; i < towers[0].size(); ++i) {
        glColor3ub(255, towers[0][i] * 45, towers[0][i] * 10);
        glVertex2f(A_Offset + (towers[0][i] * 3), 100 + (i * disk_height) + disk_height);
        glVertex2f(A_Offset + disk_width - (towers[0][i] * 3), 100 + (i * disk_height) + disk_height);
    }
    for (int i = 0; i < towers[1].size(); ++i) {
        glColor3ub(255, towers[1][i] * 45, towers[1][i] * 10);
        glVertex2f(B_Offset + (towers[1][i] * 3), 100 + (i * disk_height) + disk_height);
        glVertex2f(B_Offset + disk_width - (towers[1][i] * 3), 100 + (i * disk_height) + disk_height);
    }
    for (int i = 0; i < towers[2].size(); ++i) {
        glColor3ub(255, towers[2][i] * 45, towers[2][i] * 10);
        glVertex2f(C_Offset + (towers[2][i] * 3), 100 + (i * disk_height) + disk_height);
        glVertex2f(C_Offset + disk_width - (towers[2][i] * 3), 100 + (i * disk_height) + disk_height);
    }

    /*
    for (int i=0;i<n;++i)
    {
        glColor3ub(255,i*45,i*10);
        glVertex2f((i*3)+A_Offset, (100)+(i*disk_height)+disk_height);
        glVertex2f(A_Offset+disk_width-(i*3), (100)+(i*disk_height)+disk_height);
    }*/

    glEnd();
}
void Engine::Render()
{

    Show();
}

int main(int argc, char** argv) {
    Engine::Init("Hanoi Tower | Ali Nakhaee",800,600);
    return 0;
}
