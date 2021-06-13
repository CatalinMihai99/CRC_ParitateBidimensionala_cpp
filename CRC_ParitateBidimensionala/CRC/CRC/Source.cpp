#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

void string_to_vector(string M, int C, vector<int>& T, vector<int>& C_vector)
{
	for (int index = 0; index < M.size(); index++)
	{
		int a;
		a = (int)M[index] - 48;
		T.push_back(a);
	}
	while (C)
	{
		C_vector.push_back(C % 10);
		C = C / 10;
	}
	reverse(C_vector.begin(), C_vector.end());

	for (int index = 0; index < C_vector.size() - 1; index++)
		T.push_back(0);

	cout << "T(x)=";

	for (int index = 0; index < T.size(); index++)
		cout << T[index];
}
void XOR(vector<int>T, vector<int>C_vector, vector<int>& R)
{
	R.clear();

	cout << "Pasii XOR :" << endl;

	while (T.size() >= C_vector.size())
	{
		for (int index = 0; index < C_vector.size(); index++)
		{
			if ((T[index] + C_vector[index]) % 2 == 0)T[index] = 0;
			else T[index] = 1;
		}

		for (int index = 0; index < T.size(); index++)
		{
			if (T[index] == 0)
			{
				vector<int>::iterator it;
				it = T.begin();
				T.erase(it);
				index--;
			}
			else break;
		}

		for (int index = 0; index < T.size(); index++)
			cout << T[index];

		cout << endl;
	}

	R = T;

	if (R.size() > 0)
		cout << "R(x)=";
	else cout << "R(x) nu are nici un element,impartirea nu are rest" << endl;

	for (int index = 0; index < R.size(); index++)
		cout << R[index];
}
void scadere_binara(vector<int>T, vector<int>R, vector<int>& M_prim)
{
	reverse(T.begin(), T.end());
	reverse(R.begin(), R.end());

	for (int index = 0; index < R.size(); index++)
	{
		if ((T[index] + R[index]) % 2 == 0)
			T[index] = 0;
		else T[index] = 1;
	}

	reverse(T.begin(), T.end());

	M_prim = T;

	cout << endl << "M'(x)=";

	for (int index = 0; index < M_prim.size(); index++)
		cout << M_prim[index];

	cout << endl;
}
int main()
{

	vector<int>T;
	vector<int>C_vector;
	vector<int>R;
	vector<int>M_prim;
	vector<int>R_prim;

	string M = "1101010100111001101";
	int C = 1011;

	cout << "M(x)=" << M << endl;
	cout << "C(x)=" << C << endl;

	string_to_vector(M, C, T, C_vector);
	cout << endl;

	XOR(T, C_vector, R);
	scadere_binara(T, R, M_prim);
	XOR(M_prim, C_vector, R_prim);

	if (R_prim.size() > 0)
		cout << "MESAJ CU ERORI \n";
	else cout << "MESAJ FARA ERORI \n";

	int random_pozitie = rand() % M_prim.size();

	cout << "pozitia random pe care o vom modifica din M' este " << random_pozitie << endl;

	if (M_prim[random_pozitie] == 0)
		M_prim[random_pozitie] = 1;
	else M_prim[random_pozitie] = 0;

	XOR(M_prim, C_vector, R_prim);

	if (R_prim.size() > 0)
		cout << "\nMESAJ CU ERORI \n\n\n";
	else cout << "\nMESAJ FARA ERORI \n\n\n";

	return 0;
}

