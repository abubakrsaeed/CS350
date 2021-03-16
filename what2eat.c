/*
    <What2eat application>
    Copyright (C) <2021>  <Abubakr Saeed>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

//Github: https://github.com/abubakrsaeed/350



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum food
{ Kebab, Burger, Pasta, Lahmacun, Salad };

const int Threshold = 10;
const int foodMenu = 5;


void menu()
{
  printf ("\nEnter the number corresponding to your preferred food:\n");
  printf ("1. Kebab\n");
  printf ("2. Burger\n");
  printf ("3. Pasta\n");
  printf ("4. Lahmacun\n");
  printf ("5. Salad\n");
}

int assign(int a)
{
    if (a == Kebab){ 
        return Kebab; }
    else if (a == Burger){
        return Burger;}
    else if (a == Pasta){
        return Pasta;}
    else if (a == Lahmacun){
        return Lahmacun;}
    else if (a == Salad){
        return Salad;}
}

char* enumToStr(int a){
    
    if (a == Kebab){ 
        return "Kebab"; }
    else if (a == Burger){
        return "Burger";}
    else if (a == Pasta){
        return "Pasta";}
    else if (a == Lahmacun){
        return "Lahmacun";}
    else if (a == Salad){
        return "Salad";}
        
}


void foodItems(int a) {
   printf("%s\n", enumToStr(a));
}

int shortList (int points[]) {
    int x = 0;
    bool y = true;
    int i = 0;
    for (i=0; i<foodMenu; ++i)
    {
        if (points[i] > Threshold)
        {
            if(y)
            {
                printf("\nShortlisted Items are:\n");
                y=false;
            }
        ++x;
        printf("%d. ", i + 1);
        foodItems(i);
        }
    }
    return x;
}

char** getShortlistedList(int numberOfShortlisted, int points[]){
    char **array = malloc(numberOfShortlisted * sizeof(char *));
    
    int i;
    for (i = 0; i < numberOfShortlisted; ++i) {
        array[i] = (char *)malloc(10);
    }
    
     for (i=0; i<foodMenu; ++i)
    {
        if (points[i] > Threshold)
        {
            array[i] = enumToStr(i);
        }
    }
    
    return array;
}

void makeFinalSelection(char** shortList, int* points, int n){
    
    int max = 0;
    
    int i;
    for(i = 0 ; i < n ; i++){
        if(points[i] > points[max]){
            max = i;
        }
    }
    
    printf("\n%s got most points (%d) and it will be ordered!", shortList[max], points[max]);
}


void lsItems (int points2[], int size, int points[]) 
{
    int j = 0;
    int i = 0;
    for (i=0; i<foodMenu;++i)
    {
        if(points[i]>Threshold)
        {
            points2[j] = assign(i);
            ++j;
        }
    }
}

void Order(int ls[], int *people, int *orderChoice, int *maxInt) {
    int i=0;
    int choice=0;
    while (i < *people)
    {
        *orderChoice = *maxInt;
        printf("\nPlayer %d\n", i + 1);
        while (*orderChoice != 0)
        {
            int x = 0;
            printf("Choice %d: \n", ++choice);
            scanf("%d", &x);
            if (x <= *maxInt && x >= 0)
            {
                ls[x - 1] += *orderChoice;
                --*orderChoice;
            }
            else 
            {
                exit(0);
            }
        }
        choice = 0;
        ++i;
    }
}


int main(int argc, char *argv[]) {
   
  int people = 0;
  int orderChoice = 0;
  
  
  int *points = (int *)calloc(foodMenu, sizeof(int));

  printf ("\"What to eat today?\" A Democratic Game Program!\n");
  printf("\nEnter the number of people participating: ");
  scanf("%d", &people);
  
  int maxInt = 5;
  menu();
  
  Order(points, &people, &orderChoice, &maxInt);
  
  int a = shortList(points);
  char** shortlisted = getShortlistedList(a, points);
  
  if(a == 0)
  {
      printf("\nYou are eating at home/dorm today!\n");
      exit(0);
  }
  
  printf("\nFor round 2 make a selection from the shortlisted list above\n");
  
  int *points2= (int *)calloc(a, sizeof(int));
  orderChoice = 0;
  Order(points2, &people, &orderChoice, &a);
  
  makeFinalSelection(shortlisted, points2, a);

  return 0;
}
