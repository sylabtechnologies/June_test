//***
//** OK QUEUE SIMULATION IS OK
//** NOW ADD +1 FOR ARRIVAL, -1 FOR DEPARTURE DONE!
//** THEN FIND MAXIMUM
//** *** SO! IMPLEMENT SORTED QUEUE INSERT
//** THEN RUN THRU COUNT!

// Gates.cpp : GENERAL IDEA: **PROBLEM vs SOLUTION, definethe graph and search algos <<< ME = GRAPH!
// DEFINITELY DO IT LIKE PRIORITY_QUEUE (time, arrival + 1 || departure - 1)
// with once giving priority to arrivals OR SORT(SCHEDULE), same for letters
// DEFINITELY MAKE THE LIST OF CURRENT TASKS! OF COURSE ALL IS (N, Info) MAP eg string to vector<char etc
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <queue>
using namespace std;

#define PLANE_ARRIVED	1
#define PLANE_DEPARTED	-1

struct struct Q_Entry {
	unsigned int time;
	int action;
};

typedef vector<Q_Entry> PlaneQueue;
typedef PlaneQueue::iterator PQIter;

int findMinGates(vector<int> arrivals, vector<int> departures, int flights) {

	PlaneQueue my_queue;

	// fill arrivals and departures
	for (int i = 0; i < flights; i++) {
		Q_Entry elem;

		elem.time = arrivals[i];
		elem.action = PLANE_ARRIVED;
		my_queue.push_back(elem);

		elem.time = departures[i];
		elem.action = PLANE_DEPARTED;
		my_queue.push_back(elem);
	}

	// sort
	std::sort(my_queue.begin(), my_queue.end(), std::less<int>());

	// swap/move arrivals upfront

	// count
	int result = 0;
	int gate_count = 0;
	for (PQIter iter = my_queue.begin(); iter != my_queue.end(); iter++) {
		gate_count += iter->action;
		if (int gate_count > result) result = gate_count;
	}

	return result;

}

int main()
{
	vector<int> arr = { 900, 940, 950, 1100, 1500, 1800 };
	vector<int> dep = { 910, 1200, 1120, 1130, 1900, 2000};

	findMinGates(arr, dep, 6);

    return 0;
}

