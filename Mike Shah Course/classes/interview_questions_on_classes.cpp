/*
Q1. what keywords are used to define user defined types
Ans. class and struct
Q2. What is a class use a concrete example.
Ans. way for user to create concrete types, it's often thought of as a
blueprint, they consist of attirbutes, methods.
Q3. What is copy constructor
Ans. A copy constructor is a specialt member function that is called when
instance of class is created from another instance.
Q4. What if we don't define, constructor, destructor, copy constructor.
Ans. C++ provides defaults, but if we do define them those defaults are
overridden.
Q5. What is move constructor.
Ans. Move is a contructor, when object is initailizes from R-values.
Q6. what are the member functions advised to implement in Rule of 3.
Ans. consturctor, destructor, copy constructo and copy assignemnt operator
Q7. In what scenarios do you have to provide copy constructor.
Ans. Anytime, you need to perform a deepcopy, e.g anytime the members vars are
not trivially copyable e.g heap memory vars
Q8. what are the member functions advised to implement in Rule of 5.
- consturctor
- destructor
- copy constructor and/or copy assignemt operator
- move constructor
- move assignemt operator
Q9. when should one initailaze object with Object x{1,2}; and Object x(1,2);
- {} prevent narrowing, e.g strict type checking, if there is initalizer_list
constructor, then it will call that instead
- () calls constructor with two params for above example and doesn't prevent
narrowing.
Q10. What are three uses of const.
- const pass by ref
- const correctenss (Read only access of member vars of class), e.g make member
methos of class const so that return member vars are not changes and returned,
instead returned as is.
- immutable vars.

Q11. Diff btw struct and class
- struct has all members by default as public
- class has them private
- if we don't explicitly specify the type of inheritence e.g class A: public B{}
then in stuct it is by default public and in class it is by default private.
Q12. What is RAII stand for.
Ans. Resource aquisition is initialization. It basically means that any resourse
we aquire should be released in object lifetime, e.g aquire in constructor and
destroy in destructor.
Q13. What is operator overloading.
Ans. operator overloading allows us to defing +,-,=,>> etc for fuctions and
classes, we can use the operators as proxy to do explicit function calls Q14-
What is is-a and has-a relation. Ans. is-a is relationship of inheritence and
- has-a is compostion relationship

Q15 - What is virtaual function in C++
Ans- Virtual fucntion in c++ is a way to support dynamic distpatch. This is
necessary to make sure correct function is called on instantiated object.

Q16- what is v-table.
Ans- v-table contains the entries for virtual functions.

Q17. What is virtual inheritence.
Ans. Virtual intheritance insures that derived classes only contain one of the
base classes if it appears multiple time.s

Q18. Devise a strategy to prevent copies of objects from being made.
Ans-
- In c++ 11 and beyond we can use delete keyword to delete copy constructor to
prevent copies
- Or we can define copy constructor in with private: access manager and it won't
allow copies
Q19- Why should you use members initializer list.
Ans- Using member initializerlist can avoid copy, we can directly create the
member vars inside the object, it's effiencent. Q20. What is friend class. Ans -
Gets access to all data members even private. Q21. Why would you make destructor
of class virtual. Ans - It makes sure that in inherited sturctre, all
destructors get called. Q22. How do we make abstract classes in C++. Ans- we can
pure virtual fuctions, e.g virtaul void Draw() = 0;
*/
