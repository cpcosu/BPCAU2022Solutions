# Description
#### Runtime Limit: 1.0s
#### Memory Limit: 500.00 MB

It's spooky season and Sabrina is getting ready to cut her pumpkins and turn them into Jack-o'-Lanterns. But she wants a template to help her make the scariest face on pumpkin. Help her by making the template for each size she requests. To make it easier to automate you decide to make the template out of ASCII characters. The template Follows the below pattern:
<br><br>
Eyes
<ul>
<li>Each eye is a triangle with two diagonal line created out of "/" and "\" and one flat line created with "_".</li>
<li>The two diagonal lines start at the top middle of the eye and go diagonal down to the bottom left and right.</li>
<li>In-between the two diagonal lines at the bottom is the flat line competing the triangle. </li>
</ul>
Mouth
<ul>
<li>The mouth is created using two row of teeth. </li>
<li>Each tooth in the upper row is made like this "\/" and each tooth in the bottom row is made like this "/\". (Notice "\/" is two characters and it is not the capital of the character "v")</li>
<li>There is no spaces between any of the teeth.</li>
</ul>
Placement
<ul>
<li>Each eye will be placed at the top of the picture with two spaces in between.</li>
<li>There will be one line with nothing but spaces in-between the eyes and mouth.</li>
<li>The mouth will be centered horizontally below the eyes.</li>
<li><b>All empty spots must be filled with spaces even at the end of a line. So that every line is the same length and no column of characters is all spaces.</b></li>
</ul>

# Input

There is one line with two number H and T, where the first number H is the height of the eyes (1 ≤ H ≤ 100) and the second number T is the number of teeth (1 ≤ T ≤ H&#215;2+1).

# Output

The Jack-o'-Lantern template in the form of ASCII art.

# Sample
Cases 0 and 1