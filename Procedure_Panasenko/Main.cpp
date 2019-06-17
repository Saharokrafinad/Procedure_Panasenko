#include <iostream>
#include "Program.h"
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 3)
	{
		cout << "Ошибка. Не найдены файлы in_file out_file" << endl;
		exit(1);
	}

	ifstream inFileStream(argv[1]);
	ofstream outFileStream(argv[2]);
	container c;

	cout << "Старт" << endl;
	InitContainer(c);
	InContainer(c, inFileStream);
	cout << "Контейнер заполнен" << endl;
	OutContainer(c, outFileStream);
	MultiMethod(c, outFileStream);
	ClearContainer(c);
	cout << "Контейнер очищен" << endl;
	cout << "Завершение работы" << endl;

	system("pause");
	return 0;
}

