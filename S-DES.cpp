#include <iostream>
#include <string>
using namespace std;

void ci¹g(int arr[]);
void uzupelnienie(int arr[]);
void wypisz(int arr[]);
//void permutacja_wstepna(int arr[]);
//void krzyzowanie(int arr[]);
//void permutacja_odwrotna(int arr[]);
void per_gen_pier_rundy(int klucz[]);
void podzial_klucza_przesuwanie(int klucz[], int klucz1[], int klucz2[]);
void klucz_r_pier(int klucz[], int klucz1[], int klucz2[]);
void przesuniecie_drugiego_podklucza(int orgklucz[], int klucz12[], int klucz22[]);
void klucz_r_drug(int orgklucz[], int klucz12[], int klucz22[]);
void szyfr_podzielenie(int arr[], int arr1[], int arr2[],int arr2_copie[]);
void tworzenie_ci¹gu_8bitowego(int arr2[], int arr2_8bit[]);
void dodanie_kluczu_rundy_pierwszej(int klucz[], int arr2_8bit[]);
void dodanie_kluczu_rundy_drugiej(int orgklucz[], int cross[]);
void podzial_kluczu_rundy_pierwszej(int arr2_8bit[], int arr2_8bit_1[], int arr2_8bit_2[]);
void S_box1(int arr2_8bit_1[], int Sbox_2bit_1[]);
void S_box2(int arr2_8bit_2[], int Sbox_2bit_2[]);
void suma_boxow(int Sbox_2bit_1[], int Sbox_2bit_2[], int end_sbox[]);
void przesunieta_suma_boxow(int end_sbox[], int new_sbox[]);
void koncowy_xor(int arr1[], int new_sbox[], int end_xor[]);
void polaczenie(int finale[], int end_xor[], int arr2_copie[]);
void podzial_kluczu_rundy_drugiej(int cross[], int arr2_8bit_1[], int arr2_8bit_2[]);
void krzyzowanie(int finale[], int cross[]);
void perm_odwr(int finale[], int szyfr[]);

int main()
{
	int arr[8];
	int arr1[4], arr2[4];
	int arr2_8bit[8];
	int arr2_copie[4];
	int arr2_8bit_1[4];
	int	arr2_8bit_2[4];
	int klucz[10] = { 1,1,0,0,0,0,0,0,1,1 };
	int klucz1[5];
	int klucz2[5];
	int klucz12[5];
 	int klucz22[5];
	int orgklucz[10] = { 0,0,1,0,0,1,1,1,0,0 }; //problemy z constem, przypisane na sztywno
	
	int Sbox_2bit_1[2];
	int Sbox_2bit_2[2];
	int end_sbox[4];
	int new_sbox[4];
	int end_xor[4];
	int finale[8];
	int cross[8];
	int szyfr[8];
	int odsz;
	

	cout << "Wciœnij jeden aby zaszyfrowac, 2 aby deszyfrowac: ";
	cin >> odsz;
	if (odsz == 1)
	{

	
	cout << "Wpisz max 8 bitowy ciagu" << endl;
	ci¹g(arr);
	uzupelnienie(arr);
	wypisz(arr);
	cout << endl;
	//permutacja_wstepna(arr);
	per_gen_pier_rundy(klucz);
	cout << endl;
	podzial_klucza_przesuwanie(klucz,klucz1, klucz2);
	klucz_r_pier(klucz, klucz1, klucz2);
	przesuniecie_drugiego_podklucza(orgklucz, klucz12, klucz22);
	klucz_r_drug(orgklucz, klucz12, klucz22);
	szyfr_podzielenie(arr, arr1, arr2, arr2_copie);
	tworzenie_ci¹gu_8bitowego(arr2, arr2_8bit);
	
	//po permutacji rozpoczêcie szyfrowania rundy pierwszej
		dodanie_kluczu_rundy_pierwszej(klucz, arr2_8bit);
		podzial_kluczu_rundy_pierwszej(arr2_8bit, arr2_8bit_1, arr2_8bit_2);
		//tutaj zrobiê sboxy, problemy ze wskaznikami
		S_box1(arr2_8bit_1, Sbox_2bit_1);
		S_box2(arr2_8bit_2, Sbox_2bit_2);
		suma_boxow(Sbox_2bit_1, Sbox_2bit_2, end_sbox);
		przesunieta_suma_boxow(end_sbox, new_sbox);
		koncowy_xor(arr1, new_sbox, end_xor);
		polaczenie(finale, end_xor, arr2_copie);
		//krzy¿owanie
		krzyzowanie(finale, cross);
		// rozpoczêcie szyfrowania rundy drugiej
		dodanie_kluczu_rundy_drugiej(orgklucz, cross);
		podzial_kluczu_rundy_drugiej(cross, arr2_8bit_1, arr2_8bit_2);
		S_box1(arr2_8bit_1, Sbox_2bit_1);
		S_box2(arr2_8bit_2, Sbox_2bit_1);
		suma_boxow(Sbox_2bit_1, Sbox_2bit_2, end_sbox);
		przesunieta_suma_boxow(end_sbox, new_sbox);
		koncowy_xor(arr1, new_sbox, end_xor);
		polaczenie(finale, end_xor, arr2_copie);
		//permutacja odwrotna 
		perm_odwr(finale, szyfr);
	}
	else if (odsz == 2)
	{
		cout << "Wpisz max 8 bitowy ciagu" << endl;
		ci¹g(arr);
		uzupelnienie(arr);
		wypisz(arr);
		cout << endl;
		//permutacja_wstepna(arr);
		per_gen_pier_rundy(klucz);
		cout << endl;
		podzial_klucza_przesuwanie(klucz, klucz1, klucz2);
		klucz_r_pier(klucz, klucz1, klucz2);
		przesuniecie_drugiego_podklucza(orgklucz, klucz12, klucz22);
		klucz_r_drug(orgklucz, klucz12, klucz22);
		szyfr_podzielenie(arr, arr1, arr2, arr2_copie);
		tworzenie_ci¹gu_8bitowego(arr2, arr2_8bit);
		//po permutacji rozpoczêcie szyfrowania rundy drugiej
		dodanie_kluczu_rundy_drugiej(orgklucz, cross);
		podzial_kluczu_rundy_drugiej(cross, arr2_8bit_1, arr2_8bit_2);
		S_box1(arr2_8bit_1, Sbox_2bit_1);
		S_box2(arr2_8bit_2, Sbox_2bit_1);
		suma_boxow(Sbox_2bit_1, Sbox_2bit_2, end_sbox);
		przesunieta_suma_boxow(end_sbox, new_sbox);
		koncowy_xor(arr1, new_sbox, end_xor);
		polaczenie(finale, end_xor, arr2_copie);
		//krzy¿owanie
		krzyzowanie(finale, cross);
		// rozpoczêcie szyfrowania rundy pierwszej
		dodanie_kluczu_rundy_pierwszej(klucz, arr2_8bit);
		podzial_kluczu_rundy_pierwszej(arr2_8bit, arr2_8bit_1, arr2_8bit_2);
		//tutaj zrobiê sboxy, problemy ze wskaznikami
		S_box1(arr2_8bit_1, Sbox_2bit_1);
		S_box2(arr2_8bit_2, Sbox_2bit_2);
		suma_boxow(Sbox_2bit_1, Sbox_2bit_2, end_sbox);
		przesunieta_suma_boxow(end_sbox, new_sbox);
		koncowy_xor(arr1, new_sbox, end_xor);
		polaczenie(finale, end_xor, arr2_copie);
		//permutacja odwrotna 
		perm_odwr(finale, szyfr);
	}
	system("pause");
	return 0;
}
void uzupelnienie(int arr[])
{
	for (int i = 0; i < 8; i++)
	{
		if (arr[i] != 1)
		arr[i] = 0;
	}
}
void ci¹g(int arr[])
{
	string znaki;
	cin >> znaki;
	for (int i = 0; i < znaki.length(); i++)
	{
		char znaczek = znaki[i];
		arr[i] = atoi(&znaczek);
	}
}
void wypisz(int arr[])
{
	cout << "Wprowadzony kod do szyfrowania: ";
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	
}
//Szyfrowanie
void szyfr_podzielenie(int arr[],int arr1[], int arr2[] , int arr2_copie[])
{
	cout << "Wprowadzony kod do szyfrowania: ";
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
		arr1[0] = arr[0];
		arr1[1] = arr[1];
		arr1[2] = arr[2];
		arr1[3] = arr[3];
		//podzia³ na 2 podkoduy
		arr2[0] = arr[4];
		arr2[1] = arr[5];
		arr2[2] = arr[6];
		arr2[3] = arr[7];
		
		cout << endl;
		cout << "Podkod 1 : ";
		for (int i = 0; i < 4; i++)
		{
			cout << arr1[i] << " ";
		}
		cout << endl;
		cout << "Podkod 2 : ";
		for (int i = 0; i < 4; i++)
		{
			cout << arr2[i] << " ";
		}
		cout << endl;
		//kopia
		cout << "kopia podkodu 2 : ";
		for (int i = 0; i < 4; i++)
		{
			arr2_copie[i] = arr2[i];
			cout << arr2_copie[i];
		}
		cout<<endl;
}
void tworzenie_ci¹gu_8bitowego(int arr2[], int arr2_8bit[])
{
		arr2_8bit [0] = arr2[3];
		arr2_8bit [1] = arr2[0];
		arr2_8bit [2] = arr2[1];
		arr2_8bit [3] = arr2[2];
		arr2_8bit [4] = arr2[1];
		arr2_8bit [5] = arr2[2];
		arr2_8bit [6] = arr2[3];
		arr2_8bit [7] = arr2[0];
	
		cout << "Ciag 8bitowy kodu: ";
		for (int i = 0; i < 8; i++)
		{
			cout << arr2_8bit[i];
		}
		cout << endl;
}
void dodanie_kluczu_rundy_pierwszej(int klucz[], int arr2_8bit[]) 
{
	arr2_8bit[0] = arr2_8bit[0] ^ klucz[0];
	arr2_8bit[1] = arr2_8bit[1] ^ klucz[1];
	arr2_8bit[2] = arr2_8bit[2] ^ klucz[2];
	arr2_8bit[3] = arr2_8bit[3] ^ klucz[3];
	arr2_8bit[4] = arr2_8bit[4] ^ klucz[4];
	arr2_8bit[5] = arr2_8bit[5] ^ klucz[5];
	arr2_8bit[6] = arr2_8bit[6] ^ klucz[6];
	arr2_8bit[7] = arr2_8bit[7] ^ klucz[7];

	cout << "Xor z rundy pierwszej: ";                // DOROBIÆ RUNDE DRUG¥!!!
	for (int i = 0; i < 8; i++)
	{
		cout << arr2_8bit[i] << " ";
	}
}
void dodanie_kluczu_rundy_drugiej(int orgklucz[], int arr2_8bit[])
{
	arr2_8bit[0] = arr2_8bit[0] ^ orgklucz[0];
	arr2_8bit[1] = arr2_8bit[1] ^ orgklucz[1];
	arr2_8bit[2] = arr2_8bit[2] ^ orgklucz[2];
	arr2_8bit[3] = arr2_8bit[3] ^ orgklucz[3];
	arr2_8bit[4] = arr2_8bit[4] ^ orgklucz[4];
	arr2_8bit[5] = arr2_8bit[5] ^ orgklucz[5];
	arr2_8bit[6] = arr2_8bit[6] ^ orgklucz[6];
	arr2_8bit[7] = arr2_8bit[7] ^ orgklucz[7];

	cout << "Xor z rundy drugiej: ";                // DOROBIÆ RUNDE DRUG¥!!!
	for (int i = 0; i < 8; i++)
	{
		cout << arr2_8bit[i] << " ";
	}
}
void podzial_kluczu_rundy_pierwszej(int arr2_8bit[], int arr2_8bit_1[], int arr2_8bit_2[])
{
	arr2_8bit_1[0] = arr2_8bit[0];
	arr2_8bit_1[1] = arr2_8bit[1];
	arr2_8bit_1[2] = arr2_8bit[2];
	arr2_8bit_1[3] = arr2_8bit[3];
	arr2_8bit_2[0] = arr2_8bit[4];
	arr2_8bit_2[1] = arr2_8bit[5];
	arr2_8bit_2[2] = arr2_8bit[6];
	arr2_8bit_2[3] = arr2_8bit[7];

	cout << endl;
	cout << " Podzial Xora rundy pierwszej : " << endl << "1.";
	for (int i = 0; i < 4; i++)
	{
		cout << arr2_8bit_1[i] << " ";
	}
	cout <<endl<< " Podzial Xora rundy pierwszej : " << endl << "2.";
	for (int i = 0; i < 4; i++)
	{
		cout << arr2_8bit_2[i] << " ";
	}
	cout<<endl;
}
void podzial_kluczu_rundy_drugiej(int arr2_8bit[], int arr2_8bit_1[], int arr2_8bit_2[])
{
	arr2_8bit_1[0] = arr2_8bit[0];
	arr2_8bit_1[1] = arr2_8bit[1];
	arr2_8bit_1[2] = arr2_8bit[2];
	arr2_8bit_1[3] = arr2_8bit[3];
	arr2_8bit_2[0] = arr2_8bit[4];
	arr2_8bit_2[1] = arr2_8bit[5];
	arr2_8bit_2[2] = arr2_8bit[6];
	arr2_8bit_2[3] = arr2_8bit[7];

	cout << endl;
	cout << " Podzial Xora rundy pierwszej : " << endl << "1.";
	for (int i = 0; i < 4; i++)
	{
		cout << arr2_8bit_1[i] << " ";
	}
	cout << endl << " Podzial Xora rundy pierwszej : " << endl << "2.";
	for (int i = 0; i < 4; i++)
	{
		cout << arr2_8bit_2[i] << " ";
	}
	cout << endl;
}
void S_box1(int arr2_8bit_1[], int Sbox_2bit_1[])
{
	//int SBOX1[4][4] = { { 1,0,3,2 },{ 3,2,1,0 },{ 0,2,1,3 },{ 3,1,3,2 } };


	int sum_wier, sum_kol, res;
	cout << " Wartosc naszego wiersza dla Sboxa 1: "<< arr2_8bit_1[0] << " " << arr2_8bit_1[3] << endl;
	cout << " Wartosc naszej kolumny dla Sboxa 1: "<< arr2_8bit_1[1] << " " << arr2_8bit_1[2] << endl;

	if (arr2_8bit_1[0]==0 && arr2_8bit_1[3]==0)
	{
		cout << "Suma wierszy to 0" << endl;
		sum_wier = 0;
	}
	if (arr2_8bit_1[0] == 1 && arr2_8bit_1[3] == 0)
	{
		cout << "Suma wierszy to 2" << endl;
		sum_wier = 2;
	}
	if (arr2_8bit_1[0] == 0 && arr2_8bit_1[3] == 1)
	{
		cout << "Suma wierszy to 1" << endl;
		sum_wier = 1;
	}
	if (arr2_8bit_1[0] == 1 && arr2_8bit_1[3] == 1)
	{
		cout << "Suma wierszy to 3" << endl;
		sum_wier = 3;
	}
	if (arr2_8bit_1[1] == 0 && arr2_8bit_1[2] == 0)
	{
		cout << "Suma kolumn to 0" << endl;
		sum_kol = 0;
	}
	if (arr2_8bit_1[1] == 1 && arr2_8bit_1[2] == 0)
	{
		cout << "Suma kolumn to 2" << endl;
		sum_kol = 2;
	}
	if (arr2_8bit_1[1] == 0 && arr2_8bit_1[2] == 1)
	{
		cout << "Suma kolumn to 1" << endl;
		sum_kol = 1;
	}
	if (arr2_8bit_1[1] == 1 && arr2_8bit_1[2] == 1)
	{
		cout << "Suma kolumn to 3" << endl;
		sum_kol = 3;
	}
	if (sum_wier == 0 && sum_kol == 0|| sum_wier == 1 && sum_kol == 2||sum_wier == 2 && sum_kol == 2|| sum_wier == 3 && sum_kol == 1)
	{
		res = 1;
	}
	if (sum_wier == 0 && sum_kol == 1 || sum_wier == 1 && sum_kol == 3 || sum_wier == 2 && sum_kol == 0)
	{
		res = 0;
	}
	if (sum_wier == 0 && sum_kol == 3 || sum_wier == 1 && sum_kol == 1 || sum_wier == 2 && sum_kol == 1 || sum_wier == 3 && sum_kol == 3)
	{
		res = 2;
	}
	if (sum_wier == 0 && sum_kol == 2 || sum_wier == 1 && sum_kol == 0 || sum_wier == 2 && sum_kol == 3 || sum_wier == 3 && sum_kol == 0 || sum_wier == 3 && sum_kol == 2)
	{
		res = 3;
	}
	cout << endl << "RES = " << res << endl;
	if (res == 0)
	{
		Sbox_2bit_1[0] = 0;
		Sbox_2bit_1[1] = 0;
	}
	if (res == 1)
	{
		Sbox_2bit_1[0] = 0;
		Sbox_2bit_1[1] = 1;
	}
	if (res == 2)
	{
		Sbox_2bit_1[0] = 1;
		Sbox_2bit_1[1] = 0;
	}
	if (res == 3)
	{
		Sbox_2bit_1[0] = 1;
		Sbox_2bit_1[1] = 1;
	}
	cout << " Dwubitowy ciag kodujacy SBox1 : ";
	for (int i = 0; i < 2; i++)
	{
		cout << Sbox_2bit_1[i] << " ";
	}
	cout << endl;
}
void S_box2(int arr2_8bit_2[],int Sbox_2bit_2[])
{
	//int SBOX1[4][4] = { { 0,1,2,3 },{ 2,0,1,3 },{ 3,0,1,0 },{ 2,1,0,3 } };
	int sum_wier_1=0, sum_kol_1=0, res_1=0;

	cout << " Wartosc naszego wiersza dla Sboxa 2: " << arr2_8bit_2[0] << " " << arr2_8bit_2[3] << endl;
	cout << " Wartosc naszej kolumny dla Sboxa 2: " << arr2_8bit_2[1] << " " << arr2_8bit_2[2] << endl;

	if (arr2_8bit_2[0] == 0 && arr2_8bit_2[3] == 0)
	{
		cout << "Suma wierszy to 0" << endl;
		sum_wier_1 = 0;
	}
	if (arr2_8bit_2[0] == 1 && arr2_8bit_2[3] == 0)
	{
		cout << "Suma wierszy to 2" << endl;
		sum_wier_1 = 2;
	}
	if (arr2_8bit_2[0] == 0 && arr2_8bit_2[3] == 1)
	{
		cout << "Suma wierszy to 1" << endl;
		sum_wier_1 = 1;
	}
	if (arr2_8bit_2[0] == 1 && arr2_8bit_2[3] == 1)
	{
		cout << "Suma wierszy to 3" << endl;
		sum_wier_1 = 3;
	}
	if (arr2_8bit_2[1] == 0 && arr2_8bit_2[2] == 0)
	{
		cout << "Suma kolumn to 0" << endl;
		sum_kol_1 = 0;
	}
	if (arr2_8bit_2[1] == 1 && arr2_8bit_2[2] == 0)
	{
		cout << "Suma kolumn to 2" << endl;
		sum_kol_1 = 2;
	}
	if (arr2_8bit_2[1] == 0 && arr2_8bit_2[2] == 1)
	{
		cout << "Suma kolumn to 1" << endl;
		sum_kol_1 = 1;
	}
	if (arr2_8bit_2[1] == 1 && arr2_8bit_2[2] == 1)
	{
		cout << "Suma kolumn to 3" << endl;
		sum_kol_1 = 3;
	}
	if (sum_wier_1 == 0 && sum_kol_1 == 1 || sum_wier_1 == 1 && sum_kol_1 == 2 || sum_wier_1 == 2 && sum_kol_1 == 2 || sum_wier_1 == 3 && sum_kol_1 == 1)
	{
		res_1 = 1;
	}
	if (sum_wier_1 == 1 && sum_kol_1 == 1 || sum_wier_1 == 0 && sum_kol_1 == 0  || sum_wier_1 == 2 && sum_kol_1 == 1 || sum_wier_1 == 2 && sum_kol_1 == 3 || sum_wier_1 == 3 && sum_kol_1 == 2)
	{
		res_1 = 0;
	}
	if (sum_wier_1 == 0 && sum_kol_1 == 2 || sum_wier_1 == 1 && sum_kol_1 == 0 || sum_wier_1 == 3 && sum_kol_1 == 0)
	{
		res_1 = 2;
	}
	if (sum_wier_1 == 0 && sum_kol_1 == 3 || sum_wier_1 == 1 && sum_kol_1 == 3 || sum_wier_1 == 2 && sum_kol_1 == 0 || sum_wier_1 == 3 && sum_kol_1 == 3)
	{
		res_1 = 3;
	}
	cout << endl << "RES = "<<res_1<< endl ;

	if (res_1 == 0)
	{
		Sbox_2bit_2[0] = 0;
		Sbox_2bit_2[1] = 0;
	}
	if (res_1 == 1)
	{
		Sbox_2bit_2[0] = 0;
		Sbox_2bit_2[1] = 1;
	}
	if (res_1 == 2)
	{
		Sbox_2bit_2[0] = 1;
		Sbox_2bit_2[1] = 0;
	}
	if (res_1 == 3)
	{
		Sbox_2bit_2[0] = 1;
		Sbox_2bit_2[1] = 1;
	}

	cout << " Dwubitowy ciag kodujacy SBox2 : ";
	for (int i = 0; i < 2; i++)
	{
		cout << Sbox_2bit_2[i] << " ";           //DLACZEGO DAJE Z£Y WYNIK?!
	}
	cout << endl;

	//Napisane do sprawdzenia czy dzia³a
	//Sbox_2bit_2[0] = 0;
	//Sbox_2bit_2[1] = 0;

}
void suma_boxow(int Sbox_2bit_1[], int Sbox_2bit_2[], int end_sbox[])
{
	end_sbox[0] = Sbox_2bit_1[0];
	end_sbox[1] = Sbox_2bit_1[1];
	end_sbox[2] = Sbox_2bit_2[0];
	end_sbox[3] = Sbox_2bit_2[1];

	cout << " Suma boxow: ";
	Sbox_2bit_1[0];
	Sbox_2bit_1[1];
	Sbox_2bit_2[0];
	Sbox_2bit_2[1];
	for (int i = 0; i < 4; i++)
	{
		cout << end_sbox[i] << " ";
	}
	cout << endl;
}
void przesunieta_suma_boxow( int end_sbox[], int new_sbox[])
{
	new_sbox[0] = end_sbox[1];
	new_sbox[1] = end_sbox[3];
	new_sbox[2] = end_sbox[2];
	new_sbox[3] = end_sbox[0];

	cout << "Przesunieta suma boxow: ";
	for (int i = 0; i < 4; i++)
	{
		cout << new_sbox[i] << " ";
	}
	cout << endl;
}
void koncowy_xor(int arr1[], int new_sbox[], int end_xor[])
{	
	end_xor[0] = arr1[0] ^ new_sbox[0];
	end_xor[1] = arr1[1] ^ new_sbox[1];
	end_xor[2] = arr1[2] ^ new_sbox[2];
	end_xor[3] = arr1[3] ^ new_sbox[3];
}
void polaczenie(int finale[],int end_xor[], int arr2_copie[])
{
	finale[0] = end_xor[0];
	finale[1] = end_xor[1];
	finale[2] = end_xor[2];
	finale[3] = end_xor[3];
	finale[4] = arr2_copie[0];
	finale[5] = arr2_copie[1];
	finale[6] = arr2_copie[2];
	finale[7] = arr2_copie[3];
	cout << "Szyfr: ";
	for (int i = 0; i < 8; i++)
	{
		cout << finale[i] << " ";
	}
	cout << endl;
}
//krzyzowanie
void krzyzowanie(int finale[], int cross[])
{
		cross[0] = finale[4] ;
		cross[1] = finale[5] ;
		cross[2] = finale[6] ;
		cross[3] = finale[7] ;
		cross[4] = finale[0] ;
		cross[5] = finale[1] ;
		cross[6] = finale[2] ;
		cross[7] = finale[3] ;

		cout << "Krzyzowanie: ";
		for (int i = 0; i < 8; i++)
		{
			cout << cross[i] << " ";
		}
		cout << endl;
}
//permutacja odrwotna
void perm_odwr(int finale[], int szyfr[])
{
	szyfr[0] = finale[3];
	szyfr[1] = finale[0];
	szyfr[2] = finale[2];
	szyfr[3] = finale[4];
	szyfr[4] = finale[6];
	szyfr[5] = finale[1];
	szyfr[6] = finale[7];
	szyfr[7] = finale[5];
	 cout << "Wynik: ";
	for (int i = 0; i < 8; i++)
	{
		cout << szyfr[i] << " ";
	}
	cout << endl;
}


/*void permutacja_wstepna(int arr[])
{
	int subarr[8];
	for (int i = 0; i < 8; i++)
	{
		arr[i] = subarr[i];
	}
	arr[1] = subarr[0] ;
	arr[5] = subarr[1];
	arr[2] = subarr[2];
	arr[0] = subarr[3];
	arr[3] = subarr[4];
	arr[7] = subarr[5];
	arr[4] = subarr[6];
	arr[6] = subarr[7];
}
void krzyzowanie(int arr[])
{
	int subarr[8];
	for (int i = 0; i < 8; i++)
	{
		arr[i] = subarr[i];
	}
	arr[4] = subarr[0];
	arr[5] = subarr[1];
	arr[6] = subarr[2];
	arr[7] = subarr[3];
	arr[0] = subarr[4];
	arr[1] = subarr[5];
	arr[2] = subarr[6];
	arr[3] = subarr[7];
}

void permutacja_odwrotna(int arr[])
{
	int subarr[8];
	for (int i = 0; i < 8; i++)
	{
		arr[i] = subarr[i];
	}
	arr[3] = subarr[0];
	arr[0] = subarr[1];
	arr[2] = subarr[2];
	arr[4] = subarr[3];
	arr[6] = subarr[4];
	arr[1] = subarr[5];
	arr[7] = subarr[6];
	arr[5] = subarr[7];
}
*/
//GENERAZJA KLUCZY 1 RUNDY
void per_gen_pier_rundy(int klucz[])
{

	int subklucz[10];
	for (int i = 0; i < 10; i++)
	{
		subklucz[i] = klucz[i];
	}
	klucz[0] = subklucz[2];
	klucz[1] = subklucz[4];
	klucz[2] = subklucz[1];
	klucz[3] = subklucz[6];
	klucz[4] = subklucz[3];
	klucz[5] = subklucz[9];
	klucz[6] = subklucz[0];
	klucz[7] = subklucz[8];
	klucz[8] = subklucz[7];
	klucz[9] = subklucz[5];

	cout << "Oryginalny klucz po wstepnej permutacji: ";
	for (int i = 0; i < 10; i++)
	{
		cout << klucz [i] << " ";
	}
}
void podzial_klucza_przesuwanie(int klucz[], int klucz1[], int klucz2[])
{
	klucz1[4] = klucz[0];
	klucz1[0] = klucz[1];
	klucz1[1] = klucz[2];
	klucz1[2] = klucz[3];
	klucz1[3] = klucz[4];
	//podzia³ na 2 podklucze i przesuniêcie w lewo
	klucz2[4] = klucz[5];
	klucz2[0] = klucz[6];
	klucz2[1] = klucz[7];
	klucz2[2] = klucz[8];
	klucz2[3] = klucz[9];

	cout << "klucz1 r pierwszej po przesunieciu: ";
	for (int i = 0; i < 5; i++)
	{
		cout << klucz1[i] << " ";
	}
	cout << endl;
	cout << "klucz2 r pierwszej po przesunieciu: ";
	for (int i = 0; i < 5; i++)
	{
		cout << klucz2[i] << " ";
	}
	cout << endl;
}
void klucz_r_pier(int klucz[], int klucz1[], int klucz2[])
{
	klucz[0] = klucz2[0]; 
	klucz[1] = klucz1[2]; 
	klucz[2] = klucz2[1]; 
	klucz[3] = klucz1[3]; 
	klucz[4] = klucz2[2]; 
	klucz[5] = klucz1[4]; 
	klucz[6] = klucz2[4]; 
	klucz[7] = klucz2[3]; 

	cout << "klucz rundy pierwszej: ";
	for (int i = 0; i < 8; i++)
	{
		cout << klucz[i] << " ";
	}
	cout << endl;
}
void przesuniecie_drugiego_podklucza(int orgklucz[], int klucz12[], int klucz22[])

{
	cout << endl;
	cout << "Oryginalny klucz po wstepnej permutacji: ";
	for (int i = 0; i < 10; i++)
	{
		cout << orgklucz[i] << " ";
	}
	cout << endl;

	klucz12[2] = orgklucz[0];
	klucz12[3] = orgklucz[1];
	klucz12[4] = orgklucz[2];
	klucz12[0] = orgklucz[3];
	klucz12[1] = orgklucz[4];
	//podzia³ na 2 podklucze i przesuniêcie w lewo o 2 miejsza
	klucz22[2] = orgklucz[5];
	klucz22[3] = orgklucz[6];
	klucz22[4] = orgklucz[7];
	klucz22[0] = orgklucz[8];
	klucz22[1] = orgklucz[9];

	cout << "klucz1 r drugiej po przesunieciu: ";
	for (int i = 0; i < 5; i++)
	{
		cout << klucz12[i] << " ";
	}
	cout << endl;
	cout << "klucz2 r drugiej po przesunieciu: ";
	for (int i = 0; i < 5; i++)
	{
		cout << klucz22[i] << " ";
	}
	cout << endl;
}
void klucz_r_drug(int orgklucz[], int klucz12[], int klucz22[])
{
	orgklucz[0] = klucz22[0];
	orgklucz[1] = klucz12[2];
	orgklucz[2] = klucz22[1];
	orgklucz[3] = klucz12[3];
	orgklucz[4] = klucz22[2];
	orgklucz[5] = klucz12[4];
	orgklucz[6] = klucz22[4];
	orgklucz[7] = klucz22[3];


	cout << "Klucz rundy drugiej: ";
	for (int i = 0; i < 8; i++)
	{
		cout << orgklucz[i] << " ";
	}
	cout << endl;
}

	/*klucz1[4] = klucz[0];
	klucz1[0] = klucz[1];
	klucz1[1] = klucz[2];
	klucz1[2] = klucz[3];
	klucz1[3] = klucz[4];
	//podzia³ na 2 podklucze i przesuniêcie w lewo
	klucz2[4] = klucz[5];
	klucz2[0] = klucz[6];
	klucz2[1] = klucz[7];
	klucz2[2] = klucz[8];
	klucz2[3] = klucz[9]; */



//S-boxy
/*
void SBox1(int arr)
{

}

*/
