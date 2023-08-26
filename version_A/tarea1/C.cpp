#include <iostream> //C//
using namespace std;

int main(){
	string input;
	cin >> input;

	int largo, puntosA, puntosB;
    
	puntosA = 0;
	puntosB = 0;

	largo = input.size();

	for(int i=0;i < largo-1 ;i = i+2){
		if(input[i] == 'A'){
			char ch;
			ch = input[i+1];			
			if(ch == '1'){
				puntosA = puntosA + 1;
				}
			else{
				puntosA = puntosA + 2;
				}
			}
		else{
			char ch;
			ch = input[i+1];		
			if(ch == '1'){
				puntosB = puntosB + 1;
				}
			else{
				puntosB = puntosB + 2;
				}
			}
		}
	if(puntosA < puntosB){
		cout << "B";
		}
	else{
		cout << "A";
		}
}




