/*
                ||------RULE OF 3--------||
The rule of 3 says that,
If you have to create any object where you have to implement either one of
1. Copy constructor
2. Destructor
3. Constructor
Then you should implement all three.
 This is general rule of thumb in C++ because if for example we allocate memory
in Constructor, then copy will require new memory and also we have to delete
allocated memory thus the destructor.

                ||------Law of Big two--------||
The Law of big two states that if you are using some collection from std library
or some smart pointer the we don't need to worry about releasing memory e.g
destructors. So then we sould define the constructors and the copy constuctors.


*/