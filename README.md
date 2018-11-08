This is a simulation of MTG designed to give an accurate idea to a player whether their deck has sufficient mana to support "splashing" - adding additional colors to their deck.

To get the simualtion, clone this repository or download the zip file. Then go to the mtg-sim folder. Make sure you have cmake installed. Run cmake . in the top level directory. Then, run make to get the executable (named mtg).

Execution goes as follows:

./mtg [input file name]

The input file must be in the following format

{keyword} {value} {keyword} {value} ...

{keyword} {value} {keyword} {value} ...

Each line in the input file describes a different card. For example:

name healers-hawk quantity 2 plains 1

For a full example, see the sample input files in the sample inputs folder.

This is a work in progress that I started in late October 2018. If you have any questions or ideas email nathaniel.knapp@gmail.com.

Furthermore, I am seeking full time remote work in backend development or scientific software. If you have any advice / leads for me, I would highly appreciate you contacting me at the email above.  
