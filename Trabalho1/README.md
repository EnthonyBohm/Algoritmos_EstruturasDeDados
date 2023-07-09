Author: Enthony Gabriel Rodrigues Bohm

# LeetCode: ShortestCompletingWord
This problem consisted in giving an array of strings (words), with two dimensions that contained different words, and a string with different simbols(License Plate), wich only the letters should be considered, those who were captalized should be converted to lower case, the return of this function should be the first word in the string who is the shortest and satisfy the condition of having at least one ocourrence of all valid letters of the License Plate.
## Cases Tested

### Case 1
**Input**

_words_: "nice","idea","hard","statement","money","later","interesting","which","purpose","evening" 

_License Plate_: "IaDe806"

**Output**  
"idea"

---
### Case 2
**Input:**

_words_: "step","steps","stripe","stepple" 

_License Plate_: "1s3 PSt"

**Output:**   
"steps"

---
### Case 3
**Input:**

_words_: "looks","pest","stew","show"

_License Plate_: "1s3 456"

**Output:**   
"pest"

## Status  
From what I checked everything is running fine, the only problem is that, the code isn't well optimized, it could have some memory allocated dinamically and later on freed, but I don't know to do it very well
I still think that this is a bad solution and my Logic wasn't really great, but for now, that was the best I could do.
