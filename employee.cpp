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

int current_sizePs = 0; // currrent size increase when new element add to heap
int current_sizeCall = 0;
int general_size = 8000; // There are 10 files and each file has 800 line

class Employee{  // Employee class
public:
	int employeId;
	int totalNumberOfCall;
	int callWithPositiveFeedback;
	int callWithNegativeFeedback;
	int performanceScore;
};

Employee *employeeArrayPs = new Employee[general_size]; // creating Array 
Employee *employeeArrayCall = new Employee[general_size];  // creating Array 

int calculatePs(Employee object){ // calculate performance score

	int performanceScore = 2 * (object.totalNumberOfCall) + (object.callWithPositiveFeedback) - (object.callWithNegativeFeedback); // formula is used in homework explanation
	return performanceScore;
}

void maxHeapifyPs(Employee array[], int size, int index) // building heap according to biggest performance score
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && array[left].performanceScore < array[largest].performanceScore){ //  compresion of performance score
		largest = left;
	}

	if (right < size && array[right].performanceScore < array[largest].performanceScore){ // compresion of performance score
		largest = right;
	}

	if (largest != index) // swap the object
	{
		Employee swap; // keeping the swaping object
		swap.employeId = array[index].employeId;
		swap.totalNumberOfCall = array[index].totalNumberOfCall;
		swap.callWithPositiveFeedback = array[index].callWithPositiveFeedback;
		swap.callWithNegativeFeedback = array[index].callWithNegativeFeedback;
		swap.performanceScore = array[index].performanceScore;
		array[index].employeId = array[largest].employeId;
		array[index].totalNumberOfCall = array[largest].totalNumberOfCall;
		array[index].callWithPositiveFeedback = array[largest].callWithPositiveFeedback;
		array[index].callWithNegativeFeedback = array[largest].callWithNegativeFeedback;
		array[index].performanceScore = array[largest].performanceScore;
		array[largest].employeId = swap.employeId;
		array[largest].totalNumberOfCall = swap.totalNumberOfCall;
		array[largest].callWithPositiveFeedback = swap.callWithPositiveFeedback;
		array[largest].callWithNegativeFeedback = swap.callWithNegativeFeedback;
		array[largest].performanceScore = swap.performanceScore;
		maxHeapifyPs(array, size, largest); // recursive call for building heap correctly 
	}
}

void minHeapifyPs(Employee array[], int size, int index) // building heap according to least performance score
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && array[left].performanceScore > array[largest].performanceScore){ //  compresion of performance score
		largest = left;
	}

	if (right < size && array[right].performanceScore > array[largest].performanceScore){ // compresion of performance score
		largest = right;
	}

	if (largest != index) // swap the object
	{
		Employee swap; // keeping the swaping object
		swap.employeId = array[index].employeId;
		swap.totalNumberOfCall = array[index].totalNumberOfCall;
		swap.callWithPositiveFeedback = array[index].callWithPositiveFeedback;
		swap.callWithNegativeFeedback = array[index].callWithNegativeFeedback;
		swap.performanceScore = array[index].performanceScore;
		array[index].employeId = array[largest].employeId;
		array[index].totalNumberOfCall = array[largest].totalNumberOfCall;
		array[index].callWithPositiveFeedback = array[largest].callWithPositiveFeedback;
		array[index].callWithNegativeFeedback = array[largest].callWithNegativeFeedback;
		array[index].performanceScore = array[largest].performanceScore;
		array[largest].employeId = swap.employeId;
		array[largest].totalNumberOfCall = swap.totalNumberOfCall;
		array[largest].callWithPositiveFeedback = swap.callWithPositiveFeedback;
		array[largest].callWithNegativeFeedback = swap.callWithNegativeFeedback;
		array[largest].performanceScore = swap.performanceScore;
		minHeapifyPs(array, size, largest); // recursive call for building heap correctly 
	}
}


void maxHeapifyCall(Employee array[], int size, int index){ // building heap according to max number of call
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && array[left].totalNumberOfCall < array[largest].totalNumberOfCall){ //  compresion of number of call
		largest = left;
	}

	if (right < size && array[right].totalNumberOfCall < array[largest].totalNumberOfCall){ //  compresion of number of call
		largest = right;
	}

	if (largest != index) // swap the object
	{
		Employee swap; // keeping the swaping object
		swap.employeId = array[index].employeId;
		swap.totalNumberOfCall = array[index].totalNumberOfCall;
		swap.callWithPositiveFeedback = array[index].callWithPositiveFeedback;
		swap.callWithNegativeFeedback = array[index].callWithNegativeFeedback;
		swap.performanceScore = array[index].performanceScore;
		array[index].employeId = array[largest].employeId;
		array[index].totalNumberOfCall = array[largest].totalNumberOfCall;
		array[index].callWithPositiveFeedback = array[largest].callWithPositiveFeedback;
		array[index].callWithNegativeFeedback = array[largest].callWithNegativeFeedback;
		array[index].performanceScore = array[largest].performanceScore;
		array[largest].employeId = swap.employeId;
		array[largest].totalNumberOfCall = swap.totalNumberOfCall;
		array[largest].callWithPositiveFeedback = swap.callWithPositiveFeedback;
		array[largest].callWithNegativeFeedback = swap.callWithNegativeFeedback;
		array[largest].performanceScore = swap.performanceScore;
		maxHeapifyCall(array, size, largest);  // recursive call for building heap correctly 
	}
}

void minHeapifyCall(Employee array[], int size, int index){ // building heap according to least number of call
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && array[left].totalNumberOfCall > array[largest].totalNumberOfCall){ //  compresion of number of call
		largest = left;
	}

	if (right < size && array[right].totalNumberOfCall > array[largest].totalNumberOfCall){ //  compresion of number of call
		largest = right;
	}

	if (largest != index) // swap the object
	{
		Employee swap; // keeping the swaping object
		swap.employeId = array[index].employeId;
		swap.totalNumberOfCall = array[index].totalNumberOfCall;
		swap.callWithPositiveFeedback = array[index].callWithPositiveFeedback;
		swap.callWithNegativeFeedback = array[index].callWithNegativeFeedback;
		swap.performanceScore = array[index].performanceScore;
		array[index].employeId = array[largest].employeId;
		array[index].totalNumberOfCall = array[largest].totalNumberOfCall;
		array[index].callWithPositiveFeedback = array[largest].callWithPositiveFeedback;
		array[index].callWithNegativeFeedback = array[largest].callWithNegativeFeedback;
		array[index].performanceScore = array[largest].performanceScore;
		array[largest].employeId = swap.employeId;
		array[largest].totalNumberOfCall = swap.totalNumberOfCall;
		array[largest].callWithPositiveFeedback = swap.callWithPositiveFeedback;
		array[largest].callWithNegativeFeedback = swap.callWithNegativeFeedback;
		array[largest].performanceScore = swap.performanceScore;
		minHeapifyCall(array, size, largest);  // recursive call for building heap correctly 
	}
}

void buildMaxHeapPs(Employee array[], int size){ // sending array to maxheapfiyPs 
	for (int i = size / 2 - 1; i >= 0; i--){
		maxHeapifyPs(array, size, i);
	}
}

void buildMinHeapPs(Employee array[], int size){ // sending array to minheapfiyPs 
	for (int i = size / 2 - 1; i >= 0; i--){
		minHeapifyPs(array, size, i);
	}
}

void buildMaxHeapCall(Employee array[], int size){ // sending array to maxheapfiyCall
	for (int i = size / 2 - 1; i >= 0; i--){
		maxHeapifyCall(array, size, i);
	}
}

void buildMinHeapCall(Employee array[], int size){ // sending array to minheapfiyCall
	for (int i = size / 2 - 1; i >= 0; i--){
		minHeapifyCall(array, size, i);
	}
}

void heapSortPsMax(Employee array[], int size) // sort the object according to performance score
{
	buildMaxHeapPs(array, size); // firstly build the heap

	for (int i = size - 1; i >= 0; i--)
	{
		Employee swap; // keeping the swaping object 
		swap.employeId = array[0].employeId;
		swap.totalNumberOfCall = array[0].totalNumberOfCall;
		swap.callWithPositiveFeedback = array[0].callWithPositiveFeedback;
		swap.callWithNegativeFeedback = array[0].callWithNegativeFeedback;
		swap.performanceScore = array[0].performanceScore;
		array[0].employeId = array[i].employeId;
		array[0].totalNumberOfCall = array[i].totalNumberOfCall;
		array[0].callWithPositiveFeedback = array[i].callWithPositiveFeedback;
		array[0].callWithNegativeFeedback = array[i].callWithNegativeFeedback;
		array[0].performanceScore = array[i].performanceScore;
		array[i].employeId = swap.employeId;
		array[i].totalNumberOfCall = swap.totalNumberOfCall;
		array[i].callWithPositiveFeedback = swap.callWithPositiveFeedback;
		array[i].callWithNegativeFeedback = swap.callWithNegativeFeedback;
		array[i].performanceScore = swap.performanceScore;
		maxHeapifyPs(array, i, 0); // recursive call for controlling 
	}
}

void heapSortPsMin(Employee array[], int size) // sort the object according to performance score
{
	buildMinHeapPs(array, size); // firstly build the heap

	for (int i = size - 1; i >= 0; i--)
	{
		Employee swap; // keeping the swaping object 
		swap.employeId = array[0].employeId;
		swap.totalNumberOfCall = array[0].totalNumberOfCall;
		swap.callWithPositiveFeedback = array[0].callWithPositiveFeedback;
		swap.callWithNegativeFeedback = array[0].callWithNegativeFeedback;
		swap.performanceScore = array[0].performanceScore;
		array[0].employeId = array[i].employeId;
		array[0].totalNumberOfCall = array[i].totalNumberOfCall;
		array[0].callWithPositiveFeedback = array[i].callWithPositiveFeedback;
		array[0].callWithNegativeFeedback = array[i].callWithNegativeFeedback;
		array[0].performanceScore = array[i].performanceScore;
		array[i].employeId = swap.employeId;
		array[i].totalNumberOfCall = swap.totalNumberOfCall;
		array[i].callWithPositiveFeedback = swap.callWithPositiveFeedback;
		array[i].callWithNegativeFeedback = swap.callWithNegativeFeedback;
		array[i].performanceScore = swap.performanceScore;
		minHeapifyPs(array, i, 0); // recursive call for controlling 
	}
}

void heapSortCallMax(Employee array[], int size) // sort the object according to number of call
{
	buildMaxHeapCall(array, size);  // firstly build the heap

	for (int i = size - 1; i >= 0; i--)
	{
		Employee swap; // keeping the swaping object 
		swap.employeId = array[0].employeId;
		swap.totalNumberOfCall = array[0].totalNumberOfCall;
		swap.callWithPositiveFeedback = array[0].callWithPositiveFeedback;
		swap.callWithNegativeFeedback = array[0].callWithNegativeFeedback;
		swap.performanceScore = array[0].performanceScore;
		array[0].employeId = array[i].employeId;
		array[0].totalNumberOfCall = array[i].totalNumberOfCall;
		array[0].callWithPositiveFeedback = array[i].callWithPositiveFeedback;
		array[0].callWithNegativeFeedback = array[i].callWithNegativeFeedback;
		array[0].performanceScore = array[i].performanceScore;
		array[i].employeId = swap.employeId;
		array[i].totalNumberOfCall = swap.totalNumberOfCall;
		array[i].callWithPositiveFeedback = swap.callWithPositiveFeedback;
		array[i].callWithNegativeFeedback = swap.callWithNegativeFeedback;
		array[i].performanceScore = swap.performanceScore;
		maxHeapifyCall(array, i, 0); // recursive call for controlling
	}
}

void heapSortCallMin(Employee array[], int size) // sort the object according to number of call
{
	buildMinHeapCall(array, size);  // firstly build the heap

	for (int i = size - 1; i >= 0; i--)
	{
		Employee swap; // keeping the swaping object 
		swap.employeId = array[0].employeId;
		swap.totalNumberOfCall = array[0].totalNumberOfCall;
		swap.callWithPositiveFeedback = array[0].callWithPositiveFeedback;
		swap.callWithNegativeFeedback = array[0].callWithNegativeFeedback;
		swap.performanceScore = array[0].performanceScore;
		array[0].employeId = array[i].employeId;
		array[0].totalNumberOfCall = array[i].totalNumberOfCall;
		array[0].callWithPositiveFeedback = array[i].callWithPositiveFeedback;
		array[0].callWithNegativeFeedback = array[i].callWithNegativeFeedback;
		array[0].performanceScore = array[i].performanceScore;
		array[i].employeId = swap.employeId;
		array[i].totalNumberOfCall = swap.totalNumberOfCall;
		array[i].callWithPositiveFeedback = swap.callWithPositiveFeedback;
		array[i].callWithNegativeFeedback = swap.callWithNegativeFeedback;
		array[i].performanceScore = swap.performanceScore;
		minHeapifyCall(array, i, 0); // recursive call for controlling
	}
}

bool increaseKeyPs(Employee object){ // used for increasing the value of object which exist in the heap already
	Employee newObject; // creating new object to keeping increasing value
	for (int i = 0; i < current_sizePs; i++)
	{
		if (object.employeId == employeeArrayPs[i].employeId){
			newObject.employeId = object.employeId;
			newObject.totalNumberOfCall = employeeArrayPs[i].totalNumberOfCall + object.totalNumberOfCall;
			newObject.callWithPositiveFeedback = employeeArrayPs[i].callWithPositiveFeedback + object.callWithPositiveFeedback;
			newObject.callWithNegativeFeedback = employeeArrayPs[i].callWithNegativeFeedback + object.callWithNegativeFeedback;
			newObject.performanceScore = employeeArrayPs[i].performanceScore + object.performanceScore;
			employeeArrayPs[i] = newObject; // changing the increasing one and old one
			return true; // just for controlling in insert()
		}
	}
	return false; // just for controlling in insert()
}

bool increaseKeyCall(Employee object){ // used for increasing the value of object which exist in the heap already
	Employee newObject; // creating new object to keeping increasing value
	for (int i = 0; i < current_sizeCall; i++)
	{
		if (object.employeId == employeeArrayCall[i].employeId){
			newObject.employeId = object.employeId;
			newObject.totalNumberOfCall = employeeArrayCall[i].totalNumberOfCall + object.totalNumberOfCall;
			newObject.callWithPositiveFeedback = employeeArrayCall[i].callWithPositiveFeedback + object.callWithPositiveFeedback;
			newObject.callWithNegativeFeedback = employeeArrayCall[i].callWithNegativeFeedback + object.callWithNegativeFeedback;
			newObject.performanceScore = employeeArrayCall[i].performanceScore + object.performanceScore;
			employeeArrayCall[i] = newObject; // changing the increasing one and old one
			return true; // just for controlling in insert()
		}
	}
	return false; // just for controlling in insert()
}

void insertArrayPs(Employee object)
{
	if (current_sizePs == general_size) // if there is no space 
	{
		cout << "you can not add element." << endl;
		return;
	}

	int i = current_sizePs;
	if ((increaseKeyPs(object))){ // according to return value build heap
		maxHeapifyPs(employeeArrayPs, current_sizePs, 0);
	}
	else{
		employeeArrayPs[i] = object; // if object does not exist already new object added to heap
		maxHeapifyPs(employeeArrayPs, current_sizePs, 0);
		current_sizePs++;
	}

}

void insertArrayCall(Employee object)
{
	if (current_sizeCall == general_size) // if there is no space 
	{
		cout << "you can not add element." << endl;
		return;
	}

	int i = current_sizeCall;
	if ((increaseKeyCall(object))){ // according to return value build heap
		minHeapifyCall(employeeArrayCall, current_sizeCall, 0);
	}
	else{
		employeeArrayCall[i] = object; // if object does not exist already new object added to heap
		minHeapifyCall(employeeArrayCall, current_sizeCall, 0);
		current_sizeCall++;
	}

}

Employee extractMax(Employee array[], int size)
{
	if (size <= 0){ // if there is not a element
		cout << "there is an empty array." << endl;
	}
	if (size == 1) // if there is a just one 
	{
		size--;
		return array[0];
	}
	Employee root = array[0]; // assign biggest elemnet to the new object 
	array[0] = array[size - 1]; // copying the last elemnt to begining of array
	size--;
	maxHeapifyPs(array, size, 0); // building heap again

	return root;
}

Employee extractMin(Employee array[], int size)
{
	if (size <= 0){ // if there is not a element
		cout << "there is an empty array." << endl;
	}
	if (size == 1) // if there is a just one 
	{
		size--;
		return array[0];
	}
	Employee root = array[0]; // assign least elemnet to the new object 
	array[0] = array[size - 1]; // copying the last elemnt to begining of array
	size--;
	maxHeapifyPs(array, size, 0); // building heap again

	return root;
}

void printDailyResultPsMax(){ // printing the daily result using array and size
	Employee max1, max2, max3;
	max1 = extractMax(employeeArrayPs, current_sizePs);
	heapSortPsMax(employeeArrayPs, current_sizePs);
	max2 = extractMax(employeeArrayPs, current_sizePs);
	heapSortPsMax(employeeArrayPs, current_sizePs);
	max3 = extractMax(employeeArrayPs, current_sizePs);
	heapSortPsMax(employeeArrayPs, current_sizePs);
	cout << "BEST PERFORMANCE :" << max1.employeId << " " << max2.employeId << " " << max3.employeId << endl; // print max value
	insertArrayPs(max1);
	insertArrayPs(max2);
	insertArrayPs(max3);
	heapSortPsMax(employeeArrayPs, current_sizePs);
}

void printDailyResultPsMin(){ // printing the daily result using array and size
	Employee min1, min2, min3;
	min1 = extractMin(employeeArrayCall, current_sizeCall);
	heapSortPsMin(employeeArrayCall, current_sizeCall);
	min2 = extractMin(employeeArrayCall, current_sizeCall);
	heapSortPsMin(employeeArrayCall, current_sizeCall);
	min3 = extractMin(employeeArrayCall, current_sizeCall);
	heapSortPsMin(employeeArrayCall, current_sizeCall);
	cout << "WORST PERFORMANCE :" << min1.employeId << " " << min2.employeId << " " << min3.employeId << endl; // print min value
	insertArrayCall(min1);
	insertArrayCall(min2);
	insertArrayCall(min3);
	heapSortPsMin(employeeArrayCall, current_sizeCall);
}

void printDailyResultCallMax(){  // printing the daily result using array and size
	Employee max1, max2, max3;
	max1 = extractMax(employeeArrayPs, current_sizePs);
	heapSortCallMax(employeeArrayPs, current_sizePs);
	max2 = extractMax(employeeArrayPs, current_sizePs);
	heapSortCallMax(employeeArrayPs, current_sizePs);
	max3 = extractMax(employeeArrayPs, current_sizePs);
	heapSortCallMax(employeeArrayPs, current_sizePs);
	cout << "MAXIMUM CALL :" << max1.employeId << " " << max2.employeId << " " << max3.employeId << endl; // print max value
	insertArrayPs(max1);
	insertArrayPs(max2);
	insertArrayPs(max3);
	heapSortCallMax(employeeArrayPs, current_sizePs);
}

void printDailyResultCallMin(){  // printing the daily result using array and size
	Employee min1, min2, min3;
	min1 = extractMin(employeeArrayCall, current_sizeCall);
	heapSortCallMin(employeeArrayCall, current_sizeCall);
	min2 = extractMin(employeeArrayCall, current_sizeCall);
	heapSortCallMin(employeeArrayCall, current_sizeCall);
	min3 = extractMin(employeeArrayCall, current_sizeCall);
	heapSortCallMin(employeeArrayCall, current_sizeCall);
	cout << "MINUMUM CALL :" << min1.employeId << " " << min2.employeId << " " << min3.employeId << endl; // print min value
	insertArrayCall(min1);
	insertArrayCall(min2);
	insertArrayCall(min3);
	heapSortCallMin(employeeArrayCall, current_sizeCall);
}

void printArray(Employee array[], int size){ // just for controlling 
	for (int i = 0; i < size; i++)
	{
		cout << array[i].employeId << " " << array[i].totalNumberOfCall << " " << array[i].callWithPositiveFeedback << " " << array[i].callWithNegativeFeedback << " " << array[i].performanceScore << endl;
	}
}

int main(){
	Employee *employeeObject = new Employee[general_size];   // object is created for keeping value of employee 
	string element1, element2, element3, element4; // string element is created for reading from the file
	clock_t start_heapSortForPerformanceScore, end_heapSortForPerformanceScore, start_heapSortForCall, end_heapSortForCall; // for keeping time value
	double total_heapSortPs, total_heapSortCall;
	int dayNumber = 1; // for printing day number at the result
	string fileNameArray[10];  // array is created for keeping the name of file
	string filename1 = "day1.csv"; // assign filename
	string filename2 = "day2.csv";
	string filename3 = "day3.csv";
	string filename4 = "day4.csv";
	string filename5 = "day5.csv";
	string filename6 = "day6.csv";
	string filename7 = "day7.csv";
	string filename8 = "day8.csv";
	string filename9 = "day9.csv";
	string filename10 = "day10.csv";

	fileNameArray[0] = filename1; // sending file name to filenamearray
	fileNameArray[1] = filename2;
	fileNameArray[2] = filename3;
	fileNameArray[3] = filename4;
	fileNameArray[4] = filename5;
	fileNameArray[5] = filename6;
	fileNameArray[6] = filename7;
	fileNameArray[7] = filename8;
	fileNameArray[8] = filename9;
	fileNameArray[9] = filename10;

	for (int i = 0; i < 10; i++)
	{
		ifstream excelFile(fileNameArray[i].c_str()); // read from file according to filename
		if (excelFile.is_open()) // open the file 
		{
			for (int i = 0; i <= 800; i++)
			{
				getline(excelFile, element1, ','); // reading first element from the file
				getline(excelFile, element2, ','); // reading second element from the file
				getline(excelFile, element3, ','); // reading third element from the file
				getline(excelFile, element4);  // reading the last elelment from the file
				employeeObject[i].employeId = atoi(element1.c_str()); // converting string to integer 
				employeeObject[i].totalNumberOfCall = atoi(element2.c_str());
				employeeObject[i].callWithPositiveFeedback = atoi(element3.c_str());
				employeeObject[i].callWithNegativeFeedback = atoi(element4.c_str());
				employeeObject[i].performanceScore = calculatePs(employeeObject[i]); // calculeting performance score
				insertArrayPs(employeeObject[i]); // insert the elelment to array
				insertArrayCall(employeeObject[i]);
			}
			excelFile.close(); // close the file 
		}
		else {
			cout << "Excel file is not opened." << endl;
		}

		start_heapSortForPerformanceScore = clock();  // keeping start time of the heap sort
		heapSortPsMax(employeeArrayPs, current_sizePs);    // sorting the object according to performance score 
		end_heapSortForPerformanceScore = clock();   // keeping end time of heap sort

		total_heapSortPs = (double)(end_heapSortForPerformanceScore - start_heapSortForPerformanceScore) / CLOCKS_PER_SEC; // calculate time
		cout << "AFTER DAY-" << dayNumber << endl;

		printDailyResultPsMax();

		start_heapSortForCall = clock(); // keeping start time of the heap sort
		heapSortCallMax(employeeArrayPs, current_sizePs); // sorting the object according to number of call
		end_heapSortForCall = clock(); // keeping end time of heap sort
		printDailyResultCallMax();
		if (dayNumber == 10){ // printing the 10th day record
			heapSortPsMin(employeeArrayCall, current_sizeCall);
			printDailyResultPsMin();
			heapSortCallMin(employeeArrayCall, current_sizeCall);
			printDailyResultCallMin();
		}
		total_heapSortCall = (double)(end_heapSortForCall - start_heapSortForCall) / CLOCKS_PER_SEC; // calculate time

		cout << "Time Of HeapSort For Performance Score:" << total_heapSortPs << endl;
		cout << "Time Of HeapSort For Number Of Call   :" << total_heapSortCall << endl;
		cout << "-------------------------------END OF DAY--------------------" << endl;
		dayNumber++;
	}
	system("pause");
}
