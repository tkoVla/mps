#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "omp/EquityCalculator.h"
//#include "omp/CardRange.h"
#include "Deck.h"
#include <fstream>
#include <map>

int main() {

	int NN = 4826809;

	srand(time(NULL));

	std::ifstream file;
	file.open("Sorted_Ranges.txt");
	std::vector<std::string> Sorted_Ranges;
	std::string s;
	Sorted_Ranges.push_back("");
	while (getline(file, s))
		Sorted_Ranges.push_back(s);
	file.close();
	std::cout << Sorted_Ranges.size() << std::endl;

	omp::CardRange R1 = omp::CardRange(Sorted_Ranges[6]); std::cout << Sorted_Ranges[6] << std::endl;
	omp::CardRange R2 = omp::CardRange(Sorted_Ranges[22]); std::cout << Sorted_Ranges[22] << std::endl;

	omp::CardRange emptyRange = omp::CardRange();
	
	std::vector<omp::CardRange> rranges = {Sorted_Ranges[6], Sorted_Ranges[22] };
	//rranges.push_back(R1); rranges.push_back(R2);
	//rranges.push_back(emptyRange); rranges.push_back(emptyRange); rranges.push_back(emptyRange); rranges.push_back(emptyRange);

	omp::EquityCalculator calc;
	calc.start(rranges); calc.wait();

	omp::EquityCalculator::Results rresults = calc.getResults();
	
	for (double r : rresults.equity)
		std::cout << r << std::endl;
	
	Deck D = Deck();

	//D.shuffle();
	//while(!D.empty())
	std::cout << D.deal() << std::endl;

	std::ofstream out_file;
	out_file.open("Rezultati.txt");
	int k;
	std::string a[7];
	for (int i = 0; i < NN; i++) {
	
		k = i;
		for (int j = 0; j < 6; j++) {
			a[j] = Sorted_Ranges[(k % 13) * 5];
			k /= 13;
		}

		rranges.clear(); rranges = { a[0], a[1], a[2], a[3], a[4], a[5] };
		calc.start(rranges); calc.wait();
		rresults = calc.getResults();
		for (double r : rresults.equity)
			out_file << r << ' ';
		out_file << '\n';
		out_file.close();
	}

	std::cin.get();

	return 0;
}