#Title

C++ code of genetic Algorithm Aritifical intelligence algorithm

### Prerequisites

C++ Code editor i.e Dev C++

## Running the tests

Input is hardcoded if want to change can change it

### Run

Just click compile and run

### Problem Statement

Genetic algorithm is random search case problem where we initialize some population and then using that we explore up iterations in order to find solution. For 8-Queen problem, take initial population of four in which each chromosome will be a string of 8 numbers ranging from 1-8. Initially the four populations can be made using random function. From that now choose a fitness function. One example of fitness function can be total number of conflicts value as per the rules of chess. Then by this fitness function we will always choose those chromosomes which have less value for the fitness function. 
Next, after assigning any fitness function choose best 3 population based on the criteria. After this, cross over criteria is to be decided by your choice. You can choose any type of cross-over or any location from which two chromosomes have to be crossed. Declare the criteria in comments so as to make it understandable. 
Decide mutation criteria now, as per correct logic we can mutate those bits who have repetitions for suppose if there is a particular chromosome produced after chromosome as 1245178 so 1 should be mutated as we cannot have same number for two different queens. Else you can go for random mutations. 
Lastly there needs to be some criteria of when to stop. So for that, you can keep a threshold value for fitness function or a convergence point on how much maximum iterations the code should perform after which the answer with best fitness function gets presented. 


## Authors

* **Sooraj Kumar** 
* etc
