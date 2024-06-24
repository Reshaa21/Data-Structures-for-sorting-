#include <stdio.h>
#include <string.h>


char* find_needle(const char* haystack, const char* needle) {
        int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    
    for (int i = 0; i <= haystack_len - needle_len; i++) {
        
        int j;
        for (j = 0; j < needle_len; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        
        if (j == needle_len) {
            return (char*)&haystack[i];
        }
    }

    
    return NULL;
}

int main() {
    
    const char* haystack = "This is a simple haystack example.";
    const char* needle = "haystack";

    
    char* result = find_needle(haystack, needle);

    
    if (result != NULL) {
        printf("Needle found at position: %ld\n", result - haystack);
    } else {
        printf("Needle not found.\n");
    }

    return 0;
}

