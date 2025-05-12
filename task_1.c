#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[100];

    // -------- Create/Write to a File --------
    fp = fopen("example.txt", "w"); // Open file in write mode (creates new or overwrites)
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter text to write to the file:\n");
    fgets(data, sizeof(data), stdin); // Read input from user
    fputs(data, fp); // Write data to file
    fclose(fp); // Close file
    printf("Data written to file successfully.\n\n");

    // -------- Append to the File --------
    fp = fopen("example.txt", "a"); // Open file in append mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Enter text to append to the file:\n");
    fgets(data, sizeof(data), stdin); // Read more input
    fputs(data, fp); // Append data
    fclose(fp); // Close file
    printf("Data appended to file successfully.\n\n");

    // -------- Read from the File --------
    fp = fopen("example.txt", "r"); // Open file in read mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Contents of the file:\n");
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data); // Print each line from the file
    }
    fclose(fp); // Close file

    return 0;
}
