#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define FACTORIAL 19
#define FIBONACCI 100
#define DISCS_NUMBER 6
#define BUFF_SIZE 2024

void hanoi(void);

void main(void){
    hanoi();
    exit(0);
}

int posA = 0;
int posB = 0;
int posC = 0;
int towerA[DISCS_NUMBER];
int towerB[DISCS_NUMBER];
int towerC[DISCS_NUMBER];

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
    printf("Tower A: ");
    for (int i = 0; i < posA; i++){
        printf("%d ", towerA[i]);
    }
    printf("\nTower B: ");
    for (int i = 0; i < posB; i++){
        printf("%d ", towerB[i]);
    }
    printf("\nTower C: ");
    for (int i = 0; i < posC; i++){
        printf("%d ", towerC[i]);
    }
    printf("\n\n");
}

void bootHanoi(){
    for (int i = 6; i >= 1; i--){
        pushA(i);
    }
}

void hanoi(){
    bootHanoi();
    show();
    while(posC < 6){
        moveAB();
        show();
        if (posC == 6) break;
        moveAC();
        show();
        if (posC == 6) break;
        moveBC();
        show();
    }
}