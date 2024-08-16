#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mtx;
pthread_key_t key;

// Function to write the response data into a string
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t totalSize = size * nmemb;
    char *data = (char *)contents;
    strncat(userp, data, totalSize);
    return totalSize;
}

int step = 0;

void * getData(int c) {
    for (size_t i = c * step + 1; i <= (c + 1) * step; i++)
    {
        char request[200] = {0};
        char file[200] = {0};
        sprintf(request, "https://jsonplaceholder.typicode.com/todos/%ld", i);
        sprintf(file, "./%d.txt", c);

        CURL *curl;
        CURLcode res;
        char response[2028] = {0}; 

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, request);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

            res = curl_easy_perform(curl);

            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            } else {
                printf("Response: %s\n", response);
            }

            curl_easy_cleanup(curl);
        }

        FILE * stream = fopen(file, "a+");
        fwrite(response, strlen(response), 1, stream);
        fclose(stream);
    }
}

int count = -1;
void * test(void*arg) {
    pthread_mutex_lock(&mtx);
    count++;
    pthread_mutex_unlock(&mtx);
    
    getData(count);
}

int main(void) {
    int n = 0;
    printf("enter threads count \n");
    scanf("%d", &n);

    step = 150 / n;
    pthread_mutex_init(&mtx, NULL);
    pthread_t tid[5];
    for (size_t i = 0; i < n; i++)
    {
        pthread_create(&tid[i], NULL, test, NULL);
    }

    for (size_t i = 0; i < n; i++)
    {
        pthread_join(tid[i], NULL);
    }
   
    pthread_mutex_destroy(&mtx);

    // FILE * file = fopen("./0.txt", "r+");

    // for (size_t i = 1; i <= 150; i++)
    // {
    //     char request[200] = {0};
    //     char file[200] = {0};
    //     sprintf(request, "https://jsonplaceholder.typicode.com/todos/%ld", i);
    //     sprintf(file, "./%d.txt", 1);

    //     CURL *curl;
    //     CURLcode res;
    //     char response[2028] = {0}; 

    //     curl = curl_easy_init();
    //     if (curl) {
    //         curl_easy_setopt(curl, CURLOPT_URL, request);
    //         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    //         curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

    //         res = curl_easy_perform(curl);

    //         if(res != CURLE_OK) {
    //             fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    //         } else {
    //             printf("Response: %s\n", response);
    //         }

    //         curl_easy_cleanup(curl);
    //     }

    //     FILE * stream = fopen(file, "a+");
    //     fwrite(response, strlen(response), 1, stream);
    //     fclose(stream);
    // }
   
    // getData(NULL);
    // getData(NULL);
    // getData(NULL);
    // getData(NULL);
    // getData(NULL);
}
