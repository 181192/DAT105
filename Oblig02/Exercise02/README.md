# Exercise 2 – Piggy bank

### a)

Implement a piggy bank simulation where clients can either deposit or withdraw
money from the piggy bank.
The piggy bank should be a simple integer variable, and the clients should be represented as
threads. This time, create one function called consumer and one function called producer to
define the functionality of the threads. The functions should be able to deposit or withdraw an
amount defined by a parameter to the function. Restrictions are that the consumer should only
withdraw if there is enough money in the piggy bank. If not, it should wait for the piggy bank
to fill up.

### b)

Create a program where a consumer and a producer simultaneously accesses the
piggy bank and adds or removes random amounts in the range 1 to 50.
Run the simulation several times and observe eventual irregular
behavior.

### c)

Explain irregular behavior that you observe in the trials in b).