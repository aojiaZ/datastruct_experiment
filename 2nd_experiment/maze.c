#include"maze.h"
void out_put_maze(Point *, int);
int  find_min(Point *G) {
	int min = Maze_Length,num = 0;
	for (int i = 1;i <= Maze_Length; ++i) {
		if (G[i]->situation == 0) {
			num = G[i]->situation < min ? i : num;
		}
	}
	return num;
}
void out_put_maze(Point *G, int num) {
	if (G[num]->from != Maze_Start) {
		out_put_maze(G, G[num]->from);
		printf("->");
	}
	printf("%d", num);
}


void find_way(Point *G, int num) {
    for (int i = 0; G[num]->road[i] != -1&&i<Max_Path; ++i) {
		if (G[G[num]->road[i]]->step > G[num]->step + 1) {
			G[G[num]->road[i]]->step = G[num]->step + 1;
			G[G[num]->road[i]]->from = num;
		}
	}
	for (int i = 0; G[num]->road[i] != -1 && i<Max_Path; ++i) {
		if (G[num]->step>=G[G[num]->road[i]]->step)
			;
		else {
			find_way(G, G[num]->road[i]);
		}
	}
	return;
}

void init_graph(Point *G,int *ends) {
	int a = 0, b = 0, j = 0,i = 0; 
	for (i = 0; i <= Maze_Length; ++i) {
		G[i] = (Point)malloc(sizeof(struct point));
		G[i]->from = -1;
		G[i]->situation = 1;
		G[i]->step = Maze_Length;
		for (int j = 0; j < Max_Path; ++j) {
			G[i]->road[j] = -1;
		}
		for (int n = 0; n < End_Num; ++n) {
			if (i == ends[n]) {
				G[i]->situation = 0;
			}
		}
	}

	G[Maze_Start]->step = 1;
	freopen("line.txt", "r", stdin);
	while (scanf("%d", &a) != EOF) {
		scanf("%d", &b);
		for (j = 0; G[a]->road[j] != -1; ++j)
			;
		G[a]->road[j] = b;
		for (j = 0; G[b]->road[j] != -1; ++j)
			;
		G[b]->road[j] = a;
	}
	fclose(stdin);
}

int main() {
	Point G[Maze_Length+1];
	int ends[End_Num];
	int min;
	printf("The number of the end is %d, please input the end points' number:\n",End_Num);
	for (int i = 0; i < End_Num; ++i) {
		scanf("%d", &ends[i]);
	}
	printf("This is the shortest path:\n%d->",Maze_Start);
	init_graph(G,ends);
	find_way(G, Maze_Start);
	out_put_maze(G, find_min(G));
	printf("\n");

	system("pause");
	return 0;
}
