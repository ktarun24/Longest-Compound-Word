# Longest-compound-word
  Since problem is about seaching a string of character. So we are using Trie data structure as it give optimize search time of O(n) where n is length of word. Here using     hash table to store the characters of word;

  The time complexity for insertion is O(w*N). As the length of words(w) is small as compared to number of words the time can be approximated to O(N)

  Created a function which will return True if the given word is a compound word.
  So the first word which returns true will be the largest compound word. 
  The function runs a loop to find a prefix. If no prefix found it will return false. Otherwise, if a prefix is found then other part of the word is checked whether it is a valid or a compound word or not valid.Then words are sorted and stored according to their length.
  
  After sorting run a for loop and applying longest compound word function. When it returns two strings then break the function.

  The worst time complexity according to me will be O((m^2)*N).
