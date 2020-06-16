#pragma once
#include <iostream>
#include <chrono>
using namespace std;
class SimpleTimer
{
	public:
		SimpleTimer() {
			start = std::chrono::high_resolution_clock::now();
		}
		~SimpleTimer() {
			end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> dur = end - start;
			cout << "DURATION IS" << dur.count() << endl;
		}
	private:
		std::chrono::time_point<std::chrono::steady_clock> start, end;
};

