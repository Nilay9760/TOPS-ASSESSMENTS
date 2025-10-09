/*
*
*
*

Create an application that can perform all string related operations  Make sure each business logic is denoted with appropriate comments and make your code interactive and represent clean and clear output on your console screen. Adhere to the coding principles  It should be a menu driven approach, for which you are suppose to use the functions concept  Over Here, take string input from user and perform string operations listed below :

reverse a string
Concatenation
Palindrome
Copy  a string
Length of the string
Frequency of character in s string
Find number of vowels and consonants
Find number of blank spaces and digits

As given above perform the operation as per user’s choice  If user will not select any of the above then it should not perform any operation and  give an appropriate user friendly message  After performing the operation ask the user if the user wants to continue or not ? 

*
*
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void reverseString(char str[]);
void concatenateStrings(char str[]);
void checkPalindrome(char str[]);
void copyString(char str[]);
void stringLength(char str[]);
void charFrequency(char str[]);
void countVowelsConsonants(char str[]);
void countSpacesDigits(char str[]);

int main() {
    char str[200];
    int choice;
    char cont;

    printf("===== STRING OPERATIONS APPLICATION =====\n");

    // Take initial string input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    do {
        // Display menu
        printf("\n========= MENU =========\n");
        printf("1. Reverse the string\n");
        printf("2. Concatenate another string\n");
        printf("3. Check Palindrome\n");
        printf("4. Copy the string\n");
        printf("5. Length of the string\n");
        printf("6. Frequency of a character\n");
        printf("7. Count vowels and consonants\n");
        printf("8. Count blank spaces and digits\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        // Perform operation based on choice
        switch(choice) {
            case 1: reverseString(str); break;
            case 2: concatenateStrings(str); break;
            case 3: checkPalindrome(str); break;
            case 4: copyString(str); break;
            case 5: stringLength(str); break;
            case 6: charFrequency(str); break;
            case 7: countVowelsConsonants(str); break;
            case 8: countSpacesDigits(str); break;
            default: printf("\nInvalid choice! Please select from the menu.\n");
        }

        // Ask if user wants to continue
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &cont);
        getchar(); // Clear newline

    } while (cont == 'y' || cont == 'Y');

    printf("\nThank you for using the String Operations Application!\n");
    return 0;
}

// 1. Reverse a string
void reverseString(char str[]) {
    int len = strlen(str);
    printf("\nReversed string: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// 2. Concatenate another string
void concatenateStrings(char str[]) {
    char temp[200];
    printf("Enter another string to concatenate: ");
    fgets(temp, sizeof(temp), stdin);
    temp[strcspn(temp, "\n")] = '\0';
    strcat(str, temp);
    printf("After concatenation: %s\n", str);
}

// 3. Check if string is palindrome
void checkPalindrome(char str[]) {
    int len = strlen(str);
    int flag = 1;
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("The string is a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");
}

// 4. Copy a string
void copyString(char str[]) {
    char copy[200];
    strcpy(copy, str);
    printf("Copied string: %s\n", copy);
}

// 5. Length of the string
void stringLength(char str[]) {
    printf("Length of the string: %lu\n", strlen(str));
}

// 6. Frequency of a character
void charFrequency(char str[]) {
    char ch;
    int count = 0;
    printf("Enter the character to find frequency: ");
    scanf(" %c", &ch);
    getchar();
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            count++;
    }
    printf("Frequency of '%c': %d\n", ch, count);
}

// 7. Count vowels and consonants
void countVowelsConsonants(char str[]) {
    int vowels = 0, consonants = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}

// 8. Count blank spaces and digits
void countSpacesDigits(char str[]) {
    int spaces = 0, digits = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i]))
            spaces++;
        else if (isdigit(str[i]))
            digits++;
    }
    printf("Spaces: %d, Digits: %d\n", spaces, digits);
}
