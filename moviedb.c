/**************************************************************
Tom Chiapete
May 5, 2008
***************************************************************/

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void insertMovie(void);
void menu(void);
void countMoviesInYear(void);
void deleteMovie(void);
void viewAllTitles(void);

// Movie data structure
struct Movie 
{
	char id [6];
	char title [100];
	char year [4];
};

// Movie (m) object
struct Movie m [20];
int currentNumber = 0; 

// Insert movie 
void insertMovie(void)
{
	printf("---INSERT MOVIE---\n");
	printf("Enter title of movie:  ");
	scanf("%s", m[currentNumber].title);
	printf("\nEnter movie release year:  ");
	scanf("%s", m[currentNumber].year);
	printf("\nEnter ID:  ");
	scanf("%s", m[currentNumber].id);
	printf("\n");	
	//printf("Title: %s",m[0].title);	
	currentNumber++;
	menu();
}

// View All Titles
void viewAllTitles(void)
{

	int x = 0;
	for (; x <= 20;)
	{
		scanf("%s", m[x].title);
		x++;
	}
	menu();
}

// Count movies in a given year (input)
void countMoviesInYear(void)
{
	char year [4];
	printf("---NUMBER OF MOVIES IN A GIVEN YEAR---\n");
	printf("Enter a year:  ");
	scanf("%s", year);
	
	int counter = 0;
	int x = 0;
	for (; x <= 20;)
	{
		if (strcmp(m[x].year, year) == 0)
		{
			counter++;
		}
		x++;
	}
	printf("Found %d movies in the year given.",counter);
	menu();
}

// Delete movie from array
void deleteMovie(void)
{
	printf("---DELETE MOVIE---\n");
	int x = 0;
	int option;
	for (; x <= 20;)
	{
		printf(m[x].id);
		printf(" - ");
		printf(m[x].title);
		printf("\n");
	}	
	print("\nPlease enter digit:  ");
	scanf("%d", &option);

	//m[option].title = "\0";
	//m[option].id = "\0";
	//m[option].year = "\0";
	
	// Clear char arrays for given option index
	memset(m[option].id, 0, 6);
	memset(m[option].title, 0, 100);
	memset(m[option].year, 0, 4);
	
	menu();
}

// Main
int main (void)
{
	menu();
	return 0;
}

// Menu
void menu(void)
{
	int option;
	do
	{
		printf("SELECT AN OPTION:\n");
		printf("1 - View all titles\n");
		printf("2 - Find number of titles in given year\n");
		printf("3 - Insert a new movie to the list\n");
		printf("4 - Delete a movie from the list\n");
		printf("5 - Exit\n");
		printf("Choice:  >>> ");
		scanf("%d", &option);
		printf("\n");
	} 
	while (option != 5);
	
	switch(option)
	{
		case 1: viewAllTitles(); break;
		case 2: countMoviesInYear(); break;
		case 3: insertMovie(); break;
		case 4: deleteMovie(); break;
	}
}

         
