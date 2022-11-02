
#### Runtime Limit: 10.0s
#### Memory Limit: 500.00 MB

# Description

You are in a haunted house and you’re trying to identify where all the ghosts are. And there are a lot of ghosts. So, you treat the house like a grid.  
Each grid coordinate in the house can be either a ghost 'X' or not a ghost '-'. 
You set up a sensor along the back and left side of the house and each sensor aligns with one row or column of the house. 
The sensor reads out sections of adject ghost. So, if there are two ghosts in a row, a gap, then three more ghost the row will read "2 3". 
Each row sensor reads out sections left to right. And each column sensor reads out sections top to bottom.

# Input

The first line contains two integers W and H, the width and height of the house (1 ≤ W, H ≤ 25).
The next H lines contain the sections of ghosts in each row from the back to the front of the house.
The next W lines contain the sections of ghosts in each column from the left to the right of the house. 
If there are no ghost in a row/column the line will be '0'.

# Output

The house as a grid of 'X's for ghosts and '-'s for spots without a ghost. Moving from the back to the front of the house. There will only be one correct grid.
<br><br>
Disclaimer: Due to nature of this problem we can't guarantee that all possible testcases can be solved within the time given. But, all testcases ran by the judges can run significantly under the time limit given. 

# Sample
Case 0 and 1