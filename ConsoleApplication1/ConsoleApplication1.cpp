#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void buldMatrix(int matrix[7][7]) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void Sort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Ukrainian");
	srand(time(0));
	int matrix[7][7];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
	cout << "Наявна матриця:" << endl;
	buldMatrix(matrix);

	int diagonal[7];
	for (int i = 0; i < 7; i++) {
		diagonal[i] = matrix[i][6 - i];
	}
	Sort(diagonal,7);
	for (int i = 0; i < 7; i++) {
		matrix[i][6 - i] = diagonal[i];
	}
	cout << "Посортована матриця:" << endl;
	buldMatrix(matrix);
	return 0;
}
