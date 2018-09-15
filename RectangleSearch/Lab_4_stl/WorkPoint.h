#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include "Inspection.h"
#include "ModuleTests.h"
#include "WorkPoint.h"


using namespace std;

struct Point
{
	int x, y;
};


void SquareWork(double *pointX, double *pointY, int amountPoint, double &P, double &S, bool ModuleTest = false);

void RectangleWork(double *pointX, double *pointY, int amountPoint, double &P, double &S, bool ModuleTest = false);

void PrintToFile(ofstream &fout, vector<double> initialPoint, double *points, double P, double S, bool initial = false);

int FileSavePoint(vector<double> points);

int FileSave(double *initialPoint, vector<double> points, double P, double S );

void convexHull(vector<Point> points);

int compare(const void *vp1, const void *vp2);

int orientation(Point p, Point q, Point r);

int distSq(Point p1, Point p2);

void swap(Point &p1, Point &p2);

Point nextToTop(stack<Point> &S);
