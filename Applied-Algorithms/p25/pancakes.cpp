#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//generic print array function to output the stack of pancakes after each flip
void print_array(int *stack, int h) {
    for (int i = 0; i < h; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int convert(char c) {
    int value = 0;
    switch (c) {
        //Right side
        case 'A' : value = 1;
            break;
        case 'B' : value = 2;
            break;
        case 'C' : value = 3;
            break;
        case 'D' : value = 4;
            break;
        case 'E' : value = 5;
            break;
        case 'F' : value = 6;
            break;

        //Burnt side
        case 'a' : value = -1;
            break;
        case 'b' : value = -2;
            break;
        case 'c' : value = -3;
            break;
        case 'd' : value = -4;
            break;
        case 'e' : value = -5;
            break;
        case 'f' : value = -6;
            break;
    }
    return value;
}

int *char_to_digit(string str, int *stack) {
    int temp;
    for (int i = 0; i < str.length(); i++) {
        temp = convert(str[i]);
        if (temp != 0)
            stack[i] = temp;
    }
    return stack;
}

//function that flips the pancakes
void flip(int stack[], int n) {
    int temp = 0;
    int m = n;

    //swap the positions of the pancakes from top to n, where n is the index
    //of the largest unsorted pancake
    for (int i = 0; i < n; i++) {
        temp = stack[i];
        stack[i] = stack[n];
        stack[n] = temp;
        n--;
    }

    //change which side of the flipped pancakes is burnt
    for (int i = 0; i < m + 1; i++) {
        stack[i] = stack[i] * -1;
    }
}

//find the largest pancake in the stack
int is_max(int stack[], int n) {
    int max, i;
    //take the absolute value to account for the burnt side up (negative) pancakes
    for (max = 0, i = 0; i < n; i++) {
        if (abs(stack[max]) <= abs(stack[i])) {
            max = i;
        }
    }
    return max;
}

//the core of the program that sorts the stack
int pancake_sort(int *stack, int height) {
    int moves = 0, movesm2 = 0;
    int *stack2 = stack;

    //1st method
    //search the stack for the largest unsorted pancake
    //and flips it to the top of the stack
    for (int h = height; h > 1; h--) {
        int max = is_max(stack, h);
        if (max != h - 1) {
            if (max != 0) {
                flip(stack, max);
                moves++;
                print_array(stack, height);
            }

            //if the pancake that is now on the top is burnt side up
            //flip the pancake again (burned side up)
            if (stack[0] > 0) {
                stack[0] = stack[0] * -1;
                moves++;
                print_array(stack, height);
            }

            //finally flip the whole unsorted stack
            // until elem at size - 1 because up to that point they've been flipped
            flip(stack, h - 1);
            moves++;
            print_array(stack, height);
        }
    }

    //check for any burnt side up pancakes in the stack and flip them
    for (int i = height - 1; i > 0; i--) {
        if (stack[i] < 0) {
            flip(stack, i);
            moves++;
            print_array(stack, height);

            stack[0] = stack[0] * -1;
            moves++;
            print_array(stack, height);

            flip(stack, i);
            moves++;
            print_array(stack, height);
        }
    }

    //check that after the last flip the top pancake is burnt side down
    if (stack[0] < 0) {
        stack[0] = stack[0] * -1;
        moves++;
        print_array(stack, height);
    }

    cout << endl;

    //2nd method
    //search the stack for the largest unsorted pancake
    //and flips it to the top of the stack
    for (int h = height; h > 1; h--) {
        int max = is_max(stack2, h);

        if (max == h - 1) {
            if (max != 0) {
                flip(stack2, max - 2);
                movesm2++;
                print_array(stack2, height);
            }

            //if the pancake that is now on the top is burnt side up
            //flip the pancake again (burned side up)
            /*if (stack[0] > 0) {
                stack[0] = stack[0] * -1;
                moves++;
                print_array(stack, height);
            }

            //finally flip the whole unsorted stack
            // until elem at size - 1 because up to that point they've been flipped
            flip(stack, h - 1);
            moves++;
            print_array(stack, height);*/
        }
    }

    return moves;
}

int main(void) {
    string str;
    while (cin >> str && str != "0") {
        int size = str.length();
        int *stack = new int[size];
        stack = char_to_digit(str, stack);
        cout << "Stack: ";
        print_array(stack, str.length());

        //do the sort
        int moves = pancake_sort(stack, size);
        cout << "Moves: " << moves << endl;
        free(stack);
        cout << endl;
    }

    return 0;
}