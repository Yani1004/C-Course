#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int anagram(char word1[],char word2[]) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int *visited = (int *)malloc(len2 * sizeof(int));
    if (len1 != len2) {
        free(visited);
        return 0;
    }

    for (int i = 0; i < len2; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < len1; i++) {
        int found = 0;
        for (int j = 0; j < len2; j++) {
            if (word1[i] == word2[j] && !visited[j]) {
                visited[j] = 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            free(visited);
            return 0;
        }
    }

    free(visited);
    return 1;
}

int main() {
    int isAnagram = anagram("listen", "silent");
    printf("%d\n", isAnagram);
    return 0;
}
