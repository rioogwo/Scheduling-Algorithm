#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Constant variables
const int MIN_JOBS = 3;
const int MAX_JOBS = 10;

void SJN();
void PP();
int getJobNumber();
int getAlgoInput();
void showTable();

/**
    MAIN FUNCTION
*/
int main(){
    //Variables
    int jobNumber;
    bool loopEnd = false;
    char choice;
    //Creating Menu
    do {
        printf("- - -Scheduling Algorithm- - -\n");
        printf("A: Shortest Job Next\n");
        printf("B: Preemptive Priority\n");
        printf("C: Exit\n\n");
        printf("Enter Choice: ");
        scanf("%c", &choice);
        fflush(stdin);
        //Input Checker
        switch(toupper(choice)){
        case 'A': //Shortest Job Next
            printf("\n");
            SJN();
            break;
        case 'B': //Preemptive Priority
            printf("\n");
            PP();
            break;
        case 'C': //Exit loop and end code
            loopEnd = true;
            break;
        default: //Input Error
            printf("Input Unavailable\n");
        }
    } while (!loopEnd);
    //Exit Message
    printf("Thank You For Using The Program!\n");
    return 0;
}

/**
    Function Name: SJN
    Parameter: none
    Return Type: void
    Function:
        Do the Shortest Job Next algorithm for the data
        Display the output
*/
void SJN(){
    //variables
    int jobNumber = getJobNumber();
    int arrivalTime[jobNumber];
    int burstTime[jobNumber];
    int index[getAlgoInput(jobNumber, arrivalTime, burstTime, NULL)];





    //@Show Data Table
    showTable(jobNumber, arrivalTime, burstTime, NULL);
}

/**
    Function Name: PP
    Parameter: none
    Return Type: none
    Function:
        Do the Preemptive Priority algorithm for the data
        Display the output
*/
void PP(){
    //variables
    int jobNumber = getJobNumber();
    int arrivalTime[jobNumber];
    int burstTime[jobNumber];
    int priority[jobNumber];
    int index[getAlgoInput(jobNumber, arrivalTime, burstTime, priority)];





    //@Show Data Table
    showTable(jobNumber, arrivalTime, burstTime, priority);
}

/**
    Function Name: getJobNumber
    Parameter: none
    Return Type: int
        return the number of jobs the algorithm will have
    Function:
        Let the user input the number of jobs the algorithm will use
*/
int getJobNumber(){
    int jobNumber;
    printf("(min: 3|max: 10)\n");
    do{
        printf("Enter number of Jobs: ");
        scanf("%d", &jobNumber);
        fflush(stdin);
        if(jobNumber < 3 || jobNumber > 10){
            printf("Limit Error!\n");
        }
    } while(jobNumber < 3 || jobNumber > 10);
    printf("\n");
    return jobNumber;
}

/**
    Function Name: getAlgoNumber
    Parameter: int, int[], int[], int[]
        - jobNumber - Number of Jobs
        - AT[] - Array for Arrival Time
        - BT[] - Array for Burst Time
        - Priority[] - Array for Priority of Job
    Return Type: int
        return the total of burst time for all jobs
    Function:
        Let the user input the data for the algorithm
        Return the sum of time of the jobs
*/
int getAlgoInput(int jobNumber, int AT[], int BT[], int priority[]){
    int jobTimeSum = 0;
    //Enter Data for Arrival Time Array
    printf("Arrival Time:\n");
    for(int i = 0; i < jobNumber; ++i){
        printf("Enter Arrival Time for J%d: ", (i + 1));
        scanf("%d", &AT[i]);
        fflush(stdin);
    }
    printf("\n");

    //Enter Data for Burst Time Array
    printf("Burst Time:\n");
    for(int i = 0; i < jobNumber; ++i){
        printf("Enter Burst Time for J%d: ", (i + 1));
        scanf("%d", &BT[i]);
        fflush(stdin);
        jobTimeSum += BT[i];
    }
    printf("\n");

    //Enter Data for Priority Array
    if(priority != NULL){
        printf("(1 - Highest Priority)\n");
        printf("Priority:\n");
        for(int i = 0; i < jobNumber; ++i){
            printf("Enter Priority for J%d: ", (i + 1));
            scanf("%d", &priority[i]);
            fflush(stdin);
        }
        printf("\n");
    }
    return jobTimeSum;
}

/**
    Function Name: showTable
    Parameter: int, int[], int[], int[]
        - jobNumber - Number of Jobs
        - AT[] - Array for Arrival Time
        - BT[] - Array for Burst Time
    Return Type: void
    Function:
        Show the Table:
            JOB     AT      BT      Priority(optional)
*/
void showTable(int jobNumber, int AT[], int BT[], int priority[]){
    if(priority == NULL){
        printf("Jobs\tArrival Time\tBurst Time\n");
        for(int i = 0; i < jobNumber; ++i){
            printf("J%d\t%d\t\t%d\t\t\n", (i + 1), AT[i], BT[i]);
        }
    }
    else{
        printf("Jobs\tArrival Time\tBurst Time\tPriority\n");
        for(int i = 0; i < jobNumber; ++i){
            printf("%d\t%d\t\t%d\t\t%d\n", (i + 1), AT[i], BT[i], priority[i]);
        }
    }
}
