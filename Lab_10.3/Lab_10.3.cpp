#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
void AutoCreat(const char* filename, const int N, string* List, string prizn, int poznach, int time1, int time2)
{
	ofstream f;
	f.open(filename);
	for (int i = 0; i < N; i++)
	{
		f << prizn;
		f << ' ';
		f << List[poznach];
		f << ' ';
		f << time1;
		f << ':';
		f << time2;
		if (i != N - 1)
		{
			f << "\n";
		}
		cout << endl;
	}
	f.close();
}

void Creat(const char* filename, const int N, string* List)
{

	ofstream f;
	f.open(filename);
	string word;
	int a, poznach;
	for (int i = 0; i < N; i++)
	{
		cin.get(); cin.sync();
		cout << "Введіть місце призначення: "; cin >> word;
		do
		{
			if (word.find_first_of("0 123456789", 0) != -1)
			{
				cin.get(); cin.sync();
				word.erase(0, -1);
				cout << "Ви ввели невірні дані, попробуйте знову: " << endl;
				cout << " Введіть місце призначення: "; getline(cin, word);
			}
		} while (word.find_first_of("0 123456789", 0) != -1);
		f << word;
		cout << "Введіть позначку: ";
		cout << " Позначка (0 - звичайний , 1 - підвищеного комфорту, 2 - швидкісний експрес):";
		cin >> poznach;
		if (cin.fail() || poznach < 0 || poznach>2)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "Ви ввели невірне число, попробуйте знову: " << endl;
				cout << " Позначка (0 - звичайний , 1 - підвищеного комфорту, 2 - швидкісний експрес): ";
				cin >> poznach;
			} while (cin.fail() || poznach < 0 || poznach>2);
		}
		f << ' ';
		f << List[poznach];
		cout << "Введіть годину: "; cin >> a;
		if (cin.fail() || a < 1 || a>24)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "Ви ввели невірне число, попробуйте знову: " << endl;
				cout << " Введіть годину: "; cin >> a;
			} while (cin.fail() || a < 1 || a>24);
		}
		f << ' ';
		f << a;
		cout << "Введіть хвилину: "; cin >> a;
		if (cin.fail() || a < 1 || a>60)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "Ви ввели невірне число, попробуйте знову: " << endl;
				cout << " Введіть хвилину: "; cin >> a;
			} while (cin.fail() || a < 1 || a>60);
		}
		f << ':';
		f << a;
		if (i!=N-1)
		{
			f << "\n";
		}
		cout << endl;
	}
	f.close();
}

void Add(const char* filename, const int N, string* List,bool & are_open)
{
	ofstream f;
	f.open(filename, ios::app);
	if (!f.is_open())
	{
		cout << "Такого файла не існує"<< endl;
		are_open = false;
		return;
	}
	string word;
	int a,poznach;
	for (int i = 0; i < N; i++)
	{
		cin.get(); cin.sync();
		cout << "Введіть місце призначення: "; getline(cin, word);
		do
		{
			if (word.find_first_of("0 123456789", 0) != -1)
			{
				word.erase(0, -1);
				cout << "Ви ввели невірні дані, попробуйте знову: " << endl;
				cout << " Введіть місце призначення: "; getline(cin, word);
			}
		} while (word.find_first_of("0 123456789", 0) != -1);
		f << "\n";
		f << word;
		cout << " Позначка (0 - звичайний , 1 - підвищеного комфорту, 2 - швидкісний експрес):";
		cin >> poznach;
		if (cin.fail() || poznach < 0 || poznach>2)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "Ви ввели невірне число, попробуйте знову: " << endl;
				cout << " Позначка (0 - звичайний , 1 - підвищеного комфорту, 2 - швидкісний експрес): ";
				cin >> poznach;
			} while (cin.fail() || poznach < 0 || poznach>2);
		}
		f << ' ';
		f << List[poznach];
		cout << "Введіть годину: "; cin >> a;
		if (cin.fail() || a < 1 || a>24)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "Ви ввели невірне число, попробуйте знову: " << endl;
				cout << " Введіть годину: "; cin >> a;
			} while (cin.fail() || a < 1 || a>24);
		}
		cin.get(); cin.sync();
		f << ' ';
		f << a;
		cout << "Введіть хвилину: "; cin >> a;
		if (cin.fail() || a < 1 || a>60)
		{
			do
			{
				cin.clear();
				cin.ignore(255, '\n');
				cout << "Ви ввели невірне число, попробуйте знову: " << endl;
				cout << " Введіть хвилину: "; cin >> a;
			} while (cin.fail() || a < 1 || a>60);
		}
		f << ':';
		f << a;
	}
}

void Print(const char* filename, string* List,bool & are_open)
{
	ifstream f(filename);
	if (!f.is_open())
	{
		cout << "Такого файла не існує"<< endl;
		are_open = false;
		return;
	}
	string line;
	while (getline(f, line))
	{
		cout << line << endl;
	}
}

void Pisla(const char* filename, string* List,bool & are_open)
{
	fstream f(filename);
	if (!f.is_open())
	{
		cout << "Такого файла не існує" << endl;
		are_open = false;
		return;
	}
	int pos1,pos2;
	int tmp[2],tmp2[2];
	string line,s;
	cout << " Введіть потрібен вам час:\nГодина: "; cin >> tmp[0];
	if (cin.fail() || tmp[0] < 1 || tmp[0]>24)
	{
		do
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Ви ввели невірні дані, попробуйте знову: " << endl;
			cout << " Година: "; cin >> tmp[0];
		} while (cin.fail() || tmp[0] < 1 || tmp[0]>24);
	}
	cin.get(); cin.sync();
	cout << "Хвилина: "; cin >> tmp[1];
	if (cin.fail() || tmp[1] < 1 || tmp[1]>60)
	{
		do
		{
			cin.clear();
			cin.ignore(255, '\n');
			cout << "Ви ввели невірні дані, попробуйте знову: " << endl;
			cout << " Хвилина: "; cin >> tmp[1];
		} while (cin.fail() || tmp[1] < 1 || tmp[1]>60);
	}
	cout << endl;
	cout << "Список поїздів, які відходять після введеного часу:" << endl;
	while (getline(f, line))
	{
		pos1=line.find_last_of(':')-2;
		if (line[pos1]==' ')
		{
			pos1++;
		}
		pos2 = line.find_last_of(':') + 1;
		
		tmp2[0] = stoi(line.substr(pos1, 2));
		tmp2[1] = stoi(line.substr(pos2, 2));
		if ((tmp2[0]>tmp[0])||(tmp2[0]==tmp[0]&&tmp2[1]>tmp[1]))
		{
			cout << line << endl;
		}
	}
	f.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[60];
	int N;
	bool are_open;
	string List[] =
		{
			"звичайний",
			"підвищеного комфорту",
			"швидкісний експрес"
		};

	char word2[254];
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - створити новий файл" << endl;
		cout << " [2] - вивести дані файлу" << endl;
		cout << " [3] - доповнити існуючий файл" << endl;
		cout << " [4] - вивести електрички, які відходять після конкретного часу" << endl;
		cout << " [0] - вихід" << endl << endl;
		cout << "введіть число: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cout << "Введіть кількість елементів: "; cin >> N;
			if (cin.fail() || N<1)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "Ви ввели невірні дані, попробуйте знову: " << endl;
					cout << " Введіть кількість елементів: "; cin >> N;
				} while (cin.fail() || N < 1);
			}
			cout << "Введіть назву файлу: "; cin >> filename;
			Creat(filename, N, List);
			break;
		case 2:
			do
			{
				cout << "Введіть назву файлу: "; cin >> filename;
				are_open = true;
				Print(filename, List,are_open);
			} while (!are_open);
			break;
		case 3:
			cout << "Введіть кількість елементів для доповнення: "; cin >> N;
			if (cin.fail() || N < 1)
			{
				do
				{
					cin.clear();
					cin.ignore(255, '\n');
					cout << "Ви ввели невірні дані, попробуйте знову: " << endl;
					cout << " Введіть кількість елементів для доповнення: "; cin >> N;
				} while (cin.fail() || N < 1);
			}
			do
			{
				cout << "Введіть назву файлу: "; cin >> filename;
				are_open = true;
				Add(filename, N, List,are_open);
			} while (!are_open);
			break;
		case 4:
			do
			{
				cout << "Введіть назву файлу: "; cin >> filename;
				are_open = true;
				Pisla(filename, List,are_open);
			} while (!are_open);

			break;
		case 0:
			break;
		default:
			cout << "Ви ввели неправильний номер!" << endl;
		}
	} while (menuItem != 0);

	return 0;
}