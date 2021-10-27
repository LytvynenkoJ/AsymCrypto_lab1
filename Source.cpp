#include "Header.h"

int main()
{
	setlocale(LC_ALL,"Russian");

	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			help[i][j] = 0;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		xi_arr[i] = 0;
	}
	xi_arr[0] = sqrt(510) * alph90 + 255;
	xi_arr[1] = sqrt(510) * alph95 + 255;
	xi_arr[2] = sqrt(510) * alph99 + 255;
	xi_arr[3] = sqrt(2) * alph90 * 255 + 65025;
	xi_arr[4] = sqrt(2) * alph95 * 255 + 65025;
	xi_arr[5] = sqrt(2) * alph99 * 255 + 65025;
	xi_arr[6] = sqrt(510 * 15) * alph90 + 3825;
	xi_arr[7] = sqrt(510 * 15) * alph95 + 3825;
	xi_arr[8] = sqrt(510 * 15) * alph99 + 3825;
	out.open("results.csv", ios::app);
	out << "Tests;;Test1;;;Test2;;;Test3\n";
	out << "alpha;0.9;0.95;0.99;0.9;0.95;0.99;0.9;0.95;0.99\n limits;";
	for (int i = 0; i < 9; i++)
	{
		out << xi_arr[i] << ";";
	}
	out << "\n";
	out.close();

	obnul();
	inGen();
	out.open("results.csv", ios::app);
	out << "built-in;";
	out.close();
	cout << "Получена последовательность с помощью встроенного генератора" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;

	cout << "Получаем начальные заполнения регистров (пожалуйста, двигайте курсором)" << endl << endl;
	initial_register();
	decToBin();
	cout << endl << "==========================================================" << endl << endl;


	out.open("results.csv", ios::app);
	out << "Geffe;";
	out.close();
	obnul();
	for (int i = 0; i < length_of_sq; i++)
	{
		sq[i] = Geffe();
	}
	cout << "Получена последовательность с помощью генератора Джиффи" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;

	out.open("results.csv", ios::app);
	out << "L20;";
	out.close();
	obnul();
	for (int i = 0; i < length_of_sq; i++)
	{
		sq[i] = L20();
	}
	cout << "Получена последовательность с помощью генератора L20" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "L89;";
	out.close();
	obnul();
	for (int i = 0; i < length_of_sq; i++)
	{
		sq[i] = L89();
	}
	cout << "Получена последовательность с помощью генератора L89" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "Biblio;";
	out.close();
	obnul();
	Biblio();
	cout << "Получена последовательность с помощью генератора библиотекаря" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "LehmerLow;";
	out.close();
	obnul();
	Lehmer(1);
	cout << "Получена последовательность с помощью линейного генератора (LehmerLow)" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "LehmerHigh;";
	out.close();
	obnul();
	Lehmer(2);
	cout << "Получена последовательность с помощью линейного генератора (LehmerHigh)" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "Volfram;";
	out.close();
	obnul();
	Volfram();
	cout << "Получена последовательность с помощью генератора Вольфрама" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "BM(1);";
	out.close();
	obnul();
	BM(1);
	cout << "Получена последовательность с помощью генератора ВM (битовая модификация)" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "BM(8);";
	out.close();
	obnul();
	BM(2);
	cout << "Получена последовательность с помощью генератора ВM (байтовая модификация)" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "BBS(1);";
	out.close();
	obnul();
	BBS(1);
	cout << "Получена последовательность с помощью генератора ВBS (битовая модификация)" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;


	out.open("results.csv", ios::app);
	out << "BBS(8);";
	out.close();
	obnul();
	BBS(2);
	cout << "Получена последовательность с помощью генератора ВBS (байтовая модификация)" << endl << endl;
	probabTest();
	indepTest();
	uniformTest();
	cout << endl << "---------------------------------------------------------" << endl << endl;

	
	return 0;
}
