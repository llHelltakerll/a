#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef struct {
	char* name;
	char* author;
	int kol_str;

} Book;

int checkinput(int, int);
void add_one(Book*, int);
void show(Book*, int ze);
Book* take_struct(int*);
int menu();
void sort_name(Book*, int);
void sort_author(Book*, int);
void sort_str(Book*, int);
void free_array(Book*, int);

