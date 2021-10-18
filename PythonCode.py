import re
import string

#Opens an input file and prints each item and that items frequency
def printItems():
    file = open("item.txt", "r")                      #Open input file
    
    fileText = dict()                                 #Create a dictionary to file with keys and frequencies
    
    for fileLine in file:
        fileLine = fileLine.strip()                   #Remove leading spaces and newline characters
        fileLine = fileLine.lower()                   #Put each word to lower case to avoid case mismatch
        fileWords = fileLine.split(" ")               #Split the file into individual words

        for word in fileWords:                        #Iterate over each line
            if word in fileText:                      #Check to see if a word is already in the dictionary
                fileText[word] = fileText[word] + 1   #If word already exists, increment the word frequency
            else:
                fileText[word] = 1                    #Else add the word to the dictionary

    for key in list(fileText.keys()):                 #Print each word and its frequency
        print(key, fileText[key])

    file.close()                                      #Close the input file

#Opens an input file, searches for a user item, and prints that item and its frequency within the input file
def PrintMe(searchWord):
    print("You sent me: " + searchWord)
    searchWord = searchWord.lower()                        #Ensure search word is lower case to avoid case mismatch
    file = open("item.txt", "r")                           #Open input file
    fileText = file.read()                                 #Read all of the lines in the input file
    fileText = fileText.strip()                            #Remove any header spaces or new line characters
    fileText = fileText.lower()                            #Ensure each line is lower case to avoid case mismatch
    fileWords = fileText.split()                           #Split each line into individual words
    lenList = len(searchWord)

    for i in range(lenList):                                #Iterate through the list looking for the search word
        frequency = 0                                       #Declare frequency and set it to zero
        for word in fileWords:                              #Iterate through the file words
            if searchWord == word:                          #If the word matches the search word then increment frequency
                frequency += 1

    file.close()                                            #Close the input file

    return frequency;

#Opens an input file and creates a new file, then writes each item and their frequencies to the new file
def writeHistogram(v):
    inputFile = open("item.txt", "r")                 #Opens the input file

    fileText = dict()                                 #Creates a dictionary to store keys and values
    
    for fileLine in inputFile:                        #Reads file line by line
        fileLine = fileLine.strip()                   #Remove leading spaces and newline characters
        fileWords = fileLine.split(" ")               #Split the file into individual words

        for word in fileWords:                        #Reads each word in input file
            if word in fileText:
                fileText[word] = fileText[word] + 1   #If word is already in dictionary, increment word
            else:
                fileText[word] = 1                    #Else create word key and set value to 1

    print("Creating file...")
    with open('frequency.dat', 'w') as f:             #Creates new file named "frequency.dat"
        for key, value in fileText.items():           #For each item and frequency it writes the key, value pair on a new line
            f.write('%s %s\n' % (key, value))         #to the new "frequency.dat" file
    print("File creation completed.")

    inputFile.close()                                 #Closes the input file
    f.close                                           #Closes the new file

    return 0


