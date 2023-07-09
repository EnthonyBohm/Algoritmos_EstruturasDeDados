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
