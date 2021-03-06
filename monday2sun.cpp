// count all mon-sun weeks for specified momths
// make days, months, durations null based
// cycle from 1st monday to last sunday

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<int>	I_vec;
typedef I_vec::iterator I_iter;
typedef vector<string>	Cal_vec;
typedef Cal_vec::const_iterator	Cal_iter;

void process_error(const string, const int);
#define _OS(x) ostream_iterator<x>(cout, " ")
#define _CR cout << endl
#define _R1(x) x.begin(), x.end()
#define _R2(x) auto iter = x.begin(); iter != x.end(); ++iter
#define ERROR(X) process_error(X, __LINE__)

#define FEBRUARY	1		// make it null based
#define MONDAY		1		// make it null based
const Cal_vec MyDays{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
const Cal_vec MyMonths{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const I_vec MyDurations{ 31, 28, 31, 30, 31, 30, 31,  31, 30,  31, 30, 31 };

// use hash table?
int strings_index(const Cal_vec& myvec, const string& value)
{
	Cal_iter c_iter = std::find(myvec.begin(), myvec.end(), value);
	
	if (c_iter == myvec.end()) ERROR("invalid month");
	
	return c_iter - myvec.begin();
}


// check all correct cycle params
int solution(const int start_year, const string& begin_month, const string& end_month, const string& jan1weekday)
{
	bool leap_year = false;

	if (start_year < 2001 || start_year > 2099) ERROR("invalid year");
	if (start_year % 4 == 0) leap_year = true;

	int m_begin = strings_index(MyMonths, begin_month);
	int m_end = strings_index(MyMonths, end_month);
	if (m_begin > m_end) ERROR("invalid range");

	int jan1st = strings_index(MyDays, jan1weekday);

	int cur_monday;
	
	if (jan1st == MONDAY - 1)	// mon - 1 = sun
	{
		cur_monday = 2;
	}
	else if (jan1st == MONDAY)
	{
		cur_monday = 1;
	}
	else						// count days till sat + 2
	{
		cur_monday = 9 - jan1st;
	}

	int result = 0;
	int cur_month = 0;
	int num_monday = 1;
	// loop thru all Mondays

	while (true)
	{
		int duration = MyDurations[cur_month];
		if (cur_month == FEBRUARY && leap_year) duration = MyDurations[cur_month] + 1;

		if (cur_month == m_end && cur_monday + 6 > duration)
			break;

		if (cur_month >= m_begin)
			result++;

		cur_monday += 7;
		num_monday++;

		if (cur_monday > duration)
		{
			cur_monday = cur_monday - duration;
			cur_month++;
			num_monday = 1;
		}
	}

	return result;
}


int main()
{
	cout << solution(2010, "June", "July", "Friday") << endl;

    return 0;
}

void process_error(const string msg, const int line)
{
	cerr << __FILE__ << ", line " << line << endl;
	cerr << "Error: " << msg << endl;
	cerr << msg << endl;
	exit(1);
}
