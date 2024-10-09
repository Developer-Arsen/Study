#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <emscripten.h>

#define PORT 3006
#define SERVER_ADDR "127.0.0.1"

// Function to send data to the server
EMSCRIPTEN_KEEPALIVE
void send_data(const char *message) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        close(sock);
        return;
    }

    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    char buffer[1024] = {0};
    int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        printf("Received from server: %s\n", buffer);
    }

    close(sock);
}

// Dummy function to initialize WebAssembly module
EMSCRIPTEN_KEEPALIVE
void init() {
    printf("WebAssembly Module Initialized\n");
}
