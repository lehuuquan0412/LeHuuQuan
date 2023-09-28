#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    int birthYear;
} Person;

int compareNames(const void *a, const void *b) {
    return strcmp(((Person *)a)->name, ((Person *)b)->name);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Không thể mở file.\n");
        return 1;
    }

    int lineCount = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }
    printf("So str = %d\n", lineCount);

    fseek(file, 0, SEEK_SET);

    Person *people = (Person *)malloc(lineCount * sizeof(Person));
    if (people == NULL) {
        printf("Không đủ bộ nhớ.\n");
        return 1;
    }

    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%d,%d", people[i].name, people[i].id, &people[i].birthYear);
        i++;
    }

    qsort(people, lineCount, sizeof(Person), compareNames);

    int count = 1;
    for (i = 1; i < lineCount; i++) {
        if (strcmp(people[i].name, people[i - 1].name) == 0) {
            count++;
        } else {
            printf("Tên: %s - Số lượng: %d\n", people[i - 1].name, count);
            count = 1;
        }
    }

    printf("Tên: %s - Số lượng: %d\n", people[i - 1].name, count);

    free(people);
    fclose(file);

    return 0;
}
