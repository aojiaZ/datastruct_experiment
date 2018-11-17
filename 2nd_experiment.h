#pragma once
#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
const int Maze_Length = 17;
const int Maze_Start = 2;
const int Max_Path = 6;
const int End_Num = 2;



typedef struct point {
	int situation;
	int step;
	int from;
	int road[Max_Path];
}*Point;
