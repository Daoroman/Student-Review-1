#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include  <iomanip>

using namespace std;

class Ebook {
public:
	Ebook()
		:pages_(MAX_PAGES_, 0),
		readers_(MAX_READERS_, 0)
	{}
	

	void Read(int id, int pages) {
		for (int i = readers_[id]; i < pages; ++i) {
			++pages_[i];
		}
	   readers_[id] = pages;
	}

	double Cheer(int id) {
	int p = readers_[id] ;
	if (p == 0) {
		return 0;
	}
	else if (pages_[0] == 1) {
		return 1;
	}
	return(pages_[0] - pages_[p - 1]) * 1.0 / (pages_[0] - 1) * 1.0;
	}

private:
	static const int MAX_READERS_ = 100000;
	static const int MAX_PAGES_ = 1000;

	vector<int> pages_;
	vector<int> readers_;
};

int main() {
	Ebook ebbok;
	int count;
	cin >> count;
	for (int i = 0; i < count; ++i) {
		string querry;
		int id;
		cin >> querry;
		if (querry == "READ") {
			int pages;
			cin >> id >> pages;
			ebbok.Read(id, pages);
		}
		if (querry == "CHEER") {
			cin >> id;
			cout << setprecision(6) << ebbok.Cheer(id) << endl;
		}
	}
}