//David Wallace
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout<< sumOfNumbers(num);
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				if(isMember(myArray,num,ARRAY_SIZE)==1){
					cout<<"The element was found in the array\n\n";
				}
				else{cout<<"The element was not found in the array\n\n";}
				
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				stringReverser(userString,userString.length());
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces from string
				userStrWithoutSpaces = userString;
				for(int x=0; x<userStrWithoutSpaces.size(); x++)
				{
					if(userStrWithoutSpaces[x] == ' ') 
						userStrWithoutSpaces.erase(x, 1);
				}
				if(isPalindrome(userStrWithoutSpaces)==1){cout<<"The string you entered is a palindrome\n\n";}
				else{cout<<"The string you entered is not a palindrome\n\n";}
				
				cout<<userStrWithoutSpaces;
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout<<multiply(num1,num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!
int sumOfNumbers(int num){
		
		if(num != 0){
			num += sumOfNumbers(num-1);
			
		}
		return num;
	}

	bool isMember(int* array, int value, int size){
		if(size != 0){
		if(value==array[size]){return  true;
		}else{
			isMember(array, value, size -1);
			
		}			
		}
		if(size ==0){return false;}
			
	}
	
void stringReverser(string temp, int size){
		
		if(size != -1){	
			cout<< temp[size];
			stringReverser(temp,size-1);
		}
		
	}
	
	
	bool isPalindrome(string temp){
		if(temp.length() == 1){return true;}
		
			if(temp[0] == temp[temp.length()-1]){
				isPalindrome(temp.substr(1,temp.length()-2));
				return true;
			}
		return false;
		}
	
int multiply(int x, int y){
		
		if(x!=1){
		y +=multiply(x-1,y);		
		}
		return y;
	}