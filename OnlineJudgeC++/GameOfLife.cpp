#include <iostream>
using namespace std;

#define maxrow 6
#define maxcol 6
#define dead 0
#define alive 1

void _main()
{
	void initialise(int map[][maxcol]);
	void writemap(int map[][maxcol]);
	int NeighbourCount(int map[][maxcol], int row, int col);
	void copy(int map[][maxcol], int newmap[][maxcol]);
	void enquire(int &again);


	int map[maxrow][maxcol];
	int newmap[maxrow][maxcol];
	int i, j;
	int again;
	again = 1;
	initialise(map);
	writemap(map);

	while (again)
	{
		for (i = 0; i < maxrow; i++)
			for (j = 0; j < maxcol; j++)
			{
				switch (NeighbourCount(map, i, j))
				{
				case 0:
				case 1:
					newmap[i][j] = dead;
					break;
				case 2:
					newmap[i][j] = map[i][j];
					break;
				case 3:
					newmap[i][j] = alive;
					break;
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					newmap[i][j] = dead;
					break;
				}//switch
			}//for
		copy(newmap, map);
		writemap(newmap);
		enquire(again);
	}//while
}//main


void initialise(int map[][maxcol])
{
	int i, j;

	for (i = 0; i < maxrow; i++)
		for (j = 0; j < maxcol; j++)
		{
			map[i][j] = 0;
		}

	map[2][1] = alive;
	map[2][3] = alive;
	map[3][2] = alive;
	map[3][3] = alive;
	map[4][2] = alive;
	map[5][1] = alive;
}


void writemap(int map[][maxcol])
{
	int i, j;
	cout << endl;
	for (i = 0; i < maxrow; i++)
	{
		for (j = 0; j < maxcol; j++)
		{
			if (map[i][j] == alive)
				cout << "x";
			else
				cout << ".";
		}
		cout << endl;
	}
	cout << endl;
}


int NeighbourCount(int map[][maxcol], int row, int col)
{
	int l_row, l_col, u_row, u_col;
	int i, j, count = 0;
	if (row == 0)
	{
		l_row = 0;
		l_col = (col == 0) ? 0 : (col - 1);
		u_row = 1;
		u_col = (col == maxcol - 1) ? (maxcol - 1) : (col + 1);
	}

	else if (row == 5)
	{
		l_row = row - 1;
		l_col = (col == 0) ? 0 : (col - 1);
		u_row = maxrow - 1;
		u_col = (col == maxcol - 1) ? (maxcol - 1) : (col + 1);
	}

	else if (col == 0 && ((row != 0) || (row != maxrow - 1)))
	{
		l_row = row - 1;
		l_col = 0;
		u_row = row + 1;
		u_col = col + 1;
	}

	else if ((col == maxcol - 1) && ((row != 0) || (row != maxrow - 1)))
	{
		l_row = row - 1;
		l_col = col - 1;
		u_row = row + 1;
		u_col = maxrow - 1;
	}

	else
	{
		l_row = row - 1;
		l_col = col - 1;
		u_row = row + 1;
		u_col = col + 1;
	}


	for (i = l_row; i <= u_row; i++)
		for (j = l_col; j <= u_col; j++)
		{
			if (map[i][j] == alive)
			{
				if (!(i == row && j == col))
					++count;
			}
		}
	cout << count;
	return count;
}

void copy(int map[][maxcol], int newmap[][maxcol])
{
	int i, j;

	for (i = 0; i < maxrow; i++)
		for (j = 0; j < maxcol; j++)
		{
			newmap[i][j] = map[i][j];
		}
}

void enquire(int &again)
{
	char ans;
	cout << "Do you want to compute for another generation [y\\n]: ";
	cin >> ans;
	if (ans == 'n')
		again = 0;
}