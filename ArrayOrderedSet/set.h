#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Set{
	private:
		char *m_Data;  // the pointer for character data array
		int m_Size;      // the number of elements in set
		int m_Max;       // space preserved for set
	private:
		void Init();     // initialization
		void Free();     // free the dynamic memory
		inline bool InvalidateIndex(int nIndex);  // judge the invalidation for index
	public:
		Set();        // default construct func.
		Set(int nSize, char dValue = 0);  // construct func. for setting the size of set, default dValue
		Set(const Set& arr);  // copy Construct func.
		Set& operator=(const Set& arr);  // copy assignmet operator
		~Set();       // destruct func.
		
		void isSub(const Set& arr); 
		void Print();    // print all the elements in set
		int GetSize();   // get the size of set
		void FindElem(char searchElem); // Search for a particular element
		void StoreElem(); //Store all elements of the set in an txt file
		bool IsEqual(const Set& arr); //Determine wheter two sets are equal
		bool IsEmpty(); // Determine wheter this set is empty
		Set& Intersection(const Set& arr); //find the intersection of two sets
		Set& Union(const Set& arr); //find the Union of two sets
		Set& Complement(const Set& arr); //find the complement of the set
		char GetMaxElem(); // Get the max value element in the set 
		void SetSize(int nSize);  // func. for set resize
		char GetAt(int nIndex);  // Get element at a particular position
		void RemoveRemItem(char remitem); // remove a particular item from the set
		void PushBack(char dValue);  // add a new value to the set and sort it
		void RemoveAt(int nIndex);     // Remove an element at a particular position
};

void Set::Init(){
	m_Size = 0;   // default no element in set
	m_Max = 1;
	m_Data = new char[m_Max];
}

void Set::Free(){
	delete [] m_Data;
}

bool Set::InvalidateIndex(int nIndex){
	if(nIndex>=0 && nIndex<m_Size)
		return false;
	else
		return true;
}

// default construct func.
Set::Set(){
	Init();
}

// construct func.
Set::Set(int nSize, char dValue){
	if(nSize == 0)
		Init();
	else{
		m_Size = nSize;
		m_Max = nSize*2;
		m_Data = new char[m_Max];
		//cout << "Please input the elements for set creation." << endl; 
		for(int i=0; i<nSize; ++i){
			char elem;
			cin >> elem;
			m_Data[i] = elem;
		}
		//sort the set 
		for(int i=0; i<m_Size; i++){
	        for(int j=i; j<m_Size; j++){
	            if(m_Data[j] < m_Data[i]){
	                swap(m_Data[i], m_Data[j]);
	            }
	        }
	    }
	    cout << "Set creation finished!" << endl;
	}
}

// copy construct func.
Set::Set(const Set& arr){
	//copy private pramaters
	m_Size = arr.m_Size;  
	m_Max = arr.m_Max;
	//copy contents in array
	m_Data = new char[m_Max]; 
	memcpy(m_Data, arr.m_Data, m_Size*sizeof(char));
}

// copy construction operator
Set& Set::operator=(const Set& arr){
	//self assigned
	if(this == &arr)  
		return *this;
	m_Size = arr.m_Size;
	m_Max = arr.m_Max;
	
	char *m_Temp = new char[m_Max];
	memcpy(m_Temp, arr.m_Data, m_Size*sizeof(char));
	delete [] m_Data;
	m_Data = m_Temp;
	return *this;
}

// destruction func.
Set::~Set(){
	Free();
}

// Print the set
void Set::Print(){
	ofstream fout("file/result.txt", ios::app);
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
	fout.close();
}

// Get the size of set
int Set::GetSize(){
	return m_Size;
}


// Serach for a particular element
void Set::FindElem(char searchElem){
	ofstream fout("file/result.txt", ios::app);
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
	fout.close();
}

void Set::isSub(const Set& arr){
	ofstream fout("file/result.txt", ios::app);
	bool flag = true;
	for(int i = 0; i< m_Size; i++){
		int j;
		for(j = 0; j < arr.m_Size; j++){
			if(m_Data[i] == arr.m_Data[j]) break;
		}
		if(j == arr.m_Size){
			flag = false;
			break;
		}
	}
	if(flag == false) 
		fout << "Mset is the subset of Nset." << endl;
	else
		fout << "Mset is not the subset of Nset." << endl;
	fout.close();
}

// Store all elements of the set in an txt file
void Set::StoreElem(){
	ofstream fout1("file/Sset.txt");
    for(int i = 0 ; i < m_Size; i++){
        fout1 << m_Data[i] << " ";
    } 
    fout1.close();
    ofstream fout("file/result.txt", ios::app);
	fout << "Sset elements are stored in file/Sset.txt" << endl; 
	fout.close();
} 


// Determine wheter two sets are equal
bool Set::IsEqual(const Set& arr){
	if(this == &arr) return true;
	
	if(m_Size != arr.m_Size) return false;
	int i;
	for(i=0; i<m_Size; i++){
		if(m_Data[i] != arr.m_Data[i]) break;
	}
	if(i < m_Size) return false;
	else return true;
}

// Determine wheter this set is empty
bool Set::IsEmpty(){
	if(m_Size == 0) return true;
	else return false;
}

// find the intersection of two sets
Set& Set::Intersection(const Set& arr){
	//self assigned
	if(this == &arr)  
		return *this;
	Set Iset;
	for(int i =0; i < m_Size; i++){
		for(int j = 0; j < arr.m_Size; j++){
			if(m_Data[i] == arr.m_Data[j]){
				Iset.PushBack(arr.m_Data[j]);
				break;
			}
		}
	}
	return Iset;
} 

// find the Union of two sets
Set& Set::Union(const Set& arr){
	Set uni;
	for(int i = 0; i< arr.m_Size; i++){
		uni.PushBack(arr.m_Data[i]);
	}
	for(int i = 0; i<m_Size; i++){
		int j;
		for(j = 0; j < uni.m_Size; j++){
			if(m_Data[i] == uni.m_Data[j]) break;
		}
		if(j == uni.m_Size) uni.PushBack(m_Data[i]);
	}
	return uni;
}

//find the complement of the set
Set& Set::Complement(const Set& arr){
	Set comp;
	for(int i = 0; i < arr.m_Size; i++){
		int j;
		for(j = 0; j < m_Size; j++){
			if(arr.m_Data[i] == m_Data[j]) break;
		}
		if(j == m_Size) {
			comp.PushBack(arr.m_Data[i]);
		}
	}
	return comp;
}

// Get the max value element in the set
char Set::GetMaxElem(){
	char max = m_Data[m_Size-1];
	return max;
}  

// remove a particular item from the set
void Set::RemoveRemItem(char remitem){
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

// set resize
void Set::SetSize(int nSize){
	// cut the array
	if(nSize < m_Size){ 
		for(int i=nSize; i<m_Size; ++i)
			m_Data[i] = 0;
	}
	// assign new elements with 0
	if(m_Size<=nSize && nSize<=m_Max){ 
		for(int i=m_Size; i<nSize; ++i)
			m_Data[i] = 0;
	}
	// reallocate memory
	if(nSize > m_Max){   
		m_Max = nSize*2;
		char *temp = new char[m_Max];
		memcpy(temp, m_Data, m_Size*sizeof(char));
		for(int i=m_Size; i<nSize; ++i)
			temp[i] = 0;
		delete [] m_Data;
		m_Data = temp;
	}
	//set size
	m_Size = nSize; 
}

// Get element at a particular position
char Set::GetAt(int nIndex){
	if(InvalidateIndex(nIndex)){
		cout << "Error: the index of GetAt is invalid!" << endl;
		exit(0);
	}
	return m_Data[nIndex];
}

// add a new value to the set and sort it
void Set::PushBack(char dValue){
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
	
	for(int i=0; i<m_Size; i++){
        for(int j=i; j<m_Size; j++){
            if(m_Data[j] < m_Data[i]){
                swap(m_Data[i], m_Data[j]);
            }
        }
    }
}

// Remove an element at a particular position
void Set::RemoveAt(int nIndex){
	if(InvalidateIndex(nIndex)){
		cout << "Error: the index of DeleteAt is invalid." << endl;
		exit(0);
	}
	else{	
		for(int i=nIndex; i<m_Size; ++i)
			m_Data[i] = m_Data[i+1];
		m_Data[m_Size-1] = 0;
		--m_Size;
	}
}


