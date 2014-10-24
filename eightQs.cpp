#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int Grid_Size = 8;

bool checkValid(int* columns, int row1, int column1){
	for(int row2 = 0; row2 < row1; row2++){
		int column2 = columns[row2];
		if(column1 == column2){
			return false;
		}

		int cd = abs(column2 - column1);
		int rd = row1 - row2;
		if(cd == rd){
			return false;
		}
	}
	return true;
}

void placeQ(int row, int* columns, vector<int*> results){
	if(row == Grid_Size){
		results.push_back(columns);
	}
	else{
		for(int col = 0; col < Grid_Size; ++col){
			if(checkValid(columns, row, col)){
				columns[row] = col;
				placeQ(row + 1, columns, results);
			}
		}
	}
}



int main(){
	vector<int*> v1;
	int arr[8];
	placeQ(0, arr, v1);
	for(size_t ix = 0; ix < v1.size(); ix++){
		int* tmp = v1[ix];
		for(int i = 0; i < 8; ++i){
			cout << tmp <<" ";
		}
		cout << endl;
	}
	return 1;
}