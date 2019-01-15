/*
NAME: ÝBRHAÝM
SURNAME: KARAHAN
NU:150160550
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include<time.h>
#include <stdlib.h>
using namespace std;

int current_size = 0; // currrent size increase when new element add to heap
int general_size = 100000; // numbers.csv has 2M line
int *numberArray = new int[general_size]; // creating 
int extractArray[10000]; // extractArray is created for keeping the extract value 

void maxHeapify(int numberArray[], int size, int index) // building heap according to biggest number
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && numberArray[left] < numberArray[largest]){ //  compresion of number
		largest = left;
	}

	if (right < size && numberArray[right] < numberArray[largest]){ // compresion of number
		largest = right;
	}

	if (largest != index) // swap the number
	{
		int swap; // keeping the swaping number
		swap = numberArray[index];
		numberArray[index] = numberArray[largest];
		numberArray[largest] = swap;
		maxHeapify(numberArray, size, largest); // recursive call for building heap correctly 
	}
}

void buildMaxHeap(int numberArray[], int size){ // sending array to maxheapfiy
	for (int i = size / 2 - 1; i >= 0; i--){
		maxHeapify(numberArray, size, i);
	}
}
void heapSort(int numberArray[], int size) // sort the object according to number
{
	buildMaxHeap(numberArray, size); // firstly build the heap

	for (int i = size - 1; i >= 0; i--)
	{
		int swap; // keeping the swaping number
		swap = numberArray[0];
		numberArray[0] = numberArray[i];
		numberArray[i] = swap;
		maxHeapify(numberArray, i, 0); // recursive call for controlling 
	}
}

void insertArray(int number)
{
	if (current_size == general_size) // if there is no space 
	{
		cout << "you can not add element." << endl;
		return;
	}
	int i = current_size;
	numberArray[i] = number; // if object does not exist already new object added to heap
	maxHeapify(numberArray, current_size, 0);
	current_size++;
}

void extractMax(int numberArray[])
{
	if (current_size <= 0){ // if there is not a element
		cout << "there is an empty array." << endl;
	}
	if (current_size == 1) // if there is a just one 
	{
		current_size--;
		extractArray[0] = numberArray[0];
	}
	for (int i = 0; i < 10000; i++)
	{
		int root = numberArray[0]; // assign biggest number to root 
		numberArray[0] = numberArray[current_size - 1];
		current_size--;
		maxHeapify(numberArray, current_size, 0); // building heap again
		heapSort(numberArray, current_size);
		extractArray[i] = root;
	}
}

void writeToFile(int extractArray[]){

	ofstream excellFile("sorted.csv"); // open the file for writing
	if (excellFile.is_open())
	{
		for (int i = 0; i < 10000; i++)
		{
			excellFile << extractArray[i] << endl; // writing to file 
		}
		excellFile.close();
	}
	else cout << "Excel file can not opened.";
}

void printArray(int numberArray[], int lenght){ // just for controlling 
	for (int i = 0; i < lenght; i++)
	{
		cout << "NUMBER:" << numberArray[i] << endl;
	}
}

int main(){
	int operationNumber = 1; // keeping the value each operation
	string element;  // element is created for reading the file
	clock_t start_exctrat, end_exctrat;
	double total_exctrat;

	int number; // number is created for keeping the value of extract number

	ifstream excelFile("numbers.csv"); // file is opened for reading
	if (excelFile.is_open())
	{
		for (int i = 0; i < general_size; i++)
		{
			getline(excelFile, element);
			number = atoi(element.c_str());
			insertArray(number);
		}
		excelFile.close();
	}
	else {
		cout << "Excel file is not opened." << endl;
	}

	heapSort(numberArray, current_size); // sort the number according to biggest one 

	for (int i = 0; i < 10; i++)  
	{
		cout << "********************************************************************" << endl;
		cout << "SORTED-" << operationNumber << endl;
		cout << "HEIGHT OF HEAP BEFORE EXTRACT :" << current_size << endl;
		start_exctrat = clock();
		extractMax(numberArray);
		end_exctrat = clock();
		total_exctrat = (double)(end_exctrat - start_exctrat) / CLOCKS_PER_SEC;
		writeToFile(extractArray); // writing to file
		cout << "HEIGHT OF HEAP AFTER EXTRACT  :" << current_size << endl;
		cout << "EXECUTION TIME OF" << operationNumber << "STEP :" << total_exctrat << endl;
		operationNumber++;
	}

	delete numberArray;
	system("pause");
}
