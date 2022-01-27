﻿#include "Code_Utilities.h"

using namespace std;

//"\x1b[48;5;234m\x1b[38;5;76m" Color for the background(48) and foreground(38). 

//Protagoniste Small version A
const array<string, 11> ProtagAsmall = {
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m......\x1b[m",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[m",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m            \x1b[m",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;13m    \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[m",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m......\x1b[m" };
		
//Protagoniste Medium Version A 
const array<string, 18> ProtagAmedium = {
    "\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m......\x1b[m",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[m",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m            \x1b[m	",
    "\x1b[48;5;76m      \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m	",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m	",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m        \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m	",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m	",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m      \x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m        \x1b[48;5;234m\x1b[38;5;76m....\x1b[m	",
    "\x1b[48;5;76m        \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..........\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..............\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m................\x1b[m" };
    //for (int i = 0; i < ProtagAmedium.size(); ++i)
        //cout << ProtagAmedium[i];

//Protagoniste Large Version A		
const array<string, 18> ProtagAlarge = {
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..........................\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m........\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m          \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..........\x1b[48;5;76m      \x1b[48;5;13m      \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m....\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m    \x1b[48;5;13m            \x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m......\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..........\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m      \x1b[48;5;13m              \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..........\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m........\x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m    \x1b[48;5;13m              \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;13m                  \x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m....\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;13m            \x1b[48;5;76m  \x1b[48;5;13m    \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m........\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m        \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m          \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m........\x1b[m",
    "\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m  \x1b[48;5;13m      \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..........\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m........\x1b[48;5;76m  \x1b[48;5;13m  \x1b[48;5;76m  \x1b[48;5;13m          \x1b[48;5;76m      \x1b[48;5;234m\x1b[38;5;76m......\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m        \x1b[48;5;13m          \x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m....\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;76m              \x1b[48;5;234m\x1b[38;5;76m......\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m............\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m...................\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m................\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m................\x1b[m",
    "\x1b[48;5;234m\x1b[38;5;76m..................\x1b[48;5;76m    \x1b[48;5;234m\x1b[38;5;76m..............\x1b[m" };
    //for (int i = 0; i < ProtagAlarge.size(); ++i)
        //cout << ProtagAlarge[i];


const array<string, 11> ProtagAdyingA = {
"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;22m  \x1b[48;5;76m  \x1b[48;5;22m  \x1b[48;5;234m\x1b[38;5;76m....\x1b[m",
"\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;2m  \x1b[48;5;22m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[m",
"\x1b[48;5;76m  \x1b[48;5;22m  \x1b[48;5;76m  \x1b[48;5;77m    \x1b[48;5;76m  \x1b[48;5;34m  \x1b[m",
"\x1b[48;5;34m  \x1b[48;5;76m  \x1b[48;5;102m  \x1b[48;5;132m  \x1b[48;5;133m  \x1b[48;5;71m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;71m  \x1b[48;5;170m  \x1b[48;5;13m  \x1b[48;5;170m  \x1b[48;5;71m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;132m  \x1b[48;5;13m  \x1b[48;5;101m  \x1b[48;5;34m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;22m  \x1b[48;5;77m  \x1b[48;5;133m  \x1b[48;5;170m  \x1b[48;5;71m  \x1b[48;5;2m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;76m  \x1b[48;5;28m  \x1b[48;5;71m    \x1b[48;5;34m  \x1b[48;5;40m  \x1b[48;5;22m  \x1b[m",
"\x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;28m  \x1b[48;5;34m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;22m  \x1b[48;5;76m  \x1b[m",
"\x1b[48;5;22m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;22m  \x1b[48;5;34m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;22m  \x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;22m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;234m\x1b[38;5;76m....\x1b[m" };

const array<string, 9> ProtagAdyingB = {
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;34m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;34m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;22m  \x1b[48;5;40m  \x1b[48;5;22m  \x1b[48;5;40m  \x1b[m",
"\x1b[48;5;76m  \x1b[48;5;34m  \x1b[48;5;8m  \x1b[48;5;77m  \x1b[48;5;71m  \x1b[48;5;2m  \x1b[m",
"\x1b[48;5;22m  \x1b[48;5;101m  \x1b[48;5;164m  \x1b[48;5;133m  \x1b[48;5;102m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;170m    \x1b[48;5;76m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;102m  \x1b[48;5;200m  \x1b[48;5;133m  \x1b[48;5;2m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;76m  \x1b[48;5;34m  \x1b[48;5;132m  \x1b[48;5;76m  \x1b[48;5;34m  \x1b[48;5;22m  \x1b[m",
"\x1b[48;5;34m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[48;5;22m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;76m  \x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;34m  \x1b[48;5;2m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;234m\x1b[38;5;76m....\x1b[48;5;234m\x1b[38;5;76m....\x1b[m" };

const array<string, 7> ProtagAdyingC = {
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;22m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;22m  \x1b[48;5;76m      \x1b[m",
"\x1b[48;5;34m  \x1b[48;5;169m    \x1b[48;5;22m  \x1b[m",
"\x1b[48;5;22m  \x1b[48;5;133m  \x1b[48;5;102m  \x1b[48;5;22m  \x1b[m",
"\x1b[48;5;76m  \x1b[48;5;132m  \x1b[48;5;76m  \x1b[48;5;22m  \x1b[m",
"\x1b[48;5;22m  \x1b[48;5;34m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;34m  \x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;22m    \x1b[48;5;234m\x1b[38;5;76m..\x1b[m" };

const array<string, 4> ProtagAdyingD = {
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;28m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;76m  \x1b[48;5;133m  \x1b[48;5;34m  \x1b[m",
"\x1b[48;5;34m  \x1b[48;5;13m  \x1b[48;5;234m\x1b[38;5;76m..\x1b[m",
"\x1b[48;5;234m\x1b[38;5;76m..\x1b[48;5;34m  \x1b[48;5;2m  \x1b[m" };

const array<string, 2> ProtagAdyingE = {
"\x1b[48;5;34m  \x1b[m",
"\x1b[48;5;170m  \x1b[m" };

//\x1b[48; 5; 234m\x1b[38; 5; 76m






















const array<string, 22> Inventory = {
        u8"┌─────────────────┬──────────────────────┬────────────────────┐",
        u8"│ 1: Evolution Vie│ 2: Evolution Vitesse │ 3: Evolution Force │",
        u8"│     5x Calories │       5x Calories    │     5x Calories    │",
        u8"│                 │                      │                    │",
        u8"├─────────────────┴──────────────────────┴────────────────────┤",
        u8"│                                                             │",
        u8"│                                              Évolution      │",
        u8"│   Point de Vie:                                             │",
        u8"│                                                             │",
        u8"│   Point de Force:                                           │",
        u8"│                                                             │",
        u8"│   Point de Vitesse:                                         │",
        u8"│                                                             │",
        u8"│   Calories accumulees:                                      │",
        u8"│                                                             │",
        u8"│   Choisissez votre chemin évolutif                          │",
        u8"│   Appuyez sur 1, 2 ou 3 pour faire votre choix.             │",
        u8"│   Déplacez votre prot pour sortir de l'inventaire.          │",
        u8"│                                                             │",
        u8"│                                                             │",
        u8"└─────────────────────────────────────────────────────────────┘"};