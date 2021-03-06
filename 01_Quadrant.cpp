// 01_Quadrant.cpp : https://www.hackerrank.com/challenges/quadrant-queries/problem
// NEXT: SEGMENT TREE AND SIMPLE ARRAYS!

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#define LL long long
#define _OS(x) ostream_iterator<x>(cout, " ")
#define _CR cout << endl
#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter
#define PRN(x) cout << x << endl
#define PRV(x) copy(_R1(x), _OS(int)); _CR

int ri() { int x; cin >> x; return x; }

struct Point
{
	int x;
	int y;
};

struct Query
{
	char type;
	int start;
	int finish;
};

typedef vector<Point> Mypoints;
typedef vector<int>   Myvec;

void flip_x(Mypoints& pp, Query qq);
void flip_y(Mypoints& pp, Query qq);
void count(Mypoints& pp, Query qq);

int main()
{
	Mypoints aa;

	int num_pts = ri();

	while (num_pts > 0)
	{
		Point pt;

		pt.x = ri(); pt.y = ri();
		aa.push_back(pt);

		num_pts--;
	}

	// make num_qq queries
	int num_qq = ri();

	while (num_qq > 0)
	{
		Query qq;

		cin >> qq.type;
		qq.start = ri() - 1;
		qq.finish = ri() - 1;

		if (qq.type == 'X')
			flip_x(aa, qq);
		else if (qq.type == 'Y')
			flip_y(aa, qq);
		else if (qq.type == 'C')
			count(aa, qq);
		else
		{
			cout << "Invalid query " << qq.type << endl;
			exit(1);
		}

		num_qq--;
	}

    return 0;
}

void flip_x(Mypoints& pts, Query q)
{
	for (size_t i = q.start; i <= q.finish; i++)
	{
		pts[i].y = -pts[i].y;
	}
}

void flip_y(Mypoints& pts, Query q)
{
	for (size_t i = q.start; i <= q.finish; i++)
	{
		pts[i].x = -pts[i].x;
	}
}

// point count, no points at x or y axis
// quadr x - 1 = x
void count(Mypoints& pts, Query q)
{
	Myvec quadr {0, 0, 0, 0};

	for (size_t i = q.start; i <= q.finish; i++)
	{
		if (pts[i].x > 0)
		{
			if (pts[i].y > 0)
				quadr[0] += 1;
			else
				quadr[3] += 1;
		}
		else
		{
			if (pts[i].y > 0)
				quadr[1] += 1;
			else
				quadr[2] += 1;
		}
	}

	PRV(quadr);
}


