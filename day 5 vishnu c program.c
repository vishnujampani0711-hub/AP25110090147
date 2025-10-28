#include <stdio.h>

int main() {
    int age;
    char gender;
    int health;   // 1 for Healthy, 0 for Unhealthy
    float premium = 0.0;

    // Step 1: Accept inputs
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);

    printf("Health condition (1 for Healthy, 0 for Unhealthy): ");
    scanf("%d", &health);

    // Step 2: Determine premium based on rules
    if (age >= 25 && age <= 35) {
        if (health == 1)
            premium = 9000;
        else
            premium = 9500;
    }
    else if (age >= 36 && age <= 40) {
        if (health == 1)
            premium = 12000;
        else
            premium = 13000;
    }
    else if (age > 60 && health == 0) {
        printf("\nCustomer Result:\n");
        printf("Age: %d\nGender: %c\nHealth: Unhealthy\n", age, gender);
        printf("Not Eligible for Insurance\n");
        return 0; // stop program
    }
    else if (age > 40 && age <= 60) {
        if (health == 1)
            premium = 15000;
        else
            premium = 16000;
    }
    else {
        printf("\nCustomer Result:\n");
        printf("Age: %d\nGender: %c\n", age, gender);
        printf("Not Eligible for Insurance\n");
        return 0;
    }

    // Step 3: Apply 10% discount if female
    if (gender == 'F' || gender == 'f') {
        premium = premium - (premium * 0.10);
    }

    // Step 4: Display final result
    printf("\nCustomer Result:\n");
    printf("Age: %d\nGender: %c\n", age, gender);
    printf("Health: %s\n", (health == 1) ? "Healthy" : "Unhealthy");
    printf("Final Premium: %.2f\n", premium);

    return 0;
}
