#include "Header.h"

int checkinput(int min, int max) {
	int a;
	printf_s("%s%d%s%d%s", "Введите целое чисоо принадлежащее промежутку [", min, " : ", max, "]\n");
	while (scanf_s("%d", &a) != 1 || getchar() != '\n' || a < min || a > max) {
		printf_s("%s");
		rewind(stdin);
	}
	return a;
}
void add_one(Book* my_array, int number) {
	my_array[number].author = (char*)malloc(sizeof(char) * 100);
	my_array[number].name = (char*)malloc(sizeof(char) * 100);
	printf_s("%s", "Введите название книги\n");
	fgets(my_array[number].name, 100, stdin);
	my_array[number].name[strlen(my_array[number].name)] = '\0';
	rewind(stdin);
	printf_s("%s", "Введите название автора\n");
	fgets(my_array[number].author, 100, stdin);
	my_array[number].author[strlen(my_array[number].author)] = '\0';
	rewind(stdin);
	printf_s("%s", "Введите колличество страниц в книге\n");
	my_array[number].kol_str = checkinput(1, 5000);
	rewind(stdin);
}
void show(Book* my_array, int size) {
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			printf_s("%d%s", i + 1, ") ");
			printf_s("%s", "Название книги: ");
			for (int j = 0; j < strlen(my_array[i].name); j++) {
				printf_s("%c", my_array[i].name[j]);
			}
			printf_s("%s", "Автор книги: ");
			for (int j = 0; my_array[i].author[j] != '\0'; j++) {
				printf_s("%c", my_array[i].author[j]);
			}
			printf_s("%s%d%c", "Колличество страниц в книге: ", my_array[i].kol_str, '\n');
		}
	}
	else {
		printf_s("%s", "Массив структур пуст\n");
	}
}
Book* take_struct(int* kol) {
	printf("Введите количество книг: ");
	rewind(stdin);
	int ans = checkinput(1, 100);
	*kol = ans;
	Book* my_array = (Book*)malloc(ans * sizeof(Book));
	for (int i = 0; i < ans; i++) {
		add_one(my_array, i);
	}
	return my_array;
}
int menu() {
	printf_s("%s", "Введите 0, что бы завершить работу\n");
	printf_s("%s", "Введите 1, что бы инециализировать новый массив структур\n");
	printf_s("%s", "Введите 2, что бы вывести массив структур\n");
	printf_s("%s", "Введите 3, что бы инециализировать новый n-й элемент структуры\n");
	printf_s("%s", "Введите 4, что бы отсортироваить массив структур по убыванию страниц\n");
	printf_s("%s", "Введите 5, что бы отсортировать массив структу по названию книг\n");
	printf_s("%s", "Введите 6, что бы отсортировать массив структу по автору\n");
	return (checkinput(0, 6));
}
void sort_name(Book* my_array, int size) {
	if (size > 0) {
		int i, j;
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if (strcmp(my_array[i].name, my_array[j].name) > 0) {
					char* dp = my_array[i].name;
					my_array[i].name = my_array[j].name;
					my_array[j].name = dp;

					dp = my_array[i].author;
					my_array[i].author = my_array[j].author;
					my_array[j].author = dp;

					int dp1 = my_array[i].kol_str;
					my_array[i].kol_str = my_array[j].kol_str;
					my_array[j].kol_str = dp1;
				}
			}
		}
		show(my_array, size);
	}
	else {
		printf_s("%s", "Массив структур пуст");
	}
}
void sort_author(Book* my_array, int size) {
	if (size > 0) {
		int i, j;
		for (i = 0; i < size - 1; i++) {
			for (j = i + 1; j < size; j++) {
				if (strcmp(my_array[i].author, my_array[j].author) > 0) {
					char* dp = my_array[i].name;
					my_array[i].name = my_array[j].name;
					my_array[j].name = dp;

					dp = my_array[i].author;
					my_array[i].author = my_array[j].author;
					my_array[j].author = dp;

					int dp1 = my_array[i].kol_str;
					my_array[i].kol_str = my_array[j].kol_str;
					my_array[j].kol_str = dp1;
				}
			}
		}
		show(my_array, size);
	}
	else {
		printf_s("%s", "Массив структур пуст");
	}
}
void sort_str(Book* my_array, int size) {
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			int p = i;
			while (p > 0 && my_array[p].kol_str > my_array[p - 1].kol_str) {
				char* dp = my_array[p].name;
				my_array[p].name = my_array[p - 1].name;
				my_array[p - 1].name = dp;

				dp = my_array[p].author;
				my_array[p].author = my_array[p - 1].author;
				my_array[p - 1].author = dp;

				int dp1 = my_array[p].kol_str;
				my_array[p].kol_str = my_array[p - 1].kol_str;
				my_array[p - 1].kol_str = dp1;
				p--;
			}
		}
		show(my_array, size);
	}
	else {
		printf_s("%s", "Массив структур пуст");
	}
}
void free_array(Book* students, int size) {
	for (int i = 0; i < size; i++) {
		free(students[i].name);
		free(students[i].author);
	}
	free(students);
}
