# Description
#### Runtime Limit: 1.0s
#### Memory Limit: 500.00 MB

This problem was not very good, and as a consequence, an army of ghosts came! It's a well-known fact that, ghosts say "BOO" to show disapproval. However, when a ghost wants to be scary, they say "BOOO".
<br><br>
The problem is that, after the ghost army came, each of them said either "BOO" or "BOOO" at the exact same time, so it became difficult to distinguish between all the sounds. For example, if two ghosts say "BOO" at the same time, depending on how the syllables interweave, it could be heard as "BOOBOO", "BOBOOO", or "BBOOOO".
<br><br>
Can you help determine if there was a scary ghost who said "BOOO"?

# Input

A string S 3 ≤ |S| ≤ 40000 consisting of the letter’s 'B' and 'O'. It is guaranteed that this line can be created by interleaving the letters of some number of words 'BOO' and some other number of words 'BOOO'.

# Output

If at least one ghost said 'BOOO', we should be scared, so output 'AHH'. Otherwise, they are all jeering at us, so output a frowny face '):'

# Sample
|Input|Output|
| :--- | :--- |
| BOBOOOBBOOOO| ): |

|Input|Output|
| :--- | :--- |
| BOBOOOO| AHH |
