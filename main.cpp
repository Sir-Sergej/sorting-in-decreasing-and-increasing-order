#include<iostream>

void mySort(int *array, int length, bool (*comparisonFn)(int, int))
{
    for(int startIndex = 0; startIndex < length; startIndex++)
    {
        // bestIndex is the index of the smallest / largest element that we have discovered so far
        int bestIndex = startIndex;

        for(int currentIndex = startIndex + 1; currentIndex < length; currentIndex++)
        {
            //comparison
            if(comparisonFn(array[bestIndex], array[currentIndex]))
                bestIndex = currentIndex;
        }

        std::swap(array[startIndex], array[bestIndex]);
    }
}

// comparison function that performs sorting in ascending order
bool ascending(int a, int b)
{
    // swap if the first element is larger than the second
    return a > b;
}

// comparison function that performs sorting in descending order
bool descending(int a, int b)
{
    // swap if the second element is larger than the first
    return a < b;
}

bool evensFirst(int a, int b)
{
	
    // if the element isn`t even return true
	if ((a % 2 == 0) && !(b % 2 == 0))
		return false;
 
	// if the element is even return true
	if (!(a % 2 == 0) && (b % 2 == 0))
		return true;
 
    // othersize return ascending
	return ascending(a, b);
}

void printArray(int *array, int length)
{
    for(int i = 0; i < length; i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << '\n';
}


int main()
{
    int length;
    std::cin >> length;
    int myArray[length] {};

    for (int i = 0; i < length; i++)
    {
        std::cin >> myArray[i];
    }

    //sorting with ascending
    mySort(myArray, length, ascending);
    printArray(myArray, length);


    //sorting with descending
    mySort(myArray, length, descending);
    printArray(myArray, length);

    // sorting even elements
    mySort(myArray, length, evensFirst);
    printArray(myArray, length);



}