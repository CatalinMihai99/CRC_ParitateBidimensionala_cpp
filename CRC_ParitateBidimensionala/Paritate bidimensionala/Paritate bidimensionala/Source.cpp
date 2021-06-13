#include <iostream>
#include<string>
#include <sstream>
#include<vector>

using namespace std;
void creare_matrice(int** &matrix,string mesaj,int &n)
{
	vector<int>aux;

	for (int index = 0; index < mesaj.size(); index++)
	{
		int a;
		a = (int)mesaj[index] - 48;
		aux.push_back(a);
	}

	n = aux.size()/7;
	matrix = new int* [n];

	for (int index = 0; index < n; index++)
		matrix[index] = new int[7];

	int index3 = 0;

	for (int index = 0; index < n; index++)
		for (int index2 = 0; index2 < 7; index2++)
		{
			matrix[index][index2] = aux[index3];
			index3++;
		}
}
string paritate_bidimensionala(int **matrix,int n)
{
	vector<int>valori_de_pe_linii;
	vector<int>valori_de_pe_coloane;

	cout << "matrice:"<<endl;

	for (int index = 0; index < n; index++) {
		for (int index2 = 0; index2 < 7; index2++)
			cout << matrix[index][index2] << " ";
		cout << endl;
	}

	for (int index = 0; index < n; index++) {
		int s = 0;
		for (int index2 = 0; index2 < 7; index2++)
		{
			s += matrix[index][index2];
		}
		if (s % 2 == 0)
			valori_de_pe_linii.push_back(0);
		else valori_de_pe_linii.push_back(1);
	}

	int** transpusa;
	transpusa = new int* [7];
	for (int index = 0; index < 7; index++)
		transpusa[index] = new int[n];

	for (int index = 0; index < 7; index++)
	{
		for (int index2 = 0; index2 < n; index2++)
		{
			transpusa[index][index2] = matrix[index2][index];
		}
	}

	for (int index = 0; index < 7; index++) {

		int s = 0;

		for (int index2 = 0; index2 < n; index2++)
		{
			s += transpusa[index][index2];
		}

		if (s % 2 == 0)
			valori_de_pe_coloane.push_back(0);
		else
			valori_de_pe_coloane.push_back(1);
	}

	cout << endl << "de pe linii" << endl;

	for (int index = 0; index < valori_de_pe_linii.size(); index++)
		cout << valori_de_pe_linii[index] << " ";

	cout << endl << "de pe coloane" << endl;

	for (int index = 0; index < valori_de_pe_coloane.size(); index++)
		cout << valori_de_pe_coloane[index] << " ";

	cout << endl;
	vector<int>mesaj_int;

	for (int index = 0; index < n; index++)
	{
		for (int index2 = 0; index2 < 7; index2++)
			mesaj_int.push_back(matrix[index][index2]);
		mesaj_int.push_back(valori_de_pe_linii[index]);
	}

	for (int index = 0; index < valori_de_pe_coloane.size(); index++)
		mesaj_int.push_back(valori_de_pe_coloane[index]);

	cout << endl << "mesaj sub forma de vector de int:" << endl;

	for (int index = 0; index < mesaj_int.size(); index++)
		cout << mesaj_int[index] << " ";

	stringstream ss;

	for (size_t index = 0; index < mesaj_int.size(); index++)
	{
		ss << mesaj_int[index];
	}

	cout << endl << "mesajul transmis este;" << endl;
	string s = ss.str();

		return s;
			
}
bool verify1(string mesaj)
{
	for (int index = 0; index < mesaj.size(); index++)
		if ((mesaj[index]-48 != 0) and (mesaj[index]-48 != 1))
			return false;
	return true;
}
bool verify2(string mesaj)
{
	if (mesaj.size() % 7 == 0)
		return true;
	return false;
}
int main()
{

	std::string a;
	int** matrix;
	int n;
	a = "101101110101011101100";
	if ((verify1(a)) and (verify2(a)))
	{
		creare_matrice(matrix, a, n);
		cout << paritate_bidimensionala(matrix, n);
	}
	else
		cout << "nu ati introdus un mesaj corect";

	return 0;
}