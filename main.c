#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <readline/readline.h>
#include <readline/history.h>

void expr();
void match(char c);
void term();
void rest();

char *line;
char *current;

int main () {
	while (true) {
		line = readline("> ");
		if (!line) {
			printf("Exit Program!\n");
			exit(EXIT_SUCCESS);
		}
		if (*line == '\0') {
			continue;
		}
		
		current = line;
		expr();
		printf("\n");
		add_history(line);
		free(line);
	}

	exit(EXIT_SUCCESS);
}

void expr() {
	term(); rest();
}

void term() {
	if (isdigit(*current)) {
		printf("%c", *current++);
		return;
	}
	
	printf("\nSyntax error\n");
	exit(EXIT_FAILURE);
}

void rest() {
	if (*current == '\0') {
		return;
	}

	if (*current == '+' || *current == '-') {
		char c = *current++;
		term();
		printf("%c", c);
		rest();
		return;
	}

	if (!isdigit(*current)) {
		printf("\nSyntax error\n");
		exit(EXIT_FAILURE);
	}
}
