// Implement gas station queue with {X Y Z} pumps with {X Y Z} gas
// and carqueue as {a0 a1 a2... } needs and service time
// Return total service time or INT_MAX if stuck

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter

typedef vector<int> I_vec;
typedef list<int>   I_lst;

struct Queue_event
{
	int time_of_event;
	int pump_capacity;
	bool operator< (const Queue_event& rhs) const { return time_of_event >= rhs.time_of_event; }
	Queue_event(int t, int c) : time_of_event(t), pump_capacity(c) {}
};

void print_queue(priority_queue<Queue_event> q)
{
	while (!q.empty())
	{
		Queue_event temp = q.top();
		cout << "[ " << temp.time_of_event << ", " << temp.pump_capacity << " ]  ";
		q.pop();
	}

	cout << endl << endl;
}


int simulatePumpQueue(const I_vec &carqueue, I_lst pump)
{
	priority_queue<Queue_event> pump_events;

	int mytime = 0;

	auto iter = carqueue.begin();
	while (iter != carqueue.end())
	{
		// we need *iter gas so we find a pump
		auto piter = pump.begin();
		for (; piter != pump.end(); ++piter)
		{
			if (*piter >= *iter)
			{
				pump_events.push(Queue_event(mytime + *iter , *piter - *iter));
				print_queue(pump_events);
				break;
			}
		}

		if (piter != pump.end())
		{
			// busy the pump and serve the next car
			pump.erase(piter);
			++iter;
		}
		else
		{
			bool pumpfound = false;

			while (!pumpfound)
			{
				if (pump_events.size() == 0) break;;

				Queue_event nextpump = pump_events.top(); pump_events.pop();
				// remove empty pumps
				if (nextpump.pump_capacity == 0) continue;

				print_queue(pump_events);

				pump.push_back(nextpump.pump_capacity);
				mytime = nextpump.time_of_event;

				pumpfound = true;
			}

			if (!pumpfound) return INT_MAX;
		}
	}

	return pump_events.top().time_of_event;
}

int main()
{
	I_vec aa{2, 8, 4, 3, 2};
	I_lst pump{ 7, 11, 3 };
	cout << simulatePumpQueue(aa, pump) << endl;

    return 0;
}

