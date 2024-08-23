#include <stdio.h>
#include <stdlib.h>

void open_url(const char *url) {
    char command[256];

    #ifdef _WIN32
        // Windows
        snprintf(command, sizeof(command), "start chrome \"%s\"", url);
    #elif __APPLE__
        // macOS
        snprintf(command, sizeof(command), "open -a \"Google Chrome\" \"%s\"", url);
    #elif __linux__
        // Linux
        snprintf(command, sizeof(command), "google-chrome \"%s\"", url);
    #else
        // Unsupported OS
        printf("Unsupported OS\n");
        return;
    #endif

    int result = system(command);

    if (result == -1) {
        printf("Failed to execute command\n");
    } else {
        printf("Chrome opened with URL: %s\n", url);
    }
}

int main() {
    const char *url = "https://drive.google.com/file/d/1X_2ZnpFAz4VXG3vbQy-HGlWeKJH-vOZ0/view?usp=sharing";
    open_url(url);
    return 0;
}
