#include <iostream>
using namespace std;

main(){
	int t;
	cin >> t;
	while(t--){
		int col = -1;
		string word;
		for(int i = 0; i < 8; i++){
			string line;
			cin >> line;
			if(col == -1){
				for(int j = 0; j < 8; j++){
					if(line[j] != '.'){
						word += line[j];
						col = j;
						}
					}
				}
			else{
				if(line[col] != '.'){
					word += line[col];
					}
				}
			}
		cout << word << endl;
		}
	}
