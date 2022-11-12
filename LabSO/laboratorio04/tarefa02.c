#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define FACTORIAL 30
#define LAST_TERM 100
#define DISCS_NUMBER 6
#define BUFF_SIZE 2024

void calculateFactorialOf(int);
void fibonacciSequenceTo(int);
void towerOfHanoi(int);
void hanoi(void);
int posA = 0;
int posB = 0;
int posC = 0;
int towerA[DISCS_NUMBER];
int towerB[DISCS_NUMBER];
int towerC[DISCS_NUMBER];


void main(void){
    pid_t pid;
    pid_t pid2;
    
    pid = fork();
    if (pid == 0){
        pid2 = fork();
        if (pid2 == 0){
            hanoi();
            exit(0);
        }else{
            fibonacciSequenceTo(LAST_TERM);
            exit(0);
        }
    }else{
        calculateFactorialOf(FACTORIAL);
        exit(0);
    }

    // exit(0);
}

void calculateFactorialOf(int number){
    char buff[BUFF_SIZE] = "";
    char* pnt = buff;
    int bytesWritten;
    double factorial = 1;

    for (int i = number; i > 0; i--){
        factorial *= i; 

        if (i == number){
            bytesWritten = sprintf(buff, "[PARENT] %d!\n", i);
        }else if (i != 1){
            bytesWritten += sprintf(buff+bytesWritten, " . %d!\n", i);
        }else{
            bytesWritten += sprintf(buff+bytesWritten, " . %d!\n", i);
        }

        write(1, buff, strlen(buff));
        printf("[PARENT] CURRENT VALUE: %.0f\n", factorial);
        strcpy(&pnt[strlen(buff)-1],"\0");
        strcpy(&pnt[strlen(buff)-1],"\0");
        bytesWritten -= 2;
    }

    bytesWritten += sprintf(buff+bytesWritten, " = %.0f\n", factorial);
    write(1, buff, strlen(buff));
    write(1,"############## FINISHING PARENT ##############\n", 47);

}

void fibonacciSequenceTo(int lastTerm){
    double firstTerm = 1;
    double nextTerm = 0;
    double auxTerm = 0;
    char buff[BUFF_SIZE] = "";
    char* pnt = buff;
    int bytesWritten;

    for (int i = 1; i <= lastTerm; i++){
        auxTerm = nextTerm;
        nextTerm = auxTerm + firstTerm;
        firstTerm = auxTerm;
        printf("[CHILD] T%d: %.0f\n", i,nextTerm);
    }

    printf("############## FINISHING CHILD ##############\n");
    printf("\n\n");
    
}

void pushA(int disc){
    towerA[posA] = disc;
    posA++;
}
void pushB(int disc){
    towerB[posB] = disc;
    posB++;
}
void pushC(int disc){
    towerC[posC] = disc;
    posC++;
}

int popA(){
    posA--;
    return towerA[posA];
}

int popB(){
    posB--;
    return towerB[posB];
}

int popC(){
    posC--;
    return towerC[posC];
}

int peekA(){
    return towerA[posA - 1];
}

int peekB(){
    return towerB[posB - 1];
}

int peekC(){
    return towerC[posC - 1];
}

void moveAB(){
    if (posA == 0){
        pushA(popB());
    }else if (posB == 0){
        pushB(popA());
    }else if (peekA() > peekB()){
        pushA(popB());
    }else if (peekA() < peekB()){
        pushB(popA());
    }
}

void moveBC(){
    if (posC == 0){
        pushC(popB());
    }else if (posB == 0){
        pushB(popC());
    }else if (peekC() > peekB()){
        pushC(popB());
    }else if (peekC() < peekB()){
        pushB(popC());
    }
}

void moveAC(){
    if (posA == 0){
        pushA(popC());
    }else if (posC == 0){
        pushC(popA());
    }else if (peekA() > peekC()){
        pushA(popC());
    }else if (peekA() < peekC()){
        pushC(popA());
    }
}

void show(){
    printf("[GRANDCHILD] Tower A: ");
    for (int i = 0; i < posA; i++){
        printf("%d ", towerA[i]);
    }
    printf("\n[GRANDCHILD] Tower B: ");
    for (int i = 0; i < posB; i++){
        printf("%d ", towerB[i]);
    }
    printf("\n[GRANDCHILD] Tower C: ");
    for (int i = 0; i < posC; i++){
        printf("%d ", towerC[i]);
    }
    printf("\n\n");
}

void bootHanoi(){
    for (int i = DISCS_NUMBER; i >= 1; i--){
        pushA(i);
    }
}

void hanoi(){
    int amountOfMovements = 0;
    bootHanoi();
    show();
    while(posC < DISCS_NUMBER){
        moveAB();
        amountOfMovements++;
        show();
        if (posC == DISCS_NUMBER) break;
        moveAC();
        amountOfMovements++;
        show();
        if (posC == DISCS_NUMBER) break;
        moveBC();
        amountOfMovements++;
        show();
    }
    printf("AMOUNT OF MOVEMENTS: %d\n############## FINISHING GRANDCHILD ##############\n\n", amountOfMovements);
}