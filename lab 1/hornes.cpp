//program to implement horners method
//polynomial long division

#include <iostream>

using namespace std;

int main(){
	
	float x;
	int i, deg;
	
	cout << "Enter the degree: ";
	cin >> deg;
	
	float arr[deg + 1], div[deg + 1];
	
	for(i = 0; i <= deg; i++){
		cin >> arr[i];
	}
	
	cout << "Enter the value of x: ";
	cin >> x;
	
	i = 1;
	div[0] = arr[0];
	
	while(i != deg + 1){
		div[i] = (arr[i] + x * div[i -1]);
		i++;
	}
	
	cout << "The quotient is: ";
	for(int i = 0; i <= deg ; i++){
		cout << div[i] <<"\t";
	}
	cout << "\nRemainder: " << arr[deg];
	
	return 0;
}
