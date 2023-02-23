#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

int main()
{
	const RandomSeed masterSeed = 674;
	const size_t numTrials = 50;
	const size_t numElements = 50;
	const size_t d = 12;

	std::vector<RandomSeed> seedVector = makeRandomSeedVector(numTrials, masterSeed);

	for(RandomSeed trialSeed : seedVector)
	{
		std::vector<int> data = makeRandomNumberVector<int>(numElements, 0, numElements * 10, trialSeed, true);
		Heap<int> heap(d);

		for(int value : data)
		{
			heap.push(value);
		}
	}
	return 1;
}

