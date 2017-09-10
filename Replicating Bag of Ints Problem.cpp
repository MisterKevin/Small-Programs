/*
Replicating Bag of Ints Problem
===============================

Scenario: You want to reach a target sum from a bag of ints, which is simply a container of the integers you can use.
You want to reach a target goal (target_num_k) using the ints in the bag, which may be "replicated" at will.
Replication here simply means that you can use the integer more than once in your challenge to reach the target sum.
However, it cannot be more than a certain number (max_amount_per_int_k).

Example: Bag has {20, 30, 15} | Target is 55 | Max Replication is 3.
Solution: 20, 20, 15.

Note that if the Max Replication was 1, you cannot reach the goal.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* Constants and Globals */
const vector<int> bag_of_ints_k{ 295, 411, 161 };
const int target_num_k = 3200;
const int max_amount_per_int_k = 8;

/* Aesthetic Global Constants */
int iteration_g = 0;					// Track how many iterations of algorithm it takes to solve
int width_for_iteration_num_g = 6;		// iomanip setw() parameter for iteration number

/* Function Headers */
void print_status(const unordered_map<int, int>& map);
void calculate_target(unordered_map<int, int> map, int new_num, int curr_sum);

int main()
{
	unordered_map<int, int> bag_map;
	for (const auto x : bag_of_ints_k) /* Initializing bag ints to zero in map */
		bag_map[x] = 0;

	for (const auto& x : bag_of_ints_k)
		calculate_target(bag_map, x, 0 /* current sum starts at zero */);

	return 0;
}

/* Prints the current status of the inputted map, including contents and iteration # */
void print_status(const unordered_map<int, int>& map)
{
	cout << "Iteration: " << setw(width_for_iteration_num_g) << left << iteration_g++;
	cout << " Contents: ";
	for (const auto pair : map)
	{
		for (int i = 0; i < pair.second; ++i)
			cout << pair.first << " ";
	}
	cout << "\n";
}

/* Recursive function to calculate replicating ints up to the target sum. */
void calculate_target(unordered_map<int, int> map, int new_num, int curr_sum)
{
	print_status(map);
	map[new_num]++;
	curr_sum += new_num;

	// Check cases of sum to determine whether to break early, end program, or to continue recurisvely
	if (curr_sum > target_num_k) return;
	else if (curr_sum == target_num_k)
	{
		cout << "\n***Answer***: ";
		print_status(map);
		exit(0);
	}
	else
	{
		for (const auto bag_int : bag_of_ints_k)
		{
			// Check against max replication constant to ensure not going over
			if (map[bag_int] != max_amount_per_int_k)
				calculate_target(map, bag_int, curr_sum);
		}
	}
}