# CS210--Cplusplus

Summarize the project and what problem it was solving.

* This project began with starter code in both C++ and Python and I was asked to create several functions that would pass information back and forth between C++ and Python. I created a looping main menu function that would display all available options to the user, receive and validate user input, and then take the appropriate action. The four different options are described below:
      
   * Option 1: Produce a list of all items purchased in a given day along with the number of times each item was purchased.
      * C++ code was written to call a Python code that would calculate the frequency of each item and display the item name and its frequency.
      * Example: Apples 4
               * Spinach 5
      
   * Option 2: Produce a number representing how many times a specific item was purchased in a given day.
      * User would enter an item name and a C++ function would receive that input and pass it to the appropriate Python function. The Python code then finds the item's frequency in the input file and returns that frequency where it will be displayed in the C++ function
      * Example: Enter item name: Spinach
                Spinach occurred 5 times.
      
   * Option 3: Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased.
      * A Python function was created that converted the input file (a text file) into a .dat file. This file was then opened in C++ and a C++ function iterated over
       each line and displayed the item names and their frequency. The frequency was listed as a number of '*' equal to their frequency in the .dat file.
      * Example: Apples ****
                Spinach *****
      
   * Option 4: Exit the program.
      * Exits the do while loop in the main menu function and ends the program. 
         
What did you do particularly well?       
* I believe that my main menu function was the cleanest and most efficient piece of my total project. I also felt as though I was able to meet the standards for options 1 and 2 without much unnecessary code. 

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
* I think that the place that I could enhance the most is in option 3. I realize that my method for displaying the frequency as a histogram is unwieldy at higher frequencies and that this needs to be corrected. I spent several hours trying to determine if there was a way to convert a string such as "5" to an integer, but I was ultimately unsuccessful in finding that solution.
  
Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
* I found the third option to be the most difficult. As I stated above, I found it very difficult to convert a string to an integer in C++ and I was ultimately unsuccessful in finding a solution to this problem. I was eventually able to overcome this by taking a much longer route. However, I suspect this only worked, because the input text does not have any items that exceed a frequency of 10. 
   
What skills from this project will be particularly transferable to other projects or course work?
* I think that the ability to use multiple programming languages is the most useful piece of this project. I think that being able to jump between multiple languages will allow me to utilize the most appropriate language for a specific problem. This in turn may allow for a more manageable code for future projects and coursework. 
   
How did you make this program maintainable, readable, and adaptable?
* I believe that I used best practices when it comes to use of whitespace, naming conventions and comments throughout the code. I also believe that I adequately broke the code into several separate functions that passed information to one another. That way, if an error were to be found in the future the programmer behind me would not need to dig through every line, but would be able to find the logical pathway that the information travels. This is how I created a maintainable and readable code.
