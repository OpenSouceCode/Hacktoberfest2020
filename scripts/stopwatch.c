
edit
play_arrow

brightness_4
// C code to create stop watch 
  
// Header file for necessary system library 
#include <fcntl.h> 
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <termios.h> 
#include <unistd.h> 
  
// starting from zero 
#define MIN 0 
  
// 1 hr= 60 min ; 1 min= 60 sec 
#define MAX 60 
  
#define MILLI 200000 
  
int i, j, k, n, s; 
char c; 
pthread_t t1; 
  
// Function to perform operations 
// according keyboeard hit. 
int keyboardhit(void) 
{ 
    struct termios oldt, newt; 
    int ch; 
    int oldf; 
  
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt; 
    newt.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0); 
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); 
  
    ch = getchar(); 
  
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    fcntl(STDIN_FILENO, F_SETFL, oldf); 
  
    if (ch != EOF) { 
        ungetc(ch, stdin); 
        return 1; 
    } 
  
    return 0; 
} 
  
// display stopwatch on screen 
void print() 
{ 
    // clear screen escape sequence 
    printf("\033[2J\033[1;1H"); 
  
    // Display Hour Min Sec in screen 
    printf("TIME\t\t\t\tHr: %d Min: %d Sec: %d", n, i, j); 
} 
  
// function to pause stopwatch 
void* wait(void* arg) 
{ 
  
    while (1) { 
  
        // wait for keyboard signal if keyboard 
        // hit it return non integer number 
        if (keyboardhit()) { 
            // take input from user and do 
            // operation accordingly 
            c = getchar(); 
            if (c == 'S' || c == 's') { 
                break; 
            } 
            else if (c == 'r' || c == 'R') { 
                s = 1; 
                break; 
            } 
            else if (c == 'e' || c == 'E') 
  
                exit(0); 
        } 
    } 
} 
  
// driver code 
int main() 
{ 
  
    // label to reset the value 
reset: 
    n = MIN; 
    i = MIN; 
    j = MIN; 
    k = MIN, s = MIN; 
  
    print(); 
  
    while (1) { 
  
        /* s for start 
        e for exit 
        p for pause 
        r for reset 
        */
        if (keyboardhit()) { 
            c = getchar(); 
  
            if (c != 's') 
                continue; 
  
            for (n = MIN; n < MAX; n++) { 
                for (i = MIN; i < MAX; i++) { 
                    for (j = MIN; j < MAX; j++) { 
                        for (k = MIN; k < MILLI; k++) { 
                        start: 
                            print(); 
                            if (keyboardhit()) { 
                                c = getchar(); 
  
                                if (c == 'r' || c == 'R') 
                                    goto reset; 
                                else if (c == 'e' || c == 'E') 
                                    exit(0); 
                                else if (c == 's' || c == 'S') 
                                    goto start; 
                                else if (c == 'P' || c == 'p') { 
  
                                    pthread_create(&t1, NULL, &wait, NULL); 
  
                                    // waiting for join a thread 
                                    pthread_join(t1, NULL); 
                                    if (s == 1) 
                                        goto reset; 
                                } 
                            } 
                        } 
                    } 
                } 
            } 
        } 
    } 
  
    return 0; 
} 
