/*
Write a program to check if entered expression containing {},[] or () is valid expression or not.
A valid parenthesis expression always has a corresponding closing bracket for every opened one.
Ex. {(([])[{()}])} is Valid parenthesis
Ex. {(([][{()}])} is Invalid parenthesis
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 50

int top=-1;
void push(int ele);
int pop();
int stackFull();
int stackEmpty();
int peek();

struct stck
{
    int val;
};
struct stck myStack[MAX_SIZE];

void push(int ele)
{
    if(top==MAX_SIZE-1)
    {
        stackFull();
        return;
    }
    myStack[++top].val=ele;
}

int pop()
{
    if(top==-1)
    {
         stackEmpty();
         return 0;
    }
    int ele=myStack[top].val;
    top--;
    return ele;
}

int peek()
{
    if(top==-1)
    {
         stackEmpty();
         return 0;
    }
    return myStack[top].val;
}

int stackFull()
{

    if(top==MAX_SIZE-1)
    {
        return 0;
    }
    return 1;
}

int stackEmpty()
{

    if(top==-1)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int n;
    printf("Enter expression in a single line:");
    char str[50];
    scanf("%s",str);
    n=strlen(str);
    if(n==0||n==1)
    {
         printf("Not Valid Expression!");
         exit(0);
    }
    int i=0;
    while(i<n)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            push(str[i]);
        else
        {
            if(str[i]==')'&&stackEmpty()!=0)
            {
                if(peek()=='(')
                    pop();
                else
                {
                    printf("Not Valid!");
                    exit(0);
                }
            }
            else if(str[i]=='}'&&stackEmpty()!=0)
            {
                if(peek()=='{')
                    pop();
                else
                {
                    printf("Not Valid!");
                    exit(0);
                }
            }
            else if(str[i]==']'&&stackEmpty()!=0)
            {
                if(peek()=='[')
                    pop();
                else
                {
                    printf("Not Valid Expression!");
                    exit(0);
                }
            }
            else
                {
                    printf("Not Valid Expression!");
                    exit(0);
                }

        }
        i++;
    }
    if(stackEmpty()==0)
        printf("\nValid Expression");
    else
        printf("\nInvalid Expression");
    return 0;
}

/*
Time complexity: Stack operations take O(1) time.
Traversing through entire string of length n takes O(n) time.
Hence overall Time Complexity of Problem: O(n)
*/
