#include "app.h"
#include "../grass/process.h"

extern int getPID();

int main(int argc, char** argv) {

    printf("ps\n");
    int i;
    for( i = 0; i < MAX_NPROCESS; i++ )
    {
     // printf(" %d %d\n", grass->proc_set[i].pid, grass->proc_set[i].status );
    }
    printf("My PID is %d\n", getPID());
    return 0;
}