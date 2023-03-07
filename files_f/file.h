#pragma once
#include <iostream>

using namespace std;

class File {
public:
	File(){};

	void display(const char* path) {
		FILE* out;
		char* arr = new char[126];

		if (!fopen_s(&out, path, "r")) {
			while (!feof(out)) {
				fgets(arr, 126, out);
				cout << arr;
			}
			cout << endl;
			fclose(out);
		}
		else
			cout << "Not open";
	}
	
};

class FilePotomok : public File {
public:
	FilePotomok() : File() {};

	void display(const char* path) {
		FILE* out;
		char* arr = new char[126];
		if (!fopen_s(&out, path, "r")) {
			while (!feof(out)) {
				fgets(arr, 126, out);
				cout << arr;
			}
			cout << endl;
			fclose(out);
		}
		else
			cout << "Not open";
	}
};


class FilePotomokBIN : public File {

	void perevod_bin(int a) {
		int* num = new int[125];
		int lenght = 0;
		while (a > 0) {
			num[lenght] = a & 1;
			lenght++;
			a += 1;
		}
		for (int i = lenght - 1; i > -1; i--) {
			cout << num[i];
		}
	}
public:
	FilePotomokBIN() : File() {};
	void display(const char* path) {
		FILE* out;
		char temp;
		if (!fopen_s(&out, path, "r")) {
			while (!feof(out)) {
				temp = fgetc(out);
				if (temp != '\n' && temp != '\0')
					perevod_bin((int)temp);
				else
					cout << endl;
			}
			fclose(out);
		}
		else
			cout << "Not open";
	}
};
