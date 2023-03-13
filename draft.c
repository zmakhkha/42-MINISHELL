#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100

// function to check if a character is a whitespace character
int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// function to tokenize the input string
int tokenize(char *input, char *tokens[]) {
    int num_tokens = 0;
    int len = strlen(input);
    int i = 0;
    
    while (i < len) {
        // skip whitespace characters
        while (i < len && is_whitespace(input[i])) {
            i++;
        }
        
        if (i == len) {
            break;
        }
        
        int j = i;
        // check if the token is a shell command
        if (input[j] != '|' && input[j] != '&' && input[j] != ';' && input[j] != '(' && input[j] != ')') {
            while (j < len && !is_whitespace(input[j]) && input[j] != '|' && input[j] != '&' && input[j] != ';' && input[j] != '(' && input[j] != ')') {
                j++;
            }
            tokens[num_tokens] = malloc(j - i + 1);
            strncpy(tokens[num_tokens], input + i, j - i);
            tokens[num_tokens][j - i] = '\0';
            num_tokens++;
        }
        // check if the token is an operator
        else {
            if (j < len - 1 && input[j] == '|' && input[j + 1] == '|') {
                tokens[num_tokens] = malloc(3);
                strncpy(tokens[num_tokens], "||", 2);
                tokens[num_tokens][2] = '\0';
                num_tokens++;
                i += 2;
            }
            else if (j < len - 1 && input[j] == '&' && input[j + 1] == '&') {
                tokens[num_tokens] = malloc(3);
                strncpy(tokens[num_tokens], "&&", 2);
                tokens[num_tokens][2] = '\0';
                num_tokens++;
                i += 2;
            }
            else {
                tokens[num_tokens] = malloc(2);
                tokens[num_tokens][0] = input[j];
                tokens[num_tokens][1] = '\0';
                num_tokens++;
                i++;
            }
        }
    }
    return num_tokens;
}

// sample usage of the tokenize function
int main() {
    char input[100];
    char *tokens[MAX_TOKENS];
    int num_tokens;
    
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input
    
    num_tokens = tokenize(input, tokens);
    
    printf("Number of tokens: %d\n", num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        printf("Token %d: %s\n", i+1, tokens[i]);
        free(tokens[i]); // free memory allocated for each token
    }
    
    return 0;
}
