# Small-Programs
Repository for any random programs that I create.
Current programs in this repository:
* Replicating Bags of Ints Problem

## Replicating Bags of Ints
The game "West of Loathing" has a certain puzzle in one of its maps (Soupstock Lode) where you have to tighten screws on an elevator to reach a target pressure in order to operate the elveator. In the game, there are three screws and every turn on the screw updates the total pressure by a certain amount every time. However, each screw cannot be turned more than eight times. Thus, the player has to find the correct combination of turns on each of the three screws, up until eight times per screw, to reach the target pressure. 

After a few minutes of trying out different numbers, I finally paused the game and decided to write a program to help progress onwards in this game without a brute force method. Is this a bit extra for a $10 steam game? Perhaps. Was it fun? Indeed. There are more details about the program inside of the .cpp file. I renamed this problem to "Replicating Bag of Ints" as it seemed more generic than "West of Loathing's Elevator Problem."

## Officer Bulletin Board HTML Intro
The game "Puzzle Pirates" has this bulletin board that, upon owning a ship, you may write a message for others to see when they board. Upon buying my first ship, I realized that "Puzzle Pirates" actually takes in `<font>` HTML tags! Thus, common tag modifiers such as `<font size="5" face="Courier" color="#123456">` were all possible for text. With this in mind, I wanted to create a bulletin board using HTML code that... Well, _is_ code! I'm using C++ syntax and Sublime highlighting to simulate C++ code that is heavily HTML-ized underneath.

One of the obstacles I faced is that while "Puzzle Pirates" gives you a "Preview" option, the game doesn't actually tell you that there is a 3,000 character limit until you hit the "Submit" button. This was a problem, as I'd already have written all this text only to find out that I'm hitting that character limit because 80% of the characters are actually HTML tags. While at first I decided to simply delete less meaningful lines, I discovered that I could perform a little HTML tag shortening trick. Instead of giving each string its own tag which, in my opinion, aids in understanding what format that string has, I chose to wrap large heavily-HTML-modified sentences in their largest common denominator tag. This allowed me to cut out repetitive HTML statements.

For example, in the code you will see this style:
```
  <font color="123456" size="X">
			<font color="098765" size="Y">Some_String</font>
			String_With_123456_Tag
			<font color="098765" size="Y">Some_String_2</font>
			String_With_123456_Tag_2
	</font>.
```

As opposed to:

```
<font color="098765" size="Y">Some_String</font>
<font color="123456" size="X">String_With_123456_Tag</font>
<font color="098765" size="Y">Some_String_2</font>
<font color="123456" size="X">String_With_123456_Tag_2</font>
```

And, while I do believe taht the second method is more readable for formatting many different strings, I noticed that the first method vastly decreases the character count. Thus, in the end, I'm optimizing away readability for added optimization. In this case, my optimization is the amount of characters in the program as opposed to a more standard metric such as speed or memory. All in all, fun experience (albeit a bit annoying at many... many times.)!
