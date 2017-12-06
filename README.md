# User Authentication System
A program that simulates a user authentication system using a randomized-challenge response scheme.

### Synopsis
In a user authentication system that uses a randomized-challenge response scheme, a user is required to enter different
information everytime based on a secret (i.e., password). Specifically, the scheme will consist of a five-digit PIN number
(00000 to 99999). Each digit is assigned a random number that is 1, 2, or 3. A user then has to enter the random numbers 
correspondig to their PIN instead of their actual PIN numbers.

The password that is stored in the program is **12345**.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/https://github.com/cramaechi/user-authentication-system.git
   ```
    or [download as ZIP](https://github.com/cramaechi/user-authentication-system/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd user-authentication-system
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./user_authenticate
```

Sample Output:
```
PIN: 0 1 2 3 4 5 6 7 8 9                                                                                              
NUM: 2 2 1 1 2 2 1 1 2 2                                                                                              
                                                                                                                      
Enter PIN: 21121                                                                                                      
PIN denied. Please try again.                                                                                         
                                                                                                                      
PIN: 0 1 2 3 4 5 6 7 8 9                                                                                              
NUM: 3 2 1 3 2 2 3 1 2 3                                                                                              
                                                                                                                      
Enter PIN: 21323                                                                                                      
PIN denied. Please try again.                                                                                         
                                                                                                                      
PIN: 0 1 2 3 4 5 6 7 8 9                                                                                              
NUM: 3 1 3 2 3 3 3 1 2 3                                                                                              
                                                                                                                      
Enter PIN: 13233                                                                                                      
PIN confirmed. Thank you. 
```
