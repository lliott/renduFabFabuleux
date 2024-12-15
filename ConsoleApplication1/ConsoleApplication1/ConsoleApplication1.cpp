#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#define NOMINMAX
#include <windows.h>

static const int WIDTH = 11;
static const int HEIGHT = 11;
static const float PI = 3.14159265358979323846f;

static char output[HEIGHT][WIDTH];

struct Chrono {
    float duration;
    float elapsedTime;
    bool isFinished;
    float lastUpdateTime;
};

int AskDuration() {
    int duration;
    while (true) {
        std::cout << "Entrez une duree en secondes : ";
        std::cin >> duration;
        if (!std::cin.fail()) break;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entree invalide. Veuillez saisir un nombre.\n";
    }
    return duration;
}

float GetTime() {
    return static_cast<float>(clock()) / static_cast<float>(CLOCKS_PER_SEC);
}

void InitializeOutput() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            output[y][x] = '-';
        }
    }
    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    output[centerY][centerX] = 'X';
}

void DisplayOutput() {
    std::string display;
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            display.push_back(output[y][x]);
        }
        display.push_back('\n');
    }
    std::cout << display;
}

void ResetDisplay() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, 0 };
    SetConsoleCursorPosition(hConsole, pos);
    InitializeOutput();
}

void UpdateChrono(Chrono& chrono) {
    if (chrono.isFinished) return;
    float currentTime = GetTime();
    float deltaTime = currentTime - chrono.lastUpdateTime;
    chrono.lastUpdateTime = currentTime;
    chrono.elapsedTime += deltaTime;
    if (chrono.elapsedTime >= chrono.duration) {
        chrono.elapsedTime = chrono.duration;
        chrono.isFinished = true;
    }
}

void DisplayElapsedTime(const Chrono& chrono) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, (SHORT)(HEIGHT + 1) };
    SetConsoleCursorPosition(hConsole, pos);
    std::cout << "Temps ecoulé: " << chrono.elapsedTime << std::endl;
}

void WriteTimeLeft(Chrono& chrono) {
    float t = chrono.elapsedTime;
    float r = 3.0f;
    int centerX = 5;
    int centerY = 5;
    int posX = (int)((cos(t * 2 * PI / chrono.duration - PI / 2) * r) + 5.5f);
    int posY = (int)((sin(t * 2 * PI / chrono.duration - PI / 2) * r) + 5.5f);
    int dX = posX - centerX;
    int dY = posY - centerY;
    int steps = 3;
    for (int i = 1; i < steps; ++i) {
        int interX = centerX + (dX * i / steps);
        int interY = centerY + (dY * i / steps);
        output[interY][interX] = '*';
    }
    output[posY][posX] = '*';
}

int main() {
    int userDuration = AskDuration();
    Chrono chrono;
    chrono.duration = static_cast<float>(userDuration);
    chrono.elapsedTime = 0.0f;
    chrono.isFinished = false;
    chrono.lastUpdateTime = GetTime();
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
            DWORD count;
            DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
            COORD homeCoords = { 0, 0 };
            FillConsoleOutputCharacter(hConsole, ' ', cellCount, homeCoords, &count);
            SetConsoleCursorPosition(hConsole, homeCoords);
        }
    }

    while (!chrono.isFinished) {
        UpdateChrono(chrono);
        ResetDisplay();
        WriteTimeLeft(chrono);
        DisplayOutput();
        DisplayElapsedTime(chrono);
        Sleep(50);
    }

    std::cout << "Fin du chrono" << std::endl;
    return 0;
}
