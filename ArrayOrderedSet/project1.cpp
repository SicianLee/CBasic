#include <iostream>
#include <fstream>
using namespace std;

ofstream fout("file/result.txt");

// read data from txt file and create a new set 
void CreateSet(int &m_Size, int &m_Max, char *m_Data, string filepath);
// add a new value to the set and sort it
void PushBack(int &m_Size, int &m_Max, char *m_Data, char dValue);
// Print the set
void Print(int m_Size, char m_Data[]);
// Serach for a particular element
void FindElem(int m_Size, char* m_Data, char searchElem);
// Get the size of set
int GetSize(char* m_Data);
// Determine wheter Mset is the subset of Nset
void IsSub(int m_Size, char* m_Data, int n_Size, char* n_Data);
// Determine wheter this set is empty
bool IsEmpty(char* m_Data);
// Store all elements of the set in an txt file
void StoreElem(char* m_Data, int m_Size, string filepath);
// Determine whether two sets are equal
bool IsEqual(int m_Size, char* m_Data, int n_Size, char* n_Data);
// find the intersection of two sets
void Intersection(int m_Size, char* m_Data, int n_Size, char* n_Data, int& i_Size, int& i_Max, char* i_Data);
// find the Union of two sets
void Union(int m_Size, char* m_Data, int n_Size, char* n_Data, int& u_Size, int& u_Max, char* u_Data);
//find the complement of the set
void Complement(int m_Size, char* m_Data, int n_Size, char* n_Data, int& u_Size, int& u_Max, char* u_Data);
// Get the max value element in the set
char GetMaxElem(int m_Size, char* m_Data);
// remove a particular item from the set
void RemoveRemItem(int& m_Size, char* m_Data, char remitem);
// Remove an element at a particular position
void RemoveAt(int m_Size, char* m_Data, int nIndex);
// copy n_Data to m_Data
char* CopySet(int& m_Size, int& m_Max, char* m_Data, int n_Size, int n_Max, char* n_Data);
// find the relative difference of two sets
void RelativeDiff(int m_Size, char* m_Data, int n_Size, char* n_Data);

int main(){
	
	fout << "1. Create a set called Sset" << endl;    
	int s_Size = 0;     // the number of elements in set
	int s_Max = 100;      // space preserved for set
	char *Sset = new char[s_Max]; // the pointer for character data array
	CreateSet(s_Size, s_Max, Sset, "file/Sset.txt");
	fout << "Sset create finished!" << endl;
	fout << endl;
	
	//------------------------------------------------------------
	fout << "2. Print the contents of Sset" << endl;
	Print(s_Size, Sset);
	fout << endl ;
	
	//------------------------------------------------------------
	fout << "3. Search Sset for a particular element t" << endl;
	FindElem(s_Size, Sset, 't');
	fout << endl;
	
	//------------------------------------------------------------
	fout << "4. Find the number of elements in Sset" << endl;
	fout << GetSize(Sset) << endl;
	fout << endl;
	
	//------------------------------------------------------------
	fout << "5. Boolean subset operation for Mset and Nset" << endl;
	//create Mset
	int m_Size = 0;     
	int m_Max = 100;      
	char *Mset = new char[m_Max]; 
	CreateSet(m_Size, m_Max, Mset, "file/Mset.txt");
	fout << "Mset create finished!" << endl;
	fout << "Print Mset: ";
	Print(m_Size, Mset);
	//create Nset
	int n_Size = 0;     
	int n_Max = 100;      
	char *Nset = new char[n_Max]; 
	CreateSet(n_Size, n_Max, Nset, "file/Nset.txt");
	fout << "Nset create finished!" << endl;
	fout << "Print Nset: ";
	Print(n_Size, Nset);
	IsSub(m_Size, Mset, n_Size, Nset);
	fout << endl << endl;
	
	//------------------------------------------------------------
	fout << "6. Determine wheter Sset is empty" << endl;
	bool isEmp = IsEmpty(Sset);
	if(isEmp) 
		fout << "Sset is empty." << endl;
	else fout << "Sset is not empty." << endl;
		fout << endl;
	
	//------------------------------------------------------------
	fout << "7. Store elements of Sset in a txt file" << endl;
	StoreElem(Sset, s_Size, "file/storeSset.txt");
	fout << endl;
	
	//------------------------------------------------------------
	fout << "8. Create a new set Tset to compare with Sset" << endl;
	//create Tset
	int t_Size = 0;     
	int t_Max = 100;      
	char *Tset = new char[t_Max]; 
	CreateSet(t_Size, t_Max, Tset, "file/Tset.txt");
	fout << "Tset create finished!" << endl;
	fout << "Print Tset: ";
	Print(t_Size, Tset);
	fout << "Print Sset: ";
	Print(s_Size, Sset);
	if(IsEqual(t_Size, Tset, s_Size, Sset))
		fout << "Sset and Tset are equal." << endl;
	else fout << "Sset and Tset are not equal." << endl;
	fout << endl;
	
	//------------------------------------------------------------
	fout << "9. Find the intersection set Iset of Aset and Bset." << endl;
	//create Aset
	int a_Size = 0;     
	int a_Max = 100;      
	char *Aset = new char[a_Max]; 
	CreateSet(a_Size, a_Max, Aset, "file/Aset.txt");
	fout << "Aset create finished!" << endl;
	fout << "Print Aset: ";
	Print(a_Size, Aset);
	//create Bset
	int b_Size = 0;     
	int b_Max = 100;      
	char *Bset = new char[b_Max]; 
	CreateSet(b_Size, b_Max, Bset, "file/Bset.txt");
	fout << "Bset create finished!" << endl;
	fout << "Print Bset: ";
	Print(b_Size, Bset);
	//create Iset
	int i_Size = 0;     
	int i_Max = 100;      
	char *Iset = new char[i_Max];
	Intersection(a_Size, Aset, b_Size, Bset, i_Size, i_Max, Iset);
	if(IsEmpty(Iset))
		fout << "Iset is empty!" << endl;
	else{
		fout << "Print Iset: ";
		Print(i_Size, Iset);   
	}
	StoreElem(Iset, i_Size, "file/Iset.txt");
	fout << endl;
	
	//------------------------------------------------------------
	fout << "10. Find the Union set Unset of Cset and Dset." << endl;
	//create Cset
	int c_Size = 0;     
	int c_Max = 100;      
	char *Cset = new char[c_Max]; 
	CreateSet(c_Size, c_Max, Cset, "file/Cset.txt");
	fout << "Cset create finished!" << endl;
	fout << "Print Cset: ";
	Print(c_Size, Cset);
	//create Dset
	int d_Size = 0;     
	int d_Max = 100;      
	char *Dset = new char[d_Max]; 
	CreateSet(d_Size, d_Max, Dset, "file/Dset.txt");
	fout << "Dset create finished!" << endl;
	fout << "Print Dset: ";
	Print(d_Size, Dset);
	//create Unset
	int un_Size = 0;     
	int un_Max = 100;      
	char *Unset = new char[un_Max];
	Union(c_Size, Cset, d_Size, Dset, un_Size, un_Max, Unset);
	if(IsEmpty(Unset))
		fout << "Unset is empty!" << endl;
	else{
		fout << "Print Unset: ";
		Print(un_Size, Unset);
	}
	StoreElem(Unset, un_Size, "file/Unset.txt");
	fout << endl;
	
	//------------------------------------------------------------
	fout << "11. Find the complement set Aset_ of Universal set Uset and Aset." << endl;
	//create Uset
	int u_Size = 0;     
	int u_Max = 100;      
	char *Uset = new char[u_Max]; 
	CreateSet(u_Size, u_Max, Uset, "file/Uset.txt");
	fout << "Uset create finished!" << endl;
	fout << "Print Uset: ";
	Print(u_Size, Uset);
	fout << "Print Aset: ";
	Print(a_Size, Aset);
	//create Aset_
	int a_Size_ = 0;     
	int a_Max_ = 100;      
	char *Aset_ = new char[a_Max_]; 
	Complement(a_Size, Aset, u_Size, Uset, a_Size_, a_Max_, Aset_);
	if(IsEmpty(Aset_))
		fout << "Aset_ is empty!" << endl;
	else{
		fout << "Print Aset_: ";
		Print(a_Size_, Aset_);
	}
	StoreElem(Unset, un_Size, "file/Aset_.txt");
	fout << endl;
	
	//------------------------------------------------------------
	fout << "12. Find the maximum value in Unset" << endl;
	if(GetSize(Unset) == 0)
		fout << "The Unset is empty!" << endl;
	else{
		char max = GetMaxElem(un_Size, Unset);
		fout << "Print Unset: ";
		Print(un_Size, Unset);
		fout << "The max element in Unset is " << max << endl;
	}
	fout << endl;
	
	//------------------------------------------------------------
	fout << "13. Add a new value z to Dset and keep it ordered." << endl;
	char newval = 'z';
	fout << "Print the prior Dset: ";
	Print(d_Size, Dset);
	PushBack(d_Size, d_Max, Dset, newval);
	fout << "Print the after Dset: ";
	Print(d_Size, Dset);
	fout << endl;
	
	//------------------------------------------------------------	
	fout << "14. Remove an item remitem b from Cset." << endl;
	char remitem = 'm';
	fout << "Print the prior Cset: ";
	Print(c_Size, Cset);
	fout << "Input the remitem: ";
	RemoveRemItem(c_Size, Cset, remitem);
	fout << "Print the after Cset: ";
	Print(c_Size, Cset);
	fout << endl;
	
	//------------------------------------------------------------
	fout << "15. Remove the first element from Mset." << endl;
	fout << "Print the prior Mset: ";
	Print(m_Size, Mset);
	RemoveAt(m_Size, Mset, 0);
	fout << "Print the after Mset: ";
	Print(m_Size, Mset);
	fout << endl;
	
	//------------------------------------------------------------
	fout << "16. Remove the last element from Bset." << endl;
	fout << "Print the prior Bset: ";
	Print(b_Size, Bset);
	RemoveAt(b_Size, Bset, GetSize(Bset)-1);
	fout << "Print the after Bset: ";
	Print(b_Size, Bset);
	fout << endl;
	
	//------------------------------------------------------------
	fout << "17. Make a copy of Uset and call it CUset." << endl;
	fout << "Print the prior Uset: ";
	Print(u_Size, Uset);
	//create CUset
	int cu_Size = 0;     
	int cu_Max = 100;      
	char *CUset = new char[cu_Max]; 
	CUset = CopySet(cu_Size, cu_Max, CUset, u_Size, u_Max, Uset);
	fout << "Print the copy CUset: ";
	Print(cu_Size, CUset);
	StoreElem(CUset, cu_Size, "file/CUset.txt");
	fout << "Print the after Uset: ";
	Print(u_Size, Uset);
	fout << endl;
	
	//------------------------------------------------------------
	fout << "18. Find the relative difference of Aset and Bset." << endl;
	fout << "Print Aset: ";
	Print(a_Size, Aset);
	fout << "Print Bset: ";
	Print(b_Size, Bset);
	RelativeDiff(a_Size, Aset, b_Size, Bset);
	fout << endl;
	cout << "Execution Finish! See result in file/result.txt" << endl;
	system("pause");
	return 0;
}

void CreateSet(int &m_Size, int &m_Max, char *m_Data ,string filepath){
	ifstream fin(filepath.c_str());
	int size;
	fin.seekg(0, ios::end);
    streampos fp = fin.tellg();
	if(int(fp) == 0) {
		fout << "Empty file, please store an array in the file." << endl;
		return;
	}
	fin.seekg(0, ios::beg);
	fin >> size;
	for(int i=0; i<size; i++){
		char temp;
		fin >> temp;
		PushBack(m_Size, m_Max, m_Data,temp);
	}
}

// add a new value to the set and sort it
void PushBack(int &m_Size, int &m_Max, char *m_Data, char dValue){
	if(m_Size < m_Max){
		m_Data[m_Size] = dValue;
		//cout << "m_Data[m_Size] =" << m_Data[m_Size] << endl;
	}
	else{
		m_Max = m_Max*2;
		char* temp = new char[m_Max];
		memcpy(temp, m_Data, m_Size*sizeof(char));
		delete [] m_Data;
		m_Data = temp;
		m_Data[m_Size] = dValue;
		//cout << "m_Data[m_Size] =" << m_Data[m_Size] << endl;
	}
	++m_Size;  
	
	// sort the array 
	for(int i=0; i<m_Size; i++){
		for(int j=i; j<m_Size; j++){
			if(m_Data[j] < m_Data[i]){
				swap(m_Data[i], m_Data[j]);
			}
		}
	}
}

// Print the set
void Print(int m_Size, char m_Data[]){
	if(m_Size == 0){
		//cout << "The set is empty!" << endl;
		fout << "The set is empty!" << endl;
		return;
	}
	else{
		for(int i=0; i<m_Size; ++i)
			fout << m_Data[i] << " ";
		fout << endl;
	}
}

// Serach for a particular element
void FindElem(int m_Size, char* m_Data, char searchElem){
	int i;
	if(m_Size == 0){
		fout << "The set is empty, search failed!" << endl;
		fout.close();
		return;
	}
	for(i=0; i<m_Size; i++){
		if (searchElem == m_Data[i]) break;
	}
	if(i == m_Size)
		fout << "The element isn't exsited in the set!" << endl;
	else
		fout << "The No. " << i << " element of the set is " << searchElem << endl;
}

// Get the size of set
int GetSize(char* m_Data){
	int i = 0;
	while(m_Data[i] != '\0') i++;
	return i;
}

// Determine wheter Mset is the subset of Nset
void IsSub(int m_Size, char* m_Data, int n_Size, char* n_Data){
	bool flag = true;
	if(m_Size == 0){
		fout << "Mset is empty set, so it is the subset of Nset" << endl;
		return;
	}	
	for(int i = 0; i< m_Size; i++){
		int j;
		for(j = 0; j < n_Size; j++){
			if(m_Data[i] == n_Data[j]) break;
		}
		if(j == n_Size){
			flag = false;
			break;
		}
	}
	if(flag == true) 
		fout << "Mset is the subset of Nset." << endl;
	else
		fout << "Mset is not the subset of Nset." << endl;
}

// Determine wheter this set is empty
bool IsEmpty(char* m_Data){
	if(m_Data[0] == '\0') return true;
	else return false;
}

// Store all elements of the set in an txt file
void StoreElem(char* m_Data, int m_Size, string filepath){
	ofstream fout1(filepath.c_str());
	fout1 << m_Size << " ";
    for(int i = 0 ; i < m_Size; i++){
        fout1 << m_Data[i] << " ";
    } 
    fout1.close();
	fout << "Elements in the set have been stored in " << filepath.c_str() << endl; 
} 

// Determine whether two sets are equal
bool IsEqual(int m_Size, char* m_Data, int n_Size, char* n_Data){	
	if(m_Size != n_Size) return false;
	int i;
	for(i=0; i<m_Size; i++){
		if(m_Data[i] != n_Data[i]) break;
	}
	if(i < m_Size) return false;
	else return true;
}

// find the intersection of two sets
void Intersection(int m_Size, char* m_Data, int n_Size, char* n_Data, int& i_Size, int& i_Max, char* i_Data){
	for(int i =0; i < m_Size; i++){
		for(int j = 0; j < n_Size; j++){
			if(m_Data[i] == n_Data[j]){
				PushBack(i_Size, i_Max, i_Data, n_Data[j]);
				break;
			}
		}
	}
} 

// find the Union of two sets
void Union(int m_Size, char* m_Data, int n_Size, char* n_Data, int& u_Size, int& u_Max, char* u_Data){
	for(int i = 0; i< n_Size; i++){
		PushBack(u_Size, u_Max, u_Data, n_Data[i]);
	}
	for(int i = 0; i<m_Size; i++){
		int j;
		for(j = 0; j < u_Size; j++){
			if(m_Data[i] == u_Data[j]) break;
		}
		if(j == u_Size) 
			PushBack(u_Size, u_Max, u_Data, m_Data[i]);
	}
}

//find the complement of the set
void Complement(int m_Size, char* m_Data, int n_Size, char* n_Data, int& u_Size, int& u_Max, char* u_Data){
	for(int i = 0; i < n_Size; i++){
		int j;
		for(j = 0; j < m_Size; j++){
			if(n_Data[i] == m_Data[j]) break;
		}
		if(j == m_Size) {
			PushBack(u_Size, u_Max, u_Data, n_Data[i]);
		}
	}
}

// Get the max value element in the set
char GetMaxElem(int m_Size, char* m_Data){
	char max = m_Data[m_Size-1];
	return max;
}  

// remove a particular item from the set
void RemoveRemItem(int& m_Size, char* m_Data, char remitem){
	int i;
	for(i=0; i<m_Size; i++){
		if(m_Data[i] == remitem) break;
	}
	if(i == m_Size) 
		cout << "Remitem isn't existed in the set." <<endl;
	else{
		for(i; i<m_Size; ++i)
			m_Data[i] = m_Data[i+1];
		m_Data[m_Size-1] = 0;
		--m_Size;
	} 
}

// Remove an element at a particular position
void RemoveAt(int m_Size, char* m_Data, int nIndex){
	if(nIndex < 0 || nIndex >= m_Size){
		cout << "Error: the index of DeleteAt is invalid." << endl;
		return;
	}
	else{	
		for(int i=nIndex; i<m_Size; ++i)
			m_Data[i] = m_Data[i+1];
		m_Data[m_Size-1] = 0;
		--m_Size;
	}
}

// copy n_Data to m_Data
char* CopySet(int& m_Size, int& m_Max, char* m_Data, int n_Size, int n_Max, char* n_Data){
	m_Size = n_Size;
	m_Max = n_Max;	
	char *m_Temp = new char[m_Max];
	for(int i=0 ; i<m_Size; i++){
		char temp = n_Data[i];
		m_Temp[i] = temp;
	}
	delete [] m_Data;
	return m_Temp;
} 

// find the relative difference of two sets
void RelativeDiff(int m_Size, char* m_Data, int n_Size, char* n_Data){
	float max = m_Size + 0.0;
	if(n_Size > max) max = n_Size + 0.0;
	if(max == 0){
		fout <<  "The relative difference between the two sets is 0." << endl;
		return;
	}
	float samecnt = 0.0;
	for(int i =0; i < m_Size; i++){
		for(int j = 0; j < n_Size; j++){
			if(m_Data[i] == n_Data[j]){
				samecnt += 1.0; 
				break;
			}
		}
	}
	float relDiff = samecnt / max;
	fout << "The relative difference between the two sets is " << relDiff << endl;	
	
} 