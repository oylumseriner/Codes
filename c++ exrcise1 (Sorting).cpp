#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <chrono>
#include <limits>
using namespace std;
#define MAXSIZE 999999
//Merge for increasing order
void merge(int*& arr, int first, int mid, int last){
        int size = last - first +1;
        int tempArray[MAXSIZE];
        int first1 = first;
        int last1 = mid;
        int first2 = mid+1;
        int last2 = last;
        int index = first1;
        for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
                if (arr[first1] < arr[first2]) {
                        tempArray[index] = arr[first1];
                        ++first1;
                }
                else {
                        tempArray[index] = arr[first2];
                        ++first2;
                }
        }
        for(; first1 <= last1; ++first1, ++index){
                tempArray[index] = arr[first1];
        }
        for(; first2 <= last2; ++first2, ++index){
                tempArray[index] = arr[first2];
        }
        for(index = first; index <= last; ++index){
                arr[index] = tempArray[index];
        }

}



//Merge sort for increasing order
void mergeSort(int*& arr, int first, int last){
        int mid;
        if(first < last){
                mid = (first+last)/2;
                mergeSort(arr, first, mid);
                mergeSort(arr, mid+1, last);
                merge(arr, first, mid, last);
        }


}

//Insertion sort for increasing order
void insertionSort(int*& arr, int n){
        int temp, i, j;
        for(i = 1; i < n; i++){
                temp = arr[i];
                for(j = i; j > 0 && temp < arr[j-1]; j--){
                        arr[j] = arr[j-1];

                }
                arr[j] = temp;
        }

}

int main(){
        int size = 1000; //Report
        vector<int> randVector;
        int* randArr = new int[size];

        clock_t begin;
        clock_t end;
        double duration;

        fstream inputFile;
        ofstream MyFile("output10.txt"); //Report
        int k = 0;
        inputFile.open("Random10.txt",ios::in); //Report
        //records first time

        
        
        if(inputFile.is_open()){
                string line;
                while(getline(inputFile, line)){
                        randVector.push_back(stoi(line));
                }
                inputFile.close();
        }
        for(int i = 0; i < size; i++){
                randArr[i] = randVector[i];
        }
        randVector.clear();
        //records second time
        
     
        //Merge sort for increasing order
        if ((begin = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        insertionSort(randArr, size);

        if ((end = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
		  cout << "Time passed in insertion sort for random input: " << duration << endl;

        MyFile << "Array after insertion sort: " << endl;
        for(int i = 0; i < size; i++){
                MyFile << randArr[i] << endl;
        }

        
        inputFile.open("Sorted10.txt",ios::in);
        if(inputFile.is_open()){
                string line;
                while(getline(inputFile, line)){
                        randVector.push_back(stoi(line));
                }
                inputFile.close();
        }
        for(int i = 0; i < size; i++){
                randArr[i] = randVector[i];
        }
        randVector.clear();
        if ((begin = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        insertionSort(randArr, size);

        if ((end = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
		cout << "Time passed in insertion sort for sorted input: " << duration << endl;

        MyFile << "Array after insertion sort: " << endl;
        for(int i = 0; i < size; i++){
                MyFile << randArr[i] << endl;
        }

        inputFile.open("Reverse10.txt",ios::in);  //Report

        if ((begin = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        if(inputFile.is_open()){
                string line;
                while(getline(inputFile, line)){
                        randVector.push_back(stoi(line));
                }
                inputFile.close();
        }
        for(int i = 0; i < size; i++){
                randArr[i] = randVector[i];
        }
        randVector.clear();
        if ((begin = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        insertionSort(randArr, size);

        if ((end = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
		cout << "Time passed in insertion sort for reversed input: " << duration << endl;
    
        MyFile << "Array after insertion sort: " << endl;
        for(int i = 0; i < size; i++){
                MyFile << randArr[i] << endl;
        }
        //Merge sort for increasing order
        inputFile.open("Random10.txt",ios::in); //Report
        //records first time

        
        if(inputFile.is_open()){
                string line;
                while(getline(inputFile, line)){
                        randVector.push_back(stoi(line));
                }
                inputFile.close();
        }
        for(int i = 0; i < size; i++){
                randArr[i] = randVector[i];
        }
        //records second time
        randVector.clear();
     
        //Merge sort for increasing order
        if ((begin = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        mergeSort(randArr, 0, size-1);

        if ((end = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
		  cout << "Time passed in merge sort for random input: " << duration << endl;

        MyFile << "Array after merge sort: " << endl;
        for(int i = 0; i < size; i++){
                MyFile << randArr[i] << endl;
        }

        
        inputFile.open("Sorted10.txt",ios::in);
        if(inputFile.is_open()){
                string line;
                while(getline(inputFile, line)){
                        randVector.push_back(stoi(line));
                }
                inputFile.close();
        }
        for(int i = 0; i < size; i++){
                randArr[i] = randVector[i];
        }
        randVector.clear();
        if ((begin = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        mergeSort(randArr, 0, size-1);

        if ((end = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
		cout << "Time passed in merge sort for sorted input: " << duration << endl;

        MyFile << "Array after merge sort: " << endl;
        for(int i = 0; i < size; i++){
                MyFile << randArr[i] << endl;
        }

        inputFile.open("Reverse10.txt",ios::in);  //Report
        

        if ((begin = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        if(inputFile.is_open()){
                string line;
                while(getline(inputFile, line)){
                        randVector.push_back(stoi(line));
                }
                inputFile.close();
        }
        for(int i = 0; i < size; i++){
                randArr[i] = randVector[i];
        }
        randVector.clear();
        if ((begin = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        mergeSort(randArr, 0, size-1);

        if ((end = clock ()) == -1)
                std::cerr << "clock err" << std::endl;
        duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
		cout << "Time passed in merge sort for reversed input: " << duration << endl;
        MyFile << "Array after merge sort: " << endl;
        for(int i = 0; i < size; i++){
                MyFile << randArr[i] << endl;
        }


        MyFile.close();
        return 0;
}

