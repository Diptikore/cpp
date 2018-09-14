#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include "Inspection.h"
#include "ModuleTests.h"
#include "WorkPoint.h"


using namespace std;



void EllipHavi(double *pointX, double *pointY, int amountPoint, double &bigAxis, double &littleAxis, bool ModuleTest = false);

void PrintToFile(ofstream &fout, double *initialPoint, const int amountPoint, double bigAxis, double  littleAxis, bool initial = false);

int FileSavePoint(double *initialPoint, int amountPoint);

int FileSave(double *initialPoint, int amountPoint, double &bigAxis, double &littleAxis);