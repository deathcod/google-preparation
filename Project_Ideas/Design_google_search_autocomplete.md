## DESIGN A GOOGLE SEARCH AUTOCOMPLETE PROCESS

### Thoughts:

* Do they use Tries.


### Suggestions

***Suggestion 1***

Can be solved like:
1) Take the word user is giving
2) Now u can generate an array of synonymous
3) create a manny to one relationship to LRU DB of that word
4) Based upon other facts like location, time, history etc find the probabilty and the suggestion of the user

***Suggestion 2***

This is an open ended question, but here are some of the themes. 
How will you store the answer? 
How will you rank and recall the answer given a query? 
Some useful concept

* Levenstein distance
* Tries for dictionary entry with a common prefix
* DFAs can help test whether a word belongs to some pattern
* n-gram(shigles) can help to predict neighbouring words.
* LFU caching can help shoulder most of the (query) load.