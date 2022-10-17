/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the Universityâ€™s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
     
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: September 2, 2022
Name: Matthew Flores
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int lower_num = 1, upper_num = 6, counter = 0, j = 1;;
    double sum = 0, average = 0;

    while (counter == 0) {
        printf("How many times do you want to roll (2-5): ");
        scanf("%d", &counter);
        if (counter < 2 || counter > 5) {
            counter = 0;
        }
    }

    int arr[counter];
    srand(time(0));
    printf("\n");

    for(int i = 0; i < counter; i++) {
        int num = (rand() % (upper_num - lower_num) + lower_num);
        arr[i] = num;
        printf("Dice #%d\n", j);
        printf("\tValue is: %d", arr[i]);
        sum += arr[i];

        average = sum / j;

        printf("\tSum = %.2f", sum);
        printf("\tAverage = %.2f", average);

        printf("\n");
        j++;
    }

    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int lower_num = 1, upper_num = 6, counter = 0;
    double sum = 0, average = 0;

    while (counter == 0) {
        printf("How many times do you want to roll (2-5): ");
        scanf("%d", &counter);
        if (counter < 2 || counter > 5) {
            counter = 0;
        }
    }

    int arr[counter];
    srand(time(0));

    printf("All of the number are as follows: ");
    for (int i = 0; i < counter; i++) {
        int num = (rand() % (upper_num - lower_num) + lower_num);
        arr[i] = num;
    }

    for(int i = 0; i < counter; i++) {
        printf("%d ", arr[i] );
    }

    printf("\n");

    for(int i = 0; i < counter; i++) {
        sum += arr[i];
    }

    average = sum / counter;

    printf("Sum = %.2f\nAverage = %.2f\n", sum, average);

    return 0;
}
*/