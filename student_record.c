#include <stdio.h>
struct Student
{
    int roll;
    char name[50];
    int marks;
};

void writeOnDoc(struct Student *s, int n)
{
    FILE *fp = fopen("Students.txt", "w");
    if (fp == NULL)
    {
        printf("The file cannot be created");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%s %d %d\n", s[i].name, s[i].roll, s[i].marks);
        }
        fclose(fp);
    }
}
void appendOnDoc(struct Student *s, int n)
{
    FILE *fp = fopen("Students.txt", "a");
    if (fp == NULL)
    {
        printf("The file cannot be created");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "\n%s %d %d\n", s[i].name, s[i].roll, s[i].marks);
        }
        fclose(fp);
    }
}
void readFromDoc()
{
    FILE *fp = fopen("Students.txt", "r");
    if (fp == NULL)
    {
        printf("The file can't be read maybe its not exists!");
    }
    struct Student s;
    printf("\n--- Student Records from File ---\n");
    while (fscanf(fp, " %49s %d %d", s.name, &s.roll, &s.marks) != EOF)
    {
        printf("Name: %s, Roll: %d, Marks: %d\n", s.name, s.roll, s.marks);
    }
}
int main()
{
    int numberOfstudent, n;
    printf("Enter 1 to CREATE FILE\n");
    printf("Enter 2 to ADD THE INFO\n");
    printf("Enter 3 to SEE DATA\n");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("Enter the number of student: ");
        scanf("%d", &numberOfstudent);
        struct Student students[100];
        for (int i = 0; i < numberOfstudent; i++)
        {
            printf("ROLL: ");
            scanf("%d", &students[i].roll);
            printf("MARKS: ");
            scanf("%d", &students[i].marks);
            printf("NAME: ");
            scanf(" %[^\n]", students[i].name);
        }
        writeOnDoc(students, numberOfstudent);
        printf("Student details are successfully saved!\n");
    }
    else if (n == 2)
    {
        printf("Enter the number of student: ");
        scanf("%d", &numberOfstudent);
        struct Student students[100];
        for (int i = 0; i < numberOfstudent; i++)
        {
            printf("ROLL: ");
            scanf("%d", &students[i].roll);
            printf("MARKS: ");
            scanf("%d", &students[i].marks);
            printf("NAME: ");
            scanf(" %[^\n]", students[i].name);
        }
        appendOnDoc(students, numberOfstudent);
        printf("Data is successfully added!\n");
    }
    else if (n == 3)
    {
        readFromDoc();
        printf("Data fatched successfully");
    }
    else
    {
        printf("Enter valid number!");
    }
    return 0;
}