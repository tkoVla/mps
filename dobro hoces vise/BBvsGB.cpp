#include <iostream>
#include "omp/CardRange.h"
#include "omp/EquityCalculator.h"
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

static int s = 0;

void _f() {
	s++;
	std::this_thread::sleep_for(std::chrono::seconds(s));
	std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
}

int main() {

	std::ifstream myFile;
	myFile.open("Sorted_Ranges.txt");
	std::ofstream izlaz;
//	izlaz.open("BBvsGB.txt"); izlaz.close();

	std::vector<std::string> sRanges; sRanges.push_back("");
	std::string s;
	while (getline(myFile, s))
		sRanges.push_back(s);
	myFile.close();
	std::vector<omp::CardRange> rranges;
	omp::EquityCalculator::Results rresults;
	omp::EquityCalculator eq;
	
	/*
	std::cout << "Prije threadova!\n";

	std::thread t1(_f);
	std::thread t2(_f);
	std::thread t3(_f);
	std::thread t4(_f);
	std::thread t5(_f);
	std::thread t6(_f);


	std::cout << std::this_thread::get_id() << std::endl;

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();


	std::cout << std::this_thread::get_id() << std::endl;
	*/
	
	for(int i=0; i<=60; i+=5)
		for (int j = 0; j <= 60; j += 5) {
			rranges.clear(); rranges = { sRanges[i], sRanges[j] };
			eq.start(rranges);

			rresults = eq.getResults();

			std::cout << "BB range:" << sRanges[i] << std::endl;
			std::cout << "GB range:" << sRanges[j] << std::endl;

			for (double r : rresults.equity)
				std::cout << r << ' ';
			std::cout << std::endl << std::endl;
		}
		
	return 0;
}