# What it does
The goal of this application is to manage the records of all the members registering to the fitness studio.
The fitness studio keeps the following information about all its members: the member's name (first and last name), cell phone number, email address and credit card number. It allows the user to create new records, remove records, search for records, and modify records.

# How it was built
The application was built using C++ which models the details of the members of the fitness studio and uses a List data structure to manage the collection of members. The application also has a simple interface where the user can create, remove, search, and modify records.

# Challenges
I was met with many challenges while coding, however after stepping through the code line by line, I was able debug most of the errors.
Other challenges included design decisions where I wanted to design the insertion and retrieval functions in the most time efficient way possible. I considered a few different methods but eventually found that keeping the data sorted at all times would yield the fastest run time on average. 

# Accomplishments
This was my favourite coding project because I had created a data management system from scratch including a command line user interface. Using the interface to interact with the backend program really brought my program to life. 

# What I learned 
I learned how to design and implement a list that contains multiple member objects. I also realized that the design of the functions can impact the user experience. 
In the case that the application is scaled up to a large amount of member records, a less efficient algorithm makes a big impact on the run time to perform the different operations. Lastly, the fitness registration is only a specific use of the program, however it could be a solution applied to any problem that manages customer data. 
