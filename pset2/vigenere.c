#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
 
int main(int argc, string argv[])
{
    if (argc != 2 )
        {
            printf("incorrect command-line argument\n");
            return 1;
        }
       
    string key = argv[1];
    int len = strlen(key);
 
    //Check to see if key was correctly entered
    
    for(int j = 0; j < len; j++)    
        {
            if(!isalpha(key[j]))
                {
                    printf("incorrect command-line argument: letters only\n");
                    return 1;
                }
        }
        
    string pt = get_string();
    
    for(int i = 0, n = strlen(pt); i < n; i++)
        {
               
             if(isalpha(pt[i]))
                 {  
                     if(isupper(pt[i]))
                         {
                              pt[i] -= 'A';
                              pt[i]=(pt[i]+(key[i%len]) - 'A')%26;
                              printf("%c", pt[i]+ 'A');
                         }
            
                    if(islower(pt[i]))
                         {
                              pt[i] -= 'a';
                              pt[i]=(pt[i]+(key[i%len]) - 'a')%26;
                            //   printf("%d\n",pt[i]);
                              printf("%c", pt[i]+'a');
                         }
                  }
        }
       
    printf("\n");
    return 0;
}