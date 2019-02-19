#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int iniArray[10000];
int sortedArray[10000];
clock_t start, finish;
double totaltime;

void printMenu();
void initArray();
void createArray();
void printArray();
void readiniArray();
void bubbleSort();
void selectionSort();
void insertSort();
void quickSort();
void quick_sort(int l, int r);
void shellSort();
//void sequentialExistSearch();
void sequentialSearch();
void binarySearch(int ind);
void cntEvenOdd();
void isIndexOccupied();
 
int main(){
    initArray();
    printMenu();
    createArray();
    readiniArray();
    printArray();
    bubbleSort();
    selectionSort();
    insertSort();
    quickSort();
    shellSort();
    sequentialSearch();
    binarySearch(1);
    binarySearch(2);
    binarySearch(3);
    cntEvenOdd();
    isIndexOccupied();
    cout << "Execution finish, see result in file/result.txt" << endl;
	system("pause");
    return 0;
}

void printMenu(){
    ofstream fout("file/result.txt");
    fout << "**************************************************" << endl;
    fout << "*                   Array Project                *" << endl;
    fout << "* 1.  Create initial array.                      *" << endl;
    fout << "* 2.  Readin initial array from file.            *" << endl;
    fout << "* 3.  Print initial array.                       *" << endl;
    fout << "* 4.  Bubble sort array.                         *" << endl;
    fout << "* 5.  Selection sort array.                      *" << endl;
    fout << "* 6.  Insert sort array.                         *" << endl;
    fout << "* 7.  Quick sort array.                          *" << endl;
    fout << "* 8.  Shell sort array.                          *" << endl;
    fout << "* 9.  Sequential search array.                   *" << endl;
    fout << "* 10. Binary search array.                       *" << endl;
    fout << "* 11. Count odd and even number in array.        *" << endl;
    fout << "* 12. Is the index occupied?                     *" << endl;
    fout << "**************************************************" << endl;
    fout.close();
}

void initArray(){
    for(int i = 0; i < 10000; i++){
        iniArray[i] = -1;
        sortedArray[i] = -1;
    }
}

void readiniArray(){
    ofstream fout("file/result.txt", ios::app);
    fout << endl << " 2.  Readin initial array from file.            " << endl;
    ifstream fin("file/iniArray.txt");
    fin.seekg(0, ios::end);
    streampos fp = fin.tellg();
    if(int(fp) == 0) fout << "Empty file, please create a new array." << endl;
    else {
        fin.seekg(0, ios::beg);
        for(int i = 0; i < 10000; i++){
            fin >> iniArray[i];
        }
        /*for(int i = 0; i < 10000; i++){
            cout << i << " " << iniArray[i] << endl;
        }*/
        fout << "Array readin finish." << endl << endl;
    }   
    fout.close();
}

void createArray(){
    srand((unsigned)time(NULL));
    ofstream fout1("file/result.txt", ios::app);
    ofstream fout("file/iniArray.txt");
    fout1 << endl << " 1.  Create initial array.                      " << endl;
    for(int i = 0 ; i < 10000; i++){
        iniArray[i] = rand();
        fout << iniArray[i] << " ";
        fout1 << iniArray[i] << " ";
    } 
    fout1 << "Array creation finished!" << endl << endl;   
}

void printArray(){
    ofstream fout("file/result.txt",ios::app);
    fout << endl << " 3.  Print initial array.                       " << endl;
    fout << "Array creation finished!" << endl;
    if(iniArray[0] == -1)
        fout << "Invalid operation, please create or readin an initial array." << endl;
    else {
        for(int i = 0; i < 10000; i++){
            fout << i << " " << iniArray[i] << endl;
        }
    } 
    fout << endl;
}

void bubbleSort(){
    ofstream fout1("file/result.txt",ios::app);
    fout1 <<endl << "4.  Bubble sort array.                         " << endl;
    for(int i = 0; i < 10000; i++){
        sortedArray[i] = iniArray[i];
    }
    fout1 << "befor sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    start = clock();
    int flag = 1;
    for(int i = 0; i < 9999; i++){
        if(flag == 0) break;
        flag = 0;
        for(int j = 9999; j >= i; j--){
            if(sortedArray[j] < sortedArray[j-1]){
                flag = 1;
                swap(sortedArray[j], sortedArray[j-1]);
            }
        }
    }
    finish = clock();
    totaltime = (double)(finish - start) / 1000000;
    ofstream fout("file/BubblesortedArray.txt");
    for(int i = 0 ; i < 10000; i++){
        fout << sortedArray[i] << " ";
    } 
    fout.close();
    fout1 << endl << endl << "-------------------------------------------------" << endl;
    fout1 << endl << "after sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    fout1 << endl << "cost " << totaltime << "sec to execute bubbleSort." << endl;
    fout1.close();
}

void selectionSort(){
    ofstream fout1("file/result.txt",ios::app);
    fout1 << endl << "5.  Selection sort array.                      " << endl;
    for(int i = 0; i < 10000; i++){
        sortedArray[i] = iniArray[i];
    }
    fout1 << "befor sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    start = clock();
    for(int i=0; i<10000; i++){
        for(int j=i; j<10000; j++){
            if(sortedArray[j] < sortedArray[i]){
                swap(sortedArray[i], sortedArray[j]);
            }
        }
    }
    finish = clock();
    ofstream fout("file/SelectionSortedArray.txt");
    for(int i = 0 ; i < 10000; i++){
        fout << sortedArray[i] << " ";
    } 
    fout.close();
    fout1 << endl << endl << "-------------------------------------------------" << endl;
    fout1 << endl << "after sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    totaltime = (double)(finish - start) / 1000000;
    fout1 << endl << "cost " << totaltime << "sec to execute selectionSort." << endl;
    fout1.close();
}

void insertSort(){
    ofstream fout1("file/result.txt",ios::app);
    fout1 << endl << "6.  Insert sort array.                         " << endl;
    for(int i = 0; i < 10000; i++){
        sortedArray[i] = iniArray[i];
    }
    fout1 << "befor sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    start = clock();
    for(int i=1; i<10000; i++){
        int flag = sortedArray[i];
        int j = i - 1;
        while(j >= 0 && flag < sortedArray[j]){
            sortedArray[j+1] = sortedArray[j];
            j--;
        }
        sortedArray[j+1] = flag;
    }
    finish = clock();
    ofstream fout("file/InsertSortedArray.txt");
    for(int i = 0 ; i < 10000; i++){
        fout << sortedArray[i] << " ";
    } 
    fout.close();
    fout1 << endl << endl << "-------------------------------------------------" << endl;
    fout1 << endl << "after sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    totaltime = (double)(finish - start) / 1000000;
    fout1 << endl << "cost " << totaltime << "sec to execute insertSort." << endl;
    fout1.close();
}

void quickSort(){
    ofstream fout1("file/result.txt",ios::app);
    fout1 << endl <<  "7.  Quick sort array.                          " << endl;
    for(int i = 0; i < 10000; i++){
        sortedArray[i] = iniArray[i];
    }
    fout1 << "befor sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    start = clock();
    quick_sort(0, 9999);
    finish = clock();
    ofstream fout("file/QuickSortedArray.txt");
    for(int i = 0 ; i < 10000; i++){
        fout << sortedArray[i] << " ";
    } 
    fout.close();
    ofstream fout2("file/sortedArray.txt");
    for(int i = 0 ; i < 10000; i++){
        fout2 << sortedArray[i] << " ";
    } 
    fout2.close();
    fout1 << endl << endl << "-------------------------------------------------" << endl;
    fout1 << endl << "after sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    totaltime = (double)(finish - start) / 1000000;
    fout1 << endl << "cost " << totaltime << "sec to execute quickSort." << endl;
    fout1.close();
}

void quick_sort(int l, int r){
    if(l < r){
        int i = l, j = r, flag = sortedArray[l];
        while(i < j){
            while(i < j && sortedArray[j] >= flag) j--;  
            if(i < j) 
                sortedArray[i++] = sortedArray[j];
            while(i < j && sortedArray[i] < flag) i++;  
            if(i < j) 
                sortedArray[j--] = sortedArray[i];
        }
        sortedArray[i] = flag;
        quick_sort(l, i - 1); 
        quick_sort(i + 1, r);
    }
}

void shellSort(){
    ofstream fout1("file/result.txt",ios::app);
    fout1 << endl << "8.  Shell sort array.                          " << endl;
    for(int i = 0; i < 10000; i++){
        sortedArray[i] = iniArray[i];
    }
    fout1 << "befor sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    start = clock();
    // Start with a big gap, then reduce the gap 
    for(int gap = 10000/2; gap > 0; gap /= 2){ 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for(int i = gap; i < 10000; i++){ 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = sortedArray[i]; 
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j; 
            for(j = i; j >= gap && sortedArray[j-gap] > temp; j -= gap) 
                sortedArray[j] = sortedArray[j-gap];  
            //  put temp (the original a[i]) in its correct location 
            sortedArray[j] = temp; 
        } 
    } 
    finish = clock();
    ofstream fout("file/sortedArray.txt");
    for(int i = 0 ; i < 10000; i++){
        fout << sortedArray[i] << " ";
    } 
    fout.close();
    fout1 << endl << endl << "-------------------------------------------------" << endl;
    fout1 << endl << "after sorted:" << endl;
    for(int i = 0; i < 10000; i++){
        fout1 << sortedArray[i] << " ";
    }
    totaltime = (double)(finish - start) / 1000000;
    fout1 << endl << "cost " << totaltime << "sec to execute shellSort." << endl;
    fout1.close();
}

/*void sequentialExistSearch(){
    int num;
    cout << endl << "Input the number to be searched: ";
    cin >> num;
    int i = 0;
    while(i < 10000){
        if(sortedArray[i] == num) break;
        else i++;
    }
    if(i == 10000) 
        cout << "This number is not existed." <<endl;
    else 
        cout << "The No." << i << " number of the list is " << sortedArray[i] << endl;
}*/

void sequentialSearch(){
    int num = 32750;
    ofstream fout("file/result.txt",ios::app);
    fout << endl << "9.  Sequential search array.                   " << endl;
    fout << 32750;
    start = clock();
    int i = 0, flag = 0;
    while(i < 10000){
        if(i < 9999 && sortedArray[i] < num && sortedArray[i+1] > num){
            flag = 1; break;
        }
        if(sortedArray[i] == num) break;
        i++;
    }
    if(flag == 1||i == 10000){
        fout << "This number is not existed." <<endl;
        finish = clock();
        totaltime = (double)(finish - start) / 1000000;
        fout << "cost " << totaltime << "sec to sequential search not existed number." << endl;
    }
    else{
        fout << endl << "The No." << i+1 << " number of the list is " << sortedArray[i] << endl;
        finish = clock();
        totaltime = (double)(finish - start) / 1000000;
        fout << endl << "cost " << totaltime << "sec to sequential search existed number." << endl;
    }
    fout.close();
}

void binarySearch(int ind){
    ofstream fout("file/result.txt",ios::app);
    fout << endl << "10. Binary search array.                       " << endl;
    int i, j ,num;
    if(ind == 1){
        i = 0; j = 3333;
        num = 897;
        fout << "(1). the upper part of the array." << endl;
    }
    else if(ind == 2){
        i = 3334; j = 6666;
        num = 1962;
        fout << "(2). the middle part of the array." << endl;
    }
    else if(ind == 3){
        i = 6667; j = 9999;
        num = 32750;
        fout << "(3). the lower part of the array." << endl;
    }
    else{
        fout << "Invalid input!" << endl;
        return;
    }
    
    fout << endl << "Input the number to be searched: ";
    fout << num;
    start = clock();
    while(i <= j){
        int middle = i + ((j - i) >> 1);
        if (sortedArray[middle] > num)
            j = middle - 1; 
        else if (sortedArray[middle] < num)
            i = middle + 1;
        else{
            fout << "The No." << middle+1 << " number of the list is " << sortedArray[middle] << endl;
            finish = clock();
            totaltime = (double)(finish - start) / 1000000;
            fout << "cost " << totaltime << "sec to binary search existed number." << endl;
            fout.close();
            return;
        }
    }
    fout << "This number is not existed." <<endl;
    finish = clock();
    totaltime = (double)(finish - start) / 1000000;
    fout << "cost " << totaltime << "sec to binary search not existed number." << endl;
    fout.close();
}

void cntEvenOdd(){
    ofstream fout("file/result.txt",ios::app);
    fout << endl <<  "11. Count odd and even number in array.        " << endl;
    fout << endl << "Input the number to be searched: ";
    int even = 0, odd = 0;
    for(int i = 0; i < 10000; i++){
        if(iniArray[i]%2 == 0) even += 1;
        else odd += 1;
    }
    fout << "The number of even value: " << even << endl;
    fout << "The number of odd value: " << odd << endl;
    fout.close();
}

void isIndexOccupied(){
    ofstream fout("file/result.txt",ios::app);
    fout << endl << "12. Is the index occupied?                     " << endl;
    int ind = 9870;
    fout << endl << "Input the index to be judged: ";
    fout << ind;
    if(ind < 0) 
        fout << "Invalid Index." << endl;
    else if(ind > 9999) 
        fout << "The index is empty." << endl;
    else if(iniArray[ind] == -1) 
        fout << "The index is empty." << endl;
    else fout << "The index is occupied." << endl;
    fout.close();
}