/***************************************************************************//**
 *@file
 *
 *@brief header file for functions.cpp
 ******************************************************************************/
#pragma pack(1)
#define _CRT_SECURE_NO_WARNINGS 1

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "mp3Editor.h"
#include <direct.h>

using namespace std;

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

void displayMenu();
void pickChoice(int choice, mp3Editor &mp3E, ofstream &fout, char* name);
void displayGenres();
void play(char* name);
void massAlbum();

#endif