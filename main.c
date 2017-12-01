//
//  main.c
//  HYoshidaThreeNPlusOne
//
//  Created by Hideaki Yoshida on 2017/02/21.
//  Copyright © 2017年 Hideaki Yoshida. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

int computeMaxSequenceLength(int in1,int in2);
int computeSequenceLength(int n);
int computeNextValue(int n);


int main(int argc, const char * argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    
    char buffer[101];
    char outFilename[101];
    FILE *outFile;
    int nameLength;
    int in1;
    int in2;
    
    
    printf("Enter the output filename\n");
    fgets(outFilename, 100, stdin);
    nameLength = (int) strlen(outFilename);
    outFilename[nameLength-1] = '\0';
    outFile = fopen(outFilename, "w");
    in1 = atoi(fgets(buffer, 101, stdin));
    do {
        if(buffer[0] != '\n'){
            in2 = atoi(fgets(buffer, 101, stdin));
            int ml = computeMaxSequenceLength(in1,in2);
            fprintf(outFile, "%d\t%d\t%d\n", in1,in2,ml);
        }else break;
    } while (1);

    fclose(outFile);
    printf("Complete\n");
    
    return 0;
}

int computeMaxSequenceLength(int in1,int in2){
    int i;
    int n = 0;
    int max = 1;
    for(i = in1;i <= in2;i++){
        n = computeSequenceLength(i);
        if(n > max)
            max = n;
    }
    return max;
}

int computeSequenceLength(int n){
    int length = 1;
    while(n != 1){
        n = computeNextValue(n);
        length++;
    }
    return length;
}
int computeNextValue(int n){
    if(n % 2 == 0)
        n = n / 2;
    else
        n = 3 * n + 1;
    return n;
}
