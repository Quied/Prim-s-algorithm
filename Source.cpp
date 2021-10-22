#include <iostream>
#include <deque>
#include <set>

class array {
public:

	std::deque<int>Sectors{ 0 }; // Open sectors for while(for)
	std::deque<int>Min_Value;
	std::deque<int>Nodes{ 0 };

	int arr[5][5]{ 0 };


	void filling_array() {
		arr[0][1] = 9;
		arr[0][2] = 7;

		arr[1][0] = 9;
		arr[1][2] = 5;
		arr[1][3] = 34;

		arr[2][0] = 7;
		arr[2][1] = 5;
		arr[2][3] = 5;
		arr[2][4] = 6;

		arr[3][1] = 34;
		arr[3][2] = 5;
		arr[3][4] = 8;

		arr[4][3] = 8;
		arr[4][2] = 6;

	}

	void show_array() {
		system("cls");
		for (int j = 0; j < 5; j++) {
			for (int i = 0; i < 5; i++) {
				std::cout << arr[j][i] << " ";
			}
			std::cout << std::endl;
		}
	}

	void amount_nodes() {
		
		for (int i = 0; i < Nodes.size(); i++) {
			Nodes[i]++;
		}

		std::cout << std::endl;
		std::cout << "Need connection: ";
		for (auto el : Nodes) {
			std::cout << el << " ";
		}



		std::cout << std::endl << std::endl;
	}

	void suma_min() {
		std::cout << std::endl;
		int a = 0;
		for (int i = 0; i < Min_Value.size(); i++) {
			a = a + Min_Value[i];
		}
		std::cout << "Suma: " << a;
	}

	void find_way() {

		int max_sec = 0;
		int skip = 1;
		int j = 0;
		int min = 100;
		int next_index = 0;
		int sector_index = 0;
		bool wh = true;
		while (wh) {
				min = 100;


				for (int j = 0; j < Sectors.size(); j++) {
					for (int i = 0; i < 5; i++) {
						if (arr[Sectors[j]][i] < min && arr[Sectors[j]][i] != 0) {
							min = arr[Sectors[j]][i];
							next_index = i;
							sector_index = Sectors[j];
						}
					}
				}


				arr[sector_index][next_index] = 0;

			    	Nodes.push_back(next_index);
					Sectors.push_back(next_index);
					std::set<int>st;
					for (auto el : Sectors) {
						st.insert(el);
					}
					Sectors.clear();
					for (auto el : st) {
						Sectors.push_back(el);
					}
					st.clear();

					if (min == 100) {

					}
					else {
						Min_Value.push_back(min);
					}
					if (Sectors.size() == 5) {
						wh = false;
					}
		
					show_array();
				
		}

	}

	void show_Min_value() {
		std::cout << std::endl;
		std::cout << "M I N - V A L U E" << std::endl;
		for (auto el : Min_Value) {
			std::cout << el << " ";
		}
	}
};

int main() {

	array main;
	main.filling_array();
	main.show_array();
	main.find_way();
	main.show_Min_value();
	main.suma_min();
	main.amount_nodes();

}