#include "Code_Utilities.h"
#include "asciiIntro.h"
#include "asciiLogo.h"
#include "asciiEukaryotz.h"
#include "asciiCollectables.h"
#include "asciiMonsters.h"
#include "asciiMaps.h"
#include "asciiMap1.h"
#include <Windows.h>
#include <conio.h>

using namespace BdB;

//variables utilisées pour la carte
int hSize = 200;
int vSize = 60;
int vOffset = 0;
int hOffset = 0;
int lineSize = 800;
array<string, 2> bgColor = { "\x1b[48;5;230m","\x1b[48;5;231m" };
array<string, 200> currentMap;

//variables utilisées pour l'eukaryotz
string protName;
int protWidth = 16;
int protHeight = 11;
int protLife;
int protSpeed;
int protStrength;
array<string, 10> protInvNames = { "Blobs" };
array<int, 10> protInvQty = { 0 };
char nextMove;

void moveCursor(int v, int h)
{
    cout << ESC + (to_string(v) + ";" + to_string(h) + "H");
}

string spaceString(int length)
{
    string spaces = "";
    for (int i = 0; i < length; ++i)
    {
        spaces += " ";
    }
    return spaces;
}

/**
Ajoute du spacing
@param int lines Nombre de fois que move cursor sera appele
@param int sizeY position Y
@param int sizeX position X
@param xOffset(optional) si n'est pas spécifier il reste a 1
*/
void addSpacing(int lines, int sizeY, int sizeX, int xOffset = 1)
{
    string spaces = spaceString(sizeX);

    for (int i = 1; i <= lines; i++) {
        moveCursor(vSize / 2 + sizeY / 2 + i, hSize / 2 - sizeX / 2 + xOffset);
        cout << spaces;
    }
}

void clearCin()
{
    cin.clear();
    cin.ignore(120, '\n');
}

array<string, 200> buildRandomMap()
{
    int threshold = 100;
    array<string,200> newMap;
    string newLine = "";
    string lastLine = "";
    array<int, 800> cellThreshold = {};
    array<int, 800> cellThresholdLastLine = {};
    int distancer = 10;

    for (int i = 0; i < 200; ++i)
    {
        newLine = "";
        for (int i = 0; i < ((lineSize / 2) - 1); ++i)
        {
            if (i != 0)
                threshold -= cellThreshold[i - 1] * 4;
            threshold -= cellThresholdLastLine[i] * 30;
            threshold = threshold <= 0 ? 5 : threshold;
            if (rand() % threshold == threshold - 1 && distancer > 0)
            {
                cellThreshold[i] += 1;
                newLine += "1";
                distancer -= 1;
                threshold = 100;
            }
            else
            {
                cellThreshold[i] += 0;
                newLine += ".";
                threshold -= 1;
                distancer -= 1;
            }
            distancer = distancer < -30 ? 10 : distancer;
        }
        newMap[i] = newLine;
        lastLine = newLine;
        cellThresholdLastLine = cellThreshold;
    }
    return newMap;
}

//fonction pour demander a l'usager si il veut commencer une nouvelle partie
string startString = "Voulez-vous débuter un nouvel eukaryotz? o pour débuter.";
bool displayStartGame()
{
    string spaces = spaceString(startString.size());
    char userStart = -1;
    while (userStart != 'o' && userStart != 'O' && userStart != 'n' && userStart != 'N')
    {
        moveCursor(vSize / 2 + logo.size() / 2 + 1, hSize / 2 - startString.size() / 2 + 1);
        cout << spaces;
        moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - startString.size() / 2 + 1);
        cout << spaces;
        moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - startString.size() / 2 + 1);
        cout << spaces;
        if (userStart != -1)
        {
            moveCursor(vSize / 2 + logo.size() / 2 + 1, hSize / 2 - startString.size() / 2 + 1);
            cout << "Je n'ai pas compris, pouvez-vous répéter? ";
        }
        moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - startString.size() / 2 + 2);
        cout << "Voulez-vous débuter un nouvel eukaryotz? o pour débuter.";
        moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - startString.size() / 2 + 2);
        cin >> userStart;
        clearCin();
    }
    moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - startString.size() / 2 + 1);
    cout << spaces;
    bool startGame = userStart == 'o' || userStart == 'O' ? true : false;
    return startGame;
}

string enterName()
{
    string startName = "En tant qu'Eukaryotz, quel sera votre nom?";
    string spaces = spaceString(startName.size());
    moveCursor(vSize / 2 + logo.size() / 2 + 1, hSize / 2 - startString.size() / 2 + 1);
    cout << spaces;
    moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - startString.size() / 2 + 1);
    cout << spaces;
    moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - startString.size() / 2 + 1);
    cout << spaces;

    moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - startName.size() / 2 + 2);
    cout << startName;
    string testName = "";
    moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - startName.size() / 2 + 2);
    cin >> testName;
    clearCin();
    //getline(cin, testName);
    return testName;
}

//fonction pour que l'usager entre et valide le nom
void startNameValidation() {
    bool nameIsGood = false;
    while (!nameIsGood)
    {
        string testName = enterName();
        string startNameFinalValidate = "Votre Eukaryotz se nomme bien " + testName + "? Tappez o pour oui.";
        string spaces = spaceString(startNameFinalValidate.size());

        moveCursor(vSize / 2 + logo.size() / 2 + 1, hSize / 2 - startNameFinalValidate.size() / 2 + 1);
        cout << spaces;
        moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - startNameFinalValidate.size() / 2 + 1);
        cout << spaces;
        moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - startNameFinalValidate.size() / 2 + 1);
        cout << spaces;


        char validateName;
        moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - startNameFinalValidate.size() / 2 + 2);
        cout << startNameFinalValidate;
        moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - startNameFinalValidate.size() / 2 + 2);
        cin >> validateName;
        clearCin();
        nameIsGood = validateName == 'O' || validateName == 'o' ? true : false;
        if(nameIsGood)
            protName = testName;
    }
}

//fonction pour afficher l'intro
void displayIntro(int framesPlayed, bool skipIntro)
{
    for (int i = 0; i < framesPlayed; ++i)
    {
        if (i == 0 || (i > 0 && !skipIntro) || i == framesPlayed - 1)
        {
            cout << "\x1b[48;5;234m" << "\x1b[38;5;76m";//couleur fonctionne juste pour l'intro
            moveCursor(1, 1);
            cout << frames[i];
            if (i == framesPlayed - 6)
            {
                for (int i = 0; i < logo6.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo6.size() / 2) + i, hSize / 2 - logo6[0].size() / 2);
                    cout << logo6[i];
                }
            }
            if (i == framesPlayed - 5)
            {
                for (int i = 0; i < logo5.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo5.size() / 2) + i, hSize / 2 - logo5[0].size() / 2);
                    cout << logo5[i];
                }
            }
            if (i == framesPlayed - 4)
            {
                for (int i = 0; i < logo4.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo4.size() / 2) + i, hSize / 2 - logo4[0].size() / 2);
                    cout << logo4[i];
                }
            }
            if (i == framesPlayed - 3)
            {
                for (int i = 0; i < logo3.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo3.size() / 2) + i, hSize / 2 - logo3[0].size() / 2);
                    cout << logo3[i];
                }
            }
            if (i == framesPlayed - 2)
            {
                for (int i = 0; i < logo2.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo2.size() / 2) + i, hSize / 2 - logo2[0].size() / 2);
                    cout << logo2[i];
                }
            }
            if (i == framesPlayed - 1)
            {
                for (int i = 0; i < logo.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo.size() / 2) + i, hSize / 2 - logo[0].size() / 2);
                    cout << logo[i];
                }
            }
            Sleep(100);
            if (i != framesPlayed - 1)
                system("cls");
        }
    }
}

bool drawEukaryotz()
{
    //draw an idle Eukaryotz in the center
    int hPos = hSize / 2 - protWidth / 2;
    int vPos = vSize / 2 - protHeight / 2;

    for (int i = 0; i < ProtagAsmall.size(); ++i)
    {
        moveCursor(vPos + i,hPos);
        cout << ProtagAsmall[i];
    }

    return true;
}

bool drawMap(char &nextMove)
{
    int firstLine = ((int(currentMap.size()) / 2) - int((vSize) / 2));
    vOffset += nextMove == 'w' ? -(protSpeed) : (nextMove == 's' ? protSpeed : 0);
    hOffset += nextMove == 'a' ? -(protSpeed) : (nextMove == 'd' ? protSpeed : 0);
    system("cls");
    cout << "\x1b[48;5;234m" << "\x1b[38;5;76m";  //Ici pour mettre couleur carte et le reste du jeux.

    for (int imap = ((int(currentMap.size()) / 2) - (vSize / 2)) + vOffset; imap < ((int(currentMap.size()) / 2) + (vSize / 2)) + vOffset; ++imap)
    {
        string line;
        if (imap < 0 || imap >= int(currentMap.size()) - 1)
            line = spaceString(lineSize);
        else
            line = currentMap[imap];
        string newLine;
        for (int iLine = 0; iLine < hSize; ++iLine)
        {
            if (((int(line.size()) / 2) - (hSize / 2) + iLine + hOffset) < 0 || ((int(line.size()) / 2) - (hSize / 2) + iLine + hOffset) > int(line.size()) - 1)
                newLine += ' ';
            else
                newLine += line[(int(line.size()) / 2) - (hSize / 2) + iLine + hOffset];
            /*for (int i = 0; i < newLine.size(); ++i)
            {
                if (newLine[i] == '.')
                    cout << "\x1b[48;5;230m ";
                if (newLine[i] == '1')
                    cout << "\x1b[48;5;231m ";
            }*/
        }
        cout << newLine << endl;
    }/*
    moveCursor(3, 1);
    cout << "                  ";
    moveCursor(3, 1);
    cout << "test: " << firstLine;
    moveCursor(4, 1);
    cout << "                  ";
    moveCursor(4, 1);
    cout << "vOffset: " << vOffset;
    moveCursor(5, 1);
    cout << "                  ";
    moveCursor(5, 1);
    cout << "map # lines" << currentMap.size();
    moveCursor(6, 1);
    cout << "                  ";
    moveCursor(6, 1);
    cout << "map line length: " << lineSize;
    moveCursor(7, 1);
    cout << "                  ";
    moveCursor(8, 1);
    cout << "display size h: " << hSize;*/
    return true;
}

array<int, 2> monstersPosition;
array<int, 1> monstersHealth;
array<int, 1> monstersStrength;

void positionMonsters()
{
    int monstersNumber = 1;
    for (int i = 0; i < monstersNumber; ++i)
    {
        //int h = 1 + (rand() % lineSize);
        int h = 460;
        int v = 90;
        monstersPosition[i * 2] = h;
        monstersPosition[(i * 2) + 1] = v;
        monstersHealth[i * 2] = 2;
        monstersStrength[i * 2] = 3;
    }
}

void drawMonsters()
{
    for (int i = 0; i < 1; ++i)
    {
        int h = monstersPosition[i * 2];
        int v = monstersPosition[(i * 2) + 1];
        int monsterVOffset = (int(currentMap.size()) / 2) - (vSize / 2);
        int monsterHOffset = (lineSize / 2) - (hSize / 2);
        int monsterStr = monstersStrength[i * 2];
        int monsterHP = monstersHealth[i * 2];
        moveCursor(1, 1);
        //cout << v << " " << ((currentMap.size() / 2) - (vSize / 2)) << " " << h << " " << ((lineSize / 2) - (hSize / 2)) << endl;
        if (v > ((int(currentMap.size()) / 2) - (vSize / 2)) && v < ((int(currentMap.size()) / 2) + (vSize / 2)))
        {
            if (h > ((lineSize / 2) - (hSize / 2)) && h < ((lineSize / 2) + (hSize / 2)))
            {
                //determine if monster has been attacked by the eukaryotz
                moveCursor(3, 1);
                //cout << (v - blobVOffset - vOffset);
                if ((v - monsterVOffset - vOffset) > ((vSize / 2) - (protHeight / 2)) && (v - monsterVOffset - vOffset) < ((vSize / 2) + (protHeight / 2)))
                {
                    if ((h - monsterHOffset - hOffset) > ((hSize / 2) - (protWidth / 2)) && (h - monsterHOffset - hOffset) < ((hSize / 2) + (protWidth / 2)))
                    {
                        monstersPosition[i * 2] = 0;
                        monstersPosition[(i * 2) + 1] = 0;
                        moveCursor(vSize / 2 - protHeight / 2 - 2, hSize / 2 - protWidth / 2);
                        int protAttack = (protStrength + 1) + rand() % 6;
                        int monsterAttack = (monsterStr + 1) + rand() % 6;
                        if (protAttack >= monsterAttack)
                        {
                            monsterHP -= 1;
                            cout << "Bang!!";
                        }
                        else
                        {
                            protLife -= 1;
                            cout << "Ouch!! (" << protLife << ")";
                        }
                    }
                }

                if(monsterHP > 0)
                {
                    for (int i = 0; i < monsterAsmall.size(); ++i)
                    {
                        moveCursor(v + i - monsterVOffset - vOffset, h - monsterHOffset - hOffset);
                        cout << monsterAsmall[i];
                    }
                }
            }
        }
    }
}

array<int, 100> blobsPosition;
void positionBlobs()
{
    int blobsNumber = 25 + (rand() % 26);
    for (int i = 0; i < blobsNumber; ++i)
    {
        int h = rand() % lineSize;
        int v = rand() % currentMap.size();
        blobsPosition[i * 2] = h;
        blobsPosition[(i * 2) + 1] = v;
    }
}

void drawBlobs()
{
    for (int i = 0; i < 50; ++i)
    {
        int h = blobsPosition[i * 2];
        int v = blobsPosition[(i * 2) + 1];
        int blobVOffset = (currentMap.size() / 2) - (vSize / 2);
        int blobHOffset = (lineSize / 2) - (hSize / 2);
        moveCursor(2 + i, 1);
        //cout << v << " " << ((currentMap.size() / 2) - (vSize / 2)) << " " << h << " " << ((lineSize / 2) - (hSize / 2)) << endl;
        if (v > ((currentMap.size() / 2) - (vSize / 2)) && v < ((currentMap.size() / 2) + (vSize / 2)))
        {
            if (h > ((lineSize / 2) - (hSize / 2)) && h < ((lineSize / 2) + (hSize / 2)))
            {
                //determine if blob has been eaten by the eukaryotz
                if ((v - blobVOffset - vOffset) > ((vSize / 2) - (protHeight / 2)) && (v - blobVOffset - vOffset) < ((vSize / 2) + (protHeight / 2)))
                {
                    moveCursor(3, 1);
                    cout << (v - blobVOffset - vOffset);
                    if ((h - blobHOffset - hOffset) > ((hSize / 2) - (protWidth / 2)) && (h - blobHOffset - hOffset) < ((hSize / 2) + (protWidth / 2)))
                    {
                        moveCursor(4, 1);
                        cout << (v - blobVOffset - vOffset);
                        blobsPosition[i * 2] = 0;
                        blobsPosition[(i * 2) + 1] = 0;
                        moveCursor(vSize / 2 - protHeight / 2 - 2, hSize / 2 - protWidth / 2);
                        protInvQty[0] += 1;
                        cout << "Slurp!! +1 (" << protInvQty[0] << ")";
                    }
                    else
                    {
                        for (int i = 0; i < 2; ++i)
                        {
                            moveCursor(v + i - blobVOffset - vOffset, h - blobHOffset - hOffset);
                            cout << BlobASmall[i];
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < 2; ++i)
                    {
                        moveCursor(v + i - blobVOffset - vOffset, h - blobHOffset - hOffset);
                        cout << BlobASmall[i];
                    }
                }
            }
        }
    }
}

int main()
{
    
#if _WIN32 || _WIN64
    system("chcp 65001");
    system("cls");
#endif
    srand(time(0));
    //positionnement des acteurs
    positionBlobs();
    positionMonsters();
    currentMap = buildRandomMap();

    cout << "Assurez-vous que votre écran de terminal soit maximisé.\n"
        << "Appuyez sur S pour skipper l'intro ou une autre touche pour le voir et appuyez sur Entrée.\n";
    bool skipIntro = false;
    char userSkip;
    cin >> userSkip;
    clearCin();
    if (userSkip == 'S' || userSkip == 's')
        skipIntro = true;

    //intro
    displayIntro(50, skipIntro);

    bool startGame = displayStartGame();

    //variables utilisées pour l'eukaryotz
    array<string, 1> monsterTable = {}; //18x8
    array<string, 10> blobTable = {}; //2x2 blobs
    string envColor = ESC + Green;


    //boucle de jeu principale
    while (startGame)
    {
        //création du personnage, choix: mouvement, points de vie, force; plus tard: type d'eukaryotz
        //4 points a répartir comme on veut entre les 3 choix
        //minimum de 2 dans chacune des caractéristiques, 1 point équivaut à 1 de plus dans la caractéristique

        startNameValidation();

        //boucle pour que l'usager valide les points de caractéristiques de son Eukaryotz
        bool pointsAreGood = false;
        int pointsLeft;
        while (!pointsAreGood)
        {
            pointsLeft = 4;
            protLife = 2;
            protSpeed = 2;
            protStrength = 2;

            string longestString = "Entrez le nombre de points que vous voulez ajouter à la Vitesse de votre Eukaryotz: (points restants  )";
            string spaces = spaceString(longestString.size());

            addSpacing(9, logo.size(), longestString.size());

            moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Points de caractéristique de " << protName;
            moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString.size() / 2 + 2);
            cout << ">Vie: " << setw(3) << protLife;
            moveCursor(vSize / 2 + logo.size() / 2 + 4, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vitesse: " << setw(3) << protSpeed;
            moveCursor(vSize / 2 + logo.size() / 2 + 5, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Force: " << setw(3) << protStrength;

            char usePoints = '|';
            while (int(usePoints) < int('0') || int(usePoints) > int('0'+pointsLeft))
            {
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 1);
                cout << spaces;
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 2);
                cout << "Entrez le nombre de points que vous voulez ajouter à la Vie de votre Eukaryotz: (points restants " << pointsLeft << ")";
                moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                if (int(usePoints) != char('|'))
                {
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                    cout << spaces;
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 1);
                    cout << "Entrée invalide, utilisez vos points restants.";
                }
                cin >> usePoints;
                clearCin();
            }
            int pointsUsed;
            switch (int(usePoints))
            {
                case int('0') :
                    pointsUsed = 0;
                    break;
                case int('1') :
                    pointsUsed = 1;
                    break;
                case int('2') :
                    pointsUsed = 2;
                    break;
                case int('3') :
                    pointsUsed = 3;
                    break;
                case int('4') :
                    pointsUsed = 4;
                    break;
            }
            pointsLeft -= pointsUsed;
            protLife += pointsUsed;

            addSpacing(9, logo.size(), longestString.size());

            moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Points de caractéristique de " << protName;
            moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vie: " << setw(3) << protLife;
            moveCursor(vSize / 2 + logo.size() / 2 + 4, hSize / 2 - longestString.size() / 2 + 2);
            cout << ">Vitesse: " << setw(3) << protSpeed;
            moveCursor(vSize / 2 + logo.size() / 2 + 5, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Force: " << setw(3) << protStrength;
            
            usePoints = '|';
            while (int(usePoints) < int('0') || int(usePoints) > int('0'+pointsLeft))
            {
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 1);
                cout << spaces;
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 2);
                cout << "Entrez le nombre de points que vous voulez ajouter à la Vitesse de votre Eukaryotz: (points restants " << pointsLeft << ")";
                moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                if (int(usePoints) != char('|'))
                {
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                    cout << spaces;
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 1);
                    cout << "Entrée invalide, utilisez vos points restants.";
                }
                cin >> usePoints;
                clearCin();
            }
            pointsUsed = NULL;
            switch (int(usePoints))
            {
                case int('0') :
                    pointsUsed = 0;
                    break;
                case int('1') :
                    pointsUsed = 1;
                    break;
                case int('2') :
                    pointsUsed = 2;
                    break;
                case int('3') :
                    pointsUsed = 3;
                    break;
                case int('4') :
                    pointsUsed = 4;
                    break;
            }
            pointsLeft -= pointsUsed;
            protSpeed += pointsUsed;

            //Strength
            addSpacing(9, logo.size(), longestString.size());

            moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Points de caractéristique de " << protName;
            moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vie: " << setw(3) << protLife;
            moveCursor(vSize / 2 + logo.size() / 2 + 4, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vitesse: " << setw(3) << protSpeed;
            moveCursor(vSize / 2 + logo.size() / 2 + 5, hSize / 2 - longestString.size() / 2 + 2);
            cout << ">Force: " << setw(3) << protStrength;
            
            usePoints = '|';
            while (int(usePoints) < int('0') || int(usePoints) > int('0'+pointsLeft))
            {
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 1);
                cout << spaces;
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 2);
                cout << "Entrez le nombre de points que vous voulez ajouter à la Force de votre Eukaryotz: (points restants " << pointsLeft << ")";
                moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                if (int(usePoints) != char('|'))
                {
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                    cout << spaces;
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 1);
                    cout << "Entrée invalide, utilisez vos points restants.";
                }
                cin >> usePoints;
                clearCin();
            }
            pointsUsed = NULL;
            switch (int(usePoints))
            {
                case int('0') :
                    pointsUsed = 0;
                    break;
                case int('1') :
                    pointsUsed = 1;
                    break;
                case int('2') :
                    pointsUsed = 2;
                    break;
                case int('3') :
                    pointsUsed = 3;
                    break;
                case int('4') :
                    pointsUsed = 4;
                    break;
            }
            pointsLeft -= pointsUsed;
            protStrength += pointsUsed;
            
            addSpacing(9, logo.size(), longestString.size());

            moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Points de caractéristique de " << protName;
            moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vie: " << setw(3) << protLife;
            moveCursor(vSize / 2 + logo.size() / 2 + 4, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vitesse: " << setw(3) << protSpeed;
            moveCursor(vSize / 2 + logo.size() / 2 + 5, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Force: " << setw(3) << protStrength;

            char validCarac;
            moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Est-ce que les caractéristique de votre Eukaryotz vous conviennent? o pour oui.";
            moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
            cin >> validCarac;
            clearCin();
            pointsAreGood = validCarac == 'o' || validCarac == 'O' ? true : false;
        }

        bool inMap = true;
        while (inMap)
        {
            drawMap(nextMove);
            inMap = drawEukaryotz();
            drawBlobs();
            drawMonsters();
            cout << ESC + (to_string(vSize + 1) + ";1H");
            cout << "w,a,s,d pour faire vous déplacer.";
            nextMove = _getch();
        }

        startGame = false;
    }
    
    return 0;
}