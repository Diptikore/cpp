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



void EllipHavi(vector<double>& pointX, vector<double>& pointY, double &bigAxis, double &littleAxis, bool ModuleTest = false);

void PrintToFile(ofstream &fout, vector<double>& initialPoint, double bigAxis, double  littleAxis, bool initial = false);

int FileSavePoint(vector<double>& initialPoint);

int FileSave(vector<double>& initialPoint, double &bigAxis, double &littleAxis);