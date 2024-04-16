#include <stdio.h>
#include <stdbool.h>

// Kevin Li
// N00969115

/*  Obtains a string from command line input. Returns the length of the string. */
size_t krgetline(char s[], size_t lim) {
    /*  initializes variables. 
        c will store the ascii value of a character 
        i will be the length of the string  */
    int c; size_t i;
    
    /*  For each character the user enters, the string array s passed in through argument
        will be populated with that character in succession, until end of file or a new line 
        character is encountered. 
        
        Without checking if the next character is \n, a new line will be unintendedly 
        input into the command line.*/
    for (i = 0; (i < lim - 1 && (c = getchar()) != EOF && c != '\n'); i++)
        s[i] = c;
    // If the current character is \n, sets s at index i to \n and increments i for the next step.
    if ('\n' == c) {
        s[i] = c;
        i++;
    }
    // Introduces the null escape character to finalize a proper string.
    s[i] = '\0';
    
    // returns length of the string read.
    return i;
}
/*  Returns true if the digit c is a number, false if not.*/
bool myisdigit(char c) {
    /*  If the ASCII value of the character is not between the 
        ASCII value of 0 and 9 inclusive, the character is not a number.*/
    if (c >= '0' && c <= '9')
        return true;
    return false;
}
/*  Converts a string to an integer, up until the first non-number character.
    1234 returns 1234.
    123A returns 123.
    1A34 returns 1.
    ABCD returns 0.
    */
int myAToI(char s[]) {
    int total = 0, i = 0;

    // loop stops immediately when the next character is not a digit.
    for (; myisdigit(s[i]); i++) {
        /*  loops through the string, converting it to its numeric counterpart.
            the multiplication by 10 serves to "move the number to the left", 
            shifting from the ones place to the tens place, or the tens place
            to the hundreds place for example. 
            
            4 -> 40, 73 -> 730
            
            The next character is then converted to its numerical counterpart
            and then added to the next number, continuing until a letter or 
            a null escape is reached */
        total = 10 * total + (s[i] - '0');
    }
    return total;
}
/*  Compares strings to each other at the first character in which they are not equal.
    abcd compared to bbcd returns -1. 
    cbcd compared to abcd returns 2.
    */
int mystrcmp(const char s[], const char t[]) {
    size_t i = 0;

    // Loops through both char arrays until the characters at the index are not equal.
    for (; s[i] == t[i]; i++) {
        /*  if a null escape character is encountered, the strings are equal
            due to the previous condition of both characters at index i being equal.*/
        if (s[i] == '\0')
            return 0;
    }
    // Returns the difference between the character in the first string and the character in the second.
    return s[i] - t[i];
}

int main(void) {
    // Creates variables to compare input strings against, containing the desired inputs
    const char CSTRING[] = "Kevin";
    const int LASTFOUR = 9115;
    // Variable storing user input strings and string length
    char test[40];
    size_t size;

    puts("Please enter a String (Case Sensitive):");
    //  Prompts users to enter a string input and stores said string in test
    //  stores the size of the string entered by the user, since mystrlen can't be used
    size = krgetline(test, 40);

    /*  krgetline will store a \n character after taking input, 
        which will make the strings unequal even if the letters are identical.
        this code will replace the newline with a null terminator
        so that it can be properly compared to CSTRING. */
    if (test[size - 1] == '\n')
        test[size - 1] = '\0';

    /*  If test doesn't match CSTRING, prompts user for new input until it does.
        Will output the difference between the two strings from the first point where the characters are different.*/
    while (mystrcmp(test, CSTRING) != 0) {
        printf("The difference between your input and the correct one is %d. Please try again.\n", mystrcmp(test, CSTRING));
        size = krgetline(test, 40);
        /*  Does the same thing as above at the end of the while loop
            so the newly updated user input will have the newline removed
            just in time for the while loop to evaluate equality */ 
        if (test[size - 1] == '\n')
            test[size - 1] = '\0';
    }
    //  Prompts users to enter a number input and stores the string in test[]
    puts("Please enter a number:");
    size = krgetline(test, 40);
    //  If the parsed string doesn't match LASTFOUR, prompts user for new input until it does.
    while (myAToI(test) != LASTFOUR) {
        printf("Incorrect. Please try again.\n");
        size = krgetline(test, 40);
    }
    puts("Success!");
}