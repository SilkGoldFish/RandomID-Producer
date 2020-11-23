#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

int getRandomNum() {
	return rand() % 26;
}

void PrintTime(fstream& file) {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	// 输出 tm 结构的各个组成部分
	file << "Time:" << 1900 + ltm->tm_year << ".";
	file << 1 + ltm->tm_mon << ".";
	file << ltm->tm_mday << " ";
	file << ltm->tm_hour << ":";
	file << ltm->tm_min << ":";
	file << ltm->tm_sec;
}

void Produce(int mode, string name, int length) {
	fstream file("result.txt", ios::in | ios::app);
	string result;
	int CharArray[27] = { 0 };
	char c;
	int flag = 1;
	if (!file) {
		return;
	}
	switch (mode) {
	case 1:
		if (length <= 26) {
			while (result.size() < length) {
				c = getRandomNum();
				if (!CharArray[c]) {
					result.push_back(c + 'a');
					++CharArray[c];
				}
			}
		}
		else {
			cout << "Wrong length number!" << endl;
			flag = 0;
		}
		break;
	case 2:
		while (result.size() < length) {
			c = getRandomNum();
			result.push_back(c + 'a');
		}
		break;
	default:
		cout << "Wrong mode number!" << endl;
		flag = 0;
	}
	if (flag) {
		PrintTime(file);
		file << " Name:" << name << " Mode:" << mode << " Length:" << length << " ID:" << result << endl;
	}
	file.close();
}

int main() {
	srand((unsigned)time(0));
	string name;
	int mode;
	int length;
	cout << "Please input your name:";
	cin >> name;
	cout << "Please choose the mode you want:" << endl;
	cout << "1.All characters are different but the length should be under 26" << endl;
	cout << "2.There could be same characters but the length could be any" << endl;
	cin >> mode;
	cout << "Input the length of the ID(if you choose mode 1 it should be under 26):";
	cin >> length;
	Produce(mode, name, length);
}