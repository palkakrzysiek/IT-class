#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[]) {
    char tracks[][80] = {
        "I left my heart in Harvard Med School",
        "Newark, Newark - a wonderful town",
        "Dancing with a Dork",
        "From here to maternity",
        "The girl from Iwo Jima",
    };
    printf("%d\n", strlen(tracks[3]));
}
