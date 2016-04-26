# include "stdio.h"

/**
 * build so file ; move to  android/system/bin
 *    use function system(maexec); to create file in system when have no root permition
 */
int main(int argc,char * argv[]){
    //open ths file by write mode
    //if this file exist,clear file content
    //else create a new file
    fclose(fopen("jniDemo","w"));
    return 0;
}
