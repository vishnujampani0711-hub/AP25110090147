#include <stdio.h>

int main() {
    char student_name[50], reg_number[20], sec[5];
    float emp_salaries[10], sum = 0, average, temp;
    int total_emp, i, j, option;
    float max_salary, min_salary;
    int above_avg = 0, below_avg = 0;

    printf("===== employee salary analysis system =====\n");

    printf("enter student name: ");
    scanf(" %[^\n]", student_name);

    printf("enter registration number: ");
    scanf("%s", reg_number);

    printf("enter section: ");
    scanf("%s", sec);

    printf("enter total number of employees (max 10): ");
    scanf("%d", &total_emp);

    if (total_emp > 10) {
        printf("error: only 10 employees allowed.\n");
        return 0;
    }

    printf("enter salaries one by one:\n");
    for (i = 0; i < total_emp; i++) {
        printf("salary %d: ", i + 1);
        scanf("%f", &emp_salaries[i]);
    }

    do {
        printf("\n========== menu ==========\n");
        printf("1. show all salaries\n");
        printf("2. show total and average salary\n");
        printf("3. show highest and lowest salary\n");
        printf("4. count employees above/below average\n");
        printf("5. sort salaries in ascending order\n");
        printf("6. exit\n");
        printf("==========================\n");
        printf("choose your option: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\nall employee salaries:\n");
            for (i = 0; i < total_emp; i++) {
                printf("%.2f ", emp_salaries[i]);
            }
            printf("\n");
        }

        else if (option == 2) {
            sum = 0;
            for (i = 0; i < total_emp; i++) {
                sum += emp_salaries[i];
            }
            average = sum / total_emp;
            printf("total salary = %.2f\n", sum);
            printf("average salary = %.2f\n", average);
        }

        else if (option == 3) {
            max_salary = emp_salaries[0];
            min_salary = emp_salaries[0];
            for (i = 1; i < total_emp; i++) {
                if (emp_salaries[i] > max_salary)
                    max_salary = emp_salaries[i];
                if (emp_salaries[i] < min_salary)
                    min_salary = emp_salaries[i];
            }
            printf("highest salary = %.2f\n", max_salary);
            printf("lowest salary = %.2f\n", min_salary);
        }

        else if (option == 4) {
            sum = 0;
            for (i = 0; i < total_emp; i++) {
                sum += emp_salaries[i];
            }
            average = sum / total_emp;
            above_avg = 0;
            below_avg = 0;
            for (i = 0; i < total_emp; i++) {
                if (emp_salaries[i] > average)
                    above_avg++;
                else if (emp_salaries[i] < average)
                    below_avg++;
            }
            printf("average salary = %.2f\n", average);
            printf("above average = %d\n", above_avg);
            printf("below average = %d\n", below_avg);
        }

        else if (option == 5) {
            for (i = 0; i < total_emp - 1; i++) {
                for (j = 0; j < total_emp - i - 1; j++) {
                    if (emp_salaries[j] > emp_salaries[j + 1]) {
                        temp = emp_salaries[j];
                        emp_salaries[j] = emp_salaries[j + 1];
                        emp_salaries[j + 1] = temp;
                    }
                }
            }
            printf("sorted salaries:\n");
            for (i = 0; i < total_emp; i++) {
                printf("%.2f ", emp_salaries[i]);
            }
            printf("\n");
        }

        else if (option == 6) {
            printf("exiting program...\n");
        }

        else {
            printf("invalid option! try again.\n");
        }

        printf("\nsubmitted by: %s | reg no: %s | section: %s\n", student_name, reg_number, sec);
        printf("challenge day 17 - code2grow program\n");

    } while (option != 6);

    return 0;
}
