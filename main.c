#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20

int numCandidates;
int generation = 0;

struct Candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
};

struct Candidate* candidates;

void vote(struct Candidate* candidates);
void displayResults(struct Candidate* candidates);
void showLeadingCandidate(struct Candidate* candidates);
struct Candidate* generateCandidates(int count);

int main() {
    system("@cls||clear");
    printf("Welcome to the Election Simulation\n");

    if (generation == 0) {
        printf("How many candidates would you like to include?\n");
        scanf("%d", &numCandidates);
        candidates = generateCandidates(numCandidates);
        generation = 1;
    }

    while (1) {
        int choice;
        printf("\n1 - View Results\n");
        printf("2 - Vote\n");
        printf("3 - Leading Candidate\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayResults(candidates);
        }
        else if (choice == 2) {
            vote(candidates);
        }
        else if (choice == 3) {
            showLeadingCandidate(candidates);
        }
        else if (choice == 4) {
            system("@cls||clear");
            printf("Thank you for using the election simulation.\n");
            break;
        }
        else {
            system("@cls||clear");
            printf("Invalid choice. Please try again.\n");
        }
    }

    free(candidates);
    return 0;
}

void vote(struct Candidate* candidates) {
    system("@cls||clear");
    printf("Vote for your favorite candidate:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d - %s\n", i + 1, candidates[i].name);
    }
    printf("0 - Back\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice >= 1 && choice <= numCandidates) {
            candidates[choice - 1].votes++;
        }
        else if (choice == 0) {
            system("@cls||clear");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayResults(struct Candidate* candidates) {
    system("@cls||clear");
    printf("Election Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d - %s: Votes - %d\n", i + 1, candidates[i].name, candidates[i].votes);
    }
    printf("0 - Back\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 0) {
            system("@cls||clear");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void showLeadingCandidate(struct Candidate* candidates) {
    system("@cls||clear");

    int leadingIndex = 0;
    bool isTie = false;

    for (int i = 1; i < numCandidates; i++) {
        if (candidates[i].votes > candidates[leadingIndex].votes) {
            leadingIndex = i;
            isTie = false;
        }
        else if (candidates[i].votes == candidates[leadingIndex].votes) {
            isTie = true;
        }
    }

    if (isTie) {
        printf("Multiple candidates are leading the race with %d votes.\n", candidates[leadingIndex].votes);
    }
    else {
        printf("%s is leading the race with %d votes.\n", candidates[leadingIndex].name, candidates[leadingIndex].votes);
    }

    printf("0 - Back\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 0) {
            system("@cls||clear");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

struct Candidate* generateCandidates(int count) {
    struct Candidate* candidate = (struct Candidate*)malloc(count * sizeof(struct Candidate));
    if (candidate == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        candidate[i].votes = 0;
        sprintf(candidate[i].name, "Candidate %d", i + 1);
    }

    return candidate;
}
