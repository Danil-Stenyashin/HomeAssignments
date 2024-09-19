#include <iostream>
#include "greet.h"
#include <string>

void hello(){
	while (true){
		string str;
		cout << std::endl;
		cin >> str;
		if (str == "pause"){
			break;
		}
		cout << "Hello, " << str << "!";
	}
	
}

