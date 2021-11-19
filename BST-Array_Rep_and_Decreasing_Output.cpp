/*C++ Program for array implementation of Binary Search Tree
The following LOGIC is used:
If i is the index of an element, then:
(For array starting with index 1)
        Index of its left child = 2 * i
        Index of its right child = (2 * i) + 1 
        Index of its parent = floor(i/2)
 */

#include <iostream>
#include <conio.h>
//OR simply use --> #include <bits/stdc++.h>

#define SIZE 100
// Assuming the size of array to be 100

using namespace std;

void create_bst(int a[], int index, int value)
// For creating and inserting element in the Binary Search Tree
{
    if (index >= SIZE)
    {
        cout << "NOT enough space in array!!" << endl;
        exit(0); // Terminate the program if there is not enough space in the array
    }
    else
    {
        if (a[index] == -1)
            a[index] = value;
        else
        {
            if (value < a[index])
                // For specifying index of left child
                create_bst(a, index * 2, value);
            else
                // For specifying index of right child
                create_bst(a, (index * 2) + 1, value);
        }
    }
}

//Function definition for printing of BST in decreasing order
/*LOGIC: Printing the elements starting from the right most child to the left most child for decreasing order*/
void print_decreasing(int a[], int index)
{
    if (a[index] != -1)
    {
        print_decreasing(a, (index * 2) + 1);
        cout << a[index] << " ";
        print_decreasing(a, index * 2);
    }
}

int main()
{
    int arr[SIZE];
    int data;
    int n;
    int j = 1;

    // Initialising the array elements as (say) -1
    for (int i = 1; i < SIZE; i++)
        arr[i] = -1;

    cout << "Enter the number of input elements: ";
    cin >> n;

    //Loop to ensure valid number of input elements are entered
    while (n <= 0)
    {
        cout << "Array size is invalid, please enter a VALID size." << endl;
        cin >> n;
    }

    // Storing entered elements in the array
    cout << "Enter " << n << " integer values: ";
    while (j <= n)
    {
        cin >> data;
        j++;
        create_bst(arr, 1, data);
    }

    // Printing in decreasing order
    cout << "Decreasing output: " << endl;
    print_decreasing(arr, 1);

    return 0;
}
