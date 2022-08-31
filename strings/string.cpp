#include<iostream>
using namespace std;
int Strlen(char A[]) //function for finding length of given string 
{
   int i;
   for(i=0;A[i]!='\0';i++)
   {}
 //  cout<<"Length of "<<A<<" is: "<<i<<endl; //if you want to print like this, change the return type to void and remove return statement and uncomment this 
return i;
}
void Upp_to_low(char A[]) //for converting upper case to lower case
{   int i;
    for(i=0;A[i]!='\0';i++)
    A[i]=A[i]+32; //Difference b/w ASCII codes of uppercase and lower case characters is 32(eg: |A(65)-a(97)|=32)
    cout<<"After changing  alphabets from upper case to lower case: "<<A<<endl;
}
void Low_to_upp(char A[])
{
    int i;
    for(i=0;A[i]!='\0';i++)
    A[i]=A[i]-32;
    cout<<"After changing  alphabets from  lower case to upper case: "<<A<<endl;
}
void Toggle_cases(char A[]) //if lower then convert in upper and vice-versa
{
  int i;
  for(i=0;A[i]!='\0';i++)
    {
        if(A[i]>=65 && A[i]<='Z') //we can use any of these(Ascii value or alphabet)
         A[i]+=32;
        else if(A[i]>='a' && A[i]<=122)
         A[i]-=32;
    }
    cout<<"Converting upper case to lower case and vice-versa: ";
    printf("%s ",A);
    cout<<endl;
}
void count_vowels_consonants(char A[])
{  
   int vcount=0,ccount=0;
   cout<<A<<endl;
   for(int i=0;A[i]!='\0';i++)
   {
       if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U')
       vcount++;
       else if((A[i]>=65 && A[i]<=90)|| (A[i]>=97 && A[i]<=122))
       ccount++;
   }
   cout<<"Number of vowels= "<<vcount<<endl;
   cout<<"Number of consonant= "<<ccount<<endl;
}
void count_words(char A[])
{
  int word=1; //no.of words= spaces+1
   for(int i=0;A[i]!='\0';i++)
   {
       if(A[i]==' '&& A[i-1]!=' ') // the 2nd condn is to avoid counting extra spaces(called white space) that may or may not be present in the string
       word++;
   }
   cout<<"Number of words= "<<word<<endl;
}
int valid(char *name) //'A' to 'Z' , 'a' to 'z' and '0' tp '9' are valid rest invalid
{   int i;
    for(i=0;name[i]!='\0';i++)
    {
        if(!(name[i]>=65 && name[i]<=90)&& !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57)) 
        return 0; //0 implies false
    }
return 1; // 1 means true
}
void reverse1(char A[])
{
    int n,i,j;
    n=Strlen(A);
    n++; //since strlen return length before null character 
    char B[n];
    i=Strlen(A); //i contain the last index of the given array 
    i--; //since we don't need the last index value that is the null character while copying values from Array A to Array B in reverse order
    for(j=0;i>=0;i--,j++)  
    {
        B[j]=A[i];  
    }
    B[j]='\0'; //assigning null character to last index of B
    cout<<"Given Array in reverse order: "<<B<<endl;
}
void reverse2(char A[]) //using swapping
{
    int i,j;
    j=Strlen(A);
    j=j-1;
    for(i=0;i<j;i++,j--)
    {
        int t;
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    cout<<"String in reverse order is: "<<A<<endl;
}
void StrCompare(char A[],char B[])  //compares which string comes first in dictionary(returns greater for string occuring first) 
{
   int i,j;
   for(i=0,j=0;A[i]!='\0' && B[j]!='\0';i++,j++)
   {
       if(A[i]!=B[j])
       break;
   }
   if(A[i]==B[j])
   cout<<"equal"<<endl;
   else if(A[i]>B[j])
   cout<<"smaller"<<endl;
   else cout<<"greater"<<endl;
}
int check_palindrome(char A[])
{
    int i,j;
    j=Strlen(A);
    j--;
    for(i=0,j;i<=j;i++,j--)
    {
        if(A[i]==A[j])
        return 1;
    }
return 0;
}
int main()
{   // two ways to store string
    char N[]={'D','E','E','P','T','I','\0'};
    char S[]="MITTAL"; //'\0' is added by the compiler
    char A[]="How are you?";
    char Y[]="Python"; 
    cout<<"Name: "<<N<<" "<<S<<endl;
    /*int A[]={1,3,5,7,9};
      cout<<A<<endl; //this prints the address of A[0] since an array name is a pointer in itself
      cout<<&A[1]<<endl; //check output the difference between address of A[0] and A[1] is 4bytes
    */
    /* if(valid(N))  
       cout<<"valid string"<<endl;  
       else cout<<"Invalid string"<<endl;   
    */
    
   /* char B[]="deepti";
    if(check_palindrome(B))
    cout<<B<<" is a palindrome"<<endl;
    else cout<<B<<" is not a palindrome"<<endl;
   */ 

return 0;
}
