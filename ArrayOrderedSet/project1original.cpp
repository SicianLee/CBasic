#include <iostream>
#include "set.h"
using namespace std;

int main(){
	int num;
	ofstream fout("file/result.txt", ios::app);
	fout << "1. Create a set called Sset" << endl;
	
	Set Sset;
	ifstream fin("file/Sset.txt");
	for(int i = 0; i < 5; i++){
		char temp;
		fin >> temp;
		Sset.PushBack(temp);
	}
	fin.close();
	fout << "create finished!" << endl;
	fout << endl;
	
	fout << "2. Print the contents of Sset" << endl;
	//fout.close();
	//cout << "2. Print the contents of Sset" << endl;
	Sset.Print();
	fout << endl ;
	
	//ofstream fout("file/result.txt", ios::app);
	fout << "3. Search Sset for a particular element t" << endl;
	//fout.close();
	//cout << "Please input a character to be searched: ";
	//char searchelem;
	//cin >> searchelem;
	Sset.FindElem('t');
	fout << endl;
	
	fout << "4. Find the number of elements in Sset" << endl;
	fout << Sset.GetSize() << endl;
	fout << endl;
	
	fout << "5. Boolean subset operation for Mset and Nset" << endl;
	Set Mset;
	ifstream fin7("file/Mset.txt");
	for(int i = 0; i < 6; i++){
		char temp;
		fin7 >> temp;
		Mset.PushBack(temp);
	}
	Mset.Print();
	fin7.close();
	Set Nset;
	ifstream fin8("file/Nset.txt");
	for(int i = 0; i < 8; i++){
		char temp;
		fin8 >> temp;
		Nset.PushBack(temp);
	}
	Nset.Print();
	fin8.close();
	Mset.isSub(Nset);
	fout << endl << endl;
	
	fout << "6. Determine wheter Sset is empty" << endl;
	bool isEmp = Sset.IsEmpty();
	if(isEmp) 
		fout << "Sset is empty" << endl;
	else fout << "Sset is not empty" << endl;
		fout << endl;
	
	fout << "7. Store elements of Sset in a txt file" << endl;
	Sset.StoreElem();
	fout << endl;
	
	fout << "8. Create a new set Tset to compare with Sset" << endl;
	//cout << "Please input the number of elements in Tset: ";
	ifstream fin1("file/Tset.txt");
	Set Tset;
	for(int i = 0; i < 5; i++){
		char temp;
		fin1 >> temp;
		Tset.PushBack(temp);
	}
	fin1.close();
	//fout << "Print the elements in Tset: ";
	Tset.Print();
	if(Sset.IsEqual(Tset))
		fout << "Sset and Tset are equal." << endl;
	else fout << "Sset and Tset are not equal." << endl;
	fout << endl;
	
	fout << "9. Find the intersection set Iset of Aset and Bset." << endl;
	//cout << "Please input the number of elements in Aset: ";
	//cin >> num;
	//cout << "Please input the characters in Aset: ";
	ifstream fin2("file/Aset.txt");
	Set Aset;
	for(int i = 0; i < 5; i++){
		char temp;
		fin2 >> temp;
		Aset.PushBack(temp);
	}
	fin2.close();
	fout << "Print the elements in Aset: ";
	Aset.Print();
	//cout << "Please input the number of elements in Bset: ";
	//cin >> num;
	//cout << "Please input the characters in Bset: ";
	Set Bset;
	ifstream fin3("file/Bset.txt");
	for(int i = 0; i < 7; i++){
		char temp;
		fin3 >> temp;
		Bset.PushBack(temp);
	}
	fin3.close();
	fout << "Print the elements in Bset: ";
	Bset.Print();
	Set Iset(Aset.Intersection(Bset));
	if(Iset.IsEmpty())
		fout << "Iset is empty!" << endl;
	else{
		fout << "Print the elements in Iset: ";
		Iset.Print();   
	}
	fout << endl << endl;
	
	fout << "10. Find the Union set Unset of Cset and Dset." << endl;
	/*cout << "Please input the number of elements in Cset: ";
	cin >> num;
	cout << "Please input the characters in Cset: ";*/
	fout << "Print the elements in Cset: ";
	Set Cset;
	ifstream fin4("file/Cset.txt");
	for(int i = 0; i < 5; i++){
		char temp;
		fin4 >> temp;
		Cset.PushBack(temp);
	}
	fin4.close();
	Cset.Print();
	/*cout << "Please input the number of elements in Dset: ";
	cin >> num;
	cout << "Please input the characters in Dset: ";*/
	Set Dset;
	fout << "Print the elements in Dset: ";
	ifstream fin5("file/Dset.txt");
	for(int i = 0; i < 4; i++){
		char temp;
		fin5 >> temp;
		Dset.PushBack(temp);
	}
	fin5.close();
	Dset.Print();
	Set Unset = Cset.Union(Dset);
	if(Unset.IsEmpty())
		fout << "Unset is empty!" << endl;
	else{
		fout << "Print the elements in Unset: ";
		Unset.Print();
	}
	fout << endl << endl;
	
	fout << "11. Find the complement set Aset_ of Universal set Uset and Aset." << endl;
	Set Uset;
	ifstream fin6("file/Uset.txt");
	for(int i = 0; i < 7; i++){
		char temp;
		fin6 >> temp;
		Uset.PushBack(temp);
	}
	fin6.close();
	Uset.Print();
	Aset.Print();
	Set Aset_ = Aset.Complement(Uset);
	if(Aset_.IsEmpty())
		fout << "Aset_ is empty!" << endl;
	else{
		//fout << "Print the elements in Aset_: ";
		Aset_.Print();
	}
	fout << endl << endl;
	
	fout << "12. Find the maximum value in Unset" << endl;
	if(Unset.GetSize() == 0)
		fout << "The Unset is empty!" << endl;
	else{
		char max = Unset.GetMaxElem();
		fout << "The max element in Unset is " << max << endl;
	}
	fout << endl << endl;
	
	fout << "13. Add a new value z to Dset and keep it ordered." << endl;
	char newval = 'z';
	fout << "Print the prior Dset: ";
	Dset.Print();
	//cout << "Input a newval: ";
	//cin >> newval; 
	Dset.PushBack(newval);
	fout << "Print the after Dset: ";
	Dset.Print();
	fout << endl << endl;
		
	fout << "14. Remove an item remitem b from Cset." << endl;
	char remitem = 'b';
	fout << "Print the prior Cset: ";
	Cset.Print();
	fout << "Input the remitem: ";
	//cin >> remitem; 
	Cset.RemoveRemItem(remitem);
	fout << "Print the after Cset: ";
	Cset.Print();
	fout << endl << endl;
	
	fout << "15. Remove the first element from Mset." << endl;
	fout << "Print the prior Mset: ";
	Mset.Print();
	Mset.RemoveAt(0);
	fout << "Print the after Mset: ";
	Mset.Print();
	fout << endl << endl;
	
	fout << "16. Remove the last element from Bset." << endl;
	fout << "Print the prior Bset: ";
	Bset.Print();
	Bset.RemoveAt(Bset.GetSize()-1);
	fout << "Print the after Bset: ";
	Bset.Print();
	fout << endl << endl;
	
	fout << "17. Make a copy of Uset and call it CUset." << endl;
	fout << "Print the prior Uset: ";
	Uset.Print();
	Set CUset = Uset; 
	fout << "Print the copy CUset: ";
	CUset.Print();
	fout << "Print the after Uset: ";
	Uset.Print();
	fout << endl << endl;
	return 0;
}
