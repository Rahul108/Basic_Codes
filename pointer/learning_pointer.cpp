// Wrote this code based on: https://www.youtube.com/playlist?list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_
// For learning purpose !!
// Tried to cover the Basic ideas of Pointer... 

#include<bits/stdc++.h>
using namespace std;

// Function for testing Pointers as function argument :: call by reference
int increment(int *value){
    *value = *value + 1;
}


// Function for testing Arrays as function
int sum_of_array(int *value, int size){
    int total(0);
    for(int i=0;i<size;i++){
        total+=*(value+i);
        cout<<*(value+i)<<endl;
    }
    return total;
}


int main()
{
    int a;
    int *p;
    a=5;
    cout<<"a= "<<a<<endl;

    // referencing
    p=&a;

    // will print the address value
    cout<<"p= "<<p<<endl;
    
    // will print the value that pointing the address
    cout<<"*p= "<<*p<<endl;

    //dereferencing: will change the value of the variable which its referencing!
    // when p = &a; its called referencing
    // then when *p = 100; its called dereferencing
    *p = 6; // will change the value of a
    cout<<"After Dereferencing, a= "<<a<<endl;

    // any kind of change on a can be accessed by p! cause we are addressing through it
    a++;
    cout<<"After Incrementing a, *p= "<<*p<<endl;

    // taking a new value from other int won't change the reference address
    int b;
    b=1025;
    *p = b;
    cout<<"Address, p= "<<p<<endl<<"After deferencing with other variable, a= "<<a<<endl;

    // size of int, float, double, char...
    cout<<"--------------"<<endl;
    cout<<"size of int: "<<sizeof(int)<<" byte"<<endl;
    cout<<"size of float: "<<sizeof(float)<<" byte"<<endl;
    cout<<"size of double: "<<sizeof(double)<<" byte"<<endl;
    cout<<"size of char: "<<sizeof(char)<<" byte"<<endl;
    cout<<"--------------"<<endl;

    // Pointer Arithmatic
    // Typecasting!!
    // There are some kinds of pointer variables [eg. int*, char*, etc] that are used to reference and dereference values in a variable and also access/modify values of an address!!
    char *char_p;
    char_p = reinterpret_cast<char*>(p); // This part is called typecasting
    cout<<"a= "<<a<<endl;
    // cout<<"p= "<<p<<endl;
    printf("p= %d\n",p);
    printf("char_p= %d\n",char_p);
    printf("*char_p= %d\n",*char_p);
    // cout<<"char_p= "<<char_p<<endl;  
    // cout<<"*char_p= "<<*char_p<<endl;
    
    // incrementing the address :: https://stackoverflow.com/questions/8208021/how-to-increment-a-pointer-address-and-pointers-value

    // Void pointer :: Generic pointer type
    // We can't deference the pointer cause it doesn't support any type
    void *void_p;
    void_p = p;
    cout<< "void_p= "<<void_p<<endl; // printing *void_p will give error!!

    // Pointer to a pointer
    cout<<endl;
    int **p_pointer_to_pointer;
    int ***p_pointer_to_pointer_to_pointer;
    p_pointer_to_pointer =  &p;
    p_pointer_to_pointer_to_pointer = &p_pointer_to_pointer;
    cout<<"**p_pointer_to_pointer= "<<*(*p_pointer_to_pointer)<<endl; 
    cout<<"**p_pointer_to_pointer_to_pointer= "<<*(*(*p_pointer_to_pointer_to_pointer))<<endl;
    // When we writer one * less, then it would reference to the address practically :-P
    cout<<"**p_pointer_to_pointer= "<<*p_pointer_to_pointer<<endl; 
    cout<<"**p_pointer_to_pointer_to_pointer= "<<*(*p_pointer_to_pointer_to_pointer)<<endl;

    // after using pointer as function argument :
    increment(&a);
    cout<< "After using pointer argument in increment function, a= "<<a<<endl;

    // Pointers as arrays
    cout<<endl;
    int arr[] = {5,4,3,2,1};
    int *p_arr = arr;
    cout<<"*p_arr= "<<*p_arr<<endl;
    // This part is commented cause in memory it holds the referencing for which it causes problem on further calculation!!
    // *p_arr = *(p_arr+1);
    // cout<<"after incrementing the *p_arr= "<<*p_arr<<endl;

    // Pointer as function argument
    cout<<endl;
    int size_of_arr = sizeof(arr)/sizeof(arr[0]);
    int *pass_arr_value = arr;
    int sum_result = sum_of_array(pass_arr_value,size_of_arr);
    cout<<"Sum after passing pointer as function argument as array= "<<sum_result<<endl;
}