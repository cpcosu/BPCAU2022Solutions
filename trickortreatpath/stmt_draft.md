# Description
#### Runtime Limit: 1.0s
#### Memory Limit: 500.00 MB

You are going to trick or treating in your circular neighborhood. To help you decide which house you are going to next you roll s dice with d number of side. Then, you move the house that is the total of the dice in front of you. For example, if you are at the house of index 5 and roll a 4 you will go to the house with index 9. Similar to Monopoly. Additionally, the neighborhood is unique: It has tunnels connecting houses. If you arrive at a house with a tunnel instead of rolling the dice to find out where to go next after getting your candy, you take the directional tunnel to one of its exits. The tunnel has an equal chance of leading you to each exit. After trick or treating for a very long time you want to know the houses that you have the highest likelihood of you being at.

# Input

The first line contains 4 integers: n, s, d, and c (3 ≤ n ≤ 100, 1 ≤ s, d ≤ 100, 1 ≤ c ≤ n). n being the number of houses in the circle. s being the number of sides on each of the dice. d being the number of dice. Finally, c being the number of tunnels. The next c lines has an at least two integers and describes the tunnels. The first number on the line is the house number where the tunnel starts. The next integers are all the ending locations of the tunnel of which there is an equal chance of exiting out of. 

# Output

The location the top three locations in order on separate lines followed by their chances rounded to three decimal places. If they have equal chance when rounded output in order of lowest to highest house number.

# Sample
Cases 0, 1 and 2