# Introduction

This simple subsitution cipher would allow you to easily encrypt and decipher messages that can be solved by hand. Why make a program that you can just as easily do by hand, you may ask? Because, my dear friend, this way can be faster, if you can navigate your way through my confusing and tangled code and on-screen prompts.

# Code Example

This program uses a two-dimensional string array to store the alphabet in both uppercase and lowercase, both encryption functions regularly use this array as reference.
<img src="https://github.com/TheStupidProgrammer/Simple-Substitution-Ciphers/blob/master/Screenshots/Alphabet_Array.png?raw=true" align="left"/>
<br>
<br>
<br>
 Enciphering with the Caesar Cipher will ask for a shift code, this number will shift the alphabet left however many characters, starting the alphabet at the selected letter. <img src="https://github.com/TheStupidProgrammer/Simple-Substitution-Ciphers/blob/master/Screenshots/CaesarCipher_Code_Example.png?raw=true" align="left"/> How it works is by subtracting your number from a total of 26, it then uses the difference to find the appropriate character in the Alphabet table. Transcribing the entire alphabet from the table to a new array marked cipherAlphabet. Each time it transcribes a character from the Alphabet table to the new array, it will add 1 to the number, eventually when the number reaches 26, the variable is reset to 0 so it will transcribe A and so on.
<img src="https://github.com/TheStupidProgrammer/Simple-Substitution-Ciphers/blob/master/Screenshots/Menu_Navigation_Example.png?raw=true" align="right"/>Next, it will ask you for the text you wish to encipher. Entering the text will store your input in a string variable, This string variable is then checked against the alphabet array character by character. If there is an A in your string, it will match it with the A in the alphabet table. If the alphabet starts from 0-25, A-Z, the function would check to see what's at the 0th place in the cipherAlphabet array and replace the character in the inital string with what it found.
<br>
<br>
<br>
<img src="https://github.com/TheStupidProgrammer/Simple-Substitution-Ciphers/blob/master/Screenshots/AffineCipher_Code_Example.png?raw=true" align="left"/>
Enciphering with the Affine Cipher is somewhat simple compared to the Caesar Cipher, all you have to do is enter the text you want enciphered. The program will then check each character in the string against each character in the alphabet table, if the character matches the character in the table, it will store the number the character is found at in the table in the y variable. Using an equation (5y+8)mod26, it will calculate the new number and find the appropriate character in the alphabet table. Then it will replace the letter with the new character.
<br>
<br>
Deciphering is a bit trickier to explain, the deciphering function for the Caesar Cipher basically does what its enciphering counterpart does but in reverse. Still using a number to shift the alphabet, but instead of transcribing what's in the cipherAlphabet array to the string, it will transcribe what's in the alphabet table to the string using the cipherAlphabet array as a reference.
This function will allow you to enter text to be deciphered or enter a sequential access file to be deciphered.<img src="https://github.com/TheStupidProgrammer/Simple-Substitution-Ciphers/blob/master/Screenshots/SequentialAccessFile_Example.png?raw=true" align="right" alt="An example of a sequential access file"/><br> If you wish to decipher a text file, you would have to enter the entire file url (case-sensitive) into the specified field and enter the shift number. Entering the proper shift number, it will decipher and display the deciphered text in the command prompt. However, if you were to enter 0 instead, it will try to solve it with your help. Starting at a shift number of 1, it will display the first line in the file and prompt you if it is correct. If the translated line is incorrect, it will add 1 to the shift number and try again, all the way to a total of 25. If the line is correct, it will translate the entire file with the shift number you said was correct.
<img src="https://github.com/TheStupidProgrammer/Simple-Substitution-Ciphers/blob/master/Screenshots/SequentialAccessFile_Decoded_Example.png?raw=true" align="right" alt="An example of how the program would 'automatically' decode the file for you"/>
If you just wish to decode some text, not a whole file, you can just press 2 and enter your code. Very similar to the file decoder, it will ask you for the shift code, if you do not have it, it will go through every possible iteration until you find a suitable answer.


The Affine deciphering algorithm basically does what it's ciphering counterpart does, but with a different formula. 21(y-8)mod26. However, do to an error that's too complicated for me to understand, it subtracts 26 from the modulo, so I have to add 26 like this (21(y-8)mod26)+26. Now though, it jumps forward 26 characters with certain letters. Therefore, I added a conditional statement that checks to see if the outcome of the formula exceeds 26 or is less than 0, subtracting 26 and adding 26 respectively. Now it works, almost like magic.


# Motivation

My motivation to make this was to finish a project for my class, using all of the required fields like arrays, strings, and sequential access files. I first thought of making it like one of thos decoder rings, like the one in The Christmas Story, but I couldn't figure out what they're called so I resorted to these two ciphers. My initial inspiration though, was when I was making a program that would convert single words into Pig-Latin. I found that making that was somewhat entertaining, so I thought that making a program that uses other ciphers would be a bit more entertaining.

# Installation

This project is recommended to be run by Microsoft Visual Studio. However, if intended to be ran with other IDE software, I recommend that you omit the line "#include "pch.h"". It is a header required for programs to run on Microsoft Visual Studio.

# Tests

Using a pangram is very useful to test my program, as a pangram is a sentence that contains every letter of the alphabet at least once.
So, if you were to type the pangram "The quick brown fox jumped over the lazy dog", you would get these outputs. With a shift code of three, the Caesar Cipher would make the sentence, "Qeb nrfzh yoltk clu grjmba lsbo qeb ixwv ald". Alternatively, the Affine Cipher would say, "Zrc kewsg npaov hat beqfcx ajcp zrc lidy xam".
I like to use that pangram because it contains more than one zero, this way I know that the output isn't just a bunch of random characters from the alphabet array.

# license

This program is public domain
