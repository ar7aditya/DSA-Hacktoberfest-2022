/*
	In Dicken's time, merchants measured many commodities using weights and a two-pan balance - a practice that 
	continues in many parts of the world today. If you are using a limited set of weights, however, you can only measure
	certain quanitites accurately.
	
	For example, suppose you have only two weughts: a 1-ounce weught and a 3-ounce weight. With these you can measure out
	4 ounces by putting both weights on one pan and commodities on the other. But interestingly, you can also measure
	2 ounces by putting 3 ounce weight on one pan and '1-ounce weight and commodities' on the other pan.
	
	Write a recursive function:
		bool isMeasureable(int target, int* weights, int N);
	that determines whether it is possible to measure out the desired target amount with a
	given set of weights. The weights are stored in the integer array 'weights'.
*/

#include <iostream>
using namespace std;

bool isMeasureable(int target, int* weights, int N)
{
	if (N <= 0 || target < 0)
		return false;
	if (target == weights[N - 1])
		return true;
	bool flag = false;
	if (!flag)
	{
		int t = target - weights[N - 1];
		if (t < 0)
			t *= -1;
		flag = isMeasureable(t, weights, N - 1);
	}
	if (!flag)
	{
		flag = isMeasureable(target, weights, N - 1);
	}
	if (!flag)
	{
		flag = isMeasureable(target + weights[N - 1], weights, N - 1);
	}
	return flag;
}

int main()
{
	int w = 0;
	int weights[4] = { 1,3,20 };
	cin >> w;
	while (w != -1)
	{
		cout << isMeasureable(w, weights, 4) << "\n";
		cin >> w;
	}
	return 0;
}