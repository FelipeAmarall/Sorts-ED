#include<iostream>
#include <time.h>
using namespace std;

#define MAX 100

void VectorFill(int vetor[], int tamanho) {
	int aux = 0;

	for (int i = 0; i < tamanho; i++) {

		aux = (1 + rand() % tamanho);
		int aux2 = 0;

		while (aux2 < i) {
			if (aux != vetor[aux2])
				aux2++;
			else {
				aux = (1 + rand() % tamanho);
				aux2 = 0;
			}
		}
		vetor[i] = aux;
	}
}

int Insert(int n, int num[])
{
	int i, j, x, cont = 0;
	for (j = 1; j < n; ++j)
	{
		x = num[j];
		for (i = j - 1; i >= 0 && num[i] > x; --i)
		{
			num[i + 1] = num[i];
			cont++;
		}
		num[i + 1] = x;
	}
	return cont;
}

int Bolha(int vet[])
{
	int temp;
	int cont = 0;
	for (int x = 0; x < MAX; x++)
	{
		for (int y = x + 1; y < MAX; y++)
		{
			if (vet[x] > vet[y])
			{
				temp = vet[x];
				vet[x] = vet[y];
				vet[y] = temp;
				cont++;
			}
		}
	}
	return cont;
}

int Quick(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	int cont = 0;

	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
			cont++;
		}
	};

	if (left < j)
		cont += Quick(arr, left, j);
	if (i < right)
		cont += Quick(arr, i, right);

	return cont;
}

void Reset(int vetor[], int copia[], int tamanho) {
	for (int i = 0; i < MAX; i++)
		copia[i] = vetor[i];
}


int main()
{
	srand(time(NULL));
	int vet[MAX];
	int vetcp[MAX];

	VectorFill(vet, MAX);
	Reset(vet, vetcp, MAX);

	int InsertResult = Insert(MAX, vetcp);
	Reset(vet, vetcp, MAX);
	int BubbleResult = Bolha(vetcp);
	Reset(vet, vetcp, MAX);
	int QuickResult = Quick(vetcp, 0, MAX - 1);
	Reset(vet, vetcp, MAX);	

	cout <<"Trocas Insert:"<< InsertResult;
	cout << endl;
	cout <<"Trocas Bubble:"<< BubbleResult;
	cout << endl;
	cout <<"Trocas Quick:"<< QuickResult;
	cout << endl;

	//Metodo Insert:
	/*for (int i = 0; i < MAX; i++)
	{
		cout << "digite o numero (Insert):\n";
		cin >> vet[i];
	}

	for (int i = 0; i < MAX; i++)
	{
		Insert(MAX, vet);
	}

	cout << "Metodo Insert:\n";
	for (int i = 0; i < MAX; i++)
		cout << "/" << vet[i];'*/
		
	
	//Metodo bubble:
	/*for (int i = 0; i < MAX; i++)
	{
		cout << "digite o numero (bubble):\n";
		cin >> vet2[i];
	}

	Bolha(vet2);

	cout << "Metodo Bubble:\n";
	for (int i = 0; i < MAX; i++)
		cout << "/" << vet2[i];*/

	//Metodo Quick
	/*for (int i = 0; i < MAX; i++)
	{
		cout << "digite o numero (Quick):\n";
		cin >> vet3[i];
	}

	Quick(vet3, 0, MAX);

	cout << "Metodo Quick:\n";
	for (int i = 0; i < MAX; i++)
		cout << "/" << vet3[i];*/

	system("pause");
	return 0;
}