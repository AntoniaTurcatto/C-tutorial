#include <stdio.h>
#include <stdlib.h>//to use malloc and others
#include <stdbool.h> //for using bool type
#include <string.h> //for maipulating strings

//O comando typedef permite ao programador definir um novo nome para um determinado tipo. 
//  Pode ser usado também para dar nome a tipos complexos:

//enum example
typedef enum Gender{
    MASCULINE = 1, //first item, by default, is 0
    FEMININE, // 2
    NON_BINARY// 3
}Gender;

//example for structure
typedef struct person{
    char name[50];
    int age;
    Gender gender;
} person;



int main(){
    //array
    int mySimpleNumbers[] = {25, 50, 75, 100};
    //multidimentional array (2d in whis case)
    int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

    //assigning a value to an array index
    mySimpleNumbers[0] = 27;
    printf("value 0: %d\n", mySimpleNumbers[0]);

    //size of an array
    int lenghtOfArray = sizeof(mySimpleNumbers) / sizeof(mySimpleNumbers[0]);
    printf("lenght of array: %d\n", lenghtOfArray);
    

    //----------------STRINGS--------------------
    char myString[] = "Hello world";
    char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    printf("%s", myString);
    myString[5] = '|';
    for (int i = 0; i < sizeof(myString) / sizeof(myString[0]) -1; i++){ //-1 because the 'null' char
        printf("\n%c", myString[i]);
    }


    //----------string.h
    char alphabet[39] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Concatenate str2 to str1 (result is stored in str1)
    strcat(alphabet, greetings); 
    printf("\nsize of %s:\n %d\n", alphabet,strlen(alphabet)); //automatically does the -1 to ignore the '\0'
    
    // Copy str2 to str1
    strcpy(alphabet, "new str");
    printf("new str: %s", alphabet);


    //---------------------------user inputs-------------------
    char fullName[30];
    printf("Type your full name: \n");
    fgets(fullName, sizeof(fullName), stdin);//to read a line of string without stoping on ' ' (space)


    //-------------------------POINTERS---------------------------
    int * int_ptr;
    int n = 9;
    int_ptr = &n; //the address of n

    printf("\nvalue and address of n: \n%d\n%p\n\n", *int_ptr, int_ptr);
    //good to know: the general address of an array is it first element

    int myNumbers[7] = {32,25,53,64,1,21,5};

    //to access the rest of the elements in myNumbers, you can increment the pointer/array (+1, +2, etc):
    *myNumbers = 0;
    *(myNumbers + 1) = 1;
    *(myNumbers + 2) = 2;
    *(myNumbers + 3) = 3;
    *(myNumbers + 4) = 4;
    *(myNumbers + 5) = 5;
    *(myNumbers + 6) = 6;
    for (int i = 0; i < 7; i++){
        //printf("%d", myNumbers[i]);
        printf("%d", *(myNumbers + i));
    }
 
    
    //------------FILES------------------------------------------
    //creating file
        //FILE *fptr;
        //fptr = fopen(fileNameOrPathWithName, mode); 

    FILE *file;
    file = fopen("test.txt","w");//w = write; a = append; r = read
    if(file != NULL)
        fclose(file);

    //creating c source and batch for compiling(example)
    file = fopen("C:\\Users\\Public\\Documents\\testC.c", "w"); 
    if (file != NULL){
        fprintf(file, "#include <stdio.h>\n"
            "int main(){\n"
                "printf(\"Hello internal world!\");\n"
                "getchar();\n"
            "}");
        fclose(file);
    
        file = fopen("C:\\Users\\Public\\Documents\\compileTestC.bat","w");

        if(file != NULL){
            fprintf(file,"@echo off\n"
                "gcc C:\\Users\\Public\\Documents\\testC.c -o C:\\Users\\Public\\Documents\\compiledTestC.exe"
            );
            fclose(file);
        }
    }
    
    



    //reading a file:---------------------------
    
    file = fopen("C:\\Users\\Public\\Documents\\compileTestC.bat","r");
    if (file != NULL){
        char batFile[50];
        //fgets(batFile, 93, file); only read one line!!!!!!!

        printf("\n\n---Batch file generated on 'C:\\Users\\Public\\Documents\\'---\n"); 
        while (fgets(batFile, 93, file)){
            printf("%s", batFile);
        }
        printf("\n\n");
        fclose(file);
    }


    //-----------------------ENUMS------------------------------------
    //using the enum created above main() -using typedef 
    Gender f = FEMININE;
    Gender m = MASCULINE;
    Gender x = NON_BINARY;

    //--------------------------------------------STRUCTURE--------------------------
    //using the structure created above main() -using typedef 
    person p1 = {"Juan Rodriguez", 23, m};

    person p2;

    //copy
    p2 = p1;

    //changing the data
    strcpy(p1.name, "Juan Dominguez"); 
    p2.age = 21;
    p2.gender = x;

    printf("%s, %d, %d\n", p1.name, p1.age, p1.gender);
    printf("%s, %d, %d\n", p2.name, p2.age, p2.gender);


    //------pointers to structures
    //struct person *p;
    person * personPointer = &p1;

    //deferrencing
    printf("name of the person on the pointer (method 1): %s\n", (*personPointer).name);

    personPointer = &p2;
    printf("name of the person on the pointer (method 2): %s\n", personPointer->name);



    //it's possible to use structure on ARRAYS-------

    //------------------------MEMORY---------------------------
    //ALLOCATE MEMORY - reserving memory


    //STATIC MEMORY:
    //memory that is reserved for variables at compile time
    //(C automatically allocates memory for every variable when the program is compiled.)

    //DINAMIC MEMORY:
    /*
    Dynamic memory is memory that at runtime
    Unlike with static memory, you have full control over how much memory is being used at any time.
        You can write code to determine how much memory you need and allocate it.
    Dynamic memory does not belong to a variable, it can only be accessed with pointers.
    */

    //The malloc() function has one parameter, size, which specifies how much memory to allocate, measured in bytes.

    //allocatin memory
    int *ptr1;
    ptr1 = malloc(sizeof(*ptr1) * 3);//space for 3 int
    
    //writing into it
    *ptr1 = 12;
    ptr1[1]= 23;
    ptr1[2]= 32;
    // Read from the memory
    printf("%d %d %d", *ptr1 ,ptr1[1], ptr1[2]); 

    //reallocating (making the allocation larger)
    int* ptr2 = realloc(ptr1, sizeof(*ptr1) * 5);
    if (ptr2 != NULL){//checking if was memory available
        ptr1 = ptr2;
        free(ptr2); //Deallocating(freeing allocated) memory - it was copied to the previous pointer  
        ptr2 = NULL; // good practice after deallocating
        ptr1[3] = 4;
        ptr1[4] = 50;
        printf("\n%d %d %d %d %d\n", *ptr1 ,ptr1[1], ptr1[2], ptr1[3], ptr1[4]); 
    } else {
        printf("Unable to allocate more memory");
        
    }
    free(ptr1);
    ptr1 = NULL;




    //------------------------------MEMORY LEAKS---------------------------
    //cases:
    //1: The pointer is overwritten -- previous memory reallocated not freed
        //ptr = calloc(2, sizeof(*ptr));
        //ptr = &x; 

    //2: The pointer exists only inside a function and is not freed -- If realloc() is unable to reallocate memory it will return a pointer to NULL and the original memory will remain reserved.

    //3:The pointer gets lost when reallocation fails:
        //ptr = malloc(sizeof(*ptr));
        //ptr = realloc(ptr, 2*sizeof(*ptr)); 
    return 0;
}